# Sessão Y5-BATCHES 2026-09-15 — evidências (scratch)

Lane FFX-STRUCTURES, subagente Y5-BATCHES. Missão: fechar a onda 2 dos lotes Y5
(b10 → b08 → b11 → b04 → b05) sem promover nada a aceito.

## Inputs (read-only, pinos conferidos)

- Atlas: `docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md` sha256 `F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7` ✓
- Candidato pinado b01b02b03: `artifacts/2026-09-14/y5/y5-candidate-b01b02b03.json` sha256 `0F435C68C75BD333619ADDEE24DD5A90265E68A26D547AAB328C4500F3871BCE` ✓ (intacto no fim da sessão)
- `y5-batches.json` idêntico nas 3 localizações (research_tools/Task11Y5, artifacts/2026-09-14/y5, nvme y5-drafts): sha256 `0ce67a990fbd85cff7f34f2debc157fa0c9df8a0ca0f30a443a1afaae1c8ab33` ✓
- `y5-units-reconstruction.json` idêntico repo vs nvme ✓
- Envelope/attestations/pins da cadeia: NÃO tocados.

## Passos executados

1. Baseline dos 12 arquivos de draft existentes → `baseline_sha256.txt` (cópias em `baseline/`).
2. Extensão do gerador `research_tools/Task11Y5/y5_draft_claims.py`:
   - +5 entradas `BATCH_SUBJECTS` (b10/sjis, b08/vpa, b11/phyre, b04/fev, b05/abmap);
   - +regra de skip da janela A034 (predicado do validador: 7310 <= line_start <= 7369),
     motivo `a034-window (...)`. Sem ela, a unidade L7366 do b11 (tier A) seria rascunhada,
     violando `a034_drafted == 0`.
   - sha256 do gerador estendido: `806108369bfbceb72e04cc9791703e4b4f7cda8285400a89e82c2febb5da271f`
3. Regressão (scratch_regress/): regenerados b01-b03, b06, b07, b09 → `cmp` 12/12
   byte-idênticos (`regression_result.txt`).
4. Geração dos 5 novos (ordem da fila): b10=28, b08=55, b11=128, b04=10, b05=12 → 233 claims.
   Saída em `artifacts/2026-09-14/y5/drafts/` + espelho nvme (22/22 idênticos).
   Hashs: `new_drafts_sha256.txt`.
5. Determinismo (scratch_det/): regenerados os 5 → `cmp` 10/10 byte-idênticos.
6. Validação: `y5_batcher_validate_11lots.py` (cópia estendida aditivamente do validador
   Y5-BATCHER; original intocado) → 11/11 PASS, todas as checagens N/N
   (`validation_11lots.txt`). a034_window_drafted = 0/8 no b11. WARN: 5 pares de claim
   text duplicado (603 claims → 598 distintos) — unidades-fonte distintas com conteúdo
   byte-idêntico do atlas; registrado no doc de status §4.
7. Overlap informativo vs fila X5 re-derivada (`x5_overlap.txt`): 488/603 drafted (80,9%)
   na fila 2.915; partição 580 + 2.335 = 2.915 ✓; b21-indexes só 9/731 na fila.

## Totais

- Lotes com draft: 6 → 11 de 23. Claims: 370 → 603 (134 pinados + 469 DRAFT onda 2).
- Unidades do superset com draft: 603/5.587; restam 4.984 (ondas 3-5: 12 lotes).

## Pendências (fora do escopo)

- Ondas 3-5 (12 lotes): insumos locais completos; segurar por protocolo de ondas do plano.
- Candidato formal da onda 2: requer `y5_build_candidate.py` estendido + ciclo X/Y/Z
  com 2 attestations.
- Aceitação da lista X5 re-derivada como base de roteamento: decisão do lane-owner.
