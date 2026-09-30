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
# D43: D42 with < and > swapped (< first)
'D43': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
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
# D44: D43 trailing -1
'D44': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
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
# D45: D42 with == instead of != (single goto)
'D45': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return 1;
second0:
''',
# D46: D45 trailing -1
'D46': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D47: D42 with p1-first !=
'D47': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
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
# D48: D47 trailing -1
'D48': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
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
