#!/usr/bin/env python3
"""apply_names2.py — rename new sub_ funcs (skip pre-named), comment all,
idb_save after each phase. Idempotent: skips addrs already non-sub_."""
import json, os, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))
plan = json.load(open(os.path.join(HERE, "rename_plan.json")))
REN = [p for p in plan if p.get("rename")]
print(f"planned renames: {len(REN)}; comments: {len(plan)}", flush=True)

ida = Ida()
t0 = time.time()

# ---- phase 0: fetch current names to skip already-renamed ----
cur = {}
for i in range(0, len(plan), 400):
    part = plan[i:i + 400]
    for att in range(5):
        try:
            r = ida.call("lookup_funcs",
                         {"queries": [hex(p["addr"]) for p in part]})
            break
        except Exception as e:
            print("ERR lookup", e, flush=True)
            time.sleep(3)
    for p, q in zip(part, r):
        fn = q.get("fn")
        cur[p["addr"]] = fn["name"] if fn else None
todo = [p for p in REN if (cur.get(p["addr"]) or "").startswith("sub_")]
print(f"still sub_: {len(todo)}", flush=True)

# ---- phase 1: renames ----
i = 0
fails = 0
while i < len(todo):
    part = todo[i:i + 200]
    payload = {"batch": {"func": [{"addr": hex(p["addr"]), "name": p["name"]}
                                  for p in part]}}
    r = None
    for att in range(5):
        try:
            r = ida.call("rename", payload)
            break
        except Exception as e:
            print(f"ERR rename @{i}: {e}", flush=True)
            time.sleep(2 + att * 3)
    if r:
        s = r.get("summary", {})
        fails += s.get("failed", 0)
    i += len(part)
    if (i // 200) % 10 == 0:
        print(f"rename {i}/{len(todo)} fails={fails} ({time.time()-t0:.0f}s)",
              flush=True)
print("renames done, saving...", flush=True)
print(json.dumps(ida.call("idb_save", {}))[:300], flush=True)

# ---- phase 2: comments ----
i = 0
while i < len(plan):
    part = plan[i:i + 200]
    payload = {"items": [{"addr": hex(p["addr"]), "comment": p["comment"]}
                         for p in part]}
    for att in range(5):
        try:
            r = ida.call("set_comments", payload)
            break
        except Exception as e:
            print(f"ERR comment @{i}: {e}", flush=True)
            time.sleep(2 + att * 3)
    i += len(part)
    if (i // 200) % 10 == 0:
        print(f"comments {i}/{len(plan)} ({time.time()-t0:.0f}s)", flush=True)
print("comments done, saving...", flush=True)
print(json.dumps(ida.call("idb_save", {}))[:300], flush=True)
print("ALL DONE", time.time() - t0, flush=True)
