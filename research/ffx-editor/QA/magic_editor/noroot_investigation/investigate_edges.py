#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Investiga: (1) falso positivo magic_0244@0x1150, (2) root perdido
magic_0069@67552, (3) as 5 DLLs fechadas."""
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\scripts")))
sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\noroot_investigation")))

from ppp_disassembler.layer_c_resource import _u16, _u32  # noqa: E402
from tolerant_parse import data_sec, tolerant_root, tolerant_section  # noqa: E402

CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent


def dump(data, off, n=8):
    for o in range(off, off + n * 16, 16):
        print(f"    +0x{o:06X}: {data[o:o+16].hex(' ')}")


# --- 1. magic_0244 falso positivo em 0x1150 -------------------------------
print("=== magic_0244: R=0x1150 (tolerante) vs R=0x250A0 (audit)")
raw = (CORPUS / "magic_0244.dll").read_bytes()
data = data_sec(raw)
print("data len:", len(data))
print("-- dump R=0x1150:")
dump(data, 0x1150 - 16)
print("-- dump R=0x250A0:")
dump(data, 0x250A0 - 16)
for R in (0x1150, 0x250A0):
    rt = tolerant_root(data, R)
    print(f"tolerant_root(0x{R:X}) =", "OK" if rt else "FALHOU",
          json.dumps({k: rt[k] for k in ("R", "pc", "c2", "c3", "c4",
                                         "t1", "t2", "t3", "t4")}) if rt else "")
# o que o finder estrito diz desses offsets?
from ppp_disassembler.layer_c_resource import find_ppp_resource_roots
strict = [r.offset for r in find_ppp_resource_roots(data)]
print("strict roots:", [hex(x) for x in strict])

# --- 2. magic_0069 root 67552 ---------------------------------------------
print("\n=== magic_0069: R=0x9910 (39184) e R=0x107E0 (67552)")
raw = (CORPUS / "magic_0069.dll").read_bytes()
data = data_sec(raw)
print("data len:", len(data))
for R in (0x9910, 0x107E0):
    rt = tolerant_root(data, R)
    print(f"tolerant_root(0x{R:X}) =", "OK" if rt else "FALHOU")
    if rt is None:
        # diagnostico manual
        pc = _u16(data, R + 6); c2 = _u16(data, R + 8)
        c3 = _u16(data, R + 10); c4 = _u16(data, R + 12)
        t1 = _u32(data, R + 16); t2 = _u32(data, R + 20)
        t3 = _u32(data, R + 24); t4 = _u32(data, R + 28)
        print(f"   campos: pc={pc} c2={c2} c3={c3} c4={c4} "
              f"t1=0x{t1:X} t2=0x{t2:X} t3=0x{t3:X} t4=0x{t4:X}")
        prim = [_u32(data, R + t1 + 4 * i) for i in range(pc)] if (
            0 < pc <= 256 and t1 >= 32 and t1 % 4 == 0 and R + t1 + 4 * pc <= len(data)) else []
        print("   prim:", [hex(x) for x in prim[:12]])
        for i, rel in enumerate(prim[:6]):
            ok, sz, why = tolerant_section(data, R + rel)
            print(f"   sec[{i}] rel=0x{rel:X} sz_dec=0x{_u32(data, R+rel):X} "
                  f"-> {why} (ef={sz})")
    else:
        dump(data, R - 16, 4)

# --- 3. cinco fechadas ------------------------------------------------------
print("\n=== 5 fechadas")
for dll in ("magic_0052.dll", "magic_0053.dll", "magic_0064.dll",
            "magic_0065.dll", "magic_0709.dll"):
    raw = (CORPUS / dll).read_bytes()
    data = data_sec(raw)
    print(f"-- {dll} data_len={len(data)}")
    dump(data, 0, 4)
    # strings ascii
    import re
    strs = re.findall(rb"[ -~]{6,}", data)
    print("   strings:", [s.decode() for s in strs[:10]])
