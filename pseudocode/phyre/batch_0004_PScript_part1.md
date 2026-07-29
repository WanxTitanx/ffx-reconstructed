# FFX.exe Decompilation — Batch 4 (Phyre_PScript Part 1)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 25 (Phyre_PScripting — core scripting, Lua bridge, scheduler, async processing, components)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the PhyreEngine scripting system: type registration (PScript, PScriptCallbackHandler, PScheduler), component lifecycle (PScriptableComponent, PScriptedComponent, PScriptTriggerComponent, PScriptEntryComponent), the Lua scripting bridge (ReloadScript with lua_pcall), the async process scheduler, and the callback handler system.

## Key Insight: Scripting Architecture

PhyreEngine's scripting system has layered architecture:
1. **PScript** — Base script type (40 bytes)
2. **PScriptableComponent** — Base game component that can have scripts attached
3. **PScriptedComponent** — Component that IS a script (overrides behavior)
4. **PScriptTriggerComponent** — Trigger zone component with entry/exit handlers
5. **PScriptEntryComponent** — Entry point component
6. **PScheduler** — Async scheduler (644 bytes struct) using AlignedLinkedListBlock + PAsyncProcessBuffer
7. **PScriptCallbackHandler** — Named callback dispatch (entry point + handler)

---

## Functions Decompiled

### Core Type Registration

#### Phyre_PScript_RegisterClassDescriptor (0x5d4780, 145 bytes)
```c
void __thiscall Phyre_PScript_RegisterClassDescriptor(
        Vtable_PClassDescriptorAbstract_PClassDescriptor_Phyre ***this)
{
  DefaultPool = Phyre_GetDefaultPool();
  Singleton = Phyre_PNamespace_GetSingleton();
  Phyre_PClassDescriptor_ctor(this, Singleton, "PScript", 40, 4, DefaultPool, 0);
  *(this + 36) |= 2;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PScripting::PScript>::`vftable';
  Phyre_PClassDescriptor_SetField64(..., &val__11);
  Phyre_PClassDescriptor_SetField68(..., &val__12);
  Phyre_PClassDescriptor_SetField6C(..., &val__13);
}
```
- **Callers:** PhyreInit type system (1 direct)
- **Type:** PClassDescriptorAbstract<PScripting::PScript>, size=40, typeID=4, flags|=2
- **Purpose:** Register PScript as a serializable type in the PhyreEngine type system

#### Phyre_PScript_InitInstance (0x5d4870, 69 bytes)
```c
_DWORD *__thiscall Phyre_PScript_InitInstance(_DWORD *this)
{
  this[0..7] = 0;     // 8 DWORDs = 32 bytes
  *((_BYTE *)this + 32) = 0;  // byte at +0x20
  this[9] = 1;        // field at +0x24 = 1 (default valid state)
  return this;
}
```
- **Callers:** Instance factory
- **Purpose:** Initialize a PScript instance — zeros all fields, sets default state to 1
- **Struct layout inference:**
  - +0x00-0x1C: 8 DWORDs (context/state fields)
  - +0x20: byte flag
  - +0x24: DWORD init state (=1)

#### Phyre_PScriptCallbackHandler_RegisterClassDescriptor (0x5d38f0, 145 bytes)
- **Callers:** PhyreInit type system
- **Purpose:** Register PScriptCallbackHandler (size=12, typeID=4). Template: PClassDescriptorAbstract<PScripting::PScriptCallbackHandler>

#### Phyre_PScriptCallbackHandler_RegisterMembers (0x5d3b30, 222 bytes)
```c
void Phyre_PScriptCallbackHandler_RegisterMembers()
{
  Phyre_PTypeDefault_PChar_RegisterName(&Size__115);
  if ( (unk_CBE3B0 & 1) == 0 ) {
    unk_CBE3B0 |= 1;
    Phyre_PClassDataMember_ctorAttach_structural(
      unk_CBE384, &Size__115, &unk_C91048, "m_entryPoint", 0, 0, 0);
    atexit(PClassDataMember_Dtor_dword_CBE384);
  }
  if ( (v0 & 2) == 0 ) {
    unk_CBE3B0 |= 2;
    Phyre_PClassDataMember_ctorAttach_structural(
      unk_CBE3B4, &Size__115, &MEMORY[0xC90F30], "m_handler", 4, 0, 0);
    atexit(PClassDataMember_Dtor_dword_CBE3B4);
  }
  Phyre_PClassDescriptor_FinalizeRegistration(&Size__115);
}
```
- **Callers:** PhyreInit type system
- **Members:** "m_entryPoint"(+0x00), "m_handler"(+0x04)
- **Purpose:** Register serializable data members for PScriptCallbackHandler. Uses guard flags (0xCBE3B0) for one-time init

### Trigger System

#### Phyre_PScriptTriggerComponent_Copy (0x5518d0, 131 bytes)
```c
_DWORD *__thiscall Phyre_PScriptTriggerComponent_Copy(_DWORD *this, _DWORD *a2)
{
  this[0..4] = a2[0..4];     // Copy 5 DWORDs (20 bytes)
  if ( this+5 != a2+5 )
    Phyre_Math_MatrixInverse(this+5, (a2[5] - (a2[5] & 1)));
  this[6] = a2[6];
  this[7] = a2[7];
  if ( this+8 != a2+8 )
    Phyre_Math_MatrixInverse(this+8, (a2[8] - (a2[8] & 1)));
  this[9] = a2[9];
  this[10] = a2[10];
  return this;
}
```
- **Callers:** Phyre_ScriptAccess_TriggerReceiverComp_GetAndCopy
- **Purpose:** Deep copy with matrix inverse — copies 11 DWORDs total, with two optional matrix inverse operations at offsets +5 and +8
- **Key insight:** Matrix inverse for transform data — trigger components store transform matrices

#### Phyre_PScriptTriggerComponent_dtor (0x551a10, 141 bytes)
```c
int *__thiscall Phyre_PScriptTriggerComponent_dtor(int *this, char a2)
{
  if ( (*(_BYTE *)(this + 8) & 1) == 0 )
    Engine_AlignedFree((void *)*(this + 8));
  if ( (*(_BYTE *)(this + 5) & 1) == 0 )
    Engine_AlignedFree((void *)*(this + 5));
  PComponent_UnlinkFromEntityList(this);
  if ( (a2 & 1) != 0 )
    Engine_AlignedFree(this);
  return this;
}
```
- **Callers:** None (vtable entry?)
- **Purpose:** Destructor with AlignedFree on offsets +5 and +8, component unlink, optional self-free

#### Phyre_PScriptTriggerComponent_RegisterClassDescriptors (0x551aa0, 297 bytes)
- **Members:** "m_script"(+12, flags=18), "m_entryHandler"(+20, flags=16), "m_exitHandler"(+28, flags=16)
- **Purpose:** Data member registration for PScriptTriggerComponent (3 serializable fields)
- **Callers:** Phyre_Component_RegisterClassDescriptors

### Scriptable Component System

#### Phyre_PScriptableComponent_Destructor (0x552eb0, 124 bytes)
```c
_DWORD *__thiscall Phyre_PScriptableComponent_Destructor(_DWORD *this, char a2)
{
  *this = &Phyre::PGameplay::PScriptableComponent::`vftable';
  if ( (*(_BYTE *)(this + 4) & 1) == 0 )
    Engine_AlignedFree((void *)*(this + 4));
  PComponent_UnlinkFromEntityList(this + 1);
  if ( (a2 & 1) != 0 )
    Engine_AlignedFree(this);
  return this;
}
```
- **Callers:** Destructor chain
- **Purpose:** Reset vftable, free aligned buffer at +4, unlink from entity list
- **Namespace:** Phyre::PGameplay::PScriptableComponent

#### Phyre_PScriptableComponent_ReloadScript (0x553410, 407 bytes) ⭐
```c
void __thiscall Phyre_PScriptableComponent_ReloadScript(int *this, int obj)
{
  if ( obj )
  {
    Phyre_Stream_Printf(0, "PScriptableComponent::reloadScript %s (for %s)\n", name1, name2);
    if ( *(this + 7) ) {
      // Lua script reload path
      Phyre_NameArray_FindString(array, "onReload", 0);
      Phyre_LuaScript_ExtractModuleName(&obj, char_ptr);
      PhyreStream_PushValueSimple(stream, "onReload");
      // ... lua_pcall error handling ...
      // "execute: lua_pcall failed - error code: %d\n%s\n"
    }
  }
}
```
- **Callers:** 4 data xrefs (string table entries)
- **Callees:** LuaD_funcCallPhyreStream, Phyre_LuaScript_ExtractModuleName, Phyre_NameArray_FindString, Phyre_Scripting_PushObjectToStream, Phyre_Stream_Printf, PhyreBuffer_IsValidValue, PhyreStream_PushValueSimple
- **Strings:** "PScriptableComponent::reloadScript %s (for %s)\n", "execute: lua_pcall failed - error code: %d\n%s\n"
- **Purpose:** Reload a Lua script at runtime — logs reload event, finds "onReload" handler, extracts module name, pushes to stream, executes via lua_pcall
- **Key insight:** This IS the Lua scripting bridge. Scriptable components call lua_pcall with "onReload" callback

#### Phyre_PScriptableComponent_SetMatrixInverse (0x5535b0, 138 bytes)
- **Callers:** 4 data xrefs
- **Callees:** Phyre_NameArray_FindString, Phyre_Math_MatrixInverse
- **Purpose:** Set matrix inverse by name lookup — validates name via NameArray, copies matrix inverse at offset +4. Returns 0 (ok) or 19 (not found)

### Entry Component

#### Phyre_PScriptEntryComponent_RegisterClassDescriptors (0x552f30, 222 bytes)
- **Members:** "m_script"(+20, flags=2), "m_entryPoint"(+16, flags=0)
- **Purpose:** Register data members for PScriptEntryComponent
- **Callers:** Phyre_Component_RegisterClassDescriptors

### Scripted Component

#### Phyre_PScriptedComponent_ctor (0x554770, 143 bytes)
```c
char __stdcall Phyre_PScriptedComponent_ctor(int a1)
{
  if ( a1 ) {
    PScriptableComponent_Init(a1, &MEMORY[0xCAF8D0]);
    *(_DWORD *)a1 = &Phyre::PGameplay::PScriptedComponent::`vftable';
    *(_DWORD *)(a1 + 32) = 0;
    *(_DWORD *)(a1 + 36) = 0;
    *(_DWORD *)(a1 + 20) = 0;
    *(_DWORD *)(a1 + 24) = 0;
    *(_DWORD *)(a1 + 28) = 0;
    *(_DWORD *)(a1 + 40) = 1;      // init state = 1
    *(_WORD *)(a1 + 44) = 0;
    *(_BYTE *)(a1 + 46) = 0;
  }
  return 1;
}
```
- **Purpose:** Constructor for PScriptedComponent — zeroes fields 20-36, sets field 40=1, zeros 44-46
- **Struct size inference:** At least 47 bytes

#### Phyre_PScriptedComponent_CreateDestroy (0x554800, 38 bytes)
- **Purpose:** Thin wrapper — calls virtual function via this-4 with flag=0
- **Key insight:** Indirect virtual call pattern — the actual vtable is at offset -4

#### Phyre_PScriptedComponent_PushToStream (0x554b60, 38 bytes)
```c
int __stdcall Phyre_PScriptedComponent_PushToStream(int a1, int a2)
{
  if ( a2 )  v2 = a2 + 4;
  else       v2 = 0;
  return Phyre_Scripting_PushObjectToStream_V2(a1, v2);
}
```
- **Purpose:** Serialize component to stream — delegates to PushObjectToStream_V2 with stream+4 offset

#### Phyre_PScriptedComponent_BoolGetter_ToStream (0x554720, 77 bytes)
```c
int __thiscall Phyre_PScriptedComponent_BoolGetter_ToStream(int this, _DWORD *a2)
{
  v3 = Phyre_ScriptAccessor_PScriptedComponent_Ptr_Get(a2);
  if ( !v3 ) return 0;
  v4 = (*(int (__thiscall **)(int))(this + 8))(v3 + *(_DWORD *)(this + 12));
  PhyreStream_ReserveGrow(a2, 1);
  PhyreStream_PushBool((int)a2, v4);
  return 1;
}
```
- **Purpose:** Virtual boolean getter serialization — reads a bool via vtable (+8) at a dynamic offset (+12), pushes to stream

### Async Scheduler System

#### Phyre_PScripting_PScheduler_ClassDescriptorInit (0x5cf150, 148 bytes)
- **Type:** PClassDescriptorAbstract<PScripting::PScheduler>, **size=644** (0x284), typeID=4, extraField=4
- **Callees:** Phyre_PNamespace_GetSingleton, Phyre_PClassDescriptor_ctor, Phyre_PClassDescriptor_SetField64/68/6C
- **Purpose:** Register PScheduler type — the **largest** scripting type at 644 bytes

#### Phyre_PScripting_PScheduler_Constructor (0x5cf360, 181 bytes)
```c
char *__thiscall Phyre_PScripting_PScheduler_Constructor(char *this)
{
  *this = &Phyre::PScripting::PScheduler::`vftable';
  AlignedLinkedListBlock_Init(this+4, 32, 100, 4, "PScheduledScript");
  this[7..14] = 0;       // 8 DWORDs zeroed
  Phyre_PAsyncProcessBuffer_ctor(this + 60); // offset 0xF0
  memset(this + 132, 0, 0x200u); // 512 bytes zeroed
  return this;
}
```
- **Callers:** PScheduler_Construct_Array, Scripting_CleanupCallback
- **Purpose:** Construct PScheduler — vftable, init linked list (32-bytes stride, 100 elements, "PScheduledScript"), zero state, init async buffer, memset 512 bytes
- **Struct layout:** Total 644 bytes = 0x284

#### Phyre_PScripting_PScheduler_Destructor (0x5cf5a0, 198 bytes)
```c
int __thiscall Phyre_PScripting_PScheduler_Destructor(int *this)
{
  *this = &Phyre::PScripting::PScheduler::`vftable';
  Phyre_AnimationScheduler_FullCleanup(this);
  Phyre_PScripting_PAsyncProcessBuffer_Destructor(this + 15);
  if ( this[13] >= 0 && this[14] )
    Engine_AlignedFree(this[14]);
  this[14] = 0;  this[13] = 0;
  if ( this[10] >= 0 )
    Phyre_Scheduler_AlignedBuffer_FreeArray(this[11], this[10] & 0x7FFFFFFF);
  this[11] = 0;  this[10] = 0;
  return AlignedLinkedListBlock_FreeAll(this + 1);
}
```
- **Callers:** PScheduler_DeletingDestructor
- **Callees:** AnimationScheduler_FullCleanup, PAsyncProcessBuffer_Destructor, Engine_AlignedFree, Scheduler_AlignedBuffer_FreeArray, AlignedLinkedListBlock_FreeAll
- **Purpose:** Full scheduler teardown — cleanup animations, async buffer, 2 aligned buffers, free linked list blocks

#### Phyre_PScripting_PAsyncProcessBatch_Constructor (0x5ce600, 35 bytes)
```c
_DWORD *__thiscall Phyre_PScripting_PAsyncProcessBatch_Constructor(_DWORD *this)
{
  this[2] = this+1;       // sentinel self-pointer
  this[1] = 0;
  *this = &Phyre::PScripting::PAsyncProcessBatch::`vftable';
  this[3] = 0;
  this[4] = 0;
  return this;
}
```
- **Purpose:** Constructor — linked list sentinel pattern (self-pointer at +1), 20 bytes total
- **Struct:** vfptr(4B) + next(4B) + self-ptr(4B) + data(8B) = 20 bytes

#### Phyre_PScripting_PAsyncProcessBuffer_Destructor (0x5ce6d0, 97 bytes)
- **Callers:** PAsyncProcessBuffer_DeletingDestructor, PScheduler_Destructor
- **Callees:** PAsyncProcessBatch_UnlinkNode
- **Purpose:** Unlink all batch nodes from linked list. Walks node chain unlinking each from the list
- **Struct:** PAsyncProcessBuffer containing: vftable(4B) + linked list of PAsyncProcessBatch nodes

#### Phyre_PScripting_PScheduler_Construct_Array (0x5cfb90, 74 bytes)
- **Callers:** Scheduler array construction
- **Purpose:** Construct an array of PScheduler instances

### Script Memory Allocator

#### Phyre_PScripting_PScriptMemoryAllocatorBase_Ctor (0x61cb60, 7 bytes)
- **Purpose:** Base allocator constructor (7 bytes — minimal)

#### Phyre_PScripting_PScriptMemoryAllocator_Alloc (0x61d020, 188 bytes)
- **Purpose:** Allocate script memory — custom allocator for Lua/script heap usage

#### Phyre_PScripting_ScriptMemoryAlloc (0x61d1f0, 115 bytes)
- **Purpose:** Wrapper for script memory allocation

#### Phyre_PScripting_ScriptMemoryAllocConditional (0x61d270, 30 bytes)
- **Purpose:** Conditional alloc — only allocates if condition is met

---

## Key Findings

### 1. Lua Scripting Bridge
The scripting system directly embeds Lua (`lua_pcall`). `ReloadScript` calls Lua to execute "onReload" callbacks. This confirms PhyreEngine uses Lua for game scripting.

### 2. PScript Struct Hierarchy
| Component | Size | Base | Key Members |
|-----------|------|------|-------------|
| PScript | 40B | - | Script context/state |
| PScriptCallbackHandler | 12B | - | m_entryPoint, m_handler |
| PScriptableComponent | ~48B | PComponent | Script attachment |
| PScriptedComponent | ~47B | PScriptableComponent | Script instance |
| PScriptTriggerComponent | ~44B | PComponent | m_script, m_entryHandler, m_exitHandler |
| PScriptEntryComponent | ~40B | PComponent | m_script, m_entryPoint |
| PScheduler | 644B | - | Linked list, async buffer, animation |

### 3. Scheduler Architecture
- **PScheduler** manages async script processing with AlignedLinkedListBlock (32-byte stride, 100 elements of PScheduledScript)
- **PAsyncProcessBuffer** manages a linked list of batch nodes
- **PAsyncProcessBatch** is a linked list node (20 bytes, sentinel pattern)
- Scheduler cleanup chain: AnimationScheduler_FullCleanup → AsyncBuffer_Destructor → aligned buffer free → LinkedList_FreeAll

### 4. Guard Flag Pattern for One-Time Init
RegisterClassDescriptors functions use global guard flags (e.g., 0xCAF448, 0xCBE3B0) with bit flags:
- Bit 0: m_script registered
- Bit 1: m_entryPoint/m_entryHandler registered  
- Bit 2: m_exitHandler registered
- FinalizeRegistration called at end

This is the same pattern seen in PClassDescriptor_RegisterAll — one-time type system registration guarded by global flag variables.

### 5. Aligned Memory Management
All scripting components use Engine_AlignedFree/AlignedAllocAligned for buffer cleanup. The "bit 0 clear = needs free" pattern (checked via `*(_BYTE *)(ptr) & 1`) is consistent across all destructors.

## Next Batches
- Batch 5: Remaining PScript functions (~129 more — accessors, thunks, accessors for physics/postprocessing/etc)
- Batch 6: Phyre_PType family (~151)
- Batch 7+: PPhysics, PGeometry, PSceneNode
