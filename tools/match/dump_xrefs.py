#!/usr/bin/env python3
"""Dump code xrefs to/from an address + nearest function names (idalib)."""

import sys

import idapro
import ida_funcs
import idautils
import ida_xref


def fname(ea):
    fn = ida_funcs.get_func(ea)
    if fn is None:
        return '???'
    return ida_funcs.get_func_name(fn.start_ea) or hex(fn.start_ea)


def main() -> int:
    idb, addr = sys.argv[1], int(sys.argv[2], 16)
    idapro.open_database(idb, False)
    print(f'target {addr:#x} in {fname(addr)}')
    print('--- xrefs TO ---')
    for x in idautils.XrefsTo(addr):
        print(f'  {x.frm:#x} ({fname(x.frm)}) type={x.type}')
    print('--- xrefs FROM function ---')
    fn = ida_funcs.get_func(addr)
    if fn:
        for x in idautils.XrefsFrom(fn.start_ea, 0):
            print(f'  {x.frm:#x} -> {x.to:#x} ({fname(x.to)}) type={x.type}')
    idapro.close_database(False)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
