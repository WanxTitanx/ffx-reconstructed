# type_lift — FFXBattleActorData struct source (leva 7, 2026-09-16)

Canonical source of the `FFXBattleActorData` battle-actor record now living in the
canonical IDB (`C:\IDA_DB\ffxoficial.exe.i64`).

- `gen_actor_struct.py` — generator that emits the packed C header from the
  proven offset→name→type table (168 members, size `0xF90` / 3984 bytes).
  Unproven gaps stay as `pad_NNNN[N]` — never invent semantics.
- `FFXBattleActorData.h` — generated header (`#pragma pack(push,1)`), applied to
  the IDB via `type_apply_batch` / `declare_type` MCP tools.

Evidence trail: `docs/reverse/FFX_TYPE_LIFT_2026-09-16.md` (11 corrected
prototypes, `FFX_StatusDescRecord` 4B, 3 status descriptor tables typed).
Post-restart Hex-Rays verification: `decompile 0x791000` / `0x78AEC0` render
`v2->pendingActionRingCount`, `attacker->equipStatusInflict`,
`defender->statusResist[i]` etc. — the lift is live in pseudocode.
