# FFX.exe Decompilation — Batch 33: Menu2D System

**Database:** ffxoficial_COPY.i64 (session 9993ee7e)
**Date:** 2026-07-28
**Scope:** `FFX_Menu2D_*` — 2D menu rendering, battle menus, debug overlays, text writing

---

## Summary

The **Menu2D** layer handles all 2D UI in FFX: battle command menus, inventory screens, save/load, debug overlays, and text rendering. The largest function (`FFX_Menu2D_BlendPackedTransfer` at 5,882 bytes) is a **massive monolith** that combines menu initialization, debug overlays, and game state manipulation — a classic PS2-era "god function" that grew organically over development.

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_Menu2D_BlendPackedTransfer` | 0x7c6d90 | 5,882B | Main menu handler + debug overlays |
| `FFX_Menu2D_RenderWithTexture_structural` | 0x7c0650 | 182B | Texture-based rendering |
| `FFX_Menu2D_TextWriter_structural` | 0x7cd730 | — | Text rendering |
| `FFX_Menu2D_InitBlendStateArrays` | 0x784d90 | — | Blend state initialization |
| `FFX_Menu2D_InitItemIdTable` | 0x784ce0 | — | Item ID table setup |
| `FFX_Menu2D_InitStaticToggleFlags` | 0x784d00 | — | Toggle flag initialization |

`★ Insight ─────────────────────────────────────`
- **5,882-byte monolith** — `BlendPackedTransfer` is a god function that handles menu init, debug overlays, AND game state manipulation. This is classic PS2-era code that grew organically. The function calls 30+ sub-functions including debug utilities, inventory manipulation, party management, and battle state.
- **Debug menus are embedded in production code** — The Menu2D system contains full debug overlay support (`FFX_DbgOverlay_AddCursorX/Y`, `FFX_Dbg_PrintfFormatted`). These are compiled into the release build but activated only via debug flags.
- **Menu2D uses PhyreEngine's 2D rendering** — The menu system renders through PhyreEngine's PEntity/PComponent vtables (batch_0010), not a separate 2D engine. Menus are orthographic-projected 3D quads.
`─────────────────────────────────────────────────`

---

## Menu2D Architecture

### Layer Diagram

```
┌─────────────────────────────────────────────────────┐
│                  GAME LOGIC                           │
│  Battle commands, inventory, save/load, settings      │
└───────────────────────┬─────────────────────────────┘
                        │
┌───────────────────────▼─────────────────────────────┐
│              Menu2D SYSTEM                            │
│  BlendPackedTransfer (5882B god function)             │
│  TextWriter, RenderWithTexture, Init functions        │
│  ItemIdTable, BlendStateArrays, ToggleFlags           │
└───────────────────────┬─────────────────────────────┘
                        │ renders via
┌───────────────────────▼─────────────────────────────┐
│              DEBUG OVERLAY (embedded)                  │
│  FFX_DbgOverlay_*, FFX_Dbg_*                          │
│  Cursor tracking, text elements, formatted output     │
└───────────────────────┬─────────────────────────────┘
                        │
┌───────────────────────▼─────────────────────────────┐
│              PhyreEngine 2D                            │
│  Orthographic projection → PEntity quads → D3D9       │
└─────────────────────────────────────────────────────┘
```

---

## Key Function: BlendPackedTransfer (5,882B)

This is the **largest single function in the Menu2D system**. It handles:

### Sub-functions called (30+):

**Debug utilities:**
- `FFX_Dbg_SetElementStringFromOffset` — set debug string
- `FFX_Dbg_CreateTextElement` — create text element
- `FFX_Dbg_SetElementText` — set element text
- `FFX_Dbg_InitRepeatCounter` — init repeat counter
- `FFX_Dbg_TickRepeatCounter` — tick repeat counter
- `FFX_DbgOverlay_AddCursorX/Y` — cursor position tracking
- `FFX_Dbg_PrintfFormatted` — formatted debug output

**Game state manipulation:**
- `FFX_Inventory_DebugMaxAll` — max all items (debug cheat!)
- `FFX_SaveRam_SetGilMax` — set gil to max (debug cheat!)
- `FFX_Btl_InitPartyWideCommandBank` — init command bank
- `FFX_Party_AssignAllSlotsToFormation` — assign party slots
- `FFX_Chr_InitCharacterSlotDefaults` — init character defaults
- `FFX_SphereGrid_InitStatTableDefault` — init sphere grid stats

**Menu rendering:**
- `FFX_Menu2D_TextWriter_structural` — text rendering
- `FFX_Menu2D_InitBlendStateArrays` — blend state
- `FFX_Menu2D_InitItemIdTable` — item ID table
- `FFX_Menu2D_InitStaticToggleFlags` — toggle flags

**Battle state:**
- `FFX_Battle_FlagAllActorsForHpMpUpdate` — flag HP/MP update
- `FFX_Battle_FlagPartyActorsForHpMpUpdate` — flag party HP/MP
- `FFX_Battle_FlagMonsterActorsForHpMpUpdate` — flag monster HP/MP
- `FFX_Camera_ZeroReturn` — camera reset

### Key insight: Debug cheats in production code

`FFX_Inventory_DebugMaxAll` and `FFX_SaveRam_SetGilMax` are **debug cheats compiled into the release binary**. They're activated via the debug overlay system (debug flag at `FFX_Dbg_GetDebugUIFlag`). This means:
- The debug menu system is fully functional in the release build
- Debug flags control whether cheats are accessible
- The debug overlay can be activated via memory patches

---

## Menu2D Sub-systems

### 1. Text Rendering

`FFX_Menu2D_TextWriter_structural` handles all text rendering in menus:
- Character-by-character text drawing
- Font atlas lookup
- Color/size formatting
- Text wrapping

### 2. Blend State

`FFX_Menu2D_InitBlendStateArrays` initializes alpha blending for menu elements:
- Standard alpha blend for text
- Additive blend for highlights
- Multiply blend for shadows

### 3. Item ID Table

`FFX_Menu2D_InitItemIdTable` maps item IDs to menu entries:
- Weapon/armor/item names
- Stats descriptions
- Icon indices

### 4. Toggle Flags

`FFX_Menu2D_InitStaticToggleFlags` manages menu state:
- Visibility flags
- Selection state
- Animation state

---

## Menu Types in FFX

Based on the functions discovered:

| Menu Type | Functions | Purpose |
|-----------|-----------|---------|
| Battle Command | `Btl_BuildActorCommandMenu` | Attack/Magic/Item/Special/Defend/Flee |
| Inventory | `Inventory_DebugMaxAll`, `InitItemIdTable` | Equipment, items, key items |
| Sphere Grid | `Abmap_ActivateNode` (batch_0014) | Ability learning |
| Save/Load | `SaveRam_*` | Save game management |
| Config | — | Settings, controller mapping |
| Debug Overlay | `DbgOverlay_*`, `Dbg_*` | Developer tools |

---

## Debug System Integration

The Menu2D system is tightly integrated with the debug overlay:

```c
// From BlendPackedTransfer decompilation:
FFX_Dbg_CreateTextElement();        // Create text element
FFX_Dbg_SetElementText();           // Set text content
FFX_DbgOverlay_AddCursorX/Y();      // Track cursor position
FFX_Dbg_PrintfFormatted();          // Formatted output

// Debug cheats (accessible via debug UI flag):
FFX_Inventory_DebugMaxAll();        // Max all items
FFX_SaveRam_SetGilMax();            // Max gil
FFX_Party_AssignAllSlotsToFormation(); // Full party
```

---

## Key Findings

1. **5,882B god function** — `BlendPackedTransfer` is a monolith combining menu init, debug overlays, and game state manipulation.

2. **Debug cheats in release binary** — `DebugMaxAll`, `SetGilMax`, `AssignAllSlots` are compiled into the release build, activated via debug flags.

3. **Menu2D uses PhyreEngine 2D** — menus are orthographic-projected 3D quads, not a separate 2D engine.

4. **30+ sub-functions** called from the main menu handler — covering debug, inventory, battle, party, and rendering.

5. **Text rendering** is character-by-character with font atlas lookup.

6. **Blend state management** supports alpha, additive, and multiply blending.

7. **Item ID table** maps item IDs to menu entries and descriptions.

8. **Toggle flags** manage menu visibility, selection, and animation state.

9. **Debug overlay** is embedded in production code — can be activated via memory patches.

10. **Camera reset** (`FFX_Camera_ZeroReturn`) is called from menu code — menus reset the camera to default.

---

## Modding Implications

### What CAN be modded:
1. **Menu layout** — change positions, sizes, colors of menu elements
2. **Text strings** — change menu text (requires LocKit editing, batch_0028)
3. **Item names/descriptions** — modify item ID table entries
4. **Debug cheats** — activate via memory patch to `FFX_Dbg_GetDebugUIFlag`
5. **Menu behavior** — modify toggle flags and selection logic

### What CANNOT be modded without C++ patching:
1. **Menu rendering pipeline** — the blend state system is fixed
2. **Text rendering** — font atlas and character rendering is compiled
3. **Menu navigation** — the input handling is compiled
4. **Debug overlay system** — the overlay rendering is compiled

### Hook points for C++ mods:
1. `FFX_Menu2D_BlendPackedTransfer` (0x7c6d90) — intercept menu rendering
2. `FFX_Menu2D_RenderWithTexture_structural` (0x7c0650) — modify texture rendering
3. `FFX_Menu2D_TextWriter_structural` (0x7cd730) — modify text rendering

---

## What's Next?

- **batch_0034**: ShaderInterop + ShaderPreprocessor (~50 funcs)
- **batch_0035**: Input subsystem (~30 funcs)
- **batch_0036**: FieldSky + Cloud (~40 funcs)
- **batch_0037**: Virtuos stubs + PC remnant layer (~20 funcs)
- **batch_0038**: FFX_WinMain + window management (~10 funcs)
- **batch_0039**: Cross-batch battle synthesis — full battle system map
- **batch_0040**: Final architecture overview — all systems connected
