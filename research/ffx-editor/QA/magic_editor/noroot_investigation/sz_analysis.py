#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""1) OPEN_OK: quantas secoes truncadas (evidencia do porque OPEN_OK vs NO_ROOT)
2) sz_declared_total vs virtual_size do .data (hipotese do sz virtual-inflado)
3) robustez: tolerant_root em dados aleatorios (falsos positivos)"""
import json
import os
import random
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\scripts")))
sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\noroot_investigation")))

from ppp_disassembler.layer_c_resource import _u16, _u32  # noqa: E402
from tolerant_parse import tolerant_root  # noqa: E402

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent


def pe_info(raw: bytes) -> tuple[int, int]:
    """Retorna (data_virtual_size, data_raw_size) do .data."""
    pe = struct.unpack_from("<I", raw, 0x3C)[0]
    nsec = struct.unpack_from("<H", raw, pe + 6)[0]
    optsz = struct.unpack_from("<H", raw, pe + 20)[0]
    base = pe + 24 + optsz
    for i in range(nsec):
        off = base + i * 40
        name = raw[off:off + 8].rstrip(b"\x00")
        if name == b".data":
            vs = struct.unpack_from("<I", raw, off + 8)[0]
            rs = struct.unpack_from("<I", raw, off + 16)[0]
            return vs, rs
    return 0, 0


def sec_stats(dll: str) -> dict:
    raw = (CORPUS / dll).read_bytes()
    vs, rs = pe_info(raw)
    L = rs
    n_trunc = 0
    n_fit = 0
    declared_total = 0
    for R in range(0, L - 32, 4):
        rt = tolerant_root(raw[0:0] or _data(raw), R) if False else None
        break
    return {"dll": dll, "vs": vs, "rs": rs}


def _data(raw: bytes) -> bytes:
    pe = struct.unpack_from("<I", raw, 0x3C)[0]
    nsec = struct.unpack_from("<H", raw, pe + 6)[0]
    optsz = struct.unpack_from("<H", raw, pe + 20)[0]
    base = pe + 24 + optsz
    for i in range(nsec):
        off = base + i * 40
        name = raw[off:off + 8].rstrip(b"\x00")
        if name == b".data":
            rs = struct.unpack_from("<I", raw, off + 16)[0]
            rp = struct.unpack_from("<I", raw, off + 20)[0]
            return raw[rp:rp + rs]
    return b""


def count_trunc(dll: str) -> dict:
    raw = (CORPUS / dll).read_bytes()
    data = _data(raw)
    L = len(data)
    vs, rs = pe_info(raw)
    n_trunc = 0
    n_fit = 0
    dec_total = 0
    eff_total = 0
    for R in range(0, L - 32, 4):
        rt = tolerant_root(data, R)
        if rt is None:
            continue
        for s in rt["sections"]:
            dec_total += s["sz_declared"]
            eff_total += s["sz_effective"]
            if s["sz_declared"] > s["sz_effective"]:
                n_trunc += 1
            else:
                n_fit += 1
    return {"dll": dll, "vs": vs, "rs": rs, "n_trunc": n_trunc,
            "n_fit": n_fit, "dec_total": dec_total, "eff_total": eff_total}


def main() -> None:
    d = json.loads(AUDIT.read_text(encoding="utf-8"))
    ok = [k for k, v in d["dlls"].items() if v.get("status") == "OPEN_OK"]
    nr = [k for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]

    import random
    random.seed(11)
    ok_s = random.sample(ok, 25)
    nr_s = random.sample(nr, 25)

    print("== OPEN_OK (25): trunc/fit, dec_total vs vs")
    ok_trunc = 0
    for dll in ok_s:
        r = count_trunc(dll)
        if r["n_trunc"]:
            ok_trunc += 1
        print(f"  {dll}: vs={r['vs']} rs={r['rs']} trunc={r['n_trunc']} "
              f"fit={r['n_fit']} dec=0x{r['dec_total']:X} eff=0x{r['eff_total']:X}")
    print(f"  -> OPEN_OK com >=1 secao truncada: {ok_trunc}/25")

    print("\n== NO_ROOT (25):")
    for dll in nr_s:
        r = count_trunc(dll)
        print(f"  {dll}: vs={r['vs']} rs={r['rs']} trunc={r['n_trunc']} "
              f"fit={r['n_fit']} dec=0x{r['dec_total']:X} eff=0x{r['eff_total']:X}")

    # robustez: dados aleatorios
    print("\n== robustez: tolerant_root em dados aleatorios")
    random.seed(99)
    fp = 0
    for trial in range(20):
        blob = bytes(random.getrandbits(8) for _ in range(400000))
        found = 0
        for R in range(0, len(blob) - 32, 4):
            if tolerant_root(blob, R) is not None:
                found += 1
                if found > 3:
                    break
        if found:
            fp += 1
            print(f"  trial {trial}: {found} falsos positivos")
    print(f"  trials com falso positivo: {fp}/20")


if __name__ == "__main__":
    main()
