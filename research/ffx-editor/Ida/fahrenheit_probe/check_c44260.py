#!/usr/bin/env python3
"""Verifica 0xC44260 e 0xC24F0C (36 xrefs cada)."""
import ida_funcs
import ida_name
import ida_xref
import idc


def dump(ea, label):
    fns = {}
    xb = ida_xref.get_first_dref_to(ea)
    while xb != idc.BADADDR:
        f = ida_funcs.get_func(xb)
        if f:
            fname = ida_name.get_name(f.start_ea) or f"fn_{f.start_ea:x}"
            fns[fname] = fns.get(fname, 0) + 1
        xb = ida_xref.get_next_dref_to(ea, xb)
    print(f"=== {label} ({hex(ea)}): {len(fns)} funcoes", flush=True)
    for name, count in sorted(fns.items(), key=lambda kv: -kv[1])[:8]:
        print(f"  {count:3d}  {name}", flush=True)


def main():
    dump(0xC44260, "C44260")
    dump(0xC24F0C, "C24F0C")


if __name__ == "__main__":
    main()
