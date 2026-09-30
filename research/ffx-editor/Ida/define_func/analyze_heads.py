#!/usr/bin/env python3
"""analyze_heads.py — group fn=null heads into orphan chunks + find no-head gaps.

Inputs: heads.jsonl {a,f}, funcs_fresh.json [{addr,name,size}]
Outputs: chunks.json (contiguous orphan-head runs), gaps.json (no-head ranges
outside functions), coverage stats.
"""
import json, os
from bisect import bisect_right

HERE = os.path.dirname(os.path.abspath(__file__))
TEXT_START = 0x401000
TEXT_END = 0xB0C000

heads = {}
for l in open(os.path.join(HERE, "heads.jsonl")):
    d = json.loads(l)
    heads[d["a"]] = d["f"]
addrs = sorted(heads)
print(f"unique heads: {len(addrs)}")

funcs = json.load(open(os.path.join(HERE, "funcs_fresh.json")))
funcs = sorted(((int(f["addr"], 16), f["name"], int(f["size"], 16)) for f in funcs))
fstarts = [f[0] for f in funcs]


def in_func(a):
    i = bisect_right(fstarts, a) - 1
    if i < 0:
        return False
    s, _, sz = funcs[i]
    return s <= a < s + sz


# sanity: every head with f!=0 should be in_func
bad = sum(1 for a in addrs if heads[a] and not in_func(a))
nullfn = [a for a in addrs if heads[a] == 0]
print(f"fn=null heads: {len(nullfn)}  (in_func mismatches: {bad})")

# ---- contiguous orphan runs (any heads with fn=0, incl. align/data) ----
chunks = []
cur = None
for a in nullfn:
    if cur is None:
        cur = [a, a]
    else:
        cur[1] = a
        # note: contiguity decided later by gap analysis; here group by
        # "distance to previous nullfn head <= 0x40" to merge code+its jmptab
    chunks_tmp = None
# better: group nullfn heads where inter-head distance <= 16 bytes (covers
# insns + dd entries + small aligns); larger break = separate chunk
chunks = []
cur = None
prev = None
for a in nullfn:
    if cur is None:
        cur = [a, a]
    elif a - prev <= 16:
        cur[1] = a
    else:
        chunks.append(cur)
        cur = [a, a]
    prev = a
if cur:
    chunks.append(cur)
print(f"orphan chunks (dist<=16 grouping): {len(chunks)}")

# ---- no-head gaps ----
gaps = []
prev = None
for a in addrs:
    if prev is not None and a - prev > 15:  # head addr delta >15 => possible gap
        # the gap itself is between prev_item_end..a; without sizes we use prev..a
        gaps.append([prev, a])
    prev = a
# leading/trailing
if addrs[0] > TEXT_START:
    gaps.insert(0, [TEXT_START, addrs[0]])
print(f"head-delta>15 ranges: {len(gaps)}")

json.dump(chunks, open(os.path.join(HERE, "chunks_raw.json"), "w"))
json.dump(gaps, open(os.path.join(HERE, "gaps_raw.json"), "w"))

# coverage: bytes inside functions
tot = 0
for s, _, sz in funcs:
    tot += sz
print(f"function bytes: {tot:#x} / .text {TEXT_END-TEXT_START:#x} "
      f"({100.0*tot/(TEXT_END-TEXT_START):.2f}%)")
