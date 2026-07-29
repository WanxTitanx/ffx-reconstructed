# FFX.exe Decompilation — Batch 3 (Phyre_PArray Part 1)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 15 (Phyre_PArray — constructors, destructors, data access, template instantiations)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the Phyre_PArray family — PhyreEngine's typed dynamic array template (similar to std::vector). PArray is used everywhere in the engine: property lists, member lists, animation tracks, shader params, etc. Most functions are template-generated COMDAT instantiations (small, ~0xC0 bytes each).

## Functions Decompiled

### Phyre_PArray_PTypedObject_CopyPairs (0x456e70, 31 bytes)
```c
void __cdecl Phyre_PArray_PTypedObject_CopyPairs(_DWORD *a1, _DWORD *a2, int i)
{
  for ( int j = i; j; --j ) {
    v6 = a1;
    a1 += 2;
    if ( v6 ) {
      *v6 = *a2;
      v6[1] = a2[1];
      a2 += 2;
    }
  }
}
```
- **Callers:** Internal PArray operations
- **Purpose:** Copy key-value pairs (2 DWORDs each) between arrays. Used for PTypedObject (type-erased key-value storage)
- **Key insight:** Null-skip pattern — skips elements where dest pointer is NULL

### Phyre_PArray_FreeData (0x457c50, 18 bytes)
```c
void __thiscall Phyre_PArray_FreeData(void *this)
{
  void *v1;
  v1 = (void *)*((_DWORD *)this + 5);
  if ( v1 )
    operator delete(v1);
}
```
- **Callers:** PArray cleanup paths
- **Purpose:** Free internal data buffer at offset +0x14 (m_pData) via operator delete

### Phyre_PArray_AllocAndCopy (0x457cd0, 158 bytes)
- **Callers:** PArray growth operations
- **Callees:** operator new, memmove, Phyre_PArray_FreeData
- **Purpose:** Allocate new buffer, copy existing elements, free old buffer. Core realloc pattern for dynamic arrays
- **Structure:** 10 basic blocks

### Phyre_PArray_PTypedObject_dtor (0x458030, 27 bytes)
```c
void __thiscall Phyre_PArray_PTypedObject_dtor(int this)
{
  Phyre_PArray_FreeData((void *)this);
  *(_DWORD *)this = &Phyre_PArray_PTypedObject_vftable;
}
```
- **Callers:** PTypedObject cleanup
- **Purpose:** Destructor — frees data buffer + resets vfptr (safety pattern for virtual destructor chains)

### Phyre_PArray_PTypedObject_Init (0x458530, ~300 bytes, 22 blocks)
- **Callers:** Type system initialization
- **Callees:** RegisterClassDescriptor, Init data members, FinalizeRegistration
- **Strings:** "m_count", "m_els"
- **Purpose:** Full initialization routine for PTypedObject PArray-serializable type. Uses 2-phase init with global state flags at 0xC93CEC
- **Key insight:** Data member registration for serialization — registers m_count and m_els as serializable properties

### Phyre_PArray_GetItem_Offset (0x445b30, 9 bytes)
```c
int __thiscall Phyre_PArray_GetItem_Offset(int this)
{
  return *(_DWORD *)(this + 8);
}
```
- **Callers:** Indexing operations
- **Purpose:** Returns m_itemOffset (+0x08) — the stride/offset for element access

### Phyre_PArray_GetItem_Offset_2 (0x445b60, 9 bytes)
```c
int __thiscall Phyre_PArray_GetItem_Offset_2(int this)
{
  return *(_DWORD *)(this + 8);
}
```
- **Callers:** Indexing operations (alternate vtable entry)
- **Purpose:** Same as GetItem_Offset — returns m_itemOffset at +0x08

### Phyre_PArray_SetItem_Virtual (0x445e30, 88 bytes)
- **Callers:** Scripting, data binding via vtable
- **Purpose:** Virtual setter for array item by index

### Phyre_PArray_Return0 (0x449720, 6 bytes)
```c
int __thiscall Phyre_PArray_Return0(int this)
{
  return 0;
}
```
- **Callers:** PArray vtable (default/placeholder entry)
- **Purpose:** Placeholder for unimplemented virtual — returns 0

### Phyre_PArray_GetFieldAtOffset04 (0x449770, 16 bytes)
```c
int __thiscall Phyre_PArray_GetFieldAtOffset04(void *this)
{
  return *((_DWORD *)this + 1);
}
```
- **Callers:** Reflection, data binding
- **Purpose:** Read field at offset +0x04 (likely m_flags or m_count)

### Phyre_PArray_GetFieldAtOffset28 (0x449830, 16 bytes)
```c
int __thiscall Phyre_PArray_GetFieldAtOffset28(void *this)
{
  return *((_DWORD *)this + 10);
}
```
- **Callers:** Reflection, data binding
- **Purpose:** Read field at offset +0x28 (likely m_capacity or m_itemSize)

### Phyre_PArray_ReturnMinus1 (0x449880, 6 bytes)
```c
int __thiscall Phyre_PArray_ReturnMinus1(int this)
{
  return -1;
}
```
- **Callers:** PArray vtable (error/default entry)
- **Purpose:** Placeholder returns -1 (invalid index / not found)

### Phyre_PArray_ReturnFalse_dup (0x449b30, 6 bytes)
```c
bool __thiscall Phyre_PArray_ReturnFalse_dup(int this)
{
  return 0;
}
```
- **Callers:** PArray vtable (default boolean entry)
- **Purpose:** Default boolean virtual returns false

### Phyre_PArray_PChar_PChar_RegisterClassDescriptor (0x46ab90, ~150 bytes)
- **Callers:** Template instantiation for PArray<PChar, PChar>
- **Purpose:** Template-generated RegisterClassDescriptor for PArray<string, string> — registers the type with the PhyreEngine type system

### Phyre_PArray_bool_PChar_RegisterClassDescriptor (0x46b3d0, ~150 bytes)
- **Callers:** Template instantiation for PArray<bool, PChar>
- **Purpose:** Template-generated RegisterClassDescriptor for PArray<bool, string>

---

## Key Findings

1. **PArray struct layout (reconstructed from accessors):**
   - +0x00: vfptr (4B)
   - +0x04: m_flags or m_count (4B)
   - +0x08: m_itemOffset (4B, stride for element access)
   - +0x0C: serialized data header?
   - +0x10: serialized data?
   - +0x14: m_pData (4B, heap-allocated buffer)
   - +0x28: m_capacity or m_itemSize (4B)

2. **PArray = typed dynamic array** (similar to std::vector but with Phyre reflection):
   - m_pData = heap buffer (freed via operator delete)
   - m_itemOffset = element stride
   - m_count + m_els = registered as serializable properties

3. **Template instantiations:**
   - PArray<PTypedObject> — key-value storage with CopyPairs
   - PArray<PChar, PChar> — string-to-string mapping
   - PArray<bool, PChar> — boolean-to-string mapping
   - Each generates ~150 bytes of RegisterClassDescriptor boilerplate

4. **vtable default entries:**
   - Return0, ReturnMinus1, ReturnFalse_dup — placeholder pattern for unimplemented virtuals
   - Allows safe vtable dispatch without null checks

5. **AllocAndCopy pattern:** allocate new → memmove existing → free old (standard dynamic array growth)

## Next Batches

- Batch 4: Phyre_PArray remaining functions (~1268 more)
- Batch 5: Phyre_PAnimation family (~660)
- Batch 6: Phyre_PInput family (~632)
- Batch 7+: PScript, PType, PGeometry, PPhysics, PSceneNode
