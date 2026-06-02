import re

# File paths - update these if your files are named differently or in other folders
C_ARRAY_FILE = "src/data/text/species_names.h"    # The file containing gSpeciesNamesLiteral
TRAINER_HILL_FILE = "src/data/battle_frontier/trainer_hill.h" # The file you want to update
OUTPUT_FILE = "src/data/battle_frontier/trainer_hill.h"      # Can overwrite, or use "trainer_hill_updated.h" to test

def load_species_mapping(c_file_path):
    """Parses ONLY the gSpeciesNamesLiteral array and returns a dict of {SPECIES_CONSTANT: LITERAL_NAME}"""
    species_map = {}
    
    # Flags to track if we are inside the correct array
    inside_target_array = False
    
    # Regex to match the start of the specific array
    start_pattern = re.compile(r'gSpeciesNamesLiteral')
    # Regex to match the entries: [SPECIES_BULBASAUR] = _("מוזרע"),
    entry_pattern = re.compile(r'\[([A-Z0-9_]+)\]\s*=\s*_\("([^"]+)"\)')
    
    with open(c_file_path, 'r', encoding='utf-8') as f:
        for line in f:
            # 1. Look for the start of gSpeciesNamesLiteral
            if not inside_target_array:
                if start_pattern.search(line):
                    inside_target_array = True
                continue # Skip processing until we are inside the target array
            
            # 2. If we are inside and hit the closing brace, stop parsing completely
            if inside_target_array and '};' in line:
                break
                
            # 3. Parse the entries within the target array
            match = entry_pattern.search(line)
            if match:
                species_id = match.group(1)
                literal_name = match.group(2)
                species_map[species_id] = literal_name
                
    return species_map

def update_trainer_hill(th_file_path, out_file_path, species_map):
    """Reads trainer_hill.h and updates .nickname based on the preceding .species"""
    with open(th_file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    updated_lines = []
    current_species = None
    
    # Regex to find .species = SPECIES_XYZ
    species_pattern = re.compile(r'\.species\s*=\s*([A-Z0-9_]+)')
    # Regex to find .nickname = _("...")
    nickname_pattern = re.compile(r'(\.nickname\s*=\s*_\(")([^"]*)("\))')

    for line in lines:
        # Check if this line defines a species
        species_match = species_pattern.search(line)
        if species_match:
            current_species = species_match.group(1)
            updated_lines.append(line)
            continue
        
        # Check if this line defines a nickname
        nickname_match = nickname_pattern.search(line)
        if nickname_match and current_species:
            # If we have a translation for the active species, swap it in
            if current_species in species_map:
                new_name = species_map[current_species]
                # Reconstruct the line preserving original indentation/spacing
                line = nickname_pattern.sub(rf'\1{new_name}\3', line)
            
            # Reset current_species tracking until we hit the next .species entry
            current_species = None
            
        updated_lines.append(line)

    # Write the modified content back out
    with open(out_file_path, 'w', encoding='utf-8') as f:
        f.writelines(updated_lines)

if __name__ == "__main__":
    print("Parsing species names...")
    try:
        mapping = load_species_mapping(C_ARRAY_FILE)
        print(f"Found {len(mapping)} species definitions.")
        
        print(f"Updating {TRAINER_HILL_FILE}...")
        update_trainer_hill(TRAINER_HILL_FILE, OUTPUT_FILE, mapping)
        print("Success! Nicknames have been synchronized.")
        
    except FileNotFoundError as e:
        print(f"Error: {e}. Please check your file paths.")