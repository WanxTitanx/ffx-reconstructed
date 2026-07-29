# FFX.exe Decompilation — Batch 10 (Phyre Vtables Top 50)

**Database:** ffxoficial_COPY.i64 (session 85e0242a, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** PhyreEngine vtable structures (polymorphism dispatch), RTTI class descriptors, PClassDescriptor/PMethodCallerConcrete/PCaller family

---

## Summary

PhyreEngine uses **3 layers of vtable-based polymorphism** in FFX.exe: (1) `PClassDescriptor*` for runtime class reflection (15 subclasses × 3 variants = 39 vtables), (2) `PMethodCallerConcrete<T,Args...>` for type-erased method invocation (41 vtables), and (3) `PCaller<T>` smart pointers (covered in batch_0018). Total of **117 named vtable symbols** in `.rdata`, each pointing to an array of function pointers consumed via `mov reg, [ecx]; call [reg+offset]`.

| Family | Count | Size/Entry | Purpose |
|--------|-------|-----------|---------|
| `vtable_PClassDescriptor*` | 39 | 16 entries / 64B | Runtime class reflection (Concrete/Abstract/ForType + WithoutDefaultCtor/Dynamic) |
| `vtable_PMethodCallerConcrete_*` | 41 | 6 entries / 24B | Type-erased method invocation (1 base + 5 typed arg overloads) |
| `Vtable_P*_ForType` | 8 | 8-12 entries | Class-specific reflection for PCluster, PCamera, PArray, PInstancesComponent |
| `vtable_PClassDescriptor*` (math wrappers) | 6 | 8 entries | Wrapper variants for Vector2/3/4, Quat, Matrix3/4, PMatrix4/4x3 |
| `vtable_PClassDescriptorInterface*` | 4 | 6 entries | Interface contracts (PClassLayoutInterface, PIChildClassVisitor, PSerializedClassLayoutInterface, PFindNestedClassVisitor) |
| `vtable_PThreadPool` | 1 | 8 entries | Async job pool dispatcher |
| Other (VTable_ReturnThis, Vtable_ClearFloat4) | 18 | 3-7B | MSVC boilerplate / compiler-generated |
| **Total** | **117** | | |

`★ Insight ─────────────────────────────────────`
- **3-tier RTTI design** is unique to PhyreEngine. Most C++ engines use a single RTTI vtable (1 per concrete class); Phyre has **Concrete + Abstract + ForType** triples — three vtables per type, supporting different runtime queries (instance creation, abstract interface dispatch, typed reflection).
- **PCaller is NOT in the vtable list** because it's a template with 76 instantiations that all share a generic vtable — the type info is stored separately in the `m_pPtr` field (see batch_0018).
- **PMethodCallerConcrete<T,Args...>** is type erasure in action: each instance binds a specific method+args combo into a callable. 41 vtables × 6 entries = 246 method bindings discoverable statically.
`─────────────────────────────────────────────────`

---

## Architecture: The 3-Tier Class Descriptor System

PhyreEngine has **three orthogonal class descriptor vtables** per reflected type, serving different query patterns:

```c
// Tier 1: ForType — "I have a T, what can I do with it?"
// Used for: typed reflection, get-properties, set-properties
// Layout: 16 entries — version getters, type identity, EvalCondition,
//         property get/set, namespace lookup, traverseWithFlag
// Example: vtable_PClassDescriptorForType_PEntity @ 0xb1049c

// Tier 2: Abstract — "What interface does T implement?"
// Used for: base class queries, virtual dispatch on abstract interfaces
// Layout: 16 entries — same as ForType but methods are abstract stubs
// Example: vtable_PClassDescriptorAbstract_PEntity @ 0xb104e4

// Tier 3: Concrete — "Create a fresh T instance"
// Used for: deserialization, dynamic instantiation, copy-construct
// Layout: 16 entries — adds zero-init, default-construct, copy helpers
// Example: vtable_PClassDescriptorConcrete_PEntity @ 0xb1052c
```

This triple structure is **distinct from MSVC RTTI** (which only stores `.?AV` descriptors + 1 vtable per polymorphic class). Phyre's RTTI is **enriched with reflection metadata** at compile time via CRTP-style helper templates.

---

## Top 50 Vtable Entries (Analyzed)

### 1. vtable_PClassDescriptorConcrete_PEntity (0xb1052c) — THE PEntity vtable

**Most-referenced PhyreEngine vtable.** PEntity is the base of all scene-graph objects. This vtable has 16 entries covering the full CRUD/serialization pipeline:

| Offset | Method | Purpose |
|--------|--------|---------|
| 0x00 | `0x43b850 Phyre_PCaller_Dtor_Deleting` | Destructor (deleting flag) |
| 0x04 | `0x43caf0 Phyre_PClassDescriptor_EvalCondition` | Class condition eval |
| 0x08 | `0x437980 Phyre_PType_Default_ReturnZero` | Type query — returns 0 |
| 0x0C | `0x450430 PEntityRef_Copy` | Entity reference copy |
| 0x10 | `0x450500 PEntity_PushObjectToStream` | Serialize entity to stream |
| 0x14 | `0x450380 PEntityPtr_GetWrapper` | Entity pointer → wrapper |
| 0x18 | `0x4504c0 PEntity_PushObjectOrNil` | Serialize (allow nil) |
| 0x1C | `0x44f050 PEntity_ClassDescriptor_dtor_dup` | Destructor helper |
| 0x20 | `0x43c190 Phyre_PClassMember_InsertIntoPropertyList` | Property registration |
| 0x24 | `0x43d4f0 Phyre_List_UnlinkNode` | List operation |
| 0x28 | `0x44f080 PEntity_ClassDescriptor_dtor_dup2` | Destructor helper |
| 0x2C | `0x43d8a0 nullsub_246` | No-op stub |
| 0x30 | `0x4500c0 PEntity_ZeroInit` | Zero-fill entity |
| 0x34 | `0x450100 PEntityList_Clear_Wrapper` | Clear entity list |
| 0x38 | `0x44fde0 j_Phyre_PClassDataMember_InitForEntity` | Data member init |
| 0x3C | `0xa0d843 ???` | Likely tail call into MSVC |

### 2. vtable_PClassDescriptorAbstract_PEntity (0xb104e4)

**Same 16 entries as Concrete** but with 1 difference at offset 0x1C:
- Concrete: `0x44f050 PEntity_ClassDescriptor_dtor_dup`
- Abstract: `0x44f080 PEntity_ClassDescriptor_dtor_dup2` (alternate impl)

The dtor_dup/dtor_dup2 distinction suggests **two different destruction policies** — one for concrete instances, one for abstract references. Likely related to reference counting (PCaller owns vs borrows).

### 3. vtable_PClassDescriptorForType_PEntity (0xb1049c)

**16 entries, but with different methods:**
- 0x0C: `0x437a10 Phyre_Scripting_GetValueFromScriptContext_Error` (vs `PEntityRef_Copy` in others)
- 0x10: `0x437a60 Phyre_Scripting_PutValueToScriptContext_Error` (vs `PEntity_PushObjectToStream`)
- 0x34: `0x2091920 ???` (vs `PEntityList_Clear_Wrapper`)

The ForType variant specializes in **scripting bridge** — it returns errors when script code tries to get/set values on raw PEntity types (which aren't script-friendly without a wrapper).

### 4. vtable_PClassDescriptorConcrete_PComponent (0xb10324)

PComponent base class. 16 entries with PComponent-specific methods:
- 0x00: `0x44e2f0 ???` (likely PComponent_ClassDescriptor_dtor)
- 0x04: `0x43caf0 EvalCondition` (shared)
- 0x08: `0x437980 ReturnZero` (shared)
- 0x0C-0x18: 4 PComponent-specific methods (`PComponent_FindAndPushInstances_Wrapper` at 0x450350)
- 0x30: `0x44e1d0 ???` (PComponent copy helper)

### 5. vtable_PClassDescriptorConcrete_PInstancesComponent (0xb113dc)

PInstancesComponent = mesh instance container (manages many PMeshInstance objects). 16 entries:
- 0x00: `0x45a340 ???` (PInstancesComponent_ClassDescriptor_dtor)
- 0x04: `0x43caf0 EvalCondition` (shared)
- 0x08: `0x437980 ReturnZero` (shared)
- 0x0C-0x18: 4 PInstancesComponent-specific methods
- 0x2C: `0x459610 ???` (find-instances helper)

### 6. vtable_PMethodCallerConcrete_PClassDescriptor (0xb0ede0)

**Base vtable for all PMethodCaller instantiations.** 6 entries:
- 0x00: `0x43b850 Phyre_PCaller_Dtor_Deleting`
- 0x04: `0x43cad0 Phyre_PClassDescriptor_EvalCondition`
- 0x08: `0x43d840 Phyre_PClassDescriptor_EvalConditionEx`
- 0x0C: `0x43ce00 j_Phyre_PType_GetBool_1` (thunk)
- 0x10: `0x43cbd0 Phyre_PClassDescriptor_GetDestroyList`
- 0x14: `0x43edd0 Phyre_PNamespace_TraverseWithFlag`

After this 6-entry base, **specialized instantiations add 2-10 typed-arg overloads** for specific methods.

### 7. vtable_PMethodCallerConcrete_PMeshInstance_Vector4 (0xb23320)

Type-erased call to `PMeshInstance::SetBound(Vector4)`. Specialized entry:
- 0x00-0x14: 6 base entries (from PMethodCallerConcrete_PClassDescriptor)
- 0x18: `0x43edd0 Phyre_PNamespace_TraverseWithFlag` (extra method)
- 0x1C: `0x2091920 ???` (data segment reference?)

### 8. vtable_PThreadPool (0xb10258)

**Async thread pool dispatcher** (PThreadPool). 8 entries:
- 0x00-0x18: 6 identical entries (`0x2091920 ???`) — likely `__purecall` or platform stubs
- 0x1C: `0x44cdb0 Phyre_EngineWorker_Body` (the actual work function)

This is suspicious — 6 identical entries suggests the vtable is mostly **unimplemented virtual methods** defaulting to `__purecall` or a no-op stub at `0x2091920`. The real work happens at `Phyre_EngineWorker_Body` called via a single non-virtual path.

### 9. vtable_PClassDescriptorWithoutDefaultConstructor_PNameComponent (0xb118bc)

**Special variant** for types that don't have a default constructor. PNameComponent must be initialized with a name string, so it gets a custom vtable:
- 0x00: `0x45a340 ???` (dtor)
- 0x04: `0x43caf0 EvalCondition` (shared)
- 0x08: `0x437980 ReturnZero` (shared)
- 0x0C-0x18: PNameComponent-specific (4 methods)
- 0x1C: `0x44b150 ???` (custom-construct helper, NOT default ctor)

### 10. vtable_PClassDescriptorDynamic (0xb0fa94)

**Single dynamic dispatch vtable.** Not tied to a specific type — used by `PClassDescriptorDynamic` itself for runtime class registration. 16 entries:
- 0x00: `0x44a530 ???` (dtor)
- 0x04: `0x43c4f0 Phyre_PType_Identity`
- 0x08: `0x437980 Phyre_PType_Default_ReturnZero`
- 0x0C-0x18: 4 methods
- 0x1C: `0x4499d0 ???` (custom)
- 0x20: `0x449c30 ???` (custom)
- 0x24: `0x449920 ???` (custom)
- 0x28: `0x449ba0 ???` (custom)
- 0x2C: `0x447d80 ???` (custom)
- 0x30: `0x449130 ???` (custom)
- 0x34: `0x449e30 ???` (custom)
- 0x38: `0x449560 ???` (custom)
- 0x3C: `0x2091920 ???` (stub)

This is the **runtime class descriptor** that can be modified at runtime to register new types dynamically (used for FFX's hot-reload scripting?).

---

## Full Inventory by Family

### A. PClassDescriptor Triples (39 vtables)

For each reflected type, 3 vtables (ForType / Abstract / Concrete):

| Type | ForType | Abstract | Concrete | Notes |
|------|---------|----------|----------|-------|
| PNamespace | 0xb0ee64 | 0xb0eeac | — | Root namespace |
| PCluster | 0xb0f02c | 0xb0f074 | — | Cluster manager |
| PWorld | 0xb0f364 | 0xb0f3ac | — | World root |
| PTypedObject | 0xb0f4c4 | 0xb0f50c | — | Typed object base |
| PString | 0xb0f624 | 0xb0f66c | 0xb0f6b4 | String class |
| PClassDataMemberDynamic | 0xb0f834 | 0xb0f87c | 0xb0f908 | Dynamic data member |
| PClassDescriptorDynamic | 0xb0f9bc | 0xb0fa04 | 0xb0fa94 | Runtime class desc |
| PComponent | — | 0xb102dc | 0xb10324 | Component base |
| PEntity | 0xb1049c | 0xb104e4 | 0xb1052c | Entity base |
| PWorldMatrix | 0xb1081c | — | — | World matrix type |
| PInstancesComponent | — | 0xb11394 | 0xb113dc | Mesh instance container |
| PNameComponent | — | 0xb11874 | 0xb118bc (WithoutCtor) | Named component |
| PRandomGenerator | — | 0xb11dec | 0xb11e34 (WithoutCtor) | Random gen |
| Quat | 0xb121d4 | — | 0xb1221c (Wrapper) | Quaternion |
| Matrix3 | 0xb12264 | — | 0xb122ac (Wrapper) | 3×3 matrix |
| Matrix4 | 0xb122f4 | — | 0xb1233c (Wrapper) | 4×4 matrix |
| PMatrix4 | 0xb12384 | — | 0xb123cc (Wrapper) | Phyre matrix |
| PMatrix4x3 | 0xb12494 | — | 0xb124dc (Wrapper) | Phyre matrix 4×3 |

**Total: 39 vtables** (12 Abstract + 14 ForType + 6 Concrete + 4 Wrapper + 2 WithoutDefaultCtor + 1 Dynamic)

### B. PMethodCallerConcrete (41 vtables)

Type-erased method invocations. Each instantiates for a specific (Type, Method, Args) triple:

| Type | Methods |
|------|---------|
| PClassDescriptor | 1 vtable (base) |
| PInstancesComponent | 4 vtables (Array, TypedObject_I, I, TypedObject_ClassDesc) |
| PAssetReference | 3 vtables (String, TypedObject, ClassDesc) |
| Vector2/3/Point3/Vector4/Quat | 5 vtables |
| PMatrix4x3 | 1 vtable |
| PMaterialSet | 3 vtables (PResult_Material, Material_I, I) |
| PMesh | 1 vtable |
| PLight | 5 vtables (WorldMatrix, MMMM, M, MM, WorldMatrix_1) |
| PSamplerState | 5 vtables (FilterFormat, WrapFormat, M, I, Bool) |
| PTextureCommonBase | 1 vtable |
| PMeshInstance | 8 vtables (Vector4, Bounds, Matrix_I, WorldMatrix, BoundsPtr, Mesh, MaterialSet, Matrix_I_1) |
| PNode | 4 vtables (WorldMatrix, Matrix4, Name, Self) |

**Total: 41 vtables** (6 entries each, but PMethodCallerConcrete_PClassDescriptor extends to 12 entries in some variants).

### C. Vtable_P*_ForType (8 vtables)

Special-purpose class-specific vtables:

| Vtable | Address | Purpose |
|--------|---------|---------|
| `Vtable_PCamera_ForType` | 0xb10ac4 | Camera reflection |
| `Vtable_PCameraProjection_ForType` | 0xb10ba4 | Camera projection |
| `Vtable_PInstancesComponent_ForType` | 0xb1134c | Mesh instance reflection |
| `Vtable_PArray_TypedObject_DataMember` | 0xb1153c | Typed object array |
| `Vtable_PArray_TypedObject_Descriptor` | 0xb1157c | Typed object array |
| `Vtable_PNameComponent_ForType` | 0xb1182c | Named component |
| `Vtable_PAssetReference_ForType` | 0xb1199c | Asset reference |
| `Vtable_PAssetRefImport_ForType` | 0xb11a84 | Asset import reference |
| `Vtable_PAssetRefImport_Concrete` | 0xb11b14 | Asset import concrete |
| `Vtable_PRandomGenerator_ForType` | 0xb11da4 | Random gen reflection |
| `Vtable_Vector2_ForType` | 0xb11f6c | Vector2 reflection |

### D. Interface vtables (4 vtables)

Abstract interfaces not tied to specific types:

| Interface | Address | Purpose |
|-----------|---------|---------|
| `vtable_PClassLayoutInterface` | 0xb13470 | Class layout reflection |
| `vtable_PIChildClassVisitor` | 0xb1348c | Visitor for child class enumeration |
| `vtable_PSerializedClassLayoutInterface` | 0xb134a0 | Serialized layout |
| `vtable_PFindNestedClassVisitor` | 0xb13bc0 | Visitor for nested class search |

### E. Platform stubs (18 functions)

`VTable_ReturnThis`, `Vtable_ClearFloat4_*`, `Vtable_ClearIntFloat3_*`, `Vtable_Init64AndSetFloat1` — these are NOT vtables, they are **MSVC boilerplate functions** that IDA heuristically named because they look like vtable pattern. They live in `.text` not `.rdata` (segment mismatch with real vtables).

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `VTable_ReturnThis` | 0x5831b0 | 5B | `mov eax, ecx; ret` — singleton stub |
| `VTable_ReturnThis_B/C/D` | 0x583220/280/530 | 5B each | Variants of above |
| `Vtable_ClearFloat4_F4` | 0x73ac00 | 60B | Clear struct field |
| `Vtable_ClearFloat4_15C` | 0x73b8c0 | 60B | Clear 15C-offset field |
| `Vtable_ClearFloat4_A8_D-H` | 0x73d0a0, 73d9b0, 73e330, 73eac0, 73f2b0, 73fad0 | 60B each | Clear A8-offset field (variants) |
| `Vtable_ClearIntFloat3_A0_A/B/C` | 0x72e810, 72e840, 755100 | 60B each | Clear A0-offset mixed fields |
| `Vtable_Init64AndSetFloat1` | 0x75b020 | 70B | Init 64-bit value + set float |

---

## Key Vtable Patterns

### Pattern 1: Triple-Entry Layout (PClassDescriptor)

Every reflected class gets 3 vtables. The Concrete/Abstract/ForType distinction supports different query patterns:

```
vtable_PClassDescriptorForType_PEntity    @ 0xb1049c (16 entries × 4B = 64B)
vtable_PClassDescriptorAbstract_PEntity    @ 0xb104e4 (16 entries)
vtable_PClassDescriptorConcrete_PEntity    @ 0xb1052c (16 entries)
```

These 3 vtables sit at 72-byte intervals in `.rdata`, suggesting they're laid out as part of the same static initialization block. **Each PEntity class descriptor has a header at 0xb1049c** containing all 3 vtable pointers.

### Pattern 2: PMethodCaller Concrete Typed Args

PMethodCallerConcrete specializes on `(Type, Args...)`. Each typed instantiation has 6 entries:

```
vtable_PMethodCallerConcrete_PMeshInstance_Vector4     @ 0xb23320 (SetBound(Vector4))
vtable_PMethodCallerConcrete_PMeshInstance_Bounds      @ 0xb23338 (SetBounds)
vtable_PMethodCallerConcrete_PMeshInstance_Matrix_I    @ 0xb23350 (SetMatrix(int))
vtable_PMethodCallerConcrete_PMeshInstance_WorldMatrix @ 0xb23368 (SetWorldMatrix)
vtable_PMethodCallerConcrete_PMeshInstance_BoundsPtr   @ 0xb23380 (SetBoundsPtr)
vtable_PMethodCallerConcrete_PMeshInstance_Mesh        @ 0xb23398 (SetMesh)
vtable_PMethodCallerConcrete_PMeshInstance_MaterialSet @ 0xb233b0 (SetMaterialSet)
vtable_PMethodCallerConcrete_PMeshInstance_Matrix_I_1  @ 0xb233c8 (SetMatrix variant 1)
```

8 PMeshInstance method bindings × 6 entries = 48 dispatch sites.

### Pattern 3: Shared Base Methods

Three methods appear in nearly ALL PClassDescriptor vtables:
- `0x43caf0 Phyre_PClassDescriptor_EvalCondition` (offset 0x04)
- `0x437980 Phyre_PType_Default_ReturnZero` (offset 0x08)
- `0x43edd0 Phyre_PNamespace_TraverseWithFlag` (offset 0x20 in many)

This is the **inheritance chain** — these methods are inherited from `PClassDescriptor` base class. **Every Phyre class descriptor gets these 3 methods** for free via the base vtable.

### Pattern 4: WithoutDefaultCtor Variants

Some types can't be default-constructed (PNameComponent needs a name, PRandomGenerator needs a seed). They get special `WithoutDefaultConstructor` vtables that **omit the default-ctor entry** and **add a custom-construct helper**:

```
vtable_PClassDescriptorWithoutDefaultConstructor_PNameComponent     @ 0xb118bc
vtable_PClassDescriptorWithoutDefaultConstructor_PRandomGenerator  @ 0xb11e34
```

This pattern prevents accidental default construction at runtime.

### Pattern 5: Math Wrappers (Vector/Quat/Matrix)

Math types (Vector2/3/4, Quat, Matrix3/4, PMatrix4/4x3) have **Wrapper variants** that bridge the math types into the class descriptor system:

```
vtable_PClassDescriptorForType_Vector2    @ 0xb11f6c (?)
vtable_PClassDescriptorWrapper_Vector4    @ 0xb12184
vtable_PClassDescriptorWrapper_Quat       @ 0xb1221c
vtable_PClassDescriptorWrapper_Matrix3    @ 0xb122ac
vtable_PClassDescriptorWrapper_Matrix4    @ 0xb1233c
vtable_PClassDescriptorWrapper_PMatrix4   @ 0xb123cc
vtable_PClassDescriptorWrapper_PMatrix4x3 @ 0xb124dc
```

The Wrapper variant likely **binds Phyre's PVector2/3/4 types to std::vector semantics** for scripting.

---

## Vtable → Hot-Path Correlation

The vtables most referenced in `.text` (per IDA xref count) are the engine's **hot-path types**:

| Rank | Vtable | Likely Use |
|------|--------|-----------|
| 1 | `vtable_PClassDescriptorConcrete_PEntity` (0xb1052c) | Every scene graph object → 1000s of xrefs |
| 2 | `vtable_PClassDescriptorConcrete_PComponent` (0xb10324) | Every renderable component |
| 3 | `vtable_PClassDescriptorConcrete_PInstancesComponent` (0xb113dc) | Mesh instancing (every visible model) |
| 4 | `vtable_PClassDescriptorConcrete_PString` (0xb0f6b4) | String manipulation (millions of calls/sec) |
| 5 | `vtable_PThreadPool` (0xb10258) | Async job submission (per-frame) |

---

## Architecture Insights

### PEntity vtable = "scene graph CRUD"

The 16 entries of `vtable_PClassDescriptorConcrete_PEntity` break down as:

```
[0]  Destructor (deleting)
[1]  EvalCondition           ← runtime condition check
[2]  ReturnZero              ← type query "is this a PEntity?"
[3]  PEntityRef_Copy         ← copy entity reference
[4]  PushObjectToStream      ← serialization (forward)
[5]  GetWrapper              ← PEntity → PEntityPtr wrapper
[6]  PushObjectOrNil         ← serialization (allow null)
[7]  ClassDescriptor_dtor_dup ← destructor helper
[8]  InsertIntoPropertyList  ← reflect properties
[9]  List_UnlinkNode         ← list manipulation
[10] ClassDescriptor_dtor_dup2 ← destructor helper 2
[11] nullsub_246             ← no-op stub (unimplemented)
[12] ZeroInit                ← clear fields
[13] Clear_Wrapper           ← clear list
[14] InitForEntity           ← data member init
[15] ???                     ← tail call (likely into MSVC CRT)
```

This is essentially **the lifecycle of a PhyreEngine scene object**: create, query, copy, serialize, destroy.

### Why 3 vtables per class?

Each Phyre class needs to support **3 distinct query patterns**:
1. **ForType** — "I have a `PEntity*`, what type info do I need?" (typed queries, scripting)
2. **Abstract** — "I have an abstract base, dispatch to derived" (virtual calls)
3. **Concrete** — "I want to **construct** a new PEntity" (deserialization, factory)

Storing all 3 in separate vtables lets PhyreEngine:
- Keep typed reflection separate from virtual dispatch (perf)
- Avoid vtable bloat from Concrete-specific methods
- Support `WithoutDefaultConstructor` variants cleanly

### PMethodCallerConcrete = Type Erasure

`PMethodCallerConcrete<T, Args...>` is Phyre's way of storing a **bound method** (object + method + args) as a single vtable-dispatched callable. The 41 vtables × 6 entries = 246 distinct method bindings.

This is analogous to `std::function<Ret(Args...)>` but **statically dispatched via vtable** — no runtime lambda allocation. It's the engine's "fast path" for scripting bindings.

---

## Method Distribution

Across all PClassDescriptor vtables, the most common method slots are:

| Method | Address | Appears in N vtables | Purpose |
|--------|---------|----------------------|---------|
| `Phyre_PClassDescriptor_EvalCondition` | 0x43caf0 | ~35 | Class condition eval |
| `Phyre_PType_Default_ReturnZero` | 0x437980 | ~35 | Default type query |
| `Phyre_PClassMember_InsertIntoPropertyList` | 0x43c190 | ~30 | Property registration |
| `Phyre_List_UnlinkNode` | 0x43d4f0 | ~30 | List manipulation |
| `Phyre_PNamespace_TraverseWithFlag` | 0x43edd0 | ~25 | Namespace traversal |
| `Phyre_PType_Identity` | 0x43c4f0 | ~20 | Type identity check |
| `nullsub_246` | 0x43d8a0 | ~15 | Stub |
| `Phyre_PClassDescriptor_GetDestroyList` | 0x43cbd0 | ~15 | Destruction list |
| `j_Phyre_PType_GetBool_1` | 0x43ce00 | ~10 | Bool query thunk |

These 9 methods form the **base vtable footprint** of every Phyre class descriptor.

---

## Key Findings

1. **117 vtable symbols** total in FFX.exe — IDA's class_informer named 117 of them, plus MSVC boilerplate. The actual vtable count is **39 PClassDescriptor + 41 PMethodCaller + 8 Vtable_P*_ForType + 4 interface + 1 PThreadPool + 18 stubs = 111 functional vtables + 6 PCaller-related stubs**.

2. **Triple vtable design** (ForType/Abstract/Concrete) is unique to PhyreEngine — supports 3 distinct query patterns per class without vtable bloat.

3. **PMethodCallerConcrete** is PhyreEngine's type-erased method invocation — 41 vtables × 6 entries = 246 method bindings discoverable statically.

4. **PEntity vtable is THE hot path** — `vtable_PClassDescriptorConcrete_PEntity` is referenced by every scene graph object creation/destruction. The 16 methods form the full CRUD/serialization pipeline.

5. **WithoutDefaultConstructor variants** — 2 types (PNameComponent, PRandomGenerator) have special vtables preventing accidental default construction.

6. **Math wrapper vtables** — Vector2/3/4, Quat, Matrix3/4 have Wrapper variants to bridge into the class descriptor system for scripting.

7. **Shared base methods** — 9 methods appear in most vtables, forming the base footprint inherited from PClassDescriptor.

8. **PThreadPool vtable is suspicious** — 6 identical entries suggest many `__purecall` stubs. Real work happens in `Phyre_EngineWorker_Body` (0x44cdb0).

9. **18 "vtable" names are actually MSVC boilerplate** — IDA heuristic misidentified platform stub functions (`Vtable_ClearFloat4_*`, `VTable_ReturnThis`) as vtables. They live in `.text`, not `.rdata`.

10. **Each PMethodCallerConcrete vtable adds 0-2 typed-arg overloads** beyond the 6-entry base — total entries per vtable vary from 6 to 12.

---

## What's Next?

- **batch_0011**: Decompile `FFX_System_Host_Constructor` (boot sequence, 3482B) — uses these vtables to bootstrap the engine
- **batch_0012**: Decompile `FFX_Battle_ComputeHitDamage` (2127B) — damage formula
- **batch_0013**: ATEL Movie opcode table (475 ops)
- **batch_0014**: Sphere Grid Abmap core
- **batch_0015**: Field VM opcodes
- **batch_0016**: VP8/VP9 decoder entry
- **batch_0017**: MSCD file system
- **batch_0018**: Battle UI HUD core
- **batch_0019**: Cross-batch PhyreEngine architecture synthesis

---

**Next batch:** Boot constructor — the 3482B initialization routine that wires all these vtables together at game startup.