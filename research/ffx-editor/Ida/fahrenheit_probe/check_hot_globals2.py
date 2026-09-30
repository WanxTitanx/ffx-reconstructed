#!/usr/bin/env python3
"""Verifica os globals quentes restantes (xrefs 15-23)."""
import ida_funcs
import ida_name
import ida_xref
import idc

TARGETS = [0xC0A09C, 0xC53414, 0xC169B4, 0xC59564, 0xC0BB70, 0xC48CD0, 0xC8F86C]


def main():
    for ea in TARGETS:
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
