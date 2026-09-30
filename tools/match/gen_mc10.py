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
# K14: K8 minus while (plain if-goto, pb-first): does jne become short ja/jb?
'K14_ifgoto': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K15: K14 with reversed return order
'K15_revret': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second:
''',
# K16: K14 with != instead of == (inverts jne direction)
'K16_neq': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] != pa[0])
        goto noshort;
    goto second;
noshort:
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K17: assign-order pb-first + K14 body
'K17_assign': '''    const unsigned *pa;
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
# K18: init pb-first + K14 body
'K18_init': '''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second:
''',
# K19: K18 with < / return -1 first
'K19_lt': '''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
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
