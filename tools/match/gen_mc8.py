#!/usr/bin/env python3
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
# K2: K-shape but pb-first + canonical ja/jb second (like ref's ja/jb, not jbe/jae)
'K2_pb': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    while (pa[0] == pb[0]) {
        if (pb[0] > pa[0])
            return 1;
        goto second;
    }
    return -1;
second:
''',
# K3: while with != body
'K3_ne': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    while (pa[0] == pb[0]) {
        goto second;
    }
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K4: K-shape, pa-first, ja/jb via explicit > then <: compiler merged jne+branches?
'K4_jmp': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pa[0] == pb[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K5: K4 but pb-first loads (pb mentioned first via dummy use in condition order)
'K5_pbfirst': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K6: K5 with reversed branch (jb-shape)
'K6_pbjb': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second:
''',
# K7: two gotos (== and >), fallthrough -1
'K7_twogoto': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pa[0] == pb[0])
        goto second;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second:
''',
}
for name, head in V.items():
    src = HDR + head + TAIL + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
