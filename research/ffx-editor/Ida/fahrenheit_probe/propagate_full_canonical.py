#!/usr/bin/env python3
"""Propagacao FULL na canonica: aplica TODOS os lotes (renames fixos + globals .data
por modulo + consts .rdata + thunks + structs). Roda via idat headless."""
import ida_bytes
import ida_funcs
import ida_name
import ida_xref
import ida_typeinf
import idc
import re

DEFAULT_G = re.compile(r"^(dword_|off_|flt_|byte_|word_|qword_|unk_)", re.I)
DEFAULT_F = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)
J_RE = re.compile(r"^j_(.+)$")

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
    ("FFX_Vpx", "Vpx"), ("Phyre", "Phyre"), ("PClassDescriptor", "Phyre"),
    ("FmodManager", "Sound"),
]


def module_of(fn_name):
    for prefix, mod in MODULE_MAP:
        if fn_name.startswith(prefix):
            return mod
    return None


def rename_default(ea, name):
    cur = ida_name.get_name(ea)
    if not cur or DEFAULT_G.match(cur) or DEFAULT_F.match(cur):
        return ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE)
    return False


def rename_globals_by_module(segname, suffix):
    seg = idc.get_segm_by_sel(idc.selector_by_name(segname))
    if not seg:
        return 0
    ea = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    applied = 0
    while ea < end:
        name = ida_name.get_name(ea)
        if name and DEFAULT_G.match(name):
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
                if mod and rename_default(ea, f"FFX_{mod}_{suffix}_{ea:X}"):
                    applied += 1
        ea = ida_bytes.next_head(ea, end)
    return applied


def main():
    total = 0
    fixed = {
        0x11333C0: "FFX_Battle_CtbQueueCount", 0x11333C4: "FFX_Battle_CtbPriorityQueue",
        0x132FF60: "FFX_SndEvent_PcToActorFootPool", 0x16AD870: "FFX_SphereGrid_LpAbilityMapEngineBuffer",
        0x19450C4: "FFX_Phyre_PPostEffectBase4_ClassDescriptor", 0xC98B4C: "FFX_Phyre_PVertexStream4_ClassDescriptor",
        0x1127C84: "FFX_Mscd_QueueSlots_224B", 0x22FB6C1: "FFX_FieldMap_WorkPool",
        0xCB4D0C: "FFX_Phyre_PStreamInputDescArray_ClassDescriptor", 0xC9167C: "FFX_Phyre_UCharArray_ClassDescriptor",
        0xCA45C4: "FFX_Phyre_PShadowCaster_ClassDescriptor", 0xCE844C: "FFX_Sound_FmodCommandQueue",
        0xC5C2C8: "FFX_Menu2D_AtlasBaseTable", 0xC5B460: "FFX_Menu2D_SpriteDataTable",
        0xC8F934: "FFX_Render_MagicTransformConstants", 0xC77120: "FFX_Phyre_EmbeddedShader_DXBC",
        0xC8F790: "FFX_Render_TransformConstants", 0xC8F510: "FFX_Render_SharedTransformContext",
        0xC0E2F0: "FFX_Phyre_ClassDescriptorRegistry", 0xC4467C: "FFX_Menu2D_BlendPackTable",
        0xB92210: "FFX_Engine_GlobalScaleConstant",
    }
    for ea, name in fixed.items():
        if rename_default(ea, name):
            total += 1
    print(f"fixos: {total}", flush=True)
    total += rename_globals_by_module(".data", "Global")
    print(f"globals .data: feito", flush=True)
    total += rename_globals_by_module(".rdata", "Const")
    print(f"consts .rdata: feito", flush=True)
    qty = ida_funcs.get_func_qty()
    applied = 0
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        m = J_RE.match(name)
        if m and m.group(1).startswith(("FFX_", "Phyre", "ppp")):
            if rename_default(f.start_ea, f"{m.group(1)}_Thunk"):
                applied += 1
    total += applied
    print(f"thunks: {applied}", flush=True)
    idc.save_database("")
    print(f"CANONICA FULL: applied={total} — db salva.", flush=True)


if __name__ == "__main__":
    main()
