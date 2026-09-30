#!/usr/bin/env python3
"""apply.py — verify current names, rename dead funcs DEAD_*, comment, save.

Stages (idempotent, checkpointed):
  A) re-lookup current names for all dead addrs -> current.json
  B) rename batches -> renamed.json (applied addrs)
  C) append_comments batches -> commented.json
  D) idb_save
"""
import json, os, sys, time
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))


def load(n, d):
    p = f"{HERE}/{n}"
    return json.load(open(p)) if os.path.exists(p) else d


def save(n, o):
    json.dump(o, open(f"{HERE}/{n}", "w"))


def main():
    dead = {int(k): v for k, v in
            json.load(open(f"{HERE}/dead.json")).items()}
    funcs = {f["addr"]: f for f in json.load(open(f"{HERE}/funcs.json"))}
    ida = Ida()

    # ---- A) re-verify current names ----
    cur = load("current.json", {})
    todo = [a for a in sorted(dead) if str(a) not in cur]
    B = 300
    for i in range(0, len(todo), B):
        batch = todo[i:i + B]
        r = ida.call("lookup_funcs",
                     {"queries": [f"0x{a:x}" for a in batch]})
        for item in r:
            fn = item.get("fn")
            if fn:
                cur[str(int(fn["addr"], 16))] = fn["name"]
        if (i // B) % 10 == 0:
            save("current.json", cur)
            print(f"lookup {i}/{len(todo)}", flush=True)
    save("current.json", cur)
    changed = sum(1 for a in dead
                  if cur.get(str(a)) and cur[str(a)] != dead[a]["name"])
    print(f"names changed since snapshot: {changed}", flush=True)

    # ---- B) rename ----
    done = set(load("renamed.json", []))
    used = {f["name"] for f in funcs.values()}   # all current DB names
    plan = []
    for a in sorted(dead):
        if a in done:
            continue
        name = cur.get(str(a)) or dead[a]["name"]
        if name.startswith("DEAD_"):
            continue                   # already tagged (leva-6 or prior run)
        new = ("DEAD_" + name)[:240]
        if new in used:
            k = 2
            while f"{new}_{k}" in used:
                k += 1
            new = f"{new}_{k}"
        used.add(new)
        plan.append({"addr": f"0x{a:x}", "name": new})
    print(f"rename plan: {len(plan)}", flush=True)

    B = 300
    for i in range(0, len(plan), B):
        batch = plan[i:i + B]
        try:
            r = ida.call("rename", {"batch": {"func": batch,
                                              "dry_run": False,
                                              "stop_on_error": False,
                                              "allow_overwrite": False}})
        except Exception as e:
            print("rename fail, retry:", e, flush=True)
            ida = Ida()
            r = ida.call("rename", {"batch": {"func": batch,
                                              "dry_run": False,
                                              "stop_on_error": False,
                                              "allow_overwrite": False}})
        summ = (r or {}).get("summary", {}) if isinstance(r, dict) else {}
        if summ.get("failed", 0) or summ.get("dry_run"):
            print("  batch anomalies:", json.dumps(r)[:600], flush=True)
        for res in (r or {}).get("func", []) if isinstance(r, dict) else []:
            if res.get("error") or res.get("failed"):
                print("  item fail:", json.dumps(res)[:300], flush=True)
        for it in batch:
            done.add(int(it["addr"], 16))
        if (i // B) % 5 == 0:
            save("renamed.json", sorted(done))
            print(f"renamed {i + len(batch)}/{len(plan)}", flush=True)
    save("renamed.json", sorted(done))

    # ---- C) comments ----
    commented = set(load("commented.json", []))
    items = []
    for a in sorted(dead):
        if a in commented:
            continue
        v = dead[a]
        cls = v["class"]
        if v.get("transitive"):
            c = f"// DEAD-PC (transitive): 0 live xrefs; {cls}"
        else:
            c = f"// DEAD-PC: 0 xrefs + 0 dataptrs; {cls}"
        items.append({"addr": f"0x{a:x}", "comment": c, "scope": "func"})
    print(f"comment plan: {len(items)}", flush=True)
    B = 300
    for i in range(0, len(items), B):
        batch = items[i:i + B]
        try:
            ida.call("append_comments", {"items": batch})
        except Exception as e:
            print("comments fail, retry:", e, flush=True)
            ida = Ida()
            ida.call("append_comments", {"items": batch})
        for it in batch:
            commented.add(int(it["addr"], 16))
        if (i // B) % 5 == 0:
            save("commented.json", sorted(commented))
            print(f"commented {i + len(batch)}/{len(items)}", flush=True)
    save("commented.json", sorted(commented))

    # ---- D) save ----
    r = ida.call("idb_save", {})
    print("idb_save:", json.dumps(r)[:300], flush=True)


if __name__ == "__main__":
    main()
