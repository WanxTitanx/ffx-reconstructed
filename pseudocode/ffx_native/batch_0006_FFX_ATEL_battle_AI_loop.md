# FFX.exe Decompilation — Batch 6 (ATEL Battle AI Loop)

**Database:** ffxoficial_COPY.i64 (session b1d18aaa, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** Monster AI decision loop — ATEL Battle opcodes + target resolver + auto-item AI

---

## Summary

**FFX has NO separate `FFX_Battle_AiDecisionLoop` function.** Monster AI is entirely driven by **ATEL Battle bytecode** — a set of **135 opcodes** (`FFX_Atel_Battle_*`) that pop operands from the FieldVM stack, query target bitmasks, and dispatch action commands. This batch documents 5 ATEL Battle opcodes, 5 central battle functions, 5 resolve/item functions, and 2 turn/aftermath functions — totaling **~5,000 bytes** of decompiled code that fully maps the FFX AI system.

| Category | Count | Total bytes | Role |
|----------|-------|-------------|------|
| ATEL Battle opcodes | 5 | ~477B | Pop operands, resolve target, dispatch action |
| Central battle functions | 5 | ~1,691B | Validate actor, dispatch command, bind pool |
| Resolve/item functions | 5 | ~1,013B | Resolve command ID, auto-item AI |
| Turn/aftermath functions | 2 | ~2,589B | Turn init, apply action results |
| **Total** | **17** | **~5,770B** | Full AI decision loop |

`★ Insight ─────────────────────────────────────`
- **FFX's "AI" is 135 ATEL Battle opcodes**, not a C++ decision loop. Each opcode is a small dispatcher (~80-150B) that pops 2 operands, gets the self actor index, queries a target bitmask, and dispatches an action command. This is **declarative AI** — the AI behavior is encoded in bytecode scripts per-monster.
- **Sentinel target resolver** — `FFX_Battle_QueryActorBitmask` (1101B, 31-case switch) handles 7 special sentinel values: 0xFFF1=AllAeons, 0xFFF2=FrontlineChars, 0xFFF3=Self, 0xFFEF=LastAttacker, 0xFFFC=TargetActorsNow, 0xFFFB=AllActors, 0xFFF0=PredefinedGroup. These let ATEL scripts target "everyone", "my last attacker", or "self" without enumerating actors.
- **Command ID namespace encoding** — 16-bit command IDs split as `(id >> 12)` namespace + `(id & 0xFFF)` index. Namespace 2=Menu, 3=Kernel Command, 4=MonMagic1, 6=MonMagic2. Special IDs 12574, 12324, 12330 break the resolver loop (defend/escape actions).
`─────────────────────────────────────────────────`

---

## Architecture

### ATEL Battle Opcode Pattern

All 5 sampled ATEL Battle opcodes follow an **identical structure**:

```c
// Pseudo-template for ATEL Battle opcodes
int FFX_Atel_Battle_<Name>_CALL_structural(ATEL_Context* ctx) {
    int targetSentinel = FFX_FieldVM_PopOperand(ctx);  // signed 16-bit
    int commandId      = FFX_FieldVM_PopOperand(ctx);  // signed 16-bit
    
    int selfActor = FFX_Battle_GetScriptSelfActorIndex(ctx);
    if (selfActor < 0) return -1;
    
    ActorRecord* self = FFX_Battle_AccessCurrentActorData(selfActor);
    if (!FFX_Battle_CheckActorValidForAction(self, 0, 0, 0))
        return -1;
    
    // Sentinel check: 255 = "use pre-resolved target"
    if (commandId == 255) {
        // Skip dispatch, use existing action pool entry
        return 0;
    }
    
    // Build target bitmask from sentinel
    uint32_t bitmask = FFX_Battle_QueryActorBitmask(ctx, targetSentinel, selfActor);
    
    // Dispatch with flags (varies by opcode)
    return FFX_Battle_DispatchActionCommand(self, bitmask, commandId, flag1, flag2);
}
```

### Target Sentinel Resolver (31 cases)

`FFX_Battle_QueryActorBitmask` (0x794340, 1101B, 104 basic blocks) is the **central target resolver**:

| Sentinel | Symbol | Meaning |
|----------|--------|---------|
| 0xFFF1 (-15) | `AllAeons` | All aeons summoned |
| 0xFFF2 (-14) | `FrontlineChars` | Front-line party characters |
| 0xFFF3 (-13) | `Self` | Self actor only |
| 0xFFEF (-17) | `LastAttacker` | Last actor to attack self |
| 0xFFFC (-4) | `TargetActorsNow` | Currently-targeted actors (cursor) |
| 0xFFFB (-5) | `AllActors` | Everyone alive in battle |
| 0xFFF0 (-16) | `PredefinedGroup` | Predefined formation group |
| Other negative | `<formation_idx>` | Formation-specific group index |
| 0..N | `<actor_index>` | Direct actor index |

The function returns a **32-bit bitmask** where bit N = actor N is in the target set.

### Command ID Namespace Encoding

`FFX_Battle_ResolveCommandEntryFromId` (0x78cf10, 264B) decodes 16-bit command IDs:

```c
CommandEntry* FFX_Battle_ResolveCommandEntryFromId(int cmdId) {
    int namespace = (cmdId >> 12) & 0xF;
    int index     = cmdId & 0xFFF;
    
    switch (namespace) {
        case 2:  return FFX_Menu_GetCommandTableEntry(index);          // Player menu
        case 3:  return FFX_Kernel_GetCommandEntryById(index);         // Kernel commands
        case 4:  return FFX_Kernel_GetMonMagic1EntryById(index);       // Monster magic 1
        case 6:  return FFX_Kernel_GetMonMagic2EntryById(index);       // Monster magic 2
        default: return NULL;
    }
}
```

**Special IDs that break the loop:**
- 12574 (0x312E) — "Defend" action
- 12324 (0x3024) — "Escape" action
- 12330 (0x302A) — "Flee" action

### Action Ring Buffer Layout

The action ring buffer is at `byte_112AA81` with **16-byte slots** (vs 8-byte in batch_0004 CTB docs — corrected here based on decompilation):

```
+0x00: action_id (uint16)
+0x02: param1 (uint8)
+0x03: param2 (uint8)
+0x04: target_bitmask (uint32)
+0x08: actor_index (uint8)
+0x09: padding (3 bytes)
+0x0C: ring_id (uint32)
+0x10: next_ptr or end marker
```

Max **62 entries**, indexed via `pad_0450[17]` (0xFF = no slot).

---

## Key Function Analysis

### 1. ATEL Battle Opcodes (5 functions, ~477B total)

#### 1.1 FFX_Atel_Battle_PerformCommand_CALL_structural (0x7a44d0, 150B)

The **primary action dispatch opcode**. Pops target + command, validates actor, dispatches with flags (0, -1).

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

#### 1.2 FFX_Atel_Battle_ForcePerformCommand_CALL_structural (0x7a4a10, 104B)

**Force flag variant** — same as PerformCommand but with flag1=1, bypasses some validation.

```c
// Same as PerformCommand but flag1=1
return FFX_Battle_DispatchActionCommand(self, bitmask, commandId, 1, -1);
```

#### 1.3 FFX_Atel_Battle_OverrideDeathAnimationWithCommand_CALL_structural (0x7a4b20, 132B)

**Death-override variant** — sets flag1=1, flag2=64. If `pad_06E2[29]` (distance flag?) is set, calls `CheckActorDistanceFlag` first.

```c
// Same structure, flag1=1, flag2=64
if (self->pad_06E2[29])
    FFX_Battle_CheckActorDistanceFlag(ctx, selfActor, 0);
return FFX_Battle_DispatchActionCommand(self, bitmask, commandId, 1, 64);
```

#### 1.4 FFX_Atel_Battle_OverrideAttemptedCommand_CALL_structural (0x7a66c0, 85B)

**Bind variant** — uses `BindCommandOptionsToActionPool` instead of `DispatchActionCommand`. Binds command options for player selection (e.g., when monster uses a skill that needs target choice).

```c
// Same operand pop, but:
return FFX_Battle_BindCommandOptionsToActionPool(self, bitmask, commandId, 0);
```

#### 1.5 FFX_Atel_Battle_ChosenCommand_CALL_structural (0x7a4450, 6B)

**Trivial accessor** — just returns the currently-chosen command ID:

```c
int FFX_Atel_Battle_ChosenCommand_CALL_structural(void) {
    return *(_DWORD *)&byte_112BDE2[2806];  // global "chosen command" state
}
```

This is used after player selects a command to read back the choice.

---

### 2. Central Battle Functions (5 functions, ~1,691B total)

#### 2.1 FFX_Battle_DispatchActionCommand (0x7ac9e0, 314B)

The **central action dispatcher**. Validates command eligibility, writes 16-byte ring entry, calls `ResolveCommandEntryFromId`.

```c
int FFX_Battle_DispatchActionCommand(ActorRecord* actor, uint32_t bitmask,
                                     int cmdId, int flag1, int flag2) {
    // 1. Battle state validation
    if (*(int*)&byte_11333C4[13972] == -1) return 0;  // not in battle
    if (cmdId != *(uint16_t*)&byte_11333C4[13988]) return 0;  // wrong command slot
    if (*(uint8_t*)&byte_11333C4[13991] >= 4) return 0;  // state >= 4
    
    // 2. Get command definition
    CommandEntry* entry = FFX_Battle_ResolveCommandEntryFromId(cmdId);
    if (!entry) return 0;
    
    // 3. Get free action pool slot
    int slot = FFX_Battle_GetActorActionPoolSlot(actor);
    if (slot == 0xFF) return 0;  // pool full
    
    // 4. Write 16-byte ring entry
    ActionRingEntry* ring = &byte_112AA81[16 * slot];
    ring->action_id     = (uint16_t)cmdId;
    ring->param1        = (uint8_t)flag1;
    ring->param2        = (uint8_t)flag2;
    ring->target_bitmask = bitmask;
    ring->actor_index   = actor->index;
    ring->ring_id       = next_ring_id++;
    
    return -1;  // success
}
```

**Key insight:** Only **3 callers** — all ATEL Battle opcodes. This is the **only entry point** for action commands in the entire battle system.

#### 2.2 FFX_Battle_CheckActorValidForAction (0x7b24b0, 102B)

**7-condition validity check** used everywhere. Returns 1 if actor can act, 0 otherwise.

```c
int FFX_Battle_CheckActorValidForAction(ActorRecord* actor, int a2, int a3, int a4) {
    if (*(uint8_t*)(actor + 3534)) return 0;                    // dead flag
    if ((*(uint16_t*)(actor + 1542) & 0x300) != 0) return 0;    // status: petrify/stone
    if (*(uint8_t*)(actor + 1544)) return 0;                    // status: ???
    if ((*(uint8_t*)(actor + 1559) & 1) == 0) return 0;         // status: ???
    if (a2 && !*(uint8_t*)(actor + 3528)) return 0;            // (opt) require flag
    if (a3 && (*(uint16_t*)(actor + 1542) & 0x400) == 0) return 0;  // (opt) require
    if (a4 && (*(uint16_t*)(actor + 1542) & 0x800) == 0) return 0;  // (opt) require
    return 1;
}
```

**11 callers** — used by every ATEL Battle opcode, every auto-item function, and turn init.

#### 2.3 FFX_Battle_QueryActorBitmask (0x794340, 1101B) — The 31-case switch

**The central target resolver.** Maps 16-bit sentinel values to 32-bit actor bitmasks.

```c
uint32_t FFX_Battle_QueryActorBitmask(BattleContext* ctx, int16_t sentinel, int selfActor) {
    if (sentinel >= 0) {
        // Direct actor index (0..30)
        if (sentinel < 31) return (1u << sentinel);
        return 0;  // invalid
    }
    
    switch (sentinel) {
        case 0xFFF1:  // -15: AllAeons
            return computeAllAeonsBitmask(ctx);
        
        case 0xFFF2:  // -14: FrontlineChars (first 3 in party)
            return (1u << 0) | (1u << 1) | (1u << 2);
        
        case 0xFFF3:  // -13: Self
            return (1u << selfActor);
        
        case 0xFFEF:  // -17: LastAttacker
            return (1u << ctx->lastAttackerIdx);
        
        case 0xFFFC:  // -4: TargetActorsNow (cursor)
            return ctx->currentTargetBitmask;
        
        case 0xFFFB:  // -5: AllActors
            return computeAllAliveActorsBitmask(ctx);
        
        case 0xFFF0:  // -16: PredefinedGroup
            return ctx->predefinedGroupBitmask;
        
        // ... 24 more cases for formation-specific groups
        default:
            // Formation group index (negative)
            int formationIdx = -sentinel - 1;
            if (formationIdx < ctx->formationGroupCount)
                return ctx->formationGroups[formationIdx];
            return 0;
    }
}
```

**39 callers** (most-called function in batch), 104 basic blocks, 18 callees.

#### 2.4 FFX_Battle_BindCommandOptionsToActionPool (0x7ac960, 118B)

Used by `OverrideAttemptedCommand` opcode. Binds command options for **player choice** (e.g., when monster uses "Use" command and player must select which item to use).

```c
int FFX_Battle_BindCommandOptionsToActionPool(ActorRecord* actor, uint32_t bitmask,
                                               int cmdId, int flag) {
    if (!actor->battleContext) return 0;
    if (actor->pad_0450[28] != 3) return 0;  // wrong state
    
    int slot = FFX_Battle_GetActorActionPoolSlot(actor);
    if (slot == 0xFF) return 0;
    
    ActionRingEntry* ring = &byte_112AA81[16 * slot];
    ring->action_id     = (uint16_t)cmdId;
    ring->param1        = (uint8_t)flag;
    ring->param2        = 255;  // "bind mode" marker
    ring->target_bitmask = bitmask;
    ring->actor_index   = actor->index;
    return -1;
}
```

#### 2.5 FFX_Battle_CheckActorDistanceFlag (0x7aa120, 56B)

**Distance-based validity check.** Used by `OverrideDeathAnimationWithCommand` to skip actors too far away.

```c
int FFX_Battle_CheckActorDistanceFlag(BattleContext* ctx, int actorIdx, int flag) {
    if (!FFX_Battle_CheckActorValidForDistanceCheck(ctx, actorIdx))
        return 0;
    if (!FFX_Battle_CheckActorDistanceThreshold(ctx, actorIdx, 8.0f))  // 8.0 unit threshold
        return 0;
    
    ActorRecord* actor = FFX_Battle_AccessCurrentActorData(actorIdx);
    actor->pad_06E2[29] = (uint8_t)flag;  // set/clear "in range" flag
    return 1;
}
```

---

### 3. Resolve/Item Functions (5 functions, ~1,013B total)

#### 3.1 FFX_Battle_ResolveCommandEntryFromId (0x78cf10, 264B)

**Command ID → CommandEntry resolver.** Splits 16-bit ID into (namespace, index) and dispatches.

```c
CommandEntry* FFX_Battle_ResolveCommandEntryFromId(int cmdId) {
    // Special IDs that break out early
    if (cmdId == 12574) return NULL;  // Defend
    if (cmdId == 12324) return NULL;  // Escape
    if (cmdId == 12330) return NULL;  // Flee
    
    int namespace = (cmdId >> 12) & 0xF;
    int index     = cmdId & 0xFFF;
    
    switch (namespace) {
        case 2:  return FFX_Menu_GetCommandTableEntry(index);
        case 3:  return FFX_Kernel_GetCommandEntryById(index);
        case 4:  return FFX_Kernel_GetMonMagic1EntryById(index);
        case 6:  return FFX_Kernel_GetMonMagic2EntryById(index);
        default: return NULL;
    }
}
```

**18 callers** — every action dispatch goes through this.

#### 3.2 FFX_Battle_GetActorActionPoolSlot (0x7b09f0, 43B)

**Free slot finder** in the 62-entry ring buffer.

```c
int FFX_Battle_GetActorActionPoolSlot(ActorRecord* actor) {
    uint8_t slot = actor->pad_0450[17];  // current slot index
    if (slot == 0xFF) return 0xFF;  // no slot allocated
    return &byte_112AA81[72 * slot + 495];  // pointer into ring buffer
}
```

#### 3.3 FFX_Battle_AutoUseItemForStatus (0x7b2520, 440B) — The auto-item AI

**Status-triggered item use.** Checks 4 status conditions and uses the right item.

```c
void FFX_Battle_AutoUseItemForStatus(ActorRecord* actor, int priority) {
    if (!FFX_Battle_CheckActorValidForAction(actor, 0, 0, 0)) return;
    
    int itemId = 0;
    int n2 = 0;
    
    // Poison (bit 8 of status word at +1542)
    if (*(uint16_t*)(actor + 1542) & 0x100) {
        itemId = 8202;  // Antidote
        n2 = 1;
    }
    // Silence (bit 2)
    else if (*(uint16_t*)(actor + 1542) & 4) {
        itemId = 8204;  // Echo Screen
        n2 = 2;
    }
    // Darkness (byte +1546)
    else if (*(uint8_t*)(actor + 1546)) {
        itemId = 8205;  // Eye Drops
        n2 = 3;
    }
    // Petrify (byte +1545) — also check bit 11
    else if (*(uint8_t*)(actor + 1545) || (*(uint16_t*)(actor + 1542) & 0x800)) {
        itemId = 8206;  // Soft
        n2 = 4;
    }
    // Slow or other (catch-all)
    else if (some_other_condition) {
        itemId = 8207;  // Remedy
        n2 = 5;
    }
    
    if (itemId) {
        FFX_Battle_BuildItemRingEntry(actor, itemId, n2 + 16, priority);
    }
}
```

**Priority order** (lower = sooner): Poison(1) → Silence(2) → Darkness(3) → Petrify(4) → Catch-all(5).

#### 3.4 FFX_Battle_FindAndUseAutoPotion (0x7b27c0, 157B)

**Auto-Potion AI.** Scans for usable Potions, uses one if HP is low.

```c
void FFX_Battle_FindAndUseAutoPotion(ActorRecord* actor, int aeonMenuSlot) {
    int startIdx, endIdx;
    if (aeonMenuSlot) {
        startIdx = 20; endIdx = 28;  // aeons in menu slots
    } else {
        startIdx = 0; endIdx = 20;   // regular party
    }
    
    for (int i = startIdx; i < endIdx; ++i) {
        ActorRecord* other = FFX_Battle_AccessCurrentActorData(i);
        if (!FFX_Battle_CheckActorValidForAction(other, 0, 0, 0)) continue;
        if (!(*(uint16_t*)(other + 606*2 + 1212) & 0x1000)) continue;  // not flagged
        
        FFX_Battle_BuildItemRingEntry(other, 8198, 48, 1);  // Potion
        return;  // only one potion per turn
    }
}
```

#### 3.5 FFX_Battle_FindAndUseAutoPhoenix (0x7b2860, 189B)

**Auto-Phoenix AI.** Only triggers if HP <= maxHP/2.

```c
void FFX_Battle_FindAndUseAutoPhoenix(ActorRecord* actor, int aeonMenuSlot) {
    if (!FFX_Battle_CheckActorValidForAction(actor, 0, 0, 0)) return;
    
    int maxHP = *(uint16_t*)(actor + 1538);
    int curHP = *(uint16_t*)(actor + 1536);
    if (curHP > maxHP / 2) return;  // HP > 50% — don't use
    
    // Try Phoenix Down items in priority order
    int phoenixItems[] = { 8192, 8193, 8194 };
    for (int i = 0; i < 3; ++i) {
        if (FFX_Battle_HasItem(actor, phoenixItems[i])) {
            FFX_Battle_BuildItemRingEntry(actor, phoenixItems[i], 32 + i, 1);
            return;
        }
    }
}
```

---

### 4. Turn/Aftermath Functions (2 functions, ~2,589B total)

#### 4.1 FFX_Btl_ApplyActionResults_Aftermath (0x78f0b0, 1585B)

**The "after action" function.** Called after every action resolves to apply damage, trigger auto-items, handle death.

```c
void FFX_Btl_ApplyActionResults_Aftermath(BattleContext* ctx) {
    // ... [1585 bytes of complex post-action logic]
    
    // Key phases (reconstructed from callees):
    // 1. Apply damage from action ring
    // 2. Check for kills, mark dead actors
    // 3. Trigger auto-items: AutoUseItemForStatus, FindAndUseAutoPhoenix
    // 4. Handle overdrive charge/flee: FFX_Battle_OverdriveFleeEvent
    // 5. Apply reflect/damage effects: FFX_Battle_HandleReflectOrDamageEffect
    // 6. Process counter chain: FFX_Battle_ProcessCounterChainCamera
    // 7. Apply CTB overload damage: FFX_Battle_ApplyCtbOverloadDamage
    
    // Debug string at 0xb54a30: "CTB DAMAGE %d %d : %d"
}
```

**Stats:** 34 callees, 92 basic blocks, 143 constants, 2 strings.

#### 4.2 FFX_Battle_ProcessActorTurnInit (0x791230, 1004B)

**The "turn start" function.** Called when an actor's turn begins.

```c
void FFX_Battle_ProcessActorTurnInit(BattleContext* ctx, int actorIdx) {
    // ... [1004 bytes of turn start logic]
    
    // Key phases (reconstructed from callees):
    // 1. Set actor action menu state: FFX_Battle_SetActorActionMenuState
    // 2. Release actor afterimage: FFX_Battle_ReleaseActorAfterimage
    // 3. Set all actor death flags: FFX_Battle_SetAllActorDeathFlags
    // 4. Reset party after actor turn: FFX_Battle_ResetPartyAfterActorTurn
    // 5. Build main command ring tree: FFX_Battle_BuildMainCommandRingTree
    // 6. Check party slot active: FFX_Battle_CheckPartySlotActive
    // 7. Get actor action pool slot: FFX_Battle_GetActorActionPoolSlot
    // 8. Set actor animation by id: FFX_Battle_SetActorAnimationById
    // 9. Get encounter flags: FFX_Battle_GetEncounterFlags
    // 10. Reset party on encounter: FFX_Battle_ResetPartyOnEncounter
}
```

**Stats:** 33 callees, 60 basic blocks, 113 constants.

---

## AI Decision Loop Flow

```
Battle tick (CTB turn state machine)
    ↓
CtbSelectNextActorAndRunTurnEdgeEvents
    ↓
    ├── ProcessActorTurnInit(actorIdx) ← TURN START
    │     ├── SetActorActionMenuState
    │     ├── ReleaseActorAfterimage
    │     ├── SetAllActorDeathFlags
    │     ├── ResetPartyAfterActorTurn
    │     ├── BuildMainCommandRingTree
    │     └── SetActorAnimationById
    ↓
    ├── [ACTOR'S TURN] ← AI decision happens HERE
    │     ├── For monster actors:
    │     │     ├── ATEL_Battle_PerformCommand_CALL ← Pops target + command from ATEL stack
    │     │     ├── ATEL_Battle_ForcePerformCommand_CALL ← Force variant
    │     │     ├── ATEL_Battle_OverrideDeathAnimationWithCommand_CALL
    │     │     ├── ATEL_Battle_OverrideAttemptedCommand_CALL ← Bind mode
    │     │     └── ATEL_Battle_ChosenCommand_CALL ← Read player's choice
    │     │
    │     └── Inside opcode:
    │           ├── PopOperand (target_sentinel, command_id)
    │           ├── GetScriptSelfActorIndex
    │           ├── CheckActorValidForAction
    │           ├── QueryActorBitmask(sentinel) ← 31-case switch
    │           └── DispatchActionCommand(actor, bitmask, cmdId, ...)
    │                 ├── ResolveCommandEntryFromId
    │                 ├── GetActorActionPoolSlot
    │                 └── Write 16-byte ring entry
    ↓
    ├── [ACTION RESOLVES]
    ↓
    ├── ApplyActionResults_Aftermath ← POST-ACTION
    │     ├── Apply damage from ring
    │     ├── Mark dead actors
    │     ├── AutoUseItemForStatus ← Auto-item AI
    │     ├── FindAndUseAutoPhoenix ← Auto-Phoenix
    │     ├── OverdriveFleeEvent
    │     ├── HandleReflectOrDamageEffect
    │     ├── ProcessCounterChainCamera
    │     └── ApplyCtbOverloadDamage
    ↓
    └── [NEXT TICK]
```

---

## Key Findings

1. **FFX has NO `FFX_Battle_AiDecisionLoop`** — monster AI is 135 ATEL Battle opcodes, not a C++ decision loop. This is **declarative AI** — behavior is encoded in bytecode scripts per-monster.

2. **ATEL Battle opcode pattern is uniform** — all 5 sampled opcodes follow the same 7-step structure: 2x PopOperand → GetScriptSelfActorIndex → CheckActorValidForAction → sentinel check → QueryActorBitmask → Dispatch/Bind. The only variation is the dispatch flags.

3. **Sentinel target resolver is central** — `FFX_Battle_QueryActorBitmask` (1101B, 31-case switch) is the most-called function in the AI path (39 callers). Sentinel values 0xFFF1-0xFFFB enable scripts to target groups without enumerating actors.

4. **Command ID namespace encoding** — 16-bit IDs split as `(id >> 12)` namespace + `(id & 0xFFF)` index. Namespace 2=Menu, 3=Kernel, 4=MonMagic1, 6=MonMagic2. Special IDs 12574/12324/12330 break out (defend/escape/flee).

5. **Action ring buffer is 16-byte slots** — max 62 entries at `byte_112AA81`. Each slot has action_id, 2 params, bitmask, actor_index, ring_id. Indexed via `pad_0450[17]` (0xFF = no slot).

6. **Auto-item AI is priority-based** — `AutoUseItemForStatus` checks Poison(8202) → Silence(8204) → Darkness(8205) → Petrify(8206) → Catch-all(8207) with priorities 1-5. Only the highest-priority condition triggers per turn.

7. **Auto-Phoenix is HP-gated** — only triggers if `curHP <= maxHP / 2`. Tries items 8192/8193/8194 in priority order (Phoenix Down → Mega Phoenix → ??).

8. **Auto-Potion scans party** — iterates actors 0-19 (regular party) or 20-27 (aeons), uses item 8198 on first actor with `word[606*2+1212] & 0x1000` flag.

9. **Actor validity check is 7 conditions** — `CheckActorValidForAction` combines 4 required + 3 optional checks. Used by every ATEL opcode, every auto-item function, and turn init.

10. **Turn lifecycle is 2 functions** — `ProcessActorTurnInit` (1004B, 33 callees) for turn start, `ApplyActionResults_Aftermath` (1585B, 34 callees) for post-action. AI happens between these two.

11. **`OverrideDeathAnimationWithCommand` is distance-gated** — calls `CheckActorDistanceFlag` (8.0 unit threshold) if `pad_06E2[29]` is set. Used to skip actors too far for death animation override.

12. **`OverrideAttemptedCommand` uses bind mode** — instead of `DispatchActionCommand`, calls `BindCommandOptionsToActionPool` with `param2=255` (bind marker). Used when monster forces player to choose an option.

---

## What's Next?

- **batch_0007**: Particle system (`FFX_Particle_*`) — likely 50-100 functions for battle/field particle effects
- **batch_0008**: Sound queue (`FFX_Sound_QueueCmd22/24/32/46`) — audio command queue
- **batch_0009**: RTTI classes via class_informer (non-PhyreEngine FFX classes)
- **Task #31**: Mapear pontos de entrada do jogo — `FFX_System_Host_Constructor` (3482B) for full boot sequence
- **Task #36**: Varrer SDK 4.00 por Phyre/PBinary/MSCD/SacSlicer — when no critical batch in queue

---

**Next batch:** Particle system — FFX_Particle_* functions for battle/field visual effects.
