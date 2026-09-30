#!/usr/bin/env python3
# probe5: full interior hexdump of every chunk for F3-family exemplars
import struct, sys, os
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import u16, i16, u32, read_dispatch

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
JPPC = os.path.join(ROOT, "ffx/master/jppc")

def hexdump(b, start, length):
    out = []
    for i in range(0, length, 16):
        row = b[start+i:start+i+16]
        if not row: break
        hx = ' '.join('%02x' % c for c in row)
        asc = ''.join(chr(c) if 32 <= c < 127 else '.' for c in row)
        out.append('%08X  %-47s  %s' % (start+i, hx, asc))
    return '\n'.join(out)

W = open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe5_interior.txt', 'w')
for rel, maxc in [("map/kami/kami03/bin/mapout.vpa", 6),
                  ("map/mtgz/mtgz00/bin/mapout.vpa", 6),
                  ("map/kino/kino04/bin/mapout.vpa", 2),
                  ("map/kino/kino05/bin/mapout.vpa", 6),
                  ("map/djyt/djyt04/bin/mapout.vpa", 4),
                  ("map/bsil/bsil00/bin/mapout.vpa", 5)]:
    b = open(os.path.join(JPPC, rel), 'rb').read()
    geom, meta, dabs, rows = read_dispatch(b)
    srows = sorted(rows, key=lambda r: r['off'])
    W.write('='*90 + '\n%s geom=0x%X rows=%d\n' % (rel, geom, len(rows)))
    for i, r in enumerate(srows[:maxc]):
        s, e = geom + r['off'], geom + r['off'] + 2*r['tag']
        W.write('-- chunk[%02d] key=0x%04X tag=0x%04X [0x%X..0x%X) sz=0x%X:\n' %
                (i, r['key'], r['tag'], s, e, 2*r['tag']))
        W.write(hexdump(b, s, min(e - s, 0x110)) + '\n')
W.close()
print('ok')
