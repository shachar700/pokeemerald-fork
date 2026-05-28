import re

# File paths
MOVES_FILE = 'move_names.h'
WORDS_FILE = 'gEasyChatWord.txt'
SPECIES_FILE = 'species_names.h'
EC_WORDS_FILE = 'EC_WORD.txt'
OUTPUT_FILE = 'EC_WORD2.c'

# Mapping Hebrew starting letters to your struct's English letters
HEBREW_TO_ENG = {
    'א': 'A', 'ב': 'B', 'ג': 'C', 'ד': 'D', 'ה': 'E', 'ו': 'F',
    'ז': 'G', 'ח': 'H', 'ט': 'I', 'י': 'J', 'כ': 'K', 'ך': 'K',
    'ל': 'L', 'מ': 'M', 'ם': 'M', 'נ': 'N', 'ן': 'N', 'ס': 'P',
    'ע': 'Q', 'פ': 'R', 'ף': 'R', 'צ': 'T', 'ץ': 'T', 'ק': 'U',
    'ר': 'W', 'ש': 'X', 'ת': 'Y'
}

# Used to generate the comments in the final struct
ENG_TO_HEB_COMMENT = {
    'A': 'א', 'B': 'ב', 'C': 'ג', 'D': 'ד', 'E': 'ה', 'F': 'ו',
    'G': 'ז', 'H': 'ח', 'I': 'ט', 'J': 'י', 'K': 'כ', 'L': 'ל',
    'M': 'מ', 'N': 'נ', 'O': 'סמלים', 'P': 'ס', 'Q': 'ע', 'R': 'פ', 
    'S': '', 'T': 'צ', 'U': 'ק', 'V': '', 'W': 'ר', 'X': 'ש', 'Y': 'ת'
}

# The complete list of struct arrays to output
ALL_LETTERS = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y']

def normalize_key(s):
    # e.g., "CantWin" -> "CANTWIN", "CAN_T_WIN" -> "CANTWIN"
    return re.sub(r'[^A-Z0-9]', '', s.upper())

def get_target_array(translated_str):
    if not translated_str:
        return 'O'
    first_char = translated_str.strip()[0]
    return HEBREW_TO_ENG.get(first_char, 'O')

def main():
    # 1. Parse Moves
    moves_dict = {}
    with open(MOVES_FILE, 'r', encoding='utf-8') as f:
        for line in f:
            match = re.search(r'\[MOVE_(.+?)\]\s*=\s*_\("(.*?)"\)', line)
            if match:
                moves_dict[match.group(1)] = match.group(2)

    # 2. Parse Words
    words_dict = {}
    with open(WORDS_FILE, 'r', encoding='utf-8') as f:
        for line in f:
            match = re.search(r'gEasyChatWord_([A-Za-z0-9_]+)\[\]\s*=\s*_\("(.*?)"\)', line)
            if match:
                words_dict[normalize_key(match.group(1))] = match.group(2)

    # 3. Parse Species
    species_lit = {}
    species_trans = {}
    current_dict = None
    with open(SPECIES_FILE, 'r', encoding='utf-8') as f:
        for line in f:
            if 'gSpeciesNamesLiteral' in line:
                current_dict = species_lit
            elif 'gSpeciesNamesTranslit' in line:
                current_dict = species_trans
            
            if current_dict is not None:
                match = re.search(r'\[SPECIES_(.+?)\]\s*=\s*_\("(.*?)"\)', line)
                if match:
                    current_dict[match.group(1)] = match.group(2)

    # 4. Extract all items from EC_WORD.txt
    all_items = []
    with open(EC_WORDS_FILE, 'r', encoding='utf-8') as f:
        lines = [line.strip() for line in f if line.strip()]
        
    i = 0
    while i < len(lines):
        line = lines[i]
        
        if line.startswith('const') or line.startswith('{') or line.startswith('}') or line.startswith('//'):
            i += 1
            continue
            
        if line == 'DOUBLE_SPECIES_NAME':
            block = [line, lines[i+1], lines[i+2]]
            sp_match = re.search(r'EC_POKEMON(?:_NATIONAL)?\((.+?)\)', lines[i+1])
            key = sp_match.group(1) if sp_match else "???"
            
            lit_str = species_lit.get(key, key)
            trans_str = species_trans.get(key, key)
            
            all_items.append({'lines': block, 'lit_str': lit_str, 'trans_str': trans_str})
            i += 3
        else:
            block = [line]
            clean_item = line.strip(',')
            lit_str = trans_str = clean_item
            
            if clean_item.startswith('EC_WORD_'):
                key = normalize_key(clean_item[8:])
                lit_str = trans_str = words_dict.get(key, clean_item)
            elif clean_item.startswith('EC_MOVE'):
                m_match = re.search(r'\((.+?)\)', clean_item)
                if m_match:
                    lit_str = trans_str = moves_dict.get(m_match.group(1), clean_item)
            elif clean_item.startswith('EC_POKEMON'):
                p_match = re.search(r'\((.+?)\)', clean_item)
                if p_match:
                    key = p_match.group(1)
                    lit_str = species_lit.get(key, clean_item)
                    trans_str = species_trans.get(key, clean_item)
                    
            all_items.append({'lines': block, 'lit_str': lit_str, 'trans_str': trans_str})
            i += 1

    # 5. Redistribute to groups based on first Hebrew letter
    lit_groups = {letter: [] for letter in ALL_LETTERS}
    trans_groups = {letter: [] for letter in ALL_LETTERS}

    for item in all_items:
        # Literal mode targeting
        lit_letter = get_target_array(item['lit_str'])
        lit_groups[lit_letter].append(item)
        
        # Translit mode targeting
        trans_letter = get_target_array(item['trans_str'])
        trans_groups[trans_letter].append(item)

    # 6. Output Generation
    with open(OUTPUT_FILE, 'w', encoding='utf-8') as out_f:
        struct_entries = []

        for letter in ALL_LETTERS:
            # Sort internally by the translated string
            lit_sorted = sorted(lit_groups[letter], key=lambda x: x['lit_str'])
            trans_sorted = sorted(trans_groups[letter], key=lambda x: x['trans_str'])
            
            # Flatten lists to just the raw C macros
            lit_lines = [line for item in lit_sorted for line in item['lines']]
            trans_lines = [line for item in trans_sorted for line in item['lines']]
            
            is_different = (lit_lines != trans_lines)
            
            # Write Arrays
            if is_different:
                out_f.write(f"const u16 gEasyChatWordsByLetter_{letter}_Literal[] = {{\n")
                if not lit_lines: out_f.write("    0 // Empty\n")
                for line in lit_lines: out_f.write(f"    {line},\n" if not line.endswith(',') else f"    {line}\n")
                out_f.write("};\n\n")
                
                out_f.write(f"const u16 gEasyChatWordsByLetter_{letter}_Translit[] = {{\n")
                if not trans_lines: out_f.write("    0 // Empty\n")
                for line in trans_lines: out_f.write(f"    {line},\n" if not line.endswith(',') else f"    {line}\n")
                out_f.write("};\n\n")
                
                struct_entries.append((letter, True))
            else:
                out_f.write(f"const u16 gEasyChatWordsByLetter_{letter}[] = {{\n")
                if not lit_lines: out_f.write("    0 // Empty\n")
                for line in lit_lines: out_f.write(f"    {line},\n" if not line.endswith(',') else f"    {line}\n")
                out_f.write("};\n\n")
                
                struct_entries.append((letter, False))

        # Write Final Struct
        out_f.write("const struct EasyChatWordsByLetter gEasyChatWordsByLetter[] = {\n")
        for letter, is_diff in struct_entries:
            comment_text = ENG_TO_HEB_COMMENT.get(letter, '')
            comment = f" //{comment_text}" if comment_text else ""
            
            if is_diff:
                out_f.write("#ifdef TRANSLIT_SPECIES\n")
                out_f.write("    {\n")
                out_f.write(f"        .words = gEasyChatWordsByLetter_{letter}_Translit,{comment}\n")
                out_f.write(f"        .numWords = ARRAY_COUNT(gEasyChatWordsByLetter_{letter}_Translit),\n")
                out_f.write("    },\n")
                out_f.write("#else\n")
                out_f.write("    {\n")
                out_f.write(f"        .words = gEasyChatWordsByLetter_{letter}_Literal,{comment}\n")
                out_f.write(f"        .numWords = ARRAY_COUNT(gEasyChatWordsByLetter_{letter}_Literal),\n")
                out_f.write("    },\n")
                out_f.write("#endif\n")
            else:
                out_f.write("    {\n")
                out_f.write(f"        .words = gEasyChatWordsByLetter_{letter},{comment}\n")
                out_f.write(f"        .numWords = ARRAY_COUNT(gEasyChatWordsByLetter_{letter}),\n")
                out_f.write("    },\n")
                
        out_f.write("};\n")

    print(f"Success! Redistributed words to arrays based on Hebrew alphabet and saved to {OUTPUT_FILE}")

if __name__ == "__main__":
    main()