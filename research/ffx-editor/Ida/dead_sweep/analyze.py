#!/usr/bin/env python3
"""analyze.py — compute dead set + clusters + transitive closure.

Outputs:
  dead.json     {addr: {name,size,class,evidence,ptr_matches,transitive}}
  clusters.json [{start,end,n,members:[addr..],sample_names}]
  reachable_ptr.json  funcs kept reachable only by data-pointer hits
"""
import json, os, bisect, sys
HERE = os.path.dirname(os.path.abspath(__file__))
ENTRYPOINT = 0x9493C7
SEGS = [(".text", 0x401000, 0xB0C000), (".idata", 0xB0C000, 0xB0C8C0),
        (".rdata", 0xB0C8C0, 0xC0A000), (".data", 0xC0A000, 0x25D7000),
        (".rodata", 0x25D7000, 0x25D8000), ("_RDATA", 0x25D8000, 0x25D9000)]


def seg_of(a):
    for n, s, e in SEGS:
        if s <= a < e:
            return n
    return "?"


def main():
    funcs = json.load(open(f"{HERE}/funcs.json"))
    xrefs = json.load(open(f"{HERE}/xref.json"))
    ptrs = json.load(open(f"{HERE}/ptr.json"))
    byaddr = {f["addr"]: f for f in funcs}
    starts = sorted(byaddr)

    zero = [f for f in funcs
            if xrefs.get(f"{f['addr']:x}", {}).get("n", 0) == 0
            and f["addr"] != ENTRYPOINT]

    dead, ptr_kept = {}, {}
    for f in zero:
        a = f["addr"]
        ms = ptrs.get(f"{a:x}", [])
        if ms:
            ptr_kept[a] = ms
        else:
            dead[a] = {"name": f["name"], "size": f["size"],
                       "class": "?", "transitive": False}

    print(f"zero-xref: {len(zero)}  ptr-kept: {len(ptr_kept)}  "
          f"DEAD: {len(dead)}")

    # ---- transitive pass 1: single-xref funcs sourced only from dead ----
    changed = True
    rounds = 0
    while changed and rounds < 4:
        changed = False
        rounds += 1
        for f in funcs:
            a = f["addr"]
            if a in dead or a in ptr_kept or a == ENTRYPOINT:
                continue
            xr = xrefs.get(f"{a:x}", {})
            if xr.get("n") == 1 and not xr.get("more") \
                    and xr.get("first") and xr["first"].get("type") == "code":
                src = xr["first"].get("fn")
                srca = int(src, 16) if isinstance(src, str) else src
                if srca in dead:
                    # need ptr check too — done later in scan2; tentatively dead
                    dead[a] = {"name": f["name"], "size": f["size"],
                               "class": "?", "transitive": True,
                               "src_dead": f"0x{srca:x}"}
                    changed = True
        print(f"transitive round {rounds}: dead={len(dead)}")

    # ---- clusters: contiguous runs (gap <= 0x80 between func starts) ----
    daddrs = sorted(dead)
    clusters = []
    cur = [daddrs[0]] if daddrs else []
    for a in daddrs[1:]:
        prev_end = cur[-1] + byaddr[cur[-1]]["size"]
        if a - prev_end <= 0x80:
            cur.append(a)
        else:
            clusters.append(cur)
            cur = [a]
    if cur:
        clusters.append(cur)
    clusters.sort(key=lambda c: -len(c))
    cj = [{"start": c[0], "end": c[-1] + byaddr[c[-1]]["size"],
           "n": len(c),
           "sample_names": [byaddr[x]["name"] for x in c[:6]]}
          for c in clusters]
    json.dump(dead, open(f"{HERE}/dead_raw.json", "w"), indent=0)
    json.dump(cj, open(f"{HERE}/clusters.json", "w"), indent=1)
    json.dump({f"{a:x}": m for a, m in ptr_kept.items()},
              open(f"{HERE}/reachable_ptr.json", "w"), indent=0)
    print(f"clusters: {len(cj)}  top10:")
    for c in cj[:10]:
        print(f"  0x{c['start']:x}-0x{c['end']:x} n={c['n']} "
              f"{c['sample_names'][:3]}")
    # dead distribution by 0x100000 band
    from collections import Counter
    band = Counter(a // 0x100000 for a in dead)
    for b in sorted(band):
        print(f"  band 0x{b:x}00000: {band[b]}")


if __name__ == "__main__":
    main()
