#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
LOCALE-PARITY analysis pass 2 — variant clustering, uspc×new_uspc,
obj_ps3×obj_psv in-tree duplication, cross-name taxonomy.
Reads the per-tree census TSVs; writes analysis TSVs + summary additions.
"""
import os
from collections import defaultdict

OUT = "/home/wanderson/Documents/ffx-editor-main/work/_locale_parity"
TREES = ["inpc", "jppc", "new_chpc", "new_depc", "new_frpc", "new_itpc",
         "new_jppc", "new_krpc", "new_sppc", "new_uspc", "uspc"]

# load census
data = {}          # data[tree][relpath] = (sha, size)
for t in TREES:
    data[t] = {}
    with open(os.path.join(OUT, f"locale_census_{t}.tsv"), encoding="utf-8") as f:
        next(f)
        for line in f:
            rel, sha, size = line.rstrip("\n").split("\t")
            data[t][rel] = (sha, int(size))

# ---- 1. uspc vs new_uspc ----
with open(os.path.join(OUT, "locale_uspc_vs_newuspc.tsv"), "w", encoding="utf-8") as f:
    f.write("relpath\tuspc_sha12\tnew_uspc_sha12\tverdict\tuspc_bytes\tnew_uspc_bytes\n")
    for rel in sorted(set(data["uspc"]) | set(data["new_uspc"])):
        u = data["uspc"].get(rel)
        n = data["new_uspc"].get(rel)
        if u and n:
            v = "IDENTICAL" if u[0] == n[0] else "VARIANT"
            f.write(f"{rel}\t{u[0][:12]}\t{n[0][:12]}\t{v}\t{u[1]}\t{n[1]}\n")
        elif u:
            f.write(f"{rel}\t{u[0][:12]}\t-\tONLY-OLD-USPC\t{u[1]}\t-\n")
        else:
            f.write(f"{rel}\t-\t{n[0][:12]}\tONLY-NEW-USPC\t-\t{n[1]}\n")

# ---- 2. obj_ps3 vs obj_psv within each tree ----
with open(os.path.join(OUT, "locale_obj_ps3_vs_psv.tsv"), "w", encoding="utf-8") as f:
    f.write("tree\trelpath_ps3\tsha12_ps3\trelpath_psv\tsha12_psv\tverdict\n")
    for t in TREES:
        ps3 = {r[len("event/obj_ps3/"):]: r for r in data[t] if r.startswith("event/obj_ps3/")}
        psv = {r[len("event/obj_psv/"):]: r for r in data[t] if r.startswith("event/obj_psv/")}
        for sub in sorted(set(ps3) | set(psv)):
            r3 = ps3.get(sub)
            rv = psv.get(sub)
            if r3 and rv:
                s3, _ = data[t][r3]
                sv, _ = data[t][rv]
                v = "IDENTICAL" if s3 == sv else "VARIANT"
                f.write(f"{t}\t{r3}\t{s3[:12]}\t{rv}\t{sv[:12]}\t{v}\n")
            elif r3:
                f.write(f"{t}\t{r3}\t{data[t][r3][0][:12]}\t-\t-\tONLY-PS3\n")
            else:
                f.write(f"{t}\t-\t-\t{rv}\t{data[t][rv][0][:12]}\tONLY-PSV\n")

# ---- 3. variant clustering: for each shared relpath, group trees by sha ----
all_rels = sorted(set().union(*[set(data[t]) for t in TREES]))
cluster_rows = []
cluster_patterns = defaultdict(list)
for rel in all_rels:
    shas = {t: data[t][rel][0] for t in TREES if rel in data[t]}
    if len(shas) < 2:
        continue
    distinct = set(shas.values())
    if len(distinct) == 1:
        continue
    # pattern: tuple of frozensets of trees sharing sha, sorted by tree-list
    groups = defaultdict(list)
    for t, s in shas.items():
        groups[s].append(t)
    pat = tuple(sorted((tuple(sorted(v)) for v in groups.values())))
    cluster_patterns[pat].append(rel)
    sig = " | ".join("/".join(sorted(v)) for v in groups.values())
    cluster_rows.append((rel, len(shas), len(distinct), sig))

with open(os.path.join(OUT, "locale_variant_clusters.tsv"), "w", encoding="utf-8") as f:
    f.write("relpath\tn_trees\tn_distinct\ttree_groups_by_sha\n")
    for rel, nt, nd, sig in sorted(cluster_rows):
        f.write(f"{rel}\t{nt}\t{nd}\t{sig}\n")

# pattern histogram
with open(os.path.join(OUT, "locale_variant_patterns.tsv"), "w", encoding="utf-8") as f:
    f.write("n_relpaths\tpattern\tsample\n")
    for pat, rels in sorted(cluster_patterns.items(), key=lambda kv: -len(kv[1])):
        sig = " | ".join("/".join(sorted(v)) for v in pat)
        f.write(f"{len(rels)}\t{sig}\t{rels[0]}\n")

# ---- 4. inpc vs jppc battle/kernel (International base vs JP) ----
with open(os.path.join(OUT, "locale_inpc_vs_jppc.tsv"), "w", encoding="utf-8") as f:
    f.write("relpath\tinpc_sha12\tjppc_sha12\tverdict\n")
    for rel in sorted(set(data["inpc"]) | set(data["jppc"])):
        i = data["inpc"].get(rel)
        j = data["jppc"].get(rel)
        if i and j:
            v = "IDENTICAL" if i[0] == j[0] else "VARIANT"
            f.write(f"{rel}\t{i[0][:12]}\t{j[0][:12]}\t{v}\n")
        elif i:
            f.write(f"{rel}\t{i[0][:12]}\t-\tONLY-INPC\n")

print("analysis done", flush=True)
