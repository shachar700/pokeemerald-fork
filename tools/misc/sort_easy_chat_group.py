import re
import locale

# =========================
# HEBREW SORT
# =========================

try:
    locale.setlocale(locale.LC_COLLATE, 'he_IL.UTF-8')
except locale.Error:
    try:
        locale.setlocale(locale.LC_COLLATE, 'Hebrew_Israel.1255')
    except locale.Error:
        print("WARNING: Hebrew locale not available, using default sorting.")

# =========================
# READ WORD DEFINITIONS
# =========================

print("Paste the const u8 list, then press Enter twice:\n")

word_lines = []

while True:
    line = input()
    if line == "":
        break
    word_lines.append(line)

word_text = "\n".join(word_lines)

# =========================
# READ STRUCT
# =========================

print("\nPaste the struct list, then press Enter twice:\n")

struct_lines = []

while True:
    line = input()
    if line == "":
        break
    struct_lines.append(line)

struct_text = "\n".join(struct_lines)

# =========================
# PARSE HEBREW WORDS
# =========================
# Example:
# const u8 gEasyChatWord_Dark[] = _("אופל");

word_pattern = re.compile(
    r'const u8 gEasyChatWord_(\w+)\[\]\s*=\s*_\("([^"]+)"\);'
)

hebrew_words = {}

for name, hebrew in word_pattern.findall(word_text):
    normalized = re.sub(r'_', '', name.upper())
    hebrew_words[normalized] = hebrew

# =========================
# PARSE STRUCT BLOCKS
# =========================

block_pattern = re.compile(
    r'(\[EC_INDEX\(EC_WORD_(.*?)\)\]\s*='
    r'\s*\{.*?\.enabled\s*=\s*(TRUE|FALSE),\s*\n\s*\},)',
    re.DOTALL
)

blocks = []

for full_block, word_name, enabled in block_pattern.findall(struct_text):

    normalized = re.sub(r'_', '', word_name.upper())

    hebrew = hebrew_words.get(normalized, "")

    blocks.append({
        "name": word_name,
        "hebrew": hebrew,
        "block": full_block,
    })

# =========================
# SORT BY HEBREW
# =========================

blocks.sort(
    key=lambda x: locale.strxfrm(x["hebrew"])
)

# =========================
# REBUILD STRUCT
# =========================

result = []

for i, entry in enumerate(blocks):

    block = entry["block"]

    # Replace [EC_INDEX(...)] with [0], [1], ...
    block = re.sub(
        r'\[EC_INDEX\(EC_WORD_.*?\)\]',
        f'[{i}]',
        block,
        count=1
    )

    # Replace alphabeticalOrder
    block = re.sub(
        r'\.alphabeticalOrder\s*=\s*EC_INDEX\(EC_WORD_.*?\)',
        f'.alphabeticalOrder = {i}',
        block
    )

    result.append(block)

# =========================
# OUTPUT
# =========================

print("\n".join(result))