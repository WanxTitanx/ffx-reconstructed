#!/usr/bin/env python3
# probe8: classify chunk content across all target files with sliding anchors
import struct, sys, os
from collections import Counter
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import u16, i16, u32, read_dispatch

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
JPPC = os.path.join(ROOT, "ffx/master/jppc")
ALPHA = (0x80, 0x5B, 0xC8, 0x00)

def is_rgba(v):
    return (v >> 24) in ALPHA

def soup32_at(b, o):
    if o + 32 > len(b): return False
    cols = (u32(b,o+0x10), u32(b,o+0x14), u32(b,o+0x18))
    return all(is_rgba(c) for c in cols)

def paint20_at(b, o):
    if o + 20 > len(b): return False
    if u32(b, o) != 0x40: return False
    return all(is_rgba(u32(b, o+4+4*k)) for k in range(3))

def quad40_at(b, o):
    if o + 40 > len(b): return False
    if not all(is_rgba(u32(b, o+0x10+4*k)) for k in range(4)): return False
    # verts plausible: |s16| in [0, 0x8000) both components of each u32
    vs = [u32(b, o+4*k) for k in range(4)]
    def pl(v):
        x, z = v & 0xFFFF, v >> 16
        return 0 <= x < 0x8000 and 0 <= z < 0x8000
    return all(pl(v) for v in vs)

def range16_at(b, o):
    if o + 16 > len(b): return False
    a, c, d = u32(b, o), u32(b, o+4), u32(b, o+8)
    return 0 < a < c < 0x200000 and d < 0x10000 and (c - a) < 0x10000

def edge24_at(b, o):
    if o + 24 > len(b): return False
    if not all(is_rgba(u32(b, o+4*k)) for k in range(4)): return False
    return all(u16(b, o+0x10+2*k) < 0x1000 for k in range(4))

def classify_chunk(b, s, e):
    n = e - s
    best = ('other', 0, 0)
    for shape, size, fn in [('soup32',32,soup32_at), ('paint20',20,paint20_at),
                             ('quad40',40,quad40_at), ('range16',16,range16_at),
                             ('edge24',24,edge24_at)]:
        if n < size: continue
        # try anchors 0..6 (chunks may be misaligned vs record grids)
        for anchor in range(0, min(7, size)):
            cnt = 0; k = 0
            o = s + anchor
            while o + size <= e:
                if fn(b, o): cnt += 1
                o += size; k += 1
            if k and cnt >= max(1, int(k*0.6)):
                if cnt > best[1]:
                    best = (shape, cnt, k)
    return best

W = open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe8_classify.txt', 'w')
FILES = ["map/kami/kami03", "map/mtgz/mtgz00", "map/mtgz/mtgz01", "map/mtgz/mtgz02",
         "map/kino/kino04", "map/kino/kino05", "map/bsyt/bsyt01", "map/bsil/bsil00",
         "map/bvyt/bvyt09", "map/bvyt/bvyt11", "map/hiku/hiku18", "map/maca/maca00",
         "map/mcfr/mcfr01", "map/cdsp/cdsp00", "map/cdsp/cdsp07", "map/cdsp/cdsp08",
         "map/djyt/djyt04", "map/mihn/mihn00"]
stats = Counter()
for rel in FILES:
    path = os.path.join(JPPC, rel, "bin/mapout.vpa")
    b = open(path, 'rb').read()
    geom, meta, dabs, rows = read_dispatch(b)
    srows = sorted(rows, key=lambda r: r['off'])
    W.write('='*90 + '\n%s rows=%d\n' % (rel, len(srows)))
    for i, r in enumerate(srows):
        s, e = geom + r['off'], geom + r['off'] + 2*r['tag']
        shape, cnt, k = classify_chunk(b, s, e)
        stats[shape] += 1
        W.write('  [%02d] key=0x%04X tag=0x%04X sz=0x%03X -> %-8s %d/%d records\n' %
                (i, r['key'], r['tag'], e-s, shape, cnt, k))
W.write('\n== chunk shape stats: %s\n' % dict(stats))
W.close()
print(dict(stats))
