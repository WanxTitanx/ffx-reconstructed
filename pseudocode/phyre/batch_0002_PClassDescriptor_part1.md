# FFX.exe Decompilation — Batch 2 (Phyre_PClassDescriptor Part 1)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 25 (Phyre_PClassDescriptor family — constructors, destructors, find-by-name)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the core Phyre_PClassDescriptor type system: constructors, destructors, and name lookup. The PClassDescriptor is PhyreEngine's RTTI/reflection system — each class in the engine has a descriptor that stores name, base class, members, properties, and serialization info.

## Functions Decompiled

### Phyre_PClassDescriptor_Constructor (0x43b0a0, 239 bytes)
- **Callers:** 47 xrefs (Phyre_PTimer_GetSingleton, RegisterClassDescriptor variants for Matrix3/4, Point3, Quat, Vector2/3/4, Matrix4x3)
- **Purpose:** Base constructor — initializes all linked list sentinels (self-pointing), sets fields to 0, m_regState=-1
- **Structure:** 1 basic block (linear), 239 bytes
- **Key insight:** All 5+ linked lists are initialized as circular sentinels (`&this->field`), classic intrusive linked list pattern

### Phyre_PClassDescriptor_ctor (0x43b190, 237 bytes)
- **Callers:** 100+ xrefs — 1125 total xrefs (Phyre_PClassMember_InitSingleton, Phyre_PNamespace_InitSingleton, PCluster_InitClassDescriptor, etc.)
- **Purpose:** Extended constructor with 6 params — adds parentCD (+0x40) and field84 (+0x84) for subclass hierarchy
- **Note:** This is the most-called constructor in the entire type system

### Phyre_PClassDescriptor_Destructor (0x43b4d0, 447 bytes, 45 basic blocks) ⭐
- **Callers:** 2874 xrefs (ALL destructor variants: DtorV4/V5/V6, Dtor_Base, Math_Sin/Cos, Stream_GetBuffer, etc.)
- **Callees:** Engine_AlignedFree, PLinkedList_DrainAll, Phyre_PNamespace_DetachFromList
- **Purpose:** Full destructor — resets vfptr, detaches namespace list, drains 5 PLinkedList sentinels, frees with Engine_AlignedFree

### Phyre_PClassDescriptor_RegisterAll (0x43bf60, 410 bytes, 37 basic blocks)
- **Callers:** Phyre_Engine_Init (only 1 caller — called during engine boot)
- **Callees:** Engine_AlignedFree, Engine_AlignedAllocAlign, Phyre_PNamespace_GetSingleton, Phyre_PClass_FenceInitArray
- **Purpose:** Registers ALL class descriptors in the type system — walks a global fence array and initializes each

### Phyre_PClassDescriptor_FindByName (0x435ad0, 121 bytes, 15 basic blocks)
- **Callers:** 56 xrefs (Scripting_RegisterIsTypeOf, Scripting_InitBindings, PCluster_InitSingleton, data binding, camera registration, etc.)
- **Purpose:** Walks intrusive linked list comparing m_nameString (+0x0C) via inline strcmp
- **Key insight:** Returns NULL if name is NULL, uses tri-field sentinel (&field) to detect list end

### Phyre_PClassDescriptor_FindByNameHierarchy_MemberList (0x435c80, 131 bytes, 17 basic blocks)
- **Callers:** Phyre_Scripting_IndexHandler, Phyre_DataBinding_BindVector4Property
- **Purpose:** Finds by name walking member list hierarchy (walks up m_pParentCD + searches member lists)

### Phyre_PClassDescriptor_FindByNameSelfList (0x435d10, 131 bytes, 17 basic blocks)
- **Callers:** Phyre_Scripting_IndexHandler, PEntity_GetLocalToWorldMatrix, Phyre_DataBinding_BindVector4Method, Phyre_TextureManager_InitFromPool
- **Purpose:** Finds by name walking self list + parent chain

### Phyre_PClassDescriptor_FindByNamePropertyList (0x435da0, 135 bytes, 21 basic blocks)
- **Callers:** 9 callers (Scripting_IndexHandler, NewIndexHandler, PClassMember_InsertIntoPropertyList, Type_ResolveOnLoad, etc.)
- **Purpose:** Finds by name walking property list (m_propertyList + 4 byte offset to skip container header)

### Phyre_PClassDescriptor_FindByNamePropertyList2 (0x435e30, 131 bytes, 17 basic blocks)
- **Callers:** Phyre_Scripting_IndexHandler, Phyre_Scripting_NewIndexHandler
- **Purpose:** Finds by name walking property list V2 (alternate property list at different offset)

### Phyre_PClassDescriptor_GetOrInitSingleton (0x43a810, 109 bytes, 10 basic blocks)
- **Callers:** Phyre_Scripting_GetPClassDescriptorRef
- **Callees:** Phyre_PClass_ConstructDefault, Phyre_PClassDataMember_ValidateLayout
- **Purpose:** Singleton get-or-create pattern with flag-based init guard (0x20000000/0x40000000 flags)

---

## Key Findings

1. **PhyrePClassDescriptor struct layout** (reconstructed from constructors):
   - +0x00: vfptr (4 bytes)
   - +0x04: m_propListHead (4B, sentinel self-ptr)
   - +0x08: m_pSerializer (4B, aliased with propListHead)
   - +0x0C: m_namespaceList (4B, sentinel self-ptr)
   - +0x10: m_namespaceListPrev (4B)
   - +0x14: m_pClassDescriptor (4B, initially 0)
   - +0x18: m_pBaseClass (4B, initially 0)
   - +0x1C: m_pClassName (4B, const char* name)
   - +0x20: m_typeSize (4B, sizeof the type)
   - +0x24: m_flags (4B)
   - +0x28: m_regState (4B, -1 = unregistered)
   - +0x2C: m_memberListHead (4B sentinel)
   - +0x30: m_memberListTail (4B)
   - +0x34-0x3C: PLinkedList sentinel pairs + namespace list
   - +0x40: m_pParentCD (4B, parent class descriptor)
   - +0x44: m_propertyList (4B sentinel) + tail
   - +0x4C-0x60: 3x PLinkedList sentinel pairs
   - +0x7C: m_refCount (4B)
   - +0x84: field84 (extended ctor)

2. **Three separate intrusive linked lists** per PClassDescriptor: namespace list, member list, property list

3. **Tri-field sentinel pattern**: `&this->field` used as end-of-list marker

4. **RegisterAll** is the type system bootstrapper — called once by `Phyre_Engine_Init` at startup

5. ***ctor is the workhorse** — 1125 code xrefs, template-generated RegisterClassDescriptor functions

## Next Batches

- Batch 2 Part 2: Remaining PClassDescriptor functions (GetField, Traverse, CalcLayoutSize, etc.)
- Batch 3: Phyre_PArray family
- Batch 4: Phyre_Scripting family
- Batch 5+: PNamespace, PMath, PMemory, PStream
