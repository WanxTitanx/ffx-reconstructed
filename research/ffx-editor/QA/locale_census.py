#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
LOCALE-PARITY census — cross-LOCALE audit of the PC-Steam master.

Walks the 11 locale trees under ffx_ps2/ffx/master/ on the PC-Steam copy,
hashes every file (sha256, streamed), and emits:

  locale_census_<tree>.tsv   per-tree census: relpath / sha256 / bytes
  locale_relpath_matrix.tsv  relpath × tree matrix (sha12 per cell, '-' absent)
  locale_relpath_classes.tsv per-relpath parity class
  locale_crossnames.tsv      groups: same sha256 under >1 (tree,relpath)
  locale_summary.txt         consolidated summary

Read-only on the corpus; writes only under work/_locale_parity/.
Lane: FFX-STRUCTURES (subagente LOCALE-PARITY) — 2026-09-15.
"""
import hashlib
import os
import sys
from collections import defaultdict

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"
OUT = "/home/wanderson/Documents/ffx-editor-main/work/_locale_parity"
TREES = ["inpc", "jppc", "new_chpc", "new_depc", "new_frpc", "new_itpc",
         "new_jppc", "new_krpc", "new_sppc", "new_uspc", "uspc"]

CHUNK = 1 << 20


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while True:
            b = f.read(CHUNK)
            if not b:
                break
            h.update(b)
    return h.hexdigest()


def main():
    # entries: list of (tree, relpath, sha, size)
    entries = []
    for tree in TREES:
        base = os.path.join(ROOT, tree)
        tree_rows = []
        for dirpath, _dirs, files in os.walk(base):
            for fn in files:
                fp = os.path.join(dirpath, fn)
                rel = os.path.relpath(fp, base)
                size = os.path.getsize(fp)
                sha = sha256_file(fp)
                tree_rows.append((rel, sha, size))
                entries.append((tree, rel, sha, size))
        tree_rows.sort()
        tsv = os.path.join(OUT, f"locale_census_{tree}.tsv")
        with open(tsv, "w", encoding="utf-8") as f:
            f.write("relpath\tsha256\tbytes\n")
            for rel, sha, size in tree_rows:
                f.write(f"{rel}\t{sha}\t{size}\n")
        print(f"{tree}: {len(tree_rows)} files", file=sys.stderr)

    # relpath × tree matrix
    # map[relpath][tree] = sha
    by_rel = defaultdict(dict)
    size_of = {}
    for tree, rel, sha, size in entries:
        by_rel[rel][tree] = sha
        size_of[(tree, rel)] = size

    all_rels = sorted(by_rel.keys())
    with open(os.path.join(OUT, "locale_relpath_matrix.tsv"), "w", encoding="utf-8") as f:
        f.write("relpath\t" + "\t".join(TREES) + "\n")
        for rel in all_rels:
            row = [rel]
            for t in TREES:
                sha = by_rel[rel].get(t)
                row.append(sha[:12] if sha else "-")
            f.write("\t".join(row) + "\n")

    # classes per relpath
    n_ident = n_variant = 0
    with open(os.path.join(OUT, "locale_relpath_classes.tsv"), "w", encoding="utf-8") as f:
        f.write("relpath\tn_trees\tn_distinct_sha\tclass\tbytes\n")
        for rel in all_rels:
            shas = by_rel[rel]
            distinct = set(shas.values())
            ntrees = len(shas)
            if ntrees == 1:
                cls = "UNIQUE-1"  # exists in only one tree
            elif len(distinct) == 1:
                cls = f"IDENTICAL-{ntrees}"
                n_ident += 1
            else:
                cls = f"VARIANT-{len(distinct)}of{ntrees}"
                n_variant += 1
            sz = next(iter(size_of[(t, rel)] for t in shas))
            f.write(f"{rel}\t{ntrees}\t{len(distinct)}\t{cls}\t{sz}\n")

    # cross-name groups: same sha under >1 (tree,relpath)
    by_sha = defaultdict(list)
    for tree, rel, sha, size in entries:
        by_sha[sha].append((tree, rel, size))
    cross = {s: v for s, v in by_sha.items() if len(v) > 1}
    with open(os.path.join(OUT, "locale_crossnames.tsv"), "w", encoding="utf-8") as f:
        f.write("sha256\tbytes\tn_names\tmembers\n")
        for sha, members in sorted(cross.items(), key=lambda kv: (-len(kv[1]), kv[0])):
            mstr = "; ".join(f"{t}:{r}" for t, r, _s in sorted(members))
            f.write(f"{sha}\t{members[0][2]}\t{len(members)}\t{mstr}\n")

    # summary
    total = len(entries)
    distinct_sha = len(by_sha)
    with open(os.path.join(OUT, "locale_summary.txt"), "w", encoding="utf-8") as f:
        f.write("LOCALE-PARITY census summary — PC-Steam master, 11 locale trees\n")
        f.write(f"root: {ROOT}\n\n")
        f.write(f"files hashed: {total}\n")
        f.write(f"distinct relpaths: {len(all_rels)}\n")
        f.write(f"distinct sha256: {distinct_sha}\n")
        f.write(f"relpaths identical across all trees where present: {n_ident}\n")
        f.write(f"relpaths variant (same name, >1 sha): {n_variant}\n")
        f.write(f"cross-name sha groups (>1 member): {len(cross)}\n\n")
        f.write("per-tree counts:\n")
        for t in TREES:
            n = sum(1 for e in entries if e[0] == t)
            sz = sum(e[3] for e in entries if e[0] == t)
            f.write(f"  {t}: {n} files, {sz} bytes\n")

    print(f"done: {total} entries, {distinct_sha} distinct sha, "
          f"{len(all_rels)} relpaths, {len(cross)} crossname groups", file=sys.stderr)


if __name__ == "__main__":
    main()
