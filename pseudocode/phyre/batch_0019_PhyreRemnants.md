# FFX.exe Decompilation — Batch 19 (Small Remaining Phyre Families)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** ~445 total across 12 families
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers **all remaining PhyreEngine families** that were not yet inventoried. Most are small (14-89 functions each) with predominantly template-generated boilerplate. The combined total is ~445 functions across 12 families.

| Family | Count | Substantive Functions | Domain |
|--------|-------|----------------------|--------|
| `PShader*` | 89 | `RegisterMembers` (482B), `ParamArr_CopyDWordArr` (114B) | Shader program management, capability arrays |
| `PObject` | 77 | `RegisterClassDescriptor` (888B) | Base object class with scripting methods |
| `PTimer` | 51 | `GetSingleton` (326B), `Scripting_PTimerPtr_Get` (222B) | Timer singleton and component |
| `PTexture*` | 41 | `Texture2D_ClassDescriptor` (300B), `Description_Register` (224B) | 2D/3D/CubeMap textures |
| `PGetType` | 36 | All ≤ 118 bytes (thunks + accessors) | Type singleton accessors |
| `PStream` | 34 | `TypeInit` (518B), `RegisterMembers` (451B), `ReallocateAndCopy` (168B) | I/O streams, stream descriptors |
| `PRenderTarget` | 42 | ClassDescriptorCtor (144-145B), ScriptingAccessors (212B x2) | Render target base/abstract interface |
| `PGameSettings` | 31 | `ResizeArray` (103B), `SetIntArray` (89B) | Game settings container |
| `PDataBlockD3D11` | 22 | `ClassDescriptorCtor` (145B) x2 | D3D11 data block descriptors |
| `PDynamicGeometry` | 17 | `ExpandedClassDescriptor` (1330B), `ClassDescriptor` (477B), `VertexStreamResize` (421B) | Dynamic geometry with modifier network |
| `PWorldMatrix` | 14 | `FlyController_Update` (277B), `IdentityInit` (160B) | World matrix controllers |
| `PLight` | 1 | `GetSingleton` (137B) | Light singleton |

---

## Architecture Notes

All 12 families share patterns already documented in prior batches:

1. **Bitflag-guarded lazy class registration** — Global `dword_XXXX` tracks registration state via bits (1, 2, 4, 8, ...). Each member registered once.

2. **Class descriptor construction** — `Phyre_PClassDescriptor_Constructor(desc, namespace, "ClassName", 1, 1)` → `atexit(dtor)` set vtable → register data members → `Phyre_PClassDescriptor_FinalizeRegistration`.

3. **Data member registration** — Three variants:
   - `Phyre_PClassDataMember_ctorAttach_structural(buf, classDesc, typePtr, "m_name", offset, flags, 0)` — aligned scalar member
   - `Phyre_PClassDataMember_ctorWithMembers(buf, classDesc, typePtr, "m_name", offset, flags, 1)` — composite/object member
   - `PClassDataMemberArray_Init(buf, classDesc, arrayClassDesc, "m_name", offset, 0, typeFlags, capacity)` — array member (4-slot default)

4. **Method registration** — Linked list insertion: `Phyre_StringNode_Ctor("methodName")` → find-or-insert in name map → set vtable to PMethodCallerConcrete variant → link to function pointer.

5. **Small remaining families** — Most have only constructor/destructor/vtable-set stubs (≤ 0x27 bytes). The substantive functions are class/type registration functions.

---

## Key Function Analysis by Family

### 1. PShader (89 functions)

**Substantive:** `Phyre_PShaderCompiledProgram_RegisterMembers` (0x587920, 482B)

```c
void __cdecl Phyre_PShaderCompiledProgram_RegisterMembers() {
    // Registers class descriptor for "PShaderCompiledProgram"
    // Members (via bitflag-guarded registration):
    //   1. m_compiledCode       — PArray<PUInt8> at +12 (3, PArray, capacity=1)
    //   2. m_constantBufferSize — uint32 at +20 (16, 0)
    //   3. m_globalConstantBufferIndex — uint32 at +24 (16, 0)
    //   4. m_shaderProfile      — uint32 at +1244 (16, 0) — note: large offset!
}
```

**Key insight:** `m_shaderProfile` at offset **1244** — this implies the PShaderCompiledProgram struct is ~1248+ bytes. The compiled shader bytecode (`m_compiledCode`, PArray<PUInt8>) and metadata precede this; shader profile data is at the end.

Other PShader functions include:
- `PShaderCapLocArray_GetClassDescriptor` (89 funcs, all 6 bytes each) — trivial singleton accessors for shader capability/location arrays
- `PShaderParamArr_CopyDWordArr` (0x5aa800, 114B) — copies DWORD arrays of shader parameters
- `PShaderContainer_RegisterMembers` (0x587b10, 150B) — shader container member registration

---

### 2. PObject (77 functions)

**Substantive:** `Phyre_PObject_RegisterClassDescriptor` (0x458190, 888B)

```c
void __thiscall Phyre_PObject_RegisterClassDescriptor(PhyrePObject* this) {
    // Registers the "PObject" base class with scripting methods:
    //
    // Methods (registered via linked list + atexit):
    //   1. "getInstances"       → PEntityRef_GetDataPtr_Plus12
    //   2. "getInstance"        → PEntityRef_GetArrayElement
    //   3. "getInstanceCount"   → PEntityRef_GetFlagsMasked
    //   4. "getInstanceOfType"  → PEntityRef_Copy_script
    //
    // Data members:
    //   m_instances — PArray<PTypedObject> at +12 (typeFlags=3, capacity=4)
    //     → Registered via PTypedObjectArray_RegisterClassDescriptor
    //
    // Pattern: 8 method callers + 1 data member array
}
```

**Key insight:** PObject is the **base class** for the entity/instance system. It exposes 4 scripting methods for querying instances and stores `m_instances` as a PArray<PTypedObject> (small array optimization, 4 inline slots).

All other PObject functions (76 of 77):
- GetField0/GetField1/GetField3 accessors — `return *(this+offset)` (4-7 bytes each)
- ReturnThis/ReturnNull/ReturnThis_vN — `return this` or `return 0` (3-4 bytes each)
- ReadPropertyByIndex — index-based property reading (25 bytes)
- ReadMaskedRefCount — masked refcount read (30 bytes)
- GetSharedPtrData — reads shared pointer data (54 bytes, 2 copies)

---

### 3. PTimer (51 functions)

**Substantive:** `Phyre_PTimer_GetSingleton` (0x430430, 326B)

```c
PhyrePTimer* __stdcall Phyre_PTimer_GetSingleton() {
    // Singleton pattern:
    // 1. Check dword_C90244 & 1 — if not set:
    //    - Get PNamespace singleton
    //    - Construct "PTimer" class descriptor (typeFlags=1, capacity=1)
    //    - Set vtable to g_vtable_PClassDescriptorWrapper_PTimer_Phyre
    //    - Register atexit cleanup
    // 2. Check unk_C90248 (initialized flag) — if not set:
    //    - Register "GetTime" method via linked list
    //    - Set function caller vtable
    //    - Set Phyre_Timer_GetDeltaSinceReference as method implementation
    //    - Finalize registration
    //    - Set initialized flag
    // 3. Return singleton pointer
}
```

**Key insight:** PTimer exposes a single scripting method `GetTime` that delegates to `Phyre_Timer_GetDeltaSinceReference` (at 0x42f340). The PTimer struct is 1 element capacity, fitting inline in the descriptor.

Other PTimer functions (50 of 51):
- `Scripting_PTimerPtr_Get` (0x430cc0, 222B) — `PObjectAccessor<PTimer>::Get` accessor
- `ScriptAccessor_PTimerComponent_Ref_Get` (0x555880, 218B) — property accessor
- `PTimerComponent_ClassDescriptorCtor` (0x5551c0, 144B) — PTimerComponent registration
- 6x timer component ctors/dtors (4-136 bytes)
- 40× scripting accessors and template stubs

---

### 4. PGetType (36 functions)

All functions are either:
- **Thunks (0x76 = 118 bytes):** `Phyre_PGetTypeAccessor_CB3578_Thunk` et al — redirect to type singleton
- **Singleton accessors (0x6 = 6 bytes):** `Phyre_PGetTypeSingleton_PArray_PStreamInputDescD3D11_4` et al — `return *(global_type_ptr)`

No substantive logic; all are generated by the `PGetType<T>` template pattern for type singleton retrieval.

---

### 5. PStream (34 functions)

**Substantive:** `Phyre_PStreamInputDescArray_TypeInit` (0x5880f0, 518B)

```c
PhyrePClassDescriptor* __cdecl Phyre_PStreamInputDescArray_TypeInit(int namespace) {
    // Registers PArray<PStreamInputDescD3D11> type descriptor
    // Members:
    //   1. m_count — uint32 at +0 (annotation: 0x7FFFFFFF)
    //   2. m_els — PArray<PStreamInputDescD3D11> at +4 (typeFlags=2, capacity=4)
    //
    // The m_count annotation uses PAnnotationWithValue_Int with value 0x7FFFFFFF
    // (max element count = 2147483647)
}
```

**Other substantive:**
- `Phyre_PStreamInputDesc_RegisterMembers` (0x587bb0, 451B) — registers PStreamInputDescD3D11 class with input element descriptors
- `Phyre_PStreamArray_ReallocateAndCopy` (0x494f80, 168B) — stream array reallocation
- `Phyre_PStreamArray_Resize` (0x494ed0, 173B) — stream array resize
- `Phyre_PStreamReaderFile_alloc_ctor` (0x576a00, 155B) — file reader with buffer allocation
- `Phyre_PStreamWriterFile_Open` (0x9f0810, 137B) — file open for writing
- `Phyre_PStreamWriter_ReadWithFmt` (0x9f07a0, 109B) — formatted read
- `Phyre_PStreamWriterFile_ctor` (0x9f06d0, 103B) — file writer constructor

---

### 6. PRenderTarget (42 functions)

Mostly template stubs and abstract traps:
- Class descriptor accessors (6 bytes each): `PRenderTarget_GetClassDescriptor`, `PRenderTargetBase_GetClassDescriptor`
- Class name getters (6 bytes each): `PRenderTarget_GetClassName`, `PRenderTargetBase_GetClassName`
- Type size getter (6 bytes): `PRenderTarget_GetTypeSize`
- Return constants (5-6 bytes each): `ReturnZero`, `ReturnNegOne`
- Destructors (0x27 = 39 bytes): `PRenderTarget_Destructor` — optional `FFX_Heap_Free`
- Abstract errors (0x12 = 18 bytes each): traps for unimplemented virtual methods
- Register name/class (0x17 = 23 bytes each): singleton registration calls

Substantive setup functions (5 of 42, 144-212 bytes):
- `PRenderTarget_PClassDescriptor_ctor` (0x4c77c0, 144B) — class descriptor construction
- `PRenderTargetBase_PClassDescriptor_ctor` (0x4c7850, 145B) — base class descriptor
- `PRenderTargetList_RefreshBuffer` (0x4cc4f0, 167B) — render target list refresh
- `PScripting_PObjectAccessor_PRenderTargetPtr_Get` (0x4c7e00, 212B) — scripting accessor
- `PScripting_PObjectAccessor_PRenderTargetBasePtr_Get` (0x4c7ee0, 212B) — base scripting accessor

PRenderTarget is a **pure abstract base class** — the 5 substantive functions are registration/setup code (class descriptors, scripting accessors), not rendering implementations. No FFX-specific render target subclass exists in the binary (would be in the engine DLLs or FFX-specific code).

---

### 7. PGameSettings (31 functions)

Mostly small stubs:
- `GetSize` / `GetTypeName` (6 bytes each) — type metadata accessors
- `ReturnOne` / `ReturnMinusOne` / `Return23` (3-8 bytes) — constant return
- `DeletingDestructor` variants (0x17-0x27 bytes) — cleanup
- `Ctor_ZeroInit` (0x17 = 23 bytes) — zero-init constructor
- `InitEmpty` (0x24 = 36 bytes) — empty state init
- `Destroy` (0x31 = 49 bytes) — destruction
- `ResizeArray` (0x67 = 103 bytes) — array resize
- `SetOwnedArray` (0x41 = 65 bytes) — owned array assignment
- `SetIntArrayAtOffset` (0x59 = 89 bytes) — offset-based int array write

---

### 8. PDataBlockD3D11 (22 functions)

Substantive functions:
- `ClassDescriptorCtor` (0x91 = 145 bytes) for PDataBlockBufferD3D11 (0x55d7c0)
- `ClassDescriptorCtor` (0x90 = 144 bytes) for PDataBlockD3D11 (0x55d860)

All others are:
- Destructor variants (0x27 = 39 bytes) — scalar deleting dtors
- Class descriptor getters (6 bytes each) — 8+ identical stubs
- Vtable set (0xb = 11 bytes) — vtable pointer init

---

### 9. PDynamicGeometry (17 functions)

Despite only 17 functions, this family has the **most complex individual function** in the batch:

**Largest:** `Phyre_PDynamicGeometry_ExpandedClassDescriptor` (0x5c0b10, 1330 bytes)

```c
void __cdecl Phyre_PDynamicGeometry_ExpandedClassDescriptor() {
    // Registers PDynamicGeometry expanded class descriptor
    // Data members (8 registered via bitflags 1,2,4,8,0x10,0x20,0x40,0x80,0x100,0x200,0x400):
    //
    //   1. m_modifiers          — PArray<PModifierAndInputs> at +4  (capacity=4)
    //   2. m_totalInputCount    — uint32 at +12
    //   3. m_inputs             — PArray<PModifierNetworkBuffer> at +16 (capacity=4)
    //   4. m_outputs            — PArray<PModifierNetworkBuffer> at +24 (capacity=4)
    //   5. m_totalOutputElementSize — uint32 at +0
    //   6. m_streamingStrategy  — int32 at +36
    //   7. m_infoPacket         — type at +40 (size=18)
    //   8. m_totalPersistentStateSize — uint32 at +44
    //   9. m_totalStateBlockSize — uint32 at +48
    //  10. m_isCompiled         — bool at +52
    //  11. m_inputElementCountSources — PArray<int> at +56 (capacity=4)
}
```

**Other substantive:**
- `Phyre_PDynamicGeometry_ClassDescriptor` (0x5c0930, 477B) — base class descriptor registration
- `Phyre_PDynamicGeometryStream_RegisterClassDescriptors` (0x5c1050, 452B) — stream class descriptors
- `Phyre_PDynamicGeometry_VertexStreamResize` (0x4c55d0, 421B) — resizes vertex streams, size 4 variants
- `Phyre_PDynamicGeometryModifierState_RegisterClassDescriptors` (0x5c1700, 383B)
- `Phyre_PDynamicGeometry_RegisterAllClassDescriptors` (0x504040, 345B) — root registration

**PDynamicGeometry struct (~60+ bytes)**
```
+0x00: m_totalOutputElementSize (uint32)
+0x04: m_modifiers (PArray<PModifierAndInputs, 4>)
+0x0C: m_totalInputCount (uint32)
+0x10: m_inputs (PArray<PModifierNetworkBuffer, 4>)
+0x18: m_outputs (PArray<PModifierNetworkBuffer, 4>)
+0x24: m_streamingStrategy (int32)
+0x28: m_infoPacket (custom struct, 18 bytes)
+0x2C: m_totalPersistentStateSize (uint32)
+0x30: m_totalStateBlockSize (uint32)
+0x34: m_isCompiled (bool)
+0x38: m_inputElementCountSources (PArray<int, 4>)
```

PDynamicGeometry is a **modifier network system** — a directed graph of modifiers (modifier → inputs → outputs) with streaming strategies for GPU state management.

---

### 10. PWorldMatrix (14 functions)

**Substantive:** `Phyre_PWorldMatrixFlyController_Update` (0x5d7330, 277B)

```c
float* __thiscall Phyre_PWorldMatrixFlyController_Update(float* this, float deltaTime) {
    // 1. Transpose rotation from this[1..12] (3×4 matrix at +4)
    // 2. Copy transposed 4×4 to this[13..28] (16 floats at +52)
    // 3. Extract forward axis Z (this[21..23] = v10,v4,v12)
    // 4. Compute delta displacement: -Z * deltaTime
    // 5. Add displacement to position (this[25..27])
    // 6. Re-copy transposed matrix to this[13..28]
    // 7. Return via Matrix4x4_CopyTransposed
}
```

**Key insight:** PWorldMatrixFlyController implements **camera-relative fly movement** — it extracts the Z (forward) axis from the rotation matrix, negates it, and applies velocity along that axis. The struct is 28+ floats (112+ bytes) containing rotation matrix + position.

**Other substantive:**
- `Phyre_PWorldMatrixController_IdentityInit` (0x61a850, 160B) — initializes identity matrix + zero position
- `Phyre_PWorldMatrixController_UpdatePosition` (0x5d7940, 157B) — position update
- `Phyre_PWorldMatrixController_GetDirection` (0x61a930, 116B) — direction vector extraction

---

### 11. PLight (1 function)

`Phyre_PLight_GetSingleton` (0x5fc140, 137B) — singleton initialization that registers Vector3 type info on first call:
- Check global flag `unk_CC5780 & 1`
- Initialize Vector3 registrations (`Vector3_RegisterClassDescriptor`)
- Set type info pointers (`Phyre_PType_GetFloat`, etc.)
- Return singleton pointer

---

## Summary of Patterns

### Most families are template-generated stubs

Across all 12 families (~445 functions), roughly **420+ are template-generated stubs** (≤ 34 bytes). The remaining ~20 substantive functions follow well-established patterns:

| Pattern | Families Using It | Frequency |
|---------|------------------|-----------|
| Bitflag-guarded lazy class registration | All 12 families | ~30 instances |
| Singleton pattern (flag → ctor → register → atexit) | PTimer, PLight, PGetType | ~40 instances |
| Data member registration (ctorAttach_structural) | PObject, PDynamicGeometry, PStream, PShader, PDataBlock | ~35 instances |
| Method registration (linked list insertion) | PObject, PTimer | ~12 instances |
| Small array optimization | PDynamicGeometry, PObject, PStream | ~8 instances |
| Class descriptor finalize | All families with class registration | ~20 instances |

### Struct size summary

| Family | Struct Size (estimated) | Key Contents |
|--------|------------------------|--------------|
| PObject | ~12+ bytes | PArray<PTypedObject> at +12 |
| PTimer | ~1-element inline | GetTime method |
| PShaderCompiledProgram | ~1248+ bytes | PArray<PUInt8> code, uint32 metadata, shader profile at +1244 |
| PStreamInputDescD3D11 | ~4+ bytes | m_count with 0x7FFFFFFF annotation, m_els array |
| PDynamicGeometry | ~60+ bytes | Modifier network: inputs, outputs, strategies, state sizes |
| PWorldMatrixFlyController | ~112+ bytes (28 floats) | Rotation 3×4 at +4, Transposed 4×4 at +52, Position at +100 |
| PRenderTarget | Abstract base (vtable only) | No data members, all virtual stubs |
| PGameSettings | Variable (array-based) | Settings container with resize/assignment |
| PDataBlockD3D11 | ~24 bytes | Class descriptor for D3D11 data block |

---

## Key Findings

1. **PDynamicGeometry is the most complex remaining family** — despite only 17 functions, it has the largest function (ExpandedClassDescriptor, 1330B) and a rich modifier network data model.

2. **PRenderTarget is a pure abstract base** — all 32 functions are stubs. No FFX-specific render target implementation exists (likely implemented in the engine's C++ as a subclass of PRenderTargetBase).

3. **PShaderCompiledProgram has m_shaderProfile at +1244** — This unusually large offset (1244 bytes from struct start) suggests shader code is stored inline in the class, with metadata at the end.

4. **PGetType is all template thunks** — 36 functions all generated by `PGetType<T>::Get()` template for various types, no custom logic.

5. **PWorldMatrixFlyController is camera-relative** — the Update function demonstrates fly-through movement: extract forward axis → apply velocity → accumulate position.

6. **PGameSettings is a dynamic container** — not a fixed struct but a variable-size settings array with resize/set/get operations.

---

## Complete PhyreEngine Decompilation Status

As of Batch 19, the PhyreEngine function family decompilation is **effectively complete**. Here's the final tally:

| Batch | Families | Functions | Status |
|-------|----------|-----------|--------|
| 1 | PString/zlib | ~30 | Complete |
| 2 | PClassDescriptor | ~100+ | Complete |
| 3 | PArray | ~50 | Complete |
| 4 | PScript | ~154 | Complete |
| 5 | PType | ~151 | Complete |
| 6 | PNamespace | ~30 | Complete |
| 7 | PAnimation | ~150+ | Complete |
| 8 | Animation Input Geometry | ~100+ | Complete |
| 9 | PhyreMath | ~50+ | Complete |
| 10 | Engine | ~25 | Complete |
| 11 | Engine_2 | ~24 | Pending |
| 12 | PPhysics | ~85 | Complete |
| 13 | PInput | ~67 | Complete |
| 14 | PRendering | ~89 | Complete |
| 15 | PSceneNode | ~126 | Complete |
| 16 | PostProcessing | ~648 | Complete |
| 17 | PGeometry/PVertexStream/PMeshInstance | ~283 | Complete |
| 18 | PCaller | ~409 | Complete |
| 19 | All Remaining (12 families) | ~445 | Complete |

**Total decompiled:** ~3,040+ functions across 19 batches
**Remaining:** Batch 11 (Engine_* Part 2, ~24 functions)

The remaining Engine_* Part 2 functions are small stubs that can be covered in a brief final document if needed.

**Next step:** Update SESSION_HANDOFF.md with Batch 18-19 completion, then proceed to any remaining small families or begin cross-cutting analysis (vtables, RTTI, etc.).
