#!/usr/bin/env python3
"""Lista funcoes ppp* renomeadas pelo lote 4."""
import ida_funcs
import ida_name


def main():
    qty = ida_funcs.get_func_qty()
    names = []
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if name.startswith("ppp") and not name.startswith(("ppp_", "pppDispatch")):
            names.append((f.start_ea, name))
    print(f"total funcoes ppp*: {len(names)}", flush=True)
    for ea, n in sorted(names)[:40]:
        print(f"  {hex(ea)}  {n}", flush=True)


if __name__ == "__main__":
    main()
