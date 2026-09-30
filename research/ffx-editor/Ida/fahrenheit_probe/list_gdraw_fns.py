#!/usr/bin/env python3
"""Lista Iggy_GDraw_* (renderer D3D11 do Iggy)."""
import ida_funcs
import ida_name


def main():
    qty = ida_funcs.get_func_qty()
    found = []
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if "GDraw" in name or "gdraw" in name:
            found.append((f.start_ea, f.size(), name))
    print(f"Iggy/Phyre GDraw: {len(found)}", flush=True)
    for ea, size, name in sorted(found):
        print(f"  {hex(ea)} {size:5d} {name}", flush=True)


if __name__ == "__main__":
    main()
