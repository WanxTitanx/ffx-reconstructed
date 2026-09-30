# C2-B Runtime Reports — Deep Read Synthesis

**Mode:** READ ONLY. No inject, no compile, no deploy, no edit, no commit.
**Date:** 2026-07-14
**Companion JSON:** `DEEPSEEK_READ_C2B_RUNTIME_REPORTS.json`

---

## Reports Read (6 of 6)

| # | File | Size | Status |
|---|------|------|--------|
| 1 | `C2_B_T1_RUNTIME_CAPTURE_PLAN.md` | 40 KB | DESIGN ONLY |
| 2 | `C2_B_T1_RUNTIME_CAPTURE_PLAN_REVIEW.md` | 19 KB | CHANGES REQUIRED (7 corrections, all applied) |
| 3 | `C2_B_T1_ENVIRONMENT_PREFLIGHT.md` | — | PREFLIGHT COMPLETE |
| 4 | `C2_B_MUTATION_GATE_PLAN.md` | — | DESIGN ONLY |
| 5 | `C2_B_T_LADDER.md` | — | READ-ONLY design |
| 6 | `C2_B_T1_CAPTURE_TARGETS.md` | ~100 KB | READ-ONLY manifest |

---

## Report-by-Report State

### 1. C2_B_T1_RUNTIME_CAPTURE_PLAN.md

Targets `FFX_FieldMap_AccumulateVec4Word` (pppColor handler) at `0x75D2E0`. Proposes 16-byte read-only capture of the `a2` parameter record. 10 safety constraints (S1-S10). 9 preconditions (P1-P9); only P1, P2, P9 are MET. 6 success criteria with tiered partial success. Primary method: HW breakpoint via WinDbg (`ba e 1 0x75D2E0 "..."`). Fallback: PolyHook2 detour in `ffx-hooks.dll`.

**Key line:** §1.5 — `unk_230FD34` is a shared PPP/render-pipeline gate (143 xrefs), **not** Menu2D-specific. **Never flip.**

**Key line:** §9.3 — Option A (HW breakpoint) RECOMMENDED for first run. Option B (PolyHook2 detour) is the fallback.

**Key line:** §9.5 — `ffx-probe.dll` has `FFXPROBE_OP_CALL` but is cdecl/stdcall only. Not an issue for B-T1.

### 2. C2_B_T1_RUNTIME_CAPTURE_PLAN_REVIEW.md

Verdict: technically sound but 7 errors. Three critical: xref address (`0xC64DD0` → `0xC64CE8`), fabricated reader function names (`FFX_Menu2D_*` → actual sound/render functions), and canonical DB grounding (`ffx_exe_copy.i64` → `ffxoficial.exe.i64`). Provenance internal contradiction (P7 optional vs §10.1.6 required) resolved as tiered best-effort.

**Precondition readiness:** P1+P2 VERIFIED. P3 (fixture) highest risk. P7 (PPP interpreter pre-analysis) NOT DONE.

### 3. C2_B_T1_ENVIRONMENT_PREFLIGHT.md

**Inert probe build:** YES today on 2 paths (`ffx-probe.dll` cl.exe only, `ffx-hooks.dll` Fase 0).
**PolyHook build:** NO — `vcpkg_installed/.../lib/` missing.
**Canonical IDB:** Present at Steam path. `ffx_exe_copy.i64` MISSING.
**modules\ dir:** LIVE deployed probes present. Clean session requires backup/swap.
**cl.exe:** Not on PATH (expected; scripts use `vcvarsall.bat`).

### 4. C2_B_MUTATION_GATE_PLAN.md

9-criterion promotion gate (C1-C9). COLOR-only. Family-B target (no textures). B-T1 is a hard precondition (PR1, PR2). Thundara confound documented and avoided. Full backup/patch/rollback procedure. Detailed failure taxonomy (6 patch-time, 3 load-time, 4 runtime, 3 partial).

**Critical gate logic:** `C2-B PROMOTED ⟺ C1 ∧ C2 ∧ C3 ∧ C4 ∧ C5 ∧ C6 ∧ C7 ∧ C8 ∧ C9`

**Hard blocker:** PR1 (B-T1 pass) NOT MET. B-T1 is design-only.

### 5. C2_B_T_LADDER.md

T1-T5 delivery ladder. ~2.75h best case, ~5h worst case. Deadline 2026-07-15 00:00.
16 static facts proven today. 8 unknowns requiring game interaction. 5 refuted claims.

**Proven today (P10):** 0 pppColor non-header slots across entire 141-DLL corpus.
**Proven today (P16):** `ppp_dispatch_table.json` is UNRELIABLE — stale addresses with +0x1500 delta.

### 6. C2_B_T1_CAPTURE_TARGETS.md

81 DLLs scanned. 290 targets (146 pppColor + 144 pppScale). 0 HIGH confidence. 280 MEDIUM, 10 LOW.
**Every single target has `is_header: True`** — confirming T-Ladder P10.

---

## DINPUT8 Loader vs modules\\ffx-probe.dll — Classification

| Component | Classification | Role |
|-----------|---------------|------|
| `dinput8.dll` (game root) | **LOADER** | FFX Module Loader. Loads `modules\\*.dll` at startup. NOT a probe. |
| `modules\\ffx-probe.dll` | **PROBE** | Main-thread seam. Hooks `GetDeviceState` (vtable[9]). PROVEN RT2. |
| `modules\\ffx-hooks.dll` | **HOOK DLL** | PolyHook2 hooks (23 sources). Fase 0 inert buildable; full build BLOCKED. |
| `ffxprobctl.exe` | **CONTROL** | External console. Commands: `mon`, `read`, `write`, `call`. |

**Loader chain:** `FFX.exe` → loads `dinput8.dll` (proxy) → `dinput8.dll` loads `modules\\ffx-probe.dll` and `modules\\ffx-hooks.dll` at startup.

---

## READ vs CALL/WRITE/Injection — Strictly Distinguished

### READ (proven, used in T1)
- `ffxprobctl read <rva> <len>` — reads N bytes at RVA on main thread
- HW breakpoint (WinDbg `ba e 1 addr "..."`) — zero modification
- PollyHook2 `ResolverLogHook` — detour, log args, return trampoline result
- `KeThResSnap` pattern — `memcpy(buf, ptr, N)` under SEH via inline hook
- **T1 uses READ only**

### CALL (proven, NOT used in T1-T5)
- `ffxprobctl call <rva> [args]` — cdecl/stdcall only
- NOT proposed for any T1-T5 capture step

### WRITE (proven runtime, used differently in T4)
- `ffxprobctl write <rva> <data>` — in-memory write at frame tick
- **T4 uses file write (not memory write):** Python script patches DLL on disk; game restarted
- No runtime memory write is proposed for T1-T5

### Injection
- No `CreateRemoteThread` anywhere in proven infra
- `dinput8.dll` is a startup-time loader, not a runtime injection vector

---

## Unsafe / Unsupported Claims Identified

| # | Claim | Verdict | Source |
|---|-------|---------|--------|
| UC1 | `ppp_dispatch_table.json` is reliable | **REFUTED** — +0x1500 delta, stale | T-Ladder P16 |
| UC2 | `unk_230FD34` is Menu2D capture-batch flag | **CORRECTED** — PPP/render pipeline gate | Review C2 |
| UC3 | SCALE codec is usable for C2-B | **UNSUPPORTED** — 4 blockers | T-Ladder P13 |
| UC4 | COLOR mutation via PPP slot viable | **STRUCTURALLY BLOCKED** — 0 non-header slots | T-Ladder P10 + CAPTURE_TARGETS |
| UC5 | `ffx_exe_copy.i64` is canonical | **CORRECTED** — missing, use `ffxoficial.exe.i64` | Review C3 + Preflight §4 |
| UC6 | PolyHook2 is primary capture path | **BLOCKED** — vcpkg libs missing | Preflight §8 |

---

## Preconditions Summary by Tier

### T1 Capture (requires game launch + spell cast)
- **8 of 11 preconditions NOT MET** (P3, P4, P5, P6, P7, P8, U7, U8)
- **Critical:** P3 (fixture derivation) — highest risk
- **Hard blocker if unmet:** P7 (PPP interpreter pre-analysis) for source attribution

### T2 Correlation (offline)
- Blocked by G1 (T1 must pass with PC1+PC2+PC3)
- Tools all validated

### T3 Dry-Run (offline)
- Blocked by G2 (T2 must pass with TC1+TC2+TC3)
- Codec validated for COLOR; SCALE blocked

### T4 Mutation (requires game restart + observe)
- Blocked by G3 (T3 must pass)
- **PR1 (B-T1 pass) is a hard blocker** — NOT MET
- **PR4/PR5 (save/encounter) also NOT MET**
- Requires Python + `pefile` for patching

### T5 Reproduction (requires control run)
- Blocked by G4 (T4 must pass with C1-C5,C8,C9)
- Requires original DLL backup

---

## Structural Blockers — The COLOR Problem

The most significant finding is that **COLOR mutation via PPP slot `parameter_offset` hits a structural dead end**:

1. **T-Ladder P10:** "0 pppColor non-header slots across entire 141-DLL corpus"
2. **CAPTURE_TARGETS:** ALL 146 pppColor targets have `is_header: True`
3. **B Mutation Gate:** requires DLL payload mutation (COLOR-only)
4. **RE Locator Semantics:** `parameter_offset` is entity-data-relative

**Consequence:** Even if T1 captures pppColor data successfully, T2 will find zero non-header payload-region matches. The DLL file bytes at `section_base + parameter_offset` map to program headers, not payload data. Mutating a header byte corrupts the PPP program structure.

**Available alternate paths:**
- **SCALE** (144 non-header candidates) — but SCALE Level A must be re-promoted (4 blockers)
- **Root-record float4 surgery** — outside C2-B scope, documented in FAMILY_B_REFERENCE.md §11
- **DLL-internal handler functions** — outside C2-B scope, triggered if PC1 fails at T1

---

## Verified Commands & Capabilities

All proven components ready for T1 deployment:

| Component | Command/Pattern | Status |
|-----------|----------------|--------|
| `ffxprobctl` | `mon` (heartbeat) | PROVEN |
| `ffxprobctl` | `read <rva> <len>` | PROVEN RT2 |
| `ffxprobctl` | `write <rva> <data>` | PROVEN RT2 |
| `ffxprobctl` | `call <rva> [args]` | PROVEN RT2 (cdecl/stdcall) |
| `ffx-hooks.dll` | `ResolverLogHook` (detour+log) | PROVEN |
| `ffx-hooks.dll` | `FfxFaultProbeVeh` (EBP walk) | PROVEN |
| `ffx-probe.c` | `KeThResSnapPost` (inline-hook capture) | PROVEN |
| `ffx-hooks.dll` | `AuroraReadBytes` (SEH guard) | PROVEN |
| `build_hooks.ps1` | Deploy guard (refuse if FFX running) | PROVEN |
| `layer_c_resource.py` | Parse PPP resource | VALIDATED (274,732 slots) |
| `c2_color_codec.py` | COLOR codec | VALIDATED (71/71 fixtures) |
| `layer_c_slot.py` | Slot codec | VALIDATED (68/68 tests) |
