# FFX .mgrp (Motion Group) File Format Analysis

**Date:** 2026-07-28
**Source:** `D:/FFX Extracted/FFX/ffx_ps2/ffx/master/`
**Total files:** 3,156
**Min size:** 16 bytes | **Max size:** 3,705,388 bytes (~3.5 MB) | **Median:** 16 bytes

---

## 1. Overview

`.mgrp` files are **motion group** files used by the FFX PS2 engine (likely Square Enix's custom engine, not PhyreEngine -- PhyreEngine was used for the HD port). Each `.mgrp` contains one or more motion clips (skeletal animation data) for a character, monster, object, or event model.

### File categories by path

| Path pattern | Description | Count (approx) |
|---|---|---|
| `chr/mon/*/mot/` | Monster motion files | ~800 |
| `chr/npc/*/mot/` | NPC motion files | ~600 |
| `chr/obj/*/mot/` | Object motion files (weapons, items) | ~500 |
| `chr/sum/*/mot/` | Summon motion files | ~100 |
| `chr/skl/*/mot/` | Skeleton motion files | ~200 |
| `chr/wep/*/mot/` | Weapon motion files | ~400 |
| `event/obj/*/` | Event/cutscene motion files | ~400 |
| `battle/mot/` | Battle motion files | ~1 |

### Size distribution

| Bucket | Count |
|---|---|
| 16 bytes (empty stub) | 2,371 |
| 100 B - 1 KB | 13 |
| 1 KB - 10 KB | 93 |
| 10 KB - 100 KB | 220 |
| 100 KB - 1 MB | 416 |
| > 1 MB | 43 |

---

## 2. Empty Stub Files (16 bytes)

75% of all `.mgrp` files are exactly 16 bytes. These are **empty placeholder files** with a consistent structure:

```
Offset  Size  Value    Description
0x00    4     0x00000000  Always zero (flags/version)
0x04    4     0x00000000  entry_count = 0
0x08    4     0x00000000  Padding
0x0C    4     0x00000010  data_size = 16 (equals file size)
```

No motion data follows. The file acts as a "no animation" sentinel.

---

## 3. Non-Trivial File Header Structure

All values are **little-endian**.

### Global Header (20 bytes minimum)

| Offset | Size | Type | Field | Notes |
|--------|------|------|-------|-------|
| 0x00 | 4 | uint32 | `flags` | Always 0. Possibly version/format flags. |
| 0x04 | 4 | uint32 | `entry_count` | Number of motion clips in this group. Range: 1-20+. |
| 0x08 | 4 | uint32 | `reserved` | Always 0. |
| 0x0C | 4 | uint32 | `data_size` | `= filesize - 20`. Size of all data after global header. |
| 0x10 | 4 | uint32 | `bone_param` | Packed as two uint16: hi=bone_count, lo=0. See section 4. |
| 0x14 | 4 | uint32 | `sentinel` | Always `0x77777777` ("wwww"). Used as magic marker. |
| 0x18 | 4 | uint32 | `clip_params` | Packed as two uint16: lo=bone_count (same as 0x10 hi), hi=clip_info. |
| 0x1C | 4 | uint32 | `const_0x1E00` | Nearly always `0x00001E00` (7680). Possibly default fps*256 or frame duration. |

### Extended Header Fields (offset 0x20+)

Two variants exist:

**Variant A (hdr_size = 16, common for small/medium character files):**

| Offset | Size | Type | Field |
|--------|------|------|-------|
| 0x20 | 4 | uint32 | `param_a` | Typically 16 (0x10). |
| 0x24 | 4 | uint32 | `param_b` | Variable. Possibly total keyframe bytes or bone parameter count. |

Motion data begins at offset **0x28** (global header 20B + extended 8B = 28B).

**Variant B (hdr_size = 24, common for monsters and event files):**

| Offset | Size | Type | Field |
|--------|------|------|-------|
| 0x20 | 4 | uint32 | `param_a` | Typically 24 (0x18). |
| 0x24 | 4 | uint32 | `param_b` | Variable. Same semantics as variant A. |

Motion data begins at offset **0x30** (global header 20B + extended 12B = 32B).

---

## 4. Packed uint16 Field Analysis

### Field 0x10 (`bone_param`)

```
[f10_hi] [f10_lo=0]
```

The high uint16 appears to be a **bone/joint count** or similar skeleton parameter. Observed values range from 1 to 150+. The low uint16 is always 0.

### Field 0x18 (`clip_params`)

```
[f18_hi] [f18_lo]
```

`f18_lo` **always equals** `f10_hi`. This is consistent across all 385 non-trivial files examined. `f18_hi` is a separate variable, possibly a secondary clip count, priority, or blend weight parameter.

### Field 0x1C (`const_0x1E00`)

Value `0x00001E00` (7680) appears in nearly all files. Rare deviations exist (e.g., `0x041E00`, `0x00881E00`). The constant `0x1E` = 30 suggests this encodes **30 FPS** (the PS2 FFX framerate). The `0x00` byte after it may be a terminator or sub-parameter.

---

## 5. Motion Data Blocks

### Structure

Each motion clip consists of a **motion header** followed by **compressed keyframe data**.

**Motion Header (variable size, 8-16 bytes):**

| Pattern | Meaning |
|---------|---------|
| `00 50 01 XX ...` | Motion data preamble. `50 01` is the key signature. |
| After signature: bytes encoding bone count, frame info |
| `77 77 77 77` (`0x77777777`) | Internal sentinel marking motion boundaries within the file |

**Observed motion header pattern:**

```
[00] 50 01 [bone_hi] [frame_lo] 00 15 [param] 54 [param2] 50 01 ...
```

The `50 01` sequence appears at the start of each motion data block. Following it:
- Bone count byte(s)
- Frame-related parameters
- `0x15` appears as a separator/opcode
- `0x54` appears frequently after separator sequences

### Multi-Entry Files

Files with `entry_count > 1` contain multiple motion clips. The first clip begins right after the global+extended header. Subsequent clips are found by scanning for the `0x77777777` sentinel pattern within the data.

**Example: 2-entry event file (bjyt060000.mgrp, 33,376 bytes)**
- Sentinel positions: `0x10CC`, `0x360C`, `0x656C`, `0x8144`
- Gaps between sentinels: 9536, 12128, 7128, 4828
- The gaps vary because each clip has different animation complexity/length

**Example: 3-entry event file (bsyt030000.mgrp, 26,000 bytes)**
- Sentinel positions: `0x10CC`, `0x36BC`, `0x4494`, `0x57EC`
- Gaps: 9712, 3544, 4952

### Keyframe Data Encoding

The actual motion data uses **quantized delta encoding** centered around `0x80` (128):

| Byte value | Meaning |
|------------|---------|
| `0x80` | Neutral/zero rotation |
| `0x00` - `0x7F` | Negative delta (below neutral) |
| `0x81` - `0xFF` | Positive delta (above neutral) |
| `0x85 XX` | Run-length encoded repeat of value XX |
| `0x86 XX` | Extended run-length |
| `0x8B XX` | Longer run-length |
| `0x95 XX` | Extended delta |
| `0xD5 XX` | Large negative delta |
| `0xA5 XX` | Extended positive delta |
| `0xF5 XX` | Very large negative delta |
| `0xC5 XX` | Large positive delta |

This is a **variable-length run-length + delta encoding** scheme. Each byte either:
1. Is a raw delta value (single byte, centered at 0x80)
2. Is an opcode (0x80-0xFF with high bit set) followed by a parameter byte

### Byte 0x50 as Section Marker

The byte `0x50` appears extensively throughout motion data, always preceded or followed by structured data:

```
50 01 40 05 ...  (common opening pattern)
50 01 42 05 ...  (secondary pattern)
50 01 7F ...     (bone initialization)
50 01 00 00 ...  (identity/zero motion)
```

The byte after `0x50` (`01`, `3D`, `3F`, etc.) may encode the **transformation type**:
- `0x50 01` = Translation (position)
- `0x50 3D` / `0x50 3F` = Rotation (quaternion/Euler)
- `0x50 FD` = Scale

---

## 6. File Path Conventions

### Character Motions
```
jppc/chr/{type}/{id}/mot/resident{N}.mgrp
```

- `type`: `mon` (monster), `npc`, `obj` (object), `sum` (summon), `skl` (skeleton), `wep` (weapon)
- `id`: Monster ID (m001-m211), NPC ID (n001-n174), object ID (f001-f159), etc.
- `N`: 0-3, likely animation state (0=idle, 1=walk, 2=attack, 3=special)

### Event Motions
```
jppc/event/obj/{scene_id}/{full_id}/{full_id}{seq}.mgrp
```

Example: `event/obj/bs/bsil0100/bsil010000.mgrp` (Besaid island event, sequence 00)

Event files tend to be much larger (up to 3.7 MB) because they contain full cutscene animations with many bones and long sequences.

### Battle Motions
```
jppc/battle/mot/regmot.mgrp
```

Single file for battle motion registration. Contains 8 motion entries.

---

## 7. Correlation: Header Fields vs. File Properties

### data_size (0x0C) = filesize - 20

Consistent across all non-trivial files. The 20-byte global header is excluded from data_size.

### entry_count (0x04) distribution

| Entries | File count |
|---------|-----------|
| 1 | 291 |
| 2 | 42 |
| 3 | 45 |
| 4 | 29 |
| 5 | 39 |
| 6 | 51 |
| 7 | 44 |
| 8-12 | ~160 |
| 13-20 | ~70 |

### hdr_size (0x20) correlation

| hdr_size | Typical files | First motion data offset |
|----------|---------------|-------------------------|
| 16 (0x10) | Small/simple character files | 0x28 (byte 0x29 with alignment) |
| 24 (0x18) | Monsters, event objects, complex characters | 0x30 (byte 0x31 with alignment) |

---

## 8. Hex Dump Reference

### 16-byte empty stub (m001/resident0.mgrp)
```
00000000: 00 00 00 00 00 00 00 00 00 00 00 00 10 00 00 00  ................
          [flags=0     ] [entry=0    ] [pad=0     ] [data_sz=16  ]
```

### Small character file (f011/resident0.mgrp, 116 bytes, 1 entry)
```
00000000: 00 00 00 00 01 00 00 00 00 00 00 00 60 00 00 00  ............`...
          [flags=0     ] [entry=1    ] [pad=0     ] [data_sz=96  ]
00000010: 00 00 01 00 77 77 77 77 01 00 02 00 00 1e 00 00  ....wwww........
          [bone=1    ] [SENTINEL    ] [clip_p=1/2] [const=0x1E  ]
00000020: 10 00 00 00 16 00 00 00 00 50 01 40 05 00 15 00  .........P.@....
          [param_a=16] [param_b=22 ] [motion data starts...]
```

### Medium monster file (m162/resident1.mgrp, 1248 bytes, 1 entry)
```
00000000: 00 00 00 00 01 00 00 00 00 00 00 00 cc 04 00 00  ................
          [flags=0     ] [entry=1    ] [pad=0     ] [data_sz=1228]
00000010: 00 00 0a 00 77 77 77 77 0a 00 02 00 00 1e 00 00  ....wwww........
          [bone_hi=10 ] [SENTINEL    ] [clip=10/2] [const=0x1E  ]
00000020: 18 00 00 00 1e 00 00 00 00 00 00 00 00 00 00 00  ................
          [param_a=24] [param_b=30 ] [padding              ]
00000030: 00 50 01 40 05 77 77 77 00 00 1e 00 77 77 77 77  .P.@.www....wwww
          [motion preamble...         ] [SENTINEL (clip start)]
00000040: 1e 00 02 00 00 1e 00 00 18 00 00 00 1e 00 00 00  ................
          [clip header data...]
00000050: 00 00 00 00 00 00 00 00 30 53 01 40 05 77 22 00  ........0S.@.w".
          [more params... ] [KEYFRAME DATA STARTS]
```

### Large event file (bsil010000.mgrp, 503,588 bytes, 15 entries)
```
00000000: 00 00 00 00 0f 00 00 00 00 00 00 00 f8 ad 07 00  ................
          [flags=0     ] [entry=15   ] [pad=0     ] [data_sz=503288]
00000010: 00 00 1e 00 77 77 77 77 1e 00 76 00 00 04 1e 00  ....wwww..v.....
          [bone_hi=30 ] [SENTINEL    ] [clip=30/118] [const=0x041E00]
00000020: 18 00 00 00 22 01 00 00 90 10 00 00 00 00 00 00  ...."...........
          [param_a=24] [param_b=290] [offset=0x1090=4240] [padding]
```

---

## 9. Key Patterns Summary

| Pattern | Occurrence | Meaning (hypothesis) |
|---------|-----------|---------------------|
| `77 77 77 77` | 100% of non-trivial files at 0x14, + scattered in data | Motion sentinel / magic marker |
| `50 01` | Start of each motion data block | Motion block signature (PS2 motion opcode) |
| `00 15` | Frequent separator between bone/transform params | Bone/transform delimiter |
| `54` | Frequently after `00 15 XX` | Transform type indicator |
| `00 50 01 40 05` | Common opening pattern | Identity/initial transform |
| `00 50 01 42 05` | Common secondary pattern | Secondary transform type |
| `80` centered encoding | Throughout keyframe data | Quantized rotation deltas (128 = neutral) |

---

## 10. Data Layout Hypothesis

```
+-------------------------------------------+
| Global Header (20 bytes)                  |
|  [0x00] flags = 0                         |
|  [0x04] entry_count                       |
|  [0x08] reserved = 0                      |
|  [0x0C] data_size = filesize - 20         |
|  [0x10] bone_param (hi=count, lo=0)       |
|  [0x14] sentinel = 0x77777777             |
|  [0x18] clip_params (lo=bone, hi=info)    |
|  [0x1C] const = 0x1E00                    |
+-------------------------------------------+
| Extended Header (8 or 12 bytes)           |
|  [0x20] header_variant (16 or 24)         |
|  [0x24] param_b (variable)                |
|  [0x28-0x2F] (if variant=24) clip meta   |
+-------------------------------------------+
| Motion Clip 0                             |
|  Motion Header (variable)                 |
|  Keyframe Data (quantized deltas)         |
|  ...                                      |
|  [0x77777777 sentinel]                    |
+-------------------------------------------+
| Motion Clip 1 (if entry_count > 1)        |
|  Motion Header                            |
|  Keyframe Data                            |
|  ...                                      |
+-------------------------------------------+
| ...                                       |
+-------------------------------------------+
```

---

## 11. Relationship to Other FFX Formats

- **`.mgrp` vs `.mot`**: The directory structure `*/mot/*.mgrp` suggests `.mgrp` is the container format while `.mot` might be an older/PS2-native naming convention. All actual files found use the `.mgrp` extension.
- **`.mgrp` vs PhyreEngine**: PhyreEngine uses `.ppp` (Phyre Property Pack) for animation data on the PS3/PC HD port. The `.mgrp` format is a **Square Enix PS2-era format** predating the PhyreEngine port.
- **`.mgrp` vs `.stck`**: The `.stck` format (also found in the FFX data) stores skeletal track data in a different encoding (A3DSKLTRACKFILEHEADER). `.mgrp` appears to be the runtime motion format while `.stck` may be an intermediate/toolchain format.
- **`.mgrp` relationship to battle system**: The `regmot.mgrp` in `battle/mot/` suggests `.mgrp` files are loaded by the battle animation system. The FFX battle system's motion playback reads these files to apply skeletal animations to battle models.

---

## 12. Open Questions

1. **Exact keyframe encoding**: The variable-length delta/RLE scheme needs more reverse engineering. The opcodes (0x85, 0x86, 0x8B, 0x95, 0xD5, 0xA5, 0xF5, 0xC5) need precise definitions.

2. **[0x1C] deviations**: Why do some files have non-standard values at 0x1C (e.g., `0x041E00`, `0x00881E00`)? These may encode additional parameters for complex models.

3. **[0x24] semantics**: The param_b field varies widely. It may be total keyframe byte count, a checksum, or a bone parameter table offset.

4. **PS2 DMA alignment**: The motion data starts at odd byte offsets (0x29, 0x31) which is unusual for PS2 (which typically aligns to 16 bytes for DMA). This suggests the format uses byte-level addressing or has been repacked from PS2 memory dumps.

5. **[0x28-0x2F] in variant B**: For hdr_size=24 files, the 8 bytes at 0x28-0x2F contain values that may be an offset table or per-clip metadata. Needs further investigation with IDA cross-references.

6. **Transform type encoding**: The byte patterns `50 01 40`, `50 01 42`, `50 01 48`, `50 01 7F` after the `0x50` signature likely encode transform types (translation, rotation, scale, quaternion). Cross-reference with PhyreEngine SDK's `PGeometry`/`PVertexStream` types may clarify.

---

## 13. Files Analyzed

| File | Size | Entries | hdr_size | Notes |
|------|------|---------|----------|-------|
| chr/mon/m001/mot/resident0.mgrp | 16 | 0 | - | Empty stub |
| chr/mon/m162/mot/resident1.mgrp | 1,248 | 1 | 24 | Monster, 10 bones |
| chr/sum/s018/mot/resident1.mgrp | 1,224 | 1 | 24 | Summon, 27 bones |
| chr/obj/f126/mot/resident0.mgrp | 1,328 | 1 | 24 | Object, 40 bones |
| chr/mon/m106/mot/resident1.mgrp | 1,864 | 1 | 24 | Monster, 5 bones (minimal) |
| chr/mon/m113/mot/resident1.mgrp | 1,872 | 1 | 24 | Monster, 120 bones (complex) |
| chr/wep/w054/mot/resident1.mgrp | 2,160 | 1 | 24 | Weapon, 10 bones |
| chr/mon/m039/mot/resident0.mgrp | 1,052 | 1 | 16 | hdr_variant=16 |
| chr/mon/m175/mot/resident1.mgrp | 4,416 | 1 | 24 | Monster, 32 bones |
| event/obj/bs/bsil0100/bsil010000.mgrp | 503,588 | 15 | 24 | Large event, 15 clips |
| event/obj/bv/bvyt0000/bvyt000000.mgrp | 3,705,388 | 19 | 24 | Largest file found |
| battle/mot/regmot.mgrp | ~varies | 8 | 24 | Battle motion registry |
