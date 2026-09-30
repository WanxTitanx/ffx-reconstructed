#!/usr/bin/env python3
"""Amostra das funcoes FFX_Dbg_* (259) e FFX_PS3_* (51)."""
import ida_funcs
import ida_name


def main():
    qty = ida_funcs.get_func_qty()
    dbg = []
    ps3 = []
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if name.startswith("FFX_Dbg_"):
            dbg.append((f.start_ea, name))
        elif name.startswith("FFX_PS3_"):
            ps3.append((f.start_ea, name))
    print(f"FFX_Dbg_: {len(dbg)}", flush=True)
    for ea, name in dbg[:15]:
        print(f"  {hex(ea)} {name}", flush=True)
    print(f"FFX_PS3_: {len(ps3)}", flush=True)
    for ea, name in ps3[:10]:
        print(f"  {hex(ea)} {name}", flush=True)


if __name__ == "__main__":
    main()
