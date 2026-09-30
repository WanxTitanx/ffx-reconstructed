#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""1) Confirma hipotese SeSep (som) nas 5 fechadas vs OPEN_OK.
2) Mede sub-classificacao: secoes com sz que cabe vs sz truncado nas 229.
3) Conta TODOS os roots por DLL (sem break) p/ JSON final."""
import json
import re
import struct
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\scripts")))
sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\noroot_investigation")))

from ppp_disassembler.layer_c_resource import _u16, _u32  # noqa: E402
from tolerant_parse import data_sec, tolerant_root, tolerant_section, walk_root  # noqa: E402

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent


def sese_probe(dll: str) -> dict:
    raw = (CORPUS / dll).read_bytes()
    data = data_sec(raw)
    n = data.count(b"SeSep") if data else 0
    ctx = []
    if n and data:
        i = data.find(b"SeSep")
        ctx.append(data[max(0, i - 16):i + 32].hex(" "))
    return {"dll": dll, "n_seSep": n, "ctx": ctx}


def full_scan(dll_name: str) -> dict:
    raw = (CORPUS / dll_name).read_bytes()
    data = data_sec(raw)
    L = len(data)
    res = {"dll": dll_name, "data_len": L}
    if data is None:
        res["error"] = "no_data"
        return res
    roots = []
    for R in range(0, L - 32, 4):
        rt = tolerant_root(data, R)
        if rt is not None:
            roots.append(rt)
    res["n_roots"] = len(roots)
    res["roots"] = []
    for rt in roots:
        w = walk_root(data, rt["R"], rt)
        truncated = any(
            s["sz_declared"] > s["sz_effective"] for s in rt["sections"])
        res["roots"].append({
            "R": rt["R"],
            "pc": rt["pc"], "c2": rt["c2"], "c3": rt["c3"], "c4": rt["c4"],
            "t1": rt["t1"], "t2": rt["t2"], "t3": rt["t3"], "t4": rt["t4"],
            "n_sections": len(rt["sections"]),
            "any_sz_truncated": truncated,
            "sz_declared_total": sum(s["sz_declared"] for s in rt["sections"]),
            "sz_effective_total": sum(s["sz_effective"] for s in rt["sections"]),
            "programs": w["programs"], "slots": w["slots"],
            "handlers": w["handlers"], "first_key": w["first_key"],
        })
    return res


def main() -> None:
    # 1) SeSep probe
    closed5 = ["magic_0052.dll", "magic_0053.dll", "magic_0064.dll",
               "magic_0065.dll", "magic_0709.dll"]
    print("== SeSep nas 5 fechadas")
    for dll in closed5:
        print("  ", sese_probe(dll))
    d = json.loads(AUDIT.read_text(encoding="utf-8"))
    ok20 = [k for k, v in list(d["dlls"].items())
            if v.get("status") == "OPEN_OK"][:20]
    nr20 = [k for k, v in list(d["dlls"].items())
            if v.get("status") == "NO_ROOT"][:20]
    print("\n== SeSep em amostra OPEN_OK (20):")
    for dll in ok20:
        p = sese_probe(dll)
        if p["n_seSep"]:
            print("  ", p)
    print("== SeSep em amostra NO_ROOT (20):")
    for dll in nr20:
        p = sese_probe(dll)
        if p["n_seSep"]:
            print("  ", p)

    # 2/3) scan completo das 234
    nr = [k for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(full_scan, sorted(nr)))
    opened = [r for r in rows if r.get("n_roots", 0) > 0]
    trunc = [r for r in opened if any(x["any_sz_truncated"] for x in r["roots"])]
    fit = [r for r in opened if not any(x["any_sz_truncated"] for x in r["roots"])]
    print(f"\n== 234: abertas={len(opened)} (truncadas={len(trunc)} "
          f"sz-cabe={len(fit)}) fechadas={len(rows)-len(opened)}")
    # totais
    tot_progs = sum(x["programs"] for r in opened for x in r["roots"])
    tot_slots = sum(x["slots"] for r in opened for x in r["roots"])
    print(f"programas totais (tolerante): {tot_progs} | slots: {tot_slots}")
    out = OUT / "noroot_full_scan_raw.json"
    out.write_text(json.dumps(rows, indent=1), encoding="utf-8")
    print("wrote", out)


if __name__ == "__main__":
    main()
