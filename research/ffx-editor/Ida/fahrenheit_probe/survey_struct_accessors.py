#!/usr/bin/env python3
"""Lista FFX_Struct_* — acessores de campos por offset (revela structs)."""
import ida_funcs
import ida_name
import re

OFF_RE = re.compile(r"(?:Field|Offset|Slot|Byte|Word|Dword|Float)([0-9A-Fa-fx]+)")


def main():
    qty = ida_funcs.get_func_qty()
    structs = []
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if name.startswith("FFX_Struct_"):
            structs.append((f.start_ea, name))
    print(f"FFX_Struct_: {len(structs)}", flush=True)
    # offsets vistos
    offsets = {}
    for ea, name in structs:
        m = OFF_RE.search(name)
        if m:
            off = m.group(1)
            offsets.setdefault(off, []).append(name)
    print(f"offsets unicos: {len(offsets)}", flush=True)
    for off in sorted(offsets, key=lambda x: int(x, 16) if x.isdigit() else 0)[:25]:
        print(f"  {off}: {len(offsets[off])} (ex: {offsets[off][0][:60]})", flush=True)


if __name__ == "__main__":
    main()
