#!/usr/bin/env python3
"""Survey do estado de decompilacao: funcoes com/sem pseudocode Hex-Rays."""
import ida_funcs
import ida_hexrays
import ida_name
import idc
import time

DEFAULT = ("sub_", "FUN_", "nullsub_", "loc_", "j_")


def main():
    if not ida_hexrays.init_hexrays_plugin():
        print("hexrays NAO disponivel", flush=True)
        return
    qty = ida_funcs.get_func_qty()
    with_dc = 0
    without = []
    nullsub = 0
    t0 = time.time()
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if name.startswith("nullsub_"):
            nullsub += 1
            continue
        cf = ida_hexrays.decompile(f)
        if cf:
            with_dc += 1
        else:
            without.append((f.start_ea, name, f.size()))
        if i % 5000 == 0:
            print(f"...{i}/{qty} ({time.time()-t0:.0f}s)", flush=True)
    print(f"TOTAL: {qty} fns | com decompile: {with_dc} | sem: {len(without)} | nullsub: {nullsub}", flush=True)
    for ea, name, size in without[:30]:
        print(f"  SEM: {hex(ea)} {name} size={size}", flush=True)


if __name__ == "__main__":
    main()
