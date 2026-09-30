#!/usr/bin/env python3
"""Find glyph indices of specific characters in the SJIS table."""
import sys
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

sjis = open(r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\menu\ffxsjistbl.bin", 'rb').read()
# glyph index -> SJIS code
glyph_to_sjis = {}
for i in range(0, len(sjis), 2):
    code = (sjis[i] << 8) | sjis[i+1]
    glyph_to_sjis[i//2] = code

# Build reverse: SJIS code -> glyph index
sjis_to_glyph = {v: k for k, v in glyph_to_sjis.items()}

# Characters of interest (katakana in tile order)
chars = "ア〇カキロハナニヌク十一ノフ二ヲセソ"
for ch in chars:
    code = ch.encode('shift_jis')
    sj = (code[0] << 8) | code[1]
    g = sjis_to_glyph.get(sj)
    print(f"{ch} SJIS=0x{sj:04X} glyph_index={g}")

print()
# Also show the glyph indices of the first 60 SJIS entries to see the order
print("First 60 glyph indices and their SJIS codes:")
for i in range(60):
    print(f"  [{i:3d}] 0x{glyph_to_sjis[i]:04X}", end='')
    if i % 5 == 4: print()
