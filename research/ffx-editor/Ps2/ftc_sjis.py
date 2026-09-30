#!/usr/bin/env python3
"""Decode ffxsjistbl.bin entries as SJIS (big-endian) and analyze width table."""
import struct, sys
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

# FIX 2026-09-15 (FFX-STRUCTURES validation): rebase hardcoded corpus path from
# the old Windows layout (D:\FFX Extracted\...) to the Linux corpus mount; same
# file, same bytes, only the mount point changed.
sjis = open(r"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/ffxsjistbl.bin", 'rb').read()
print(f"SJIS table: {len(sjis)} bytes = {len(sjis)//2} u16 BE entries")
decoded = []
for i in range(0, len(sjis), 2):
    code = (sjis[i] << 8) | sjis[i+1]
    try:
        ch = bytes([sjis[i], sjis[i+1]]).decode('shift_jis')
    except Exception:
        ch = '?'
    decoded.append((i//2, code, ch))

for idx, code, ch in decoded[:100]:
    print(f"  glyph[{idx:3d}] = 0x{code:04X} = {ch}")
