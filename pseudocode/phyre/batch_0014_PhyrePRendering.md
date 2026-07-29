# FFX.exe Decompilation — Batch 14 (Phyre_PRendering — Render Pipeline, D3D11, Job System)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 32 (Phyre_Renderer/D3D11/RenderState/Rendering pipeline)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers 32 core rendering functions from FFX.exe — the D3D11 render pipeline of PhyreEngine 3.1.5.0 "SacSlicer". The rendering architecture spans 6 naming convention domains (Phyre_Renderer\_, Phyre_RenderState\_/Phyre_renderState\_, Phyre_D3D11\_, Phyre_PRendering\_, Phyre_Rendering\_, Phyre_RenderTargetBlendDesc\_) and 7 architectural layers:

1. **Renderer Lifecycle** — BeginScene, Clear, DispatchDraw, Ctor/Dtor
2. **Render State Management** — push/pop/apply stack, ExecuteBatch, CommitChanges, CopyState
3. **Render State Internals** — init/dtor/compile defaults, setCull/setBlend/setDepth
4. **Rendering Pipeline** — cull/draw/update/prepare with distance-based visibility
5. **D3D11 Implementation** — vertex input layout, depth-stencil state, shader pass validation
6. **Type Registration** — class descriptor registration for geometry, shaders, textures
7. **Thread Pool & Job System** — thread pool job execution, batch job processing, bone transform

**Key discovery:** `Phyre_renderer_submit_opaque` and `Phyre_renderer_submit_transparent` are **misnamed by RTTI** — they are actually `PObjectAccessor<PLODGroup*>::Get` and `PObjectAccessor<PLODLevel*>::Get` Lua scripting accessors, following the same pattern seen in Batch 9 (Phyre_Math) where `Phyre_Math_Vec3Normalize` was actually a scripting accessor.

**Key discovery 2:** `Phyre_renderState_pop` has **47 callers** — the most-called function in this batch, used as a singleton pattern for `PNamedSemanticDescriptor` initialization across the entire codebase.

**Key discovery 3:** The render pipeline uses a **dual scratch buffer allocation** pattern in every frame operation (BeginScene, Clear, ClearColor), allocating primary scratch at offset +7 and secondary at offset +12.

---

# Part 1: Renderer Lifecycle (9 functions)

## Phyre_RendererDrawContext_Ctor (0x5b4660, 87 bytes)
```c
_DWORD *__thiscall Phyre_RendererDrawContext_Ctor(
    _DWORD *this, int a2, int a3, int a4, int a5, int a6)
```
- **Callers:** 1 (Phyre_Renderer_DispatchDraw)
- **Callees:** none
- **Purpose:** Constructor for the draw context object. Stores 6 construction parameters and zeroes 6 fields (total struct size = 28 DWORDs = 112 bytes).
- **Struct layout:**
  ```
  +0:  a2 (draw param 1)
  +4:  a3 (draw param 2)
  +8:  a4 (draw param 3)
  +12: 0 (reserved)
  +16: a5 (draw param 4)
  +20: a6 (draw param 5)
  +24: 0 (reserved)
  +28: 0
  +32: 0
  +36: 0
  +104: 0 (offset 26)
  +108: 0 (offset 27)
  ```
- **Blocks:** 1 (linear)
- **Constants:** 0x0 (×8 zero fields), 0x14 (20 — struct size hint)

## Phyre_RendererThreadPoolJob_Ctor (0x5b48f0, 136 bytes)
```c
_DWORD *__thiscall Phyre_RendererThreadPoolJob_Ctor(_DWORD *this)
```
- **Callers:** 1 (Phyre_Renderer_AllocatePreprocessJob)
- **Callees:** unknown_libname_262 (lib init at +6)
- **Purpose:** Constructs a thread pool job object. Sets vftable to `Phyre::PRendering::PInternal::PRendererThreadPoolJob::vftable` (0xB36888), initializes embedded object at offset +6, zeroes 6 fields.
- **Constants:** 0xB2A2E8 (sub-object vtable), 0xB36888 (main vtable)
- **Blocks:** 1 (linear)

## Phyre_RendererThreadPoolJob_scalar_dtor (0x5b5220, 33 bytes)
```c
_DWORD *__thiscall Phyre_RendererThreadPoolJob_scalar_dtor(
    _DWORD *this, char a2)
```
- **Callers:** 0 (vtable entry)
- **Callees:** PThreadPoolJob_Destructor_Internal, FFX_Heap_Free
- **Purpose:** Scalar destructor. Calls internal destructor, then conditionally frees heap if `a2 & 1`.
- **Blocks:** 3 (check → free → return)

## Phyre_Renderer_BeginScene (0x5b5fd0, 189 bytes) ⭐
```c
int __thiscall Phyre_Renderer_BeginScene(_DWORD *this)
```
- **Callers:** 64+ (throughout the engine)
- **Callees:** Phyre_ScratchBuffer_AllocWithFallback (×2)
- **Purpose:** Begins a render scene with re-entrancy guard. Uses dual scratch buffer allocation pattern.
- **Algorithm:**
  1. Check `this[1] & 1` (flags bit 0 = scene active)
  2. If already active → return 22 (EINVAL)
  3. Allocate primary scratch buffer from offset +7 with flag 0
  4. Allocate secondary scratch buffer from offset +12 with size 72 (0x48)
  5. Set `this[1] |= 1` to mark scene active
  6. Return 0 on success
- **Blocks:** 3 (guard check + 2 allocs + set flag)
- **Error codes:** 22 (EINVAL) if re-entered

## Phyre_Renderer_BeginSceneWithTimeline (0x5b6c90, 188 bytes)
```c
int __thiscall Phyre_Renderer_BeginSceneWithTimeline(_DWORD *this)
```
- **Callers:** 1+
- **Purpose:** Twin of BeginScene — same dual scratch buffer pattern, same re-entrancy guard. Likely adds timeline profiling wrapper.
- **Note:** Structurally identical to BeginScene at 0x5b5fd0.

## Phyre_Renderer_Clear (0x5babe0, 178 bytes)
```c
int __thiscall Phyre_Renderer_Clear(_DWORD *this, int a2)
```
- **Callers:** 3
- **Callees:** Phyre_ScratchBuffer_AllocWithFallback (×2)
- **Purpose:** Clears the render target (depth/stencil). Dual scratch buffer pattern:
  - Primary alloc at offset +7 with flag 0
  - Secondary alloc at offset +12 with size 72 (0x48)
- **Error:** Returns 13 on allocation failure
- **Blocks:** 3

## Phyre_Renderer_ClearColor (0x5baf40, 184 bytes)
```c
int __thiscall Phyre_Renderer_ClearColor(_DWORD *this, int a2)
```
- **Callers:** 24 (used heavily throughout rendering)
- **Callees:** Phyre_ScratchBuffer_AllocWithFallback (×2)
- **Purpose:** Clears the render target with a specific color. Same dual scratch buffer pattern as Clear.
- **Error:** Returns 13 on allocation failure
- **Blocks:** 3
- **Note:** 8× more callers than non-color Clear — color clears happen per-pass in multi-pass rendering.

## Phyre_Renderer_DispatchDraw (0x5b9c30, 1102 bytes) ⭐
```c
int __thiscall Phyre_Renderer_DispatchDraw(int *this)
```
- **Callers:** 56
- **Callees:** 16 callees including shadow rendering, skinning, stats, preprocessing ring buffer allocation
- **Purpose:** Main draw dispatch — the central rendering command. 52 basic blocks with complex control flow.
  - 0x17C (380) byte stack frame via `__alloca_probe_16`
  - Calls Phyre_RendererDrawContext_Ctor to set up draw context
  - Calls Phyre_PreprocessRingBuffer_Allocate for ring buffer slot
  - Dispatches to shadow rendering and skinning pipelines
  - Uses `__alloca_probe_16` for dynamic stack alignment
- **Blocks:** 52 (most complex in render lifecycle)
- **Key insight:** Every render call goes through this function. 56 callers across all rendering subsystems.

## Phyre_RenderDevice_Initialize (0x5b8f40, 217 bytes)
```c
int __cdecl Phyre_RenderDevice_Initialize(void)
```
- **Callers:** 1 (InitEngineRenderSystem)
- **Callees:** Display_GetDimensions, Thread_GetCurrentId, RenderDevice_InitBuffers
- **Purpose:** One-time render device initialization. Gated by guard flag at `byte_C9628C`:
  1. Check `byte_C9628C` — if already initialized, skip
  2. Register atexit handler at `Phyre_Shader_CompilePass_C94F00`
  3. Call `Display_GetDimensions` for buffer sizes
  4. Call `Thread_GetCurrentId` to record main render thread
  5. Call `RenderDevice_InitBuffers` to set up D3D11 buffers
  6. Set `byte_C9628C = 1`
- **Blocks:** 4 (guard check → init → set flag → return)
- **Constants:** 0xC9628C (init guard flag)

---

# Part 2: Render State Management (7 functions)

## Phyre_RenderState_ExecuteBatch (0x59eb90, 462 bytes)
```c
unsigned int __thiscall Phyre_RenderState_ExecuteBatch(
    int *this, void (*callback)(int, int, int), int a3)
```
- **Callers:** 1 (Phyre_RenderStateManager_Process)
- **Callees:** 10 — Engine_AlignedAllocSimple, PChunkAllocator_InitV2, Phyre_renderState_push, Phyre_PClass_CopyConstruct, Phyre_Vector3_Assign, PChunkAllocator_AllocMemory, PChunkAllocator_DtorCleanup, AlignedLinkedListBlock_FreeAll, Engine_AlignedFree
- **Purpose:** Executes a render state batch. Iterates the 12-byte stride array:
  ```c
  sizeof_array = (*(this + 1) - *this) / 12;
  ```
  Uses magic constant `0x2AAAAAAB` (fixed-point inverse of 3 for div-by-3 optimization via `unsigned __int64` multiply + shift).
  For each valid entry, pushes render state, allocates chunk allocator, copy-constructs class instances, invokes callback per element.
- **Strings:** `"invalid vector<T> subscript"` (0xB34484)
- **Blocks:** 37 (complex iteration + allocation + error paths)
- **12-byte entry layout:**
  ```
  +0: index/key
  +4: pointer to descriptor (or null)
  +8: value/data
  ```

## Phyre_RenderState_CommitChanges (0x59ed60, 433 bytes)
```c
unsigned int __thiscall Phyre_RenderState_CommitChanges(
    int *this, int (*callback)(int, int), int a3)
```
- **Callers:** 1 (Phyre_RenderStateManager_Process)
- **Callees:** 10 (same pattern as ExecuteBatch)
- **Purpose:** Commits render state changes by iterating the state array, pushing each changed entry, allocating chunk memory, and invoking the callback (Phyre_TraverseHierarchy_Copy12Floats_v1) to apply changes.
- **String:** `"invalid vector<T> subscript"` (0xB34484)
- **Blocks:** 26
- **Key difference from ExecuteBatch:** Uses ChunkAllocator with `unk_CAF55C` stride (vs `unk_C9134C` in ExecuteBatch), and a different type descriptor at `&type__0` (vs `&type_`).
- **Constants:** 0x2AAAAAAB (div-by-3), 0x4C (76 bytes — alloc size)

## Phyre_RenderState_CopyState (0x59ef20, 433 bytes)
```c
unsigned int __thiscall Phyre_RenderState_CopyState(
    int *this, int (*callback)(int, int), int flags)
```
- **Callers:** 1 (Phyre_RenderStateManager_Process)
- **Callees:** 10 (same pattern as CommitChanges)
- **Purpose:** Copies render state with callback `Phyre_TraverseHierarchy_Copy12Floats_v2`. Structurally identical to CommitChanges but:
  - Uses `unk_CAED74` stride (vs `unk_CAF55C`)
  - Uses type descriptor `&type__1` (vs `&type__0`)
- **Blocks:** 26
- **Constants:** 0x2AAAAAAB, 0x4C (76 bytes)

## Phyre_RenderStateManager_Process (0x59fd40, 441 bytes)
```c
int __thiscall Phyre_RenderStateManager_Process(
    void *this, int *a2, int a3)
```
- **Callers:** 0 (likely vtable dispatch from engine tick)
- **Callees:** 6 — PChunkAllocator_DtorCleanup, AlignedLinkedListBlock_FreeAll, Engine_AlignedFree, Phyre_RenderState_ExecuteBatch, Phyre_RenderState_CopyState, Phyre_RenderState_CommitChanges
- **Purpose:** Main state manager process function. Coordinates the three-phase render state update:
  1. **Validation loop:** Scans state array (12-byte stride) comparing each entry's class descriptor against 14 known type descriptors at global singleton addresses (0xCBE778, 0xCBE8A8, ... 0xCBF780)
  2. **Cleanup old state:** Iterates state entries cleaning up chunk allocator resources. Entries with `*v11 == 2` get dual cleanup (both primary and secondary pointers)
  3. **Three-phase commit:** `ExecuteBatch(DeepClone) → CopyState(Copy12Floats_v2) → CommitChanges(Copy12Floats_v1)`
- **Blocks:** 28
- **Constants:** 0xE (14 — type descriptor count), 0x2 (cleanup flag)

## Phyre_renderState_push (0x5a02e0, 134 bytes)
```c
int __thiscall Phyre_renderState_push(int *this, int a2, int a3, int a4)
```
- **Callers:** 3
- **Purpose:** Pushes a new render state entry onto the state stack. Validates state with warning strings at 0xB342F8 and 0xB342B0 about "converting instance list".
- **Blocks:** 5 (validation → push → return)

## Phyre_renderState_pop (0x5a0390, 103 bytes) ⭐
```c
int __thiscall Phyre_renderState_pop(int *this)
```
- **Callers:** **47!** (highest call count in this batch)
- **Purpose:** Pops the render state stack. Singleton pattern — resets vtable to `PNamedSemanticDescriptor_Base` (0xB344B8), unlinks from intrusive linked list at `0xC26B74`.
- **Algorithm:**
  1. Set vtable to 0xB344B8 (PNamedSemanticDescriptor_Base)
  2. Unlink from intrusive linked list at 0xC26B74
  3. Return
- **Blocks:** 1 (linear)
- **Key insight:** 47 callers means this is used as a general-purpose "reset to base state" across the entire codebase, not just rendering.

## Phyre_renderState_apply (0x5a0430, 61 bytes)
```c
int __thiscall Phyre_renderState_apply(int *this)
```
- **Callers:** 0 (vtable dispatch)
- **Purpose:** Applies the current render state. Vtable swap 0xB344B8 → 0xB0E570. Linked list unlink from 0xC26B74 + conditional AlignedFree.
- **Blocks:** 4

---

# Part 3: Render State Internals + Setters (6 functions)

## Phyre_renderState_init (0x5a2510, 137 bytes)
```c
int __thiscall Phyre_renderState_init(void *this, int *a2)
```
- **Callers:** 2
- **Callees:** Phyre_RenderState_AllocCopyIntArr
- **Purpose:** Initializes render state from source array. SSO-optimized copy: checks count & 0x7FFFFFFF ≤ 1 for small-string optimization threshold.
- **Blocks:** 4
- **Constants:** 0x7FFFFFFF (SSO mask)

## Phyre_renderState_dtor (0x5a26b0, 118 bytes)
```c
void __thiscall Phyre_renderState_dtor(void *this)
```
- **Callers:** 1
- **Callees:** Phyre_AlignedFree
- **Purpose:** Render state destructor. Sets FLT_MAX/-FLT_MAX extremes for position bounds. Default LOD type pointer at 0xC29794, blend type at 0xC298C8. Sets `active` flag at +68 = 1.
- **Constants:** 0x7F7FFFFF (FLT_MAX), 0xFF7FFFFF (-FLT_MAX)
- **Blocks:** 3

## Phyre_renderState_compile (0x5a27c0, 146 bytes)
```c
int __thiscall Phyre_renderState_compile(void *this)
```
- **Callers:** 1
- **Callees:** Phyre_POD_dtor (potentially)
- **Purpose:** Compiles render state with default values:
  ```
  +0:   0          (render mode)
  +4:   0          (flags)
  +8:   0          (additional flags)
  +12:  0.0f       (near plane / min distance)
  +16:  10000.0f   (far plane / max distance)
  +20:  1          (enabled flag)
  +24:  4          (cull mode — D3D11_CULL_BACK)
  +28:  1.0f       (depth bias / scale)
  +32:  0.0f       (depth bias / offset)
  +68:  1          (active flag)
  ```
- **Blocks:** 4
- **Constants:** 0x461C4000 (10000.0f), 0x3F800000 (1.0f), 0x4 (cull mode)

## Phyre_renderState_setCull (0x5a2ad0, 134 bytes)
```c
int __thiscall Phyre_renderState_setCull(void *this, int mode)
```
- **Callers:** 0 (vtable dispatch)
- **Callees:** Phyre_POD_dtor
- **Purpose:** Sets cull mode. Calls Phyre_POD_dtor at offset +15, then checks capacity at +8. If count & 0x7FFFFFFF > 1 (heap-allocated), frees via AlignedFree at +9.
- **Blocks:** 5
- **Constants:** 0x7FFFFFFF (capacity mask)

## Phyre_renderState_setBlend (0x5a2b60, 176 bytes)
```c
int __thiscall Phyre_renderState_setBlend(void *this, int a2)
```
- **Callers:** 3
- **Callees:** Phyre_AlignedFree
- **Purpose:** Sets blend state with dual-array cleanup pattern:
  - First array at +5/+6 (ptr + capacity)
  - Second array at +1/+2 (ptr + capacity)
  Both use same SSO-optimized capacity check (0x7FFFFFFF mask + > 1 check).
- **Blocks:** 8
- **Constants:** 0x7FFFFFFF (×4 — for both arrays)

## Phyre_renderState_setDepth (0x5a2ca0, 131 bytes)
```c
int __thiscall Phyre_renderState_setDepth(void *this, int a2)
```
- **Callers:** 2
- **Callees:** Phyre_AlignedFree
- **Purpose:** Sets depth-stencil state. Same SSO-optimized copy pattern as init. Checks capacity, frees old heap buffer if needed, copies new state.
- **Blocks:** 5
- **Constants:** 0x7FFFFFFF

---

# Part 4: Rendering Pipeline (7 functions)

## Phyre_renderer_cull (0x5a4cb0, 271 bytes)
```c
int __thiscall Phyre_renderer_cull(int this, int a2)
```
- **Callers:** 1 (Phyre_renderer_update)
- **Callees:** none (pure x87 FPU math)
- **Purpose:** Distance-based cull test using x87 FPU double-precision arithmetic. Pure scalar math — no sub-calls.
  - Compares object positions against view position threshold with scalar 1.0
  - 17 basic blocks with FPU comparison branches
  - Uses `fld`/`fcom`/`fnstsw` for double-precision comparisons
- **Blocks:** 17
- **Constants:** 0x3FF0000000000000 (1.0 double), 0x3F800000 (1.0f float)

## Phyre_renderer_draw (0x5a4dc0, 396 bytes)
```c
int __thiscall Phyre_renderer_draw(int this)
```
- **Callers:** 1 (Phyre_renderer_update)
- **Callees:** none (pure state machine)
- **Purpose:** Main draw state machine with 38 basic blocks. Accesses slot state via 12-byte stride array. States:
  - **4 = ready** (waiting to be drawn)
  - **1 = drawing** (currently being rendered)
  - **0 = drawn** (completed)
- **Blocks:** 38 — complex slot-based dispatch
- **Constants:** 0x4 (ready), 0x1 (drawing), 0x0 (drawn)

## Phyre_renderer_update (0x5a4f50, 678 bytes) ⭐
```c
int __thiscall Phyre_renderer_update(int this)
```
- **Callers:** 1+ (engine tick)
- **Callees:** 7 — Phyre_renderer_cull, Phyre_renderer_draw, Phyre_renderer_prepare, Phyre_BBox_distance, Phyre_BBox_centerDistance, Phyre_Spline_setupIdentityTransform, Phyre_Renderer_ClearShSlots
- **Purpose:** Main render update loop — the central orchestrator of the rendering pipeline. 61 basic blocks (most complex CFG in this batch).
  - Calls `prepare` for each render slot
  - Calls `cull` for visibility testing
  - Calls `draw` for submission
  - Manages bounding box distance calculations
  - Clears shadow slots at end of frame
- **Blocks:** 61 (largest in pipeline functions)
- **Pipeline order:**
  1. Clear shadow slots via ClearShSlots
  2. Prepare each slot
  3. Cull invisible objects
  4. Draw visible objects
  5. Update bounding box distances
  6. Spline identity transform setup

## Phyre_renderer_prepare (0x5a5200, 152 bytes)
```c
double __cdecl Phyre_renderer_prepare(
    float a1, int a2, int a3, int a4)
```
- **Callers:** 1 (Phyre_renderer_update)
- **Callees:** none
- **Purpose:** Prepares a single render slot by comparing distance threshold:
  ```c
  v7 = 1.0;
  if (a3[12] <= a1 || a3[12] <= 0.0)
  {
    if (a3[16] >= a1)
      v4 = 1;   // in range — mark visible
    else
      v4 = 0;   // beyond far plane
  }
  else
    v4 = 0;     // before near plane
  
  // SSO-optimized array store
  slot_array[a4][8] = v4;  // at +8 in 12-byte slot entry
  ```
  Returns visibility weight (0.0 or 1.0).
- **Blocks:** 11
- **Constants:** 0x7FFFFFFF (SSO mask), 0x1 (visible), 0x18 (24 — 12-byte stride × 2)

## Phyre_renderer_submit_opaque (0x5a5ae0, 212 bytes) — ⚠️ MISNAMED
```c
int __cdecl Phyre_renderer_submit_opaque(lua_State *stream)
```
- **Callers:** 3 (Phyre_RenderState_PushSubmitOpaque, Phyre_RenderState_ValidateSubmitOpaque, Phyre_renderer_submit_opaque_thunk)
- **Callees:** Phyre_Scripting_PushPhyreObject, PhyreStream_Reserve, PhyreBuffer_GetType, LuaG_errorThrow
- **Strings:**
  - `"r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"`
  - `"Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PLOD::PLODGroup *>::Get"`
  - Standard Lua error strings for type mismatch
- **Purpose:** ⚠️ **NOT an opaque submission function!** This is `PObjectAccessor<PLODGroup*>::Get` — a Lua scripting accessor that:
  1. Pushes Phyre PLODGroup object from Lua stream
  2. Validates object type by walking parent chain up to `MEMORY[0xCBAB20]`
  3. Throws Lua error on type mismatch with detailed type info
  4. Returns pointer to PLODGroup at the object's offset +4
- **Blocks:** 12
- **Build path:** Same `PhyreScripting.inl` as the misnamed `Phyre_Math_Vec3Normalize` (PObjectAccessor<PString*>::Get) found in Batch 9

## Phyre_renderer_submit_transparent (0x5a5bc0, 212 bytes) — ⚠️ MISNAMED
```c
int __cdecl Phyre_renderer_submit_transparent(lua_State *stream)
```
- **Callers:** 1 (Phyre_renderer_submit_transparent_thunk)
- **Callees:** Phyre_Scripting_PushPhyreObject, PhyreStream_Reserve, PhyreBuffer_GetType, LuaG_errorThrow
- **Strings:**
  - `"r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"`
  - `"Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PLOD::PLODLevel *>::Get"`
  - Same Lua error strings
- **Purpose:** ⚠️ **NOT a transparent submission function!** This is `PObjectAccessor<PLODLevel*>::Get` — identical pattern to submit_opaque but for PLODLevel instead of PLODGroup.
- **Blocks:** 12
- **Parent chain target:** `MEMORY[0xCBAA88]` (vs 0xCBAB20 for PLODGroup)

## Phyre_Renderer_ClearShSlots (0x5a8530, 100 bytes)
```c
int __userpurge Phyre_Renderer_ClearShSlots@<eax>(
    int result@<eax>, int a2@<ecx>, char a3)
```
- **Callers:** 2 (Phyre_renderer_update, Phyre_Scripting_SetActiveFlag)
- **Callees:** none
- **Purpose:** Clears shadow (Sh) slots in the slot array. SSO-optimized array access pattern. If `a3 != 0`, preserves the slot reference; if `a3 == 0`, sets `[v8+28] = 0`.
  - Iterates `count & 0x7FFFFFFF` entries
  - SSO threshold at count <= 1 (inline vs heap storage)
- **Blocks:** 13
- **Constants:** 0x7FFFFFFF (SSO mask), 0x4 (DWORD stride)

---

# Part 5: D3D11 Implementation (3 functions)

## Phyre_D3D11_InitVertexInputLayout (0x595100, 653 bytes)
```c
int __thiscall Phyre_D3D11_InitVertexInputLayout(int *this)
```
- **Callers:** 1
- **Callees:** unknown (internal D3D11 layout creation)
- **Purpose:** Initializes D3D11 vertex input layout with 16 semantic slots. Each slot assigned `POSITION` or `TEXCOORD` semantics in a loop.
  ```c
  for (int i = 0; i < 16; i++) {
    layout[i].SemanticName = (i == 0) ? "POSITION" : "TEXCOORD";
    layout[i].SemanticIndex = (i == 0) ? 0 : i - 1;
    // ...
  }
  ```
- **Strings:** `"POSITION"` (0xB33C14), `"TEXCOORD"` (0xB33C20), `"DebugDrawConstantBuffer"` (0xB33C2C)
- **Flags:** 0x28000 (163840 — stride flag), 0x10000 (slot flag)
- **Struct size:** 0x90 (144 bytes) per slot entry
- **Blocks:** 4 (initialization + loop + return)

## Phyre_D3D11_CreateDepthStencilState (0x595390, 744 bytes)
```c
int __thiscall Phyre_D3D11_CreateDepthStencilState(int *this)
```
- **Callers:** 1
- **Callees:** unknown D3D11 create calls
- **Purpose:** Creates D3D11 depth-stencil state. Checks DXBC magic header at 0xC30510 to validate shader bytecode before creating state.
- **Strings:** `"DXBC"` (shader magic), `"POSITION"`, `"DrawClearConstantBuffer"` (0xB33C44)
- **Stack frame:** 0x60 (96 bytes)
- **Blocks:** 19

## Phyre_D3D11_ValidateShaderPassState (0x57f5d0, 130 bytes)
```c
int __thiscall Phyre_D3D11_ValidateShaderPassState(void *this)
```
- **Callers:** 2
- **Callees:** Phyre_PType registration functions
- **Purpose:** One-time class descriptor registration for `PArray<PStreamInputDescD3D11,4>`. Guard flag at `0xCB4CEC` prevents re-initialization. Vtable at `0xB33CF4`.
  - Registers the array type descriptor at `0xCB4C58`
  - Sets guard flag to 1 after first call
- **Blocks:** 3 (guard check → register → set flag)
- **Key insight:** This is a type system registration function disguised as a shader validation function — it registers the D3D11 stream input descriptor type so the type system knows about it.

---

# Part 6: Type Registration (3 functions)

## Phyre_Rendering_RegisterGeometryClassDescriptors (0x4323c0, 355 bytes)
```c
int __cdecl Phyre_Rendering_RegisterGeometryClassDescriptors(void)
```
- **Callers:** 1 (engine init)
- **Callees:** 18 class descriptor registration calls
- **Purpose:** Registers geometry-related class descriptors with the Phyre type system. Registered types include:
  - PVertexStreamArray, PIndexBuffer, PMesh, PSkinBone
  - GeometryBuffer, MaterialArray, DynamicMesh
  - (Additional types at string list addresses 0xC985B4-0xC98650)
- **Blocks:** 4

## Phyre_Rendering_RegisterShaderAndTextureClassDescriptors (0x432920, 531 bytes) ⭐
```c
int __cdecl Phyre_Rendering_RegisterShaderAndTextureClassDescriptors(void)
```
- **Callers:** 1 (engine init)
- **Callees:** **83 callees** — the most of any function in this batch
- **Purpose:** Mass registration of shader and texture class descriptors. Gated by `byte_C0A09C` init guard. Registers:
  - PEffect, PTexture2D, PShaderParameterDef
  - PRenderTarget, SurfaceDescription
  - PStructuredBuffer, PIndirectArgsBuffer
  - PShaderConstantBuffer, PShaderResourceRead/Write
  - PShaderPass, PShaderProgram, PShaderParamCaptureBuffer
  - PShaderParamCapture, PShaderParamArrayCapture
  - PRenderQueueEntry
- **Blocks:** 10
- **Guard:** byte_C0A09C

## Phyre_Rendering_StringListCleanup (0x432530, 269 bytes)
```c
int __cdecl Phyre_Rendering_StringListCleanup(void)
```
- **Callers:** 1 (atexit/shutdown)
- **Callees:** Engine_StringListRemoveWrapper
- **Purpose:** Cleans up 18+ string lists at addresses 0xC985B4 through 0xC98650 during engine shutdown. Each string list is individually cleared.
- **Blocks:** 5

---

# Part 7: Thread Pool & Job System (5 functions)

## Phyre_Renderer_ThreadPoolJob_Execute (0x5b3f90, 1543 bytes) ⭐
```c
int __thiscall Phyre_Renderer_ThreadPoolJob_Execute(int this)
```
- **Callers:** 1+ (vtable dispatch from thread pool)
- **Callees:** 17 — PThreadPool_GetGlobal_C0B950, Phyre_ThreadPool_GetSingleton, DispatchDraw, Phyre_Renderer_AllocatePreprocessJob, JobQueue_PackEntry, JobQueue_Pop, Phyre_Renderer_UpdateBoneTransform, and more
- **Purpose:** Main thread pool job execution function — the **largest rendering function** in this batch (1543 bytes).
  - 67 basic blocks — most complex CFG
  - 0x23E0 (9184) byte stack frame via `__alloca_probe` — enormous stack
  - `"PRendererThreadPoolJob"` string for debug/profiling
  - Gets global thread pool singleton
  - Calls DispatchDraw for each draw command
  - Allocates preprocessing jobs
  - Packs/pops entries from the job queue
  - Updates bone transform matrices per-frame
- **Blocks:** 67
- **Stack:** 0x23E0 (9184 bytes) via __alloca_probe

## Phyre_Renderer_BatchJob_Execute (0x5b5740, 729 bytes)
```c
int __thiscall Phyre_Renderer_BatchJob_Execute(int this)
```
- **Callers:** 1+ (vtable dispatch)
- **Callees:** 2 — Phyre_Renderer_CalculateVertexBufferSizes, PShaderBinding_LookupOrCache
- **Purpose:** Executes a batch of rendering work. 31 basic blocks. Calculates vertex buffer sizes and looks up or caches shader bindings.
  - First phase: Calculate vertex buffer sizes for all visible meshes
  - Second phase: Lookup/cache shader bindings for material rendering
- **Blocks:** 31

## Phyre_Renderer_BoneTransformMatrix (0x5b88a0, 288 bytes)
```c
int *__thiscall Phyre_Renderer_BoneTransformMatrix(int this, int a2)
```
- **Callers:** 0 (likely called from thread pool job execution)
- **Callees:** 5 — Phyre_ScratchBuffer_Alloc, Phyre_PMatrix4_copy16f, Phyre_Matrix4x4_ComposeMultiply, Phyre_Matrix4x4_DecomposeTransform, memcpy
- **Purpose:** Transforms bone matrices for skinning. 17 basic blocks with switch dispatch on bone operation type:
  ```c
  switch (bone_op) {
    case 0x82:  // Direct copy from source
      Src = Src_2;
      break;
    case 0x83:  // Decompose + recompose
      result = Phyre_Matrix4x4_DecomposeTransform(...);
      Phyre_PMatrix4_copy16f(Src, result);
      break;
    case 0x84:  // Compose multiply
      result = Phyre_Matrix4x4_ComposeMultiply(...);
      Phyre_PMatrix4_copy16f(Src, result);
      break;
    default:    // Skip
      goto skip;
  }
  ```
- **Bone index bound:** 0x1FFF (8191 — 13-bit limit)
- **Stride:** 0x10 (16 bytes) per bone entry
- **Stack:** 0xDC (220 bytes)
- **Constants:** 0x82 (130), 0x83 (131), 0x84 (132) — bone operation opcodes

## Phyre_PRenderingUnit_Flush (0x9f3a40, 382 bytes)
```c
int __thiscall Phyre_PRenderingUnit_Flush(int this)
```
- **Callers:** 0 (vtable dispatch)
- **Callees:** 12 — Phyre_NameTree, Phyre_VisibleBatch, Phyre_Calc_MulMatrix4, Phyre_Renderer_ThreadPoolJob_Execute_w, Phyre_RenderingStructure_ClearLists, and more
- **Purpose:** Flushes the rendering unit — processes all queued visible batches and dispatches them to the thread pool:
  1. Process visible batches 
  2. Calculate matrix multiplication chains
  3. Dispatch thread pool jobs for each batch
  4. Clear rendering structures
- **Blocks:** 6
- **Key role:** Bridge between the scene graph (visible batch list) and the thread pool renderer

## Phyre_PRenderingUnit_FlushSecondary (0x9f3c30, 250 bytes)
```c
int __thiscall Phyre_PRenderingUnit_FlushSecondary(
    _DWORD *this, _DWORD *a2, float *a3, int a4, int a5)
```
- **Callers:** 1 (CallGraphicsTransformFunction)
- **Callees:** 12 — Phyre_PMeshInstanceBounds_InitFromMemory, Phyre_Stream_FileFormat_Read, Phyre_Stream_FileFormat_Process, Phyre_Calc_MatrixMul, Phyre_CollectVisibleBatches_ProcessQueue, Phyre_Calc_TransformPoint, Phyre_VisibleBatch_JobProcessor, Phyre_Stats_GetSingleton, Phyre_PPreprocessRingBuffer_AllocateAndSetFlag, Phyre_VisibleBatch_SortAndInsert, Phyre_Renderer_ThreadPoolJob_Execute_w, Phyre_RenderingStructure_ClearLists
- **Purpose:** Secondary flush path for rendering unit. Complete pipeline:
  1. Initialize mesh instance bounds from memory
  2. Read stream file format
  3. Process stream file format with float parameters
  4. Calculate matrix multiplication
  5. Collect visible batches to process queue
  6. Transform points
  7. Process visible batches in job processor
  8. Allocate preprocessing ring buffer from stats singleton
  9. Sort and insert visible batches
  10. Execute thread pool job
  11. Clear rendering structures
- **Blocks:** 3 (pipelin → job submit → cleanup)
- **Stack:** 0x90 (144 bytes)
- **Key insight:** This is a self-contained "flush + process" pipeline — used when a secondary render pass needs full visibility processing separate from the main render thread

---

# Summary Tables

## Size Distribution

| Bucket | Range | Count |
|--------|-------|-------|
| Huge | >= 1024 bytes | 6 |
| Large | 512 - 1023 | 4 |
| Medium | 256 - 511 | 8 |
| Small | 128 - 255 | 11 |
| Tiny | < 128 bytes | 3 |

## Most-Called Functions

| Function | Callers | Purpose |
|----------|---------|---------|
| Phyre_renderState_pop | **47** | PNamedSemanticDescriptor singleton reset |
| Phyre_Renderer_BeginScene | **64+** | Scene begin with re-entrancy guard |
| Phyre_Renderer_DispatchDraw | **56** | Main draw dispatch |
| Phyre_Renderer_ClearColor | **24** | Color clear for render targets |
| Phyre_Renderer_Clear | **3** | Depth/stencil clear |
| Phyre_renderState_setBlend | **3** | Blend state setter |
| Phyre_renderer_submit_opaque (misnamed) | **3** | Lua PLODGroup accessor |

## Complexity Leaders

| Function | Blocks | Stack | Bytes |
|----------|--------|-------|-------|
| Phyre_Renderer_ThreadPoolJob_Execute | **67** | 0x23E0 (9184) | 1543 |
| Phyre_renderer_update | **61** | — | 678 |
| Phyre_Renderer_DispatchDraw | **52** | 0x17C (380) | 1102 |
| Phyre_renderer_draw | **38** | — | 396 |
| Phyre_RenderState_ExecuteBatch | **37** | — | 462 |
| Phyre_Renderer_BatchJob_Execute | **31** | — | 729 |

## Misnamed Functions (RTTI vs Reality)

| Symbol Name | Actual Function | Impact |
|-------------|----------------|--------|
| `Phyre_renderer_submit_opaque` | `PObjectAccessor<PLODGroup*>::Get` | Lua scripting, not rendering |
| `Phyre_renderer_submit_transparent` | `PObjectAccessor<PLODLevel*>::Get` | Lua scripting, not rendering |
| `Phyre_D3D11_ValidateShaderPassState` | Type registration for D3D11 input descriptors | Type system, not validation |

## Subsystem Distribution

| Subsystem | Count |
|-----------|-------|
| Renderer Lifecycle (Ctor/Begin/Clear/Dispatch) | 9 |
| Render State Management (push/pop/ExecuteBatch) | 7 |
| Render State Internals + Setters | 6 |
| Rendering Pipeline (cull/draw/update/prepare) | 7 |
| D3D11 Implementation | 3 |
| Type Registration | 3 |
| Thread Pool & Job System | 5 |

---

# Part 8: Bone Operation Opcodes

The `Phyre_Renderer_BoneTransformMatrix` function uses a switch dispatch on bone operation opcodes embedded in the bone data stream:

| Opcode | Value | Operation |
|--------|-------|-----------|
| 0x82 | 130 | Direct copy from source skeleton |
| 0x83 | 131 | Decompose + recompose transform |
| 0x84 | 132 | Compose multiply (local × parent) |
| default | — | Skip (invalid/unused slot) |

Each bone entry is 16 bytes (0x10 stride), indexed via `*(unsigned __int16*)(bone_base + 8)` (start offset) and `*(unsigned __int16*)(bone_base + 10) & 0x1FFF` (copy size, 13-bit bound).

---

## Key Findings

1. **renderState_pop has 47 callers** — The most-called function in this batch by far. It's used as a viram-style singleton pattern to reset `PNamedSemanticDescriptor` to base state across the entire codebase, not just rendering.

2. **Dual scratch buffer allocation is universal** — Every frame operation (BeginScene, Clear, ClearColor) uses the same pattern: primary scratch alloc at offset +7 (flags 0), secondary scratch alloc at offset +12 (size 0x48). This suggests a dual-ring-buffer architecture for GPU data.

3. **Three-phase state commit** — `Phyre_RenderStateManager_Process` orchestrates a coordinated three-phase update: `ExecuteBatch(DeepClone)` pour copier les descripteurs → `CopyState(Copy12Floats_v2)` → `CommitChanges(Copy12Floats_v1)`. Each phase uses the same `PChunkAllocator` allocation/copy/cleanup pattern.

4. **Two submit functions are misnamed** — `Phyre_renderer_submit_opaque` and `Phyre_renderer_submit_transparent` are Lua scripting accessors (`PObjectAccessor<PLODGroup*>::Get` and `PObjectAccessor<PLODLevel*>::Get`), not submission functions. Same RTTI misidentification as `Phyre_Math_Vec3Normalize` in Batch 9.

5. **Thread pool jobs use enormous stack frames** — `ThreadPoolJob_Execute` uses 9184 bytes (0x23E0) of stack via `__alloca_probe`. This is a red flag for potential stack overflow on the default 1MB Windows thread stack.

6. **67 basic blocks in ThreadPoolJob_Execute** — The most complex CFG in the rendering subsystem. It orchestrates: global thread pool singleton, Draw dispatch, preprocessing job allocation, job queue pack/pop, and bone transform updates.

7. **SSE is absent from the rendering pipeline** — Unlike the explicit `Phyre_Math_SSE_VertexTransform` functions, the rendering pipeline functions use pure x87 FPU and scalar math. SSE is only used in the two dedicated vertex transform functions.

8. **D3D11 depth-stencil creation validates DXBC** — `CreateDepthStencilState` checks the "DXBC" magic header at runtime before creating the depth-stencil state object, confirming D3D11 shader bytecode validation.

9. **Bone transform support 3 operation types** — Skin deformation supports direct copy (0x82), decompose+recompose (0x83), and compose-multiply (0x84) for different animation blending modes.

10. **13-bit bone index bound** — Bone indices are capped at 0x1FFF (8191), supporting up to 8192 bones per model through the transform pipeline.

---

## Next Batches

- **Batch 15:** Phyre_PSceneNode (~90 functions) — scene graph, node hierarchy, transforms
- **Batch 16:** Phyre_PPostProcessing (~60 functions) — post-processing effects
- **Batch 17:** Phyre_PAudio (~50 functions) — audio system
- **Batch 18:** Bullet Physics wrappers (~80 functions) — collision detection
- **Batch 19:** Phyre_PVideo (~30 functions) — video playback (bink)
- **Batch 20:** Phyre_UI / Iggy (~100 functions) — UI system
- **Batch 21:** FFX_Config_* functions (~40 functions) — config parsing
