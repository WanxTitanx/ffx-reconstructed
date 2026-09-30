#!/usr/bin/env python3
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
# K20: K16 with pa-first loads (assign pa first? inits already pa-first... K16 inits pa,pa-first... hmm K16 got pb-first loads from `pb[0] != pa[0]` first mention)
# To flip loads pa-first: mention pa first: `if (pa[0] != pb[0]) goto noshort; goto second;'
'K20_pafirst': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pa[0] != pb[0])
        goto noshort;
    goto second;
noshort:
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K21: K20 with jb variant
'K21_pafirst_jb': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pa[0] != pb[0])
        goto noshort;
    goto second;
noshort:
    if (pa[0] < pb[0])
        return -1;
    return 1;
second:
''',
# K22: reversed gotos (second first)
'K22_revgoto': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pa[0] == pb[0])
        goto second;
    goto noshort;
second:
    goto third;
noshort:
    if (pa[0] > pb[0])
        return 1;
    return -1;
third:
''',
# K23: K16-shape but sbb-inducing compare is != on SECOND dword instead (move sbb out of head)
'K23_cleanhead': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pa[0] == pb[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K24: K23 with pb-first mention in == (loads pb-first, cmp pa-first?)
'K24_pbload': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K25: K24 with assign pb-first
'K25_pbassign': '''    const unsigned *pa;
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
}
for name, head in V.items():
    src = HDR + head + TAIL + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
