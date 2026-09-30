#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Perfil das 234 DLLs NO_ROOT: tamanhos, nomes PS2, buckets, keywords."""
import json
import re
import statistics
from collections import Counter
from pathlib import Path

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
OUT = Path(__file__).resolve().parent

d = json.loads(AUDIT.read_text(encoding="utf-8"))
nr = [(k, v) for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]
sizes = sorted(v["data_section_size"] for _, v in nr)
n = len(sizes)


def pct(p):
    return sizes[int(p * (n - 1))]


print(f"n={n}")
print(f"min={sizes[0]} p10={pct(0.10)} p25={pct(0.25)} median={pct(0.50)} "
      f"p75={pct(0.75)} p90={pct(0.90)} max={sizes[-1]} mean={statistics.mean(sizes):.0f}")

buckets = Counter()
for s in sizes:
    if s < 65536:
        buckets["<64KB"] += 1
    elif s < 262144:
        buckets["64-256KB"] += 1
    elif s < 1048576:
        buckets["256KB-1MB"] += 1
    else:
        buckets[">=1MB"] += 1
print("size buckets:", dict(buckets))

names = Counter((v["name_ps2"] or "NO_NAME") for _, v in nr)
print("\ntop name_ps2 (30):")
for k, c in names.most_common(30):
    print(f"  {k}: {c}")

kw = Counter()
patterns = {
    "Summon": r"summon", "Overdrive": r"overdrive|od\b", "Event": r"^event|event ",
    "Death": r"death|dead", "Cutscene/Movie": r"cutscene|movie", "unk": r"^unk",
    "YuYevon": r"yevon", "Sin": r"\bsin\b", "Aeon": r"aeon", "Dome": r"dome",
    "Battle": r"battle", "Boss": r"boss", "FMV": r"fmv", "Mystery": r"mystery",
}
for _, v in nr:
    nm = v["name_ps2"] or ""
    for kk, pat in patterns.items():
        if re.search(pat, nm, re.I):
            kw[kk] += 1
print("\nkeyword counts (name_ps2):", dict(kw))

# nomes que NAO casam nenhum keyword acima
unk_kw = set()
for kk in patterns:
    unk_kw.update(re.findall(r"\w+", patterns[kk]))
miss = [(k, v["name_ps2"]) for k, v in nr if not any(
    re.search(pat, v["name_ps2"] or "", re.I) for pat in patterns.values())]
print(f"\n{len(miss)} com nome fora dos keywords; primeiros 40:")
for k, nm in miss[:40]:
    print(f"  {k}: {nm}")

# id range
ids = sorted(v["id"] for _, v in nr)
print(f"\nid range: {ids[0]}..{ids[-1]}")
gaps = [a for a, b in zip(ids, ids[1:]) if b - a > 1]
print(f"n gaps>1 no id: {len(gaps)}")
