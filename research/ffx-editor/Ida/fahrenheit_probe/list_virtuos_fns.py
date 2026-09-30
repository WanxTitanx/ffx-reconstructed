#!/usr/bin/env python3
"""Frente 5: lista as funcoes FFX_Virtuos* (sistema de movie do port PC)."""
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
        if "Virtuos" in name or name.startswith("FFX_Video") or "Movie" in name:
            found.append((f.start_ea, name, f.size()))
    print(f"funcoes Virtuos/Video/Movie: {len(found)}", flush=True)
    for ea, name, size in sorted(found):
        print(f"  {hex(ea)} {size:5d}  {name}", flush=True)


if __name__ == "__main__":
    main()
