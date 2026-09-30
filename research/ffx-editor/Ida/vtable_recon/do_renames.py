#!/usr/bin/env python3
"""do_renames.py — batch rename ??_7 vftables -> vtbl_<Class> + evidence comments."""
import json, time, sys
from mcp import call

proposed = json.load(open("proposed_names.json"))
# slot counts from rdata for comment
import struct
rdata = open("rdata.bin", "rb").read(); RS = 0xB0C8C0
import pickle
funcs = pickle.load(open("all_funcs.pkl", "rb")); fs = set(int(f["addr"], 16) for f in funcs)
ext = open("ext.bin", "rb").read(); ES = 0xC0A000
def dw(a):
    if RS <= a < RS + len(rdata): return struct.unpack_from("<I", rdata, a - RS)[0]
    if ES <= a < ES + len(ext): return struct.unpack_from("<I", ext, a - ES)[0]
    return None

# re-verify current names: fresh entity query of ??_7* to catch lane races
from mcp import post
def fresh_vt7():
    allg = []; off = 0
    while True:
        out = call("entity_query", {"queries": [{"kind": "globals", "filter": "??_7*",
                    "offset": off, "count": 500, "fields": ["addr", "name"]}]})
        if isinstance(out, str): out = json.loads(out)
        q = out[0] if isinstance(out, list) else out["result"][0]
        allg += q["data"]; nxt = q.get("next_offset")
        if not nxt or not q["data"]: break
        off = nxt
    return {g["addr"]: g["name"] for g in allg if g["name"].startswith("??_7")}

if "--fresh" in sys.argv:
    cur = fresh_vt7()
    json.dump(cur, open("fresh_vt7.json", "w"))
else:
    cur = {a: e["mangled"] for a, e in proposed.items()}

items = []
for addr, e in proposed.items():
    old = cur.get(addr, e["mangled"])
    if not old.startswith("??_7"):
        continue  # claimed by another lane meanwhile
    items.append({"old": old, "new": e["new"], "addr": addr, "cls": e["cls"]})
print("to rename:", len(items))

BATCH = 200
results = []
for i in range(0, len(items), BATCH):
    chunk = items[i:i + BATCH]
    out = call("rename", {"batch": {"data": [{"old": c["old"], "new": c["new"]} for c in chunk]}})
    if isinstance(out, str):
        try: out = json.loads(out)
        except Exception: pass
    results.append({"i": i, "res": out})
    summ = out.get("summary", out) if isinstance(out, dict) else out
    print(f"batch {i}: {summ}", flush=True)
    time.sleep(0.3)
json.dump(results, open("rename_results.json", "w"), indent=1)

# comments
citems = []
for it in items:
    a = int(it["addr"], 16)
    n = 0
    while dw(a + 4 * n) in fs: n += 1
    citems.append({"addr": it["addr"],
        "comment": f"[Jarvis-DEVIN-VTABLE] C++ vftable, class {it['cls']} ({it['old']}); {n} slots",
        "scope": "line"})
print("commenting:", len(citems))
cres = []
for i in range(0, len(citems), BATCH):
    chunk = citems[i:i + BATCH]
    out = call("set_comments", {"items": [{"addr": c["addr"], "comment": c["comment"]} for c in chunk]})
    if isinstance(out, str):
        try: out = json.loads(out)
        except Exception: pass
    cres.append({"i": i, "res": out})
    summ = out.get("summary", out) if isinstance(out, dict) else out
    print(f"cmt {i}: {summ}", flush=True)
    time.sleep(0.3)
json.dump(cres, open("comment_results.json", "w"), indent=1)
