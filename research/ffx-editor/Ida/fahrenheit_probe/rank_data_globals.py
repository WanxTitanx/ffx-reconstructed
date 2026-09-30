#!/usr/bin/env python3
"""Relatorio dos globals default do .data: top por xrefs com funcao dominante (heuristica de nome)."""
import ida_bytes
import ida_funcs
import ida_name
import ida_xref
import idc
import re
import json

DEFAULT = re.compile(r"^(dword_|off_|flt_|byte_|word_|qword_|unk_)", re.I)


def main():
    results = []
    seg = idc.get_segm_by_sel(idc.selector_by_name(".data")) or idc.get_first_seg()
    start = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    ea = start
    while ea < end:
        name = ida_name.get_name(ea)
        if name and DEFAULT.match(name):
            fns = {}
            xb = ida_xref.get_first_dref_to(ea)
            while xb != idc.BADADDR:
                f = ida_funcs.get_func(xb)
                if f:
                    fname = ida_name.get_name(f.start_ea) or f"fn_{f.start_ea:x}"
                    fns[fname] = fns.get(fname, 0) + 1
                xb = ida_xref.get_next_dref_to(ea, xb)
            if fns:
                top_fn = max(fns, key=fns.get)
                results.append((sum(fns.values()), len(fns), ea, name, top_fn, fns[top_fn]))
            ea = ida_bytes.next_head(ea, end)
        else:
            ea = ida_bytes.next_head(ea, end)
    results.sort(reverse=True)
    out = {"total": len(results), "top": [
        {"count": c, "funcs": nf, "ea": hex(ea), "name": nm,
         "top_fn": tf, "top_count": tc} for c, nf, ea, nm, tf, tc in results[:60]]}
    with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\data_globals_report.json", "w", encoding="utf-8") as f:
        json.dump(out, f, indent=1, ensure_ascii=False)
    print(f"total globals com xrefs: {len(results)}", flush=True)
    for c, nf, ea, nm, tf, tc in results[:30]:
        print(f"  {c:4d} xrefs/{nf:2d} fns  {hex(ea)}  {nm}  <- {tf} ({tc})", flush=True)


if __name__ == "__main__":
    main()

