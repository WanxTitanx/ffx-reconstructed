#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Mede contribuicao isolada: (a) estrito + so sz-truncado (pc<=64, counts<=256)
vs (b) tolerante completo. Tambem: DLLs multi-root + stats de secoes."""
import json
import struct
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\scripts")))
sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\noroot_investigation")))

from ppp_disassembler.layer_c_resource import _u16, _u32, _valid_counted_u32_table  # noqa: E402
from ppp_disassembler.layer_c_slot import parse_ppp_slot  # noqa: E402
from tolerant_parse import data_sec  # noqa: E402

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent
PPP_SLOT = 16


def strict_with_truncated_sz(data: bytes, R: int) -> bool:
    """Parser ESTRITO + unica mudanca: sz truncado. pc<=64, counts<=256."""
    L = len(data)
    pc = _u16(data, R + 6)
    c2 = _u16(data, R + 8); c3 = _u16(data, R + 10); c4 = _u16(data, R + 12)
    t1 = _u32(data, R + 16); t2 = _u32(data, R + 20)
    t3 = _u32(data, R + 24); t4 = _u32(data, R + 28)
    if not (0 < pc <= 64):
        return False
    if any(c > 256 for c in (c2, c3, c4)):
        return False
    if any(r < 32 or r % 4 for r in (t1, t2, t3, t4)):
        return False
    if tuple(sorted((t1, t2, t3, t4))) != (t1, t2, t3, t4):
        return False
    if any(R + r >= L for r in (t1, t2, t3, t4)):
        return False
    prim = [_u32(data, R + t1 + 4 * i) for i in range(pc)]
    if any(r < 32 or r % 4 for r in prim):
        return False
    for rel in prim:
        sec = R + rel
        if sec + 56 > L:
            return False
        declared = _u32(data, sec)
        if declared < 56:
            return False
        sz = min(declared, L - sec)  # <-- UNICA mudanca
        if sz < 56:
            return False
        for ct_off in (8, 12):
            r = _u32(data, sec + ct_off)
            if r < 16 or r + 4 > sz:
                return False
            tbl = sec + r
            cnt = _u32(data, tbl)
            if cnt > 4096 or r + 4 + 4 * cnt > sz:
                return False
            if any(_u32(data, tbl + 4 + 4 * i) >= sz for i in range(cnt)):
                return False
        prog = sec + 16
        visited = set()
        found = False
        while True:
            pr = prog - sec
            if pr in visited or prog + 40 > sec + sz:
                return False
            visited.add(pr)
            sc = int.from_bytes(data[prog + 38:prog + 40], "little", signed=True)
            if not (0 <= sc <= 256):
                return False
            if prog + 40 + PPP_SLOT * sc > sec + sz:
                return False
            for si in range(sc):
                so = prog + 40 + PPP_SLOT * si
                slot = parse_ppp_slot(data, so)
                if slot.handler_table_index > 255:
                    return False
                if slot.primary_callback_relative >= sz:
                    return False
                if slot.secondary_callback_relative >= sz:
                    return False
                found = True
            nxt = _u32(data, prog)
            if nxt == 0:
                if not found:
                    return False
                break
            if nxt <= pr or nxt % 4:
                return False
            prog = sec + nxt
    for name, cnt, base, stride, chk in (
        ("a2", c2, t2, 32, (20, 24, 28)),
        ("a3", c3, t3, 4, (0,)),
        ("a4", c4, t4, 8, (4,)),
    ):
        tab = R + base
        if tab + stride * cnt > L:
            return False
        for i in range(cnt):
            for part in chk:
                if _u32(data, tab + stride * i + part) >= L - R:
                    return False
    return True


def scan_one(dll_name: str) -> dict:
    raw = (CORPUS / dll_name).read_bytes()
    data = data_sec(raw)
    L = len(data)
    n_strict = 0
    first_R = None
    for R in range(0, L - 32, 4):
        if strict_with_truncated_sz(data, R):
            n_strict += 1
            if first_R is None:
                first_R = R
            if n_strict >= 8:
                break
    return {"dll": dll_name, "n_roots_strict_trunc": n_strict,
            "first_R": first_R}


def main() -> None:
    d = json.loads(AUDIT.read_text(encoding="utf-8"))
    nr = [k for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(scan_one, sorted(nr)))
    opened = [r for r in rows if r["n_roots_strict_trunc"] > 0]
    print(f"abrem com ESTRITO+sz-truncado (pc<=64, counts<=256): "
          f"{len(opened)}/{len(rows)}")
    closed = [r["dll"] for r in rows if r["n_roots_strict_trunc"] == 0]
    print("fechadas nesse modo:", closed)
    OUT.joinpath("strict_trunc_raw.json").write_text(
        json.dumps(rows, indent=1), encoding="utf-8")


if __name__ == "__main__":
    main()
