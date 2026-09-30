#!/usr/bin/env python3
"""Propagacao CANONICA: aplica os lotes determinísticos na db canonica via idalib.

Roda quando a canonica (ffxoficial.exe.i64) estiver livre (sem idat/idapython nela).
Uso: idat64 -A -S"<este script>" -Llog.txt ffxoficial.exe.i64
"""
import ida_name
import ida_typeinf
import idc
import re

DEFAULT_G = re.compile(r"^(dword_|off_|flt_|byte_|word_|qword_|unk_)", re.I)
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
    if not cur or DEFAULT_G.match(cur):
        return ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE)
    return False


def main():
    applied = 0
    # 1) renames fixos (buffers provados)
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
            applied += 1
    # 2) struct LpAbilityMapEngine
    idati = ida_typeinf.get_idati()
    ti = ida_typeinf.tinfo_t()
    decl = ("struct FFX_LpAbilityMapEngine { char state[8]; char clusters[2048]; "
            "char nodes[40960]; char links[14336]; char node_type_ui[33280]; };")
    if ida_typeinf.parse_decl(ti, idati, decl, 0):
        if ida_typeinf.apply_tinfo(0x16AD870, ti, ida_typeinf.TINFO_DEFINITE):
            applied += 1
    # 3) struct FFX_AtelFuncspaceEntry nas 12 tabelas (tamanhos reais)
    tables = [(0xC40E20, 383), (0xC42618, 311), (0xC43988, 3180), (0xC50050, 689),
              (0xC52B60, 8), (0xC52BE0, 31), (0xC52DD8, 2734), (0xC5D8C0, 61),
              (0xC5DC90, 4096), (0xC85EB0, 749), (0xC88D88, 71), (0xC891F8, 256)]
    ti2 = ida_typeinf.tinfo_t()
    if ida_typeinf.parse_decl(ti2, idati,
                              "struct FFX_AtelFuncspaceEntry { void *callpopa_fn; void *status_fn; "
                              "void *float_return_fn; void *int_return_fn; };", 0):
        for ea, count in tables:
            arr = ida_typeinf.tinfo_t()
            if arr.create_array(ti2, count) and ida_typeinf.apply_tinfo(ea, arr, ida_typeinf.TINFO_DEFINITE):
                applied += 1
    idc.save_database("")
    print(f"CANONICA: applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()
