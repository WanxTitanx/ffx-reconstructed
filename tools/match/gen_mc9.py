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
# K8: K_whileincr but pb-first (swap the while condition operands)
'K8_pbwhile': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    while (pb[0] == pa[0]) {
        if (pa[0] > pb[0])
            return 1;
        goto second;
    }
    return -1;
second:
''',
# K9: K8 with ja/jb-friendly body (explicit > then fallthrough -1)
'K9_pbjaw': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K10: K9 with assign-order swapped (pb assigned first)
'K10_assign': '''    const unsigned *pa;
    const unsigned *pb;
    pb = (const unsigned *)p2;
    pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K11: init pb-first
'K11_init': '''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K12: K11 with jb variant (return -1 first)
'K12_jb': '''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second:
''',
# K13: two-sided goto (== goes second, != falls to sign test like ref's ja/jb?)
'K13_twoside': '''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pa[0] == pb[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
}
for name, head in V.items():
    src = HDR + head + TAIL + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
