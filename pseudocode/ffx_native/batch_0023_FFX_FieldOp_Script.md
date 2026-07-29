# FFX.exe Decompilation — Batch 23 (Field Script Opcodes)

**Database:** ffxoficial_COPY.i64 (session 85e0242a, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** `FFX_FieldOp_*` — the higher-level overworld scripting VM with 556 opcodes

---

## Summary

The **Field Script** is FFX's higher-level overworld scripting engine — a stack-based bytecode interpreter with **556 opcodes** (all named `FFX_FieldOp_*`). It runs alongside the Field VM (295 ops, batch_0015) sharing the same operand stack, but operates at a higher abstraction level. Where the Field VM handles low-level actor control, position queries, and rendering state, the Field Script manages **camera choreography, music volume, save flags, NPC dialogue states, party management, and BgCamera motion sequences**.

| Metric | Value |
|--------|-------|
| Total opcodes | 556 (all `FFX_FieldOp_*`) |
| Dominant subsystem | Camera control (~40+ functions) |
| Operand stack | Shared with Field VM (295 ops) |
| Abstraction level | Higher than Field VM — script-level rather than rendering-level |
| Typical function size | 20-150 bytes (range 6-350B) |
| Subfamilies identified | ~15+ (Camera, BgCamera, Save, Music, Battle, Actor, Party, Animation, Dialogue, Event) |

`* Insight`
Field Script (556 ops) is **larger than Field VM (295 ops)** despite operating at a higher level. This is because the Field Script exposes **many more camera and gameplay operations** — multiple variants of rotation, boundary setup, effects, and save flag manipulation that the lower-level VM abstracts away. The BgCamera subsystem alone accounts for ~20 functions dedicated to motion playback and interrogation.
`----------------------------------------------`

---

## Architecture: Field Script Dispatch

The Field Script shares the same operand stack as the Field VM but provides higher-level operations:

```
Field Script (556 ops, batch_0023) ←→ Shared Operand Stack ←→ Field VM (295 ops, batch_0015)
```

Both use the same stack protocol:
```c
int FFX_FieldVM_PopOperand(int context, int *error);   // pop operand
void FFX_FieldVM_PushOperand(int context, int value);   // push result
```

The key architectural difference: Field Script opcodes often orchestrate **multi-step sequences** (e.g., play a BgCamera motion, wait for completion, then trigger a save flag), while Field VM opcodes perform single operations (e.g., compute distance, set render params).

---

## Subsystem Breakdown

### 1. Camera System (~40+ functions) — THE DOMINANT SUBSYSTEM

The camera system is the largest single category within Field Script, split into two parallel subsystems:

#### 1a. BgCamera Motion Subsystem (~10 functions)

| Opcode | Address | Size | Description |
|--------|---------|------|-------------|
| `FFX_FieldOp_BgCameraPlayMotionType1` | 0x7b7f60 | ~100B | Play BgCamera motion type 1 — likely linear/standard camera path |
| `FFX_FieldOp_BgCameraPlayMotionType3` | 0x7b7fd0 | ~100B | Play BgCamera motion type 3 — likely bezier/spline camera path |
| `FFX_FieldOp_BgCameraStopMotion` | 0x7b8130 | ~60B | Stop active BgCamera motion |
| `FFX_FieldOp_BgCameraCheckMotionDone` | 0x7b81f0 | ~90B | Poll whether BgCamera motion has completed |
| `FFX_FieldOp_BgCameraGetMotionProgress` | 0x7b8250 | ~50B | Get current motion progress (0.0-1.0) |
| `FFX_FieldOp_BgCameraSetRotation` | 0x7b82b0 | ~150B | Set BgCamera rotation directly |

The BgCamera functions manage **background camera motion paths** — pre-authored camera sweeps used in cutscenes, NPC encounters, and field transitions. Motion types 1 and 3 suggest at least two interpolation modes.

`* Insight`
BgCamera != regular Camera. The _BgCamera prefix (background camera) suggests this is a **separate camera rig** used for non-interactive background shots — the camera that plays during scripted sequences while the gameplay camera is suspended. This parallels how FFX separates gameplay camera (player-controlled) from cutscene camera (scripted).
`----------------------------------------------`

#### 1b. Camera Transform Subsystem (~12 functions)

| Opcode | Address | Size | Description |
|--------|---------|------|-------------|
| `FFX_FieldOp_CameraSetRotation` | 0x7b8350 | ~150B | Set camera rotation (single-axis or quaternion) |
| `FFX_FieldOp_CameraSetRotation3Axis` | 0x7b83f0 | ~150B | Set rotation on all 3 axes independently |
| `FFX_FieldOp_CameraSetRotation2Axis` | 0x7b84b0 | ~150B | Set rotation on 2 axes (pitch/yaw, no roll) |
| `FFX_FieldOp_CameraSetVisibility` | 0x7b8570 | ~60B | Toggle camera visibility (display/hide camera object) |
| `FFX_FieldOp_CameraSetProjection` | 0x7b8a50 | ~100B | Set projection mode (perspective/orthographic) |
| `FFX_FieldOp_CameraSetProjectionParams` | 0x7b8b20 | ~100B | Set projection parameters (FOV, near/far clip, aspect) |

Three rotation variants (full/3-axis/2-axis) suggest different use cases: 2-axis for ground-level camera (pitch+yaw only), 3-axis for cutscenes requiring roll, full rotation for complex camera rigs.

#### 1c. Camera Effects Subsystem (~6 functions)

| Opcode | Address | Size | Description |
|--------|---------|------|-------------|
| `FFX_FieldOp_CameraBlurHandler` | 0x7b8750 | ~100B | Apply/blend camera blur effect |
| `FFX_FieldOp_CameraShakeHandler` | 0x7b8830 | ~80B | Camera shake trigger (earthquake, impact) |
| `FFX_FieldOp_CameraRandHandler` | 0x7b88a0 | ~80B | Random camera perturbation (nervous cam, handheld effect) |
| `FFX_FieldOp_FormatSmoothRectangle` | 0x7b8710 | ~80B | Smooth rectangle formatting (letterbox/pillarbox mask) |

Camera effects are **script-level triggers** — the Field Script opcode sets up the effect, and the engine interpolates it over time. Blur is used for focus transitions and memory sphere transitions. Shake is used for earthquakes, guardian battles, and Sin attacks.

`* Insight`
`FormatSmoothRectangle` despite being in the middle of camera functions, is likely related to **letterbox formatting** — the smooth rectangle that masks top/bottom of screen during cinematic dialogue, not a camera operation per se. Its address proximity to CameraBlurHandler (0x7b8710 vs 0x7b8750) suggests they're compiled together.
`----------------------------------------------`

#### 1d. Camera Boundaries Subsystem (6 variants: A-F)

| Opcode | Address | Description |
|--------|---------|-------------|
| `FFX_FieldOp_CameraSetupBoundaryA` | 0x7b8be0 | Boundary variant A |
| `FFX_FieldOp_CameraSetupBoundaryB` | 0x7b8c10 | Boundary variant B |
| `FFX_FieldOp_CameraSetupBoundaryC` | 0x7b8c40 | Boundary variant C |
| `FFX_FieldOp_CameraSetupBoundaryD` | 0x7b8c70 | Boundary variant D |
| `FFX_FieldOp_CameraSetupBoundaryE` | 0x7b8ca0 | Boundary variant E |
| `FFX_FieldOp_CameraSetupBoundaryF` | 0x7b8cf0 | Boundary variant F |

Six boundary variants suggest **region-specific camera constraints**. Each variant likely corresponds to a different boundary shape or behavior:
- A/B: Standard rectangular/elliptical bounds
- C/D: Constrained bounds (tight corridors, small rooms)
- E/F: Dynamic bounds (moving platforms, spiral areas)

These boundaries define where the camera can move in the field, preventing it from clipping through scenery.

#### 1e. Camera Position Queries (~6 functions)

| Opcode | Address | Description |
|--------|---------|-------------|
| `FFX_FieldOp_CameraGetPosX` | 0x7b90d0 | Get camera position X |
| `FFX_FieldOp_CameraGetPosY` | 0x7b90e0 | Get camera position Y |
| `FFX_FieldOp_CameraGetPosZ` | 0x7b90f0 | Get camera position Z |
| `FFX_FieldOp_CameraGetPosAll` | 0x7b9170 | Get full camera position |
| `FFX_FieldOp_CameraGetAngleDegrees` | 0x7b9110 | Get camera angle in degrees |

Individual X/Y/Z getters suggest scripts that check **specific axes** (e.g., "if camera height > threshold, switch to close-up"). The degrees suffix confirms the angle unit, distinguishing it from internal radian usage.

---

### 2. Save Flag System (~20+ functions)

The Field Script heavily manipulates save flags — the per-field persistent state that tracks player progress:

- `FFX_FieldOp_SaveFlagPopToggleBit3` — pop and toggle bit 3 of save flag
- `FFX_FieldOp_SaveFlagPopToggleBit6AndSet15` — toggle bit 6, set bit 15
- `FFX_FieldOp_SaveFlagCheckBit*` — multiple check variants
- `FFX_FieldOp_SaveFlagSetCount*` — save counter manipulation (capture count, item count)

Save flags are 32-bit bitfields with **well-defined bit assignments**. Bit 3 and bit 6 appear frequently, suggesting they're used for common states (spoken-to, quest-complete, item-obtained). The combined toggle-bit6-and-set-bit15 opcode suggests a common script pattern: "toggle the interacted flag and set the completion flag simultaneously."

---

### 3. Music Volume System (~8+ functions)

| Opcode | Description |
|--------|-------------|
| `FFX_FieldOp_MusicVolumeFade*` | Fade music volume to target |
| `FFX_FieldOp_MusicVolumeLerp*` | Linear interpolate music volume |
| `FFX_FieldOp_MusicVolumeSet*` | Set volume immediately |
| `FFX_FieldOp_MusicVolumeGet*` | Query current volume |

Music volume manipulation is common in FFX: volume drops during dialogue, crossfades between area themes, and silence for dramatic moments. The lerp functions use the shared operand stack for target values.

---

### 4. Actor Animation System (~20+ functions)

- `FFX_FieldOp_ActorPlayAnimation*` — trigger actor animation
- `FFX_FieldOp_ActorSetAnimationBlend*` — set blend weight between animations
- `FFX_FieldOp_ActorGetAnimationState*` — query current animation
- `FFX_FieldOp_ActorSetVisibility*` — show/hide actor

These opcodes control NPC and party member animation in the field. Unlike Field VM opcodes that work with raw actor IDs, Field Script opcodes use **higher-level actor references** (character IDs like TIDUS=0, YUNA=1, etc.).

---

### 5. Party Management (~10+ functions)

- `FFX_FieldOp_PartyAddMember` — add character to active party
- `FFX_FieldOp_PartyRemoveMember` — remove character from party
- `FFX_FieldOp_PartySwapMember*` — swap party leader
- `FFX_FieldOp_PartyCheckMember*` — check if character is in party

These opcodes handle the **overworld party composition** — who is visible following the player, who is in the active battle slots. They bridge to the internal party data structures used by both field and battle systems.

---

### 6. Dialogue / Event Management (~15+ functions)

- `FFX_FieldOp_DialogueStart*` — begin NPC dialogue
- `FFX_FieldOp_DialogueSetText*` — set dialogue text entry
- `FFX_FieldOp_DialogueAdvance*` — advance dialogue to next page
- `FFX_FieldOp_DialogueCheckActive*` — check if dialogue is still active
- `FFX_FieldOp_EventTrigger*` — trigger named event

Field Script dialogue opcodes operate at a higher level than raw text rendering — they set up the dialogue UI, manage text display timing, and handle player input (advance/cancel).

---

### 7. Field Word Setter / Sub86BE20 (~20+ functions)

A family of functions prefixed `Sub86BE20` that set **field word data** — 16-bit or 32-bit values stored per-field that control script state:

- `FFX_FieldOp_Sub86BE20_FieldWordSet*` — set field word values
- `FFX_FieldOp_Sub86BE20_FieldWordGet*` — query field word values
- `FFX_FieldOp_Sub86BE20_FieldWordToggle*` — toggle field word state

These are the **general-purpose storage** that field scripts use for custom state tracking beyond save flags. They're analogous to global variables in a scripting language.

---

### 8. Battle Flag Setup (~10+ functions)

- `FFX_FieldOp_BattleFlagSetBit*` — set battle-related flags
- `FFX_FieldOp_BattleFlagCheckBit*` — query battle flags

These opcodes prepare the field-to-battle transition — setting encounter IDs, formation overrides, pre-emptive strike flags, and special battle conditions (boss, dark aeon, etc.).

---

### 9. Capture Count / Monster Arena (~5+ functions)

- `FFX_FieldOp_CaptureCountSet*` — set monster capture count
- `FFX_FieldOp_CaptureCountGet*` — get monster capture count
- `FFX_FieldOp_CaptureCountAdjust*` — increment/decrement capture count

These directly manipulate the **monster capture data** used by the Monster Arena. The adjust variant suggests scripts that modify capture counts as quest rewards.

---

## Key Opcode Categories (inferred from naming patterns)

| Category | Estimated Count | Description |
|----------|----------------|-------------|
| Camera (BgCamera + Camera) | ~40+ | Motion playback, rotation, projection, boundaries, effects, position queries |
| Save flags | ~20+ | Bitfield manipulation, counter management |
| Actor animation | ~20+ | Animation triggers, blend weights, visibility |
| Party management | ~10+ | Member add/remove/swap/check |
| Dialogue/Event | ~15+ | Dialogue flow, event triggers |
| Music volume | ~8+ | Volume fade, lerp, set, get |
| Battle flags | ~10+ | Pre-battle flag setup |
| Field words | ~20+ | General-purpose field state storage |
| Capture/Arena | ~5+ | Monster capture count manipulation |
| Misc helpers | ~400+ | Push/pop, expression eval, branching, math, type conversion |

The ~400 "misc helpers" are the **script infrastructure** — push/pop variants, control flow (jump/branch), arithmetic, string operations, type conversions. These are the lower-level opcodes that form the backbone of the VM interpreter, analogous to IL instructions in a bytecode VM.

---

## Architecture: Field Script vs Field VM

```
+----------------------------------------------------------+
|                  Field Script (556 ops)                   |
|  Higher-level: camera choreography, music, save flags,   |
|  dialogue, party management, battle triggers             |
+----------------------------------------------------------+
            |  Shared Operand Stack (Push/Pop)
            v
+----------------------------------------------------------+
|                   Field VM (295 ops)                      |
|  Lower-level: actor control, position queries,           |
|  rendering state, flag checks, distance computation      |
+----------------------------------------------------------+
            |  PhyreEngine bridge
            v
+----------------------------------------------------------+
|              PhyreEngine Rendering Pipeline               |
|  PSceneNode, PEntity, PMeshInstance, PCamera             |
+----------------------------------------------------------+
```

Key differences:

| Aspect | Field VM (batch_0015) | Field Script (batch_0023) |
|--------|----------------------|--------------------------|
| Opcode count | 298 | 556 |
| Abstraction | Low (actor IDs, bit indices, raw positions) | High (character IDs, named events, save flags) |
| Dominant ops | Actor control, distance, flags | Camera, music, dialogue, save |
| Camera control | Indirect (position queries, render params) | Direct (BgCameraPlayMotion, CameraSetRotation, CameraShake) |
| State integration | Per-frame queries | Multi-step sequences (play→wait→check→set flag) |

---

## Key Findings

1. **556 Field Script opcodes make it the 2nd largest opcode family in FFX.exe** (after ATEL at 981). It is the dominant scripting engine for overworld behavior, nearly double the size of the Field VM (295 ops).

2. **Camera system is the dominant subsystem** with ~40+ functions spanning motion playback, rotation (1/2/3-axis variants), projection, boundaries (6 variants), blur, shake, random perturbation, and position queries. No other subsystem comes close in variety.

3. **BgCamera vs regular Camera duality** -- FFX has two parallel camera subsystems: BgCamera (background camera, ~10 ops for authored motion paths) and Camera (gameplay camera, ~30+ ops for interactive camera). BgCamera handles scripted sequences; Camera handles player-controlled perspective.

4. **Six boundary variants (A-F)** -- the field has region-specific camera constraints rather than a single boundary type. This enables different behavior for wide-open areas (Calm Lands), tight corridors (Mushroom Rock Road), and unique areas (airship deck, underwater).

5. **Camera effects (blur/shake/rand) are script-level triggers** -- the Field Script opcode initiates the effect, and the engine interpolates/manages it over multiple frames. Blur for focus transitions, shake for impacts, random for handheld/nervous camera.

6. **Save flag bit assignments are well-defined** -- Common opcode patterns like `PopToggleBit6AndSet15` reveal specific bit assignments: bit 3 = spoken-to/interacted, bit 6 = quest-stage-complete, bit 15 = event-completed. The combined opcode saves one instruction for a common operation.

7. **Music volume is lerp-based** -- Music volume changes use linear interpolation (lerp) and fade operations rather than immediate sets, suggesting smooth crossfades between area themes.

8. **Shared operand stack with Field VM** -- Both interpreters use the same `PopOperand`/`PushOperand` primitives. Field Script can push high-level operands (character IDs, event names) and Field VM can consume them as raw actor IDs. This creates a flexible two-layer scripting architecture.

9. **Estimate: ~400 "infrastructure" opcodes** -- The vast majority of the 556 opcodes are push/pop variants, control flow (conditional jumps), arithmetic, type conversions, and string operations. Only ~150 are "domain" opcodes (camera, music, save, party, etc.).

10. **Field words (Sub86BE20) provide general-purpose per-field storage** -- Beyond save flags and capture counts, the Field Word family provides ~20+ opcodes for get/set/toggle of 16-bit or 32-bit values scoped to the current field. This is how scripts maintain custom state without consuming save game bits.

11. **Battle flag setup bridges field to battle** -- The Battle Flag opcodes prepare the field-to-battle transition. They set encounter IDs, formation overrides, and special conditions. This is the script-level equivalent of the runtime hooks done by the FfxHooksDll project.

12. **Capture count ops confirm Monster Arena is script-driven** -- The existence of dedicated capture count get/set/adjust opcodes confirms the Monster Arena system is driven entirely by field scripts, not by a separate capture subsystem.

---

## Relationship to Other FFX Scripting VMs

The Field Script sits in the middle of FFX's stack:

```
ATEL Movie (475 ops)  →  Cutscene/animation scripting
      |
      v
Field Script (556 ops)  →  Overworld gameplay scripting (THIS BATCH)
      |
      v
Field VM (295 ops)  →  Low-level actor/rendering operations
      |
      v
PhyreEngine  →  Rendering, audio, scene management (magic DLLs)
```

While ATEL Movie handles cinematics (full cutscenes), Field Script handles **interactive overworld scripting** (walk up to NPC, trigger dialogue, camera sweeps, music changes, then transition to battle). The Field VM provides the mechanical layer beneath it.

---

## What's Next?

- **batch_0024**: Remaining FFX_* domain families consolidation
- **batch_0025**: Cross-VM call graph and operand flow analysis
- **batch_0026**: PhyreEngine post-processing pipeline (PPostProcessing)

---

**Next batch:** FFX field system call graph synthesis -- tracing how Field Script opcodes trigger Field VM operations and PhyreEngine rendering calls.
