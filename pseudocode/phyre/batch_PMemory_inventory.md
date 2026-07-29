# Inventory: Phyre_Memory_*

**Database:** ffxoficial.exe.i64 (FFX.exe)
**Query filter:** `Phyre_Memory_*`
**Generated:** 2026-07-27

## Summary

- **Total functions:** 15
- **Address range:** 0x4305e0 - 0x9f09e0
- **Size range:** 0x5 (5 bytes) - 0x325 (805 bytes)
- **Average size:** 0x76 (118 bytes)
- **Total bytes:** 1773 bytes

## Size Distribution

| Bucket | Range | Count |
|--------|-------|-------|
| Tiny | < 0x10 bytes | 4 |
| Small | 0x10 - 0x3F | 5 |
| Medium | 0x40 - 0xFF | 4 |
| Large | 0x100 - 0x3FF | 2 |
| Huge | >= 0x400 | 0 |

## All Functions

| # | Address | Name | Size | Type Info |
|---|---------|------|------|-----------|
| 1 | `0x443620` | `Phyre_Memory_Allocate` | `0x14d` (333 bytes) | RTTI |
| 2 | `0x58c250` | `Phyre_Memory_AllocateAlignedBuffer` | `0x325` (805 bytes) | RTTI |
| 3 | `0x443a70` | `Phyre_Memory_Compare` | `0x5d` (93 bytes) | RTTI |
| 4 | `0x4438e0` | `Phyre_Memory_Copy` | `0x18` (24 bytes) | RTTI |
| 5 | `0x9f09e0` | `Phyre_Memory_CopyBytes` | `0x65` (101 bytes) | RTTI |
| 6 | `0x4306b0` | `Phyre_Memory_CopyDouble` | `0x5` (5 bytes) | RTTI |
| 7 | `0x4305f0` | `Phyre_Memory_CopyWord` | `0x6` (6 bytes) | RTTI |
| 8 | `0x443b10` | `Phyre_Memory_DebugCheck` | `0x98` (152 bytes) | RTTI |
| 9 | `0x443960` | `Phyre_Memory_Fill` | `0x17` (23 bytes) | RTTI |
| 10 | `0x430680` | `Phyre_Memory_FillWord` | `0x5` (5 bytes) | RTTI |
| 11 | `0x443770` | `Phyre_Memory_Free` | `0x2d` (45 bytes) | RTTI |
| 12 | `0x443900` | `Phyre_Memory_Move` | `0x1b` (27 bytes) | RTTI |
| 13 | `0x4438b0` | `Phyre_Memory_Reallocate` | `0x30` (48 bytes) | RTTI |
| 14 | `0x443a00` | `Phyre_Memory_Set` | `0x65` (101 bytes) | RTTI |
| 15 | `0x4305e0` | `Phyre_Memory_Zero` | `0x5` (5 bytes) | RTTI |


> **Note:** The requested prefix `Phyre_PPmemory_*` has 0 matches in the binary. 
> The actual naming convention in FFX.exe is `Phyre_Memory_*` (15 functions).
> See also: `Phyre_PStream_*` (3 ctor/dtor functions) for the variant with extra letter.
