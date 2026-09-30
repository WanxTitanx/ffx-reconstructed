#!/usr/bin/env python3
# ── PARITY-MGRP-BIN census: .mgrp + .bin families across FFX platform copies ──
# Purpose: hash every *.mgrp and *.bin under ffx_ps2/ffx/master/jppc in the 4
#          local platform copies (PC-Steam VBF extraction, PS3 PSARC extraction,
#          PS4 FFX_Data_P1 extraction, PC repack VBF extraction) and classify
#          per-relative-path parity (identical / variant / missing) per family.
#          Unlike .ebp (flat in event/obj/), .mgrp/.bin live in subtrees
#          (chr/**/mot, event/obj/<map>/<obj>/, battle/**, help*/**, menu/...),
#          so the census is a full-tree relpath comparison.
# Why: corpus-debt rule 5-e follow-up — same audit family as PARITY-CHR /
#      PARITY-EBP / PARITY-VPA. Initial signal (raw find|wc): .mgrp = PC +1 vs
#      the other three; .bin = PS4/Repack +5 vs PC/PS3 — the delta direction is
#      INVERTED vs .ebp/.vpa (extras on the NEWER platforms, not a PS3 deficit).
#      This script is the evidence generator for
#      docs/reverse/FFX_PARITY_MGRP_BIN_2026-09-15.md: it measures which
#      relpaths differ so the doc can diagnose WHY (mod pollution? dbg_?
#      cloudsave/stub? new-platform files?).
# Derived from: research_tools/QA/ebp_census.py (PARITY-EBP, 2026-09-15), itself
#   derived from chr_census.py (PARITY-CROSS). Adaptations vs ebp_census:
#   (a) two extensions censused in ONE run (FAMILIES table), output files get a
#   family prefix (mgrp_/bin_); (b) prefix breakdown replaced by TOP-DIRECTORY
#   breakdown (files are tree-distributed, not flat) PLUS filename-prefix for
#   flat cases; (c) OUT dir work/_mgrp_bin_parity/; (d) missing-detail /
#   variants-detail / crossnames / classes all kept per family, same TSV
#   schema as the .ebp run so the docs stay comparable.
# Constraints: corpora under /mnt are READ-ONLY (open 'rb' only); all writes go
#          to work/_mgrp_bin_parity/ (gitignored mirror) — the curated copies
#          live in artifacts/2026-09-15/parity-mgrp-bin/.
# Maintenance: rerun with `python3 mgrp_bin_census.py` from anywhere (absolute
#          paths). Runtime is dominated by hashing ~4.6k files x 4 sides.

import hashlib
import os
import sys
from collections import defaultdict

OUT = "/home/wanderson/Documents/ffx-editor-main/work/_mgrp_bin_parity"

# Platform label -> jppc root. Labels follow the physical extraction source
# (per FFX_HD_CORPUS_IDENTITY_2026-09-04: the ffx_ps2 tree is the PS2-era
# payload re-carried by every HD remaster container; it is NOT PS2 disc media).
ROOTS = {
    "PC-Steam": "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc",
    "PS3-PSARC": "/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/FFXX2HDREMASTER/PSARC_EXTRACTED/FFX/ffx_ps2/ffx/master/jppc",
    "PS4-P1": "/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/PS4FFX/extracted/FFX_Data_P1/ffx_ps2/ffx/master/jppc",
    "PC-Repack": "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc",
}

# Families censused in this run. Key = file prefix used for every output name.
FAMILIES = {
    "mgrp": ".mgrp",
    "bin": ".bin",
}


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def census(fam, platform, root, ext):
    """Return list of (relpath, size, sha256) for every *<ext> under root."""
    rows = []
    for dirpath, _dirnames, filenames in os.walk(root):
        for fn in filenames:
            if fn.lower().endswith(ext):
                full = os.path.join(dirpath, fn)
                rel = os.path.relpath(full, root).replace(os.sep, "/")
                rows.append((rel, os.path.getsize(full), sha256_file(full)))
    rows.sort()
    # Per-platform evidence TSV (mission deliverable: nome/sha/bytes/plataforma)
    with open(os.path.join(OUT, f"{fam}_census_{platform.lower()}.tsv"), "w") as f:
        f.write("name\tsha256\tbytes\tplatform\n")
        for rel, size, sha in rows:
            f.write(f"{rel}\t{sha}\t{size}\t{platform}\n")
    return rows


def first_bytes(path, n=32):
    with open(path, "rb") as f:
        return f.read(n)


def top_dir(rel):
    """First path component under jppc (chr / event / battle / menu / ...).
    Groups tree-distributed files by subsystem; flat files return '(root)'."""
    head = rel.split("/", 1)
    return head[0] if len(head) > 1 else "(root)"


def name_prefix(rel):
    """Leading alphabetic prefix of the basename (kept from ebp_census for
    dbg_/cn_/psv_-style filename pollution detection)."""
    base = rel.rsplit("/", 1)[-1]
    out = []
    for ch in base.lower():
        if ch.isalpha():
            out.append(ch)
        else:
            break
    return "".join(out) or "(other)"


def census_family(fam, ext):
    data = {}  # platform -> {relpath: (size, sha)}
    for platform, root in ROOTS.items():
        if not os.path.isdir(root):
            print(f"[WARN] missing root for {platform}: {root}", file=sys.stderr)
            data[platform] = {}
            continue
        rows = census(fam, platform, root, ext)
        data[platform] = {rel: (size, sha) for rel, size, sha in rows}
        print(f"{platform}: {len(rows)} {ext} files hashed")

    platforms = list(ROOTS)
    all_relpaths = sorted({r for d in data.values() for r in d})

    # ── Per-relpath parity classification ──
    classes = defaultdict(int)
    with open(os.path.join(OUT, f"{fam}_relpath_classes.tsv"), "w") as f:
        f.write("name\tclass\t" + "\t".join(platforms) + "\n")
        for rel in all_relpaths:
            shas = {p: data[p].get(rel, ("", ""))[1] for p in platforms}
            present = [p for p in platforms if rel in data[p]]
            distinct = {s for s in shas.values() if s}
            if len(present) == len(platforms) and len(distinct) == 1:
                cls = "IDENTICAL-4"
            elif len(distinct) == 1:
                cls = f"IDENTICAL-PARTIAL(missing:{len(platforms)-len(present)})"
            elif len(distinct) > 1:
                cls = f"VARIANT({len(distinct)} hashes)"
            else:
                cls = "EMPTY"
            classes[cls] += 1
            f.write(f"{rel}\t{cls}\t" + "\t".join(shas[p][:12] for p in platforms) + "\n")

    # ── Missing detail: exact relpaths absent per platform, with the size/sha
    #    they have on the sides that DO carry them (the doc's core evidence) ──
    with open(os.path.join(OUT, f"{fam}_missing_detail.tsv"), "w") as f:
        f.write("missing_from\tname\tbytes\tsha256\tpresent_on\tfirst32hex(ref)\n")
        for p in platforms:
            for rel in all_relpaths:
                if rel not in data[p]:
                    present_on = ",".join(q for q in platforms if rel in data[q])
                    ref = next((q for q in platforms if rel in data[q]), None)
                    size, sha = data[ref][rel] if ref else (0, "")
                    fb = ""
                    if ref and os.path.isfile(os.path.join(ROOTS[ref], rel)):
                        fb = first_bytes(os.path.join(ROOTS[ref], rel)).hex()
                    f.write(f"{p}\t{rel}\t{size}\t{sha}\t{present_on}\t{fb}\n")

    # ── Cross-name content: sha under >1 distinct relpath (any platform) ──
    sha_to_names = defaultdict(set)
    for p in platforms:
        for rel, (_size, sha) in data[p].items():
            sha_to_names[sha].add(rel)
    cross = {sha: names for sha, names in sha_to_names.items() if len(names) > 1}
    with open(os.path.join(OUT, f"{fam}_crossnames.tsv"), "w") as f:
        f.write("sha256\tn_names\tn_platforms\tnames\n")
        for sha in sorted(cross, key=lambda s: -len(cross[s])):
            names = sorted(cross[sha])
            nplat = len({p for p in platforms for r in names if r in data[p]})
            f.write(f"{sha}\t{len(names)}\t{nplat}\t{';'.join(names)}\n")

    # ── Variant detail: same relpath, different content across platforms ──
    variants = []
    for rel in all_relpaths:
        shas = {p: data[p].get(rel) for p in platforms if rel in data[p]}
        if len({v[1] for v in shas.values()}) > 1:
            variants.append(rel)
    with open(os.path.join(OUT, f"{fam}_variants_detail.tsv"), "w") as f:
        f.write("name\tplatform\tbytes\tsha256\tfirst32hex\n")
        for rel in variants:
            for p in platforms:
                if rel in data[p]:
                    full = os.path.join(ROOTS[p], rel)
                    size, sha = data[p][rel]
                    fb = first_bytes(full).hex()
                    f.write(f"{rel}\t{p}\t{size}\t{sha}\t{fb}\n")

    # ── Same-content different-size impossible; but check size-vs-sha sanity ──
    size_by_sha = {}
    for p in platforms:
        for rel, (size, sha) in data[p].items():
            size_by_sha.setdefault(sha, set()).add(size)
    multi_size = {s: v for s, v in size_by_sha.items() if len(v) > 1}
    assert not multi_size, f"sha collision across sizes (impossible): {multi_size}"

    # ── Variant signature: which corpora share a sha (MEASURE the pattern,
    #    don't assume the .ebp PS3-alone story generalizes to binaries) ──
    sig = defaultdict(int)
    with open(os.path.join(OUT, f"{fam}_variant_signatures.tsv"), "w") as f:
        f.write("name\tsignature\t" + "\t".join(platforms) + "\n")
        for rel in variants:
            groups = defaultdict(list)
            for p in platforms:
                if rel in data[p]:
                    groups[data[p][rel][1]].append(p)
            signature = "|".join("+".join(sorted(v)) for v in groups.values())
            sig[signature] += 1
            f.write(f"{rel}\t{signature}\t" + "\t".join(
                data[p][rel][1][:12] if rel in data[p] else "-" for p in platforms) + "\n")

    # ── Top-dir + name-prefix breakdowns (files per platform) ──
    sub = defaultdict(lambda: defaultdict(int))
    pre = defaultdict(lambda: defaultdict(int))
    for p in platforms:
        for rel in data[p]:
            sub[top_dir(rel)][p] += 1
            pre[name_prefix(rel)][p] += 1

    # ── Summary ──
    total_hashes = sum(len(d) for d in data.values())
    distinct_hashes = len(size_by_sha)
    lines = []
    lines.append(f"FFX .{fam} family parity census — 2026-09-15 (PARITY-MGRP-BIN)\n")
    lines.append("Platforms (jppc root per side):")
    for p, r in ROOTS.items():
        lines.append(f"  {p}: {r} -> {len(data[p])} files")
    lines.append(f"\nTotal hashed entries: {total_hashes}")
    lines.append(f"Distinct sha256: {distinct_hashes}")
    lines.append(f"Distinct relpaths: {len(all_relpaths)}\n")
    lines.append("Per-relpath classes:")
    for c, n in sorted(classes.items(), key=lambda kv: -kv[1]):
        lines.append(f"  {c}: {n}")
    lines.append("\nMissing per platform:")
    for p in platforms:
        miss = [r for r in all_relpaths if r not in data[p]]
        lines.append(f"  {p}: {len(miss)} missing")
        for r in miss:
            lines.append(f"    {r}")
    lines.append(f"\nCross-name sha groups (same content, >1 relpath): {len(cross)}")
    lines.append(f"Variant relpaths (same name, >1 hash): {len(variants)}")
    lines.append("Variant signatures (which corpora share a sha):")
    for s, n in sorted(sig.items(), key=lambda kv: -kv[1]):
        lines.append(f"  {s}: {n}")
    lines.append("\nTop-dir breakdown (files per platform):")
    for s in sorted(sub):
        lines.append(f"  {s}: " + ", ".join(f"{p}={sub[s][p]}" for p in platforms))
    lines.append("\nName-prefix breakdown (files per platform, deltas only):")
    for s in sorted(pre):
        counts = [pre[s][p] for p in platforms]
        if len(set(counts)) > 1:
            lines.append(f"  {s}: " + ", ".join(f"{p}={pre[s][p]}" for p in platforms))
    text = "\n".join(lines) + "\n"
    with open(os.path.join(OUT, f"{fam}_summary.txt"), "w") as f:
        f.write(text)
    print(text)


def main():
    os.makedirs(OUT, exist_ok=True)
    for fam, ext in FAMILIES.items():
        print(f"===== family {fam} ({ext}) =====")
        census_family(fam, ext)


if __name__ == "__main__":
    main()
