#!/usr/bin/env python3
"""Survey dos globals default restantes do .data: com/sem xrefs, tamanhos."""
import ida_bytes
import ida_name
import ida_xref
import idc
import re

DEFAULT = re.compile(r"^(dword_|off_|flt_|byte_|word_|qword_|unk_)", re.I)


def main():
    seg = idc.get_segm_by_sel(idc.selector_by_name(".data"))
    ea = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    no_xrefs, with_xrefs = [], []
    total = 0
    while ea < end:
        name = ida_name.get_name(ea)
        if name and DEFAULT.match(name):
            total += 1
            xrefs = 0
            xb = ida_xref.get_first_dref_to(ea)
            while xb != idc.BADADDR:
                xrefs += 1
                xb = ida_xref.get_next_dref_to(ea, xb)
            if xrefs == 0:
                no_xrefs.append(ea)
            else:
                with_xrefs.append((xrefs, ea))
        ea = ida_bytes.next_head(ea, end)
    print(f"total default: {total} | sem xrefs: {len(no_xrefs)} | com xrefs: {len(with_xrefs)}", flush=True)
    # amostra dos com xrefs (top)
    with_xrefs.sort(reverse=True)
    for xrefs, ea in with_xrefs[:12]:
        # tamanho ate o proximo item
        nxt = ida_bytes.next_head(ea, end)
        size = nxt - ea if nxt else 4
        print(f"  {xrefs:3d} xrefs {hex(ea)} size={size}", flush=True)
    # amostra dos sem xrefs (grandes = buffers)
    big = []
    for ea in no_xrefs:
        nxt = ida_bytes.next_head(ea, end)
        size = nxt - ea if nxt else 4
        if size >= 64:
            big.append((size, ea))
    big.sort(reverse=True)
    print(f"sem xrefs com size>=64: {len(big)}", flush=True)
    for size, ea in big[:15]:
        print(f"  {size:7d} {hex(ea)}", flush=True)


if __name__ == "__main__":
    main()
