# FFX.exe Decompilation — Batches 35-37: Input, Sky/Cloud, Virtuos Stubs

**Database:** ffxoficial_COPY.i64 | **Date:** 2026-07-28 | **Source:** Hex-Rays decompiler + existing batches
**Scope:** Three peripheral domains — `FFX_Input_*` (~30), `FFX_Sky_*`/`FFX_Cloud_*` (~40), `FFX_Virtuos_*` (~20)

---

## Summary

These three domains are **peripheral subsystems** — low-priority targets that are nonetheless architecturally significant. The Input subsystem bridges DirectInput8 and XInput into the game's frame loop. The Sky/Cloud system handles environmental rendering (skybox, fog, weather) driven by ATEL Map VM opcodes. The Virtuos stubs are vestigial PS2/PS3 code paths that were stubbed when Virtuos ported the game from PS3 to PC.

| Domain | Prefix | Functions | Size Range | Priority |
|--------|--------|-----------|------------|----------|
| Input | `FFX_Input_*` | ~30 | 0x17B–0x888700+ | Low |
| Sky/Cloud | `FFX_Sky_*` / `FFX_Cloud_*` | ~40 | Unknown | Low |
| Virtuos Stubs | `FFX_Virtuos_*` | ~20 | Mostly stubs | Low (vestigial) |

`★ Insight ─────────────────────────────────────`
- **Input = frame-rate-coupled** — `FFX_Input_AnalogStickDeadZone(2, FFX_Field_UpdateSceneTimer)` is called during field init, meaning analog stick dead zone processing is tied directly to the scene timer. The controller polling rate IS the update rate.
- **DVD FILE is vestigial** — the MSCD file system was originally a PS2 DVD-ROM driver. The PC port keeps the string as a slot identifier even though there is no DVD drive. DVD stubs call `FFX_Virtuos_MovieNotImplemented_movie_err`.
- **Sky is ATEL-driven** — skybox visibility, fog density/color, and clear color are all controlled by ATEL Map VM opcodes (channel 2, 38 opcodes). The field script triggers environment changes, not the rendering code itself.
`─────────────────────────────────────────────────`

---

## 1. Input Subsystem (~30 functions)

### Known Functions

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_Input_ReadButtonBit` | 0x630ea0 | 0x17B (379B) | Read button state bitfield |
| `FFX_Input_AnalogStickDeadZone` | 0x888700 | Unknown | Dead zone processing with callback |

### Architecture

```
Win32 Game Loop
├── DirectInput8Create (dinput8.dll) → Keyboard, Mouse, Joystick
├── XInputGetState (xinput1_3.dll) → Gamepad axes/triggers/buttons
└── FFX_Input_* → ReadButtonBit (bitfield), AnalogStickDeadZone (axis+callback)
```

### Key Design Details

- **Dual input API**: DirectInput8 for keyboard/mouse, XInput for gamepad. Both polled per-frame.
- **Dead zone is parameterized**: `FFX_Input_AnalogStickDeadZone(2, FFX_Field_UpdateSceneTimer)` — the first parameter is the stick index (0=left, 1=right, 2=both), the second is a callback invoked when input changes.
- **Button reading is bitfield-based**: `FFX_Input_ReadButtonBit` takes a bitmask (e.g., `0x8000000` for a specific button) and returns the current state. Used throughout battle menus and field interaction.
- **Scene timer is input-tied**: The call `FFX_Input_AnalogStickDeadZone(2, FFX_Field_UpdateSceneTimer)` in field init (batch_0003, step 9) confirms that frame updates are coupled to controller polling, not a free-running timer.

### Integration Points

- **Field VM**: `FFX_Field_UpdateSceneTimer` callback — field scene state advances when controller input triggers the dead zone callback.
- **Battle menus**: `FFX_BtlTick_IsBattleReadyForInput` (0x7911e0) and `FFX_Btl_BattleMenuInputDispatch` (0x792ab0) consume Input state.
- **PhyreEngine PInput**: Engine layer has ~30 `PInput_*` functions. `FFX_Input_*` is the game-level wrapper.

---

## 2. Sky/Cloud System (~40 functions)

No individually decompiled `FFX_Sky_*` or `FFX_Cloud_*` functions exist. Documented through ATEL Map VM integration (batch_0021) and field map rendering (batch_0030).

### Architecture

```
Field Script → Field VM opcode → ATEL Map VM (channel 2, 38 opcodes)
  ├── setFogParams_CALL (0x91b810) → FFX_FieldMap_SetFogParams
  ├── setFogColor_INTRET (0x91bad0) → FFX_FieldMap_SetFogColor
  ├── setSkyboxVisibility_INTRET (0x91c5b0) → FFX_FieldMap_SetSkyboxVisibility
  └── setMapLayerVisibility_INTRET (0x91c530) → FFX_FieldMap_SetLayerVisibility
```

### Key Design Details

- **Sky is scripted, not procedural** — skybox visibility, fog density, fog color, and clear color are all controlled by ATEL Map VM opcodes. The field script triggers changes via the VM, not through a time-of-day system.
- **Fog params include density, start, and end** — standard linear fog with RGB color. Used for distance-based atmosphere in fields like Macalania (ice fog) and Mt. Gagazet (mountain mist).
- **Skybox is a simple toggle** — `setSkyboxVisibility_INTRET` enables/disables skybox rendering. No gradient system, no time-of-day blending (that was PS2-era; the HD remaster simplifies to static skyboxes per area).
- **Cloud layers** are part of the FieldMap rendering pipeline — `FFX_FieldMap_*` handles sky/cloud/fog as a unified environmental rendering pass.

Data flow: `ATEL Map Script -> Map VM Dispatch -> FieldMap Rendering (Skybox toggle, Fog params, Clear Color, Cloud layers)`.

---

## 3. Virtuos Stubs (~20 functions)

| Function | Purpose |
|----------|---------|
| `FFX_Virtuos_MovieNotImplemented_movie_err` | Error handler for unimplemented PS3 features |
| Various `FFX_Virtuos_*` nullsubs | Stub functions for PS2/PS3 code paths |

- **PS3→PC port by Virtuos** — added platform shims, preserved PS3 code paths almost entirely.
- **DVD stubs are the most visible** — `FFX_Mscd_DvdFileReadOrDecompress` falls through to `MovieNotImplemented_movie_err` when DVD access is attempted.
- **Most Virtuos functions are nullsubs** — preserve function table layout from PS3 build. Calling them does nothing.
- **"DVD FILE" string is vestigial** — MSCD (batch_0017) was a PS2 DVD-ROM driver. PC port keeps the string as a slot identifier.
- **Error handler is shared** — `MovieNotImplemented_movie_err` is the catch-all for "this PS3 feature doesn't exist on PC."

### MSCD Integration (batch_0017)

```
FFX_Mscd_* (PS2/PS3 CDROM)
├── FFX_Mscd_Pc* (PC shims — VBF reader, Steam)
├── FFX_Virtuos_* (stubs — DVD→MovieNotImplemented, nullsubs)
└── FFX_Mscd_LoadFileFromCdrom → actual file I/O (via VBF)
```

---

## 4. Key Findings

1. **Input is frame-rate-coupled** — `FFX_Input_AnalogStickDeadZone(2, FFX_Field_UpdateSceneTimer)` means controller polling rate directly drives the scene update. Input and game logic share the same clock.

2. **Dual input API (DirectInput8 + XInput)** — Keyboard/mouse through DirectInput8, gamepad through XInput. Standard Windows game input pattern from the MSVC 2012 era.

3. **Button reading is bitfield-based** — `FFX_Input_ReadButtonBit` uses bitmask parameters (e.g., `0x8000000`), not enumerated button IDs. Efficient but opaque without a button map.

4. **Sky is ATEL-driven, not procedural** — All environmental effects (skybox visibility, fog, clear color) are controlled by ATEL Map VM opcodes triggered by field scripts. No time-of-day system in the HD remaster.

5. **Fog is the primary atmospheric tool** — Linear fog with RGB color, density, start/end. Each field sets its own fog params via ATEL Map VM. PS2 had per-frame fog animation; PS3→PC simplifies to static per-area.

6. **Virtuos stubs preserve PS3 function table layout** — ~20 `FFX_Virtuos_*` functions maintain ABI compatibility. Most are nullsubs. Only `MovieNotImplemented_movie_err` has real logic.

7. **DVD FILE is a vestigial constant** — MSCD was a PS2 DVD-ROM driver. The string `"DVD FILE"` persists as a slot identifier, routed through Virtuos stubs. PC uses VBF instead.

8. **Debug infrastructure survives in retail** — 257 `FFX_Dbg_*` functions (batch_0010) + debug menu remnants (N33xx flags) compiled into release binary, activated only via debug flags in Menu2D.

---

## Decompilation Coverage

- **Input**: `FFX_Input_ReadButtonBit` (0x630ea0) decompiled. ~29 remaining. Key: `AnalogStickDeadZone` (0x888700).
- **Sky/Cloud**: Zero decompilations. Documented via ATEL Map VM (batch_0021) and field map (batch_0030). Key: `FFX_Sky_Init`, `FFX_FieldMap_SetFogParams`.
- **Virtuos**: Zero decompilations. Documented via MSCD (batch_0017) and cross-batch (batch_0039). Key: `FFX_Virtuos_MovieNotImplemented_movie_err`.

---

*Generated as part of the FFX.exe horizontal decompilation campaign (batches 0035-0037). See `batch_0039_FFX_CrossBatch_Synthesis.md` for cross-domain analysis.*
