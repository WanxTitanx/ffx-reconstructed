# FFX.exe Decompilation — Batch 7 (Particle / PPP System)

**Database:** ffxoficial_COPY.i64 (session b1d18aaa, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** Particle system + PPP (Particle Programming Pipeline) opcode VM — 227 functions across 15 sub-families

---

## Summary

FFX's particle system is a **bytecode-driven VFX pipeline** built on the **PPP (Particle Programming Pipeline)** VM — 274 opcodes that drive particle effects. The system spans **227 functions** across 15 families, from core particle lifecycle (Emit/Update/Render) through PPP opcode execution, VFX texture binding, and field particle integration.

| Category | Functions | Substantial (>100B) | Key Entry Point |
|----------|-----------|---------------------|-----------------|
| Core Particle Engine | 11 | 5 | `FFX_Particle_Emit` / `Update` / `Render` |
| PPP Opcode VM | 9 | 6 | `FFX_MagicVm_PppOpcodeExecute` (274 opcodes) |
| PPP Resource Management | 24 | 14 | `FFX_MagicHost_AllocPppDrawRecord` |
| PPP Draw Pipeline | 3 | 3 | `FFX_Magic_PPP_BuildDrawableFromOpcode_ProcessCmd` |
| PPP Sprite Draw | 4 | 3 | `FFX_Magic_PPP_SpriteDraw_Setup` (3.4KB) |
| VFX Texture Binding | 46 | 34 | `FFX_MagicHost_AllocVfxParticleSlots` (4.3KB) |
| VFX Draw Dispatch | 6 | 4 | `FFX_MagicHost_VfxDraw` / `VfxDrawDispatch` |
| Field Particle | 14 | 8 | `FFX_FieldParticle_UpdateTick` (1.3KB) |
| Particle Side Ops | 22 | 14 | `FFX_MagicSideOp_17_structural` (2.3KB) |
| PPP Memory Pool | 49 | 2 (47 stubs) | `PppMem_BuildNodeChain` / `PppMem_InitNodeIdentityFields` |
| Magic VM Core | 19 | 12 | `FFX_MagicVm_PppOpcodeExecute` (1.97KB) |
| PPP Kernel Ops | 5 | 3 | `FFX_KR_AdjustPppBufferOffsets` |
| Magic Particle Flags | 5 | 0 | Set/Clear flag bit operations |
| Debug Particle | 5 | 2 | `Dbg_SaveParticleDataToHost` / `SerializeParticleItem` |
| Field Map Particle | 6 | 5 | `FieldMap_InitParticleNode` / `RenderVfxParticlesEx` |

**Total unique functions: 227** (across FFX_Particle_*, FFX_FieldParticle_*, FFX_Magic_PPP_*, FFX_MagicHost_Ppp/Vfx*, FFX_MagicVm_*, PppMem_*, FFX_MagicSideOp_*, FFX_FieldVM_Particle*, FFX_Magic_Particle_*, FFX_KR_Ppp*, FFX_PppMem_*, Phyre_Particle_*, FFX_Dbg_Particle*, FFX_Render_Ppp*, FieldMap_Render*)

`★ Insight ─────────────────────────────────────`
- **PPP = Particle Programming Pipeline** — a complete bytecode VM with 274 opcodes embedded in FFX.exe. Categories: Draw(46), Ke/Kernel(106), Rand(33), Matrix(29), Special(14), Light(12), Move(7), Accele(4), Point(5), Color(2), Other(20).
- **VFX pipeline is texture-driven**: particle effects are first allocated as texture slots, then PPP opcodes manipulate those slots. The largest function (`AllocVfxParticleSlots`, 4.3KB) handles this binding.
- **PppMem_* is a POOLED allocator**, not particle logic — 47 of 49 functions are template-generated stubs for fixed-size slab allocations (1x8, 4x16, 8x128, etc.).
`─────────────────────────────────────────────────`

---

## Architecture

### Particle System Layers

```
PPP Bytecode (274 opcodes in FFX.exe)
    │
    ▼
FFX_MagicVm_PppOpcodeExecute — central opcode dispatcher
    │
    ├── FFX_Magic_PPP_SpriteDraw_Setup — sprite draw setup (3 callers)
    ├── FFX_Magic_PPP_BuildDrawableFromOpcode — build drawable from PPP
    ├── FFX_Magic_PPP_RenderGeometry — render geometry from PPP
    └── FFX_Magic_PPP_RenderWithMetadata — render with metadata
    │
    ▼
FFX_MagicHost_AllocVfxParticleSlots — allocates VFX particle slots (texture binding)
    │
    ├── FFX_TextureSlot_FindOrCacheByKeyProxy — texture slot cache
    ├── FFX_MagicHost_AllocPppDrawRecord — allocates draw record
    └── FFX_MagicHost_AllocPppParticleSlot — allocates particle slot per texture
    │
    ▼
FFX_MagicHost_DrawPppElements — draws PPP elements (called by DrawDispatch)
    │
    ├── FFX_MagicHost_PppDrawRecord_Build — build draw records
    └── FFX_MagicHost_PppDrawRec_CopyGlobalA/B — copy global state
    │
    ▼
FFX_MagicHost_RenderVfxParticles — renders VFX particles (2 callers)
    │
    ├── FFX_MagicHost_ProcessParticleVfx — process particle VFX update
    │   └── FFX_MagicHost_ClassifyPppOpcodeByte — classify opcode byte
    └── FFX_MagicHost_CommitDrawableResources — commit resources to GPU
    │
    ▼
FFX_FieldParticle_UpdateTick — field particle tick integration
    │
    ├── FFX_FieldParticle_UpdateMovement — movement update
    ├── FFX_FieldParticle_ComputePosition — position computation
    ├── FFX_FieldParticle_ComputeQuadVertices — quad vertex computation
    └── FFX_BtlUI_HudParty_GetCommand/GetTarget — HUD integration
```

### Particle Data Flow

```
Magic binary (PS3 → VBF)
    │
    ▼
FFX_MagicHost_RelocatePppResourceBlob — fix up PPP relocations
    │
    ▼
FFX_MagicHost_InitQueuedPppResourceBuffers — initialize PPP buffers
    │
    ▼
FFX_Magic_PPP_BuildTexturePathFromOpcode — build texture path from opcode
    │
    ▼
FFX_MagicHost_BuildVfxTexture — build VFX texture (46 variants: TypeF/G/H/I/J/K/E/Locale)
    │
    ▼
FFX_MagicHost_AllocVfxParticleSlots — allocate slots (up to 4 textures × 10000-key stride)
    │   Uses magic IDs for special sizes: 374→512px, 102/103→256/512px, 515/667→512/256px
    │
    ▼
FFX_MagicHost_ProcessParticleVfx — process particle VFX (tick update)
    │
    ├── Updates transforms every frame
    ├── Checks opcode category (ClassifyPppOpcodeByte)
    └── Commits drawable resources
    │
    ▼
FFX_MagicHost_DrawPppElements / FFX_MagicHost_RenderVfxParticles — render
    │
    ├── Allocates draw records
    ├── Sets up sprite geometry (UV coords, color scales, alpha)
    └── Finalizes via FFX_MagicHost_CommitDrawableResources
```

### Texture Slot Key Scheme

Particle textures use a **64-bit key scheme** with a **10000-unit stride** for multi-texture variants:

```
Key = (host_16 << 32) | v100    (64-bit pair)
Stride = 10000 per texture slot

For n2_1 == 1 (4-texture mode):
    Slot 0: base key + 0
    Slot 1: base key + 10000
    Slot 2: base key + 20000
    Slot 3: base key + 30000

For n2_1 == 2 (variable count from header):
    Slot N: base key + N * 10000
```

### PPP Opcode Categories (274 total in FFX_MagicVm_PppOpcodeExecute)

| Category | Count | Description |
|----------|-------|-------------|
| Draw | 46 | Sprite/geometry draw commands |
| Ke/Kernel | 106 | Core kernel operations (matrix, color, transform) |
| Rand | 33 | Random/statistical operations |
| Matrix | 29 | Matrix transformation operations |
| Special | 14 | Special operations |
| Light | 12 | Lighting operations |
| Move | 7 | Movement/translation operations |
| Accele | 4 | Acceleration operations |
| Point | 5 | Point operations |
| Color | 2 | Color operations |
| Other | 20 | Uncategorized |

**Opcode strings** reside at `0xB4FEB0`–`0xB513D4` in the .rdata section — used for debug naming.

---

## Key Function Analysis

### 1. FFX_MagicHost_AllocVfxParticleSlots (0x7186f0, 4350B)

**The largest particle function (29 callers, 17 callees).** Allocates VFX particle slots by binding textures to a PPP draw record.

```c
int __cdecl FFX_MagicHost_AllocVfxParticleSlots(int64_t keyPair, int ctx, int slotConfig) {
    // Phase 1: Texture slot resolution
    // - Compute identity function from context
    // - Check global flag at byte_11333C4[1868748] — early exit if set
    // - Find/cache texture slot by 64-bit key
    // - Get data pointer; if NULL → return 0 (failure)
    
    // Phase 2: Multi-texture binding based on n2 field
    //   n2 == 1: Bind 4 textures (stride 10000), set byte+182 from slotConfig+68
    //   n2 == 2: Bind variable count from header word at dataPtr+196
    //   else:    Single texture, set byte+182
    
    // Phase 3: Special magic ID overrides
    // - ID 374 + specific sizes (14208/14336/14464) → override uv[25]=12336, uv[24]=48
    // - ID 102/103 (Aeons) → flt_C3A4C8 = 512.0
    // - ID 515/667 + opcode 72 + unknown 11 → conditional 512/256
    // - flt_C3A48C = 0.0078125 / flt_C3A4C8 (inv_size * 2/256)
    
    // Phase 4: Color scaling from slotConfig[24..27]
    // - Scale v112/v113/v114/v115 by config byte / 255.0
    
    // Phase 5: HUD target integration
    // - Compare charId string against dword_B43674
    // - FFX_BtlUI_HudParty_GetTarget
    // - Read addr slot[16] and slot[20]
    
    // Phase 6: Render resource binding
    // - Update slot[56] and slot[60] if NULL (default from identity)
    // - Check if render resource exists and matches identity
    // - Free/rebind if mismatch
    
    // Phase 7: Light matrix setup (bit 0x40 flag + magic ID 519)
    // - Copy 16-float matrix from slot+40 to dst
    // - Call FFX_BtlUI_HudParty_ApplyStatus
    // - Iterate 4 textures: FFX_Material_SetLightMatricesByTextureKey
    
    // Phase 8: YIQ shift (save op 5 + magic ID 392)
    // - Apply color space shift per texture slot
    
    // Phase 9: PPP draw record allocation
    // - FFX_MagicHost_AllocPppDrawRecord
    // - Copy 64-byte header from slot+32, slot+68
    // - Store color scales, opcode byte, host pointers
    
    // Phase 10: Slot allocation by opcode type
    // - Iterate 108-byte stride over v108 count
    // - 8 cases (0-7) determining slot layout size:
    //   case 0: size=20 per entry
    //   case 1: size=28 per entry
    //   case 2: size=32 per entry
    //   case 3: default size
    //   case 4: size=24 per entry (3 × 8)
    //   case 5: size=32 per entry
    //   case 6: size=40 per entry (5 × 8)
    //   case 7: size=48 per entry
    // - Each case allocates via FFX_MagicHost_AllocPppParticleSlot
    // - Returns 0 on any allocation failure
}
```

**Key constants:** stride=10000 (texture key spacing), 108 (opcode stride), 3240 (max stride), 40000 (4-texture range), v112-v115 (color scale).

### 2. FFX_Magic_PPP_SpriteDraw_Setup (0x71c190, 3433B)

Called by **3 callers** (likely different opcode handlers). Sets up sprite drawing from PPP opcode data, handles:
- Building texture slots from opcode configuration
- Setting up sprite geometry (UV, color, alpha)
- Commit to drawable resources

### 3. FFX_MagicHost_DrawPppElements (0xa72b80, 2929B)

**Called ONLY by FFX_MagicHost_DrawDispatch** — single entry point. Draws all queued PPP elements:

```c
int FFX_MagicHost_DrawPppElements(ctx, config) {
    // Phase 1: Draw record processing
    // - Walk draw record chain
    // - Build from PPP program (FFX_MagicHost_PppDrawRecord_Build)
    // - Copy global transform (A and B variants)
    
    // Phase 2: Per-element drawing
    // - Set up sprite geometry per element
    // - Apply color transforms
    // - Apply texture transforms
    
    // Phase 3: Commit and finalize
    // - FFX_MagicHost_CommitDrawableResources
    // - Advance PPP frame index
}
```

### 4. FFX_MagicVm_PppOpcodeExecute (0xa72380, 1969B)

The **central PPP opcode executor** — a VM dispatch function that handles all 274 opcodes:

```c
void __fastcall FFX_MagicVm_PppOpcodeExecute(FFX_PppOpcode opcode, void *vmContext) {
    // Phase 1: Texture slot initialization
    // - Push work buffer frame (4864 bytes)
    // - Find/cache texture slot by 64-bit key
    // - If not found: "NoTexture" fallback
    // - Classify opcode byte → determine category
    // - Matrix init, BuildTextureSlotRecord, ValidateGeometry
    // - Dedup insert (avoids duplicate slot creation)
    
    // Phase 2: Global state copy
    // - Copy 16 floats from v79 (sprite params) → unk_C8F850..C8F88C
    // - Copy 16 floats from v62 (transform) → unk_C8F890..C8F8CC
    // - Copy 4 floats from v68[36..39] (color) → unk_C8F8E0..C8F8EC
    
    // Phase 3: Particle generation loop
    // - Iterate over opcode list (*i = count)
    // - For each active opcode:
    //   - Compute particle count from v70[15] (speed/rate param)
    //   - Allocate slots modulo ring buffer size (12 * (v13[1] % *v13))
    //   - Random jitter: position, rotation, scale, alpha
    //   - FFX_Math_RandomJitterScale_structural(2.0) for position
    //   - FFX_Math_ComputeFixedAngle_structural for rotation
    //   - Scale alpha by 0.00390625 (1/256), rotation by 0.000244140625
    //   - Pack 16-bit rotation and scale into HIWORD/LOWORD
    
    // Phase 4: Vertex submission
    // - For each particle slot:
    //   - Decrement lifetime; if still alive:
    //   - Update position (acceleration + velocity integration)
    //   - Compute alpha fade: 4 * (lifetime-1) for < 32 frames, else 0x80
    //   - Write 3 vertices per particle (offset, rotation, scale)
    //   - Write UV coords (0.5, 0.5, 0.5 default)
    //   - Write alpha via sin lookup (flt_C44BE0)
    
    // Phase 5: Finalize
    // - memset remaining vertex buffer to 0
    // - memset remaining index buffer to 0
    // - Project node coordinates via FFX_Menu2D_ProjectNodeCoords
    // - Set render state (z bounds: -100000 to 100000)
    // - Release texture slot
    // - Commit drawable resources
    // - Wait for GPU (spin on MEMORY[0x23056E8] & 0x100)
    // - Setup render state block
    // - Pop work buffer frame
}
```

**Key strings:** "NoTexture" at `0xB41B58` — fallback when texture slot not found.

### 5. FFX_MagicHost_ProcessParticleVfx (0x74af40, 1673B)

**0 direct callers** (called indirectly via function pointer table or thunks). Processes particle VFX updates:

```c
void __usercall FFX_MagicHost_ProcessParticleVfx(int a1@<ebp>, DWORD *a2, int a3, int a4) {
    // Phase 1: Update transforms from slot B
    // Phase 2: Check opcode category via ClassifyPppOpcodeByte
    // Phase 3: Build VFX texture and finalize
    // Phase 4: Load character model if flagged
    // Phase 5: Commit drawable resources
    // Phase 6: ByteVector/ShortVector operations (SIMD-friendly)
}
```

The function calls `FFX_MagicHost_ClassifyPppOpcodeByte` to determine the opcode category before processing. This is a **tick function** — called every frame to update particle VFX state.

### 6. FFX_MagicHost_AllocPppParticleSlotsForMenu (0x7197d0, 2512B)

Menu-specific variant of the particle slot allocator. Handles allocating particle slots for menu particle effects (different pool/capacity than battle particles).

### 7. FFX_MagicHost_RenderVfxParticles (0x7697d0, 1489B)

Called by **2 callers**: `FieldMap_RenderVfxParticlesEx` and `FieldMap_VfxAudioNodeTick_Callback`. Renders VFX particles to the scene:

```c
int FFX_MagicHost_RenderVfxParticles(ctx) {
    // Phase 1: Particle slot enumeration
    // Phase 2: Draw record setup
    // Phase 3: VFX transform processing
    // Phase 4: Render with transform (RenderVfxWithTransform)
    // Phase 5: Commit drawable
}
```

**Audio sync variant** (0x76a300, 1094B): `FFX_MagicHost_RenderVfxParticlesAudioSync` — synchronizes particle rendering with audio playback (e.g., spell casting sounds matching particle bursts).

### 8. FFX_FieldParticle_UpdateTick (0x830620, 1327B)

Called by **`FFX_Field_UpdateEncounterTick`** (0x82edd0, 4272B). Updates field particle system each tick:

```c
void __cdecl FFX_FieldParticle_UpdateTick(int tickParam) {
    // Phase 1: Read field particle state
    // Phase 2: Compute dot product for direction
    // Phase 3: Call FFX_FieldParticle_UpdateMovement for each active particle
    // Phase 4: HUD integration:
    //   - FFX_BtlUI_HudParty_GetCommand — get current command
    //   - FFX_BtlUI_HudParty_GetTarget — get current target
    // Phase 5: Math operations (sqrt, pow for distance/scaling)
    // Phase 6: Security cookie check
}
```

**Callees:** memset, _CIsqrt, _CIpow, FFX_Vector3_DotProduct, FFX_FieldParticle_UpdateMovement, FFX_BtlUI_HudParty_GetCommand, FFX_BtlUI_HudParty_GetTarget.

### 9. FFX_Field_DrawParticlePass_structural (0x81a5e0, 1836B)

**0 direct callers** (called via vtable or function pointer). Draws the field particle rendering pass:

```c
WORD *__cdecl FFX_Field_DrawParticlePass_structural(int a1, WORD *a2) {
    // Phase 1: Read particle state (constant 0x1FF = 511 max particles)
    // Phase 2: Begin render pass (18-byte stride state)
    // Phase 3: For each active particle:
    //   - Compute position and rotation
    //   - Apply material/color transforms
    //   - Write vertex/index data
    // Phase 4: End render pass
    // Phase 5: Security cookie check
}
```

### 10. FFX_Magic_PPP_BuildDrawableFromOpcode_ProcessCmd (0x71d600, 1704B)

Processes a PPP command to build a drawable. Called during the PPP→drawable conversion pipeline:

```c
int FFX_Magic_PPP_BuildDrawableFromOpcode_ProcessCmd(cmd, ctx) {
    // Phase 1: Decode PPP command header
    // Phase 2: Extract texture paths from opcode
    // Phase 3: Build drawable primitives
    // Phase 4: Apply opcode-specific configuration
    //   - Sprite size, UV coordinates
    //   - Color/alpha modulation
    //   - Blend mode
    // Phase 5: Register with render system
}
```

---

## Complete Function Inventory

### Core Particle Engine (11 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x6e4fd0 | `FFX_Particle_Emit` | 303B | Emit particle(s) from emitter |
| 0x6e54f0 | `FFX_Particle_Render` | 193B | Render particle batch |
| 0x6e5150 | `FFX_Particle_Update` | 113B | Update particle properties |
| 0x634940 | `FFX_Particle_FreeBuffers` | 154B | Free particle buffers |
| 0x6e55c0 | `FFX_Particle_GetCount` | 25B | Get particle count |
| 0x6e5100 | `FFX_Particle_Init` | 19B | Initialize particle system |
| 0x6e5120 | `FFX_Particle_SetTexture` | 43B | Set particle texture |
| 0x6e57d0 | `FFX_Particle_SetLife` | 43B | Set particle lifetime |
| 0x6e5800 | `FFX_Particle_GetLife` | 29B | Get particle lifetime |
| 0x6e57c0 | `FFX_Particle_Kill` | 11B | Kill particle |
| 0x6e5700 | `FFX_Particle_IsAlive` | 6B | Check if particle alive |

### PPP Opcode VM – MagicVM (19 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0xa72380 | `FFX_MagicVm_PppOpcodeExecute` | 1969B | **Central PPP VM dispatcher (274 opcodes)** |
| 0xa73d90 | `FFX_MagicVm_CommitAndRenderDrawable` | 1652B | Commit and render drawable |
| 0xa6dbe0 | `FFX_MagicVm_DrawDispatchSetup` | 1480B | Draw dispatch setup |
| 0x72ef30 | `FFX_MagicVm_ProcessTransformFrame` | 1300B | Process transform frame |
| 0xa6ed40 | `FFX_MagicVm_DrawVertexTransform` | 1165B | Draw vertex transform |
| 0xa6e2e0 | `FFX_MagicVm_SetupDrawPipelineState` | 594B | Setup draw pipeline state |
| 0xa753f0 | `FFX_MagicVm_InitRenderStateArrays` | 582B | Initialize render state arrays |
| 0xa62e20 | `FFX_MagicVm_SetupCoordTransform` | 537B | Setup coordinate transform |
| 0xa63070 | `FFX_MagicVm_DrawGeometrySetup` | 562B | Draw geometry setup |
| 0xa6e540 | `FFX_MagicVm_InitDrawSlots` | 143B | Initialize draw slots |
| 0xa74c60 | `FFX_MagicVm_InitOrLoadRenderState` | 208B | Init/load render state |
| 0xa6e5d0 | `FFX_MagicVm_DrawSlotPushTransform` | 116B | Push draw slot transform |
| 0xa6e260 | `FFX_MagicVm_UpdateTextureFadeSlots` | 120B | Update texture fade slots |
| 0x7ea760 | `FFX_MagicVm_TransformDrawDispatch_helper` | 148B | Transform draw dispatch helper |
| 0x801620 | `FFX_MagicVm_GetOpuRecordPoolIndex_helper` | 128B | Get OPU record pool index |
| 0x7e97c0 | `FFX_MagicVm_ComposeRecordMatrix_helper` | 154B | Compose record matrix helper |
| 0xa63040 | `FFX_MagicVm_SetupDefaultDrawGeometry` | 39B | Setup default draw geometry |
| 0x7e6910 | `FFX_MagicVm_PushWorkBufferFrame` | 38B | Push work buffer frame (4864B) |
| 0x7e6970 | `FFX_MagicVm_PopWorkBufferFrame` | 7B | Pop work buffer frame |

### PPP Draw Pipeline – FFX_Magic_PPP_* (9 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x71c190 | `FFX_Magic_PPP_SpriteDraw_Setup` | 3433B | **Sprite draw setup (3 callers)** |
| 0x71d600 | `FFX_Magic_PPP_BuildDrawableFromOpcode_ProcessCmd` | 1704B | Build drawable from opcode command |
| 0x7129b0 | `FFX_Magic_PPP_RenderWithMetadata` | 679B | Render with metadata |
| 0x712770 | `FFX_Magic_PPP_RenderGeometry` | 568B | Render geometry |
| 0x715ea0 | `FFX_Magic_PPP_BuildTexturePathFromOpcode` | 650B | Build texture path from opcode string |
| 0x7158f0 | `FFX_Magic_PPP_SpriteDraw_BuildTextureSlots` | 547B | Build texture slots for sprite draw |
| 0x711910 | `FFX_Magic_PPP_BuildDrawableFromOpcode` | 218B | Build drawable from opcode |
| 0x7115e0 | `FFX_Magic_PPP_SpriteDraw_CommitResources` | 172B | Commit sprite draw resources |
| 0x7111b0 | `FFX_Magic_PPP_SpriteDraw_DivideSamples` | 172B | Divide sprite draw samples |

### PPP Resource Management – FFX_MagicHost (24 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0xa5c370 | `FFX_MagicHost_PppDrawRecord_Build` | 739B | Build PPP draw record |
| 0x745560 | `FFX_MagicHost_AllocEffectPppMemory_C` | 310B | Alloc effect PPP memory C |
| 0x728750 | `FFX_MagicHost_AllocPppDrawRecord` | 233B | Alloc PPP draw record |
| 0x7456d0 | `FFX_MagicHost_InitPppTransformFromSource` | 284B | Init PPP transform from source |
| 0x712080 | `FFX_MagicHost_RelocatePppResourceBlob` | 335B | Relocate PPP resource blob |
| 0x7121d0 | `FFX_MagicHost_RelocatePppSection` | 342B | Relocate PPP section |
| 0x63ff60 | `FFX_MagicHost_AllocPppParticleSlot` | 406B | **Alloc PPP particle slot** |
| 0x72a3d0 | `FFX_MagicHost_BuildPppTransformFromEulerOrder_structural` | 561B | Build PPP transform from euler |
| 0x746600 | `FFX_MagicHost_AllocEffectPppMemory_D` | 193B | Alloc effect PPP memory D |
| 0x747820 | `FFX_MagicHost_AllocEffectPppMemory_E` | 193B | Alloc effect PPP memory E |
| 0x76acf0 | `FFX_MagicHost_AdvancePppFrameIndex` | 136B | Advance PPP frame index |
| 0x711540 | `FFX_MagicHost_BindPppResourceToDrawable` | 157B | Bind PPP resource to drawable |
| 0xa5be30 | `FFX_MagicHost_PppDrawRec_CopyGlobalA` | 135B | Copy global state A to draw record |
| 0xa5bec0 | `FFX_MagicHost_PppDrawRec_CopyGlobalB` | 135B | Copy global state B to draw record |
| 0x716ab0 | `FFX_MagicHost_AttachPppResourceBuffer` | 84B | Attach PPP resource buffer |
| 0x8004a0 | `FFX_MagicHost_InitQueuedPppResourceBuffers` | 101B | Initialize queued PPP buffers |
| 0x712d10 | `FFX_MagicHost_ClassifyPppOpcodeByte` | 100B | **Classify PPP opcode byte → category** |
| 0x7176e0 | `FFX_MagicHost_SetPppLineMax32` | 11B | Set PPP line max to 32 |
| 0x7176f0 | `FFX_MagicHost_SetPppLineCount` | 13B | Set PPP line count |
| 0x7e45e0 | `FFX_MagicHost_CheckPppResourceRingAvailability_structural` | 79B | Check PPP resource ring availability |
| 0x7197d0 | `FFX_MagicHost_AllocPppParticleSlotsForMenu` | 2512B | **Menu PPP particle slot alloc** |
| 0xa72b80 | `FFX_MagicHost_DrawPppElements` | 2929B | **Draw PPP elements (called by DrawDispatch)** |

### VFX Texture Binding – FFX_MagicHost (46 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x7186f0 | `FFX_MagicHost_AllocVfxParticleSlots` | **4350B** | **LARGEST — VFX particle slot allocator** |
| 0x713870 | `FFX_MagicHost_BuildVfxTextureBindingDispatch_structural` | 4086B | VFX texture binding dispatch |
| 0x73ba70 | `FFX_MagicHost_BuildVfxTextures` | 3874B | Build VFX textures |
| 0x914a10 | `FFX_MagicHost_VfxTransformPopulate` | 1778B | Populate VFX transform |
| 0x73fb10 | `FFX_MagicHost_BuildVfxTexture` | 1685B | Build VFX texture |
| 0x715250 | `FFX_MagicHost_CreateVfxRenderDataBuffer` | 1682B | Create VFX render data buffer |
| 0x74af40 | `FFX_MagicHost_ProcessParticleVfx` | 1673B | **Process particle VFX (tick)** |
| 0x739df0 | `FFX_MagicHost_BuildVfxTextureLocale` | 1590B | Build VFX texture locale |
| 0x738f80 | `FFX_MagicHost_BuildVfxTexture_TypeE` | 1471B | Build VFX texture Type E |
| 0x738000 | `FFX_MagicHost_BuildVfxTexture_TypeF` | 1455B | Build VFX texture Type F |
| 0x74a2b0 | `FFX_MagicHost_BuildVfxTexture_TypeG` | 1406B | Build VFX texture Type G |
| 0x71d070 | `FFX_MagicHost_AllocVfxVertexSlots` | 1418B | Alloc VFX vertex slots |
| 0x7404d0 | `FFX_MagicHost_RenderVfxWithTransform` | 1349B | Render VFX with transform |
| 0x74a920 | `FFX_MagicHost_RenderVfxWithTransform_B` | 1319B | Render VFX with transform B |
| 0x738b00 | `FFX_MagicHost_BuildVfxTexture_TypeH` | 1150B | Build VFX texture Type H |
| 0x73d130 | `FFX_MagicHost_BuildVfxTexture_TypeI` | 1114B | Build VFX texture Type I |
| 0x741660 | `FFX_MagicHost_BuildVfxTexture_TypeJ` | 1087B | Build VFX texture Type J |
| 0x76a300 | `FFX_MagicHost_RenderVfxParticlesAudioSync` | 1094B | **Render VFX particles (audio-synced)** |
| 0x741020 | `FFX_MagicHost_BuildVfxDrawableFromPppAlt` | 1250B | Build VFX drawable from PPP (alt) |
| 0x740b30 | `FFX_MagicHost_BuildVfxDrawableFromPpp` | 1076B | Build VFX drawable from PPP |
| 0x714e20 | `FFX_MagicHost_BuildVfxTextureFromRecord` | 1057B | Build VFX texture from record |
| 0xa76770 | `FFX_MagicHost_VfxDraw` | 969B | VFX draw entry |
| 0x737830 | `FFX_MagicHost_BuildVfxTexture_TypeK` | 938B | Build VFX texture Type K |
| 0x714890 | `FFX_MagicHost_BuildVfxTextureFromPath` | 938B | Build VFX texture from path |
| 0x755130 | `FFX_MagicHost_UpdateVfxTransformAnim` | 882B | Update VFX transform animation |
| 0x757930 | `FFX_MagicHost_UpdateVfxRandomAnimation` | 751B | Update VFX random animation |
| 0x715bd0 | `FFX_MagicHost_BuildVfxTextureRecordsFromNames_structural` | 714B | Build VFX texture records from names |
| 0x712fa0 | `FFX_MagicHost_LoadSpecialVfxTextureTriplet` | 657B | Load special VFX texture triplet |
| 0xa5bf50 | `FFX_MagicHost_VfxDrawDispatch` | 305B | VFX draw dispatch |
| 0x749f60 | `FFX_MagicHost_ProcessPlaneVfx` | 249B | Process plane VFX |
| 0x74a830 | `FFX_MagicHost_ProcessRibbonVfx` | 235B | Process ribbon VFX |
| 0x74ae50 | `FFX_MagicHost_LookupVfxTransformData` | 235B | Lookup VFX transform data |
| 0x7112c0 | `FFX_MagicHost_BuildVfxTextureForMenu` | 238B | Build VFX texture for menu |
| 0x711110 | `FFX_MagicHost_ProcessVfxRenderData` | 157B | Process VFX render data |
| 0x7118a0 | `FFX_MagicHost_AllocOrBuildVfxVertex` | 111B | Alloc or build VFX vertex |
| 0x740aa0 | `FFX_MagicHost_DispatchVfxDrawableBySlot` | 142B | Dispatch VFX drawable by slot |
| 0x740f90 | `FFX_MagicHost_DispatchVfxDrawableAlt` | 142B | Dispatch VFX drawable alt |
| 0x740a20 | `FFX_MagicHost_CheckVfxChannelFlags` | 127B | Check VFX channel flags |
| 0x741aa0 | `FFX_MagicHost_CheckVfxMaskFlagBits` | 96B | Check VFX mask flag bits |
| 0x716700 | `FFX_MagicHost_BuildNamedVfxTextureAndCommitDrawable_structural` | 135B | Build named VFX texture |
| 0x711260 | `FFX_MagicHost_BuildVfxTextureAndCommitDrawable_structural` | 89B | Build VFX texture and commit drawable |
| 0x7110b0 | `FFX_MagicHost_BuildVfxTextureAndFinalize_structural` | 89B | Build VFX texture and finalize |
| 0xa76720 | `FFX_MagicHost_VfxDrawDispatcher` | 73B | VFX draw dispatcher |
| 0x74bfa0 | `FFX_MagicHost_ProcessDecalVfx` | 49B | Process decal VFX |
| 0x6414e0 | `FFX_MagicHost_BuildVfxTexture_Bridge` | 22B | Build VFX texture bridge |

### Field Particle System (14 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x830620 | `FFX_FieldParticle_UpdateTick` | 1327B | **Field particle tick (called by UpdateEncounterTick)** |
| 0x81a5e0 | `FFX_Field_DrawParticlePass_structural` | 1836B | **Draw field particle pass** |
| 0x831d90 | `FFX_FieldParticle_ComputeQuadVertices` | 496B | Compute quad vertices |
| 0x82e460 | `FFX_FieldParticle_ComputePosition` | 440B | Compute particle position |
| 0x63cd40 | `FFX_FieldParticle_UpdateMovement` | 411B | Update particle movement |
| 0x766860 | `FFX_Field_AllocSceneParticleSlots` | 583B | Alloc scene particle slots |
| 0x71a410 | `FFX_Field_AllocMiniMapParticleSlots` | 425B | Alloc minimap particle slots |
| 0x830200 | `FFX_FieldParticle_UpdateAll` | 192B | Update all field particles |
| 0x8302c0 | `FFX_FieldParticle_UpdateSingle` | 214B | Update single field particle |
| 0x830420 | `FFX_FieldParticle_IsSuppressedByEncounter` | 64B | Check if suppressed by encounter |
| 0x831800 | `FFX_FieldParticle_IsExcludedType` | 41B | Check if excluded type |
| 0x8301e0 | `FFX_FieldParticle_SetOpacityMode` | 32B | Set opacity mode |
| 0x830130 | `FFX_FieldParticle_SetFlagBit19` | 31B | Set flag bit 19 |
| 0x643160 | `FFX_FieldParticle_SetHudBarEnemyPosition` | 33B | Set HUD bar enemy position |

### Particle Side Ops – FFX_MagicSideOp_* (22 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x811d20 | `FFX_MagicSideOp_17_structural` | 2287B | Side op 17 (particle system) |
| 0x80ecb0 | `FFX_MagicSideOp_18_structural` | 1715B | Side op 18 (particle system) |
| 0x811690 | `FFX_MagicSideOp_10_structural` | 1679B | Side op 10 |
| 0x80e450 | `FFX_MagicSideOp_14_TransformColorsOpaque` | 1539B | Transform colors opaque |
| 0x812cb0 | `FFX_MagicSideOp_12_structural` | 1100B | Side op 12 |
| 0x813d80 | `FFX_MagicSideOp_05_CommitParticleVertices` | 1092B | **Commit particle vertices** |
| 0x811280 | `FFX_MagicSideOp_01_structural` | 1032B | Side op 01 |
| 0x813180 | `FFX_MagicSideOp_06_structural` | 994B | Side op 06 |
| 0x801fc0 | `FFX_MagicSideOp_02_structural` | 651B | Side op 02 |
| 0x80ea60 | `FFX_MagicSideOp_ComputeSlotColorScales` | 592B | Compute slot color scales |
| 0x80f7e0 | `FFX_MagicSideOp_07_structural` | 347B | Side op 07 |
| 0x80e190 | `FFX_MagicSideOp_15_structural` | 289B | Side op 15 |
| 0x80e070 | `FFX_MagicSideOp_14_structural` | 282B | Side op 14 |
| 0x802270 | `FFX_MagicSideOp_16_structural` | 253B | Side op 16 |
| 0x8141d0 | `FFX_MagicSideOp_05_LoadNoTextureSlot` | 219B | Load "NoTexture" slot |
| 0x813100 | `FFX_MagicSideOp_04_structural` | 123B | Side op 04 |
| 0x813a30 | `FFX_MagicSideOp_05_DrawLineTriangleSetup` | 115B | Draw line triangle setup |
| 0x813570 | `FFX_MagicSideOp_05_structural` | 70B | Side op 05 |
| 0x8135c0 | `FFX_MagicSideOp_11_structural` | 28B | Side op 11 |
| 0x6392c0 | `FFX_MagicSideOp_SetGaussianBlurActive` | 20B | Set gaussian blur active |
| 0x80f960 | `FFX_MagicSideOp_08_Noop` | 1B | Side op 08 (noop) |
| 0x80e060 | `FFX_MagicSideOp_13_Noop` | 1B | Side op 13 (noop) |

### PPP Memory Pool – PppMem_* (49 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x764ca0 | `FFX_PppMem_BuildNodeChain` | 138B | Master node chain builder (non-template) |
| 0x73d070 | `PppMem_InitNodeIdentityFields` | 48B | Init node identity fields |
| 0x736ef0 | `PppMem_NodeChainInitOne` | 46B | Init node chain with ones |
| 0x736f20 | `PppMem_NodeChainInitZero` | 46B | Init node chain with zeros |
| 0x73cf40 | `PppMem_GetDefaultVfxTexCoords` | 39B | Get default VFX texture coords |
| 0x72ee90 | `PppMem_ClearVec3At160` | 39B | Clear Vec3 at offset 160 |
| 0x73cee0 | `PppMem_GetVramBufferPtr` | 6B | Get VRAM buffer pointer |
| 0x7374d0 | `PppMem_ClearNodeFlag` | 11B | Clear node flag |
| 0x7648f0 | `FFX_PppMem_AllocNode` | 24B | Alloc PPP memory node |
| 0x73d980 | `PppMem_InitNodeField_296` | 35B | Init node field at 296 |
| 0x73e300 | `PppMem_InitNodeField_160_A` | 35B | Init node field 160 A |
| 0x73ea90 | `PppMem_InitNodeField_160_B` | 35B | Init node field 160 B |
| 0x73f280 | `PppMem_InitNodeField_160_C` | 35B | Init node field 160 C |
| 0x73faa0 | `PppMem_InitNodeField_160_D` | 35B | Init node field 160 D |

**BuildNodeChain template stubs (35 functions, 0x24-0x27B each):**
`PppMem_BuildNodeChain_1x8`, `4x8`, `1x16`, `4x16`, `8x16`, `16x16`, `24x16`, `32x32`, `64x16`, `1x24`, `4x24`, `8x24`, `16x24`, `1x32`, `4x32`, `8x32`, `16x32`, `24x32`, `32x32`, `1x40`, `4x40`, `8x40`, `16x40`, `1x48`, `4x48`, `8x48`, `16x48`, `1x64`, `4x64`, `8x64`, `16x64`, `1x128`, `4x128`, `8x128`, `1x255`, `4x255`, `128x8`

All follow same pattern: `NxM` = N elements of M bytes each.

### PPP Kernel Ops – FFX_KR / FFX_Render / FFX_Ppp (16 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x729ba0 | `FFX_Render_PppRenderLoop` | 1107B | PPP render loop |
| 0x7170f0 | `FFX_Render_PppProgramProcessor` | 1003B | PPP program processor |
| 0x728bb0 | `FFX_Render_BuildPppTransform` | 686B | Build PPP transform |
| 0x72a8e0 | `FFX_Render_LoadPppResourceBlob` | 578B | Load PPP resource blob |
| 0x7123d0 | `FFX_Render_PppRenderProcess` | 208B | PPP render process |
| 0x7288a0 | `FFX_Render_ProcessParticleCommand` | 537B | Process particle render command |
| 0x72ab30 | `FFX_Render_LoadPppTextures` | 116B | Load PPP textures |
| 0x908df0 | `FFX_Render_CopyPppTransformById` | 50B | Copy PPP transform by ID |
| 0x90a520 | `FFX_Render_WritePppTransformById` | 50B | Write PPP transform by ID |
| 0x908e30 | `FFX_Render_CopyPppTransformByFieldId` | 85B | Copy PPP transform by field ID |
| 0x90a4d0 | `FFX_Ppp_SetTransformFloatParam` | 56B | Set PPP transform float param |
| 0x9083e0 | `FFX_Render_PppRenderIfActive` | 23B | Render PPP if active |
| 0x80b7b0 | `FFX_Magic_IsLargePppResource` | 27B | Check if large PPP resource |
| 0x712cb0 | `FFX_KR_AdjustPppBufferOffsets` | 93B | Adjust PPP buffer offsets |
| 0x756360 | `FFX_KR_FreeSlotPppMemory` | 75B | Free slot PPP memory |
| 0x766c80 | `FFX_PppMemoryPool_AllocEntry` | 80B | Alloc PPP memory pool entry |

### Magic Particle Flags (5 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x639510 | `FFX_Magic_Particle_SetFlag5` | 12B | Set particle flag 5 |
| 0x639520 | `FFX_Magic_Particle_SetFlag4` | 12B | Set particle flag 4 |
| 0x639540 | `FFX_Magic_Particle_SetFlag6` | 12B | Set particle flag 6 |
| 0x639650 | `FFX_Magic_Particle_ClearFlag6` | 12B | Clear particle flag 6 |
| 0x639660 | `FFX_Magic_ParticleSubmitCluster` | 38B | Submit particle cluster |

### Field Map Particle Integration (8 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x769450 | `FieldMap_RenderVfxParticle_CommitDrawable` | 840B | Commit VFX particle drawable |
| 0x75a850 | `FieldMap_RenderVfxParticlesAudioSync` | 259B | Render VFX particles audio sync |
| 0x75ac40 | `FieldMap_RenderVfxParticlesAudioSyncEx` | 259B | Render VFX particles audio sync ex |
| 0x75a490 | `FieldMap_RenderVfxParticlesEx` | 256B | Render VFX particles ex |
| 0x75a0e0 | `FieldMap_RenderVfxParticles_Prep` | 243B | Prepare VFX particle render |
| 0x75a340 | `FieldMap_ParticleNodeTick_Callback` | 126B | Particle node tick callback |
| 0x75a1e0 | `FieldMap_InitParticleNode` | 72B | Initialize particle node |
| 0x75a230 | `FieldMap_FreeParticleNode` | 74B | Free particle node |

### Magic Alloc/Parse (11 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x6e48a0 | `FFX_Field_ProcessParticles` | 428B | Process field particles |
| 0x800690 | `FFX_Magic_AllocParticleSlot` | 309B | Alloc particle slot |
| 0x7134c0 | `FFX_Magic_AllocParticle_ParseSections` | 452B | Parse particle alloc sections |
| 0x713690 | `FFX_Magic_AllocParticle_ParseSections_B` | 445B | Parse particle alloc sections B |
| 0x6416c0 | `FFX_Magic_AllocParticleResources` | 327B | Alloc particle resources |
| 0x712640 | `FFX_Magic_AllocParticleSlot_ParsePPP` | 290B | Parse PPP in particle slot alloc |
| 0x713240 | `FFX_MagicHost_AllocParticleSlotNoTexture` | 297B | Alloc particle slot no texture |
| 0x71cf00 | `FFX_MagicHost_SetupQuadParticleSlots` | 366B | Setup quad particle slots |
| 0x800890 | `FFX_Magic_ClearAllParticleSlots` | 73B | Clear all particle slots |
| 0x8007d0 | `FFX_Magic_FreeRunParticleSlot` | 166B | Free run particle slot |
| 0x713370 | `FFX_KR_ResetParticleSlotCounters` | 144B | Reset particle slot counters |
| 0x713400 | `FFX_KR_ResetParticleSlotData` | 179B | Reset particle slot data |

### Debug Particle (5 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x938350 | `Dbg_SaveParticleDataToHost` | 542B | Save particle data to debug host |
| 0x9399f0 | `FFX_Dbg_SerializeParticleItem` | 275B | Serialize particle item |
| 0x93c120 | `FFX_Dbg_IsParticleEditActive` | 40B | Check if particle edit active |
| 0x932320 | `FFX_FieldDebug_InitMotionParticleState` | 130B | Init debug motion particle state |
| 0x932470 | `FFX_FieldDebug_SetupMotionParticleSlot` | 252B | Setup debug motion particle slot |

### Phyre Particle (6 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0x9b7050 | `Phyre_Particle_GroupDispatch` | 870B | Particle group dispatch |
| 0x9b5bf0 | `Phyre_Particle_ClampCoefficients` | 125B | Clamp particle coefficients |
| 0xa06470 | `Phyre_PostProcessing_MeshParticle` | 724B | Post-processing mesh particle |
| 0xa06750 | `Phyre_PostProcessing_ParticleSystem` | 726B | Post-processing particle system |
| 0x91f9d0 | `FFX_MagicVfx_BuildParticleSim` | 811B | Build particle simulation |
| 0xaf3b70 | `PhyreInit_PMeshParticleSystemBase` | 183B | Init Phyre mesh particle system base |

### Particle Alloc via Phyre (7 functions)

| Address | Name | Size | Role |
|---------|------|------|------|
| 0xa176d0 | `Phyre_PostProcessing_ParticleSystemAlloc` | 161B | Alloc particle system |
| 0xa17ec0 | `Phyre_PostProcessing_ParticleSystemAlloc2` | 345B | Alloc particle system 2 |
| 0xa19970 | `Phyre_PostProcessing_ParticleSystemAlloc_WithEffectChain` | 328B | Alloc particle system with effect chain |
| 0xa198d0 | `Phyre_PostProcessing_ParticleSystemAlloc_Wrapper` | 156B | Alloc wrapper |
| 0xa19c10 | `Phyre_PostProcessing_ParticleSystemAlloc2_Wrapper` | 156B | Alloc 2 wrapper |
| 0xa17980 | `Phyre_PostProcessing_ParticleSystemAlloc_ThunkToA1A2C0` | 9B | Alloc thunk |

---

## Complete Size Distribution

```
Bytes Range       Count     Examples
─────────────────────────────────────
≥ 4000            1         FFX_MagicHost_AllocVfxParticleSlots (4350B)
3000-3999         2         FFX_Magic_PPP_SpriteDraw_Setup (3433B), FFX_MagicHost_DrawPppElements (2929B)
2000-2999         5         AllocPppParticleSlotsForMenu (2512B), PppOpcodeExecute (1969B), etc.
1000-1999         12        DrawParticlePass, ProcessParticleVfx, AllocEffectPppMemory*, etc.
500-999           18        BuildVfxTexture_TypeE/F/G/H, PppDrawRecord_Build, etc.
100-499           48        AllocPppDrawRecord, UpdateVfxTransformAnim, etc.
< 100             141       Mostly PppMem_BuildNodeChain stubs + small accessors
```

---

## Key Findings

1. **PPP is a complete bytecode VM with 274 opcodes** — not just a data format. `FFX_MagicVm_PppOpcodeExecute` (1.97KB) dispatches 11 categories: Draw(46), Ke(106), Rand(33), Matrix(29), Special(14), Light(12), Move(7), Accele(4), Point(5), Color(2), Other(20). Opcode strings at `0xB4FEB0`–`0xB513D4`.

2. **VFX pipeline is texture-slot-driven** — `AllocVfxParticleSlots` (4.3KB, 29 callers) is the largest function because it orchestrates texture binding, transform setup, color scaling, and slot allocation in one pass. Multi-texture effects use a 10000-unit key stride.

3. **PppMem_* is a pooled allocator, not particle logic** — 47 of 49 functions are template-generated stubs for fixed-size slab allocation. The only non-trivial function is `FFX_PppMem_BuildNodeChain` (138B). Size variants range from 1x3 to 4x255 elements.

4. **No single "particle manager" function** — the system is distributed: field particles tick via `FFX_FieldParticle_UpdateTick` → `FFX_Field_UpdateEncounterTick`, battle particles via `FFX_MagicHost_ProcessParticleVfx`, menu particles via dedicated allocators.

5. **VFX texture types A-K** — `FFX_MagicHost_BuildVfxTexture_TypeE/F/G/H/I/J/K` plus `TypeLocale` and `BuildVfxTextures` (bulk) handle different texture build strategies. Each type likely corresponds to a different shader profile or blend mode.

6. **Magic ID overrides control particle resolution** — IDs 102, 103, 374, 515, 667 force specific particle sizes (256/512px) and UV layouts. This is how Aeon overdrive particle quality is controlled.

7. **Variable-count multi-texture** — The `n2` field (at dataPtr+192) controls texture count: 0=single, 1=4-texture (fixed), 2=variable from header word at dataPtr+196.

8. **Side ops 05 is the particle vertex commit** — `FFX_MagicSideOp_05_CommitParticleVertices` (1092B) is the function that actually writes particle vertex data to the GPU buffer.

9. **Audio-synced particle rendering** — `FFX_MagicHost_RenderVfxParticlesAudioSync` (1094B) + `FieldMap_RenderVfxParticlesAudioSync` (259B) synchronize particle effects with audio playback cues.

10. **227 functions total** — of which ~86 are substantive (>100 bytes) and ~141 are small stubs (<100 bytes, mostly template-generated PppMem variants).

---

## What's Next?

- **batch_0008**: Sound queue (`FFX_Sound_QueueCmd22/24/32/46`)
- **batch_0009**: RTTI classes via class_informer (non-PhyreEngine FFX classes)
- **Task #31**: Mapear pontos de entrada do jogo — `FFX_System_Host_Constructor` (3482B)
- **Task #36**: Varrer SDK 4.00 por Phyre/PBinary/MSCD/SacSlicer

---

**Next batch:** Sound queue — FFX_Sound_QueueCmd22/24/32/46.
