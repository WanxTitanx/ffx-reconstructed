#!/usr/bin/env python3
"""Apply rename batch + evidence comments for the string-naming sweep (leva 7)."""
import json, sys
sys.path.insert(0, '.')
from mcp import Mcp

RENAMES = [
    # --- mislabeled -> corrected (string/xref proven) ---
    ("0x7dcd90", "FFX_Field_FormatMonsterMotionSrcPath"),     # host0:/home/%s/battle/%s/mon/_m%03d/mt%03d.src
    ("0x7dd4f0", "FFX_Field_GeneratePlayerMotionMacroFile"),  # #macro player_%02d_motion_set / summon_%02d
    ("0x76ba80", "FFX_Mscd_CdRead"),                          # installed into 'cd_read' cb slot; libmscd.c
    ("0x76c080", "FFX_Mscd_CdReadEx"),                        # DVD FILE/HDD FILE + sector resolve variant
    ("0x70e3b0", "FFX_FmodShout_InitData"),                   # "FmodShout::initData: NULL == mShoutFsb"
    ("0x70e560", "FFX_FmodShout_PlaySound"),                  # FmodShout.cpp 'ML' subsound table play
    ("0x70e4e0", "FFX_FmodShout_SetChannelVolume"),           # FmodShout.cpp channel setVolume
    ("0x70e530", "FFX_FmodShout_ReleaseSound"),               # FmodShout.cpp Sound::release
    ("0x708e30", "FFX_FmodMusic_InitData"),                   # "FmodMusic::initData: NULL == mEventProject!"
    ("0x708810", "FFX_FmodMusic_ReleaseEventSlot"),           # release+zero one 60B music event slot
    ("0x708900", "FFX_FmodMusic_ReleaseIdleEventSlots"),      # release all idle (f4==0 && state!=1) slots
    ("0x708be0", "FFX_FmodMusic_ReleaseAllEventSlots"),       # release every non-null slot
    ("0x7089f0", "FFX_FmodMusic_RequestTrackPlay"),           # play cmd: set flags, fade prev, ReadEvent+PlayTrack
    ("0x708f40", "FFX_FmodMusic_UpdateEventFades"),           # per-frame fade tick + auto-stop
    ("0x7e0f20", "FFX_FieldScript_ParserInit"),               # lexer char-class tables + #include hash + skip stack
    ("0x7e1500", "FFX_FieldScript_HandleDirective"),          # switch: include/define/if/endif/undef dispatch
    ("0x7e2180", "FFX_FieldScript_ParseFile"),                # file->buf + '# %d "%s"' linemarkers + per-line parse
    ("0x7e2680", "FFX_FieldScript_DefineMacro"),              # registers #define macro (name,args,body,funcLike)
    ("0x7e2970", "FFX_FieldScript_ExpandMacro"),              # identifier hash lookup + recursive expansion
    ("0x7d7fc0", "FFX_FieldDebug_PositionEditorHandler"),     # 17-case debug UI handler (0x8001+), BattlePos file
    ("0x6dd4e0", "FFX_MemDebug_DumpVramCsv"),                 # "WIN32_%s_%s_%lld.csv" addr,size,memtype,desc dump
    ("0x86e540", "FFX_FieldActor_SyncVisibilityAndMotion"),   # Force Disable Hide + SetVisibilityConditional + mgrp
    ("0x7e7f40", "FFX_Math_OpMNormalize"),                    # "*** Calling op_m_normalize() math.c:%d ***"
    ("0x7e8a10", "FFX_Math_OpMulM33"),                        # "*** Calling op_mul_m33() math.c:%d ***"
    ("0x8409a0", "FFX_ResourceCache_EvictOnOverflow"),        # "Memory overflow!!" + "disposed from Cache" + Free
    ("0x7e45c0", "FFX_Magic_Oef2ClutLoad"),                   # "CLUTINFO was null in Yonishi op_oef2_clut_load"
    ("0x80b960", "FFX_MagicCoreOp_DD_PartRun"),               # "osu->malloc is NULL in opu_part_run() u_15.c"
    ("0x80bea0", "FFX_Magic_OppMain"),                        # "effect func ptr in opp_main() is NULL"
    ("0x814610", "FFX_MagicCoreOp_D4_Bind2"),                 # "(op)\topu_bind2\t\tno ground id(%d)"
    ("0x814b60", "FFX_MagicCoreOp_DF_DumpTextureClut"),       # "u_file_tc[] texture clut data write file" t_*.txc
    ("0x665390", "FFX_Menu2D_LoadDefaultMenuShader"),         # loads MenuDefaultShaderNA.cgfx.phyre via Phyre
    # --- _structural suffix drop (string evidence confirms) ---
    ("0x6657f0", "FFX_DatEt_LoadVfxTexLists_Global"),
    ("0x6714a0", "FFX_Ps3Data_LoadTextureListAndRegisterEntries"),
    ("0x6e7180", "FFX_Menu_UpdateInputDeviceIconPrompt"),
    ("0x6e7430", "FFX_Menu_UpdateInputDeviceIconPromptFromState"),
    ("0x7cd730", "FFX_Menu2D_TextWriter"),
    ("0x7d1e80", "FFX_Camera_DebugDisplayTagTable"),
    ("0x7d7a50", "FFX_Field_DebugPrintActorDistances"),
    ("0x7d9620", "FFX_Field_DebugDisplayActorSlotInfo"),
    ("0x7dcdd0", "FFX_Field_FormatMotionSrcPath"),
    ("0x7dce80", "FFX_Field_DebugFormatMotionTypeSetstat"),
    ("0x7dd390", "FFX_Field_GenerateMonsterMotionMacro"),
    ("0x7dd7a0", "FFX_Field_DebugFieldMonitorUI"),
    ("0x7e1da0", "FFX_FieldScript_ReadParenthesizedArg"),
    ("0x7e5b20", "FFX_File_ReadToAllocatedBuffer"),
    ("0x7e5be0", "FFX_File_GetFileSize"),
    ("0x7e6a60", "FFX_Debug_DumpHexMemory"),
    ("0x7ff280", "FFX_DatEt_InitRuntimeAndLoadEffectBins"),
    ("0x7e37b0", "FFX_Magic_Oef2SetParticleData"),
    ("0x7e3a80", "FFX_Magic_Oef2RelocateDataSections"),
    ("0x713870", "FFX_MagicHost_BuildVfxTextureBindingDispatch"),
    ("0x715bd0", "FFX_MagicHost_BuildVfxTextureRecordsFromNames"),
    ("0x81f320", "FFX_SoundSpuCmd_InitTransferQueue"),
    ("0x825ac0", "FFX_Debug_ModelBrowserUpdateFromDebug"),
    ("0x826f20", "FFX_Chr_InitCommonTablesAndResetActiveInstances"),
    ("0x829f70", "FFX_Chr_LoadChrDataAsync"),
    ("0x8405f0", "FFX_ResourceCache_SetReadState"),
    ("0x8406f0", "FFX_ResourceCache_GetDataPtrWarnIfPending"),
    ("0x843260", "FFX_GS_DmaSyncCheckpointA"),
    ("0x843360", "FFX_GS_WaitVif1DmaSyncAndDumpTimeout"),
    ("0x86dde0", "FFX_FieldVM_PopFloatOperand"),
    ("0x8781b0", "FFX_Atel_ReadEncounterGroupFromSaveStack"),
    ("0xa445f0", "FFX_Atel_AbilityMap_FuncD000_CALL"),
    ("0xa79980", "FFX_Atel_ChEvent_ReadSystemMgrpFinishCallback"),
    ("0x7810f0", "FFX_Encounter_Loader"),
    ("0x7a4930", "FFX_Atel_Battle_Print_CALL"),
    ("0x7a4a80", "FFX_Atel_Battle_BtlPrintSp_CALL"),
    ("0x80b7d0", "FFX_MagicCoreOp_DC_Draw"),
    ("0x81bcd0", "FFX_MagicCoreOp_8F_Transform"),
    ("0x80cd60", "FFX_Magic_RunRuntimeRootPhase"),
    ("0x7d9b40", "FFX_Field_LocationMarkersFontBlit"),
    # --- fieldscript cluster prefix normalization ---
    ("0x7e1c60", "FFX_FieldScript_ReadToken"),
    ("0x7e1b40", "FFX_FieldScript_ReadStringChunkAndTrim"),
    ("0x7e11e0", "FFX_FieldScript_BuildCharLookupTable"),
    ("0x7e2ca0", "FFX_FieldScript_BuildKeywordHash"),
    ("0x7e10b0", "FFX_FieldScript_ComputeStringDoubleHash"),
    ("0x7e2de0", "FFX_File_OpenAndReadToBuffer"),
    ("0x7de610", "FFX_Mem_AppendStringToBlockBuffer"),
]

m = Mcp()
batch = [{"addr": a, "name": n} for a, n in RENAMES]
r = m.call('rename', {'batch': {'func': batch}})
print(r[:4000])
