#!/usr/bin/env python3
"""survey_comments.py — conta comentarios e tipos aplicados na db (API 9.x: idc.get_cmt)."""
import ida_funcs
import idc


def main():
    qty = ida_funcs.get_func_qty()
    n_cmt = 0
    n_type = 0
    shown = 0
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        ea = f.start_ea
        cmt = idc.get_cmt(ea, False)
        if cmt:
            n_cmt += 1
            if shown < 8:
                print(f"  CMT {ea:08X}: {cmt[:80]}", flush=True)
                shown += 1
        t = idc.get_type(ea)
        if t:
            n_type += 1
    print(f"funcs: {qty} | comentarios: {n_cmt} | tipos: {n_type}", flush=True)


if __name__ == "__main__":
    main()

