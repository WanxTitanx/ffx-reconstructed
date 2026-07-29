# FFX.exe Decompilation — Batch 8 (PAnimation + PInput + PGeometry)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 25 (PAnimation Curve/Target ops, PInput Device constructors, PGeometry ClassDescriptors)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers three PhyreEngine subsystems:
1. **PAnimation Curve** — interpolation, keyframe management, compilation
2. **PInput** — Keyboard/Mouse/Pad/Touch device constructors, timer init, mapper type registration
3. **PGeometry** — Vertex stream class descriptors, mesh data copy

---

# Part 1: PAnimation Curve System

## Phyre_PAnimationCurve_GetInterpolationType (0x50ab80, 163 bytes)
```c
int __thiscall Phyre_PAnimationCurve_GetInterpolationType(int *this, float a2, float *a3)
{
  int nKeys = *this;                       // key count
  int *pKeys = *(this + 2);                // key array ptr
  int low = 0;
  int high = nKeys - 1;
  float midVal = pKeys[high / 2];

  // Binary search for the key containing time a2
  while (low != high) {
    if (midVal <= a2)
      low = mid + 1;
    else
      high = mid - 1;
    mid = (low + high) / 2;
    midVal = pKeys[mid];
  }
  if (mid > 0 && midVal > a2)
    --mid;

  // Returns interpolation type based on found key
  // ...
}
```
- **Callers:** 1 (Phyre_PAnimationKey_RegisterDescriptor)
- **Callees:** none
- **Purpose:** Binary search for keyframe by time, returns interpolation type. Classic binary search on sorted float key array.
- **Constants:** 0x41, 0x8 (float/byte size)

## Phyre_PAnimationCurve_SetInterpolationType (0x50ac30, 156 bytes)
```c
unsigned int __thiscall Phyre_PAnimationCurve_SetInterpolationType(
    unsigned int *this, float a2, unsigned int a3, float *a4)
{
  // Clamp index, then forward/backward scan to find position
  // Update interpolation type at found position
}
```
- **Callers:** 1
- **Callees:** none
- **Purpose:** Sets interpolation type for a keyframe by index. Forward/backward scan from clamped index.
- **Observation:** Mirror of GetInterpolationType — write variant

## Phyre_PAnimationCurve_Compile (0x50afd0, 153 bytes)
```c
int __thiscall Phyre_PAnimationCurve_Compile(int *this, unsigned int a2)
{
  unsigned int v4 = *this & 0x7FFFFFFF;   // mask high bit
  if (a2 == *this) return 0;              // already compiled
  if (a2 < v4) v4 = a2;

  int *pNew = Engine_AlignedAllocAlign(4 * a2, 4);
  if (pNew)
    Phyre_PAnimationTarget_RemoveTarget(pNew, oldPtr, v4);

  // Free old buffer, assign new
  Engine_AlignedFree(oldPtr);
  this[1] = pNew;
  *this = a2;
  return 0;
}
```
- **Callers:** 1 (CompileWrapper)
- **Callees:** Engine_AlignedAllocAlign, Engine_AlignedFree, RemoveTarget
- **Purpose:** Compile/allocate animation curve buffer. Allocates aligned float array, copies old data via RemoveTarget, frees old buffer. High bit tracks "compiled" flag.
- **Constants:** 0x7FFFFFFF (mask), 0x4 (float size)

## Phyre_PAnimationCurve_GetKeyValue (0x50b1d0, 93 bytes)
```c
int __thiscall Phyre_PAnimationCurve_GetKeyValue(_DWORD *this, int a2, void *ptr, int a4)
{
  int *v4 = (int *)(a2 + this[9] - *(this[3] + 136));
  if (a4 < 0) return 5;
  // Free old, assign new
  Engine_AlignedFree(v4[1]);
  v4[1] = (int)ptr;
  *v4 = a4 | 0x80000000;   // set high bit
  return 0;
}
```
- **Callers:** none
- **Callees:** Engine_AlignedFree
- **Purpose:** Gets/sets keyframe value. Offset calculation involves this+9 relative to PClassDescriptor offset +136.
- **Constants:** 0x5 (error), 0x80000000 (high bit flag)

## Phyre_PAnimationCurve_AddKey (0x50b890, 82 bytes)
```c
_DWORD *__thiscall Phyre_PAnimationCurve_AddKey(_DWORD *this, _DWORD *src)
{
  if (this != src) {
    this[4] = src[4];
    *this = *src;
    this[1] = src[1];
    this[2] = src[2];
    this[3] = src[3];
    Phyre_Math_MatrixInverse(this + 5, (src[5] - (src[5] & 1)));
    this[6] = src[6];
  }
  return this;
}
```
- **Callers:** 5 (AddKey, GetValue, GetChannelType, GetSlotCount, GetSlotFlags)
- **Callees:** Phyre_Math_MatrixInverse
- **Purpose:** Copy keyframe data between curve instances. Copies 7 fields including matrix inverse transform.

## Phyre_PAnimationCurve_RemoveKey (0x50b910, 97 bytes)
```c
bool __thiscall Phyre_PAnimationCurve_RemoveKey(_DWORD *this, _DWORD *a2)
{
  return this[4] == a2[4]
      && *this == *a2
      && this[1] == a2[1]
      && this[2] == a2[2]
      && this[3] == a2[3]
      && PRendering_CollectLights(this + 5, (a2[5] - (a2[5] & 1)))
      && this[6] == a2[6];
}
```
- **Callers:** 2 (PAnimationSet_Compile, PAnimationDescriptor_SetName)
- **Callees:** PRendering_CollectLights
- **Purpose:** Compare two keys for equality. Compares 7 fields including a rendering light collection check.

---

# Part 2: PAnimation Target System

## Phyre_PAnimationTarget_FindTarget (0x508ed0, 25 bytes)
```c
int **__stdcall Phyre_PAnimationTarget_FindTarget(lua_State *stream, int **a2)
{
  int *vfptr = Phyre_PAnimationSlotListIndex_RegisterDescriptor_Sub(stream)->vfptr;
  *a2 = vfptr;
  return a2;
}
```
- **Callees:** RegisterDescriptor_Sub
- **Purpose:** Find animation target. Gets vfptr from slot list index.

## Phyre_PAnimationTarget_AddTarget (0x508ef0, 43 bytes)
```c
int *__stdcall Phyre_PAnimationTarget_AddTarget(lua_State *stream, int **a2)
{
  RegisterDescriptor_Sub = Phyre_PAnimationChannelTarget_RegisterDescriptor_Sub(stream);
  *a2 = RegisterDescriptor_Sub->vfptr;
  a2[1] = RegisterDescriptor_Sub->m_namespaceList;
  a2[2] = RegisterDescriptor_Sub->m_namespaceListPrev;
  a2[3] = RegisterDescriptor_Sub->m_nameString;
  return a2[3];
}
```
- **Callees:** RegisterDescriptor_Sub
- **Purpose:** Add animation target. Maps 4 PClassDescriptor fields to target entry.

## Phyre_PAnimationTarget_RemoveTarget (0x509060, 122 bytes)
```c
float *__cdecl Phyre_PAnimationTarget_RemoveTarget(float *dst, float *src, int n)
{
  // Unrolled loop: copy 4 floats per iteration
  for (int i = 0; i < n; ) {
    if (dst) *dst = *src++;
    if (dst != -4) dst[1] = *src++;
    if (dst != -8) dst[2] = *src++;
    if (dst != -12) dst[3] = *src++;
    i += 4;
    dst += 4;
  }
  return dst;
}
```
- **Callers:** 5 (CopyTargets, Curve_Compile, Source_GetValue, Source_SetValue, PostProcessing_BufferDeepCopy64)
- **Callees:** none
- **Purpose:** Copy n floats with null/invalid pointer checks. **Note:** `RemoveTarget` is a misleading name — it actually copies/removes target data (float array copy with sentinel checks).
- **Observation:** The `dst != -4/-8/-12` checks suggest an intrusive sentinel pattern in the float array

## Phyre_PAnimationTarget_FindTargetBySlot (0x509120, 118 bytes)
```c
PhyrePClassDescriptor *Phyre_PAnimationTarget_FindTargetBySlot()
{
  // Lazy singleton at 0xCA9AB0
  if ((unk_CA9B44 & 1) == 0) {
    unk_CA9B44 |= 1;
    Phyre_PArray_float4__PClassDescriptorAbstract_ctor(&MEMORY[0xCA9AB0]);
    unk_CA9B40 &= ~2u;
    MEMORY[0xCA9AB0].vfptr = &Phyre::PClassDescriptorConcrete<Phyre::PArray<float,4>>::vftable;
    atexit(Phyre_PClassDescDtor_PArray_Float_4);
  }
  return &MEMORY[0xCA9AB0];
}
```
- **Callees:** PArray_float4_PClassDescriptorAbstract_ctor, atexit
- **Purpose:** Lazy singleton for `PArray<float, 4>` class descriptor at 0xCA9AB0. Guard at 0xCA9B44.
- **Key insight:** Animation targets use `PArray<float, 4>` (4 floats = quaternion? or position+something?)

## Phyre_PAnimationTarget_ClearTargets (0x5091b0, 130 bytes)
```c
int __cdecl Phyre_PAnimationTarget_ClearTargets()
{
  // Same singleton pattern as FindTargetBySlot
  return Phyre_PClassDescriptor_GetTotalSize(&MEMORY[0xCA9AB0]);
}
```
- **Callers:** 6 (PArray_float4_ScriptAccessorRef_Get, etc.)
- **Callees:** PArray_float4_PClassDescriptorAbstract_ctor, PClassDescriptor_GetTotalSize, atexit
- **Purpose:** Clears all animation targets. Same lazy singleton at 0xCA9AB0, returns total allocated size.
- **Note:** Identical singleton init to FindTargetBySlot — both reference the same `PArray<float,4>` descriptor

## Phyre_PAnimationTarget_CopyTargets (0x509a70, 114 bytes)
```c
int *__thiscall Phyre_PAnimationTarget_CopyTargets(int *this, int *src)
{
  int n = src[0] & 0x7FFFFFFF;
  int *pNew = 0;
  if (n)
    Engine_AlignedAllocAlign(4 * n, 4);
    RemoveTarget(pNew, src[1], n);
  // Free old, assign new
  Engine_AlignedFree(this[1]);
  this[1] = pNew;
  *this = n;
  return this;
}
```
- **Callers:** 6 (GetViaScriptAccessor, RegisterAndGetRef, GetChannelType, HierarchyNode_Copy, etc.)
- **Callees:** Engine_AlignedAllocAlign, Engine_AlignedFree, RemoveTarget
- **Purpose:** Deep copy target array. Allocates new aligned buffer, copies via RemoveTarget, frees old.

---

# Part 3: PInput Device System

## Phyre_PInputMapper_RegisterType (0x622d20, 471 bytes) ⭐
```c
void Phyre_PInputMapper_RegisterType()
{
  // Register PInputMapper type with 1 data member: "m_inputMap"
  Phyre_PTypeDefault_PChar_RegisterName(&MEMORY[0xCC9E50]);
  if ((unk_CCA2B0 & 1) == 0) {
    unk_CCA2B0 |= 1;
    PClassDataMember_ctorAttach_structural(singleton, &MEMORY[0xCC9E50], PUInt32, "m_inputMap", 0, 2, 0);
    atexit(PClassDataMember_Dtor_byte_CCA284);
  }
  // Register 10+ Lua property accessors: getMouseX, getMouseY, getPadAxis,
  // getPadButton, setVibration, etc.
  Phyre_StringNode_Ctor(&MEMORY[0xCCA2B4], name, "getMouseX", 0);
  // ... (10+ accessor registrations)
}
```
- **Callers:** 1 (Scripting_PInputMapper_RegisterApiInit)
- **Callees:** 6 (RegisterName, FinalizeRegistration, StringNode_Ctor, FindByName, PClassDataMember_ctorAttach_structural, atexit)
- **Strings:** "m_inputMap", "getMouseX", "getMouseY", "getPadAxis", "getPadButton", "setVibration"
- **Purpose:** Registers PInputMapper type system + Lua scripting bindings. Registers 1 data member + 10+ property accessors.
- **Constants:** flag bits 0x1/0x2 (two-phase init)

## Phyre_PInputDevice_Base Constructor Pattern

All 4 input device constructors share a common base pattern:
1. Init linked list sentinels (self-pointing +4/+12 pairs)
2. Set vfptr to `g_vtable_PInputDevice_Phyre` (0xB3FC00)
3. Device ID assignment (a2 parameter)
4. Link into global device list at `off_C30FA4[0]`
5. Set device-specific destructor vtable
6. Zero-init device-specific memory (memset or vector constructor iterator)
7. Init sub-devices (vector ctor iterator)

### Phyre_PInputDeviceKeyboard_Constructor (0x6201b0, 126 bytes)
```c
char *__thiscall Phyre_PInputDeviceKeyboard_Constructor(char *this, int a2)
{
  // Base init: sentinels + vfptr + device ID + linked list
  // memset(this+536, 0, 256)  → 256 key state bytes
  // memset(this+24, 0, 256)   → 256 key state bytes
  // memset(this+280, 0, 256)  → 256 key state bytes
  return this;
}
```
- **Callers:** Factory
- **Callees:** memset
- **Key constant:** 0x100 (256) — 3× 256-byte key state buffers = 768 bytes
- **Size:** Total struct ~792+ bytes (base + 3×256 + fields)

### Phyre_PInputDeviceMouse_Constructor (0x620290, 199 bytes)
```c
char *__thiscall Phyre_PInputDeviceMouse_Constructor(char *this, int a2)
{
  // Base init + vector ctor iterator for 5 sub-devices × 48 bytes
  `eh vector constructor iterator'(this + 24, 0x30, 5, SubDeviceInit, nullsub_32);
  this[264] = 0;   // some field cleared
  this[268] = 0;   // some field cleared
  this[272] = 0;   // some field cleared
  return this;
}
```
- **Callers:** Factory
- **Callees:** vector constructor iterator
- **Key constants:** 5 sub-devices × 0x30 (48) bytes each
- **Size:** Total struct ~300+ bytes

### Phyre_PInputDevicePad_Constructor (0x620360, 374 bytes) ⭐
```c
char *__thiscall Phyre_PInputDevicePad_Constructor(char *this, int a2)
{
  // Base init + vector ctor iterator for 4 sub-devices × 48 bytes
  `eh vector constructor iterator'(this + 108, 0x30, 4, SubDeviceInit, nullsub_32);
  // Init axis configs, button states, timer, DirectInput state
  memset(this + 940, 0, 12);           // 12 bytes
  this[940] = 0;                        // DirectInput device ptr
  // ... axis configs, DPAD, threshold, vibration
  return this;
}
```
- **Callers:** FactoryOrInit
- **Callees:** vector constructor iterator, memset
- **Key constants:** 4 sub-devices × 0x30 bytes, +940 offset for DI device
- **Size:** Total struct ~1024+ bytes (largest input device)
- **Vtable:** Phyre::PFramework::PInputDevicePad::vftable (0xB3FCAC)

### Phyre_PInputDeviceTouch_Constructor (0x620570, 368 bytes)
```c
char *__thiscall Phyre_PInputDeviceTouch_Constructor(char *this)
{
  // Base init (device ID = 0)
  // Timer init call at offset +344 (float time values)
  // Touch state zero-init
  return this;
}
```
- **Callers:** none (likely constructed by factory)
- **Callees:** Phyre_Timer_GetTime, Phyre_Thread_TimedWaitOrSkip
- **Key constants:** float fields at +344 (timer state)
- **Vtable:** Phyre::PFramework::PInputDeviceTouch::vftable (0xB3FC54)

## Phyre_PInputDevice_TimerInit (0x620750, 248 bytes)
```c
_DWORD *__thiscall Phyre_PInputDevice_TimerInit(_DWORD *this)
{
  // Zero-init 160+ bytes of timer state
  // Sets *this through *(this+39) to 0
  // Then sets *(this+6) through *(this+27) to 0
  // Return this
}
```
- **Callers:** 2 (PApplication_Constructor, Template_GetVtablePtr_E)
- **Callees:** none
- **Purpose:** Zero-initialize timer state for an input device. No strings, no sub-calls.
- **Observation:** Pure memset-equivalent — the decompiler unpacked a large memset into field-by-field assignments

---

# Part 4: PGeometry Class Descriptors

## Phyre_PGeometry_PVertexStream_ClassDescriptor (0x4805d0, 376 bytes) ⭐
```c
void Phyre_PGeometry_PVertexStream_ClassDescriptor()
{
  // Register PVertexStream type with 4 data members
  Phyre_PTypeDefault_PChar_RegisterName(&MEMORY[0xC98730]);
  if ((dword_C987F0 & 1) == 0) {
    dword_C987F0 |= 1;
    PClassDataMember_ctorAttach_structural(..., "m_type", 8, 16, 0);
    atexit(Phyre_SingletonCall_5755E0_C987C4);
  }
  if (($v0 & 2) == 0) {
    dword_C987F0 |= 2;
    PClassDataMember_ctorAttach_structural(..., "m_offset", 0, 16, 0);
    atexit(Phyre_SingletonCall_57...);
  }
  if (($v0 & 4) == 0) {
    dword_C987F0 |= 4;
    // "m_renderDataType"
  }
  if (($v0 & 8) == 0) {
    dword_C987F0 |= 8;
    // "m_streamSet"
  }
  Phyre_PClassDescriptor_FinalizeRegistration(&MEMORY[0xC98730]);
}
```
- **Callers:** 1 (Rendering_RegisterGeometryClassDescriptors)
- **Callees:** 7 (RegisterName, GetPUInt8, GetPUInt32, PClassDataMember_ctorAttach_structural, GetSingleton, FinalizeRegistration, atexit)
- **Strings:** "m_type" (offset 8), "m_offset" (offset 0), "m_renderDataType" (offset 16), "m_streamSet" (offset 11)
- **Purpose:** Register PVertexStream class descriptor with 4 data members. Phased init with 4 flag bits (1/2/4/8).
- **Key insight:** m_offset=0, m_type=8, m_streamSet=11, m_renderDataType=16 — stream struct layout

## Phyre_PGeometry_PVertexStreamArray_ClassDescriptor (0x482040, 477 bytes) ⭐
```c
void Phyre_PGeometry_PVertexStreamArray_ClassDescriptor()
{
  // Register PArray<PVertexStream> type with 4 data members
  // Members: "m_memoryType" (offset 21), "m_stride" (offset 0),
  //          "m_elementCount" (offset 0), "m_streams" (offset 0)
  // Plus: PArray_PVertexStream_Init + PArray class descriptor init
}
```
- **Callers:** 1 (Rendering_RegisterGeometryClassDescriptors)
- **Callees:** 9 (RegisterName, GetPUInt8/32, ctorAttach, PArray_PVertexStream_Init, PClassDataMemberArray_Init, etc.)
- **Strings:** "m_memoryType", "m_stride", "m_elementCount", "m_streams"
- **Purpose:** Register `PArray<PVertexStream>` class descriptor. More complex — includes array initialization and member array setup.

## PGeometry Class Descriptor Registration Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| PVertexStream_ClassDescriptor | 0x4805d0 | 376 | Register PVertexStream type |
| PVertexStreamArray_ClassDescriptor | 0x482040 | 477 | Register PArray<PVertexStream> type |
| PMeshElementGroup_ClassDescriptor | 0x4971a0 | 376 | Register PMeshElementGroup type |
| PMeshDataCopy | 0x48f1b0 | 249 | Copy mesh data |
| PDataBlock_RegisterClassDescriptors | 0x55eae0 | 391 | Register PDataBlock types |
| PIndexDataBlock_RegisterClassDescriptors | 0x55ec90 | 391 | Register PIndexDataBlock types |
| PMeshData_RegisterClassDescriptors | 0x55ee20 | 321 | Register PMeshData types |

## PVertexStream Struct Layout
```
PVertexStream:
  +0x00: m_offset       (PUInt32)
  +0x08: m_type         (PUInt8)
  +0x0B: m_streamSet    (PUInt8 or smaller)
  +0x10: m_renderDataType (PRenderDataType)
```

---

## Key Findings

1. **Animation curve binary search** — `GetInterpolationType` uses classic binary search on sorted float key array. Keyframes are sorted by time.

2. **`PArray<float,4>` as animation target** — FindTargetBySlot and ClearTargets both use the same lazy singleton at 0xCA9AB0 for `PArray<float,4>` class descriptor. The 4 floats likely represent position data (xyzw? or quaternion?).

3. **Input device hierarchy** — Keyboard (792+ bytes), Mouse (300+ bytes), Pad (1024+ bytes), Touch (368+ bytes). All share base pattern: sentinel init → vfptr → device ID → global linked list → sub-device init.

4. **Pad is the most complex input device** — 4 sub-devices, DirectInput pointer, axis configs, DPAD, threshold, vibration. Largest struct at ~1KB.

5. **Keyboard has 768 bytes of key state** — 3× 256-byte memset blocks (current state, previous state, and another buffer).

6. **Global device list** at `off_C30FA4[0]` — intrusive linked list of all input devices. Inserted during construction.

7. **Input mapper registers 10+ Lua accessors** — `getMouseX/Y`, `getPadAxis/Button`, `setVibration`. Two-phase init with flags 0x1/0x2.

8. **PVertexStream struct** — 4 fields: m_offset (0), m_type (8), m_streamSet (11), m_renderDataType (16). Compact vertex layout descriptor.

9. **Geometry class descriptors** — Phased registration with flag bits 1/2/4/8. Each phase registers one data member + atexit cleanup.

---

## Next Batches

- Batch 9: Engine_* functions (engine init, memory, threading)
- Batch 10: Phyre_PMath functions (Matrix, Vector, Quaternion)
- Batch 11+: PSceneNode, PRendering, PPostProcessing
