#!/usr/bin/env python3
"""Marca os ultimos bytes unknown do .text como db (create_data size=1)."""
import ida_bytes
import ida_segment


def main():
    seg = ida_segment.getseg(0x401000)
    s = seg.start_ea
    e = seg.end_ea
    n = 0
    ea = s
    while ea < e:
        if ida_bytes.is_unknown(ida_bytes.get_flags(ea)):
            print(f"unknown em {ea:X}", flush=True)
            if ida_bytes.create_data(ea, 0, 1, 0):
                n += 1
        ea += 1
    print(f"marcados: {n}", flush=True)
    import ida_pro
    ida_pro.qexit(0)


if __name__ == "__main__":
    main()
