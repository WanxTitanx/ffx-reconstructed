#!/usr/bin/env python3
"""Verifica 0xC34194 (43 xrefs) e Pmcom: quem usa."""
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
    for name, count in sorted(fns.items(), key=lambda kv: -kv[1])[:10]:
        print(f"  {count:3d}  {name}", flush=True)


def main():
    dump(0xC34194, "C34194")
    # Pmcom: procura funcoes com Pmcom no nome
    qty = ida_funcs.get_func_qty()
    pmcom = []
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if "Pmcom" in name or "PmCom" in name:
            pmcom.append((f.start_ea, f.size(), name))
    print(f"=== funcoes Pmcom: {len(pmcom)}", flush=True)
    for ea, size, name in sorted(pmcom)[:12]:
        print(f"  {hex(ea)} {size:5d} {name}", flush=True)


if __name__ == "__main__":
    main()
