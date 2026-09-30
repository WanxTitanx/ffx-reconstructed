#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Gera os schemas U1 restantes em work/ppp_c2/families/ (formato canonico de pppSclMove.json).

Provas: decompiles + entries (10 DWORDs) + byte-identity via IDA 13338, 2026-07-31.
Padrao canonico: FFX_PppHandler_<Opcode> / FFX_PppHandler_<Opcode>_SetFromGlobals.
"""
import json
from pathlib import Path

OUT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\ppp_c2\families")
OUT.mkdir(parents=True, exist_ok=True)

GLOBALS_C0A = "flt_C0A004..flt_C0A010 (4 floats globais de estado inicial)"
GLOBALS_ANGLE = "0xC8F508 (256.0f,256.0f), word_C8F510, dword_C8F514 (angulos default)"

def schema(opcode, entry_t0, handler, aux, layer, window, notes, renames_old):
    return {
        "opcode": opcode,
        "entry_addrs": [entry_t0],
        "handler_addr": handler,
        "handler_name_canonical": "FFX_PppHandler_" + opcode,
        "handler_slot": 8,
        "args": 3,
        "guard": "FFX_PppStatePausedFlag @ 0x230FD34 (se setado, retorna sem acumular)",
        "match_word": {
            "offset_in_program": 0,
            "compared_to": "a1+12 (contexto do efeito = type do record); program[0] == ctx[+12]"
        },
        "layer_mode": layer,
        "reads": [
            {"what": "delta", "offset": "program+16..+28 (a2[4..7])" if window == 16 else "program+8..+15 (a2[2..3] u16[4])", "width": window},
            {"what": "estado anterior", "offset": "node + a1 + 160..+172 (0xA0..0xAC)", "width": 16},
            {"what": "guard de pausa", "offset": "FFX_PppStatePausedFlag @ 0x230FD34", "width": 4}
        ],
        "writes": [{"what": "acumula delta no estado do node/bone", "offset": "node + a1 + 160..+172", "width": 16, "op": "+= delta de program"}],
        "runtime_window": {"start": 16 if window == 16 else 8, "width": window},
        "raw_width_yonishi": 24,
        "width_reconciled": window,
        "evidence": [
            "decompile 0x" + handler[2:].upper() + " (handler U1, IDA 13338, COPY ffxoficial_COPY.i64, 2026-07-31)",
            "decompile 0x" + aux[2:].upper() + " (aux +0x1C/+0x20)",
            "entry t0 " + entry_t0 + " dwords: [name_ptr, 0, " + handler + ", 0,0,0,0, " + aux + ", " + aux + ", 0]",
            "byte-identity: pares clone confirmados por get_bytes (ver doc)",
            "docs/reverse/PPP_C2_U1_HANDLER_CONTRACTS_20260731.md"
        ],
        "renames": [
            {"addr": handler, "old": renames_old[0], "new": "FFX_PppHandler_" + opcode, "proof": "handler slot +8; decompile completo"},
            {"addr": aux, "old": renames_old[1], "new": "FFX_PppHandler_" + opcode + "_SetFromGlobals", "proof": "aux +0x1C/+0x20 identicos; decompile completo"}
        ],
        "notes": notes,
    }


F = [
    ("pppAccele", "0xC3A500", "0x75B830", "0x75B900", "double", 16,
     ["Double-layer: layerB(node[1]+a1+160..172) += program+16..28 f32[4] (DENTRO do match); layerA(node[0]+a1+160..172) += layerB SEMPRE (fora do match).",
      "BYTE-IDENTICO a 0x75BED0 (pppMove) — mesmo codigo, 2 opcodes. Clone group confirmado por get_bytes.",
      "Estado +0xA0..+0xAC do doc dispatch antigo = +160..+172 decimal = MESMA janela do padrao BoneAnim (0xA0=160, 0xAC=172). SEM conflito.",
      "Aux 0x75B900: SetFromGlobals layerB <- flt_C0A004..flt_C0A010."],
     ["FFX_Atel_AbilityMap_FuncD020_CALLPOPA_structural", "FFX_PppHandler_Accele_SetFromGlobalQ"]),
    ("pppAngAccele", "0xC3A528", "0x75B940", "0x75B9B0", "double", 16,
     ["Double-layer (mesmo padrao Accele/Move). Window real = program+16..28 (16B f32[4]).",
      "Raw yonishi 36B: o handler le apenas 16B; resto do payload nao-consumido por este handler (pode ser lido por outros slots/handlers do mesmo efeito). window_conflict_with_writer: FALSE (janela editavel 16B cabe no raw).",
      "BYTE-IDENTICO a 0x75BFE0 (pppAngMove).",
      "Aux 0x75B9B0: SetFromGlobals layerB <- (256.0f,256.0f @ 0xC8F508, word_C8F510, dword_C8F514). 256.0 = provavel angulo default em unidades PPP."],
     ["FieldMap_AccumulateDelta", "FFX_FieldMap_SetPositionFromGlobalB"]),
    ("pppMove", "0xC3A5A0", "0x75BED0", "0x75BFA0", "double", 16,
     ["Double-layer (mesmo padrao Accele). Raw 20B vs window 16B: 4B extras do payload nao sao lidos por este handler (dword1 do prefixo + possivel param de outro handler).",
      "BYTE-IDENTICO a 0x75B830 (pppAccele).",
      "Aux 0x75BFA0: SetFromGlobals layerB <- flt_C0A004..flt_C0A010."],
     ["FieldMap_AccumulateDoubleLayerDelta_B", "FFX_FieldMap_SetPositionFromGlobalD"]),
    ("pppAngMove", "0xC3A5C8", "0x75BFE0", "0x75C050", "double", 16,
     ["Double-layer (mesmo padrao AngAccele). BYTE-IDENTICO a 0x75B940 (pppAngAccele).",
      "Aux 0x75C050: SetFromGlobals layerB <- (256,256,word_C8F510,dword_C8F514)."],
     ["FieldMap_AccumulateDelta_B", "FFX_FieldMap_SetPositionFromGlobalE"]),
    ("pppColMove", "0xC3A618", "0x75C480", "0x75C500", "double", 8,
     ["UNICO U1 com janela 8B: delta u16[4] @ program+8..+15 (a2[2..3]); record 16B = 8B prefixo + 8B payload.",
      "layerB(node[1]+160..166) += u16[4] (match); layerA(node[0]+160..166) += layerB SEMPRE.",
      "ATENCAO (writer): a t0 entry 151 (alias) aponta para 0x75C090 (SclMove float4, janela 16B) — handler REAL depende do fp.h local. Schema DIRECT (word4/8B) vale para o handler 0x75C480; se o fp.h local ligar pppColMove a 0x75C090, usar schema SclMove.",
      "Aux 0x75C500: SetFromGlobals layerB <- (256.0f,256.0f @ 0xC8F508) apenas 8B. CHAR_Tidus (0xC8B500) = ponteiro node base global, nome ENGANOSO do pass."],
     ["FFX_BoneAnim_ApplyDeltaWord4", "FFX_FieldMap_SetPositionWithBaseOffset_B"]),
    ("pppPoint", "0xC3A640", "0x75C540", "0x75C5B0", "single", 16,
     ["SINGLE-layer: node[0]+a1+160..172 += program+16..28 f32[4] (somente no match). Sem propagacao entre camadas.",
      "BYTE-IDENTICO a 0x75D0D0 (pppScale). 4.306 samples = maior familia U1 — melhor candidato a proxima T3.",
      "Aux 0x75C5B0: SetFromGlobals node[0] <- flt_C0A004..flt_C0A010 (single-layer usa node[0], nao node[1]). Nome antigo ResetBoneToDefault enganoso — nao reseta, seta globais."],
     ["FFX_BoneAnim_ApplyDeltaFloat4", "FFX_BoneAnim_ResetBoneToDefault"]),
    ("pppAngle", "0xC3A668", "0x75CF20", "0x75CF70", "single", 16,
     ["SINGLE-layer (igual Point/Scale): node[0]+160..172 += program+16..28. Semantic-identico a Scale/Point mas NAO byte-identico (ordem de load difere).",
      "Aux 0x75CF70: SetFromGlobals node[0] <- (256,256,word_C8F510,dword_C8F514)."],
     ["FFX_FieldMap_AccumulateVec4", "FFX_FieldMap_SetPositionFromGlobalG"]),
    ("pppScale", "0xC3A690", "0x75D0D0", "0x75D140", "single", 16,
     ["SINGLE-layer (igual Point). BYTE-IDENTICO a 0x75C540 (pppPoint).",
      "T4 observado 2026-07-31: mutacao 42.5->2.0 deixou cast do Power Break visivelmente mais lento (acumulador por frame do bone).",
      "Aux 0x75D140: SetFromGlobals node[0] <- flt_C0A004..flt_C0A010."],
     ["FFX_BoneAnim_ApplyDeltaFloat4_B", "FFX_FieldMap_SetPositionFromGlobalH"]),
]

for (op, t0, h, aux, layer, window, notes, olds) in F:
    (OUT / (op + ".json")).write_text(
        json.dumps(schema(op, t0, h, aux, layer, window, notes, olds), indent=1, ensure_ascii=False) + "\n",
        encoding="utf-8")

print("OK: %d schemas escritos em %s" % (len(F), OUT))
