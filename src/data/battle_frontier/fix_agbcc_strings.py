import os
import re

def convert_file(file_path):
    if not os.path.exists(file_path):
        print(f"File not found: {file_path}")
        return

    print(f"Processing and overwriting {file_path}...")
    
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()

    # Pattern to find the big struct array declarations
    struct_array_pattern = re.compile(
        r'(const\s+struct\s+BattleFrontierTrainer\s+\w+\[[^\]]*\]\s*=\s*\{)(.*?)(\};)', 
        re.DOTALL
    )

    # Patterns to match individual trainer blocks inside the array
    entry_pattern = re.compile(r'(\[[A-Z0-9_]+\]\s*=\s*\{.*?\})', re.DOTALL)
    trainer_idx_pattern = re.compile(r'\[([A-Z0-9_]+)\]')
    trainer_name_pattern = re.compile(r'\.trainerName\s*=\s*_\("([^"]+)"\)')
    
    speech_fields = ['speechBefore', 'speechWin', 'speechLose']

    def process_large_struct(match):
        array_header = match.group(1)   # e.g., const struct BattleFrontierTrainer gBattleFrontierTrainers[...] = {
        array_body = match.group(2)     # Everything inside the braces
        array_footer = match.group(3)   # };

        all_declarations = []

        def process_trainer_entry(entry_match):
            block_text = entry_match.group(1)
            
            if "COMPOUND_STRING" not in block_text:
                return block_text

            idx_match = trainer_idx_pattern.search(block_text)
            name_match = trainer_name_pattern.search(block_text)
            
            if not idx_match:
                return block_text
                
            # Create a clean base name for the variables
            if name_match:
                base_var_name = name_match.group(1).title().replace('_', '')
            else:
                clean_idx = idx_match.group(1).replace('FRONTIER_TRAINER_', '').replace('_TENT_TRAINER_', '')
                base_var_name = clean_idx.title().replace('_', '')

            modified_block = block_text

            # Extract the strings out
            for field in speech_fields:
                field_regex = re.compile(r'\.' + field + r'\s*=\s*COMPOUND_STRING\("([^"]*)"\),?')
                field_match = field_regex.search(modified_block)
                
                if field_match:
                    string_content = field_match.group(1)
                    var_name = f"sText_{base_var_name}{field[6:]}" # e.g., sText_BradyBefore
                    
                    # Store string declaration globally for this struct
                    decl = f'static const u8 {var_name}[] = _("{string_content}");'
                    all_declarations.append(decl)
                    
                    # Replace macro layout inside the struct with the variable reference
                    modified_block = field_regex.sub(f'.{field} = {var_name},', modified_block)

            return modified_block

        # Step 1: Update every inner trainer block and pull out strings
        new_array_body = entry_pattern.sub(process_trainer_entry, array_body)

        # Step 2: Combine all accumulated string declarations
        formatted_declarations = "\n".join(all_declarations) + "\n\n"

        # Step 3: Piece together strings, followed by the original struct initialization block
        return formatted_declarations + array_header + new_array_body + array_footer

    # Perform structural modification over the data arrays
    new_content = struct_array_pattern.sub(process_large_struct, content)

    # Overwrite the existing file directly
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(new_content)
    print(f"Successfully modified {file_path} in-place!")

if __name__ == "__main__":
    convert_file("battle_frontier_trainers.h")
    convert_file("battle_tent.h")