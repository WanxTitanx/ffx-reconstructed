#!/usr/bin/env python3
HDR = '#include <string.h>\nint __cdecl R(const void *p1, const void *p2)\n{\n'
TAIL = '''    if (pa[1] > pb[1])
        return 1;
    if (pa[1] == pb[1])
        goto second;
    return -1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, pa[-1] - 4);
}'''
V = {
# L7: L1-head (== goto + > ret1) + eq/goto tail. Predict: jne-short + ja/jb?
'L7': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
''',
# L8: L7 with < variant
'L8': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second0:
''',
# L9: L7 assign pb-first
'L9': '''    const unsigned *pa;
    const unsigned *pb;
    pb = (const unsigned *)p2;
    pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
''',
# L10: L8 assign pb-first
'L10': '''    const unsigned *pa;
    const unsigned *pb;
    pb = (const unsigned *)p2;
    pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second0:
''',
# L11: L7 init pb-first
'L11': '''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
''',
# L12: L8 init pb-first
'L12': '''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second0:
''',
}
for name, head in V.items():
    src = HDR + head + TAIL + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
