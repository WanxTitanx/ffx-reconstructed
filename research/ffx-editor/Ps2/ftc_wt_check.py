#!/usr/bin/env python3
"""Check width table at glyph indices of tile glyphs."""
import sys
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

# FIX 2026-09-15 (FFX-STRUCTURES validation): rebase hardcoded corpus paths from
# the old Windows layout (D:\FFX Extracted\...) to the Linux corpus mount; same
# files, same bytes, only the mount point changed.
ftc = open(r"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/base.ftc", 'rb').read()
wptr = int.from_bytes(ftc[0x30:0x34], 'little')
wsize = int.from_bytes(ftc[0x34:0x38], 'little')
wt = ftc[wptr:wptr+wsize]

# glyph index -> char
sjis = open(r"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/ffxsjistbl.bin", 'rb').read()
chars = {}
for i in range(0, len(sjis), 2):
    code = (sjis[i] << 8) | sjis[i+1]
    try:
        ch = bytes([sjis[i], sjis[i+1]]).decode('shift_jis')
    except Exception:
        ch = '?'
    chars[i//2] = ch

# tiles in order with their glyph indices (from previous analysis)
tiles = [
    (0, 'ア', 128), (1, '〇', None), (2, 'カ', 137), (3, 'キ', 139),
    (4, 'ロ', 203), (5, 'ハ', 173), (6, 'ナ', 168), (7, 'ニ', 169),
    (8, 'ヌ', 170), (9, 'ク', 141), (10, '十', 893), (11, '一', 267),
    (12, 'ノ', 172), (13, 'フ', 179), (14, '二', 558), (15, 'ヲ', 205),
    (16, 'セ', 153), (17, 'ソ', 155),
]
print("tile | char | glyph_idx | wt[glyph_idx] | wt[tile]")
for t, ch, g in tiles:
    wg = wt[g] if g is not None else '?'
    wtile = wt[t]
    print(f"  {t:3d} |  {ch}  |  {str(g):>4}  |  {str(wg):>4}  |  {wtile}")

# Also check: does wt match the glyph order for the first 60?
print("\nwidth table first 60 vs glyph chars:")
for i in range(60):
    print(f"  wt[{i:3d}]={wt[i]:2d} {chars.get(i,'?')}", end='')
    if i % 6 == 5: print()
