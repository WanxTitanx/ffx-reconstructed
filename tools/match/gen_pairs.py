#!/usr/bin/env python3
"""16 if-pair combos: first-if x second-if, fixed tail."""

import os

IFS = {
    'palt': ('if (pa[0] > pb[0])\n        return 1;', 'if (pa[0] < pb[0])\n        return -1;'),
    'palt2': ('if (pa[0] < pb[0])\n        return -1;', 'if (pa[0] > pb[0])\n        return 1;'),
    'pb_ltgt': ('if (pb[0] < pa[0])\n        return 1;', 'if (pb[0] > pa[0])\n        return -1;'),
    'pb_gtlt': ('if (pb[0] > pa[0])\n        return -1;', 'if (pb[0] < pa[0])\n        return 1;'),
}

SECOND = '''if (pa[1] > pb[1])
        return 1;
    if (pa[1] != pb[1])
        return -1;
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, pa[-1] - 4);'''


def main():
    outdir = 'pairs'
    os.makedirs(outdir, exist_ok=True)
    n = 0
    for a, (ifa, ifa2) in IFS.items():
        for b, (ifb, ifb2) in IFS.items():
            name = f'p_{a}_{b}.c'
            src = '#include <string.h>\nint __cdecl P(const void *p1, const void *p2)\n{\n'
            src += '    const unsigned *pa = (const unsigned *)p1;\n    const unsigned *pb = (const unsigned *)p2;\n'
            for line in (ifa + '\n' + ifb).split('\n'):
                src += '    ' + line + '\n'
            for line in SECOND.split('\n'):
                src += ('    ' + line if line.strip() else '') + '\n'
            src += '}\n'
            open(os.path.join(outdir, name), 'w').write(src)
            n += 1
    print(f'wrote {n}')


if __name__ == '__main__':
    raise SystemExit(main())
