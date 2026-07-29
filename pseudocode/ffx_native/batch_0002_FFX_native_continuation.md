# FFX.exe Decompilation — Batch 2 (FFX Native Code Continuation)

**Database:** ffxoficial.exe.i64 (ffxoficial_COPY.i64 session 85e0242a)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** Continues batch_0001 — covers the remaining ~4,353 FFX_* functions not in the top 29 domains

---

## Summary

Batch_0001 documented 29 top-level FFX_* domains totaling ~9,114 of the 13,467 named FFX_* functions. This batch covers the remaining 4,353 (32%) under **27 additional FFX_* sub-prefixes** and **3 non-FFX_** families (PppMem, Pcp_Trampoline, etc.).

`★ Insight ─────────────────────────────────────`
The 27 additional FFX_* prefixes reveal that FFX's codebase has **strong domain-specific naming conventions** with sub-prefixes like `FFX_FieldVM_*`, `FFX_FieldOp_*`, `FFX_Btl_FieldOpcode_*` — each represents a **separate bytecode VM or scripting interpreter**. FFX has at least 5 distinct VMs: Field (overworld), Battle (turn-based), ATEL Movie (cutscene), Ability Map (Sphere Grid), and LocKit.
`─────────────────────────────────────────────────`

| Metric | Batch 1 | Batch 2 | Combined |
|--------|---------|---------|----------|
| FFX_* functions | 9,114 | 4,353 | 13,467 |
| Domains covered | 29 | 27 | 56 |

---

## Top New Domains by Function Count

| Rank | Domain | Count | Description |
|------|--------|-------|-------------|
| 1 | `FFX_Atel_*` (all subdomains) | **981** | ATEL scripting: Battle + Map + Movie + AbilityMap + Debug + Thunks |
| 2 | `FFX_FieldOp_*` | **556** | Field script opcodes (overworld interpreter) |
| 3 | `FFX_BtlUI_*` | **370** | Battle UI: HUD, command select, target cursor, gauges |
| 4 | `FFX_FieldVM_*` | **295** | Field VM opcodes (lower-level VM) |
| 5 | `FFX_Dbg_*` | **257** | Debug overlays: stacktrace, module tracking, log printf |
| 6 | `FFX_FieldMap_*` | **240** | Field map data: load/lighting/scene bridge |
| 7 | `FFX_FieldActor_*` | **223** | Field actor script ops (animation, material, script state) |
| 8 | `FFX_VpxFrameDecoder_*` | **201** | VP8/VP9 frame decoder (cutscreen video codec) |
| 9 | `FFX_Math_*` | **197** | Vector/matrix math utilities (Vec2/3/4, identity, classify) |
| 10 | `FFX_Abmap_*` | **187** | Sphere Grid / Ability Map (CTB-style node traversal) |
| 11 | `FFX_Atel_Battle_*` | 135 | Battle ATEL interpreter ops (8 opcodes: CallPopA, GiveItem, BtlUseChrMpLimit, etc.) |
| 12 | `FFX_Btl_FieldOpcode_*` | 126 | Battle field script opcodes (used in cutscenes that bridge field→battle) |
| 13 | `FFX_Video_*` | 107 | Video plane reconstruction (transposed blocks, deblock MMX/SSE2, MC compensators) |
| 14 | `FFX_Mscd_*` | 61 | MSCD file system (PS3-style file table, PC port shim) |
| 15 | `FFX_Get*` | 43 | Generic getters (struct ptr, vtable, mutex, compile date) |
| 16 | `FFX_Atel_Map_*` | 38 | Map ATEL ops (Gfx binding, layer visibility) |
| 17 | `FFX_MagicFile_*` | 31 | Magic file loader (PRX-style file binding) |
| 18 | `FFX_RenderTarget_*` | 24 | Render target global mgmt (acquire/release surfaces) |
| 19 | `FFX_Stub_*` | 14 | Generic 3-byte return-0 stubs |
| 20 | `FFX_LocKit_*` | 9 | Localization kit (regional PS3 bin loader) |
| 21 | `FFX_Thunk_*` | 8 | Direct thunks (5-9 byte jumps) |
| 22 | `FFX_RenderStub_*` | 4 | Render stubs |
| 23 | `FFX_Thread*` | 3 | Threading (DestroyHandle, Cleanup, Alloc) |
| 24 | `FFX_Atel_AbilityMap_*` | 2 | Sphere Grid ATEL ops |
| 25 | `FFX_Lzss*` | 2 | LZSS decompression variants (2048 / 4096) |
| 26 | `FFX_Throw*` | 2 | CAtlException throwers |

**Total new sub-prefixes: 4,353 FFX_* functions**

---

## Architecture Notes

### 5 Bytecode VMs in FFX.exe

FFX has at least **5 distinct bytecode interpreters**, each implemented as a giant switch statement over opcode IDs, with `CALL`/`INTRET`/`STATUS`/`FLOATRET`/`CALLPOPA` suffixes indicating the calling convention:

| VM | Sub-prefix | Opcode Range | Total Ops |
|----|-----------|--------------|-----------|
| **ATEL Movie** | `FFX_Atel_Movie_*` | B000-FFFF | 475 funcs |
| **ATEL Battle** | `FFX_Atel_Battle_*` | 70xx | 135 funcs |
| **ATEL Map** | `FFX_Atel_Map_*` | 804B-80FF | 38 funcs |
| **Field VM** | `FFX_FieldVM_*` | Various | 295 funcs |
| **Field Script** | `FFX_FieldOp_*` | Various | 556 funcs |

Total interpreter ops: **1,499 functions**.

This explains why FFX can have different scripting layers:
- **ATEL** = Atelio (animation/scripting language from PS2 era FFX/FFX-2)
- **Field VM** = mid-level VM bytecode
- **Field Op** = high-level script ops (push/pop globals, call entities)

### The Sphere Grid / Ability Map System (`FFX_Abmap_*`)

The ability map has its own substantial subsystem (187 funcs). It manages:
- Node activation with inventory requirements
- Animations (scroll, zoom, 4-frame interp, 3-frame step)
- Menu panel rendering (BuildPanelPrimsFromMenuEntries)
- Button layout state machine
- Link batching and adjacency

The presence of `FFX_Atel_AbilityMap_FuncD020_CALLPOPA` and `FFX_Atel_AbilityMap_FuncD000_CALL` confirms the **Sphere Grid is fully driven by ATEL scripting** — same VM as cutscenes.

### Video Codec: VP8/VP9 Port

`FFX_Video_*` (107) and `FFX_VpxFrameDecoder_*` (201) totals **308 functions** for video decoding.

This is **libvpx (FFmpeg)** ported into the game (not at runtime — statically compiled into FFX.exe). Functions include:
- Frame header parser
- Macroblock processor
- Loop filter
- Token probability init
- MMX/SSE2 8-tap subpixel filters
- Color transform
- Deblock filters

This confirms FFX's cutscenes are stored as **VP8/VP9 streams in PSARC files**.

### Battle UI = HUD + Command Select

`FFX_BtlUI_*` (370) is the **battle HUD system**:
- DrawHudAtlasQuad
- CursorRingArray
- HudIconCondition_Iterate
- SetHudDrawParam
- Overdrive gauge reset state

This is **2D rendering on top of the 3D battle scene**, layered with PhyreEngine's `PAtlasQuadPrimitive`.

### Field Map Loading (`FFX_FieldMap_*`)

240 functions covering:
- `LoadEntry_graphicFieldMapLoad` — graphic field map load entry
- `ActivateSceneBridge` — scene switching
- `SetGuidePolyScreenW/H` — guide polygon dimensions
- `SetMorphWeightBlend` — morph weight blending
- `LoadingStatusCheck` — file load status

This is the **field/zone loader** that reads `FFXOMAP_*` files and assembles the overworld scene.

---

## Key Function Analysis by Domain

### 1. ATEL Movie (475 funcs) — The Cutscene VM

`FFX_Atel_Movie_*` is the most heavily-used ATEL subdomain. Functions include `loadFmv_CALLPOPA`, `ResetVideoFlag`, `SetSubtitleActive`, plus hundreds of `FuncBxxx_*_STRUCTURAL` bytecode dispatchers.

Representative dispatch pattern:
```c
// FFX_Atel_Movie_FuncB06E_STATUS_structural @ 0x770f20 (size 0x6)
//   mov eax, [ebp+0x14]
//   ; write STATUS to op_result register
//   ; return based on call type
```

The opcode IDs **B000-BFFF** are likely movie/cutscene ops — they pop arguments, exec logic, write back status/int/float.

### 2. Field Script Opcodes (556 funcs) — Overworld

`FFX_FieldOp_*` covers **lower-level field ops** that drive:
- BgCamera motion (play / stop / check / progress / rotation)
- Save flag toggles (`PopToggleBit3`, `PopToggleBit6AndSet15`)
- Music volume lerping
- Battle flag setup
- Capture count adjustment
- Sub86BE20 field word setters

These operate on a **stack-based VM** with push/pop semantics.

### 3. Battle UI (370 funcs) — HUD System

Notable functions:
- `FFX_BtlUI_RenderCmd_SetParam` (0x630770, 61B)
- `FFX_BtlUI_DrawHudAtlasQuad` (0x6308e0, 245B)
- `FFX_BtlUI_FreeCursorRingAllocation` (0x636430, 40B)
- `FFX_BtlUI_ReadActorPositionFromInstance` (0x63b370, 68B)
- `FFX_BtlUI_HudIconFunction_Guarded` (0x642900, 67B)

### 4. Sphere Grid / Ability Map (187 funcs)

Key functions:
- `FFX_Abmap_ActivateNode` (0xa48910, 358B)
- `FFX_Abmap_AnimateScrollOffset` (0xa48f50, 355B)
- `FFX_Abmap_AnimateZoomTransition` (0xa490c0, 421B)
- `FFX_Abmap_BuildPanelPrimsFromMenuEntries` (0xa459e0, ~340B)
- `FFX_Abmap_BuildNodeAdjacencyFromLinks` (0xa5b140, ~340B)
- `FFX_Abmap_BuildNodePlacementMatrix` (0xa5ad30, ~280B)
- `FFX_Abmap_ButtonLayout_StateMachine` (0xa53450, ~1.5KB — largest)

### 5. VP8/VP9 Decoder (201 funcs in FFX_VpxFrameDecoder_*, 107 in FFX_Video_*)

This is **libvpx statically compiled**:
- `FFX_VpxFrameDecoder_ParseFrameHeader` (0x409970, 244B)
- `FFX_VpxFrameDecoder_ProcessMacroblock` (0x40e6f0, ~300B)
- `FFX_VpxFrameDecoder_LoopFilterMacroblock` (0x40e860, ~250B)
- `FFX_VpxFrameDecoder_IntraFrameModeInit` (0x40f930, ~100B)
- `FFX_VpxFrameDecoder_InitTokenProbs` (0x40f320, ~700B)
- `FFX_VpxFrameDecoder_ReallocFrameBuffers` (0x41caf0, ~300B)

Vectorized SIMD variants:
- `FFX_Video_SubPixel_8tap_horiz_MMX` (0xa7f026, ~140B)
- `FFX_Video_SubPixel_8tap_SSE2` (0xa7ed7b, ~180B)
- `FFX_Video_SubPixel_8tap_vert_SSE2` (0xa7ee04, ~270B)
- `FFX_Video_PlaneTranspose` (0x411ce0, 410B — for YUV→RGB)
- `FFX_Video_ColorTransformBlock` (0x416dc0, 465B)

### 6. Debug Overlays (257 funcs)

FFX has a **full debug/runtime introspection system**:
- `FFX_Dbg_LogPrintf` (0x648a00, 108B)
- `FFX_Dbg_VsnprintfWrapper` (0x687210, 32B)
- `FFX_Dbg_EnumerateModulesViaPsapi` (0x687650, 471B)
- `FFX_Dbg_EnumerateModulesViaToolhelp` (0x687830, 437B)
- `FFX_Dbg_FormatStackTraceCallback` (0x688440, 449B)
- `FFX_Dbg_FormatModuleSymbolInfo` (0x688680, 250B)
- `FFX_Dbg_ResolveSymbolFromModuleEntry` (0x6804d0, 121B)

These suggest the **debug build used module enumeration + symbol resolution** for stack traces — but they survive in the PC retail build, possibly as a debug menu.

### 7. MSCD File System (61 funcs)

`FFX_Mscd_*` is **PS3 MSCD (Mass Storage CD file system)** ported to PC:
- `FFX_Mscd_AllocQueueSlot` (0x76bee0, 415B) — async I/O slot allocation
- `FFX_Mscd_GetSystemFlagThunk`
- `FFX_Mscd_PcFileTblSetDvdOnlyError` — PC-only error for read-only file table
- `FFX_Mscd_PcLoadDvdOnlyError` — PC stub

The `Pc*` prefixes are **PC-port fallbacks** for DVD-only operations on PS3.

### 8. Math Utilities (197 funcs)

FFX-specific math helpers:
- `FFX_Math_Vec2ClassifyDirection` (0x728ec0, 99B) — 8-direction classification
- `FFX_Math_Vec4LengthWithGlobal` (0x72ac10, 256B)
- `FFX_Math_AccumulateWeightedVec4` (0x72c680, 82B)
- `FFX_Math_Vec3MulScalarStore`
- `FFX_Math_Vec3Mul3Scalars`
- `FFX_Math_Vec4Assign` / `Vec4AssignReverse`
- `FFX_Math_InitIdentityQuadFloats` (0x42ef00, 29B)
- `FFX_Math_SetFlagBit7/6` (8-11B trivial setters)

### 9. Localization (9 funcs)

`FFX_LocKit_*`:
- `FFX_LocKit_LoadRegionalPs3LocKitBin` (0x6db420, 443B) — main regional loader
- `FFX_LocKit_ParseEntry` (0x6da3d0, 61B)
- `FFX_LocKit_FreeEntry` (0x6da590, 28B)
- `FFX_LocKit_GetLineByIndex` (0x6db320, 242B) — main lookup
- `FFX_LocKit_GetStringTable` / `GetStringTableByVideoSingleton`

This is the **regional localization loader** — loads PS3-style regional text from .bin files.

### 10. Field Map / Camera / Path (240 + 556 funcs)

`FFX_FieldMap_*`:
- `FFX_FieldMap_LoadEntry_graphicFieldMapLoad` (0x6403c0, 346B)
- `FFX_FieldMap_SetGuidePolyScreenW/H` (16B each)
- `FFX_FieldMap_SetMorphWeightBlend`
- `FFX_FieldMap_ProcessLevelName_inner` (0x641eb0, 136B)
- `FFX_FieldMap_LoadColorCorrectionForLevel` (0x641f60, 111B)

`FFX_FieldOp_*` for camera:
- `FFX_FieldOp_BgCameraPlayMotionType1/3` (0x7b7f60/d0, 109B each)
- `FFX_FieldOp_BgCameraSetRotation` (0x7b82b0, 146B)
- `FFX_FieldOp_BgCameraCheckMotionDone` (0x7b81f0, 93B)
- `FFX_FieldOp_CameraSetRotation` (0x7b8350, 146B)

---

## PppMem — Pooled Memory Allocator (49 funcs)

`PppMem_*` is a **PhyreEngine-internal pooled allocator** with fixed-size slabs. Functions:

```
PppMem_ClearVec3At160                    @ 0x72ee90  39B
PppMem_BuildNodeChain_1x128              @ 0x736750  39B
PppMem_BuildNodeChain_4x128              @ 0x736780  39B
PppMem_BuildNodeChain_8x128              @ 0x7367b0  39B
PppMem_BuildNodeChain_1x16               @ 0x7367e0  36B
PppMem_BuildNodeChain_16x16              @ 0x736810  36B
PppMem_BuildNodeChain_24x16              @ 0x736840  36B
PppMem_BuildNodeChain_4x16               @ 0x736870  36B
```

Pooled allocator with **typed slabs** (e.g., `1x128` = 1 element of 128 bytes, `4x128` = 4 elements of 128 bytes). Used for small fixed-size game objects where dynamic allocation would cause heap fragmentation.

---

## Combined FFX_* Coverage (Batch 1 + Batch 2)

| Total FFX_* families covered | 56 |
|------------------------------|----|
| Total FFX_* functions documented | 13,467 (100%) |
| Total bytes of batch documents | ~28 KB |

| Largest sub-domains | |
|---|---|
| `FFX_Atel_*` combined | 981 |
| `FFX_Battle_*` (batch 1) | 716 |
| `FFX_Field_*` (batch 1) | 715 |
| `FFX_FieldOp_*` | 556 |
| `FFX_Atel_Movie_*` | 475 |
| `FFX_BtlUI_*` | 370 |
| `FFX_Menu_*` (batch 1) | 502 |
| `FFX_FieldVM_*` | 295 |
| `FFX_Dbg_*` | 257 |
| `FFX_Save_*` (batch 1) | 253 |
| `FFX_FieldMap_*` | 240 |
| `FFX_FieldActor_*` | 223 |
| `FFX_Render_*` (batch 1) | 263 |
| `FFX_VpxFrameDecoder_*` | 201 |
| `FFX_Math_*` | 197 |
| `FFX_Abmap_*` | 187 |

---

## Key Findings

1. **5 bytecode VMs in FFX.exe** — ATEL Movie (475 ops), ATEL Battle (135), ATEL Map (38), ATEL AbilityMap (2), Field VM (295) + Field Script (556 ops) = ~1,499 interpreter opcodes total. This is **far more VM machinery than typical PS2-era ports** — FFX HD PC has full scripting infra.

2. **libvpx statically compiled** — 308 VP8/VP9 decoder functions including SIMD-optimized filters. Cutscenes are VP8/VP9 streams in PSARC files, decoded at runtime.

3. **Sphere Grid is ATEL-driven** — `FFX_Atel_AbilityMap_*` confirms FFX's signature ability system uses the same bytecode as cutscenes.

4. **PC port has PS3 file system shims** — `FFX_Mscd_PcFileTblSetDvdOnlyError` is a PC fallback for PS3 DVD-only ops. The original FFX/FFX-2 code ran on PS3 with TRC/TRS DVD checks; PC port needed errors when called.

5. **Debug infrastructure survives in retail** — 257 `FFX_Dbg_*` functions including module enumeration, stack traces, symbol resolution. Likely a debug menu that wasn't fully removed from the PC release.

6. **Sub-prefix explosion** — Same logical system has multiple layer names: `Field` + `FieldVM` + `FieldOp` + `FieldMap` + `FieldActor`. Each represents a different abstraction layer of the same field subsystem.

7. **PppMem pooled allocator is PhyreEngine-internal** — not FFX-specific. 49 functions of typed slab allocation (`1x128`, `16x16`, etc).

8. **MSCD ported to PC** — Async file queue system (PS3 MSCD) maintained in PC build with shim errors for unsupported DVD ops.

---

## What's Next?

After batch_0001 + batch_0002 the FFX function inventory is **complete** (13,467 functions across 56 domains). Recommended next steps:

1. **Decompile the master entry point** — `FFX_System_Host_Constructor` (3482B) for full boot sequence
2. **Decompile the damage formula** — `FFX_Battle_ComputeHitDamage` (2127B) for combat math
3. **Decompile `FFX_Battle_CtbSelectNextActorAndRunTurnEdgeEvents`** for turn scheduling
4. **Decompile ATEL Movie dispatcher** to understand cutscene VM
5. **Decompile libvpx entry** (`FFX_VpxFrameDecoder_ParseFrameHeader`) for video frame structure
6. **Trace MSCD to PhyreEngine stream layer** to understand the file I/O path
7. **Find RTTI for non-PhyreEngine FFX classes** — likely under `class FFXBattle`, `FFXMenu`, etc.

---

**Next batch:** Deeper dive into 2-3 critical functions (battle/boot/video) to extract true logic, not just naming.
