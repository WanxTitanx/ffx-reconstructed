#!/usr/bin/env python3
"""Verifica quem usa cada FFX_Data_Table_* (para dar nomes melhores)."""
import ida_funcs
import ida_name
import ida_xref
import idc

TABLES = [0xC1A930, 0xC39620, 0xC49714, 0xC5455C, 0xC5A040,
          0xC5B360, 0xC5E350, 0xC6B274, 0xC6D448, 0xC87872]


def main():
    for ea in TABLES:
        fns = {}
        xb = ida_xref.get_first_dref_to(ea)
        while xb != idc.BADADDR:
            f = ida_funcs.get_func(xb)
            if f:
                fname = ida_name.get_name(f.start_ea) or f"fn_{f.start_ea:x}"
                fns[fname] = fns.get(fname, 0) + 1
            xb = ida_xref.get_next_dref_to(ea, xb)
        top = sorted(fns.items(), key=lambda kv: -kv[1])[:3]
        print(f"{hex(ea)} ({sum(fns.values())} refs): {[f'{n}({c})' for n, c in top]}", flush=True)


if __name__ == "__main__":
    main()
