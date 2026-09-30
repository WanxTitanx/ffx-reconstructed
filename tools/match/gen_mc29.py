#!/usr/bin/env python3
HDR = '#include <string.h>\nint __cdecl R(const void *p1, const void *p2)\n{\n'
TAIL = '''    if (((const unsigned *)p1)[1] > ((const unsigned *)p2)[1])
        return 1;
    if (((const unsigned *)p1)[1] == ((const unsigned *)p2)[1])
        goto second;
    return -1;
second:
    p1 = (const void *)((const unsigned *)p1 + 2);
    p2 = (const void *)((const unsigned *)p2 + 2);
    return memcmp(p1, p2, ((const unsigned *)p1)[-1] - 4);
}'''
V = {
# D67: D62 with > first (ja)
'D67': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    return 1;
second0:
''',
# D68: D67 trailing -1
'D68': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    return -1;
second0:
''',
# D69: D62 with == single-goto
'D69': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return 1;
second0:
''',
# D70: D69 trailing -1
'D70': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D71: D62 with p1-first !=
'D71': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return 1;
second0:
''',
# D72: D71 trailing -1
'D72': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
}
for name, head in V.items():
    src = HDR + head + TAIL + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
