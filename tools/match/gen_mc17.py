#!/usr/bin/env python3
HDR = '#include <string.h>\nint __cdecl R(const void *p1, const void *p2)\n{\n'
V = {
# L26: L15 but head == is pa==pb (pa mentioned first) -- tests whether == order flips loads
'L26': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pa[0] == pb[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
    k = pa[1];
    if (k > pb[1])
        return 1;
    if (k == pb[1])
        goto second;
    return -1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, k - 4);
}''',
# L27: L15 but head == is pa==pb AND > is pb>pa (mixed)
'L27': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pa[0] == pb[0])
        goto second0;
    if (pb[0] < pa[0])
        return 1;
    return -1;
second0:
    k = pa[1];
    if (k > pb[1])
        return 1;
    if (k == pb[1])
        goto second;
    return -1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, k - 4);
}''',
# L28: L15 but > is pb<pa form
'L28': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pb[0] == pa[0])
        goto second0;
    if (pb[0] < pa[0])
        return 1;
    return -1;
second0:
    k = pa[1];
    if (k > pb[1])
        return 1;
    if (k == pb[1])
        goto second;
    return -1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, k - 4);
}''',
# L29: L28 with < form (jb)
'L29': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second0:
    k = pa[1];
    if (k > pb[1])
        return 1;
    if (k == pb[1])
        goto second;
    return -1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, k - 4);
}''',
}
for name, body in V.items():
    src = HDR + body + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
