# FFX PS2 Binary Format Analysis: .sbin, .rbin, .dcp, .sps2

**Date:** 2026-07-28
**Source:** `D:/FFX Extracted/FFX/ffx_ps2/ffx/master/`
**Scope:** All samples (10 .sbin, 10 .rbin, 10 .dcp, 130 .sps2)

---

## Table of Contents

1. [Overview and File Inventory](#1-overview-and-file-inventory)
2. [.sbin -- Sprite/Texture Binary](#2-sbin--spritetexture-binary)
3. [.rbin -- Resource Binary Stub](#3-rbin--resource-binary-stub)
4. [.dcp -- Macro Dictionary Container](#4-dcp--macro-dictionary-container)
5. [.sps2 -- PS2 Shader/Presentation Binary](#5-sps2--ps2-shaderpresentation-binary)
6. [Cross-Format Relationships](#6-cross-format-relationships)
7. [Locale Variants](#7-locale-variants)

---

## 1. Overview and File Inventory

All files reside under `jppc/help/` (Japanese pre-complete) or `new_XXpc/help/` (localized versions).

### File counts and sizes

| Format | Count | Min Size | Max Size | Notes |
|--------|-------|----------|----------|-------|
| .sbin  | 10    | 198,704  | 659,536  | 5 base names x 2 folders (help, help_inter) |
| .rbin  | 10    | 16       | 16       | All identical 16-byte stubs |
| .dcp   | 10    | 11,594   | 23,248   | 1 per locale, all named macrodic.dcp |
| .sps2  | 130   | 10,815   | 827,136  | 5 base names x ~26 variants across locales |

### Base file names

| Name | Purpose |
|------|---------|
| dvdcopy | DVD copy protection screen |
| mon_boku | Monster bestiary/bestiary menu |
| now_help | Current help/tutorial overlay |
| s_monitor | System monitor/debug display |
| test_proj | Test project (identical help/help_inter) |

### Folder structure

```
jppc/               -- Japanese (original PS2 build)
  help/             -- Help system files (sbin+rbin+sps2)
  help_inter/       -- Internationalized help (sbin+rbin+sps2, localized content)
new_jppc/           -- New Japanese PC port
new_chpc/           -- Chinese PC port
new_depc/           -- German PC port
new_frpc/           -- French PC port
new_itpc/           -- Italian PC port
new_krpc/           -- Korean PC port
new_sppc/           -- Spanish PC port
new_uspc/           -- US English PC port
uspc/               -- US English (original)
```

---

## 2. .sbin -- Sprite/Texture Binary

### Purpose

Container for indexed-color sprite/texture pages used by the FFX PS2 help/menu system. Each .sbin holds one or more pages of pixel data with associated metadata (dimensions, palette references).

### Header Structure (16 bytes)

```c
struct SBinHeader {        // All values little-endian
    uint32_t version;      // Always 1
    uint32_t page_count;   // Number of pages (1-4 observed)
    uint32_t reserved[2];  // Always 0
};
// Immediately followed by page_count page descriptors (16 bytes each)
```

### Page Descriptor (16 bytes, repeated page_count times)

```c
struct SBinPageDescriptor {
    uint16_t width;        // Page width (256 or 512 observed)
    uint16_t height;       // Page height (128, 256, or 512 observed)
    uint16_t sentinel_a;   // Always 0xFF08
    uint16_t sentinel_b;   // Always 0xFFFF
    uint16_t data_offset;  // Byte offset to page pixel data within file
    uint16_t page_index;   // Page index within this file (0-based)
    uint16_t data_end;     // Byte offset to end of page data
    uint16_t page_index2;  // Duplicate of page_index
};
```

### Sample Header Dumps

**dvdcopy.sbin** (2 pages, 198,704 bytes):
```
Offset  Hex                                              Interpretation
0000:   01 00 00 00 02 00 00 00  00 00 00 00 00 00 00 00   ver=1, pages=2, zeros
0010:   00 02 00 01 08 ff ff ff  30 00 00 00 30 04 00 00   Page[0]: 512x256, off=0x30, end=0x430
0020:   00 02 80 00 08 ff ff ff  30 04 02 00 30 08 02 00   Page[1]: 512x128, off=0x430, end=0x830
```

**mon_boku.sbin** (4 pages, 659,536 bytes):
```
Offset  Hex                                              Interpretation
0000:   01 00 00 00 04 00 00 00  00 00 00 00 00 00 00 00   ver=1, pages=4, zeros
0010:   00 02 00 02 08 ff ff ff  50 00 00 00 50 04 00 00   Page[0]: 512x512, off=0x50, end=0x450
0020:   00 02 00 02 08 ff ff ff  50 04 04 00 50 08 04 00   Page[1]: 512x512, off=0x450, end=0x850
0030:   00 01 00 01 08 ff ff ff  50 08 08 00 50 0c 08 00   Page[2]: 256x256, off=0x850, end=0xC50
0040:   00 01 00 01 08 ff ff ff  50 0c 09 00 50 10 09 00   Page[3]: 256x256, off=0xC50, end=0x1050
```

**now_help.sbin** (1 page, 263,200 bytes):
```
0010:   00 02 00 02 08 ff ff ff  20 00 00 00 20 04 00 00   Page[0]: 512x512, off=0x20, end=0x420
```

### Observed Page Sizes

| File | Pages | Dimensions | Data per page | Total pixel data |
|------|-------|-----------|---------------|------------------|
| dvdcopy.sbin | 2 | 512x256 + 512x128 | 1,024 each | 2,048 |
| mon_boku.sbin | 4 | 512x512 + 512x512 + 256x256 + 256x256 | 1,024 each | 4,096 |
| now_help.sbin | 1 | 512x512 | 1,024 | 1,024 |
| s_monitor.sbin | 1 | 512x512 | 1,024 | 1,024 |
| test_proj.sbin | 2 | 512x256 + 512x128 | 1,024 each | 2,048 |

**Key observation:** The page descriptor `data_offset`/`data_end` values only cover a small metadata portion at the start of the file. The actual pixel data extends far beyond. For mon_boku.sbin (659,536 bytes), the page table ends at offset 0x1050 (4,176 bytes), leaving 655,360 bytes of pixel data.

### Pixel Data Encoding

- **Palette/indexed color** -- Byte values range 0x00-0xFF (256-color palette)
- **50%+ zeros** in most files (transparency/empty regions)
- Byte distribution shows diverse values 0x00-0xFF, consistent with palette indices
- help vs help_inter differ in pixel data content (localized graphics)

### help vs help_inter

| File | Identical? |
|------|-----------|
| dvdcopy.sbin | YES (identical) |
| test_proj.sbin | YES (identical) |
| mon_boku.sbin | NO (different pixel data, same structure) |
| now_help.sbin | NO (different pixel data, same structure) |
| s_monitor.sbin | NO (different pixel data, same structure) |

First difference in mon_boku.sbin: offset 0x80854 (526,420 bytes in) -- deep in the pixel data, not in headers.

---

## 3. .rbin -- Resource Binary Stub

### Purpose

Minimal 16-byte placeholder/stub files. Likely a resource reference or index that was never populated for the help system, or a flag file indicating the presence of associated .sbin/.sps2 resources.

### Complete Contents (all 10 files identical)

```
Offset  Hex
0000:   01 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
```

### Structure

```c
struct RBinStub {
    uint32_t version;      // Always 1
    uint32_t reserved[3];  // Always 0 (12 bytes)
};
```

### Key Facts

- All 10 files (5 names x 2 folders) are byte-for-byte identical
- 16 bytes exactly -- too small to contain any real data
- Version 1 matches .sbin and .sps2 version numbers
- Likely a resource manifest entry or allocation stub

---

## 4. .dcp -- Macro Dictionary Container

### Purpose

Locale-specific macro dictionary files used by the FFX menu/help system. Each locale has exactly one `macrodic.dcp` in its `menu/` folder. Contains encoded text or command macros with an offset lookup table.

### File Inventory

| Locale | Size | Notes |
|--------|------|-------|
| jppc (Japanese) | 23,248 | Original |
| uspc (US English) | 19,408 | Original |
| new_jppc | 11,594 | New Japanese PC |
| new_chpc (Chinese) | 11,955 | |
| new_depc (German) | 19,502 | |
| new_frpc (French) | 19,615 | |
| new_itpc (Italian) | 20,463 | |
| new_krpc (Korean) | 11,916 | |
| new_sppc (Spanish) | 20,818 | |
| new_uspc (US English) | 14,625 | New US PC |

### Header Structure (64 bytes)

```c
struct DCPHeader {              // All values little-endian
    uint32_t zero_pad[6];       // Bytes 0x00-0x17: always 0
    uint32_t section0_offset;   // 0x18: Offset to first section (always 0x40)
    uint32_t section0_size;     // 0x1C: Size of first section
    uint32_t section1_offset;   // 0x20: Offset to second section
    uint32_t section1_pad;      // 0x24: Often 0 or section1-related
    uint32_t section2_offset;   // 0x28: Usually 0
    uint32_t section2_size;     // 0x2C: Section data size
    uint32_t section3_offset;   // 0x30: Usually 0
    uint32_t section3_size;     // 0x34: Section data size
    uint32_t reserved[2];       // 0x38-0x3F: Always 0
};
```

### Sample Headers

**jppc macrodic.dcp** (23,248 bytes):
```
0000:   00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00   zero padding
0010:   00 00 00 00 00 00 00 00  40 00 00 00 40 06 00 00   sec0: off=0x40, size=0x640
0020:   00 0e 00 00 d0 1a 00 00  00 00 00 00 f0 1a 00 00   sec1: off=0xe00, data=0x1ad0
0030:   00 00 00 00 80 56 00 00  00 00 00 00 00 00 00 00   sec2/3 sizes
```

**new_uspc macrodic.dcp** (14,625 bytes):
```
0000:   00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
0010:   00 00 00 00 00 00 00 00  40 00 00 00 25 06 00 00   sec0: off=0x40, size=0x625
0020:   0b 0c 00 00 00 00 00 00  00 00 00 00 61 14 00 00   sec1: off=0xc0b, size=0x1461
0030:   00 00 00 00 02 35 00 00  00 00 00 00 00 00 00 00   sec2/3
```

### Data Layout

#### Section 0 (Offset Table) -- starts at 0x40

Contains pairs of uint16 values that are increasing offsets pointing into the encoded data sections:

```
jppc @ 0x40:  ac01 b201 b801 b801 bc01 bc01 c001 c001
              = 0x01AC, 0x01B2, 0x01B8, 0x01B8, 0x01BC, 0x01BC, 0x01C0, 0x01C0
```

These offsets (0x01AC = 428, 0x01B2 = 434, etc.) point to entries within the same section or into the data section. Each pair appears to be (start_offset, end_offset) for consecutive macro entries.

#### Section 1 (Macro Data) -- varies per locale

Contains the actual encoded macro data. The byte patterns suggest a custom encoding:
- Some bytes appear to be characters shifted or XORed
- Repetitive patterns suggest dictionary-compressed text
- The name "macrodic" strongly implies "macro dictionary"

### Locale Size Correlation

Larger files (jppc 23KB, sppc 20KB, itpc 20KB) correlate with larger character sets (Japanese Kanji, accented European characters), while simpler scripts (Korean 11KB, Chinese 11KB, new_jppc 11KB) are smaller -- though Chinese/Korean being smaller suggests the "new" variants may use a different encoding or subset.

---

## 5. .sps2 -- PS2 Shader/Presentation Binary

### Purpose

PS2-specific shader/presentation binary format. Contains VU microcode or GS (Graphics Synthesizer) settings for rendering the help/menu system sprites. The "sps2" suffix likely means "SPS2 = Sprite/Shader Presentation System 2" or similar Square Enix internal naming.

### File Inventory

130 files total across all locales. Two distinct structural variants:

| Variant | Description | Examples |
|---------|-------------|----------|
| **Full** (code + data) | Has block table, shader code, and data section | jppc/help/*.sps2 |
| **Data-only** | No shader programs, just offset tables + data | new_XXpc/help/*/[name].sps2 |

### Header Structure (36 bytes fixed)

```c
struct SPS2Header {             // All values little-endian
    uint32_t version;           // Always 1
    uint32_t num_blocks;        // Number of shader blocks (0 for data-only)
    uint32_t data_offset;       // Offset to data section
    uint32_t header_size;       // Size of this header (always 0x24 = 36)
    uint32_t code_offset;       // Offset to code/shader section
    uint32_t code_size;         // Size or metadata for code section
    uint32_t checksum_a;        // Checksum or signature (0xCCCCCCCC if unused)
    uint32_t checksum_b;        // Checksum or signature (0xCCCCCCCC if unused)
};
```

### Sample Headers

**Full variant (jppc/help/dvdcopy.sps2, 39,992 bytes):**
```
0000:   01 00 00 00 06 00 00 00  20 2d 00 00 24 00 00 00
        ver=1, blocks=6, data_off=0x2d20, hdr_size=0x24
0010:   84 00 00 00 38 9c 00 00  cc cc cc cc cc cc cc cc
        code_off=0x84, code_size=0x9c38, checksums=0xCCCCCCCC
```

**Full variant (jppc/help/mon_boku.sps2, 821,488 bytes):**
```
0000:   01 00 00 00 1f 00 00 00  80 25 01 00 24 00 00 00
        ver=1, blocks=31, data_off=0x12580, hdr_size=0x24
0010:   84 03 00 00 b0 6d 0c 00  e0 b8 95 81 94 88 e3 01
        code_off=0x384, code_size=0xc6db0, checksum_a=0x8195b8e0
0020:   10 4d 70 c9 00 00 00 02  00 00 00 02 00 00 ff ff
        checksum_b=0xc9704d10, block[0] starts here
```

**Data-only variant (new_chpc/help/dvdcopy/dvdcopy.sps2, 10,992 bytes):**
```
0000:   01 00 00 00 00 00 00 00  f0 2a 00 00 00 00 00 00
        ver=1, blocks=0, data_off=0x2af0=file_size, hdr_size=0
0010:   24 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
        code_off=0x24, code_size=0, all zeros
```

### Block Table

Follows immediately after the header (at offset 0x24 for full variant, or after the 0x24-byte header for data-only).

Block table size = `code_offset - 0x24` bytes.

#### Block Entry Format (16 bytes, for simple blocks)

```c
struct SPS2BlockEntry {
    uint16_t field_0;           // Block type or parameter
    uint16_t field_2;           // Size or parameter (0x0200 common)
    uint16_t field_4;           // Often 0
    uint16_t field_6;           // Size or parameter
    uint16_t field_8;           // Often 0 or index
    uint16_t sentinel;          // Always 0xFFFF
    uint16_t field_C;           // Parameter
    uint16_t field_E;           // Parameter
};
```

**dvdcopy.sps2 block table (6 entries):**
```
block[0]: 0000 0200 0000 00d0 0000 ffff 004f 0102
block[1]: 0000 00d0 0000 ffff 0115 0200 0000 00d0
block[2]: 0000 ffff 0000 0200 0000 005e 0001 ffff
block[3]: 0000 0200 0000 0029 0001 ffff 0000 0200
block[4]: 0029 0049 0001 ffff 0000 00c4 0049 005c
block[5]: 0001 ffff 0104 0138 0050 0074 0001 ffff
```

**mon_boku.sps2 block table (31 entries, first 10):**
```
block[0]:  0000 0200 0000 0200 0000 ffff 0000 01ff
block[1]:  0000 019f 0000 ffff 0000 0200 0000 0200
block[2]:  0001 ffff 0000 01ff 0000 019f 0001 ffff
block[3]:  0000 0100 0000 0100 0002 ffff 0000 002b
block[4]:  0000 0021 0002 ffff 002c 0047 0000 001c
block[5]:  0002 ffff 0048 0065 0000 001c 0002 ffff
block[6]:  0066 00eb 0000 0016 0002 ffff 0066 00eb
block[7]:  0000 0016 0002 ffff 0066 00eb 0000 0016
block[8]:  0002 ffff 0066 00eb 0000 0016 0002 ffff
block[9]:  0066 00eb 0000 0016 0002 ffff 0066 00eb
```

**Pattern:** 0xFFFF is a sentinel. Entries with repeated values (e.g., blocks 6-9 in mon_boku all `0066 00eb 0000 0016 0002 ffff`) suggest repeated shader programs or texture references.

### Code Section

Starts at `code_offset` (typically 0x84 for simple files, 0x384 for complex ones).

The code section begins with an **offset table** -- a series of uint32 values that are increasing offsets into the code section itself:

**dvdcopy.sps2 code offset table (70 entries):**
```
[0]=412, [1]=709, [2]=1283, [3]=1290, [4]=1306, [5]=1314, ...
[66]=10836, [67]=11013, [68]=11190, [69]=11367
```

These offsets point to individual shader programs or code blocks within the section.

### Code Block Content

The actual code at each offset contains what appears to be PS2 VU (Vector Unit) microcode or GS register settings:

**dvdcopy.sps2 code[0] @ 0x0220:**
```
88 00 00 00 00 00 00 00  02 00 00 00 0b f1 0b f6
01 00 01 00 00 00 cc cc  02 00 00 00 0b f7 60 3e
```

The `0xCC` bytes appear as padding/no-op markers throughout the code section.

### Data Section

Starts at `data_offset`. Contains a secondary offset table followed by texture/sprite data:

**dvdcopy.sps2 data section start:**
```
2d20:   50 2d 00 00 0b 00 ff ff  b8 3a 00 00 06 00 ff ff
2d30:   08 42 00 00 08 00 ff ff  c8 4b 00 00 34 00 ff ff
```

Format: `uint32 offset, uint16 size, uint16 0xFFFF` repeated. These are self-referencing offsets into the data section itself, each pointing to a texture or data block with its size.

### Data-Only Variant

The `new_XXpc/help/[name]/[name].sps2` files (as opposed to `[name]_page.sps2`) have:
- `num_blocks = 0`
- `code_size = 0`
- `header_size = 0`
- `data_offset = file_size` (the entire file IS the data section)

These appear to be stripped versions containing only the texture/sprite data without the shader programs, used by the PC port which has its own rendering pipeline.

### Size Summary

| File | Variant | Blocks | Code Size | Data Offset |
|------|---------|--------|-----------|-------------|
| dvdcopy.sps2 | Full | 6 | 39,992 | 11,552 |
| mon_boku.sps2 | Full | 31 | 814,512 | 75,136 |
| now_help.sps2 | Full | 155 | 763,360 | 31,728 |
| s_monitor.sps2 | Full | 34 | 120,232 | 11,696 |
| test_proj.sps2 | Full | 5 | 37,272 | 10,400 |
| new_chpc/dvdcopy.sps2 | Data-only | 0 | 0 | 10,992 |
| new_chpc/mon_boku.sps2 | Data-only | 0 | 0 | 74,453 |

---

## 6. Cross-Format Relationships

### The Help System Pipeline

```
.rbin (resource stub, 16B)     -- Resource allocation/reference
  |
  +-> .sbin (sprite pages)     -- Indexed pixel data for menu/help graphics
  |
  +-> .sps2 (shader + texture) -- PS2 rendering instructions + texture data
        |
        +-> _page.sps2         -- Full shader+data (PS2 render)
        +-> [name].sps2        -- Data-only (PC port, stripped shader)
```

### Naming Convention

- `.sbin` and `.sps2` share the same base names (dvdcopy, mon_boku, etc.)
- `.rbin` also shares the same base names
- All three formats coexist in the same directory
- This suggests a 1:1:1 mapping where each resource has a sprite binary, a resource reference, and a shader/presentation binary

### Version Consistency

All three formats use version field = 1 as their first uint32.

### help vs help_inter

The `help_inter` (international) folder contains the same file set as `help` but with localized content:
- .sbin: Same structure, different pixel data (localized text as bitmap)
- .rbin: Identical (structural stub)
- .sps2: Same structure, different shader/data content (localized)

### new_XXpc Variants

The PC port folders contain only .sps2 files (no .sbin or .rbin), split into:
- `[name]_page.sps2` -- Full shader+data (identical to jppc version)
- `[name].sps2` -- Data-only (PC-specific, stripped of PS2 shaders)
- `gcm/gnm/gxm/` subfolders -- Platform-specific shader variants (PS3/PS2/PS Vita)

---

## 7. Locale Variants

### DCP Size by Locale

```
jppc    23,248 bytes  (Japanese, original -- largest character set)
sppc    20,818        (Spanish)
itpc    20,463        (Italian)
frpc    19,615        (French)
depc    19,502        (German)
uspc    19,408        (US English, original)
uspc    14,625        (US English, new PC -- smaller, possibly compressed)
chpc    11,955        (Chinese)
krpc    11,916        (Korean)
jppc    11,594        (Japanese, new PC -- smallest)
```

### SPS2 Locale Coverage

Each of the 5 base names exists in up to 26 variants:
- 1x jppc/help (original Japanese)
- 1x jppc/help_inter (international Japanese)
- 8x new_XXpc/help (PC ports: JP, CN, DE, FR, IT, KR, SP, US)
  - Each with up to 5 sub-variants: [name].sps2, [name]_page.sps2, gcm/, gnm/, gxm/

### _page.sps2 Size Consistency

The `_page.sps2` files maintain consistent sizes across locales (identical shader code, only data differs):
- dvdcopy_page.sps2: 39,992-39,656 bytes (jppc vs others)
- mon_boku_page.sps2: 821,488 bytes (identical across all locales)
- now_help_page.sps2: 766,224 bytes (identical across all locales)
- s_monitor_page.sps2: 120,896 bytes (identical across all locales)

This confirms the shader programs are shared; only the localized texture data varies.

---

## Appendix A: Magic Numbers and Sentinels

| Value | Context | Meaning |
|-------|---------|---------|
| 0xFF08 | .sbin page descriptor [2] | Page type/sentinel |
| 0xFFFF | .sbin page descriptor [3], .sps2 block entries | End-of-entry sentinel |
| 0xCCCCCCCC | .sps2 header [18-1F] | Unused checksum slot (MSVC debug fill) |
| 0xCC | .sps2 code section | No-op/padding byte (PS2 VU convention) |
| 0x01 | All formats [00] | Version number |

## Appendix B: Raw Hex Dumps

### dvdcopy.sbin (first 128 bytes)
```
00000000: 0100 0000 0200 0000 0000 0000 0000 0000  ................
00000010: 0002 0001 08ff ffff 3000 0000 3004 0000  ........0...0...
00000020: 0002 8000 08ff ffff 3004 0200 3008 0200  ........0...0...
00000030: 0000 0000 0000 000a 0000 001d 0000 0028  ...............(
00000040: 0000 0038 0202 0211 1111 117e 1515 151e  ...8.......~....
00000050: 1d1d 1d7e 1f1f 1f80 2121 217e 2222 225b  ...~....!!!~"""[
00000060: 2222 2280 2323 237e 2525 2514 2626 2629  """.###~%%%.&&&)
00000070: 1515 152c 1616 1660 1616 167e 1919 193c  ...,...`...~...<
```

### dvdcopy.rbin (complete, 16 bytes)
```
00000000: 0100 0000 0000 0000 0000 0000 0000 0000  ................
```

### jppc macrodic.dcp (first 128 bytes)
```
00000000: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000010: 0000 0000 0000 0000 4000 0000 4006 0000  ........@...@...
00000020: 000e 0000 d01a 0000 0000 0000 f01a 0000  ................
00000030: 0000 0000 8056 0000 0000 0000 0000 0000  .....V..........
00000040: ac01 b201 b801 b801 bc01 bc01 c001 c001  ................
00000050: c701 d201 dd01 dd01 e001 e001 e501 e501  ................
00000060: e901 e901 ee01 ee01 f301 f301 f701 f701  ................
00000070: fd01 fd01 0302 0302 0702 0702 0b02 0b02  ................
```

### dvdcopy.sps2 (first 128 bytes)
```
00000000: 0100 0000 0600 0000 202d 0000 2400 0000  ........ -..$...
00000010: 8400 0000 389c 0000 cccc cccc cccc cccc  ....8...........
00000020: cccc cccc 0000 0002 0000 d000 0000 ffff  ................
00000030: 4f00 0201 0000 d000 0000 ffff 1501 0002  O...............
00000040: 0000 d000 0000 ffff 0000 0002 0000 5e00  ..............^.
00000050: 0100 ffff 0000 0002 0000 2900 0100 ffff  ..........).....
00000060: 0000 0002 2900 4900 0100 ffff 0000 c400  ....).I.........
00000070: 4900 5c00 0100 ffff 0401 3801 5000 7400  I.\.......8.P.t.
```

---

*Analysis by Jarvis (Verboo Code Worker). All hex dumps from raw binary examination of extracted FFX PS2 master files.*
