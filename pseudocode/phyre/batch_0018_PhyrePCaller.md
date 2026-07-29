# FFX.exe Decompilation — Batch 18 (Phyre_PCaller)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 409 total across ~27 type instantiations
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

The **PCaller** family is PhyreEngine's **reference-counted smart pointer/handle** system, implemented as a C++ template. Of the 409 functions, **408 are compiler-generated COMDAT template instantiations** (7-34 bytes each) — constructors, destructors, vtable initializers, and trivial accessors for 27 distinct types. Only **one function** is substantive logic: `PCaller_Destructor_Release` (85 bytes), the ref-count decrement + cleanup.

| Metric | Count |
|--------|-------|
| Total functions | 409 |
| Unique template types | 27 |
| Constructors (7 bytes) | ~75+ |
| Destructors (34 bytes) | ~150+ |
| VTableInit (7 bytes) | ~30+ |
| Vtable set (7 bytes) | ~20+ |
| Substantive functions (>50 bytes) | 1 |

### PCaller struct (16 bytes / 4 DWORDs)

```c
struct PCaller {
    void* m_pPtr;          // +0: pointer to managed object (or `this` if empty/unowned)
    void* m_pSelf;         // +4: secondary pointer (often = `this` as sentinel)
    int   m_flags;         // +8: flags / refcount. Bit 31 (negative) = "don't own data"
    void* m_pData;         // +12: heap data pointer (freed via Engine_AlignedFree if owned)
};
```

**Constructor** (0x442ab0, 22 bytes):
```c
void __thiscall PCaller_Constructor(PCaller* this) {
    this->m_pPtr  = this;    // self-reference = "empty"
    this->m_pSelf = this;    // self-reference = "empty"
    this->m_flags = 0;       // refcount 0, owns data
    this->m_pData = NULL;    // no data
}
```

A variant `PCaller_InitFields` writes `this[3]=0; this[4]=-1` — suggesting a **5-DWORD variant** (20 bytes) for a subclass or a differently-templated PCaller.

---

## Architecture

### What is PCaller?

PCaller is PhyreEngine's **generic reference-counted handle**, analogous to `std::shared_ptr<T>` but with additional linked-list tracking. Each PCaller:

1. **Holds a pointer** to a managed object (`m_pPtr`)
2. **Tracks references** via a linked list embedded at negative offset from the managed object
3. **Owns optional heap data** (`m_pData`) freed via `Engine_AlignedFree`
4. **Uses self-reference sentinel**: when empty, `m_pPtr == m_pSelf == this`

### Self-reference sentinel pattern

```c
// Empty PCaller: both pointers point to itself
m_pPtr  = &this;
m_pSelf = &this;

// Active PCaller pointing to object at 0x12345678:
m_pPtr  = 0x12345678;
m_pSelf = &this;  // or = 0x12345678
```

This allows distinguishing "null/empty" PCaller from "pointing to something" via `if (this->m_pPtr != this)`.

### 27 template instantiation types

| Type | Domain |
|------|--------|
| `PAssetRef` | Asset references |
| `PAssetRefImport` | Imported asset references |
| `PAttachableComponent` | Scene attachable components |
| `PBlendableAnimSource` | Animation blending sources |
| `PCamera` | Camera component |
| `PCameraControllerComponent` | Camera controller component |
| `PCameraProjection` | Camera projection |
| `PClassDescriptor` | Runtime class descriptors |
| `PCluster` | Cluster manager |
| `PDataMemberArray` | Data member arrays |
| `PInstancesComp` | Mesh instances component |
| `PLocator` | Scene locators |
| `PMatrix3` | 3×3 matrix (math) |
| `PMatrix4` | 4×4 matrix (math) |
| `PMatrix4x3` | 4×3 matrix (math) |
| `PNameComponent` | Named components |
| `POrthographic` | Orthographic camera |
| `PPoint3` | 3D point (math) |
| `PQuat` | Quaternion (math) |
| `PRandomGen` | Random number generator |
| `PScriptedComponent` | Scripted components |
| `PSpline` | Spline path |
| `PTextureCommonBase` | Texture base |
| `PTimerComponent` | Timer component |
| `PTrigger` | Event trigger |
| `PVector2` | 2D vector (math) |
| `PArrayPTypedObj` | Typed object array |

---

## Key Function Analysis

### PCaller_Destructor_Release (0x442b50, 85 bytes) — THE substantive function

```c
void __thiscall PCaller_Destructor_Release(PCaller* this) {
    // Phase 1: Unlink from tracking list
    if (this->m_pPtr != this && this->m_pPtr) {
        // Walk linked list embedded at offset -72 from m_pPtr
        for (void* node = ((char*)this->m_pPtr - 72); 
             node; 
             node = ((char*)node->next - 72)) {
            
            node->field_at_64 = 0;    // clear binding flag
            if (node->next == this)    // reached back-pointer to this PCaller
                break;
            if (!node->next)           // end of list
                break;
        }
    }
    
    // Phase 2: Free heap data if owned
    // m_flags >= 0 means bit 31 is clear = "we own the data"
    // m_pData != NULL means there's data to free
    if (this->m_flags >= 0 && this->m_pData)
        Engine_AlignedFree(this->m_pData);
    
    // Phase 3: Clear
    this->m_pData = NULL;
    this->m_flags = 0;
}
```

**Critical insight:** `this->m_flags >= 0` is a **signed comparison** — it tests bit 31. When bit 31 is set (negative value), the PCaller **does not own** its `m_pData` and will NOT free it. This allows both owning and non-owning (borrowed) references.

The linked list walk is **iterating backwards** through nodes stored before the managed object. Each node is 72 bytes, with:
- Offset 64 (`node->field_at_64`): binding flag that gets cleared
- Offset 72 (`node->next`): next pointer / back-pointer to owning PCaller

This is likely a **tracking list** so that when one PCaller releases, it can notify others referencing the same object.

### Standard destructor pattern (34 bytes, 140+ instantiations)

```c
Vtable_PCaller_Phyre** __thiscall PCaller_Dtor(Vtable_PCaller_Phyre** this, char flags) {
    *this = &g_vtable_PCaller_Phyre;         // reset vtable
    if ((flags & 1) != 0)                     // scalar deleting flag
        FFX_Heap_Free(this);                  // free the PCaller itself
    return this;
}
```

All 140+ destructor instantiations are **identical** — they reset the vtable pointer and optionally free memory. The only variation is the vtable they reset to, which is always `g_vtable_PCaller_Phyre`.

### Standard constructor pattern (22 bytes, ~9 instances)

```c
void __thiscall PCaller_Constructor(PCaller* this) {
    *this = this;        // m_pPtr = this
    this[1] = this;      // m_pSelf = this
    this[2] = 0;         // m_flags = 0
    this[3] = 0;         // m_pData = NULL
}
```

**Note on function naming:** IDA names 17 functions as `PCaller_Constructor_*` that are only **7 bytes** — they set only the vtable pointer (`*this = &g_vtable_PCaller_Phyre`). These are VTableInit functions misnamed by the IDA heuristic. The real field-initializing constructor is the 22-byte version above.

All constructors are identical — the template generates no additional initialization for the specific type.

### Standard VTableInit pattern (7 bytes, 30+ instantiations)

```c
void __thiscall PCaller_VTableInit(PCaller* this) {
    *(void**)this = &g_vtable_PCaller_Phyre;
}
```

Each type-specific variant just sets the vtable differently:
- `PCaller_VTableInit_Camera` → different vtable
- `PCaller_VTableInit_AssetRef` → another vtable
- etc.

All are **7 bytes** — single `mov [ecx], offset vtable` instruction.

---

## Template Explosion Analysis

409 functions from a single template class is a **massive COMDAT explosion**. This is characteristic of:

1. **Header-only template** defined in a .h file included by many translation units
2. **MSVC COMDAT folding** (identical functions merged by linker)
3. **Each .cpp that uses PCaller<T>** generates its own copy of ctor/dtor/vtable-set

The 140+ destructors are NOT all unique — MSVC's `/OPT:ICF` (Identical COMDAT Folding) would merge identical ones. The fact that they survived suggests subtle differences (different vtable addresses, different EH tables, or different alignment).

---

## Complete Inventory

### Substantive functions (>20 bytes)

| Address | Name | Size | Notes |
|---------|------|------|-------|
| 0x442b50 | `PCaller_Destructor_Release` | 0x55 (85B) | Only real logic — ref count release + data free |

### All other functions (409 total)

The remaining 408 functions fall into these categories:

| Category | Typical size | Count (approx) | Behavior |
|----------|-------------|----------------|----------|
| Constructor (real) | 22 bytes (0x16) | ~9 | `m_pPtr=this; m_pSelf=this; m_flags=0; m_pData=0` |
| VTableInit (misnamed "Ctor") | 7 bytes (0x7) | ~17 | `*this = &g_vtable_PCaller_Phyre` (vtable only) |
| VTableInit | 7 bytes (0x7) | ~30 | `*(void**)this = &vtable` |
| VTable set | 7 bytes (0x7) | ~12 | Sets vtable pointer |
| Destructor | 34 bytes (0x22) | ~160 | Reset vtable + optional FFX_Heap_Free |
| Scalar dtor | 34 bytes (0x22) | ~60 | Same as destructor |
| SetInt | 14 bytes (0xe) | ~12 | `this[0] = a2; return this` |
| SwapInts | 21 bytes (0x15) | ~4 | Swaps two int values |
| ReleaseReturnTrue | 17 bytes (0x11) | ~1 | Calls PCaller_Destructor_Release + returns 1 |
| ReturnTrue | 3 bytes (0x3) | ~1 | Returns true |
| ReturnZero | 5 bytes (0x5) | ~1 | Returns 0 |
| ReturnMinus1 | 6 bytes (0x6) | ~2 | Returns -1 |
| GetFieldAtOffset4 | 4 bytes (0x4) | ~4 | `return *(this+4)` |
| SupportsType_RetFalse | 3 bytes (0x3) | ~8 | Returns false |
| ctor_vtable | 7 bytes (0x7) | ~25 | vtable-placement ctor variant |

---

## Key Findings

1. **PCaller is a template smart pointer, not a base class** — 27 type instantiations confirm it's `PCaller<T>` where T varies. 409 functions from template explosion.

2. **Self-reference sentinel** — empty PCaller points `m_pPtr` at itself, not NULL. This is checked as `if (this->m_pPtr != this)` to determine if the handle is active.

3. **Ownership flag in bit 31** — `m_flags` bit 31 controls whether `m_pData` is freed on release. `>= 0` test = "clear bit 31 = owned".

4. **Linked-list tracking** — objects managed by PCaller have a 72-byte tracking header at negative offset, with binding flags and back-pointers. This enables coordinated release across multiple PCaller handles to the same object.

5. **Massive template overhead** — 408/409 functions are compiler-generated boilerplate. Only `PCaller_Destructor_Release` has real logic.

6. **Engine_AlignedFree for data cleanup** — heap data is freed via `Engine_AlignedFree` (not `free` or `delete`), indicating PCaller manages alignment-sensitive allocations.

---

**Next batch:** Phyre_PObject family (77 functions) — runtime object system, dynamic typing, RTTI.
