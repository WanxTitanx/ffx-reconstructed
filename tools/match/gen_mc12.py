#!/usr/bin/env python3
HDR = '#include <string.h>\nint __cdecl R(const void *p1, const void *p2)\n{\n'
TAIL_EQNE = '''    if (pa[1] > pb[1])
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
# L1: K24-head (pb==pa goto, pa>pb ret1) + eq/goto tail
'L1': ('''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
''', TAIL_EQNE),
# L2: same but assign pb-first
'L2': ('''    const unsigned *pa;
    const unsigned *pb;
    pb = (const unsigned *)p2;
    pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
''', TAIL_EQNE),
# L3: init pb-first
'L3': ('''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
''', TAIL_EQNE),
# L4: L1 with jb variant (pa<pb -> -1, fallthrough +1)
'L4': ('''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second0:
''', TAIL_EQNE),
# L5: L4 assign pb-first
'L5': ('''    const unsigned *pa;
    const unsigned *pb;
    pb = (const unsigned *)p2;
    pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second0:
''', TAIL_EQNE),
# L6: L4 init pb-first
'L6': ('''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second0:
''', TAIL_EQNE),
}
for name, (head, tail) in V.items():
    src = HDR + head + tail + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
