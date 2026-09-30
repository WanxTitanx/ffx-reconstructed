#!/usr/bin/env python3
# ── PARITY-VPA census: .vpa family (MAP1 "mapout" map/battle containers) across
#    the 4 local FFX platform copies ──
# Purpose: hash every *.vpa under ffx_ps2/ffx/master/jppc in the 4 local platform
#          copies (PC-Steam VBF extraction, PS3 PSARC extraction, PS4 FFX_Data_P1
#          extraction, PC repack VBF extraction) and classify per-relative-path
#          parity (identical / variant / missing). Every .vpa is named
#          mapout.vpa and lives in map/<area>/<sub>/bin/ or
#          btlmap/<area>/<sub>/bin/ (verified before writing this; zero .vpa
#          outside jppc), so the RELPATH is the map identity — the census is a
#          per-map comparison, not per-filename.
# Why: corpus-debt rule 5-e follow-up — the .chr/.ebp audits flagged .vpa as
#      491/350/491/491 with PS3 at -141 (vs .ebp's -14). This script generates
#      the evidence for FFX_PARITY_VPA_2026-09-15.md: which relpaths are
#      missing, whether their CONTENT survives on PS3 under another path,
#      whether the 350 shared relpaths carry revised bytes, and whether every
#      absence is real in the FFX_Data.psarc manifest (extraction-gap check).
# Derived from: research_tools/QA/ebp_census.py (PARITY-EBP, 2026-09-15),
#   itself derived from chr_census.py (PARITY-CROSS). Adaptations vs ebp:
#   (a) glob *.vpa; (b) out work/_vpa_parity/; (c) group breakdown by
#   <tree>/<area> directory (map/azit, btlmap/kino) instead of filename prefix
#   (all files share the name mapout.vpa); (d) variant detail gains per-platform
#   FIRST-DIVERGENT-OFFSET + prefix/subset measurement vs the PC-Steam
#   reference copy (mission requires "how different", not just "different");
#   (e) stub detection — 64B/128B files that are MAP1 magic + all-zero offset
#   table (empty map shells); (f) missing-detail gains two verification
#   columns: in_ps3_manifest (relpath looked up in the full FFX_Data.psarc
#   listing — proves release-absence vs extraction-gap) and
#   ps3_content_elsewhere (the PC sha appearing under a DIFFERENT PS3 relpath —
#   proves rename/move rather than removal).
# Constraints: corpora under /mnt are READ-ONLY (open 'rb' only); all writes go
#          to work/_vpa_parity/.
# Maintenance: rerun with `python3 vpa_census.py` from anywhere (absolute paths).
#   Manifest path is the parity-ebp artifact (full 68,099-entry dump of
#   FFX_Data.psarc produced 2026-09-15); reuse, do not regenerate.

import hashlib
import os
import sys
from collections import defaultdict

OUT = "/home/wanderson/Documents/ffx-editor-main/work/_vpa_parity"
MANIFEST = "/home/wanderson/Documents/ffx-editor-main/artifacts/2026-09-15/parity-ebp/psarc_manifest_ffxdata.txt"

# Platform label -> jppc root. Labels follow the physical extraction source
# (per FFX_HD_CORPUS_IDENTITY_2026-09-04: the ffx_ps2 tree is the PS2-era
# payload re-carried by every HD remaster container; it is NOT PS2 disc media).
ROOTS = {
    "PC-Steam": "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc",
    "PS3-PSARC": "/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/FFXX2HDREMASTER/PSARC_EXTRACTED/FFX/ffx_ps2/ffx/master/jppc",
    "PS4-P1": "/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/PS4FFX/extracted/FFX_Data_P1/ffx_ps2/ffx/master/jppc",
    "PC-Repack": "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc",
}
REF = "PC-Steam"  # reference side for variant divergence measurements


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def is_stub(path, size):
    """Empty-map shell: MAP1 magic + an all-zero section-offset table.
    Observed sizes: 64 B (bare header) and 128 B (padded header)."""
    if size > 512:
        return False
    with open(path, "rb") as f:
        data = f.read()
    return data[:4] == b"MAP1" and data[4:] == b"\x00" * (size - 4)


def first_diff(a_path, b_path):
    """(first divergent byte offset, a_is_prefix_of_b, b_is_prefix_of_a).
    Streams both files in 1 MiB chunks; prefix flags answer the mission's
    'is one copy a prefix/subset of the other' question."""
    off = 0
    with open(a_path, "rb") as fa, open(b_path, "rb") as fb:
        while True:
            ca = fa.read(1 << 20)
            cb = fb.read(1 << 20)
            if ca == cb:
                if not ca:  # both exhausted, identical
                    return -1, True, True
                off += len(ca)
                continue
            n = min(len(ca), len(cb))
            for i in range(n):
                if ca[i] != cb[i]:
                    return off + i, False, False
            # shared prefix over this window; the shorter side ran out
            if len(ca) < len(cb):
                return off + n, True, False
            return off + n, False, True


def census(platform, root):
    """Return list of (relpath, size, sha256, stub?) for every *.vpa under root."""
    rows = []
    for dirpath, _dirnames, filenames in os.walk(root):
        for fn in filenames:
            if fn.lower().endswith(".vpa"):
                full = os.path.join(dirpath, fn)
                rel = os.path.relpath(full, root).replace(os.sep, "/")
                size = os.path.getsize(full)
                rows.append((rel, size, sha256_file(full), is_stub(full, size)))
    rows.sort()
    # Per-platform evidence TSV (mission deliverable: nome/sha/bytes/plataforma)
    with open(os.path.join(OUT, f"vpa_census_{platform.lower()}.tsv"), "w") as f:
        f.write("name\tsha256\tbytes\tplatform\tstub\n")
        for rel, size, sha, stub in rows:
            f.write(f"{rel}\t{sha}\t{size}\t{platform}\t{int(stub)}\n")
    return rows


def first_bytes(path, n=32):
    with open(path, "rb") as f:
        return f.read(n)


def area_group(rel):
    """<tree>/<area> directory pair (map/azit, btlmap/kino). Files are all named
    mapout.vpa, so the area dir is the only name-level grouping available."""
    parts = rel.split("/")
    return "/".join(parts[:2]) if len(parts) >= 2 else rel


def main():
    os.makedirs(OUT, exist_ok=True)
    data = {}   # platform -> {relpath: (size, sha)}
    stubs = {}  # platform -> set(relpath) of empty-shell files
    for platform, root in ROOTS.items():
        if not os.path.isdir(root):
            print(f"[WARN] missing root for {platform}: {root}", file=sys.stderr)
            data[platform] = {}
            stubs[platform] = set()
            continue
        rows = census(platform, root)
        data[platform] = {rel: (size, sha) for rel, size, sha, _s in rows}
        stubs[platform] = {rel for rel, _size, _sha, s in rows if s}
        print(f"{platform}: {len(rows)} .vpa files hashed ({len(stubs[platform])} stubs)")

    platforms = list(ROOTS)
    all_relpaths = sorted({r for d in data.values() for r in d})

    # ── PS3 manifest: full FFX_Data.psarc listing (release-content ground truth) ──
    manifest = set()
    if os.path.isfile(MANIFEST):
        with open(MANIFEST) as f:
            manifest = {ln.strip() for ln in f if ln.strip()}
    print(f"manifest entries loaded: {len(manifest)}")

    # sha -> relpaths per platform (for content-elsewhere checks)
    sha_to_rel = {p: defaultdict(set) for p in platforms}
    for p in platforms:
        for rel, (_s, sha) in data[p].items():
            sha_to_rel[p][sha].add(rel)

    # ── Per-relpath parity classification ──
    classes = defaultdict(int)
    rel_class = {}
    with open(os.path.join(OUT, "vpa_relpath_classes.tsv"), "w") as f:
        f.write("name\tclass\tstub\t" + "\t".join(platforms) + "\n")
        for rel in all_relpaths:
            shas = {p: data[p].get(rel, ("", ""))[1] for p in platforms}
            present = [p for p in platforms if rel in data[p]]
            distinct = {s for s in shas.values() if s}
            stub = "1" if any(rel in stubs[p] for p in platforms) else "0"
            if len(present) == len(platforms) and len(distinct) == 1:
                cls = "IDENTICAL-4"
            elif len(distinct) == 1:
                cls = f"IDENTICAL-PARTIAL(missing:{len(platforms)-len(present)})"
            elif len(distinct) > 1:
                cls = f"VARIANT({len(distinct)} hashes)"
            else:
                cls = "EMPTY"
            classes[cls] += 1
            rel_class[rel] = cls
            f.write(f"{rel}\t{cls}\t{stub}\t" + "\t".join(shas[p][:12] for p in platforms) + "\n")

    # ── Missing detail: exact relpaths absent per platform, with size/sha from
    #    the sides that DO carry them + manifest verification + content-elsewhere ──
    with open(os.path.join(OUT, "vpa_missing_detail.tsv"), "w") as f:
        f.write("missing_from\tname\tbytes\tsha256\tstub\tpresent_on\tin_ps3_manifest\tps3_content_elsewhere\tfirst32hex(pc-steam)\n")
        for p in platforms:
            for rel in all_relpaths:
                if rel not in data[p]:
                    present_on = ",".join(q for q in platforms if rel in data[q])
                    ref_p = next((q for q in platforms if rel in data[q]), None)
                    size, sha = data[ref_p][rel] if ref_p else (0, "")
                    is_st = "1" if ref_p and rel in stubs[ref_p] else "0"
                    in_man = ""
                    if p == "PS3-PSARC" and manifest:
                        in_man = "1" if f"/ffx_ps2/ffx/master/jppc/{rel}" in manifest else "0"
                    elsewhere = ""
                    if p == "PS3-PSARC" and sha:
                        hits = sorted(sha_to_rel["PS3-PSARC"].get(sha, ()))
                        elsewhere = ";".join(hits)
                    fb = ""
                    if ref_p and os.path.isfile(os.path.join(ROOTS[ref_p], rel)):
                        fb = first_bytes(os.path.join(ROOTS[ref_p], rel)).hex()
                    f.write(f"{p}\t{rel}\t{size}\t{sha}\t{is_st}\t{present_on}\t{in_man}\t{elsewhere}\t{fb}\n")

    # ── Cross-name content: sha under >1 distinct relpath (any platform) ──
    sha_to_names = defaultdict(set)
    for p in platforms:
        for rel, (_size, sha) in data[p].items():
            sha_to_names[sha].add(rel)
    cross = {sha: names for sha, names in sha_to_names.items() if len(names) > 1}
    with open(os.path.join(OUT, "vpa_crossnames.tsv"), "w") as f:
        f.write("sha256\tn_names\tn_platforms\tnames\n")
        for sha in sorted(cross, key=lambda s: -len(cross[s])):
            names = sorted(cross[sha])
            nplat = len({p for p in platforms for r in names if r in data[p]})
            f.write(f"{sha}\t{len(names)}\t{nplat}\t{';'.join(names)}\n")

    # ── Variant detail: same relpath, different content across platforms.
    #    For each side measure vs the PC-Steam copy: first divergent offset,
    #    size delta, prefix/subset relation. ──
    variants = []
    for rel in all_relpaths:
        shas = {p: data[p].get(rel) for p in platforms if rel in data[p]}
        if len({v[1] for v in shas.values()}) > 1:
            variants.append(rel)
    with open(os.path.join(OUT, "vpa_variants_detail.tsv"), "w") as f:
        f.write("name\tplatform\tbytes\tsize_delta_vs_ref\tfirst_diff_off_vs_ref\tprefix_of_ref\tref_is_prefix\tsha256\tfirst32hex\n")
        for rel in variants:
            ref_full = os.path.join(ROOTS[REF], rel) if rel in data[REF] else None
            ref_size = data[REF][rel][0] if ref_full else 0
            for p in platforms:
                if rel in data[p]:
                    full = os.path.join(ROOTS[p], rel)
                    size, sha = data[p][rel]
                    fd, a_pre, b_pre = (-1, "", "")
                    if ref_full and p != REF:
                        fd, a_pre, b_pre = first_diff(full, ref_full)
                    f.write(f"{rel}\t{p}\t{size}\t{size-ref_size if ref_full else ''}\t"
                            f"{fd if p != REF else ''}\t{a_pre}\t{b_pre}\t{sha}\t{first_bytes(full).hex()}\n")

    # ── Same-content different-size impossible; size-vs-sha sanity ──
    size_by_sha = {}
    for p in platforms:
        for rel, (size, sha) in data[p].items():
            size_by_sha.setdefault(sha, set()).add(size)
    multi_size = {s: v for s, v in size_by_sha.items() if len(v) > 1}
    assert not multi_size, f"sha collision across sizes (impossible): {multi_size}"

    # ── Area breakdown (map/<area>, btlmap/<area> per platform) ──
    sub = defaultdict(lambda: defaultdict(int))
    for p in platforms:
        for rel in data[p]:
            sub[area_group(rel)][p] += 1

    # ── Summary ──
    total_hashes = sum(len(d) for d in data.values())
    distinct_hashes = len(size_by_sha)
    with open(os.path.join(OUT, "vpa_summary.txt"), "w") as f:
        f.write("FFX .vpa family parity census — 2026-09-15 (PARITY-VPA)\n\n")
        f.write("Platforms (jppc root per side):\n")
        for p, r in ROOTS.items():
            f.write(f"  {p}: {r} -> {len(data[p])} files ({len(stubs[p])} stubs)\n")
        f.write(f"\nManifest: {MANIFEST} ({len(manifest)} entries)\n")
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
                ref_p = next((q for q in platforms if r in data[q]), None)
                size, sha = data[ref_p][r]
                tag = "STUB" if r in stubs.get(ref_p, set()) else "REAL"
                man = ""
                if p == "PS3-PSARC" and manifest:
                    man = " manifest=" + ("PRESENT" if f"/ffx_ps2/ffx/master/jppc/{r}" in manifest else "ABSENT")
                else_hits = sorted(sha_to_rel[p].get(sha, ())) if p in sha_to_rel else []
                f.write(f"    {r}  [{tag} {size}B sha:{sha[:12]}{man}"
                        + (f" content-on-{p}-as: {';'.join(else_hits)}" if else_hits else "")
                        + "]\n")
        f.write(f"\nCross-name sha groups (same content, >1 relpath): {len(cross)}\n")
        f.write(f"Variant relpaths (same name, >1 hash): {len(variants)}\n")
        f.write("\nArea breakdown (files per platform):\n")
        for s in sorted(sub):
            f.write(f"  {s}: " + ", ".join(f"{p}={sub[s][p]}" for p in platforms) + "\n")
    print(open(os.path.join(OUT, "vpa_summary.txt")).read())


if __name__ == "__main__":
    main()
