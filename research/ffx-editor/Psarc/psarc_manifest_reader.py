#!/usr/bin/env python3
# psarc_manifest_reader.py — reader/validator for PS4 `PSArcManifest.bin`
# chunk manifests (stdlib-only, read-only).
#
# Lane: ARCHIVE-R2 (2026-09-17), closing the FMT-ARCHIVE audit UNKNOWN
# "PSArcManifest.bin — 29 PS4 files, no parser"
# (docs/reverse/FFX_FMT_ARCHIVE_AUDIT_2026-09-16.md §6.1).
#
# FORMAT (proven 2026-09-17 on the 29-file corpus at
# /mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/PS4FFX/extracted/):
#   The file is NOT binary despite the .bin name — it is the same payload a
#   PSARC stores as entry 0: UTF-8 text, one absolute path per line,
#   LF-separated, NO trailing newline, no NUL, no CR, no header, no footer.
#   Each `FFX{,-2}_Data_PN/PSArcManifest.bin` lists the entries of the
#   matching PS4 chunk archive (`..._PN.psarc` split, per the sibling
#   `.psarc-cl-settings`: compressionType=zlib / blockSize=65536 /
#   pathType=absolute / endianness=big — i.e. identical build params to the
#   PS3 PSAR 1.4 archives).
#   Lines are in ARCHIVE ORDER, not sorted. The same path may appear in
#   several chunk manifests (PS4 playgo-style replication: e.g. FFX-2 voice
#   files ship in P1,P5,P6,P7,P8), but never twice inside one manifest.
#
# ORACLE: the PS3 `FFX_Data.psarc` / `FFX-2_Data.psarc` entry-0 manifest text
# (68,100 / 99,281 names) cross-checks the PS4 unions (69,100 / 111,001) —
# deltas are platform content changes (GCM->GNMX shaders, LocKit .BIN case,
# PS4Data/Sound_PS4 additions), not format deviations.
#
# USAGE
#   psarc_manifest_reader.py FILE...           validate + per-file stats
#   psarc_manifest_reader.py DIR               scan DIR/*/PSArcManifest.bin
#   psarc_manifest_reader.py DIR --union       print the union set + overlap
#   psarc_manifest_reader.py FILE --list       print all lines
#   psarc_manifest_reader.py DIR --cross ORACLE.txt [--ci]
#       diff union(manifests) vs a PS3 psarc entry-0 manifest text file
#   psarc_manifest_reader.py DIR --verify-tree
#       assert every manifest line == one file on disk inside the chunk dir
#       (and no extra payload files on disk)
#
# Exit 0 when every check passes; 1 on any FAIL.
#
# NOTE: the USAGE text lives in this comment header, NOT a module docstring —
# keep the `--help` fallback below in sync if this block moves.
_USAGE_TEXT = """\
psarc_manifest_reader.py FILE...           validate + per-file stats
psarc_manifest_reader.py DIR               scan DIR/*/PSArcManifest.bin
psarc_manifest_reader.py DIR --union       print the union set + overlap
psarc_manifest_reader.py FILE --list       print all lines
psarc_manifest_reader.py DIR --cross ORACLE.txt [--ci]
    diff union(manifests) vs a PS3 psarc entry-0 manifest text file
psarc_manifest_reader.py DIR --verify-tree
    assert every manifest line == one file on disk inside the chunk dir
    (and no extra payload files on disk)
"""

# Evidence: work/_archive_r2/psarc_manifest_*.txt; doc:
# docs/reverse/FFX_FMT_ARCHIVE_R2_2026-09-17.md §1.

import os
import re
import sys
from collections import Counter


def read_manifest(path):
    """Parse one PSArcManifest.bin -> (names[list[str]], problems[list[str]]).

    Validation rules (all proven on the 29-file corpus):
      * bytes are ASCII-clean (no NUL, no CR, no byte >= 0x80)
      * LF-separated, no trailing newline, no empty lines
      * every line is an absolute path ('/'-prefixed)
      * no duplicate path inside one manifest
    """
    d = open(path, "rb").read()
    problems = []
    if d.count(b"\x00"):
        problems.append("contains NUL bytes")
    if d.count(b"\r"):
        problems.append("contains CR bytes")
    hi = sum(1 for b in d if b >= 0x80)
    if hi:
        problems.append("contains %d non-ASCII bytes" % hi)
    if d.endswith(b"\n"):
        problems.append("trailing newline present (corpus has none)")
    lines = [l for l in d.split(b"\n") if l]
    if len(lines) != d.count(b"\n") + (1 if d else 0):
        problems.append("empty lines inside")
    nonabs = [l for l in lines if not l.startswith(b"/")]
    if nonabs:
        problems.append("%d non-absolute lines (e.g. %r)" % (len(nonabs), nonabs[:1]))
    names = [l.decode("ascii") for l in lines]
    dup = len(names) - len(set(names))
    if dup:
        problems.append("%d duplicate lines inside manifest" % dup)
    return names, problems


def chunk_key(path):
    m = re.search(r"_P(\d+)", os.path.basename(os.path.dirname(path)))
    return int(m.group(1)) if m else 0


def collect(targets):
    """Expand dirs to their */PSArcManifest.bin children (chunk-sorted)."""
    files = []
    for t in targets:
        if os.path.isdir(t):
            for root, _ds, fs in os.walk(t):
                for f in fs:
                    if f == "PSArcManifest.bin":
                        files.append(os.path.join(root, f))
        else:
            files.append(t)
    return sorted(set(files), key=lambda p: (os.path.dirname(p), chunk_key(p)))


def main(argv):
    do_list = "--list" in argv
    do_union = "--union" in argv
    do_vt = "--verify-tree" in argv
    ci = "--ci" in argv
    cross = None
    args = []
    it = iter(range(len(argv)))
    i = 0
    while i < len(argv):
        a = argv[i]
        if a == "--cross" and i + 1 < len(argv):
            cross = argv[i + 1]
            i += 2
            continue
        if not a.startswith("--"):
            args.append(a)
        i += 1
    if not args:
        print(_USAGE_TEXT.strip())
        return 2

    files = collect(args)
    if not files:
        print("no PSArcManifest.bin found under:", args)
        return 1

    ok = True
    union = set()
    seen_in = {}
    for f in files:
        names, problems = read_manifest(f)
        ok = ok and not problems
        chunk = os.path.basename(os.path.dirname(f)) or os.path.dirname(f)
        print("[%-4s] %-60s lines=%6d" % ("OK" if not problems else "FAIL",
              f if len(f) <= 60 else "…" + f[-59:], len(names)))
        for p in problems:
            print("       FAIL %s" % p)
        for n in names:
            union.add(n)
            seen_in.setdefault(n, []).append(chunk)
        if do_list:
            for n in names:
                print("  %s" % n)
        if do_vt:
            root = os.path.dirname(f)
            onset = set(n.lstrip("/") for n in names)
            missing = [n for n in onset
                       if not os.path.isfile(os.path.join(root, n))]
            extra = []
            for r, _ds, fs in os.walk(root):
                for fn in fs:
                    rel = os.path.relpath(os.path.join(r, fn), root)
                    if rel not in onset and rel not in ("PSArcManifest.bin",
                                                        ".psarc-cl-settings"):
                        extra.append(rel)
            good = not missing and not extra
            ok = ok and good
            print("       verify-tree: manifest=%d missing=%d extra=%d %s"
                  % (len(onset), len(missing), len(extra),
                     "OK" if good else "FAIL"))
            for m in missing[:5]:
                print("         missing: %s" % m)
            for e in extra[:5]:
                print("         extra:   %s" % e)

    total = sum(len(v) for v in [seen_in])  # noqa: F841 (clarity)
    total_lines = sum(len(v) for v in seen_in.values())
    dup_across = {k: v for k, v in seen_in.items() if len(v) > 1}
    print("files=%d total_lines=%d union=%d cross_chunk_dups=%d (max_copies=%d)"
          % (len(files), total_lines, len(union), len(dup_across),
             max((len(v) for v in dup_across.values()), default=0)))

    if do_union:
        for n in sorted(union):
            print(n)

    if cross:
        oracle = set()
        for l in open(cross, "rb").read().split(b"\n"):
            if l.strip():
                oracle.add(l.decode("utf-8", "replace").strip())
        a, b = union, oracle
        if ci:
            amap = {n.lower(): n for n in a}
            bmap = {n.lower(): n for n in b}
            aa, bb = set(amap), set(bmap)
        else:
            aa, bb = a, b
        only_a, only_b, common = aa - bb, bb - aa, aa & bb
        print("cross vs %s (%s): oracle=%d union=%d common=%d "
              "manifest-only=%d oracle-only=%d"
              % (cross, "ci" if ci else "exact", len(b), len(a), len(common),
                 len(only_a), len(only_b)))
        tops = Counter(n.split("/")[2] if n.count("/") > 2 else n
                       for n in only_a)
        print("  manifest-only top-dirs: %s" % tops.most_common(6))
        tops = Counter(n.split("/")[2] if n.count("/") > 2 else n
                       for n in only_b)
        print("  oracle-only top-dirs:   %s" % tops.most_common(6))
        for n in sorted(only_a)[:5]:
            print("   + %s" % (amap[n] if ci else n))
        for n in sorted(only_b)[:5]:
            print("   - %s" % (bmap[n] if ci else n))
        # sanity floor: a real oracle must share a large common core
        if len(common) * 4 < len(aa):
            print("   WARN common core < 25%% of union — wrong oracle?")
            ok = False

    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
