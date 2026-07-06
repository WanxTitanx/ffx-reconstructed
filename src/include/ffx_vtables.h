// ============================================================================
// FFX.EXE — PhyreEngine Vtable Definitions
// FASE 3-B: Vtable layouts extraidos da analise Hex-Rays do PhyreEngine Core
// Database: jarvis_goal (session 12605b8a)
//
// NOTA: Todos os function pointers usam __thiscall para corresponder a
// convencao de chamada de metodos C++ do MSVC (x86). O primeiro parametro
// de cada metodo recebe o nome _this para evitar conflito com a keyword
// this do C++.
// ============================================================================
#ifndef FFX_VTABLES_H
#define FFX_VTABLES_H

#include "ffx_structs.h"

#include <stddef.h>  // size_t

// ============================================================================
// PCLASSDESCRIPTOR VTABLE — Core type system virtual methods
// 12+ entries based on decompiler output
// ============================================================================
typedef struct Vtable_PClassDescriptor {
    size_t (__thiscall *GetTypeSize)(PhyrePClassDescriptor *_this);         // [0]
    int    (__thiscall *GetClassDescFlags)(PhyrePClassDescriptor *_this);   // [1]
    int    (__thiscall *GetFieldAt2)(PhyrePClassDescriptor *_this);         // [2]
    int    (__thiscall *GetFieldAt3)(PhyrePClassDescriptor *_this);         // [3]
    int    (__thiscall *GetStaticTypePtr)(PhyrePClassDescriptor *_this);    // [4]
    int    (__thiscall *GetTypeId)(PhyrePClassDescriptor *_this);           // [5]
    int    (__thiscall *GetFieldAt6)(PhyrePClassDescriptor *_this);         // [6]
    int    (__thiscall *GetFieldAt7)(PhyrePClassDescriptor *_this);         // [7]
    int    (__thiscall *GetFieldAt8)(PhyrePClassDescriptor *_this);         // [8]
    int    (__thiscall *GetFieldAt9)(PhyrePClassDescriptor *_this);         // [9]
    int    (__thiscall *Serialize)(PhyrePClassDescriptor *_this);           // [10]
    int    (__thiscall *ConstructDefault)(PhyrePClassDescriptor *_this);    // [11] — index 12 in vtable
    int    (__thiscall *GetOrInit)(PhyrePClassDescriptor *_this);           // [12]
    int    (__thiscall *GetFieldAt13)(PhyrePClassDescriptor *_this);        // [13]
    int    (__thiscall *GetFieldAt14)(PhyrePClassDescriptor *_this);        // [14]
    int    (__thiscall *Clone)(PhyrePClassDescriptor *_this);               // [15]
    int    (__thiscall *Destroy)(PhyrePClassDescriptor *_this, int flag);   // [16]
} Vtable_PClassDescriptor;

// ============================================================================
// PCLASSMEMBER VTABLE
// ============================================================================
typedef struct Vtable_PClassMember {
    int (__thiscall *GetTypeSize)(PhyrePClassMember *_this);                // [0]
    int (__thiscall *GetTypeName)(PhyrePClassMember *_this);                // [1]
    int (__thiscall *GetFieldAt2)(PhyrePClassMember *_this);                // [2]
    int (__thiscall *GetFieldAt3)(PhyrePClassMember *_this);                // [3]
    int (__thiscall *GetDefaultValue)(PhyrePClassMember *_this);            // [4]
    int (__thiscall *Serialize)(PhyrePClassMember *_this);                  // [5]
} Vtable_PClassMember;

// ============================================================================
// PCLASSMEMBER TYPEINFO VTABLE — Method caller implementations
// Each scripting method has a PMethodCallerConcrete vtable
// ============================================================================
typedef struct Vtable_PMethodCaller {
    int (__thiscall *Call0)(void *_this);                                   // [0] — 0-arg call
    int (__thiscall *Call1)(void *_this, void *arg1);                       // [1] — 1-arg call
    int (__thiscall *GetArgCount)(void *_this);                             // [2]
    int (__thiscall *GetReturnType)(void *_this);                           // [3]
    int (__thiscall *GetName)(void *_this);                                 // [4]
} Vtable_PMethodCaller;

// ============================================================================
// ENTITY VTABLE
// ============================================================================
typedef struct Vtable_PEntity {
    int (__thiscall *GetTypeSize)(PhyrePEntity *_this);                     // [0]
    int (__thiscall *GetClassDescFlags)(PhyrePEntity *_this);               // [1]
    int (__thiscall *GetComponent)(PhyrePEntity *_this, int classDesc);     // [2]
    int (__thiscall *AddComponent)(PhyrePEntity *_this, int component);     // [3]
    int (__thiscall *RemoveComponent)(PhyrePEntity *_this, int comp);       // [4]
    int (__thiscall *GetWorldMatrix)(PhyrePEntity *_this);                  // [5]
    void (__thiscall *SetWorldMatrix)(PhyrePEntity *_this, int *mat);       // [6]
} Vtable_PEntity;

// ============================================================================
// STRING NODE — Used by scripting method registration
// ============================================================================
typedef struct PhyreStringNode {
    int *vfptr;                 // 0x00 — PStringNode vtable
    int prev;                   // 0x04
    int next;                   // 0x08
    const char *text;           // 0x0C — string content
} PhyreStringNode;

// ============================================================================
// PWORLD MATRIX
// ============================================================================
typedef struct PhyrePWorldMatrix {
    int *vfptr;                 // 0x00
    float m[4][4];              // 0x04 — 4x4 transform matrix (64 bytes)
} PhyrePWorldMatrix;

#endif // FFX_VTABLES_H
