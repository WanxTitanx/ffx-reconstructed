# FFX.exe Decompilation — Batch 1 (Phyre Zlib + String)

**Database:** ffxoficial.exe.i64 (session 98fb3878)
**Date:** 2026-07-27
**Functions:** 22 (Phyre_ZlibInflate family + Phyre_String_Replace)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the PhyreEngine zlib 1.2.8 implementation embedded in FFX.exe. Used for decompressing `.phyre` asset files (models, textures, scenes). Standard zlib code, well-understood.

## Functions Decompiled

### Phyre_String_Replace (0x405220, 486 bytes)
```c
_DWORD *__thiscall Phyre_String_Replace(_DWORD *this, size_t a2, size_t Size_1, _BYTE *Src, size_t Size_4)
```
- **Callers:** Engine_String_erase_or_replace_range
- **Callees:** Engine_String_grow, memmove, memcpy, std::Xout_of_range, std::Xlength_error
- **Strings:** "invalid string position", "string too long"
- **Purpose:** Replace substring in Phyre::String (SSO-optimized, 16-byte inline buffer)

### Phyre_ZlibInflate_Buffer (0x405e20, 153 bytes)
```c
int __cdecl Phyre_ZlibInflate_Buffer(int a1, int *a2, unsigned __int8 *a3, int a4)
```
- **Callers:** Phyre_UI_ShowMessageBox
- **Callees:** Phyre_ZlibStream_Init, Phyre_ZlibInflate, Phyre_ZlibStream_Destroy
- **Purpose:** Inflate a zlib-compressed buffer in one shot

### Phyre_ZlibStream_Reset (0x405f90, 106 bytes)
```c
int __thiscall Phyre_ZlibStream_Reset(int this)
```
- **Callers:** Phyre_ZlibStream_Init
- **Purpose:** Reset zlib stream state to initial values (window=15, mode=1)

### Phyre_ZlibStream_Init (0x406000, 132 bytes)
```c
int __thiscall Phyre_ZlibStream_Init(_DWORD *this)
```
- **Callers:** Phyre_ZlibInflate_Buffer, Phyre_ZlibStream_Init_wrapper
- **Callees:** Phyre_Zlib_AllocArray, Phyre_Zlib_FreeArray, Phyre_ZlibStream_Reset
- **Purpose:** Initialize zlib stream with custom allocators (Phyre_Zlib_AllocArray/FreeArray)
- **Alloc size:** 7116 bytes (0x1BCC) for zlib internal state

### Phyre_ZlibStream_Init_wrapper (0x406090, 12 bytes)
```c
int __thiscall Phyre_ZlibStream_Init_wrapper(_DWORD *this)
```
- **Purpose:** Thin wrapper around Phyre_ZlibStream_Init (likely vtable entry)

### Phyre_ZlibInflate_InitFixedTables (0x406110, 29 bytes)
```c
void __thiscall Phyre_ZlibInflate_InitFixedTables(_DWORD *this)
```
- **Callers:** Phyre_ZlibInflate
- **Purpose:** Initialize fixed Huffman tables (lengths 9, 5)
- **Data refs:** 0xB7CD18, 0xB7D540 (fixed Huffman code tables)

### Phyre_ZlibInflate_ProcessBlock (0x406130, 247 bytes)
```c
int __fastcall Phyre_ZlibInflate_ProcessBlock(int this, int next_out, size_t Size)
```
- **Callers:** Phyre_ZlibInflate
- **Callees:** memcpy
- **Purpose:** Process a single deflate block

### Phyre_ZlibInflate (0x406230, 5605 bytes) ⭐ LARGEST
```c
int __thiscall Phyre_ZlibInflate(PhyreZlibState *this)
```
- **Callers:** Phyre_ZlibInflate_Buffer
- **Callees:** Phyre_ZlibInflate_ProcessBlock, Phyre_ZlibCRC32_Safe, Phyre_ZlibInflate_InitFixedTables, Phyre_ZlibCRC32, Phyre_ZlibInflate_InflateBlock, Phyre_ZlibInflate_BuildHuffmanTables, memcpy, Phyre_ZlibInflate_Adler32
- **Strings:** "unknown compression method", "invalid window size", "incorrect header check", "unknown header flags set", "header crc mismatch", "invalid block type", "invalid stored block lengths", "invalid code lengths set", "too many length or distance symbols"
- **Purpose:** Main zlib inflate routine (zlib 1.2.8)
- **Note:** 359 basic blocks — heavily optimized

### Phyre_ZlibStream_Destroy (0x4078b0, 69 bytes)
```c
int __thiscall Phyre_ZlibStream_Destroy(_DWORD *this)
```
- **Callers:** Phyre_ZlibInflate_Buffer
- **Purpose:** Destroy zlib stream, free internal state via Phyre_Zlib_FreeArray

### Phyre_ZlibInflate_HuffmanStateMachine (0x407a30, 116 bytes)
```c
unsigned int __fastcall Phyre_ZlibInflate_HuffmanStateMachine(unsigned int *a1, int a2, unsigned int a3)
```
- **Purpose:** State machine for Huffman decoding sync pattern detection

### Phyre_ZlibInflate_Adler32 (0x407da0, 621 bytes)
```c
unsigned int __fastcall Phyre_ZlibInflate_Adler32(unsigned int n0xFFF1, unsigned __int8 *a2, unsigned int next_out)
```
- **Callers:** Phyre_ZlibInflate
- **Purpose:** Compute Adler32 checksum (zlib 1.2.8)
- **Constants:** 65521 (F1 modulus), 65535 (FFFF mask)

### Phyre_ZlibAdler32 (0x408010, 183 bytes)
```c
unsigned int __fastcall Phyre_ZlibAdler32(unsigned int a1, unsigned int a2, __int64 a3)
```
- **Callees:** __alldiv (64-bit division)
- **Purpose:** Combined Adler32 computation (likely optimized variant)

### Phyre_ZlibInflate_InflateBlock (0x408110, 1070 bytes)
```c
unsigned __int8 *__fastcall Phyre_ZlibInflate_InflateBlock(unsigned __int8 **this, size_t Size)
```
- **Callers:** Phyre_ZlibInflate
- **Strings:** "invalid literal/length code", "invalid distance code", "invalid distance too far back"
- **Purpose:** Inflate a single deflate block (literal + distance codes)

### Phyre_ZlibCRC32TableGetter (0x408540, 6 bytes)
```c
int *Phyre_ZlibCRC32TableGetter()
{
  return dword_B7D5C0;
}
```
- **Purpose:** Return pointer to CRC32 lookup table (precomputed at 0xB7D5C0)

### Phyre_ZlibCRC32_Safe (0x408550, 17 bytes)
```c
int __fastcall Phyre_ZlibCRC32_Safe(int a1, _DWORD *a2, unsigned int a3)
```
- **Purpose:** Null-safe wrapper for Phyre_ZlibCRC32

### Phyre_ZlibCRC32 (0x408570, 695 bytes)
```c
unsigned int __fastcall Phyre_ZlibCRC32(int a1, _DWORD *a2, unsigned int n0x20_1)
```
- **Callers:** Phyre_ZlibInflate
- **Purpose:** Compute CRC32 checksum (zlib 1.2.8)
- **Constants:** 0xFF (byte mask), 0x20 (32-byte unroll), 0x8/0x10 (shift amounts)

### Phyre_ZlibCRC32_InitTable (0x408b90, 495 bytes)
```c
unsigned int __fastcall Phyre_ZlibCRC32_InitTable(unsigned int a1, int a2, __int64 a3)
```
- **Callees:** __security_check_cookie
- **Purpose:** Initialize CRC32 lookup table at runtime
- **Polynomial:** 0xEDB88320 (standard CRC32 reversed)

### Phyre_ZlibVersionString_1_2_8 (0x408dc0, 6 bytes)
```c
const char *Phyre_ZlibVersionString_1_2_8()
{
  return "1.2.8";
}
```
- **Purpose:** Return zlib version string — **confirms PhyreEngine uses zlib 1.2.8**

### Phyre_Zlib_Return85 (0x408dd0, 6 bytes)
```c
int Phyre_Zlib_Return85()
{
  return 85;
}
```
- **Purpose:** Unknown — returns constant 85 (likely Z_BUF_ERROR or similar zlib code)

### Phyre_Zlib_AllocArray (0x408df0, 22 bytes)
```c
void *__cdecl Phyre_Zlib_AllocArray(int a1, int a2, int a3)
{
  return malloc(a3 * a2);
}
```
- **Purpose:** Custom zlib allocator — wraps malloc

### Phyre_Zlib_FreeArray (0x408e10, 17 bytes)
- **Purpose:** Custom zlib deallocator — wraps free

### Phyre_ZlibInflate_BuildHuffmanTables (0x408e30, 1098 bytes)
- **Callers:** Phyre_ZlibInflate
- **Purpose:** Build Huffman lookup tables from code lengths

---

## Key Findings

1. **PhyreEngine embeds zlib 1.2.8** (confirmed by `Phyre_ZlibVersionString_1_2_8` returning "1.2.8")
2. **Custom allocators** (`Phyre_Zlib_AllocArray`/`FreeArray`) wrap standard malloc/free
3. **CRC32 polynomial** 0xEDB88320 (standard)
4. **Adler32 modulus** 65521 (standard)
5. **Alloc size** 7116 bytes for zlib internal state
6. **Fixed Huffman tables** at 0xB7CD18 (lengths) and 0xB7D540 (distances)
7. **CRC32 lookup table** at 0xB7D5C0

## Next Batches

- Batch 2: Phyre_PClassDescriptor family (destructors, traversers)
- Batch 3: Phyre_Scripting family (Lua bridge)
- Batch 4: Phyre_PNamespace family
- Batch 5+: Phyre_PArray, Phyre_PVector, Phyre_PQuaternion math
