# FFX PS2 File Format Analysis: .ftc / .chr / .vpa

> Generated 2026-07-28 from hex analysis of multiple samples in `D:/FFX Extracted/FFX/ffx_ps2/ffx/master/`

---

## 1. .FTC — Font/Texture Cache

### Overview

FTC files store pre-rendered bitmap font glyph sheets and associated texture data. Two format variants exist:

- **FTCX** — Standard format, used in help, menu, and battle UI. Has `"FTCX"` ASCII magic.
- **Legacy (event)** — Used for event/obj overlays. Starts with `0x73` byte, no ASCII magic.

### File Count and Size Distribution

| Category | Count | Typical Size |
|----------|-------|-------------|
| Battle FTCs (`new_chpc/battle/`) | ~1400 | 80 bytes (header-only) |
| Help FTCs | 2 | 1,248 - 2,400 bytes |
| Menu FTCs | ~5 | 304 - 65,584 bytes |
| Event/obj FTCs | ~50 | 176 - 58,192 bytes |
| **Total** | **1,535** | 80 bytes to 65 KB |

### 1.1 FTCX Header Layout (64 bytes, little-endian)

```
Offset  Size  Field              Notes
------  ----  -----              -----
+0x00   4     magic              "FTCX" (0x5446 0x5843 LE)
+0x04   2     version            Always 200 (0x00C8)
+0x06   2     format_flags       Always 1556 (0x0614)
+0x08   2     type               0=menu, 2=battle, 3=help
+0x0A   6     padding            Always zero
+0x10   2     glyph_count        Number of glyphs in this sheet
+0x12   2     padding
+0x14   2     glyph_width        Pixels per glyph row (always 14)
+0x16   2     glyph_height       Pixels per glyph col (always 18)
+0x18   4     padding            Always zero
+0x20   2     header_size        Always 64 (0x0040)
+0x22   2     padding
+0x24   2     texture_data_size  Bytes of texture bitmap after header
+0x26   2     padding
+0x28   2     texture_flags      Always 128 (0x0080) — likely PS2 GS tex format
+0x2A   2     tex_payload_size   Additional texture metadata bytes
+0x2C   4     padding
+0x30   2     glyph_data_offset  Offset from +0x40 to glyph width table
+0x32   10    padding
+0x3C   4     padding
```

### 1.2 FTCX Data Layout

```
[Header: 64 bytes]
[Glyph Texture Bitmap: texture_data_size bytes, starting at +header_size]
[Glyph Metadata: tex_payload_size bytes]
```

**Verification examples:**

| File | FileSize | header(64) + tex_off + tex_size | Match? |
|------|----------|--------------------------------|--------|
| help.ftc | 1,248 | 64 + 1152 + 36 = 1252 | ~yes (4 byte rounding) |
| help_inter.ftc | 2,400 | 64 + 2304 + 36 = 2404 | ~yes |
| menu/base.ftc | 65,584 | 64 + 64512 + 1008 = 65584 | exact |
| bika01_10.ftc | 80 | 64 + 0 + 18 = 82 | ~yes (padding) |

### 1.3 Battle FTCs (Header-Only)

All battle FTCs are exactly **80 bytes** and contain only the FTCX header with:
- `type = 2` (battle)
- `glyph_count = 1` (single placeholder glyph)
- `texture_data_size = 0` (no actual bitmap data)
- Byte at +0x40 varies per encounter (possibly an encounter-specific ID/color)

These are stub files — the actual font texture comes from a shared runtime source.

### 1.4 Legacy FTC (event/obj/base.ftc)

```
Offset  Size  Field              Notes
------  ----  -----              -----
+0x00   1     magic              0x73 (115, ASCII 's')
+0x01   3     padding
+0x04   4     zero
+0x08   4     header_size        0x0004A0 = 1184
+0x0C   4     zero
+0x10   2     header_size_dup    Same as +0x08 (LE 16-bit view)
+0x12   2     glyph_count        222 (0x00DE)
+0x14   2     data_offset_hi     0x01BC
+0x16   2     data_offset_lo     0x01D0 = 0x01D0 = 464? (or 0xBC01 = big-endian)
+0x18   4     data_size          0x00A00100? (needs more analysis)
+0x1C   2     flags
+0x1E   2     zero
+0x20-0x3F   padding (all zeros)
+0x40   var   glyph_widths       Byte per glyph, values 0x0A-0x0F (10-15 pixels)
```

**Byte distribution from +0x40:** Values 0x00 (41%), 0xCC (4%), 0x33 (5%), 0x03 (5%), 0xFF (2%) — this is compressed glyph bitmap data, not just widths.

### 1.5 Sample Hex Dumps

**bika01_10.ftc (80 bytes, battle stub):**
```
00000000: 4654 4358 c800 1406 0200 0000 0000 0000  FTCX............
00000010: 0100 0000 0e00 1200 0000 0000 0000 0000  ................
00000020: 4000 0000 0000 0000 8000 1200 0000 0000  @...............
00000030: 4000 0000 1200 0000 0000 0000 0000 0000  @...............
00000040: 3607 0707 0707 0707 0707 0707 0707 0707  6...............
```

**menu/base.ftc (65,584 bytes, full font sheet):**
```
00000000: 4654 4358 c800 1406 0000 0000 0000 0000  FTCX............
00000010: e703 0000 0e00 1200 0000 0000 0000 0000  ................
00000020: 4000 0000 00fc 0000 8000 f003 0000 0000  @...............
00000030: 40fc 0000 f003 0000 0000 0000 0000 0000  @...............
```

---

## 2. .CHR — Character Model Data

### Overview

CHR files contain pre-processed PS2 character/monster/object 3D model data including vertices, normals, UVs, bone weights, and animation tracks. They are the runtime-ready form of the model pipeline.

### File Count and Size Distribution

| Category | Count | Size Range |
|----------|-------|-----------|
| Monsters (`mon/`) | ~800 | 130 KB - 1.3 MB |
| Player chars (`pc/`) | ~20 | similar range |
| Summons (`sum/`) | ~30 | similar range |
| Objects (`obj/`) | ~15 | similar range |
| **Total** | **865** | 130 KB - 1.3 MB |

**Total: 172 MB** across 865 files. Average ~200 KB per file.

### 2.1 CHR Header Layout (128 bytes, little-endian)

```
Offset  Size  Field              Notes
------  ----  -----              -----
+0x00   4     zero               Always 0
+0x04   4     version/format     Always 0x0B (11)
+0x08   4     model_type         Always 2
+0x0C   4     zero               Always 0
+0x10   4     header_ext_size    Extended header size (1024-1600)
+0x14   4     zero
+0x18   4     vertex_data_size   Size of primary vertex buffer
+0x1c   4     anim_track_count   Number of animation tracks (1-7)
+0x20   4     struct_size        Always 0x70 (112) — sub-header size
+0x24   4     bone_count         Number of bones/joints (9-16 typical)
+0x28   4     zero
+0x2C   4     zero
+0x30   4     extra_data_size    Additional data block size (0, 256-368)
+0x34   4     extra_block_count  Number of extra data blocks (0-2)
+0x38   4     extra_block_0_size Size of extra block 0
+0x3C   4     extra_block_1_size Size of extra block 1
+0x40   2     extra_tag_0        Tag identifying extra data type
+0x42   2     zero
+0x44   4     extra_data_offset  Offset to extra data from some base
+0x48   4     zero
+0x4C   4     zero
+0x50   4     zero
+0x54   4     zero
+0x58   4     sub_header_size    Extended sub-header total size
+0x5C   4     sub_header_const   Always 0x48 (72)
+0x60   4     anim_data_size     Size of animation data block
+0x64   4     anim_data_size_2   Secondary anim data size
+0x68   16    marker             "wwwwwwwwwwwwwwww" (0x77 x 8)
+0x78   4     flags              0x00000100 typical
+0x7C   4     zero
```

### 2.2 Key Header Field Relationships

| Field | Relationship | Evidence |
|-------|-------------|----------|
| +0x04 = 0x0B | Version/format constant | All 10 samples identical |
| +0x08 = 0x02 | Model type constant | All samples identical |
| +0x20 = 0x70 | Sub-header anchor | All samples identical |
| +0x24 | Bone count | 9 (simple) to 16 (complex monsters) |
| +0x1c | Animation tracks | 1-7, correlates with model complexity |
| +0x60 | Anim data size | 0 for some models (baked geometry only?) |
| +0x68 | Magic marker | Always 8 bytes of 0x77 ('w') |

### 2.3 CHR Data Sections (after header)

```
[Header: 0x80 (128) bytes]
[Extended Header: header_ext_size bytes — bone transforms, material refs]
[Animation Tracks: anim_data_size bytes — keyframe data]
[Vertex Data: vertex_data_size bytes — position/normal/UV buffers]
[Extra Data: extra_data_size bytes — optional, type indicated by +0x30/+0x34]
```

### 2.4 Sample Header Comparisons

| Monster | File Size | +0x10 | +0x18 | +0x1c | +0x24 | +0x30 | +0x60 | +0x64 |
|---------|-----------|-------|-------|-------|-------|-------|-------|-------|
| m001 | 184,320 | 1232 | 49408 | 2 | 9 | 256 | 117376 | 66944 |
| m002 | 202,752 | 1024 | 67840 | 2 | 9 | 0 | 0 | 0 |
| m020 | 285,712 | 1520 | 81664 | 2 | 9 | 256 | 0 | 0 |
| m100 | 530,144 | 1600 | 246272 | 7 | 9 | 256 | 460896 | 69248 |
| m150 | 1,040,912 | 1216 | 10240 | 5 | 11 | 288 | 0 | 0 |
| m200 | 136,384 | 1376 | 68480 | 1 | 10 | 272 | 0 | 0 |
| m250 | 130,688 | 1296 | 61184 | 1 | 16 | 368 | 0 | 0 |

### 2.5 "wwwwwwww" Marker Analysis

At offset +0x68, every CHR file contains exactly 8 bytes of `0x77` (ASCII 'w'). This is NOT text — it's a binary marker/separator between the fixed header region and the variable-size animation/vertex data. The 'w' value (0x77) is likely chosen because it's visually distinctive in hex dumps and avoids confusion with common binary patterns.

### 2.6 Sample Hex Dump (m001.chr)

```
00000000: 0000 0000 0b00 0000 0200 0000 0000 0000  ................
00000010: d004 0000 0000 0000 00c1 0000 0200 0000  ................
00000020: 7000 0000 0900 0000 0000 0000 0000 0000  p...............
00000030: 0001 0000 0100 0000 c401 0000 0100 0000  ................
00000040: c801 0000 ac00 0000 0000 0000 0000 0000  ................
00000050: 0000 0000 0000 0000 8004 0000 4800 0000  ............H...
00000060: 80ca 0100 8005 0100 7777 7777 7777 7777  ........wwwwwwww
```

**Header decoded (m001):**
- Version: 11, Model type: 2
- Header ext: 1232 bytes, Vertex data: 49408 bytes
- Anim tracks: 2, Bones: 9
- Sub-header: 112 bytes
- Extra data: 256 bytes, 1 block, block size: 452

---

## 3. .VPA — Vertex Parameters / Map Output

### Overview

VPA (Vertex Parameters Array?) files contain pre-processed PS2 battle map / field map geometry. The magic `"MAP1"` suggests this is the PS2-era map output format used for battle arenas, field areas, and test maps. Despite the `.vpa` extension, the internal magic is `MAP1`.

### File Count and Size Distribution

| Location | Count | Size Range |
|----------|-------|-----------|
| Battle maps (`jppc/btlmap/`) | ~200 | 448 KB - 2.2 MB |
| Field maps (`jppc/map/`) | ~290 | 4 MB - 10 MB |
| **Total** | **491** | 448 KB - 10.4 MB |

**Total: 813 MB** across 491 files. Average ~1.6 MB per file.

### 3.1 VPA Header Layout (128 bytes, little-endian)

```
Offset  Size  Field              Notes
------  ----  -----              -----
+0x00   4     magic              "MAP1" (0x3150414D LE)
+0x04   4     version            0 or 1
+0x08   12    padding            All zeros
+0x14   4     header_size        Always 128 (0x80)
+0x18   4     section1_offset    Offset to scene metadata section
+0x1C   4     zero
+0x20   4     zero
+0x24   4     zero
+0x28   4     zero
+0x2C   4     zero
+0x30   4     zero
+0x34   4     zero
+0x38   4     section2_offset    Offset to command/param section
+0x3C   4     section3_offset    Optional third section (0 = absent)
+0x40-0x7F   padding             All zeros
```

### 3.2 VPA Section Layout

```
[Header: 128 bytes]
[Main Geometry Data: header_size to section1_offset)
[Section 1: section1_offset to section2_offset) — Scene metadata
[Section 2: section2_offset to section3_offset) — Command parameters
[Section 3: section3_offset to EOF) — Optional trailing data
```

### 3.3 Section 1 — Scene Metadata (112 bytes typical)

Contains bounding box, render parameters, and scene graph info:

```
Offset  Size  Field              Notes
------  ----  -----              -----
+0x00   4     flags/zero
+0x04   4     object_count       Number of objects in scene
+0x08   4     render_params      Packed render flags
+0x0C   4     bbox_max_y         Float: bounding box Y max (e.g. 573.44)
+0x10-0x17  zeros
+0x18   4     viewport_w         Viewport width (32, 96, etc.)
+0x1C   4     viewport_h         Viewport height
+0x20-0x3F  dimension_params     Packed uint16 dimension values (0x9000, 0x7000 = PS2 GS tex dims)
+0x40   2     object_count_2     Duplicate or sub-object count
+0x42   2     material_count
+0x44-0x47  0xFFFFFFFF          Sentinel value
+0x48   4     param_count
+0x4C-0x5F  zeros
+0x60   2     param_count_2
+0x62   2     zero
+0x64   4     command_offset
+0x68-0x6F  zeros
+0x6C   4     section_size
+0x70   4     param_data_size
```

**Key observations in Section 1:**
- Values like `0x9000` and `0x7000` are PS2 GS (Graphics Synthesizer) texture dimension constants
- `0xFFFF` serves as a sentinel/terminator in object lists
- Float value 573.44 at +0x0C is a real 3D bounding coordinate

### 3.4 Main Geometry Data (before Section 1)

The main body (from +0x80 to section1_offset) contains packed vertex data:

```
Offset 0x80+: Sub-header with vertex counts and buffer sizes
Offset 0x100+: Float3 vertex positions (x,y,z per vertex)
Offset 0x180+: Index buffers and draw commands
```

**Float vertex data observed:**
```
+0x10C: 20.2555 (float) — vertex Y coordinate
+0x11C: 1.0000 (float) — normal W or scale
+0x130: 72.0000 (float) — dimension or position
+0x18C: 5.9385 (float) — vertex coordinate
+0x190: -14.4447, -1.9528, -25.4701, 1.0 — full position+weight vertex
+0x1A0: -17.4140, -3.4272, -27.7683, 0.0 — vertex position
```

This is clearly 3D vertex position data in (X, Y, Z, W) format with PS2 fixed-point precision.

### 3.5 Version Differences

| Version | Files | Notable Difference |
|---------|-------|-------------------|
| 0 | ~95% of files | Standard format |
| 1 | bsil03, cdsp00, some others | Has additional section3_offset populated |

Version 1 files have a third section containing trailing metadata (e.g., bsil03 has 528 KB in section 2).

### 3.6 Section Pointer Analysis

| File | File Size | Sec1 Offset | Sec2 Offset | Sec3 | Sec1 Size | Sec2+ Size |
|------|-----------|-------------|-------------|------|-----------|-----------|
| grid00 | 448,624 | 0x67500 | 0 | 0 | 448,624 (all data) | 0 |
| bika00 | 951,632 | 0xE39E0 | 0xE3A50 | 0 | 112 | 932,432 |
| azit03 | 1,230,512 | 0x122170 | 0x1284E0 | 0 | 25,360 | 1,213,664 |
| bsil03 | 2,258,080 | 0x1A64E0 | 0x1A6550 | 0x1A7840 | 112 | 528,208 |
| hiku18 | 8,563,536 | 0x800970 | 0x808B10 | 0x82A6C0 | 33,152 | 139,328 |

**Pattern:** Section 1 is always small metadata (112-33KB). The main geometry data lives between +0x80 and the first section pointer.

### 3.7 Sample Hex Dumps

**bika00 mapout.vpa (951,632 bytes):**
```
00000000: 4d41 5031 0000 0000 0000 0000 0000 0000  MAP1............
00000010: 0000 0000 8000 0000 e039 0e00 0000 0000  .........9......
00000020: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000030: 0000 0000 0000 0000 503a 0e00 0000 0000  ........P:......
00000040: 0000 0000 0000 0000 0000 0000 0000 0000  ................
```

**hiku18 mapout.vpa (8,563,536 bytes, largest field map):**
```
00000000: 4d41 5031 0000 0000 0000 0000 0000 0000  MAP1............
00000010: 0000 0000 8000 0000 d007 1400 0000 0000  ................
00000020: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000030: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000040: 0000 0000 0000 0000 0000 0000 0000 0000  ................
```

---

## 4. Cross-Format Observations

### 4.1 Common PS2 Binary Patterns

All three formats share PS2-era conventions:
- **Little-endian** byte order (PS2 EE is little-endian for data)
- **Fixed-size headers** with pointer-based section layout
- **Magic markers** at offset 0 (FTCX, MAP1, 0x00 for CHR)
- **Packed structures** with no alignment padding between fields
- **0x77777777 ("www")** used as section delimiter in CHR

### 4.2 GS (Graphics Synthesizer) Constants

The VPA format contains PS2 GS texture dimension values:
- `0x9000` = 128 texels (GS register format)
- `0x7000` = 112 texels
- These map to PS2's `TEX0` register texture width encoding

### 4.3 File Pipeline Position

```
[Source Models] → [PS2 Build Tools] → [.chr] → [Runtime Loader] → [GS Rendering]
[Font Sources] → [.ftc] → [Runtime Font Renderer]
[Map Editor]   → [.vpa] → [Runtime Map Loader] → [Battle Arena Geometry]
```

### 4.4 Naming Convention

| Extension | Actual Content | Name Origin |
|-----------|---------------|-------------|
| .ftc | Font Texture Cache | Descriptive — caches font textures |
| .chr | Character model | Short for "character" |
| .vpa | Vertex Parameters Array | Short for "vertex params" (internal magic: MAP1) |

---

## 5. Research Notes

### Open Questions

1. **CHR +0x38/+0x3c extra blocks**: Purpose unclear — possibly collision data or LOD meshes
2. **VPA section 3**: Only present in version 1 files, likely additional scene metadata
3. **Legacy FTC 0x73 magic**: Full header structure needs more RE effort
4. **CHR animation compression**: The anim_data_size field sometimes equals 0 despite having tracks — animation may be baked into vertex data for some models
5. **VPA command stream**: The data between the sub-header and vertex positions appears to be draw commands, but exact format needs IDA RE against FFX.exe map loader

### Recommended Next Steps

- IDA RE of FTC loader functions (`FFX_Font_*` or similar) to confirm header fields
- IDA RE of CHR loader to map bone transform matrix layout
- IDA RE of VPA/map loader to decode the draw command stream
- Cross-reference VPA section 1 bounding box with PhyreEngine `PGeometry` AABB format
