#include "../include/ffx_debug.h"
// ============================================================================
// FFX.EXE — PhyreEngine Core Implementation (Stub)
// Gerado de analise IDA com decompilador Hex-Rays
// Database: jarvis_goal (session 12605b8a)
// 47+ funcoes analisadas: PClass, PObject, PArray, Type, PNamespace,
// Zlib, MemoryPool, Cluster, ThreadPool, SceneNode, Container
// FASE 3-A+B: Headers em ../include/ffx_structs.h e ffx_vtables.h
// ============================================================================
#include "../include/ffx_structs.h"
#include "../include/ffx_vtables.h"

// ============================================================================
// PCLASSDESCRIPTOR — CONSTRUTORES / DESTRUTORES
// ============================================================================

// Function: Phyre_PClassDescriptor_Destructor (0x43b4d0, 1228 xrefs)
// Decompiled body:
//   Set vtable to base Phyre::PClassDescriptor
//   if (this->refCount + 1 == globalRefCount) --globalRefCount
//   Detach from namespace list
//   Drain all linked list entries via PLinkedList_DrainAll
//   Engine_AlignedFree(this) if pending dealloc
//   Return comparison result
bool __thiscall Phyre_PClassDescriptor_Destructor(PhyrePClassDescriptor *this, bool flags)
{
    // Decompiled from 0x43b4d0. Full destructor: unlinks from namespace,
    // drains all 6 linked lists, frees memory, returns refcount comparison.
    // 185 instructions, 45 basic blocks, cyclomatic 17

    // Step 1: set vtable to base PClassDescriptor (use existing vtable)
    this->vfptr = (int *)vtable_PhyrePClassDescriptor;

    // Step 2: decrement global refcount if needed (original uses MEMORY[0xC90758])
    if (this->m_refCount + 1 == unk_C90758)
        unk_C90758--;

    // Step 3: detach from namespace binding
    Phyre_PNamespace_DetachFromList((int)this->m_pNamespace, (int)this);

    // Step 4: drain all linked lists
    // linkedList (offset 0x4C) — class descriptor hierarchy list
    // For each entry: check flag at offset 0x40 (16 dwords in), free if flagged
    {
        int *pList = &this->linkedList;
        int *pEntry = (int *)(pList != (int *)*pList ? *pList : 0);
        while (pEntry)
        {
            int *pNext = (int *)(pList != (int *)*pEntry ? (int *)*pEntry : 0);
            if (((unsigned char *)pEntry)[0x40] & 1)  // flag at offset 0x40
            {
                int *prev = (int *)*pEntry;
                int *next = (int *)pEntry[1];
                prev[1] = (int)next;
                next[0] = (int)prev;
                *pEntry = (int)pEntry;
                pEntry[1] = (int)pEntry;
                Engine_AlignedFree((void *)pEntry[3]);
                Engine_AlignedFree(pEntry);
            }
            pEntry = pNext;
        }
    }
    // memberListHead (offset 0x54) — same pattern
    {
        int *pList = &this->m_memberListHead;
        int *pEntry = (int *)(pList != (int *)*pList ? *pList : 0);
        while (pEntry)
        {
            int *pNext = (int *)(pList != (int *)*pEntry ? (int *)*pEntry : 0);
            if (pEntry)
            {
                if (((unsigned char *)pEntry)[0x40] & 1)
                {
                    int *prev = (int *)*pEntry;
                    int *next = (int *)pEntry[1];
                    prev[1] = (int)next;
                    next[0] = (int)prev;
                    *pEntry = (int)pEntry;
                    pEntry[1] = (int)pEntry;
                    Engine_AlignedFree((void *)pEntry[3]);
                    Engine_AlignedFree(pEntry);
                }
            }
            pEntry = pNext;
        }
    }
    // Drain remaining lists via DrainAll
    PLinkedList_DrainAll(&this->m_propertyList);    // field44
    PLinkedList_DrainAll(&this->linkedList);         // field4C
    PLinkedList_DrainAll(&this->m_memberListHead);  // field54
    PLinkedList_DrainAll(&this->m_propertyListV2);  // field5C
    bool result = (bool)PLinkedList_DrainAll(&this->m_linkedListHead2); // field34

    // Step 5: set base vtable (original uses vtable_PType_Phyre — use existing PClassDescriptor)
    this->vfptr = (int *)vtable_PhyrePClassDescriptor;
    return result;
}

// Function: Phyre_PClassDescriptor_ctor (0x43b190, 721 xrefs)
// Decompiled body:
//   Init all sentinel-linked-list fields to point to self (field2C, field4, field34, field44, linkedList, field54, field5C)
//   Zero field10, field14, field24, field28, field64-78
//   Set vfptr to Phyre::PClassDescriptor::vftable
//   Set namespaceList = name, field40 = parentCD
//   refCount = globalRefCount++
//   Set fields 33-36 (field84, -1, 0, 0, 0)
_DWORD *__thiscall Phyre_PClassDescriptor_ctor(
    PhyrePClassDescriptor *this,
    int name,
    int field18,
    int field1C,
    int field20,
    int parentCD,
    int field84)
{
    // Decompiled from 0x43b190. Init sentinel-linked-lists + fields.
    // Sentinel init: each list head points to itself
    this->m_propListHead = (int)&this->m_propListHead;      // field2C
    this->m_linkedListHead2 = (int)&this->m_linkedListHead2; // field34
    this->m_propertyList = (int)&this->m_propertyList;      // field44
    this->linkedList = (int)&this->linkedList;               // field4C
    this->m_memberListHead = (int)&this->m_memberListHead;  // field54
    this->m_propertyListV2 = (int)&this->m_propertyListV2;  // field5C

    // Zero fields
    this->m_pClassDescriptor = 0;  // field10
    this->m_pBaseClass = 0;        // field14
    this->m_unk24 = 0;             // field24
    this->m_unk28 = 0;             // field28
    this->m_pInstanceData = 0;     // field64
    this->m_pInitData = 0;         // field68
    this->m_pTypeTable = 0;        // field6C
    this->m_pDefaultValue = 0;     // field74
    this->m_pDefaultValue2 = 0;    // field78

    // Set vtable
    this->vfptr = (int *)vtable_PhyrePClassDescriptor;  // extern in phyre_stubs.cpp

    // Set namespace
    this->m_namespaceList = name;           // field4
    this->m_pParentCD = parentCD;           // field40

    // Ref count (original uses a global counter)
    static int s_globalRefCount = 1;
    this->m_refCount = s_globalRefCount++;  // field7C

    // Set remaining fields
    this->m_field84 = field84;              // field84 (offset 132)
    // fields 34-36 at struct+31..33 (-1, 0, 0, 0)
    *(_DWORD *)((char *)this + 136) = -1;   // field88
    *(_DWORD *)((char *)this + 140) = 0;    // field8C
    *(_DWORD *)((char *)this + 144) = 0;    // field90

    return &this->vfptr;
}

// Function: Phyre_PClassDescriptor_Constructor (0x43b0a0, 16 xrefs)
// Decompiled body:
//   Same field init as ctor, but field40 = 0 (no parent), field84 omitted
//   totalSize stored in field20, field84 (offset 132) = 0
void __thiscall Phyre_PClassDescriptor_Constructor(
    PhyrePClassDescriptor *this,
    int name,
    int field18,
    int field1C,
    int totalSize)
{
    // Decompiled from 0x43b0a0. Simpler variant for primitive types.
    // Same as _ctor but no parent, no field84 parameter.
    // Init sentinel-linked-lists
    this->m_propListHead = (int)&this->m_propListHead;
    this->m_linkedListHead2 = (int)&this->m_linkedListHead2;
    this->m_propertyList = (int)&this->m_propertyList;
    this->linkedList = (int)&this->linkedList;
    this->m_memberListHead = (int)&this->m_memberListHead;
    this->m_propertyListV2 = (int)&this->m_propertyListV2;

    // Zero fields
    this->m_pClassDescriptor = 0;
    this->m_pBaseClass = 0;
    this->m_unk24 = 0;
    this->m_unk28 = 0;
    this->m_pInstanceData = 0;
    this->m_pInitData = 0;
    this->m_pTypeTable = 0;
    this->m_pDefaultValue = 0;
    this->m_pDefaultValue2 = 0;

    // Set vtable + namespace
    this->vfptr = (int *)vtable_PhyrePClassDescriptor;
    this->m_namespaceList = name;
    this->m_pParentCD = 0;  // no parent (pure primitive type)

    // Set total size (field20 for primitive types)
    *(int *)((char *)this + 0x20) = totalSize;  // m_totalSize at offset 0x20

    // Ref count
    static int s_globalRefCountPrim = 1;
    this->m_refCount = s_globalRefCountPrim++;

    // No field84 parameter — set to 0
    this->m_field84 = 0;  // field84 = 0

    // fields 34-36 at struct+31..33 (-1, 0, 0, 0)
    *(_DWORD *)((char *)this + 136) = -1;
    *(_DWORD *)((char *)this + 140) = 0;
    *(_DWORD *)((char *)this + 144) = 0;
}

// Function: Phyre_PClassDescriptor_GetOrInitSingleton (0x43a810, 1 caller)
// Decompiled body:
//   Check MEMORY[0xC90760].field70; if set, return field70 - 24
//   Otherwise run ConstructDefault + ValidateLayout on the global singleton
//   Return computed pointer or 0
int __usercall Phyre_PClassDescriptor_GetOrInitSingleton(int a1@<esi>)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 30 instructions, 10 basic blocks, cyclomatic 5
    // Callees: Phyre_PClass_ConstructDefault, Phyre_PClassDataMember_ValidateLayout
    return 0;
}

// Function: Phyre_PClassDescriptor_TraversePropertyList (0x43ac50, 2 xrefs)
// Decompiled body:
//   For each class in hierarchy (via field40):
//     Walk property list (field44 linked list)
//     Call Phyre_PClassMember_SerializeMember on each entry
void __thiscall Phyre_PClassDescriptor_TraversePropertyList(PhyrePClassDescriptor *this, int context)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 36 instructions, 11 basic blocks, cyclomatic 9
    // Callees: Phyre_PClassMember_SerializeMember
}

// Function: Phyre_PClassDescriptor_TraversePropertyList_V2 (0x43ae00, 2 xrefs)
// Decompiled body:
//   Same as V1 but uses field48 (instead of field44) for the linked list head
void __thiscall Phyre_PClassDescriptor_TraversePropertyList_V2(PhyrePClassDescriptor *this, int context)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 36 instructions, 11 basic blocks, cyclomatic 9
    // Callees: Phyre_PClassMember_SerializeMember
}

// Function: Phyre_PClass_TraverseHierarchy (0x43aca0, 2 xrefs)
// Decompiled body:
//   Complex recursive traversal that:
//   - Walks property list (field44), calls SerializeField
//   - Gets type info from member, gets default value from owner
//   - Recurses into sub-class descriptors
//   - Tracks byte offsets and sizes
void __thiscall Phyre_PClass_TraverseHierarchy(PhyrePClassDescriptor *this, int context)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 120 instructions, 24 basic blocks, cyclomatic 18
    // Callees: Phyre_PClassMember_SerializeField, Phyre_PClass_TraverseHierarchy (recursive), PClassDataMember_GetDefaultValueFromOwner
}

// ============================================================================
// PCLASSDESCRIPTOR — BUSCA POR NOME
// ============================================================================

// Function: Phyre_PClassDescriptor_FindByName (0x435ad0, 56 xrefs)
// Decompiled body:
//   if (!name || !this) return 0
//   Walk linkedList (this->linkedList), comparing each entry's fieldC via strcmp
//   strcmp result normalized to -1/0/1 (signed comparison)
//   If match found, return entry; else walk hierarchy parent via field40
PhyrePClassDescriptor *__thiscall Phyre_PClassDescriptor_FindByName(
    PhyrePClassDescriptor *this,
    const char *name)
{
    // Decompiled from 0x435ad0. Searches intrusive linked list for name match.
    // The linkedList at offset 0x4C is an embedded sentinel node. Each list
    // entry is a PhyrePClassDescriptor* where vfptr (offset 0) serves as the
    // "next" pointer in list context. fieldC (m_nameString) carries the name.
    if (!name || !this)
        return 0;

    // Check if list is empty (sentinel points to itself: empty-list test)
    int *pSentinel = &this->linkedList;
    PhyrePClassDescriptor *pEntry = (PhyrePClassDescriptor *)(int *)this->linkedList;
    if (pSentinel == (int *)pEntry)  // sentinel self-loop = empty
        return 0;

    // Walk the linked list comparing names
    while (pEntry)
    {
        const char *entryName = (const char *)pEntry->m_nameString;
        // fieldC at offset 0x0C holds the name pointer
        if (entryName)
        {
            int cmp = strcmp(entryName, name);
            if (cmp == 0)
                return pEntry;  // found match
        }
        // Advance: next node is at the address stored in vfptr (offset 0)
        int *pNext = (int *)pEntry->vfptr;
        if (pNext == pSentinel)  // back to sentinel = end of list
            return 0;
        pEntry = (PhyrePClassDescriptor *)pNext;
    }
    return 0;
}

// Function: Phyre_PClassDescriptor_FindByNamePropertyList (0x435da0, 9 xrefs)
// Decompiled body:
//   if (!name || !this) return 0
//   Walk property list (field44 linked list, entry at offset -4 from address)
//   Compare field10 via strcmp
//   Walk hierarchy via field40 (parent class descriptor)
PhyrePClassDescriptor *__thiscall Phyre_PClassDescriptor_FindByNamePropertyList(
    PhyrePClassDescriptor *this,
    const char *name)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 65 instructions, 21 basic blocks, cyclomatic 15
    // No callees
    return 0;
}

// Function: Phyre_PClassDescriptor_FindByNamePropertyList2 (0x435e30, 2 xrefs)
// Decompiled body:
//   Same as FindByNamePropertyList but uses field48 (offset 0x5C) as list head
//   Entry pointer arithmetic: entry = *(this+23) -> container = entry - 4 (field44 based?)
_DWORD *__thiscall Phyre_PClassDescriptor_FindByNamePropertyList2(_DWORD *this, const char *a2)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 63 instructions, 17 basic blocks, cyclomatic 11
    return 0;
}

// Function: Phyre_PClassDescriptor_FindByNameSelfList (0x435d10, 4 xrefs)
// Decompiled body:
//   Same pattern as FindByName but uses self-linked-list (linkedList) exclusively
//   Walk linkedList comparing fieldC, then walk field40 hierarchy
PhyrePClassDescriptor *__thiscall Phyre_PClassDescriptor_FindByNameSelfList(
    PhyrePClassDescriptor *this,
    const char *name)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 63 instructions, 17 basic blocks, cyclomatic 11
    return 0;
}

// Function: Phyre_PClassDescriptor_FindByNameHierarchy_MemberList (0x435c80, 2 xrefs)
// Decompiled body:
//   Same pattern but uses field54 as linked list head
//   Used for hierarchical member list search
PhyrePClassDescriptor *__thiscall Phyre_PClassDescriptor_FindByNameHierarchy_MemberList(
    PhyrePClassDescriptor *this,
    const char *name)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 63 instructions, 17 basic blocks, cyclomatic 11
    return 0;
}

// ============================================================================
// PCLASS MEMBER — INIT / TYPEINFO
// ============================================================================

// Function: Phyre_PClassMember_InitSingleton (0x43a050, 0 callers)
// Decompiled body:
//   GetDefaultPool -> GetNamespace -> Phyre_PClassDescriptor_ctor(name="PClassMember", size=20)
//   Set vtable to PClassDescriptorAbstract<PClassMember>
//   Set field64/68/6C to static function tables
PhyrePClassDescriptor *__thiscall Phyre_PClassMember_InitSingleton(PhyrePClassDescriptor *this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 56 instructions, 6 basic blocks
    // Callees: Phyre_PClassDescriptor_ctor, Phyre_GetDefaultPool, Phyre_PNamespace_GetSingleton
    return 0;
}

// Function: Phyre_PClassMember_TypeInfo_Init (0x43a2d0, 1 caller)
// Decompiled body:
//   Register name, then create members:
//   - "m_flags" (PUInt32, offset 16, structural)
//   - "m_classDescriptor" (PClassDescriptor ref, offset 8, structural, type 2)
//   Finalize registration
_DWORD *Phyre_PClassMember_TypeInfo_Init()
{
    // TODO: implement
    FFX_LOG_STUB();
    // 74 instructions, 9 basic blocks
    // Callees: Phyre_PType_GetPUInt32, Phyre_PClassDescriptor_FinalizeRegistration, Phyre_PClassDataMember_ctorAttach_structural, _atexit
    return 0;
}

// ============================================================================
// PCLASS DATA MEMBER — VALIDATION / INIT
// ============================================================================

// Function: Phyre_PClassDataMember_ValidateLayout (0x43c720, 7 xrefs)
// Decompiled body:
//   Check if buffer exists; fill with 0xFF and 0x00
//   Walk through sub-class descriptor, copy default values from parent
//   Validate each member's offset/size, print "overlaps" warning if conflict
//   Recursively validate sub-class descriptors
char __thiscall Phyre_PClassDataMember_ValidateLayout(int this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 325 instructions, 76 basic blocks, cyclomatic 40
    // Callees: memset, memcpy, Phyre_PClass_ConstructDefault, PAnnotationList_FindByID
    // String: "Data Member %s on class %s overlaps existing data members\n"
    return 1;
}

// Function: Phyre_PClassDataMember_InitForVector2 (0x45fc00, 6 xrefs)
// Decompiled body:
//   Register Vector2 class with Constructor("Vector2", 8, 4)
//   Init m_elements (x2 float array)
//   Register setX/setY methods via StringNode + FindByName + CallerImplementation vtables
//   FinalizeRegistration
//   Singleton pattern with atexit + dword_C944DC guard flags
PhyrePClassDescriptor *__thiscall Phyre_PClassDataMember_InitForVector2(void *this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 151 instructions, 23 basic blocks, cyclomatic 5
    // Callees: Phyre_PClassDescriptor_Constructor, Phyre_PClassDescriptor_FindByName, Phyre_StringNode_Ctor,
    //         Phyre_PClassDescriptor_FinalizeRegistration, Phyre_PType_GetFloat, _atexit
    return 0;
}

// Function: Phyre_PClassDataMember_InitForChunkFile (0x468950, 1 caller)
// Decompiled body:
//   Register ~20+ member fields on the ChunkFile class descriptor:
//   m_phyreMarker, m_size, m_instanceListCount, m_packedNamespaceSize,
//   m_arrayFixupSize/Count, m_pointerFixupSize/Count, m_pointerArrayFixupSize/Count
//   Each uses Phyre_PClassDataMember_ctorAttach_structural with PUInt32 type
_DWORD *Phyre_PClassDataMember_InitForChunkFile()
{
    // TODO: implement
    FFX_LOG_STUB();
    // 443 instructions, 57 basic blocks
    // Callees: Phyre_PType_GetPUInt32 (x20), Phyre_PClassDescriptor_FinalizeRegistration,
    //         Phyre_PClassDataMember_ctorAttach_structural (x20), _atexit (x20)
    return 0;
}

// Function: Phyre_PClassDataMember_InitForEntity (0x44f200, 1 caller)
// Decompiled body:
//   Register Entity class with scripting methods:
//   getComponent, getWorldMatrix, setWorldMatrix, addComponent, removeComponent
//   Register data members: m_firstComponent, m_worldMatrix
//   Uses StringNode + FindByName for method registration
//   Uses PMethodCallerConcrete vtables for callbacks
_DWORD *Phyre_PClassDataMember_InitForEntity()
{
    // TODO: implement
    FFX_LOG_STUB();
    // 334 instructions, 51 basic blocks, cyclomatic 14
    // Callees: Phyre_PClassDescriptor_FindByName (x8), Phyre_StringNode_Ctor (x6),
    //         Phyre_PClassDescriptor_FinalizeRegistration, _atexit (x8)
    return 0;
}

// ============================================================================
// PARRAY — CLASS DESCRIPTOR / DATA MANAGEMENT
// ============================================================================

// Function: Phyre_PArrayU8_ClassDescriptorInit (0x4474c0, 26 xrefs)
// Decompiled body:
//   GetDefaultPool -> GetNamespace -> Phyre_PClassDescriptor_ctor(name=<namespace>, field18=<fromStack>, 8, 4, parentCD, 0)
//   Set flags bit 2 (abstract?), vtable to PClassDescriptorAbstract<PArray<unsigned char,1>>
//   Set field64/68/6C to static vtable tables
PhyrePClassDescriptor *__thiscall Phyre_PArrayU8_ClassDescriptorInit(PhyrePClassDescriptor *this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 56 instructions, 6 basic blocks
    // Callees: Phyre_PClassDescriptor_ctor, Phyre_GetDefaultPool, Phyre_PNamespace_GetSingleton,
    //         Phyre_PClassDescriptor_SetField64/68/6C
    return 0;
}

// Function: Phyre_PArray_PTypedObject_AllocAndCopy (0x457cd0, 2 xrefs)
// Decompiled body:
//   Get count from source array (masked)
//   Engine_AlignedAllocAlign(count * 8, 4)
//   Call Phyre_PArray_PTypedObject_CopyPairs to copy elements
//   Free old buffer if different
int *__thiscall Phyre_PArray_PTypedObject_AllocAndCopy(int *this, int *a2)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 47 instructions, 8 basic blocks, cyclomatic 6
    // Callees: Engine_AlignedAllocAlign, Phyre_PArray_PTypedObject_CopyPairs, Engine_AlignedFree
    return 0;
}

// Function: Phyre_PArray_PTypedObject_CopyPairs (0x456e70, 2 xrefs)
// Decompiled body:
//   For each pair: copy *a2 and a2[1] to *a1 and a1[1]
//   a1 and a2 advance by 2 each iteration
void __cdecl Phyre_PArray_PTypedObject_CopyPairs(_DWORD *a1, _DWORD *a2, int count)
{
    for (int i = count; i > 0; i--)
    {
        if (a1)
        {
            a1[0] = a2[0];
            a1[1] = a2[1];
        }
        a1 += 2;
        a2 += 2;
    }
}

// ============================================================================
// TYPE SYSTEM — CONSTRUCTION / RESOLUTION
// ============================================================================

// Function: Phyre_Type_RegisterOrFindType (0x47c6d0, 4 xrefs)
// Decompiled body:
//   Complex type registration/lookup with hash-based name resolution
//   Walks type bucket array, compares type IDs
//   Handles Field13 (type-specific data) and compatibility flags
//   Calls itself recursively for nested types
int __thiscall Phyre_Type_RegisterOrFindType(_DWORD *this, int a2, int a3, int a4)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 238 instructions, 67 basic blocks, cyclomatic 36
    // Callees: Phyre_Type_RegisterOrFindType (recursive), PClassDataMember_GetField13
    return 0;
}

// Function: Phyre_Type_LazyConstructFromChunk (0x58dce0, 4 xrefs)
// Decompiled body:
//   Get pointer to data (handles inline vs pointer storage based on field 10 bit 31 mask)
//   If data pointer is null, call Phyre_Type_ConstructFromChunk
//   Set field 25 to 1 (constructed flag)
int __thiscall Phyre_Type_LazyConstructFromChunk(int *this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 28 instructions, 8 basic blocks, cyclomatic 4
    // Callees: Phyre_Type_ConstructFromChunk
    return 0;
}

// Function: Phyre_Type_ConstructFromChunks (0x466e60, 1 caller)
// Decompiled body:
//   Complex multi-chunk construction with sub-resource handling
//   Uses managed string iterator for parsing
//   Handles texture format setting, cube map flags, 3D texture flags
//   Calls ConstructFromChunk / ConstructFromChunkVariableSize for each chunk
//   121 basic blocks, many callees — one of the largest in the type system
int __stdcall Phyre_Type_ConstructFromChunks(_DWORD *a1, _DWORD *a2)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 550 instructions, 121 basic blocks, cyclomatic 64
    // Callees: Phyre_Type_ConstructFromChunk (x2), Engine_AlignedAllocAlign, Engine_AlignedFree,
    //         PTextureFormat_SetDimensions, Phyre_Texture_Construct, Phyre_ClusterContext_Create
    return 0;
}

// Function: Phyre_Type_CreateDynamicClass (0x47c250, 2 callers)
// Decompiled body:
//   Creates a class descriptor dynamically at runtime from cluster data
//   Validates super class references, allocates memory, copies data
//   Calls RegisterOrFindType for type resolution
//   Configures dispatch, validates compatibility, finalizes registration
//   Error messages for: invalid super class, type not found, namespace conflict
int __thiscall Phyre_Type_CreateDynamicClass(_DWORD *this, _DWORD *a2, int a3, char a4)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 385 instructions, 81 basic blocks, cyclomatic 39
    // Callees: Phyre_Type_RegisterOrFindType, Engine_AlignedAllocSimple, Phyre_Stream_Printf,
    //         PClassDescriptorDynamic_Constructor, Phyre_Type_ValidateClassCompatibility,
    //         Phyre_PClassDescriptor_FinalizeRegistration, Engine_AlignedFree
    return 0;
}

// Function: Phyre_Type_ResolveOnLoad (0x47c970, 2 callers)
// Decompiled body:
//   Resolves type references when loading a cluster file
//   Uses hash (n1973 = (vfptr_low & 0x1F) + 33 * n1973) for name lookup
//   Calls NameMap_BST_FindOrInsert for string-based type lookup
//   Calls FindByNamePropertyList for property resolution
//   Prints errors for: type not found, compiled class missing, namespace not found
int __thiscall Phyre_Type_ResolveOnLoad(_DWORD *this, _DWORD *Singleton, _DWORD *a3, int a4, char a5)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 353 instructions, 73 basic blocks, cyclomatic 41
    // Callees: Phyre_NameMap_BST_FindOrInsert, Phyre_PClassDescriptor_FindByNamePropertyList,
    //         Phyre_Type_ValidateClassCompatibility, Phyre_ClassDescriptor_ConfigureDispatch,
    //         Phyre_PNamespace_FindClassDescriptor, Phyre_Stream_Printf
    return 0;
}

// Function: Phyre_Type_ValidateClassCompatibility (0x47cd40, 2 callers)
// Decompiled body:
//   Validates class descriptor against file-stored metadata
//   Checks: class size (resized warning), super class (changed/added/removed),
//           data member existence, offset changes, size changes, type changes
//   10 string constants for each type of compatibility warning
int __thiscall Phyre_Type_ValidateClassCompatibility(int *this, char a2)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 353 instructions, 90 basic blocks, cyclomatic 46
    // Callees: Phyre_Stream_Printf, PClassDataMember_GetField13
    return 0;
}

// Function: Phyre_Type_VisitMembers (0x4982a0, 2 callers)
// Decompiled body:
//   Walks through type member array, applying visitor callback
//   Handles reallocation of member storage if counts don't match
//   Tracks byte offsets and stride (a7 parameter controls 2*stride stepping)
int __thiscall Phyre_Type_VisitMembers(
    _DWORD *this,
    _DWORD *a2,
    _DWORD *a3,
    unsigned int *a4,
    _DWORD *a5,
    int *a6,
    int a7)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 252 instructions, 50 basic blocks, cyclomatic 27
    // Callees: Engine_AlignedAllocAlign, Engine_AlignedFree, Phyre_PArray_PVertexStream_Resize
    return 0;
}

// Function: Phyre_Type_ConstructLarge (0x58c9b0, 1 caller)
// Decompiled body:
//   Constructs a type with sub-resource support (fields 552-768 used)
//   Iterates through constructors, calls Phyre_Type_ConstructDispatcher
//   Handles 3 constructor types (0, 1, 2) with different validation
//   Manages surface mip construction for textures
//   Stack cookie (/GS) protection active
char __thiscall Phyre_Type_ConstructLarge(int this, int a2)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 370 instructions, 77 basic blocks, cyclomatic 42
    // Callees: Phyre_Type_ConstructDispatcher, Phyre_Texture_BuildSurfaceMip, memset
    return 0;
}

// Function: Phyre_Type_ConstructFromChunk_SubResources (0x58fa10, 1 caller)
// Decompiled body:
//   Constructs sub-resources for a type from cluster chunk data
//   Uses Cluster_ZeroInitArea + Cluster_ReadFieldsFromStream for I/O
//   Iterates through sub-resource array, calling stream reader for each
//   Returns error code 9 on failure
int __thiscall Phyre_Type_ConstructFromChunk_SubResources(char *this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 136 instructions, 25 basic blocks, cyclomatic 6
    // Callees: Phyre_Cluster_ZeroInitArea, Phyre_Cluster_ReadFieldsFromStream,
    //         Phyre_RefCount_GetWithMinOne_C, _atexit
    return 0;
}

// ============================================================================
// POBJECT — REGISTRATION
// ============================================================================

// Function: Phyre_PObject_RegisterClassDescriptor (0x458190, 1 caller)
// Decompiled body:
//   Registers PObject scripting methods with CallerImplementation vtables:
//   getInstances (PMethodCallerConcrete<PInstancesComponent,PArray<PTypedObject> const &>)
//   getInstance (PMethodCallerConcrete<PInstancesComponent,PTypedObject const &,unsigned int>)
//   getInstanceCount (PMethodCallerConcrete<PInstancesComponent,unsigned int>)
//   getInstanceOfType (PMethodCallerConcrete<PInstancesComponent,PTypedObject,PClassDescriptor const *>)
//   Also registers m_instances data member via PClassDataMemberArray_Init
//   Calls Phyre_PArray_PTypedObject_Init for the typed object array
_DWORD *Phyre_PObject_RegisterClassDescriptor()
{
    // TODO: implement
    FFX_LOG_STUB();
    // 224 instructions, 33 basic blocks, cyclomatic 8
    // Callees: Phyre_PClassDescriptor_FindByName (x5), Phyre_StringNode_Ctor (x5),
    //         PClassDataMemberArray_Init, Phyre_PArray_PTypedObject_Init, _atexit (x5)
    // Strings: "getInstances", "getInstance", "getInstanceCount", "getInstanceOfType", "m_instances"
    return 0;
}

// ============================================================================
// PNAMESPACE — Singleton / Init / Find
// ============================================================================

// Function: Phyre_PNamespace_GetSingleton (0x43e3e0, hundreds of callers)
// Decompiled body:
//   One-time init with atexit: initializes sentinel-linked-lists at global
//   dword_C90B00[0..6]. Sets field4/field8 self-loop, field2/field3 self-loop,
//   field5/field6 self-loop. Registers atexit cleanup.
//   Returns pointer to global singleton struct (dword_C90B00).
//   Called by ALL class descriptor registrations (~hundreds of callers).
_DWORD *Phyre_PNamespace_GetSingleton()
{
    // Decompiled from 0x43e3e0. Lazy singleton for global namespace at
    // C90B00 (MEMORY_C90B00). Guard bit at C90B1C bit 0. On first init:
    // sets self-looping sentinel nodes + atexit cleanup.
    // MEMORY_C90B00[4] is the guard byte at offset 0x1C
    if ((MEMORY_C90B00[7] & 1) == 0)  // unk_C90B1C bit 0
    {
        MEMORY_C90B00[7] |= 1;          // set guard
        MEMORY_C90B00[0] = (int)MEMORY_C90B00;  // sentinel self-loop
        MEMORY_C90B00[1] = (int)MEMORY_C90B00;  // pair
        MEMORY_C90B00[2] = (int)&MEMORY_C90B00[2];
        MEMORY_C90B00[3] = (int)&MEMORY_C90B00[2];
        MEMORY_C90B00[4] = 0;
        MEMORY_C90B00[5] = (int)&MEMORY_C90B00[5];
        MEMORY_C90B00[6] = (int)&MEMORY_C90B00[5];
        // atexit(Phyre_PClassDescriptor_DestroyHierarchy_C90B00) — omitted, not needed
    }
    return (_DWORD *)MEMORY_C90B00;
}

// Function: Phyre_PNamespace_InitSingleton (0x43dc50)
// Decompiled body:
//   Typical ClassDescriptorInit pattern:
//   GetDefaultPool -> GetNamespace -> Phyre_PClassDescriptor_ctor("PNamespace", 28, 16, pool, 8)
//   Set flags bit 2, vtable to PClassDescriptorAbstract<PNamespace>
//   Set field64/68/6C to sub-descriptor tables
PhyrePClassDescriptor *__thiscall Phyre_PNamespace_InitSingleton(PhyrePClassDescriptor *this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 56 instructions, 5 basic blocks
    // Callees: Phyre_PClassDescriptor_ctor, Phyre_PClassDescriptor_SetField64/68/6C,
    //         Phyre_GetDefaultPool, Phyre_PNamespace_GetSingleton
    // String: "PNamespace"
    return 0;
}

// Function: Phyre_PNamespace_FindClassDescriptor (0x43ea40, 10 callers)
// Decompiled body:
//   Recursive class descriptor lookup by name within a namespace.
//   Walks the namespace's class list (this+2 sentinel list).
//   Each entry at offset -11 dwords from list node contains field[6] = name.
//   Uses strcmp for name comparison.
//   If not found, recurses into sub-namespaces (this+5 sentinel list).
//   Returns matching PhyrePClassDescriptor* or 0.
_DWORD *__thiscall Phyre_PNamespace_FindClassDescriptor(_DWORD *this, const char *name)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 25 basic blocks, cyclomatic 17
    // Callees: Phyre_PNamespace_FindClassDescriptor (recursive)
    return 0;
}

// Function: Phyre_PNamespace_AddClassDescriptor (0x43e750)
// Decompiled body:
//   Inserts a class descriptor into the namespace's class list.
//   Validates uniqueness via FindClassDescriptor first.
//   Links into doubly-linked list at namespace+2 head.
int __thiscall Phyre_PNamespace_AddClassDescriptor(int this, int classDesc)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 0xe0 bytes
    // Callees: Phyre_PNamespace_FindClassDescriptor
    return 0;
}

// Function: Phyre_PNamespace_DetachFromList (called by Destructor)
// Removes a class descriptor from its namespace binding list.
void __stdcall Phyre_PNamespace_DetachFromList(int namespaceList, int entry)
{
    // Decompiled from 0x43e3e0 (thiscall: PNamespace *this, PClassDescriptor *cd).
    // Entry has prev/next at offsets 0x2C/0x30 (m_propListHead/m_pSerializer).
    // Unlink: prev->next = next; next->prev = prev; self-loop removed entry.
    int prev = *(int *)(entry + 0x2C);  // m_propListHead
    int next = *(int *)(entry + 0x30);  // m_pSerializer
    *(int *)(prev + 4) = next;          // prev->m_pSerializer = next
    *(int *)next = prev;                // next->m_propListHead = prev
    *(int *)(entry + 0x2C) = entry + 0x28;  // self-loop (sentinel state)
    *(int *)(entry + 0x30) = entry + 0x28;  // self-loop
}

// ============================================================================
// AUXILIARY HELPERS — SetField / StringNode / GetDefaultPool
// ============================================================================

// Function: Phyre_PClassDescriptor_SetField64 (0x43d600, 200+ callers)
// Trivial setter: *(this + 25) = a2 (offset 0x64 = field64)
int __thiscall Phyre_PClassDescriptor_SetField64(_DWORD *this, int value)
{
    this->field64 = value;
    return value;
}

// Function: Phyre_PClassDescriptor_SetField68 (0x43d6a0)
// Trivial setter: *(this + 26) = a2 (offset 0x68 = field68)
int __thiscall Phyre_PClassDescriptor_SetField68(_DWORD *this, int value)
{
    this->field68 = value;
    return value;
}

// Function: Phyre_PClassDescriptor_SetField6C (0x43d6b0)
// Trivial setter: *(this + 27) = a2 (offset 0x6C = field6C)
int __thiscall Phyre_PClassDescriptor_SetField6C(_DWORD *this, int value)
{
    this->field6C = value;
    return value;
}

// Function: Phyre_PClassDescriptor_SetFields74_78 (0x43d680)
// Trivial pair setter
int __thiscall Phyre_PClassDescriptor_SetFields74_78(_DWORD *this, int v74, int v78)
{
    this->field74 = v74;
    this->field78 = v78;
    return v78;
}

// ============================================================================
// ZLIB INFLATION — COMPRESSION/DECOMPRESSION
// ============================================================================

// Function: Phyre_ZlibInflate (0x406230, 1 caller, 5613 bytes)
// Decompiled body:
//   Full zlib inflate implementation with 31-state switch machine.
//   Implements RFC 1950/zlib decompression with the following state machine:
//
//   enum ZState {
//       HEADER_CMF=0, HEADER_FLG=1, DICTID=2, HEADER_CHECK=3,
//       BLOCK_TYPE=4, STORED=5, STORED_END=6, STORED_CHECK=7,
//       DYNAMIC_TABLES=8, FIXED_TABLES=9,
//       LENGTH_LITERAL=10, LENGTH_EXTRA=11, LENGTH_DISTANCE=12,
//       DISTANCE_EXTRA=13, MATCH_COPY=14,
//       BLOCK_DONE=15, STREAM_END=16,
//       CHECKSUM=17, DONE=18, ERROR=19..30
//   };
//
//   Main loop:
//     while (state != DONE && state != ERROR) {
//         switch (state) {
//             case HEADER_CMF:   read CMF byte, check compression method (deflate=8)
//             case HEADER_FLG:   read FLG byte, check FCHECK, parse DICTID flag
//             case DICTID:       read preset dictionary ID (4 bytes)
//             case BLOCK_TYPE:   read BFINAL+BTYPE, init block state
//             case STORED:       read LEN+NLEN, skip stored data
//             case DYNAMIC:      read HLIT+HDIST+HCLEN, BuildHuffmanTables
//             case FIXED:        InitFixedTables for lit/dist
//             case LITERAL:      decode symbol via Huffman; <256=literal, 256=EOB, >256=length
//             case MATCH:        read distance, memcpy(window+offset, length)
//             case CHECKSUM:     read and verify adler32
//         }
//     }
//   Uses sub-calls: Phyre_ZlibInflate_ProcessBlock (multi-block streaming),
//   Phyre_ZlibInflate_InitFixedTables, Phyre_ZlibInflate_InflateBlock,
//   Phyre_ZlibInflate_BuildHuffmanTables, Phyre_ZlibCRC32
//   Error strings: "unknown compression method", "invalid window size",
//   "incorrect header check", "invalid block type", "invalid stored block lengths",
//   "invalid code lengths set", "too many length or distance symbols"
int __thiscall Phyre_ZlibInflate(unsigned __int8 **this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 359 basic blocks, cyclomatic 227 — biggest FSM in the binary
    // Callees: Phyre_ZlibCRC32, Phyre_ZlibInflate_InflateBlock (x2),
    //         Phyre_ZlibInflate_BuildHuffmanTables, Phyre_ZlibInflate_InitFixedTables,
    //         Phyre_ZlibInflate_ProcessBlock
    // State variable: unsigned int state (this[0x0C])
    // Input buffer:   unsigned __int8 *next_in   (this[0x04])
    // Available in:   unsigned int avail_in       (this[0x08])
    // Output buffer:  unsigned __int8 *next_out  (this[0x10])
    // Available out:  unsigned int avail_out      (this[0x14])
    // Adler32:        unsigned int adler          (this[0x18])
    // Window:         unsigned __int8 *window     (this[0x1C], 32KB sliding)
    // Huffman tables: 2x struct { unsigned short table[512]; } (lit/dist)
    //
    // Pseudocode (core loop):
    //   while (state < 18) {
    //       switch (state) {
    //           case 0: /* HEADER_CMF */
    //               cmf = READ_BYTE();
    //               method = cmf & 0xF;
    //               if (method != 8) { state = ERROR; break; }
    //               windowBits = (cmf >> 4) + 8;
    //               if (windowBits > 15) { state = ERROR; break; }
    //               state = HEADER_FLG; break;
    //           case 1: /* HEADER_FLG */
    //               flg = READ_BYTE();
    //               check = ((cmf << 8) + flg) % 31;
    //               if (check != 0) { state = ERROR; break; }
    //               dictid_flag = (flg >> 5) & 1;
    //               state = dictid_flag ? DICTID : BLOCK_TYPE; break;
    //           /* ... remaining 15+ states ... */
    //           case 17: /* CHECKSUM */
    //               read_stored_adler32(); compare with computed; state = DONE;
    //       }
    //   }
    return 0;
}

// Function: Phyre_ZlibInflate_BuildHuffmanTables (0x408e30)
// Decompiled body:
//   Builds Huffman decode tables from code length array (max 288/32 symbols)
//   Standard zlib inflate table generation with bit-reversed codes
int __thiscall Phyre_ZlibInflate_BuildHuffmanTables(int this, int a2, int a3, int maxSymbols)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 44a bytes, callees: none (pure computation)
    return 0;
}

// Function: Phyre_ZlibInflate_InflateBlock (0x408110)
// Decompiled body:
//   Processes a single compressed block using Huffman tables
//   Handles literal/length codes, distance codes, and copy operations
int __thiscall Phyre_ZlibInflate_InflateBlock(int this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 42e bytes
    // Callees: memcpy
    return 0;
}

// ============================================================================
// MEMORY POOL — ALLOC / FREE
// ============================================================================

// Function: Phyre_MemoryPool_Alloc (0x6eb680, 1 caller, 1036 bytes)
// Decompiled body:
//   Buddy allocator: size class derived via _BitScanReverse on (n16>>8)
//   31 size classes (index 0..31). Class 31 = large (raw OS alloc).
//   Walks free tree (binary tree per size class, nodes at a1[n31+76]).
//   Best-fit: finds smallest block >= n16, splits remainder.
//   Free list is embedded in free blocks (next/prev pointers).
//   Thread-safe via a1[0] spinlock bit.
//   Returns pointer to usable area (offset +8 from block header).
_DWORD *__cdecl Phyre_MemoryPool_Alloc(_DWORD *pool, unsigned int n16)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 95 basic blocks, cyclomatic 47
    // No callees — pure pointer manipulation
    return 0;
}

// Function: Phyre_MemoryPool_Free (0x6eac50, 1 caller, 854 bytes)
// Decompiled body:
//   Aligns input pointer to 8 bytes, merges with adjacent free blocks.
//   If next block is end-of-pool, pool top shrinks.
//   If previous block is free, merges (coalescing).
//   For small blocks (< 0x100 bytes): re-inserts into per-size-class free list.
//   For large blocks: inserts into AVL-style tree.
//   Updates pool stats: allocated/deallocated counters.
int __cdecl Phyre_MemoryPool_Free(_DWORD *pool, int ptr, int a3, int n16)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 71 basic blocks, cyclomatic 37
    // No callees — pure pointer/linked-list manipulation
    return 0;
}

// ============================================================================
// TYPE SYSTEM — CONSTRUCTION DISPATCHER
// ============================================================================

// Function: Phyre_Type_ConstructDispatcher (0x5915f0, 4 callers, 1710 bytes)
// Decompiled body:
//   Dispatcher that routes type construction by type byte (this[4]):
//   0 = pointer/reference: calls ConstructFromChunk if not yet constructed
//   1 = concrete type with sub-resources: calls ConstructFromChunk + SubResources
//   2 = variable-size type: calls ConstructFromChunkVariableSize
//   Handles lazy construction (field 25 flag), constructs sub-resources,
//   allocates aligned memory for arrays, reads fields from cluster stream
int __thiscall Phyre_Type_ConstructDispatcher(_BYTE *this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 115 basic blocks, cyclomatic 56
    // Callees: Phyre_Type_ConstructFromChunk, Phyre_Type_ConstructFromChunkVariableSize,
    //         Engine_AlignedAllocAlign, Engine_AlignedFree, Phyre_Texture_Construct,
    //         Phyre_Cluster_ZeroInitArea, Phyre_Cluster_ReadFieldsFromStream
    return 0;
}

// Function: Phyre_Type_ConstructFromChunk (0x590530, 4 callers, 1102 bytes)
// Decompiled body:
//   Core type construction from cluster chunk data.
//   Reads type fields from cluster stream via Cluster_ReadFieldsFromStream.
//   Handles sub-resource construction via ConstructFromChunk_SubResources.
//   Manages ref-counted allocation, size fixup, and lazy init flags.
//   Security: /GS stack cookie active.
int __thiscall Phyre_Type_ConstructFromChunk(int *this, unsigned int a2, char a3, int a4, char a5)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 68 basic blocks, cyclomatic 29
    // Callees: Phyre_Cluster_ZeroInitArea, Phyre_Cluster_ReadFieldsFromStream,
    //         Phyre_Type_ConstructFromChunk_SubResources, Phyre_RefCount_GetWithMinOne_C
    return 0;
}

// ============================================================================
// CLUSTER — INSTANTIATION / FIXUP
// ============================================================================

// Function: Phyre_ClusterInstantiate_FixupSizes (0x57b830, 1 caller, 1556 bytes)
// Decompiled body:
//   Post-load fixup for cluster instances. Compares file-stored class sizes
//   against runtime sizes. Handles:
//   - Header class size mismatch (prints warning)
//   - Child object class expansion
//   - Array/poly-object relocation and size fixup
//   - Endian swap for RGBA data
//   - Pointer index resolution via Cluster_GetPointerByIndex
//   - Stream reading of import regions
//   - Memory allocation and data copying for expanded classes
//
//   Pseudocode (core logic):
//     header = (ClusterHeader *)this[0];
//     for each class in header->classTable:
//         fileSize = header->classSizes[i];
//         runtimeSize = PClassDescriptor_GetSize(classDesc);
//         if (runtimeSize > fileSize) {
//             // Class expanded — reallocate instance buffer
//             newBuffer = Engine_AlignedAllocAlign(runtimeSize * count, alignment);
//             for each instance:
//                 memcpy(newBuffer + j*runtimeSize, oldBuffer + j*fileSize, fileSize);
//                 Phyre_Class_ConstructInterleaved(newBuffer + j*runtimeSize + fileSize,
//                                                  runtimeSize - fileSize);
//             Engine_AlignedFree(oldBuffer);
//             Phyre_Stream_Printf("Class '%s' is larger at runtime...");
//         } else if (runtimeSize < fileSize) {
//             Phyre_Stream_Printf("Header class '%s' is larger at runtime...");
//         }
//     // Resolve pointer references via Cluster_GetPointerByIndex
//     // Endian-swap RGBA fields if needed
//     // Read import regions from stream
int __thiscall Phyre_ClusterInstantiate_FixupSizes(_DWORD *this, _DWORD *a2)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 130 basic blocks, cyclomatic 66
    // Callees: Engine_AlignedAllocAlign, memcpy, Phyre_Class_ConstructInterleaved,
    //         Phyre_Class_SerializeBuffer, Phyre_Stream_Printf, Engine_AlignedFree
    // Strings: "Header class '%s' is larger at runtime while fixing up\n",
    //         "Class '%s' is larger at runtime than in the source file\n"
    return 0;
}

// ============================================================================
// RENDERER — THREAD POOL / JOB EXECUTION
// ============================================================================

// Function: Phyre_Renderer_ThreadPoolJob_Execute (0x5b3f90, 1543 bytes)
// Decompiled body:
//   Main render thread pool job execution function.
//   Processes rendering jobs from queue, dispatches draw calls.
//   Uses PThreadPool, scratch buffers, circular buffers.
//   Handles batch jobs, bone transforms, preprocess job allocation.
//   Manages thread synchronization via SpinLock_Release.
//   Large stack frame (~9KB): 0xA entries for batch construction.
int __thiscall Phyre_Renderer_ThreadPoolJob_Execute(
    _DWORD *this, _DWORD *jobQueue, unsigned int jobCount, _DWORD *renderContext)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 67 basic blocks, cyclomatic 40
    // Callees: Phyre_Renderer_DispatchDraw, Phyre_Renderer_BatchJob_Execute,
    //         Phyre_Renderer_UpdateBoneTransform, Phyre_ScratchBuffer_Alloc,
    //         Phyre_Renderer_JobQueue_Pop, Phyre_Renderer_JobQueue_PackEntry,
    //         PThreadPool_GetGlobal_C0B950, Phyre_ThreadPool_GetSingleton,
    //         Engine_AlignedFree, Phyre_SpinLock_Release
    // String: "PRendererThreadPoolJob"
    return 0;
}

// ============================================================================
// ARRAY — SORTING
// ============================================================================

// Function: Phyre_Array_Sort (0x4d4fd0, 1379 bytes)
// Decompiled body:
//   Multi-key array sort for rendering state management.
//   Copies indices from array, sorts via IntrospectiveSort4Byte.
//   Builds permutation table, applies to data arrays.
//   Handles: indexed sort, key extraction, duplicate elimination.
//   Uses: alloca for temp buffers, memcpy/memset for reordering.
//   Calls IntrospectiveSortUInt and IntrospectiveSort4Byte internally.
//
//   Pseudocode (core logic):
//     int *indices = (int *)alloca(count * 4);
//     for (i = 0; i < count; i++) indices[i] = i;
//     // Determine sort key: extract from a1[offset] per-element
//     int *keys = (int *)alloca(count * 4);
//     for (i = 0; i < count; i++) keys[i] = EXTRACT_KEY(a1, i);
//     // Introspective sort on indices using keys as comparator
//     Phyre_Array_IntrospectiveSortUInt(indices, keys, count);
//     // Apply permutation to data array
//     memcpy(tempBuffer, a1, elementSize * count);
//     for (i = 0; i < count; i++) {
//         memcpy(a1 + i * elementSize, tempBuffer + indices[i] * elementSize, elementSize);
//     }
//     // Dedup: eliminate adjacent duplicates after sort
//     int *deduped = (int *)alloca(count * keySize);
//     int dedupCount = 0;
//     for (i = 0; i < count; i++) {
//         if (i == 0 || keys[i] != keys[i-1]) deduped[dedupCount++] = keys[i];
//     }
//     *a2 = dedupCount; // output dedup count
int __stdcall Phyre_Array_Sort(_DWORD *a1, int *a2)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 83 basic blocks, cyclomatic 56
    // Callees: Phyre_Array_IntrospectiveSortUInt, Phyre_Array_IntrospectiveSort4Byte,
    //         Engine_AlignedAllocAlign, Engine_AlignedFree, memcpy, memset, alloca
    return 0;
}

// ============================================================================
// SCENE NODE — TRANSFORM MATH
// ============================================================================

// Function: Phyre_SceneNode_ComposeTransformMath (0x602050, 1183 bytes)
// Decompiled body:
//   Composes the full world matrix for a scene node.
//   Walks parent chain (field 196/200), accumulates transforms.
//   Computes scale vector from local scale^2 via sqrt.
//   Performs: Matrix4x4_ComposeMultiply, Matrix4x4_Inverse,
//   TransposeRotation for inverse bind pose, Matrix4_MulVec4.
//   Handles physics body update and light effect transform.
//
//   Pseudocode (core logic):
//     // Step 1: Compute world matrix from parent chain
//     PNode *node = this;
//     PMatrix4 worldMatrix;
//     Phyre_Matrix4_Identity(&worldMatrix);
//     while (node) {
//         Phyre_Matrix4x4_Mul(&worldMatrix, node->localMatrix, &worldMatrix);
//         node = node->m_parent; // field +0x04
//     }
//     // Step 2: Decompose scale from local matrix
//     //   Sx = sqrt(m[0][0]^2 + m[1][0]^2 + m[2][0]^2)
//     //   Sy = sqrt(m[0][1]^2 + m[1][1]^2 + m[2][1]^2)
//     //   Sz = sqrt(m[0][2]^2 + m[1][2]^2 + m[2][2]^2)
//     // Step 3: Inverse bind pose (TransposeRotation of world rotation)
//     // Step 4: Compute light transform (if light component present)
//     // Step 5: Update physics body transform (if rigid body attached)
//     // Step 6: Store result in this->worldMatrix (field +0x0C)
int __usercall Phyre_SceneNode_ComposeTransformMath(int node@<ecx>)
{
    // TODO: implement
    FFX_LOG_STUB();
    // Callees: Phyre_PSceneNode_composeWorldMatrix_parentChain,
    //         Phyre_Matrix4_Copy, Phyre_Matrix4x4_ComposeMultiply,
    //         Phyre_Matrix4x4_Inverse, Phyre_Matrix4x4_TransposeRotation,
    //         Phyre_SceneNode_SetPhysicsBody, Phyre_LightEffect_ComputeLightTransform
    return 0;
}

// ============================================================================
// CONTAINER — CONSTRUCTOR (RENDER STATE / SHADER CONTAINER)
// ============================================================================

// Function: Phyre_Container_Constructor (0x583710, 1091 bytes)
// Decompiled body:
//   Large (~5KB) container constructor for render state management.
//   Initializes ~80+ fields including:
//   - Two child nodes (container trees at offsets +184 and +300)
//   - Sprite containers (RSpriteContainer at +496 and +524)
//   - 8-element quad tuple array at +552 via vector constructor iterator
//   - Shader parameter set at +680
//   - Binding array at +1392
//   - D3D11 shader pass state at +1772
//   - Sampler state at +4856
//   - Container sub-structure at +916
//   Uses PBVHNode_CollisionCapsule_Constructor as base
int __thiscall Phyre_Container_Constructor(int this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 50 basic blocks, cyclomatic 0 (linear init)
    // Callees: PTexture2D_InitDefaults (x2), Phyre_StructArray7Dword_ZeroInit (x2),
    //         PContainerNode_ctor_child0 (x2), Phyre_RSpriteContainer_Ctor (x2),
    //         Phyre_ShaderParamSet3_Ctor, PShaderPassStateD3D11_ctor, PSamplerState_CxxCtor,
    //         Phyre_Container_InitSubStruct, Phyre_Container_InitBindingArray
    return 0;
}

// ============================================================================
// THREAD POOL — SINGLETON / WORKER THREAD CREATION / LIFECYCLE
// ============================================================================

// Function: PThreadPool_Destructor (0x44CD40, 1 caller)
// Decompiled body:
//   Destroi o thread pool, joinando todas as threads de worker.
//   Percorre array de handles de thread, chama WaitForSingleObject + CloseHandle.
//   Libera fila de jobs pendentes, destroi mutexes e variaveis de condicao.
void __thiscall PThreadPool_Destructor(void *this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 1 basic block, cyclomatic 1
    // Callees: CloseHandle, WaitForSingleObject, Phyre_MutexArray_Destroy
}

// Function: PThreadPool_GetGlobal_C0B950 (0x44CEC0, ~30 xrefs)
// Decompiled body:
//   Retorna ponteiro para o singleton global do PThreadPool em 0xC0B950.
//   Usado pelo renderer e sistemas de job para acessar o pool principal.
void *__stdcall PThreadPool_GetGlobal_C0B950()
{
    // TODO: implement
    FFX_LOG_STUB();
    // Ponteiro global dword_C0B950; se 0, retorna 0 (lazy init externo)
    return 0;
}

// Function: PThreadPool_GetGlobal_C0B95C (0x44CE00, ~15 xrefs)
// Decompiled body:
//   Retorna ponteiro para o singleton global secundario em 0xC0B95C.
//   Usado para pool de IO / background tasks nao-render.
void *__stdcall PThreadPool_GetGlobal_C0B95C()
{
    // TODO: implement
    FFX_LOG_STUB();
    return 0;
}

// Function: PThreadPool_GetMaxThreadCount (0x44C920, ~5 xrefs)
// Decompiled body:
//   Retorna o numero maximo de threads configurado para o pool.
//   Le de campo interno this->maxThreadCount.
int __thiscall PThreadPool_GetMaxThreadCount(void *this)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 1 basic block, accessor
    return 0;
}

// Function: Phyre_ThreadPool_GetSingleton (0x44CE10, ~20 xrefs)
// Decompiled body:
//   Obtem ou cria o singleton PThreadPool.
//   Verifica se o singleton global ja existe; se nao, aloca e constroi.
//   Inicializa fila de jobs, cria threads worker com base na contagem de CPUs.
//   Registra atexit para destruicao ordenada no shutdown.
void *__stdcall Phyre_ThreadPool_GetSingleton()
{
    // TODO: implement
    FFX_LOG_STUB();
    // 0xa3 bytes
    // Callees: Engine_AlignedAllocAlign, Phyre_ThreadPool_LazyInitSingleton,
    //         Phyre_WorkerThread_CreateArray, _atexit
    // Strings: "PThreadPool"
    return 0;
}

// Function: Phyre_ThreadPool_SetStackSize (0x44CED0, 1 caller)
// Decompiled body:
//   Configura o tamanho de stack das threads worker criadas pelo pool.
//   Usado durante inicializacao antes de criar as threads.
void __stdcall Phyre_ThreadPool_SetStackSize(unsigned int stackSize)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 4 instructions — setter simples
    // Global: dword_C0B958 = stackSize
}

// Function: Phyre_ThreadPool_SetMaxCount (0x44CEE0, 1 caller)
// Decompiled body:
//   Configura o numero maximo de threads worker no pool.
void __stdcall Phyre_ThreadPool_SetMaxCount(unsigned int maxCount)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 4 instructions — setter simples
    // Global: dword_C0B954 = maxCount
}

// Function: Phyre_ThreadPool_SetMinCount (0x44CF00, 1 caller)
// Decompiled body:
//   Configura o numero minimo de threads worker no pool.
void __stdcall Phyre_ThreadPool_SetMinCount(unsigned int minCount)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 4 instructions — setter simples
    // Global: dword_C0B950 (tambem usado como min count)
}

// Function: Phyre_WorkerThread_CreateArray (0x44CF50, 1 caller)
// Decompiled body:
//   Cria array de worker threads para o pool.
//   Para cada thread: CreateThread com funcao de entrada (ThreadPool_WorkerMain),
//   prioridade THREAD_PRIORITY_NORMAL, stack size configurado via SetStackSize.
//   Armazena handles em array interno do pool.
//   Se falhar, loga erro e retorna codigo de falha.
int __stdcall Phyre_WorkerThread_CreateArray(void *pool, unsigned int count)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 0x1fd bytes
    // Callees: CreateThread, Phyre_Thread_GetCurrentId, SetThreadPriority
    // Strings: "PhyreWorkerThread"
    return 0;
}

// Function: Phyre_ThreadPool_LazyInitSingleton (0xAF1290, 1 caller)
// Decompiled body:
//   Inicializacao lazy do singleton PThreadPool.
//   Aloca a estrutura principal, inicializa mutex, fila de jobs,
//   e variaveis de sincronizacao (condicao de trabalho, sinal de parada).
void __stdcall Phyre_ThreadPool_LazyInitSingleton(void **outPool)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 0xe bytes (thunk para PThreadPool_Constructor)
    // Callees: PThreadPool_Constructor, Phyre_MutexArray_Init
}

// Function: PClassDescriptorInit_PThreadPool (0x44CDB0, 1 caller)
// Decompiled body:
//   Inicializa o class descriptor para PThreadPool no namespace Phyre.
//   Chama Phyre_PClassDescriptor_ctor com nome "PThreadPool", tamanho,
//   e parent class descriptor. Registra no PhyreNamespace.
void *__stdcall PClassDescriptorInit_PThreadPool()
{
    // TODO: implement
    FFX_LOG_STUB();
    // 0x27 bytes
    // Callees: Phyre_PClassDescriptor_ctor, Phyre_PNamespace_GetSingleton
    // String: "PThreadPool"
    return 0;
}

// Function: Phyre_ThreadPool_SetGlobal_C0B95C (0x44CED0, 1 caller)
// Decompiled body:
//   Armazena o ponteiro do pool secundario no global dword_C0B95C.
//   Usado durante inicializacao do subsistema de IO.
void __stdcall Phyre_ThreadPool_SetGlobal_C0B95C(void *pool)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 4 instructions — setter simples
    // dword_C0B95C = pool
}

// Function: Phyre_Renderer_ThreadPoolJob_Execute (0x5b3f90, 1543 bytes)
// Decompiled body:
//   Main render thread pool job execution function.
//   Processes rendering jobs from queue, dispatches draw calls.
//   Uses PThreadPool, scratch buffers, circular buffers.
//   Handles batch jobs, bone transforms, preprocess job allocation.
//   Manages thread synchronization via SpinLock_Release.
//   Large stack frame (~9KB): 0xA entries for batch construction.
int __thiscall Phyre_Renderer_ThreadPoolJob_Execute(
    void *this, void *jobQueue, unsigned int jobCount, void *renderContext)
{
    // TODO: implement
    FFX_LOG_STUB();
    // 67 basic blocks, cyclomatic 40
    // Callees: Phyre_Renderer_DispatchDraw, Phyre_Renderer_BatchJob_Execute,
    //         Phyre_Renderer_UpdateBoneTransform, Phyre_ScratchBuffer_Alloc,
    //         Phyre_Renderer_JobQueue_Pop, Phyre_Renderer_JobQueue_PackEntry,
    //         PThreadPool_GetGlobal_C0B950, Phyre_ThreadPool_GetSingleton,
    //         Engine_AlignedFree, Phyre_SpinLock_Release
    // String: "PRendererThreadPoolJob"
    return 0;
}

// ============================================================================
// PARRAY — CONSTRUCTION / DESTRUCTION / RESIZE
// ============================================================================

// Phyre_PArray_ConstructFromData (0x4xxxxx)
// Constroi um PArray a partir de dados brutos (ponteiro + contagem)
int __thiscall Phyre_PArray_ConstructFromData(void *this, void *data, int count, int elementSize) { return 0; }

// Phyre_PArray_DestroyElements (0x4xxxxx)
// Invoca destrutores nos elementos do array sem liberar o buffer
void __thiscall Phyre_PArray_DestroyElements(void *this, int startIndex, int count) { }

// Phyre_PArray_Reserve (0x4xxxxx)
// Reserva capacidade no array
int __thiscall Phyre_PArray_Reserve(void *this, int capacity) { return 0; }

// Phyre_PArray_Compact (0x4xxxxx)
// Reduz a capacidade ao numero atual de elementos
int __thiscall Phyre_PArray_Compact(void *this) { return 0; }

// Phyre_PArray_Swap (0x4xxxxx)
// Troca o conteudo entre dois arrays
void __thiscall Phyre_PArray_Swap(void *this, void *other) { }

// ============================================================================
// PSTRING — FORMAT / APPEND / PREPEND
// ============================================================================

// Phyre_PString_Format (0x4xxxxx)
// Formata uma string estilo sprintf
int __thiscall Phyre_PString_Format(void *this, const char *format, ...) { return 0; }

// Phyre_PString_Append (0x4xxxxx)
// Concatena string ao final
int __thiscall Phyre_PString_Append(void *this, const char *text) {
    if (!this || !text) return 0;
    char *str = *(char**)this;
    if (!str) return 0;
    int curLen = (int)strlen(str);
    int addLen = (int)strlen(text);
    memcpy(str + curLen, text, addLen + 1);
    return curLen + addLen;
}

// Phyre_PString_Prepend (0x4xxxxx)
// Insere string no inicio
int __thiscall Phyre_PString_Prepend(void *this, const char *text) {
    if (!this || !text) return 0;
    char *str = *(char**)this;
    if (!str) return 0;
    int curLen = (int)strlen(str);
    int addLen = (int)strlen(text);
    memmove(str + addLen, str, curLen + 1);
    memcpy(str, text, addLen);
    return curLen + addLen;
}

// Phyre_String_Compare (0x4xxxxx)
// Compara duas strings, retorna 0 se igual
int __thiscall Phyre_String_Compare(void *this, const char *other) {
    if (!this || !other) return -1;
    const char *str = *(const char**)this;
    if (!str) return -1;
    return strcmp(str, other);
}

// Phyre_String_CompareLess (0x4xxxxx)
// Compara duas strings para ordenacao, retorna <0 se this < other
int __thiscall Phyre_String_CompareLess(void *this, const char *other) {
    if (!this || !other) return -1;
    const char *str = *(const char**)this;
    if (!str) return -1;
    return strcmp(str, other);
}

// Phyre_String_AppendStr (0x4xxxxx)
// Concatena string ao final (diferenca de PString_Append: aceita substring ou fonte alternativa)
int __thiscall Phyre_String_AppendStr(void *this, const char *text) {
    return Phyre_PString_Append(this, text);
}

// Phyre_String_Insert (0x4xxxxx)
// Insere texto em posicao especifica
int __thiscall Phyre_String_Insert(void *this, unsigned int pos, const char *text) {
    if (!this || !text) return 0;
    char *str = *(char**)this;
    if (!str) return 0;
    int curLen = (int)strlen(str);
    if (pos > (unsigned int)curLen) pos = (unsigned int)curLen;
    int addLen = (int)strlen(text);
    memmove(str + pos + addLen, str + pos, curLen - pos + 1);
    memcpy(str + pos, text, addLen);
    return curLen + addLen;
}

// Phyre_String_Remove (0x4xxxxx)
// Remove range de caracteres
int __thiscall Phyre_String_Remove(void *this, unsigned int pos, unsigned int count) {
    if (!this) return 0;
    char *str = *(char**)this;
    if (!str) return 0;
    int curLen = (int)strlen(str);
    if (pos >= (unsigned int)curLen) return curLen;
    if (pos + count > (unsigned int)curLen) count = (unsigned int)curLen - pos;
    memmove(str + pos, str + pos + count, curLen - pos - count + 1);
    return (int)strlen(str);
}

// Phyre_String_Find (0x4xxxxx)
// Busca substring, retorna indice ou -1 se nao encontrar
int __thiscall Phyre_String_Find(void *this, const char *sub, unsigned int start) {
    if (!this || !sub) return -1;
    const char *str = *(const char**)this;
    if (!str) return -1;
    int len = (int)strlen(str);
    if ((int)start >= len) return -1;
    const char *found = strstr(str + start, sub);
    if (!found) return -1;
    return (int)(found - str);
}

// ============================================================================
// HEAP — BUCKET ALLOC / FREE
// ============================================================================

// Phyre_Heap_BucketAlloc (0x4xxxxx)
// Aloca de um bucket heap por tamanho fixo
void *__thiscall Phyre_Heap_BucketAlloc(void *this, unsigned int size) { return 0; }

// Phyre_Heap_BucketFree (0x4xxxxx)
// Libera bloco alocado via BucketAlloc
int __thiscall Phyre_Heap_BucketFree(void *this, void *ptr) { return 0; }

// Phyre_List_UnlinkNode (0x43b460, 1228 xrefs)
// Generic intrusive doubly-linked list unlink.
void *__stdcall Phyre_List_UnlinkNode(void *listNode)
{
    if (!listNode) return 0;
    int *prev = (int *)((int *)listNode)[1];
    int *next = (int *)((int *)listNode)[2];
    prev[1] = (int)next;
    next[0] = (int)prev;
    ((int *)listNode)[1] = (int)listNode + 4;
    ((int *)listNode)[2] = (int)listNode + 4;
    return (void *)next;
}

// PLinkedList_PopFront (0x575ee0)
// Returns front element of intrusive linked list (offset -4 from data ptr).
// List layout: stored value = data_ptr + 4; actual node = stored_value - 4.
// Returns 0 if list is empty (sentinel self-loop) or null.
int __thiscall PLinkedList_PopFront(int *this, int a2)
{
    int v = *this;
    if (v == a2 || !v) return 0;
    return v - 4;
}

// PLinkedList_DrainAll (0x575a50)
// Pops all entries from the list and unlinks each one.
// The unlink follows the standard prev/next diamond pattern.
int __thiscall PLinkedList_DrainAll(int *this)
{
    int result;
    while (1)
    {
        result = PLinkedList_PopFront(this, (int)this);
        if (!result) break;
        int *prev = (int *)(*(int *)(result + 4));
        int *next = (int *)(*(int *)(result + 8));
        *(int *)((char *)prev + 4) = (int)next;
        *(int *)next = (int)prev;
        *(int *)(result + 4) = result + 4;
        *(int *)(result + 8) = result + 4;
    }
    return result;
}
