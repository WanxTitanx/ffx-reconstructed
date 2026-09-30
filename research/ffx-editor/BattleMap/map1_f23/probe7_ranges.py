#!/usr/bin/env python3
# probe7: F2 range-table hypothesis — do 16B range records point into the ring stream?
import struct, sys, os
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import u16, i16, u32, read_dispatch, scan_ring_stream, decode_s16_stream

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
JPPC = os.path.join(ROOT, "ffx/master/jppc")
W = open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe7_ranges.txt', 'w')

for rel in ["map/mihn/mihn00/bin/mapout.vpa", "map/kino/kino05/bin/mapout.vpa", "map/djyt/djyt04/bin/mapout.vpa"]:
    b = open(os.path.join(JPPC, rel), 'rb').read()
    geom, meta, dabs, rows = read_dispatch(b)
    W.write('='*90 + '\n%s geom=0x%X meta=0x%X dabs=0x%X\n' % (rel, geom, meta, dabs))
    # ring stream
    cnt, s, e = scan_ring_stream(b, geom, meta if meta > geom else len(b))
    W.write('ring stream: tris=%d [0x%X..0x%X)\n' % (cnt, s, e))
    # collect 16B range-like records from chunks + post-chunk region
    # walk chunks
    srows = sorted(rows, key=lambda r: r['off'])
    for i, r in enumerate(srows):
        st, en = geom + r['off'], geom + r['off'] + 2*r['tag']
        # try 16B range records inside chunk
        n = (en - st) // 16
        for k in range(n):
            o = st + 16*k
            a, c, d2 = u32(b, o), u32(b, o+4), u32(b, o+8)
            if 0 < a < c < 0x100000 and d2 < 0x10000 and u16(b, o+12) < 0x100 and u16(b, o+14) < 0x100:
                W.write('  RANGE chunk[%d]+%d @0x%X: start=0x%X end=0x%X id=%d f=0x%X k=0x%X  (end-start=0x%X)\n'
                        % (i, 16*k, o, a, c, d2, u16(b, o+12), u16(b, o+14), c - a))
    # post-chunk scan for range runs
    last_end = geom + srows[-1]['off'] + 2*srows[-1]['tag']
    o = last_end
    runs = 0
    while o + 16 <= len(b) and o < last_end + 0x2000:
        a, c, d2 = u32(b, o), u32(b, o+4), u32(b, o+8)
        if 0 < a < c < 0x100000 and d2 < 0x10000:
            W.write('  RANGE post @0x%X (+%d from last chunk): start=0x%X end=0x%X id=%d f=0x%X k=0x%X\n'
                    % (o, o - last_end, a, c, d2, u16(b, o+12), u16(b, o+14)))
            runs += 1
            o += 16
        else:
            break
    W.write('  post-chunk run: %d range records\n' % runs)
    # test: do ring tris sit at ring_start + range.start?
    if cnt and runs:
        pass
W.close()
print('ok')
