# -*- coding: utf-8 -*-
"""Debug rápido da dispatch table 0xC3A500 do FFX.exe (nomes em +0)."""
import struct
import sys

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\work\ppp_inventory")
import inventory_scan as m

data = m.FFX_EXE.read_bytes()
layout = m._parse_pe_layout(data)
imagebase, sections = layout


def v2o(va):
    rva = va - imagebase if va >= imagebase else va
    for _n, sva, svs, srp, srs in sections:
        if sva <= rva < sva + max(svs, srs):
            d = rva - sva
            return srp + d if d < srs else None
    return None


off = v2o(0xC3A500)
n = 0
for i in range(1024):
    e = off + 40 * i
    name_ptr = struct.unpack_from("<I", data, e)[0]
    if not name_ptr:
        break
    no = v2o(name_ptr)
    name = m._read_cstr(data, no, cap=80) if no else None
    if not name:
        break
    n += 1
    if i < 8 or i % 50 == 0:
        print(i, name, hex(struct.unpack_from("<I", data, e + 8)[0]))
print("total entries:", n)
