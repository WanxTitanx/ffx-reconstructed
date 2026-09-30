#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Root-by-backref: para cada DLL NO_ROOT com secoes orfas, procura um
header de root R cuja table1 (u32(R+16)) aponte para uma secao valida:
u32(R + t1) == secao - R. Coleta campos de R p/ diagnostico."""
import json
import struct
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\scripts")
from ppp_disassembler.layer_c_resource import (
    _u16, _u32, _valid_primary_section, _valid_counted_u32_table,
)

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent


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


def is_valid_section(data: bytes, off: int) -> bool:
    L = len(data)
    if off + 56 > L:
        return False
    sz = _u32(data, off)
    if sz < 56 or off + sz > L:
        return False
    r8 = _u32(data, off + 8)
    r12 = _u32(data, off + 12)
    if not (16 <= r8 < sz and 16 <= r12 < sz):
        return False
    if not _valid_counted_u32_table(data, off, sz, r8):
        return False
    if not _valid_counted_u32_table(data, off, sz, r12):
        return False
    return _valid_primary_section(data, off, 0)


def scan_one(dll_name: str) -> dict:
    raw = (CORPUS / dll_name).read_bytes()
    data = data_sec(raw)
    L = len(data)
    res = {"dll": dll_name, "data_len": L, "roots_alt": []}
    if data is None:
        res["error"] = "no_data_section"
        return res
    # set de offsets de secao valida
    sec_set = set()
    for off in range(0, L - 56, 4):
        if is_valid_section(data, off):
            sec_set.add(off)
    if not sec_set:
        res["n_sections"] = 0
        return res
    res["n_sections"] = len(sec_set)
    # varre R candidato: u32(R+16)=t1 aponta p/ entry que resolve p/ secao
    seen = set()
    for R in range(0, L - 32, 4):
        t1 = _u32(data, R + 16)
        if t1 < 32 or t1 % 4 or R + t1 + 4 > L:
            continue
        e = _u32(data, R + t1)
        if e < 32 or e % 4:
            continue
        S = R + e
        if S not in sec_set:
            continue
        pc = _u16(data, R + 6)
        c2 = _u16(data, R + 8); c3 = _u16(data, R + 10); c4 = _u16(data, R + 12)
        t2 = _u32(data, R + 20); t3 = _u32(data, R + 24); t4 = _u32(data, R + 28)
        if (R, t1, e) in seen:
            continue
        seen.add((R, t1, e))
        res["roots_alt"].append({
            "R": R, "pc": pc, "c2": c2, "c3": c3, "c4": c4,
            "t1": t1, "t2": t2, "t3": t3, "t4": t4,
            "first_section": S,
        })
    return res


def main() -> None:
    d = json.loads(AUDIT.read_text(encoding="utf-8"))
    nr = [k for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(scan_one, sorted(nr)))
    out = OUT / "root_backref_raw.json"
    out.write_text(json.dumps(rows, indent=1), encoding="utf-8")
    hits = [r for r in rows if r.get("roots_alt")]
    print(f"DLLs com backref de root: {len(hits)}/{len(rows)}")
    for r in hits[:20]:
        ra = r["roots_alt"][0]
        print(f"  {r['dll']}: R=0x{ra['R']:X} pc={ra['pc']} c2={ra['c2']} "
              f"c3={ra['c3']} c4={ra['c4']} t1=0x{ra['t1']:X} "
              f"t2=0x{ra['t2']:X} t3=0x{ra['t3']:X} t4=0x{ra['t4']:X} "
              f"sec=0x{ra['first_section']:X}")
    print("wrote", out)


if __name__ == "__main__":
    main()
