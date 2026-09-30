#!/usr/bin/env python3
# ── PARITY-EBP census: .ebp family (EV01 field-event scripts) across FFX platform copies ──
# Purpose: hash every *.ebp under ffx_ps2/ffx/master/jppc in the 4 local platform
#          copies (PC-Steam VBF extraction, PS3 PSARC extraction, PS4 FFX_Data_P1
#          extraction, PC repack VBF extraction) and classify per-relative-path
#          parity (identical / variant / missing). All .ebp live in event/obj/ on
#          every side (verified before writing this), so the census is effectively
#          a flat comparison of event/obj/*.ebp.
# Why: corpus-debt rule 5-e follow-up — the .chr audit (FFX_PARITY_CHR_2026-09-15
#      §8) flagged .ebp as 397/383/397/397 with PS3 at -14 and NO explanation.
#      This script is the evidence generator for FFX_PARITY_EBP_2026-09-15.md:
#      it measures the gap (which relpaths, which sizes) so the doc can diagnose
#      WHY they are missing (deliberate omission vs reorganization vs revision).
# Derived from: research_tools/QA/chr_census.py (PARITY-CROSS, 2026-09-15).
#   Adaptations vs original: (a) glob *.ebp instead of *.chr; (b) output dir
#   work/_ebp_parity/; (c) subfamily breakdown replaced by filename-prefix
#   breakdown (event/obj is flat — no chr/<sub>/ tree); (d) NEW section
#   "missing detail" that dumps the exact per-platform missing relpaths with
#   size/sha from the sides that DO have them — that list is the doc's subject.
# Constraints: corpora under /mnt are READ-ONLY (open 'rb' only); all writes go
#          to work/_ebp_parity/.
# Maintenance: rerun with `python3 ebp_census.py` from anywhere (absolute paths).

import hashlib
import os
import sys
from collections import defaultdict

OUT = "/home/wanderson/Documents/ffx-editor-main/work/_ebp_parity"

# Platform label -> jppc root. Labels follow the physical extraction source
# (per FFX_HD_CORPUS_IDENTITY_2026-09-04: the ffx_ps2 tree is the PS2-era
# payload re-carried by every HD remaster container; it is NOT PS2 disc media).
ROOTS = {
    "PC-Steam": "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc",
    "PS3-PSARC": "/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/FFXX2HDREMASTER/PSARC_EXTRACTED/FFX/ffx_ps2/ffx/master/jppc",
    "PS4-P1": "/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/PS4FFX/extracted/FFX_Data_P1/ffx_ps2/ffx/master/jppc",
    "PC-Repack": "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc",
}


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def census(platform, root):
    """Return list of (relpath, size, sha256) for every *.ebp under root."""
    rows = []
    for dirpath, _dirnames, filenames in os.walk(root):
        for fn in filenames:
            if fn.lower().endswith(".ebp"):
                full = os.path.join(dirpath, fn)
                rel = os.path.relpath(full, root).replace(os.sep, "/")
                rows.append((rel, os.path.getsize(full), sha256_file(full)))
    rows.sort()
    # Per-platform evidence TSV (mission deliverable: nome/sha/bytes/plataforma)
    with open(os.path.join(OUT, f"ebp_census_{platform.lower()}.tsv"), "w") as f:
        f.write("name\tsha256\tbytes\tplatform\n")
        for rel, size, sha in rows:
            f.write(f"{rel}\t{sha}\t{size}\t{platform}\n")
    return rows


def first_bytes(path, n=32):
    with open(path, "rb") as f:
        return f.read(n)


def name_prefix(rel):
    """Leading alphabetic prefix of the basename (event/obj naming is
    <prefix><number>.ebp, e.g. ssbt0200.ebp -> ssbt). Groups scripts by
    field/area without needing a semantic table."""
    base = rel.rsplit("/", 1)[-1]
    out = []
    for ch in base.lower():
        if ch.isalpha():
            out.append(ch)
        else:
            break
    return "".join(out) or "(other)"


def main():
    data = {}  # platform -> {relpath: (size, sha)}
    for platform, root in ROOTS.items():
        if not os.path.isdir(root):
            print(f"[WARN] missing root for {platform}: {root}", file=sys.stderr)
            data[platform] = {}
            continue
        rows = census(platform, root)
        data[platform] = {rel: (size, sha) for rel, size, sha in rows}
        print(f"{platform}: {len(rows)} .ebp files hashed")

    platforms = list(ROOTS)
    all_relpaths = sorted({r for d in data.values() for r in d})

    # ── Per-relpath parity classification ──
    classes = defaultdict(int)
    with open(os.path.join(OUT, "ebp_relpath_classes.tsv"), "w") as f:
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
    with open(os.path.join(OUT, "ebp_missing_detail.tsv"), "w") as f:
        f.write("missing_from\tname\tbytes\tsha256\tpresent_on\tfirst32hex(pc-steam)\n")
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
    with open(os.path.join(OUT, "ebp_crossnames.tsv"), "w") as f:
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
    with open(os.path.join(OUT, "ebp_variants_detail.tsv"), "w") as f:
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

    # ── Prefix breakdown (event/obj naming: ssbt/test/znkd/... per platform) ──
    sub = defaultdict(lambda: defaultdict(int))
    for p in platforms:
        for rel in data[p]:
            sub[name_prefix(rel)][p] += 1

    # ── Summary ──
    total_hashes = sum(len(d) for d in data.values())
    distinct_hashes = len(size_by_sha)
    with open(os.path.join(OUT, "ebp_summary.txt"), "w") as f:
        f.write("FFX .ebp family parity census — 2026-09-15 (PARITY-EBP)\n\n")
        f.write("Platforms (jppc root per side):\n")
        for p, r in ROOTS.items():
            f.write(f"  {p}: {r} -> {len(data[p])} files\n")
        f.write(f"\nTotal hashed entries: {total_hashes}\n")
        f.write(f"Distinct sha256: {distinct_hashes}\n")
        f.write(f"Distinct relpaths: {len(all_relpaths)}\n\n")
        f.write("Per-relpath classes:\n")
        for c, n in sorted(classes.items(), key=lambda kv: -kv[1]):
            f.write(f"  {c}: {n}\n")
        f.write("\nMissing per platform:\n")
        for p in platforms:
            miss = [r for r in all_relpaths if r not in data[p]]
            f.write(f"  {p}: {len(miss)} missing\n")
            for r in miss:
                f.write(f"    {r}\n")
        f.write(f"\nCross-name sha groups (same content, >1 relpath): {len(cross)}\n")
        f.write(f"Variant relpaths (same name, >1 hash): {len(variants)}\n")
        f.write("\nPrefix breakdown (files per platform):\n")
        for s in sorted(sub):
            f.write(f"  {s}: " + ", ".join(f"{p}={sub[s][p]}" for p in platforms) + "\n")
    print(open(os.path.join(OUT, "ebp_summary.txt")).read())


if __name__ == "__main__":
    main()
