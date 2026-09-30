#!/usr/bin/env python3
"""Full grid for Phyre_MemCmp_WithLength: head x prologue x tail x advance."""

import os

HEADS = {
    'gt_lt': 'if (pa[0] > pb[0])\n        return 1;\n    if (pa[0] < pb[0])\n        return -1;',
    'gtlt_pb': 'if (pb[0] < pa[0])\n        return 1;\n    if (pb[0] > pa[0])\n        return -1;',
    'ltgt_pb': 'if (pb[0] > pa[0])\n        return -1;\n    if (pb[0] < pa[0])\n        return 1;',
}

PROLOGUES = {
    'init': 'const unsigned *pa = (const unsigned *)p1;\n    const unsigned *pb = (const unsigned *)p2;',
    'assign': 'const unsigned *pa;\n    const unsigned *pb;\n    pa = (const unsigned *)p1;\n    pb = (const unsigned *)p2;',
}

SECONDS = {
    'eq': 'if (pa[1] > pb[1])\n        return 1;\n    if (pa[1] == pb[1])\n    {\nTAIL\n    }\n    return -1;',
    'ne': 'if (pa[1] > pb[1])\n        return 1;\n    if (pa[1] != pb[1])\n        return -1;\nTAIL',
}

TAILS = {
    'sign_pa': 'pa += 2;\n        pb += 2;\n        return memcmp(pa, pb, pa[-1] - 4);',
    'sign_k': 'k = pa[1];\n        pa += 2;\n        pb += 2;\n        return memcmp(pa, pb, k - 4);',
    'eq0_pa': 'pa += 2;\n        pb += 2;\n        return memcmp(pa, pb, pa[-1] - 4) == 0;',
}


def main():
    outdir = 'mcheads4'
    os.makedirs(outdir, exist_ok=True)
    n = 0
    for hn, head in HEADS.items():
        for pn, pro in PROLOGUES.items():
            for sn, sec in SECONDS.items():
                for tn, tail in TAILS.items():
                    if 'k = ' in tail and 'unsigned k;' not in pro:
                        decls = pro + '\n    unsigned k;'
                    else:
                        decls = pro
                    name = f'q_{hn}_{pn}_{sn}_{tn}.c'
                    secf = sec.replace('TAIL', '\n'.join('        ' + l for l in tail.split('\n')))
                    src = '#include <string.h>\nint __cdecl Q(const void *p1, const void *p2)\n{\n'
                    for line in decls.split('\n'):
                        src += '    ' + line + '\n'
                    for line in head.split('\n'):
                        src += '    ' + line + '\n'
                    for line in secf.split('\n'):
                        src += ('    ' + line if line.strip() else '') + '\n'
                    src += '}\n'
                    open(os.path.join(outdir, name), 'w').write(src)
                    n += 1
    print(f'wrote {n}')


if __name__ == '__main__':
    raise SystemExit(main())
