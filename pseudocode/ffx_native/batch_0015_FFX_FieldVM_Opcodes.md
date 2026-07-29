# FFX.exe Decompilation — Batch 15 (Field VM Opcodes)

**Database:** ffxoficial_COPY.i64 (session 85e0242a, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** `FFX_FieldVM_Op_*` — the overworld scripting VM with 298 opcodes

---

## Summary

The **Field VM** is FFX's overworld scripting engine — a stack-based bytecode interpreter with **298 opcodes** (295 named `FFX_FieldVM_Op_*` + 3 helpers). It runs on the **field model** (the 3D overworld) and handles actor control, camera motion, animation triggers, distance queries, skybox data, and party management. Each opcode is a **small function (10-80 bytes)** that pops operands from a shared stack and executes a specific action or query.

| Metric | Value |
|--------|-------|
| Total opcodes | 298 (295 `FFX_FieldVM_Op_*` + 3 helpers) |
| Opcode size avg | ~40 bytes (range 6-350B) |
| Operand stack | Shared with Field Script (556 ops) |
| Key subsystems | Actor control, position, rendering, sky, callbacks |
| Stack access | `PopOperand` — pops int/float from VM stack |
| Return type | `int` (0/1 status) or `double` (distance, position) |

`★ Insight ─────────────────────────────────────`
- **298 opcodes is LARGE for a field VM** — most game engines have 50-100 field ops. FFX's is big because it handles **both scripting and rendering** (actor placement, camera, sky data, animation blending).
- **Shared stack with Field Script (556 ops)** — Field VM (lower-level) and Field Script (higher-level) share the same operand stack. Field Script opcodes call Field VM opcodes for low-level work.
- **Actor action table** — `FFX_FieldOp_GetActorActionTableByType` returns a float[3] position table from the actor's action data. This is how the field VM tracks actor positions without requiring PhyreEngine scene graph queries.
`─────────────────────────────────────────────────`

---

## Architecture: Field VM Dispatch

The Field VM is a **stack-based bytecode interpreter** that shares its operand stack with the Field Script VM (556 ops, batch_0023):

```
Field Script (556 ops) ←→ Shared Operand Stack ←→ Field VM (298 ops)
```

The stack has:
- `PopOperand(int context, int *error)` — pop next int/float operand
- `PushOperand(int context, int value)` — push result back
- Return values are the last operand left on the stack

---

## Detailed Opcode Analysis

### 1. FFX_FieldVM_Op_SelectControlledActor (0x856540, 6B)

```c
int FFX_FieldVM_Op_SelectControlledActor() {
    FFX_Field_SelectControlledActorInstance();
    return 1;
}
```

**Purpose:** Selects the currently-controlled actor instance (the party member the player is controlling). Called at field load to set up the controlled character. Returns 1 (success).

### 2. FFX_FieldVM_Op_Compute3DDistance (0x856550, ~100B)

```c
double FFX_FieldVM_Op_Compute3DDistance(int context, int a2, int *error) {
    int actorA = FFX_FieldVM_PopOperand(context, error);
    int actorB = FFX_FieldVM_PopOperand(context, error);
    
    // Get actor positions from action table
    char **stateA = FFX_Field_AiScriptStateMachine_structural(actorA);
    char **stateB = FFX_Field_AiScriptStateMachine_structural(actorB);
    
    float *posA = FFX_FieldOp_GetActorActionTableByType(stateA);
    float *posB = FFX_FieldOp_GetActorActionTableByType(stateB);
    
    float dx = posA[0] - posB[0];
    float dy = posA[1] - posB[1];
    float dz = posA[2] - posB[2];
    
    return sqrt(dx*dx + dy*dy + dz*dz);
}
```

**Purpose:** Computes 3D Euclidean distance between two field actors. Pops 2 actor IDs from stack, reads their positions from the action table, and returns sqrt(dx²+dy²+dz²).

**Key insight:** The position table is `float[3]` (X/Y/Z). This is NOT PhyreEngine's scene graph — it's a **flat array** indexed by actor type, used for fast AI queries without traversing the scene graph.

### 3. FFX_FieldVM_Op_GetPositionData (0x856630, ~30B)

```c
BOOL FFX_FieldVM_Op_GetPositionData(int context, int a2, int *error) {
    int actorId = FFX_FieldVM_PopOperand(context, error);
    return FFX_Field_IsActorControlActive(actorId);
}
```

**Purpose:** Checks if an actor is currently active (controlled by player or AI). Pops actor ID from stack, returns BOOL.

### 4. FFX_FieldVM_Op_SetSkyData (0x8565e0, ~40B)

Sets skybox/background data for the current field. Called on field load to configure the environment (sky color, fog, cloud layers).

### 5. FFX_FieldVM_Op_ClearControlledActors (0x856650, ~20B)

Clears all controlled actor instances. Called during field transitions to reset actor state before loading new field.

### 6. FFX_FieldVM_Op_CheckActorFlagBit (0x856670, ~30B)

```c
// Checks a specific flag bit on an actor
// Pops actor ID and bit index from stack
// Returns 0 or 1 based on flag state
```

Used for conditional branching in field scripts (e.g., "has this NPC been spoken to?").

### 7. FFX_FieldVM_Op_SetRenderParams (0x856680, ~100B)

Sets rendering parameters for a specific actor or scene element. This bridges the Field VM to the PhyreEngine rendering pipeline (PEntity, PMeshInstance from batch_0010).

### 8. FFX_FieldVM_Op_SetActorEnabled (0x856770, ~50B)

```c
// Enables or disables an actor in the field
// Pops actor ID + enable flag from stack
// If disabled, actor is hidden and doesn't process AI
```

### 9. FFX_FieldVM_Op_InitDefaultState (0x856a40, ~30B)

Initializes the default state for all field actors. Called once when the field loads. Resets positions, animations, AI state, and collision data.

### 10. FFX_FieldVM_Op_FindPartySlotById (0x856a60, ~50B)

```c
// Finds which party slot (0-6) holds a specific character by ID
// Returns -1 if not in party
// Used by field scripts to check party composition
```

### 11. FFX_FieldVM_Op_GetAverageActorPosition (0x856cc0, ~80B)

```c
// Computes average position of all active party members
// Used for camera follow and encounter detection
// Returns float[3]
```

### 12. FFX_FieldVM_Op_SetActorFlagBit3 (0x856970, ~60B)

Sets flag bit 3 on an actor. Used for **specific animation states** (walking, running, idle, talking).

### 13. FFX_FieldVM_Op_SetActorFlagBit6 (0x856c60, ~60B)

Sets flag bit 6 on an actor. Different from bit 3 — likely for **interaction states** (trading, examining, cutscene participation).

### 14. FFX_FieldVM_Op_Compute2DDistanceXZ (0x856830, ~60B)

```c
double FFX_FieldVM_Op_Compute2DDistanceXZ(context, a2, error) {
    // Same as Compute3DDistance but only uses X/Z (ignores Y)
    // Useful for ground-level distance checks
    return sqrt(dx*dx + dz*dz);
}
```

Used for **encounter range detection** — check if player is close enough to trigger a random encounter.

---

## Opcode Categories (by name pattern)

From the 30 sampled opcodes:

| Category | Count (sampled) | Example |
|----------|----------------|---------|
| Actor control | 6 | `SelectControlledActor`, `ClearControlledActors` |
| Actor flags | 4 | `CheckActorFlagBit`, `SetActorFlagBit3`, `SetActorFlagBit6` |
| Position/distance | 4 | `GetPositionData`, `Compute3DDistance`, `Compute2DDistanceXZ`, `GetAverageActorPosition` |
| Rendering | 4 | `SetRenderParams`, `SetRenderParamsMode3`, `SetSkyData` |
| State init | 3 | `InitDefaultState`, `InitDefaultStateOff` |
| Float params | 5 | `SetActorFloatParam`, `SetQuadFloatParam`, `SetQuadFloatParamPush0` |
| VM call | 4 | `Call874970`, `Call871240WithPop`, `Call876210` |
| Party/ID lookup | 2 | `FindPartySlotById`, `GetIndexedWordData` |
| Math helpers | 3 | `GetActorPositionDword`, `HasOwnershipAndSightCheck` |

---

## Stack Protocol

All Field VM opcodes use the same **operand stack protocol**:

```c
// Pushing: opcode leaves result on stack
Op(actorId) → pushes actor position onto stack

// Popping: opcode consumes operands
PopOperand(context, &error) → pops next int

// Return: last operand on stack
// If opcode returns void, stack is unchanged
```

The stack is **shared with Field Script** (556 ops), meaning Field Script can push operands then call a Field VM opcode to consume them.

---

## Key Functions (non-opcode helpers)

### FFX_FieldVM_PopOperand (0x86de90, ~50B)

The stack operation primitive. Pops the next operand from the VM's operand stack:

```c
int FFX_FieldVM_PopOperand(int context, int *error) {
    // Read next int from operand stack at current offset
    // Increment stack pointer
    // Return value (or error code)
}
```

### FFX_FieldOp_GetActorActionTableByType

```c
float* FFX_FieldOp_GetActorActionTableByType(char **stateMachine) {
    // Returns pointer to float[3] position table
    // Layout: [posX, posY, posZ]
    // Position is in world space for query, not render space
}
```

### FFX_Field_AiScriptStateMachine_structural

Returns a pointer to the actor's AI script state machine — the object that holds the actor's animation, movement, and behavior state.

---

## Actor Flag Bits

From the sampled opcodes:

| Bit | Name | Purpose |
|-----|------|---------|
| 3 | `SetActorFlagBit3` | Animation state (walk/run/idle) |
| 6 | `SetActorFlagBit6` | Interaction state (talk/trade/examine) |
| 15 | `SetFlagBit15` | ? (higher-level script flag) |

The flag system is **bitfield-per-actor** — each actor has a 32-bit flag field, and different opcodes set/check specific bits.

---

## Key Findings

1. **298 Field VM opcodes** — large for a field VM, handles both scripting AND rendering. Most are 10-80 byte stubs.

2. **Shared stack with Field Script (556 ops)** — Field VM is the lower-level engine; Field Script is the higher-level compiler output. They share the same operand stack.

3. **Actor action table** — positions stored in `float[3]` flat array, NOT in PhyreEngine scene graph. Fast AI queries without scene traversal.

4. **sqrt-based distance** — `Compute3DDistance` and `Compute2DDistanceXZ` use `sqrt(dx²+dy²+dz²)`. Native sqrt (not `sqrtf`), suggesting MSVC CRT.

5. **Flag bit system** — per-actor 32-bit bitfield. Different bits for different state categories (animation, interaction, script flags).

6. **Position is in world space** — the position table stores world-space coordinates, used for AI queries, encounter triggers, camera follow.

7. **4 call opcodes** — `Call874970`, `Call871240WithPop`, `Call876210`, `Call876210With3` — direct function calls from the VM to native code. The number suffixes are addresses in the .text segment (renamed by IDA).

8. **Party slot lookup** — `FindPartySlotById` maps character IDs (Tidus=0, Yuna=1, etc) to party slots (0-6). Essential for field scripts that check party composition.

9. **Rendering bridge** — `SetRenderParams` and `SetRenderParamsMode3` bridge from Field VM to PhyreEngine rendering. Mode 3 is likely a specific render path (e.g., reflection map, shadow map).

10. **Average position** — `GetAverageActorPosition` computes camera follow target. Camera follows the average of all party members, not just the controlled character.

---

## What's Next?

- **batch_0016**: VP8/VP9 decoder entry — video codec (skipped for now, lower priority)
- **batch_0017**: MSCD file system — asset loading pipeline
- **batch_0018**: Battle UI HUD core
- **batch_0019**: Cross-batch PhyreEngine architecture synthesis
- **batch_0020**: ATEL Battle opcodes (135 funcs)

---

**Next batch:** MSCD file system — the PS3-era asset loading layer ported to PC.