#!/usr/bin/env python3
import sys, json, struct
sys.path.insert(0, "/home/wanderson/Documents/ffx-editor-main/work/_atel_ns")
from mcplib import Mcp
m = Mcp()

def get_bytes(addr, size):
    out = bytearray()
    while size > 0:
        n = min(size, 0x800)
        r = m.call("get_bytes", {"regions": {"addr": hex(addr + len(out)), "size": n}})
        # tolerate fragmented SSE: find the json array
        s = r.index("["); e = r.rindex("]")
        d = json.loads(r[s:e+1])
        data = d[0]["data"]
        out += bytes(int(t, 16) for t in data.split()) if data else b"\x00"*n
        size -= n
    return bytes(out)

def is_code(v):
    return 0x401000 <= v < 0xD00000

def scan(base, nentries, label):
    raw = get_bytes(base, nentries*16)
    filled = []
    for i in range(nentries):
        e = struct.unpack_from("<4I", raw, i*16)
        if any(is_code(x) for x in e):
            filled.append((i, e))
    print(f"== {label} @ {base:#x}: {len(filled)} code-ptr entries in window of {nentries}")
    for i, e in filled[:50]:
        print(f"   [{i:4}] " + " ".join(f"{x:#010x}" if x else "-" for x in e))
    if len(filled) > 50:
        print(f"   ... ({len(filled)-50} more) last idx {filled[-1][0]}")
    return filled

scan(0xC85EB0, 781, "AbilityMap region (to SgEvent 0xC88D88)")
scan(0xC5D8C0, 61, "Mount region (to Map 0xC5DC90)")
scan(0xC52B60, 8+31+50, "Default+overrun window")
