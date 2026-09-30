#!/usr/bin/env python3
"""Lote 7: renomeia globals default do .rdata por MODULO da funcao dominante (constantes).

Nome: FFX_<MOD>_Const_<ADDR>. So renomeia default; nunca sobrescreve.
"""
import ida_bytes
import ida_funcs
import ida_name
import ida_xref
import idc
import re

DEFAULT = re.compile(r"^(off_|dword_|unk_|byte_|word_|qword_|flt_)", re.I)

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
    ("FFX_Vpx", "Vpx"), ("FFX_Phyre", "Phyre"),
    ("Phyre", "Phyre"), ("PClassDescriptor", "Phyre"),
    ("FmodManager", "Sound"),
]


def module_of(fn_name):
    for prefix, mod in MODULE_MAP:
        if fn_name.startswith(prefix):
            return mod
    return None


def main():
    seg = idc.get_segm_by_sel(idc.selector_by_name(".rdata")) or idc.get_first_seg()
    start = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    ea = start
    applied, no_mod, no_ref = 0, 0, 0
    while ea < end:
        name = ida_name.get_name(ea)
        if name and DEFAULT.match(name):
            fns = {}
            xb = ida_xref.get_first_dref_to(ea)
            while xb != idc.BADADDR:
                f = ida_funcs.get_func(xb)
                if f:
                    fname = ida_name.get_name(f.start_ea) or ""
                    if fname:
                        fns[fname] = fns.get(fname, 0) + 1
                xb = ida_xref.get_next_dref_to(ea, xb)
            if fns:
                top_fn = max(fns, key=fns.get)
                mod = module_of(top_fn)
                if mod:
                    new_name = f"FFX_{mod}_Const_{ea:X}"
                    if ida_name.set_name(ea, new_name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                        applied += 1
                else:
                    no_mod += 1
            else:
                no_ref += 1
        ea = ida_bytes.next_head(ea, end)
    idc.save_database("")
    print(f"DONE: applied={applied} sem_modulo={no_mod} sem_xrefs={no_ref} — db salva.", flush=True)


if __name__ == "__main__":
    main()
