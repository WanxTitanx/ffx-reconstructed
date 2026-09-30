#!/usr/bin/env python3
# probe3: targeted hexdumps around the record stream (sorted-by-offset walk + contiguity)
import struct, sys, os
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import u16, u32, read_dispatch

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
TARGETS = {
    "map/kami/kami03/bin/mapout.vpa": [(0x235190, 0x2A0), (0x235290, 0x100)],
    "map/mihn/mihn00/bin/mapout.vpa": [(0x3BEB70, 0x140)],
    "map/mtgz/mtgz00/bin/mapout.vpa": None,
    "map/kino/kino04/bin/mapout.vpa": None,
    "map/bsyt/bsyt01/bin/mapout.vpa": None,
    "map/bsil/bsil00/bin/mapout.vpa": None,
}

def hexdump(b, start, length):
    out = []
    for i in range(0, length, 16):
        row = b[start+i:start+i+16]
        if not row: break
        hx = ' '.join('%02x' % c for c in row)
        asc = ''.join(chr(c) if 32 <= c < 127 else '.' for c in row)
        out.append('%08X  %-47s  %s' % (start+i, hx, asc))
    return '\n'.join(out)

W = open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe3_hex.txt', 'w')
for rel, regions in TARGETS.items():
    b = open(os.path.join(ROOT, 'ffx/master/jppc', rel), 'rb').read()
    geom, meta, dabs, rows = read_dispatch(b)
    srows = sorted(rows, key=lambda r: r['off'])
    W.write('='*90 + '\n%s  geom=0x%X meta=0x%X dabs=0x%X rows=%d\n' % (rel, geom, meta, dabs, len(rows)))
    # sorted walk + contiguity check
    W.write("-- sorted walk: key tag off -> next_off_expected(off+2*tag)\n")
    for i, r in enumerate(srows):
        end = r['off'] + 2*r['tag']
        nxt = srows[i+1]['off'] if i+1 < len(srows) else None
        ok = 'OK' if nxt == end else ('LAST' if nxt is None else 'GAP %+d' % (nxt - end))
        W.write('  [%02d] key=0x%04X tag=0x%04X off=0x%06X blob=0x%06X end=0x%06X %s\n' %
                (i, r['key'], r['tag'], r['off'], geom + r['off'], geom + end, ok))
    if regions:
        for (s, l) in regions:
            W.write('-- hexdump 0x%X..0x%X:\n' % (s, s+l))
            W.write(hexdump(b, s, l) + '\n')
W.close()
print('ok')
