#!/usr/bin/env python3
"""Subdivide FFX_outros: prefixos de 2a palavra das funcoes FFX_* nao mapeadas."""
import ida_funcs
import ida_name
from collections import Counter

KNOWN = ("Sphere", "FieldMap", "FieldMath", "Field", "Battle", "Btl", "Magic", "Ppp",
         "Abmap", "Menu2D", "Atel", "Save", "Sound", "Text", "Input", "Encounter",
         "Camera", "KR", "GDraw", "Mscd", "Event", "Chr", "Vpx", "Phyre", "Virtuos",
         "Math", "BattleModel", "Menu", "Debug", "Config", "File", "Ps3Data",
         "TexAnim", "ClusterHandle", "Pmcom", "Model", "HelpSystem", "Scene",
         "EffectRegistry", "Settings", "DatEt", "Video", "VideoStream", "Movie",
         "Texture", "BtlUI", "FieldDebug", "Render", "Character", "BtlChr")


def main():
    qty = ida_funcs.get_func_qty()
    fams = Counter()
    samples = {}
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        if not name.startswith("FFX_"):
            continue
        parts = name.split("_")
        if len(parts) < 3:
            continue
        second = parts[1]
        if second in KNOWN:
            continue
        fams[second] += 1
        samples.setdefault(second, []).append(name)
    print(f"familias FFX_<X> nao mapeadas: {len(fams)}", flush=True)
    for fam, count in fams.most_common(30):
        print(f"  {fam}: {count}  ex: {samples[fam][0][:60]}", flush=True)


if __name__ == "__main__":
    main()
