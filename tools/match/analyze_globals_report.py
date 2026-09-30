#!/usr/bin/env python3
"""Report how the data-global types are inferred across the emitted corpus.

Usage: analyze_globals_report.py [units_dir]

Prints the distinct-global count, the per-global kind split, and the top-N globals
with the assigned type and the shape counts that justify it.
"""
import glob
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import analyze_globals as A

TOP = 20


def main():
    units = sys.argv[1] if len(sys.argv) > 1 else '/tmp/real2'
    paths = sorted(glob.glob(os.path.join(units, '*.c')))
    file_refs, usage = A.scan(paths)
    ranked = [n for n, _ in file_refs.most_common() if A.is_global(n)]
    arrays = [n for n in ranked if A.classify(n, usage[n])[0] == 'array']
    print('units                : %d' % len(paths))
    print('distinct globals     : %d' % len(ranked))
    print('retyped as arrays    : %d' % len(arrays))
    print()
    print('%-3s %-22s %6s %-8s %-10s %s' %
          ('#', 'global', 'files', 'kind', 'declared', 'evidence'))
    for i, n in enumerate(ranked[:TOP], 1):
        kind, ctype, reason = A.classify(n, usage[n])
        u = usage[n]
        ev = 'X[i]=%d *X=%d (T*)X=%d &X=%d value=%d' % (
            u['sub'], u['deref'], u['castptr'], u['addr'], u['bare'])
        decl = (ctype + '[]') if kind == 'array' else ctype
        print('%-3d %-22s %6d %-8s %-10s %s | %s' %
              (i, n, file_refs[n], kind, decl, reason, ev))


if __name__ == '__main__':
    main()

