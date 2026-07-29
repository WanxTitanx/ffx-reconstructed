# FFX.exe Decompilation — Batch 15 (Phyre_PSceneNode / Phyre_SceneNode / Phyre_PNode)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 126 (88 PSceneNode + 18 SceneNode + 20 PNode)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the **PhyreEngine scene graph** — 126 functions forming the node hierarchy system of FFX.exe. The scene graph manages parent-child transform composition, world matrix computation, visibility propagation, LOD selection, bounding volumes, and the render-node association.

**Three naming prefixes** reflect the C++ class hierarchy:
- `Phyre_PNode_*` (19 functions) — base class (84 bytes, 4-byte alignment), vftable at `0xB24CE4`. Provides `SupportsType_RetTrue` family and descriptor accessors.
- `Phyre_PSceneNode_*` (88 functions) — intermediate layer. Scene graph member: transform matrices at +12/+28, child management, LOD, bounding boxes, visibility.
- `Phyre_SceneNode_*` (18 functions) — concrete scene node (runtime). Update pipeline, render children dispatch, physics integration, time accumulator.

**Key discovery:** The Notify/Propagate family (5 functions) are **near-duplicates** — identical CFG skeleton differing only by which `SetLocal*` call they make (SetLocalPosition vs SetLocalRotation). Several `PSceneNode_*` functions are actually **Lua scripting accessors** (FindChild, GetChildCount, GetBoundingBox), following the misnaming pattern observed in Batches 9 and 14.

---

# Part 1: PSceneNode Core Operations (5 largest functions)

## Phyre_PSceneNode_Copy (0x453490, 564 bytes) ⭐
```c
float *__thiscall Phyre_PSceneNode_Copy(float *this, float *a2)
{
  *this = *a2;  *(this + 1) = a2[1];  // ... through +11 (12 DWORDs)
  Phyre_PMatrix4_copy16f(this + 12, a2 + 12);  // matrix at +12
  Phyre_PMatrix4_copy16f(this + 28, a2 + 28);  // matrix at +28
  *(this + 44) = a2[44];  // ... through +82 (39 DWORDs)
  if ( this + 51 != a2 + 51 )
    Phyre_Math_MatrixInverse((_DWORD *)this + 51, ...);  // conditional
  // ... continues through +82
  return this;
}
```
- **Callers:** 7 (PCamera_CopyOrthographicData, PCameraPerspective_Copy, PCameraPerspective_CopyData, PScriptAccessors_PCamera_CopySceneNode, FFX_FieldMap_LoadOrchestrator_10k_structural, FFX_Dbg_ResolveSymbolFromModuleEntry, FFX_FieldCamera_LinkToFlyController)
- **Callees:** `Phyre_PMatrix4_copy16f`, `Phyre_Math_MatrixInverse`
- **Purpose:** Deep-copies the PSceneNode struct. Copies 12 head DWORDs directly, then 2 matrices (PMatrix4_copy16f at +12 and +28), then 39 tail DWORDs (+44 through +82). Conditional MatrixInverse at +51.
- **Struct layout (83 fields, inferred):**
  ```
  +0..+11:  12 DWORDs (vfptr, parent ptr, first child, flags, etc.)
  +12..+27: 4x4 matrix (16 floats, local matrix?)
  +28..+43: 4x4 matrix (16 floats, world matrix?)
  +44..+50: 7 DWORDs
  +51:      DWORD (inverse matrix conditional)
  +52..+82: 31 DWORDs
  ```
- **Blocks:** 3 basic blocks, linear copy + conditional inverse

## Phyre_PSceneNode_composeWorldMatrix_parentChain (0x5067c0, 468 bytes) ⭐
```c
// Jarvis goal: Recursively composes world matrix by multiplying local with parent world.
// Traverses parent chain via m_parent@0x04. Copies from m_localMatrix@0x10.
void __thiscall Phyre_PSceneNode_composeWorldMatrix_parentChain(PhyrePNode *this)
{
  struct PhyrePNode *i;
  float dst[16];

  qmemcpy(dst, this->m_localMatrix, 0x40u);           // copy local matrix
  for ( i = this->m_parent; i; dst[15] = v34[15] ) {
    // Decompose dst into 4 parts:
    //   v30 = translation column (dst[12..15])
    //   v31 = scale row (dst[8..11])
    //   v33 = rotation row 2 (dst[4..7])
    //   v32 = rotation row 1 (dst[0..3])
    v25 = Phyre_Matrix4x4_Transform(i->m_localMatrix, v26, v30);   // transform translation
    v24 = Phyre_Matrix3x4_Multiply(i->m_localMatrix, v29, v31);    // multiply scale
    v23 = Phyre_Matrix3x4_Multiply(i->m_localMatrix, v27, v33);    // multiply rotation row 2
    v22 = Phyre_Matrix3x4_Multiply(i->m_localMatrix, v28, v32);    // multiply rotation row 1
    Matrix4x4_ComposeAffineTransform(v34, v22, v23, v24, v25);     // reassemble
    // Copy v34[0..15] back to dst
    i = i->m_parent;
  }
}
```
- **Callers:** 7 (setMatricesForWorldMatrix, UpdateSkinningMatrices, LightEffect_ComputeLightTransform, SceneNode_ComposeTransformMath, Skeleton_UpdatePoseAsync, CalculatePhysicsTransformFromSceneNode, FFX_FieldMap_UpdateDrawClusterNodeTransforms)
- **Callees:** `Phyre_Matrix4x4_Transform`, `Phyre_Matrix3x4_Multiply` (×3), `Matrix4x4_ComposeAffineTransform`
- **Purpose:** Core world-matrix composition algorithm. Decomposes the accumulated matrix into translation/rotation/scale components, multiplies each by the parent's local matrix, then reassembles via `ComposeAffineTransform`. Walks `m_parent` chain recursively.
- **Blocks:** 4 (head + loop iterate + loop body + return)
- **Struct proof:** `m_parent` at offset +4, `m_localMatrix` at offset +0x10

## Phyre_PSceneNode_UpdateSkinningMatrices (0x55b7e0, 265 bytes) ⭐
```c
// Most complex PSceneNode function — 30 basic blocks, 3 code paths.
void __thiscall Phyre_PSceneNode_UpdateSkinningMatrices(int this)
{
  if ( *(_BYTE *)(this + 104) ) {                     // flag check
    if ( (parent_exists || *(this + 88)) ) {
      v3 = *(float **)(this + 96);                    // matrix source pointer
      if ( v3 ) {
        // Walk class descriptor chain for match at 0xC92090
        ClassDescriptor *cd = *(this + 100);
        while (cd) {
          if (cd == &MEMORY[0xC92090]) goto PATH_A;
          cd = cd->m_pParentCD;
        }
        // Not found at 0xC92090 → check 0xCA7228
        while (cd2) {
          if (cd2 == &MEMORY[0xCA7228]) goto PATH_B;
          cd2 = cd2->m_pParentCD;
        }
        // PATH_C: not found → FindClassDescriptorPNode → composeWorldMatrix_parentChain
        goto PATH_C;

      PATH_A:  // Found 0xC92090: transpose → decompose → setMatricesForWorldMatrix or CopyTransposed
        Matrix4x4_TransposeRotation(dst, v3);
        v7 = Phyre_Matrix4x4_DecomposeTransform(dst, ..., this + 12);
        if (*(this + 88))
          Phyre_PSceneNode_setMatricesForWorldMatrix(v8, v7);
        else if (*(this + 4))
          Matrix4x4_CopyTransposed(v10, v7);
        break;

      PATH_B:  // Found 0xCA7228: POcclusionQuery singleton → decompose → apply
        POcclusionQuery_ClassDescriptor_GetSingleton(v3, dst, *(this + 92));
        goto APPLY;

      PATH_C:  // Not found: find PNode descriptor → composeWorldMatrix → decompose → apply
        ClassDescriptorPNode = Phyre_PSceneNode_FindClassDescriptorPNode(this + 96);
        if (!ClassDescriptorPNode) return;
        Phyre_PSceneNode_composeWorldMatrix_parentChain(ClassDescriptorPNode);
        goto APPLY;

      APPLY:
        v12 = Phyre_Matrix4x4_DecomposeTransform(dst, ..., this + 12);
        Phyre_PSceneNode_ApplyWorldMatrixFromParent(this, v12);
      }
    }
  }
}
```
- **Callers:** 0 (data-referenced at 0x55A26A — vtable entry)
- **Callees:** 8 functions
- **Purpose:** Updates skinning matrices by walking the class descriptor chain to determine the matrix source type. Three code paths:
  - **Path A** (type == 0xC92090): TransposeRotation → DecomposeTransform → setMatricesForWorldMatrix or CopyTransposed to world matrix ptr
  - **Path B** (type == 0xCA7228): POcclusionQuery singleton → decompose → ApplyWorldMatrixFromParent
  - **Path C** (unknown type): FindClassDescriptorPNode → composeWorldMatrix_parentChain → decompose → apply
- **Blocks:** 30 — most complex CFG in the batch
- **Critical addresses:** `0xC92090` and `0xCA7228` are singleton class descriptor addresses used as type discriminators

## Phyre_PSceneNode_AddChildAndCopyName (0x55aca0, 226 bytes)
```c
int __thiscall Phyre_PSceneNode_AddChildAndCopyName(_DWORD *this, char *Srca, char *Src)
{
  if ( Src && *Src ) {
    result = Phyre_PSceneNode_AddChild(Srca, Src);
  } else {
    result = Srca;
  }
  if (!result) return 19;           // E_FAIL

  if (Src) {
    v8 = strlen(Src);
    v9 = Engine_AlignedAllocAlign(v8 + 1, 2);  // aligned alloc for name copy
    memcpy(v9, Src, v8 + 1);
    v10 = v12;
  } else {
    v10 = 0;
  }

  if ((this[21] & 1) == 0)
    Engine_AlignedFree(this[21]);   // free old name

  this[21] = v10;                   // name pointer
  this[19] = (Srca ? Srca + 4 : 0); // ?
  this[20] = &MEMORY[0xCA91F8];     // global singleton
  this[24] = result + 4;            // ?
  this[25] = &MEMORY[0xCA91F8];     // global singleton
  this[23] = -1;                    // invalid index
  return 0;
}
```
- **Callers:** 0 (data-referenced at 0x55A50E)
- **Callees:** `Phyre_PSceneNode_AddChild`, `Engine_AlignedAllocAlign`, `memcpy`, `Engine_AlignedFree`
- **Purpose:** Adds a child node and copies its name to `this[21]`. Allocates name buffer via `Engine_AlignedAllocAlign`. Sets fields +19, +20, +24, +25, +23. Returns 19 on failure, 13 on alloc failure.
- **Key insight:** `this[20]` and `this[25]` point to `0xCA91F8` — a shared global sentinel/null-like singleton.
- **Error codes:** 19 (child add failed), 13 (alloc failed)

## Phyre_PSceneNode_setMatricesForWorldMatrix (0x507570, 172 bytes)
```c
// Jarvis goal lot12: PSceneNode set from world matrix.
float *__thiscall Phyre_PSceneNode_setMatricesForWorldMatrix(int this, float *a2)
{
  PhyrePNode *parent = *(this + 4);  // m_parent@0x04
  if (parent) {
    if (parent->m_worldMatrixPtr) {
      // Path A: parent has world matrix → transpose parent world × multiply → decompose → copy to +16
      Matrix4x4_TransposeRotation(v15, parent->m_worldMatrixPtr);
      v4 = Phyre_Matrix4x4_MultiplyAndStore(v14, v15);
      Phyre_Matrix4_Copy(v15, v4);
      v10 = Phyre_Matrix4x4_DecomposeTransform(v15, dst, a2);
      result = Phyre_PMatrix4_copy16f(this + 16, v10);
    } else {
      // Path B: no world matrix → composeWorldMatrix_parentChain → multiply → decompose → copy
      Phyre_PSceneNode_composeWorldMatrix_parentChain(parent);
      v8 = Phyre_Matrix4x4_MultiplyAndStore(v14, v7);
      Phyre_Matrix4_Copy(v15, v8);
      v11 = Phyre_Matrix4x4_DecomposeTransform(v15, v12, a2);
      result = Phyre_PMatrix4_copy16f(this + 16, v11);
    }
  } else {
    // Path C: no parent → direct copy to +16
    result = Phyre_PMatrix4_copy16f(this + 16, a2);
  }
  // Final step: copy transposed to world matrix pointer at +12
  v9 = *(this + 12);
  if (v9) return Matrix4x4_CopyTransposed(v9, a2);
  return result;
}
```
- **Callers:** 1 (UpdateSkinningMatrices)
- **Callees:** 7 functions
- **Purpose:** Three-path world matrix setter. If parent exists with a pre-computed world matrix: transpose, multiply, decompose. If parent exists without world matrix: compute via `composeWorldMatrix_parentChain`. If no parent: direct copy. Always copies transposed to the world matrix pointer at offset +12.

---

# Part 2: SceneNode Update Pipeline (5 functions)

## Phyre_SceneNode_ComposeTransformMath (0x602050, 1183 bytes) ⭐
```c
// bad sp value at call has been detected, the output may be wrong!
int __usercall Phyre_SceneNode_ComposeTransformMath@<eax>(int a1@<ecx>, int a2@<ebp>)
```
- **Callers:** 0 (internal dispatch)
- **Callees:** `Phyre_Matrix4x4_ComposeMultiply`, `Matrix4x4_TransposeRotation`, `Phyre_Matrix4x4_Inverse`, `Phyre_LightEffect_ComputeLightTransform`, `Phyre_SceneNode_SetPhysicsBody`, `Phyre_PSceneNode_composeWorldMatrix_parentChain`, `Phyre_Matrix4_MulVec4`, `Phyre_TransformStruct_Copy16`, `_CIsqrt`, `@__security_check_cookie@4`
- **Purpose:** Largest SceneNode function (1.2KB). Composes world transform by traversing the parent chain and combining with physics body transforms. Uses `__usercall` convention with register params. 9 basic blocks, 248-byte stack frame.
- **Constants:** 0xF0, 0xF8, 0xC (stack offsets)
- **SECURITY_CHECK_COOKIE present** — indicates stack buffer overflow protection

## Phyre_SceneNode_UpdateStep (0x9bc3c0, 307 bytes) ⭐
```c
int __thiscall Phyre_SceneNode_UpdateStep(float *this, float deltaTime, int a3, float fixedDt)
{
  v4 = 0;
  if ( a3 ) {
    // Bounded mode: accumulate delta, step when >= fixedDt
    this[60] += deltaTime;
    if ( this[60] >= (double)fixedDt ) {
      v4 = (int)(this[60] / fixedDt);           // step count
      this[60] -= fixedDt * (float)v4;           // remainder
    }
  } else {
    // Unbounded mode: set directly, 1 step if above epsilon
    this[60] = deltaTime;
    if ( fabs(deltaTime) >= 0.00000011920929f ) {  // ~FLT_EPSILON
      v4 = 1;
      a3 = 1;
    } else {
      v4 = 0;
      a3 = 0;
    }
  }
  // Loop calling vtable dispatch per step
  for ( int step = 0; step < v4; ++step ) {
    // vtable call at this[0] + 0x3C → dispatch per fixed timestep
  }
}
```
- **Callers:** 0 (vtable dispatch from UpdateAllNodes)
- **Callees:** `__ftol2_sse` (float-to-int conversion)
- **Purpose:** Classic fixed-timestep game loop accumulator. Two modes:
  - **Bounded** (a3 != 0): Accumulates `deltaTime`, computes `steps = accumulator / fixedDt`, subtracts `fixedDt * steps` from accumulator. Calls vtable dispatch per step.
  - **Unbounded** (a3 == 0): Sets accumulator directly. Calls 1 step if |value| > epsilon.
- **Blocks:** 15 (with loop, conditional branches)

## Phyre_SceneNode_DispatchWithSEH (0x9848e0, 251 bytes)
```c
int __userpurge Phyre_SceneNode_DispatchWithSEH@<eax>(
    _DWORD **this@<ecx>, int a2@<ebp>, float *a3, float *a4, int a5)
{
  // SEH setup: __except_handler3 with exception filter at 0xAD8BEB
  v9 = -1;                        // SEH cookie
  LODWORD(v8[66]) = &loc_AD8BEB;  // exception filter
  v8[65] = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;  // chain previous handler
  LODWORD(v8[64]) = &v12;

  Bullet_btSingleRayCallback_ctor(v8, a3, a4, this, a5);

  v6 = **(this + 20);             // vtable dispatch
  v9 = 0;                         // clear SEH cookie
  return (*(int (__cdecl **)(float *))(v6 + 20))(a3);
}
```
- **Callers:** 0 (vtable dispatch)
- **Callees:** `Bullet_btSingleRayCallback_ctor`, `@__security_check_cookie@4`
- **Purpose:** Wraps a Bullet Physics ray-cast callback in `__except_handler3` SEH. Sets up an exception filter at `0xAD8BEB`. Calls `btSingleRayCallback` constructor, then dispatches via vtable +20. Demonstrates PhyreEngine's integration of Bullet Physics with structured exception handling for crash resilience.
- **SEH filter:** `0xAD8BEB` — custom filter handling access violations during ray casts

## Phyre_SceneNode_RenderChildren (0x9bbfc0, 194 bytes)
```c
void __thiscall Phyre_SceneNode_RenderChildren(_DWORD *this, int renderer)
{
  int i, j;

  // Loop 1: visible children
  for ( i = 0; i < *(this + 2); ++i ) {
    v4 = *(_BYTE **)(*(this + 4) + 4 * i);   // child pointer
    if ( (v4[244] & 2) != 0 ) {               // visibility flag at +244
      v5 = vtable_getLayer(v4);                 // vtable +12
      v6 = vtable_getPass(renderer, v5, 1);     // vtable +12
      v7 = vtable_getRenderOrder(v4, *(v6 + 8), renderer); // vtable +16
      vtable_submit(renderer, v6, v7, 0x59444252, v4);     // vtable +16, fourCC='RBDR'
    }
  }

  // Loop 2: all children (second dispatch)
  for ( j = 0; j < *(this + 47); ++j ) {
    // Similar dispatch with fourCC 0x534E4F43 ('CONS')
  }
}
```
- **Callers:** 1 (Phyre_SceneNode_UpdateCallback)
- **Callees:** none (all vtable dispatch)
- **Purpose:** Dual-loop render submission. First loop iterates visible children (`this[2]` items at `this[4]`), checks visibility flag at child+244, gets layer+pass+order, then submits with fourCC `0x59444252` ('RBDR' = Renderer?). Second loop iterates remaining children (`this[47]` count) with fourCC `0x534E4F43` ('CONS' = Console?).
- **Magic constants:**
  - `0x59444252` = 'RBDR' (Render Buffer Draw?)
  - `0x534E4F43` = 'CONS' (Console render?)
  - `0x2` at child+244 = visibility flag

## Phyre_SceneNode_UpdateAllNodes (0x985ef0, 358 bytes)
```c
void __thiscall Phyre_SceneNode_UpdateAllNodes(_DWORD *this, int a2)
{
  // Two-phase update:
  // Phase 1: Gather active nodes into a list (while loop)
  for (i = 0; ; ) {
    v4 = *(this + 4);  // child list
    // Walk children, add to temp buffer
    // ... 19 blocks total
  }

  // Phase 2: For each gathered node, call vtable dispatch
  // If Ragdoll_ResetSolverBodies returns true, skip HashTable_Insert
}
```
- **Callers:** 2 (Phyre_SceneNode_DispatchUpdate, Phyre_SceneNode_UpdateCallback)
- **Callees:** `Phyre_Ragdoll_ResetSolverBodies`, `Phyre_HashTable_Insert`
- **Purpose:** Two-phase node update. First gathers active scene nodes into a temporary list, then iterates calling dispatch on each. Links to ragdoll physics solver reset. 19 basic blocks.
- **Key insight:** `Phyre_Ragdoll_ResetSolverBodies` is called per gathered node — physics simulation is tied to scene node update loop.

---

# Part 3: Notify / Propagate System (5 near-duplicate functions)

The Notify/Propagate family shares identical CFG skeletons. They differ only by which `SetLocal*` call they make and which entry condition check they have. This strongly suggests compiler-generated template expansions from a single macro/pattern.

## Phyre_PSceneNode_NotifyTransformChanged (0x507170, 87 bytes)
```c
_DWORD *__stdcall Phyre_PSceneNode_NotifyTransformChanged(int a1, int a2)
{
  v2 = Phyre_ScriptAccessor_PScenePNodeRef_Get(a1);
  // Copy 4 DWORDs + 1 matrix from v2 to a2
  *(_DWORD *)a2 = *(_DWORD *)v2;
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(v2 + 4);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(v2 + 8);
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(v2 + 12);
  Phyre_PMatrix4_copy16f((float *)(a2 + 16), (float *)(v2 + 16));
  // Conditional MatrixInverse at +80
  if ( a2 + 80 != v2 + 80 )
    Phyre_Math_MatrixInverse((_DWORD *)(a2 + 80), ...);
}
```
- **Callers:** 0 (vtable entry at 0xB24D38)
- **Callees:** `Phyre_ScriptAccessor_PScenePNodeRef_Get`, `Phyre_PMatrix4_copy16f`, `Phyre_Math_MatrixInverse`
- **Purpose:** Copies transform data from a script-accessible node reference. Copies 4 DWORDs (offset+0 to +12) + 1 matrix (offset +16 to +32) + conditional inverse at +80.
- **Key insight:** This is a **scripting bridge** — uses `ScriptAccessor_PScenePNodeRef_Get` to resolve the source, not a direct pointer copy.

## Phyre_PSceneNode_NotifyHierarchyChanged (0x5071d0, 101 bytes)
```c
int __thiscall Phyre_PSceneNode_NotifyHierarchyChanged(_DWORD *this)
{
  if (!Phyre_PSceneNode_SetLocalPosition(this)) {
    v2 = *(this + 6);
    do {
      if (v2) {
        v2 = (*(this + 5) != *v2) ? (_DWORD *)*v2 : 0;
        *(this + 6) = v2;
      }
    } while (!Phyre_PSceneNode_SetLocalPosition(this));
  }
  result = *(this + 6);
  if (result)
    return Phyre_StringLiteral_GetLength(this, result);
  // Clear 5 DWORDs
  *this = 0;  *(this + 1) = 0;  *(this + 2) = 0;  *(this + 3) = 0;  *(this + 4) = 0;
  return result;
}
```
- **Callers:** 3 (via vtable: 0x504D75, 0x504EF4, 0x50624C)
- **Callees:** `Phyre_PSceneNode_SetLocalPosition`, `Phyre_StringLiteral_GetLength`
- **Purpose:** Notifies hierarchy change → calls `SetLocalPosition`. On failure, walks a linked list at `this[6]` retrying. Returns string length on success, zeros 5 DWORDs on failure.
- **Algorithm:** `SetLocalPosition` → if false, walk `this[6]` chain → retry → if still false, zero the state.

## Phyre_PSceneNode_NotifyVisibilityChanged (0x507240, 101 bytes)
- **Same CFG as NotifyHierarchyChanged** but calls `Phyre_PSceneNode_SetLocalRotation` instead of `SetLocalPosition`
- **Callers:** 3 (via vtable: 0x504F44, 0x504F95, 0x50617C)

## Phyre_PSceneNode_PropagateVisibility (0x5072b0, 93 bytes)
- **Same CFG** as NotifyHierarchyChanged but **no initial `if` guard** — always enters the `do..while(!SetLocalPosition)` loop
- **Callers:** 4 (via vtable: 0x5052EE, 0x50629A, 0x5062A8, 0x50739B)

## Phyre_PSceneNode_PropagateVisibilityToChildren (0x507310, 93 bytes)
- **Same CFG** as PropagateVisibility but calls `Phyre_PSceneNode_SetLocalRotation` instead of `SetLocalPosition`
- **Callers:** 4 (via vtable: 0x50532E, 0x5061CA, 0x5061D8, 0x5073DB)

### Notify/Propagate Comparison Table

| Function | Bytes | Blocks | Guard | Set Call | Callers |
|----------|-------|--------|-------|----------|---------|
| NotifyTransformChanged | 87 | 3 | `ScriptAccessor_Get` | N/A (direct copy) | 1 |
| NotifyHierarchyChanged | 101 | 9 | `if (!SetLocalPosition)` | SetLocalPosition | 3 |
| NotifyVisibilityChanged | 101 | 9 | `if (!SetLocalRotation)` | SetLocalRotation | 3 |
| PropagateVisibility | 93 | 7 | none | SetLocalPosition | 4 |
| PropagateVisibilityToChildren | 93 | 7 | none | SetLocalRotation | 4 |

---

# Part 4: Class Descriptors & Type Registration

## Phyre_PNode_ClassDescriptor_ctor (0x504c40, 145 bytes)
```c
Vtable_PClassDescriptorAbstract_PClassDescriptor_Phyre ***__thiscall
Phyre_PNode_ClassDescriptor_ctor(
    Vtable_PClassDescriptorAbstract_PClassDescriptor_Phyre ***this)
{
  DefaultPool = Phyre_GetDefaultPool();
  Singleton = Phyre_PNamespace_GetSingleton();
  Phyre_PClassDescriptor_ctor((PhyrePClassDescriptor *)this, Singleton, "PNode", 84, 4, DefaultPool, 4);
  // Set flags: *(this + 36) |= 2
  *(this + 36) = (unsigned int)*(this + 36) | 2;
  // Set vftable to Phyre::PClassDescriptorAbstract<Phyre::PScene::PNode>::vftable
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PScene::PNode>::`vftable';
  // Set 3 fields via SetField64/68/6C
  Phyre_PClassDescriptor_SetField64(this, &val__29);
  Phyre_PClassDescriptor_SetField68(this, &val__30);
  Phyre_PClassDescriptor_SetField6C(this, &val__31);
  return this;
}
```
- **Callers:** 0 (init-time registration)
- **Callees:** 6 functions
- **Strings:** `"PNode"`
- **Purpose:** Registers the `PNode` class descriptor with type system. Class size = 84 bytes, alignment = 4. Pool ID = 4. Sets vftable to `Phyre::PClassDescriptorAbstract<Phyre::PScene::PNode>` at `0xB24CE4`.
- **Constants:** 84 (class size), 4 (alignment and pool), `0xCA95E0` (class descriptor address)

## Phyre_PSceneNode_GetOrCreateSceneNode (0x507a20, 130 bytes)
```c
_DWORD *Phyre_PSceneNode_GetOrCreateSceneNode()
{
  if ( (dword_CA9770[0] & 1) == 0 ) {
    dword_CA9770[0] |= 1u;       // mark initialized
    Phyre_renderState_pop(unk_CA973C);        // pop render state
    unk_CA973C[0] = vtbl_NSD_PAnimationKeyDataType;  // set vtable
    atexit(Phyre_PNamedSemanticInit_CA973C);  // register dtor
  }
  return unk_CA973C;             // return singleton
}
```
- **Callers:** 4 (Phyre_RegisterAnimationDescriptorSuite, Phyre_PAnimationTarget_ClassDescriptorInit, Phyre_PAnimationKey_ClassDescriptorInit, PhyrePScripting_AnimationDescriptorNew)
- **Callees:** `Phyre_renderState_pop`, `_atexit`
- **Strings:** `"PAnimationKeyDataType"` at 0xB24FC8
- **Purpose:** Lazy singleton factory for scene node. First call allocates via `renderState_pop`, sets vtable to `PAnimationKeyDataType`, registers atexit destructor. Returns singleton at `0xCA973C`. Guarded by bit 0 of `0xCA9770`.

## Phyre_PSceneNode_InsertChild (0x506d90, 114 bytes) — also typed as `RemoveChildByIndex`
Both `Phyre_PSceneNode_InsertChild` and `Phyre_PSceneNode_RemoveChildByIndex` share identical CFG: guarded singleton initialization returning a `PString*` singleton. Despite different names, both are **type registration wrappers**, not actual child management functions.

```c
// Representative decompilation of both:
_DWORD *Phyre_PSceneNode_InsertChild()  // or RemoveChildByIndex
{
  if ( (guard_flag & 1) == 0 ) {
    guard_flag |= 1u;
    singleton = &unk_CA91F9;          // empty PString sentinel
    singleton_type = Phyre_PTypeDefault_PChar_SingletonInit() | 1;
    singleton_zero = 0;
  }
  return &singleton;
}
```
- **Key insight:** These are **not** insert/remove functions — they are PString* type registration singletons. The "child management" naming is a decompiler artifact.

---

# Part 5: PhyrePNode Struct & Phyre_PNode_* Family (19 functions)

The `Phyre_PNode_*` family is the base class layer (19 functions). Most are 3-6 byte stubs.

## PhyrePNode Struct Layout (inferred, 84 bytes)

```
Offset  Size  Field
+0      4     vfptr (vtable pointer)
+4      4     m_parent (PhyrePNode*)
+8      4     m_firstChild (or child list head)
+0xC    4     ? (class descriptor pointer?)
+0x10   64    m_localMatrix (4×4 float, 16 floats)
+0x50   4     ?
...
Total:  84 bytes (as declared in PNode_ClassDescriptor_ctor: "PNode", 84, 4)
```

### Key Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `Phyre_PNode_ClassDescriptor_ctor` | 0x504C40 | 145 | Register "PNode" class (84 bytes, align 4) |
| `Phyre_PNode_Descriptor_Dtor` | 0x504D10 | 39 | Class descriptor destructor |
| `Phyre_PNode_SupportsType_RetTrue_B/C/D` | various | 3 | `return 1` stubs for type queries |
| `Phyre_PNode_GetDescriptorPtr` * 6 | various | 6 | Return descriptor vtable at fixed addresses |
| `Phyre_PNode_GetClassName` | 0x504CE0 | 6 | Returns class type ID = 2 |
| `Phyre_PNode_PClassDescriptor_DtorWithFree` | 0x504D40 | 39 | Dtor + aligned free |

---

# Part 6: PSceneNode Helper Functions (tabulated)

## Transform & Matrix Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `Phyre_PSceneNode_ApplyWorldMatrixFromParent` | 0x55B8F0 | 46 | Applies world matrix from parent to this node |
| `Phyre_PSceneNode_setMatricesForWorldMatrix` | 0x507570 | 172 | 3-path world matrix setter (see Part 1) |
| `Phyre_PSceneNode_setLocalMatrix` | 0x507480 | 12 | Sets local matrix from source |
| `Phyre_PSceneNode_setLocalToWorldMatrix` | 0x507490 | 13 | Sets local-to-world matrix |
| `Phyre_PSceneNode_PropagateTransform` | 0x506B20 | 99 | Propagates transform to children |
| `Phyre_PSceneNode_UpdateWorldMatrix_Recursive` | 0x506A30 | 127 | Recursive world matrix update |

## Child Management Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `Phyre_PSceneNode_AddChild` | 0x506CE0 | 58 | Add child by name lookup |
| `Phyre_PSceneNode_AddChildAndCopyName` | 0x55ACA0 | 226 | Add + copy name (see Part 1) |
| `Phyre_PSceneNode_RemoveChild` | 0x506EB0 | 46 | Remove child by pointer |
| `Phyre_PSceneNode_RemoveAllChildren` | 0x506F30 | 46 | Remove all children |
| `Phyre_PSceneNode_DetachChild` | 0x506E70 | 46 | Detach child (unlink only) |
| `Phyre_PSceneNode_DetachAllChildren` | 0x507080 | 46 | Detach all children |
| `Phyre_PSceneNode_InsertChild` | 0x506D90 | 114 | Type registration (NOT insert) |
| `Phyre_PSceneNode_InsertChildAfter` | 0x506D20 | 114 | Type registration (NOT insert) |
| `Phyre_PSceneNode_RemoveChildByIndex` | 0x506F70 | 114 | Type registration (NOT remove) |
| `Phyre_PSceneNode_GetChildCount` | 0x5069A0 | 60 | Scripting accessor (Lua) |
| `Phyre_PSceneNode_FindChild` | 0x5069E0 | 65 | Scripting accessor (Lua) |
| `Phyre_PSceneNode_GetChildIndex` | 0x507010 | 59 | Get child index by pointer |
| `Phyre_PSceneNode_GetChildPtr` | 0x506FE0 | 4 | `return *(this+4)` stub |
| `Phyre_PSceneNode_getFirstChild` | 0x506FD0 | 4 | `return *(this+4)` stub |

## LOD & Render Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `Phyre_PSceneNode_GetLODLevel` | 0x507780 | 43 | Get current LOD level |
| `Phyre_PSceneNode_SetLODLevel` | 0x507C30 | 62 | Set LOD level |
| `Phyre_PSceneNode_GetActiveLOD` | 0x507CB0 | 31 | Get active LOD |
| `Phyre_PSceneNode_UpdateLOD` | 0x507CD0 | 91 | Update LOD selection (linked list walk) |
| `Phyre_PSceneNode_CompareLOD` | 0x507B90 | 92 | Compare LOD by name (strcmp) |
| `Phyre_PSceneNode_GetSceneNodeRenderInfo` | 0x507D50 | 167 | Walk linked list at CA9734 → serialize |
| `Phyre_PSceneNode_GetRenderLayer` | 0x507930 | 71 | Get render layer |
| `Phyre_PSceneNode_SetRenderLayer` | 0x507980 | 44 | Set render layer |
| `Phyre_PSceneNode_GetRenderMask` | 0x5079B0 | 44 | Get render mask |
| `Phyre_PSceneNode_GetShadowMask` | 0x5079E0 | 44 | Get shadow mask |

## Bounding Volume Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `Phyre_PSceneNode_GetBoundingBox` | 0x507750 | 83 | Scripting accessor (Lua) |
| `Phyre_PSceneNode_SetBoundingBox` | 0x5077D0 | 71 | Set bounding box |
| `Phyre_PSceneNode_GetBoundingSphere` | 0x507820 | 85 | Get bounding sphere |
| `Phyre_PSceneNode_SetBoundingSphere` | 0x507880 | 71 | Set bounding sphere |

## Visibility Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `Phyre_PSceneNode_SetVisibility` | 0x507630 | 105 | Set visibility (flagged) |
| `Phyre_PSceneNode_SetLocalPosition` | 0x5073F0 | 43 | Set local position |
| `Phyre_PSceneNode_SetLocalRotation` | 0x507420 | 43 | Set local rotation |
| `Phyre_PSceneNode_SetLocalScale` | 0x507450 | 61 | Set local scale |
| `Phyre_PSceneNode_GetLocalPosition` | 0x507490 | 38 | Get local position |
| `Phyre_PSceneNode_GetLocalRotation` | 0x5074C0 | 68 | Get local rotation |

## SceneNode Type Functions (PSceneNode + SceneNode)

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `Phyre_PSceneNode_GetSceneNodeType` | 0x506A30 | 51 | Get node type |
| `Phyre_PSceneNode_IsTypeOrSubtype` | 0x506A70 | 64 | Type+subtype check |
| `Phyre_PSceneNode_SupportsType_RetFalse` | 0x506CD0 | 5 | `return 0` stub |
| `Phyre_PSceneNode_GetScene` | 0x506B80 | 51 | Get scene pointer |
| `Phyre_PSceneNode_GetTypeName` | 0x506AD0 | 21 | Get type name string |
| `Phyre_PSceneNode_GetParentNodeType` | 0x5076D0 | 33 | Get parent node type |
| `Phyre_PSceneNode_FindClassDescriptorPNode` | 0x533930 | 34 | Find PNode class descriptor |
| `Phyre_PSceneNode_LogHierarchy` | 0x506CB0 | 37 | Debug log hierarchy |

## Flags Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `Phyre_PSceneNode_GetSceneNodeFlags` | 0x5076E0 | 9 | Get flags |
| `Phyre_PSceneNode_SetSceneNodeFlags` | 0x5076F0 | 9 | Set flags |
| `Phyre_PSceneNode_ClearSceneNodeFlags` | 0x507700 | 9 | Clear flags |
| `Phyre_PSceneNode_ToggleSceneNodeFlags` | 0x507710 | 9 | Toggle flags |
| `Phyre_PSceneNode_CheckSceneNodeFlags` | 0x507720 | 9 | Check flags |
| `Phyre_PSceneNode_GetTransformLock` | 0x507730 | 18 | Get transform lock bit |

## 3-byte Stubs (return-value helpers)

| Function | Address | Size | Return |
|----------|---------|------|--------|
| `Phyre_PSceneNode_DerefThis` | 0x506FF0 | 3 | `return *this` |
| `Phyre_PSceneNode_getNextSibling` | 0x506FC0 | 3 | `return *(this+4)` |
| `Phyre_PSceneNode_GetChildPtr` | 0x506FE0 | 4 | `return *(this+4)` |
| `Phyre_PSceneNode_getFirstChild` | 0x506FD0 | 4 | `return *(this+4)` |
| `Phyre_PSceneNode_getLocalMatrix` | 0x506FA0 | 4 | `return this+0x10` |
| `Phyre_PSceneNode_GetLocalMatrixPtr_0` | 0x506FB0 | 4 | `return this+?` |
| `Phyre_PSceneNode_getLocalToWorldMatrix` | 0x506F90 | 4 | `return this+?` |

---

# Part 7: Phyre_SceneNode_* (Runtime) — 18 functions

## SceneNode Update Pipeline

| Function | Address | Size | Blocks | Purpose |
|----------|---------|------|--------|---------|
| `Phyre_SceneNode_ComposeTransformMath` | 0x602050 | 1183 | 9 | Compose world transform (see Part 2) |
| `Phyre_SceneNode_UpdateStep` | 0x9BC3C0 | 307 | 15 | Fixed-timestep accumulator loop |
| `Phyre_SceneNode_DispatchWithSEH` | 0x9848E0 | 251 | 5 | SEH-wrapped Bullet ray cast dispatch |
| `Phyre_SceneNode_UpdateAllNodes` | 0x985EF0 | 358 | 19 | Two-phase node gather + update |
| `Phyre_SceneNode_DispatchUpdate` | 0x984A40 | 38 | 2 | Update dispatch wrapper |
| `Phyre_SceneNode_UpdateChildren` | 0x507A20 | 53 | 2 | Children update dispatch |
| `Phyre_SceneNode_UpdateCallback` | 0x9BBF90 | 46 | 1 | Linear callback update |
| `Phyre_SceneNode_RenderChildren` | 0x9BBFC0 | 194 | 8 | Dual-loop render submission ('RBDR'/'CONS') |
| `Phyre_SceneNode_DispatchCallbacks` | 0x985F90 | 59 | 3 | Dispatch registered callbacks |

## SceneNode Helpers

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `Phyre_SceneNode_SetPhysicsBody` | 0x5F3FB0 | 115 | Associate physics body with scene node |
| `Phyre_SceneNode_GetField68` | 0x504C30 | 4 | Read field at +68 |
| `Phyre_SceneNode_GetField2F0` | 0x504C10 | 7 | Read field at +0x2F0 |
| `Phyre_SceneNode_GetField04` | 0x504C20 | 4 | Read field at +4 |
| `Phyre_SceneNode_GetByteB0` | 0x984A80 | 7 | Read byte at +0xB0 |
| `Phyre_SceneNode_VtableCall3C_01` | 0x5F3FD0 | 9 | Vtable dispatch at +0x3C |
| `Phyre_SceneNode_VtableCall3C_02` | 0x5F3FE0 | 9 | Vtable dispatch at +0x3C |
| `Phyre_SceneNode_GetField04_01/02` | 0x507BA0 | 4 | Read field at +4 |

---

# Summary Tables

## Size Distribution

| Bucket | Range | Count |
|--------|-------|-------|
| Huge | >= 1024 bytes | 1 (ComposeTransformMath) |
| Large | 512 - 1023 | 2 (Copy, composeWorldMatrix_parentChain) |
| Medium | 256 - 511 | 5 (UpdateSkinning, AddChildAndCopyName, UpdateStep, UpdateAllNodes, RenderChildren) |
| Small | 100 - 255 | 15 |
| Tiny | 3 - 99 | 103 |

## Complexity Leaders

| Function | Blocks | Bytes | Callees |
|----------|--------|-------|---------|
| UpdateSkinningMatrices | **30** | 265 | 8 |
| AddChildAndCopyName | 20 | 226 | 4 |
| UpdateAllNodes | 19 | 358 | 2 |
| GetSceneNodeRenderInfo | 16 | 167 | 2 |
| UpdateStep | 15 | 307 | 1 |
| ResetState | 15 | 108 | 2 |
| CompareLOD | 13 | 92 | 0 |

## Most-Called Functions

| Function | Callers | Purpose |
|----------|---------|---------|
| composeWorldMatrix_parentChain | **7** | Core world matrix composition |
| PSceneNode_Copy | **7** | Deep copy node |
| GetOrCreateSceneNode | **4** | Scene node singleton factory |
| CompareLOD | **3** | LOD comparison by name |
| NotifyHierarchyChanged | 3 | Hierarchy notification |
| NotifyVisibilityChanged | 3 | Visibility notification |

## Misnamed / Non-obvious Functions

| Symbol Name | Actual Behavior | Misleading Factor |
|---|---|---|
| `PSceneNode_InsertChild` | PString* singleton constructor | Name implies child list insert |
| `PSceneNode_InsertChildAfter` | PString* singleton constructor | Same — both are type reg |
| `PSceneNode_RemoveChildByIndex` | PString* singleton constructor | Name implies child removal |
| `PSceneNode_FindChild` | Lua scripting accessor | Name implies tree walk |
| `PSceneNode_GetChildCount` | Lua scripting accessor | Name implies count query |
| `PSceneNode_GetBoundingBox` | Lua scripting accessor | Name implies AABB compute |

## Subsystem Distribution

| Subsystem | Count |
|-----------|-------|
| PNode base class stubs | 19 |
| PSceneNode transform/matrix | 12 |
| PSceneNode child management | 14 |
| PSceneNode LOD/render info | 10 |
| PSceneNode Notify/Propagate | 5 |
| PSceneNode flags/type | 14 |
| PSceneNode bounding/visibility | 8 |
| PSceneNode scene/helpers | 6 |
| SceneNode update pipeline | 9 |
| SceneNode helpers | 9 |

---

## Key Findings

1. **Scene graph hierarchy confirmed** — PNode is the base (84 bytes, vftable at 0xB24CE4). PSceneNode extends with 2 matrices (+12, +28) plus 39+ additional fields. SceneNode adds runtime state (physics body, callback list, time accumulator).

2. **World matrix composition is decomposed** — `composeWorldMatrix_parentChain` decomposes the local matrix into translation, rotation, and scale components, multiplies each by the parent's local matrix via `Matrix3x4_Multiply` (×3) + `Matrix4x4_Transform` (×1), then reassembles via `ComposeAffineTransform`. Not a simple matrix multiply.

3. **UpdateSkinningMatrices is the complexity king** — 30 basic blocks, 3 distinct code paths discriminated by class descriptor chain walk (0xC92090 vs 0xCA7228 vs unknown). Handles: POcclusionQuery singletons, PNode descriptors, and direct world matrix transposition.

4. **Fixed-timestep accumulator** — `UpdateStep` implements a classic game loop: accumulate delta, compute step count via integer division, subtract remainder. Supports both bounded (fixed dt) and unbounded (immediate) modes.

5. **Structured exception handling for Bullet Physics** — `DispatchWithSEH` wraps `Bullet_btSingleRayCallback_ctor` in `__except_handler3` with custom filter at 0xAD8BEB. PhyreEngine uses SEH for crash resilience during ray casts.

6. **FourCC render dispatch** — `RenderChildren` uses `0x59444252` ('RBDR') and `0x534E4F43` ('CONS') as magic constants passed to vtable dispatchers for render submission.

7. **5 Notify/Propagate near-duplicates** — Generated from the same template/macro skeleton, differing only by SetLocalPosition vs SetLocalRotation call. This is strong evidence of C++ template expansion producing multiple functions with identical CFG.

8. **Several "child management" functions are actually type registration** — `InsertChild`, `InsertChildAfter`, and `RemoveChildByIndex` all resolve to guarded PString* singleton initialization, not child list operations. The PSceneNode vtable has function pointers that the decompiler mapped to wrong names.

9. **Lua scripting accessors in PSceneNode** — `FindChild`, `GetChildCount`, `GetBoundingBox`, and `NotifyTransformChanged` all use `ScriptAccessor_PScenePNodePtr_Get` or `ScriptAccessor_PScenePNodeRef_Get` — confirming the misnaming pattern observed in Batches 9 and 14.

10. **Key singleton addresses:**
    - `0xC92090` — Class descriptor (used as type discriminator in skinning matrices)
    - `0xCA7228` — Another class descriptor (POcclusionQuery path)
    - `0xCA91F8` — Shared sentinel/like-null singleton for PString fields
    - `0xB24CE4` — PNode vftable
    - `0xCA9734` — Global linked list head (LOD, render info)

---

## Next Batches

- Batch 16: Phyre_PPostProcessing (PPA, PPAntiAlias, PPBloom, PPColor, ~80 functions)
- Batch 17: Phyre_PAudio (PA, PAData, PASound, PAPlayer, ~150 functions)
- Batch 18: Engine_* Part 2 (remaining ~140 small functions)
- Batch 19: Phyre_PPhysics Part 2 (PActor, PWorld, PShape, PConstraint, ~222 remaining)
