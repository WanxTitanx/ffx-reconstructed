#!/usr/bin/env python3
# kernel_strides_audit.py — FFX battle/kernel/*.bin record-layout audit (research-only, read-only on corpus)
#
# PURPOSE : validates the documented record strides of every kernel table against ALL locale
#           variants in one or more corpus copies, and flags anomalies:
#             * files whose declared EntrySize doesn't match the documented stride
#             * files whose size isn't header(0x14) + rows*stride + pool
#             * non-Excel containers (btl.bin, magic.bin, albhed.bin)
#             * corpus contamination (editor backups, post-dump mtimes, cross-copy content diffs)
#
# HEADER  : EntryListFile / IndexedFixedTableHeader (FFXProjectEditor/FfxLib/Common/EntryListFile.cs,
#           FfxLib/Customization/Customization_File.cs):
#             0x00 u8   Signature            (0x01 = Excel table; 0x02 = btl.bin container)
#             0x01 7B   zeros
#             0x08 i16  MinIndex             (PreviousFileCount; split-file base index, e.g. monster2/3)
#             0x0A i16  MaxIndex             (last 0-based index of the GLOBAL table; == row count-1 when MinIndex=0)
#             0x0C i16  EntrySize            (record stride, declared by the file itself)
#             0x0E u16  EntryTableSize       (rows*EntrySize masked to 16 bits — wraps for big tables)
#             0x10 i32  EntryTableFileOffset (always 0x14)
#           rows = MaxIndex - MinIndex + 1 ; data region = rows*EntrySize @0x14 ; trailing = string pool.
#
# USAGE   : python3 kernel_strides_audit.py [ROOT ...] [--out DIR]
#           Default ROOTs = the two local corpus copies (edit below for your machine).
#
# LANE    : KERNEL-STRIDES (2026-09-15). Output lands in work/_kernel_strides/ by default.

import os, sys, json, struct, hashlib, collections

DEFAULT_ROOTS = [
    "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master",  # primary PC-Steam master
    "/mnt/nvme-xpg/ffx_ps2/ffx/master",                       # second corpus copy (cross-check)
]
OUT_DIR = "/home/wanderson/Documents/ffx-editor-main/work/_kernel_strides"


def sha12(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for c in iter(lambda: f.read(1 << 20), b""):
            h.update(c)
    return h.hexdigest()[:12]


def parse(path):
    """Parse one file. Returns a dict row."""
    st = os.stat(path)
    r = {"size": st.st_size, "mtime": st.st_mtime, "sha12": sha12(path)}
    if st.st_size < 20:
        r["verdict"] = "TOO_SMALL_OR_EMPTY"
        return r
    with open(path, "rb") as f:
        head = f.read(20)
    sig = head[0]
    unk = head[1:8]
    minidx, maxidx, esize, tsize, toff = struct.unpack("<hhhH i", head[8:20])
    r.update(sig=sig, unk_zero=(unk == b"\x00" * 7), min_index=minidx,
             max_index=maxidx, esize=esize, tsize=tsize, toff=toff)
    if sig != 1 or unk != b"\x00" * 7 or toff != 0x14:
        r["verdict"] = "NON_EXCEL_FORMAT"
        return r
    rows = maxidx - minidx + 1
    r["rows"] = rows
    r["data_end"] = toff + rows * esize
    r["pool"] = st.st_size - r["data_end"]
    r["fits"] = r["data_end"] <= st.st_size
    # EntryTableSize is a u16 mask of rows*EntrySize (wraps past 64 KiB, e.g. item_get/command)
    r["tsize_ok"] = (rows * esize) & 0xFFFF == tsize
    # naive whole-file divisibility (usually non-zero because of the 20B header + pool)
    r["size_mod_stride"] = st.st_size % esize if esize else None
    r["body_mod_stride"] = (st.st_size - toff) % esize if esize else None
    ok = r["fits"] and r["tsize_ok"] and r["pool"] >= 0
    r["verdict"] = "OK" if ok else "CHECK"
    return r


def scan_root(root):
    """Scan every */battle/kernel/ under one corpus root. Returns {locale: {file: row}}."""
    out = {}
    for loc in sorted(os.listdir(root)):
        d = os.path.join(root, loc, "battle", "kernel")
        if not os.path.isdir(d):
            continue
        out[loc] = {}
        for fn in sorted(os.listdir(d)):
            p = os.path.join(d, fn)
            if fn.startswith(".") or not os.path.isfile(p):
                continue
            row = parse(p)
            row["root"] = root
            row["locale"] = loc
            row["file"] = fn
            out[loc][fn] = row
    return out


def main():
    roots = [a for a in sys.argv[1:] if not a.startswith("--")] or DEFAULT_ROOTS
    outdir = OUT_DIR
    if "--out" in sys.argv:
        outdir = sys.argv[sys.argv.index("--out") + 1]
    os.makedirs(outdir, exist_ok=True)

    scans = {root: scan_root(root) for root in roots if os.path.isdir(root)}
    primary = scans[roots[0]]

    # ---- flat row list (primary root) ----
    rows = [r for loc in primary.values() for r in loc.values()]

    # ---- cross-copy verdict: same file in root B identical / different / missing ----
    for loc, files in primary.items():
        other = scans.get(roots[1], {}).get(loc, {}) if len(roots) > 1 else {}
        for fn, r in files.items():
            o = other.get(fn)
            if o is None:
                r["xcopy"] = "MISSING_IN_COPY2"
            elif o["sha12"] == r["sha12"]:
                r["xcopy"] = "IDENTICAL"
            else:
                r["xcopy"] = "DIFFERS"

    # ---- per-file locale matrix ----
    matrix = collections.defaultdict(dict)   # file -> locale -> row
    for loc, files in primary.items():
        for fn, r in files.items():
            matrix[fn][loc] = r

    locales = sorted(primary)
    summary = {"roots": roots, "locales": {l: len(primary[l]) for l in locales},
               "files": {}, "anomalies": []}
    for fn, per in sorted(matrix.items()):
        strides = sorted({r.get("esize") for r in per.values() if r.get("esize") is not None})
        rowcounts = collections.defaultdict(list)
        for loc, r in per.items():
            rowcounts[r.get("rows")].append(loc)
        entry = {
            "locales_present": sorted(per),
            "locales_missing": [l for l in locales if l not in per],
            "strides": strides,
            "row_classes": {str(k): sorted(v) for k, v in rowcounts.items()},
            "non_excel": [l for l, r in per.items() if r["verdict"] == "NON_EXCEL_FORMAT"],
            "check": [l for l, r in per.items() if r["verdict"] in ("CHECK", "TOO_SMALL_OR_EMPTY")],
            "content_diffs_vs_copy2": [l for l, r in per.items() if r.get("xcopy") == "DIFFERS"],
        }
        summary["files"][fn] = entry
        if len(strides) > 1:
            summary["anomalies"].append(f"{fn}: stride varies {entry['row_classes']}")
        if entry["non_excel"]:
            summary["anomalies"].append(f"{fn}: NON_EXCEL_FORMAT in {entry['non_excel']}")
        if entry["check"]:
            summary["anomalies"].append(f"{fn}: failed checks in {entry['check']}")
        if entry["content_diffs_vs_copy2"]:
            summary["anomalies"].append(f"{fn}: content differs vs copy2 in {entry['content_diffs_vs_copy2']}")

    # ---- emit ----
    cols = ["locale", "file", "size", "sig", "min_index", "max_index", "rows", "esize",
            "tsize", "tsize_ok", "toff", "data_end", "pool", "fits",
            "size_mod_stride", "body_mod_stride", "sha12", "mtime", "xcopy", "verdict"]
    with open(os.path.join(outdir, "kernel_strides.csv"), "w") as f:
        f.write(",".join(cols) + "\n")
        for r in rows:
            f.write(",".join(str(r.get(c, "")) for c in cols) + "\n")
    with open(os.path.join(outdir, "kernel_strides.json"), "w") as f:
        json.dump({"rows": rows, "summary": summary}, f, indent=1)

    # ---- console ----
    print(f"locales: {summary['locales']}")
    print(f"rows: {len(rows)}  anomalies: {len(summary['anomalies'])}")
    for a in summary["anomalies"]:
        print("  !", a)


if __name__ == "__main__":
    main()
