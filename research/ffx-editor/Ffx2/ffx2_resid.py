#!/usr/bin/env python3
# ffx2_resid.py — FFX-2 save-format RESIDUALS research tool (wave-14, Jarvis-FFX2-RESIDUALS)
#
# Purpose: decode the regions that wave-13 (ffx2_savemap.py) left unmapped:
#   * PS2-era wraps (54296/54312-byte files, different payload layout, 0x70-stride records)
#   * charset-table name decoding for non-US saves (ffx2sjistbl_{us,jp,kr,ch,cn}.bin)
#   * PlySave creature tail (+0x58..+0x77 modern / +0x58..+0x6F PS2) statistical profile
#   * modern GAP regions nonzero/variance profile
#
# Research-only. Stdlib only. Does not touch product code.
#
# Usage:
#   python3 ffx2_resid.py ps2 <savefile>                # dump PS2-era field map
#   python3 ffx2_resid.py names <savefile> [--tbl BIN]  # decode name strings w/ charset table
#   python3 ffx2_resid.py tail <corpus.txt>             # modern creature-tail u16 profile
#   python3 ffx2_resid.py gaps <corpus.txt>             # gap-region activity profile
#
# corpus.txt format: one save per line "size\ttag\thash\tpath" (see work/_ffx2fields/corpus.txt)
# sjistbl paths default to the extracted-assets location; override with --tbl or FFX2_TBL_DIR.

import os
import struct
import sys
import collections

TBL_DIR_DEFAULTS = [
    os.environ.get("FFX2_TBL_DIR", ""),
    "/mnt/nvme-samsung/FFX Extracted/FFX2/ffx_ps2/ffx2/master/jppc/ffx2_encoding",
    "work/_ffx2fields",
]

# ---------------------------------------------------------------- charset ---

def load_table(lang):
    """Load ffx2sjistbl_<lang>.bin (UTF-8 glyph table indexed by charset byte)."""
    for d in TBL_DIR_DEFAULTS:
        if not d:
            continue
        p = os.path.join(d, f"ffx2sjistbl_{lang}.bin")
        if os.path.exists(p):
            return open(p, "rb").read().decode("utf-8")
    return None


def dec_name(bs, tbl):
    """Decode one NUL-terminated name string. Bytes < 0x30 introduce a 2-byte
    multibyte index: idx = (b - 0x2B) * 208 + (lo - 0x30). Others index directly."""
    if tbl is None:
        return f"<no table: {bs.hex()}>"
    out = []
    i = 0
    while i < len(bs):
        b = bs[i]
        if b == 0:
            break
        if b < 0x30 and i + 1 < len(bs):
            lo = bs[i + 1]
            idx = (b - 0x2B) * 208 + (lo - 0x30)
            out.append(tbl[idx] if 0 <= idx < len(tbl) else f"<{b:02X}{lo:02X}>")
            i += 2
        else:
            out.append(tbl[b - 0x30] if 0 <= b - 0x30 < len(tbl) else "?")
            i += 1
    return "".join(out)


def dec_blob(data, tbl, limit=64):
    """Split a packed NUL-separated blob and decode each entry."""
    names = []
    for raw in data.split(b"\x00"):
        if not raw:
            continue
        names.append(dec_name(raw, tbl))
        if len(names) >= limit:
            break
    return names

# ------------------------------------------------------------- ps2 layout ---

# PS2-era file offsets (54296/54312-byte files). Evidence: save_e3_00/01 +
# converter "PS2 (north america)" — all three share these anchors.
PS2_FIELDS = [
    (0x0000, 0x0040, "header",        "PS2 header; +0x30 u32 = lead-name prefix (charset bytes of e.g. 'Yuna')"),
    (0x00F4, 0x0020, "u16blk",        "room/eventjump state block (u16 room ids, differs per save)"),
    (0x0C2C, 0x0004, "u32",           "story_progress (600 / 2760 / 5300 across corpus)"),
    (0x118C, 0x0004, "u32",           "current_chapter (1 / 3 / 5 across corpus)"),
    (0x1D40, 0x0250, "glyph_tables",  "embedded glyph-order tables (charset UI data, 'd'/'(' fill)"),
    (0x7810, 0x0050, "btl_party",     "btl_party analog: +0x00 gil? u32, +0x04 u32, +0x08 time-ish u32, +0x14 party[3]+atb, +0x18 item_type u16[] (na has +0x10 extra, offsets shift)"),
    (0x7970, 0x0340, "u16arr",        "inventory_ids u16[] (0x20XX item ids; empty slot = 0x00FF)"),
    (0x7CB4, 0x0100, "u16arr",        "accessory_ids u16[0x80] (0x90XX; empty = 0x00FF)"),
    (0x7DB0, 0x0080, "fill0x63",      "default-names scratch region (0x63 fill)"),
    (0x7E30, 0x0220, "bitfields",     "monster_meet/defeat + important-item bitfields"),
    (0x81E0, 0x0590, "ply_records_a", "ply_save records, 0x70 stride (active party/creature slots)"),
    (0x8770, 0x0024, "name_blob",     "packed name blob referenced by record name{ofs,id} (US-charset in e3 demo)"),
    (0x8790, 0x0490, "ply_records_b", "ply_save records, 0x70 stride (template/remaining creature slots)"),
    (0x8C30, 0x3A60, "friend_mon",    "friend_monster records x9, 0x6A0 stride (u16 stat block ~+0x30)"),
    (0xC792, 0x021C, "u16recs",       "9 x 0x3C records: 7x u16 0x30XX ability/command ids + pad"),
    (0xC9B0, 0x0190, "creature_names","creature/team name strings (NUL-separated charset blob)"),
    (0xD0F0, 0x0128, "tail",          "end fields + trailer (checksum/pad; ps2na has +0x10 extra)"),
]


def cmd_ps2(path, lang=None):
    d = open(path, "rb").read()
    print(f"== {os.path.basename(path)} ({len(d)} bytes) ==")
    print(f"hdr+0x30 name-tag: {d[0x30:0x34].hex()}")
    print(f"story_progress  @0xC2C  : {struct.unpack_from('<I', d, 0xC2C)[0]}")
    print(f"current_chapter @0x118C : {struct.unpack_from('<I', d, 0x118C)[0]}")
    print(f"gil?            @0x7810 : {struct.unpack_from('<I', d, 0x7810)[0]}")
    print(f"u32             @0x7814 : {struct.unpack_from('<I', d, 0x7814)[0]}")
    print(f"time-ish/seed   @0x7818 : {struct.unpack_from('<I', d, 0x7818)[0]}")
    print(f"party/items     @0x7824 : {d[0x7824:0x7830].hex()}")
    items = struct.unpack_from("<16H", d, 0x7970)
    acc = struct.unpack_from("<8H", d, 0x7CB4)
    print(f"inventory_ids   @0x7970 : {[hex(v) for v in items]}")
    print(f"accessory_ids   @0x7CB4 : {[hex(v) for v in acc]} ...")
    # records: scan 0x81E0..0x8C30 for 0x70-stride records w/ plausible stats
    print("ply records (0x70 stride):")
    for base in range(0x81E0, 0x8C30 - 0x70, 0x70):
        exp, nxt, hp, mp, mhp, mmp = struct.unpack_from("<6I", d, base + 0x14)
        if hp <= mhp and mp <= mmp and 0 < mhp < 1000000:
            nm = struct.unpack_from("<2H", d, base)
            job = struct.unpack_from("<H", d, base + 0x36)[0]
            tail = struct.unpack_from("<9H", d, base + 0x54)
            print(f"  @0x{base:05X} name{{ofs={nm[0]},id={nm[1]}}} exp={exp} hp={hp}/{mhp} "
                  f"mp={mp}/{mmp} job=0x{job:04X} tail54={list(tail)}")
    tbl = load_table(lang or "us")
    if tbl:
        print("name blob @0x8770:", dec_blob(d[0x8770:0x87A0], tbl))
        print("creature names @0xC9B0:", dec_blob(d[0xC9B0:0xCB40], tbl)[:12])
    for off, end, kind, note in PS2_FIELDS:
        print(f"  0x{off:05X}-0x{off+end:05X} {kind:15s} {note}")


def cmd_names(path, lang):
    d = open(path, "rb").read()
    tbl = load_table(lang)
    if tbl is None:
        print(f"no ffx2sjistbl_{lang}.bin found (set FFX2_TBL_DIR or --tbl)", file=sys.stderr)
        return 2
    # scan for runs of >=4 bytes in charset single-byte range 0x30..0x8F
    print(f"== names in {os.path.basename(path)} (tbl={lang}) ==")
    i = 0
    while i < len(d):
        if 0x30 <= d[i] <= 0x8F:
            j = i
            while j < len(d) and 0x30 <= d[j] <= 0x8F:
                j += 1
            if j - i >= 4:
                s = dec_name(d[i:j], tbl)
                if any(ord(c) > 0x3000 for c in s) or (any(c.isalpha() for c in s) and len(s) >= 3):
                    print(f"  0x{i:X} ({j-i}B): {s}")
            i = j
        else:
            i += 1
    return 0


def cmd_tail(corpus):
    files = [l.split("\t")[3].strip() for l in open(corpus) if len(l.split("\t")) >= 4]
    cnt = collections.defaultdict(collections.Counter)
    recs = 0
    for p in files:
        try:
            d = open(p, "rb").read()
        except OSError:
            continue
        if len(d) not in (91808, 90736):
            continue
        sd = d[0x40:]
        for i in range(0x17):
            tail = sd[0x81B0 + i * 0x80 + 0x58: 0x81B0 + i * 0x80 + 0x78]
            if any(tail):
                recs += 1
            for j in range(0, 0x20, 2):
                v = struct.unpack_from("<H", tail, j)[0]
                if v:
                    cnt[j][v] += 1
    print(f"modern ply_save tail +0x58..+0x77: {recs} records with data")
    for j in sorted(cnt):
        vals = cnt[j]
        print(f"  +0x{0x58+j:02X}: nz={sum(vals.values())} distinct={len(vals)} "
              f"top={vals.most_common(5)}")
    return 0


def cmd_gaps(corpus):
    files = [l.split("\t")[3].strip() for l in open(corpus) if len(l.split("\t")) >= 4]
    gaps = [("GAP_11", 0x1ED, 0x44D), ("GAP_13", 0xBEE, 0xD60), ("GAP_14", 0xD6C, 0x10FC),
            ("GAP_18", 0x11B2, 0x21EC), ("GAP_18b", 0x61F4, 0x6FD0), ("GAP_32", 0xB118, 0xC8D0)]
    n = 0
    nz = collections.Counter()
    for p in files:
        try:
            d = open(p, "rb").read()
        except OSError:
            continue
        if len(d) not in (91808, 90736):
            continue
        n += 1
        sd = d[0x40:]
        for name, a, b in gaps:
            if any(sd[a:b]):
                nz[name] += 1
    print(f"modern saves: {n}")
    for name, a, b in gaps:
        print(f"  {name} 0x{a:05X}-0x{b:05X} ({b-a}B): nonzero in {nz[name]}/{n}")
    return 0


def main(argv):
    if len(argv) < 3:
        print(__doc__)
        return 2
    cmd, target = argv[1], argv[2]
    lang = "us"
    if "--tbl" in argv:
        lang = argv[argv.index("--tbl") + 1]
    if cmd == "ps2":
        return cmd_ps2(target, lang if "--tbl" in argv else None)
    if cmd == "names":
        return cmd_names(target, lang)
    if cmd == "tail":
        return cmd_tail(target)
    if cmd == "gaps":
        return cmd_gaps(target)
    print(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv))
