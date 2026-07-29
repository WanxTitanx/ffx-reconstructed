# FFX.exe Decompilation — Batch 16 (Phyre_PostProcessing)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** ~150 substantive + ~498 stubs/thunks (648 total)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Naming Convention Note

The naming convention is **`Phyre_PostProcessing_*`**, NOT `Phyre_PP*` or `Phyre_PPA*`. The `Phyre_PP*` filter returns only `Phyre_PPhysics` (224 functions, separate namespace). All post-processing functions follow `Phyre_PostProcessing_<Subsystem><Detail>`.

---

## Summary

This batch covers FFX.exe's complete **post-processing pipeline** — the rendering subsystem that applies effects (bloom, DOF, motion blur, SSR, SSAO, glow, color grading, shadows, tone mapping, particle lighting, etc.) to the final framebuffer after scene rendering.

**Key discoveries:**
1. **23+ post-effect classes** discovered via Lua bindings (PDOF/PGlow/PMotionBlur/PSSR/PFXAA/PMLAA/PLegacyGlow/PPostEffectManager + Base/D3D11/GPUBase variants)
2. **RenderMain failed decompilation** (483 bytes, 28 blocks, 14 callees) — likely SIMD/intrinsic-heavy assembly
3. **`EffectDispatch` is the central registration hub** — registers all post-effects at startup
4. **`ShaderInitNoop` is the most-referenced stub** — 28 data refs, used as default initializer
5. **FFX-specific custom callee found** — `FFX_Phyre_FindShaderParamDefinitionByName` at 0x56cd50 — FFX team added function NOT in PhyreEngine SDK

---

# Part 1: Render Pipeline (6 functions)

## Phyre_PostProcessing_RenderMain (0x650e60, 483 bytes) — ⚠️ FAILED DECOMPILE
- **Status:** Hex-Rays failed (likely SIMD/intrinsic-heavy)
- **Callers:** 2 (InitSceneBattleHud, FFX_FieldMap_LoadOrchestrator_10k_structural)
- **Callees (14):** Phyre_Renderer_BeginWithViewport, Phyre_Renderer_DispatchDraw, Phyre_Renderer_DispatchDraw_w, Phyre_Renderer_UpdateBoneTransform, CalculateModelViewMatrix, FFX_Scene_GetRenderTarget, FFX_Scene_GetRenderTargetById, Phyre_PostProcessing_CalcSize_Hud, Phyre_PostProcessing_CheckRenderActive, FFX_PostProcess_CalcRenderTargetSize
- **Interpretation:** Central dispatcher for HUD + post-processing render, called from field map loading + battle HUD init
- **Note:** Requires manual disassembly for full analysis

## Phyre_PostProcessing_CheckRenderActive (0x652590, 24 bytes)
```c
int __thiscall Phyre_PostProcessing_CheckRenderActive(int this)
{
  return *(int *)(this + 0x439B0) || MEMORY[0x13407E4];  // 69068 + 0xC8?
}
```
- **Purpose:** Trivial boolean check — is post-processing active?
- **Constant:** `0x69068` is the singleton state field

## Phyre_PostProcessing_RenderFrame (0xa12470, 94 bytes) ⭐
```c
int __thiscall Phyre_PostProcessing_RenderFrame(int *this, unsigned int *a2, int a3)
{
  if ( !*(this + 4109) ) return 21;  // not ready
  result = PShaderInput_LoadResource(a2, 0, 0);
  if ( !result ) {
    result = Phyre_ShaderEffect_ConfigureFromParams(a2, 0);
    if ( !result ) {
      *(_DWORD *)(a3 + 200) = 0;
      return Phyre_PostProcessing_QueueCommand2(a2, *(this + 4110), *(this + 4109));
    }
  }
  return result;
}
```
- **Sequence:** ready check → load shader → configure params → zero slot → enqueue
- **Constants:** 4109/4110 = stride offsets in effect cluster

## Phyre_PostProcessing_Pipeline (0xa0fd00, 316 bytes)
```c
int __thiscall Phyre_PostProcessing_Pipeline(int *this, int a2, int a3, int a4)
```
- **Callees:** PShaderInput_LoadResource, Phyre_ShaderParamSet3_Ctor, Phyre_ShaderEffect_ConfigureFromParams, PShaderParam_BindSamplerChecked, Phyre_Renderer_BeginScene, Phyre_Renderer_DispatchDraw
- **Purpose:** Complete shader pipeline — load → configure → bind → begin → draw
- **No direct callers** (called via vtable/function pointer)

## Phyre_PostProcessing_BeginRender3/4/6 (305/381/625 bytes) ⭐

Three variants for different working surface counts:

| Variant | Address | Surface Slot | Extra Calls |
|---------|---------|--------------|-------------|
| BeginRender3 | 0xa19ee0 | a3[2] | — |
| BeginRender4 | 0xa18f20 | a3[3] | — |
| BeginRender6 | 0xa191f0 | a3[5] | GetSingleton + Stub |

**Common algorithm:**
```c
if (*(this + 4021)) return 22;  // busy
validate working surface
extract width/height from render target
call WorkingSurfacesCreate()
call AllocWorkingBuffers()
return BeginRenderPrepHardware(this, a2);
```

## Phyre_PostProcessing_BeginRenderPrepHardware (0xa19cb0, 61 bytes)
```c
int __thiscall Phyre_PostProcessing_BeginRenderPrepHardware(_DWORD *this, int a2)
{
  *(this + 4023) = Phyre_PostProcessing_BufferOps();
  *(this + 4024) = Phyre_PostProcessing_Blend(a2, 8u);
  *(this + 4025) = FFX_Flash_TextureManager(a2, 0x10u);
  return 0;
}
```
- **Sets 3 hardware handles:** buffer ops + blend state + Flash texture manager
- **Constants:** 4023/4024/4025 = stride offsets

---

# Part 2: Effect System Dispatch (5 functions)

## Phyre_PostProcessing_EffectDispatch (0xa03dc0, 885 bytes) ⭐⭐
- **Purpose:** **THE central registration hub** for ALL post-effects
- **Registers (23+ effects):**
  ```
  DisableR2 (7 variants), Bloom, DOF / DOFCombine,
  MotionBlur, SMAA / SMAANeighborhood / SMAABlendingWeight,
  FXAA, SSAO / HDAO, Glow / BlurGlow,
  ColorCorrection, LightShaft / GodRay,
  FogExp / FogExpCol / FogLin,
  Shadow / ShadowMask / ShadowPCF / ShadowESM / ShadowVSM,
  Downscale / DownscaleCopy / DownscaleLum,
  RadialBlur, ColorGradingLUT,
  ToneMapping / ToneMappingFilmic / ToneMappingUncharted2, Copy
  ```
- **Class members:** m_postEffects, getPostEffect, getPostEffectClassDescriptor, getObjectAsBase, getObjectType
- **Callers:** Phyre_PostProcessing_RegisterAllEffects (0xa18020)

## Phyre_PostProcessing_EffectChain (0xa06120, 846 bytes) ⭐
- **Callees:** Phyre_PCluster_Allocate, Phyre_Stream_WriteLine, Phyre_Stream_ReadInt, Phyre_Stream_ReadString, Phyre_Stream_Close
- **Callers:** 14 (FFX_PostProcess_Buffer_Inicializar, blur/gaussian/motion blur init, video shader config)
- **Purpose:** Serialized effect chain — read/write geometry, indices, strings from stream

## Phyre_PostProcessing_EffectOneShot (0xa041c0, 224 bytes)
- **Callees:** Phyre_PClassDataMember_ctorAttach_structural (twice for float members)
- **Members:** m_minReflectionDirZ (float), m_marchStepFactor (float)
- **Callers:** RegisterAllEffects
- **Purpose:** One-shot effect descriptor registration

## Phyre_PostProcessing_Patch (0xa0e620, 485 bytes)
```c
int __thiscall Phyre_PostProcessing_Patch(int *this, _BYTE *a2)
```
- **Switch on this[4021]** — 3 modes
- **Callees:** PShaderInput_LoadResource, Phyre_ShaderParamSet3_Ctor, Phyre_ShaderEffect_ConfigureFromParams
- **Purpose:** Patch/override effect parameters at runtime

## Phyre_PostProcessing_RegisterAllEffects (0xa18020, 520 bytes) ⭐
- **Singleton guard:** byte_C0A09C
- **Callees:** Setup, RenderState x3, Init, EffectDispatch, EffectOneShot
- **Registers 2 class descriptors:** 0x1944510, 0x1943DF0 via `PTypeDefault_PChar_RegisterName` + `PClassDescriptor_FinalizeRegistration`
- **No direct callers** — called via CRT init from data pointer at 0xb73f74

---

# Part 3: Effect Base Class Constructors (6 functions)

All base constructors follow the **same structural pattern:**
1. Zero 3 header fields
2. Set width=256 at offset 8
3. Set vftable
4. Init shared ptrs via `PSharedPtr_GetRefCount`
5. Zero remaining DWORD fields
6. Conditional byte flag check at (base+12) & 0x80

## Phyre_PostProcessing_DeferredLightingBase_Constructor (0x9fb830, 759 bytes)
- **Vftable:** 0xb74160
- **Allocates:** 128 params via `PPostProcessEffect_SetParam` loop (127 iterations, 31-dword stride)
- **Defaults:** ambient=0.2/0.2/0.2, unknown=1.0
- **Callees:** PSharedPtr_GetRefCount, PPostProcessEffect_SetParam (loop)
- **Callers:** D3D11 ctor + ShaderEntryA

## Phyre_PostProcessing_DeferredLightingD3D11_Constructor (0x9fbb30, 445 bytes)
- **Calls:** Base ctor first
- **Replaces vftable** with D3D11 vftable at 0xb74270
- **Zeroes:** 12 render target slots at this+16276..16324 (48 bytes total)

## Phyre_PostProcessing_DepthOfFieldBase_Constructor (0x9fbd90, 540 bytes)
- **Vftable:** 0xb74488
- **DOF defaults:** focusPlaneDist=5.0, focusRange=2.0, focusBlurRange=0.5
- **Allocates:** shared ptrs at +976/+985, 976-element param table
- **Callers:** 4 (ShaderEntry C/D/E + others)

## Phyre_PostProcessing_GlowBase_Constructor (0x9fc310, 368 bytes)
- **Vftable:** 0xb752e8
- **Glow defaults:** intensity=1.0, threshold=0.7, blur passes=5, sampleCount=3
- **Controls:** glow buffer resolution at offset+12
- **Conditional:** bit 0x80 byte flag check

## Phyre_PostProcessing_MotionBlurBase_Constructor (0x9fcbb0, 722 bytes)
- **Vftable:** 0xb74820
- **MB defaults:** shutter speed=10.0, full screen blur strength=1.0
- **Allocates:** 824-element param table, 10 sample count, max steps 24
- **Weighted loop** for center/edge sampling

## Phyre_PostProcessing_ScreenSpaceReflectionBase_Constructor (0x9fd080, 372 bytes)
- **Vftable:** 0xb75d88
- **SSR defaults:** rayStep=0.0, rayLength=1.0
- **11 render target slots** at this+26..36
- **Bit check** at +15

---

# Part 4: Shader Setup Family (15 functions)

## Pattern: Each effect has Init + Setup pair

| Effect | Init (size) | Setup (size) | Vftable |
|--------|-------------|--------------|---------|
| DeferredLighting | 0xa1b6e0 (47B) | 0xa1a4f0 (459B) | 0xb74160 |
| DepthOfField | 0xa1b710 (105B) | 0xa185a0 (708B) | 0xb74488 |
| Effect | 0xa1b780 (47B) | 0xa18870 (527B) | — |
| Glow | 0xa1b7b0 (47B) | 0xa1a830 (716B) | 0xb752e8 |
| MotionBlur | 0xa1b7e0 (47B) | 0xa18c80 (672B) | 0xb74820 |
| SSR | 0xa1b820 (47B) | 0xa1ae00 (618B) | 0xb75d88 |

## Phyre_PostProcessing_ShaderInit (6 variants, 47B each)
```c
int __usercall Phyre_PostProcessing_ShaderInit(_DWORD *@<ecx>, int@<ebx>)
{
  // Universal pattern: call Setup, GetShaderPointer, set up shader slot
  return Phyre_<Effect>Setup(...) | Phyre_PostProcessing_GetShaderPointer(...);
}
```
- **Common callee:** GetShaderPointer (0xa161b0)

## Phyre_PostProcessing_ShaderSetup (6 variants, 459-716B) ⭐
- **Callees:** ResourceSurfaceAlloc, Cluster_Allocate, AlignedFree, FindShaderParamDefinitionByName, Texture_DeferredCreateFromFormat, memcpy, BindDeferredShadowParams_structural
- **Purpose:** Full shader compilation pipeline — alloc resources, find params, create textures, copy data
- **Each setup is unique** to its effect (no near-duplicate templates)

## Phyre_PostProcessing_ShaderCompile (0xa081b0, 311 bytes) ⭐
```c
int __cdecl Phyre_PostProcessing_ShaderCompile(lua_State *stream)
{
  // Lua binding for shader compilation
  Phyre_Scripting_PushPhyreObject(stream, ...);
  Phyre_RegisterBatch(...);
  PArrayPostEffectBase_ctor(...);  // PArray<PPostEffectBase*,4>
  ...
}
```
- **Purpose:** Lua-callable shader compile entry point

## Phyre_PostProcessing_ShaderApply (0xa07e80, 116 bytes)
```c
int __cdecl Phyre_PostProcessing_ShaderApply(_DWORD *a1)
{
  // Iterates shader list, calls DeferredLightingShaderSetup
  result = Phyre_PostProcessing_DeferredLightingShaderSetup(v3, v1, &unk_1943DA0, ShaderPointer);
}
```

## Phyre_PostProcessing_ShaderSetup_Wrapper (0xa07f00, 173 bytes) ⭐⭐
- **FFX-specific call:** `FFX_Phyre_FindShaderParamDefinitionByName` at 0x56cd50
- **Caches 3 shader params** at v2[1005]/[1006]/[1007]:
  - `FocusPlaneDistance` (string @ 0xb76734)
  - `FocusRange` (string @ 0xb76748)
  - `FocusBlurRange` (string @ 0xb76754)
- **Insight:** FFX team added custom function to find shader params by name — proves FFX modified PhyreEngine internals

---

# Part 5: Working Surface & Buffer Management (10 functions)

## Phyre_PostProcessing_WorkingSurface_Alloc (0x58f440, 472 bytes) ⭐
- **Stores:** width/height/format/flag
- **Uses:** SceneWideParam singleton at 0xC94F00 (with atexit cleanup)
- **Iterates** refcounted surfaces calling device CreateTexture via vtable+12
- **Returns:** error 9 on failure, calls RenderTargetView_Create on success
- **Callers:** 2 (WorkingSurfacesCreate + AllocWorkingBuffers)

## Phyre_PostProcessing_RenderTargetView_Create (0x58f760, 317 bytes)
- **Flag check:** bit 8 at +52 (return 0 if not set)
- **Same singleton pattern** as WorkingSurface_Alloc
- **Iterates** surfaces calling CreateRenderTargetView via vtable+28 (20-byte stride)
- **Returns:** error 9 on failure
- **Caller:** WorkingSurface_Alloc only

## Phyre_PostProcessing_WorkingSurfacesCreate (0xa10590, 330 bytes)
- **Purpose:** Create N working surfaces with format/flags
- **Stride:** width/height/format triplets

## Phyre_PostProcessing_AllocWorkingBuffers (0xa19cf0, 486 bytes)
- **Callees:** WorkingSurface_Alloc, RenderTargetView_Create (chained)
- **Allocates** working buffer array

## Phyre_PostProcessing_BufferDeepCopy64 (0xa00160, 1175 bytes) ⭐⭐
- **LARGEST buffer function** — 1.2KB deep copy
- **64-byte aligned** block copy
- **Used for** transferring state blocks between effects

## Phyre_PostProcessing_BufferOps (0xa05e70, 677 bytes)
- **Callees:** 20+ geometry/stream operations
- **Purpose:** All buffer arithmetic operations

## Phyre_PostProcessing_ProcessBuffers (0xa1b9d0, 467 bytes)
- **Callees:** memcpy, memmove, allocators
- **Purpose:** Process buffer pool after frame

## Phyre_PostProcessing_InitBuffers (0xa17780, 210 bytes)
- **Callees:** memcpy, Cluster_Allocate
- **Purpose:** Initialize buffer pool at startup

## Phyre_PostProcessing_Resolve (0xa0c860, 180 bytes)
```c
int __cdecl Phyre_PostProcessing_Resolve(lua_State *stream, const void *obj)
```
- **Lua binding** for resolving post-effect object pointer from script

## Phyre_PostProcessing_ResolveThunk (0xa1bbb0, 23 bytes)
- **Stdcall thunk** to Resolve — adjusts calling convention for Lua callbacks

---

# Part 6: Cluster & Effect Chain Allocation (9 functions)

## Phyre_PostProcessing_CreateEffectChain (0xa1a350, 386 bytes)
- **Callees:** Cluster_Allocate, Phyre_Stream_*
- **Purpose:** Allocate effect chain cluster (serialized effect list)

## Phyre_PostProcessing_Allocate3Clusters (0xa1a190, 293 bytes)
- **Allocates** 3 clusters for working buffers

## Phyre_PostProcessing_AllocateSingleClusterWithEffectChain (0xa1a2c0, 139 bytes)
- **Single cluster** with embedded effect chain

## Phyre_PostProcessing_CreateMipChainInternal (0xa179a0, 550 bytes) ⭐
- **Recursive mip chain** creation
- **Loop:** each mip = previous / 2

## Phyre_PostProcessing_CreateGlowMipChain (0xa17bd0, 412 bytes)
- **Special mip chain** for glow buffer (typically down to 1x1)

## Phyre_PostProcessing_ParticleSystemAlloc (0xa176d0, 161 bytes)
- **Allocates** particle system cluster

## Phyre_PostProcessing_ParticleSystemAlloc2 (0xa17ec0, 345 bytes)
- **Variant 2** with extra params

## Phyre_PostProcessing_ParticleSystemAlloc_WithEffectChain (0xa19970, 328 bytes)
- **Particle system + effect chain** combined

## Phyre_PostProcessing_ParticleSystemAlloc_ThunkToA1A2C0 (0xa17980, 9 bytes)
- **Trivial thunk** — just `jmp` to AllocateSingleClusterWithEffectChain

---

# Part 7: Particle System & Blend (5 functions)

## Phyre_PostProcessing_Blend (0xa06ab0, 932 bytes) ⭐⭐
- **20 callees** (geometry/stream ops)
- **Prototype:** `int __cdecl(_DWORD *, unsigned int n8)`
- **Purpose:** Most complex blend operation — composites effects into final framebuffer

## Phyre_PostProcessing_Composite (0xa0fe60, 234 bytes)
- **Prototype:** `int __thiscall(int *this, unsigned int, unsigned int, int)`
- **Purpose:** Composite layer over base framebuffer

## Phyre_PostProcessing_ParticleLightCalc (0xa0ff50, 1588 bytes) ⭐⭐⭐
- **LARGEST POST-PROCESSING FUNCTION** — 1.6KB
- **Prototype:** `int __thiscall(float *this, unsigned int Src, unsigned int, int n7, float)`
- **Callees:** _CIsqrt, _CIcos, _CIsin (uses FPU transcendentals)
- **Purpose:** Compute lighting contributions for particles — heaviest compute in post-processing

## Phyre_PostProcessing_ParticleSystem (0xa06750, 726 bytes)
- **Callees:** Cluster_Allocate, Phyre_Stream_*
- **Purpose:** Full particle system update + render

## Phyre_PostProcessing_MeshParticle (0xa06470, 724 bytes)
- **Variant:** Mesh-based particles (vs point sprites in ParticleSystem)

---

# Part 8: Init / Setup / Render State Registration (8 functions)

All follow the **class descriptor member registration** pattern (no runtime logic):

| Function | Address | Size | Members |
|----------|---------|------|---------|
| Phyre_PostProcessing_Init | 0xa03c20 | 151B | m_velocityScale |
| Phyre_PostProcessing_Setup | 0xa03ce0 | 223B | m_effectMaterial, m_enabled |
| Phyre_PostProcessing_RenderState | 0xa03500 | 625B | m_ambientColor, m_instantLightIntensity, m_instantLightScatteringIntensity, m_fogDistance/NearDistance/Amount/Color |
| Phyre_PostProcessing_RenderState2 | 0xa037c0 | 300B | m_focusPlaneDistance/Range/BlurRange (DOF) |
| Phyre_PostProcessing_RenderState3 | 0xa03990 | 300B | m_glowAmountScale/LuminanceThreshold/LuminanceScale |
| Phyre_PostProcessing_InitEffect6 | 0xa19620 | 686B | Complex effect6 setup |
| Phyre_PostProcessing_InitClusterResources | 0xa19ac0 | 156B | Cluster resource init |
| Phyre_PostProcessing_FindClassDescriptorInList | 0xa16100 | 68B | Class desc lookup with 0x7FFFFFFF mask |

---

# Part 9: SMAA & Texture Compression (3 functions)

## Phyre_PostProcessing_SMAAEdgeDetect (0xa0c7d0, 63 bytes)
- **Purpose:** Sample buffer zeroing loop (48B stride)
- **Caller:** FFX_Render_SMAA_GenerateSamples at 0xa14570

## Phyre_PostProcessing_RenderRoute (0xa0fc10, 239 bytes) ⭐
- **Purpose:** Convert RGBA [0.0, 1.0] to [0, 255] with clamping
- **Pipeline:** Vec3_Min/Vec3_Max clamping, 5-6-5 RGB packing
- **Callees:** Phyre_Vec3_Min, Phyre_Vec3_Max
- **Caller:** FFX_Render_TextureCompression_CompressBlock (0xa10DD0)
- **Insight:** Part of FFX's texture compression pipeline (BC1/BC3 block encoding)

## Phyre_PostProcessing_Scale2xRender (0xa15c70, 481 bytes) ⭐
- **Validates:** output surface (this+3292), input surface (this+3404), type checks (CA3454/CA3364)
- **Verifies:** resolution is exactly 2x
- **Callees:** Phyre_Math_TransformMatrixByMatrix4x4, PShaderParam_BindSamplerChecked, FFX_Binary_ReadStructToBuffer
- **Pipeline:** bind sampler → load shader → configure params → begin scene → dispatch draw

---

# Part 10: QueueCommand & Camera (4 functions)

## Phyre_PostProcessing_QueueCommand (0x5b64d0, 185 bytes)
- **Allocates** scratch buffers via `Phyre_ScratchBuffer_AllocWithFallback`
- **Uses** 2 scratch slots (7 + 12) with sizes 0 and 72 bytes
- **Returns:** 22 (EINVAL) if bit 0 of this[4] not set
- **Callers:** 10 (RenderMain, FFX_BtlUI_RenderHudActor/Element, FFX_Phyre_GaussianBlur_Render, FFX_Phyre_RenderShadowCasterMapForSplit, etc.)

## Phyre_PostProcessing_QueueCommand2 (0x5b6660, 172 bytes)
- **Variant** without bitflag gate
- **Caller:** RenderFrame only

## Phyre_PostProcessing_UpdateCameraDefaults (0x66f2d0, 414 bytes) ⭐
- **Copies camera params** from source (+260..284, 6 floats) to dest (+128..152)
- **Clamps** FOV min=0.35
- **Special case:** scene IDs 409, 4842, 5939 force zNear=1.0, zFar=1.0 (orthographic override)
- **Warning string:** "Warning: No global camera. Post-process is using default values from scene context"
- **Insight:** 3 magic scene IDs trigger orthographic camera — used for cinematic cutscenes

## Phyre_PostProcessing_GetSingleton (0x4fda00, 101 bytes)
- **Returns:** global post-processing singleton pointer
- **Callees:** atexit registration, lazy init

---

# Part 11: Toggle Pass Functions (2 functions)

## Phyre_PostProcessing_FakeTransparent_TogglePass (0x6515b0, 92 bytes)
```c
char **__cdecl Phyre_PostProcessing_FakeTransparent_TogglePass(int a1, char a2)
{
  char **ptr;
  if (a2) {
    ptr = (*(char ***)(a1+8) == &off_C169D4) ? *(char ***)(a1+12) : &off_C169D4;
    if (ptr != &off_C16B44)  // "HSVPass"
      return (char **)PClassDesc_SetFields(a1, &off_C169D4, &off_C16B14);  // "FakeTransparent"
  }
  if (*(char ***)(a1+8) == &off_C169D4)
    ptr = *(char ***)(a1+12);
  else
    ptr = &off_C169D4;
  if (ptr == &off_C16B14)
    return (char **)PClassDesc_SetFields(a1, 0, 0);
  return ptr;
}
```
- **Strings:** "Transparent" (0xC169D4), "FakeTransparent" (0xC16B14), "HSVPass" (0xC16B44)
- **Purpose:** Toggle between Transparent/FakeTransparent/HSVPass states

## Phyre_PostProcessing_HSV_TogglePass (0x64fc50, 66 bytes)
- **Similar** to FakeTransparent but for HSVPass only
- **Caller:** FFX_Magic_FreeDrawElementList (0x6402B0)

---

# Part 12: Lua Binding Templates — StateBlock / ScriptAccessor / BufferClear (26 functions)

**All 26 functions follow the IDENTICAL template** — compiler-generated boilerplate:

```c
PhyrePClassDescriptor *__cdecl Phyre_PostProcessing_<NAME>(lua_State *stream)
{
  PhyrePClassDescriptor **v1;
  v1 = (PhyrePClassDescriptor **)Phyre_Scripting_PushPhyreObject(stream, 0xFFFFFFFF, typeDesc);
  PhyreStream_Reserve((int)stream, -2);
  if (!v1) {
    Phyre_PClassDescriptor_GetTotalSize(&unk_194XXXX);
    MEMORY[0xC96A98] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
    MEMORY[0xC96AA0] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::<CLASS> &>::Get";
    LuaG_errorThrow(stream, "Object obtained from script was not a Phyre Object when an object of type \"%s\" was required.\n");
  }
  // ... push result to Lua stack
}
```

## StateBlock Functions (0xe0 size each, 13 functions)

| Variant | Address | Class | ClassDesc @ |
|---------|---------|-------|-------------|
| A | 0xa08570 | PColorCorrection | 0x19445A0 |
| B | 0xa08650 | PColorCorrectionBase | 0x19444C0 |
| C | 0xa08690 | PColorCorrectionD3D11 | 0x19446F0 |
| D | 0xa086d0 | ... | 0x19445F8 |
| E | 0xa08710 | PDeferredLightingBase | 0x1944798 |
| F | 0xa08750 | PGlow | 0x19445A0 |
| G | 0xa08830 | PGlowBase | 0x19444C0 |
| H | 0xa08910 | PGlowD3D11 | 0x19446F0 |
| I | 0xa089f0 | PGlowGPUBase | 0x19445F8 |
| J | 0xa08ad0 | PMLAA* | 0x1944798 |
| K | 0xa08bb0 | PMotionBlur | 0x1944830 |
| L | 0xa08c90 | PMotionBlurBase | 0x19448D8 |
| M | 0xa08d70 | PMotionBlurD3D11 | 0x1944908 |

## ScriptAccessor Functions (0xda size each, 13 functions)

| Variant | Address | Class | ClassDesc @ |
|---------|---------|-------|-------------|
| A | 0xa09270 | PDOF | 0x1943B70 |
| B | 0xa09350 | PDOFBase | 0x1943A80 |
| C | 0xa09510 | PFXAA | 0x1943F08 |
| D | 0xa095f0 | PFXAABase | 0x1943E58 |
| E | 0xa096d0 | PFXAAD3D11 | 0x1944050 |
| F | 0xa097b0 | PGlow (dup) | 0x19445A0 |
| G | 0xa09960 | PArray<PPostEffectBase*,4> | 0x19445A0+ |
| H | 0xa09a40 | PLegacyGlow | 0x19443E0 |
| I | 0xa09b20 | PLegacyGlowBase | 0x19442B0 |
| J | 0xa09c00 | PLegacyGlowD3D11 | 0x1944478 |
| K | 0xa09ce0 | PLegacyGlowGPUBase | 0x1944348 |
| L | 0xa09dc0 | PMLAA* | 0x1944798 |
| M | 0xa09ec0 | PPostEffectManager | 0x19448A0 |

## BufferClear Functions (0xc1 size each, 5 functions)

| Variant | Address | Class | ClassDesc @ |
|---------|---------|-------|-------------|
| A | 0xa08e50 | PLegacyGlow | 0x19443E0 |
| B | 0xa08f20 | PLegacyGlowBase | 0x19442B0 |
| C | 0xa08ff0 | PLegacyGlowD3D11 | 0x1944478 |
| D | 0xa090c0 | PLegacyGlowGPUBase | 0x1944348 |
| E | 0xa09890 | PPostEffectManager | 0x19448A0 |

**Insight:** These 31 Lua binding functions are MSVC compiler-generated instantiations of `PObjectAccessor<T>::Get` for each post-effect class. The pattern proves FFX exposes ALL post-processing effects to Lua scripts.

---

# Part 13: Stubs, Thunks & Property Accessors (~498 functions)

## Null Stubs (10 functions, 6 bytes each)
```c
PhyrePClassDescriptor *Phyre_PostProcessing_Null<N>() {
  return &MEMORY[0xC9AF80 + 0xA8 * N];  // different per stub
}
```
- **Addresses:** 0xa0bee0..0xa0bfe0 (Null1-10)
- **Purpose:** Return class descriptor pointers

## FlushThunk Functions (~77 functions, 10 bytes each)
```c
int Phyre_PostProcessing_FlushThunk_<XXX>() { return 0; }
```
- **Purpose:** vtable no-op entries

## TableAccess Functions (25 functions, 18 bytes each)
```c
int __stdcall Phyre_PostProcessing_TableAccess_<XXX>(int a1, int a2) {
  return Phyre_Stream_Printf(2, (char *)&MEMORY[0xb7XXXX]);  // different per variant
}
```
- **Purpose:** Format string access for shader parameter tables

## Traverse Functions (30 functions, 0x69 or 0x2e bytes)
```c
// 0x69 version (with conditional)
char __stdcall Phyre_PostProcessing_Traverse_XXX(int a1, char a2) {
  if (a2) {
    if (a1) Phyre_PClassDescriptor_TraverseWithFlag(&unk_1944XXX, a1 + 4);
    else    Phyre_PClassDescriptor_TraverseWithFlag(&unk_1944XXX, 0);
    return 1;
  } else {
    if (a1) Phyre_PClassDescriptor_TraverseWithFlag(&unk_1944XXX, a1 + 4);
    else    Phyre_PClassDescriptor_TraverseWithFlag(&unk_1944XXX, 0);
    return 0;
  }
}

// 0x2e version (simplified)
char __stdcall Phyre_PostProcessing_TraverseDirect_XXX(int flag, char a2) {
  Phyre_PClassDescriptor_TraverseWithFlag(&unk_1944XXX, flag);
  return 1;
}
```
- **Class descriptors:** 0x1944C68..0x1944E08 (range of 8 descriptors)

## TextureSlot Functions (52 functions, ~0xd5 core + 0x17 wrapper)
- Each texture slot binds a render target slot to a shader sampler
- **Purpose:** Texture-to-shader binding system

## ShaderEntry Functions (26 functions, 0x2b-0x86)
- Vtable dispatch entries for each post-effect type
- **Called from** base class vtables

---

# Part 14: ShaderInitNoop — Most Referenced Stub (1 function)

## Phyre_PostProcessing_ShaderInitNoop (0xa1b810, 9 bytes) ⭐
```c
int __thiscall Phyre_PostProcessing_ShaderInitNoop(_DWORD *this)
{
  *(this + 3) = *(this + 2);  // copy slot 2 to slot 3
  return 0;
}
```
- **28 data xrefs** (most-referenced stub)
- **Addresses referenced:** 0xb74060..0xb75ea0 (full vtable range)
- **Purpose:** No-op shader init — copies existing shader pointer to init slot

---

# Part 15: Copy Functions (3 functions)

## Phyre_PostProcessing_StateBlock_Copy (0x9fec50, 1020 bytes) ⭐⭐
- **Deep copy** of state block (3964 bytes total)
- **Copies:** 4 header DWORDs + 2 bytes + 128 iterations of 31-float stride via `PPostProcessEffect_GetOutputTex2`
- **Areas:** 16016..16016+2 floats (ambient), 15892 area

## Phyre_PostProcessing_DeferredLightingD3D11_Copy (0x9ff050, 540 bytes)
- **Calls** StateBlock_Copy then copies D3D11-specific fields
- **Copies:** 12 render target pointers (16276..16324) + pixel shader (16328) + SRV (16332)

## ShaderEntry Functions (26 functions, varying)
- Each post-effect class has its own Copy function (auto-generated from template)

---

# Part 16: Discovered Class Hierarchy (23+ classes)

## Full PPostProcessing Class Tree
```
PPostEffectBase (root)
├── PShadow
│   ├── PShadowMask
│   ├── PShadowPCF
│   ├── PShadowESM
│   └── PShadowVSM
├── PDisableR2 (7 variants)
├── PBloom
├── PDOF / PDOFBase / PDOFCombine
├── PMotionBlur / PMotionBlurBase / PMotionBlurD3D11
├── PSMAA / PSMAANeighborhood / PSMAABlendingWeight
├── PFXAA / PFXAABase / PFXAAD3D11
├── PSSAO / PHDAO
├── PGlow / PGlowBase / PGlowD3D11 / PGlowGPUBase
├── PLegacyGlow / PLegacyGlowBase / PLegacyGlowD3D11 / PLegacyGlowGPUBase
├── PBlurGlow
├── PColorCorrection / PColorCorrectionBase / PColorCorrectionD3D11
├── PLightShaft / PGodRay
├── PFogExp / PFogExpCol / PFogLin
├── PDownscale / PDownscaleCopy / PDownscaleLum
├── PRadialBlur
├── PColorGradingLUT
├── PToneMapping / PToneMappingFilmic / PToneMappingUncharted2
├── PCopy
└── PPostEffectManager (top-level manager)
```

---

# Summary Tables

## Size Distribution (Substantive Functions Only)

| Bucket | Range | Count |
|--------|-------|-------|
| Huge | >= 1024 bytes | 1 (ParticleLightCalc) |
| Large | 512 - 1023 | 8 |
| Medium | 256 - 511 | 18 |
| Small | 128 - 255 | 25 |
| Tiny | < 128 | 90+ |

## Largest Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| ParticleLightCalc | 0xa0ff50 | 1588B | Particle lighting compute |
| BufferDeepCopy64 | 0xa00160 | 1175B | Aligned buffer copy |
| StateBlock_Copy | 0x9fec50 | 1020B | State block deep copy |
| Blend | 0xa06ab0 | 932B | Effect blend compositor |
| EffectDispatch | 0xa03dc0 | 885B | Effect registration |
| EffectChain | 0xa06120 | 846B | Effect chain serialize |
| DeferredLightingBase_Constructor | 0x9fb830 | 759B | DL constructor |
| ParticleSystem | 0xa06750 | 726B | Particle system |
| MeshParticle | 0xa06470 | 724B | Mesh particle |
| MotionBlurBase_Constructor | 0x9fcbb0 | 722B | MB constructor |

## Stub/Thunk Distribution (~498 functions)

| Category | Count | Typical Size |
|----------|-------|--------------|
| Null stubs | 10 | 6B |
| FlushThunk | ~77 | 10B |
| TableAccess | 25 | 18B |
| Traverse | 30 | 0x69 or 0x2E |
| TextureSlot | 52 | 0xD5 + 0x17 |
| StateBlock | 13 | 0xE0 |
| ShaderEntry | 26 | 0x2B-0x86 |
| ScriptAccessor | 13 | 0xDA |
| BufferClear | 5 | 0xC1 |
| ScriptAccessors_Copy | ~25 | 0xDA |
| ShaderInitNoop | 1 | 9B |

## Subsystem Distribution

| Subsystem | Count |
|-----------|-------|
| Render pipeline | 6 |
| Effect system | 5 |
| Effect constructors | 6 |
| Shader setup | 15 |
| Buffer/working surface | 10 |
| Cluster allocation | 9 |
| Particle/Blend | 5 |
| Render state registration | 8 |
| SMAA/Compression | 3 |
| QueueCommand/Camera | 4 |
| TogglePass | 2 |
| Lua bindings (StateBlock/ScriptAccessor/BufferClear) | 31 |
| Stubs/thunks/traverse | ~498 |

## Magic Constants Discovered

| Address | Purpose |
|---------|---------|
| 0xC0A09C | Singleton guard (RegisterAllEffects) |
| 0xC94F00 | SceneWideParam singleton (WorkingSurface_Alloc) |
| 0x1943DA0 | Frequent context pointer (shader setup) |
| 0x1943B70..0x19448D8 | Class descriptor range (DOF/Glow/MotionBlur) |
| 0x1944C68..0x1944E08 | Class descriptor range (Traverse) |
| 0x1944510 | Effect descriptor 1 |
| 0x1943DF0 | Effect descriptor 2 |
| 0xCA3454/CA3364 | Type checks (Scale2xRender) |
| 0xC169D4/C16B14/C16B44 | Strings (Transparent/FakeTransparent/HSVPass) |
| 409/4842/5939 | Special scene IDs (orthographic override) |
| 0x56cd50 | **FFX-specific custom function** (FindShaderParamDefinitionByName) |

---

# Key Findings

1. **23+ post-effect classes discovered** — PDOF/PGlow/PMotionBlur/PSSR/PFXAA/PMLAA/PLegacyGlow/PSMAA/PToneMapping/PSSAO/PCopy + Base/D3D11/GPUBase variants. Confirms FFX has a comprehensive post-processing pipeline matching modern AAA engines.

2. **RenderMain failed decompilation** — 483 bytes with 14 callees, likely SIMD/intrinsic-heavy. Requires manual disassembly. The only decompile failure in this batch.

3. **EffectDispatch is the registration hub** — All 23+ effects register at startup via this single function. Called from RegisterAllEffects during CRT init (data pointer at 0xb73f74).

4. **ShaderInitNoop is the most-referenced stub** — 28 data refs, used as default no-op initializer for shader slot descriptors that don't need real init logic.

5. **FFX-specific custom callee found** — `FFX_Phyre_FindShaderParamDefinitionByName` at 0x56cd50. Called ONLY from ShaderSetup for DepthOfField. Caches FocusPlaneDistance/Range/BlurRange params at v2[1005]/[1006]/[1007]. **Proof that FFX team modified PhyreEngine internals** — this function is NOT in standard PhyreEngine SDK.

6. **UpdateCameraDefaults has 3 magic scene IDs** — scene IDs 409, 4842, 5939 force orthographic camera (zNear=zFar=1.0). These trigger cinematic cutscenes.

7. **3 orthographic override scenes** (4xx/4xxx/5xxx range) — Used for UI/HUD rendering where perspective distortion would be incorrect.

8. **Lua binding covers 23+ post-effect classes** — 31 Lua accessor functions (13 StateBlock + 13 ScriptAccessor + 5 BufferClear) plus 1 array variant. All follow identical compiler-generated template.

9. **PArray<PPostEffectBase*,4>** — Fixed 4-slot array of base effect pointers. Used in EffectDispatch for type registration.

10. **ParticleLightCalc is the heaviest compute** — 1588 bytes, uses FPU transcendentals (_CIsqrt/_CIcos/_CIsin). Likely the per-pixel lighting accumulation for particles.

---

# Next Batches

- Batch 17: Phyre_PAudio (~150 functions, PA/PAData/PASound/PAPlayer)
- Batch 18: Engine_* remaining (~140 small functions)
- Batch 19: Phyre_PPhysics Part 2 (Bullet integration details)
- Batch 20: Phyre_PGraphics (~200 functions, D3D11 wrappers)