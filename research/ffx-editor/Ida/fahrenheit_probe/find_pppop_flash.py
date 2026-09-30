#!/usr/bin/env python3
"""Acha a string pppop_flash e quem a referencia."""
import ida_bytes
import ida_name
import ida_xref
import idc


def main():
    # procura a string em .rdata
    seg = idc.get_segm_by_sel(idc.selector_by_name(".rdata"))
    start = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    target = b"pppop_flash"
    found = []
    ea = start
    while ea < end:
        s = ida_bytes.get_bytes(ea, len(target))
        if s == target:
            found.append(ea)
        ea = ida_bytes.next_head(ea, end)
    print(f"string pppop_flash em: {[hex(e) for e in found]}", flush=True)
    for ea in found[:3]:
        xrefs = []
        xb = ida_xref.get_first_dref_to(ea)
        while xb != idc.BADADDR:
            f = ida_funcs.get_func(xb)
            fname = ida_name.get_name(f.start_ea) if f else "?"
            xrefs.append((hex(xb), fname))
            xb = ida_xref.get_next_dref_to(ea, xb)
        print(f"  xrefs de {hex(ea)}: {xrefs[:6]}", flush=True)


if __name__ == "__main__":
    main()
