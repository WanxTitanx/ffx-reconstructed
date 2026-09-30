#!/usr/bin/env python3
"""Distribuicao das funcoes default por segmento + amostra."""
import ida_funcs
import ida_name
import idc
import re
from collections import Counter

DEFAULT = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)


def main():
    qty = ida_funcs.get_func_qty()
    segs = Counter()
    samples = []
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea)
        if name and DEFAULT.match(name):
            seg = idc.get_segm_name(f.start_ea) or "?"
            segs[seg] += 1
            if len(samples) < 12:
                samples.append((f.start_ea, seg, name, f.size()))
    print(f"por segmento: {dict(segs)}", flush=True)
    for ea, seg, name, size in samples:
        print(f"  {hex(ea)} [{seg}] {name} size={size}", flush=True)


if __name__ == "__main__":
    main()
