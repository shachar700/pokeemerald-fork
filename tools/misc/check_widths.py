import re

# Define the maximum allowed width
MAX_WIDTH = 204
# Default width for characters not explicitly defined
DEFAULT_WIDTH = 6 

# Character width dictionary initialized with your JSON data
CHAR_WIDTHS = {
    " ": 3, "À": 6, "Á": 6, "Â": 6, "Ç": 6, "È": 6, "É": 6, "Ê": 6, "Ë": 6, "Ì": 6, 
    "Î": 6, "Ï": 6, "Ò": 6, "Ó": 6, "Ô": 6, "Œ": 8, "Ù": 6, "Ú": 6, "Û": 6, "Ñ": 6, 
    "ß": 6, "à": 6, "á": 6, "ç": 6, "è": 6, "é": 6, "ê": 6, "ë": 6, "ì": 6, "î": 6, 
    "ï": 6, "ò": 6, "ó": 6, "ô": 6, "œ": 8, "ù": 6, "ú": 6, "û": 6, "ñ": 6, "º": 6, 
    "ª": 6, "{SUPER_ER}": 9, "&": 7, "+": 6, "LV": 10, "=": 8, ";": 3, "¿": 6, "¡": 4, 
    "{PK}": 8, "{PKMN}": 16, "{POKEBLOCK}": 35, "Í": 6, "%": 6, "(": 4, ")": 4, "â": 6, 
    "í": 6, "{UNK_SPACER}": 6, "{UP_ARROW}": 7, "{DOWN_ARROW}": 7, "{LEFT_ARROW}": 7, 
    "{RIGHT_ARROW}": 7, "{SUPER_E}": 6, "<": 6, ">": 6, "{SUPER_RE}": 8, "0": 6, "1": 6, 
    "2": 6, "3": 6, "4": 6, "5": 6, "6": 6, "7": 6, "8": 6, "9": 6, "!": 4, "?": 6, 
    ".": 3, "-": 6, "·": 3, "…": 6, "“": 6, "”": 6, "‘": 3, "'": 3, "♂": 6, "♀": 6, 
    "¥": 6, ",": 3, "×": 7, "/": 6, "A": 6, "B": 6, "C": 6, "D": 6, "E": 6, "F": 6, 
    "G": 6, "H": 6, "I": 6, "J": 6, "K": 6, "L": 6, "M": 6, "N": 6, "O": 6, "P": 6, 
    "Q": 6, "R": 6, "S": 6, "T": 6, "U": 6, "V": 6, "W": 6, "X": 6, "Y": 6, "Z": 6, 
    "a": 6, "b": 6, "c": 6, "d": 6, "e": 6, "f": 6, "g": 6, "h": 6, "i": 4, "j": 5, 
    "k": 6, "l": 4, "m": 6, "n": 6, "o": 6, "p": 6, "q": 6, "r": 5, "s": 6, "t": 6, 
    "u": 6, "v": 6, "w": 6, "x": 6, "y": 6, "z": 6, "▶": 8, ":": 5, "Ä": 6, "Ö": 6, 
    "Ü": 6, "ä": 6, "ö": 6, "ü": 6, "{TALL_PLUS}": 0, "{PLAYER}": 42, "{STR_VAR_1}": 80, 
    "{STR_VAR_2}": 80, "{STR_VAR_3}": 80, "{KUN}": 0, "{RIVAL}": 56, "{VERSION}": 56, 
    "{AQUA}": 24, "{MAGMA}": 30, "{ARCHIE}": 36, "{MAXIE}": 30, "{KYOGRE}": 36, 
    "{GROUDON}": 42, "$": 0
}

# Add custom Hebrew rules (Range \u0590 to \u05fe includes standard letters)
HEBREW_EXCEPTIONS = {
    'ג': 5,
    'ו': 3,
    'ז': 4,
    'י': 3,
    'ן': 3,
    'נ': 5
}

def get_char_width(char: str) -> int:
    """Returns the width of an individual character based on mapping tables."""
    if 'א' <= char <= 'ת':  # Checks if it's a Hebrew letter
        return HEBREW_EXCEPTIONS.get(char, 6)
    return CHAR_WIDTHS.get(char, DEFAULT_WIDTH)

def calculate_string_width(text: str) -> int:
    """Calculates total pixel width of a string while respecting special bracket tokens."""
    total_width = 0
    i = 0
    n = len(text)
    
    while i < n:
        # Check for bracketed tokens like {PKMN}
        if text[i] == '{':
            end_idx = text.find('}', i)
            if end_idx != -1:
                token = text[i:end_idx+1]
                total_width += CHAR_WIDTHS.get(token, DEFAULT_WIDTH)
                i = end_idx + 1
                continue
        
        # Standard character calculation
        total_width += get_char_width(text[i])
        i += 1
        
    return total_width

def main():
    # Regex to grab content inside _("...")
    string_pattern = re.compile(r'_\("([^"]*)"\)')
    
    try:
        with open('input.txt', 'r', encoding='utf-8') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print("Error: 'input.txt' not found. Please create it in the same directory.")
        return

    over_limit_count = 0
    print(f"{'LINE':<6} | {'WIDTH':<5} | {'STATUS':<8} | {'VARIABLE/TEXT'}")
    print("-" * 70)

    for line_num, line in enumerate(lines, 1):
        line = line.strip()
        if not line:
            continue
            
        match = string_pattern.search(line)
        if match:
            extracted_text = match.group(1)
            # Find the variable name for cleaner console feedback
            var_match = re.search(r'sText_\w+', line)
            var_name = var_match.group(0) if var_match else "UnknownVar"
            
            # Handle string line breaks (like \n) if necessary
            # For strict engine dialogue constraints, split on '\n' to measure single-line maximums
            sub_lines = extracted_text.split('\\n')
            
            for sub_idx, sub_line in enumerate(sub_lines):
                width = calculate_string_width(sub_line)
                display_name = f"{var_name}[L{sub_idx+1}]" if len(sub_lines) > 1 else var_name
                
                if width > MAX_WIDTH:
                    over_limit_count += 1
                    status = "❌ FAIL"
                    print(f"{line_num:<6} | {width:<5} | {status:<8} | {display_name}: \"{sub_line}\"")
                else:
                    # Optional: Uncomment if you want to see passing strings too
                    # status = "✅ PASS"
                    # print(f"{line_num:<6} | {width:<5} | {status:<8} | {display_name}")
                    pass

    print("-" * 70)
    if over_limit_count == 0:
        print("All strings passed the font width limits successfully!")
    else:
        print(f"Validation complete. Found {over_limit_count} instance(s) exceeding {MAX_WIDTH}px.")

if __name__ == '__main__':
    main()