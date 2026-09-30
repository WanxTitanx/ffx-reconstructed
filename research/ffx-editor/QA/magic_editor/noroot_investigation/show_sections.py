#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Dump raiz: secoes individuais (rel, sz_declared, conteudo real estimado)
para DLLs especificas."""
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\scripts")))
sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\noroot_investigation")))

from ppp_disassembler.layer_c_resource import _u16, _u32  # noqa: E402
from tolerant_parse import data_sec, tolerant_root  # noqa: E402

CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")


def show(dll: str) -> None:
    raw = (CORPUS / dll).read_bytes()
    data = data_sec(raw)
    L = len(data)
    print(f"==== {dll} data_len=0x{L:X}")
    rt = None
    for R in range(0, L - 32, 4):
        rt = tolerant_root(data, R)
        if rt is not None:
            break
    if rt is None:
        print("  SEM ROOT")
        return
    R = rt["R"]
    print(f"  R=0x{R:X} pc={rt['pc']} c2={rt['c2']} c3={rt['c3']} c4={rt['c4']} "
          f"t1=0x{rt['t1']:X}")
    for i in range(rt["pc"]):
        rel = _u32(data, R + rt["t1"] + 4 * i)
        sec = R + rel
        dec = _u32(data, sec)
        eff = min(dec, L - sec)
        # fim real estimado: proxima secao ou fim do .data
        nxt = None
        for j in range(rt["pc"]):
            if j == i:
                continue
            r2 = _u32(data, R + rt["t1"] + 4 * j)
            if r2 > rel and (nxt is None or r2 < nxt):
                nxt = r2
        real_end = (R + nxt) if nxt is not None else L
        real_sz = real_end - sec
        print(f"    sec[{i}] rel=0x{rel:X} abs=0x{sec:X} dec=0x{dec:X} "
              f"eff=0x{eff:X} conteudo_real~0x{real_sz:X}")


for dll in ["magic_0665.dll", "magic_0071.dll", "magic_0018.dll",
            "magic_0563.dll"]:
    show(dll)
