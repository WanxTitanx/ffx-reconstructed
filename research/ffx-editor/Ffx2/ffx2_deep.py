#!/usr/bin/env python3
# ffx2_deep.py — FFX-2 save-format DEEP residuals research tool (wave-14, Jarvis-FFX2-DEEP)
#
# Second-pass residual analysis. Extends ffx2_resid.py (wave-14 wave-1) on the
# corpus of 188 modern-layout saves (91808B PC/Vita + 90736B PS3-era) and the
# 3 PS2-era saves (54296B e3 tutorial x2 + 54312B PS2-NA converter).
#
# Research-only. Stdlib only. Does not touch product code. Produces CSV evidence
# under docs/reverse/data/wave14/ for the FFX2_DEEP_2026-09-18 report.
#
# Usage:
#   python3 ffx2_deep.py <command> <corpus.txt> [out_dir]
#   commands: all | bitcensus | gapcorr | resultcard | ps2na | charset | tail | expecho | vi
#
# corpus.txt: one save per line "size\ttag\thash\tpath" (see work/_ffx2fields/corpus.txt)
# Charset tables default to the extracted-assets dir; override with FFX2_TBL_DIR.
#
# Key offsets (SaveData-relative for modern; file-relative for PS2):
#   modern: story_progress 0xBEC, chapter ~0x114C, time 0xBC, result_card 0x61F0,
#           GAP_18b 0x61F4-0x6FD0, GAP_13 0xBEE-0xD60, GAP_14 0xD6C-0x10FC,
#           character_names[23]x40B 0xCAEC, ply_saves 0x81B0 stride 0x80,
#           friend_monster ~0xD570 stride 0xE38, dgn_save_data 0x14730-0x16228.
#   PS2:    story 0xC2C, chapter 0x118C, btl_party 0x7810, inventory 0x7970,
#           accessories 0x7CB4, ply_saves 0x81E0/0x8790 stride 0x70,
#           name blobs 0x8770/0xC9B0, friend_monster 0x8C30 stride 0x6A0,
#           tail-data 0xD0C0-0xD1FF, EOF trailer 0xD409+.

import collections
import os
import struct
import sys

# ------------------------------------------------------------ corpus I/O ---

def iter_corpus(corpus_path):
    """Yield (tag, path, size, kind) for each corpus entry.
    kind: 'modern' (91808/90736) or 'ps2' (54296/54312)."""
    for line in open(corpus_path, "r", encoding="utf-8", errors="replace"):
        p = line.rstrip("\n").split("\t")
        if len(p) < 4 or not p[0].strip().isdigit():
            continue
        size = int(p[0])
        kind = "modern" if size in (91808, 90736) else ("ps2" if size in (54296, 54312) else "other")
        yield p[1].strip(), p[3].strip(), size, kind


def read_modern_savedata(path):
    """Return the SaveData payload (file minus 0x40 wrap) for a modern save."""
    return open(path, "rb").read()[0x40:]


def basename(path):
    return path.replace("\\", "/").rstrip("/").split("/")[-1]


# --------------------------------------------------------- charset tables ---

TBL_DIR_DEFAULTS = [
    os.environ.get("FFX2_TBL_DIR", ""),
    "/mnt/nvme-samsung/FFX Extracted/FFX2/ffx_ps2/ffx2/master/jppc/ffx2_encoding",
    "work/_ffx2fields",
]

def load_table(lang):
    for d in TBL_DIR_DEFAULTS:
        if not d:
            continue
        p = os.path.join(d, f"ffx2sjistbl_{lang}.bin")
        if os.path.exists(p):
            return open(p, "rb").read().decode("utf-8")
    return None


def dec_name(bs, tbl):
    """Shared charset decode: byte>=0x30 -> direct glyph tbl[b-0x30];
    byte<0x30 -> 2-byte index (b-0x2B)*208 + (lo-0x30)."""
    if tbl is None:
        return "<no table>"
    out, i = [], 0
    while i < len(bs) and bs[i] != 0:
        b = bs[i]
        if b >= 0x30:
            out.append(tbl[b - 0x30] if b - 0x30 < len(tbl) else "?")
            i += 1
        else:
            if i + 1 >= len(bs):
                break
            idx = (b - 0x2B) * 208 + (bs[i + 1] - 0x30)
            out.append(tbl[idx] if 0 <= idx < len(tbl) else f"<{b:02X}{bs[i+1]:02X}>")
            i += 2
    return "".join(out)


# --------------------------------------------------------------- CSV out ---

def write_csv(path, header, rows):
    with open(path, "w", encoding="utf-8", newline="") as f:
        f.write(",".join(header) + "\n")
        for r in rows:
            f.write(",".join(str(c) for c in r) + "\n")
    print(f"wrote {path} ({len(rows)} rows)")


# =============================================================================
# 1. bitcensus — per-gap byte/bit census across the modern corpus
# =============================================================================

GAPS = [
    ("GAP_13", 0x0BEE, 0x0D60),
    ("GAP_14", 0x0D6C, 0x10FC),
    ("GAP_18b", 0x61F4, 0x6FD0),
    ("GAP_18", 0x11B2, 0x21EC),
    ("GAP_11", 0x01ED, 0x044D),
    ("GAP_32", 0xB118, 0xC8D0),
]


def cmd_bitcensus(corpus, outdir):
    """For each gap region: per-relative-byte nonzero-save count, distinct value
    count, and the set of bit positions ever set. Reveals record strides and
    which sub-fields are real vs dead padding."""
    stats = {g[0]: collections.defaultdict(lambda: {"saves": 0, "vals": set(), "bits": set()})
             for g in GAPS}
    saves = list(iter_corpus(corpus))
    for tag, path, size, kind in saves:
        if kind != "modern":
            continue
        try:
            sd = read_modern_savedata(path)
        except OSError:
            continue
        for name, a, b in GAPS:
            reg = sd[a:b]
            for i, by in enumerate(reg):
                if by:
                    s = stats[name][i]
                    s["saves"] += 1
                    s["vals"].add(by)
                    for bit in range(8):
                        if by & (1 << bit):
                            s["bits"].add(bit)
    rows = []
    for name, a, b in GAPS:
        n_saves = sum(1 for t in saves if t[3] == "modern")
        for i in range(b - a):
            s = stats[name].get(i)
            if not s:
                continue
            rows.append((name, f"+0x{i:04X}", a + i, s["saves"], len(s["vals"]),
                         "".join(str(x) for x in sorted(s["bits"]))))
    write_csv(os.path.join(outdir, "ffx2_deep_gap_bits.csv"),
              ["region", "rel_off", "sd_off", "nonzero_saves", "distinct_vals", "bits_set"], rows)


# =============================================================================
# 2. gapcorr — per-save activity correlations
# =============================================================================

def count_nonzero(sd, a, b):
    return sum(1 for x in sd[a:b] if x)


def cmd_gapcorr(corpus, outdir):
    """Per-save: story/chapter/playtime + nonzero byte count per gap region +
    capture/inventory counters + result_card. Used to test which known field
    each gap's activity tracks."""
    rows = []
    for tag, path, size, kind in iter_corpus(corpus):
        if kind != "modern":
            continue
        try:
            sd = read_modern_savedata(path)
        except OSError:
            continue
        story = struct.unpack_from("<H", sd, 0xBEC)[0]
        chap = sd[0x114C] if len(sd) > 0x114C else 0
        tsec = struct.unpack_from("<I", sd, 0xBC)[0]
        rc = struct.unpack_from("<I", sd, 0x61F0)[0]
        # friend_monster recruits: count records with nonzero species id at +0x00
        recruits = 0
        for i in range(9):
            base = 0xD570 + i * 0xE38
            if base + 4 <= len(sd) and struct.unpack_from("<H", sd, base)[0]:
                recruits += 1
        # inventory_ids[0x44] u16 @0x7940 (0x2xxx ids): count valid entries
        inv = sum(1 for i in range(0x44)
                  if 0x2000 <= struct.unpack_from("<H", sd, 0x7940 + i * 2)[0] < 0x3000) \
            if len(sd) > 0x7940 + 0x88 else 0
        # monster_meet[0x20] bitfield @0x8020: nonzero bytes = bestiary seen
        seen = count_nonzero(sd, 0x8020, 0x8060) if len(sd) > 0x8060 else 0
        row = [basename(path), tag, story, chap, tsec, f"0x{rc:08X}",
               recruits, inv, seen]
        for name, a, b in GAPS:
            row.append(count_nonzero(sd, a, b))
        rows.append(row)
    hdr = ["save", "tag", "story", "chapter", "time_s", "result_card",
           "recruits", "inv_u16", "mon_meet"] + [g[0] for g in GAPS]
    write_csv(os.path.join(outdir, "ffx2_deep_gap_corr.csv"), hdr, rows)


# =============================================================================
# 3. resultcard — result_card field census + party lineup cross-check
# =============================================================================

def cmd_resultcard(corpus, outdir):
    """result_card (u32 @ SaveData+0x61F0) is 4 packed u8 dressphere/job indices.
    Cross-check against the 3 party members' current ply_save.job and equipped
    plate to test the 'party lineup on the save/result card' hypothesis."""
    rows = []
    for tag, path, size, kind in iter_corpus(corpus):
        if kind != "modern":
            continue
        try:
            sd = read_modern_savedata(path)
        except OSError:
            continue
        rc = struct.unpack_from("<I", sd, 0x61F0)[0]
        b = rc.to_bytes(4, "little")
        jobs = [struct.unpack_from("<H", sd, 0x81B0 + i * 0x80 + 0x36)[0] - 0x5000
                for i in range(3)]
        plates = [struct.unpack_from("<H", sd, 0x81B0 + i * 0x80 + 0x38)[0]
                  for i in range(3)]
        chap = sd[0x114C] if len(sd) > 0x114C else 0
        rows.append((basename(path), tag, f"0x{rc:08X}",
                     b[0], b[1], b[2], b[3],
                     f"{jobs[0]},{jobs[1]},{jobs[2]}",
                     f"{plates[0]},{plates[1]},{plates[2]}", chap))
    write_csv(os.path.join(outdir, "ffx2_deep_resultcard.csv"),
              ["save", "tag", "result_card", "b0", "b1", "b2", "b3",
               "party_jobs_idx", "plates", "chapter"], rows)


# =============================================================================
# 4. ps2na — PS2-NA +0x10 delta: anchor table + trailer decode
# =============================================================================

PS2_FILES = {
    "e3_00": "/mnt/nvme-samsung/FFX Extracted/FFX2/ffx_ps2/ffx2/master/jppc/menu/tuto_savedata/save_e3_00",
    "e3_01": "/mnt/nvme-samsung/FFX Extracted/FFX2/ffx_ps2/ffx2/master/jppc/menu/tuto_savedata/save_e3_01",
    "na": "/home/wanderson/Documents/ffx-editor-main/Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX-2/PS2 (north america)",
}

PS2_ANCHORS = [
    ("hdr_ver_u32", 0x0000, 4), ("hdr_nameid_u32", 0x0008, 4), ("hdr_u16", 0x000C, 2),
    ("hdr_u32a", 0x0010, 4), ("hdr_u32b", 0x0014, 4), ("hdr_u32c", 0x0018, 4),
    ("hdr_tag4", 0x0030, 4),
    ("story_progress", 0x0C2C, 4), ("current_chapter", 0x118C, 4),
    ("btl_party", 0x7810, 4), ("inventory", 0x7970, 4), ("accessories", 0x7CB4, 4),
    ("plyA", 0x81E0, 4), ("name_blob", 0x8770, 4), ("plyB", 0x8790, 4),
    ("friend_mon", 0x8C30, 4), ("creature_names", 0xC9B0, 4),
    ("tail_data", 0xD0D0, 4), ("eof_trailer", 0xD409, 4),
]


def cmd_ps2na(corpus, outdir):
    """Verify the +0x10 (16-byte) PS2-NA file-size delta is confined to the EOF
    trailer: dump every anchor at the SAME file offset in all 3 PS2 saves."""
    data = {}
    for nm, p in PS2_FILES.items():
        try:
            data[nm] = open(p, "rb").read()
        except OSError:
            data[nm] = b""
    rows = []
    for nm, off, n in PS2_ANCHORS:
        e0 = data["e3_00"][off:off + n].hex()
        e1 = data["e3_01"][off:off + n].hex()
        na = data["na"][off:off + n].hex()
        rows.append((nm, f"0x{off:05X}", e0, e1, na))
    # append full trailer bytes
    for nm in data:
        rows.append((f"TRAILER_{nm}", "EOF", data[nm][-0x20:].hex(), "", ""))
    write_csv(os.path.join(outdir, "ffx2_deep_ps2na.csv"),
              ["anchor", "file_off", "e3_00", "e3_01", "na"], rows)


# =============================================================================
# 5. charset — table coverage + corpus charset census
# =============================================================================

def cmd_charset(corpus, outdir):
    """Load all 5 sjistbl tables; report size + reachable-index coverage under the
    shared (direct 208 + multibyte 5*208) scheme; census each modern save's
    charset by name-blob byte range; decode sample names."""
    langs = ["us", "jp", "kr", "ch", "cn"]
    tbl = {l: load_table(l) for l in langs}
    rows = []
    for l in langs:
        t = tbl[l]
        n = len(t) if t else 0
        reach = min(n, 1040)  # direct cap 208 + multibyte cap 1040 (lead 0x2B-0x2F)
        rows.append((f"TABLE_{l}", n, reach, n - reach, f"{reach/n:.0%}" if n else "0"))
    for tag, path, size, kind in iter_corpus(corpus):
        if kind != "modern":
            continue
        try:
            sd = read_modern_savedata(path)
        except OSError:
            continue
        nb = sd[0xCAEC:0xCAEC + 0x100]
        hi = sum(1 for b in nb if b > 0x90)
        lo = sum(1 for b in nb if 0x30 <= b <= 0x90)
        cs = "jp" if hi > lo else ("us" if lo > 0 else "?")
        # decode first name under the save's own table for the record
        t = tbl["jp"] if cs == "jp" else tbl["us"]
        name0 = dec_name(sd[0xCAEC:0xCAEC + 40], t) if t else ""
        rows.append((basename(path), tag, cs, f"hi={hi} lo={lo}", name0))
    write_csv(os.path.join(outdir, "ffx2_deep_charset.csv"),
              ["entry", "size_or_tag", "glyphs_or_charset", "reachable_or_bytes",
               "pct_or_name"], rows)


# =============================================================================
# 6. tail — modern + PS2 ply_save tail field census
# =============================================================================

def cmd_tail(corpus, outdir):
    """Census the ply_save tail sub-array ({flag u16 @+0x54, 0x50XX job-id echo
    @+0x56, u16 value array @+0x58+}) for modern (0x80 stride) and PS2 (0x70
    stride) records. Modern extends to +0x7F; PS2 ends +0x6F with the +0x6C
    next-exp echo."""
    cnt = collections.Counter()
    vals = collections.defaultdict(collections.Counter)
    nrec = 0
    for tag, path, size, kind in iter_corpus(corpus):
        if kind != "modern":
            continue
        try:
            sd = read_modern_savedata(path)
        except OSError:
            continue
        for i in range(0x17):
            base = 0x81B0 + i * 0x80
            if base + 0x80 > len(sd) or not any(sd[base:base + 0x50]):
                continue
            nrec += 1
            for off in range(0x50, 0x80):
                by = sd[base + off]
                if by:
                    cnt[off] += 1
                    vals[off][by] += 1
    rows = [("modern", f"+0x{o:02X}", cnt[o], len(vals[o]),
             ";".join(f"{v}:{c}" for v, c in vals[o].most_common(5)))
            for o in sorted(cnt)]
    # PS2 tail census
    pcnt = collections.Counter()
    prec = 0
    for nm, p in PS2_FILES.items():
        try:
            d = open(p, "rb").read()
        except OSError:
            continue
        for b0, b1 in ((0x81E0, 0x8770), (0x8790, 0x8C30)):
            base = b0
            while base + 0x70 <= b1:
                if any(d[base:base + 0x50]):
                    prec += 1
                    for off in range(0x50, 0x70):
                        if d[base + off]:
                            pcnt[off] += 1
                base += 0x70
    rows += [("ps2", f"+0x{o:02X}", pcnt[o], "", "") for o in sorted(pcnt)]
    write_csv(os.path.join(outdir, "ffx2_deep_tail.csv"),
              ["fmt", "rec_off", "nonzero_records", "distinct_vals", "top_vals"], rows)


# =============================================================================
# 7. expecho — PS2 +0x6C next-exp echo verification
# =============================================================================

def cmd_expecho(corpus, outdir):
    """Test the 'record+0x6C == next record's exp' serializer-echo hypothesis
    across every populated transition in all 3 PS2 saves, both regions."""
    rows = []
    for nm, p in PS2_FILES.items():
        try:
            d = open(p, "rb").read()
        except OSError:
            continue
        for reg, b0, b1 in (("A", 0x81E0, 0x8770), ("B", 0x8790, 0x8C30)):
            recs = []
            base = b0
            while base + 0x70 <= b1:
                recs.append(base)
                base += 0x70
            for i, base in enumerate(recs):
                exp = struct.unpack_from("<I", d, base + 0x14)[0]
                echo = struct.unpack_from("<I", d, base + 0x6C)[0]
                nxt = struct.unpack_from("<I", d, recs[i + 1] + 0x14)[0] \
                    if i + 1 < len(recs) else -1
                verdict = ("match" if echo == nxt else
                           ("sentinel" if i + 1 == len(recs) else
                            ("both_zero" if echo == 0 and nxt == 0 else "MISMATCH")))
                rows.append((nm, f"{reg}{i}", f"0x{base:X}", exp, echo, nxt, verdict))
    write_csv(os.path.join(outdir, "ffx2_deep_expecho.csv"),
              ["save", "rec", "file_off", "exp", "echo_6C", "next_exp", "verdict"], rows)


# =============================================================================
# 8. vi — dgn_save_data / Via Infinito nonzero scan
# =============================================================================

def cmd_vi(corpus, outdir):
    """Scan the complete dgn_save_data region (SaveData 0x14730-0x16228) in every
    modern save; record nonzero counts and ranges. Genuine Via Infinito state
    vs the known 0x11 rip-fill artifact."""
    rows = []
    for tag, path, size, kind in iter_corpus(corpus):
        if kind != "modern":
            continue
        try:
            sd = read_modern_savedata(path)
        except OSError:
            continue
        reg = sd[0x14730:0x16228]
        nz = [i for i, b in enumerate(reg) if b]
        if nz:
            rows.append((basename(path), tag, len(nz), f"0x{min(nz):X}", f"0x{max(nz):X}",
                         reg[min(nz):min(nz) + 8].hex(), "0x11-fill" if reg[0] == 0x11 else "data"))
        else:
            rows.append((basename(path), tag, 0, "-", "-", "-", "empty"))
    write_csv(os.path.join(outdir, "ffx2_deep_vi.csv"),
              ["save", "tag", "nonzero", "first", "last", "head", "verdict"], rows)


# =============================================================================

CMDS = {
    "bitcensus": cmd_bitcensus, "gapcorr": cmd_gapcorr, "resultcard": cmd_resultcard,
    "ps2na": cmd_ps2na, "charset": cmd_charset, "tail": cmd_tail,
    "expecho": cmd_expecho, "vi": cmd_vi,
}


def main():
    if len(sys.argv) < 3 or sys.argv[1] not in list(CMDS) + ["all"]:
        print(__doc__)
        sys.exit(1)
    cmd, corpus = sys.argv[1], sys.argv[2]
    outdir = sys.argv[3] if len(sys.argv) > 3 else "docs/reverse/data/wave14"
    os.makedirs(outdir, exist_ok=True)
    if cmd == "all":
        for fn in CMDS.values():
            fn(corpus, outdir)
    else:
        CMDS[cmd](corpus, outdir)


if __name__ == "__main__":
    main()
