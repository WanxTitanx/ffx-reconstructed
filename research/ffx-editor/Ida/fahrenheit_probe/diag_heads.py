#!/usr/bin/env python3
"""Diagnostica get_item_head/next_head no 9.x."""
import ida_bytes
import ida_segment


def main():
    qty = ida_segment.get_segm_qty()
    print(f"segs: {qty}", flush=True)
    for i in range(min(qty, 8)):
        seg = ida_segment.getnseg(i)
        s = seg.start_ea
        e = seg.end_ea
        name = ida_segment.get_segm_name(seg) or "?"
        h = ida_bytes.get_item_head(s)
        n = ida_bytes.next_head(s, e)
        print(f"{name}: s={hex(s)} e={hex(e)} get_item_head(s)={hex(h) if h not in (-1, 0xFFFFFFFFFFFFFFFF) else 'BADADDR'} next_head(s)={hex(n) if n not in (-1, 0xFFFFFFFFFFFFFFFF) else 'BADADDR'}", flush=True)


if __name__ == "__main__":
    main()
