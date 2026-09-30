#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Analisa tolerant_parse_raw.json: fechadas, stats do walk, distribuicao."""
import json
import statistics
from collections import Counter
from pathlib import Path

BASE = Path(__file__).resolve().parent
rows = json.loads((BASE / "tolerant_parse_raw.json").read_text(encoding="utf-8"))

closed = [r for r in rows if r.get("n_roots", 0) == 0]
print("FECHADAS:", len(closed))
for r in closed:
    print(" ", r["dll"], r.get("data_len"))

w = [r["walk"] for r in rows if r.get("walk")]
progs = [x["programs"] for x in w]
slots = [x["slots"] for x in w]
h = [len(x["handlers"]) for x in w]
print("\nwalk stats: n =", len(w))
print(" programs: min", min(progs), "med", statistics.median(progs), "max", max(progs))
print(" slots: min", min(slots), "med", statistics.median(slots), "max", max(slots))
print(" handlers distintos: min", min(h), "med", statistics.median(h), "max", max(h))

c = Counter(r["n_roots"] for r in rows)
print("\nn_roots distribution:", dict(c))

print("\namostra de walks (12):")
for r in rows[:12]:
    if r.get("walk"):
        wd = r["walk"]
        rt = r["root"]
        print(f" {r['dll']}: R=0x{rt['R']:X} pc={rt['pc']} "
              f"progs={wd['programs']} slots={wd['slots']} "
              f"handlers={wd['handlers'][:12]}")

# handlers fora de 0..193 (range da dispatch table)
bad = []
for r in rows:
    if r.get("walk"):
        mx = max(r["walk"]["handlers"])
        if mx > 200:
            bad.append((r["dll"], mx, r["walk"]["handlers"][:6]))
print("\nwalks com handler > 200:", len(bad))
for dll, mx, hh in bad[:10]:
    print(f"  {dll}: max={mx} {hh}")
