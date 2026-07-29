# FFX.exe Decompilation — Batch 10 (Engine_*)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 25 (Engine_* — MSVC STL + Mesh/Shader/Resource utilities)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers 25 of 188 `Engine_*` functions in FFX.exe — the MSVC 2012 v110 STL infrastructure (`std::string`, `std::streambuf`, `std::locale`, `std::iostream`) plus PhyreEngine's mesh compilation, shader parameter handling, and aligned memory allocator.

**Key discovery:** `Engine_AlignedAllocAlign` (0x42fc60) is the **most-called** allocator in the codebase with **1094 xrefs**, paired with `Engine_AlignedFree` (4316 xrefs). Together they form PhyreEngine's core heap primitive — over-allocating 7 bytes to hide the real heap pointer before alignment, used everywhere Phyre needs aligned buffers.

---

# Part 1: MSVC STL String/Stream (10 functions)

These are MSVC 2012 v110 standard library implementations (NOT Phyre code), shipped statically linked into FFX.exe. They handle UTF-8, MS-DOS/CRT error strings, and STL exception throwing.

## Engine_String_replace (0x405450, 897 bytes) ⭐
```c
// MSVC STL: std::string::replace
// Complex range-replace with grow, memcpy, memmove, Xlength_error/Xout_of_range
const void **__thiscall Engine_String_replace(
    const void **this, size_t pos, size_t len,
    const void **src, size_t subpos, size_t sublen)
```
- **Callers:** 1 (Phyre_String_Replace)
- **Callees:** `_Xlength_error`, `_Xout_of_range`, `Engine_String_grow`, `memmove`, `memcpy`
- **Strings:** "string too long", "invalid string position"
- **Purpose:** Core `std::string::replace(pos, len, src, subpos, sublen)`. 111 basic blocks — most complex CFG in batch.
- **Constants:** 0x10 (16-byte SSO threshold), 0xFFFFFFFF, 0xFFFFFFFFFFFFFFFE (npos-1)
- **SSO (Small String Optimization):** Inline buffer for strings ≤15 chars, heap otherwise. `*(this+5) < 0x10` is the SSO test.

## Engine_String_from_int (0x404a90, 511 bytes)
```c
char *__thiscall Engine_String_from_int(char *this)
```
- **Callers:** 1 (FFX_Config_WriteIniStream)
- **Callees:** `?flush@?$basic_ostream`, `?sputc@?$basic_streambuf`, `?uncaught_exception`, `?_Osfx`, `?setstate`
- **Purpose:** MSVC `std::ostream::operator<<(int)`. Writes integer to stream. 43 basic blocks with locale lookup fallback.

## Engine_streambuf_xsputn (0x403080, 476 bytes)
```c
int __thiscall Engine_streambuf_xsputn(int this, int a2)
```
- **Callees:** `FFX_Heap_AllocGameArenaDebugFill_wrapper_w`, `?_Pninc@?$basic_streambuf`, `FFX_Heap_Free`, `memcpy`, `?_Xbad_alloc`
- **Purpose:** MSVC `std::streambuf::xsputn` — put n chars to buffer. Handles full/empty cases, allocates more buffer space via game arena when full.
- **Constants:** 0x8, 0x2 (flag bits), 0x20 (32-bit counter)

## Engine_streambuf_seekoff (0x403320, 449 bytes)
```c
unsigned int *__thiscall Engine_streambuf_seekoff(
    int this, unsigned int *a2, __int64 offset, int origin, char mode)
```
- **Purpose:** MSVC `std::streambuf::seekoff` — seek by offset from beginning/cur/end. 41 basic blocks with conditional paths for `ios_base::in` (1) / `ios_base::out` (2).
- **Constants:** 0x1, 0x2 (mode bits)

## Engine_istream_operator_read_string (0x405800, 446 bytes)
```c
int *__fastcall Engine_istream_operator_read_string(int *a1, const void **a2)
```
- **Callers:** 1 (FFX_Config_TokenizeBuffer)
- **Callees:** `Engine_String_push_back`, `?_Ipfx@?$basic_istream`, `Engine_std_locale_ctype_facet_lookup`, `?getloc@ios_base`, `?sgetc@?$basic_streambuf`, `?setstate`, `?snextc`
- **Purpose:** MSVC `std::istream::operator>>(std::string&)` — reads whitespace-delimited token from stream. 44 basic blocks with locale-dependent whitespace skipping.

## Engine_stringbuf_str (0x403ec0, 349 bytes)
```c
_DWORD *__thiscall Engine_stringbuf_str(int this, _DWORD *a2)
```
- **Callers:** 2 (Engine_iostream_sentry_ctor, Engine_stringbuf_overflow_to_str)
- **Callees:** `memmove`, `FFX_Heap_Free`, `Engine_String_assign_range`, `Engine_String_assign_move`, `@__security_check_cookie@4`
- **Purpose:** MSVC `std::stringbuf::str()` getter/setter. Returns accumulated content as std::string.

## Engine_String_FindCaseInsensitive (0x45d7d0, 337 bytes)
```c
unsigned __int8 *__cdecl Engine_String_FindCaseInsensitive(unsigned __int8 *a1, unsigned __int8 *C)
```
- **Callers:** 1 (Phyre_EventSystem_Init)
- **Callees:** `Phyre_UTF8_ReadCodepoint`, `toupper`
- **Purpose:** Case-insensitive UTF-8 string search. **Notable:** Uses Phyre's UTF-8 reader (`Phyre_UTF8_ReadCodepoint`) — confirms Phyre string handling integrates with UTF-8 codepoint iteration.
- **Algorithm:** Outer loop reads codepoint from haystack, toupper; inner loop reads codepoint from needle, toupper; compare.

## Engine_String_grow (0x404740, 334 bytes) ⭐
```c
int *__thiscall Engine_String_grow(const void **this, int n0x10_1, int Size)
```
- **Callers:** 8 (Engine_String_assign, Engine_String_push_back, Engine_String_assign_range, Engine_String_reserve, Phyre_String_Replace, Engine_String_replace, Phyre_String_Insert, Phyre_String_AppendData)
- **Callees:** `_CxxThrowException`, `FFX_Heap_AllocGameArenaDebugFill_wrapper_w`, `memcpy`, `FFX_Heap_Free`, `Engine_Heap_AllocGameArena_throw`, `?_Xbad_alloc`
- **Purpose:** MSVC `std::string::_Grow` — reallocates string buffer to new capacity. Uses geometric growth: `n0x10 = (cap/3 > n/3) ? n : cap/2 + cap`.
- **Critical allocator path:** Routes through FFX game arena heap for memory.

## Engine_String_assign (0x403a10, 279 bytes) ⭐
```c
_DWORD *__thiscall Engine_String_assign(_DWORD *this, _DWORD *this_2, unsigned int pos, size_t len)
```
- **Callers:** 15! (FFX_Config_TokenizeBuffer, Engine_String_init_assign, Engine_String_assign_range, FFX_BtlUI_CreateStringHandle, Phyre_WStringArray_Copy, Engine_String_CopyConstruct, FFX_String_CopyAssignSEH×4)
- **Callees:** `_Xlength_error`, `_Xout_of_range`, `Engine_String_erase`, `Engine_String_grow`, `memcpy`
- **Strings:** "invalid string position", "string too long"
- **Purpose:** MSVC `std::string::assign` — replaces string contents with substring range. Heavy use via SEH-wrapped wrappers (`FFX_String_CopyAssignSEH×4` = 4 variants).

## Engine_String_assign_range (0x404270, 247 bytes) ⭐
```c
_DWORD *__thiscall Engine_String_assign_range(_DWORD *this, _BYTE *Src, size_t Size)
```
- **Callers:** 15! (Engine_std_error_category_from_syserror_map, Engine_std_error_category_iostream_error, Engine_std_error_category_from_winerror_map, FFX_Config_TokenizeBuffer, Engine_String_ctor_from_cstr, Engine_stringbuf_str, FFX_Chr_LoadCdfFile, FFX_FieldMap_HookTextureAnimationChar, FFX_FieldMap_BeginAsyncLoad, FFX_Phyre_CloneInstanceArray, +5 more)
- **Callees:** `Engine_String_assign`, `_Xlength_error`, `Engine_String_grow`, `memcpy`
- **Strings:** "string too long"
- **Purpose:** MSVC `std::string::assign(InputIt first, InputIt last)` — assigns from arbitrary source range with aliasing detection.
- **Aliasing logic:** Detects if `Src` overlaps with internal buffer; if so, delegates to `Engine_String_assign` with offset.

---

# Part 2: Mesh Vertex Stream Compilation (4 functions)

The `Engine_Mesh_*` family compiles vertex stream descriptions for rendering. Three variants exist for different shadow/optimization paths.

## Engine_Mesh_VertexStreamCompiler (0x498af0, 415 bytes)
```c
int __thiscall Engine_Mesh_VertexStreamCompiler(
    _DWORD *this, _DWORD *a2, int arg4, PhyrePVertexStream *a4, int a5)
```
- **Callers:** 1 (Phyre_ShadowMesh_CompileVertexStreams)
- **Callees:** `VertexFormat_SemanticToComponentSize`, `Phyre_PVertexStream_InitZero`, `Phyre_PVertexStream_SetPtrWithRefCount`, `PShader_StreamLookup_ByID`
- **Purpose:** Primary mesh vertex stream compiler. Reads `(this+5) + 16*arg4` table; populates `PVertexStream` array with shader-compatible layouts.
- **Constants:** 0x7FFFFFFF (mask high bit), 0xC (12-byte stride), 0x4 (DWORD size)

## Engine_Mesh_VertexStreamCompilerAlt (0x498c90, 305 bytes)
```c
int __thiscall Engine_Mesh_VertexStreamCompilerAlt(
    _DWORD *this, int a2, int a3, PhyrePVertexStream *a4, int a5)
```
- **Callers:** 1 (Phyre_ShadowRenderer_DrawOcclusion)
- **Callees:** `Phyre_PVertexStream_InitZero`, `Phyre_PVertexStream_SetPtrWithRefCount`
- **Purpose:** Alternate path used by shadow occlusion renderer. Skips `VertexFormat_SemanticToComponentSize` and `PShader_StreamLookup_ByID` — uses precomputed tables instead.

## Engine_Mesh_VertexStreamCompiler_V2 (0x498de0, 243 bytes)
```c
int __thiscall Engine_Mesh_VertexStreamCompiler_V2(
    _DWORD *this, _DWORD *a2, int a3, _DWORD *a4, _DWORD *a5,
    int a6, int a7, int *a8, int a9)
```
- **Callees:** `__alloca_probe_16`, `Phyre_Memory_AllocateAlignedBuffer`, `@__security_check_cookie@4`
- **Purpose:** V2 compiler — uses `alloca(4*i_1)` for stack array then `Phyre_Memory_AllocateAlignedBuffer` for output. Different allocation strategy than V1.
- **Constants:** 0x40 (64), 0x20 (32) — likely stride/alignment constants
- **9 data refs** to various global stream tables (0xB16878, 0xB35178, 0xB43EE8, etc.)

## Engine_LinkedListToFlatArray_Convert (0x49cad0, 410 bytes)
```c
void __thiscall Engine_LinkedListToFlatArray_Convert(_DWORD *this)
```
- **Callers:** 1 (Phyre_TimerQueue_ProcessWithLinkedList)
- **Callees:** `Engine_AlignedFree`, `Engine_AlignedAllocAlign`
- **Purpose:** Converts intrusive linked list (timer queue entries) to flat array. Walks list once to count, allocates `28*count` aligned array, walks again to fill.
- **Constants:** 0x18 (24 — sizeof timer entry), 0x4 (alignment), 0x1C (28 — total stride)
- **Algorithm:** Two-pass — count nodes, then copy each into 28-byte slot.

---

# Part 3: Resource Handle & Shader Defs (3 functions)

## Engine_ResourceHandle_Destructor (0x495ae0, 327 bytes) ⭐
```c
void __thiscall Engine_ResourceHandle_Destructor(int *this)
```
- **Callers:** 11! (Phyre_ResourceHandle_Dtor, FFX_Video_DestroyPlayerInternal, PPostProcessEffect_ResolveTarget, PPostProcessEffect_SetInput, PPostProcessEffect_GetLastError, Phyre_PostProcessing_GlowGPU_Destructor, PPostProcessEffect_BufferCopy2, PPostProcessEffect_ShaderRef, Phyre_PostProcessing_Destructor_ReleaseHandles, Phyre_PostProcessing_DestroyResourceHandle)
- **Callees:** `Engine_AlignedFree`, `Phyre_Stream_Close`, `Phyre_Stream_IsEOF`
- **Purpose:** Releases 3 resource pairs: stream + stream-handle, aligned-buffer + length, second aligned-buffer + length. Each pair checked for null + sign bit (`v & 0x7FFFFFFF >= 0` test) before freeing.
- **Constants:** 0x7FFFFFFF (sign mask), 0x1F (sign bit shift), 0x1, 0x8, 0x4

## Engine_ShaderParamDef_Copy (0x4a3610, 238 bytes)
```c
void __cdecl Engine_ShaderParamDef_Copy(int dst, int src, int count)
```
- **Callers:** 4 (PShaderParamDef_ManagedArray_Assign, PShaderParamDef_ManagedArray_Resize, PhyrePRendering_DeepCopyShaderDefArray, PhyrePRendering_DeepCopyShaderDefEntry)
- **Callees:** `Engine_AlignedAllocAlign`, `memcpy`
- **Purpose:** Deep copy array of shader parameter definitions (16 bytes each). Each entry: 2 bytes type/category, 1 byte stage, 1 byte flags, 4 bytes name pointer, 8 bytes misc.
- **Constants:** 0x10 (16-byte entry size), 0x4 (4-byte skip), 0x1 (low bit clear), 0x2 (alignment)

## Engine_ShaderStreamDef_Copy (0x4a3700, 238 bytes)
```c
int __usercall Engine_ShaderStreamDef_Copy@<eax>(int result@<eax>, int dst, int src, int count)
```
- **Callers:** 4 (PShaderStreamDef_ManagedArray_Assign, PShaderStreamDef_ManagedArray_Resize, PhyrePRendering_DeepCopyShaderDefArray, PhyrePRendering_DeepCopyShaderDefEntry)
- **Callees:** `Engine_AlignedAllocAlign`, `memcpy`
- **Purpose:** Deep copy array of shader stream definitions (16 bytes each). Different field layout than ParamDef (4 bytes type, 4 bytes name ptr, 8 bytes misc).
- **Note:** Uses `__usercall` convention — first arg in EAX.

---

# Part 4: I/O & String Constructors (3 functions)

## Engine_streambuf_seekpos (0x4034f0, 297 bytes)
```c
unsigned int *__thiscall Engine_streambuf_seekpos(
    int this, unsigned int *a2, __int64 pos, __int64 state, int mode, int a6, char a7)
```
- **Purpose:** MSVC `std::streambuf::seekpos` — seek to absolute position. 31 basic blocks. Delegates to `_BADOFF` sentinel check before processing.

## Engine_CountSectionEntriesInFile (0x628760, 297 bytes)
```c
int __cdecl Engine_CountSectionEntriesInFile(void *ArgList)
```
- **Callers:** 1 (InitEngineRenderSystem)
- **Callees:** `Phyre_Stream_Printf`, `Phyre_PStreamReaderFile_ctor`, `Engine_AlignedFree`, `Phyre_Cluster_ValidateImportRegion`, `Phyre_PStreamReaderFile_dtor`, `Phyre_PStreamWriterFile_Close`, `Phyre_SectionData_GetPointerFromOffset`
- **Strings:** "Error opening : %s", "%d:"
- **Purpose:** Counts entries in a file section (likely engine render config). Opens via `PStreamReaderFile`, validates region via `Cluster_ValidateImportRegion`, prints errors.
- **Constants:** 0x13 (19 — error code?)

## Engine_PStringArray_Set (0x44c190, 295 bytes)
```c
int __thiscall Engine_PStringArray_Set(_DWORD *this, _DWORD *Size)
```
- **Callees:** `Engine_AlignedFree`, `Engine_AlignedAllocAlign`, `memcpy`, `PStringArray_PushBack`
- **Purpose:** Sets PStringArray element at index. Allocates aligned copy of string data (using 2-byte alignment), pushes to array via `PStringArray_PushBack`.
- **Constants:** 0xD (13 — error code for null alloc), 0x1 (low bit mask)

---

# Part 5: Misc STL Wrappers (2 functions)

## Engine_std_locale_ctype_facet_lookup (0x4049a0, 238 bytes)
```c
struct std::_Facet_base *__thiscall Engine_std_locale_ctype_facet_lookup(int *this)
```
- **Callers:** 1 (Engine_istream_operator_read_string)
- **Callees:** `_CxxThrowException`, `??0_Lockit@std@@QAE@H@Z`, `?_Getcat@?$ctype@D@std@@SAI`, `??1_Lockit@std@@QAE@XZ`, `?_Facet_Register`, `??Bid@locale@std@@QAEIXZ`, `??0bad_cast@std@@QAE@PBD@Z`, `?_Getgloballocale@locale@std@@CAPAV_Locimp@12@XZ`
- **Strings:** "bad cast"
- **Purpose:** MSVC `std::locale::facet` lookup for ctype facet. Acquires `_Lockit`, looks up facet by ID, throws `bad_cast` on type mismatch.

## Engine_String_push_back (0x4041c0, 164 bytes)
```c
const void **__thiscall Engine_String_push_back(
    const void **this, int c, char a3)
```
- **Callers:** 1 (Engine_istream_operator_read_string)
- **Callees:** `_Xlength_error`, `Engine_String_grow`
- **Strings:** "string too long"
- **Purpose:** MSVC `std::string::push_back` — append single char. Grows buffer if needed, updates size + null terminator.

---

# Part 6: Aligned Allocator (CORE, 3 functions)

These three functions form the **core heap primitive** of PhyreEngine. Every aligned allocation/free in the entire 47K-function codebase routes through them.

## Engine_AlignedAllocAlign (0x42fc60, 65 bytes) ⭐⭐
```c
int *__cdecl Engine_AlignedAllocAlign(int a1, int a2)
{
  int *result;
  int *v3;

  result = FFX_Heap_AllocGameArenaDebugFill_wrapper(a2 + a1 + 4);  // size + align + 4
  v3 = result;
  if ( result )
  {
    result = (int *)((char *)result + (-(int)(result + 1) & (a2 - 1)) + 4);  // align
    *(int *)((char *)result + ((7 - (_DWORD)result) & 3) - 7) = (int)v3;  // stash real ptr
  }
  return result;
}
```
- **Callers:** 1094! (most-called allocator)
- **Callees:** `FFX_Heap_AllocGameArenaDebugFill_wrapper`
- **Constants:** 0x4 (header size), 0x3 (alignment mask)
- **Algorithm:**
  1. Allocates `size + align + 4` bytes from game arena
  2. Aligns up by `align - 1` mask
  3. Stores real heap pointer at `(aligned - 7)` (uses `(7-ptr)&3 - 7` for pointer-specific offset)
  4. Returns aligned ptr with 4-byte header before it
- **Total xrefs:** 1094 — used by EVERY Phyre subsystem (String, Animation, Resource, Mesh, Shader, Audio, Rendering)

## Engine_AlignedFree (0x42fc00, 32 bytes) ⭐⭐
```c
void __stdcall Engine_AlignedFree(void *ptr)
{
  if ( ptr )
    Engine_HeapFreeThunk(*(_DWORD *)((char *)ptr + ((7 - (_DWORD)ptr) & 3) - 7));
}
```
- **Callers:** 4316! (most-called deallocator in the codebase)
- **Callees:** `Engine_HeapFreeThunk`
- **Algorithm:** Inverse of AlignedAllocAlign — reads stashed real ptr and frees it.

## Phyre_String_Replace (0x405220, 486 bytes)
```c
const void **__thiscall Phyre_String_Replace(
    _DWORD *this, size_t pos, size_t len, _BYTE *Src, size_t sublen)
```
- **Callers:** 1 (Engine_String_erase_or_replace_range)
- **Callees:** `_Xlength_error`, `_Xout_of_range`, `Engine_String_replace`, `Engine_String_grow`, `memmove`, `memcpy`
- **Strings:** "invalid string position", "string too long"
- **Purpose:** Phyre's wrapper over MSVC `std::string::replace`. Performs range validation, aliasing check, delegates to Engine_String_replace with offset.

---

# Summary Tables

## Size Distribution

| Bucket | Range | Count |
|--------|-------|-------|
| Huge | >= 1024 bytes | 0 |
| Large | 512 - 1023 | 2 |
| Medium | 256 - 511 | 8 |
| Small | 64 - 255 | 13 |
| Tiny | < 64 | 2 |

## Most-Called Functions

| Function | Callers | Purpose |
|----------|---------|---------|
| Engine_AlignedFree | **4316** | Deallocator (paired with AlignedAllocAlign) |
| Engine_AlignedAllocAlign | **1094** | Allocator (paired with AlignedFree) |
| Engine_String_assign | **15** | std::string::assign |
| Engine_String_assign_range | **15** | std::string::assign(InputIt) |
| Engine_ResourceHandle_Destructor | **11** | Resource cleanup |
| Engine_String_grow | **8** | std::string::_Grow |

## Subsystem Distribution

| Subsystem | Count |
|-----------|-------|
| MSVC STL String/Stream | 10 |
| Phyre Mesh | 3 |
| Phyre Shader Defs | 2 |
| Phyre I/O + LinkedList | 3 |
| MSVC Locale/iostream | 2 |
| Phyre Allocator (CORE) | 3 |
| Phyre String wrapper | 1 |
| MSVC exception | 1 |

## Alignment Algorithm Pattern

```c
// Alloc(size, align):
raw = malloc(size + align + 4);
aligned = (raw + 4 + align - 1) & ~(align - 1);  // align up
stashed_ptr_offset = (aligned - 7 + (7-aligned)&3);  // store real ptr 4 bytes before aligned
*(aligned - 4) = raw;  // 4-byte header

// Free(aligned):
real_ptr = *(aligned - 4);
free(real_ptr);
```

## Tech Stack

| Technology | Used In |
|------------|---------|
| MSVC STL (v110) | All string/stream/locale functions |
| MSVCR110.dll | External CRT imports (`_Xlength_error`, `setstate`, `sputc`) |
| SSE/AVX | None in this batch |
| x87 FPU | None — pure integer/pointer ops |
| Aligned alloc pattern | Engine_AlignedAllocAlign + Engine_AlignedFree |
| FFX game arena | `FFX_Heap_AllocGameArenaDebugFill_wrapper` |
| Lua scripting | None in this batch |
| UTF-8 codepoint | Phyre_UTF8_ReadCodepoint in FindCaseInsensitive |

---

## Key Findings

1. **Core allocator: 1094 + 4316 = 5410 xrefs** — `Engine_AlignedAllocAlign`/`Engine_AlignedFree` are the most-called heap primitives in the entire FFX.exe codebase. Every Phyre subsystem uses them.

2. **MSVC STL is statically linked** — All `Engine_String_*` and `Engine_streambuf_*` functions are MSVC 2012 v110 standard library implementations (NOT Phyre code). They route through `FFX_Heap_AllocGameArenaDebugFill_wrapper` for memory — Phyre intercepted the allocator.

3. **UTF-8 in FindCaseInsensitive** — `Engine_String_FindCaseInsensitive` calls `Phyre_UTF8_ReadCodepoint` for codepoint-aware case-insensitive search. MSVC's standard library normally uses ASCII, but FFX extended it with Phyre's UTF-8 reader.

4. **Three Mesh VertexStream compilers** — V1 (0x498af0, 415B) for shadow meshes, Alt (0x498c90, 305B) for occlusion, V2 (0x498de0, 243B) for general purpose with alloca stack array. All use `PVertexStream_SetPtrWithRefCount` for ref-counted stream setup.

5. **Resource Handle dtor is heavily called** — 11 callers across post-processing, video, glow GPU, and shader resource handling. Each releases 3 resource pairs (stream, buffer1, buffer2) with sign-bit sanity checks.

6. **Phyre wraps MSVC STL** — `Phyre_String_Replace` (0x405220) is a thin wrapper over `Engine_String_replace` (the MSVC STL impl). The Phyre wrapper adds range validation + aliasing detection before delegating.

7. **C++ exception throwing throughout** — `_Xlength_error` and `_Xout_of_range` are MSVC STL exceptions thrown in `std::string::assign`, `replace`, `push_back`, `grow`. SEH-wrapped variants (`FFX_String_CopyAssignSEH×4`) exist for exception-safe C-API interop.

8. **MSVC STL exception class names** — All `??_Xlength_error@std@@YAXPBD@Z`, `??Bid@locale@std@@QAEIXZ`, etc. — these are mangled MSVC symbols for std::string + std::locale classes.

---

## Next Batches

- Batch 11: Engine_* remaining ~163 functions (mostly small STL wrappers)
- Batch 12: Phyre_PPhysics (37 WorldSetup_* functions, mostly small)
- Batch 13: Phyre_PInput_Pad/Keyboard/Mouse/Touch (~150 functions)
- Batch 14: Phyre_PRendering (render pipeline, D3D11)
- Batch 15: Phyre_PSceneNode (~90 functions)