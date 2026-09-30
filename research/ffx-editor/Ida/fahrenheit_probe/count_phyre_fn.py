#!/usr/bin/env python3
"""Conta funcoes Phyre_*_Fn_* renomeadas pelo lote 3."""
import ida_funcs
import ida_name


def main():
    qty = ida_funcs.get_func_qty()
    count = 0
    samples = []
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if name.startswith("Phyre_") and "_Fn_" in name:
            count += 1
            if len(samples) < 15:
                samples.append(name)
    print(f"total funcoes Phyre_*_Fn_*: {count}", flush=True)
    for s in samples:
        print(f"  {s}", flush=True)


if __name__ == "__main__":
    main()
