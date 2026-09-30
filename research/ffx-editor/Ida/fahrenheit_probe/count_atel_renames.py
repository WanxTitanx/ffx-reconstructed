#!/usr/bin/env python3
"""Conta handlers FFX_Atel_*_H_* renomeados pelo lote 11."""
import ida_funcs
import ida_name
from collections import Counter


def main():
    qty = ida_funcs.get_func_qty()
    count = 0
    tabs = Counter()
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if name.startswith("FFX_Atel_") and "_H_" in name:
            count += 1
            tab = name.split("_")[2]
            tabs[tab] += 1
    print(f"total handlers Atel renomeados: {count}", flush=True)
    for t, c in tabs.most_common():
        print(f"  {t}: {c}", flush=True)


if __name__ == "__main__":
    main()
