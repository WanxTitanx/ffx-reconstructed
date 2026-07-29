# FFX.exe Decompilation — Batch 5 (Phyre_PType Part 1)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 20 (Phyre_PType core system — singletons, BST lookup, serialization)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the Phyre_PType type system core — PhyreEngine's equivalent of `std::type_info` but with serialization support. Each primitive C++ type (int, float, bool, unsigned char, etc.) has a singleton PType descriptor with virtual Read/Write/Get methods. String types (PChar) use a Binary Search Tree (BST) for O(log n) name lookup.

## Functions Decompiled

### Phyre_PType_GetSingleton (0x4375d0, 150 bytes)
```c
// Phyre PType: Get singleton
_DWORD *Phyre_PType_GetSingleton()
{
  if ( (dword_C903AC & 1) == 0 )
  {
    dword_C903AC |= 1u;
    dword_C90384 = &dword_C90384;
    unk_C90388 = &dword_C90384;
    unk_C9038C = &dword_C90384;
    unk_C90390 = 0;
    unk_C90394 = 0;
    unk_C90380[0] = &g_vtable_PType_Phyre;
    PType = "PType";
    n44_0 = 44;
    n4_3 = 4;
    Phyre_PType_SerializeNameString_0 = Phyre_PType_SerializeNameString;
    Phyre_PTypeDefault_PChar_TryCreate_0 = Phyre_PTypeDefault_PChar_TryCreate;
    atexit(PhyrePTypeInit_dwordC901A8_1D8);
  }
  return unk_C90380;
}
```
- **Callers:** Phyre_TypeSystem_RegisterAllTypes, Phyre_Math_Vec4Transform, FFX_Phyre_ResolvePointerFixups_ImportVsLocalSplit
- **Callees:** _atexit
- **Strings:** "PType"
- **Purpose:** Root PType singleton — base type descriptor for all Phyre types
- **Flags guard:** `dword_C903AC & 1` — one-time init
- **Struct layout inferred:** vfptr(+0), 3 sentinel ptrs(+4,+8,+0C), field0(+0x10), field1(+0x14), slot8(+0x18)=vtable+8, m_size(+0x1C)=44, m_align(+0x20)=4, SerializeNameString ptr(+0x24), TryCreate ptr(+0x28)
- **Size constant:** 44 bytes for PType itself

### Phyre_PTypeDefault_PChar_SingletonInit (0x437d90, 150 bytes)
```c
// Phyre PTypeDefault PChar: Singleton init
_DWORD *Phyre_PTypeDefault_PChar_SingletonInit()
{
  if ( (dword_C9040C & 1) == 0 )
  {
    dword_C9040C |= 1u;
    dword_C903E4 = &dword_C903E4;
    unk_C903E8 = &dword_C903E4;
    unk_C903EC = &dword_C903E4;
    unk_C903F0 = 0;
    unk_C903F4 = 0;
    p_slot8 = &g_vtable_PTypeDefault_char_Phyre.slot8;
    unk_C903FC = 1;
    unk_C90400 = 1;
    unk_C90404 = 0;
    unk_C90408 = 0;
    p_g_vtable_PTypeDefault_char_Phyre = &g_vtable_PTypeDefault_char_Phyre;
    atexit(PhyrePTypeInit_dwordC901A8_238);
  }
  return &p_g_vtable_PTypeDefault_char_Phyre;
}
```
- **Callers:** 64 callers (Phyre_TypeSystem_RegisterAllTypes, Phyre_PNamespace_GetNameListSingleton, 60+ RegisterClassDescriptor functions)
- **Callees:** _atexit
- **Purpose:** PChar (string) type singleton — the most-used type descriptor after float
- **Flags guard:** `dword_C9040C & 1`
- **Key detail:** `m_isString=1` at +0x1C and +0x20 — distinguishes PChar from numeric types

### Phyre_PTypeDefault_PChar_Find (0x438720, 76 bytes)
```c
// Phyre PTypeDefault PChar: Find
_DWORD *__thiscall Phyre_PTypeDefault_PChar_Find(_DWORD *this, char *a2)
{
  char *v2; // edx
  int n1973; // esi
  char v4; // al
  _DWORD v6[2]; // [esp+8h] [ebp-8h] BYREF

  v2 = a2;
  v6[1] = a2;
  n1973 = 1973;
  if ( a2 )
  {
    v4 = *a2;
    if ( *a2 )
    {
      do
      {
        ++v2;
        n1973 = (v4 & 0x1F) + 33 * n1973;
        v4 = *v2;
      }
      while ( *v2 );
    }
  }
  v6[0] = n1973;
  return Phyre_PTypeDefault_PChar_BST_Search(this, v6);
}
```
- **Callers:** Phyre_PTypeDefault_PChar_RegisterName
- **Callees:** Phyre_PTypeDefault_PChar_BST_Search
- **Purpose:** Hash a name string and search the BST for an existing entry
- **Hash function:** seed=1973, `n = (char & 0x1F) + 33 * n` — Bernstein djb2 variant

### Phyre_PTypeDefault_PChar_BST_Search (0x438770, 167 bytes)
```c
// Phyre PTypeDefault PChar: BST search
_DWORD *__thiscall Phyre_PTypeDefault_PChar_BST_Search(_DWORD *this, _DWORD *a2)
{
  // Walks BST comparing hash values, uses strcmp for tiebreaker
  // Node layout: [parent_ptr, left_child, right_child, hash, name_ptr]
  // Returns NULL if name not found
}
```
- **Callers:** Phyre_PTypeDefault_PChar_Find
- **Purpose:** BST search by hash + strcmp tiebreaker
- **Node structure:** offset -4 from node ptr accesses hash(0), name_ptr(+4)
- **29 basic blocks** — full BST traversal with left/right branching

### Phyre_PTypeDefault_PChar_BST_Insert (0x438870, 251 bytes)
```c
// Phyre PTypeDefault PChar: BST insert
int __thiscall Phyre_PTypeDefault_PChar_BST_Insert(_DWORD *this, int a2)
{
  // Standard BST insertion with self-balancing
  // Updates parent/child pointers, recalculates balance factors
}
```
- **Callers:** Phyre_PTypeDefault_PChar_RegisterName
- **Purpose:** Insert name into BST with balance factor (+0x0C) tracking
- **Balance factor:** `*(_DWORD *)(a2 + 12) += 1 - (*(_BYTE *)(a2 + 12) & 1)` — odd/even balance heuristic

### Phyre_PTypeDefault_PChar_HashName (0x43bf20, 60 bytes)
```c
int __cdecl Phyre_PTypeDefault_PChar_HashName(int *a1, char *a2)
{
  int v3; // eax

  if ( a2 )
  {
    Phyre_PTypeDefault_PUInt64_SingletonInit();
    v3 = Phyre_NameMap_Hash(a2);
    *a1 = v3;
    return v3 != 0 ? 0 : 19;
  }
  else
  {
    *a1 = 0;
    return 19;
  }
}
```
- **Callees:** Phyre_NameMap_Hash, Phyre_PTypeDefault_PUInt64_SingletonInit
- **Purpose:** Hash a C string name into a uint64 via Phyre_NameMap_Hash
- **Returns:** 0 on success, 19 (E_FAIL) on null name or zero hash

### Phyre_PTypeDefault_PChar_RegisterName (0x4396a0, 140 bytes)
```c
// Phyre PTypeDefault PChar: Register name
char __cdecl Phyre_PTypeDefault_PChar_RegisterName(_DWORD *a1)
{
  char *v2; // edi
  char v4; // cl
  char *v5; // ebx
  int i; // edx
  _DWORD *v7; // [esp+10h] [ebp+8h]

  v2 = (char *)a1[6];
  if ( !v2 )
    return 0;
  v7 = Phyre_PTypeDefault_PUInt64_SingletonInit();
  if ( Phyre_PTypeDefault_PChar_Find(v7, v2) )
    return 0;
  v4 = *v2;
  v5 = v2;
  for ( i = 1973; *v5; v4 = *v5 )
  {
    ++v5;
    i = (v4 & 0x1F) + 33 * i;
  }
  a1[5] = v2;
  a1[4] = i;
  if ( Phyre_PTypeDefault_PChar_BST_Insert(v7, (int)a1) )
    return 0;
  Phyre_Tree_RemoveNode_COMDAT(v7, (int)(a1 + 1));
  return 1;
}
```
- **Callers:** 637 callers (Phyre_Engine_Init, RegisterName_wrapper, Rendering_RegisterGeometryClassDescriptors, Rendering_RegisterShaderAndTextureClassDescriptors, RegisterAnimationDescriptorSuite, etc.)
- **Callees:** Phyre_PTypeDefault_PUInt64_SingletonInit, Phyre_PTypeDefault_PChar_Find, Phyre_PTypeDefault_PChar_BST_Insert, Phyre_Tree_RemoveNode_COMDAT
- **Purpose:** Register a name in the global PChar BST — skip if duplicate, remove old node on BST insert failure
- **Key insight:** 637 callers = every class descriptor registration in the engine calls this

### Phyre_PTypeDefault_PChar_TryCreate (0x437930, 60 bytes)
```c
// Phyre PTypeDefault PChar: Try create
int __cdecl Phyre_PTypeDefault_PChar_TryCreate(int *a1, char *a2)
{
  int v3; // eax

  if ( a2 )
  {
    Phyre_PTypeDefault_PUInt64_SingletonInit();
    v3 = Phyre_NameMap_Hash(a2);
    *a1 = v3;
    return v3 != 0 ? 0 : 19;
  }
  else
  {
    *a1 = 0;
    return 19;
  }
}
```
- **Callees:** Phyre_NameMap_Hash, Phyre_PTypeDefault_PUInt64_SingletonInit
- **Purpose:** Create a named entry — identical logic to HashName
- **Note:** Used as TryCreate function pointer in PType vtable

### Phyre_PType_Dtor (0x437810, 34 bytes)
```c
// Phyre PType: Dtor
Vtable_PType_Phyre **__thiscall Phyre_PType_Dtor(Vtable_PType_Phyre **this, char a2)
{
  *this = &g_vtable_PType_Phyre;
  if ( (a2 & 1) != 0 )
    Engine_AlignedFree(this);
  return this;
}
```
- **Callees:** Engine_AlignedFree
- **Purpose:** PType destructor — reset vtable and optionally free memory (AlignedFree pattern with bit 0 check)
- **Standard pattern:** All 11 Dtor variants (DtorV1-V10, Dtor_Deleting) follow identical logic

### Phyre_PType_SerializeNameString (0x437840, 75 bytes)
```c
// Phyre PType: Serialize name string
int __cdecl Phyre_PType_SerializeNameString(_DWORD *a1, const char **a2, _DWORD *a3)
{
  int v3; // eax
  const char *v5; // edx

  v3 = (*(int (__thiscall **)(_DWORD *))(*a1 + 4))(a1);
  if ( v3 && (*(_BYTE *)(v3 + 144) & 1) != 0 )
    return 18;
  v5 = (const char *)a1[6];
  *a3 = strlen(v5) + 1;
  *a2 = v5;
  return 0;
}
```
- **Purpose:** Serialize PType name string — returns pointer+size via out params
- **Error 18:** Returned if type has flag at +144 bit 0 ("don't serialize")
- **Callback:** Calls vtable slot 4 (GetClassDescriptor) to check serialization flag

### Phyre_PType_GetFloat (0x438150, 150 bytes)
```c
// Phyre PType: Get float
_DWORD *Phyre_PType_GetFloat()
{
  if ( (dword_C9058C & 1) == 0 )
  {
    dword_C9058C |= 1u;
    dword_C90564 = &dword_C90564;
    unk_C90568 = &dword_C90564;
    unk_C9056C = &dword_C90564;
    unk_C90570 = 0;
    unk_C90574 = 0;
    p_slot8_1 = &g_vtable_PTypeDefault_float_Phyre.slot8;
    n4_4 = 4;
    n4_5 = 4;
    unk_C90584 = 0;
    unk_C90588 = 0;
    p_g_vtable_PTypeDefault_float_Phyre = &g_vtable_PTypeDefault_float_Phyre;
    atexit(PhyrePTypeInit_dwordC901A8_3B8);
  }
  return &p_g_vtable_PTypeDefault_float_Phyre;
}
```
- **Callers:** **241 xrefs** — the most-called singleton in the entire type system
- **Size/align:** 4 bytes (float), m_isString=0
- **Purpose:** Float type singleton — hottest type in PhyreEngine

### Phyre_PType_GetBool (0x438480, 150 bytes)
```c
// Phyre PType: Get bool
_DWORD *Phyre_PType_GetBool()
{
  // Same singleton pattern: flag guard + sentinel + vtable + atexit
  // m_size=1, m_isString=1 (stored as 1-byte numeric)
}
```
- **Callers:** 81 xrefs
- **Size/align:** 1 byte, m_isString=1
- **Purpose:** Bool type singleton

### Phyre_PType_GetPUInt8 (0x437e30, 150 bytes)
```c
// Phyre PType: Get PUInt8
_DWORD *Phyre_PType_GetPUInt8()
{
  // Same singleton pattern: flag guard at dword_C9043C
  // m_size=1, m_isString=1
}
```
- **Callers:** 148 xrefs
- **Purpose:** Unsigned byte type singleton

### Phyre_PType_GetPInt32 (0x438010, 150 bytes)
```c
// Phyre PType: Get PInt32
_DWORD *Phyre_PType_GetPInt32()
{
  // Same singleton pattern: flag guard at dword_C904CC
  // m_size=4, m_isString=0
}
```
- **Callers:** 114 xrefs
- **Purpose:** Signed 32-bit integer type singleton

### Phyre_PTypeDefault_PUInt64_SingletonInit (0x439130, 96 bytes)
```c
// Phyre PTypeDefault PUInt64: Singleton init
_DWORD *Phyre_PTypeDefault_PUInt64_SingletonInit()
{
  if ( (dword_C90608[0] & 1) == 0 )
  {
    dword_C90608[0] |= 1u;
    dword_C905F0 = &dword_C905F0;
    unk_C905F4 = &dword_C905F0;
    unk_C905F8 = &dword_C905F0;
    unk_C90604 = &dword_C905F0;
    unk_C90600 = &dword_C905F0;
    unk_C905FC = &dword_C905F0;
    atexit(PhyreCDDtorWrapper_TreeRemove);
  }
  return &dword_C905F0;
}
```
- **Callers:** Phyre_PTypeDefault_PChar_TryCreate, Phyre_PTypeDefault_PChar_RegisterName, Phyre_PTypeDefault_PChar_HashName, Phyre_Type_ResolveOnLoad
- **Purpose:** PUInt64 singleton — used as the BST root for all PChar name registrations
- **Different layout:** 6 sentinel self-pointers (vs 3 for other types) — because this IS the BST root node
- **Note:** Does NOT set size/align/isString — this is a container/root, not a data type

### Phyre_PTypeDefault_UInt32_GetSingleton (0x43f180, 150 bytes)
```c
_DWORD *Phyre_PTypeDefault_UInt32_GetSingleton()
{
  if ( (dword_C90C50 & 1) == 0 )
  {
    dword_C90C50 |= 1u;
    dword_C90C28 = &dword_C90C28;
    unk_C90C2C = &dword_C90C28;
    unk_C90C30 = &dword_C90C28;
    unk_C90C34 = 0;
    unk_C90C38 = 0;
    Phyre::PResult = "Phyre::PResult";
    n4_6 = 4;
    n4_8 = 4;
    unk_C90C48 = 0;
    unk_C90C4C = 0;
    p_g_vtable_PTypeDefault_unsigned_int = &g_vtable_PTypeDefault_unsigned_int;
    atexit(Phyre_PType_vftable_init_C90C24);
  }
  return &p_g_vtable_PTypeDefault_unsigned_int;
}
```
- **Callers:** 72 xrefs
- **Strings:** "Phyre::PResult"
- **Purpose:** Unsigned int type singleton — specifically maps to `Phyre::PResult` (a typedef)
- **Name:** `Phyre::PResult` — the string name of this type for serialization

### Phyre_PType_ReadFloat (0x439880, 46 bytes)
```c
// Phyre PType: Read float
float *__stdcall Phyre_PType_ReadFloat(_DWORD *a1, float *a2)
{
  float Float; // [esp+0h] [ebp-4h]

  Float = PhyreBuffer_ReadFloat(a1, -1, 0);
  PhyreStream_Reserve((int)a1, -2);
  *a2 = Float;
  return a2;
}
```
- **Callees:** PhyreBuffer_ReadFloat, PhyreStream_Reserve
- **Purpose:** Read a float from a stream/buffer deserialization

### Phyre_PType_WriteFloat (0x439b20, 39 bytes)
```c
// Phyre PType: Write float
_DWORD *__stdcall Phyre_PType_WriteFloat(_DWORD *a1, float *a2)
{
  PhyreStream_ReserveGrow(a1, 1);
  return PhyreStream_PushFloat((int)a1, COERCE_INT(*a2));
}
```
- **Callees:** PhyreStream_ReserveGrow, PhyreStream_PushFloat
- **Purpose:** Write a float to a stream for serialization

### Phyre_PType_ReadUInt32 (0x439850, 41 bytes)
```c
// Phyre PType: Read uint32
int __stdcall Phyre_PType_ReadUInt32(_DWORD *a1, int *a2)
{
  int NumAsInt; // edi
  int result; // eax

  NumAsInt = PhyreBuffer_ReadNumAsInt(a1, -1, 0);
  result = PhyreStream_Reserve((int)a1, -2);
  *a2 = NumAsInt;
  return result;
}
```
- **Callees:** PhyreBuffer_ReadNumAsInt, PhyreStream_Reserve
- **Purpose:** Read a uint32 from a stream

### Phyre_PType_WriteUInt32 (0x439af0, 33 bytes)
```c
// Phyre PType: Write uint32
int __stdcall Phyre_PType_WriteUInt32(_DWORD *a1, int *a2)
{
  PhyreStream_ReserveGrow(a1, 1);
  return PhyreStream_PushIntAsFloat((int)a1, *a2);
}
```
- **Callees:** PhyreStream_ReserveGrow, PhyreStream_PushIntAsFloat
- **Purpose:** Write a uint32 to a stream

---

## Key Findings

### Global Singleton Registry (all singletons use same pattern)

| Singleton | Address | Guard Flag | Xrefs | Size | Name String |
|-----------|---------|-----------|-------|------|-------------|
| PType (base) | 0x4375d0 | dword_C903AC & 1 | 10+ | 44 | "PType" |
| PChar | 0x437d90 | dword_C9040C & 1 | 64 | 1 (string) | (internal) |
| Float | 0x438150 | dword_C9058C & 1 | **241** | 4 | (heap) |
| Bool | 0x438480 | dword_C903DC & 1 | 81 | 1 | (heap) |
| PUInt8 | 0x437e30 | dword_C9043C & 1 | 148 | 1 | (heap) |
| PInt32 | 0x438010 | dword_C904CC & 1 | 114 | 4 | (heap) |
| UInt32 (PResult) | 0x43f180 | dword_C90C50 & 1 | 72 | 4 | "Phyre::PResult" |

### PType Struct Layout (reconstructed, 44 bytes)
```
+0x00: vfptr (4B)
+0x04: m_listSentinel (4B, self-ptr)
+0x08: m_listNext (4B, self-ptr)
+0x0C: m_listPrev (4B, self-ptr)
+0x10: field_0 (4B, 0)
+0x14: field_1 (4B, 0)
+0x18: vtable+8 ptr (4B, slot8 in vtable)
+0x1C: m_size (4B, sizeof the type)
+0x20: m_alignment (4B, alignof)
+0x24: pSerializeNameString (4B)
+0x28: pTryCreate (4B)
```

### PChar BST Architecture
1. **Global root:** `Phyre_PTypeDefault_PUInt64_SingletonInit()` returns BST root at `dword_C905F0`
2. **Hash function:** seed=1973, `n = (char & 0x1F) + 33 * n` (Bernstein djb2 variant)
3. **Search:** Compare hash → strcmp tiebreaker → left/right walk
4. **Node layout:** [parent, left, right, hash, name_ptr] — 20 bytes per node
5. **Balance:** Simple odd/even balance factor at node+0x0C
6. **637 callers** to RegisterName = every class descriptor in the engine

### PType Read/Write Layer
- All Read functions: Read from `PhyreBuffer_*`, then `PhyreStream_Reserve` with -2
- All Write functions: `PhyreStream_ReserveGrow` with 1, then `PhyreStream_Push*`
- All follow `__stdcall` convention with `(buffer, out_value_ptr)` signature
- Float Read/Write are the hottest serialization path (241 xrefs to GetFloat)

### Singleton Pattern (identical for all ~20 types)
```pseudo
if (guard_flag & 1 == 0):
    guard_flag |= 1
    init 3 sentinel self-pointers
    zero field_0, field_1
    set vtable+8 ptr, size, alignment
    set isString flag if applicable
    set vfptr
    atexit(cleanup_func)
return &singleton
```

## Next Batches
- Batch 5 Part 2: Remaining PType functions (GetPUInt16, GetPInt16, GetPUInt32, GetPUInt64, GetPInt64, GetDouble, GetPUInt128, Read/Write Int8/16/32/64/Bool/Double, ReadBoolEx, CompareReturnTrue variants, ctor variants, vftable_init functions)
- Batch 6: Phyre_PAnimation family (~660 functions)
- Batch 7: Phyre_PInput family (~632 functions)
