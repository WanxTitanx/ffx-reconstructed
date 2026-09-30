#!/usr/bin/env python3
"""Generate a systematic grid of memcmp source shapes for the entry-pattern hunt.

Axes: prologue (pa/pb locals vs direct params) x pre-check form x loop form x
counter (len param vs k local). The tail is fixed to the proven sbb/or shape.
Each variant is a complete TU; run_batch builds all, score_variant ranks them.
"""

import itertools
import os

TAIL_K = '''
    if ((int)K != -4)
    {
        const unsigned char *ca = (const unsigned char *)PA;
        const unsigned char *cb = (const unsigned char *)PB;
        if (*ca != *cb)
            return ((*ca < *cb) ? -1 : 0) | 1;
        if ((int)K != -3)
        {
            if (ca[1] != cb[1])
                return ((ca[1] < cb[1]) ? -1 : 0) | 1;
            if ((int)K != -2)
            {
                if (ca[2] != cb[2])
                    return ((ca[2] < cb[2]) ? -1 : 0) | 1;
                if ((int)K != -1)
                    return ca[3] == cb[3] ? 0 : 1;
            }
        }
    }
    return 0;
'''

TAIL_LEN = TAIL_K.replace('K', 'len')

PROLOGUES = {
    'pp': ('unsigned int *pa;\n    unsigned int *pb;', 'pa = (unsigned int *)p1;\n    pb = (unsigned int *)p2;'),
    'pi': ('unsigned int *pa = (unsigned int *)p1;\n    unsigned int *pb = (unsigned int *)p2;', None),
    'dd': (None, None),  # direct params
}

# loop bodies per prologue kind
BODY_PP = '''
            if (*pa != *pb)
                return 1;
            ++pa;
            ++pb;
'''
BODY_DD = '''
            if (*(unsigned int *)p1 != *(unsigned int *)p2)
                return 1;
            p1 = (const void *)((const unsigned int *)p1 + 1);
            p2 = (const void *)((const unsigned int *)p2 + 1);
'''

LOOPFORMS = {
    # name: template with {BODY} {DEC} {CHECK} -- assembled below
    'dowhile_ge0': 'if ((int){C} >= 0)\n    {{\n        do\n        {{\n{BODY}            {C} -= 4;\n        }} while ((int){C} >= 0);\n    }}',
    'while_ge4': 'while ({C} >= 4)\n    {{\n{BODY}        {C} -= 4;\n    }}',
    'for_sub': 'for ({C} -= 4; (int){C} >= 0; {C} -= 4)\n    {{\n{BODY}}}',
    'for_uge4': 'for ({C} -= 4; {C} < 0xFFFFFFFC; {C} -= 4)\n    {{\n{BODY}}}',
    'dowhile_uge': 'if ({C} >= 4)\n    {{\n        {C} -= 4;\n        do\n        {{\n{BODY}            {C} -= 4;\n        }} while ({C} >= 4);\n    }}\n    else\n    {{\n        {C} -= 4;\n    }}',
}

PRECHECKS = {
    'if0': 'if (!len)\n        return 0;',
    'none': '',
}


def build(pro, pre, loop, counter):
    decls, assigns = PROLOGUES[pro]
    body = BODY_DD if pro == 'dd' else BODY_PP
    pa, pb = ('p1', 'p2') if pro == 'dd' else ('pa', 'pb')
    c = 'len' if counter == 'len' else 'k'
    lines = ['int __cdecl F(const void *p1, const void *p2, unsigned int len)', '{']
    if counter == 'k':
        lines.append('    unsigned int k;')
    if decls:
        for d in decls.split('\n'):
            lines.append('    ' + d)
    if pre != 'none':
        for d in PRECHECKS[pre].split('\n'):
            lines.append('    ' + d)
    if assigns:
        for d in assigns.split('\n'):
            lines.append('    ' + d)
    if counter == 'k' and pro != 'dd':
        lines.append('    k = len - 4;')
    elif counter == 'k':
        lines.append('    k = len - 4;')
    looptext = LOOPFORMS[loop].replace('{BODY}', body).replace('{C}', c)
    for d in looptext.split('\n'):
        lines.append('    ' + d)
    tail = TAIL_LEN if counter == 'len' else TAIL_K
    tail = tail.replace('PA', pa).replace('PB', pb)
    for d in tail.split('\n'):
        lines.append('    ' + d if d.strip() else d)
    lines.append('}')
    return '\n'.join(lines) + '\n'


def main():
    outdir = 'shapes'
    os.makedirs(outdir, exist_ok=True)
    n = 0
    for pro, pre, loop, counter in itertools.product(
        ['pp', 'pi', 'dd'], ['if0', 'none'], list(LOOPFORMS), ['len', 'k']
    ):
        if pro == 'dd' and counter == 'k':
            continue  # k-local with direct params still needs pa/pb for tail; skip
        name = f's_{pro}_{pre}_{loop}_{counter}.c'
        # fix function name
        src = build(pro, pre, loop, counter).replace('int __cdecl F(', 'int __cdecl F(')
        open(os.path.join(outdir, name), 'w').write(src)
        n += 1
    print(f'wrote {n} shapes to {outdir}/')


if __name__ == '__main__':
    raise SystemExit(main())
