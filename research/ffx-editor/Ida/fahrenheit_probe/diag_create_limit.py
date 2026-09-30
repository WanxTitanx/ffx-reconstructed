#!/usr/bin/env python3
"""Testa limites do create_data em byte unknown (0x25D7004)."""
import ida_bytes


def main():
    ea = 0x25D7004
    print(f"is_unknown antes: {ida_bytes.is_unknown(ida_bytes.get_flags(ea))}", flush=True)
    for size in [0x100, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000, 0x10000]:
        r = ida_bytes.create_data(ea, 0, size, 0)
        print(f"create_data(size=0x{size:X}) = {r}", flush=True)
        # desfaz
        ida_bytes.del_items(ea, 0, size)


if __name__ == "__main__":
    main()
