# FFX.exe Decompilation — Batch 27 (Debug Infrastructure)

**Database:** ffxoficial_COPY.i64 (session b1d18aaa, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** Debug/monitoring infrastructure — 257 functions across 10 categories, PS3-era debug layer ported to PC

---

## Summary

| Metric | Count |
|--------|-------|
| Total functions | 257 |
| Categories | 10 |
| Largest function | `FFX_Dbg_ScreenCapture` (0x83a2f0, ~2.5KB) |
| Key PS3 remnant | `FFX_Dbg_SceWriteWrapper` — SCE I/O stub, dead on PC |
| Dual enumeration | Psapi + Toolhelp32 for module discovery |
| Auto-test entry | `FFX_Dbg_AutoTest_ExecuteCommand` (0x6bcf40) |
| Debug flag range | N3330–N3340 — PS3 debug menu IDs |

`★ Insight`
FFX_Dbg_* is Square Enix's cross-platform debug layer built for PS3 devkits, left intact in the PC port. Most functions are lightweight wrappers into a global debug state struct. The dual module enumeration path (Psapi + Toolhelp) is a Windows adaptation of what was a single SCE API call on PS3. The N33xx flag setters map directly to the PS3 developer debug overlay (Triangle-button menu).
`----------------------------------------------`

---

## 1. Logging (Core Output)

All text debug output routes through `FFX_Dbg_LogPrintf` (0x648a00), a varargs printf that writes to `OutputDebugStringA` (visible in DebugView) and/or `logs/crash/game_output.log`. `FFX_Dbg_VsnprintfWrapper` (0x687210) is a thin CRT bound. `FFX_Dbg_SceWriteWrapper` (0x62ff70) is the PS3 `sceWrite` call — a no-op stub on PC. `FFX_Dbg_InitDebugTextBuffers` (0x844eb0) allocates the text buffer pool for the debug overlay HUD.

## 2. Module Enumeration

Two parallel paths for resolving loaded modules during stack trace/crash reporting:

| Function | Address | Notes |
|----------|---------|-------|
| `FFX_Dbg_EnumerateModulesViaPsapi` | 0x687650 | `EnumProcessModules` (modern path) |
| `FFX_Dbg_EnumerateModulesViaToolhelp` | 0x687830 | `CreateToolhelp32Snapshot` (legacy fallback) |
| `FFX_Dbg_ResolveSymbolFromModuleEntry` | 0x6804d0 | DbgHelp `SymFromAddr` wrapper (300B) |
| `FFX_Dbg_ToggleModuleTracking` | 0x685370 | Enable/disable module change monitoring |

PSAPI is the primary path on modern Windows; Toolhelp is the fallback for older or minimal configurations.

## 3. Stack Trace & Error Formatting

Call stack walker with EBP-chain traversal, feeding into the crash dump system (`logs/crash/<timestamp>/`):

- `FFX_Dbg_FormatStackTraceCallback` (0x688440, 300B) — callback-based stack frame formatter
- `FFX_Dbg_FormatErrorString` (0x688610, 110B) — error code to string
- `FFX_Dbg_FormatModuleSymbolInfo` (0x688680, 150B) — module-level sym detail
- `FFX_Dbg_FormatSymInitInfo` (0x688790, 150B) — DbgHelp init result formatter

## 4. Graphics Debug Flags

All read a single bool from the global debug state struct:

- `FFX_Dbg_GetSpecularFlag` (0x82ec00) / `GetSpecularMode` (0x82ec60) — specular debug
- `FFX_Dbg_GetShadowEnableFlag` (0x82ecf0) — shadow toggle
- `FFX_Dbg_GetDebugDrawFlag` (0x8340e0) — wireframe overlay
- `FFX_Dbg_GetDebugUIFlag` (0x8303a0) — debug HUD toggle

All are trivial getters: `return g_DbgState.flag != 0;`

## 5. Battle Debug Flags

Encounter control and performance visualization:

- `FFX_Dbg_GetEncounterFlag` (0x831850) / `SetEncounterFlag` (0x831d80) — random encounter enable. Setting to 0 disables all random encounters (internal mechanism for "No Encounters" cheat).
- `FFX_Dbg_GetPerfFlag` (0x8319b0) — performance overlay toggle.

## 6. Screen Capture

`FFX_Dbg_ScreenCapture` (0x83a2f0, ~2.5KB) — reads the D3D9 backbuffer and writes BMP or DDS. BMP is fallback; DDS preserves alpha/channels. No PNG/JPEG (no libpng/libjpeg linked). PS3 version captured RSX framebuffer.

## 7. Memory Dump

`FFX_Dbg_MemoryDumpSummaryToCsv` (0x6dd110, ~400B) — iterates `FFX_Heap_*` allocators and writes a CSV (address, size, allocator, tag). Used for leak/fragmentation tracking in dev builds.

## 8. Auto-Test

`FFX_Dbg_AutoTest_ExecuteCommand` (0x6bcf40, ~500B) — automated QA scripting system. Reads commands from a text resource (load scene, walk path, trigger encounter, assert, screenshot). Separate from ATEL VM — this is C-level command dispatch.

## 9. Camera Debug

PS3 Character Viewer tool:

- `FFX_Dbg_ComputeCharacterViewerRadius` (0x830ba0, 150B) — bounding sphere for debug viewer
- `FFX_Dbg_ComputeViewportMatrix` (0x8440f0, 400B) — projection/viewport for debug orbit camera

## 10. PS3 Debug Menu Remnants (N33xx)

Toggle functions that map to numbered PS3 debug menu items. The "N" prefix is the PS3 menu item ID, carried verbatim to PC:

| Function | Address |
|----------|---------|
| `FFX_Dbg_ToggleN3470` | 0x844cb0 |
| `FFX_Dbg_GetDebugByte3479` | 0x844ce0 |
| `FFX_Dbg_SetN3335` through `SetN3340` | 0x843020–0x843320 |

All follow the same pattern: `g_DbgState.offset[N] = val ? 1 : 0;`

---

## Architecture

### Debug State Struct (inferred layout)

```
Offset  Field               Size  Notes
------  ------------------- ----  -----------------------------
0x0000  Flags bitfield      4     specular, shadow, draw, UI
0x0004  encounterEnabled    4     bool32
0x0008  perfFlag            4     bool32
...                           ~0xDA0 bytes total
0x0D10  n3335..n3340        32    8 bool32s
0x0D9C  n3470               4     bool32
0x0DA0  debugByte3479       1     single byte
```

~0xDB0 bytes total, allocated in BSS, initialized at boot. All getters/setters are inline-friendly trivial wrappers.

### Output Flow

```
App code → FFX_Dbg_LogPrintf
    ├── OutputDebugStringA (DebugView)
    ├── logs/crash/game_output.log
    └── [SceWriteWrapper: no-op on PC]

Crash path:
    SEH → FormatStackTraceCallback → FormatErrorString → LogPrintf → dump
```

---

## Key Findings

1. **257 debug functions** — extensive PS3 debug layer, largely intact in the PC port. Most are <200B trivial wrappers.

2. **Dual enumeration** (Psapi + Toolhelp) is a Windows-port pattern. PS3 used only `sceKernelGetModuleList`. The dual path is defensive Win9x-vs-NT compatibility.

3. **`SceWriteWrapper`** (0x62ff70) is the clearest PS3 remnant. Called `sceWrite` to devkit debug TTY on PS3. No-op on PC.

4. **Screen capture writes raw BMP/DDS** — no PNG/JPEG (no library linked). Dev-only feature, not end-user.

5. **Auto-test system** (0x6bcf40) reads scripted commands for automated QA. Separate from ATEL VM. Handles load/walk/encounter/assert/capture commands.

6. **N33xx flags are PS3 debug menu IDs** that survived the port. The PC build removed the overlay UI but kept all backend flag functions.

7. **Character viewer** (0x830ba0 + 0x8440f0) is a PS3 developer tool for inspecting character models in isolation with free-orbit camera.

8. **Patch potential**: `FFX_Dbg_SetEncounterFlag` (0x831d80) is a mod hook candidate for custom encounter control logic.

9. **No security exposure** — all entries are either stubs, read-only, or gated by debug flags not set in release. Auto-test is the most complex but is not exposed to untrusted input.
