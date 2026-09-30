#!/usr/bin/env python3
# ── clp_reader.py — PS2 FFX `menu.clp` palette-bank reader/validator ────────────
#
# Format verdict (docs/reverse/FFX_FMT_CLP_2026-09-17.md, lane Jarvis-FMT):
#   .clp is a fixed-size palette BANK file: N x 4096-byte banks; each bank is
#   16 records of 256 bytes; each record is 8 rows x 8 RGBA colors (4 B each,
#   byte order R,G,B,A; alpha follows the PS2 GS convention 0x00..0x80, with
#   0xFF used on opaque-black filler rows). There is NO magic, NO header, NO
#   offset table and NO pointer anywhere — every 4-byte word is a color.
#   The "8 x u32 BE header" reading in the 2026-08-19 doc is a coincidence:
#   row 0 of banks 0/1 is a black alpha-ramp (00 00 00 xx, xx increasing),
#   which merely *looks* like cumulative counts.
#
# Observed per-bank record motifs (menu.clp, jppc + uspc):
#   bank 0: {4 color rows, 2 x 000000FF rows, copy of rows 2-3}
#           -> 32-color palette + variant with first 16 entries masked black
#   bank 1: 8 color rows (no masks); rows 0-1 of each record are locale-tuned
#   bank 2: {C0, C1, C2, C2, C4..C7} — row 2 duplicated; CLUT slot0 = 00000000,
#           slot1 = 2C2C7B00 fixed prefix on many rows; 100% locale-shared
#   bank 3: {6 color rows + 2 x 000000FF} -> 48-color palette padded to 64
#
# stdlib only. Exit 0 if all input files validate.
# ──────────────────────────────────────────────────────────────────────────────
import os
import struct
import sys

BANK_SIZE = 4096
ROW_SIZE = 32          # 8 colors x 4 B
ROWS_PER_BANK = 128
REC_SIZE = 256         # 8 rows
RECS_PER_BANK = 16
BLACK_FF = (0, 0, 0, 0xFF)
TRANSPARENT = (0, 0, 0, 0)


def read_colors(data, off, n):
    """Return list of (r,g,b,a) tuples from data[off:off+4*n]."""
    return [tuple(data[off + 4 * i: off + 4 * i + 4]) for i in range(n)]


def classify_row(colors):
    """Classify one 8-color row. colors = list of 8 (r,g,b,a)."""
    if all(c == TRANSPARENT for c in colors):
        return "ZERO"
    if all(c == BLACK_FF for c in colors):
        return "BLACKFF"
    if all(c[0] == 0 and c[1] == 0 and c[2] == 0 for c in colors):
        return "BKRAMP"  # all-black alpha ramp (00 00 00 xx)
    return "COLOR"


def parse(data):
    """Parse a .clp blob -> dict with banks/records/rows + validation errors."""
    errors = []
    if len(data) == 0 or len(data) % BANK_SIZE != 0:
        raise ValueError(f"size {len(data)} is not a multiple of {BANK_SIZE}")
    banks = []
    for b in range(len(data) // BANK_SIZE):
        base = b * BANK_SIZE
        rows = [read_colors(data, base + r * ROW_SIZE, 8) for r in range(ROWS_PER_BANK)]
        records = [rows[u * 8:(u + 1) * 8] for u in range(RECS_PER_BANK)]
        banks.append({"index": b, "offset": base, "rows": rows, "records": records})
    return {"banks": banks, "errors": errors}


def motif_report(bank):
    """Per-record structural report: classify each row + intra-record dups."""
    out = []
    for u, rec in enumerate(bank["records"]):
        marks = []
        for j, row in enumerate(rec):
            cls = classify_row(row)
            dup = [k for k in range(8) if k != j and rec[k] == row]
            m = {"ZERO": "Z", "BLACKFF": "F", "BKRAMP": "b", "COLOR": "C"}[cls]
            if dup:
                m += "=r" + ",".join(str(x) for x in dup)
            marks.append(f"{j}:{m}")
        out.append((u, " ".join(marks)))
    return out


def validate(data, strict_menu=True):
    """Structural validation of a menu.clp-style blob. Returns list of issues."""
    issues = []
    parsed = parse(data)
    for bank in parsed["banks"]:
        for u, rec in enumerate(bank["records"]):
            for j, row in enumerate(rec):
                for k, c in enumerate(row):
                    if len(c) != 4:
                        issues.append(f"bank{bank['index']} rec{u} row{j} col{k}: truncated color")
                    # alpha sanity: PS2 GS alpha is 0..0x80; 0xFF seen on filler
                    # rows. Anything else in 0x81..0xFE is suspicious.
                    if 0x81 <= c[3] <= 0xFE:
                        issues.append(
                            f"bank{bank['index']} rec{u} row{j} col{k}: "
                            f"alpha 0x{c[3]:02X} outside GS range (not filler 0xFF)")
    return issues


def dump(path, verbose=False):
    data = open(path, "rb").read()
    parsed = parse(data)
    print(f"{path}: {len(data)} bytes = {len(parsed['banks'])} banks x {BANK_SIZE} B")
    issues = validate(data)
    for bank in parsed["banks"]:
        rows = bank["rows"]
        kinds = [classify_row(r) for r in rows]
        print(f"  bank {bank['index']} @0x{bank['offset']:04X}: "
              f"rows C={kinds.count('COLOR')} F={kinds.count('BLACKFF')} "
              f"b={kinds.count('BKRAMP')} Z={kinds.count('ZERO')}")
        if verbose:
            for u, marks in motif_report(bank):
                print(f"    rec{u:2d} (rows {u*8:3d}-{u*8+7:3d}): {marks}")
            for r, row in enumerate(rows):
                hexs = " ".join(f"{c[0]:02X}{c[1]:02X}{c[2]:02X}{c[3]:02X}" for c in row)
                print(f"      row{r:3d}: {hexs}  {kinds[r]}")
    if issues:
        for i in issues[:50]:
            print(f"  ISSUE: {i}")
        print(f"  -> {len(issues)} issue(s)")
        return False
    print("  -> OK")
    return True


def main(argv):
    paths = argv[1:] or [
        "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/menu/menu.clp",
        "/mnt/nvme-xpg/ffx_ps2/ffx/master/uspc/menu/menu.clp",
    ]
    verbose = False
    if paths and paths[0] == "-v":
        verbose, paths = True, paths[1:]
    ok = True
    for p in paths:
        if not os.path.exists(p):
            print(f"{p}: MISSING"); ok = False; continue
        ok = dump(p, verbose) and ok
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
