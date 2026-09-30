# Type-lift 2026-09-16 — manifest of applied changes (IDB `C:\IDA_DB\ffxoficial.exe.i64`)

Lane: Jarvis-DEVIN (subagent, type-lift). **SEM commit** (fan-in do orquestrador).

## Estruturas persistidas na IDB

| Tipo | Tamanho | Estado |
|---|---|---|
| `FFXBattleActorData` | 3984 (0xF90) | já existente, mantida — 168 membros, campos provados nomeados, gaps genéricos (`unk_*`) |
| `FFX_StatusDescRecord` | 4 | declarada `{u8 effectResId, u8 altResId, u8 stateKeySlotIdx, u8 flags}` |

Declarações-canônica: `FFXBattleActorData.h` (pack(1) + offsets em comentário), `FFXBattleActorData_nopack.h`, `FFXBattleActorData_orig.h` (backup).

## Tabelas de dados tipadas

| Addr | Tipo aplicado | Bytes | Registros |
|---|---|---|---|
| `0xC423D8` | `FFX_StatusDescRecord[12]` | 48 | 12 |
| `0xC42410` | `FFX_StatusDescRecord[16]` | 64 | 16 |
| `0xC42454` | `FFX_StatusDescRecord[13]` | 52 | 13 |

Verificado por `read_struct` (record 0 decodificado) + `get_global_value` (range de bytes casa com N×4).

## Protótipos corrigidos NESTA sessão (11 — `type_apply_batch`, applied=11, failed=0)

| Addr | Função | Antes (errado) | Depois |
|---|---|---|---|
| 0x7AF270 | `FFX_Battle_PropagateActorStatusEffects` | `int __cdecl(char n3, int ActorRecord)` | `int __cdecl(int n3, FFXBattleActorData *actor)` |
| 0x78C330 | `FFX_Btl_HitDamagePrecheck_structural` | 15 args c/ **nomes duplicados** (`n8`,`n100` 2×) | mesmos 15 args, nomes únicos |
| 0x7AF3A0 | `FFX_Battle_ProcessStatusEffectTimers` | `void __fastcall(FFX_StatusEffect, FFXBattleActorRecord*)` | `void __cdecl(int n15, FFXBattleActorData *actor)` |
| 0x78C580 | `FFX_Battle_CheckActorCanAct` | `int __fastcall(FFXBattleActorRecord*)` | `int __cdecl(int n15, FFXBattleActorData *actor)` |
| 0x78A950 | `FFX_Battle_ResolveHitAccuracyAndEffects` | `void __fastcall(FFX_HitCalcType, FFXBattleActorRecord*, FFXBattleActorRecord*)` | `int __cdecl(FFXBattleActorData *attacker, FFXBattleActorData *defender, int cmdCtx, int hitResultCtx, int arg_10)` |
| 0x78E400 | `FFX_Battle_ApplyMpDamage` | `int __fastcall(FFX_DamageFlags, FFXBattleActorRecord*, char n3, float *ActorRecord, int,int,int,int, char)` | `int __cdecl(char n3, FFXBattleActorData *actor, int mpDamage, int a4, int a5, int a6flags, char n129)` |
| 0x78D580 | `FFX_Battle_CtbQueuePushActor` | `void __fastcall(FFXBattleActorRecord*, FFX_BattleContext*)` | `void __cdecl(int actorIndex)` |
| 0x7B13D0 | `FFX_Battle_CtbEdgeOverdriveEvent` | `void __fastcall(FFX_CtbEdgeEventType, void*)` | `void __cdecl(int actorSlot, FFXBattleActorData *actor)` |
| 0x78D4A0 | `FFX_Battle_SortCtbPriorityQueue` | `void __fastcall(FFX_CtbPriorityModifier, void*)` | `void __cdecl(int *pOutCount)` |
| 0x78E2F0 | `FFX_Battle_ApplyHpDamage` | `int __cdecl(int n3, float *ActorRecord, int <nomes corrompidos "…Jarvis_STATUS…">…)` | `int __cdecl(int n3, FFXBattleActorData *actor, int hpDamage, int a4, int a5, int a6flags, char n129)` |
| 0x78D460 | `FFX_Battle_CanActorDieFromDamage` | `int __fastcall(FFX_DamageFlags, FFXBattleActorRecord*)` | `int __cdecl(int slotIndex)` |

Evidência (disasm): `0x7AF270` [esi+0x63C/0x63E/0x63F] + repassa ponteiro p/ `0x79B1B0`/`0x79B2A0`; `0x7AF3A0` `mov esi,[ebp+arg_4]` → `[esi+0xDC8]/+0x608/+0xE30`; `0x78C580` actor em arg1 (caller `push esi; push [ebp+n15]`); `0x78A950` `[ebx+0x5AF]` accuracy / `[eax+0x606]` suffer; `0x78E400`/`0x78E2F0` `[esi+0x5D4]` MP / `[esi+0x5D0]` HP; `0x78D580` `FFX_Battle_CtbPriorityQueue[count]=al` (índice u8); `0x7B13D0` switch 0..6 em arg0 + `[edi+0x5BB/0x594/0x5D0]`; `0x78D4A0` `mov [eax],ecx` out-count; `0x78D460` único arg → `IsAeonMenuSlot`.

## Protótipos já corretos (sessões anteriores — re-verificados via `func_profile`)

`0x791000` `int __cdecl()` · `0x794030` `FFXBattleActorData* __cdecl(int actorIndex)` · `0x78AEC0` `int __cdecl(int n8, FFXBattleActorData *attacker, int defenderSlot, FFXBattleActorData *defender, int cmdCtx, _DWORD *hitCounters, _DWORD *effectCounters, int hitResultCtx, int EffectsAndMultipliers, int *p_n10000, int *outCounterFlag)` · `0x78E2A0` `int __cdecl(char n3, FFXBattleActorData *actor, int ctbDamage, int a4, int a5, char n129)` · `0x7AFB70` `void __cdecl(int odEventType, FFXBattleActorData *actor)` · `0x79B1B0`/`0x79B2A0` `void __cdecl(FFXBattleActorData *actor)` · `0x79F010` `void __cdecl(FFXBattleActorData *actor, void *descriptorRows)` · `0x7AF4C0` `void __cdecl(FFXBattleActorData *actor)` · `0x78D290` `int __cdecl(FFXBattleActorData *actor, int rank, int hasteDur, int slowDur)` · `0x78C210` `int __cdecl(FFXBattleActorData *actor, int waitBase, int hasteDur, int slowDur)` · `0x78BFC0` `int __cdecl(int curHp, int maxHp)` · `0x78DF90` `void __cdecl(int ctbStartMode)` · `0x78D8B0` `void __cdecl(int actorIndex, int n2)` · `0x79C610` `void __cdecl(int actorIndex)`.

## Comentários de citação (`append_comments`, scope=func/line, 15 aplicados)

`0x791000`, `0x794030`, `0x7AF270`, `0x7AF3A0`, `0x78C580`, `0x78A950`, `0x78E400`, `0x78E2F0`, `0x78D580`, `0x7B13D0`, `0x78D4A0`, `0x78D460` (func) + `0xC423D8`/`0xC42410`/`0xC42454` (line) — todos com tag `[type-lift 2026-09-16]` citando `FFX_CTB_RESIDUAL_2026-09-15.md`, `FFX_CTB_STATUS_SYSTEM_COMPLETE_2026-08-19.md`, `FFX_BTL_ACTOR_PROPERTY_FULL_MAP_INFERNO_2026-06-15.md`, `FFX_AURORA_ACTOR_0xF90_STRUCT_C_DEEP_2026-06-15.md`.

## Limitação registrada — Hex-Rays indisponível

`server_health`: `hexrays_ready=true` mas `auto_analysis_ready=false` (persistente >1h); `decompile` falha em TODAS as funções testadas (incl. triviais `0x4011C0`, `0x78D460`). `idb_open`/`idb_save`/`analyze_function`/`force_recompile` não restauraram. **Delta de qualidade de decompile NÃO mensurável nesta sessão** — antes/depois só existe como assinaturas de protótipo + evidência de disasm/frame. Arquivos `before_*.txt`/`after_*.txt` anteriores preservados (alguns contêm apenas a mensagem de falha).

## IDB

`idb_save` → `{"ok":true,"path":"C:\\IDA_DB\\ffxoficial.exe.i64"}` (2026-09-16, após os 11 retypes + 15 comentários).
