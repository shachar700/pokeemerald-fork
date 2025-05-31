import re

# src/data/battle_frontier/battle_frontier_trainers.h for the other big file
INPUT_FILE = 'src/data/battle_frontier/battle_tent.h'
OUTPUT_FILE = 'src/data/battle_frontier/battle_tent_2.h'

SPECIAL_EC_WORD_MAP = {
    'EXCL': '!',
    'EXCL_EXCL': '!!',
    'QUES_EXCL': '?!',
    'QUES': '?',
    'ELLIPSIS': '…',
    'ELLIPSIS_EXCL': '…!',
    'ELLIPSIS_ELLIPSIS_ELLIPSIS': '………',
    'DASH': '-',
    'DASH_DASH_DASH': '- - -',
    'UH_OH': 'uh-oh',
    'WAAAH': 'waaah',
    'AHAHA': 'ahaha',
    'OH_QUES': 'oh?',
    'NOPE': 'nope',
    'URGH': 'urgh',
    'HMM': 'hmm',
    'WHOAH': 'whoah',
    'WROOOAAR_EXCL': 'wroooaar!',
    'WOW': 'wow',
    'GIGGLE': 'giggle',
    'SIGH': 'sigh',
    'UNBELIEVABLE': 'unbelievable',
    'CRIES': 'cries',
    'AGREE': 'agree',
    'EH_QUES': 'eh?',
    'CRY': 'cry',
    'EHEHE': 'ehehe',
    'OI_OI_OI': 'oi, oi, oi',
    'OH_YEAH': 'oh, yeah',
    'OH': 'oh',
    'OOPS': 'oops',
    'SHOCKED': 'shocked',
    'EEK': 'eek',
    'GRAAAH': 'graaah',
    'GWAHAHAHA': 'gwahahaha',
    'WAY': 'way',
    'TCH': 'tch',
    'HEHE': 'hehe',
    'HAH': 'hah',
    'YUP': 'yup',
    'HAHAHA': 'hahaha',
    'AIYEEH': 'aiyeeh',
    'HIYAH': 'hiyah',
    'FUFUFU': 'fufufu',
    'LOL': 'lol',
    'SNORT': 'snort',
    'HUMPH': 'humph',
    'HEHEHE': 'hehehe',
    'HEH': 'heh',
    'HOHOHO': 'hohoho',
    'UH_HUH': 'uh-huh',
    'OH_DEAR': 'oh, dear',
    'ARRGH': 'arrgh',
    'MUFUFU': 'mufufu',
    'MMM': 'mmm',
    'OH_KAY': 'oh-kay',
    'OKAY': 'okay',
    'LALALA': 'lalala',
    'YAY': 'yay',
    'AWW': 'aww',
    'WOWEE': 'wowee',
    'GWAH': 'gwah',
    'WAHAHAHA': 'wahahaha',
    'POKEMON': 'Pokémon',
}

CONTRACTION_MAP = {
    "can_t": "can't",
    "aren_t": "aren't",
    "isn_t": "isn't",
    "didn_t": "didn't",
    "don_t": "don't",
    "won_t": "won't",
    "I_am": "I'm",
    "you_re": "you're",
    "it_s": "it's",
    "we_re": "we're",
    "they_re": "they're",
    "doesn_t": "doesn't",
    "haven_t": "haven't",
    "hasn_t": "hasn't",
    "wouldn_t": "wouldn't",
    "shouldn_t": "shouldn't",
    "couldn_t": "couldn't",
    "mustn_t": "mustn't",
    "I_ll": "I'll",
    "you_ll": "you'll",
    "he_ll": "he'll",
    "she_ll": "she'll",
    "we_ll": "we'll",
    "they_ll": "they'll",
    "I_ve": "I've",
    "you_ve": "you've",
    "we_ve": "we've",
    "they_ve": "they've",
    "didn’t": "didn't",
}

def format_move_or_pokemon(name: str) -> str:
    return ' '.join(part.capitalize() for part in name.split('_'))

def fix_contractions(text: str) -> str:
    for k, v in CONTRACTION_MAP.items():
        text = re.sub(r'\b' + re.escape(k) + r'\b', v, text, flags=re.IGNORECASE)

    # Fix contractions written without underscores
    text = re.sub(r"\b([A-Za-z]+)\s+t\b", lambda m: m.group(1) + "'t", text, flags=re.IGNORECASE)
    text = re.sub(r"\b([A-Za-z]+)\s+re\b", lambda m: m.group(1) + "'re", text, flags=re.IGNORECASE)
    text = re.sub(r"\b([A-Za-z]+)\s+ll\b", lambda m: m.group(1) + "'ll", text, flags=re.IGNORECASE)
    text = re.sub(r"\b([A-Za-z]+)\s+d\b", lambda m: m.group(1) + "'d", text, flags=re.IGNORECASE)
    text = re.sub(r"\b([A-Za-z]+)\s+s\b", lambda m: m.group(1) + "'s", text, flags=re.IGNORECASE)
    text = re.sub(r"\b([A-Za-z]+)\s+ve\b", lambda m: m.group(1) + "'ve", text, flags=re.IGNORECASE)

    # Fix lowercase "i" when it's alone
    text = re.sub(r'\bi\b', 'I', text)

    return text

def smart_capitalize(text: str) -> str:
    def cap(match):
        return match.group(1) + match.group(2).upper()

    if text:
        text = text[0].upper() + text[1:]

    text = re.sub(r'([.!?…]\s+)([a-z])', cap, text)

    # Add a period if it ends without proper punctuation
    if not re.search(r'[.!?…]$', text):
        text += '.'

    return text


def convert_token(tok: str) -> str:
    tok = tok.strip()

    if tok.lower() == 'ec_empty_word':
        return ''

    if tok.startswith('EC_WORD_'):
        key = tok[len('EC_WORD_'):]
        if key in SPECIAL_EC_WORD_MAP:
            return SPECIAL_EC_WORD_MAP[key]
        else:
            return key.lower().replace('_', ' ')

    if tok.startswith('EC_MOVE(') or tok.startswith('EC_MOVE2('):
        inside = tok[tok.find('(')+1:-1]
        return inside.lower().replace('_', ' ')

    if tok.startswith('EC_POKEMON(') or tok.startswith('EC_POKEMON_NATIONAL('):
        inside = tok[tok.find('(')+1:-1]
        return format_move_or_pokemon(inside)

    if '_' in tok:
        return tok.replace('_', ' ')

    return tok.lower()

def convert_easychat_line(line: str) -> str:
    if line.lstrip().startswith('.moves'): # this is specifically for battle_tent.h file
        return line  # skip lines starting with ".moves"
    
    var_match = re.match(r'(\s*\.\w+\s*=\s*){(.*)}', line)
    if not var_match:
        return line

    prefix, content = var_match.groups()
    tokens = [tok.strip() for tok in content.split(',')]
    words = []

    for tok in tokens:
        converted = convert_token(tok)
        if converted:
            words.append(converted)

    sentence = ' '.join(words)
    sentence = re.sub(r'\s+([!?.,…])', r'\1', sentence)

    sentence = fix_contractions(sentence)
    sentence = smart_capitalize(sentence)

    return f'{prefix}_(\"{sentence}\"),'

def convert_file_content(content: str) -> str:
    lines = content.splitlines()
    return '\n'.join(convert_easychat_line(line) for line in lines)

if __name__ == "__main__":
    with open(INPUT_FILE, 'r', encoding='utf-8') as f:
        content = f.read()

    converted_content = convert_file_content(content)

    with open(OUTPUT_FILE, 'w', encoding='utf-8') as f:
        f.write(converted_content)

    print(f"Converted file saved as {OUTPUT_FILE}")
