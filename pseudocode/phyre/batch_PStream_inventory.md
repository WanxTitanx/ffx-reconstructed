# Inventory: Phyre_Stream_*

**Database:** ffxoficial.exe.i64 (FFX.exe)
**Query filter:** `Phyre_Stream_*`
**Generated:** 2026-07-27

## Summary

- **Total functions:** 65
- **Address range:** 0x433bf0 - 0x9f2580
- **Size range:** 0x3 (3 bytes) - 0x3dc (988 bytes)
- **Average size:** 0x8f (143 bytes)
- **Total bytes:** 9314 bytes

## Size Distribution

| Bucket | Range | Count |
|--------|-------|-------|
| Tiny | < 0x10 bytes | 4 |
| Small | 0x10 - 0x3F | 22 |
| Medium | 0x40 - 0xFF | 30 |
| Large | 0x100 - 0x3FF | 9 |
| Huge | >= 0x400 | 0 |

## All Functions

| # | Address | Name | Size | Type Info |
|---|---------|------|------|-----------|
| 1 | `0x434310` | `Phyre_Stream_Close` | `0x104` (260 bytes) | RTTI |
| 2 | `0x434640` | `Phyre_Stream_CopyTo` | `0x239` (569 bytes) | RTTI |
| 3 | `0x434880` | `Phyre_Stream_Field4_getter` | `0x4` (4 bytes) | RTTI |
| 4 | `0x434890` | `Phyre_Stream_Field4_getter_0` | `0x4` (4 bytes) | RTTI |
| 5 | `0x9f24e0` | `Phyre_Stream_FileFormat_Check` | `0x17` (23 bytes) | RTTI |
| 6 | `0x9f2560` | `Phyre_Stream_FileFormat_Next` | `0x11` (17 bytes) | RTTI |
| 7 | `0x9f2580` | `Phyre_Stream_FileFormat_Process` | `0xf9` (249 bytes) | RTTI |
| 8 | `0x9f23f0` | `Phyre_Stream_FileFormat_Read` | `0x7a` (122 bytes) | RTTI |
| 9 | `0x9f2500` | `Phyre_Stream_FileFormat_Skip` | `0x3` (3 bytes) | RTTI |
| 10 | `0x4341a0` | `Phyre_Stream_Flush` | `0x21` (33 bytes) | RTTI |
| 11 | `0x435980` | `Phyre_Stream_FlushBuffer` | `0x2e` (46 bytes) | RTTI |
| 12 | `0x4356e0` | `Phyre_Stream_GetBuffer` | `0x27` (39 bytes) | RTTI |
| 13 | `0x435710` | `Phyre_Stream_GetBufferSize` | `0x37` (55 bytes) | RTTI |
| 14 | `0x66f470` | `Phyre_Stream_GetByteFlag` | `0x7` (7 bytes) | RTTI |
| 15 | `0x434a10` | `Phyre_Stream_GetElementOffset_V3` | `0x4c` (76 bytes) | RTTI |
| 16 | `0x6da320` | `Phyre_Stream_GetLineCount` | `0x33` (51 bytes) | RTTI |
| 17 | `0x4340d0` | `Phyre_Stream_GetSize` | `0x98` (152 bytes) | RTTI |
| 18 | `0x434460` | `Phyre_Stream_IsEOF` | `0x3d` (61 bytes) | RTTI |
| 19 | `0x433bf0` | `Phyre_Stream_Open` | `0x18f` (399 bytes) | RTTI |
| 20 | `0x4353f0` | `Phyre_Stream_Printf` | `0x9e` (158 bytes) | RTTI |
| 21 | `0x562bf0` | `Phyre_Stream_Printf_w` | `0x12` (18 bytes) | RTTI |
| 22 | `0x5cbcf0` | `Phyre_Stream_Printf_w_0` | `0x12` (18 bytes) | RTTI |
| 23 | `0x49bed0` | `Phyre_Stream_Printf_w_1` | `0x12` (18 bytes) | RTTI |
| 24 | `0x49bef0` | `Phyre_Stream_Printf_w_2` | `0x12` (18 bytes) | RTTI |
| 25 | `0x511510` | `Phyre_Stream_Printf_w_3` | `0x12` (18 bytes) | RTTI |
| 26 | `0x594a60` | `Phyre_Stream_Printf_w_4` | `0x12` (18 bytes) | RTTI |
| 27 | `0x6f9ac0` | `Phyre_Stream_Printf_w_5` | `0x12` (18 bytes) | RTTI |
| 28 | `0x435490` | `Phyre_Stream_PrintfArgs` | `0x67` (103 bytes) | RTTI |
| 29 | `0x6234d0` | `Phyre_Stream_PrintLine` | `0x19` (25 bytes) | RTTI |
| 30 | `0x433d80` | `Phyre_Stream_Read` | `0x85` (133 bytes) | RTTI |
| 31 | `0x9f0ae0` | `Phyre_Stream_Read_Small` | `0x7a` (122 bytes) | RTTI |
| 32 | `0x9f0d20` | `Phyre_Stream_ReadBlock` | `0xdf` (223 bytes) | RTTI |
| 33 | `0x6058f0` | `Phyre_Stream_ReadFile` | `0x118` (280 bytes) | RTTI |
| 34 | `0x434dd0` | `Phyre_Stream_ReadFloat` | `0x7f` (127 bytes) | RTTI |
| 35 | `0x434d50` | `Phyre_Stream_ReadInt` | `0x7f` (127 bytes) | RTTI |
| 36 | `0x4344c0` | `Phyre_Stream_ReadLine` | `0x6e` (110 bytes) | RTTI |
| 37 | `0x4355f0` | `Phyre_Stream_ReadLineWide` | `0x2e` (46 bytes) | RTTI |
| 38 | `0x9f0b60` | `Phyre_Stream_ReadMulti` | `0xf3` (243 bytes) | RTTI |
| 39 | `0x60b010` | `Phyre_Stream_ReadPairVarints` | `0x32` (50 bytes) | RTTI |
| 40 | `0x44ca40` | `Phyre_Stream_ReadPString` | `0x11c` (284 bytes) | RTTI |
| 41 | `0x9f0c80` | `Phyre_Stream_ReadSegment` | `0x97` (151 bytes) | RTTI |
| 42 | `0x434f40` | `Phyre_Stream_ReadString` | `0x70` (112 bytes) | RTTI |
| 43 | `0x435750` | `Phyre_Stream_ReadToEnd` | `0xd4` (212 bytes) | RTTI |
| 44 | `0x435920` | `Phyre_Stream_ReadToEnd_wrapper` | `0x17` (23 bytes) | RTTI |
| 45 | `0x60adc0` | `Phyre_Stream_ReadVarint` | `0x48` (72 bytes) | RTTI |
| 46 | `0x433ed0` | `Phyre_Stream_Seek` | `0x82` (130 bytes) | RTTI |
| 47 | `0x60cbd0` | `Phyre_Stream_UnpackArray_AllPresent` | `0x5b` (91 bytes) | RTTI |
| 48 | `0x60cd30` | `Phyre_Stream_UnpackArray_Bitmasked28` | `0xa1` (161 bytes) | RTTI |
| 49 | `0x60cc80` | `Phyre_Stream_UnpackArray_Bitmasked4` | `0xad` (173 bytes) | RTTI |
| 50 | `0x60cc30` | `Phyre_Stream_UnpackArrayCopy` | `0x48` (72 bytes) | RTTI |
| 51 | `0x60cf10` | `Phyre_Stream_UnpackCountsAndData28` | `0x115` (277 bytes) | RTTI |
| 52 | `0x60cde0` | `Phyre_Stream_UnpackCountsAndData4` | `0x129` (297 bytes) | RTTI |
| 53 | `0x60d100` | `Phyre_Stream_UnpackDataRemainder28` | `0xb8` (184 bytes) | RTTI |
| 54 | `0x60d030` | `Phyre_Stream_UnpackDataRemainder4` | `0xc1` (193 bytes) | RTTI |
| 55 | `0x60d1c0` | `Phyre_Stream_UnpackDataWithCallback` | `0x73` (115 bytes) | RTTI |
| 56 | `0x60d240` | `Phyre_Stream_UnpackDataWithCallback_v2` | `0x6b` (107 bytes) | RTTI |
| 57 | `0x60a500` | `Phyre_Stream_UnpackValue` | `0x3dc` (988 bytes) | RTTI |
| 58 | `0x60a910` | `Phyre_Stream_UnpackValue_v2` | `0x3bb` (955 bytes) | RTTI |
| 59 | `0x433e40` | `Phyre_Stream_Write` | `0x85` (133 bytes) | RTTI |
| 60 | `0x435940` | `Phyre_Stream_WriteBuffer` | `0x3a` (58 bytes) | RTTI |
| 61 | `0x4352f0` | `Phyre_Stream_WriteFloat` | `0x5e` (94 bytes) | RTTI |
| 62 | `0x4351b0` | `Phyre_Stream_WriteInt` | `0x36` (54 bytes) | RTTI |
| 63 | `0x434530` | `Phyre_Stream_WriteLine` | `0xd0` (208 bytes) | RTTI |
| 64 | `0x435680` | `Phyre_Stream_WriteLineWide` | `0x36` (54 bytes) | RTTI |
| 65 | `0x435370` | `Phyre_Stream_WriteString` | `0x49` (73 bytes) | RTTI |


> **Note:** The requested prefix `Phyre_PPstream_*` has 0 matches in the binary. 
> The actual naming convention in FFX.exe is `Phyre_Stream_*` (65 functions).
> See also: `Phyre_PStream_*` (3 ctor/dtor functions) for the variant with extra letter.
