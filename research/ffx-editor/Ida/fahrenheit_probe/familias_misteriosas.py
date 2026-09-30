#!/usr/bin/env python3
"""Investiga familias misteriosas: __TO*, BulletPhysics*, Physics_*, ManagedCpp_*."""
import ida_funcs
import ida_name
from collections import Counter


def main():
    qty = ida_funcs.get_func_qty()
    fams = Counter()
    samples = {}
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        for prefix in ("__TO", "BulletPhysics", "Physics_", "ManagedCpp", "Engine_",
                       "FFX_Debug_", "FFX_Render_Texture", "Phyre_Zlib"):
            if name.startswith(prefix):
                fams[prefix] += 1
                samples.setdefault(prefix, []).append((f.start_ea, f.size(), name))
    for fam, count in fams.most_common():
        print(f"{fam}: {count} funcoes", flush=True)
        for ea, size, name in samples[fam][:8]:
            print(f"    {hex(ea)} {size:5d} {name}", flush=True)


if __name__ == "__main__":
    main()
