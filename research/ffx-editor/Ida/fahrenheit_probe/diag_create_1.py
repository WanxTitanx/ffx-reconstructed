#!/usr/bin/env python3
"""Confirma create_data size=1 em unknown."""
import ida_bytes


def main():
    ea = 0x25D7004
    ida_bytes.del_items(ea, 0, 1)
    print(f"is_unknown: {ida_bytes.is_unknown(ida_bytes.get_flags(ea))}", flush=True)
    r = ida_bytes.create_data(ea, 0, 1, 0)
    print(f"create_data(size=1) = {r}", flush=True)
    print(f"is_unknown depois: {ida_bytes.is_unknown(ida_bytes.get_flags(ea))}", flush=True)


if __name__ == "__main__":
    main()
