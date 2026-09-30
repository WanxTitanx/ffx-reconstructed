#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Gera schemas U2/U3 em work/ppp_c2/families/ (formato canonico U1).

Provas: decompiles + entries (10 DWORDs) via IDA 13338, 2026-07-31.
"""
import json
from pathlib import Path

OUT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\ppp_c2\families")
OUT.mkdir(parents=True, exist_ok=True)


def schema(opcode, entry, handler, slot, notes, renames, window=None, match=None):
    return {
        "opcode": opcode,
        "entry_addrs": [entry],
        "handler_addr": handler,
        "handler_name_canonical": "FFX_PppHandler_" + opcode,
        "handler_slot": slot,
        "args": 3,
        "guard": "U2/U3: sem FFX_PppStatePausedFlag na maioria (ver notas por familia)",
        "match_word": match or {"offset_in_program": 0, "compared_to": "NAO aplicavel (handler nao le payload direto)"},
        "reads": [],
        "writes": [],
        "runtime_window": window or {"start": 0, "width": 0},
        "raw_width_yonishi": None,
        "width_reconciled": (window or {"width": 0})["width"],
        "evidence": [
            "decompile 0x" + handler[2:].upper() + " (IDA 13338, COPY ffxoficial_COPY.i64, 2026-07-31)",
            "entry " + entry + " dwords: 10 DWORDs lidos via eval (slot " + str(slot) + ")",
            "docs/reverse/PPP_C2_FULL_VERDICT_20260731.md"
        ],
        "renames": renames,
        "notes": notes,
    }


F = [
    ("pppMatrixXYZ", "0xC3A780", "0x72D470", 8,
     ["NAO le payload (4B raw = prefixo nao-consumido). Constroi matriz Euler ZYX (FFX_MagicHost_BuildEulerZYXMatrix_structural) do estado node[1] (a1+160+v3[1]); escala a matriz por node[2] (scratch 0xC8F820..0xC8F82C); escreve a1+16..+60; copia node[0]+160..168 -> a1+64..72.",
      "Sem guard de pausa, sem match word. Estado escrito: contexto do efeito (a1+16..+72).",
      "Nome antigo MagicHost_ApplyEulerZYXTransform renomeado -> FFX_PppHandler_MatrixXYZ."],
     [{"addr": "0x72D470", "old": "MagicHost_ApplyEulerZYXTransform", "new": "FFX_PppHandler_MatrixXYZ", "proof": "entry 0xC3A780 slot+8; decompile 2026-07-31"}]),
    ("pppMatrixScl", "0xC3A7A8", "0x734240", 8,
     ["NAO le payload. Copia posicoes dual-node: node[1]+160..168 -> a3[4]/[9]/[14]; node[0]+160..168 -> a3[16..18] (a3 = buffer de saida).",
      "Sem guard, sem match. Chamada FFX_BtlUI_HudParty_GetElement = provavel mis-identification do decompilador.",
      "Nome antigo FFX_MagicHost_CopyDualReferencePosition -> FFX_PppHandler_MatrixScl."],
     [{"addr": "0x734240", "old": "FFX_MagicHost_CopyDualReferencePosition", "new": "FFX_PppHandler_MatrixScl", "proof": "entry 0xC3A7A8 slot+8; decompile 2026-07-31"}]),
    ("pppDrawMatrix", "0xC3A7F8", "0x734C40", 12,
     ["NAO le payload. Zera flag byte a1+156 e projeta node coords (a1+80 world) -> a1+16 (screen) via FFX_Menu2D_ProjectNodeCoords_structural.",
      "Nome antigo FFX_MagicHost_ResetNode156Flag -> FFX_PppHandler_DrawMatrix."],
     [{"addr": "0x734C40", "old": "FFX_MagicHost_ResetNode156Flag", "new": "FFX_PppHandler_DrawMatrix", "proof": "entry 0xC3A7F8 slot+0xC; decompile 2026-07-31"}]),
    ("pppDrawMatrixFront", "0xC3A820", "0x734CA0", 12,
     ["NAO le payload. Seta flag byte a1+156=1 e copia transform vec4 src_7@0x230FF20 -> a1+64 via FFX_MagicHost_CopySmallTransformVec4_structural.",
      "Assembly (2026-07-31): cdecl, arg_0=contexto (mov edi,[ebp+arg_0]; mov [edi+9Ch],1). Chamadas GetPortrait = mis-identification.",
      "Nome antigo FFX_MagicHost_SetupTransformProjection -> FFX_PppHandler_DrawMatrixFront."],
     [{"addr": "0x734CA0", "old": "FFX_MagicHost_SetupTransformProjection", "new": "FFX_PppHandler_DrawMatrixFront", "proof": "entry 0xC3A820 slot+0xC; assembly arg_0=contexto"}]),
    ("pppDrawMdlSemi", "0xC3A870", "0x737BE0", 12,
     ["Draw handler. Record: +4 resource key u16 (guard key!=0xFFFF; 0xFFFF=skip build); +8 u16 param. Descritor 32B via FFX_PppResourceDescriptorTablePtr(+32)+32*key; lookup FFX_TextureSlot_FindOrCacheByKeyExProxy(inst+FFX_PppGlobalOffsetKey); AllocVfxParticleSlots / BuildVfxTextureAndCommitDrawable.",
      "Node state packing 13-bit via ShortVector_MultiplyAndPack/ByteVector_Reinterleave (scratch 0xC8F590..0xC8F5A6).",
      "Nome antigo MagicHost_BuildVfxDrawable_TypeF_Sub -> FFX_PppHandler_DrawMdlSemi."],
     [{"addr": "0x737BE0", "old": "MagicHost_BuildVfxDrawable_TypeF_Sub", "new": "FFX_PppHandler_DrawMdlSemi", "proof": "entry 0xC3A870 slot+0xC; decompile 2026-07-31"}]),
]


F2 = [
    ("pppDrawMdlTs", "0xC3A898", "0x738000", 12,
     ["Draw handler com match: +0 u32 id (== inst+12); +4 resource key s32 (0xFFFF=skip); +8..+28 = 6 f32 deltas init state+160..180. Guard FFX_PppStatePausedFlag.",
      "Acumula estado node[2] (records[2]): integracao 160+=164, 172+=176; aplica deltas quando match. Projecao fixed-point 65536.0; handles modelo/textura inst+144/+148; larg/alt do descritor (+28 dados modelo, u16 +22).",
      "Nome antigo FFX_MagicHost_BuildVfxTexture_TypeF -> FFX_PppHandler_DrawMdlTs."],
     [{"addr": "0x738000", "old": "FFX_MagicHost_BuildVfxTexture_TypeF", "new": "FFX_PppHandler_DrawMdlTs", "proof": "entry 0xC3A898 slot+0xC; decompile 2026-07-31"}]),
    ("pppDrawMdl3", "0xC86490", "0x739580", 12,
     ["Draw handler (t2 keyhole). Mesmo nucleo do DrawMdlSemi (packing 13-bit + descritores + key) com extras: guard key em v55+4; FFX_Magic_GetCurrentMagicId() 272/273/378; FFX_Locale_GetCurrentId; FFX_FieldEngine_Dispatch_65E010 no inicio.",
      "Nome antigo FFX_BattleCmd_ProcessAbilitySetup ENGANOSO -> FFX_PppHandler_DrawMdl3."],
     [{"addr": "0x739580", "old": "FFX_BattleCmd_ProcessAbilitySetup", "new": "FFX_PppHandler_DrawMdl3", "proof": "entry 0xC86490 slot+0xC; decompile 2026-07-31"}]),
    ("pppDrawMdlSea", "0xC3ACF8", "0x73ACA0", 12,
     ["Draw handler (name_ptr 0xB51278='pppDrawMdlSea'). Aux +0x1C/+0x20 = 0x73ABC0/0x73AC00; +0x24 = 0x73AC30 (release).",
      "Nome antigo FFX_FaceAnimation_Sequencer_structural ENGANOSO -> FFX_PppHandler_DrawMdlSea. Decompile pendente de refinamento."],
     [{"addr": "0x73ACA0", "old": "FFX_FaceAnimation_Sequencer_structural", "new": "FFX_PppHandler_DrawMdlSea", "proof": "entry 0xC3ACF8 name_ptr 'pppDrawMdlSea' slot+0xC"}]),
    ("pppKeTh", "0xC3A528-alias", "0x736F50", 8,
     ["Handler U3 KeTh (acumulador de animacao). Payload 26 campos: +0 u32 id (match ctx+12); +8..+38 = 16xu16 canais de bone node0+160..190; +40/+44/+48/+52 f32 -> node0+192/196/200/204; +56 u8 flag -> node1+240. Propagacao node0->node1 (node1+188..302 16xu16). Janela le +0..+56 (60B).",
      "Família com schema DIRECT (0x736F50, raw 64B, width 57B conservador). Sem T3/T4 autorizado (U3).",
      "Nome antigo FieldMap_AccumulateAnimationDelta -> FFX_PppHandler_KeTh."],
     [{"addr": "0x736F50", "old": "FieldMap_AccumulateAnimationDelta", "new": "FFX_PppHandler_KeTh", "proof": "decompile 2026-07-31; payload 26 campos; DIRECT_OPERAND_SCHEMAS ja apontava 0x736F50"}]),
    ("pppRandHCV", "0xC3A550-alias", "0x731F90", 8,
     ["Handler RandHCV (RNG real: srand + FFX_Math_RandomFloat01). Payload: +0 u32 id (match); +4 s32 node target offset (-1 = g_PppDefaultDeltaTarget@0xD52388); +8..+15 4xs16 ranges; +16 u8 flag (0=2x um rand; !=0 soma de 2 rands). state160 = rand (0..~512); canal i += range_i*(rand-1). Janela +0..+16 (20B).",
      "Família DIRECT (0x731F90, width 9B + offset 8). Sem T3/T4 autorizado.",
      "Nome antigo FFX_MagicHost_ApplyTransformPattern_V -> FFX_PppHandler_RandHCV."],
     [{"addr": "0x731F90", "old": "FFX_MagicHost_ApplyTransformPattern_V", "new": "FFX_PppHandler_RandHCV", "proof": "decompile 2026-07-31; RNG + ranges; DIRECT_OPERAND_SCHEMAS ja apontava 0x731F90"}]),
    ("pppKeThRes32", "0xC3AF44-alloc", "0x736A20", 0,
     ["Allocator/chain builder (PppMem_BuildNodeChain_1x32): FFX_PppMem_BuildNodeChain(node_base+a1+160, 1, 32). PAPEL DUAL: (a) allocator +0x00 da entry aux pppSRandCV (0xC3AF44, layout {+0 alloc, +0xC name, +0x14 ease}); (b) +0x1C de entries KeThRes32 na dispatch.",
      "Confirmado 1:1 com PORT_STATUS (pppKeThRes32=0x736A20)."],
     [{"addr": "0x736A20", "old": "PppMem_BuildNodeChain_1x32", "new": "FFX_PppMem_BuildNodeChain_1x32", "proof": "comentario atualizado; papel dual documentado"}]),
    ("pppKeThRes48", "0xC86080", "0x736C00", 28,
     ["Entry keyhole pppKeThRes48: +0x1C = 0x736C00 = PppMem_BuildNodeChain_1x48 — HIPOTESE '+0x1C = alocador' CONFIRMADA por dados (entry real).",
      "Wrappers NxS 39 (0x736750..0x736E10), alvo node_base+a1+160. Slots: o que contem = pendente (descritores de resource, hipotese)."],
     [{"addr": "0x736C00", "old": "PppMem_BuildNodeChain_1x48", "new": "FFX_PppMem_BuildNodeChain_1x48", "proof": "entry 0xC86080 +0x1C; decompile wrapper 1x48"}]),
]

for (op, entry, handler, slot, notes, renames) in F + F2:
    (OUT / (op + ".json")).write_text(
        json.dumps(schema(op, entry, handler, slot, notes, renames), indent=1, ensure_ascii=False) + "\n",
        encoding="utf-8")

print("OK: %d schemas U2/U3 escritos em %s" % (len(F) + len(F2), OUT))
