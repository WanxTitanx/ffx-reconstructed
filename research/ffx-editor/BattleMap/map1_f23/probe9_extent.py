#!/usr/bin/env python3
# probe9: stream extents — how far do soup/paint streams reach before/after the chunk walk?
import struct, sys, os
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import u16, i16, u32, read_dispatch

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
JPPC = os.path.join(ROOT, "ffx/master/jppc")
ALPHA = (0x80, 0x5B, 0xC8, 0x00)

def is_rgba(v): return (v >> 24) in ALPHA

def soup_run(b, o, direction, limit):
    """Walk soup32 units forward(+1)/backward(-1) from o while valid; return (count, end_off)."""
    n = 0
    while 0 <= o and o + 32 <= len(b) and abs(o - limit) < 0x20000:
        cols = (u32(b, o+0x10), u32(b, o+0x14), u32(b, o+0x18))
        ok = all(is_rgba(c) for c in cols) and u16(b, o+2) == 0
        if not ok: break
        n += 1
        o += 32 * direction
    return n, o

def paint_run(b, o, direction, limit):
    n = 0
    while 0 <= o and o + 20 <= len(b):
        if u32(b, o) != 0x40: break
        if not all(is_rgba(u32(b, o+4+4*k)) for k in range(3)): break
        n += 1
        o += 20 * direction
    return n, o

W = open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe9_extent.txt', 'w')
for rel in ["map/kami/kami03", "map/mtgz/mtgz00", "map/kino/kino04", "map/bsil/bsil00",
            "map/bsyt/bsyt01", "map/mtgz/mtgz02", "map/bvyt/bvyt09", "map/hiku/hiku18",
            "map/maca/maca00", "map/mcfr/mcfr01", "map/cdsp/cdsp00"]:
    path = os.path.join(JPPC, rel, "bin/mapout.vpa")
    b = open(path, 'rb').read()
    geom, meta, dabs, rows = read_dispatch(b)
    srows = sorted(rows, key=lambda r: r['off'])
    first = geom + srows[0]['off']
    walk_end = geom + srows[-1]['off'] + 2*srows[-1]['tag']
    W.write('='*80 + '\n%s geom=0x%X dabs=0x%X walk=[0x%X..0x%X)\n' % (rel, geom, dabs, first, walk_end))
    # try both soup and paint from the walk start, and also backward
    for name, fn in [('soup', soup_run), ('paint', paint_run)]:
        size = 32 if name == 'soup' else 20
        nf, ef = fn(b, first, +1, len(b))
        nb, eb = fn(b, first, -1, len(b))
        # backward: eb is where it stopped (first invalid); stream start = eb + size
        W.write('  %s: fwd %d units to 0x%X | bwd %d units to 0x%X (start=0x%X)\n' %
                (name, nf, ef, nb, eb, eb + size if nb else first))
        # extend from walk_end too
        n2, e2 = fn(b, walk_end - (0 if nf else 0), +1, len(b)) if False else fn(b, walk_end, +1, len(b))
        W.write('  %s from walk_end: %d units to 0x%X (dabs=0x%X, delta=%+d)\n' %
                (name, n2, e2, dabs, dabs - e2))
W.close()
print('ok')
