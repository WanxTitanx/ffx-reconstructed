#!/usr/bin/env python3
# probe4: 32B unit grid analysis for F3 files + full hexdumps of chunk regions
import struct, sys, os
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import u16, i16, u32, read_dispatch

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
JPPC = os.path.join(ROOT, "ffx/master/jppc")
REL_LO, REL_HI = 0x80000000, 0x82000000

def units_in(b, start, end):
    """Parse 32B units in [start,end): return list of dicts."""
    out = []
    o = start
    while o + 32 <= end:
        relocs = (u32(b, o+0x10), u32(b, o+0x14), u32(b, o+0x18))
        ok = all(REL_LO <= r < REL_HI for r in relocs)
        out.append({'off': o, 'id': u16(b, o), 'pad': u16(b, o+2),
                    'verts': [(i16(b,o+4),i16(b,o+6)),(i16(b,o+8),i16(b,o+10)),(i16(b,o+0xC),i16(b,o+0xE))],
                    'relocs': ['%08X'%r for r in relocs], 'idx': (u16(b,o+0x1C), u16(b,o+0x1E)),
                    'band': ok})
        o += 32
    return out

W = open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe4_units.txt', 'w')
for rel in ["map/kami/kami03/bin/mapout.vpa", "map/mtgz/mtgz00/bin/mapout.vpa",
            "map/kino/kino04/bin/mapout.vpa", "map/bsyt/bsyt01/bin/mapout.vpa",
            "map/bsil/bsil00/bin/mapout.vpa", "map/mihn/mihn00/bin/mapout.vpa",
            "map/djyt/djyt04/bin/mapout.vpa", "map/kino/kino05/bin/mapout.vpa"]:
    b = open(os.path.join(JPPC, rel), 'rb').read()
    geom, meta, dabs, rows = read_dispatch(b)
    srows = sorted(rows, key=lambda r: r['off'])
    W.write('='*90 + '\n%s geom=0x%X rows=%d\n' % (rel, geom, len(rows)))
    for i, r in enumerate(srows[:14]):
        s, e = geom + r['off'], geom + r['off'] + 2*r['tag']
        us = units_in(b, s, e)
        nband = sum(1 for u in us if u['band'])
        ids = [u['id'] for u in us]
        pads = sorted(set(u['pad'] for u in us))
        idxs = [u['idx'] for u in us]
        W.write('  [%02d] key=0x%04X tag=0x%04X chunk=[0x%X,0x%X) sz=0x%X  units=%d band=%d ids=%s pads=%s idxmax=%s tail2=%s\n' %
                (i, r['key'], r['tag'], s, e, 2*r['tag'], len(us), nband, ids[:10], pads[:4],
                 max((max(u['idx']) for u in us), default=None),
                 b[e-2:e].hex() if e <= len(b) else '?'))
W.close()
print('ok')
