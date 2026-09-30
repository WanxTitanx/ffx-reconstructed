#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Detalha roots/secoes de DLLs especificas a partir do full scan."""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\scripts")))

BASE = Path(__file__).resolve().parent
rows = json.loads((BASE / "noroot_full_scan_raw.json").read_text(encoding="utf-8"))

for dll in ["magic_0665.dll", "magic_0563.dll", "magic_0071.dll",
            "magic_0018.dll", "magic_0045.dll"]:
    r = [x for x in rows if x["dll"] == dll][0]
    print(f"==== {dll} n_roots={r['n_roots']} data_len=0x{r['data_len']:X}")
    for rt in r["roots"]:
        print(f"  R=0x{rt['R']:X} pc={rt['pc']} c2={rt['c2']} c3={rt['c3']} "
              f"c4={rt['c4']} progs={rt['programs']} slots={rt['slots']} "
              f"dec=0x{rt['sz_declared_total']:X} eff=0x{rt['sz_effective_total']:X}")
        for s in rt["sections"]:
            tag = "TRUNC" if s["sz_declared"] > s["sz_effective"] else "fit  "
            print(f"    {tag} sec rel=0x{s['rel']:X} dec=0x{s['sz_declared']:X} "
                  f"eff=0x{s['sz_effective']:X}")
