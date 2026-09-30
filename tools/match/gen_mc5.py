#!/usr/bin/env python3
"""Prologue grid with fixed ne-second + sign_pa tail."""

import os

HEADS = {
    'gt_lt': 'if (pa[0] > pb[0])\n        return 1;\n    if (pa[0] < pb[0])\n        return -1;',
    'gtlt_pb': 'if (pb[0] < pa[0])\n        return 1;\n    if (pb[0] > pa[0])\n        return -1;',
    'ltgt_pb': 'if (pb[0] > pa[0])\n        return -1;\n    if (pb[0] < pa[0])\n        return 1;',
}

PROLOGUES = {
    'init_ab': 'const unsigned *pa = (const unsigned *)p1;\n    const unsigned *pb = (const unsigned *)p2;',
    'init_ba': 'const unsigned *pb = (const unsigned *)p2;\n    const unsigned *pa = (const unsigned *)p1;',
    'assign_ab': 'const unsigned *pa;\n    const unsigned *pb;\n    pa = (const unsigned *)p1;\n    pb = (const unsigned *)p2;',
    'assign_ba': 'const unsigned *pa;\n    const unsigned *pb;\n    pb = (const unsigned *)p2;\n    pa = (const unsigned *)p1;',
    'declba_assignba': 'const unsigned *pb;\n    const unsigned *pa;\n    pb = (const unsigned *)p2;\n    pa = (const unsigned *)p1;',
    'direct': None,
}

SECOND = '''if (pa[1] > pb[1])
        return 1;
    if (pa[1] != pb[1])
        return -1;
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, pa[-1] - 4);'''

SECOND_DD = SECOND.replace('pa[1]', '((const unsigned *)p1)[1]').replace('pb[1]', '((const unsigned *)p2)[1]').replace('pa += 2;', 'p1 = (const void *)((const unsigned *)p1 + 2);').replace('pb += 2;', 'p2 = (const void *)((const unsigned *)p2 + 2);').replace('memcmp(pa, pb, pa[-1] - 4)', 'memcmp(p1, p2, ((const unsigned *)p1)[-1] - 4)')


def head_dd(h):
    return h.replace('pa[0]', '((const unsigned *)p1)[0]').replace('pb[0]', '((const unsigned *)p2)[0]')


def main():
    outdir = 'mcheads5'
    os.makedirs(outdir, exist_ok=True)
    n = 0
    for pn, pro in PROLOGUES.items():
        for hn, head in HEADS.items():
            name = f'r_{pn}_{hn}.c'
            src = '#include <string.h>\nint __cdecl R(const void *p1, const void *p2)\n{\n'
            if pro is None:
                h = head_dd(head)
                s = SECOND_DD
            else:
                for line in pro.split('\n'):
                    src += '    ' + line + '\n'
                h = head
                s = SECOND
            for line in h.split('\n'):
                src += '    ' + line + '\n'
            for line in s.split('\n'):
                src += ('    ' + line if line.strip() else '') + '\n'
            src += '}\n'
            open(os.path.join(outdir, name), 'w').write(src)
            n += 1
    print(f'wrote {n}')


if __name__ == '__main__':
    raise SystemExit(main())
