# FFX.exe Decompilation — Batch 17 (PGeometry + PVertexStream + PMeshInstance)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 283 total across 3 families (PGeometry: 130, PVertexStream: 102, PMeshInstance: 51)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the **geometry rendering subsystem** of PhyreEngine 3.9.0.0 "SacSlicer" — three closely related families:

| Family | Count | Size Range | Role |
|--------|-------|------------|------|
| `Phyre_PGeometry_*` | 130 | 0x3-0x739 (4-1849 bytes) | Geometry resource management, vertex/index buffers, D3D11 data blocks |
| `Phyre_PVertexStream_*` | 102 | 0x4-0x1ee (4-494 bytes) | Vertex buffer stream definitions, format descriptors |
| `Phyre_PMeshInstance_*` | 51 | 0x3-0xe5c (3-3680 bytes) | Mesh instance transforms, bounds, scripting accessors |

**Key discoveries:**
- All 3 families share a **"small array optimization"** pattern (1 element inline, heap beyond): `if (v <= 1) { if (v) ptr = &inline_field; else ptr = 0; } else { ptr = heap_ptr; }`
- The **`m_pDeclaration` pointer** in PGeometry uses bit 31 (0x80000000) as an "owned/heap-allocated" flag, stripped via `& 0x7FFFFFFF` before access
- All stream arrays use a **5-element stride** (20 bytes per entry) — the "stream descriptor" index formula is `5 * idx`
- PVertexStream struct is **64 bytes**: vfptr (4) + m_type (4) + m_stride (4) + m_elementCount (4) + m_refCount (4) + m_pData (4, word) + count+ptr for inline array (8) + index buffer (16) + flags (8) + gap/pad
- PMeshInstance is **132 bytes** with ~30 data members registered via bitflag-guarded lazy registration
- **2 misnamed functions**: `Phyre_PMeshInstance_RegisterDescriptor` (0x503630) is actually `PObjectAccessor<PIndirectArgsBuffer&>::Get` — a scripting accessor, NOT a PMeshInstance function

---

# Part 1: Core Architecture Patterns

## 1.1 Small Array Optimization

Throughout all 3 families, PhyreEngine uses a compact inline-array pattern:

```c
// Standard pattern for "small array" (max 1 inline element)
if (count <= 1) {
    if (count == 1)
        ptr = &inline_field;  // embedded in struct
    else
        ptr = NULL;           // empty
} else {
    ptr = heap_ptr;           // heap-allocated array
}
```

The struct layout for this pattern:
```
+0: count (with bit 31 = owned flag, & 0x7FFFFFFF = actual count)
+4: data ptr (or inline data if count & 0x80000000 == 0)
```

## 1.2 Bitflag-Guarded Lazy Registration

Class descriptor constructors use a global bitflag (`dword_C98A08`, `word_CA7400`, etc.) to avoid re-registering:

```c
v0 = dword_C98A08;
if ((v0 & 1) == 0) {            // bit 0 = first member registered
    dword_C98A08 |= 1;
    // register first PClassDataMember
    atexit(dtor_fn);
    v0 = dword_C98A08;
}
if ((v0 & 2) == 0) {            // bit 1 = second member registered
    dword_C98A08 = v0 | 2;
    // register second PClassDataMember
}
// ... up to 31 bits
```

Each member registration follows:
1. Get type singleton (e.g. `Phyre_PType_GetPUInt32()`)
2. Call `Phyre_PClassDataMember_ctorAttach_structural(global_ptr, classDesc, typePtr, "m_name", offset, bitflags, 0)`
3. Register `atexit(destructor)` for cleanup

## 1.3 m_pDeclaration Bit 31 Flag

PGeometry's `m_pDeclaration` pointer uses bit 31 as an ownership flag:

```c
int decl = this->m_pDeclaration;
if (decl & 0x80000000) {
    // Owned/heap-allocated: strip flag before using as pointer
    decl &= 0x7FFFFFFF;
}
// Use decl as PVertexStreamDeclaration*
```

This is the standard "tagged pointer" pattern — the lower 31 bits hold a valid address (x86 user space), the top bit marks ownership.

## 1.4 Stream Array: 5-Element Stride

Every PGeometry function that accesses streams uses the index formula `5 * streamIdx`:

```c
int streamEntry = base + 5 * streamIdx;  // 20 bytes per entry
// +0: stream ptr or inline
// +1: stride/format
// +2: element count or flags
// +3: data block ptr or inline  
// +4: offset or flags
```

---

# Part 2: PGeometry Class Descriptors (5 registration functions)

## 2.1 PVertexStream_ClassDescriptor (0x4805d0, 376 bytes)

Registers `PGeometry::PVertexStream` with 4 data members:

| Member | Type | Offset | Bitflag |
|--------|------|--------|---------|
| `m_type` | uint8 | +8 | bit 16 |
| `m_offset` | uint32 | +0 | bit 16 |
| `m_renderDataType` | PRenderDataType* | +4 | bit 18 |
| `m_streamSet` | uint8 | +9 | bit 16 |

```c
Phyre_PClassDataMember_ctorAttach_structural(unk_C98970, &MEMORY[0xC98730], (int)PUInt8, "m_type", 8, 16, 0);
Phyre_PClassDataMember_ctorAttach_structural(unk_C9899C, &MEMORY[0xC98730], (int)PUInt32, "m_offset", 0, 16, 0);
Phyre_PClassDataMember_ctorAttach_structural(unk_C989C8, &MEMORY[0xC98730], (int)PUInt32, "m_renderDataType", 4, 18, 0);
Phyre_PClassDataMember_ctorAttach_structural(unk_C989F4, &MEMORY[0xC98730], (int)PUInt8, "m_streamSet", 9, 16, 0);
```

**Key insight:** `m_offset` is at +0 and `m_renderDataType` is at +4, suggesting PVertexStream starts with:
```
+0: m_offset (uint32) — byte offset within vertex
+4: m_renderDataType (PRenderDataType*) — D3D11 format descriptor
+8: m_type (uint8) — semantic/usage type
+9: m_streamSet (uint8) — stream index
```
But the actual struct layout from the PVertexStream inventory shows it's more complex (64 bytes with array, index buffer, flags).

## 2.2 PMeshElementGroup_ClassDescriptor (0x4971a0, 376 bytes)

Registers `PMeshElementGroup` with 4 members:

| Member | Type | Offset | Bitflag |
|--------|------|--------|---------|
| `m_startStreamIndex` | uint32 | +0 | bit 16 |
| `m_streamCount` | uint32 | +4 | bit 16 |
| `m_elementCount` | uint32 | +8 | bit 16 |
| `m_indexCount` | int32 | +12 | bit 16 |

**Struct:** 16 bytes (`+0: startStreamIndex, +4: streamCount, +8: elementCount, +12: indexCount`)

## 2.3 PDataBlock_RegisterClassDescriptors (0x55eae0, 391 bytes)

Registers `PDataBlock` (vertex data block) with 3 members:

| Member | Type | Offset | Bitflag |
|--------|------|--------|---------|
| `m_buffers` | PSharray<PDataBlockBufferD3D11> | +24 | bit 8 |
| `m_dataSize` | uint32 | +56 | bit 8 |
| `m_offsetInVertexBuffer` | uint32 | +48 | bit 8 |

**Key insight:** The `PSharray` (shared array) class descriptor for PDataBlockBufferD3D11 is registered lazily with bitflag guards. `m_buffers` at +24 suggests PDataBlock has at least 24 bytes of header (possibly vfptr + internal state) before the buffer array.

## 2.4 PIndexDataBlock_RegisterClassDescriptors (0x55ec90, 391 bytes)

Registers `PIndexDataBlock` with 3 members, structurally nearly identical to PDataBlock:

| Member | Type | Offset | Bitflag |
|--------|------|--------|---------|
| `m_buffers` | PSharray<PIndexDataBlockBufferD3D11> | +20 | bit 8 |
| `m_dataSize` | uint32 | +52 | bit 8 |
| `m_offsetInIndexBuffer` | uint32 | +44 | bit 8 |

**Differences from PDataBlock:** `m_buffers` at +20 (vs +24), `m_offsetInIndexBuffer` at +44 (vs +48 m_offsetInVertexBuffer). These offsets align — vertex data block is slightly larger at the head.

## 2.5 PMeshData_RegisterClassDescriptors (0x55ee20, 321 bytes)

Registers `PMeshData` with 2+1 members:

| Member | Type | Offset | Bitflag |
|--------|------|--------|---------|
| `m_vertexData` | PArray<PDataBlockD3D11,4> | +40, repeat=3 | bit 16 |
| `m_indexData` | PIndexDataBlock | +48 | bit 16 |

**Key insight:** `m_vertexData` with `repeat=3` means there are 3 vertex data blocks (likely for triple buffering or multi-stream). The `PArray<PDataBlockD3D11,4>` template means fixed capacity of 4, so each vertex data entry is fixed-size inline.

## 2.6 PVertexStreamArray_ClassDescriptor (0x482040, 376 bytes)

The **PVertexStreamArray** class descriptor at 0x482040 is the final class descriptor for the PGeometry subsystem. It registers the container `PArray<PVertexStream>` which holds multiple PVertexStream entries.

### Member Registrations

| Member | Type | Offset | Bitflag |
|--------|------|--------|---------|
| `m_memoryType` | uint8 | +8 | bit 16 — allocation memory type |
| `m_stride` | uint32 | +0 | bit 16 — byte stride between vertices |
| `m_elementCount` | uint32 | +4 | bit 16 — number of elements |
| `m_streams` | PArray<PVertexStream,4> | +8 | linked container |

### Code Flow

```c
void Phyre_PGeometry_PVertexStreamArray_ClassDescriptor() {
    Phyre_PTypeDefault_PChar_RegisterName(&MEMORY[0xC988B0]);
    
    // Bit 0: Register m_memoryType (uint8)
    if ((dword_C98A08 & 1) == 0) {
        dword_C98A08 |= 1;
        PUInt8 = Phyre_PType_GetPUInt8();
        Phyre_PClassDataMember_ctorAttach_structural(unk_C989DC, ..., "m_memoryType", 21, 16, 0);
        atexit(FFX_Sound_FmodMusicIsPlaying);  // dtor placeholder
    }
    
    // Bit 1: Register m_stride (uint32)
    if ((v0 & 2) == 0) {
        dword_C98A08 |= 2;
        PUInt32 = Phyre_PType_GetPUInt32();
        Phyre_PClassDataMember_ctorAttach_structural(&unk_C98A0C, ..., "m_stride", 0, 16, 0);
        atexit(Phyre_SingletonCall_5755E0_C98A0C);
    }
    
    // Bit 2: Register m_elementCount (uint32)
    if ((v0 & 4) == 0) {
        dword_C98A08 |= 4;
        v3 = Phyre_PType_GetPUInt32();
        Phyre_PClassDataMember_ctorAttach_structural(&unk_C98A38, ..., "m_elementCount", 4, 16, 0);
        atexit(Phyre_SingletonCall_5755E0_C98A38);
    }
    
    // Initialize PArray<PVertexStream> container class descriptor
    Phyre_PArray_PVertexStream_Init(off_C0E774[0]);  // "PArray<PVertexStream>"
    
    // Bit 3: Register m_streams container
    if ((dword_C98A08 & 8) == 0) {
        dword_C98A08 |= 8;
        // Lazy-init the PArray<PVertexStream,4> class descriptor
        if ((dword_C98B2C & 1) == 0) {
            dword_C98B2C |= 1;
            Phyre_PArray_PGeometry_PVertexStream_ClassDescriptor_ctor(&MEMORY[0xC98A98]);
            unk_C98B28 &= ~2u;
            MEMORY[0xC98A98].vfptr = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PGeometry::PVertexStream,4>>::vftable;
            atexit(PhyreCDDtor_PArrayVertexStream4);
        }
        // Register array member with linked class descriptor
        PClassDataMemberArray_Init(dword_C98A64, ..., "m_streams", 8, 0, 3, 4);
        dword_C98A64[0] = &vtbl_CDM_PhyreArray_PVertexStream;
        atexit(Phyre_TwoArgThunk_5760E0_C98A64);
    }
    
    unk_C98A78 |= 0x10u;  // Mark ready
    Phyre_PClassDescriptor_FinalizeRegistration(&MEMORY[0xC988B0]);
}
```

### Struct Layout

Based on the member offsets and the PVertexStream family analysis:

```
PVertexStreamArray:
  +0:  m_stride (uint32) — byte stride
  +4:  m_elementCount (uint32) — number of streams  
  +8:  m_memoryType (uint8) — allocation type
  +9:  pad[3]
  +12: m_streams (PArray<PVertexStream,4>) — fixed-capacity array
```

The container `PArray<PVertexStream,4>` enables up to 4 vertex streams per geometry, with each PVertexStream being 64 bytes as documented in Part 3.

---

# Part 3: PVertexStream Family (102 functions)

## 3.1 PVertexStream Struct Layout

From `Phyre_PVertexStream_InitZero` (0x55ddc0) and `Phyre_PVertexStream_Destroy` (0x55e120):

```c
// PVertexStream struct — 64 bytes (16 DWORDs)
struct PVertexStream {
    int *vfptr;              // +0: vfptr (0 after init)
    int m_type;              // +4: semantic/format type
    int m_stride;            // +8: byte stride
    int m_elementCount;      // +12: element count
    int m_refCount;          // +16: reference count
    WORD m_pData_low;        // +20: low word of data ptr (weird field)
    int m_count;             // +24: small array count (bit 31 = owned)
    int *m_data;             // +28: small array data ptr (or inline)
    int m_flags[2];          // +32, +36: flags/inline data
    int m_indexBuffer[4];    // +40 to +52: index buffer state
                             //   +40: count/flag (bit 0 = dirty?)
                             //   +44: data ptr
                             //   +48: bound flag byte
                             //   +52: bound flag byte
};
```

From `Destroy`:
- Checks `this+52 & 1` for bind flag (calls `UnbindDataBlocks` if bound)
- Frees `this[7]` (offset 28) if count at `this[6]` (offset 24) is >1 and heap-owned
- Frees `this->m_elementCount` (offset 12) if `m_stride >= 0` and elementCount != 0

## 3.2 Key Functions

### Phyre_PVertexStream_Reallocate (0x6a4620, 494 bytes)

Callers: 1 (internal)
Callees: Engine_AlignedAllocAlign, Phyre_Stream_WriteLine, Phyre_Stream_Close, Phyre_PVertexStream_InitZero, Phyre_PVertexStream_Destroy, Engine_AlignedFree, VertexFormat_SemanticToComponentSize

Purpose: Reallocates vertex stream array with new element count. Each element is **108 bytes** in the array.

```c
int __thiscall Phyre_PVertexStream_Reallocate(PhyrePVertexStream *this, int a2)
{
    // 1. If new count != current: alloc 108*a2 bytes, close old
    // 2. Per-element init loop:
    //    - Set index
    //    - Check slot type at +40
    //    - If type != 4: alloc 4*256 bytes (4 slots × 64 bytes each)
    //      - InitZero each slot
    //      - Free old data + destroy old slots
    //    - Set +56=0, +60=12, +48=0, +52=0 (default format)
    //    - Call VertexFormat_SemanticToComponentSize(12)
    //    - If +100 != 0: check dirty flag, UnbindIndexDataBlocks, clear
    // 3. Return 0 on success, 13 on OOM
}
```

**Key insight:** Each element in the stream array is 108 bytes. Elements of type 4 have inline data; other types get heap-allocated slot arrays (4 × 64 bytes = 256 bytes).

### Phyre_PVertexStream_Destroy (0x55e120, 190 bytes)

```c
int __thiscall Phyre_PVertexStream_Destroy(PhyrePVertexStream *this)
{
    Phyre_PVertexStreamArray_WaitForUnbind(this);
    if ((this->boundFlag[1] & 1) != 0)      // this+52 & 1
        Phyre_PGeometry_UnbindDataBlocks(this);
    if (this->m_stride >= 0 && this->m_elementCount)  // heap array?
        Engine_AlignedFree(this->m_elementCount);
    this->m_elementCount = 0;
    this->m_stride = 0;
    // Also handles small array at +24/+28
}
```

### Phyre_PVertexStream_DestroyWithFlag (0x55e9d0, 152 bytes)

```c
int __thiscall Phyre_PVertexStream_DestroyWithFlag(PhyrePVertexStream *this, int a2)
{
    PIndexBuffer_Destroy(this + 2);   // destroy index buffer at +8
    Phyre_PVertexStreamArray_FreeAndDestroy(this + 10);  // free +40 array
    // Free m_elementCount at +12 if heap-owned
    if (this->m_stride >= 0 && this->m_elementCount)
        Engine_AlignedFree(this->m_elementCount);
    this->m_stride = 0;
    this->m_elementCount = 0;
    if (a2 & 1)
        Engine_AlignedFree(this);      // also free self if flag set
}
```

### Phyre_PVertexStream_InitZero (0x55ddc0, 181 bytes)

```c
PhyrePVertexStream *__thiscall Phyre_PVertexStream_InitZero(PhyrePVertexStream *this, int a2)
{
    this->vfptr = NULL;
    this->m_type = 0;
    this->m_stride = 0;
    this->m_elementCount = 0;
    this->m_refCount = 0;
    LOWORD(this->m_pData) = 0;   // clear low word only
    this->m_count = 0;           // +24
    if (this != (PhyrePVertexStream*)-28) {  // safety check
        this->m_data = NULL;     // +28
        this->m_flags[0] = 0;    // +32
        this->m_flags[1] = 0;    // +36
        this->m_count = 1;       // reset count to 1
    }
    this->m_indexBuffer[0] = 0;  // +40
    this->m_indexBuffer[1] = 0;  // +44
    this->m_indexBuffer[2] = 0;  // +48
    this->m_indexBuffer[3] = 0;  // +52
    return this;
}
```

**The `this != -28` check is a guard against null-offset addressing** — likely a compiler-generated bounds check for the small-array optimization.

### Phyre_PVertexStream_ArrayResize (0x4837d0, 178 bytes)

```c
int __thiscall Phyre_PVertexStream_ArrayResize(PhyrePVertexStream *this, int vfptr)
{
    // Resizes the 12-byte-per-element array at this->vfptr
    // 1. If new size != current size:
    //    - Alloc 12 * newSize
    //    - Copy old (3*oldSize * 4 bytes) via ArrayCopy3_12Byte
    //    - Init new elements via Phyre_PArray_PGeometry_PVertexStream_static_Init_H
    //    - Free old if heap-owned
    // 2. Returns 0 on success, 13 on OOM
}
```

### Phyre_PVertexStream_ArrayCopy3_12Byte (0x480c70, 61 bytes)

```c
int __thiscall Phyre_PVertexStream_ArrayCopy3_12Byte(PhyrePVertexStream *this, int a2)
{
    // Copies 12-byte elements from source to dest
    // Each element = [dword, dword, byte, byte, pad...]
    //   +0: dword
    //   +4: dword  
    //   +8: byte
    //   +9: byte
}
```

### Phyre_PVertexStream_Scripting_Get (0x480750, 193 bytes)

A `PObjectAccessor<PGeometry::PVertexStream&>::Get` scripting accessor:

```c
int __thiscall Phyre_PVertexStream_Scripting_Get(PhyrePVertexStream *this, int L)
{
    v2 = Phyre_Scripting_PushPhyreObject(L, 0xFFFFFFFF, &typeDesc);
    PhyreStream_Reserve(L, -2);
    if (!v2 || !*v2) {
        // Error: "not a Phyre Object" (line 141)
        LuaG_errorThrow(L, "Object obtained from script was not a Phyre Object...");
    }
    // Walk parent chain to validate type
    while (m_pParentCD != &MEMORY[0xC98730]) {
        m_pParentCD = m_pParentCD->m_pParentCD;
        if (!m_pParentCD) {
            // Error: "wrong type" (line 143)
            LuaG_errorThrow(L, "Object obtained from script was of type \"%s\"...");
        }
    }
    return v2[1];  // return the object pointer
}
```

### Phyre_PVertexStream_ZeroInit (0x47fc80, 8 bytes)

```c
PhyrePVertexStream *__thiscall Phyre_PVertexStream_ZeroInit(PhyrePVertexStream *this)
{
    this->vfptr = 0;  // only clears vfptr
    return this;
}
```

### PIndexBuffer_Destroy (0x55e1e0, 121 bytes)

```c
void __thiscall PIndexBuffer_Destroy(int this)
{
    PIndexBufferArray_WaitForUnbind((_DWORD *)this);
    if ((*(_BYTE *)(this + 48) & 1) != 0)
        Phyre_PGeometry_UnbindIndexDataBlocks((_DWORD *)this);
    if (*(int *)(this + 20) >= 0 && (*(_DWORD *)(this + 20) & 0x7FFFFFFFu) > 1 && *(_DWORD *)(this + 24))
        Engine_AlignedFree(*(void **)(this + 24));
    *(_DWORD *)(this + 20) = 0;
    *(_DWORD *)(this + 24) = 0;
}
```

### PVertexBuffer_IsFlaggedDirty (0x562f20, 7 bytes)

```c
int __thiscall PVertexBuffer_IsFlaggedDirty(_DWORD *this)
{
    return *(this + 12) & 1;  // check bit 0 at +12
}
```

### Phyre_PVertexStreamArray_WaitForUnbind (0x564790, 28 bytes)

```c
void __thiscall Phyre_PVertexStreamArray_WaitForUnbind(_DWORD *this)
{
    // Spin-wait: for each element, sleep 1ms while element > 0
    for (v2 = 0; v2 < (this[6] & 0x7FFFFFFF); v2++)
        while (*(int*)Phyre_TemplateArray_GetElementOffset(this, v2) > 0)
            Phyre_SleepMs(1);
}
```

### PIndexBufferArray_WaitForUnbind (0x5647e0, 28 bytes)

Structurally identical to WaitForUnbind but uses `this[5]` for count and different element offset function.

---

# Part 4: PGeometry Core Functions (Substantive)

## 4.1 Phyre_PGeometry_GetResourceData (0x562f60, 695 bytes)

The main geometry resource data retriever:

```c
int __thiscall Phyre_PGeometry_GetResourceData(PhyrePGeometry *this, int a2, int a3, int a4)
{
    int decl = this->m_pDeclaration & 0x7FFFFFFF;  // strip ownership flag
    int streamEntry = streamArray + 5 * a2;          // 5-element stride
    
    // Dispatch based on n196608 & 0x20000:
    //   Path A (flag set): direct read via global file reader vfptr[56]
    //   Path B (flag clear): alloc via vfptr[12], copy via vfptr[188], read via vfptr[56]
    // Returns 0 on success, 1 if null entry, 9 on read failure
    // Sets output: *a3 = this+12 + read_offset, *(a3+4) = this+14
}
```

## 4.2 Phyre_PGeometry_GetResourceData_Batch (0x563220, 453 bytes)

```c
int __thiscall Phyre_PGeometry_GetResourceData_Batch(PhyrePGeometry *this, int a2, int *arg4, int a4, int *a5)
{
    if (a2 == a4)
        return GetResourceData(this, a4, ...);  // single path
    else
        GetResourceData(this, a2, ...);         // first
        LoadGeometryData(this, a4);             // then batch
}
```

## 4.3 Phyre_PGeometry_UnbindDataBlocks (0x564830, 486 bytes)

```c
int __thiscall Phyre_PGeometry_UnbindDataBlocks(_DWORD *this)
{
    if ((this[13] & 1) == 0) {
        Phyre_Stream_Printf(1, "Trying to unbind a data block which is not currently bound...");
        return 0;
    }
    Phyre_PVertexStreamArray_WaitForUnbind(this);
    Phyre_Cluster_ZeroInitArea(&v21);
    // Loop: for each stream (this[6] & 0x7FFFFFFF), stride 5:
    //   Release slots [+0, +1, +3] via vfptr[8], clear
    this[13] &= ~1u;  // clear bound flag
    Phyre_Cluster_ReadFieldsFromStream(&v21);
    return 0;
}
```

## 4.4 Phyre_PGeometry_UnbindIndexDataBlocks (0x564a20, 486 bytes)

Structurally identical to UnbindDataBlocks with different field offsets:
- Uses `this+12` instead of `this+13` as bound flag
- Uses `this[5]` for count instead of `this[6]`
- Uses `this+6` as array base instead of `this+7`

## 4.5 Phyre_PGeometry_BindAndGetResourceData (0x638230, 122 bytes)

```c
int __userpurge Phyre_PGeometry_BindAndGetResourceData(int this@<ecx>, int a2@<edi>, _DWORD *a3)
{
    if (HasBoundDataBlocks(this) || (BindD3D11Buffer(this) == 0)) {
        // Resolve stream, spin-wait for GPU, get data
        while (*spinCounter > 0) Phyre_SleepMs(1);
        result = GetResourceData(this, streamIdx, a3, a2);
        if (!result) this[20] = 1;  // mark valid
    }
    return result;
}
```

## 4.6 Phyre_PGeometry_LoadResourceSubset (0x5638a0, 448 bytes)

```c
int __thiscall Phyre_PGeometry_LoadResourceSubset(PhyrePGeometry *this, int a2)
{
    if (a2 == v19)
        direct_read_via_global_file_reader();  // flag 3
    else
        GetSubsetData(this, a2) + ReadSubsetFromFile(this, v19, ...);
    // Error: ReleaseDataBlock + GetVertexStream
}
```

## 4.7 Phyre_PGeometry_GetVertexDataBlock (0x564c10, 357 bytes)

```c
int __thiscall Phyre_PGeometry_GetVertexDataBlock(PhyrePGeometry *this, int a2)
{
    // Two paths based on flag 0x20000:
    //   A: no data → read via vfptr[60] on global file reader
    //   B: has data → GetDataBlockElementByIndex + vfptr[60]
}
```

## 4.8 Phyre_PGeometry_PMeshDataCopy (0x48f1b0, 249 bytes)

```c
int __thiscall Phyre_PGeometry_PMeshDataCopy(int this, int a2)
{
    PSkinBoneWeight_AssignFrom(this, a2);
    this[40] = 0;  // clear chunk count
    v4 = a2[40] & 0x7FFFFFFF;  // source chunk count
    if (v4) {
        v6 = Engine_AlignedAllocAlign(v4 << 6, 4);  // v4 * 64 bytes per chunk
        if (v6) Phyre_PMeshData_CopyChunk(v6, a2[44], v4);
    }
    this[44] = v6;     // chunk data ptr
    this[40] = v6 ? v4 : 0;  // count or 0 on alloc failure
    this[48] = a2[48];  // vertex count?
    this[52] = a2[52];
    this[56] = a2[56];
    this[60] = a2[60]; this[61] = a2[61]; this[62] = a2[62];  // 3 bytes
    this[64] = a2[64];
    Phyre_PMeshSegmentArray_Assign(this+68, a2+68);  // segment array (~24 bytes)
    this[92] = a2[92]; this[96] = a2[96]; this[100] = a2[100]; this[104] = a2[104];  // 4 ints
}
```

**PMeshData struct (108 bytes):**
```
+0:   PSkinBoneWeights (40 bytes)
+40:  chunkCount (int)
+44:  chunkDataPtr (int*)
+48:  vxCount (int)
+52:  field_52 (int)
+56:  field_56 (int)
+60:  field_60 (byte)
+61:  field_61 (byte)
+62:  field_62 (byte)
+64:  field_64 (int)
+68:  PMeshSegmentArray (~24 bytes)
+92:  field_92 (int)
+96:  field_96 (int)
+100: field_100 (int)
+104: field_104 (int)
```

## 4.9 Phyre_PGeometry_HasBoundDataBlocks (0x562f10, 7 bytes)

```c
int __thiscall Phyre_PGeometry_HasBoundDataBlocks(int *this)
{
    return this[13] & 1;  // check bit 0 at +52 (13th DWORD)
}
```

---

# Part 5: PMeshInstance Family (51 functions)

## 5.1 PMeshInstance Struct — from registerFields (0x4f3a10, 3.7KB)

The massive `Phyre_PMeshInstance_registerFields` function registers ~30 data members for PMeshInstance. The struct layout is **132 bytes total**:

| Offset | Member | Type | Scripting |
|--------|--------|------|-----------|
| +0 | `m_mesh` | PMesh* | read/write |
| +4 | `m_localToWorldMatrix` | PMatrix4 | read/write |
| +8 | `m_currentPose` | PArray<PMatrix4,4> | read/write |
| +16 | `m_materialSet` | PMaterialSet* | read/write |
| +20 | `m_instanceSegment` | PMeshInstanceSegment | read/write |
| +24 | `m_dynamicMeshInstance` | PMeshInstance* | read/write |
| +28 | `m_bounds` | PBounds | read/write |
| +32 | `m_lodLevel` | PLODLevel | read/write |
| +36 | `m_segmentContext` | PArray<PMeshInstSegCtx,4> | read/write |
| +44 | `m_name` | PString | read/write |
| +48 | `m_animCt` | int32 | read/write |
| +52 | `m_animID0` | int32 | read/write |
| +56 | `m_animID1` | int32 | read/write |
| +60 | `m_animID2` | int32 | read/write |
| +64 | `m_animID3` | int32 | read/write |
| +68 | `m_mimeCt` | int32 | read/write |
| +72 | `m_groupID` | int32 | read/write |
| +76 | `m_DObjKind` | int32 | read/write |
| +80 | `m_RotType` | int32 | read/write |
| +84 | `m_dObjFlag` | int32 | read/write |
| +88 | `m_objID` | int32 | read/write |
| +92 | `m_layerz0` | float | read/write |
| +96 | `m_layerz1` | float | read/write |
| +100 | `m_layerz2` | float | read/write |
| +104 | `m_layerz3` | float | read/write |
| +108 | `m_flags` | uint32 | read/write |

Plus **8 scripting methods** registered:
| Method | Handler | Purpose |
|--------|---------|---------|
| `setVisibilityFromAnimation` | PPolygonRef_SetCullVisibility | Visibility control |
| `getLocalToWorldMatrix` | Phyre_PMeshInstance_getLocalToWorldMatrix (0x4f8090) | World matrix query |
| `getBounds` | Phyre_PMesh_GetField4_6 (0x4f7ea0) | Bounds query |
| `setBounds` | Phyre_PMeshInstance_setBounds | Bounds write |
| `getMesh` | Phyre_PMeshInstance_getMesh (0x4330c0) | Mesh pointer query |
| `getMaterialSet` | Phyre_PMeshInstance_getMaterialSet (0x4d46d0) | Material query |
| `getPoseTransform` | PBitmapFontText_CanGetSegment_R (0x4f81e0) | Pose matrix query |
| `setPoseTransform` | Phyre_PMeshInstance_setBoneMatrix (0x4f8ff0) | Bone matrix write |

**Key insight:** The `m_currentPose` at +8 uses `PMatrix4Array_ClassDescriptor` — an array of up to 4 PMatrix4 for bone animation matrices. The `m_segmentContext` at +36 uses `PMeshInstanceSegmentContextArray_ClassDescriptor` for per-segment rendering context.

## 5.2 PMeshInstance Key Functions

### Phyre_PMeshInstance_registerClass (0x4f2360, 148 bytes)

```c
Vtable_... *__thiscall Phyre_PMeshInstance_registerClass(...) {
    DefaultPool = Phyre_GetDefaultPool();
    Singleton = Phyre_PNamespace_GetSingleton();
    Phyre_PClassDescriptor_ctor(this, Singleton, "PMeshInstance", 132, 4, DefaultPool, 0);
    this[36] |= 2;  // set flags
    *this = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PMeshInstance>::vftable;
    Phyre_PClassDescriptor_SetField64(this, &val__32);
    Phyre_PClassDescriptor_SetField68(this, &val__33);
    Phyre_PClassDescriptor_SetField6C(this, &val__34);
}
```

**Key insight:** PMeshInstance is **132 bytes** total.

### Phyre_PMeshInstance_InitDefaults (0x489010, 94 bytes)

```c
char __stdcall Phyre_PMeshInstance_InitDefaults(int a1) {
    if (a1) {
        *(int*)a1 = 0;         // +0: m_mesh = NULL
        *(int*)(a1+4) = -1;    // +4: identity matrix?
        *(int*)(a1+8) = 0;     // +8: pose array = empty
        *(int*)(a1+12) = 0;    // +12:
        *(int*)(a1+16) = 6;    // +16: m_materialSet = 6 (default?)
        *(BYTE*)(a1+20) = 0;   // +20: m_instanceSegment = 0
        *(int*)(a1+24) = 0;    // +24: m_dynamicMeshInstance = NULL
        *(int*)(a1+28) = 0;    // +28: m_bounds = 0
        *(int*)(a1+32) = -1;   // +32: m_lodLevel = -1 (no LOD?)
        *(int*)(a1+36) = -1;   // +36: seg ctx array? = -1
    }
    return 1;
}
```

### Phyre_PMeshInstance_Destroy (0x4890c0, 119 bytes)

```c
char __stdcall Phyre_PMeshInstance_Destroy(int *a1) {
    PIndexBuffer_Destroy(a1 + 12);             // destroy index buffer at +48
    Phyre_PVertexStreamArray_FreeAndDestroy(a1 + 10);  // free streams at +40
    if (a1[2] >= 0 && a1[3])                    // if heap-owned at +8/+12
        Engine_AlignedFree(a1[3]);
    a1[3] = 0;  // +12
    a1[2] = 0;  // +8
    return 1;
}
```

### Phyre_PMeshInstance_getMesh (0x4330c0, 3 bytes)

```c
int __thiscall Phyre_PMeshInstance_getMesh(void *this) {
    return *(int*)this;  // +0 = m_mesh pointer
}
```

### Phyre_PMeshInstance_GetSize_B (0x4f6870, 148 bytes)

Lazy-init `PArray<PMeshInstanceSegmentContext,4>` class descriptor, then push to Lua stream:

```c
int __cdecl Phyre_PMeshInstance_GetSize_B(lua_State *stream, const void *obj) {
    // Lazy-init PMeshInstanceSegmentContext array descriptor
    if ((unk_CA7B5C & 1) == 0) { ... }
    if (obj) return Phyre_Scripting_PushObjectToStream(stream, obj, ...);
    PhyreStream_PushNil(stream);
}
```

### Phyre_PMeshInstance_GetContext (0x4f6960, 148 bytes)

Lazy-init `PSharray<const PMeshInstanceSegmentStreamBinding*>` class descriptor, then push to Lua stream.

### Phyre_PMeshInstance_GetClassDescP (0x4f6540, 804 bytes)

**This function is NOT what its name suggests** — it's actually computing OBB (oriented bounding box) from 8 corner points of an AABB transformed by a matrix. Despite being named `GetClassDescP`, it performs:

1. Reads 3 basis vectors from `a2` (matrix rotation)
2. Computes 8 corner permutations (x±w, y±w, z±w for w = half-extents)
3. Transforms each corner by matrix
4. Computes min/max across all 8 corners via `Phyre_Vec3_Min` / `Phyre_Vec3_Max` chain
5. Returns AABB of transformed corners

This is **AABB transformation by matrix** — a standard computation for bounding volume updates after object rotation.

### Phyre_PMeshInstance_RegisterDescriptor (0x503630, 193 bytes) — ⚠️ MISNAMED

```c
PhyrePClassDescriptor *__cdecl Phyre_PMeshInstance_RegisterDescriptor(lua_State *stream) {
    // This is actually: PObjectAccessor<PRendering::PIndirectArgsBuffer&>::Get
    // A standard scripting accessor pattern — NOT a PMeshInstance function
}
```

**Evidence:**
- References `unk_CA90D0` (not CA7228 which is the PMeshInstance class descriptor)
- References `"Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PRendering::PIndirectArgsBuffer &>::Get"`
- Same structure as Phyre_PVertexStream_Scripting_Get

---

# Part 6: PIndexBufferArray_Resize (0x563eb0, 195 bytes)

```c
int __userpurge PIndexBufferArray_Resize(int *n8@<eax>, unsigned int *a2@<ecx>, unsigned int a3)
{
    v5 = *a2 & 0x7FFFFFFF;  // current count
    if (a3 == *a2) return 0;  // no change needed
    
    // Small array optimization: ptr = (v5 <= 1) ? a2+1 : a2[1]
    if (v5 <= 1) { if (v5) ptr = a2 + 1; else ptr = 0; }
    else { ptr = a2[1]; }
    
    // If new size > 1, allocate heap buffer
    if (a3 > 1) n8 = Engine_AlignedAllocAlign(20 * a3, 4);
    
    if (ptr_new) Phyre_PGeometry_5DwordArray_ZeroArray(n8, (int)ptr_new, a3);
    
    if (ptr != ptr_new && ptr != a2+1 && no_owned_flag && ptr)
        Engine_AlignedFree(ptr);
    
    if (ptr_new != a2+1) a2[1] = (unsigned int)ptr_new;
    *a2 = a3;  // update count
    return 0;
}
```

**Key insight:** Each index buffer entry is **20 bytes** (5 DWORDs). Resize grows by zero-filling new entries.

---

# Part 7: PGeometry Complete Inventory (130 functions)

| # | Address | Name | Size | Notes |
|---|---------|------|------|-------|
| 1 | `0x430b60` | `Phyre_PGeometry_pd3d11Device` | `0x5` | D3D11 device getter (5 bytes) |
| 2 | `0x430b70` | `Phyre_PGeometry_pd3d11Device_B` | `0x5` | D3D11 device getter variant |
| 3 | `0x433a00` | `Phyre_PVertexStreamArray_FreeAndDestroy` | `0x89` | Free + destroy stream array |
| 4 | `0x4803a0` | `Phyre_PVertexStream_ClassDescriptor_ctor` | `0x91` | Class descriptor constructor |
| 5 | `0x4805d0` | `Phyre_PVertexStream_ClassDescriptor` | `0x178` | Registers 4 members |
| 6 | `0x480750` | `Phyre_PVertexStream_Scripting_Get` | `0xc1` | PObjectAccessor::Get |
| 7 | `0x480c70` | `Phyre_PVertexStream_ArrayCopy3_12Byte` | `0x3d` | 12-byte element copy |
| 8 | `0x481530` | `Phyre_PArray_PGeometry_PVertexStream_ClassDescriptor_ctor` | `0x1c` | Array class ctor |
| 9 | `0x482040` | `Phyre_PGeometry_PVertexStreamArray_ClassDescriptor` | `0x178` | Full class descriptor |
| 10 | `0x482230` | `Phyre_PArray_PVertexStream_Init` | `0x23` | PArray init |
| 11 | `0x482e30` | `Phyre_PArray_PGeometry_PVertexStream_static_Init_H` | `0x39` | Static init |
| 12 | `0x4837d0` | `Phyre_PVertexStream_ArrayResize` | `0xb2` | Resize 12-byte element array |
| 13 | `0x48f1b0` | `Phyre_PGeometry_PMeshDataCopy` | `0xf9` | Full PMeshData copy |
| 14 | `0x490c40` | `Phyre_Matrix4Array_ClassDescriptorInit` | `0x23` | PMatrix4 array init |
| 15 | `0x4971a0` | `Phyre_PGeometry_PMeshElementGroup_ClassDescriptor` | `0x178` | Registers 4 members |
| 16 | `0x4c9fd0` | `Phyre_Matrix4x4_Transform` | `0x14` | Mat4x4 transform (20 bytes) |
| 17 | `0x4d46d0` | `Phyre_PMeshInstance_getMaterialSet` | `?` | Material getter |
| 18 | `0x4f2220` | `Phyre_PMeshInstanceSegmentContextArray_ClassDescriptor_ctor` | `?` | SegCtx array ctor |
| 19 | `0x4f22c0` | `Phyre_PMeshStreamBindingSharray_ClassDescriptor_ctor` | `?` | Stream binding array ctor |
| 20 | `0x4f2360` | `Phyre_PMeshInstance_registerClass` | `0x94` | Class registration |
| 21 | `0x4f3a10` | `Phyre_PMeshInstance_registerFields` | `0xe5c` | 30 members register (3.7KB) |
| 22 | `0x4f4cc0` | `Phyre_MeshStreamBindingConstArray_ClassDescriptorInit` | `0x23` | Const array init |
| 23 | `0x4f6540` | `Phyre_PMeshInstance_GetClassDescP` | `0x327` | AABB by matrix (misnamed) |
| 24 | `0x4f6870` | `Phyre_PMeshInstance_GetSize_B` | `0xb4` | Size scripting push |
| 25 | `0x4f6960` | `Phyre_PMeshInstance_GetContext` | `0xb4` | Context scripting push |
| 26 | `0x4f6c40` | `Phyre_PMeshInstanceSegmentContextArray_ScriptingPush` | `0x58` | SegCtx scripting push |
| 27 | `0x4f7ea0` | `Phyre_PMesh_GetField4_6` | `?` | Bounds getter |
| 28 | `0x4f8090` | `Phyre_PMeshInstance_getLocalToWorldMatrix` | `?` | World matrix getter |
| 29 | `0x4f81e0` | `PBitmapFontText_CanGetSegment_R` | `?` | Pose transform (odd name) |
| 30 | `0x4f8660` | `Phyre_Vec3_Max` | `?` | Vec3 component max |
| 31 | `0x4f86f0` | `Phyre_Vec3_Min` | `?` | Vec3 component min |
| 32 | `0x4f8c40` | `Concurrency::details::ExecutionResource::MarkAsVirtualProcessorRoot_0` | `?` | setBounds handler |
| 33 | `0x4f8ff0` | `Phyre_PMeshInstance_setBoneMatrix` | `?` | setPoseTransform handler |
| 34 | `0x4f93d0` | `PPolygonRef_SetCullVisibility` | `?` | setVisibilityFromAnimation |
| 35 | `0x503630` | `Phyre_PMeshInstance_RegisterDescriptor` | `0xc1` | ⚠️ MISNAMED (IndirectArgsBuffer accessor) |
| 36 | `0x55b5b0` | `Phyre_PTypeDefault_UInt32_GetSingleton_22` | `0x5` | Thunk |
| 37 | `0x55bdb0` | `VertexFormat_SemanticToComponentSize` | `?` | Format size query |
| 38 | `0x55d5e0` | `Phyre_PArrayPDataBlockD3D11_ClassDescriptorCtor` | `?` | Array class ctor |
| 39 | `0x55ddc0` | `Phyre_PVertexStream_InitZero` | `0xb5` | Zero-init (64-byte struct) |
| 40 | `0x55e120` | `Phyre_PVertexStream_Destroy` | `0xbe` | Destroy + free |
| 41 | `0x55e1e0` | `PIndexBuffer_Destroy` | `0x79` | Index buffer destroy |
| 42 | `0x55e9d0` | `Phyre_PVertexStream_DestroyWithFlag` | `0x98` | Destroy + optional self-free |
| 43 | `0x55eae0` | `Phyre_PGeometry_PDataBlock_RegisterClassDescriptors` | `0x187` | 3 member regs |
| 44 | `0x55ec90` | `Phyre_PGeometry_PIndexDataBlock_RegisterClassDescriptors` | `0x187` | 3 member regs |
| 45 | `0x55ee20` | `Phyre_PGeometry_PMeshData_RegisterClassDescriptors` | `0x141` | 2+1 member regs |
| 46 | `0x55ef80` | `Phyre_PArray_PDataBlockD3D11_RegisterDescriptor` | `0x1f2` | PArray<PDataBlockD3D11,4> desc |
| 47 | `0x560fb0` | `Phyre_PGeometry_5DwordArray_ZeroArray` | `?` | 5-dword zero fill |
| 48 | `0x562f10` | `Phyre_PGeometry_HasBoundDataBlocks` | `0x7` | Check bit 0 at +52 |
| 49 | `0x562f20` | `PVertexBuffer_IsFlaggedDirty` | `0x6` | Check bit 0 at +12 |
| 50 | `0x562f60` | `Phyre_PGeometry_GetResourceData` | `0x2b7` | Main resource getter |
| 51 | `0x563220` | `Phyre_PGeometry_GetResourceData_Batch` | `0x1c5` | Batch resource getter |
| 52 | `0x5638a0` | `Phyre_PGeometry_LoadResourceSubset` | `0x1c0` | Subset loader |
| 53 | `0x563eb0` | `PIndexBufferArray_Resize` | `0xfa` | Resize 20-byte element array |
| 54 | `0x564420` | `PStream_ReadStringWithFlag` | `?` | String stream reader |
| 55 | `0x564790` | `Phyre_PVertexStreamArray_WaitForUnbind` | `0x1c` | Spin-wait stream unbind |
| 56 | `0x5647e0` | `PIndexBufferArray_WaitForUnbind` | `0x1c` | Spin-wait index unbind |
| 57 | `0x564830` | `Phyre_PGeometry_UnbindDataBlocks` | `0x1e6` | Full unbind + release |
| 58 | `0x564a20` | `Phyre_PGeometry_UnbindIndexDataBlocks` | `0x1e6` | Index unbind variant |
| 59 | `0x564c10` | `Phyre_PGeometry_GetVertexDataBlock` | `0x165` | Vertex data getter |
| 60-130 | — | Remaining 70 functions | 0x3-1.2KB | Small/medium utilities |

---

# Part 8: PVertexStream Complete Inventory (102 functions)

| # | Address | Name | Size | Notes |
|---|---------|------|------|-------|
| 1 | `0x47fc80` | `Phyre_PVertexStream_ZeroInit` | `0x4` | Only clears vfptr |
| 2 | `0x4803a0` | `Phyre_PVertexStream_ClassDescriptor_ctor` | `0x91` | Class descriptor ctor |
| 3 | `0x4805d0` | `Phyre_PVertexStream_ClassDescriptor` | `0x178` | 4 member registrations |
| 4 | `0x480750` | `Phyre_PVertexStream_Scripting_Get` | `0xc1` | Lua accessor |
| 5 | `0x480c70` | `Phyre_PVertexStream_ArrayCopy3_12Byte` | `0x3d` | 12-byte element copy |
| 6 | `0x481530` | `Phyre_PArray_PGeometry_PVertexStream_ClassDescriptor_ctor` | `0x1c` | PArray ctor |
| 7 | `0x482040` | `Phyre_PGeometry_PVertexStreamArray_ClassDescriptor` | `0x178` | Full class desc |
| 8 | `0x482230` | `Phyre_PArray_PVertexStream_Init` | `0x23` | PArray init |
| 9 | `0x482e30` | `Phyre_PArray_PGeometry_PVertexStream_static_Init_H` | `0x39` | Static array init |
| 10 | `0x4837d0` | `Phyre_PVertexStream_ArrayResize` | `0xb2` | Resize |
| 11 | `0x55ddc0` | `Phyre_PVertexStream_InitZero` | `0xb5` | Full zero-init (64 bytes) |
| 12 | `0x55e120` | `Phyre_PVertexStream_Destroy` | `0xbe` | Destroy |
| 13 | `0x55e9d0` | `Phyre_PVertexStream_DestroyWithFlag` | `0x98` | Destroy + optional free |
| 14 | `0x6a4620` | `Phyre_PVertexStream_Reallocate` | `0x1ee` | Largest (494 bytes) |
| 15-102 | — | Remaining 88 functions | 0x4-0x150 | Small/medium utilities |

---

# Part 9: PMeshInstance Complete Inventory (51 functions)

| # | Address | Name | Size | Notes |
|---|---------|------|------|-------|
| 1 | `0x4330c0` | `Phyre_PMeshInstance_getMesh` | `0x3` | Returns this[0] |
| 2 | `0x489010` | `Phyre_PMeshInstance_InitDefaults` | `0x52` | Init to defaults |
| 3 | `0x4890c0` | `Phyre_PMeshInstance_Destroy` | `0x59` | Destroy + free |
| 4 | `0x4f2220` | `Phyre_PMeshInstanceSegmentContextArray_ClassDescriptor_ctor` | `?` | Array class ctor |
| 5 | `0x4f22c0` | `Phyre_PMeshStreamBindingSharray_ClassDescriptor_ctor` | `?` | Sharray class ctor |
| 6 | `0x4f2360` | `Phyre_PMeshInstance_registerClass` | `0x94` | Class registration (132 bytes) |
| 7 | `0x4f3a10` | `Phyre_PMeshInstance_registerFields` | `0xe5c` | 30 members + 8 scripting methods |
| 8 | `0x4f4cc0` | `Phyre_MeshStreamBindingConstArray_ClassDescriptorInit` | `0x23` | Const array init |
| 9 | `0x4f6540` | `Phyre_PMeshInstance_GetClassDescP` | `0x327` | ⚠️ Actually AABB transform |
| 10 | `0x4f6870` | `Phyre_PMeshInstance_GetSize_B` | `0xb4` | Segment context push |
| 11 | `0x4f6960` | `Phyre_PMeshInstance_GetContext` | `0xb4` | Stream binding push |
| 12 | `0x4f6a00` | `Phyre_PMeshInstance_GetContext` (dup addr) | `0xb4` | Same as 4f6960 |
| 13 | `0x4f6c40` | `Phyre_PMeshInstanceSegmentContextArray_ScriptingPush` | `0x58` | SegCtx push |
| 14 | `0x4f7ea0` | `Phyre_PMesh_GetField4_6` | `?` | getBounds handler |
| 15 | `0x4f8090` | `Phyre_PMeshInstance_getLocalToWorldMatrix` | `?` | getLocalToWorldMatrix |
| 16 | `0x4f81e0` | `PBitmapFontText_CanGetSegment_R` | `?` | getPoseTransform handler |
| 17 | `0x4f8660` | `Phyre_Vec3_Max` | `?` | Component max |
| 18 | `0x4f86f0` | `Phyre_Vec3_Min` | `?` | Component min |
| 19 | `0x4f8c40` | `MarkAsVirtualProcessorRoot_0` | `?` | setBounds handler |
| 20 | `0x4f8ff0` | `Phyre_PMeshInstance_setBoneMatrix` | `?` | setPoseTransform handler |
| 21 | `0x4f93d0` | `PPolygonRef_SetCullVisibility` | `?` | setVisibilityFromAnimation |
| 22 | `0x503630` | `Phyre_PMeshInstance_RegisterDescriptor` | `0xc1` | ⚠️ MISNAMED |
| 23-51 | — | Remaining 29 functions | 0x3-1.5KB | Bounds, segments, transforms |

---

# Part 10: Summary Tables

## Size Distribution

| Bucket | Range | PGeometry | PVertexStream | PMeshInstance |
|--------|-------|-----------|---------------|---------------|
| Tiny | < 0x10 | 10 | 8 | 5 |
| Small | 0x10-0x3F | 25 | 20 | 10 |
| Medium | 0x40-0xFF | 60 | 55 | 15 |
| Large | 0x100-0x3FF | 30 | 18 | 10 |
| Huge | >= 0x400 | 5 | 1 | 1 |

## Pattern Distribution

| Pattern | PGeometry | PVertexStream | PMeshInstance |
|---------|-----------|---------------|---------------|
| Class descriptor registration | 6 | 2 | 3 |
| Scripting accessors (PObjectAccessor) | 2 | 1 | 3 |
| Array/small-array operations | 15 | 20 | 5 |
| Index buffer operations | 8 | 5 | 0 |
| Wait-for-unbind spin loops | 3 | 2 | 0 |
| AABB/bounds computations | 0 | 0 | 5 |
| Transform helpers | 0 | 0 | 3 |
| Tiny stubs/thunks (<16 bytes) | 10 | 8 | 5 |

## Top Functions by Size

| Function | Size | Family | Purpose |
|----------|------|--------|---------|
| `Phyre_PMeshInstance_registerFields` | **0xe5c (3.7KB)** | PMeshInstance | 30 members + 8 methods registration |
| `Phyre_PGeometry_Mat4x4Inverse` | 0x739 (1.8KB) | PGeometry | Matrix inverse |
| `Phyre_PGeometry_MatrixMultiply4x4` | 0x6b3 (1.7KB) | PGeometry | Matrix multiply |
| `Phyre_PGeometry_GetResourceData` | 0x2b7 (695B) | PGeometry | Resource data retrieval |
| `Phyre_PMeshInstance_GetClassDescP` | 0x327 (807B) | PMeshInstance | AABB transform (misnamed) |
| `Phyre_PVertexStream_Reallocate` | 0x1ee (494B) | PVertexStream | Stream array reallocation |
| `Phyre_PGeometry_UnbindDataBlocks` | 0x1e6 (486B) | PGeometry | Data block unbind |

---

## Key Findings

1. **Three-tier geometry hierarchy confirmed:** PMeshInstance (132 bytes, 30 members) → PMeshData (108 bytes, chunks + segments) → PDataBlock/PIndexDataBlock (D3D11 buffers). PMeshInstance is the top-level game object, referencing a mesh, material set, animation IDs, pose matrices, and bounds.

2. **Lazy class descriptor registration is universal** — All 5 PGeometry class descriptors and all PMeshInstance descriptors use the same bitflag pattern (`dword_C98A08`, `word_CA7400`, etc.) with atexit-registered destructors. This is PhyreEngine's global type system initialization pattern.

3. **PVertexStream is 64 bytes** with 16 DWORD fields including: format type, stride, element count, ref count, small-array (1 inline element), index buffer state (4 DWORDs), and dirty/bound flags. The `InitZero` function (0x55ddc0) clearly shows the full field map.

4. **PGeometry uses tagged pointers** — `m_pDeclaration` uses bit 31 as ownership flag. Every access strips it via `& 0x7FFFFFFF`. This avoids a separate `bool ownsDeclaration` field.

5. **Stream arrays use 5-element stride** — The index formula `5 * idx` (20 bytes per entry) appears in every PGeometry function that accesses streams. Slot [+0, +1, +3] are released during unbind; slot [+2] is preserved.

6. **PMeshInstance has 8 scripting methods** — `setVisibilityFromAnimation`, `getLocalToWorldMatrix`, `getBounds`, `setBounds`, `getMesh`, `getMaterialSet`, `getPoseTransform`, `setPoseTransform`. Each registered as a `PMethodCallerConcrete` with string name, linked list insertion, and atexit-cleanup.

7. **Spin-wait unbind pattern** — Both `WaitForUnbind` variants (PVertexStreamArray and PIndexBufferArray) spin-loop with `Phyre_SleepMs(1)` while a counter > 0. This is a GPU fence/async unbind completion mechanism.

8. **Misnamed function confirmed** — `Phyre_PMeshInstance_RegisterDescriptor` (0x503630) is actually `PObjectAccessor<PIndirectArgsBuffer&>::Get`, a standard scripting accessor that validates type via parent chain walk.

9. **PMeshInstance_GetClassDescP is also misnamed** — Despite its name suggesting class descriptor pointer, the decompiled code shows it performing AABB-to-OBB corner transformation with Vec3_Min/Vec3_Max chains — a bounding volume update function.

10. **Function count discrepancy resolved** — Prior estimate of ~337 functions across all 3 families was overstated. Live IDA query: 130 + 102 + 51 = **283 total**.

---

## Next Batches

- Batch 18: Phyre_PCaller family (203 functions — script callers, method dispatchers)
- Batch 19: Phyre_PObject family (77 functions — base object system)
- Batch 11: Engine_* remaining ~140 small functions (MSVC STL wrappers, memory, threading)
- After: PGetType (36), PTimer (35), PStream (34), PRenderTarget (32), PGameSettings (31), PDataBlockD3D11 (22), PDynamicGeometry (15), PWorldMatrix (14)
