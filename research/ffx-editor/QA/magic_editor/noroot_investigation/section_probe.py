#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Probe estrutural PE das NO_ROOT vs OPEN_OK.

Para cada DLL: lista seções (nome, VS, RS), imports?, e roda o
find_ppp_resource_roots original em CADA seção (nao so .data).
"""
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\scripts")
from ppp_disassembler.layer_c_resource import find_ppp_resource_roots

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent

d = json.loads(AUDIT.read_text(encoding="utf-8"))
nr = [(k, v) for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]
ok = [(k, v) for k, v in d["dlls"].items() if v.get("status") == "OPEN_OK"]

# amostra: 24 NO_ROOT variadas + 8 OPEN_OK
import random
random.seed(7)
sample_nr = random.sample(nr, 24)
sample_ok = random.sample(ok, 8)


def sections(path: bytes | None, raw: bytes) -> list[dict]:
    if len(raw) < 0x40:
        return []
    pe = struct.unpack_from("<I", raw, 0x3C)[0]
    if raw[pe:pe + 2] != b"PE":
        return []
    nsec = struct.unpack_from("<H", raw, pe + 6)[0]
    optsz = struct.unpack_from("<H", raw, pe + 20)[0]
    base = pe + 24 + optsz
    secs = []
    for i in range(nsec):
        off = base + i * 40
        if off + 40 > len(raw):
            break
        name = raw[off:off + 8].rstrip(b"\x00").decode("ascii", "replace")
        vs = struct.unpack_from("<I", raw, off + 8)[0]
        rs = struct.unpack_from("<I", raw, off + 16)[0]
        rp = struct.unpack_from("<I", raw, off + 20)[0]
        secs.append({"name": name, "vs": vs, "rs": rs, "rp": rp,
                     "data": raw[rp:rp + rs]})
    return secs


def root_in_section(sec: dict) -> list[int]:
    try:
        return [r.offset for r in find_ppp_resource_roots(sec["data"])]
    except Exception:
        return []


def probe(dll_name: str) -> dict:
    p = CORPUS / dll_name
    raw = p.read_bytes()
    secs = sections(None, raw)
    out = {"dll": dll_name, "file_size": len(raw), "n_sections": len(secs),
           "sections": []}
    for s in secs:
        roots = root_in_section(s)
        out["sections"].append({
            "name": s["name"], "vs": s["vs"], "rs": s["rs"],
            "roots_found": roots[:5], "n_roots": len(roots),
        })
    return out


rows = []
for dll_name, _ in sample_nr:
    try:
        rows.append(probe(dll_name))
    except Exception as exc:
        rows.append({"dll": dll_name, "error": str(exc)})

print("=== NO_ROOT sample (24) ===")
for r in rows:
    secs = ", ".join(f"{s['name']}(vs={s['vs']},rs={s['rs']},roots={s['n_roots']})"
                     for s in r.get("sections", []))
    print(f"{r['dll']}: size={r.get('file_size')} nsec={r.get('n_sections')} | {secs}")

print("\n=== OPEN_OK sample (8) ===")
for dll_name, _ in sample_ok:
    try:
        r = probe(dll_name)
        secs = ", ".join(f"{s['name']}(vs={s['vs']},rs={s['rs']},roots={s['n_roots']})"
                         for s in r.get("sections", []))
        print(f"{r['dll']}: size={r.get('file_size')} nsec={r.get('n_sections')} | {secs}")
    except Exception as exc:
        print(f"{dll_name}: ERROR {exc}")

OUT.joinpath("section_probe_raw.json").write_text(
    json.dumps(rows, indent=1), encoding="utf-8")
print("\nwrote section_probe_raw.json")
