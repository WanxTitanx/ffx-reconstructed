#!/usr/bin/env python3
# probe1: full dispatch + zone blob hexdump for F2/F3 exemplars
import struct, sys, os
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import (u16, i16, u32, read_dispatch, zone_rows, blob_shape,
                            decode_f3, scan_ring_stream)

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
TARGETS = [
    "ffx/master/jppc/map/mihn/mihn00/bin/mapout.vpa",
    "ffx/master/jppc/map/djyt/djyt04/bin/mapout.vpa",
    "ffx/master/jppc/map/kino/kino05/bin/mapout.vpa",
    "ffx/master/jppc/map/kami/kami03/bin/mapout.vpa",
    "ffx/master/jppc/map/mtgz/mtgz00/bin/mapout.vpa",
    "ffx/master/jppc/map/kino/kino04/bin/mapout.vpa",
    "ffx/master/jppc/map/bsyt/bsyt01/bin/mapout.vpa",
    "ffx/master/jppc/map/bsil/bsil00/bin/mapout.vpa",
]

def hexdump(b, start, length, base):
    out = []
    for i in range(0, length, 16):
        row = b[start+i:start+i+16]
        if len(row) == 0: break
        hx = ' '.join('%02x' % c for c in row)
        asc = ''.join(chr(c) if 32 <= c < 127 else '.' for c in row)
        out.append('%08X  %-47s  %s' % (base+i, hx, asc))
    return '\n'.join(out)

with open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe1_dispatch.txt', 'w') as W:
    for rel in TARGETS:
        path = os.path.join(ROOT, rel)
        b = open(path, 'rb').read()
        W.write('='*90 + '\n')
        W.write('%s size=0x%X\n' % (rel, len(b)))
        geom, meta, dabs, rows = read_dispatch(b)
        W.write('geom=0x%X meta=0x%X dispatch@0x%X rows=%d\n' % (geom, meta, dabs, len(rows)) if dabs else
                'geom=0x%X meta=0x%X NO DISPATCH\n' % (geom, meta))
        # ALL rows
        for i, r in enumerate(rows):
            W.write('  row[%02d] key=0x%04X tag=0x%04X off=0x%X blob=0x%X shape=%s\n' %
                    (i, r['key'], r['tag'], r['off'], r['blob'], blob_shape(b, r['blob'])))
        # zone blobs full hexdump 0x60 bytes
        zr = zone_rows(rows, b)
        for r in zr:
            W.write('  --- zone blob @0x%X (key=0x%X tag=0x%X) 0x60 bytes:\n' % (r['blob'], r['key'], r['tag']))
            W.write(hexdump(b, r['blob'], 0x60, r['blob']) + '\n')
print("done")
