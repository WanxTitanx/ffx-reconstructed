#!/usr/bin/env python3
"""Survey Iggy (UI toolkit) + FieldOp kinds (opcodes de campo)."""
import ida_funcs
import ida_name
from collections import Counter


def main():
    qty = ida_funcs.get_func_qty()
    iggy = []
    fieldop = Counter()
    fop_samples = {}
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if name.startswith("FFX_Iggy_"):
            iggy.append((f.start_ea, f.size(), name))
        elif name.startswith("FFX_FieldOp_"):
            rest = name[len("FFX_FieldOp_"):]
            kind = rest.split("_")[0] if rest else "?"
            fieldop[kind] += 1
            fop_samples.setdefault(kind, []).append(name)
    print(f"=== Iggy: {len(iggy)}", flush=True)
    for ea, size, name in iggy[:20]:
        print(f"  {hex(ea)} {size:4d} {name}", flush=True)
    print(f"=== FieldOp kinds: {len(fieldop)}", flush=True)
    for kind, count in fieldop.most_common(20):
        print(f"  {kind}: {count}  ex: {fop_samples[kind][0][:65]}", flush=True)


if __name__ == "__main__":
    main()
