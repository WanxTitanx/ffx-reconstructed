#!/usr/bin/env python3
HDR = '#include <string.h>\nint __cdecl R(const void *p1, const void *p2)\n{\n'
V = {
# L16: L15 with pa-first loads (mention pa first in ==)
'L16': '''    const unsigned *pa = (const unsigned *)p1;
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
# L17: L16 with < (jb) instead of > (ja)
'L17': '''    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pa[0] == pb[0])
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
# L18: L16 assign-order (decls then assigns, pa first)
'L18': '''    const unsigned *pa;
    const unsigned *pb;
    unsigned k;
    pa = (const unsigned *)p1;
    pb = (const unsigned *)p2;
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
# L19: L18 with pb-first assigns
'L19': '''    const unsigned *pa;
    const unsigned *pb;
    unsigned k;
    pb = (const unsigned *)p2;
    pa = (const unsigned *)p1;
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
# L20: L19 with pb-first == mention
'L20': '''    const unsigned *pa;
    const unsigned *pb;
    unsigned k;
    pb = (const unsigned *)p2;
    pa = (const unsigned *)p1;
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
    return memcmp(pa, pb, k - 4);
}''',
# L21: L20 init pb-first
'L21': '''    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
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
    return memcmp(pa, pb, k - 4);
}''',
}
for name, body in V.items():
    src = HDR + body + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
