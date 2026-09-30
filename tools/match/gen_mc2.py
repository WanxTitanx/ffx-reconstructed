#!/usr/bin/env python3
"""Second head grid: params-vs-locals advance x head logic."""

import os

HEADS = {
    'gt_lt': ('if (pa[0] > pb[0])\n        return 1;\n    if (pa[0] < pb[0])\n        return -1;', 'pa', 'pb'),
    'lt_gt': ('if (pa[0] < pb[0])\n        return 1;\n    if (pa[0] > pb[0])\n        return -1;', 'pa', 'pb'),
    'gtlt_pb': ('if (pb[0] < pa[0])\n        return 1;\n    if (pb[0] > pa[0])\n        return -1;', 'pb', 'pa'),
    'ltgt_pb': ('if (pb[0] > pa[0])\n        return -1;\n    if (pb[0] < pa[0])\n        return 1;', 'pb', 'pa'),
}

TAILS = {
    'locals': ('pa += 2;\n        pb += 2;\n        return memcmp(pa, pb, pa[-1] - 4) == 0;', True),
    'params': ('p1 = (const void *)((const unsigned *)p1 + 2);\n        p2 = (const void *)((const unsigned *)p2 + 2);\n        return memcmp(p1, p2, ((const unsigned *)p1)[-1] - 4) == 0;', False),
}

SECOND = '''
    if (pa[1] > pb[1])
        return 1;
    if (pa[1] == pb[1])
    {
TAIL
    }
    return -1;
'''

SECOND_DD = '''
    if (((const unsigned *)p1)[1] > ((const unsigned *)p2)[1])
        return 1;
    if (((const unsigned *)p1)[1] == ((const unsigned *)p2)[1])
    {
TAIL
    }
    return -1;
'''


def main():
    outdir = 'mcheads2'
    os.makedirs(outdir, exist_ok=True)
    n = 0
    for hn, (head, _x, _y) in HEADS.items():
        for tn, (tail, use_locals) in TAILS.items():
            name = f'k_{hn}_{tn}.c'
            src = '#include <string.h>\nint __cdecl K(const void *p1, const void *p2)\n{\n'
            if use_locals:
                src += '    const unsigned *pa = (const unsigned *)p1;\n    const unsigned *pb = (const unsigned *)p2;\n'
                h = head
                s = SECOND.replace('TAIL', '\n'.join('        ' + l for l in tail.split('\n')))
            else:
                h = head.replace('pa[0]', '((const unsigned *)p1)[0]').replace('pb[0]', '((const unsigned *)p2)[0]')
                s = SECOND_DD.replace('TAIL', '\n'.join('        ' + l for l in tail.split('\n')))
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
