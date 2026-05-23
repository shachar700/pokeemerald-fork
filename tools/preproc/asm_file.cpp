// Copyright(c) 2016 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <cstdio>
#include <cstdarg>
#include <stdexcept>
#include "preproc.h"
#include "asm_file.h"
#include "char_util.h"
#include "utf8.h"
#include "string_parser.h"
#include "../../include/constants/characters.h"
#include "io.h"

AsmFile::AsmFile(std::string filename, bool isStdin, bool doEnum) : m_filename(filename)
{
    m_buffer = ReadFileToBuffer(filename.c_str(), isStdin, &m_size);
    m_doEnum = doEnum;

    m_pos = 0;
    m_lineNum = 1;
    m_lineStart = 0;

    RemoveComments();
}

AsmFile::AsmFile(AsmFile&& other) : m_filename(std::move(other.m_filename))
{
    m_buffer = other.m_buffer;
    m_doEnum = other.m_doEnum;
    m_pos = other.m_pos;
    m_size = other.m_size;
    m_lineNum = other.m_lineNum;
    m_lineStart = other.m_lineStart;

    other.m_buffer = nullptr;
}

AsmFile::~AsmFile()
{
    if (m_size > 0) delete[] m_buffer;
}

// Removes comments to simplify further processing.
// It stops upon encountering a null character,
// which may or may not be the end of file marker.
// If it's not, the error will be caught later.
void AsmFile::RemoveComments()
{
    long pos = 0;
    char stringChar = 0;

    for (;;)
    {
        if (m_buffer[pos] == 0)
            return;

        if (stringChar != 0)
        {
            if (m_buffer[pos] == '\\' && m_buffer[pos + 1] == stringChar)
            {
                pos += 2;
            }
            else
            {
                if (m_buffer[pos] == stringChar)
                    stringChar = 0;
                pos++;
            }
        }
        else if (m_buffer[pos] == '@' && (pos == 0 || m_buffer[pos - 1] != '\\'))
        {
            while (m_buffer[pos] != '\n' && m_buffer[pos] != 0)
                m_buffer[pos++] = ' ';
        }
        else if (m_buffer[pos] == '/' && m_buffer[pos + 1] == '*')
        {
            m_buffer[pos++] = ' ';
            m_buffer[pos++] = ' ';

            for (;;)
            {
                if (m_buffer[pos] == 0)
                    return;

                if (m_buffer[pos] == '*' && m_buffer[pos + 1] == '/')
                {
                    m_buffer[pos++] = ' ';
                    m_buffer[pos++] = ' ';
                    break;
                }
                else
                {
                    if (m_buffer[pos] != '\n')
                        m_buffer[pos] = ' ';
                    pos++;
                }
            }
        }
        else
        {
            if (m_buffer[pos] == '"' || m_buffer[pos] == '\'')
                stringChar = m_buffer[pos];
            pos++;
        }
    }
}

// Checks if we're at a particular directive and if so, consumes it.
// Returns whether the directive was found.
bool AsmFile::CheckForDirective(std::string name)
{
    long i;
    long length = static_cast<long>(name.length());

    for (i = 0; i < length && m_pos + i < m_size; i++)
        if (name[i] != m_buffer[m_pos + i])
            return false;

    if (i < length)
        return false;

    m_pos += length;

    return true;
}

// Checks if we're at a known directive and if so, consumes it.
// Returns which directive was found.
Directive AsmFile::GetDirective()
{
    SkipWhitespace();

    if (CheckForDirective(".include"))
        return Directive::Include;
    else if (CheckForDirective(".string"))
        return Directive::String;
    else if (CheckForDirective(".braille"))
        return Directive::Braille;
    else if (CheckForDirective("enum"))
        return Directive::Enum;
    else if (CheckForDirective(".macro"))
        return Directive::Macro;
    else
        return Directive::Unknown;
}

// Checks if we're at label that ends with '::'.
// Returns the name if so and an empty string if not.
std::string AsmFile::GetGlobalLabel()
{
    long start = m_pos;
    long pos = m_pos;

    if (IsIdentifierStartingChar(m_buffer[pos]))
    {
        pos++;

        while (IsIdentifierChar(m_buffer[pos]))
            pos++;
    }

    if (m_buffer[pos] == ':' && m_buffer[pos + 1] == ':')
    {
        m_pos = pos + 2;
        ExpectEmptyRestOfLine();
        return std::string(&m_buffer[start], pos - start);
    }

    return std::string();
}

// Skips tabs and spaces.
void AsmFile::SkipWhitespace()
{
    while (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
        m_pos++;
}

// Reads include path.
std::string AsmFile::ReadPath()
{
    SkipWhitespace();

    if (m_buffer[m_pos] != '"')
        RaiseError("expected file path");

    m_pos++;

    int length = 0;
    long startPos = m_pos;

    while (m_buffer[m_pos] != '"')
    {
        unsigned char c = m_buffer[m_pos++];

        if (c == 0)
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF in include string");
            else
                RaiseError("unexpected null character in include string");
        }

        if (!IsAsciiPrintable(c))
            RaiseError("unexpected character '\\x%02X' in include string", c);

        // Don't bother allowing any escape sequences.
        if (c == '\\')
        {
            c = m_buffer[m_pos];
            RaiseError("unexpected escape '\\%c' in include string", c);
        }

        length++;

        if (length > kMaxPath)
            RaiseError("path is too long");
    }

    m_pos++; // Go past the right quote.

    ExpectEmptyRestOfLine();

    return std::string(&m_buffer[startPos], length);
}

// Reads a charmap string.
int AsmFile::ReadString(unsigned char* s)
{
    SkipWhitespace();

    int length;
    StringParser stringParser(m_buffer, m_size);

    try
    {
        m_pos += stringParser.ParseString(m_pos, s, length);
    }
    catch (std::runtime_error& e)
    {
        RaiseError(e.what());
    }

    SkipWhitespace();

    if (ConsumeComma())
    {
        SkipWhitespace();
        int padLength = ReadPadLength();

        while (length < padLength)
        {
            s[length++] = CHAR_SPACE;
        }
    }

    ExpectEmptyRestOfLine();

    return length;
}

void AsmFile::VerifyStringLength(int length)
{
    if (length == kMaxStringLength)
        RaiseError("mapped string longer than %d bytes", kMaxStringLength);
}

// int AsmFile::ReadBraille(unsigned char* s)
// {
//     static std::map<char/* char */, unsigned char> encoding =
//     {
//         { 'A', BRAILLE_CHAR_A },
//         { 'B', BRAILLE_CHAR_B },
//         { 'C', BRAILLE_CHAR_C },
//         { 'D', BRAILLE_CHAR_D },
//         { 'E', BRAILLE_CHAR_E },
//         { 'F', BRAILLE_CHAR_F },
//         { 'G', BRAILLE_CHAR_G },
//         { 'H', BRAILLE_CHAR_H },
//         { 'I', BRAILLE_CHAR_I },
//         { 'J', BRAILLE_CHAR_J },
//         { 'K', BRAILLE_CHAR_K },
//         { 'L', BRAILLE_CHAR_L },
//         { 'M', BRAILLE_CHAR_M },
//         { 'N', BRAILLE_CHAR_N },
//         { 'O', BRAILLE_CHAR_O },
//         { 'P', BRAILLE_CHAR_P },
//         { 'Q', BRAILLE_CHAR_Q },
//         { 'R', BRAILLE_CHAR_R },
//         { 'S', BRAILLE_CHAR_S },
//         { 'T', BRAILLE_CHAR_T },
//         { 'U', BRAILLE_CHAR_U },
//         { 'V', BRAILLE_CHAR_V },
//         { 'W', BRAILLE_CHAR_W },
//         { 'X', BRAILLE_CHAR_X },
//         { 'Y', BRAILLE_CHAR_Y },
//         { 'Z', BRAILLE_CHAR_Z },
//         { 'a', BRAILLE_CHAR_A },
//         { 'b', BRAILLE_CHAR_B },
//         { 'c', BRAILLE_CHAR_C },
//         { 'd', BRAILLE_CHAR_D },
//         { 'e', BRAILLE_CHAR_E },
//         { 'f', BRAILLE_CHAR_F },
//         { 'g', BRAILLE_CHAR_G },
//         { 'h', BRAILLE_CHAR_H },
//         { 'i', BRAILLE_CHAR_I },
//         { 'j', BRAILLE_CHAR_J },
//         { 'k', BRAILLE_CHAR_K },
//         { 'l', BRAILLE_CHAR_L },
//         { 'm', BRAILLE_CHAR_M },
//         { 'n', BRAILLE_CHAR_N },
//         { 'o', BRAILLE_CHAR_O },
//         { 'p', BRAILLE_CHAR_P },
//         { 'q', BRAILLE_CHAR_Q },
//         { 'r', BRAILLE_CHAR_R },
//         { 's', BRAILLE_CHAR_S },
//         { 't', BRAILLE_CHAR_T },
//         { 'u', BRAILLE_CHAR_U },
//         { 'v', BRAILLE_CHAR_V },
//         { 'w', BRAILLE_CHAR_W },
//         { 'x', BRAILLE_CHAR_X },
//         { 'y', BRAILLE_CHAR_Y },
//         { 'z', BRAILLE_CHAR_Z },
//         { '0', BRAILLE_CHAR_0 },
//         { '1', BRAILLE_CHAR_1 },
//         { '2', BRAILLE_CHAR_2 },
//         { '3', BRAILLE_CHAR_3 },
//         { '4', BRAILLE_CHAR_4 },
//         { '5', BRAILLE_CHAR_5 },
//         { '6', BRAILLE_CHAR_6 },
//         { '7', BRAILLE_CHAR_7 },
//         { '8', BRAILLE_CHAR_8 },
//         { '9', BRAILLE_CHAR_9 },
//         { ' ', BRAILLE_CHAR_SPACE },
//         { ',', BRAILLE_CHAR_COMMA },
//         { '.', BRAILLE_CHAR_PERIOD },
//         { '?', BRAILLE_CHAR_QUESTION_MARK },
//         { '!', BRAILLE_CHAR_EXCL_MARK },
//         { ':', BRAILLE_CHAR_COLON },
//         { ';', BRAILLE_CHAR_SEMICOLON },
//         { '-', BRAILLE_CHAR_HYPHEN },
//         { '/', BRAILLE_CHAR_SLASH },
//         { '(', BRAILLE_CHAR_PAREN },
//         { ')', BRAILLE_CHAR_PAREN },
//         { '\'', BRAILLE_CHAR_APOSTROPHE },
//         { '#', BRAILLE_CHAR_NUMBER },

//         // hebrew letters with multiple verses will use the lower eng alternatives
//         { U'א', BRAILLE_CHAR_A},
//         { U'ב', BRAILLE_CHAR_B},
//         // ב עם נק as V
//         { U'ג', BRAILLE_CHAR_G},
//         { U'ד', BRAILLE_CHAR_D},
//         { U'ה', BRAILLE_CHAR_H},
//         { U'ו', BRAILLE_CHAR_W}, 
//         // ו as O
//         // ו as U
//         { U'ז', BRAILLE_CHAR_Z},
//         { U'ח', BRAILLE_CHAR_X},
//         { U'ט', BRAILLE_CHAR_T},
//         { U'י', BRAILLE_CHAR_J},
//         // אי Xy as I
//         { U'כ', BRAILLE_CHAR_CHAF}, // Kaf
//         // Kaf as K
//         { U'ל', BRAILLE_CHAR_L},
//         { U'מ', BRAILLE_CHAR_M},
//         { U'נ', BRAILLE_CHAR_N},
//         { U'ס', BRAILLE_CHAR_S},
//         { U'ע', BRAILLE_CHAR_AYIN},
//         { U'פ', BRAILLE_CHAR_P},
//         // fey as F
//         { U'צ', BRAILLE_CHAR_TZADIK},
//         { U'ק', BRAILLE_CHAR_Q},
//         { U'ר', BRAILLE_CHAR_R},
//         { U'ש', BRAILLE_CHAR_SHIN},
//         { U'ץ', BRAILLE_CHAR_SIN}, // used for Sin
//         { U'ת', BRAILLE_CHAR_TAF},
//         { '$', EOS },
//     };

//     SkipWhitespace();

//     int length = 0;

//     if (m_buffer[m_pos] != '"')
//         RaiseError("expected braille string literal");

//     m_pos++;

//     bool inNumber = false;
//     while (m_buffer[m_pos] != '"')
//     {
//         if (m_buffer[m_pos] == '\\' && m_buffer[m_pos + 1] == 'n')
//         {
//             VerifyStringLength(length);
//             s[length++] = CHAR_NEWLINE;
//             m_pos += 2;
//         }
//         else
//         {
//             char c = m_buffer[m_pos];

//             if (encoding.count(c) == 0)
//             {
//                 if (IsAsciiPrintable(c))
//                     RaiseError("character '%c' not valid in braille string", m_buffer[m_pos]);
//                 else
//                     RaiseError("character '\\x%02X' not valid in braille string", m_buffer[m_pos]);
//             }

//             if (!inNumber && c >= '0' && c <= '9' )
//             {
//                 // Output number indicator at start of a number
//                 inNumber = true;
//                 VerifyStringLength(length);
//                 s[length++] = BRAILLE_CHAR_NUMBER;
//             }
//             else if (inNumber && encoding[c] == BRAILLE_CHAR_SPACE)
//             {
//                 // Number ends at a space.
//                 // Non-number characters encountered before a space will simply be output as is.
//                 inNumber = false;
//             }

//             VerifyStringLength(length);
//             s[length++] = encoding[c];
//             m_pos++;
//         }
//     }

//     m_pos++; // Go past the right quote.

//     ExpectEmptyRestOfLine();

//     return length;
// }
#include <cstring>

// ==========================================================
// Decode a single UTF-8 codepoint from the buffer.
// Member function: can call RaiseError
// ==========================================================
char32_t AsmFile::DecodeUtf8Codepoint(size_t &pos)
{
    size_t buf_len = strlen(m_buffer); // use size_t to match pos

    if (pos >= buf_len)
        RaiseError("utf8 decode out of range");

    unsigned char b0 = m_buffer[pos];
    char32_t cp = 0;

    if (b0 <= 0x7F) {
        cp = b0;
        pos += 1;
    }
    else if ((b0 & 0xE0) == 0xC0) {
        if (pos + 1 >= buf_len) RaiseError("invalid UTF-8");
        unsigned char b1 = m_buffer[pos + 1];
        if ((b1 & 0xC0) != 0x80) RaiseError("invalid UTF-8");
        cp = ((b0 & 0x1F) << 6) | (b1 & 0x3F);
        pos += 2;
    }
    else if ((b0 & 0xF0) == 0xE0) {
        if (pos + 2 >= buf_len) RaiseError("invalid UTF-8");
        unsigned char b1 = m_buffer[pos + 1];
        unsigned char b2 = m_buffer[pos + 2];
        if ((b1 & 0xC0) != 0x80 || (b2 & 0xC0) != 0x80) RaiseError("invalid UTF-8");
        cp = ((b0 & 0x0F) << 12) | ((b1 & 0x3F) << 6) | (b2 & 0x3F);
        pos += 3;
    }
    else if ((b0 & 0xF8) == 0xF0) {
        if (pos + 3 >= buf_len) RaiseError("invalid UTF-8");
        unsigned char b1 = m_buffer[pos + 1];
        unsigned char b2 = m_buffer[pos + 2];
        unsigned char b3 = m_buffer[pos + 3];
        if ((b1 & 0xC0) != 0x80 || (b2 & 0xC0) != 0x80 || (b3 & 0xC0) != 0x80)
            RaiseError("invalid UTF-8");
        cp = ((b0 & 0x07) << 18) | ((b1 & 0x3F) << 12) | ((b2 & 0x3F) << 6) | (b3 & 0x3F);
        pos += 4;
    }
    else {
        RaiseError("invalid UTF-8 start byte");
    }

    return cp;
}

// ==========================================================
// ReadBraille function: supports Hebrew + escapes + numbers
// ==========================================================
int AsmFile::ReadBraille(unsigned char* s)
{
    SkipWhitespace();

    if (m_buffer[m_pos] != '"')
        RaiseError("expected braille string literal");

    m_pos++; // skip opening quote
    int length = 0;
    bool inNumber = false;

    size_t buf_len = strlen(m_buffer);

    while ((size_t)m_pos < buf_len && m_buffer[m_pos] != '"') {

        // --- Escape handling ---
        if (m_buffer[m_pos] == '\\') {
            char next = m_buffer[m_pos + 1];
            if (next == 'n') {
                VerifyStringLength(length);
                s[length++] = CHAR_NEWLINE;
                m_pos += 2;
                continue;
            } else {
                RaiseError("unsupported escape sequence \\%c", next);
            }
        }

        // --- Decode UTF-8 codepoint ---
        size_t start_pos = m_pos;
        char32_t cp = DecodeUtf8Codepoint(start_pos); // member function
        m_pos = start_pos;

        unsigned char brailleChar = 0;

        // --- Map Latin letters ---
        switch (cp) {
            case U'A': case U'a': brailleChar = BRAILLE_CHAR_A; break;
            case U'B': case U'b': brailleChar = BRAILLE_CHAR_B; break;
            case U'C': case U'c': brailleChar = BRAILLE_CHAR_C; break;
            case U'D': case U'd': brailleChar = BRAILLE_CHAR_D; break;
            case U'E': case U'e': brailleChar = BRAILLE_CHAR_E; break;
            case U'F': case U'f': brailleChar = BRAILLE_CHAR_F; break;
            case U'G': case U'g': brailleChar = BRAILLE_CHAR_G; break;
            case U'H': case U'h': brailleChar = BRAILLE_CHAR_H; break;
            case U'I': case U'i': brailleChar = BRAILLE_CHAR_I; break;
            case U'J': case U'j': brailleChar = BRAILLE_CHAR_J; break;
            case U'K': case U'k': brailleChar = BRAILLE_CHAR_K; break;
            case U'L': case U'l': brailleChar = BRAILLE_CHAR_L; break;
            case U'M': case U'm': brailleChar = BRAILLE_CHAR_M; break;
            case U'N': case U'n': brailleChar = BRAILLE_CHAR_N; break;
            case U'O': case U'o': brailleChar = BRAILLE_CHAR_O; break;
            case U'P': case U'p': brailleChar = BRAILLE_CHAR_P; break;
            case U'Q': case U'q': brailleChar = BRAILLE_CHAR_Q; break;
            case U'R': case U'r': brailleChar = BRAILLE_CHAR_R; break;
            case U'S': case U's': brailleChar = BRAILLE_CHAR_S; break;
            case U'T': case U't': brailleChar = BRAILLE_CHAR_T; break;
            case U'U': case U'u': brailleChar = BRAILLE_CHAR_U; break;
            case U'V': case U'v': brailleChar = BRAILLE_CHAR_V; break;
            case U'W': case U'w': brailleChar = BRAILLE_CHAR_W; break;
            case U'X': case U'x': brailleChar = BRAILLE_CHAR_X; break;
            case U'Y': case U'y': brailleChar = BRAILLE_CHAR_Y; break;
            case U'Z': case U'z': brailleChar = BRAILLE_CHAR_Z; break;

            // --- Hebrew letters ---
            case U'א': brailleChar = BRAILLE_CHAR_A; break;
            case U'ב': brailleChar = BRAILLE_CHAR_B; break;
            case U'ג': brailleChar = BRAILLE_CHAR_G; break;
            case U'ד': brailleChar = BRAILLE_CHAR_D; break;
            case U'ה': brailleChar = BRAILLE_CHAR_H; break;
            case U'ו': brailleChar = BRAILLE_CHAR_W; break;
            case U'ז': brailleChar = BRAILLE_CHAR_Z; break;
            case U'ח': brailleChar = BRAILLE_CHAR_X; break;
            case U'ט': brailleChar = BRAILLE_CHAR_T; break;
            case U'י': brailleChar = BRAILLE_CHAR_J; break;
            case U'כ': brailleChar = BRAILLE_CHAR_CHAF; break;
            case U'ל': brailleChar = BRAILLE_CHAR_L; break;
            case U'מ': brailleChar = BRAILLE_CHAR_M; break;
            case U'נ': brailleChar = BRAILLE_CHAR_N; break;
            case U'ס': brailleChar = BRAILLE_CHAR_S; break;
            case U'ע': brailleChar = BRAILLE_CHAR_AYIN; break;
            case U'פ': brailleChar = BRAILLE_CHAR_P; break;
            case U'צ': brailleChar = BRAILLE_CHAR_TZADIK; break;
            case U'ק': brailleChar = BRAILLE_CHAR_Q; break;
            case U'ר': brailleChar = BRAILLE_CHAR_R; break;
            case U'ש': brailleChar = BRAILLE_CHAR_SHIN; break;
            case U'ץ': brailleChar = BRAILLE_CHAR_SIN; break;  // keep this
            case U'ת': brailleChar = BRAILLE_CHAR_TAF; break;

            // --- Symbols ---
            case U' ': brailleChar = BRAILLE_CHAR_SPACE; break;
            case U',': brailleChar = BRAILLE_CHAR_COMMA; break;
            case U'.': brailleChar = BRAILLE_CHAR_PERIOD; break;
            case U'?': brailleChar = BRAILLE_CHAR_QUESTION_MARK; break;
            case U'!': brailleChar = BRAILLE_CHAR_EXCL_MARK; break;
            case U':': brailleChar = BRAILLE_CHAR_COLON; break;
            case U';': brailleChar = BRAILLE_CHAR_SEMICOLON; break;
            case U'-': brailleChar = BRAILLE_CHAR_HYPHEN; break;
            case U'/': brailleChar = BRAILLE_CHAR_SLASH; break;
            case U'(': case U')': brailleChar = BRAILLE_CHAR_PAREN; break;
            case U'\'': brailleChar = BRAILLE_CHAR_APOSTROPHE; break;
            case U'#': brailleChar = BRAILLE_CHAR_NUMBER; break;
            case U'$': brailleChar = EOS; break;

            default:
                RaiseError("character U+%04X not valid in braille string", cp);
        }

        // --- Number indicator logic ---
        if (!inNumber && cp >= U'0' && cp <= U'9') {
            inNumber = true;
            VerifyStringLength(length);
            s[length++] = BRAILLE_CHAR_NUMBER;
        } else if (inNumber && brailleChar == BRAILLE_CHAR_SPACE) {
            inNumber = false;
        }

        VerifyStringLength(length);
        s[length++] = brailleChar;
    }

    m_pos++; // skip closing quote
    ExpectEmptyRestOfLine();
    return length;
}

// If we're at a comma, consumes it.
// Returns whether a comma was found.
bool AsmFile::ConsumeComma()
{
    if (m_buffer[m_pos] == ',')
    {
        m_pos++;
        return true;
    }

    return false;
}

// Converts digit character to numerical value.
static int ConvertDigit(char c, int radix)
{
    int digit;

    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'A' && c <= 'F')
        digit = 10 + c - 'A';
    else if (c >= 'a' && c <= 'f')
        digit = 10 + c - 'a';
    else
        return -1;

    return (digit < radix) ? digit : -1;
}

// Reads an integer. If the integer is greater than maxValue, it returns -1.
int AsmFile::ReadPadLength()
{
    if (!IsAsciiDigit(m_buffer[m_pos]))
        RaiseError("expected integer");

    int radix = 10;

    if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'x')
    {
        radix = 16;
        m_pos += 2;
    }

    unsigned n = 0;
    int digit;

    while ((digit = ConvertDigit(m_buffer[m_pos], radix)) != -1)
    {
        n = n * radix + digit;

        if (n > kMaxStringLength)
            RaiseError("pad length greater than maximum length (%d)", kMaxStringLength);

        m_pos++;
    }

    return n;
}

// Outputs the current line and moves to the next one.
void AsmFile::OutputLine()
{
    while (m_buffer[m_pos] != '\n' && m_buffer[m_pos] != 0)
        m_pos++;

    if (m_buffer[m_pos] == 0)
    {
        if (m_pos >= m_size)
        {
            RaiseWarning("file doesn't end with newline");
            puts(&m_buffer[m_lineStart]);
        }
        else
        {
            RaiseError("unexpected null character");
        }
    }
    else
    {
        m_buffer[m_pos] = 0;
        puts(&m_buffer[m_lineStart]);
        m_buffer[m_pos] = '\n';
        m_pos++;
        m_lineStart = m_pos;
        m_lineNum++;
    }
}

// parses an assumed C `enum`. Returns false if `enum { ...` is not matched
bool AsmFile::ParseEnum()
{
    if (!m_doEnum)
        return false;

    long fallbackPosition = m_pos;
    std::string headerFilename = "";
    long currentHeaderLine = SkipWhitespaceAndEol();
    std::string enumName = ReadIdentifier();
    currentHeaderLine += SkipWhitespaceAndEol();
    std::string enumBase = "0";
    long enumCounter = 0;
    long symbolCount = 0;

    if (m_buffer[m_pos] == ':') // : <type>
    {
        m_pos++;
        std::string underlyingType;
        do {
            currentHeaderLine += SkipWhitespaceAndEol();
            underlyingType = ReadIdentifier();
        } while (!underlyingType.empty());
        currentHeaderLine += SkipWhitespaceAndEol();
    }

    if (m_buffer[m_pos] != '{') // assume assembly macro, otherwise assume enum and report errors accordingly
    {
        m_pos = fallbackPosition - 4;
        return false;
    }

    currentHeaderLine += FindLastLineNumber(headerFilename);
    m_pos++;
    for (;;)
    {
        currentHeaderLine += SkipWhitespaceAndEol();
        std::string currentIdentName = ReadIdentifier();
        if (!currentIdentName.empty())
        {
            std::printf("# %ld \"%s\"\n", currentHeaderLine, headerFilename.c_str());
            currentHeaderLine += SkipWhitespaceAndEol();
            if (m_buffer[m_pos] == '=')
            {
                m_pos++;
                SkipWhitespace();
                enumBase.clear();
                for (;;)
                {
                    if (m_pos == m_size)
                        RaiseError("unexpected EOF");
                    if (m_buffer[m_pos] == ',')
                        break;
                    if (m_buffer[m_pos] == '\n')
                    {
                        currentHeaderLine++;
                        enumBase.push_back(' ');
                    }
                    else
                    {
                        enumBase.push_back(m_buffer[m_pos]);
                    }
                    m_pos++;
                }
                enumCounter = 0;
            }
            std::printf(".equiv %s, (%s) + %ld\n", currentIdentName.c_str(), enumBase.c_str(), enumCounter);
            enumCounter++;
            symbolCount++;
        }
        else if (symbolCount == 0)
        {
            RaiseError("%s:%ld: empty enum is invalid", headerFilename.c_str(), currentHeaderLine);
        }

        if (m_buffer[m_pos] == '#')
        {
            currentHeaderLine = ParseLineSkipInEnum();
        }
        else if (m_buffer[m_pos] != ',')
        {
            currentHeaderLine += SkipWhitespaceAndEol();
            if (m_buffer[m_pos++] == '}' && m_buffer[m_pos++] == ';')
            {
                ExpectEmptyRestOfLine();
                break;
            }
            else
            {
                RaiseError("unterminated enum from included file %s:%ld", headerFilename.c_str(), currentHeaderLine);
            }
        }
        m_pos++;
    }
    return true;
}

// Asserts that the rest of the line is empty and moves to the next one.
void AsmFile::ExpectEmptyRestOfLine()
{
    SkipWhitespace();

    if (m_buffer[m_pos] == 0)
    {
        if (m_pos >= m_size)
            RaiseWarning("file doesn't end with newline");
        else
            RaiseError("unexpected null character");
    }
    else if (m_buffer[m_pos] == '\n')
    {
        m_pos++;
        m_lineStart = m_pos;
        m_lineNum++;
    }
    else if (m_buffer[m_pos] == '\r' && m_buffer[m_pos + 1] == '\n')
    {
        m_pos += 2;
        m_lineStart = m_pos;
        m_lineNum++;
    }
    else
    {
        RaiseError("junk at end of line");
    }
}

// Checks if we're at the end of the file.
bool AsmFile::IsAtEnd()
{
    return (m_pos >= m_size);
}

// Output the current location to set gas's logical file and line numbers.
void AsmFile::OutputLocation()
{
    std::printf("# %ld \"%s\"\n", m_lineNum, m_filename.c_str());
}

// Reports a diagnostic message.
void AsmFile::ReportDiagnostic(const char* type, const char* format, std::va_list args)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];
    std::vsnprintf(buffer, bufferSize, format, args);
    std::fprintf(stderr, "%s:%ld: %s: %s\n", m_filename.c_str(), m_lineNum, type, buffer);
}

#define DO_REPORT(type)                   \
do                                        \
{                                         \
    std::va_list args;                    \
    va_start(args, format);               \
    ReportDiagnostic(type, format, args); \
    va_end(args);                         \
} while (0)

// Reports an error diagnostic and terminates the program.
void AsmFile::RaiseError(const char* format, ...)
{
    DO_REPORT("error");
    std::exit(1);
}

// Reports a warning diagnostic.
void AsmFile::RaiseWarning(const char* format, ...)
{
    DO_REPORT("warning");
}

// Skips Whitespace including newlines and returns the amount of newlines skipped
int AsmFile::SkipWhitespaceAndEol()
{
    int newlines = 0;
    while (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ' || m_buffer[m_pos] == '\r' || m_buffer[m_pos] == '\n')
    {
        if (m_buffer[m_pos] == '\n')
            newlines++;
        m_pos++;
    }
    return newlines;
}

int AsmFile::ParseLineSkipInEnum(void)
{
    m_pos++;
    while (m_buffer[m_pos] == ' ' || m_buffer[m_pos] == '\t')
        m_pos++;

     if (!IsAsciiDigit(m_buffer[m_pos]))
        RaiseError("malformatted line indicator found inside `enum`, expected line number");

    unsigned n = 0;
    int digit = 0;
    while ((digit = ConvertDigit(m_buffer[m_pos++], 10)) != -1)
        n = 10 * n + digit;

    while (m_buffer[m_pos] == ' ' || m_buffer[m_pos] == '\t')
        m_pos++;

    if (m_buffer[m_pos++] != '"')
        RaiseError("malformatted line indicator found before `enum`, expected filename");

    while (m_buffer[m_pos] != '"')
    {
        unsigned char c = m_buffer[m_pos++];

        if (c == 0)
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF in line indicator");
            else
                RaiseError("unexpected null character in line indicator");
        }

        if (!IsAsciiPrintable(c))
            RaiseError("unexpected character '\\x%02X' in line indicator", c);

        if (c == '\\')
        {
            c = m_buffer[m_pos];
            RaiseError("unexpected escape '\\%c' in line indicator", c);
        }
    }
    return n - 1;
}

// returns the last line indicator and its corresponding file name without modifying the token index
int AsmFile::FindLastLineNumber(std::string& filename)
{
    long pos = m_pos;
    long linebreaks = 0;
    while (m_buffer[pos] != '#' && pos >= 0)
    {
        if (m_buffer[pos] == '\n')
            linebreaks++;
        pos--;
    }

    if (pos < 0)
        RaiseError("line indicator for header file not found before `enum`");

    pos++;
    while (m_buffer[pos] == ' ' || m_buffer[pos] == '\t')
        pos++;

    if (!IsAsciiDigit(m_buffer[pos]))
        RaiseError("malformatted line indicator found before `enum`, expected line number");

    unsigned n = 0;
    int digit = 0;
    while ((digit = ConvertDigit(m_buffer[pos++], 10)) != -1)
        n = 10 * n + digit;

    while (m_buffer[pos] == ' ' || m_buffer[pos] == '\t')
        pos++;

    if (m_buffer[pos++] != '"')
        RaiseError("malformatted line indicator found before `enum`, expected filename");

    while (m_buffer[pos] != '"')
    {
        unsigned char c = m_buffer[pos++];

        if (c == 0)
        {
            if (pos >= m_size)
                RaiseError("unexpected EOF in line indicator");
            else
                RaiseError("unexpected null character in line indicator");
        }

        if (!IsAsciiPrintable(c))
            RaiseError("unexpected character '\\x%02X' in line indicator", c);

        if (c == '\\')
        {
            c = m_buffer[pos];
            RaiseError("unexpected escape '\\%c' in line indicator", c);
        }

        filename += c;
    }

    return n + linebreaks - 1;
}

std::string AsmFile::ReadIdentifier()
{
    long start = m_pos;
    if (!IsIdentifierStartingChar(m_buffer[m_pos]))
        return std::string();

    m_pos++;

    while (IsIdentifierChar(m_buffer[m_pos]))
        m_pos++;

    return std::string(&m_buffer[start], m_pos - start);
}

long AsmFile::ReadInteger(std::string filename, long line)
{
    bool negate = false;
    int radix = 10;
    if (!IsAsciiDigit(m_buffer[m_pos]))
    {
        if (m_buffer[m_pos++] == '-')
            negate = true;
        else
            RaiseError("expected number in included file %s:%ld", filename.c_str(), line);
    }

    if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'x')
    {
        radix = 16;
        m_pos += 2;
    }
    else if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'b')
    {
        radix = 2;
        m_pos += 2;
    }
    else if (m_buffer[m_pos] == '0' && IsAsciiDigit(m_buffer[m_pos+1]))
    {
        radix = 8;
        m_pos++;
    }

    long n = 0;
    int digit;

    while ((digit = ConvertDigit(m_buffer[m_pos], radix)) != -1)
    {
        n = n * radix + digit;
        m_pos++;
    }

    return negate ? -n : n;
}
