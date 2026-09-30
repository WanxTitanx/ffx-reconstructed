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
# D7: D3-head + D-tail, pa-first mention in != (loads pa-first? D3 got ecx-first from p2-first mention... wait D3 mentions p2 first and got ecx=[ebp+8]... hmm D3 first load is ecx=[ebp+8]=p1. So p2-first mention gave p1-first loads?!)
# Actually D3: `if (p2[0] != p1[0])` -> mov ecx,[ebp+8] first. So mention order does NOT drive loads here. The compiler loads p1 (ecx) then p2 (esi).
# D7: swap mention to p1-first in !=
'D7': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D8: D7 with < (jb)
'D8': '''    if (((const unsigned *)p1)[0] != ((const unsigned *)p2)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    return 1;
second0:
''',
# D9: D3 with < (jb)
'D9': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    return 1;
second0:
''',
# D10: D3 with p2-left > (ja on swapped operands?)
'D10': '''    if (((const unsigned *)p2)[0] != ((const unsigned *)p1)[0])
        goto noshort;
    goto second0;
noshort:
    if (((const unsigned *)p2)[0] < ((const unsigned *)p1)[0])
        return 1;
    return -1;
second0:
''',
# D11: D3 but == single-goto (no double goto)
'D11': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    return -1;
second0:
''',
# D12: D11 with < form
'D12': '''    if (((const unsigned *)p2)[0] == ((const unsigned *)p1)[0])
        goto second0;
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
