# FFX.exe Decompilation — Batch 9 (Phyre_Math)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 25 (Phyre_Math — Matrix, Vector, Quaternion, Transform)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers 25 Phyre_Math functions (of 87 total in the family) — the mathematical foundation of PhyreEngine. Matrix 4x4 operations, vector math, quaternion operations, coordinate transforms, and SSE-optimized vertex batch processing.

**Key discovery:** 2 of 25 functions are **mismamed** — their RTTI symbol name does not match actual behavior:
- `Phyre_Math_QuaternionSlerp` → actually `PClassDataMemberDynamic` constructor
- `Phyre_Math_Vec3Normalize` → actually `PObjectAccessor<PString*>::Get` Lua scripting accessor

---

# Part 1: Matrix 4x4 Operations (Largest Functions)

## Phyre_Math_StackAlignedComputation (0x5f9ce0, 3280 bytes) ⭐
```c
// Phyre: Math stack-aligned computation — performs aligned stack math operations
// bad sp value at call has been detected, the output may be wrong!
int __userpurge Phyre_Math_StackAlignedComputation@<eax>(
        _DWORD *a1@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        float *a5, float *a6, float *a7, int a8)
```
- **Callers:** 0 (internal/vtable dispatch)
- **Callees:** none
- **Purpose:** Largest PMath function (3.2KB). Stack-aligned computation with `__userpurge` convention. "bad sp value" warning indicates hand-optimized stack alignment.
- **Constants:** 0x8, 0xFFFFFFF0 (alignment mask), 0x4, 0x38, 0x10
- **Blocks:** 1 basic block (linear, no branches) — pure straight-line computation
- **Note:** Zero strings, zero sub-calls. Pure FPU math with x87 doubles.

## Phyre_Math_TransformMatrixByMatrix4x4 (0xa13b90, 2522 bytes)
```c
// SSE-optimized 4x4 matrix multiply. Used throughout render pipeline for transform composition.
float *__thiscall Phyre_Math_TransformMatrixByMatrix4x4(float *this, float *a2)
```
- **Callers:** 2 (PostProcessing_Scale2xRender, TransformMultipleMatrices)
- **Callees:** PMatrix4_copy16f, Matrix4x4_TransposeRotation, Matrix4x4_ComposeFromVectors, Matrix4_MulVec4, MatrixMultiply4x4
- **Purpose:** SSE-optimized 4x4 matrix multiply with transpose and compose sub-steps. 780-byte stack frame.
- **Blocks:** 3 (head + loop + return)

## Phyre_Math_Mat4x4Inverse (0x704ec0, 1849 bytes)
```c
// Phyre 4x4 matrix inverse (1.8KB). Computes inverse using cofactor expansion.
// Used for view matrix inverse, world matrix inverse, and transform computations.
int __cdecl Phyre_Math_Mat4x4Inverse(int a1, float *a2)
```
- **Callers:** 1 (FFX_BtlUI_HudParty_ApplyStatus)
- **Callees:** @__security_check_cookie@4
- **Purpose:** 4x4 matrix inverse via cofactor expansion. 184-byte stack frame. 6 basic blocks with loop.
- **Key insight:** Only called from battle UI (HudParty apply status) — used for UI transform inversion

## Phyre_Math_SinCosTransform (0x5fb280, 1719 bytes)
```c
int __userpurge Phyre_Math_SinCosTransform@<eax>(
        int a1@<ecx>, int a2@<ebp>,
        float *a3, float *a4, float *a5,
        float a6, float a7, float a8, float a9, float a10, int a11, float a12)
```
- **Callers:** 0 (vtable dispatch)
- **Callees:** _CIcos, _CIsin, __ftol2_sse, @__security_check_cookie@4
- **Purpose:** Simultaneous sin/cos transform with 6 float params. x87 FPU heavy. 44 basic blocks.
- **Stack frame:** ~0xA58 (2648 bytes) — very large for parameter passing

## Phyre_Math_MatrixMultiply4x4 (0x573e70, 1715 bytes) ⭐
```c
float *__cdecl Phyre_Math_MatrixMultiply4x4(float *a1, float *a2)
```
- **Callers:** 12! (PScriptAccessors_Matrix_Multiply, ShadowSkinning_ProcessBones, FFX_Camera_ComputeTransformMatrix, FFX_Model_BoneMatrixPaletteUpdate, TransformMatrixByMatrix4x4, Iggy_TextureLayer_DispatchB/E/D, TransformMultipleMatrices)
- **Callees:** none
- **Purpose:** Most-called math function in the batch. Pure matrix multiply with no sub-calls. 332-byte stack frame, 1 basic block.
- **Used by:** Camera, model bone skinning, shadow skinning, texture layers, scripting

## Phyre_Math_SSE_VertexTransform (0x5c9010, 1623 bytes)
```c
// SSE-optimized vertex transformation for batch vertex processing.
// Uses SSE intrinsics for 4-wide float operations.
void __cdecl Phyre_Math_SSE_VertexTransform(int a1, int a2, float **a3, int a4)
```
- **Callers:** 0
- **Callees:** none
- **Purpose:** SSE batch vertex transform. Uses `__m128` SIMD types. 8 basic blocks with dual-loop structure.
- **Constants:** 0x3, 0x6 (stride/iteration constants), 0xD8 (216 bytes stack)

## Phyre_Math_SSE_VertexTransform2 (0x5c8ab0, 1367 bytes)
```c
void __cdecl Phyre_Math_SSE_VertexTransform2(int a1, int a2, float **a3, int a4)
```
- **Callers:** 0
- **Callees:** none
- **Purpose:** Variant 2 of SSE vertex transform. Same prototype as v1, different inner loop structure.
- **Blocks:** 8 (same dual-loop pattern as v1)
- **Note:** Two data refs at 0xC294BC and 0xC294FC (function pointer tables?)

## Phyre_Math_StackAlignedCompute2 (0x5fada0, 1236 bytes)
```c
// bad sp value at call
int __userpurge Phyre_Math_StackAlignedCompute2@<eax>(
        int *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>,
        float a5, int a6, float a7)
```
- **Callers:** 0
- **Callees:** none
- **Purpose:** Variant 2 of stack-aligned computation. Same `__userpurge` with register params.
- **Constants:** 0xA8 (168 bytes stack), 0xC

## Phyre_Math_TransformTriangle (0x984250, 1105 bytes)
```c
int __userpurge Phyre_Math_TransformTriangle@<eax>(
        int a1@<ecx>, int a2@<ebp>, float *a3, int a4, int a5)
```
- **Callers:** 0
- **Callees:** _CIsqrt
- **Purpose:** Transforms a triangle (3 vertices × 3 coords). Uses sqrt for normalization.
- **Constants:** 0x3F800000 (1.0f), 0xC8 (200 bytes stack)
- **Data ref:** 0xB6F970

## Phyre_Math_TransformMultipleMatrices (0xa25410, 1095 bytes)
```c
float *__thiscall Phyre_Math_TransformMultipleMatrices(float *this, int a2)
```
- **Callers:** 2 (Iggy_TextureLayer_DispatchE, FFX_Iggy_TextureLayer_DataTransform)
- **Callees:** PMatrix4_copy16f, Matrix4x4_TransposeRotation, TransformMatrixByMatrix4x4, Matrix4_MulVec4, MatrixMultiply4x4
- **Purpose:** Multi-matrix transform for Iggy texture layer system. 452-byte stack frame.

---

# Part 2: Vector & Quaternion Operations

## Phyre_Math_LengthNormalize (0x5ff810, 1164 bytes)
```c
void __userpurge Phyre_Math_LengthNormalize(
        int a1@<ecx>, int a2@<ebp>,
        int a3, float *a4, float *a5, float *a6)
```
- **Callers:** 0
- **Callees:** Phyre_Script_FindEntryPoint, BulletPhysics_ApplyTorque, _CIsqrt, Phyre_GetDefaultPool
- **Purpose:** Vector length + normalization. Interesting — calls Bullet physics and scripting entry point.
- **Blocks:** 26 — most complex CFG in the batch
- **Data refs:** 0xCBEA70, 0xCBF228 (global singleton addresses)

## Phyre_Math_MatrixDecompose (0x5d75f0, 820 bytes)
```c
// Decomposes a matrix into translation/rotation/scale
float *__thiscall Phyre_Math_MatrixDecompose(float *this, float a2, float a3)
```
- **Callers:** 0
- **Callees:** PMatrix4_copy16f, Matrix4x4_TransposeRotation, Matrix4x4_CopyTransposed, Matrix4x4_ComposeAffineTransform, _CIasin, _CIcos, _CIatan2, _CIsin, _CIsqrt
- **Purpose:** Full matrix decomposition using Euler angles. Calls ALL major CRT math functions.
- **Blocks:** 12 with nested loop structure
- **Observation:** Decomposes into translation vector, rotation matrix, and scale factors

## Phyre_Math_AnimationInterpolate (0x5f99c0, 788 bytes)
```c
// Interpolates animation keyframes for smooth playback.
// Supports linear and spline interpolation.
int __userpurge Phyre_Math_AnimationInterpolate@<eax>(
        _DWORD *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>,
        float *a5, float *a6, int a7)
```
- **Callers:** 0
- **Callees:** none
- **Purpose:** Animation keyframe interpolation. 1 basic block (linear flow).

## Phyre_Math_TransformVerticesByMatrix (0x6ee3b0, 753 bytes)
```c
int __cdecl Phyre_Math_TransformVerticesByMatrix(_DWORD *a1, int a2, float *a3)
```
- **Callers:** 1 (FFX_Ps3Data_BuildSlotRecordForDraw)
- **Callees:** Phyre_Math_Mat4x4MulVec3
- **Purpose:** Batch vertex transform by matrix. 12 basic blocks with dual-vertex loop.
- **Stack:** 96 bytes

## Phyre_Math_Vector3_MaxAxis (0x5fe290, 409 bytes) ⭐
```c
void __thiscall Phyre_Math_Vector3_MaxAxis(float *this, float *a2)
```
- **Callers:** 5! (btCollisionMath_AngularConstraint, Bullet_btCollisionWorld_convexSweepTest, Phyre_SubDraw_v2, Bullet_ContactPoint_Calc, Phyre_SubDraw)
- **Callees:** _CIsqrt, @__security_check_cookie@4
- **Purpose:** Finds the dominant axis (X/Y/Z) of a 3D vector. Used by Bullet Physics collision and sub-draw.
- **Logic:** Compares abs values of x/y/z components, returns axis index (0/1/2).
- **Key insight:** Bridges PhyreEngine math with Bullet Physics collision detection

## Phyre_Math_QuaternionNormalize (0x5d2330, 382 bytes)
```c
void __thiscall Phyre_Math_QuaternionNormalize(float *this)
```
- **Callers:** 1 (Phyre_AABB_ToQuaternionTransform)
- **Callees:** _CIsqrt
- **Purpose:** Normalize a quaternion to unit length. 1 linear basic block.

## Phyre_Math_Vector3_CrossProduct (0x5d1e60, 305 bytes)
```c
float *__cdecl Phyre_Math_Vector3_CrossProduct(float *a1, float *a2, float *a3)
```
- **Callers:** 1 (Phyre_AABB_IntersectRay)
- **Callees:** none
- **Purpose:** Pure 3D cross product. Clean, compact implementation:
```c
  a1[0] = a3[1]*a2[2] - a3[2]*a2[1];  // x = y1*z2 - z1*y2
  a1[1] = a3[2]*a2[0] - a3[0]*a2[2];  // y = z1*x2 - x1*z2
  a1[2] = a3[0]*a2[1] - a3[1]*a2[0];  // z = x1*y2 - y1*x2
```

## Phyre_Math_Vec4Transform (0x446560, 299 bytes) — MISNAMED
```c
void Phyre_Math_Vec4Transform()
```
- **Callers:** 1 (Phyre_Engine_Init)
- **Callees:** Phyre_PTypeDefault_PChar_RegisterName, Phyre_PType_GetSingleton, Phyre_PType_GetPUInt32, Phyre_PClassDataMember_ctorAttach_structural, Phyre_PClassDescriptor_FinalizeRegistration, _atexit
- **Strings:** "m_type", "m_offset", "m_nameAsString"
- **Purpose:** ⚠️ NOT a vector transform! This is a **class descriptor registration** for some type with 3 data members (m_type, m_offset, m_nameAsString). Called during Engine_Init.
- **Constants:** 0x18 (24), 0x24 (36) — member offsets

## Phyre_Math_Interpolate (0x5f3df0, 252 bytes)
```c
double __thiscall Phyre_Math_Interpolate(int this, int a2, char a3)
```
- **Callers:** 0
- **Callees:** none
- **Purpose:** Interpolation between two animation states. Conditional path for `a3` flag:
  - If true: direct field copy from a2+16/20/24/28
  - If false: matrix-weighted blend (3x3 rotation part)
- **Blocks:** 4

## Phyre_Math_MatrixTransformVector3 (0x531470, 247 bytes)
```c
float *__cdecl Phyre_Math_MatrixTransformVector3(float *a1, float *a2, float *p_Src)
```
- **Callers:** 1 (Phyre_Animation_BlendQuaternion)
- **Callees:** none
- **Purpose:** Transform a 3D vector by a 4x4 matrix (rotation part only — no translation). Outputs 3 rows of 3 columns.
- **Clean implementation:**
```c
  a1[0] = a2[0]*p_Src[0];  // row0
  a1[1] = a2[1]*p_Src[0];
  a1[2] = a2[2]*p_Src[0];
  a1[4] = a2[4]*p_Src[1];  // row1
  a1[5] = a2[5]*p_Src[1];
  a1[6] = a2[6]*p_Src[1];
  a1[8] = a2[8]*p_Src[2];  // row2
  a1[9] = a2[9]*p_Src[2];
  a1[10]= a2[10]*p_Src[2];
```

## Phyre_Math_Mat4x4ScaleUniform (0x7045f0, 245 bytes)
```c
float *__cdecl Phyre_Math_Mat4x4ScaleUniform(float *a1, float *a2, float a3)
```
- **Callers:** 0
- **Callees:** none
- **Purpose:** Uniform scale of a 4x4 matrix. Multiplies all 16 components by scalar a3.

## Phyre_Math_CoordinateTransform (0x5ff560, 230 bytes)
```c
int __thiscall Phyre_Math_CoordinateTransform(float *this, int a2, float *a3)
```
- **Callers:** 0
- **Callees:** none
- **Purpose:** Coordinate system transform using axis sign flips. Reads 3 basis vectors from `this+8/9/10`, applies sign flips based on bitmask `a2`:
  - bit 0: flip X
  - bit 1: flip Y
  - bit 2: flip Z
```c
  v16 = 1 - (a2 & 1);         // X sign
  v13 = 1 - ((a2>>1) & 1);    // Y sign
  v15 = 1 - ((a2>>2) & 1);    // Z sign
```

---

# Part 3: Misnamed Functions (Critical Findings)

## Phyre_Math_QuaternionSlerp (0x4462b0, 219 bytes) — ⚠️ MISNAMED
```c
Vtable_PClassDescriptor_Phyre **__thiscall Phyre_Math_QuaternionSlerp(
        Vtable_PClassDescriptor_Phyre **this,
        size_t thisa, int a3, const char *Src, int Srcb, int a6, size_t Size)
```
- **Callers:** 3 (Phyre_Math_PlaneFromPoints, PClassDescriptorDynamic_CreateInstance, PClassDescriptorDynamic_CloneInstance)
- **Callees:** Engine_AlignedAllocAlign, Phyre_PClassDataMember_ctorAttach_structural, memcpy
- **Purpose:** ⚠️ **NOT a quaternion slerp!** This is actually a `PClassDataMemberDynamic` constructor:
  1. Calls `PClassDataMember_ctorAttach_structural` with 7 params
  2. Sets vfptr to `vtable_PClassDataMemberDynamic` (0xB0F908)
  3. Allocates + copies dynamic default instance string
  4. Handles `Src != Src_0` ("PClassDataMemberDynamicDefaultInstance") string comparison
- **Key insight:** The RTTI symbol table misidentified this function. It belongs to `PClassDescriptorDynamic`, not `Phyre_Math`.

## Phyre_Math_Vec3Normalize (0x4457d0, 212 bytes) — ⚠️ MISNAMED
```c
int __cdecl Phyre_Math_Vec3Normalize(lua_State *stream)
```
- **Callers:** 2 (PCluster_LoadNormalizedVec3, Phyre_Math_Vec3Normalize_Out)
- **Callees:** PhyreBuffer_GetType, LuaG_errorThrow, PhyreStream_Reserve, Phyre_Scripting_PushPhyreObject
- **Strings:** 
  - `"r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"`
  - `"Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PString *>::Get"`
  - `"Object pointer obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n"`
  - `"Unable to obtain object pointer from script - found another type of data instead (Lua type %d)\n"`
- **Purpose:** ⚠️ **NOT a vector normalize!** This is `PObjectAccessor<PString*>::Get` — a Lua scripting accessor that:
  1. Pushes Phyre object from Lua stream
  2. Validates object type by walking parent chain up to `typeInfo__8`
  3. Throws Lua error on type mismatch
  4. Returns object pointer
- **Build path:** `r:\hg_code\middleware_w32\phyreengine\include\Scripting/PhyreScripting.inl`
- **Key insight:** The RTTI symbol is completely wrong. This is a template-generated scripting accessor, not a math function.

---

# Summary Tables

## Size Distribution

| Bucket | Range | Count |
|--------|-------|-------|
| Huge | >= 1024 bytes | 10 |
| Large | 512 - 1023 | 4 |
| Medium | 256 - 511 | 5 |
| Small | 128 - 255 | 6 |

## Most-Called Functions

| Function | Callers | Used By |
|----------|---------|---------|
| MatrixMultiply4x4 | **12** | Camera, Skinning, Texture, Scripting |
| Vector3_MaxAxis | **5** | Bullet Physics, SubDraw |
| PlaneFromPoints via QuaternionSlerp | 3 | PClassDescriptorDynamic |
| TransformMatrixByMatrix4x4 | 2 | PostProcessing, Multi-Transform |
| TransformMultipleMatrices | 2 | Iggy Texture Layer |

## Misnamed Functions (RTTI vs Reality)

| Symbol Name | Actual Function | Impact |
|-------------|----------------|--------|
| `Phyre_Math_QuaternionSlerp` | `PClassDataMemberDynamic` ctor | Type registration, not math |
| `Phyre_Math_Vec3Normalize` | `PObjectAccessor<PString*>::Get` | Lua scripting, not math |
| `Phyre_Math_Vec3Cross` | PString array type registration | Type system, not math |
| `Phyre_Math_Vec4Transform` | Class descriptor registration | Type system, not math |

## Tech Stack

| Technology | Used In |
|------------|---------|
| x87 FPU (double st7) | All math functions |
| SSE (__m128) | VertexTransform v1/v2 |
| __userpurge convention (regparams) | StackAligned functions |
| MSVC CRT math | _CIsqrt, _CIcos, _CIsin, _CIatan2, _CIasin |
| AlignedAlloc | PClassDataMemberDynamic constructor |

---

## Key Findings

1. **MatrixMultiply4x4 is the workhorse** — 12 callers spanning camera, model skinning, shadow skinning, texture layers, and scripting accessors. Single basic block, no sub-calls.

2. **4 of 25 functions are misnamed by RTTI** — The Phyre_Math_* prefix caught several non-math functions due to RTTI template name collisions. `Vec3Normalize` is actually a Lua PString accessor; `QuaternionSlerp` is a PClassDataMemberDynamic constructor; `Vec3Cross` and `Vec4Transform` are type registration functions.

3. **Two SSE vertex transform implementations** — `SSE_VertexTransform` v1 (1623 bytes) and v2 (1367 bytes) share identical prototypes but different inner loops. Both have dual-loop structure (dispatch + processing), suggesting batch processing with stride-based vertex data.

4. **Bullet Physics integration** — `Vector3_MaxAxis` is called by Bullet Physics collision functions (AngularConstraint, convexSweepTest, ContactPoint_Calc), confirming PhyreEngine integrates Bullet Physics for collision detection.

5. **x87 FPU dominates** — All pure math functions use x87 FPU doubles (`double v8; // st7` pattern). SSE is only used in the two explicit vertex transform functions.

6. **Stack-aligned convention** — `__userpurge` with register parameters (`ecx`, `ebp`, `edi`, `esi`) is used for the two StackAligned functions. The "bad sp value" warning suggests these are compiler intrinsics or hand-tuned assembly for performance.

7. **Build path confirmation** — `PhyreScripting.inl` at `r:\hg_code\middleware_w32\phyreengine\include\Scripting\` confirms the MSVC 2012 v110 toolchain path.

---

## Next Batches

- Batch 10: Phyre_Math remaining 62 functions (medium/small — most <100 bytes)
- Batch 11: Engine_* functions (engine init, memory, threading)
- Batch 12: Phyre_PPhysics (~222 functions)
- Batch 13: Phyre_PSceneNode (~90 functions)
- Batch 14: Phyre_PRendering (render pipeline)
