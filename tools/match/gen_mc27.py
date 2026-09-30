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
# D55: D50 with > first (ja)
'D55': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
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
# D56: D55 trailing -1
'D56': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
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
# D57: D50 with == single-goto
'D57': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return 1;
second0:
''',
# D58: D57 trailing -1
'D58': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D59: D50 with p1-first !=
'D59': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
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
# D60: D59 trailing -1
'D60': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
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
