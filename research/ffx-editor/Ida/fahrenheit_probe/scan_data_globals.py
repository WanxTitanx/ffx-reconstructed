#!/usr/bin/env python3
"""Scan do segmento .data da db ABERTA: globals com nome default (inexplorados).

Roda dentro do IDA GUI (File > Script File ou via mcp py_exec_file).
Imprime: total por prefixo + os maiores blocos por tamanho ate o proximo label.
"""
import re

import ida_bytes
import ida_name
import ida_segment

PAT = re.compile(r"^(dword_|unk_|byte_|word_|flt_|off_|dbl_|qword_|a[A-Za-z0-9]{1,10}$)")


def main():
    seg = ida_segment.get_segm_by_name(".data")
    counts = {}
    total = 0
    sizes = []
    if seg:
        ea = seg.start_ea
        while ea < seg.end_ea:
            n = ida_name.get_name(ea)
            if n and PAT.match(n):
                total += 1
                p = PAT.match(n).group(1)
                counts[p] = counts.get(p, 0) + 1
                size = ida_bytes.get_item_size(ea)
                sizes.append((size, hex(ea), n))
            ea = ida_bytes.next_head(ea, seg.end_ea)
    print(f"TOTAL={total} POR_PREFIXO={counts}")
    for s in sorted(sizes, reverse=True)[:20]:
        print("BIG", s)
    # xrefs para os maiores (quem usa)
    for size, ea_s, n in sorted(sizes, reverse=True)[:5]:
        import idautils
        xrefs = [hex(x.frm) for x in idautils.XrefsTo(int(ea_s, 16), 0)][:6]
        print(f"XREFS {ea_s} {n} size={size}: {xrefs}")


if __name__ == "__main__":
    main()
