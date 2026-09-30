#!/usr/bin/env python3
"""Identifica as funcoes dos crashes FFX.exe na db (VAs = offset + 0x400000)."""
import ida_funcs
import ida_name

OFFSETS = [0x78261E, 0x79F150, 0x834420, 0x705AAE, 0x5B9DCB, 0x82AD8D, 0x640A8B, 0x67BB65]


def main():
    for off in OFFSETS:
        va = off + 0x400000
        f = ida_funcs.get_func(va)
        if f:
            name = ida_name.get_name(f.start_ea) or "?"
            print(f"  +{off:08X} = {hex(va)} -> {name} (+{va - f.start_ea:#x})", flush=True)
        else:
            print(f"  +{off:08X} = {hex(va)} -> (sem funcao)", flush=True)


if __name__ == "__main__":
    main()
