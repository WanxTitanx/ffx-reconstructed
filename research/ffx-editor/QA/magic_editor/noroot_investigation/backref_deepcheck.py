#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Para cada root alternativo (backref), roda o deep_check do parser
original e reporta o step exato de falha + dump dos bytes do root."""
import json
import struct
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\scripts")))
sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\noroot_investigation")))

from relaxed_scan import data_sec, deep_check, STEP_RANK  # noqa: E402

CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent
backrefs = json.loads((OUT / "root_backref_raw.json").read_text(encoding="utf-8"))

hits = [r for r in backrefs if r.get("roots_alt")]
print(f"DLLs com backref: {len(hits)}")

steps = Counter()
detail = []
for r in hits:
    dll = r["dll"]
    data = data_sec((CORPUS / dll).read_bytes())
    best_step = None
    best_fields = None
    best_R = None
    for ra in r["roots_alt"]:
        R = ra["R"]
        ok, step, fields = deep_check(data, R)
        if ok:
            best_step = "OK"
            best_fields = fields
            best_R = R
            break
        rank = STEP_RANK.get(step, 99)
        if best_step is None or rank > STEP_RANK.get(best_step, 99):
            best_step = step
            best_fields = fields
            best_R = R
    steps[best_step] += 1
    detail.append({"dll": dll, "R": best_R, "step": best_step,
                   "fields": best_fields})

print("\nsteps de falha nos roots alternativos:")
for k, v in steps.most_common():
    print(f"  {k}: {v}")

# detalhe das DLLs OK e das que falham em aux
print("\ndetalhe:")
for d in detail:
    if d["step"] in ("OK", "aux2_rel", "aux3_rel", "aux4_rel", "aux2_oob",
                     "aux3_oob", "aux4_oob", "ct8_rel", "ct12_rel", "cb_prim",
                     "cb_sec", "next_rel", "slot_count_range", "slots_oob",
                     "handler_idx", "prog_bounds"):
        f = d["fields"] or {}
        print(f"  {d['dll']}: R=0x{d['R']:X} step={d['step']} "
              f"pc={f.get('pc')} c2={f.get('c2')} c3={f.get('c3')} c4={f.get('c4')} "
              f"t1=0x{f.get('t1')} t2=0x{f.get('t2')} t3=0x{f.get('t3')} t4=0x{f.get('t4')}")

OUT.joinpath("backref_deepcheck_raw.json").write_text(
    json.dumps(detail, indent=1), encoding="utf-8")
