#!/usr/bin/env python3
# probe10: bsyt01 + cdsp00 chunk interiors (last unidentified layouts)
import sys, os
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import read_dispatch

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

W = open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe10_last.txt', 'w')
for rel, picks in [("map/bsyt/bsyt01", [0, 1, 4, 9]), ("map/cdsp/cdsp00", [0, 1, 2, 3, 4]),
                   ("map/bvyt/bvyt11", [0, 1]), ("map/hiku/hiku18", [0, 1]),
                   ("map/mcfr/mcfr01", [0, 3]), ("map/maca/maca00", [0, 1])]:
    b = open(os.path.join(JPPC, rel, "bin/mapout.vpa"), 'rb').read()
    geom, meta, dabs, rows = read_dispatch(b)
    srows = sorted(rows, key=lambda r: r['off'])
    W.write('='*90 + '\n%s rows=%d\n' % (rel, len(srows)))
    for i in picks:
        if i >= len(srows): continue
        r = srows[i]
        s, e = geom + r['off'], geom + r['off'] + 2*r['tag']
        W.write('-- chunk[%02d] key=0x%04X tag=0x%04X [0x%X..0x%X):\n' % (i, r['key'], r['tag'], s, e))
        W.write(hexdump(b, s, min(e-s, 0xB0)) + '\n')
W.close()
print('ok')
