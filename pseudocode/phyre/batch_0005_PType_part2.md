# FFX.exe Decompilation — Batch 5 (Phyre_PType Part 2 — Read/Write/Thunks)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 21 (Phyre_PType Read/Write/Compare/Getter thunks)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

Part 2 covers all Read/Write virtual methods of the PType system plus thunk/comparison helpers. All Read functions follow an identical pattern (PhyreBuffer_Read → PhyreStream_Reserve), all Write functions follow another (PhyreStream_ReserveGrow → PhyreStream_Push*). The thunks (ReturnZero, Identity, CompareReturnTrue) are trivial but heavily referenced in vtables.

## Functions Decompiled

### Read Functions (all follow identical pattern)

#### Phyre_PType_ReadInt8 (0x439790, 41 bytes)
```c
// Phyre PType: Read int8
int __stdcall Phyre_PType_ReadInt8(_DWORD *a1, _BYTE *a2)
{
  char NumAsInt; // bl
  int result; // eax

  NumAsInt = PhyreBuffer_ReadNumAsInt(a1, -1, 0);
  result = PhyreStream_Reserve((int)a1, -2);
  *a2 = NumAsInt;
  return result;
}
```
- **Callees:** PhyreBuffer_ReadNumAsInt, PhyreStream_Reserve

#### Phyre_PType_ReadBool (0x439760, 41 bytes)
```c
// Phyre PType: Read bool
int __stdcall Phyre_PType_ReadBool(_DWORD *a1, _BYTE *a2)
  // Identical pattern to ReadInt8 — PhyreBuffer_ReadNumAsInt + PhyreStream_Reserve
```
- **Callees:** PhyreBuffer_ReadNumAsInt, PhyreStream_Reserve

#### Phyre_PType_ReadInt16 (0x4397c0, 43 bytes)
```c
// Phyre PType: Read int16
_WORD *__stdcall Phyre_PType_ReadInt16(_DWORD *a1, _WORD *a2)
{
  __int16 NumAsInt; // di
  NumAsInt = PhyreBuffer_ReadNumAsInt(a1, -1, 0);
  PhyreStream_Reserve((int)a1, -2);
  *a2 = NumAsInt;
  return a2;
}
```

#### Phyre_PType_ReadInt32 (0x439820, 41 bytes)
```c
// Phyre PType: Read int32
int __stdcall Phyre_PType_ReadInt32(_DWORD *a1, int *a2)
  // Same pattern — PhyreBuffer_ReadNumAsInt + PhyreStream_Reserve
```

#### Phyre_PType_ReadUInt16 (0x4397f0, 41 bytes)
- Same ReadNumAsInt pattern

#### Phyre_PType_ReadUInt32 (0x439850, 41 bytes)
- Same ReadNumAsInt pattern

#### Phyre_PType_ReadFloat (0x439880, 46 bytes)
```c
float *__stdcall Phyre_PType_ReadFloat(_DWORD *a1, float *a2)
{
  float Float; // [esp+0h] [ebp-4h]
  Float = PhyreBuffer_ReadFloat(a1, -1, 0);
  PhyreStream_Reserve((int)a1, -2);
  *a2 = Float;
  return a2;
}
```
**Note:** Uses PhyreBuffer_ReadFloat (not ReadNumAsInt) — float-specific reader

#### Phyre_PType_ReadDouble (0x4398b0, 48 bytes)
```c
double *__stdcall Phyre_PType_ReadDouble(_DWORD *a1, double *a2)
{
  double Float; // [esp+0h] [ebp-8h]
  Float = PhyreBuffer_ReadFloat(a1, -1, 0);
  PhyreStream_Reserve((int)a1, -2);
  *a2 = Float;
  return a2;
}
```
**Note:** Uses PhyreBuffer_ReadFloat (same as float!) — double is read as float then widened

#### Phyre_PType_ReadPInt64 (0x439930, 49 bytes)
```c
// Phyre PType: Read PInt64
int __stdcall Phyre_PType_ReadPInt64(_DWORD *a1, _QWORD *a2)
  // ReadNumAsInt — returns 64-bit value
```

#### Phyre_PType_ReadPUInt64 (0x439970, 49 bytes)
```c
// Phyre PType: Read PUInt64
  // ReadNumAsInt — returns 64-bit value
```

#### Phyre_PType_ReadPUInt128 (0x4398e0, 68 bytes)
```c
// Phyre PType: Read PUInt128
int __stdcall Phyre_PType_ReadPUInt128(_DWORD *a1, int a2)
{
  __int64 NumAsInt; // kr00_8
  NumAsInt = PhyreBuffer_ReadNumAsInt(a1, -1, 0);
  PhyreStream_Reserve((int)a1, -2);
  *(_QWORD *)a2 = NumAsInt;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  return HIDWORD(NumAsInt);
}
```
**Note:** 128-bit type stored as 64-bit value with upper 64 bits zeroed

#### Phyre_PType_ReadBoolEx (0x4399b0, 42 bytes)
```c
// Phyre PType: Read bool ex
bool *__stdcall Phyre_PType_ReadBoolEx(_DWORD *a1, bool *a2)
{
  bool IsValidValue; // bl
  IsValidValue = PhyreBuffer_IsValidValue(a1, -1);
  PhyreStream_Reserve((int)a1, -2);
  *a2 = IsValidValue;
  return a2;
}
```
**Note:** Uses PhyreBuffer_IsValidValue instead of ReadNumAsInt — validates boolean semantics

### Write Functions (all follow identical pattern)

#### Phyre_PType_WriteInt8 (0x439a00, 35 bytes)
```c
int __stdcall Phyre_PType_WriteInt8(_DWORD *a1, char *a2)
{
  PhyreStream_ReserveGrow(a1, 1);
  return PhyreStream_PushIntAsFloat((int)a1, *a2);
}
```

#### Phyre_PType_WriteInt16 (0x439a60, 35 bytes)
```c
int __stdcall Phyre_PType_WriteInt16(_DWORD *a1, __int16 *a2)
{
  PhyreStream_ReserveGrow(a1, 1);
  return PhyreStream_PushIntAsFloat((int)a1, *a2);
}
```

#### Phyre_PType_WriteInt32 (0x439ac0, 33 bytes)
```c
int __stdcall Phyre_PType_WriteInt32(_DWORD *a1, int *a2)
{
  PhyreStream_ReserveGrow(a1, 1);
  return PhyreStream_PushIntAsFloat((int)a1, *a2);
}
```

#### Phyre_PType_WriteUInt8 (0x439a30, 35 bytes)
- Same PushIntAsFloat pattern

#### Phyre_PType_WriteUInt16 (0x439a90, 35 bytes)
- Same PushIntAsFloat pattern

#### Phyre_PType_WriteUInt32 (0x439af0, 33 bytes)
```c
int __stdcall Phyre_PType_WriteUInt32(_DWORD *a1, int *a2)
{
  PhyreStream_ReserveGrow(a1, 1);
  return PhyreStream_PushIntAsFloat((int)a1, *a2);
}
```

#### Phyre_PType_WriteFloat (0x439b20, 39 bytes)
```c
_DWORD *__stdcall Phyre_PType_WriteFloat(_DWORD *a1, float *a2)
{
  PhyreStream_ReserveGrow(a1, 1);
  return PhyreStream_PushFloat((int)a1, COERCE_INT(*a2));
}
```
**Note:** Uses PhyreStream_PushFloat (not PushIntAsFloat)

#### Phyre_PType_WriteDouble (0x439b50, 45 bytes)
```c
_DWORD *__stdcall Phyre_PType_WriteDouble(_DWORD *a1, double *a2)
  // Truncates double to float, then pushes via PhyreStream_PushFloat
```

#### Phyre_PType_WriteBool (0x439c10, 35 bytes)
```c
BOOL __stdcall Phyre_PType_WriteBool(_DWORD *a1, unsigned __int8 *a2)
{
  PhyreStream_ReserveGrow(a1, 1);
  return PhyreStream_PushBool((int)a1, *a2);
}
```
**Note:** Uses PhyreStream_PushBool (dedicated bool writer)

#### Phyre_PType_WritePInt64 (0x439bb0, 33 bytes)
- PushIntAsFloat pattern

#### Phyre_PType_WritePUInt64 (0x439be0, 33 bytes)
- PushIntAsFloat pattern

#### Phyre_PType_WritePUInt128 (0x439b80, 33 bytes)
- PushIntAsFloat pattern (lower 32 bits only)

### Type Singletons

#### Phyre_PType_GetDouble (0x4381f0, 150 bytes)
```c
// Phyre PType: Get double
_DWORD *Phyre_PType_GetDouble()
{
  if ( (dword_C905BC & 1) == 0 )
  {
    // Standard singleton init: flag guard → sentinels → vtable → atexit
    // m_size=8, m_align=8, m_isString=0
  }
  return &p_g_vtable_PTypeDefault_double_Phyre;
}
```
- **Callers:** 33 xrefs (Phyre_Timer_GetElapsed, TypeSystem_RegisterAllTypes, PArray double variants)

### Thunks and Helpers

#### Phyre_PType_Identity (0x43c4f0, 3 bytes)
```c
// Returns input value unchanged (identity function)
int __stdcall Phyre_PType_Identity(int val)
{
  return v1; // ecx return
}
```
- **Vtable refs:** **1228 data xrefs** — used as identity callback in virtually every PType vtable

#### Phyre_PType_ReturnZero (0x437970, 3 bytes)
```c
int Phyre_PType_ReturnZero() { return 0; }
```
- **Vtable refs:** 37 data xrefs — used as default "get 0" callback

#### Phyre_PType_Default_ReturnZero (0x437980, 3 bytes)
```c
int __stdcall Phyre_PType_Default_ReturnZero() { return 0; }
```
- **Vtable refs:** **1240 data xrefs** — most-used return-zero thunk in the entire engine

#### Phyre_PType_CompareReturnTrue (0x439cc0, 5 bytes)
```c
char __stdcall Phyre_PType_CompareReturnTrue(int a1, int a2) { return 1; }
```
- **Purpose:** Comparison callback that always returns true

#### Phyre_PType_SwapBytes_CompareTrue (0x439d10, 22 bytes)
```c
char __stdcall Phyre_PType_SwapBytes_CompareTrue(_WORD *a1, int a2)
{
  *a1 = __ROL2__(*a1, 8); // byte-swap via rotate-left-8
  return 1;
}
```
- **Purpose:** Byte-swap then return true — used for endianness conversion in comparison

#### Phyre_PType_Field0_getter (0x4379e0, 3 bytes)
```c
int __thiscall Phyre_PType_Field0_getter(void *this)
{
  return *(_DWORD *)this; // returns vfptr value
}
```
- **Purpose:** Getter for the first DWORD of PType (the vfptr itself)

---

## Key Findings

### Read Function Pattern (all 12 variants)
```
PhyreBuffer_Read*(buffer, -1, 0)  → read typed value
PhyreStream_Reserve(buffer, -2)    → advance stream position
*out = value                        → store result
```
- `-1` = read from current position
- `-2` = unspecified/reserved stream operation
- Float/double use `PhyreBuffer_ReadFloat`; all other types use `PhyreBuffer_ReadNumAsInt`

### Write Function Pattern (all 12 variants)
```
PhyreStream_ReserveGrow(buffer, 1)   → ensure stream capacity
PhyreStream_Push*(buffer, value)      → write typed value
```
- Int8/16/32/64/UInt8/16/32/64/PUInt64/128 → `PhyreStream_PushIntAsFloat`
- Float/double → `PhyreStream_PushFloat`
- Bool → `PhyreStream_PushBool`

### Type System Constants (from GetSingleton functions)

| Type | Guard Flag | Size | Align | Vtable Ptr | Xrefs |
|------|-----------|------|-------|-----------|-------|
| PType (base) | dword_C903AC | 44 | 4 | 0xB0E570 | 10+ |
| PChar | dword_C9040C | 1 | 1 | 0xB0E718 | 64 |
| PUInt8 | dword_C9043C | 1 | 1 | 0xB0E744 | 148 |
| PInt32 | dword_C904CC | 4 | 4 | 0xB0E7C8 | 114 |
| Float | dword_C9058C | 4 | 4 | 0xB0E854 | **241** |
| Double | dword_C905BC | 8 | 8 | 0xB0E880 | 33 |
| Bool | dword_C903DC | 1 | 1 | 0xB0E6EC | 81 |
| UInt32 (PResult) | dword_C90C50 | 4 | 4 | 0xB0F0C0 | 72 |

### Thunk Reference Table

| Thunk | Address | Size | Xrefs | Purpose |
|-------|---------|------|-------|---------|
| Phyre_PType_Identity | 0x43c4f0 | 3 | **1228** | Return arg (identity) |
| Phyre_PType_Default_ReturnZero | 0x437980 | 3 | **1240** | Return 0 (stdcall) |
| Phyre_PType_ReturnZero | 0x437970 | 3 | 37 | Return 0 (thiscall?) |
| Phyre_PType_CompareReturnTrue | 0x439cc0 | 5 | 1 | Return 1 |
| Phyre_PType_Field0_getter | 0x4379e0 | 3 | 0 | Return *this |
| Phyre_PType_SwapBytes_CompareTrue | 0x439d10 | 22 | 1 | Byte-swap + return 1 |

### Serialization Architecture Insight
The PType Read/Write system is a **tagged union serializer**: values are read/written as their native types (float → PhyreBuffer_ReadFloat), but ALL integer types (8-128 bit, signed/unsigned) go through a single `PhyreBuffer_ReadNumAsInt` function that returns the widest type and lets the caller truncate. Doubles are truncated to float on write — lossy serialization.

## Next Batches
- Batch 6: Remaining PType singleton inits (PUInt16, PInt16, PUInt32, PUInt64, PInt64, PUInt128) + AnimatableComponent singletons
- Batch 7: Phyre_PAnimation family (~660 functions)
- Batch 8: Phyre_PInput family (~632 functions)
