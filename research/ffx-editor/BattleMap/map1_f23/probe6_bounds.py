#!/usr/bin/env python3
# probe6: region before/after chunks + meta block, for stream-boundary derivation
import struct, sys, os
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import u16, i16, u32, read_dispatch

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
JPPC = os.path.join(ROOT, "ffx/master/jppc")
REL_LO, REL_HI = 0x80000000, 0x82000000

def hexdump(b, start, length):
    out = []
    for i in range(0, length, 16):
        row = b[start+i:start+i+16]
        if not row: break
        hx = ' '.join('%02x' % c for c in row)
        asc = ''.join(chr(c) if 32 <= c < 127 else '.' for c in row)
        out.append('%08X  %-47s  %s' % (start+i, hx, asc))
    return '\n'.join(out)

W = open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe6_bounds.txt', 'w')
JOBS = [
    ("map/kami/kami03/bin/mapout.vpa", "BEFORE", 0x235100, 0x90),
    ("map/kami/kami03/bin/mapout.vpa", "AFTER-CHUNKS", 0x235510, 0x100),
    ("map/kami/kami03/bin/mapout.vpa", "META", None, None),
    ("map/mihn/mihn00/bin/mapout.vpa", "BEFORE", 0x3BEA00, 0x180),
    ("map/mihn/mihn00/bin/mapout.vpa", "AFTER", 0x3BEC20, 0x100),
    ("map/mihn/mihn00/bin/mapout.vpa", "META", None, None),
    ("map/kino/kino05/bin/mapout.vpa", "META", None, None),
    ("map/mtgz/mtgz00/bin/mapout.vpa", "BEFORE", 0x204180, 0xB0),
    ("map/mtgz/mtgz00/bin/mapout.vpa", "AFTER", 0x204480, 0x100),
    ("map/mtgz/mtgz00/bin/mapout.vpa", "META", None, None),
]
for rel, label, s, l in JOBS:
    b = open(os.path.join(JPPC, rel), 'rb').read()
    geom, meta, dabs, rows = read_dispatch(b)
    if label == "META":
        W.write('='*90 + '\n%s META @0x%X (0x100 bytes):\n' % (rel, meta))
        W.write(hexdump(b, meta, 0x100) + '\n')
    else:
        W.write('='*90 + '\n%s %s @0x%X:\n' % (rel, label, s))
        W.write(hexdump(b, s, l) + '\n')
W.close()
print('ok')
