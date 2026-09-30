#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Parser tolerante: revalida os roots alternativos com section_size
truncado ao espaco disponivel no .data (min(sz, L - sec)). Se a seccao
valida, faz walk completo: programas, slots, handler indices, callbacks.
Mede quantas das 234 NO_ROOT abrem com essa heuristica."""
import json
import struct
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\scripts")
from ppp_disassembler.layer_c_resource import _u16, _u32
from ppp_disassembler.layer_c_slot import parse_ppp_slot

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent
PPP_SLOT = 16


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


def tolerant_section(data: bytes, sec: int) -> tuple[bool, int, str]:
    """Valida secao com sz truncado. Retorna (ok, size_efetivo, motivo)."""
    L = len(data)
    if sec + 56 > L:
        return False, 0, "bounds"
    declared = _u32(data, sec)
    if declared < 56:
        return False, 0, "sz<56"
    sz = min(declared, L - sec)
    if sz < 56:
        return False, 0, "trunc<56"
    for ct_off in (8, 12):
        r = _u32(data, sec + ct_off)
        if r < 16 or r + 4 > sz:
            return False, 0, f"ct{ct_off}"
        tbl = sec + r
        cnt = _u32(data, tbl)
        if cnt > 4096 or r + 4 + 4 * cnt > sz:
            return False, 0, f"ct{ct_off}_cnt"
        if any(_u32(data, tbl + 4 + 4 * i) >= sz for i in range(cnt)):
            return False, 0, f"ct{ct_off}_rel"
    prog = sec + 16
    visited = set()
    found = False
    while True:
        pr = prog - sec
        if pr in visited or prog + 40 > sec + sz:
            return False, 0, "prog_bounds"
        visited.add(pr)
        sc = int.from_bytes(data[prog + 38:prog + 40], "little", signed=True)
        if not (0 <= sc <= 256):
            return False, 0, "slot_count"
        if prog + 40 + PPP_SLOT * sc > sec + sz:
            return False, 0, "slots_oob"
        for si in range(sc):
            so = prog + 40 + PPP_SLOT * si
            slot = parse_ppp_slot(data, so)
            if slot.handler_table_index > 255:
                return False, 0, "handler"
            if slot.primary_callback_relative >= sz:
                return False, 0, "cb1"
            if slot.secondary_callback_relative >= sz:
                return False, 0, "cb2"
            found = True
        nxt = _u32(data, prog)
        if nxt == 0:
            if not found:
                return False, 0, "no_slots"
            break
        if nxt <= pr or nxt % 4:
            return False, 0, "next"
        prog = sec + nxt
    return True, sz, "OK"


def tolerant_root(data: bytes, R: int) -> dict | None:
    """Valida root alternativo com secoes tolerantes + aux tables."""
    L = len(data)
    pc = _u16(data, R + 6)
    c2 = _u16(data, R + 8); c3 = _u16(data, R + 10); c4 = _u16(data, R + 12)
    t1 = _u32(data, R + 16); t2 = _u32(data, R + 20)
    t3 = _u32(data, R + 24); t4 = _u32(data, R + 28)
    if not (0 < pc <= 256):
        return None
    if any(c > 4096 for c in (c2, c3, c4)):
        return None
    if any(r < 32 or r % 4 for r in (t1, t2, t3, t4)):
        return None
    if tuple(sorted((t1, t2, t3, t4))) != (t1, t2, t3, t4):
        return None
    if any(R + r >= L for r in (t1, t2, t3, t4)):
        return None
    prim = [_u32(data, R + t1 + 4 * i) for i in range(pc)]
    if any(r < 32 or r % 4 for r in prim):
        return None
    secs = []
    for rel in prim:
        ok, sz, why = tolerant_section(data, R + rel)
        if not ok:
            return None
        secs.append({"rel": rel, "sz_declared": _u32(data, R + rel),
                     "sz_effective": sz})
    for name, cnt, base, stride, chk in (
        ("aux2", c2, t2, 32, (20, 24, 28)),
        ("aux3", c3, t3, 4, (0,)),
        ("aux4", c4, t4, 8, (4,)),
    ):
        tab = R + base
        if tab + stride * cnt > L:
            return None
        for i in range(cnt):
            for part in chk:
                if _u32(data, tab + stride * i + part) >= L - R:
                    return None
    return {"R": R, "pc": pc, "c2": c2, "c3": c3, "c4": c4,
            "t1": t1, "t2": t2, "t3": t3, "t4": t4, "sections": secs}


def walk_root(data: bytes, R: int, root: dict) -> dict:
    """Walk programas/slots do root tolerante (mesma semantica do audit)."""
    pc = root["pc"]
    t1 = root["t1"]
    programs = 0
    slots = 0
    handlers = set()
    first_key = None
    for i in range(pc):
        rel = _u32(data, R + t1 + 4 * i)
        sec = R + rel
        declared = _u32(data, sec)
        sz = min(declared, len(data) - sec)
        prog = sec + 16
        visited = set()
        while True:
            pr = prog - sec
            if pr in visited:
                break
            visited.add(pr)
            sc = _u16(data, prog + 38)
            if first_key is None:
                first_key = _u32(data, prog + 4)
            programs += 1
            slots += sc
            for si in range(sc):
                so = prog + 40 + PPP_SLOT * si
                h = _u32(data, so)
                handlers.add(h)
            nxt = _u32(data, prog)
            if nxt == 0 or nxt <= pr:
                break
            prog = sec + nxt
    return {"programs": programs, "slots": slots,
            "handlers": sorted(handlers), "first_key": first_key}


def scan_one(dll_name: str) -> dict:
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
            if len(roots) >= 4:
                break
    res["n_roots"] = len(roots)
    if roots:
        r0 = roots[0]
        res["root"] = r0
        res["walk"] = walk_root(data, r0["R"], r0)
    return res


def main() -> None:
    d = json.loads(AUDIT.read_text(encoding="utf-8"))
    nr = [k for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]
    print(f"scanning {len(nr)}...", flush=True)
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(scan_one, sorted(nr)))
    opened = [r for r in rows if r.get("n_roots", 0) > 0]
    print(f"DLLs que abrem com parser tolerante: {len(opened)}/{len(rows)}")
    out = OUT / "tolerant_parse_raw.json"
    out.write_text(json.dumps(rows, indent=1), encoding="utf-8")
    print("wrote", out)


if __name__ == "__main__":
    main()
