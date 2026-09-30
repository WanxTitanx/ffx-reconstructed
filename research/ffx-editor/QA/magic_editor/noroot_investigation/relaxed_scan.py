#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Relaxed root scan nas 234 NO_ROOT.

Para cada DLL:
  1. extrai .data (raw)
  2. confirma 0 roots com o finder original
  3. pre-filtro numpy (3 modos: LE-relativo, LE-VA, BE)
  4. deep_check instrumentado no melhor candidato -> PRIMEIRA falha
  5. guarda: melhor candidato por modo + step de falha + dump dos campos

Saida: relaxed_scan_raw.json
"""
import json
import struct
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

import numpy as np

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\scripts")
from ppp_disassembler.layer_c_resource import find_ppp_resource_roots

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent

VA_LO = 0x10000000
VA_HI = 0x11000000


def data_sec(raw: bytes) -> bytes | None:
    if len(raw) < 0x40:
        return None
    pe = struct.unpack_from("<I", raw, 0x3C)[0]
    if raw[pe:pe + 2] != b"PE":
        return None
    nsec = struct.unpack_from("<H", raw, pe + 6)[0]
    optsz = struct.unpack_from("<H", raw, pe + 20)[0]
    base = pe + 24 + optsz
    for i in range(nsec):
        off = base + i * 40
        name = raw[off:off + 8].rstrip(b"\x00")
        if name != b".data":
            continue
        rs = struct.unpack_from("<I", raw, off + 16)[0]
        rp = struct.unpack_from("<I", raw, off + 20)[0]
        return raw[rp:rp + rs]
    return None


# ---------------------------------------------------------------------------
# deep check instrumentado (LE, relativo) — mesma ordem do parser original
# ---------------------------------------------------------------------------
def deep_check(data: bytes, off: int) -> tuple[bool, str, dict]:
    L = len(data)
    def u16(o): return int.from_bytes(data[o:o + 2], "little")
    def u32(o): return int.from_bytes(data[o:o + 4], "little")

    pc = u16(off + 6); c2 = u16(off + 8); c3 = u16(off + 10); c4 = u16(off + 12)
    t1 = u32(off + 16); t2 = u32(off + 20); t3 = u32(off + 24); t4 = u32(off + 28)
    fields = {"pc": pc, "c2": c2, "c3": c3, "c4": c4,
              "t1": t1, "t2": t2, "t3": t3, "t4": t4}
    if not (0 < pc <= 64):
        return False, "pc_range", fields
    if any(c > 256 for c in (c2, c3, c4)):
        return False, "counts_range", fields
    if any(r < 32 for r in (t1, t2, t3, t4)):
        return False, "tbl_ge32", fields
    if any(r % 4 for r in (t1, t2, t3, t4)):
        return False, "tbl_align", fields
    if tuple(sorted((t1, t2, t3, t4))) != (t1, t2, t3, t4):
        return False, "tbl_unsorted", fields
    if any(off + r >= L for r in (t1, t2, t3, t4)):
        return False, "tbl_oob", fields

    prim = [u32(off + t1 + 4 * i) for i in range(pc)]
    if any(r < 32 for r in prim):
        return False, "prim_rel_ge32", fields
    if any(r % 4 for r in prim):
        return False, "prim_rel_align", fields
    for pi, rel in enumerate(prim):
        sec = off + rel
        if sec + 56 > L:
            return False, "prim_sec_bounds", fields
        sz = u32(sec)
        if sz < 56 or sec + sz > L:
            return False, "prim_sec_size", fields
        for ct_off in (8, 12):
            r = u32(sec + ct_off)
            if r < 16 or r + 4 > sz:
                return False, f"ct{ct_off}_bad", fields
            tbl = sec + r
            cnt = u32(tbl)
            if cnt > 4096 or r + 4 + 4 * cnt > sz:
                return False, f"ct{ct_off}_count", fields
            if any(u32(tbl + 4 + 4 * i) >= sz for i in range(cnt)):
                return False, f"ct{ct_off}_rel", fields
        prog = sec + 16
        visited = set()
        found = False
        while True:
            pr = prog - sec
            if pr in visited or prog + 40 > sec + sz:
                return False, "prog_bounds", fields
            visited.add(pr)
            sc = int.from_bytes(data[prog + 38:prog + 40], "little", signed=True)
            if not (0 <= sc <= 256):
                return False, "slot_count_range", fields
            if prog + 40 + 16 * sc > sec + sz:
                return False, "slots_oob", fields
            for si in range(sc):
                so = prog + 40 + 16 * si
                h = u32(so)
                if h > 255:
                    return False, "handler_idx", fields
                cb1 = u32(so + 8); cb2 = u32(so + 12)
                if cb1 >= sz:
                    return False, "cb_prim", fields
                if cb2 >= sz:
                    return False, "cb_sec", fields
                found = True
            nxt = u32(prog)
            if nxt == 0:
                if not found:
                    return False, "no_slots", fields
                break
            if nxt <= pr or nxt % 4:
                return False, "next_rel", fields
            prog = sec + nxt
    # aux tables
    for name, cnt, base, stride, chk in (
        ("aux2", c2, t2, 32, (20, 24, 28)),
        ("aux3", c3, t3, 4, (0,)),
        ("aux4", c4, t4, 8, (4,)),
    ):
        tab = off + base
        if tab + stride * cnt > L:
            return False, f"{name}_oob", fields
        for i in range(cnt):
            for part in chk:
                if u32(tab + stride * i + part) >= L - off:
                    return False, f"{name}_rel", fields
    return True, "OK", fields



def prefilter(data: bytes, mode: str) -> list[int]:
    """Candidatos por pre-filtro numpy. mode: le_rel | le_va | be."""
    L = len(data)
    if L < 64:
        return []
    if mode == "be":
        a32 = np.frombuffer(data, dtype=">u4")
        a16 = np.frombuffer(data, dtype=">u2")
        t_lo, t_hi = 4, L
    elif mode == "le_va":
        a32 = np.frombuffer(data, dtype="<u4")
        a16 = np.frombuffer(data, dtype="<u2")
        t_lo, t_hi = VA_LO, VA_HI
    else:
        a32 = np.frombuffer(data, dtype="<u4")
        a16 = np.frombuffer(data, dtype="<u2")
        t_lo, t_hi = 4, L
    n = min(len(a16) // 8, len(a32) // 8)
    if n < 8:
        return []
    a16t = a16[:8 * n].reshape(-1, 8)
    a32t = a32[:8 * n].reshape(-1, 8)
    pc = a16t[:, 3]; c2 = a16t[:, 4]; c3 = a16t[:, 5]; c4 = a16t[:, 6]
    t1 = a32t[:, 4]; t2 = a32t[:, 5]; t3 = a32t[:, 6]; t4 = a32t[:, 7]
    m = (
        (pc >= 1) & (pc <= 4096)
        & (c2 <= 4096) & (c3 <= 4096) & (c4 <= 4096)
        & (t1 >= t_lo) & (t1 < t_hi) & (t1 % 4 == 0)
        & (t2 >= t_lo) & (t2 < t_hi) & (t2 % 4 == 0)
        & (t3 >= t_lo) & (t3 < t_hi) & (t3 % 4 == 0)
        & (t4 >= t_lo) & (t4 < t_hi) & (t4 % 4 == 0)
    )
    idx = np.nonzero(m)[0]
    return [int(i) * 32 for i in idx]


STEP_RANK = {
    "pc_range": 1, "counts_range": 2, "tbl_ge32": 3, "tbl_align": 4,
    "tbl_unsorted": 5, "tbl_oob": 6, "prim_rel_ge32": 7, "prim_rel_align": 8,
    "prim_sec_bounds": 9, "prim_sec_size": 10, "ct8_bad": 11, "ct8_count": 12,
    "ct8_rel": 13, "ct12_bad": 14, "ct12_count": 15, "ct12_rel": 16,
    "prog_bounds": 17, "slot_count_range": 18, "slots_oob": 19,
    "handler_idx": 20, "cb_prim": 21, "cb_sec": 22, "no_slots": 23,
    "next_rel": 24, "aux2_oob": 25, "aux2_rel": 26, "aux3_oob": 27,
    "aux3_rel": 28, "aux4_oob": 29, "aux4_rel": 30, "OK": 31,
}


def scan_one(dll_name: str) -> dict:
    raw = (CORPUS / dll_name).read_bytes()
    data = data_sec(raw)
    res = {"dll": dll_name, "data_len": len(data) if data else 0}
    if data is None:
        res["error"] = "no_data_section"
        return res
    res["orig_roots"] = len(find_ppp_resource_roots(data))
    best = {}
    for mode in ("le_rel", "le_va", "be"):
        cands = prefilter(data, mode)
        best_step = None
        best_fields = None
        best_off = None
        n_cands = len(cands)
        for off in cands[:2000]:
            ok, step, fields = deep_check(data, off)
            rank = STEP_RANK.get(step, 99)
            cur = STEP_RANK.get(best_step, 99) if best_step else -1
            if rank > cur or (ok and best_step != "OK"):
                best_step = step
                best_fields = fields
                best_off = off
            if ok:
                break
        best[mode] = {
            "n_cands": n_cands,
            "best_off": best_off,
            "step": best_step,
            "fields": best_fields,
        }
    res["best"] = best
    return res


def main() -> None:
    d = json.loads(AUDIT.read_text(encoding="utf-8"))
    nr = [k for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]
    print(f"scanning {len(nr)} DLLs...", flush=True)
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(scan_one, sorted(nr)))
    out = OUT / "relaxed_scan_raw.json"
    out.write_text(json.dumps(rows, indent=1), encoding="utf-8")
    print(f"wrote {out}", flush=True)


if __name__ == "__main__":
    main()
