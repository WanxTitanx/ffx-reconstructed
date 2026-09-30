#!/usr/bin/env python3
"""Por que .rodata/_RDATA recusam create_data? (flags do segmento + idc.create_byte)."""
import ida_bytes
import ida_segment
import idc


def main():
    for s, e, label in [(0x25D7000, 0x25D8000, ".rodata"), (0x25D8000, 0x25D9000, "_RDATA")]:
        seg = ida_segment.getseg(s)
        print(f"{label}: flags={hex(seg.flags)} perm={hex(seg.perm)} type={seg.type} align={seg.align}", flush=True)
    ea = 0x25D7004
    r = idc.create_byte(ea)
    print(f"idc.create_byte(0x25D7004) = {r}", flush=True)
    print(f"is_unknown depois: {ida_bytes.is_unknown(ida_bytes.get_flags(ea))}", flush=True)


if __name__ == "__main__":
    main()
