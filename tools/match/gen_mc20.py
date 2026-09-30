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
# D13: D8-head (je + sbb) + D-tail, but head == operands p2-first
'D13': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    return 1;
second0:
''',
# D14: D8 with > (ja)
'D14': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D15: plain == goto (no double-goto) + sbb-free sign via nested if (ja/jb, like ref!)
'D15': '''    if (((const unsigned *)p1)[0] == ((const unsigned *)p2)[0])
        goto second0;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    return 1;
second0:
''',
# D16: D15 with p2-first ==
'D16': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    return 1;
second0:
''',
# D17: D16 with < first (jb)
'D17': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D18: D8-head but tail uses != (alt)
'D18': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    return 1;
second0:
''',
}
for name, head in V.items():
    src = HDR + head + TAIL + '\n'
    open(f'/mnt/ssd-kingston/ffx-reconstructed/tools/match/mc6/{name}.c', 'w').write(src)
print('wrote', len(V))
