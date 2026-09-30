#!/usr/bin/env python3
"""Disassemble one function by start address (idalib)."""

import sys

import idapro
import ida_funcs
import idautils
import ida_ua
import idc


def main() -> int:
    idb, addr = sys.argv[1], int(sys.argv[2], 16)
    idapro.open_database(idb, False)
    fn = ida_funcs.get_func(addr)
    if fn is None:
        print('no function')
        return 1
    print(f'{ida_funcs.get_func_name(fn.start_ea)} {fn.start_ea:#x}-{fn.end_ea:#x} size={fn.end_ea - fn.start_ea}')
    for head in idautils.Heads(fn.start_ea, fn.end_ea):
        print(f'  {head:#x}: {idc.GetDisasm(head)}')
    idapro.close_database(False)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
