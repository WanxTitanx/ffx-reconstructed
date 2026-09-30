#!/usr/bin/env python3
"""Lista os ops da FieldVM (295 funcoes FFX_FieldVM_*)."""
import ida_funcs
import ida_name
from collections import Counter


def main():
    qty = ida_funcs.get_func_qty()
    ops = Counter()
    samples = {}
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if not name.startswith("FFX_FieldVM_"):
            continue
        # pega a parte apos FieldVM_ (ex: Op_SelectControlledActor)
        rest = name[len("FFX_FieldVM_"):]
        kind = rest.split("_")[0] if rest else "?"
        ops[kind] += 1
        samples.setdefault(kind, []).append(name)
    print(f"FieldVM kinds: {len(ops)}", flush=True)
    for kind, count in ops.most_common(15):
        print(f"  {kind}: {count}  ex: {samples[kind][0][:70]}", flush=True)


if __name__ == "__main__":
    main()
