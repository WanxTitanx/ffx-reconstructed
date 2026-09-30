#!/usr/bin/env python3
"""atel_op_census.py — census ATEL opcodes inside FFX EV01 (.ebp) containers.

Maintained-by: Jarvis (research lane)
Purpose      : research-only tooling for the FFX ATEL/Event-VM reverse
               engineering effort. Walks a corpus directory for .ebp files,
               unwraps the EV01 container, locates the embedded ATEL script
               blob, and decodes ONLY the code region so data-region bytes are
               never mistaken for opcodes.

ATEL instruction encoding (proven @ FFX_Atel_FetchOpcode 0x869D00):
  - opcode byte < 0x80  -> 1-byte instruction
  - opcode byte >= 0x80 -> 3-byte instruction (u16 LE operand follows)
  - runtime opcode index = byte & 0x7F

Container layout (EV01, little-endian):
  +0x00  magic "EV01"
  +0x04  offset of embedded ATEL blob (commonly 0x40)

ATEL blob header (relative to blob base):
  +0x00  u32 code_len        size of the bytecode region
  +0x10  u32 total_len       blob size
  +0x30  u32 code_off        file offset of bytecode region
  +0x34  u16 sub_count
  +0x36  u16 worker_count
  +0x38  u16 worker0_off     start of worker-offset table

Usage:
    python3 atel_op_census.py <corpus_root> [more_roots...] [-o out.csv]

The CSV has one row per .ebp file with per-opcode counts for the REQ family
(0x36-0x3B, 0x45-0x53, 0x77-0x7A) plus aggregate columns for the B-prefix
family (0x47-0x49, 0x4C-0x4E, 0x51-0x53).
"""

import argparse
import collections
import csv
import os
import struct
import sys

def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]

def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]

# REQ-family opcodes of interest (runtime index after &0x7F strip)
REQ_OPS = {
    0x36: "REQ",    0x37: "REQSW",  0x38: "REQEW",
    0x39: "PREQ",   0x3A: "PREQSW", 0x3B: "PREQEW",
    0x45: "FREQ",   0x46: "TREQ",
    0x47: "BREQ",   0x48: "BFREQ",  0x49: "BTREQ",
    0x4A: "FREQSW", 0x4B: "TREQSW",
    0x4C: "BREQSW", 0x4D: "BFREQSW", 0x4E: "BTREQSW",
    0x4F: "FREQEW", 0x50: "TREQEW",
    0x51: "BREQEW", 0x52: "BFREQEW", 0x53: "BTREQEW",
    0x77: "REQWAIT", 0x78: "PREQWAIT", 0x79: "REQCHG", 0x7A: "ACTREQ",
}
B_OPS = (0x47, 0x48, 0x49, 0x4C, 0x4D, 0x4E, 0x51, 0x52, 0x53)
REQ_COLS = sorted(REQ_OPS)


def iter_ebp(roots):
    for root_dir in roots:
        for dirpath, _dirs, files in os.walk(root_dir):
            for fn in files:
                if fn.lower().endswith(".ebp"):
                    yield os.path.join(dirpath, fn)


def scan_blob(blob):
    """Return (hist, code_len, code_off, status)."""
    if len(blob) < 0x3C:
        return None, -1, -1, "skipped:blob-too-small"
    code_len = u32(blob, 0x00)
    code_off = u32(blob, 0x30)
    if not (0 < code_len < 0x800000 and 0 < code_off < len(blob)):
        return None, code_len, code_off, "skipped:bad-header"
    end = min(code_off + code_len, len(blob))
    hist = collections.Counter()
    i = code_off
    while i < end:
        op = blob[i]
        if op < 0x80:
            if op in REQ_OPS:
                hist[op] += 1
            i += 1
        else:
            if i + 3 > end:
                break
            i += 3
    return hist, code_len, code_off, "ok"


def scan_file(path):
    """Return a row dict or a skipped row dict."""
    try:
        data = open(path, "rb").read()
    except OSError as exc:
        return {"status": f"skipped:{exc}"}
    if data[:4] != b"EV01":
        return {"status": "skipped:not-EV01"}
    blob_off = u32(data, 0x04)
    if blob_off >= len(data):
        return {"status": "skipped:bad-EV01-offset"}
    hist, code_len, code_off, status = scan_blob(data[blob_off:])
    row = {"container": "EV01/ATEL", "code_len": code_len,
           "code_off": code_off, "blob_len": len(data) - blob_off,
           "status": status}
    if hist is not None:
        row["counts"] = hist
        row["b_ops"] = sum(hist.get(o, 0) for o in B_OPS)
    return row


def main():
    ap = argparse.ArgumentParser(description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("roots", nargs="+", help="corpus root directories")
    ap.add_argument("-o", "--out", help="CSV output path")
    ap.add_argument("--tag", action="append", default=[],
                    help="label per root, in order (default: dir name)")
    args = ap.parse_args()

    tags = args.tag if args.tag else [os.path.basename(r.rstrip("/")) or r
                                    for r in args.roots]
    if len(tags) != len(args.roots):
        tags = [os.path.basename(r.rstrip("/")) or r for r in args.roots]

    rows = []
    grand = collections.Counter()
    n_ok = n_skip = n_bfiles = 0
    for tag, root_dir in zip(tags, args.roots):
        for path in sorted(iter_ebp([root_dir])):
            rel = os.path.relpath(path, root_dir)
            r = scan_file(path)
            status = r.get("status", "?")
            if r.get("counts") is not None:
                n_ok += 1
                for op, c in r["counts"].items():
                    grand[op] += c
                if r.get("b_ops"):
                    n_bfiles += 1
            else:
                n_skip += 1
            rows.append([tag, rel, r.get("container", "?"),
                         r.get("code_len", -1), r.get("code_off", -1),
                         r.get("blob_len", -1), status,
                         r.get("b_ops", 0)]
                        + [r.get("counts", {}).get(o, 0) for o in REQ_COLS])

    hdr = (["build", "file", "container", "code_len", "code_off",
            "blob_len", "status", "b_ops"]
           + [REQ_OPS[o] for o in REQ_COLS])
    if args.out:
        with open(args.out, "w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(hdr)
            w.writerows(rows)
        print(f"wrote {args.out} ({len(rows)} rows)")
    else:
        w = csv.writer(sys.stdout)
        w.writerow(hdr)
        w.writerows(rows)
    print(f"scanned {n_ok} ok, {n_skip} skipped, "
          f"{n_bfiles} files with B-ops", file=sys.stderr)
    print("REQ-family totals:", file=sys.stderr)
    for op in REQ_COLS:
        if grand[op]:
            print(f"  {REQ_OPS[op]:9s} 0x{op:02X} = {grand[op]}",
                  file=sys.stderr)


if __name__ == "__main__":
    main()
