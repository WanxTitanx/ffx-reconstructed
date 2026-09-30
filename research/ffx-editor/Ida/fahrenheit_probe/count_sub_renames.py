#!/usr/bin/env python3
"""Conta funcoes com _Sub_ renomeadas pelo lote 2."""
import ida_funcs
import ida_name
from collections import Counter


def main():
    qty = ida_funcs.get_func_qty()
    count = 0
    mods = Counter()
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if "_Sub_" in name:
            count += 1
            mod = name.split("_")[1] if name.startswith("FFX_") else "?"
            mods[mod] += 1
    print(f"total funcoes _Sub_: {count}", flush=True)
    for mod, c in mods.most_common(20):
        print(f"  {mod}: {c}", flush=True)


if __name__ == "__main__":
    main()
