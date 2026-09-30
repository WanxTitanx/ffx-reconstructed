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
# D1: p2-first == goto, pa-first > ret1
'D1': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D2: D1 with jb form
'D2': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    return 1;
second0:
''',
# D3: != double-goto
'D3': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D4: control - p1-first ==
'D4': '''    if (((const unsigned *)p1)[0] == ((const unsigned *)p2)[0])
        goto second0;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D5: p2-first ==, > with p2-left operands (commute test)
'D5': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p2)[0] < ((const unsigned *)p1)[0])
        return 1;
    return -1;
second0:
''',
# D6: D1 but second if uses != (alt tail entry, control)
'D6': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
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
