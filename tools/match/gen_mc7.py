#!/usr/bin/env python3
"""mc7: push-esi-early triggers. esi must be WRITTEN 2nd. What C writes esi 2nd?"""
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
# I: use esi explicitly? can't. Use 3 pointer locals to force callee-saved use
'I_3ptr': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pc = pa;
    if (pa[0] > pb[0])
        return 1;
    if (pa[0] < pb[0])
        return -1;
''',
# J: loop-carried pointer (esi typical for loop index/pointer under /O2)
'J_forloop': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    int i;
    for (i = 0; i < 1; i++) {
        if (pa[0] > pb[0])
            return 1;
        if (pa[0] < pb[0])
            return -1;
    }
''',
# K: memcmp-style while with pointer increments (esi idiom)
'K_whileincr': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    while (pa[0] == pb[0]) {
        if (pa[0] > pb[0])
            return 1;
        goto second;
    }
    return -1;
second:
''',
# L: do-while(0) wrapper (forces single-iteration region, often esi)
'L_dowhile0': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    do {
        if (pa[0] > pb[0])
            return 1;
        if (pa[0] < pb[0])
            return -1;
    } while (0);
''',
# M: switch on compare result (jump-table-free small switch -> ja/jb chain?)
'M_switch': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    int c = (pa[0] > pb[0]) - (pa[0] < pb[0]);
    switch (c) {
    case 1: return 1;
    case -1: return -1;
    }
''',
# N: early push via nested function-scope block with extra local (forces frame shuffling)
'N_block': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    {
        unsigned x = pa[0], y = pb[0];
        if (x > y)
            return 1;
        if (x < y)
            return -1;
    }
''',
# O: compare via helper macro style with !! normalization
'O_bang': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (!!(pa[0] > pb[0]))
        return 1;
    if (!!(pa[0] < pb[0]))
        return -1;
''',
# P: reversed compare order in source (jb-shape first) to see if ja/jb flips with push
'P_revorder': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pa[0] < pb[0])
        return -1;
    if (pa[0] > pb[0])
        return 1;
''',
}
for name, head in V.items():
    src = HDR + head + TAIL + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
