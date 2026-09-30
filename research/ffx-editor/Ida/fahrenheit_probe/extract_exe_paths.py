#!/usr/bin/env python3
"""Lote 12: extrai paths de arquivos das strings do exe (indice do filesystem do jogo).

Procura strings com padroes de path (data/, .bin, .phyre, .pak, .mvr, etc.) na regiao
de strings do exe e salva um JSON.
"""
import ida_bytes
import json
import re

STR_START = 0x400000
STR_END = 0x1400000
PATTERNS = [
    rb"[A-Za-z0-9_./\\-]{6,}\.(?:bin|BIN|phyre|PHYRE|pak|PAK|mvr|MVR|dat|DAT|txt|TXT|ini|INI|csv|CSV|spr|SPR|ps2|PS2|iso|ISO|rg|RG|tm2|TM2|tim|TIM|seq|SEQ|mld|MLD)",
    rb"data/[A-Za-z0-9_./\\-]{4,}",
    rb"menu/[A-Za-z0-9_./\\-]{4,}",
    rb"battle/[A-Za-z0-9_./\\-]{4,}",
    rb"field/[A-Za-z0-9_./\\-]{4,}",
]


def main():
    raw = ida_bytes.get_bytes(STR_START, STR_END - STR_START) or b""
    found = set()
    for pat in PATTERNS:
        for m in re.finditer(pat, raw):
            s = m.group().decode("ascii", "replace")
            if len(s) >= 6 and s not in found:
                found.add(s)
    print(f"paths unicos: {len(found)}", flush=True)
    for s in sorted(found)[:40]:
        print(f"  {s}", flush=True)
    with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\exe_file_paths.json", "w", encoding="utf-8") as f:
        json.dump(sorted(found), f, indent=1)


if __name__ == "__main__":
    main()
