#!/usr/bin/env python3
"""Anatomia do exe: contagem e tamanho de codigo por modulo (prefixo FFX_*/Phyre*/ppp*)."""
import ida_funcs
import ida_name
from collections import defaultdict


def module_of(name):
    for prefix in ("FFX_Sphere", "FFX_FieldMap", "FFX_FieldMath", "FFX_Field", "FFX_Battle",
                   "FFX_Btl", "FFX_Magic", "FFX_Ppp", "FFX_Abmap", "FFX_Menu2D", "FFX_Atel",
                   "FFX_Save", "FFX_Sound", "FFX_Text", "FFX_Input", "FFX_Encounter",
                   "FFX_Camera", "FFX_KR", "FFX_GDraw", "FFX_Mscd", "FFX_Event", "FFX_Chr",
                   "FFX_Vpx", "FFX_Phyre", "FFX_Virtuos", "FFX_Math", "FFX_BattleModel"):
        if name.startswith(prefix):
            return prefix
    if name.startswith("Phyre") or name.startswith("PClassDescriptor"):
        return "Phyre"
    if name.startswith("ppp"):
        return "ppp"
    if name.startswith("FmodManager"):
        return "FmodManager"
    if name.startswith("FFX_"):
        return "FFX_outros"
    return None


def main():
    qty = ida_funcs.get_func_qty()
    stats = defaultdict(lambda: [0, 0])
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        mod = module_of(name)
        if mod:
            stats[mod][0] += 1
            stats[mod][1] += f.size()
    print(f"{'modulo':<22} {'fns':>6} {'bytes':>9}", flush=True)
    total_f = total_b = 0
    for mod, (count, size) in sorted(stats.items(), key=lambda kv: -kv[1][1]):
        print(f"{mod:<22} {count:>6} {size:>9}", flush=True)
        total_f += count
        total_b += size
    print(f"{'TOTAL':<22} {total_f:>6} {total_b:>9}", flush=True)


if __name__ == "__main__":
    main()
