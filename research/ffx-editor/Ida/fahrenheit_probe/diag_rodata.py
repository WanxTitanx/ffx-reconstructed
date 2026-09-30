#!/usr/bin/env python3
"""Diagnostica create_data no .rodata (0x25D7000)."""
import ida_bytes


def main():
    ea = 0x25D7000
    flags = ida_bytes.get_flags(ea)
    print(f"flags(0x25D7000) = {hex(flags)}", flush=True)
    print(f"is_unknown = {ida_bytes.is_unknown(flags)}", flush=True)
    print(f"is_data = {ida_bytes.is_data(flags)}", flush=True)
    print(f"item_size = {ida_bytes.get_item_size(ea)}", flush=True)
    # tenta criar 1 byte
    r1 = ida_bytes.create_data(ea, 0, 1, 0)
    print(f"create_data(1B) = {r1}", flush=True)
    # tenta 16 bytes
    r2 = ida_bytes.create_data(ea, 0, 16, 0)
    print(f"create_data(16B) = {r2}", flush=True)
    # tenta dword
    r3 = ida_bytes.create_data(ea, ida_bytes.FF_DWORD, 4, 0)
    print(f"create_data(FF_DWORD 4B) = {r3}", flush=True)
    flags2 = ida_bytes.get_flags(ea)
    print(f"flags depois = {hex(flags2)}, is_unknown = {ida_bytes.is_unknown(flags2)}", flush=True)


if __name__ == "__main__":
    main()
