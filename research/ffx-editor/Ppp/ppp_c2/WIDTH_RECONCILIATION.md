# WIDTH_RECONCILIATION — PPP C2/C3

> Gerado automaticamente por `work/ppp_c2/gen_width_audit.py` (2026-07-31, Jarvis-PPP-C2C3). Não editar à mão — re-rodar o script.

## Fontes

1. `work/ppp_c2/families/*.json` — 22 schemas (10 U1 com janela, 12 U2/U3 sem janela).
2. `scripts/ppp_disassembler/family_schema.py` — `U1_PROVEN_SCHEMAS` (9) e `DIRECT_OPERAND_SCHEMAS` (3).
3. `work/t3_batch/T3_BATCH_SUMMARY_20260731.md` — evidências T3 (janelas reais por família).

## Método

- `raw_yonishi` = campo `raw_width_yonishi` do schema JSON (fronteira do record no corpus Yonishi).
- `raw_effective` = valor usado na classificação: para famílias `U1_PROVEN_SCHEMAS` usa o `raw_payload_width` proven (autoridade — ver conflitos abaixo); demais usam o campo JSON.
- `runtime_window` = janela editável provada por decompile do handler (`0` = N/A).
- `width_reconciled` = janela reconciliada (runtime_window.width).
- `proven_schema_bate` = existe schema proven E ele confirma a janela do schema JSON (janela N/A no JSON => schema proven é a fonte).

## Tabela de reconciliação (22 famílias)

| family | handler | raw_yonishi | raw_effective | janela (start/width) | reconciled | schema proven | bate | classificação | T3 | nota |
|---|---|---|---|---|---|---|---|---|---|---|
| pppAccele | 0x75B830 | 24 | 16 | 16/16 | 16 | U1_PROVEN_SCHEMAS | não | janela_igual_raw | 0021: 1 PASS; 0098: 16 PASS | schema U1_PROVEN_SCHEMAS (handler 0x75b830): raw=16 float4 off=8 w=16 rec=32; CONFLITO raw: JSON=24 vs proven=16 (nota do proprio JSON cita 16B; corpus proven); usar proven; janela editavel 16B @ p... |
| pppAngAccele | 0x75B940 | 24 | 36 | 16/16 | 16 | U1_PROVEN_SCHEMAS | não | payload_maior_que_janela | 0021: 5 PASS; 0098: 22 PASS | schema U1_PROVEN_SCHEMAS (handler 0x75b940): raw=36 int32x4 off=8 w=16 rec=32; CONFLITO raw: JSON=24 vs proven=36 (nota do proprio JSON cita 36B; corpus proven); usar proven; janela editavel 16B @... |
| pppAngMove | 0x75BFE0 | 24 | 24 | 16/16 | 16 | U1_PROVEN_SCHEMAS | sim | payload_maior_que_janela | 0021: 5 PASS; 0098: 22 PASS | schema U1_PROVEN_SCHEMAS (handler 0x75bfe0): raw=24 int32x4 off=8 w=16 rec=32; janela editavel 16B @ program+16..+31 (record+0x10..+0x20); payload_maior_que_janela: handler consome menos que o reco... |
| pppAngle | 0x75CF20 | 24 | 24 | 16/16 | 16 | U1_PROVEN_SCHEMAS | sim | payload_maior_que_janela | 0021: 11 PASS; 0098: 51 PASS | schema U1_PROVEN_SCHEMAS (handler 0x75cf20): raw=24 int32x4 off=8 w=16 rec=32; janela editavel 16B @ program+16..+31 (record+0x10..+0x20); payload_maior_que_janela: handler consome menos que o reco... |
| pppColMove | 0x75C480 | 24 | 24 | 8/8 | 8 | DIRECT_OPERAND_SCHEMAS | sim | payload_maior_que_janela | 0021: 11 PASS; 0098: 41 PASS | schema DIRECT_OPERAND_SCHEMAS (handler 0x75c480): raw=8 int32x4 off=8 w=8 rec=32; raw JSON=24 = fronteira do record no corpus; schema raw=8 = payload consumido pelo handler (semantica diferente — j... |
| pppMove | 0x75BED0 | 24 | 20 | 16/16 | 16 | U1_PROVEN_SCHEMAS | não | payload_maior_que_janela | 0021: 2 PASS; 0098: 16 PASS | schema U1_PROVEN_SCHEMAS (handler 0x75bed0): raw=20 float4 off=8 w=16 rec=32; CONFLITO raw: JSON=24 vs proven=20 (nota do proprio JSON cita 20B; corpus proven); usar proven; janela editavel 16B @ p... |
| pppPoint | 0x75C540 | 24 | 24 | 16/16 | 16 | U1_PROVEN_SCHEMAS | sim | payload_maior_que_janela | 0021: 15 PASS; 0098: 62 PASS | schema U1_PROVEN_SCHEMAS (handler 0x75c540): raw=24 float4 off=8 w=16 rec=32; janela editavel 16B @ program+16..+31 (record+0x10..+0x20); payload_maior_que_janela: handler consome menos que o recor... |
| pppScale | 0x75D0D0 | 24 | 24 | 16/16 | 16 | U1_PROVEN_SCHEMAS | sim | payload_maior_que_janela | 0021: 14 PASS; 0098: 62 PASS | schema U1_PROVEN_SCHEMAS (handler 0x75d0d0): raw=24 float4 off=8 w=16 rec=32; janela editavel 16B @ program+16..+31 (record+0x10..+0x20); payload_maior_que_janela: handler consome menos que o recor... |
| pppSclAccele | 0x75B9F0 | 24 | 24 | 16/16 | 16 | U1_PROVEN_SCHEMAS | sim | payload_maior_que_janela | 0021: 9 PASS; 0098: 29 PASS | schema U1_PROVEN_SCHEMAS (handler 0x75b9f0): raw=24 float4 off=8 w=16 rec=32; janela editavel 16B @ program+16..+31 (record+0x10..+0x20); payload_maior_que_janela: handler consome menos que o recor... |
| pppSclMove | 0x75C090 | 24 | 24 | 16/16 | 16 | U1_PROVEN_SCHEMAS | sim | payload_maior_que_janela | 0021: 9 PASS; 0098: 29 PASS | schema U1_PROVEN_SCHEMAS (handler 0x75c090): raw=24 float4 off=8 w=16 rec=32; janela editavel 16B @ program+16..+31 (record+0x10..+0x20); payload_maior_que_janela: handler consome menos que o recor... |
| pppDrawMatrix | 0x734C40 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: NAO le payload. Zera flag byte a1+156 e projeta node coords (a1+80 world) -> a1+16 (screen) via FFX_Menu2D_ProjectNodeCoords_structural. |
| pppDrawMatrixFront | 0x734CA0 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: NAO le payload. Seta flag byte a1+156=1 e copia transform vec4 src_7@0x230FF20 -> a1+64 via FFX_MagicHost_CopySmallTransformVec4_structural. |
| pppDrawMdl3 | 0x739580 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: Draw handler (t2 keyhole). Mesmo nucleo do DrawMdlSemi (packing 13-bit + descritores + key) com extras: guard key em v55+4; FFX_Magic_GetCurrentMagicId() 272... |
| pppDrawMdlSea | 0x73ACA0 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: Draw handler (name_ptr 0xB51278='pppDrawMdlSea'). Aux +0x1C/+0x20 = 0x73ABC0/0x73AC00; +0x24 = 0x73AC30 (release). |
| pppDrawMdlSemi | 0x737BE0 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: Draw handler. Record: +4 resource key u16 (guard key!=0xFFFF; 0xFFFF=skip build); +8 u16 param. Descritor 32B via FFX_PppResourceDescriptorTablePtr(+32)+32*k... |
| pppDrawMdlTs | 0x738000 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: Draw handler com match: +0 u32 id (== inst+12); +4 resource key s32 (0xFFFF=skip); +8..+28 = 6 f32 deltas init state+160..180. Guard FFX_PppStatePausedFlag. |
| pppKeTh | 0x736F50 | — | — | — | 0 | DIRECT_OPERAND_SCHEMAS | sim | sem_janela_registrada | 0021: 1 PASS; 0098: 0 n/a (sem candidatos) | schema DIRECT_OPERAND_SCHEMAS (handler 0x736f50): raw=64 int32x4 off=8 w=57 rec=64; T3: 0021: 1 PASS; 0098: 0 n/a (sem candidatos); schema JSON: Handler U3 KeTh (acumulador de animacao). Payload 26... |
| pppKeThRes32 | 0x736A20 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: Allocator/chain builder (PppMem_BuildNodeChain_1x32): FFX_PppMem_BuildNodeChain(node_base+a1+160, 1, 32). PAPEL DUAL: (a) allocator +0x00 da entry aux pppSRa... |
| pppKeThRes48 | 0x736C00 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: Entry keyhole pppKeThRes48: +0x1C = 0x736C00 = PppMem_BuildNodeChain_1x48 — HIPOTESE '+0x1C = alocador' CONFIRMADA por dados (entry real). |
| pppMatrixScl | 0x734240 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: NAO le payload. Copia posicoes dual-node: node[1]+160..168 -> a3[4]/[9]/[14]; node[0]+160..168 -> a3[16..18] (a3 = buffer de saida). |
| pppMatrixXYZ | 0x72D470 | — | — | — | 0 | — | não | sem_janela_registrada | — | sem proven schema (U2/U3); schema JSON: NAO le payload (4B raw = prefixo nao-consumido). Constroi matriz Euler ZYX (FFX_MagicHost_BuildEulerZYXMatrix_structural) do estado node[1] (a1+160+v3[1]); e... |
| pppRandHCV | 0x731F90 | — | — | — | 0 | DIRECT_OPERAND_SCHEMAS | sim | sem_janela_registrada | 0021: 0 n/a (sem candidatos); 0098: 0 n/a (sem candidatos) | schema DIRECT_OPERAND_SCHEMAS (handler 0x731f90): raw=16 int32x4 off=8 w=9 rec=32; T3: 0021: 0 n/a (sem candidatos); 0098: 0 n/a (sem candidatos); schema JSON: Handler RandHCV (RNG real: srand + FF... |

## Famílias `payload_maior_que_janela` (raw > janela)

- pppAngAccele: 36 → 16 (handler consome menos que o record; bytes extras não-lidos por este handler)
- pppAngMove: 24 → 16 (handler consome menos que o record; bytes extras não-lidos por este handler)
- pppAngle: 24 → 16 (handler consome menos que o record; bytes extras não-lidos por este handler)
- pppColMove: 24 → 8 (handler consome menos que o record; bytes extras não-lidos por este handler)
- pppMove: 20 → 16 (handler consome menos que o record; bytes extras não-lidos por este handler)
- pppPoint: 24 → 16 (handler consome menos que o record; bytes extras não-lidos por este handler)
- pppScale: 24 → 16 (handler consome menos que o record; bytes extras não-lidos por este handler)
- pppSclAccele: 24 → 16 (handler consome menos que o record; bytes extras não-lidos por este handler)
- pppSclMove: 24 → 16 (handler consome menos que o record; bytes extras não-lidos por este handler)

## Conflitos de `raw_width_yonishi` nos JSONs (campo com typo)

- `pppAccele.json`: campo `raw_width_yonishi` = 24 mas proven = 16 — usar proven (o próprio JSON, na nota, cita 16B).
- `pppAngAccele.json`: campo `raw_width_yonishi` = 24 mas proven = 36 — usar proven (o próprio JSON, na nota, cita 36B).
- `pppMove.json`: campo `raw_width_yonishi` = 24 mas proven = 20 — usar proven (o próprio JSON, na nota, cita 20B).

## Conclusões

1. **Janela editável = `runtime_window`.** O valor reconciliado (e o que o writer deve respeitar) é o `runtime_window` provado por decompile/T3. `raw_yonishi` é a fronteira do record no corpus — **não** é a janela.
2. **`payload_maior_que_janela` em 9 famílias.** O handler consome menos que o record; os bytes extras não são lidos por este handler (ex.: pppMove 20B com 4B extras do prefixo; podem pertencer a outros handlers do mesmo record).
3. **pppColMove é a única janela 8B** (`u16[4]` @ program+8..+15) → **writer extension obrigatória** (schema DIRECT raw=8/w=8; o writer U1 de 16B não serve). Atenção extra: a t0 entry 151 liga pppColMove a `0x75C090` (SclMove float4/16B) — resolver o handler real pelo fp.h local antes de escrever.
4. **pppKeTh / pppRandHCV (DIRECT, janela N/A no JSON):** o schema proven define a janela de operando `{off 8, w 57}` (KeTh) e `{off 8, w 9}` (RandHCV) como writer boundary. Sem T3/T4 autorizado; pppRandHCV sem candidatos em 0021/0098; pppKeTh T3 PASS só em 0021.
5. **U2/U3 (draw/matrix/alloc):** sem janela editável — handler não lê payload (DrawMatrix, DrawMatrixFront, MatrixScl, MatrixXYZ, KeThRes32/48) ou payload não reconciliado (DrawMdl3/Sea/Semi/Ts).
6. **Conflitos de campo corrigidos pelo audit:** pppAccele (JSON 24 → proven 16) e pppAngAccele (JSON 24 → proven 36) — ver seção acima; corrigir `raw_width_yonishi` nos JSONs.
7. **pppColAccele:** T3 PASS em 0021/0098 mas **sem schema** em `work/ppp_c2/families/` — 23ª família pendente de schema JSON.
8. **T3 confirma as janelas:** 12 famílias com PASS, 23 combinações família×efeito, 485 candidatos processados (copy-only, offline).

## Arquivos gerados

- `work/ppp_c2/width_audit.json`
- `work/ppp_c2/WIDTH_RECONCILIATION.md`
