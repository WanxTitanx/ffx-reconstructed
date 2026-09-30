#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Triagem C2 de TODAS as familias PPP: cruza opcode_handler_map (118 familias/329 rows)
com PppHandlerBehaviorCatalog (payload_indexes) e os schemas existentes.

Output: work/ppp_c2/FAMILY_C2_TRIAGE_20260731.json + resumo no stdout.
"""
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(r"C:\Users\wande\Documents\ffx-editor-main")
MAP = json.loads((ROOT / "work/ppp_c2/opcode_handler_map.json").read_text(encoding="utf-8"))
CAT = json.loads((ROOT / "work/ppp_handlers/PppHandlerBehaviorCatalog.json").read_text(encoding="utf-8"))
SCHEMA_DIR = ROOT / "work/ppp_c2/families"

schemas = {}
for f in SCHEMA_DIR.glob("*.json"):
    d = json.loads(f.read_text(encoding="utf-8-sig"))
    schemas[d["opcode"]] = d

# handler addr -> payload_indexes (do catalogo)
cat_by_handler = {}
for addr, rec in CAT["handlers"].items():
    cat_by_handler[int(addr, 16)] = rec

# familia -> rows
fam_rows = defaultdict(list)
for r in MAP["rows"]:
    fam_rows[r["opcode"]].append(r)

triage = {}
for fam, rows in sorted(fam_rows.items()):
    # row "principal": primeira entry da tabela 0 (ou a que tiver handler_ptr)
    row0 = next((r for r in rows if r["table"] == 0), rows[0])
    handler_ptr = row0.get("handler_ptr")
    h = int(handler_ptr, 16) if handler_ptr else None
    cat = cat_by_handler.get(h)
    payload = bool(cat and cat.get("payload_indexes"))
    has_schema = fam in schemas
    if has_schema:
        status = "FECHADO"
    elif payload:
        status = "FALTA_SCHEMA_PAYLOAD"
    else:
        status = "FALTA_SCHEMA_SEM_PAYLOAD"
    triage[fam] = {
        "handler_addr": handler_ptr,
        "handler_name": row0.get("handler_name"),
        "handler_slot": row0.get("handler_slot"),
        "entry_addr": row0.get("entry_addr"),
        "aux_1c": row0.get("aux_1c"),
        "aux_20": row0.get("aux_20"),
        "n_aliases": len(rows),
        "payload_indexes": cat.get("payload_indexes") if cat else None,
        "reads_payload": payload,
        "has_schema": has_schema,
        "status": status,
    }

out = {
    "meta": {
        "stamp": "20260731",
        "n_families": len(triage),
        "n_rows": len(MAP["rows"]),
        "n_handlers_catalog": len(cat_by_handler),
    },
    "families": triage,
}
(ROOT / "work/ppp_c2/FAMILY_C2_TRIAGE_20260731.json").write_text(
    json.dumps(out, indent=1, ensure_ascii=False), encoding="utf-8")

from collections import Counter
c = Counter(t["status"] for t in triage.values())
print("familias:", len(triage), "| status:", dict(c))
print("FALTA_SCHEMA_PAYLOAD:", sorted(f for f, t in triage.items() if t["status"] == "FALTA_SCHEMA_PAYLOAD"))
print("FALTA_SCHEMA_SEM_PAYLOAD:", len([f for f, t in triage.items() if t["status"] == "FALTA_SCHEMA_SEM_PAYLOAD"]))
