# work/_btluihud — FFX_BtlUIHud type-lift R3 artifacts

Evidence + apply artifacts for the HUD/UI object lift (2026-09-16, Jarvis-DEVIN).
The object is a Phyre PInstanceList-derived HUD container of **0x4068** bytes,
allocated in `Phyre_Sort_RunScratchPass` (0x6C9640) via
`FFX_Heap_AllocGameArenaDebugFill_wrapper_w(0x4068)` and stored at global
`ds:0CDEC18` (typed `struct FFX_BtlUIHud *`, name `g_BtlUIHud`).

## Files

- `FFX_BtlUIHud.h` — canonical struct (98 members, pack-exact, offsets annotated
  CONFIRMED/VALID/SUSPECTED + evidence addresses).
- `gen_hud_struct.py` — emits the header; asserts contiguous layout to 0x4068.
- `apply_hud.py` — driver: snapshot old protos → `declare_type` →
  `type_apply_batch` (batches of 5) → `idb_save` after each batch → decompile
  verify → `append_comments`. Modes: `all|snap|declare|apply|comments`.
- `apply_res_r3.json` — per-addr apply results (28/28 ok).
- `old_protos_r3.json` — pre-lift prototypes (rollback record).
- `disasm/*.asm`, `decomp/*.c` — per-function evidence captures.
- `this_fields.json`, `offsets.json`, `disasm_hits.json` — this-alias offset
  harvest across the family.
- `residual_record_protos.json` — the 27-function residual list (source task).
- `getter_xrefs.json`, `cdec18_xrefs.json` — global/getter xref captures.
- `mcpc.py` — persistent JSON-RPC client for idalib-mcp (`IDA_MCP_URL` env).

## Applied signature shape notes

- `struct` prefix is required in MCP signatures for the UDT
  (`struct FFX_BtlUIHud *this`), bare name is rejected as "not a function type".
- `declare_type` splits `decls` on commas — send a comment-free, comma-free
  declaration (no `#pragma pack`, no multi-token comments containing commas).
- The idalib-mcp server is session-fragile: `type_apply_batch` can corrupt the
  session and `decompile` may kill the process — `idb_save` after every batch.

## Verification

- `type_inspect FFX_BtlUIHud` → size 16488 (0x4068), 98 members.
- `func_profile` post-restart shows lifted protos (e.g. 0x6CCE40
  `void __thiscall(struct FFX_BtlUIHud *this, int, char, int, int, int, int)`).
- Decompiles render `this->hudModeId`, `this->modeFilterFn`,
  `this->enemyBarPosX/Y`, `->slotEnableGridA`, `this->postFxChain` etc.
