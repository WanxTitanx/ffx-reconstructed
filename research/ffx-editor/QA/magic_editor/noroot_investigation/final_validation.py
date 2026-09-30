#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Validacao final: callbacks dentro do conteudo real; numeros consolidados
para o relatorio. Gera NOROOT_SUMMARY.json (apoio)."""
import json
import struct
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\scripts")))
sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\noroot_investigation")))

from ppp_disassembler.layer_c_resource import _u16, _u32  # noqa: E402
from ppp_disassembler.layer_c_slot import parse_ppp_slot  # noqa: E402
from tolerant_parse import data_sec, tolerant_root  # noqa: E402

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent
PPP_SLOT = 16


def validate(dll: str) -> dict:
    raw = (CORPUS / dll).read_bytes()
    data = data_sec(raw)
    L = len(data)
    res = {"dll": dll, "data_len": L, "roots": []}
    if data is None:
        return res
    for R in range(0, L - 32, 4):
        rt = tolerant_root(data, R)
        if rt is None:
            continue
        # boundaries reais por secao: fim = proxima secao ou L
        sec_abs = [R + _u32(data, R + rt["t1"] + 4 * i) for i in range(rt["pc"])]
        cb_out = 0
        cb_total = 0
        programs = 0
        slots = 0
        handlers = set()
        for idx, sec in enumerate(sec_abs):
            nxt = min([s for s in sec_abs if s > sec] or [L])
            declared = _u32(data, sec)
            eff = min(declared, L - sec)
            real = nxt - sec
            prog = sec + 16
            visited = set()
            while True:
                pr = prog - sec
                if pr in visited:
                    break
                visited.add(pr)
                sc = _u16(data, prog + 38)
                programs += 1
                slots += sc
                for si in range(sc):
                    so = prog + 40 + PPP_SLOT * si
                    slot = parse_ppp_slot(data, so)
                    handlers.add(slot.handler_table_index)
                    for cb in (slot.primary_callback_relative,
                               slot.secondary_callback_relative):
                        cb_total += 1
                        if cb >= real and cb < eff:
                            cb_out += 1
                nxtr = _u32(data, prog)
                if nxtr == 0 or nxtr <= pr:
                    break
                prog = sec + nxtr
        res["roots"].append({
            "R": R, "pc": rt["pc"], "programs": programs, "slots": slots,
            "handlers": sorted(handlers),
            "cb_total": cb_total, "cb_beyond_real": cb_out,
        })
    return res


def main() -> None:
    import concurrent.futures as cf
    d = json.loads(AUDIT.read_text(encoding="utf-8"))
    nr = [k for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]
    with cf.ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(validate, sorted(nr)))
    opened = [r for r in rows if r["roots"]]
    closed = [r for r in rows if not r["roots"]]

    n_multi = sum(1 for r in opened if len(r["roots"]) > 1)
    tot_progs = sum(x["programs"] for r in opened for x in r["roots"])
    tot_slots = sum(x["slots"] for r in opened for x in r["roots"])
    cb_out_total = sum(x["cb_beyond_real"] for r in opened for x in r["roots"])
    cb_total = sum(x["cb_total"] for r in opened for x in r["roots"])
    all_handlers = set()
    for r in opened:
        for x in r["roots"]:
            all_handlers.update(x["handlers"])
    max_h = max(all_handlers) if all_handlers else -1

    summary = {
        "total_no_root": len(rows),
        "open_with_tolerant_parser": len(opened),
        "closed_no_ppp": len(closed),
        "closed_dlls": [r["dll"] for r in closed],
        "multi_root_dlls": n_multi,
        "roots_total": sum(len(r["roots"]) for r in opened),
        "programs_total": tot_progs,
        "slots_total": tot_slots,
        "callback_total": cb_total,
        "callback_beyond_real_content": cb_out_total,
        "callback_beyond_pct": round(100 * cb_out_total / max(1, cb_total), 3),
        "handler_indices_distinct": len(all_handlers),
        "max_handler_index": max_h,
        "per_dll": rows,
    }
    out = OUT / "NOROOT_SUMMARY.json"
    out.write_text(json.dumps(summary, indent=1), encoding="utf-8")
    print(f"abertas={len(opened)} fechadas={len(closed)} multi-root={n_multi}")
    print(f"roots={summary['roots_total']} progs={tot_progs} slots={tot_slots}")
    print(f"callbacks={cb_total} alem do conteudo real={cb_out_total} "
          f"({summary['callback_beyond_pct']}%)")
    print(f"handlers distintos={len(all_handlers)} max={max_h}")
    print("fechadas:", [r["dll"] for r in closed])
    print("wrote", out)



if __name__ == "__main__":
    main()
