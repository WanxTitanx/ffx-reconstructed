#!/usr/bin/env python3
"""Decompile the functions the corpus never extracted (idalib + Hex-Rays).

The pseudocode corpus has 10,251 "NOT EXTRACTED" placeholders. This walks every
INVENTORY address that has no real body, runs Hex-Rays on it, and writes the
same file shape the corpus generator used, so the existing compile+verify
pipeline applies unchanged.

Run on the VM:  python decompile_missing.py <i64> <inv.tsv> <outdir> <first> <count>
Progress is flushed per function, so it can be stopped and resumed.
"""
import os, sys

import idapro
import ida_funcs
import ida_hexrays
import idautils
import idc


def main() -> int:
    i64, inv_path, outdir = sys.argv[1], sys.argv[2], sys.argv[3]
    first = int(sys.argv[4]) if len(sys.argv) > 4 else 0
    count = int(sys.argv[5]) if len(sys.argv) > 5 else 10 ** 9
    os.makedirs(outdir, exist_ok=True)

    todo = []
    with open(inv_path, encoding='utf-8', errors='replace') as f:
        f.readline()
        for line in f:
            p = line.rstrip('\n').split('\t')
            if len(p) < 6:
                continue
            todo.append((int(p[0], 16), int(p[2]), p[5]))
    todo = todo[first:first + count]
    print(f'targets {len(todo)}', flush=True)

    idapro.open_database(i64, False)
    if not ida_hexrays.init_hexrays_plugin():
        print('hexrays unavailable', flush=True)
        return 2

    done = 0
    for va, size, name in todo:
        out = os.path.join(outdir, 'd%08X.c' % va)
        if os.path.exists(out):
            continue
        try:
            cf = ida_hexrays.decompile(va)
            if cf is None:
                continue
            body = str(cf)
        except Exception:
            continue
        with open(out, 'w', encoding='utf-8') as f:
            f.write('// Function: %s\n// Address: 0x%X\n// Size: 0x%X\n' % (name, va, size))
            f.write(body)
        done += 1
        if done % 25 == 0:
            print('done %d' % done, flush=True)
    print('wrote %d' % done, flush=True)
    idapro.close_database(False)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())

