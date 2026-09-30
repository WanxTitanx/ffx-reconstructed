#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Gera schemas para TODAS as familias PPP (uniao mapa 118 + catalogo 131) que
ainda nao tem schema. Fonte: FAMILY_C2_TRIAGE + decompiles dos 11 knobs (janelas reais).

Output: work/ppp_c2/families/*.json (novos)
"""
import json
from pathlib import Path

ROOT = Path(r"C:\Users\wande\Documents\ffx-editor-main")
TRIAGE = json.loads((ROOT / "work/ppp_c2/FAMILY_C2_TRIAGE_20260731.json").read_text(encoding="utf-8"))["families"]
CAT = json.loads((ROOT / "work/ppp_handlers/PppHandlerBehaviorCatalog.json").read_text(encoding="utf-8"))
OUT = ROOT / "work/ppp_c2/families"
OUT.mkdir(parents=True, exist_ok=True)

existing = {f.stem for f in OUT.glob("*.json")}

# janelas reais dos 11 knobs (prova decompile 2026-07-31)
KNOB_WINDOWS = {
    "pppAngMoveLoop": {"start": 16, "width": 12, "note": "3x s32 (+16/+20/+24) += node1+160..168 (match); node0 += node1 sempre. Double-layer int32."},
    "pppAngleLoop": {"start": 16, "width": 12, "note": "3x s32 (+16/+20/+24) += node0+160..168. Init: node0+176=handle do prog quando nulo. Single-node."},
    "pppDrawMdlTs2": {"start": 8, "width": 24, "note": "6x f32 (+8..+28) init deltas node[2]+160..180; key dword +4 (0xFFFF=skip). Tipo E."},
    "pppDrawMdlTs3": {"start": 8, "width": 24, "note": "6x f32 (+8..+28) init deltas; key +4. Variante locale (magic id checks)."},
    "pppDrawMdlLoop": {"start": 8, "width": 24, "note": "6x f32 (+8..+28); INIT quando node+160 nulo (164=a3+8, 176=a3+20); key +4."},
    "pppDrawMdlLoopZ": {"start": 8, "width": 24, "note": "6x f32 (+8..+28); key +4; checks magic id 258/259/244/272/313/122."},
    "pppDrawMdlLoopDisPos": {"start": 8, "width": 24, "note": "6x f32 (+8..+28); key +4; flags +33..+38 (byte +38 seleciona node alternativo)."},
    "pppDrawMdlCameraLoop": {"start": 8, "width": 24, "note": "6x f32 (+8..+28); key +4; flags anim textura +33/+34/+35; fmod 32768.0; camera."},
    "pppDrawFilter": {"start": 12, "width": 24, "note": "wrapX u32<<8 +12, wrapY<<8 +16, deltas s32 +28/+32 += node+164/+168; clamp [0, wrap<<8). SEM match word."},
    "pppEiWindFun": {"start": 16, "width": 36, "note": "6x f32 init (+16..+36) node+160..180 + 3x f32 deltas (+40/+44/+48) node+188..196; magnitude/norm de vento; Euler."},
    "pppNeiPointLight": {"start": 4, "width": 12, "note": "3x f32 (+4/+8/+12) += node+160/164/168; node+172/+176 = handles vizinhos; Euler acc->vel->pos."},
}

CAT_BY_HANDLER = {int(a, 16): r for a, r in CAT["handlers"].items()}

created = 0
for fam, t in sorted(TRIAGE.items()):
    if fam in existing:
        continue
    handler = t["handler_addr"]
    if not handler:
        continue
    h = int(handler, 16)
    cat = CAT_BY_HANDLER.get(h)
    payload = bool(cat and cat.get("payload_indexes"))

    if fam in KNOB_WINDOWS:
        win = KNOB_WINDOWS[fam]
        payload_consumer = True
        window = {"start": win["start"], "width": win["width"]}
        reads = [{"what": "operandos", "offset": f"program+{win['start']}..+{win['start']+win['width']-1}", "width": win["width"]}]
        notes = [win["note"], "Decompile completo 2026-07-31 (IDA 13338)."]
    else:
        payload_consumer = False
        window = {"start": 0, "width": 0}
        reads = []
        notes = ["NAO le payload direto (catalogo payload_indexes vazio); contrato de dispatch provado. "
                 "Decompile disponivel no PppHandlerBehaviorCatalog."]
        if payload:
            payload_consumer = True  # catalogo diz que le — janela por verificar
            notes = ["PAYLOAD_INDEXES do catalogo: " + str(cat["payload_indexes"]) +
                     " — janela NAO confirmada por decompile manual nesta rodada (verificar antes de writer)."]

    schema = {
        "opcode": fam,
        "handler_addr": handler,
        "handler_name_canonical": f"FFX_PppHandler_{fam}",
        "handler_slot": t.get("handler_slot"),
        "entry_addrs": [t.get("entry_addr")] if t.get("entry_addr") else [],
        "args": 3,
        "guard": "FFX_PppStatePausedFlag @ 0x230FD34 (se setado, retorna sem acumular) — exceto DrawFilter (sem guard/match)",
        "match_word": "program[0] == ctx[+12]" if fam != "pppDrawFilter" else "SEM match word (DrawFilter nao checa id)",
        "payload_consumer": payload_consumer,
        "reads": reads,
        "writes": [],
        "raw_width_yonishi": None,
        "runtime_window": window,
        "width_reconciled": window["width"],
        "evidence": [
            f"handler {handler} (decompile catalogo PppHandlerBehaviorCatalog, 139/139)",
            f"triagem FAMILY_C2_TRIAGE_20260731.json (row do opcode_handler_map)",
        ],
        "renames": [{"addr": handler, "old": t.get("handler_name"), "new": f"FFX_PppHandler_{fam}",
                     "proof": "padrao canonico C2 FULL; handler da entry do opcode"}],
        "notes": notes,
    }
    (OUT / f"{fam}.json").write_text(json.dumps(schema, indent=1, ensure_ascii=False) + "\n", encoding="utf-8")
    created += 1

# ---- Parte 2: familias do catalogo fora do mapa (inclui os 3 knobs) ----
CAT_FAMILIES = {}
for addr, rec in CAT["handlers"].items():
    for op in rec["used_by"]:
        CAT_FAMILIES.setdefault(op, {"handler_addr": hex(int(addr, 16)),
                                     "handler_name": rec.get("func_name"),
                                     "payload_indexes": rec.get("payload_indexes") or []})

created2 = 0
for fam, info in sorted(CAT_FAMILIES.items()):
    if fam in existing or (OUT / f"{fam}.json").exists():
        continue
    if fam in KNOB_WINDOWS:
        win = KNOB_WINDOWS[fam]
        window = {"start": win["start"], "width": win["width"]}
        notes = [win["note"], "Decompile completo 2026-07-31 (IDA 13338)."]
        reads = [{"what": "operandos", "offset": f"program+{win['start']}..+{win['start']+win['width']-1}", "width": win["width"]}]
        payload_consumer = True
    else:
        payload_consumer = bool(info["payload_indexes"])
        window = {"start": 0, "width": 0}
        reads = []
        if payload_consumer:
            notes = ["PAYLOAD_INDEXES do catalogo: " + str(info["payload_indexes"]) +
                     " — janela NAO confirmada por decompile manual nesta rodada (verificar antes de writer)."]
        else:
            notes = ["NAO le payload direto (catalogo payload_indexes vazio)."]

    schema = {
        "opcode": fam,
        "handler_addr": info["handler_addr"],
        "handler_name_canonical": f"FFX_PppHandler_{fam}",
        "handler_slot": None,
        "entry_addrs": [],
        "args": 3,
        "guard": "FFX_PppStatePausedFlag @ 0x230FD34 (padrao; verificar por familia)",
        "match_word": "program[0] == ctx[+12] (padrao; DrawFilter nao checa id)",
        "payload_consumer": payload_consumer,
        "reads": reads,
        "writes": [],
        "raw_width_yonishi": None,
        "runtime_window": window,
        "width_reconciled": window["width"],
        "evidence": [
            f"handler {info['handler_addr']} (decompile catalogo PppHandlerBehaviorCatalog, 139/139)",
            "fonte: opcode do catalogo fora do opcode_handler_map (entry nao mapeada no EXE)",
        ],
        "renames": [{"addr": info["handler_addr"], "old": info["handler_name"],
                     "new": f"FFX_PppHandler_{fam}", "proof": "padrao canonico C2 FULL"}],
        "notes": notes,
    }
    (OUT / f"{fam}.json").write_text(json.dumps(schema, indent=1, ensure_ascii=False) + "\n", encoding="utf-8")
    created2 += 1

print("schemas criados parte 2 (catalogo):", created2)
print("total schemas agora:", len(list(OUT.glob('*.json'))))

