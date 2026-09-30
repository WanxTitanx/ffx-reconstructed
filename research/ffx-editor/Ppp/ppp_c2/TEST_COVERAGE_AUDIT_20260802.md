# TEST COVERAGE AUDIT — Módulo MagicDll (2026-08-02)

**Lane:** Jarvis-PPP-C2C3 · **Método:** análise estática (14 arquivos de teste, 42 testes)
**Suíte atual:** 41/41 PASS (filter MagicDll) · projeto: 336/336

## 1. Matriz área → testes

| Área | Arquivo(s) | Testes | Cobertura |
|---|---|---|---|
| Parser PE→root→sections→programs→slots | MagicDllParserTests | 7 | 0021/0098, schema fields, RT0, missing, embedded, fp.h |
| Abertura corpus (581) | MagicDllCorpusSmokeTests | 5 | amostra 40, ≥300, noroot, sem-PPP, corruptos nunca-lança |
| Round-trip byte-idêntico | MagicDllRoundTripAllTests | 1 | 581/581 DLLs |
| Cobertura field_map | MagicDllCoverageScanTests | 1 | 50 DLLs, 0 opcodes fora do catálogo |
| Write-back confinado | MagicDllEditorFlowTests + EditFuzz + EditFuzzMultiDll | 6+1+1 | fluxo, diff confinado (0021 + 4 DLLs) |
| Save/backup/restore | MagicDllEditorFlowTests | 3 | backup .bak, restore hash-gated, steam lock |
| Grow (unidade) | MagicDllGrowTests | 5+2 (theory) | aplica, re-parse, width inválido, sem doc, roundtrip, guarda node |
| Grow (corpus) | MagicDllGrowCorpusTests | 2 | 40 DLLs W=4 + multi-width 8/12/16 |
| ViewModel/UI | MagicDllEditorViewModelTests + ControlStartupTests | 5+2 | fluxo E2E, concorrência, defaults |
| Slot +4/+12 | MagicSlotArgumentOffsetTests + SlotW4InvestigationTests | 1+1 | determinístico por handler, flags 1..6 |
| C3 (targets) | MagicDllCloneTargetsTests | 1 | 164 slots U1 do 0098 |

## 2. Lacunas de cobertura (priorizadas)

1. **Descriptor table (table2)** — os 32B (w20/w24/w28, Q12) NÃO têm teste (só análise offline).
2. **Curvas dos programs** (+16/+20 samples u8) — sem teste (só análise offline).
3. **Nodes +12** — sem teste de estrutura (a guarda do grow cobre o crossing, não o formato).
4. **Restore hash-gate NEGATIVO** — restaurar com SHA errado deve ABORTAR (testado? RestoreBackup_AfterEdit cobre o positivo; o negativo não).
5. **SaveCopy bloqueando Steam Library** — IsSteamLibraryPath é unit; o SaveCopy chamando o bloqueio não.
6. **ViewModel.AddField (grow via VM)** — o fluxo VM cobre edit/save/revert; não AddField.
7. **Parser de 0086/0087** — só 0021/0098 nos testes de parse (o smoke cobre a abertura, não a estrutura).
8. **TryApplyFieldEdit com bytes de tamanho errado** — o EditFuzz usa tamanho certo; o erro de largura não é assertado.

## 3. Testes sugeridos (priorizados)

1. `DescriptorTable_0021_HasCountStrideHeader` — table2: 7 entries, w28 = count=3/stride=0x20.
2. `ProgramCurves_0021_AreU8Samples` — +16/+20: samples crescentes, sem header RLE.
3. `RestoreBackup_WrongSha_Aborts` — restore com SHA divergente → false + erro hash-gated.
4. `SaveCopy_ToSteamLibraryPath_Blocked` — save com caminho steam → bloqueado.
5. `ViewModel_AddField_OnSlot_GrowsAndLogs` — AddField via VM (slot selecionado).
6. `ApplyFieldEdit_WrongWidth_Rejected` — bytes com largura ≠ campo → erro claro.
7. `Parse_0086_0087_StructureConsistent` — paridade de estrutura (counts/roots) nas outras DLLs.
8. `Grow_0098_FirstSclMove_Applies` — grow no alvo do clone (0x1C0F0) aplica com RT0.

*2026-08-02 · Jarvis-PPP-C2C3 · análise estática (nenhum teste executado nesta auditoria)*
