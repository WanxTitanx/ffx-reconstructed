#!/usr/bin/env python3
"""Survey: top 40 funcoes por tamanho (sistemas centrais) + quantas tem decompile."""
import ida_funcs
import ida_hexrays
import ida_name


def main():
    qty = ida_funcs.get_func_qty()
    fns = []
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or "?"
        fns.append((f.size(), f.start_ea, name))
    fns.sort(reverse=True)
    print(f"top 40 por tamanho:", flush=True)
    for size, ea, name in fns[:40]:
        print(f"  {size:6d}  {hex(ea)}  {name}", flush=True)


if __name__ == "__main__":
    main()
