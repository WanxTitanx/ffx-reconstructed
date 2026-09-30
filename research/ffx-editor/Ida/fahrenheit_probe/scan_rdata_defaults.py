#!/usr/bin/env python3
"""Scan do .rdata: globals default restantes (off_/dword_/unk_) com xrefs."""
import ida_bytes
import ida_name
import ida_xref
import idc
import re
from collections import Counter

DEFAULT = re.compile(r"^(off_|dword_|unk_|byte_|word_|qword_|flt_)", re.I)


def main():
    seg = idc.get_segm_by_sel(idc.selector_by_name(".rdata")) or idc.get_first_seg()
    start = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    ea = start
    counts = Counter()
    total = 0
    top = []
    while ea < end:
        name = ida_name.get_name(ea)
        if name and DEFAULT.match(name):
            total += 1
            kind = name.split("_")[0]
            counts[kind] += 1
            # conta xrefs
            xrefs = 0
            xb = ida_xref.get_first_dref_to(ea)
            while xb != idc.BADADDR:
                xrefs += 1
                xb = ida_xref.get_next_dref_to(ea, xb)
            if xrefs >= 3:
                top.append((xrefs, ea, name))
        ea = ida_bytes.next_head(ea, end)
    print(f"globals default no .rdata: {total} {dict(counts)}", flush=True)
    top.sort(reverse=True)
    for xrefs, ea, name in top[:25]:
        print(f"  {xrefs:3d}  {hex(ea)}  {name}", flush=True)


if __name__ == "__main__":
    main()
