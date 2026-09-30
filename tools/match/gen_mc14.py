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
# L13: L7-head + L-tail, plus early-clobber bait: extra dead use of esi BEFORE loads?
# Can't write esi in C. Instead: 3 live pointers (extra dummy) to force esi early.
'L13': ('''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pc = pa + 1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    (void)pc;
    return -1;
second0:
''', TAIL),
# L14: same but pc used in tail (kept live)
'L14': ('''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
''', TAIL),
# L15: L14 with len temp k (extra live int)
'L15': ('''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
''', '''    k = pa[1];
    if (k > pb[1])
        return 1;
    if (k == pb[1])
        goto second;
    return -1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, k - 4);
}'''),
}
for name, (head, tail) in V.items():
    src = HDR + head + tail + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
