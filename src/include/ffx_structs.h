// ============================================================================
// FFX.EXE — PhyreEngine Type/Struct Definitions
// FASE 3-B: Struct definitions extraidas da analise Hex-Rays do PhyreEngine Core
// Database: jarvis_goal (session 12605b8a)
// ============================================================================
#ifndef FFX_STRUCTS_H
#define FFX_STRUCTS_H

#include <stdint.h>
#include <stdbool.h>

// ============================================================================
// PRIMITIVE ALIASES (matching IDA _DWORD / _BYTE / _WORD conventions)
// ============================================================================
typedef uint32_t    dword;
typedef uint8_t     byte;
typedef uint16_t    word;
typedef uint32_t    _DWORD;
typedef uint8_t     _BYTE;
typedef uint16_t    _WORD;
typedef uint32_t    _BOOL;

// ============================================================================
// PCLASSDESCRIPTOR — Core type system descriptor (0x94 bytes / 37 dwords)
// Layout confirmed from Phyre_PClassDescriptor_ctor (0x43b190) decompilation
//
// Sentinel-linked-lists: each pair (fieldN, fieldN+4) forms a circular
// doubly-linked list where each entry is 8 bytes (2 dwords: next, prev).
// When empty, both point to &fieldN (self-loop).
// When populated, they point to the first/last entry in the list.
// ============================================================================
typedef struct PhyrePClassDescriptor {
    int *vfptr;             // 0x00
    int m_namespaceList;    // 0x04
    int m_namespaceListPrev; // 0x08
    int m_nameString;       // 0x0C
    int m_pClassDescriptor; // 0x10
    int m_pBaseClass;       // 0x14
    const char *m_pClassName; // 0x18
    int m_typeSize;         // 0x1C
    int m_totalSize;        // 0x20
    int m_alignSize;        // 0x24
    int m_classVersion;     // 0x28
    int m_propListHead;     // 0x2C
    int m_pSerializer;      // 0x30
    int m_linkedListHead2;  // 0x34
    int m_flags2;           // 0x38
    int m_pNamespace;       // 0x3C
    int m_pParentCD;        // 0x40
    int m_propertyList;     // 0x44
    int m_propertyCount;    // 0x48
    int linkedList;         // 0x4C
    int m_linkedListTail;   // 0x50
    int m_memberListHead;   // 0x54
    int m_memberListTail;   // 0x58
    int m_propertyListV2;   // 0x5C
    int m_propListV2Count;  // 0x60
    int m_pInstanceData;    // 0x64
    int m_pInitData;        // 0x68
    int m_pTypeTable;       // 0x6C
    int m_cachedTotalSize;  // 0x70
    int m_pDefaultValue;    // 0x74
    int m_pDefaultValue2;   // 0x78
    int m_refCount;         // 0x7C
    int m_regState;         // 0x80
    int m_flags;            // 0x84
    int m_propCapacity;     // 0x88
    int m_propCount;        // 0x8C
    int m_padding;          // 0x90
} PhyrePClassDescriptor;

// ============================================================================
// PCAMERA — Camera with view + projection matrices (208 bytes)
// Layout inferred from decompile of:
//   - PCameraOrthographic_Constructor (0x455c00)
//   - PCameraProjection_InitIdentity (0x454a30)
//   - PCameraOrthographic_UpdateProjectionMatrix (0x4560b0)
//   - Phyre_Camera_ComputeProjectionMatrix (0x454330)
//   - PCamera_SetFieldX/Y/Z (0x454ee0, 0x454f00, 0x454f20)
//   - PCamera_SetField3 (0x452870)
//   - PCameraOrthographic_SetAspectRatio (0x456010)
// Init values from Phyre_ViewMatrix_InitIdentity:
//   view = identity 3x4, projection = identity 4x4,
//   viewProjection = identity 4x4, near=0.1, far=10000.0
// ============================================================================
typedef struct PhyrePCamera {
    void *vfptr;                       // 0x00 — vtable
    float mViewMatrix[12];             // 0x04-0x33 — affine 3x4 view matrix
    float mProjectionMatrix[16];       // 0x34-0x73 — 4x4 projection matrix
    float mViewProjectionMatrix[16];   // 0x74-0xB3 — 4x4 view*projection result
    int m_flags;                       // 0xB4 — integer flags (DWORD)
    float m_nearPlane;                 // 0xB8 — near clip plane (default 0.1)
    float m_farPlane;                  // 0xBC — far clip plane (default 10000.0)
    float m_fieldC0;                   // 0xC0 — reserved/unknown
    float m_fieldC4;                   // 0xC4 — reserved/unknown
    float m_fieldC8;                   // 0xC8 — reserved/unknown
    float m_fieldCC;                   // 0xCC — reserved/unknown
} PhyrePCamera;

// ============================================================================
// PCLASS MEMBER — Single class data member (20 bytes)
// Layout confirmed from Phyre_PClassMember_InitSingleton (0x43a050)
// ============================================================================
typedef struct PhyrePClassMember {
    int *vfptr;         // 0x00 — vtable
    int field4;         // 0x04
    int field8;         // 0x08
    int fieldC;         // 0x0C — name string
    int field10;        // 0x10
    int field14;        // 0x14
    int field18;        // 0x18
    int field1C;        // 0x1C — offset/type info
} PhyrePClassMember;

// ============================================================================
// PARRAY<unsigned char,1> — Byte array with class descriptor (8 bytes)
// ============================================================================
typedef struct PhyrePArrayU8 {
    int capacity_mask;  // 0x00 — capacity (bit 31 = flag)
    byte *data;         // 0x04 — pointer to data
} PhyrePArrayU8;

// ============================================================================
// PARRAY<PTypedObject,4> — Typed object array with 4-element inline storage
// ============================================================================
typedef struct PhyrePArrayPTypedObject {
    int capacity;       // 0x00 — capacity | flags
    dword *data;        // 0x04 — data pointer
    // inline storage: 4 * 8 = 32 bytes (4 pairs of ptr+type)
} PhyrePArrayPTypedObject;

// ============================================================================
// MEMORY POOL — Buddy allocator (size varies by class count)
// Layout from Phyre_MemoryPool_Alloc (0x6eb680)
// ============================================================================
typedef struct PhyreMemoryPool {
    // 00: lock / flags
    // 04: region base
    // 08: region size
    // 0C: allocated counter
    // 10: free counter
    // 14: per-size-class free tree roots (index 0..30 at offset 0x4C + index*4)
    // Large blocks: AVL tree at offset 0x4C + 31*4 = 0xC8
    dword header[19];       // 0x00-0x4B
    dword sizeClassRoots[32];// 0x4C-0xCB — binary tree roots for 32 size classes
    // ... inline free lists follow
} PhyreMemoryPool;

// ============================================================================
// CONTAINER — Render state / shader container (~5KB)
// Layout from Phyre_Container_Constructor (0x583710)
// ============================================================================
typedef struct PhyreContainer {
    dword data[1280];       // ~5KB, many sub-structs
} PhyreContainer;

// ============================================================================
// ENGINE ALIASES
// ============================================================================
typedef void (*Engine_AlignedFree_fn)(void *ptr);

// ============================================================================
// ZLIB INFLATE STATE — Compression context
// From Phyre_ZlibInflate (0x406230)
// ============================================================================
typedef struct PhyreZlibState {
    byte *next_in;          // 0x00 — next input byte
    int avail_in;           // 0x04 — number of bytes available at next_in
    int total_in;           // 0x08 — total nb of input bytes read so far
    byte *next_out;         // 0x0C — next output byte
    int avail_out;          // 0x10 — remaining free space at next_out
    int total_out;          // 0x14 — total nb of bytes output so far
    int state;              // 0x18 — FSM state (0..30)
    int flags;              // 0x1C — header/block flags
    // Huffman tables and window buffer follow
    byte window[0x4000];    // 16KB sliding window
    dword huffmanFixedLit[288];   // fixed literal/length table
    dword huffmanFixedDist[32];   // fixed distance table
    dword huffmanDynLit[288];     // dynamic literal/length table
    dword huffmanDynDist[32];     // dynamic distance table
} PhyreZlibState;

// ============================================================================
// PENTITY — Scene entity (RBTree node, NOT a component container)
// 28 bytes, 7 fields. Components are separate objects linked via RBTree.
// ============================================================================
typedef struct PhyrePEntity {
    int *vfptr;              // 0x00 — vtable
    int *m_pEntityList;      // 0x04 — PEntityList pointer (doubly linked list)
    int m_rbLeft;            // 0x08 — RBTree left child
    int m_rbRight;           // 0x0C — RBTree right child
    int m_rbParent;          // 0x10 — RBTree parent
    void *m_rbKey;           // 0x14 — RBTree key (class descriptor ptr)
    void *m_rbSelfRef;       // 0x18 — RBTree self reference
} PhyrePEntity;

// ============================================================================
// PINSTANCESCOMPONENT — Object instance management (20 bytes, 4 campos)
// ============================================================================
typedef struct PhyrePInstancesComponent {
    int *vfptr;                     // 0x00 — vtable
    int m_field4;                   // 0x04 — flags/int
    int m_field8;                   // 0x08 — count/pointer
    PhyrePArrayPTypedObject m_instances;  // 0x0C — instance array (managed ptrs)
} PhyrePInstancesComponent;

// ============================================================================
// FFXMENU2DCONTEXT — Menu 2D context (global at 0xCCC838)
// Extracted from sub_684E70 dispatch table (15 texture slots, 0x88-0xE0)
// Each slot holds a pointer to a FFXMenu2DTextureSlot
// ============================================================================

// FFXMenu2DBatch — Vertex/index batch for 2D quad rendering
// Referenced at [slot+0x94], used by sub_63EAE0 (menu2d texture draw)
typedef struct FFXMenu2DBatch {
    int state;              // 0x00 — 0=empty, 1=active
    int vertexCount;        // 0x04 — number of vertices queued
    int indexCount;         // 0x08 — number of indices queued
    float *vertexBuffer;    // 0x0C — packed vertex buffer (x,y,z,w per vertex)
    float *colorBuffer;     // 0x10 — color buffer (r,g,b,a per vertex)
    float *uvBuffer;        // 0x14 — UV buffer (u,v per vertex)
    float *alphaBuffer;     // 0x18 — alpha/1D buffer
    word *indexBuffer;      // 0x1C — 16-bit index buffer
    const char *textureName; // 0x20 — texture name string for this batch
    int field24;            // 0x24
    float scaleX;           // 0x28 — horizontal scale factor
    float scaleY;           // 0x2C — vertical scale factor
    int accumulatedVertex;  // 0x30 — accumulated vertex count (after flush)
    int accumulatedIndex;   // 0x34 — accumulated index count (after flush)
} FFXMenu2DBatch;

// FFXMenu2DTextureSlot — Per-texture-type slot (one of 15 in context)
// Contains batch pointer + per-texture rendering state
typedef struct FFXMenu2DTextureSlot {
    int slotFlags;              // 0x00 — slot state/type flags
    int m_vertexCount;          // 0x04 — number of vertices
    int m_indexCount;           // 0x08 — number of indices
    float *m_pPositions;        // 0x0C — position buffer
    float *m_pNormals;          // 0x10 — normal buffer
    float *m_pColors;           // 0x14 — color buffer
    float *m_pUvs;              // 0x18 — UV buffer
    word *m_pIndices;           // 0x1C — 16-bit index buffer
    const char *slotName;       // 0x20 — texture group name
    int m_vertexOffsetBase;     // 0x24 — base vertex offset
    float field28;              // 0x28
    float field2C;              // 0x2C
    float field30;              // 0x30
    float field34;              // 0x34
    float field38;              // 0x38
    float field3C;              // 0x3C
    float field40;              // 0x40
    float field44;              // 0x44
    float field48;              // 0x48
    float field4C;              // 0x4C
    float field50;              // 0x50
    float field54;              // 0x54
    float field58;              // 0x58
    float field5C;              // 0x5C
    float field60;              // 0x60
    float field64;              // 0x64
    float field68;              // 0x68
    float field6C;              // 0x6C — sub-texture offset (face, icon, etc.)
    float field70;              // 0x70
    float field74;              // 0x74
    float *m_pWritePositions;   // 0x78 — write pointer into position buffer
    float *m_pWriteNormals;     // 0x7C — write pointer into normal buffer
    float *m_pWriteColors;      // 0x80 — write pointer into color buffer
    float *m_pWriteUvs;         // 0x84 — write pointer into UV buffer
    word *m_pWriteIndices;      // 0x88 — write pointer into index buffer
    float field8C;              // 0x8C
    FFXMenu2DBatch *batch;      // 0x90 — pointer to batch for this texture slot
} FFXMenu2DTextureSlot;

// FFXMenu2DContext — Main 2D menu context (0xCCC838)
// Contains dispatch table: sub_684E70 returns [this+offset] for a given
// texture type enum (0..14). Each returned pointer is a FFXMenu2DTextureSlot.
// Singleton global at 0xCCC838.
typedef struct FFXMenu2DContext {
    int *vfptr;                     // 0x00 — vtable
    int highResFlag;                // 0x04 — 0=low-res, >0=high-res
    int modifierCount;              // 0x08 — modifier stack depth
    int m_captureState;             // 0x0C — capture state flag
    void *m_pGeomSlot0;             // 0x10 — geometry slot 0
    void *m_pTexDesc0;              // 0x14 — texture descriptor 0
    void *m_pGeomSlot1;             // 0x18 — geometry slot 1
    void *m_pTexDesc1;              // 0x1C — texture descriptor 1
    void *m_pGeomSlot2;             // 0x20 — geometry slot 2
    void *m_pTexDesc2;              // 0x24 — texture descriptor 2
    void *m_pGeomSlot3;             // 0x28 — geometry slot 3
    void *m_pTexDesc3;              // 0x2C — texture descriptor 3
    void *m_pGeomSlot4;             // 0x30 — geometry slot 4
    void *m_pTexDesc4;              // 0x34 — texture descriptor 4
    void *m_pGeomSlot5;             // 0x38 — geometry slot 5
    void *m_pTexDesc5;              // 0x3C — texture descriptor 5
    void *m_pGeomSlot6;             // 0x40 — geometry slot 6
    void *m_pTexDesc6;              // 0x44 — texture descriptor 6
    void *m_pGeomSlot7;             // 0x48 — geometry slot 7
    void *m_pTexDesc7;              // 0x4C — texture descriptor 7
    void *m_pGeomSlot8;             // 0x50 — geometry slot 8
    void *m_pTexDesc8;              // 0x54 — texture descriptor 8
    void *m_pGeomSlot9;             // 0x58 — geometry slot 9
    void *m_pTexDesc9;              // 0x5C — texture descriptor 9
    void *m_pGeomSlot10;            // 0x60 — geometry slot 10
    void *m_pTexDesc10;             // 0x64 — texture descriptor 10
    void *m_pGeomSlot11;            // 0x68 — geometry slot 11
    void *m_pTexDesc11;             // 0x6C — texture descriptor 11
    void *m_pGeomSlot12;            // 0x70 — geometry slot 12
    void *m_pTexDesc12;             // 0x74 — texture descriptor 12
    void *m_pGeomSlot13;            // 0x78 — geometry slot 13
    void *m_pTexDesc13;             // 0x7C — texture descriptor 13
    void *m_pGeomSlot14;            // 0x80 — geometry slot 14
    void *m_pTexDesc14;             // 0x84 — texture descriptor 14

    // --- Texture slot dispatch table (15 entries, sub_684E70 cases 0-14) ---
    // sub_684E70(this, Str, n6) returns [this + offset_table[n6]]
    // Each entry points to a FFXMenu2DTextureSlot
    FFXMenu2DTextureSlot *texSlot0;    // 0x88 — case 0: default
    FFXMenu2DTextureSlot *texSlot1;    // 0x8C — case 1
    FFXMenu2DTextureSlot *texSlot2;    // 0x90 — case 2
    FFXMenu2DTextureSlot *texSlot3;    // 0x94 — case 3: most common (mes/face/icon)
    FFXMenu2DTextureSlot *texSlot4_low; // 0x98 — case 4, low-res
    FFXMenu2DTextureSlot *texSlot5_low; // 0x9C — case 13, low-res
    FFXMenu2DTextureSlot *texSlot6_low; // 0xA0 — case 5, low-res
    FFXMenu2DTextureSlot *texSlot7_low; // 0xA4 — case 6/11, low-res, no pad
    FFXMenu2DTextureSlot *texSlot8_low; // 0xA8 — case 14, low-res
    FFXMenu2DTextureSlot *texSlot9_pad; // 0xAC — case 6/11, low-res, pad icon
    FFXMenu2DTextureSlot *texSlot4_hi;  // 0xB0 — case 4, high-res
    FFXMenu2DTextureSlot *texSlot5_hi;  // 0xB4 — case 13, high-res
    FFXMenu2DTextureSlot *texSlot6_hi;  // 0xB8 — case 5, high-res
    FFXMenu2DTextureSlot *texSlot7_hi;  // 0xBC — case 6/11, high-res, no pad
    FFXMenu2DTextureSlot *texSlot8_hi;  // 0xC0 — case 14, high-res
    FFXMenu2DTextureSlot *texSlot10_pad_hi; // 0xC4 — case 6/11, high-res, pad icon
    FFXMenu2DTextureSlot *texSlot7;     // 0xC8 — case 7
    FFXMenu2DTextureSlot *texSlot8;     // 0xCC — case 8
    FFXMenu2DTextureSlot *texSlot9_low; // 0xD0 — case 9, low-res (mod <= 0)
    FFXMenu2DTextureSlot *texSlot12_low; // 0xD4 — case 12, low-res (mod <= 0)
    FFXMenu2DTextureSlot *texSlot9_hi;  // 0xD8 — case 9, high-res (mod > 0)
    FFXMenu2DTextureSlot *texSlot12_hi; // 0xDC — case 12, high-res (mod > 0)
    FFXMenu2DTextureSlot *texSlot10;    // 0xE0 — case 10
} FFXMenu2DContext;

// ============================================================================
// PHYREPRENDERER — PhyreEngine Renderer base class
// Vtable: Phyre::PRendering::PRendererBase at 0xb363e0
// Derived: Phyre::PRendering::PRenderer at 0xb36400
// Phyre::PRendering::PRendererForJobs at 0xb363f0
// Layout inferred from vtable RTTI and function signatures
// ============================================================================
typedef struct PhyrePRendererBase {
    int *vfptr;                     // 0x00 — vtable (PRendererBase)
    int m_nRendererFlags;           // 0x04 — renderer capability flags
    int m_nFenceCount;              // 0x08 — number of GPU fences
    int fieldC;                     // 0x0C
    int m_nDisplayWidth;            // 0x10 — display width in pixels
    int m_nDisplayHeight;           // 0x14 — display height in pixels
    void *m_pInputAxisConfig;       // 0x18 — input axis configuration

    // --- Pending job queue (circular buffer, 5 ints) ---
    int m_pendingJobQueue[5];       // 0x1C-0x2C — pending job queue entries

    // --- Completion queue (circular buffer, 5 ints) ---
    int m_completionQueue[5];       // 0x30-0x40 — completed job queue entries

    // --- Job system and render state ---
    void *m_hJobSpinlock;           // 0x44 — job spinlock handle
    int m_nJobKey;                  // 0x48 — job key identifier
    int m_nJobParam0;               // 0x4C — job parameter 0
    int m_nJobParam1;               // 0x50 — job parameter 1
    void *m_pGlobalRenderTarget;    // 0x54 — global render target
    int m_nUnknown58;               // 0x58
    int m_nUnknown5C;               // 0x5C
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
} PhyrePRendererBase;

// PhyrePRenderer — Derived renderer (adds job system fields)
typedef struct PhyrePRenderer {
    PhyrePRendererBase base;        // 0x00-0xA3 — inherited fields
    int fieldA4;                    // 0xA4
    int fieldA8;                    // 0xA8
    int fieldAC;                    // 0xAC
    int fieldB0;                    // 0xB0
    int fieldB4;                    // 0xB4
    int fieldB8;                    // 0xB8
} PhyrePRenderer;

// ============================================================================
// PHYREPINPUTFAMILY — Input system types
// Namespace: Phyre::PFramework
// Classes: PInputMapper, PInputDevice, PInputAction, PInputSource, PInputMap
// Extracted from string RTTI refs and stub function signatures
// ============================================================================

// PInputSource — Individual input source (key, button, axis, motion sensor)
// Size varies by source type (key ~8 bytes, axis ~12 bytes)
// Types: PInputSourceKey, PInputSourceJoypadButton, PInputSourceJoypadAxis,
//        PInputSourceMouseButton, PInputSourceMouseDeltaX/Y,
//        PInputSourceTouchDragX/Y/Pinch/Rotate/TwoFinger,
//        PInputSourceMotionQuatX/Y/Z/W/LinearAccelX/Y/Z
typedef struct PhyrePInputSource {
    int *vfptr;                     // 0x00 — vtable (per source type)
    int *m_pTypeSlot;               // 0x04 — type slot pointer
    int *m_pTypeSemantic;           // 0x08 — type semantic pointer
    int m_nId;                      // 0x0C — source identifier
    int m_bInvert;                  // 0x10 — invert flag (0 or 1)
    float m_fScale;                 // 0x14 — scale factor
    int m_nCachedValueA;            // 0x18 — cached value A
    int m_nCachedValueB;            // 0x1C — cached value B
} PhyrePInputSource;

// PInputAction — A named input action bound to source(s)
// Maintains sorted list of sources by priority
typedef struct PhyrePInputAction {
    int *vfptr;                     // 0x00 — vtable
    char *m_pActionName;            // 0x04 — pointer to action name string (NOT int actionId!)
    int m_field8;                   // 0x08
    int *m_pLookupTable;            // 0x0C — lookup table pointer
} PhyrePInputAction;

// PInputMap — Named map/context for a set of input actions
// Each map has a name and sorted list of actions
// NOTE: This is NOT a class with its own fields — it is a PArray<PInputAction*> inline.
// Total size: 8 bytes.
typedef struct PhyrePInputMap {
    int m_nCount;                   // 0x00 — element count
    PhyrePInputAction **m_pActions; // 0x04 — pointer to action array
} PhyrePInputMap;

// PInputDevice — Physical/virtual input device (keyboard, mouse, controller)
// First 0x18 bytes are common header (linked list + device handle).
// Rest varies by derived type:
//   Keyboard  = ~792 bytes
//   Mouse     = ~283 bytes
//   Pad       = ~964 bytes
//   Touch     = complex (multi-touch state)
typedef struct PhyrePInputDevice {
    int *vfptr;                     // 0x00 — vtable
    int *m_pListPrev;               // 0x04 — linked list prev (PSimpleDoubleListElement<VPInputDevice>)
    int *m_pListNext;               // 0x08 — linked list next
    int *m_pListPrev2;              // 0x0C — second intrusive list prev
    int *m_pListNext2;              // 0x10 — second intrusive list next
    void *m_pDeviceHandle;          // 0x14 — IDirectInputDevice8* or XInput index
    int m_stateBuffer[0];           // 0x18+ — derived-class specific state buffer
} PhyrePInputDevice;

// PInputMapper — Input system singleton/mapper
// Manages maps, devices, and action dispatch
// Total size: 0xB8 (184 bytes)
typedef struct PhyrePInputMapper {
    int *vfptr;                     // 0x00 — vtable
    PhyrePInputDevice **devices;    // 0x04 — array of registered devices
    int deviceCount;                // 0x08 — number of devices
    int deviceCapacity;             // 0x0C — capacity
    PhyrePInputMap **maps;          // 0x10 — array of named maps
    int mapCount;                   // 0x14 — number of maps
    int mapCapacity;                // 0x18 — capacity
    int activeMap;                  // 0x1C — currently active map index
    int field20;                    // 0x20
    int field24;                    // 0x24
    int field28;                    // 0x28 — callback / subscriber list
    int field2C;                    // 0x2C
    int field30;                    // 0x30
    int field34;                    // 0x34
    int field38;                    // 0x38
    int field3C;                    // 0x3C
    int field40;                    // 0x40
    int field44;                    // 0x44
    int field48;                    // 0x48
    int field4C;                    // 0x4C
    int field50;                    // 0x50
    int field54;                    // 0x54
    int field58;                    // 0x58
    int field5C;                    // 0x5C
    int field60;                    // 0x60
    int field64;                    // 0x64
    int field68;                    // 0x68
    int field6C;                    // 0x6C
    int field70;                    // 0x70
    int field74;                    // 0x74
    int field78;                    // 0x78
    int field7C;                    // 0x7C
    int field80;                    // 0x80
    int field84;                    // 0x84
    int field88;                    // 0x88
    int field8C;                    // 0x8C
    int field90;                    // 0x90
    int field94;                    // 0x94
    int field98;                    // 0x98
    int field9C;                    // 0x9C
    int fieldA0;                    // 0xA0
    int fieldA4;                    // 0xA4
    int fieldA8;                    // 0xA8
    int m_nMouseX;                  // 0xAC — mouse X position
    int m_nMouseY;                  // 0xB0 — mouse Y position
} PhyrePInputMapper;

// ============================================================================
// PHRYEPAPPLICATION — Application singleton
// ~6 campos from docs. Manages lifecycle, input, rendering, viewports.
// Inferred from sub_622210 (script registry) and Phyre::PFramework::PApplication
// ============================================================================
typedef struct PhyrePApplication {
    int *vfptr;                     // 0x00 — vtable
    int field4;                     // 0x04
    int field8;                     // 0x08 — world pointer?
    int fieldC;                     // 0x0C
    int field10;                    // 0x10
    int field14;                    // 0x14
    int field18;                    // 0x18
    int field1C;                    // 0x1C
} PhyrePApplication;

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================
typedef struct PhyreMatrix4 PhyreMatrix4;   // 4x4 matrix, 64 bytes
struct struct_GUID;                         // GUID structure (used in DirectInput)
// GUID is defined by Windows SDK (guiddef.h) - do not redefine

#endif // FFX_STRUCTS_H
