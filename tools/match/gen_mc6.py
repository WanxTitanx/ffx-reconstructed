#!/usr/bin/env python3
"""mc6: pa/pb-pointer variants to force push-esi-early + cmp-pa-first."""
import os
HDR = '#include <string.h>\nint __cdecl R(const void *p1, const void *p2)\n{\n'
TAIL = '''    if (pa[1] > pb[1])
        return 1;
    if (pa[1] != pb[1])
        return -1;
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, pa[-1] - 4);
}'''
V = {
# A: pb-first + explicit esi use via inline asm-free trick: compare through *pb++ style post-increment?
'A_incr': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned a0 = *pa++;
    unsigned b0 = *pb++;
    if (b0 < a0)
        return 1;
    if (b0 > a0)
        return -1;
''',
# B: comma-expression forcing order: load pb first into named temp used in cmp second position
'B_comma': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned b0, a0;
    b0 = pb[0], a0 = pa[0];
    if (a0 > b0)
        return 1;
    if (a0 < b0)
        return -1;
''',
# C: nested-if form (single cmp, ja/jb out of one compare)
'C_nested': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pa[0] != pb[0]) {
        if (pa[0] > pb[0])
            return 1;
        return -1;
    }
''',
# D: ternary-free sign via subtraction (tests sbb path, likely jae/ja -- control)
'D_sub': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pa[0] != pb[0])
        return pa[0] > pb[0] ? 1 : -1;
''',
# E: pb-first loads via use in earlier statement (touch pb first, then pa-compare)
'E_touch': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    (void)pb;
    if (pa[0] > pb[0])
        return 1;
    if (pa[0] < pb[0])
        return -1;
''',
# F: reversed assignment order with pa-first compare
'F_revassign': '''    const unsigned *pa;
    const unsigned *pb;
    pb = (const unsigned *)p2;
    pa = (const unsigned *)p1;
    if (pa[0] > pb[0])
        return 1;
    if (pa[0] < pb[0])
        return -1;
''',
# G: single-temp for b0, compare pa[0] against temp (forces pb load first, cmp pa-first)
'G_temp': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned b0 = pb[0];
    if (pa[0] > b0)
        return 1;
    if (pa[0] < b0)
        return -1;
''',
# H: volatile-free but address-taken locals (forces stack homes, changes regalloc)
'H_addrtaken': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    const unsigned **ppa = &pa;
    if ((*ppa)[0] > pb[0])
        return 1;
    if ((*ppa)[0] < pb[0])
        return -1;
''',
}
for name, head in V.items():
    src = HDR + head + TAIL + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
