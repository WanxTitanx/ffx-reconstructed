#!/usr/bin/env python3
"""Lote 1 EXPANDIDO: varre TODO o .data, renomeia globals default por MODULO da funcao dominante.

Heuristica: top_fn (funcao que mais referenciou o global) -> prefixo do modulo.
Nome: FFX_<MODULO>_Global_<ADDR>. So renomeia default; nunca sobrescreve.
"""
import ida_bytes
import ida_funcs
import ida_name
import ida_xref
import idc
import re

DEFAULT = re.compile(r"^(dword_|off_|flt_|byte_|word_|qword_|unk_)", re.I)
GLOBAL_PAT = re.compile(r"^FFX_")

MODULE_MAP = [
    ("FFX_Magic", "Magic"), ("FFX_Ppp", "Ppp"), ("ppp", "Ppp"),
    ("FFX_Abmap", "Abmap"), ("FFX_FieldMap", "FieldMap"),
    ("FFX_Field_", "Field"), ("FFX_FieldMath", "Field"),
    ("FFX_Battle", "Battle"), ("FFX_Btl", "Battle"),
    ("FFX_Sound", "Sound"), ("FFX_Menu2D", "Menu2D"),
    ("FFX_Atel", "Atel"), ("FFX_AtelOp", "Atel"),
    ("FFX_FieldOp", "Field"), ("FFX_FieldVM", "Field"), ("FFX_FieldActor", "Field"),
    ("FFX_MagicHost", "Magic"), ("FFX_MagicCoreOp", "Magic"), ("FFX_MagicVfx", "Magic"),
    ("FFX_Iggy", "Menu2D"), ("FFX_CustomizeMenu", "Menu2D"), ("FFX_EscMenu", "Menu2D"),
    ("FFX_Audio", "Sound"), ("FFX_FmodSfx", "Sound"), ("FFX_FmodVoice", "Sound"),
    ("FFX_FmodMusic", "Sound"), ("FFX_SoundCmd", "Sound"),
    ("FFX_Save", "Save"),
    ("FFX_Sphere", "SphereGrid"), ("FFX_Text", "Text"),
    ("FFX_Input", "Input"), ("FFX_Encounter", "Encounter"),
    ("FFX_Camera", "Camera"), ("FFX_KR_", "Kernel"),
    ("FFX_GDraw", "GDraw"), ("FFX_Mscd", "Mscd"),
    ("FFX_Event", "Event"), ("FFX_Chr", "Chr"),
    ("Phyre", "Phyre"), ("PhyreInit", "Phyre"), ("PCluster", "Phyre"), ("PClassDescriptor", "Phyre"),
    ("FmodManager", "Sound"),
]


def module_of(fn_name):
    for prefix, mod in MODULE_MAP:
        if fn_name.startswith(prefix):
            return mod
    return None


def main():
    seg = idc.get_segm_by_sel(idc.selector_by_name(".data")) or idc.get_first_seg()
    start = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    ea = start
    applied, named, no_mod, no_ref = 0, 0, 0, 0
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
                    new_name = f"FFX_{mod}_Global_{ea:X}"
                    if ida_name.set_name(ea, new_name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                        applied += 1
                else:
                    no_mod += 1
            else:
                no_ref += 1
        elif name and GLOBAL_PAT.match(name):
            named += 1
        ea = ida_bytes.next_head(ea, end)
    idc.save_database("")
    print(f"DONE: applied={applied} ja_nomeados={named} sem_modulo={no_mod} sem_xrefs={no_ref} — db salva.", flush=True)


if __name__ == "__main__":
    main()
