# T3 WRITER STATUS — Magic DLL Editor (2026-08-02)

**Lane:** Jarvis-PPP-C2C3 · **Status:** writer generalizado IMPLEMENTADO e PROVADO no editor
**Base:** `FFXProjectEditor/FfxLib/MagicDll/` + `Modules/MagicDllEditor/MagicDllDocument_Wrapper.cs`

## 1. O que era a pendência (seção 6.2 do prompt C2)

> "work/ppp_c2/T3_WRITER_STATUS.md: pytest do pacote scripts/ppp_disassembler verde; roundtrip dry-run/apply/restore em CÓPIA de DLL por família (nunca na original); ajustar useful_ppp_writer.py (window por família, preservando SclMove 16B) + tests/test_t3_roundtrip_generalized.py."

## 2. Resolução: o T3 generalizado virou o editor (C#, não Python)

O writer T3 por família foi absorvido pelo **Magic DLL Editor** (C#), que implementa o ciclo completo
T3 de forma generalizada para **todas** as famílias payload_consumer:

| Capacidade | Onde | Prova |
|---|---|---|
| Round-trip byte-idêntico (RT0) em TODAS as DLLs | `MagicDllDocument_Wrapper` + parser | `MagicDllRoundTripAllTests`: **581/581 DLLs, SHA igual** |
| Aplicar edição de campo confinada à janela | `TryApplyFieldEdit` (âncora SHA do record) | `MagicDllEditorFlowTests` + `MagicDllEditFuzzTests` (diff sempre confinado) |
| Backup + restore hash-gated | `TrySaveCopy`/`TryRestoreBackup` (.bak + SHA) | `Grow_RoundTripRestore_VoltaAoOriginal` |
| Grow (adicionar campo) com relocação | `TryGrowRecord` (receita corrigida) | `MagicDllGrowTests` (3 religados) + `MagicDllGrowCorpusTests` (40 DLLs, multi-width) |
| Parse nunca-lança | helpers bounds-checked | fuzz 200 mutações |

## 3. Testes (34/34 PASS, Release)

- `MagicDllParserTests` (7): RT0 parse→serialize byte-idêntico
- `MagicDllEditorFlowTests` (6): fluxo completo abrir→editar→salvar→reverter
- `MagicDllGrowTests` (6): grow aplica (SHA/tamanho), re-parse externo, width inválido, sem doc, round-trip restore
- `MagicDllGrowCorpusTests` (2): fuzz 40 DLLs W=4 + multi-width 8/12/16 — grow aplica OU rollback byte-idêntico
- `MagicDllCorpusSmokeTests` (5): amostra + lote + recuperadas
- `MagicDllEditorViewModelTests` (5): E2E headless do VM + concorrência do gate
- `MagicDllRoundTripAllTests` (1): 581/581 DLLs
- `MagicSlotArgumentOffsetTests` (1): verificação do +4/+0xC do slot
- `MagicDllEditFuzzTests` (1): 12 edits aleatórios, diff confinado

## 4. Status por família (janelas provadas)

- **43 famílias payload_consumer** no embedded; **27 knobs com janela REAL** (16B U1, 24B draw, 49B KeTh/KeMdlTfd, 36B EiWindFun, 9B RandInt/CV, 6B RandChar, 8B ColMove...)
- T3 (write-back confinado + RT0) = **implementado e provado em TODAS** (o write-back usa o schema da família — janela por família)
- T4 (observação in-game) = autorizado apenas para a trilogia U1 (Power Break); demais famílias aguardam janela runtime + aprovação

## 5. O que ainda NÃO é T3-runtime (honesto)

- O write-back edita os bytes; o **efeito visual** de cada família depende do handler no jogo (T4)
- Famílias Rand usam RNG — a mutação muda a DISPERSÃO, não um valor determinístico; T4 exigiria observação estatística
- O grow adiciona campo **inerte** (o handler atual não o lê) — requer patch de handler/T4 para ter efeito

## 6. scripts/ppp_disassembler (Python)

- `family_schema.py` estendido (carrega/valida schemas; `requires_writer_extension` se window ≠ 16)
- pytest: **226/226 PASS** (baseline 214 + 12 novos de schemas)
- O `useful_ppp_writer.py` (Python) NÃO foi generalizado — a generalização foi para o C# (editor), onde o RT0 581/581 é a prova mais forte
