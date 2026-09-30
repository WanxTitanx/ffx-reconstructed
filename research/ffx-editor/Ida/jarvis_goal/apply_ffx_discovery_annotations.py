# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): source restored from git history
# commit 53d82b2a, original path RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/<name>.
# The work/reverse/ida/scripts/ tree was never committed at its original location;
# only __pycache__/*.pyc + this history copy survived. Cited by docs/reverse/* + SESSION_HANDOFF.
import json
import os
from pathlib import Path

import ida_auto
import ida_funcs
import ida_kernwin
import ida_name
import idc


# FIX 2026-09-18 (Jarvis-TOOLS-REPAIR): parents[3] = repo root at the new
# research_tools/Ida/jarvis_goal/ location; parents[4] was stale from the
# FFXMapViewerWeb recovery and resolved to ~/Documents/ (reports would write outside the repo).
REPO_ROOT = Path(__file__).resolve().parents[3]
REPORT_PATH = REPO_ROOT / "work" / "reverse" / "ida" / "exports" / "ffx_apply_discovery_annotations_report.json"


ANNOTATIONS = [
    {
        "ea": 0x00C43988,
        "name": "g_FFX_Atel_CameraFuncspaceTable",
        "kind": "data",
        "repeatable_comment": (
            "[proved 2026-06-07 camera-polar] Camera namespace funcspace table for ATEL calls. "
            "The battle camera CALL handlers used here are in slot +12, not slot +0; e.g. "
            "0x6004 entry+12 -> FFX_Atel_Camera_camSetPolar_CALL. "
            "Source: FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07 §6d."
        ),
    },
    {
        "ea": 0x007B9260,
        "name": "FFX_Atel_Camera_camSetPolar_CALL",
        "kind": "func",
        "repeatable_comment": (
            "[proved 2026-06-07 camera-polar] ATEL Camera func 0x6004 CALL-slot wrapper. "
            "Calls FFX_Camera_SetPolar_FromAtelStack(vmCtx, ..., mode=1, flags=0). "
            "Streamed args are horizontalDeg, elevationDeg, distance. "
            "Source: FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07 §6d."
        ),
    },
    {
        "ea": 0x007BB550,
        "name": "FFX_Camera_SetPolar_FromAtelStack",
        "kind": "func",
        "repeatable_comment": (
            "[proved 2026-06-07 camera-polar] Pops camSetPolar args from ATEL stack in reverse order: "
            "distance, elevationDeg, horizontalDeg; converts degrees to radians and dispatches the absolute "
            "polar camera setter. See FFX_Camera_PolarToCartesian for the final axis formula."
        ),
    },
    {
        "ea": 0x007C4760,
        "name": "FFX_Camera_PolarToCartesian",
        "kind": "func",
        "repeatable_comment": (
            "[proved 2026-06-07 camera-polar] camSetPolar cartesian projection: "
            "x=refX+cos(horizontal)*cos(elevation)*distance; "
            "y=refY+sin(elevation)*distance; "
            "z=refZ+sin(horizontal)*cos(elevation)*distance. Angles are radians here, degrees in ATEL."
        ),
    },
    {
        "ea": 0x007BAD30,
        "name": "FFX_Camera_SetBattlePolar_TargetAware",
        "kind": "func",
        "repeatable_comment": (
            "[structural 2026-06-07 camera-polar] Shared target-aware path for camSetBtlPolar*/camSetChrPolar2 "
            "variants (0x6040/0x6044/0x604D family). It consumes actor refs/target geometry and must not be "
            "collapsed into the simple camSetPolar 0x6004 inverse without further proof."
        ),
    },
    {
        "ea": 0x009DA420,
        "name": "FFX_MagicFile_LoadDllByMagicId",
        "kind": "func",
        "repeatable_comment": (
            "[proved] MagicFile lifecycle load step. Fails without current magicId, calls preload, builds "
            "magicFiles\\\\FFX\\\\magic_%04d.dll, then loads the DLL via the host loader callback path. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x009DA780,
        "name": "FFX_MagicFile_SetMagicId",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Writes the active magicId and rejects transitions while another magic is still active. "
            "Lifecycle order anchor for MagicFile load/start/stop/unload. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x009DA7D0,
        "name": "FFX_MagicFile_Start",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Start step after DLL load/bind. Calls InitMagicPRX(&off_C64CE8) only after the export "
            "callbacks are resolved. Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x009DA860,
        "name": "FFX_MagicFile_Stop",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Stop/teardown-visible lifecycle step. Called by near-scene wrappers before deeper unload. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x009DA940,
        "name": "FFX_MagicFile_Unload",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Wider teardown/unload step. Calls clear-preload before the final module release. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x009DACA0,
        "name": "FFX_MagicFile_ClearPreloadedPrx",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Clears preloaded PRX/cache state. Also exposed through scene-reset hygiene wrappers. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x009DAE70,
        "name": "FFX_MagicFile_PreloadAsync",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Real preload/cache layer. Walks preload slots, frees conflicting handles, and issues "
            "preload work before visible load/start. Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x009DB0F0,
        "name": "FFX_MagicFile_BindDllExports",
        "kind": "func",
        "allowed_old_names": ["FFX_MagicFile_InvokeInitMagicPrx"],
        "repeatable_comment": (
            "[proved] Resolves/binds DLL exports via GetProcAddress. This is the exact bind point for "
            "GetEffectOverlayTable and InitMagicPRX, not the InitMagicPRX invocation itself. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00787FE0,
        "name": "FFX_MagicFile_LoadWrapper_A",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Immediate wrapper that proves SetMagicId -> Load ordering by calling "
            "FFX_MagicFile_SetMagicId then FFX_MagicFile_LoadDllByMagicId."
        ),
    },
    {
        "ea": 0x00788D20,
        "name": "FFX_MagicFile_LoadWrapper_B",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Sibling immediate wrapper for SetMagicId -> Load ordering."
        ),
    },
    {
        "ea": 0x007881D0,
        "name": "FFX_MagicFile_StartWrapper_A",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Immediate wrapper that calls FFX_MagicFile_Start and then local follow-up state work."
        ),
    },
    {
        "ea": 0x00788DD0,
        "name": "FFX_MagicFile_StartWrapper_B",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Sibling immediate wrapper for the MagicFile start path."
        ),
    },
    {
        "ea": 0x00787BB0,
        "name": "FFX_MagicFile_StopWrapper_A",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Near-scene stop/teardown wrapper that ends in FFX_MagicFile_Stop."
        ),
    },
    {
        "ea": 0x00788CC0,
        "name": "FFX_MagicFile_StopWrapper_B",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Sibling stop/teardown wrapper that ends in FFX_MagicFile_Stop."
        ),
    },
    {
        "ea": 0x009DAC80,
        "name": "FFX_MagicFile_ClearPreloadWrapper",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Thin wrapper around FFX_MagicFile_ClearPreloadedPrx used by init/scene-reset hygiene."
        ),
    },
    {
        "ea": 0x008222E0,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[proved] Gate/poll loop above the real MagicFile start wrappers. Load does not imply start; "
            "this context decides when FFX_MagicFile_StartWrapper_A/B are fired."
        ),
    },
    {
        "ea": 0x00820C00,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[proved] Late frame/scene caller of the MagicFile unload path via FFX_MagicFile_Unload."
        ),
    },
    {
        "ea": 0x0088DFE0,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[proved] Scene-reset hygiene path that calls FFX_MagicFile_ClearPreloadWrapper(-1)."
        ),
    },
    {
        "ea": 0x00C64CE8,
        "name": "FFX_Magic_InitMagicPrxHostContext",
        "kind": "data",
        "repeatable_comment": (
            "[proved] Host context block passed to InitMagicPRX(&off_C64CE8). Offsets +2968/+2972 reconnect "
            "this block to the runtime root table/recipe lane. Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x012A4080,
        "name": "FFX_Magic_RuntimeRootTable",
        "kind": "data",
        "repeatable_comment": (
            "[proved] Runtime root/recipe table consumed by the structural phase trio and materialized by "
            "sub_7FD9A0. Do not read this as a simple overlay-slot array. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00C48D9C,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[proved] Real pointer block for the first runtime phase dispatch family. Slot 0 -> "
            "FFX_Magic_RunPhase0_structural, slot 1 -> FFX_Magic_RunPhase1_structural, later slots mostly "
            "nullsub stubs. Together with 0x00C48E04, proves the phase trio lives in data tables, not in "
            "ad hoc overlay-timing code. Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00C48E04,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[proved] Continuation of the runtime phase dispatch pointer family. Slot 0 -> "
            "FFX_Magic_RunPhase2_structural. Read together with 0x00C48D9C. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00C490DC,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[proved] Contiguous handler-family table rooted at sub_813B10. Neighbor slots include "
            "sub_81B670, sub_816750, sub_803B20, sub_8019D0, sub_819590, sub_817FA0, sub_81BCD0, "
            "and sub_80A0F0. Structural dispatch-family evidence, not per-magic timing. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00C49000,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[proved] Pointer block for one runtime handler family with packet/build-flavored members "
            "(sub_80F370, sub_8175B0, sub_81C370, sub_814680, sub_8172E0, sub_814960, sub_80AE00, "
            "sub_815F60, sub_8173B0). Structural dispatch-family evidence only. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00C48EC0,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[proved] Pointer block for a separate runtime handler family centered on owner-context/apply "
            "and cleanup helpers (sub_80ECB0, sub_80C540, sub_7FD640, sub_8169F0, sub_8158B0, "
            "unknown_libname_741_w_3, sub_817830, sub_80C650). Structural dispatch-family evidence only. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00C48FF0,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[proved] Pointer block for a runtime stream/table neighborhood. Starts with sub_81BAC0 and "
            "sub_81C000, then continues into the neighboring data block. Structural dispatch-family "
            "evidence only. Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00C49084,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[proved] Pointer block for another runtime handler family (sub_81C600, sub_817C10, sub_818F00, "
            "sub_818090, sub_818430). Reads like a transform/selector neighborhood, not overlay-texture timing. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00C49128,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[proved] Pointer block for a runtime handler family containing sub_804BB0 (twice), sub_80CA90, "
            "sub_816A00, and sub_816F90. Structural dispatch-family evidence only. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00C48E78,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[structural] Auxiliary record-type dispatch table consumed by "
            "FFX_Magic_RunAuxRuntimeRootPass_structural through dword_C48E78[(u8)(record+187)]. "
            "Per-type semantics still open. Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x007FD680,
        "name": "FFX_Magic_BootstrapPrimaryRuntimeRoot_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] High bootstrap that materializes/seeds the first runtime root, directly reached from "
            "FFX_BattleEffect_LoadDatEtEffectBins. Structural reading; not final timing semantics."
        ),
    },
    {
        "ea": 0x007FD9A0,
        "name": "FFX_Magic_MaterializeRuntimeRoot_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Structural writer for FFX_Magic_RuntimeRootTable[a1]. Materializes the runtime root record."
        ),
    },
    {
        "ea": 0x00800530,
        "name": "FFX_Magic_RunPhase0_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Structural phase 0 wrapper over FFX_Magic_RuntimeRootTable[0]. Promotes root+88 -> root+84 "
            "when present, otherwise falls back to dword_2332E8C and arms the companion work pointer before "
            "calling sub_80CD60(0, 0). Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00800590,
        "name": "FFX_Magic_RunPhase1_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Structural phase 1 wrapper over FFX_Magic_RuntimeRootTable[0]. Runs pre-hooks "
            "(sub_7E4630, sub_7E4D90(-1), pending-queue handling), reapplies the root+88/dword_2332E8C fallback, "
            "then calls sub_80CD60(0,1) and sub_80BEA0(0). Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00800950,
        "name": "FFX_Magic_RunPhase2_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Structural phase 2 wrapper over FFX_Magic_RuntimeRootTable[0]. Reapplies the same "
            "root+88/dword_2332E8C fallback path, then calls sub_80CD60(0, 2). "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x0080CD60,
        "name": "FFX_Magic_RunRuntimeRootPhase_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Structural phase interpreter/pass over the runtime root table. Copies "
            "FFX_Magic_RuntimeRootTable[(u16)a1] into a work buffer, stores the phase selector, then picks the "
            "active phase table from root+16/root+20/root+24 via *(work+548)=*(work+784+4*phase). Records are "
            "then resolved from root+32 + (recordIndex << 8). This is a real runtime record interpreter, not a "
            "simple overlay-slot or texture-timing reader. Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x0080BEA0,
        "name": "FFX_Magic_RunAuxRuntimeRootPass_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Auxiliary runtime-root pass paired especially with phase 1. Uses root[7] as an additional "
            "table/selector surface, resolves records from root+32 + (index << 8), and dispatches by record+187 "
            "through dword_C48E78 or a host callback path when the record type is negative. "
            "Source: FFX_MAGIC_RUNTIME_ORDER_AND_TIMING_PASS_2026-06-05."
        ),
    },
    {
        "ea": 0x00817200,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[strong-structural] Table-driven handler (DATA XREF .data:00C48F4C). On the opcode-family "
            "0x1000 path, uses the root clone at a1+768 and writes rootClone[21] and rootClone[22] together "
            "(root+84/root+88), then calls a host callback through rootClone[20]+96. Best current candidate "
            "for the root+88 change observed after host +2864 / sub_80CD60. "
            "Source: FFX_MAGIC_ROOT88_WRITER_PASS11_2026-06-05."
        ),
    },
    {
        "ea": 0x00C48F4C,
        "name": None,
        "kind": "data",
        "repeatable_comment": (
            "[strong-structural] Dispatch-table slot to sub_817200, the current best root+88 writer "
            "candidate. The handler writes rootClone[21]/rootClone[22] (root+84/root+88) on the 0x1000 "
            "family path. Source: FFX_MAGIC_ROOT88_WRITER_PASS11_2026-06-05."
        ),
    },
    {
        "ea": 0x00813180,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[structural] Auxiliary path that repoints a2[21] (root+84) to v17+112 after copying "
            "record-derived data. Useful contrast: this path updates root+84 only, while sub_817200 writes "
            "root+84 and root+88 together. Source: FFX_MAGIC_ROOT88_WRITER_PASS11_2026-06-05."
        ),
    },
    {
        "ea": 0x00800090,
        "name": "FFX_Magic_ProcessPendingQueue_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Structural staging/pending-queue intermediary around phase 1. Not the root-table materializer."
        ),
    },
    {
        "ea": 0x00804400,
        "name": "FFX_Magic_BindResidentMotionForActiveInstance_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Motion/runtime helper above the interpreter root. Resets playback flags, binds MSEQ, and "
            "selects resident motion for the active instance."
        ),
    },
    {
        "ea": 0x00809780,
        "name": "FFX_Magic_ShapeActiveInstanceRuntimeSpace_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Spatial/runtime shaping helper for the active instance. Uses matrix/vector helpers and lands "
            "in deeper runtime transform paths."
        ),
    },
    {
        "ea": 0x00800AD0,
        "name": "FFX_Magic_ToggleInstancesMode0_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Mass toggle helper over active instances. Calls sub_82AAB0(instance, 0)."
        ),
    },
    {
        "ea": 0x00800B00,
        "name": "FFX_Magic_ToggleInstancesMode1_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Mass toggle helper over active instances. Calls sub_82AAB0(instance, 1)."
        ),
    },
    {
        "ea": 0x008001E0,
        "name": "FFX_Magic_GatedStateFanout_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] State-gated fan-out over candidate rows. Only forwards entries that pass state/byte checks."
        ),
    },
    {
        "ea": 0x009086D0,
        "name": "FFX_Magic_FilterRuntimeRgbaByFlags_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Rebuilds/filters RGBA through runtime flags in dword_18DED08."
        ),
    },
    {
        "ea": 0x00909E10,
        "name": "FFX_Magic_ClearRuntimeFlagMask_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Clears bits in the shared runtime flag word used by the live color/flag lane."
        ),
    },
    {
        "ea": 0x00909E20,
        "name": "FFX_Magic_SetRuntimeFlagMask_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Companion setter for the shared runtime flag word used by the live color/flag lane."
        ),
    },
    {
        "ea": 0x0090A040,
        "name": "FFX_Magic_ApplyRuntimeRgba_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Writes RGBA into runtime globals and, for most magicIds, normalizes RGB to floats and pushes "
            "them onward. Live color plumbing, not merely static metadata."
        ),
    },
    {
        "ea": 0x004D6D40,
        "name": "FFX_Phyre_WalkPParameterBufferMemberDescriptors",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Walks 16-byte PParameterBuffer member descriptors (offset at +8, name at +4, type tags at +2/+3). "
            "This is the key proof that field 172/0xAC is reflection/member metadata, not a hardcoded draw constant. "
            "Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03."
        ),
    },
    {
        "ea": 0x0067B980,
        "name": "FFX_Phyre_HashShaderParamName_Djb2",
        "kind": "func",
        "repeatable_comment": (
            "[proved] djb2-style hash used for shader parameter name resolution (TextureSampler, ShadowMapSampler, "
            "and sibling runtime param names). Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03."
        ),
    },
    {
        "ea": 0x0069BCC0,
        "name": "FFX_Phyre_SelectLitShaderFamilyByAssetPath",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Shader-family selector by asset path. Distinguishes PhyreDefaultLitShader (map lane) from "
            "PhyreChrLitShader (character lane). Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03."
        ),
    },
    {
        "ea": 0x0069FB10,
        "name": "FFX_Phyre_BindTextureSamplerByName",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Shader setup/bind path that resolves TextureSampler by name and binds the texture handle through "
            "the parameter descriptor. Strong proof that runtime bind is by named shader param, not by raw +0xAC offset. "
            "Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03."
        ),
    },
    {
        "ea": 0x0056CD50,
        "name": "FFX_Phyre_FindShaderParamDefinitionByName",
        "kind": "func",
        "repeatable_comment": (
            "[proved] strcmp-based lookup over PShaderParameterDefinition entries. Returns the named parameter descriptor "
            "used by the runtime bind path. Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03."
        ),
    },
    {
        "ea": 0x0066E680,
        "name": "FFX_Phyre_BindTextureHandleToShaderParam",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Texture bind helper used after the named parameter descriptor is resolved."
        ),
    },
    {
        "ea": 0x0056E770,
        "name": "FFX_Phyre_BindSamplerStateToShaderParam",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Sampler-state bind helper paired with the named shader-parameter lane."
        ),
    },
    {
        "ea": 0x00A182F0,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[proved] Deferred/shadow parameter bootstrap lane. Resolves depth/shadow params by name and binds sampler "
            "state for PointClampSampler and ShadowMapSampler; this is not a base/albedo TextureSampler bind lane. "
            "Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03 / 2026-06-05 addendum."
        ),
    },
    {
        "ea": 0x006A3240,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[proved] Name-driven texture/sampler bind lane with FrameBuffer/RealFrameBuffer special-casing. Resolves "
            "MaterialColour, TextureSampler, and TextureSamplerState by shader param name, then binds sampler state and "
            "texture handle; not a hardcoded +0xAC draw-path constant. Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03 / 2026-06-05 addendum."
        ),
    },
    {
        "ea": 0x006A3CA0,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[proved] Multi-param post-effect bind lane. Resolves TextureSampler, TextureSamplerState, TargetTexture, "
            "UvScaleBias, CCTexture, MaterialColour, doCameraFadeout, and cameraFadeoutFactor by name before binding "
            "texture/sampler handles. Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03 / 2026-06-05 addendum."
        ),
    },
    {
        "ea": 0x006A4BA0,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[proved] Texture bind lane that also resolves zCrct, zMatrix, and ScreenShift. This reads like a "
            "screen/video-style named-parameter path, not a separate normal-map or water-material bind lane. "
            "Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03 / 2026-06-05 addendum."
        ),
    },
    {
        "ea": 0x006A5B20,
        "name": None,
        "kind": "func",
        "repeatable_comment": (
            "[proved] YUV/video-style texture lane. Falls back between TextureSampler and TextureSamplerY/U/V plus "
            "TextureSamplerState/UvScaleBias; useful negative evidence against a map-material normal/water bind "
            "interpretation here. Source: FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03 / 2026-06-05 addendum."
        ),
    },
    {
        "ea": 0x00AE5CF0,
        "name": "FFX_Phyre_RegisterPParameterBufferDescriptor_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Registration/accessor path for the concrete Phyre PParameterBuffer descriptor (descriptor dword_CA5040). "
            "Structural reflection lane; not a draw-path helper."
        ),
    },
    {
        "ea": 0x00AE5DC0,
        "name": "FFX_Phyre_RegisterPParameterBufferBaseDescriptor_structural",
        "kind": "func",
        "repeatable_comment": (
            "[proved] Registration/accessor path for the Phyre PParameterBufferBase descriptor. "
            "Structural reflection lane; not a draw-path helper."
        ),
    },
    {
        "ea": 0x00CA5040,
        "name": "FFX_Phyre_PParameterBufferClassDescriptor",
        "kind": "data",
        "allowed_old_names": ["Size_68"],
        "repeatable_comment": (
            "[proved] Concrete PParameterBuffer class descriptor used by the Phyre reflection/serializer system. "
            "Field 172/0xAC lives in the member-descriptor lane around this type, not as a hardcoded draw constant."
        ),
    },
]


def is_default_name(name: str) -> bool:
    return (
        name.startswith("sub_")
        or name.startswith("nullsub_")
        or name.startswith("loc_")
        or name.startswith("off_")
        or name.startswith("dword_")
        or name.startswith("qword_")
        or name.startswith("byte_")
        or name.startswith("word_")
        or name.startswith("unk_")
    )


def apply_name(ea: int, desired_name: str, allowed_old_names=None):
    current_name = ida_name.get_name(ea) or ""
    if current_name == desired_name:
        return {"status": "already_named", "old_name": current_name, "new_name": desired_name}

    allowed_old_names = set(allowed_old_names or [])
    if current_name and not is_default_name(current_name) and current_name not in allowed_old_names:
        return {"status": "skipped_name_conflict", "old_name": current_name, "new_name": desired_name}

    ok = ida_name.set_name(ea, desired_name, ida_name.SN_NOWARN)
    return {
        "status": "renamed" if ok else "rename_failed",
        "old_name": current_name,
        "new_name": desired_name,
    }


def apply_repeatable_comment(ea: int, kind: str, text: str):
    if kind == "func":
        func = ida_funcs.get_func(ea)
        target_ea = func.start_ea if func else ea
        old = idc.get_func_cmt(target_ea, 1) or ""
        if old == text:
            return {"status": "comment_already_present"}
        ok = idc.set_func_cmt(target_ea, text, 1)
        return {"status": "comment_set" if ok else "comment_failed", "old_comment": old}

    old = idc.get_cmt(ea, 1) or ""
    if old == text:
        return {"status": "comment_already_present"}
    ok = idc.set_cmt(ea, text, 1)
    return {"status": "comment_set" if ok else "comment_failed", "old_comment": old}


def main():
    if os.environ.get("FFX_IDA_SKIP_AUTO_WAIT") != "1":
        ida_auto.auto_wait()

    report = {
        "database_path": idc.get_idb_path(),
        "applied": [],
        "skipped": [],
        "errors": [],
    }

    for item in ANNOTATIONS:
        ea = item["ea"]
        entry_report = {
            "ea": f"0x{ea:08X}",
            "kind": item["kind"],
            "requested_name": item.get("name"),
        }
        try:
            if item.get("name"):
                name_result = apply_name(ea, item["name"], item.get("allowed_old_names"))
                entry_report["name_result"] = name_result

            if item.get("repeatable_comment"):
                comment_result = apply_repeatable_comment(ea, item["kind"], item["repeatable_comment"])
                entry_report["comment_result"] = comment_result

            report["applied"].append(entry_report)
        except Exception as exc:
            entry_report["error"] = str(exc)
            report["errors"].append(entry_report)

    REPORT_PATH.parent.mkdir(parents=True, exist_ok=True)
    REPORT_PATH.write_text(json.dumps(report, indent=2, ensure_ascii=False), encoding="utf-8")

    save_error = None
    try:
        idc.save_database(idc.get_idb_path(), 0)
    except Exception as exc:
        save_error = str(exc)

    ida_kernwin.msg(f"[apply_ffx_discovery_annotations] wrote {REPORT_PATH}\n")
    if save_error:
        ida_kernwin.msg(f"[apply_ffx_discovery_annotations] save_database warning: {save_error}\n")

    idc.qexit(0 if not report["errors"] else 2)


if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        ida_kernwin.msg(f"[apply_ffx_discovery_annotations] fatal error: {exc}\n")
        try:
            REPORT_PATH.parent.mkdir(parents=True, exist_ok=True)
            REPORT_PATH.write_text(json.dumps({"fatal_error": str(exc)}, indent=2, ensure_ascii=False), encoding="utf-8")
        except Exception:
            pass
        idc.qexit(1)
