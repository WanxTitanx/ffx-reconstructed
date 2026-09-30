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
        s = r.index("["); e = r.rindex("]")
        d = json.loads(r[s:e+1])
        data = d[0]["data"]
        out += bytes(int(t, 16) for t in data.split()) if data else b"\x00"*n
        size -= n
    return bytes(out)

TABLES = [
 (0x0,"Common",0xC50050,616),(0x1,"Math",0xC52BE0,30),(0x4,"SgEvent",0xC88D88,71),
 (0x5,"ChEvent",0xC891F8,145),(0x6,"Camera",0xC43988,138),(0x7,"Battle",0xC42618,296),
 (0x8,"Map",0xC5DC90,108),(0x9,"Mount",0xC5D8C0,1),(0xB,"Movie",0xC40E20,16),
 (0xC,"Debug",0xC52DD8,94),(0xD,"AbilityMap",0xC85EB0,1),
]
res={}
for ns,name,base,n in TABLES:
    raw = get_bytes(base, n*16)
    holes=[]
    for i in range(n):
        e = struct.unpack_from("<4I", raw, i*16)
        if not any(e): holes.append(i)
    res[name]={"ns":ns,"declared":n,"holes":holes,"filled":n-len(holes)}
    print(f"{name:>10} ns{ns:#04x} filled={n-len(holes)}/{n} holes={holes if len(holes)<30 else str(holes[:30])+'…'}")
json.dump(res, open("work/_atel_ns/table_holes.json","w"), indent=1)
