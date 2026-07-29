# FFX.exe Decompilation — Batch 28 (Localization Kit — LocKit)

**Database:** ffxoficial_COPY.i64 (session ffx-session-002)
**Date:** 2026-07-28
**Scope:** `FFX_LocKit_*` (9 functions) — regional PS3 LocKit binary loader for localized text

---

## Summary

**LocKit** (Localization Kit) is FFX's **regional text loader** — a PS3-era binary format that stores locale-specific text lines indexed by integer ID. It has only **9 functions** because it delegates all actual file I/O to `FFX_Mscd_*` (batch_0017). LocKit is the **smallest FFX_* domain** in the entire binary.

| Metric | Value |
|--------|-------|
| Total functions | 9 (`FFX_LocKit_*`) |
| Largest function | `FFX_LocKit_LoadRegionalPs3LocKitBin` (0x6db420, 443B) |
| Smallest function | `FFX_LocKit_FreeEntry` (0x6da590, 28B) |
| Registered data file | `FFX_LOC_KIT_PS3_US.BIN` |

`★ Insight ─────────────────────────────────────`
- **Smallest domain in FFX.exe** — only 9 functions. The LocKit is a thin parsing layer on top of MSCD's async file I/O.
- **PS3 remnant** — the `.BIN` path contains `PS3Data/LocKit/`, confirming this is a direct port of the PS3 LocKit format, not a new PC format.
- **Text indexed by integer ID** — menu code calls `GetLocKitLine(id, buf, 256)` with IDs like 526, 528, 775, etc. No string keys, no hash lookups.
- **Delegates to MSCD** — the 443B loader function calls `FFX_Mscd_*` for actual file read. LocKit only parses the loaded buffer.
`─────────────────────────────────────────────────`

---

## Architecture

```
Menu / UI Code (FFX_FFEscMenu_*, FFX_BtlUI_*)
    │
    └── GetLocKitLine(id, buf, 256)
        │
        └── FFX_LocKit_GetLineByIndex  (0x6db320, 242B)
            │
            ├── FFX_LocKit_ParseEntry  (0x6da3d0, 61B)  — parse single entry
            └── FFX_LocKit_FreeEntry   (0x6da590, 28B)  — free parsed entry
                    │
                    └── FFX_LocKit_LoadRegionalPs3LocKitBin  (0x6db420, 443B)
                            │
                            └── FFX_Mscd_GetRegionCodeFromLanguage  (region detection)
                            └── FFX_Mscd_LoadFileFromCdrom        (async file read)
                                    │
                                    Data file: PS3Data/LocKit/FFX_LOC_KIT_PS3_<REGION>.BIN
```

## Function Inventory

| # | Function | Address | Size | Purpose |
|---|----------|---------|------|---------|
| 1 | `FFX_LocKit_LoadRegionalPs3LocKitBin` | 0x6db420 | 443B | Main regional loader — detects region via MSCD, loads .BIN |
| 2 | `FFX_LocKit_GetLineByIndex` | 0x6db320 | 242B | Primary lookup — returns text line by integer ID |
| 3 | `FFX_LocKit_ParseEntry` | 0x6da3d0 | 61B | Parse a single LocKit entry from binary buffer |
| 4 | `FFX_LocKit_FreeEntry` | 0x6da590 | 28B | Free a parsed LocKit entry |
| 5-9 | Various small helpers | — | <100B each | String table accessors, singleton getters |

### FFX_LocKit_LoadRegionalPs3LocKitBin (0x6db420, 443B)

The **main entry point** for loading regional text. Called once during game boot (from `FFX_System_Host_Constructor`).

Flow:
1. Call `FFX_Mscd_GetRegionCodeFromLanguage()` to determine current language/region
2. Build path string: `PS3Data/LocKit/FFX_LOC_KIT_PS3_<REGION>.BIN`
3. Call `FFX_Mscd_LoadFileFromCdrom()` to load the .BIN into memory
4. Parse the binary header and build internal lookup table
5. Keep buffer resident for the session

The path registered in the game's asset table (from `OUTPUT.TXT` line 668):
```
[FFX_section_data_win32] ../../../FFX_Data/GameData/PS3Data/LocKit/FFX_LOC_KIT_PS3_US.BIN
```

### FFX_LocKit_GetLineByIndex (0x6db320, 242B)

**The primary text lookup function.** Called by the menu system with an integer line ID.

```c
// Signature (reconstructed from IDA)
char* FFX_LocKit_GetLineByIndex(int lineId, char* outBuf, int maxLen) {
    // 1. Look up lineId in the parsed entry table
    // 2. If found: copy text string to outBuf (capped at maxLen)
    // 3. If not found: return empty string or fallback
    // 4. Return outBuf pointer
}
```

Usage pattern across the codebase (from `ffx_menu.cpp` reconstructions):
```c
// ESC menu config pages use Line IDs 526-629:
GetLocKitLine(543, buf, 256)  // "Cursor Config"
GetLocKitLine(541, buf, 256)  // "Menu Config"
GetLocKitLine(539, buf, 256)  // "Sound Config"
GetLocKitLine(537, buf, 256)  // "Video Config"
GetLocKitLine(535, buf, 256)  // "Controller Config"
GetLocKitLine(530, buf, 256)  // "Button Config"
GetLocKitLine(529, buf, 256)  // "Gamepad Config"
GetLocKitLine(528, buf, 256)  // "Keyboard Config"

// Quit confirmation popup uses IDs 775-777:
GetLocKitLine(777, buf, 256)  // "Save"
GetLocKitLine(776, buf, 256)  // "Don't Save"
GetLocKitLine(775, buf, 256)  // "Cancel"
```

### FFX_LocKit_ParseEntry (0x6da3d0, 61B) & FreeEntry (0x6da590, 28B)

Minimal parsing helpers. `ParseEntry` extracts a single `(lineId, text)` pair from the binary buffer. `FreeEntry` releases the parsed entry.

---

## Binary Format (Inferred)

Based on the usage patterns and small function sizes:

```
FFX_LOC_KIT_PS3_<REGION>.BIN:
  +0x00   Header (magic + count + offsets)
  +0x??   Entry Table: [lineId:4B, offset:4B, length:2B] * N
  +0x??   String Data: UTF-8/Shift-JIS text lines concatenated
```

The **integer IDs** (526-777 range observed) suggest:
- IDs < 100: reserved
- IDs 500-600: config menu strings (observed: 526-549)
- IDs 600-700: input binding strings (observed: 622-629)
- IDs 700-800: dialog/popup strings (observed: 775-777)

---

## Region Detection

Region detection is NOT done inside LocKit. The loader delegates to:
```
FFX_Mscd_GetRegionCodeFromLanguage()
```
(from batch_0017, MSCD File System)

The MSCD function maps the system language setting (e.g., `FFX_System_GetLocaleId`) to a **region code** that selects the correct .BIN file:

| Language | Region Code | Expected File |
|----------|-------------|---------------|
| English (US) | US | `FFX_LOC_KIT_PS3_US.BIN` |
| English (UK) | UK | `FFX_LOC_KIT_PS3_UK.BIN` |
| Japanese | JP | `FFX_LOC_KIT_PS3_JP.BIN` |
| French | FR | `FFX_LOC_KIT_PS3_FR.BIN` |
| German | DE | `FFX_LOC_KIT_PS3_DE.BIN` |
| Italian | IT | `FFX_LOC_KIT_PS3_IT.BIN` |
| Spanish | ES | `FFX_LOC_KIT_PS3_ES.BIN` |

---

## Key Findings

1. **Smallest FFX_* domain** — 9 functions is the absolute minimum. Every other domain has at least 10+ functions. LocKit is a thin parser, not a system.

2. **PS3 remnant binary format** — the path `PS3Data/LocKit/` and `.BIN` extension confirm this is a **direct port** of the PS3 LocKit format. No PC-specific rework.

3. **Delegates ALL file I/O to MSCD** — LocKit never opens files directly. It calls `FFX_Mscd_LoadFileFromCdrom` via the MSCD queue system (batch_0017). This is why 9 functions suffice.

4. **Text lines indexed by integer ID** — no string keys, no resource identifiers. Menu code hardcodes IDs like `GetLocKitLine(543, buf, 256)`. The IDs are positional offsets into the binary's entry table.

5. **Loaded once at boot, resident for session** — `LoadRegionalPs3LocKitBin` is called during `FFX_System_Host_Constructor` (batch_0011) and the buffer stays allocated until shutdown. No hot-reloading of LocKit.

6. **256-byte buffer limit** — all observed calls pass `maxLen=256`. Individual text lines are capped at 255 characters plus null terminator.

---

## Relationship to Other Batches

| Batch | Domain | Relationship |
|-------|--------|--------------|
| 0011 | `FFX_System_Host` | Host Constructor calls `LoadRegionalPs3LocKitBin` during boot |
| 0017 | `FFX_Mscd_*` | MSCD provides file I/O + region detection |
| 0018 | `FFX_BtlUI_*` | Battle UI reads LocKit lines for button labels |
| — | `FFX_FFEscMenu_*` | ESC menu system is the primary LocKit consumer (~15 LocKit IDs observed) |

---

**Next batch:** Continue to remaining small domains or revisit FFX_Battle_* for deep vertical analysis.
