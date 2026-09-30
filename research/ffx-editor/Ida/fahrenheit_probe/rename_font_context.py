#!/usr/bin/env python3
"""Renomeia 0xCCC820 (contexto de fontes do menu) + 0xCCC818 (getter)."""
import ida_name
import idc

RENAMES = {
    0x2322790: "FFX_Magic_EffectPool_2MB",
    0x2322668: "FFX_Magic_EffectPool_Header",
    0xC34194: "Phyre_RBTree_Root_C34194",
    0xC44260: "FFX_Menu2D_StartDataSystem",
    0xC24F0C: "Phyre_PClusterGlobalList",
    0xC0A09C: "Phyre_PApplication_Instance",
    0xC53414: "FFX_FieldDebug_BookContext",
    0xC169B4: "FFX_Render_TransformMatrixState",
    0xC59564: "FFX_Menu_InternationalContext",
    0xC0BB70: "Phyre_EntityTree",
    0xC8F86C: "FFX_Math_Matrix4x4Const",
    0xC87872: "FFX_Settings_DisplayPaletteTable",
    0xC39620: "FFX_MenuAudio_SettingsTable",
    0xC49714: "FFX_FieldParticle_Data",
    0xC5A040: "FFX_Menu_DigitWheelTable",
    0xC5B360: "FFX_Menu_ListInputTable",
    0xC5E350: "FFX_DebugFlagsTable",
    0xC6B274: "FFX_Video_DecodeThreadBuffer",
    0xC6D448: "Iggy_GDraw_State",
}


def main():
    applied = 0
    for ea, name in RENAMES.items():
        cur = ida_name.get_name(ea)
        if not cur or cur.startswith(("dword_", "byte_", "unk_", "off_", "word_", "flt_", "qword_")):
            if ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                applied += 1
    idc.save_database("")
    print(f"DONE: applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()
