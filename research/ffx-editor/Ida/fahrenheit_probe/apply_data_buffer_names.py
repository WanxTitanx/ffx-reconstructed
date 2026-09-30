#!/usr/bin/env python3
"""Renomeia globals identificados do .data (CTB queue, SndEvent pool)."""
import ida_name
import idc

RENAMES = {
    0x11333C0: "FFX_Battle_CtbQueueCount",
    0x11333C4: "FFX_Battle_CtbPriorityQueue",
    0xC8F790: "FFX_Render_TransformConstants",
    0xC8F510: "FFX_Render_SharedTransformContext",
    0xC4467C: "FFX_Menu2D_BlendPackTable",
    0xCC0784: "FFX_Phyre_RigidBody_ClassDescriptor",
    0xC0E2F0: "FFX_Phyre_ClassDescriptorRegistry",
    0xC9165C: "FFX_Phyre_PArrayU8_ClassDescriptor",
    0xCB2224: "FFX_Phyre_SpriteSystem_ClassDescriptorRegistry",
    0x132FF60: "FFX_SndEvent_PcToActorFootPool",
    0x16AD870: "FFX_SphereGrid_LpAbilityMapEngineBuffer",
    0x19450C4: "FFX_Phyre_PPostEffectBase4_ClassDescriptor",
    0xC98B4C: "FFX_Phyre_PVertexStream4_ClassDescriptor",
    0x1127C84: "FFX_Mscd_QueueSlots_224B",
    0x22FB6C1: "FFX_FieldMap_WorkPool",
    0xCB4D0C: "FFX_Phyre_PStreamInputDescArray_ClassDescriptor",
    0xC9167C: "FFX_Phyre_UCharArray_ClassDescriptor",
    0xCA45C4: "FFX_Phyre_PShadowCaster_ClassDescriptor",
    0xCE844C: "FFX_Sound_FmodCommandQueue",
    0xC5C2C8: "FFX_Menu2D_AtlasBaseTable",
    0xC5B460: "FFX_Menu2D_SpriteDataTable",
    0xC8F934: "FFX_Render_MagicTransformConstants",
    0xC77120: "FFX_Phyre_EmbeddedShader_DXBC",
}


def main():
    applied = 0
    for ea, name in RENAMES.items():
        cur = ida_name.get_name(ea)
        if cur and not cur.startswith(("byte_", "dword_", "unk_", "off_")):
            print(f"skip {hex(ea)} (ja tem {cur})", flush=True)
            continue
        if ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            applied += 1
    idc.save_database("")
    print(f"DONE: applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()
