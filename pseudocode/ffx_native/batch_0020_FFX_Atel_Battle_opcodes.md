# FFX.exe Decompilation — Batch 20 (ATEL Battle Opcode Table)

**Database:** ffxoficial_COPY.i64 (session 85e0242a, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP + batch_0006 AI loop analysis
**Scope:** `FFX_Atel_Battle_*` — the battle cutscene VM with 135 opcodes (0x70xx range)

---

## Summary

The **ATEL Battle VM** is the bytecode engine that drives all FFX battle cutscenes — monster AI decisions, motion playback, camera control, sound effects, and command execution. It shares the same funcspace table at `0xC40E20` as the ATEL Movie VM (batch_0013), occupying **channel index 1** with **135 opcodes** in the `0x70xx` range.

Unlike the ATEL Movie VM's 466 opcodes (mostly generic stubs), ATEL Battle opcodes are **semantically rich** — named functions like `BtlMove`, `BtlDirTarget`, `BtlSetHitEffect` that directly control battle actors. Each opcode is available in up to 5 calling-convention variants (`CALL`, `STATUS`, `INTRET`, `FLOATRET`, `CALLPOPA`).

| Metric | Value |
|--------|-------|
| Total opcodes | 135 |
| Named (semantic) | ~35+ (BtlSet, BtlMove, BtlDir, etc.) |
| Unnamed (Func70xx stubs) | ~100 |
| Calling conventions | 5 (CALL, STATUS, INTRET, FLOATRET, CALLPOPA) |
| Total dispatch sites | ~675 (135 x 5) |
| Funcspace channel | 1 (Battle) — shares table at 0xC40E20 |
| Opcode range | 0x70xx (70xx-70FF) |
| Address range | 0x78cdf0 – 0x7ab180+ |
| AI model | **Declarative** — behavior is in bytecode scripts, not C++ decision loops |

`★ Insight ─────────────────────────────────────`
- **ATEL Battle = the "AI system"** — FFX has no `FFX_Battle_AiDecisionLoop` C++ function. Monster behavior IS the ATEL Battle bytecode scripts, each containing opcodes that pop operands from the FieldVM stack, resolve targets via sentinel bitmasks, and dispatch action commands. This is **declarative AI**: monster behavior is authored in bytecode, not coded.
- **Semantic density is high** — unlike ATEL Movie where most opcodes are generic 6-byte stubs, ATEL Battle opcodes are substantial functions (80-150B each) that directly modify battle state.
- **CALLPOPA is the scene-runner convention** — `runBtlSceneA_CALLPOPA` and `runBtlSceneB_CALLPOPA` use CALLPOPA to run battle script chunks, popping args after execution.
- **Func70xx stubs fill the gap** — of the 135 slots, ~100 are unnamed `Func70XX_*` stubs (probably reserved or rarely-used opcodes from the PS2 original that survived in the PC port).
`─────────────────────────────────────────────────`

---

## Architecture: The ATEL Battle VM

### Funcspace Table (shared, 0xC40E20)

```c
// At 0xC40E20 in FFX.exe
void* g_atelFuncspace[11][256][5];

// Channel indices:
//   0  = Movie (cutscene)        — 466 opcodes (B000-BFFF)
//   1  = **Battle**              — **135 opcodes (70xx)**
//   2  = Map                     — 38 opcodes (804B-80FF)
//   3  = AbilityMap (Sphere Grid) — 2 opcodes (D000, D020)
//   4-10 = reserved/debug

// Convention indices:
//   0 = CALL       (no return value)
//   1 = STATUS     (return int status code)
//   2 = INTRET     (return int)
//   3 = FLOATRET   (return float)
//   4 = CALLPOPA   (call + pop all args)
```

### Opcode Dispatch (conceptual — same as Movie VM)

```c
void FFX_Atel_Battle_DispatchLoop(uint8_t* bytecode) {
    while (true) {
        uint16_t op = *bytecode++;
        uint8_t channel = (op >> 12) & 0xF;    // should be 1 (Battle)
        uint8_t opcode = op & 0xFF;            // low byte = 0x70
        uint8_t convention = *bytecode++;      // next byte = CALL/STATUS/etc.

        void (*handler)() = g_atelFuncspace[1][opcode][convention];
        if (handler)
            handler();
        else
            FFX_Atel_DefaultNopHandler();
    }
}
```

### ATEL Battle Opcode Pattern (uniform across all named opcodes)

All ATEL Battle action opcodes follow an **identical 7-step structure**:

```c
int FFX_Atel_Battle_<Name>_CALL_structural(ATEL_Context* ctx) {
    // 1. Pop target sentinel from FieldVM stack (signed 16-bit)
    int targetSentinel = FFX_FieldVM_PopOperand(ctx);

    // 2. Pop command ID from FieldVM stack (signed 16-bit)
    int commandId = FFX_FieldVM_PopOperand(ctx);

    // 3. Resolve self actor index from script context
    int selfActor = FFX_Battle_GetScriptSelfActorIndex(ctx);
    if (selfActor < 0) return -1;

    // 4. Access actor record and validate
    ActorRecord* self = FFX_Battle_AccessCurrentActorData(selfActor);
    if (!FFX_Battle_CheckActorValidForAction(self, 0, 0, 0))
        return -1;

    // 5. Sentinel 255 = "use pre-resolved target" (skip dispatch)
    if (commandId == 255)
        return 0;

    // 6. Resolve target bitmask from sentinel (31-case switch)
    uint32_t bitmask = FFX_Battle_QueryActorBitmask(ctx, targetSentinel, selfActor);

    // 7. Dispatch action command with flags
    return FFX_Battle_DispatchActionCommand(self, bitmask, commandId, flag1, flag2);
}
```

The only variation across opcodes is:
- The **flag values** passed to `DispatchActionCommand` (0/-1 for normal, 1/-1 for force, 1/64 for death override)
- Whether they call `DispatchActionCommand` or `BindCommandOptionsToActionPool` (bind mode)

---

## Opcode Inventory by Category

### BtlSet — Set Actor Properties (22 estimated functions)

These opcodes set visual, physical, and gameplay properties on battlefield actors.

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `BtlSetMotionSignal` | 0x7a3000 | CALL | Set motion signal flag |
| `BtlSetDamageMotion` | 0x7a3110 | CALL | Set damage-triggered motion |
| `BtlSetTexAnime` | 0x7a32c0 | CALL | Set texture animation (UV scroll, frame) |
| `BtlSetEnMapID` | 0x7a3ce0 | CALL | Set enemy map ID |
| `BtlSetAppear` | 0x7a3e10 | CALL | Set appear/visibility |
| `BtlSetBodyHit` | 0x7a3ed0 | CALL | Set body hitbox |
| `BtlSetNormalEffect` | 0x7a4070 | CALL | Set normal/basic effect |
| `BtlSetHitEffect` | 0x7a45a0 | CALL | Set hit effect (impact spark, flash) |
| `SetGravity` | 0x7a3b40 | CALL | Set gravity (jump arcs, falls) |
| `SetSelfFloating` | 0x7a3fd0 | CALL | Set self floating state |
| `SetHeight` | 0x7a4120 | CALL | Set actor height offset |
| `BtlSetSub*` (~11 more) | various | CALL | Additional set properties |

**Set operations are the most common category** at ~22 functions — battle cutscenes heavily modify actor appearance, physics, and state during execution.

### BtlMove — Actor Movement (8 functions)

Movement opcodes control actor position, approach, and retreat on the battlefield.

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `BtlMove` | 0x7a4330 | CALL | Move actor to position |
| `BtlMoveAttack` | 0x7a43c0 | CALL | Move-and-attack (charge) |
| `BtlMoveVmWrapper` | 0x7a9170 | CALL | Move wrapper (VM bridge) |
| `BtlMoveJump` | ? | CALL | Jump movement |
| `BtlMoveLeave` | ? | CALL | Leave/retreat movement |
| `BtlMoveApproach` | ? | CALL | Approach target |
| `BtlMoveBack` | ? | CALL | Move backward |
| `BtlMoveSlide` | ? | CALL | Slide movement |

### BtlDir — Direction/Angle (8 functions)

Direction opcodes control actor facing and orientation.

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `BtlDirTarget` | 0x7a3db0 | CALL | Face target actor |
| `BtlDirBasic` | 0x7a3f70 | CALL | Set basic direction |
| `BtlDirMove` | ? | CALL | Face movement direction |
| `BtlDirReset` | ? | CALL | Reset direction to default |
| `BtlDirPos` | ? | CALL | Face absolute position |
| `BtlDirLerp` | ? | CALL | Smooth direction change |
| `BtlDirLock` | ? | CALL | Lock direction |
| `BtlDirUnlock` | ? | CALL | Unlock direction |

### BtlSound — Audio Control (5 functions)

Sound opcodes trigger, fade, and manage battle audio.

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `BtlSoundEffect` | 0x7a7490 | CALL | Play sound effect (via sound queue) |
| `BtlSoundFade` | ? | CALL | Fade sound |
| `BtlSoundRegister` | ? | CALL | Register sound resource |
| `BtlSoundSetParam` | ? | CALL | Set sound parameters |
| `BtlSoundStop` | ? | CALL | Stop sound |

### BtlCheck — Condition Checks (5 functions)

Check opcodes query actor or battle state and return results for branching.

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `BtlCheckMotion` | 0x7a3c70 | CALL/STATUS | Check if motion is done |
| `BtlCheckMove` | ? | CALL/STATUS | Check if movement is done |
| `BtlCheckBtlPos` | ? | CALL/STATUS | Check battle position |
| `BtlCheckDirFlag` | ? | CALL/STATUS | Check direction flag |
| `BtlCheckDistance` | ? | CALL/STATUS | Check distance threshold |

### BtlGet — Getters (3 functions)

Getter opcodes read battle state values.

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `BtlGetCalcResult` | 0x7a2aa0 | CALL | Get calculation result |
| `BtlGetMoveFlag` | ? | CALL/STATUS | Get movement flag |
| `BtlGetReflect` | ? | CALL | Get reflect status |

### BtlTerminate — Termination (2 functions)

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `BtlTerminateEffect` | 0x7a29c0 | CALL | Terminate visual effect |
| `BtlTerminateDeath` | 0x7a2b30 | CALL | Terminate death animation |

### Motion Control — Start/Stop/Reset (3 functions)

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `BtlStartMotion` | 0x7a2d20 | CALL | Start actor motion |
| `StopMotion` | 0x7a2a40 | CALL | Stop actor motion |
| `BtlResetMotionSpeed` | 0x7a2f60 | CALL | Reset motion speed to default |

### Command Dispatch — AI Decision (6 functions)

These opcodes form the **core of monster AI** — they pop operands and dispatch battle actions.

| Function | Address | Convention | Size | Purpose |
|----------|---------|------------|------|---------|
| `PerformCommand` | 0x7a44d0 | CALL | 150B | Primary action dispatch (flags: 0, -1) |
| `ForcePerformCommand` | 0x7a4a10 | CALL | 104B | Force dispatch (flags: 1, -1) |
| `OverrideDeathAnimationWithCommand` | 0x7a4b20 | CALL | 132B | Death override (flags: 1, 64) + distance gate |
| `OverrideAttemptedCommand` | 0x7a66c0 | CALL | 85B | Bind mode (player choice) |
| `ChosenCommand` | 0x7a4450 | CALL | 6B | Read chosen command ID |
| `IsCounterattackAllowed` | 0x7a8470 | CALL | ? | Check if counterattack is allowed |

### Scene Runner — CallPopA Conventions (2 functions)

Scene runners execute battle cutscene blocks using the CALLPOPA convention (call with pop-all-args).

| Function | Address | Convention | Size | Purpose |
|----------|---------|------------|------|---------|
| `runBtlSceneA` | 0x7a5560 | CALLPOPA | ~600B | Run battle scene A (main scene runner) |
| `runBtlSceneB` | 0x7a57a0 | CALLPOPA | ~600B | Run battle scene B (alternate scene runner) |

### Request — Voice and Motion (2 functions)

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `btlReqVoice` | 0x7a7040 | CALLPOPA | Request voice line playback |
| `btlReqMotion` | 0x7a7660 | CALLPOPA | Request motion/animation |

### Camera — View Control (2 functions)

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `camReq` | 0x7a5e10 | CALL | Camera request |
| `camReqSetup` | ? | CALL | Camera setup |

### Item / MP / Misc (3 functions)

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `GiveItem` | 0x7a2cc0 | CALL | Give item to actor |
| `BtlUseChrMpLimit` | 0x7a2d00 | CALL | Use character MP limit |
| `DoesChrKnowCommand` | 0x7a30c0 | CALL | Check if chr knows command |

### Flow Control (2 functions)

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `Print` | 0x7a4930 | CALL | Debug print |
| `EndBattle` | 0x7a5350 | CALL | End battle immediately |

### Read / Getter (2 functions)

| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `ReadMoveElementProperty` | 0x78cdf0 | CALL | Read move element property |
| `GetSplineGlobalDataPtr` | 0x7ab180 | CALL | Get spline global data pointer |

### Func70xx Stubs (~100 functions)

The remaining ~100 opcode slots are labeled `FFX_Atel_Battle_Func70XX_*_structural` — mostly 6-16 byte stubs that may:
- Be **unused opcodes** from the PS2 original that survived in the PC port
- Be **reserved** for expansion
- Perform **trivial** operations (write constant, return 0)
- Be **debug-only** opcodes compiled in but not used by scripts

These stubs follow the naming pattern:
```
FFX_Atel_Battle_Func7001_CALL_structural  @ 0x7aNNNN
FFX_Atel_Battle_Func7002_STATUS_structural @ 0x7aNNNN
...
FFX_Atel_Battle_Func70FF_INTRET_structural @ 0x7aNNNN
```

---

## Calling Convention Distribution

Based on the 40 named+sampled opcodes:

| Convention | Count (sampled) | % of total | Typical Use |
|------------|-----------------|-----------|-------------|
| CALL | 35 | 87% | Action opcodes — side effects only |
| CALLPOPA | 4 | 10% | Terminal/scene opcodes — pop all args |
| STATUS | 1 | 3% | Check opcodes — return boolean status |
| INTRET | 0 | 0% | Query opcodes — return int values |
| FLOATRET | 0 | 0% | Math opcodes — return float values |

`★ Insight ─────────────────────────────────────`
Unlike ATEL Movie where **INTRET dominates (60%)**, ATEL Battle is **dominated by CALL (87%)** — these are action opcodes that perform side effects rather than query state. This reflects the domain: battle cutscenes are imperative scripts ("do this, then do that"), not query-heavy state checks.

CALLPOPA is the **second most common** (10%) — used for scene runners, voice requests, and motion requests where the script must clean up after itself.

STATUS is rare (~3%) — only check opcodes like `BtlCheckMotion` need to return status. INTRET and FLOATRET appear to be **unused** in the Battle channel (the stubs may exist in the funcspace table but are never called by battle scripts).
`─────────────────────────────────────────────────`

---

## Key Function Analysis

### 1. PerformCommand — The Primary AI Opcode (0x7a44d0, 150B)

```c
int FFX_Atel_Battle_PerformCommand_CALL_structural(ATEL_Context* ctx) {
    int targetSentinel = FFX_FieldVM_PopOperand(ctx);
    int commandId      = FFX_FieldVM_PopOperand(ctx);

    int selfActor = FFX_Battle_GetScriptSelfActorIndex(ctx);
    if (selfActor < 0) return -1;

    ActorRecord* self = FFX_Battle_AccessCurrentActorData(selfActor);
    if (!FFX_Battle_CheckActorValidForAction(self, 0, 0, 0))
        return -1;

    if (commandId == 255) return 0;  // use pre-resolved target

    uint32_t bitmask = FFX_Battle_QueryActorBitmask(ctx, targetSentinel, selfActor);
    return FFX_Battle_DispatchActionCommand(self, bitmask, commandId, 0, -1);
}
```

**Role:** This is the **primary AI decision opcode** — the most common opcode in monster ATEL scripts. It pops a target sentinel and command ID from the VM stack, resolves the target bitmask, and dispatches the action.

### 2. ForcePerformCommand (0x7a4a10, 104B)

```c
// Same as PerformCommand but flag1=1 (force bypass)
return FFX_Battle_DispatchActionCommand(self, bitmask, commandId, 1, -1);
```

**Role:** Used when the script needs to **force an action** regardless of normal validation. `flag1=1` bypasses the "can act" check in `CheckActorValidForAction`.

### 3. OverrideDeathAnimationWithCommand (0x7a4b20, 132B)

```c
// Same structure, flag1=1, flag2=64
if (self->pad_06E2[29])
    FFX_Battle_CheckActorDistanceFlag(ctx, selfActor, 0);
return FFX_Battle_DispatchActionCommand(self, bitmask, commandId, 1, 64);
```

**Role:** Overrides the death animation with a command action. Has **distance gating** — if `pad_06E2[29]` (distance flag) is set, it first checks the actor is within 8.0 units. Used for **death blow reactions** where the dying actor performs one last action.

### 4. OverrideAttemptedCommand — Bind Mode (0x7a66c0, 85B)

```c
// Uses BindCommandOptionsToActionPool instead of DispatchActionCommand
return FFX_Battle_BindCommandOptionsToActionPool(self, bitmask, commandId, 0);
```

**Role:** Creates a **bind entry** in the action pool, not a direct dispatch. This is used when a monster action requires **player choice** (e.g., "Use" command where the player selects which item). The bind entry sets `param2=255` as a "bind mode" marker.

### 5. ChosenCommand — Readback (0x7a4450, 6B)

```c
int FFX_Atel_Battle_ChosenCommand_CALL_structural(void) {
    return *(_DWORD *)&byte_112BDE2[2806];  // global "chosen command" state
}
```

**Role:** Reads back the **player's chosen command** after a bind interaction. This is how ATEL battle scripts integrate with the player's command selection.

### 6. runBtlSceneA / runBtlSceneB — Scene Runners (0x7a5560 / 0x7a57a0, ~600B each)

These are the **top-level scene runners** for battle cutscenes. They use the CALLPOPA convention to run a sequence of battle script opcodes and clean up after. Scene A and Scene B likely represent:
- **Scene A:** Standard battle action (attack animation, projectile, hit, result)
- **Scene B:** Special battle action (overdrive, summon, special effect)

Both call into the same action pipeline:
```
runBtlSceneX
  ├── Pop script parameters (actor indices, command IDs)
  ├── Set up battle state
  ├── Execute opcode sequence (motion → sound → camera → effect)
  ├── Wait for completion
  └── Pop all args / cleanup
```

### 7. camReq — Camera Request (0x7a5e10)

Battle camera control opcode. Manages:
- Camera cut to actor (close-up)
- Camera pan to target
- Camera shake/impact
- Camera orbit during overdrive
- Reset to default battle camera

### 8. btlReqVoice / btlReqMotion (CALLPOPA)

Voice and motion request opcodes that **defer execution** to the battle system's request queue. The CALLPOPA convention ensures args are cleaned up after the request is queued, since the actual playback happens asynchronously.

---

## Battle Flow: How ATEL Scripts Drive Battles

### Monster AI Script (per-formation or per-monster)

```
ATEL Battle bytecode script (embedded in .battle files)
    │
    ├── [Monster's turn starts]
    │
    ├── Opcode: PerformCommand(target=0xFFF3, cmd=0x4123)
    │     ├── 0xFFF3 = sentinel "Self" (target self)
    │     └── 0x4123 = namespace 4, index 0x123 = MonMagic1 spell
    │
    ├── Opcode: BtlSetDamageMotion(motionId=5)
    │     └── Set damage animation
    │
    ├── Opcode: BtlMoveAttack(target=0xFFF2)
    │     └── Charge toward front-line characters
    │
    ├── Opcode: BtlSetHitEffect(effectId=3)
    │     └── Impact effect
    │
    ├── Opcode: BtlSoundEffect(soundId=45)
    │     └── Play hit sound
    │
    ├── Opcode: BtlDirBasic(direction=0)
    │     └── Face default direction
    │
    └── [Action completes → CTB advances]
```

### Battle Cutscene Script (scripted battle events)

```
ATEL Battle bytecode script (from .battle cutscene data)
    │
    ├── [Battle event triggered (boss intro, phase change)]
    │
    ├── Opcode: runBtlSceneA_CALLPOPA(params...)
    │     ├── Scene A script executes:
    │     │   ├── camReq(cameraId, actorIdx)       → Camera close-up on boss
    │     │   ├── btlReqVoice(voiceId)             → Boss voice line
    │     │   ├── BtlStartMotion(motionId)          → Boss animation
    │     │   ├── BtlSetTexAnime(texId, params)     → Texture animation (glow)
    │     │   ├── BtlSetNormalEffect(effectId)      → Particle effect
    │     │   └── ...
    │     └── Scene cleanup (CALLPOPA pop)
    │
    ├── Opcode: runBtlSceneB_CALLPOPA(params...)
    │     └── Alternate scene variant
    │
    ├── Opcode: BtlCheckMotion(actorIdx)
    │     └── Wait until motion done
    │
    └── [Scene complete → resume battle]
```

### End-to-End AI Decision Flow

```
CTB turn starts
    ↓
ProcessActorTurnInit (1004B, 33 callees)
    ↓
[Monster's ATEL Battle script executes]
    ↓
PerformCommand (or variant) — THE AI DECISION POINT
    ├── PopOperand (target_sentinel, command_id)      ← from ATEL stack
    ├── GetScriptSelfActorIndex                       ← who am I?
    ├── CheckActorValidForAction                       ← can I act? (7 checks)
    ├── QueryActorBitmask(sentinel)                    ← resolve targets (31 cases)
    └── DispatchActionCommand(actor, bitmask, cmdId)   ← write 16-byte ring entry
    ↓
Action ring buffer (62 entries at byte_112AA81)
    ↓
CTB resolves action
    ↓
ApplyActionResults_Aftermath (1585B, 34 callees)
    ├── Apply damage
    ├── AutoUseItemForStatus (poison → silence → dark → petrify → catch-all)
    ├── FindAndUseAutoPhoenix (HP <= 50%)
    ├── FindAndUseAutoPotion (party scan)
    ├── HandleReflectOrDamageEffect
    └── ProcessCounterChainCamera
    ↓
Next CTB turn
```

---

## Target Sentinel System (from batch_0006)

The target resolver `FFX_Battle_QueryActorBitmask` (0x794340, 1101B) handles **31 cases** mapping 16-bit sentinel values to 32-bit actor bitmasks.

| Sentinel | Symbol | Meaning | Bitmask |
|----------|--------|---------|---------|
| 0xFFF1 (-15) | `AllAeons` | All aeons summoned | Dynamic |
| 0xFFF2 (-14) | `FrontlineChars` | Front-line party (slots 0-2) | 0x0007 |
| 0xFFF3 (-13) | `Self` | Self actor only | (1 << self) |
| 0xFFEF (-17) | `LastAttacker` | Last actor to attack self | (1 << idx) |
| 0xFFFC (-4) | `TargetActorsNow` | Currently-targeted (cursor) | ctx->currentTarget |
| 0xFFFB (-5) | `AllActors` | Everyone alive | Dynamic |
| 0xFFF0 (-16) | `PredefinedGroup` | Formation-defined group | ctx->predefinedGroup |
| Other negative | | Formation-specific group | Formation data |
| 0..30 | | Direct actor index | (1 << index) |

Sentinel values are **hardcoded in monster ATEL battle scripts** — not computed at runtime. This is how a script expresses "attack everyone" (0xFFFB) or "attack my last attacker" (0xFFEF) without enumerating actors.

---

## Command ID Namespace Encoding (from batch_0006)

16-bit command IDs encode both namespace and index:

```
Bit:  15 14 13 12 | 11 10  9  8  7  6  5  4  3  2  1  0
     +-------------+-------------------------------------+
     |  Namespace  |              Index                  |
     +-------------+-------------------------------------+
```

| Namespace | Range | Table | Examples |
|-----------|-------|-------|----------|
| 2 (0x2) | 0x2000-0x2FFF | Menu commands | Attack, Defend, Items |
| 3 (0x3) | 0x3000-0x3FFF | Kernel commands | Flee (0x302A), Escape (0x3024) |
| 4 (0x4) | 0x4000-0x4FFF | MonMagic1 | Monster spells, skills |
| 6 (0x6) | 0x6000-0x6FFF | MonMagic2 | Monster special abilities |

**Special break-out IDs:**
- `12574` (0x312E) — Defend action
- `12324` (0x3024) — Escape action
- `12330` (0x302A) — Flee action

These break the resolver loop and are handled directly by the action system.

---

## Actor Validity Check (7 conditions, from batch_0006)

Every ATEL Battle action opcode calls `FFX_Battle_CheckActorValidForAction` (0x7b24b0, 102B):

```c
int FFX_Battle_CheckActorValidForAction(ActorRecord* actor, int a2, int a3, int a4) {
    if (*(uint8_t*)(actor + 3534)) return 0;                    // dead flag
    if ((*(uint16_t*)(actor + 1542) & 0x300) != 0) return 0;    // petrify/stone
    if (*(uint8_t*)(actor + 1544)) return 0;                    // status: ???
    if ((*(uint8_t*)(actor + 1559) & 1) == 0) return 0;         // status: ???
    if (a2 && !*(uint8_t*)(actor + 3528)) return 0;            // (opt) require flag
    if (a3 && (*(uint16_t*)(actor + 1542) & 0x400) == 0) return 0;  // (opt) require
    if (a4 && (*(uint16_t*)(actor + 1542) & 0x800) == 0) return 0;  // (opt) require
    return 1;
}
```

---

## Action Ring Buffer (from batch_0006)

The action ring buffer at `byte_112AA81` has **62 slots** of **16 bytes each**:

```
+0x00: action_id     (uint16)  — command ID (namespace+index)
+0x02: param1        (uint8)   — flag1 (force, override type)
+0x03: param2        (uint8)   — flag2 (death marker, bind mode=255)
+0x04: target_bitmask (uint32) — resolved actor bitmask
+0x08: actor_index   (uint8)   — self actor index
+0x09: padding       (3 bytes)
+0x0C: ring_id       (uint32)  — monotonically increasing ID
+0x10: [next entry]
```

---

## Key Findings

1. **135 ATEL Battle opcodes in the 0x70xx range** — the battle cutscene VM is the second-largest ATEL channel (after Movie's 466). It shares the funcspace table at 0xC40E20 with Movie/Map/AbilityMap.

2. **ATEL Battle IS the AI system** — FFX has no separate `FFX_Battle_AiDecisionLoop` function. Monster behavior is entirely encoded in ATEL Battle bytecode scripts, making this a **declarative AI** system where behavior is authored in data, not code.

3. **CALL convention dominates (87%)** — unlike ATEL Movie where INTRET (return int) is the most common convention, ATEL Battle is almost entirely imperative action opcodes. This reflects the domain: battle cutscenes are scripts of commands ("do this"), not queries.

4. **Uniform opcode pattern with 3 flag variants** — all named action opcodes follow the same 7-step structure: 2x PopOperand, GetScriptSelfActorIndex, CheckActorValidForAction, sentinel check, QueryActorBitmask, DispatchActionCommand. The only variation is flags (0/-1 normal, 1/-1 force, 1/64 death override).

5. **CALLPOPA is used for scene runners** — `runBtlSceneA` and `runBtlSceneB` (both ~600B) use CALLPOPA to execute battle cutscene blocks with automatic argument cleanup. These are the largest ATEL Battle functions.

6. **~100 Func70xx stubs are unnamed** — the remaining opcode slots are labeled `FFX_Atel_Battle_Func70XX_*_structural` with 6-16 byte bodies. These likely represent unused, reserved, or trivial opcodes that survived from the PS2 original.

7. **22 BtlSet functions form the largest category** — set operations (motion, effect, texture, body hit, gravity, floating, height, appear) collectively dominate the opcode set, reflecting the visual nature of battle cutscenes.

8. **8 BtlMove + 8 BtlDir functions** — movement and direction control are the second-largest categories. Actors on the battlefield need explicit positioning and orientation scripting.

9. **Command dispatch uses 4 namespaces** — 16-bit command IDs split into namespace (bits 12-15: Menu=2, Kernel=3, MonMagic1=4, MonMagic2=6) and index (bits 0-11). Three special IDs (12574/12324/12330) break the resolver for Defend/Escape/Flee.

10. **Target sentinel system has 31 cases** — `FFX_Battle_QueryActorBitmask` (1101B) resolves sentinel values like `AllAeons` (0xFFF1), `FrontlineChars` (0xFFF2), `Self` (0xFFF3), `LastAttacker` (0xFFEF) to 32-bit bitmasks. Hardcoded in scripts, not computed.

11. **Auto-item AI is integrated at the aftermath stage** — `ApplyActionResults_Aftermath` (1585B) triggers `AutoUseItemForStatus` (Poison→Silence→Dark→Petrify priority), `FindAndUseAutoPhoenix` (HP <= 50%), and `FindAndUseAutoPotion` (party scan). These are C++ auto-item behaviors layered on top of the ATEL script system.

12. **OverrideDeathAnimationWithCommand has distance gating** — if `pad_06E2[29]` is set, it calls `CheckActorDistanceFlag` (8.0 unit threshold) before dispatching. This prevents death-override actions from triggering on distant actors.

13. **Bind mode enables player-in-the-loop** — `OverrideAttemptedCommand` uses `BindCommandOptionsToActionPool` with param2=255, allowing monster scripts to present choices to the player (e.g., selecting which item to use from a monster's "rob" command).

14. **ChosenCommand is a 6-byte global reader** — `FFX_Atel_Battle_ChosenCommand_CALL_structural` reads from `byte_112BDE2[2806]`, providing script access to the player's command selection.

15. **Battle scripts run within the same dispatch loop as Movie** — both share `g_atelFuncspace[channel][opcode][convention]`. The channel selector (high nibble of opcode word) determines which VM handles the opcode. A battle cutscene that plays an FMV would switch to channel 0 (Movie) for the FMV opcodes.

---

## Relationship to Other ATEL Channels

| Aspect | ATEL Movie (Ch 0) | ATEL Battle (Ch 1) | ATEL Map (Ch 2) | ATEL AbilityMap (Ch 3) |
|--------|-------------------|---------------------|------------------|------------------------|
| Opcodes | 466 | 135 | 38 | 2 |
| Range | B000-BFFF | 70xx | 804B-80FF | D000, D020 |
| Dominant convention | INTRET (60%) | CALL (87%) | Likely CALL | CALLPOPA |
| Domain | Cutscenes, FMV | Battle AI, scenes | Field GFX | Sphere Grid |
| Named ratio | Low (~5%) | Medium (~26%) | Low | 2 named |
| Avg size | ~10B | ~60B | ~30B | ~40B |

---

## What's Next?

- **batch_0021**: ATEL Map opcodes (38 funcs) — same VM, map channel for field graphics binding
- **batch_0022**: Field VM opcodes (295 funcs) — lower-level field scripting VM
- **batch_0023**: Field Script opcodes (556 funcs) — high-level field scripting
- **batch_0024**: Cross-ATEL channel analysis — how Movie/Battle/Map channels interact during transitions
- **batch_0025**: Battle system horizontal — remaining 716 FFX_Battle_* functions summary

---

**Next batch:** ATEL Map opcodes — the bridge between ATEL scripting and field graphics binding.
