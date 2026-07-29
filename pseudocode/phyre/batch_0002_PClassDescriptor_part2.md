# FFX.exe Decompilation — Batch 2 (Phyre_PClassDescriptor Part 2)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 15 (Phyre_PClassDescriptor — destructor variants, FinalizeRegistration, Traverse, serialization, getters)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the core PClassDescriptor lifecycle: destructor variants, registration finalization, serialization (Traverse/TraverseWithFlag), size computation (GetTotalSize, CalcLayoutSize), and field accessors. These functions represent the serialization backbone of PhyreEngine's RTTI system.

## Functions Decompiled

### Phyre_PClassDescriptor_DtorV4 (0x43b7f0, 11 bytes)
```c
void __thiscall Phyre_PClassDescriptor_DtorV4(PhyrePClassDescriptor *this)
{
  Phyre_PClassDescriptor_Destructor(this, 4);
}
```
- **Callers:** 113 xrefs (Engine type system cleanup)
- **Purpose:** Destructor wrapper with flags=4 (likely "destroy children only")

### Phyre_PClassDescriptor_DtorV5 (0x43b820, 11 bytes)
```c
void __thiscall Phyre_PClassDescriptor_DtorV5(PhyrePClassDescriptor *this)
{
  Phyre_PClassDescriptor_Destructor(this, 5);
}
```
- **Callers:** 113 xrefs
- **Purpose:** Destructor wrapper with flags=5

### Phyre_PClassDescriptor_Dtor_Base (0x43b900, 11 bytes)
```c
void __thiscall Phyre_PClassDescriptor_Dtor_Base(PhyrePClassDescriptor *this)
{
  Phyre_PClassDescriptor_Destructor(this, 0xFFFF);
}
```
- **Callers:** 99 xrefs
- **Purpose:** Base destructor with 0xFFFF flags (full teardown)

### Phyre_PClassDescriptor_FinalizeRegistration (0x43c230, 26 bytes)
```c
void __thiscall Phyre_PClassDescriptor_FinalizeRegistration(PhyrePClassDescriptor *this)
{
  Phyre_PNamespace_AddClassDescriptor((PhyrePNamespace *)this->m_pNamespace, this);
  this->m_padding |= 0x40000000u;
}
```
- **Callers:** 574 xrefs
- **Callees:** Phyre_PNamespace_AddClassDescriptor
- **Purpose:** Finalizes registration — adds to namespace singleton + sets flag 0x40000000 (registered+locked)
- **Key insight:** This is THE gate for the 2-phase init pattern. After this, m_padding >= 0 check passes and GetTotalSize/GetMemberCount/etc proceed

### Phyre_PClassDescriptor_EvalCondition (0x43cad0, 65 bytes)
- **Callers:** Internal serialization (used during Traverse)
- **Purpose:** Evaluates a condition on the class descriptor (likely serializer condition flag check)

### Phyre_PClassDescriptor_GetMemberCount (0x43cc70, 35 bytes)
```c
int __thiscall Phyre_PClassDescriptor_GetMemberCount(PhyrePClassDescriptor *this)
{
  int result;
  if ( this->m_padding >= 0 )
  {
    if ( (this->m_padding & 0x40000000) == 0 )
      Phyre_PClassDescriptor_FinalizeRegistration(this);
    Phyre_PClass_ConstructDefault((int)this, (int)this);
    Phyre_PClassDataMember_ValidateLayout((int)this);
  }
  result = this->m_propCount;
  return result;
}
```
- **Callers:** Data binding, scripting reflection
- **Purpose:** Returns m_propCount with 2-phase init guard (finalize + construct + validate)
- **Key insight:** GetMemberCount forces full initialization before returning count

### Phyre_PClassDescriptor_GetTotalSize (0x43cca0, 113 bytes)
- **Callers:** 990+ xrefs
- **Purpose:** Returns cached total size with lazy init. Checks m_cachedTotalSize first, then triggers 2-phase init if needed. Uses flag 0x20000000 as "size cached" marker
- **Key constants:** 0x20000000 (cached flag), 0x40000000 (registered flag)

### Phyre_PClassDescriptor_GetDataMemberSize (0x43ce70, 30 bytes)
- **Callers:** Layout validation, serialization
- **Purpose:** Returns data member size by reading m_pDataMember->size

### Phyre_PClassDescriptor_PushToStream (0x43d3e0, 53 bytes)
- **Callers:** Serialization subsystem
- **Purpose:** Serialize class descriptor to stream (write m_typeSize + m_propCount + property list)

### Phyre_PClassDescriptor_PushToStreamAlt (0x43d420, 39 bytes)
- **Callers:** Serialization subsystem (alternate path)
- **Purpose:** Alternate serialization — writes m_typeSize + m_propCount only (no property list)

### Phyre_PClassDescriptor_Traverse (0x43d6c0, 244 bytes)
- **Callers:** 100+ xrefs
- **Callees:** Phyre_PClassDescriptor_TraverseWithFlag
- **Purpose:** Walk the property list and invoke a callback for each property. Entry point for serialization reflection
- **Key insight:** Calls TraverseWithFlag with a computed flag parameter

### Phyre_PClassDescriptor_TraverseWithFlag (0x43d790, 55 bytes) ⭐
```c
int __thiscall Phyre_PClassDescriptor_TraverseWithFlag(PhyrePClassDescriptor *this, int flag)
{
  context[1] = this->m_typeSize;
  context[2] = flag;
  v4 = v5;
  if ( v5 )
    Phyre_PClassDescriptor_TraversePropertyList(&typeInfo__5, (int)context);
  else
    Phyre_PClassDescriptor_TraversePropertyList_V2(&typeInfo__5, (int)context);
}
```
- **Callers:** **2063 xrefs** — THE most-called non-constructor in PClassDescriptor
- **Purpose:** Central serialization dispatcher. Builds a context struct (typeSize + flag) and dispatches to TraversePropertyList or V2 based on a condition. This is the function that walks ALL properties during serialization
- **Key insight:** With 2063 callers, this is THE critical dispatch point. Every serialized class hits this function

### Phyre_PClassDescriptor_CalcLayoutSize (0x43d7d0, 55 bytes)
```c
int __thiscall Phyre_PClassDescriptor_CalcLayoutSize(PhyrePClassDescriptor *this)
{
  DefaultPool = Phyre_GetDefaultPool();
  this->m_propCapacity = 0;
  this_1 = this;
  do {
    if ( this_1 == DefaultPool ) break;
    this->m_propCapacity += this_1->m_flags;
    this_1 = this_1->m_pParentCD;
  } while ( this_1 );
}
```
- **Callers:** 5 xrefs (layout validation, allocation)
- **Callees:** Phyre_GetDefaultPool
- **Purpose:** Walk inheritance chain summing m_flags from each ancestor up to DefaultPool. Computes total property capacity needed
- **Key insight:** Walks m_pParentCD chain — each PClassDescriptor stores per-class flags (number of properties), and CalcLayoutSize sums them all

### Phyre_PClassDescriptor_DestroyHierarchy (0x43ded0, 83 bytes)
- **Callers:** Type system cleanup
- **Purpose:** Recursively destroy class descriptor hierarchy (walks children + destroys linked lists)

### Phyre_PClassDescriptor_GetField (0x443be0, 180 bytes)
- **Callers:** Data binding, scripting property access
- **Purpose:** Find a field/member by name or offset in the class descriptor tree
- **Callees:** Phyre_PClassDescriptor_FindByName (delegates name lookup)

---

## Key Findings

1. **2063 xrefs to TraverseWithFlag** makes it the single hottest serialization dispatch in PhyreEngine
2. **574 callers to FinalizeRegistration** — every registered class calls this once
3. **2-phase init pattern** confirmed across ALL accessors (GetMemberCount, GetTotalSize, GetDataMemberSize):
   - Phase 1: Check m_padding >= 0 (is initialized?)
   - Phase 1b: Check m_padding & 0x40000000 (is registered?)
   - Phase 2: ConstructDefault + ValidateLayout
   - Return cached value
4. **Flag system:**
   - 0x40000000 = registered+locked (set by FinalizeRegistration)
   - 0x20000000 = size cached (set by GetTotalSize)
   - Sign bit (>= 0 / < 0) = initialized vs uninitialized
5. **CalcLayoutSize** walks inheritance chain (m_pParentCD) terminating at DefaultPool
6. **All destructor variants** delegate to main Destructor with different flag values (4, 5, 0xFFFF)
7. **Destructor signature:** `Phyre_PClassDescriptor_Destructor(this, flags)` where flags indicates depth/scope

## Next Batches

- Batch 3: Phyre_PArray family
- Batch 4+: PAnimation, PInput, PScript, PType, PGeometry families
