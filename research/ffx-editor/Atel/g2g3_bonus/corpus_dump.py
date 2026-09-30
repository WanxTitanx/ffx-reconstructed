#!/usr/bin/env python3
# ── G2G3 BONUS cluster save-corpus dump — 154 real saves ──
#
# Lane: FFX-STRUCTURES / G2G3-BONUS · 2026-09-15 · Python stdlib only.
# Research tool, read-only.
#
# Corpus (per task spec):
#   Utilities/FFX_TAS_Python/tas_saves                                 (66)
#   Utilities/.../Extracted Saves/FFX  -> files "Steam"+"Switch"       (2)
#   /mnt/disco-velho/Backup C 2026-09-02/.../FINAL FANTASY X           (43)
#   /mnt/disco-velho/Old C/.../FINAL FANTASY X                         (43)
#
# Frame conventions (proven in FFX_G2G3_COUNTERS_2026-09-15):
#   file offset = Fh + 0x40   (0x40-byte Steam wrapper header)
#   Fh          = ATEL slot + 0x1EC
#   runtime     = save_ram@0x112CA90 + Fh
#
# The task called the targets "file offsets 0x305-0x31C"; the sibling doc's
# writer evidence (slots 0x119-0x130 <-> Fh 0x305-0x31C) fixes them as **Fh**.
# We still dump the literal-file-offset interpretation (Fh 0x2C5-0x2DC and
# Fh 0x40D/0x410/0x411) as a control column set so both readings are covered.

import os, json, struct
from collections import Counter

REPO = "/home/wanderson/Documents/ffx-editor-main"
OUT = os.path.join(REPO, "work/_g2g3_bonus")

DIRS = [
    (os.path.join(REPO, "Utilities/FFX_TAS_Python/tas_saves"), "tas"),
    (os.path.join(REPO, "Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX"), "xtr"),
    ("/mnt/disco-velho/Backup C 2026-09-02/Users/wande/Documents/SQUARE ENIX/FINAL FANTASY X&X-2 HD Remaster/FINAL FANTASY X", "bkC"),
    ("/mnt/disco-velho/Old C/Users/wande/Documents/SQUARE ENIX/FINAL FANTASY X&X-2 HD Remaster/FINAL FANTASY X", "oldC"),
]

# Only the two PC-format files in Extracted Saves/FFX
XTR_KEEP = {"Steam", "Switch"}

FH = 0x40  # file base

# Fh offsets to dump
BONUS = list(range(0x305, 0x31D))            # 24 u8
BONUS_SINGLE = [0x44D, 0x450, 0x451]
ALT = list(range(0x2C5, 0x2DD))              # literal-file-offset interp of 0x305..0x31C
ALT_SINGLE = [0x40D, 0x410, 0x411]           # literal-file interp of 0x44D/0x450/0x451
ANCHORS = {"scene": 0x00, "map": 0x04, "b8": 0xB8, "ba": 0xBA, "c54": 0xC54,
           "c60": 0xC60, "story": 0xBEC, "c20": 0xC20}


def u16(b, o): return b[o] | (b[o + 1] << 8)
def u32(b, o): return b[o] | (b[o+1] << 8) | (b[o+2] << 16) | (b[o+3] << 24)


def collect():
    files = []
    for d, tag in DIRS:
        if not os.path.isdir(d):
            print(f"MISSING {d}")
            continue
        for fn in sorted(os.listdir(d)):
            p = os.path.join(d, fn)
            if not os.path.isfile(p):
                continue
            if tag == "xtr" and fn not in XTR_KEEP:
                continue
            if os.path.getsize(p) != 26880:
                print(f"SKIP size {os.path.getsize(p)} {p}")
                continue
            files.append((tag, fn, p))
    return files


def main():
    files = collect()
    print(f"corpus files: {len(files)}")
    rows = []
    for tag, fn, p in files:
        b = open(p, 'rb').read()
        r = {"name": f"{tag}:{fn}", "path": p}
        r["scene"] = u16(b, FH + 0x00)
        r["map"] = u16(b, FH + 0x04)
        r["story"] = u16(b, FH + 0xBEC)
        r["c54"] = u32(b, FH + 0xC54)
        r["c60"] = u32(b, FH + 0xC60)
        r["b8"] = u32(b, FH + 0xB8)
        r["ba"] = u32(b, FH + 0xBA)
        for fh in BONUS:
            r[f"fh{fh:03x}"] = b[FH + fh]
        for fh in BONUS_SINGLE:
            r[f"fh{fh:03x}"] = b[FH + fh]
        for fh in ALT:
            r[f"alt{fh:03x}"] = b[FH + fh]
        for fh in ALT_SINGLE:
            r[f"alt{fh:03x}"] = b[FH + fh]
        r["c20f"] = struct.unpack('<f', b[FH + 0xC20:FH + 0xC24])[0]
        rows.append(r)

    with open(os.path.join(OUT, "corpus_dump.json"), 'w') as f:
        json.dump(rows, f, indent=0)

    # ── distributions ──
    rep = []
    rep.append(f"# corpus dump — {len(rows)} saves (file=Fh+0x40)\n")
    for fh in BONUS + BONUS_SINGLE:
        key = f"fh{fh:03x}"
        c = Counter(r[key] for r in rows)
        nz = sum(1 for r in rows if r[key] != 0)
        rep.append(f"Fh 0x{fh:03X} (slot 0x{fh-0x1EC:04x}, file 0x{fh+0x40:03x}): "
                   f"nonzero {nz}/{len(rows)}  dist={dict(sorted(c.items()))}")
    rep.append("\n# alternative literal-file-offset interpretation control:\n")
    for fh in ALT + ALT_SINGLE:
        key = f"alt{fh:03x}"
        c = Counter(r[key] for r in rows)
        nz = sum(1 for r in rows if r[key] != 0)
        rep.append(f"Fh 0x{fh:03X} (file 0x{fh+0x40:03x}): nonzero {nz}/{len(rows)}  dist={dict(sorted(c.items()))}")

    # ── per-save table (compact) ──
    rep.append("\n# per-save table: name scene map story | 305..31C hex | 44d 450 451\n")
    for r in rows:
        arr = ' '.join(f"{r[f'fh{fh:03x}']:02x}" for fh in BONUS)
        rep.append(f"{r['name']:44s} sc={r['scene']:4d} map={r['map']:4d} st={r['story']:5d} "
                   f"c60={r['c60']:3d} | {arr} | {r['fh44d']:3d} {r['fh450']:3d} {r['fh451']:3d}")

    txt = '\n'.join(rep)
    with open(os.path.join(OUT, "corpus_report.txt"), 'w') as f:
        f.write(txt)
    print(txt[:6000])


if __name__ == '__main__':
    main()
