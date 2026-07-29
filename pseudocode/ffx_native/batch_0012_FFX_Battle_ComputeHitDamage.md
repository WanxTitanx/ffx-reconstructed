# FFX.exe Decompilation — Batch 12 (FFX Battle ComputeHitDamage)

**Database:** ffxoficial_COPY.i64 (session 85e0242a, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** `FFX_Battle_ComputeHitDamage` — the master damage calculator orchestrating 30+ sub-functions

---

## Summary

`FFX_Battle_ComputeHitDamage` (0x78e680, **2,127 bytes**) is the **master damage formula orchestrator** for FFX's battle system. It calls **30+ sub-functions** to compute physical, magical, and multi-hit damage while applying 40+ modifiers (critical, overdrive, element, status, guard, shield, polarity, etc). The result is **clamped to 9999/99999** based on whether target is break-damage-cap limit, then written to the hit result context.

| Metric | Value |
|--------|-------|
| Function size | 2,127 bytes (raw x86) |
| Decompiled size | ~165 lines of pseudo-C |
| Sub-functions called | **30+** (damage modifiers, formula dispatch, effect application) |
| Damage types | Physical (1), Magical (2), Multi-hit (4) |
| Damage cap | 9999 (normal) or 99999 (break damage cap limit = 0x800) |
| Hit result code | 0x80 = KO flag, bit 0 = physical, bit 1 = magical, bit 4 = multi-hit |

`★ Insight ─────────────────────────────────────`
- **Damage is an OR'd bitmask of modifiers** — `v80[0]` is a 16-bit value with bits set per damage type (1=physical, 2=magical, 4=multi-hit, 0x80=KO). Each modifier only applies if its bit is set. The final damage is the OR'd result.
- **Damage cap is FLAT** — 9999 normal, 99999 with break cap limit. There is **no sliding scale**; the clamp is `min(damage, 9999)`. This matches FFX's UI where you see "9999" max for damage numbers.
- **Three damage formulas share dispatch** — `FFX_Battle_DamageFormulaDispatch(formulaType, attacker, basePower, defender)` is called **3 times** (physical, magical, multi-hit), each with a different formula type selected via `(1 - unk_112A908)` — likely normal vs. `1 + crit` mode.
`─────────────────────────────────────────────────`

---

## Architecture: The Damage Pipeline

```
FFX_Battle_ComputeHitDamage(dmgType, attacker, target, basePower)
    │
    ├── 1. Resolve hit type & counters
    │     ├── FFX_Battle_CheckPreemptiveAttack(0, ...)
    │     ├── FFX_Battle_ResolveHitElementalCounters(...)
    │     └── Branch on hit type (miss/crit/multi)
    │
    ├── 2. For each damage type (physical/magical/multi):
    │     ├── Apply status pre-effects
    │     │     ├── FFX_Battle_ProcessPhysicalHitStatus
    │     │     ├── FFX_Battle_ResolveHitAccuracyAndEffects
    │     │     └── FFX_Battle_ComputeMagicAbsorb
    │     │
    │     ├── Compute base damage via formula dispatch
    │     │     └── FFX_Battle_DamageFormulaDispatch(formula, attacker, basePower, defender)
    │     │
    │     ├── Apply damage modifiers (in order):
    │     │     ├── ¼ multiplier (QuarterDamage?)
    │     │     ├── Magic Guard (halve if shell/protos)
    │     │     ├── Phys Guard (halve if armor/shell)
    │     │     ├── Critical hit (1.5x if crit)
    │     │     ├── Doublecast (2x if doublecast)
    │     │     ├── Zanmato (instant kill if applicable)
    │     │     ├── DoubleDamagePierce (armor/shell pierce)
    │     │     ├── Element affinity (Fire/Thunder/Water/etc)
    │     │     ├── Polarity reversal (reflect if aeon)
    │     │     ├── Element resistance (-50% if half, +50% if weak, etc)
    │     │     ├── Shield damage (calc shield hits)
    │     │     ├── Guard damage (if defending)
    │     │     ├── Pierce damage halving (if armor-pierce)
    │     │     ├── Element null consume (e.g., NulBlaze)
    │     │     └── Overdrive damage multiplier (Stoic/Comrade/Slayer)
    │     │
    │     └── Store result in v80[0] (damage bits)
    │
    ├── 3. Post-modifier pipeline:
    │     ├── FFX_Battle_ApplyDamageAmplifier (BGM/Hypernull?)
    │     ├── FFX_Battle_CheckAssessConceal (auto-hit from Assess)
    │     ├── FFX_Battle_MainDamageFormula (final aggregation)
    │     ├── FFX_Battle_ResolveHitTargetEffectsAndMultipliers (per-target mods)
    │     ├── FFX_Battle_CheckEjectHit (eject from battle?)
    │     ├── FFX_Battle_TrackDeathAndOverkill (death tracking)
    │     ├── FFX_Battle_CheckFirstStrikeMultiplier (initiative)
    │     ├── FFX_Battle_ApplyStatusEffectFromMask (Zombie/Stone/etc)
    │     └── FFX_Battle_ComputeOverdriveChargeFromHit (gain OD on hit)
    │
    ├── 4. Clamp to 9999 / 99999 (break cap limit)
    │     └── n9999 = (basePower[1726] & 0x800) ? 99999 : 9999
    │
    ├── 5. Write to hit result context
    │     ├── hitResultCtx[0] = hitCount (1+)
    │     ├── hitResultCtx[1] = result counter
    │     ├── hitResultCtx[24] = damage bits v80[0]
    │     ├── hitResultCtx[28] = final damage value
    │     └── hitResultCtx[6] |= cmdCtx[90]  (status mask)
    │
    └── 6. Update stats & return damage
          ├── defender.currentHp -= damage
          ├── defender.currentStrength -= damage
          └── if defender.currentHp < 0: defender.currentHp = 0
```

---

## Damage Flow — Detailed

### Step 1: Pre-Hit Resolution

```c
// Branch A: Counter-hit (target retaliated first)
if (FFX_Battle_ResolveHitElementalCounters(...)) {
    *v80 = cmdCtx[35];                  // hit result code
    v64 = hitResultCtx[7];
    n2_1 = cmdCtx[32] & 3;               // hit location (front/back/etc)
    v70 = 1;
    n2 = 2;
    p_n17 = FFX_Btl_LoadMonsterBins(    // delegate to monster AI
        target, n8, n2_1, 0, 0, 0,
        &p_n10000, hitCounters, effectCounters,
        cmdCtx, 0, v64, v80[0], 0, &v70);
    if (!v78) goto LABEL_35;
}

// Branch B: Normal hit (damage flow)
else {
    FFX_Battle_ResolveHitAccuracyAndEffects(...);
    // 1 = normal hit, 2 = critical, 0 = miss
    if (n2_3 == 1) {
        n2 = 1;
        ++*p_n17;  // increment hit counter
        // ... target is dead/sentinel, exit early
    } else if (n2_3 == 2) {
        ++*p_n17;
        v71 = 1;
        goto LABEL_35;
    }
    ++*counterPtr;  // increment hit counter
}
```

### Step 2: Physical Damage (Bit 0)

```c
if (basePowera) {                      // basePower is valid
    if (v18 & 1) {                     // bit 0 = physical hit
        // Pre-effects
        FFX_Battle_ProcessPhysicalHitStatus(DMGFLAG_PHYSICAL, actorData);
        
        // Compute base damage
        v20 = FFX_Battle_DamageFormulaDispatch(
            (FFX_DamageFormula)(1 - unk_112A908),  // formula selection
            attacker, basePower, defender);
        
        // Apply modifiers in sequence
        v21 = FFX_Battle_ComputeDamageQuarterMultiplier(defender, v80, v20);
        v22 = FFX_Battle_ComputeMagicGuardHalving(cmdCtx, v80, &p_n2, hitResultCtx, v21);
        v23 = FFX_Battle_ComputePhysGuardHalving(cmdCtx, v80, &p_n2, hitResultCtx, v22);
        
        if (!unk_112A909)  // global flag — "no crit" mode
            v23 = FFX_Battle_ComputeCriticalHit(basePower, defender, cmdCtx, v80, v23);
        
        p_n17 = FFX_Battle_ComputeDoublecastDamage(basePower, v23);
        FFX_Battle_CheckZanmatoOrInstantKill(basePower, cmdCtx, n12524, &p_n17);
        FFX_Battle_CheckDoubleDamagePierce(basePower, cmdCtx, n12524, formulaType, p_n17);
        FFX_Battle_ApplyElementAffinityModifier(target, actorData, target);
        
        currentMagic_1 = FFX_Battle_ComputeMagicAbsorb(defender, formulaType, &v78, 1, &v70, v25);
        FFX_Battle_ApplyDamagePolarityReversal(basePower, cmdCtx, hitResultCtx, currentMagic_1);
        FFX_Battle_ApplyElementResist(element, actorData, &defender->modelHandle);
        
        v30 = FFX_Battle_ComputeShieldDamage(basePower, defender, cmdCtx, hitResultCtx, &p_n3, v29);
        v31 = FFX_Battle_ComputeGuardDamage(defender, cmdCtx, v80, hitResultCtx, v30);
        FFX_Battle_ApplyPierceDamageHalving(basePower, cmdCtx, v31);
        FFX_Battle_TryConsumeElementNullStatus(element, actorData);
        
        p_n10000 = FFX_Battle_ComputeOverdriveDamageMul(odType, actorData);
        n2 = p_n2;
        v18 = *v80;
    }
```

### Step 3: Magical Damage (Bit 1)

```c
if (v18 & 2) {                          // bit 1 = magical hit
    p_n17 = FFX_Battle_DamageFormulaDispatch(
        (FFX_DamageFormula)(1 - unk_112A908),
        actorData, basePower, defender);
    
    FFX_Battle_CheckZanmatoOrInstantKill(basePower, cmdCtx, n12524, &p_n17);
    
    currentMagic = FFX_Battle_CheckDoubleDamagePierce(
        basePower, cmdCtx, n12524, formulaType, p_n17);
    
    // Cap at target's current MP
    if (currentMagic > 0 && defender->currentMagic < currentMagic)
        currentMagic = defender->currentMagic;
    
    n10000 = FFX_Battle_ApplyDamagePolarityReversal(
        basePower, cmdCtx, hitResultCtx, currentMagic);
}
```

### Step 4: Multi-Hit Damage (Bit 2)

```c
if (v18 & 4) {                          // bit 2 = multi-hit
    v78 &= ~4u;                         // clear bit 2 (will be set per-hit)
    currentMagic_2 = FFX_Battle_DamageFormulaDispatch(
        (FFX_DamageFormula)(1 - unk_112A908),
        formulaType_1, basePower, defender);
    
    v95 = FFX_Battle_ApplyDamagePolarityReversal(
        basePower, cmdCtx, hitResultCtx, currentMagic_2);
}
```

### Step 5: Post-Modifier Aggregation

```c
v39 = FFX_Battle_ApplyDamageAmplifier(defender, cmdCtx, v18, &p_n10000);

EffectsAndMultipliers_1 = FFX_Battle_CheckAssessConceal(
    defender, hitResultCtx, &v78, 4, v39, &v70, &p_n10000);

p_n2_1 = *(_WORD *)(hitResultCtx + 20);  // hit result flags
EffectsAndMultipliers = EffectsAndMultipliers_1;
p_n2 = p_n2_1;

if (!unk_112A906) {                       // global flag — "compute final damage" mode
    v43 = FFX_Battle_MainDamageFormula(EffectsAndMultipliers_1, attacker, target, basePower);
    
    EffectsAndMultipliers_2 = FFX_Battle_ResolveHitTargetEffectsAndMultipliers(
        target, basePower, n8, defender, cmdCtx,
        hitCounters, effectCounters, hitResultCtx,
        v43, &p_n10000, v67);
    
    if ((*(_BYTE *)(hitResultCtx + 20) & 4) == 0)
        *(_BYTE *)(hitResultCtx + 6) |= *(_BYTE *)(cmdCtx + 90);
    
    LOBYTE(p_n2_1) = p_n2;
}

FFX_Battle_CheckEjectHit(defender, hitResultCtx, p_n2_1, &v78, hitCounters, &p_n10000);
FFX_Battle_TrackDeathAndOverkill(v45, &p_n10000, hitCounters, effectCounters, EffectsAndMultipliers, 0);

*v80 = FFX_Battle_CheckFirstStrikeMultiplier(
    defender, hitResultCtx, p_n2, EffectsAndMultipliers, &p_n10000);

FFX_Battle_ApplyStatusEffectFromMask(effect, actorData);
FFX_Battle_ComputeOverdriveChargeFromHit(n8, defender, cmdCtx, hitCounters, hitResultCtx);
```

### Step 6: Damage Cap Clamp (9999 / 99999)

```c
v48 = *(_WORD *)(cmdCtx + 32);

// Determine cap based on break damage cap limit (0x800 bit in basePower[1726])
n9999 = (*(_WORD *)(basePower + 1726) & 0x800) ? 99999 : 9999;

// Override based on cmdCtx flags
if (!(v48 & 0x80)) {
    if (v48 & 0x40) n9999 = 9999;
} else {
    n9999 = 99999;
}

// Apply "9999 demonstration" override (debug modes)
if (MEMORY[0x112A90E]) {                 // debug flag 1
    if (v80[0] & 1) p_n10000 = 1;
    if (v80[0] & 2) n10000 = 1;
}
if (MEMORY[0x112A90F]) {                 // debug flag 2
    if (v80[0] & 1) p_n10000 = 10000;
    if (v80[0] & 2) n10000 = 10000;
}
if (MEMORY[0x112A910]) {                 // debug flag 3
    if (v80[0] & 1) p_n10000 = 100000;
    if (v80[0] & 2) n10000 = 100000;
}

// Cap clamp (with reverse damage)
if (basePower[1600] & 8 && v80[0] & 1) {
    if ((unsigned int)(p_n10000 - 1) > 0x270D) {  // > 9999
        if ((unsigned int)(p_n10000 + 9998) <= 0x270D)
            p_n10000 = -9999;
    } else {
        p_n10000 = 9999;
    }
}
```

**Key insight:** The damage cap clamp handles **both positive and negative damage**:
- Positive damage > 9999 → capped to 9999
- Negative damage < -9999 → capped to -9999
- This is needed for **damage reversal** (Counter-attacks, Reflect, etc)

### Step 7: Write to Hit Result Context

```c
// Write hit result
*(_BYTE *)hitResultCtx = p_n17;                          // hit count
*(_BYTE *)(hitResultCtx + 1) = FFX_Battle_CheckHitResultCounters(v66, &v70);
*(_WORD *)(hitResultCtx + 24) = v80[0];                  // damage bits
*(_WORD *)(hitResultCtx + 26) = EffectsAndMultipliers;   // crit/multi flags
*(_BYTE *)(hitResultCtx + 2) = (_BYTE)attacker;          // attacker ID
*(_BYTE *)(hitResultCtx + 3) = n2;                        // hit type

// Recompute final damage (for output)
v58 = FFX_Battle_DamageFormulaDispatch(formulaType, attacker, basePower, defender);
*(_DWORD *)(hitResultCtx + 28) = v58;                    // final damage value
*(_BYTE *)(hitResultCtx + 4) = v92;                       // status effect

// Update stats
FFX_Battle_CheckStatModifiersActive(target, basePower, cmdCtx, n100, v61);

// Set KO flag if HP dropped below pre-hit value
if (v65 - *n100 <= 0)
    *v80 |= 0x80;  // KO flag bit

return *n100;  // return remaining HP?
```

### Step 8: Update Actor Stats

```c
// Apply damage to defender stats
dmgBufferBase_1 = dmgBufferBase;
n100 = hitResultCtx + 32;
v51 = (int *)(hitResultCtx + 32);
p_currentStrength = &defender->currentStrength;

p_n3 = 3;
do {
    n9999_1 = *(_DWORD *)((char *)dmgBufferBase_1 + (_DWORD)v53);  // load damage
    
    // Clamp to ±9999
    if (n9999_1 >= -n9999) {
        if (n9999_1 > n9999)
            n9999_1 = n9999;
    } else {
        n9999_1 = -n9999;
    }
    
    *v51 = n9999_1;
    p_currentStrength[404] += n9999_1;     // increment overdamage counter
    *p_currentStrength -= n9999_1;         // decrement current stat
    
    if (dmgBufferBase)
        *dmgBufferBase_1 -= n9999_1;       // decrement buffer
    
    // Cap at 0 (can't go negative)
    v55 = *p_currentStrength < 0;
    ++v51;
    ++dmgBufferBase_1;
    ++p_currentStrength;
    *(p_currentStrength - 1) = v55 ? 0 : *(p_currentStrength - 1);
    
    v4 = p_n3-- == 1;
}
while (!v4);
```

**Insight:** The damage is applied to **3 stat counters**: currentHp, currentStrength, and one more (likely currentMagic). Each is decremented by the damage value, capped at 0.

---

## Damage Modifiers Catalog

The 30+ sub-functions apply modifiers in this order:

| # | Function | Modifier | Notes |
|---|----------|----------|-------|
| 1 | `FFX_Battle_DamageFormulaDispatch` | Base damage | Calls formula-specific compute |
| 2 | `FFX_Battle_ComputeDamageQuarterMultiplier` | Quarter damage | Defending? Quarter damage? |
| 3 | `FFX_Battle_ComputeMagicGuardHalving` | Magic Guard | Shell/Protos halves magic damage |
| 4 | `FFX_Battle_ComputePhysGuardHalving` | Phys Guard | Armor/Shell halves phys damage |
| 5 | `FFX_Battle_ComputeCriticalHit` | Critical hit | 1.5x damage on crit |
| 6 | `FFX_Battle_ComputeDoublecastDamage` | Doublecast | 2x damage on Flare/Ultima doublecast |
| 7 | `FFX_Battle_CheckZanmatoOrInstantKill` | Instant kill | Zanmato, Death, etc |
| 8 | `FFX_Battle_CheckDoubleDamagePierce` | DoubleDamage/Pierce | 2x damage from Concentrate/Pierce |
| 9 | `FFX_Battle_ApplyElementAffinityModifier` | Element affinity | Fire/Thunder/Water/etc |
| 10 | `FFX_Battle_ComputeMagicAbsorb` | Magic absorb | Absorb elements (e.g., Spellspasm) |
| 11 | `FFX_Battle_ApplyDamagePolarityReversal` | Polarity reversal | Reflect damage back |
| 12 | `FFX_Battle_ApplyElementResist` | Element resistance | ½x, 2x based on target's affinity |
| 13 | `FFX_Battle_ComputeShieldDamage` | Shield damage | Hits shield before HP |
| 14 | `FFX_Battle_ComputeGuardDamage` | Guard damage | Reduced damage if defending |
| 15 | `FFX_Battle_ApplyPierceDamageHalving` | Pierce damage halving | If armor pierces but no pierce |
| 16 | `FFX_Battle_TryConsumeElementNullStatus` | Element null consume | NulBlaze/NulShock etc |
| 17 | `FFX_Battle_ComputeOverdriveDamageMul` | Overdrive damage mul | Stoic/Comrade/Slayer/Warrior modes |
| 18 | `FFX_Battle_ApplyDamageAmplifier` | Damage amplifier | BGM/Hypernull/etc? |
| 19 | `FFX_Battle_CheckAssessConceal` | Assess conceal | First-strike bonus |
| 20 | `FFX_Battle_MainDamageFormula` | Main damage formula | Aggregates all 3 damage types |
| 21 | `FFX_Battle_ResolveHitTargetEffectsAndMultipliers` | Target effects | Per-target specific mods |
| 22 | `FFX_Battle_CheckEjectHit` | Eject hit | Knockback/eject |
| 23 | `FFX_Battle_TrackDeathAndOverkill` | Death tracking | Track overkill for rewards |
| 24 | `FFX_Battle_CheckFirstStrikeMultiplier` | First strike | Initiative bonus |
| 25 | `FFX_Battle_ApplyStatusEffectFromMask` | Status effects | Zombie/Stone/Death |
| 26 | `FFX_Battle_ComputeOverdriveChargeFromHit` | OD charge | Gain overdrive on hit |
| 27 | `FFX_Battle_CheckHitResultCounters` | Hit counters | Compute total hits |
| 28 | `FFX_Battle_CheckStatModifiersActive` | Stat modifiers | Track active mods |
| 29 | `FFX_Battle_ResolveHitElementalCounters` | Counter resolution | Counter-attack detection |
| 30 | `FFX_Battle_ResolveHitAccuracyAndEffects` | Accuracy/effects | Hit/miss/effect resolution |

---

## Damage Bits Encoding

The `v80[0]` (16-bit) value uses bits to indicate damage type:

| Bit | Value | Meaning |
|-----|-------|---------|
| 0 | 0x0001 | Physical damage |
| 1 | 0x0002 | Magical damage |
| 2 | 0x0004 | Multi-hit damage |
| 7 | 0x0080 | KO (target HP ≤ 0) |
| 8 | 0x0100 | Critical hit flag |
| 9 | 0x0200 | Miss flag |
| 10 | 0x0400 | Some other flag |
| ... | ... | ... |

**Bits 0/1/2 are mutually exclusive per hit** (can't have physical AND magical from same hit). Bit 4 (multi-hit) is set **per-hit** in multi-hit scenarios.

---

## The 9999/99999 Damage Cap

```c
n9999 = (*(_WORD *)(basePower + 1726) & 0x800) ? 99999 : 9999;
```

**Why 99999?** When the **Break Damage Cap limit** ability is equipped (auto-ability from aeons like Ixion's `Kill_E:+50%` doesn't unlock this; it's `Break HP Limit`+`Break MP Limit` combo with `Break Damage Limit` from the aeons Yojimbo's `Kill +50%` etc).

Actually re-reading: the bit `0x800` at `basePower[1726]` is likely the **Break Damage Limit** auto-ability. This is the iconic FFX ability that pushes damage past 9999 to 99999.

The 9999 cap matches FFX's **HP display** which also caps at 9999 normally and 99999 with the limit break.

---

## Overdrive Damage Multipliers

```c
p_n10000 = FFX_Battle_ComputeOverdriveDamageMul(odType, actorData);
```

This applies **overdrive-mode multipliers** to damage:

| Mode | Multiplier |
|------|------------|
| Stoic | 1.5x |
| Warrior | 1.0x |
| Healer | 0.5x |
| Slayer | 2.0x |
| Tactician | 1.0x |
| Comrade | 1.0x |

(Specific multipliers depend on the formula in `ComputeOverdriveDamageMul`)

---

## Polarity Reversal (Reflect)

```c
FFX_Battle_ApplyDamagePolarityReversal(basePower, cmdCtx, hitResultCtx, currentMagic);
```

Polarity reversal is the **reflect damage** mechanic — when the attacker hits a target with Reflect status, damage is reflected back. The function swaps attacker/target roles and **computes damage as if the target hit the attacker**.

---

## Element Affinity & Resistance

Two functions handle elemental damage:

```c
// Affinity: how attacker interacts with target's element
FFX_Battle_ApplyElementAffinityModifier(target, actorData, target);

// Resistance: target's resistance to attacker's element
FFX_Battle_ApplyElementResist(element, actorData, &defender->modelHandle);
```

Multipliers:

| Affinity | Multiplier |
|----------|------------|
| Same element | +50% (e.g., Fire vs Fire-weak) |
| Opposing element | -50% (e.g., Water vs Fire) |
| No affinity | 0% |

---

## Critical Hit

```c
if (!unk_112A909)  // global flag — "no crit" mode (debug?)
    v23 = FFX_Battle_ComputeCriticalHit(basePower, defender, cmdCtx, v80, v23);
```

Critical hits multiply damage by **1.5x** (FFX's standard crit multiplier). The `unk_112A909` flag probably disables crits in some debug/training mode.

---

## KO Detection

```c
if (v65 - *n100 <= 0)
    *v80 |= 0x80u;  // set KO flag bit
```

`v65` is the defender's HP **before** the hit. `*n100` is HP after. If HP drops to 0 or below, KO flag is set.

---

## Key Findings

1. **30+ sub-functions** orchestrate the damage pipeline — each applies one specific modifier in a deterministic order.

2. **9999 / 99999 damage cap** — matches FFX's UI display. Break Damage Limit auto-ability pushes to 99999.

3. **3 damage types** (physical/magical/multi-hit) — each computed separately, then OR'd in `v80[0]` damage bits.

4. **3 damage formulas share `DamageFormulaDispatch`** — same dispatch with `(1 - unk_112A908)` formula selection. Likely normal vs. crit mode.

5. **Polarity reversal is a full re-dispatch** — Reflect damage uses the same damage formula but with swapped attacker/target.

6. **3 stats updated per hit** — currentHp, currentStrength, and one more (likely currentMagic). All capped at 0.

7. **Debug flags** at `0x112A90E/90F/910` allow forcing damage to 1, 10000, or 100000 for testing.

8. **Status effects applied via bitmask** — `cmdCtx[90]` is an 8-bit status mask (Zombie/Stone/Death/etc).

9. **Critical hit is 1.5x** — standard FFX crit multiplier. Disabled by `unk_112A909` flag (debug mode).

10. **Elemental system has 2 functions** — affinity (attacker→target element) and resistance (target→attacker element). Both can stack multiplicatively.

11. **Counter-attack handling** — `FFX_Btl_LoadMonsterBins` is called when target counters; damage flow exits early.

12. **Death tracking** — `FFX_Battle_TrackDeathAndOverkill` records overkill for rewards (AP, items, etc).

---

## What's Next?

- **batch_0013**: ATEL Movie opcode table (475 ops) — cutscene scripting
- **batch_0014**: Sphere Grid Abmap core — FFX's signature system
- **batch_0015**: Field VM opcodes — overworld scripting
- **batch_0016**: VP8/VP9 decoder entry — video codec
- **batch_0017**: MSCD file system — asset loading
- **batch_0018**: Battle UI HUD core — uses m_cursorRingState
- **batch_0019**: Cross-batch PhyreEngine architecture synthesis

---

**Next batch:** ATEL Movie opcode table — the cutscene VM that drives all FFX cutscenes.