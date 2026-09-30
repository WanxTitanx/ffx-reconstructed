#!/usr/bin/env python3
"""Dump IDB segment map and a few raw byte windows for cross-checking."""

import sys

import idapro
import ida_bytes
import ida_nalt
import ida_segment
import idautils


def main() -> int:
    idb = sys.argv[1]
    idapro.open_database(idb, False)
    print("input file:", ida_nalt.get_input_file_path())
    print("imagebase :", hex(ida_nalt.get_imagebase()))
    for ea in idautils.Segments():
        sg = ida_segment.getseg(ea)
        print(
            f"{ida_segment.get_segm_name(sg):10s} start={sg.start_ea:#010x} "
            f"end={sg.end_ea:#010x} size={sg.end_ea - sg.start_ea} "
            f"perm={sg.perm} type={sg.type} bitness={sg.bitness}"
        )
    for va, size in ((0x401000, 8), (0x401020, 112), (0x401090, 29)):
        raw = ida_bytes.get_bytes(va, size)
        print(f"bytes {va:#x} ({size}): {raw.hex() if raw else None}")
    idapro.close_database(False)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
