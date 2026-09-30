#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
LOCALE-PARITY analysis pass 3 — cross-name group taxonomy.

Classifies each sha-group (>1 member) as:
  INTRA-TREE   : all members inside one tree (e.g. obj_ps3==obj_psv same tree)
  CROSS-TREE   : members in >1 tree, same basename (locale dup of same asset)
  CROSS-NAME   : different basenames share content (subfont=xfont1208 class)
  MIXED
Emits locale_crossname_classes.tsv + interesting cross-name (diff-basename) list.
"""
import os
from collections import defaultdict

OUT = "/home/wanderson/Documents/ffx-editor-main/work/_locale_parity"
TREES = ["inpc", "jppc", "new_chpc", "new_depc", "new_frpc", "new_itpc",
         "new_jppc", "new_krpc", "new_sppc", "new_uspc", "uspc"]

data = {}
for t in TREES:
    data[t] = {}
    with open(os.path.join(OUT, f"locale_census_{t}.tsv"), encoding="utf-8") as f:
        next(f)
        for line in f:
            rel, sha, size = line.rstrip("\n").split("\t")
            data[t][rel] = (sha, int(size))

by_sha = defaultdict(list)
for t in TREES:
    for rel, (sha, size) in data[t].items():
        by_sha[sha].append((t, rel, size))

groups = {s: v for s, v in by_sha.items() if len(v) > 1}


def classify(members):
    trees = {m[0] for m in members}
    basenames = {os.path.basename(m[1]) for m in members}
    # ps3/psv in-tree mirror pair detection
    rels = [m[1] for m in members]
    ps_mirror = all(
        r.startswith("event/obj_ps3/") or r.startswith("event/obj_psv/")
        for r in rels)
    if len(trees) == 1:
        cls = "INTRA-TREE"
        if ps_mirror:
            cls = "INTRA-TREE-PS3PSV-MIRROR"
    elif len(basenames) == 1:
        cls = "CROSS-TREE-SAMENAME"  # same asset name in many locales
    else:
        cls = "CROSS-NAME"  # different basenames — the subfont class
    return cls, len(trees), len(basenames), ps_mirror


rows = []
hist = defaultdict(int)
diffname_groups = []
for sha, members in groups.items():
    cls, nt, nb, psm = classify(members)
    hist[cls] += 1
    rows.append((sha, members[0][2], len(members), nt, nb, cls, members))
    if cls == "CROSS-NAME" or (cls == "CROSS-TREE-SAMENAME" and nb > 1):
        diffname_groups.append((sha, members))

with open(os.path.join(OUT, "locale_crossname_classes.tsv"), "w", encoding="utf-8") as f:
    f.write("sha256\tbytes\tn_members\tn_trees\tn_basenames\tclass\tmembers\n")
    for sha, size, nm, nt, nb, cls, members in sorted(rows, key=lambda r: (-r[2], r[0])):
        mstr = "; ".join(f"{t}:{r}" for t, r, _s in sorted(members))
        f.write(f"{sha}\t{size}\t{nm}\t{nt}\t{nb}\t{cls}\t{mstr}\n")

# diff-basename groups report (the interesting subfont.fmt-class finds)
with open(os.path.join(OUT, "locale_diffname_groups.tsv"), "w", encoding="utf-8") as f:
    f.write("sha256\tbytes\tmembers\n")
    for sha, members in sorted(diffname_groups, key=lambda kv: -len(kv[1])):
        mstr = "; ".join(f"{t}:{r}" for t, r, _s in sorted(members))
        f.write(f"{sha}\t{members[0][2]}\t{mstr}\n")

print("=== class histogram ===")
for k, v in sorted(hist.items(), key=lambda kv: -kv[1]):
    print(f"{v:6d}  {k}")
print(f"total groups: {len(groups)}; diff-basename groups: {len(diffname_groups)}")
