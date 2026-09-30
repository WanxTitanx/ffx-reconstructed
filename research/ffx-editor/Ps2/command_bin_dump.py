#!/usr/bin/env python3
# command_bin_dump.py — FFX PS2 battle/kernel/command.bin record dumper.
#
# Lane BTL-RESIDUAL (Jarvis-DEVIN, 2026-09-17). Layout cross-proven:
#   disk record == runtime kernel record verbatim, 96 B stride
#   (docs/reverse/FFX_BTL_DISPATCH_2026-09-17.md §5 — 11 fields byte-exact).
#
# File format (FFXProjectEditor/FfxLib/Common/EntryListFile.cs):
#   header 0x14 B: sig u8 | unk[7] | prevFileCount s16 | entryCount s16 (=N-1)
#                  | entrySize s16 (=96) | entryTableSize s16 | tableOff u32 (=0x14)
#   then N*96 B records, then the shared text pool (NameTSInfo.Offset @ +0x00
#   indexes into it; NUL-terminated FFX-encoded script).
#
# Usage:
#   command_bin_dump.py <command.bin> [--csv out.csv] [--od-join]
#                       [--sjistbl path/to/ffxsjistbl_us.bin] [--census]
#
# --od-join  prints the cmdId->OverdriveCategory join for the OD blocks
#            (0x3060-0x3067 stage cmds, 0x310A-0x3112 system ids) used by
#            FFX_OvDrive_CategoryCaseTable @0x7B03BC.
# --census   prints the +0x15 CasterAnimId distribution used by the
#            jpt_7AE6AF 30-case switch in FFX_BtlCmd_ApplySelectedCommand.

import argparse
import csv
import pathlib
import struct
import sys
from collections import Counter, defaultdict

REC = 96  # record stride (EntrySize)
HDR = 0x14

# Field offsets inside the 96 B record (Ability_Command.cs order).
FIELDS = [
    (0x10, "Anim1Id", "h"), (0x12, "Anim2Id", "h"), (0x14, "IconId", "B"),
    (0x15, "CasterAnimId", "B"), (0x16, "MenuFlgs", "B"),
    (0x17, "SubSubMenuCat", "B"), (0x18, "SubMenuCat", "B"),
    (0x19, "CharacterUser", "B"), (0x1A, "TargetFlgs", "B"),
    (0x1B, "TargetsAllowed", "B"), (0x1C, "Misc1Flgs", "B"),
    (0x1D, "Misc2Flgs", "B"), (0x1E, "Misc3Flgs", "B"), (0x1F, "Misc4Flgs", "B"),
    (0x20, "DamageFlgs", "B"), (0x21, "StealGil", "B"), (0x22, "PreviewFlgs", "B"),
    (0x23, "DamageTypeFlgs", "B"), (0x24, "MoveRank", "B"), (0x25, "CostMp", "B"),
    (0x26, "CostOverdrive", "B"), (0x27, "AttackCritBonus", "B"),
    (0x28, "DamageFormula", "B"), (0x29, "AttackAccuracy", "B"),
    (0x2A, "AttackPower", "B"), (0x2B, "HitCount", "B"),
    (0x2C, "ShatterChance", "B"), (0x2D, "ElementFlgs", "B"),
    (0x54, "StatusFlgs", "H"), (0x56, "StatBuffFlgs", "H"),
    (0x58, "OverdriveCategory", "B"), (0x59, "StatBuffValue", "B"),
    (0x5A, "SpecialBuffFlgs", "H"),
]

# Built-in US glyph table (byte-0x30 index), subset — same as
# research_tools/Encoding/ffx_text_dump.py builtin_table("us").
# Byte-value table (index = byte-0x30), from FfxEncoding.us.cs UsDecoder:
# 0x30='0' ... 0x6F=U+2018, 0x70='a' — NOTE: no backtick between '_' and U+2018.
US_SEQ = ("0123456789 !\u201D#$%&\u2019()*+,-./:;<=>?"
          "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\u2018"
          "abcdefghijklmnopqrstuvwxyz{|}~")
GLYPH_LEADS = {0x06} | set(range(0x26, 0x30))
CHARNAME = {0x30: "<TIDUS>", 0x31: "<YUNA>", 0x32: "<AURON>", 0x33: "<KIMAHRI>",
            0x34: "<WAKKA>", 0x35: "<LULU>", 0x36: "<RIKKU>", 0x37: "<SEYMOUR>",
            0x38: "<VALEFOR>", 0x39: "<IFRIT>", 0x3A: "<IXION>", 0x3B: "<SHIVA>",
            0x3C: "<BAHAMUT>", 0x3D: "<ANIMA>", 0x3E: "<YOJIMBO>",
            0x3F: "<CINDY>", 0x40: "<SANDY>", 0x41: "<MINDY>"}


def load_table(path):
    if path:
        return list(pathlib.Path(path).read_bytes().decode("utf-8"))
    return list(US_SEQ)


def decode_script(script, table):
    """Best-effort decode of one NUL-stripped FFX text script (US glyphs)."""
    out = []
    i = 0
    while i < len(script):
        b = script[i]
        if b == 0x00:
            i += 1
            continue
        if b == 0x03:  # newline
            out.append("\\n")
        elif b == 0x19 and i + 1 < len(script):  # char-name token
            out.append(CHARNAME.get(script[i + 1], f"<C19:{script[i+1]}>"))
            i += 1
        elif b in GLYPH_LEADS and i + 1 < len(script) and script[i + 1] >= 0x30:
            idx = 208 * b + script[i + 1] - 8992
            out.append(table[idx] if 0 <= idx < len(table) else f"<G{idx}>")
            i += 1
        elif b >= 0x30:
            idx = b - 0x30
            out.append(table[idx] if idx < len(table) else f"<{b:02X}>")
        else:
            out.append(f"<{b:02X}>")
        i += 1
    return "".join(out)


def read_cstr(b, off):
    if off < 0 or off >= len(b):
        return b""
    end = b.find(b"\x00", off)
    return b[off:] if end < 0 else b[off:end]


def parse(path, id_base=0x3000):
    d = pathlib.Path(path).read_bytes()
    prev, count_m1, esize, tsize = struct.unpack_from("<4h", d, 8)
    toff, = struct.unpack_from("<I", d, 16)
    n = count_m1 + 1 - prev
    assert esize in (REC, 92), f"unexpected entry size {esize}"  # 92 = monmagic (no ExtraInfo)
    table = d[toff:toff + n * esize]
    pool = d[toff + n * esize:]
    recs = []
    for i in range(n):
        r = table[i * esize:(i + 1) * esize]
        row = {"index": i, "cmdId": id_base | i,
               "name_off": struct.unpack_from("<H", r, 0x00)[0],
               "desc_off": struct.unpack_from("<H", r, 0x08)[0]}
        for off, name, fmt in FIELDS:
            row[name] = struct.unpack_from("<" + fmt, r, off)[0]
        recs.append(row)
    return recs, pool


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("bin")
    ap.add_argument("--csv")
    ap.add_argument("--sjistbl")
    ap.add_argument("--census", action="store_true")
    ap.add_argument("--od-join", action="store_true")
    a = ap.parse_args()

    recs, pool = parse(a.bin)
    table = load_table(a.sjistbl)
    for r in recs:
        r["name"] = decode_script(read_cstr(pool, r["name_off"]), table)

    hdr = [c for c in ("index", "cmdId", "name")] + [n for _, n, _ in FIELDS]
    if a.csv:
        with open(a.csv, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=hdr, extrasaction="ignore")
            w.writeheader()
            for r in recs:
                row = dict(r)
                row["cmdId"] = f"0x{r['cmdId']:04X}"
                w.writerow(row)
        print(f"wrote {len(recs)} rows -> {a.csv}", file=sys.stderr)

    if a.census:
        c = Counter(r["CasterAnimId"] for r in recs)
        fam = defaultdict(list)
        for r in recs:
            fam[r["CasterAnimId"]].append(f"0x{r['cmdId']:04X}:{r['name']}")
        for v in sorted(c):
            names = ", ".join(fam[v][:14])
            more = f" ... +{len(fam[v])-14}" if len(fam[v]) > 14 else ""
            print(f"CasterAnimId={v:3d}  n={c[v]:3d}  {names}{more}")

    if a.od_join:
        want = list(range(0x3060, 0x3068)) + list(range(0x310A, 0x3113))
        print("cmdId   idx  name                     ODcat Anim CstrAnim HitCnt Pow Formula PrevFlgs")
        for cid in want:
            r = recs[cid & 0xFFF]
            print(f"0x{cid:04X}  {r['index']:3d}  {r['name'][:22]:22} "
                  f"{r['OverdriveCategory']:4d} {r['Anim1Id']:5d} "
                  f"{r['CasterAnimId']:8d} {r['HitCount']:5d} {r['AttackPower']:4d} "
                  f"{r['DamageFormula']:6d} 0x{r['PreviewFlgs']:02X}")


if __name__ == "__main__":
    main()
