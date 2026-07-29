# FFX.exe Decompilation — Batch 6 (Phyre_PNamespace)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 27 (Phyre_PNamespace family — singleton, registry, lookup, serialization)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the Phyre_PNamespace class — the global namespace registry for PhyreEngine's RTTI/reflection type system. PNamespace is a hierarchical container that maps class names to PClassDescriptor instances, providing both flat (linked-list) and recursive (sub-namespace) lookup.

**Key architectural role:** PNamespace is the bridge between `Phyre_PClassDescriptor` (type system) and client code that needs to find classes by name at runtime — scripting, serialization, dynamic class creation, and debug inspection.

---

## Functions Decompiled

### Getters (4 byte field accessors)

#### Phyre_PNamespace_Field4_getter (0x437480, 4 bytes)
```c
int __thiscall Phyre_PNamespace_Field4_getter(PhyrePNamespace *this)
{
  return this->m_pNamespaceTree;
}
```
- **Purpose:** Returns m_pNamespaceTree (first field, vtable-relative)

#### Phyre_PNamespace_GetThisPlus8 (0x437490, 4 bytes)
```c
int *__thiscall Phyre_PNamespace_GetThisPlus8(PhyrePNamespace *this)
{
  return &this->m_rootNamespace;
}
```
- **Purpose:** Returns pointer to m_rootNamespace (+8 from base)

#### Phyre_PNamespace_Field8_getter (0x4374a0, 4 bytes)
```c
int __thiscall Phyre_PNamespace_Field8_getter(PhyrePNamespace *this)
{
  return this->m_rootNamespace;
}
```
- **Purpose:** Returns m_rootNamespace value (+8)

#### Phyre_PNamespace_Field10_getter (0x4374b0, 4 bytes)
```c
int __thiscall Phyre_PNamespace_Field10_getter(PhyrePNamespace *this)
{
  return this->m_classDescCount;
}
```
- **Purpose:** Returns m_classDescCount (+0x10) — number of registered class descriptors

---

### Singleton System

#### Phyre_PNamespace_InitSingleton (0x43dc50, 145 bytes)
```c
void __thiscall Phyre_PNamespace_InitSingleton(PhyrePNamespace *this)
{
  PhyrePNamespace *Singleton;
  PhyrePClassDescriptor *DefaultPool;

  DefaultPool = Phyre_GetDefaultPool();
  Singleton = Phyre_PNamespace_GetSingleton();
  Phyre_PClassDescriptor_ctor(
    (PhyrePClassDescriptor *)this,
    (int)Singleton,
    (int)(&vtable_PClassDescriptorAbstract_PNamespace + 16),
    28, 16,         // typeSize=28, align=16
    (int)DefaultPool, 8);
  *((_DWORD *)this + 36) |= 2u;
  this->vfptr = (int *)&vtable_PClassDescriptorAbstract_PNamespace;
  Phyre_PClassDescriptor_SetField64(this, (int)&val__20);
  Phyre_PClassDescriptor_SetField68(this, (int)&val__21);
  Phyre_PClassDescriptor_SetField6C(this, (int)&val__22);
}
```
- **Callers:** 0 (called indirectly during engine boot)
- **Callees:** Phyre_GetDefaultPool, Phyre_PNamespace_GetSingleton, Phyre_PClassDescriptor_ctor, SetField64/68/6C
- **Purpose:** Initializes PNamespace as a class descriptor singleton (typeSize=28, pool=default)
- **Key constants:** vtable at 0xB0EEAC, typeSize=28, align=16

#### Phyre_PNamespace_GetSingleton (0x43e3e0, 106 bytes)
```c
PhyrePNamespace *__stdcall Phyre_PNamespace_GetSingleton()
{
  if ( (MEMORY[0xC90B1C] & 1) == 0 )
  {
    MEMORY[0xC90B1C] |= 1u;
    MEMORY[0xC90B00][0] = (int)MEMORY[0xC90B00];        // sentinel self-ptr
    unk_C90B04 = MEMORY[0xC90B00];                       // prev = self
    MEMORY[0xC90B08] = (PhyrePNamespace *)&MEMORY[0xC90B08];
    MEMORY[0xC90B0C] = &MEMORY[0xC90B08];
    unk_C90B10 = 0;
    unk_C90B14 = &unk_C90B14;
    unk_C90B18 = &unk_C90B14;
    atexit(Phyre_PClassDescriptor_DestroyHierarchy_C90B00);
  }
  return (PhyrePNamespace *)&MEMORY[0xC90B00];
}
```
- **Callers:** 100+ (1194 total xrefs — most-called singleton in the type system)
- **Callees:** atexit
- **Purpose:** Lazy singleton at global 0xC90B00 (28 bytes). Guard bit at +0x1C. Initializes 3 sentinel pairs + atexit cleanup.
- **Global layout at 0xC90B00:**
  - +0x00: m_pNamespaceTree (sentinel self-ptr)
  - +0x04: m_rootNamespace (sentinel self-ptr)
  - +0x08: m_namespaceFlags/m_propertyCount (sentinel self-ptr)
  - +0x0C: property tail (sentinel self-ptr)
  - +0x10: some field = 0
  - +0x14: another sentinel self-ptr
  - +0x18: another sentinel tail
  - +0x1C: guard byte (bit 0)

---

### Destructors

#### Phyre_PNamespace_DtorV1 (0x43e000, 39 bytes)
```c
PhyrePClassDescriptor *__thiscall Phyre_PNamespace_DtorV1(PhyrePClassDescriptor *this, char a2)
{
  this->vfptr = (int *)&vtable_PClassDescriptorForType_PNamespace;
  Phyre_PClassDescriptor_Destructor(this, flags);
  if ( (a2 & 1) != 0 )
    Engine_AlignedFree(this);
  return this;
}
```
- **Callees:** Engine_AlignedFree, Phyre_PClassDescriptor_Destructor

#### Phyre_PNamespace_DtorV2 (0x43e030, 39 bytes)
- **Purpose:** Same pattern as DtorV1 — resets vfptr, delegates to PClassDescriptor_Destructor, aligned free

#### Phyre_PNamespace_DtorV3 (0x43e060, 34 bytes)
```c
Vtable_PCaller_Phyre **__thiscall Phyre_PNamespace_DtorV3(Vtable_PCaller_Phyre **this, char a2)
{
  *this = &g_vtable_PCaller_Phyre;
  if ( (a2 & 1) != 0 )
    FFX_Heap_Free(this);
  return this;
}
```
- **Note:** Uses **FFX_Heap_Free** (not Engine_AlignedFree) — different allocator for PCaller vtables

#### Phyre_PNamespace_DtorV4 (0x43e090, 34 bytes)
- **Purpose:** Same as DtorV3 — resets to PCaller vtable, FFX_Heap_Free

#### Phyre_PNamespace_DestroyWrapper (0x43e970, 37 bytes)
```c
void __thiscall Phyre_PNamespace_DestroyWrapper(PhyrePNamespace *this)
{
  int v1; // [esp+8h] [ebp+8h]
  if ( v1 )
    Phyre_PClassDescriptor_DestroyHierarchy(v1 - 8);
  else
    Phyre_PClassDescriptor_DestroyHierarchy(0);
}
```
- **Callees:** Phyre_PClassDescriptor_DestroyHierarchy
- **Purpose:** Vtable wrapper — adjusts this-8 before delegating

---

### Registry Operations

#### Phyre_PNamespace_RecalcLayoutSizes (0x43e530, 116 bytes)
```c
void __thiscall Phyre_PNamespace_RecalcLayoutSizes(PhyrePNamespace *this)
{
  // Walks m_rootNamespace linked list
  // For each PClassDescriptor: GetMemberCount + CalcLayoutSize + TraverseWithFlag
  // Skips descriptors where field84 < 2
  Singleton->m_classDescCount = 1;
  // ... walks all descriptors in the linked list
}
```
- **Callers:** Phyre_Engine_Init (only 1 caller, during boot)
- **Callees:** GetSingleton, GetMemberCount, CalcLayoutSize, TraverseWithFlag
- **Purpose:** Recalculates layout sizes for ALL registered class descriptors. Called once at engine init.

#### Phyre_PNamespace_DestroyClassDescriptors (0x43e700, 70 bytes)
```c
void __thiscall Phyre_PNamespace_DestroyClassDescriptors(PhyrePNamespace *this)
{
  Singleton = Phyre_PNamespace_GetSingleton();
  p_m_rootNamespace = &Singleton->m_rootNamespace;
  while ( 1 )
  {
    m_rootNamespace = (int *)*p_m_rootNamespace;
    if ( m_rootNamespace == p_m_rootNamespace || !m_rootNamespace || m_rootNamespace == (int *)44 )
      break;
    if ( m_rootNamespace == p_m_rootNamespace )
      Phyre_PClassDescriptor_Unregister(0);
    else
      Phyre_PClassDescriptor_Unregister(m_rootNamespace - 11);
  }
  Singleton->m_classDescCount = 0;
}
```
- **Callers:** Phyre_Engine_GetVersion (1 caller — called during engine shutdown)
- **Callees:** GetSingleton, Unregister
- **Purpose:** Destroys all class descriptors in the namespace. Walks linked list calling Unregister on each.

#### Phyre_PNamespace_AddClassDescriptor (0x43e750, 224 bytes)
```c
int __thiscall Phyre_PNamespace_AddClassDescriptor(PhyrePNamespace *this, PhyrePClassDescriptor *cd)
{
  ArgList = cd->m_pClassName;
  cd_1 = Phyre_PNamespace_FindClassDescriptor(this, ArgList);
  if ( cd_1 )
  {
    if ( cd_1 != cd )
      return Phyre_Stream_Printf(2, "A class descriptor with the name \"%s\" already exists\n", ...);
  }
  // Otherwise: insert into namespace linked list
  // ...
}
```
- **Callers:** 2 callers: Phyre_Scripting_RegisterIsTypeOf, Phyre_PClassDescriptor_FinalizeRegistration
- **Callees:** FindClassDescriptor, Stream_Printf, GetSingleton, CalcLayoutSize
- **Strings:** "A class descriptor with the name \"%s\" already exists in this namespace\n", "Adding class '%s' to namespace after initialization\n"
- **Purpose:** Registers a class descriptor. Checks for duplicate names, warns on post-init registration.

---

### Lookup Operations

#### Phyre_PNamespace_FindClassDescriptor (0x43ea40, 196 bytes)
```c
PhyrePClassDescriptor *__thiscall Phyre_PNamespace_FindClassDescriptor(PhyrePNamespace *this, const char *name)
{
  // if (!name) return 0
  // Walk m_rootNamespace linked list
  // For each: compare m_pClassName via strcmp
  // If not found in root list, walk property list chain
  // Recursive into sub-namespaces
}
```
- **Callers:** 10 callers (Scripting_InitIndexHandler, AddClassDescriptor, StringLiteral_Parse, Memory_Free, PClassDescriptorDynamic_CreateFromName, PComponent_FindAndPushInstances, Type_CreateDynamicClass, Type_ResolveOnLoad, Object_DebugPrintFields)
- **Purpose:** Primary name→class descriptor lookup. Walks linked list comparing class names.

#### Phyre_PNamespace_FindByName (0x43eb20, 196 bytes)
```c
PhyrePNamespace *__thiscall Phyre_PNamespace_FindByName(PhyrePNamespace *this, const char *name)
{
  // Similar to FindClassDescriptor but returns sub-namespace by name
  // Walks root namespace list, then property list chain
  // Recursive into child namespaces
}
```
- **Callers:** 3 callers (itself recursive, PClassDescriptorDynamic_InitElementArray, FFX_Phyre_ClusterInstantiateDriver)
- **Purpose:** Recursive namespace lookup by name string.

---

### Name List Singleton

#### Phyre_PNamespace_GetNameListSingleton (0x43e9c0, 114 bytes)
```c
_DWORD *Phyre_PNamespace_GetNameListSingleton()
{
  if ( (unk_C90B8C & 1) == 0 )
  {
    unk_C90B8C |= 1u;
    unk_C90B80 = &unk_C90A19;                              // pointer to namespace area
    unk_C90B84 = (unsigned int)Phyre_PTypeDefault_PChar_SingletonInit() | 1;
    unk_C90B88 = 0;
  }
  return &unk_C90B80;
}
```
- **Callees:** Phyre_PTypeDefault_PChar_SingletonInit
- **Purpose:** Lazy singleton for name list (global at 0xC90B80). Links to PChar type system.

---

### Lua Scripting Bridge

#### Phyre_PNamespace_Accessor_Get (0x43e880, 45 bytes)
```c
int __thiscall Phyre_PNamespace_Accessor_Get(PhyrePNamespace *this)
{
  v1 = this->m_pNamespaceTree();
  obj = v1 ? v1 + 8 : 0;
  Phyre_Scripting_PushObjectToStream(stream, obj, &typeInfo__9);
  return 1;
}
```
- **Callees:** Phyre_Scripting_PushObjectToStream
- **Purpose:** Lua __index metamethod — pushes namespace object to Lua stack

#### Phyre_PNamespace_PropertyAccessor_Get (0x43e8b0, 127 bytes)
```c
int __thiscall Phyre_PNamespace_PropertyAccessor_Get(PhyrePNamespace *this, int L)
{
  v3 = PhyreBuffer_ReadToStringPtr(L, -1, 0);
  PhyreStream_Reserve(L, -2);
  v4 = Phyre_Scripting_PNamespaceAccessor_Get(L);
  if ( !v4 ) return 0;
  v5 = ((int (__thiscall *)(int, int))this->m_rootNamespace)(v4 + this->m_namespaceFlags, v3);
  if ( v5 )
    Phyre_Scripting_PushObjectToStream(L, v5 + 24, &typeInfo__5);
  else {
    PhyreStream_ReserveGrow(L, 1);
    PhyreStream_PushNil(L);
  }
  return 1;
}
```
- **Callees:** ReadToStringPtr, Reserve, PNamespaceAccessor_Get, PushObjectToStream, ReserveGrow, PushNil
- **Purpose:** Lua property accessor — reads a string key, looks up in namespace, pushes value or nil

#### Phyre_PNamespace_Accessor_Get_V2 (0x43ee40, 54 bytes)
- **Purpose:** Variant of Accessor_Get with different offset calculation

#### Phyre_PNamespace_PropertyAccessor_Get_V2 (0x43ee80, 85 bytes)
- **Purpose:** Variant of PropertyAccessor_Get with different type info

---

### Serialization

#### Phyre_PNamespace_PushToStream (0x43ecc0, 61 bytes)
```c
void __thiscall Phyre_PNamespace_PushToStream(PhyrePNamespace *this)
{
  // Serialize namespace to stream
  // Push 2 elements (namespace count + ?)
}
```
- **Purpose:** Serialize namespace to output stream

#### Phyre_PNamespace_PushPtrToStream (0x43ed00, 38 bytes)
```c
void __thiscall Phyre_PNamespace_PushPtrToStream(PhyrePNamespace *this)
{
  // Serialize namespace pointer to stream
}
```
- **Purpose:** Serialize namespace pointer to output stream

---

### Maintenance

#### Phyre_PNamespace_DetachFromList (0x43ed30, 83 bytes)
```c
void __thiscall Phyre_PNamespace_DetachFromList(PhyrePNamespace *this)
{
  // Remove this namespace from the intrusive linked list
  // this->prev->next = this->next
  // this->next->prev = this->prev
  // this->prev = this->next = this (sentinel reset)
}
```
- **Purpose:** Intrusive linked list detachment. Resets to self-pointing sentinel state.

#### Phyre_PNamespace_TraverseWithFlag (0x43edd0, 105 bytes)
- **Purpose:** Traverse namespace tree with conditional flag check

#### Phyre_PNamespace_SingletonOrFlag (0x43ec80, 9 bytes)
```c
int __thiscall Phyre_PNamespace_SingletonOrFlag(PhyrePNamespace *this)
{
  return (int)&unk_C90A19;
}
```
- **Purpose:** Returns hardcoded address 0xC90A19 (inside singleton region). Vtable entry.

#### Phyre_PNamespace_SingletonOrFlag_0 (0x43ec90, 9 bytes)
- **Purpose:** Same as SingletonOrFlag

---

## PNamespace Struct Layout (reconstructed)

```
PhyrePNamespace (28 bytes + vfptr):
  +0x00: m_pNamespaceTree    (4B, int*)     — first field, vtable dispatch target
  +0x04: m_rootNamespace     (4B, int*)     — linked list head for class descriptors
  +0x08: m_propertyCount     (4B, int*)     — also = m_namespaceFlags
  +0x0C: (property tail)     (4B, int*)     — sentinel pair tail
  +0x10: m_classDescCount    (4B, int)      — number of registered class descriptors
  +0x14: (sentinel)          (4B, int*)     — self-pointing sentinel
  +0x18: (sentinel tail)     (4B, int*)     — sentinel pair tail
```

Global singleton at **0xC90B00** (28 bytes). Guard bit at **0xC90B1C**.

---

## Key Findings

1. **PNamespace is a hierarchical class descriptor registry** — maps class names to PClassDescriptor instances. Used by scripting, serialization, and factory/reflection systems.

2. **Lazy singleton at 0xC90B00** — 1194 xrefs (highest of any namespace function). Guard bit at +0x1C. Three sentinel pair initialization + atexit cleanup.

3. **Two linked list walk patterns:**
   - **FindClassDescriptor:** Walks m_rootNamespace linked list then property list chain
   - **FindByName:** Recursive — walks root list, then recurses into sub-namespaces

4. **Duplicate name protection** — AddClassDescriptor warns if name already registered

5. **Two allocator paths in destructors:**
   - DtorV1/V2: `Engine_AlignedFree` (standard engine heap)
   - DtorV3/V4: `FFX_Heap_Free` (different allocator for PCaller vtables)

6. **Lua bridge** — Accessor_Get and PropertyAccessor_Get provide __index/__newindex for scripting namespace access

7. **DestroyClassDescriptors** — engine shutdown path, walks and unregisters every descriptor

---

## Next Batches

- Batch 7: Phyre_PAnimation family (~827 functions — largest family, needs prioritization)
- Batch 8: Phyre_PInput family (~632 functions)
- Batch 9: Phyre_PPhysics family (~222 functions)
- Batch 10: Phyre_PGeometry family (~125 functions)
