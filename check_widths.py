import os
import json
import re

class WidthChecker:
    def __init__(self, config_path):
        with open(config_path, 'r', encoding='utf-8') as f:
            self.config = json.load(f)
        
        self.default_font = self.config['defaultFontId']
        self.font_data = self.config['fonts'][self.default_font]
        self.widths = self.font_data['widths']
        self.max_width = self.font_data['maxLineLength']
        
        # Pre-compile replacements
        self.replacements = []
        for rep in self.config.get('textReplacements', []):
            pattern = rep['pattern']
            self.replacements.append((re.compile(pattern), rep['replacement']))

    def get_char_width(self, char):
        return self.widths.get(char, self.widths.get("default", 6))

    def calculate_width(self, text):
        # 1. Apply replacements
        for pattern, replacement in self.replacements:
            text = pattern.sub(replacement, text)
        
        total_width = 0
        i = 0
        while i < len(text):
            # Handle Control Codes like {STR_VAR_1}
            if text[i] == '{':
                end = text.find('}', i)
                if end != -1:
                    code = text[i:end+1]
                    total_width += self.widths.get(code, 0)
                    i = end + 1
                    continue
            
            # Handle standard chars
            total_width += self.get_char_width(text[i])
            i += 1
        return total_width

    def scan_scripts(self):
        base_path = os.path.join('data', 'maps')
        found_errors = False

        for root, dirs, files in os.walk(base_path):
            if 'scripts.inc' in files:
                file_path = os.path.join(root, 'scripts.inc')
                with open(file_path, 'r', encoding='utf-8') as f:
                    for line_num, line in enumerate(f, 1):
                        # Match .string "..."
                        match = re.search(r'\.string\s+"(.*)"', line)
                        if match:
                            raw_content = match.group(1)
                            
                            # Skip strings that are just terminal symbols
                            if raw_content == "$": continue

                            # Split by \n, \l, \p which reset the line width
                            segments = re.split(r'\\n|\\l|\\p', raw_content)
                            
                            for segment in segments:
                                width = self.calculate_width(segment)
                                if width > self.max_width:
                                    found_errors = True
                                    print(f"FAILED: {file_path}:{line_num}")
                                    print(f"  -> Width: {width}px (Limit: {self.max_width})")
                                    print(f"  -> Text:  {segment.strip()}\n")
        
        if not found_errors:
            print("All scripts passed! No line exceeds 208px.")

if __name__ == "__main__":
    checker = WidthChecker('font_config.json')
    checker.scan_scripts()