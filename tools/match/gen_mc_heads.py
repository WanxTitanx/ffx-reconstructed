#!/usr/bin/env python3
"""Generate head-variant grid for Phyre_MemCmp_WithLength (fixed proven tail)."""

import os

TAIL = '''
    if (pa[1] > pb[1])
        return 1;
    if (pa[1] == pb[1])
    {
        pa += 2;
        pb += 2;
        return memcmp(pa, pb, pa[-1] - 4) == 0;
    }
    return -1;
'''

HEADS = {
    # name: code lines (pa/pb already declared+assigned or direct)
    'gt_lt': ['if (pa[0] > pb[0])', '        return 1;', '    if (pa[0] < pb[0])', '        return -1;'],
    'lt_gt': ['if (pa[0] < pb[0])', '        return 1;', '    if (pa[0] > pb[0])', '        return -1;'],
    'gtlt_pb': ['if (pb[0] < pa[0])', '        return 1;', '    if (pb[0] > pa[0])', '        return -1;'],
    'ltgt_pb': ['if (pb[0] > pa[0])', '        return -1;', '    if (pb[0] < pa[0])', '        return 1;'],
    'neq_sign': ['if (pa[0] != pb[0])', '        return pa[0] > pb[0] ? 1 : -1;'],
    'neq_sign_pb': ['if (pb[0] != pa[0])', '        return pa[0] > pb[0] ? 1 : -1;'],
}

PROLOGUES = {
    'init_ab': 'const unsigned *pa = (const unsigned *)p1;\n    const unsigned *pb = (const unsigned *)p2;',
    'init_ba': 'const unsigned *pb = (const unsigned *)p2;\n    const unsigned *pa = (const unsigned *)p1;',
    'decl_assign_ab': 'const unsigned *pa;\n    const unsigned *pb;\n    pa = (const unsigned *)p1;\n    pb = (const unsigned *)p2;',
    'decl_assign_ba': 'const unsigned *pa;\n    const unsigned *pb;\n    pb = (const unsigned *)p2;\n    pa = (const unsigned *)p1;',
    'decl_ba_assign_ab': 'const unsigned *pb;\n    const unsigned *pa;\n    pa = (const unsigned *)p1;\n    pb = (const unsigned *)p2;',
    'decl_ab_assign_ba': 'const unsigned *pa;\n    const unsigned *pb;\n    pb = (const unsigned *)p2;\n    pa = (const unsigned *)p1;',
}


def main():
    outdir = 'mcheads'
    os.makedirs(outdir, exist_ok=True)
    n = 0
    for pn, pro in PROLOGUES.items():
        for hn, head in HEADS.items():
            name = f'h_{pn}_{hn}.c'
            src = '#include <string.h>\nint __cdecl H(const void *p1, const void *p2)\n{\n'
            for line in pro.split('\n'):
                src += '    ' + line + '\n'
            for line in head:
                src += '    ' + line + '\n'
            for line in TAIL.split('\n'):
                src += ('    ' + line if line.strip() else '') + '\n'
            src += '}\n'
            open(os.path.join(outdir, name), 'w').write(src)
            n += 1
    print(f'wrote {n}')


if __name__ == '__main__':
    raise SystemExit(main())
