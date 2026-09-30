#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Analisa relaxed_scan_raw.json: detalha candidatos pc_range/counts_range
e amostra DLLs sem candidato (None)."""
import json
from pathlib import Path

BASE = Path(__file__).resolve().parent
rows = json.loads((BASE / "relaxed_scan_raw.json").read_text(encoding="utf-8"))

sel = [r for r in rows if r["best"]["le_rel"].get("step") in ("pc_range", "counts_range")]
print("total com candidato pc_range/counts_range:", len(sel))
for r in sel[:60]:
    b = r["best"]["le_rel"]
    f = b["fields"]
    print(f"{r['dll']}: {b['step']} off=0x{b['best_off']:X} pc={f['pc']} "
          f"c2={f['c2']} c3={f['c3']} c4={f['c4']} "
          f"t1=0x{f['t1']:X} t2=0x{f['t2']:X} t3=0x{f['t3']:X} t4=0x{f['t4']:X}")

# distribuição de pc nos candidatos pc_range
import collections
pc_vals = collections.Counter()
for r in sel:
    f = r["best"]["le_rel"]["fields"]
    if r["best"]["le_rel"]["step"] == "pc_range":
        pc_vals[f["pc"]] += 1
print("\npc values (pc_range):", pc_vals.most_common(15))

c_vals = collections.Counter()
for r in sel:
    f = r["best"]["le_rel"]["fields"]
    if r["best"]["le_rel"]["step"] == "counts_range":
        for k in ("c2", "c3", "c4"):
            if f[k] > 256:
                c_vals[(k, f[k])] += 1
print("\ncounts >256:", c_vals.most_common(15))

# DLLs sem candidato le_rel
none_rows = [r for r in rows if r["best"]["le_rel"].get("step") is None]
print("\nDLLs sem candidato le_rel:", len(none_rows))
print([r["dll"] for r in none_rows[:30]])
