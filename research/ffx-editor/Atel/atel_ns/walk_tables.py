#!/usr/bin/env python3
"""Walk all ATEL funcspace tables: resolve each of the 16 AtelCallTargets slots
per the proven registration order, dump entries, count filled ones, resolve
handler names."""
import sys, json, struct
sys.path.insert(0, "/home/wanderson/Documents/ffx-editor-main/work/_atel_ns")
from mcplib import Mcp

m = Mcp()

# Proven registration map (disasm 0x86D788-0x86D823). Default fills everything first.
TABLES = {
    0x0: ("Common",     0xC50050),
    0x1: ("Math",       0xC52BE0),
    0x4: ("SgEvent",    0xC88D88),
    0x5: ("ChEvent",    0xC891F8),
    0x6: ("Camera",     0xC43988),
    0x7: ("Battle",     0xC42618),
    0x8: ("Map",        0xC5DC90),
    0x9: ("Mount",      0xC5D8C0),
    0xB: ("Movie",      0xC40E20),
    0xC: ("Debug",      0xC52DD8),
    0xD: ("AbilityMap", 0xC85EB0),
}
DEFAULT = 0xC52B60
# next-symbol bounds for physical extent sanity (only where adjacent)
# designed lengths per fahrenheit AtelCallTargets asserts:
DESIGNED = {"Common":616,"Math":30,"SgEvent":71,"ChEvent":145,"Camera":138,
            "Battle":296,"Map":108,"Mount":1,"Movie":16,"Debug":94,"AbilityMap":1}

def get_bytes(addr, size):
    out = m.call("get_bytes", {"regions": {"addr": hex(addr), "size": size}})
    d = json.loads(out)
    data = d[0]["data"] if isinstance(d, list) else d["result"][0]["data"]
    if data is None:
        return b"\x00" * size
    return bytes(int(t, 16) for t in data.split())

def entries(base, count):
    raw = get_bytes(base, count * 16)
    out = []
    for i in range(count):
        e = struct.unpack_from("<4I", raw, i * 16)
        out.append(e)
    return out

def names(addrs):
    """resolve function names for a set of addrs via lookup_funcs batch"""
    res = {}
    todo = [a for a in addrs if a]
    if not todo:
        return res
    out = m.call("lookup_funcs", {"queries": [hex(a) for a in todo]})
    try:
        for row in json.loads(out):
            fn = row.get("fn")
            if fn:
                res[int(row["query"], 16)] = fn.get("name")
    except Exception:
        pass
    return res

report = {}
# effective slot map
slot_map = {}
for ns in range(16):
    if ns in TABLES:
        slot_map[ns] = TABLES[ns]
    else:
        slot_map[ns] = ("Default", DEFAULT)

for ns in range(16):
    fam, base = slot_map[ns]
    if fam == "Default":
        n = 8  # bounded by Math table base
    else:
        n = DESIGNED[fam]
    ents = entries(base, n)
    filled = [i for i, e in enumerate(ents) if any(e)]
    # also probe a few entries past the declared bound for the default table
    extra = []
    if fam == "Default":
        ex = entries(base + 8 * 16, 8)  # aliases into Math
        extra = ex
    handler_addrs = set()
    for e in ents:
        handler_addrs.update(x for x in e if x)
    nm = names(handler_addrs)
    report[ns] = {
        "family": fam, "base": hex(base), "declared": n,
        "filled": len(filled), "filled_idx": filled[:40],
        "entries_sample": {i: [hex(x) for x in ents[i]] for i in filled[:12]},
        "handler_names": {hex(k): v for k, v in sorted(nm.items())},
    }
    if fam == "Default":
        report[ns]["alias_past_bound"] = [[hex(x) for x in e] for e in extra]

json.dump(report, open("work/_atel_ns/table_walk.json", "w"), indent=1)
for ns in range(16):
    r = report[ns]
    print(f"ns {ns:#04x} {r['family']:>10} @{r['base']} declared={r['declared']:>4} filled={r['filled']:>4}")
print("\n--- default table detail ---")
print(json.dumps(report[0x2], indent=1)[:3500])
