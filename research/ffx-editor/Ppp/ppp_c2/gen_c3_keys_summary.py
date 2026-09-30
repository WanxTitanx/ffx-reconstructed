#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Sumariza c3_roots_raw.json -> work/ppp_c2/c3_keys_summary.json + md.

Para cada DLL: lista de programas (prog_abs, key hex, slots, handlers draw usados).
"""
import json
from pathlib import Path

ROOT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work")
RAW = json.loads((ROOT / "c3_keys" / "c3_roots_raw.json").read_text(encoding="utf-8"))

summary = {}
for dll, res in RAW.items():
    progs = res.get("roots", [{}])[0].get("programs", [])
    if not progs:
        # tenta estrutura alternativa: roots[*].programs
        progs = []
        for r in res.get("roots", []):
            progs.extend(r.get("programs", []))
    rows = []
    for p in progs:
        rows.append({
            "prog_abs": p.get("prog_abs"),
            "key": p.get("key"),
            "key_hex": hex(p.get("key", 0)),
            "slots": p.get("slots"),
            "draw_slots": p.get("draw_slots"),
        })
    summary[dll] = {
        "root_count": res.get("root_count") or len(res.get("roots", [])),
        "program_count": len(rows),
        "programs": rows,
    }

(ROOT / "ppp_c2" / "c3_keys_summary.json").write_text(
    json.dumps(summary, indent=1, ensure_ascii=False), encoding="utf-8")

lines = ["# C3 Keys Summary — 2026-07-31 (derivado de c3_roots_raw.json)", ""]
for dll, s in summary.items():
    lines.append(f"## {dll} — {s['program_count']} programas, {s['root_count']} root(s)")
    lines.append("")
    lines.append("| prog_abs | key | slots | draw_slots |")
    lines.append("|---|---|---|---|")
    for p in s["programs"]:
        lines.append(f"| {p['prog_abs']} | {p['key_hex']} | {p['slots']} | {p['draw_slots']} |")
    lines.append("")
(ROOT / "ppp_c2" / "c3_keys_summary.md").write_text("\n".join(lines), encoding="utf-8")

print("OK: %d DLLs | total programas: %d" % (len(summary), sum(s["program_count"] for s in summary.values())))
