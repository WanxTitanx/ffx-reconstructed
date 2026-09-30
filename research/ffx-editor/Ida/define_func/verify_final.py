#!/usr/bin/env python3
"""verify_final.py — post-sweep live verification of the leva-9 define_func sweep.

Re-checks, against the LIVE idb via MCP:
  1. function census (list_funcs count=0) -> total funcs, sub_* count
  2. still_sub.json addrs -> current fn name (were they renamed?)
  3. the three MISLABEL-R2 flagged addrs -> containing fn + name + comment probe
  4. loose_still_out.json addrs -> all should still report fn attribution
  5. gaps_outside.json head addrs -> confirm still outside any func (sample)
Writes verify_final.json + prints a summary.
"""
import json, os, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, "verify_final.json")


def chunks(lst, n):
    for i in range(0, len(lst), n):
        yield lst[i:i + n]


def lookup_all(ida, addrs, tag, batch=150):
    """addrs: list of int -> dict addr -> fn record (or None)."""
    res = {}
    addrs = list(addrs)
    for i, part in enumerate(chunks(addrs, batch)):
        for att in range(6):
            try:
                r = ida.call("lookup_funcs",
                             {"queries": [hex(a) for a in part]})
                break
            except Exception as e:
                print(f"  {tag} lookup ERR @{i} att{att}: {e}", flush=True)
                time.sleep(5 * (att + 1))
        else:
            raise RuntimeError(f"{tag} lookup failed @{i}")
        for a, q in zip(part, r):
            res[a] = q.get("fn")
        if (i + 1) % 20 == 0:
            print(f"  {tag}: {i + 1}/{len(addrs)//batch + 1} batches", flush=True)
    return res


def main():
    ida = Ida()
    report = {}

    # ---------- 1. full census ----------
    print("[1] full func census ...", flush=True)
    r = ida.call("list_funcs", {"queries": {"count": 0}})
    funcs = r[0].get("funcs", r[0]) if isinstance(r, list) else r.get("funcs", r)
    if isinstance(funcs, dict):
        funcs = funcs.get("funcs", [])
    total = len(funcs)
    subs = [f for f in funcs if str(f.get("name", "")).startswith("sub_")]
    report["census"] = {"total_funcs": total, "sub_count": len(subs),
                        "sub_sample": [f["addr"] for f in subs[:40]]}
    print(f"    total={total}  sub_*={len(subs)}", flush=True)
    json.dump(funcs, open(os.path.join(HERE, "funcs_verify.json"), "w"))

    # ---------- 2. still_sub addrs ----------
    still = json.load(open(os.path.join(HERE, "still_sub.json")))
    print(f"[2] still_sub addrs: {len(still)}", flush=True)
    m = lookup_all(ida, still, "still_sub")
    now_sub = {a: f for a, f in m.items()
               if f and str(f.get("name", "")).startswith("sub_")}
    no_fn = [a for a, f in m.items() if not f]
    report["still_sub"] = {"total": len(still), "now_sub": len(now_sub),
                           "no_fn": len(no_fn),
                           "now_sub_addrs": [hex(a) for a in list(now_sub)[:60]],
                           "no_fn_addrs": [hex(a) for a in no_fn[:60]]}
    print(f"    now_sub={len(now_sub)}  no_fn={len(no_fn)}", flush=True)

    # ---------- 3. flagged addrs ----------
    flagged = [0x88E914, 0x89DC40, 0x887974]
    print("[3] flagged addrs", flush=True)
    fm = lookup_all(ida, flagged, "flagged")
    report["flagged"] = {hex(a): fm[a] for a in flagged}
    for a in flagged:
        print(f"    {hex(a)} -> {fm[a]}", flush=True)

    # ---------- 4. loose_still_out ----------
    loose = json.load(open(os.path.join(HERE, "loose_still_out.json")))
    print(f"[4] loose_still_out: {len(loose)}", flush=True)
    lm = lookup_all(ida, loose, "loose")
    loose_no_fn = [a for a, f in lm.items() if not f]
    report["loose_still_out"] = {"total": len(loose),
                                 "no_fn": len(loose_no_fn),
                                 "no_fn_addrs": [hex(a) for a in loose_no_fn]}
    print(f"    no_fn={len(loose_no_fn)}", flush=True)

    # ---------- 5. gap head sample ----------
    gaps = json.load(open(os.path.join(HERE, "gaps_outside.json")))
    # gaps format? -> list of {start,end,...} or [start,end]
    heads = []
    for g in gaps:
        if isinstance(g, dict):
            s = g.get("start", g.get("s", g.get("addr")))
        else:
            s = g[0]
        heads.append(int(s, 16) if isinstance(s, str) else int(s))
    print(f"[5] gap heads: {len(heads)} (verifying all still outside)", flush=True)
    gm = lookup_all(ida, heads, "gaps")
    now_in = {a: f for a, f in gm.items() if f}
    report["gaps"] = {"total": len(heads), "now_inside": len(now_in),
                      "inside_addrs": [hex(a) for a in list(now_in)[:60]]}
    print(f"    now_inside_a_func={len(now_in)}", flush=True)

    json.dump(report, open(OUT, "w"), indent=1)
    print("WROTE", OUT, flush=True)
    print(json.dumps(report, indent=1)[:4000], flush=True)


if __name__ == "__main__":
    main()
