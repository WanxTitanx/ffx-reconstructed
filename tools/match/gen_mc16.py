#!/usr/bin/env python3
HDR = '#include <string.h>\nint __cdecl R(const void *p1, const void *p2)\n{\n'
V = {
# L22: L15-head + L15-second, but memcmp args swapped (test arg-order effect on head)
'L22': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pb[0] == pa[0])
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
    return memcmp(pb, pa, k - 4);
}''',
# L23: L22 with len from pb (k = pb[1])
'L23': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
    k = pb[1];
    if (k > pa[1])
        return 1;
    if (k == pa[1])
        goto second;
    return -1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, k - 4);
}''',
# L24: L15 with second using pb/k swapped (k compared as second operand)
'L24': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] > pb[0])
        return 1;
    return -1;
second0:
    k = pa[1];
    if (pb[1] < k)
        return -1;
    if (pb[1] == k)
        goto second;
    return 1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, k - 4);
}''',
# L25: L15 with head == operands swapped (pa==pb instead of pb==pa)
'L25': '''    const unsigned *pa = (const unsigned *)p1;
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
}
for name, body in V.items():
    src = HDR + body + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
