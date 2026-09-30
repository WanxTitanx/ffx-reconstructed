#!/usr/bin/env python3
"""Lista as funcoes que referenciam 0xC8F510 (Magic_SharedContextPtr)."""
import ida_funcs
import ida_name
import ida_xref
import idc
import json


def main():
    ea = 0xC8F510
    fns = {}
    xb = ida_xref.get_first_dref_to(ea)
    while xb != idc.BADADDR:
        f = ida_funcs.get_func(xb)
        if f:
            fname = ida_name.get_name(f.start_ea) or f"fn_{f.start_ea:x}"
            fns[fname] = fns.get(fname, 0) + 1
        xb = ida_xref.get_next_dref_to(ea, xb)
    print(f"funcoes: {len(fns)}", flush=True)
    for name, count in sorted(fns.items(), key=lambda kv: -kv[1])[:30]:
        print(f"  {count:3d}  {name}", flush=True)
    with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\c8f510_users.json", "w", encoding="utf-8") as f:
        json.dump(fns, f, indent=1, ensure_ascii=False)


if __name__ == "__main__":
    main()
