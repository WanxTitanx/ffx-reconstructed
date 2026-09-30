#!/usr/bin/env python3
"""census.py — phase A/B/C: enumerate funcs, xref census, pointer scan.

Writes:
  funcs.json      all functions [{addr,name,size}]
  xref.json       {addr: {"n": count, "first": {type, fn-addr} | None}}
  ptr.json        {addr: [match addrs]} for zero-xref funcs (LE dword hits)
"""
import json, os, sys, time
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))
ENTRYPOINT = 0x9493C7


def load(name, default):
    p = os.path.join(HERE, name)
    if os.path.exists(p):
        return json.load(open(p))
    return default


def save(name, obj):
    json.dump(obj, open(os.path.join(HERE, name), "w"))


def main():
    ida = Ida()

    # ---- Phase A: enumerate ----
    funcs = load("funcs.json", None)
    if funcs is None:
        funcs = []
        off = 0
        while True:
            r = ida.call("list_funcs",
                         {"queries": {"offset": off, "count": 5000}})
            rows = r[0]["data"] if isinstance(r, list) else r["data"]
            funcs += rows
            nxt = r[0].get("next_offset") if isinstance(r, list) \
                else r.get("next_offset")
            print(f"list_funcs off={off} got={len(rows)} next={nxt}",
                  flush=True)
            if nxt is None or not rows:
                break
            off = nxt
        for f in funcs:
            f["addr"] = int(f["addr"], 16)
            f["size"] = int(f["size"], 16) if isinstance(
                f.get("size"), str) else f.get("size", 0)
        save("funcs.json", funcs)
    print(f"total funcs: {len(funcs)}", flush=True)

    # ---- Phase B: xref census (limit=1 -> presence) ----
    xrefs = load("xref.json", {})
    todo = [f for f in funcs if f"{f['addr']:x}" not in xrefs]
    print(f"xref census todo: {len(todo)}", flush=True)
    B = 400
    t0 = time.time()
    for i in range(0, len(todo), B):
        batch = todo[i:i + B]
        addrs = [f"0x{f['addr']:x}" for f in batch]
        try:
            r = ida.call("xrefs_to", {"addrs": addrs, "limit": 1})
        except Exception as e:
            print("xrefs_to batch fail, retry once:", e, flush=True)
            ida = Ida()
            r = ida.call("xrefs_to", {"addrs": addrs, "limit": 1})
        for item in r:
            a = int(item["addr"], 16)
            first = item["xrefs"][0] if item.get("xrefs") else None
            xrefs[f"{a:x}"] = {"n": item.get("xref_count", 0),
                               "more": item.get("more", False),
                               "first": ({"type": first.get("type"),
                                          "src": first.get("addr"),
                                          "fn": (first.get("fn") or {})
                                          .get("addr")}
                                         if first else None)}
        if (i // B) % 10 == 0:
            save("xref.json", xrefs)
            print(f"xrefs {i}/{len(todo)} "
                  f"({(time.time()-t0):.0f}s)", flush=True)
    save("xref.json", xrefs)
    zero = [f for f in funcs
            if xrefs.get(f"{f['addr']:x}", {}).get("n", 0) == 0
            and f["addr"] != ENTRYPOINT]
    print(f"zero-xref funcs: {len(zero)}", flush=True)

    # ---- Phase C: pointer scan (LE dword) over zero-xref funcs ----
    ptrs = load("ptr.json", {})
    todo = [f for f in zero if f"{f['addr']:x}" not in ptrs]
    print(f"ptr scan todo: {len(todo)}", flush=True)
    B = 150
    t0 = time.time()
    for i in range(0, len(todo), B):
        batch = todo[i:i + B]
        pats = [f"{f['addr'] & 0xff:02X} {(f['addr'] >> 8) & 0xff:02X} "
                f"{(f['addr'] >> 16) & 0xff:02X} "
                f"{(f['addr'] >> 24) & 0xff:02X}" for f in batch]
        try:
            r = ida.call("find_bytes", {"patterns": pats, "limit": 50})
        except Exception as e:
            print("find_bytes fail, retry once:", e, flush=True)
            ida = Ida()
            r = ida.call("find_bytes", {"patterns": pats, "limit": 50})
        bypat = {}
        for item in r:
            p = item["pattern"].replace(" ", "").lower()
            a = int.from_bytes(bytes.fromhex(p), "little")
            bypat[a] = [int(m, 16) for m in item.get("matches", [])]
            if item.get("cursor", {}).get("done") is False:
                print(f"  WARN pattern {item['pattern']} truncated",
                      flush=True)
        for f in batch:
            ptrs[f"{f['addr']:x}"] = bypat.get(f["addr"], [])
        if (i // B) % 10 == 0:
            save("ptr.json", ptrs)
            print(f"ptrs {i}/{len(todo)} "
                  f"({(time.time()-t0):.0f}s)", flush=True)
    save("ptr.json", ptrs)
    print("DONE census", flush=True)


if __name__ == "__main__":
    main()
