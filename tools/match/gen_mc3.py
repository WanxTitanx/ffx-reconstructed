#!/usr/bin/env python3
"""Third head grid: mixed local/param pointer sourcing."""

import os

HEADS = {
    # (head template with PA/PB tokens, tail-second template)
    'gt_lt': 'if (PA[0] > PB[0])\n        return 1;\n    if (PA[0] < PB[0])\n        return -1;',
    'gtlt_pb': 'if (PB[0] < PA[0])\n        return 1;\n    if (PB[0] > PA[0])\n        return -1;',
    'ltgt_pb': 'if (PB[0] > PA[0])\n        return -1;\n    if (PB[0] < PA[0])\n        return 1;',
}

SECOND = '''
    if (PA[1] > PB[1])
        return 1;
    if (PA[1] == PB[1])
    {
TAIL
    }
    return -1;
'''

SOURCINGS = {
    # name: (decls, PA expr, PB expr)
    'pbloc': ('    const unsigned *pb = (const unsigned *)p2;', '((const unsigned *)p1)', 'pb'),
    'paloc': ('    const unsigned *pa = (const unsigned *)p1;', 'pa', '((const unsigned *)p2)'),
    'pbloc_a': ('    const unsigned *pb;\n    pb = (const unsigned *)p2;', '((const unsigned *)p1)', 'pb'),
    'paloc_a': ('    const unsigned *pa;\n    pa = (const unsigned *)p1;', 'pa', '((const unsigned *)p2)'),
}

TAILS = {
    'params': 'p1 = (const void *)((const unsigned *)p1 + 2);\n        p2 = (const void *)((const unsigned *)p2 + 2);\n        return memcmp(p1, p2, ((const unsigned *)p1)[-1] - 4) == 0;',
}


def main():
    outdir = 'mcheads3'
    os.makedirs(outdir, exist_ok=True)
    n = 0
    for sn, (decls, pae, pbe) in SOURCINGS.items():
        for hn, head in HEADS.items():
            for tn, tail in TAILS.items():
                name = f'm_{sn}_{hn}_{tn}.c'
                h = head.replace('PA', pae).replace('PB', pbe)
                s = SECOND.replace('PA', pae).replace('PB', pbe)
                s = s.replace('TAIL', '\n'.join('        ' + l for l in tail.split('\n')))
                src = '#include <string.h>\nint __cdecl M(const void *p1, const void *p2)\n{\n'
                for line in decls.split('\n'):
                    src += '    ' + line + '\n'
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
