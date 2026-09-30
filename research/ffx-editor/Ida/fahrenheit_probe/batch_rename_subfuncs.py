#!/usr/bin/env python3
"""Lote 2: renomeia funcoes default (sub_*) chamadas por EXATAMENTE 1 funcao nomeada.

Nome: FFX_<MODULO>_<PAI>_Sub_<ADDR> (ex: FFX_Magic_InitRecordStructDefaults_Sub_C12345).
So renomeia default; nunca sobrescreve. Pais sem modulo (ex: nullsub_) pulados.
"""
import ida_funcs
import ida_name
import ida_xref
import idc
import re

DEFAULT = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)
MODULE_MAP = [
    ("FFX_Magic", "Magic"), ("FFX_Ppp", "Ppp"), ("ppp", "Ppp"),
    ("FFX_Abmap", "Abmap"), ("FFX_FieldMap", "FieldMap"),
    ("FFX_Field_", "Field"), ("FFX_FieldMath", "Field"),
    ("FFX_Battle", "Battle"), ("FFX_Btl", "Battle"),
    ("FFX_Sound", "Sound"), ("FFX_Menu2D", "Menu2D"),
    ("FFX_Atel", "Atel"), ("FFX_Save", "Save"),
    ("FFX_Sphere", "SphereGrid"), ("FFX_Text", "Text"),
    ("FFX_Input", "Input"), ("FFX_Encounter", "Encounter"),
    ("FFX_Camera", "Camera"), ("FFX_KR_", "Kernel"),
    ("FFX_GDraw", "GDraw"), ("FFX_Mscd", "Mscd"),
    ("FFX_Event", "Event"), ("FFX_Chr", "Chr"),
    ("Phyre", "Phyre"), ("PClassDescriptor", "Phyre"),
    ("FmodManager", "Sound"),
]


def module_of(fn_name):
    for prefix, mod in MODULE_MAP:
        if fn_name.startswith(prefix):
            return mod
    return None


def main():
    qty = ida_funcs.get_func_qty()
    applied, skipped, no_parent = 0, 0, 0
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        fname = ida_name.get_name(f.start_ea)
        if not fname or not DEFAULT.match(fname):
            continue
        # coleta chamadores (code xrefs)
        callers = set()
        xb = ida_xref.get_first_cref_to(f.start_ea)
        while xb != idc.BADADDR:
            cf = ida_funcs.get_func(xb)
            if cf:
                callers.add(cf.start_ea)
            xb = ida_xref.get_next_cref_to(f.start_ea, xb)
        if len(callers) != 1:
            skipped += 1
            continue
        parent = list(callers)[0]
        pname = ida_name.get_name(parent) or ""
        mod = module_of(pname)
        if not mod or "_Sub_" in fname or fname.startswith("FFX_"):
            skipped += 1
            continue
        base = pname.replace("FFX_", "").replace("_structural", "").replace("_CALL", "")
        new_name = f"FFX_{mod}_{base}_Sub_{f.start_ea:X}"
        if ida_name.set_name(f.start_ea, new_name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            applied += 1
    idc.save_database("")
    print(f"DONE: applied={applied} skipped={skipped} — db salva.", flush=True)


if __name__ == "__main__":
    main()
