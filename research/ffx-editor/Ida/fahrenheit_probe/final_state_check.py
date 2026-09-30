#!/usr/bin/env python3
"""Estado final: globals default restantes no .data e .rdata."""
import ida_bytes
import ida_name
import idc
import re

DEFAULT = re.compile(r"^(off_|dword_|unk_|byte_|word_|qword_|flt_)", re.I)


def main():
    for segname in (".data", ".rdata"):
        seg = idc.get_segm_by_sel(idc.selector_by_name(segname))
        if not seg:
            print(f"{segname}: nao encontrado", flush=True)
            continue
        start = idc.get_segm_start(seg)
        end = idc.get_segm_end(seg)
        ea = start
        total, default = 0, 0
        while ea < end:
            name = ida_name.get_name(ea)
            if name:
                total += 1
                if DEFAULT.match(name):
                    default += 1
            ea = ida_bytes.next_head(ea, end)
        print(f"{segname}: {total} items, {default} default ({100*default//max(total,1)}%)", flush=True)


if __name__ == "__main__":
    main()
