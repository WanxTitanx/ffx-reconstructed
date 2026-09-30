# U1 Manifests — T3 Targets (PPP C2)

Gerado em 2026-08-01T01:47:28Z por `work/ppp_c2/gen_u1_targets.py`.
Fonte de candidatos: manifests `prepare_u1_manifest.py` (9 famílias U1) + walker C1 do batch T3 2026-07-31 (pppColMove).
DLLs de origem (somente leitura): `F:\ffx-reconstructed\extras\magicFiles\FFX`

## DLLs

| DLL | SHA256 |
|---|---|
| magic_0021.dll | `a659894a109e535ea1ad8d8676d3e151a63aded9eb683133d247bfc43b890cb9` |
| magic_0098.dll | `ecc88fc9109c9cd6825baac62b19d93238e04cd23cb56d3fd98d3b1ea53bc313` |

## Manifests (reproduzíveis byte-a-byte vs 2026-07-31)

| Manifest | SHA256 |
|---|---|
| magic_0021.json | `c5de20c956364df896c00b64325625f0e9e7227a45be7b28ce91d00267cb48a4` |
| magic_0098.json | `b68f63ee3e2cb6b9534ac0b82de71cf65f310e00e3e260cbbb7ef9bc640aa03f` |

## Tabela de alvos T3 por família × DLL

| Família | DLL | #candidatos | record(s) | janela (record+) | handler_index local | origem | status |
|---|---|---|---|---|---|---|---|
| pppSclMove | magic_0021.dll | 9 | `0x193C0, 0x198B0, 0x19DB0, … (+6)` | +0x10..+0x20 (16B) | 7 | manifest | t3_pass |
| pppSclMove | magic_0098.dll | 29 | `0x19AC0, 0x19E60, 0x1A270, … (+26)` | +0x10..+0x20 (16B) | 6 | manifest | t3_pass |
| pppSclAccele | magic_0021.dll | 9 | `0x19310, 0x197D0, 0x19CD0, … (+6)` | +0x10..+0x20 (16B) | 3 | manifest | t3_pass |
| pppSclAccele | magic_0098.dll | 29 | `0x19A60, 0x19DD0, 0x1A210, … (+26)` | +0x10..+0x20 (16B) | 2 | manifest | t3_pass |
| pppAccele | magic_0021.dll | 1 | `0x18F60` | +0x10..+0x20 (16B) | 1 | manifest | t3_pass |
| pppAccele | magic_0098.dll | 16 | `0x19DA0, 0x1A550, 0x1C6A0, … (+13)` | +0x10..+0x20 (16B) | 0 | manifest | t3_pass |
| pppAngAccele | magic_0021.dll | 5 | `0x18C50, 0x197A0, 0x19CA0, … (+2)` | +0x10..+0x20 (16B) | 2 | manifest | t3_pass |
| pppAngAccele | magic_0098.dll | 22 | `0x19A30, 0x1A1E0, 0x1A9C0, … (+19)` | +0x10..+0x20 (16B) | 1 | manifest | t3_pass |
| pppMove | magic_0021.dll | 2 | `0x18FB0, 0x1BBF0` | +0x10..+0x20 (16B) | 5 | manifest | t3_pass |
| pppMove | magic_0098.dll | 16 | `0x19E30, 0x1A5E0, 0x1C750, … (+13)` | +0x10..+0x20 (16B) | 4 | manifest | t3_pass |
| pppAngMove | magic_0021.dll | 5 | `0x18C80, 0x19880, 0x19D80, … (+2)` | +0x10..+0x20 (16B) | 6 | manifest | t3_pass |
| pppAngMove | magic_0098.dll | 22 | `0x19A90, 0x1A240, 0x1AA20, … (+19)` | +0x10..+0x20 (16B) | 5 | manifest | t3_pass |
| pppColMove | magic_0021.dll | 11 | `0x18fe0, 0x19430, 0x19920, … (+8)` | +0x8..+0x10 (8B) | 8 | walker_t3 | t3_pass |
| pppColMove | magic_0098.dll | 41 | `0x19e90, 0x1a640, 0x1ae00, … (+38)` | +0x8..+0x10 (8B) | 7 | walker_t3 | t3_pass |
| pppPoint | magic_0021.dll | 15 | `0x18CB0, 0x19010, 0x19470, … (+12)` | +0x10..+0x20 (16B) | 9 | manifest | t3_pass |
| pppPoint | magic_0098.dll | 62 | `0x19AF0, 0x19EC0, 0x1A2A0, … (+59)` | +0x10..+0x20 (16B) | 8 | manifest | t3_pass |
| pppAngle | magic_0021.dll | 11 | `0x18CE0, 0x194A0, 0x19990, … (+8)` | +0x10..+0x20 (16B) | 10 | manifest | t3_pass |
| pppAngle | magic_0098.dll | 51 | `0x19B20, 0x1A2D0, 0x1AAB0, … (+48)` | +0x10..+0x20 (16B) | 9 | manifest | t3_pass |
| pppScale | magic_0021.dll | 14 | `0x18D30, 0x19040, 0x194D0, … (+11)` | +0x10..+0x20 (16B) | 11 | manifest | t3_pass |
| pppScale | magic_0098.dll | 62 | `0x19B70, 0x19F10, 0x1A320, … (+59)` | +0x10..+0x20 (16B) | 10 | manifest | t3_pass |

## Notas de honestidade

- `handler_index` é **local ao fp.h do efeito** (nunca índice universal). pppSclMove/0021 = 7 confirmado; demais índices vêm do manifest do efeito correspondente.
- `pppColMove` não está em `U1_PROVEN_SCHEMAS` (vive em `DIRECT_OPERAND_SCHEMAS`, janela 8B u16[4] @ +8). Candidatos vieram do walker C1 do batch T3 (evidências `work/t3_batch/T3_EVIDENCE_pppColMove_*.json`), não do manifest U1.
- Status `t3_pass` = evidência T3 copy-only de 2026-07-31 (dry-run/apply/restore byte-idêntico em cópias descartáveis). Nenhuma DLL do jogo foi modificada.
- Offsets completos + SHA256 de cada record: `work/ppp_c2/u1_targets.json` (este diretório).
- pppRandHCV/pppSRandHCV/pppKeTh não fazem parte da fila U1 (schemas diretos, sem writer autorizado na fila principal).
