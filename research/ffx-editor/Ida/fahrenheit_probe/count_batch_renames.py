#!/usr/bin/env python3
"""Conta globals renomeados com o padrao FFX_*_Global_* no .data."""
import ida_bytes
import ida_name
import idc
import re
from collections import Counter

PAT = re.compile(r"^FFX_(\w+)_Global_[0-9A-F]+$")


def main():
    seg = idc.get_segm_by_sel(idc.selector_by_name(".data")) or idc.get_first_seg()
    start = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    ea = start
    count = 0
    mods = Counter()
    while ea < end:
        name = ida_name.get_name(ea)
        m = PAT.match(name or "")
        if m:
            count += 1
            mods[m.group(1)] += 1
        ea = ida_bytes.next_head(ea, end)
    print(f"total FFX_*_Global_*: {count}", flush=True)
    for mod, c in mods.most_common(20):
        print(f"  {mod}: {c}", flush=True)


if __name__ == "__main__":
    main()
