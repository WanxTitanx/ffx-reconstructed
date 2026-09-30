#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
BIN-PS3PSV divergence decomposer — what structurally differs inside the 541
VARIANT `.bin` pairs of `event/obj_ps3` vs `event/obj_psv` (intra-tree platform
mirror), follow-up of LOCALE-PARITY §9 (FFX_PARITY_LOCALE_2026-09-15.md).

Format context ("Dialeto B", FFX_PS2_MASTER_ATLAS_2026-06-01.md §3.1):
  index   = N x 8B records of TWO IDENTICAL u32; each u32 = (flag16<<16)|offset16
            (low16 ascending offsets, high16 = per-entry flag/type);
            first entry low16 = index size = payload start (multiple of 8).
  payload = event-obj stream of text records (event-message strings in the
            FFX 1/2-byte glyph encoding) + control/marker stream.

Decoders: 1-byte glyph range is resolved with the project's OWN tables —
  * US/EU trees: FfxEncoding.us.cs parsed at runtime (no hand-copied charmap);
  * CJK trees:   ffxsjistbl_{jp,kr,ch}.bin from jppc/ffx_encoding (UTF-8 glyph
                 list; glyph index = byte - 0x30). Fullwidth ASCII normalized
                 to ASCII for keyword matching.
2-byte glyph codes (leads 0x06/0x26-0x2F) are rendered <LLii> — font-sheet
indices, not decodable to chars without the FTCX sheet.

Method per VARIANT pair (a=obj_ps3, b=obj_psv):
  1. index: entry-by-entry alignment (difflib over logical entries) —
     count add/del entries, lo16 offset shifts == size delta, hi16 flag changes.
  2. payload: difflib opcodes -> hunks (insert/delete/replace), each mapped to
     the index-record(s) covering it; per-hunk textiness.
  3. keyword mechanism scan on decoded full payload of BOTH sides:
     Msg Missing / MES PLAYGO / Installing / save-data-other-users warning /
     Soundtrack-Arranged-Original / fullwidth CJK equivalents.
  4. point-diff detection: replace hunks of <=2B whose byte is preceded by a
     text control byte (<0x30) on both sides -> icon/param-byte change.
  5. mechanism class per pair (see CLASS order in code).

Outputs under work/_bin_ps3psv/:
  bin_ps3psv_pairs.tsv    one row per VARIANT pair with full classification
  bin_ps3psv_hunks.tsv    one row per payload diff hunk (offset/len/decoded)
  bin_ps3psv_names.tsv    per-basename cross-tree mechanism matrix
  size_delta_hist.tsv / first_diff_hist.tsv
  summary.txt             consolidated report

Read-only on the corpus. Lane: FFX-STRUCTURES (subagente BIN-PS3PSV) — 2026-09-15.
"""
import difflib
import os
import re
import struct
import sys
import unicodedata
from collections import Counter, defaultdict

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"
REPO = "/home/wanderson/Documents/ffx-editor-main"
PAIRS_TSV = os.path.join(REPO, "work/_locale_parity/locale_obj_ps3_vs_psv.tsv")
US_CS = os.path.join(REPO, "FFXProjectEditor/FfxLib/Encoding/FfxEncoding.us.cs")
ENCDIR = os.path.join(ROOT, "jppc/ffx_encoding")
OUT = os.path.join(REPO, "work/_bin_ps3psv")

TREES = ["new_chpc", "new_depc", "new_frpc", "new_itpc",
         "new_jppc", "new_krpc", "new_sppc", "new_uspc"]
TREE2LOC = {"new_uspc": "us", "new_depc": "de", "new_frpc": "fr",
            "new_itpc": "it", "new_sppc": "sp",
            "new_jppc": "jp", "new_krpc": "kr", "new_chpc": "ch"}

# text controls seen in the payload (FFX_EVENT_TEXT_ENCODING_CRACKED + observed)
LEAD2 = set(range(0x26, 0x30)) | {0x06}
CTRL_PARAM = {0x0A, 0x10, 0x12, 0x13, 0x19}   # controls that take 1 param byte
TEXTLIKE = set(range(0x30, 0x100)) | LEAD2 | CTRL_PARAM | {0x00, 0x03, 0x04,
                                                          0x07, 0x09, 0x0B}


# ---------- decoders -------------------------------------------------------

def build_us_decoder():
    dec = {}
    try:
        with open(US_CS, encoding="utf-8-sig") as f:
            src = f.read()
        for m in re.finditer(r"\{\s*(\d+),\s*'((?:[^'\\]|\\.)?)'\s*\}", src):
            n = int(m.group(1))
            c = m.group(2)
            if c.startswith("\\"):
                c = c.encode().decode("unicode_escape")
            dec[n] = c if c else "?"
    except OSError:
        pass
    return dec


US_DEC = build_us_decoder()
_CJK = {}
for loc in ("jp", "kr", "ch"):
    try:
        raw = open(os.path.join(ENCDIR, f"ffxsjistbl_{loc}.bin"),
                   "rb").read().decode("utf-8")
        _CJK[loc] = list(raw)
    except OSError:
        _CJK[loc] = []


def decode(buf, loc):
    """Best-effort event-text decode. 1-byte glyphs via locale table
    (US via FfxEncoding.us.cs; CJK via ffxsjistbl_*.bin), 2-byte codes as
    <LLii>, param controls as [CC:pp], other controls as {XX}."""
    out = []
    i = 0
    tbl = _CJK.get(loc)
    while i < len(buf):
        c = buf[i]
        if c >= 0x30:
            if loc == "us" or tbl is None or loc in ("de", "fr", "it", "sp"):
                out.append(US_DEC.get(c, chr(c) if 0x30 <= c < 0x80 else "?"))
            else:
                gi = c - 0x30
                out.append(tbl[gi] if gi < len(tbl) else "?")
            i += 1
        elif c in LEAD2:
            if i + 1 < len(buf):
                out.append(f"<{c:02x}{buf[i+1]:02x}>")
                i += 2
            else:
                out.append(f"{{{c:02x}}}")
                i += 1
        elif c in CTRL_PARAM:
            if i + 1 < len(buf):
                out.append(f"[{c:02x}:{buf[i+1]:02x}]")
                i += 2
            else:
                out.append(f"[{c:02x}]")
                i += 1
        else:
            out.append(f"{{{c:02x}}}")
            i += 1
    return "".join(out)


def norm(s):
    """NFKC-normalize (folds fullwidth ASCII used in CJK stubs to ASCII)."""
    return unicodedata.normalize("NFKC", s)


def textiness(buf):
    if not buf:
        return 0.0
    n = sum(1 for c in buf if c in TEXTLIKE)
    return n / len(buf)


def u32(buf, off):
    return struct.unpack_from("<I", buf, off)[0]


def parse_index(buf):
    """Dialeto-B index -> (payload_start, [logical u32 entries]) or None."""
    if len(buf) < 8:
        return None
    first = u32(buf, 0) & 0xFFFF
    if first == 0 or first % 8 != 0 or first > len(buf):
        return None
    n = first // 4
    entries = [u32(buf, i * 4) for i in range(n)]
    if any(entries[i] != entries[i + 1] for i in range(0, n - 1, 2)):
        return None
    logical = entries[::2]
    lo = [e & 0xFFFF for e in logical]
    if any(lo[i] > lo[i + 1] for i in range(len(lo) - 1)):
        return None
    return first, logical


def hunk_align(ent_a, ent_b):
    """Align logical index entries; returns (n_shift, n_flag, n_add, n_del)."""
    n_shift = n_flag = n_add = n_del = 0
    sm = difflib.SequenceMatcher(None, ent_a, ent_b, autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            continue
        if tag == "replace" and (i2 - i1) == (j2 - j1):
            for k in range(i2 - i1):
                va, vb = ent_a[i1 + k], ent_b[j1 + k]
                if (va >> 16) != (vb >> 16):
                    n_flag += 1
                elif (vb & 0xFFFF) != (va & 0xFFFF):
                    n_shift += 1
        elif tag in ("replace", "delete"):
            n_del += (i2 - i1)
            if tag == "replace":
                n_add += (j2 - j1)
        elif tag == "insert":
            n_add += (j2 - j1)
    return n_shift, n_flag, n_add, n_del


KW = {
    "PLAYGO":  ("Msg Missing", "MES PLAYGO WAIT", "MES_PLAYGO",
                "Installing", "installing"),
    "SNDTRK":  ("soundtrack", "Soundtrack", "Arranged", "Original",
                "Arrange"),
    "SAVEWARN": ("other users", "save data from", "Speicherdaten anderer",
                 "autres", "dati salvati", "otros usuarios",
                 "dados guardados"),
}

# Mechanism-consensus name sets (verified by content on US/EU trees + CJK
# spot-decode via ffxsjistbl): same relpath diverges for the same reason in
# every tree where it diverges.
MECH_NAMES = {
    "PLAYGO_SLOT": {"bika0300", "cdsp0000", "dome0100", "genk0500",
                    "kino0200", "luca0100", "maca0000", "mtgz0200",
                    "ptkl0100", "stbv0000", "swin0400"},
    "VITA_SAVEWARN": {"azit0600", "azit0700", "bjyt0000", "hiku0500",
                      "maca0100", "mihn0300", "nagi0100"},
    "SNDTRK_REMOVED": {"lchb1200", "test20"},
    "MINIGAME_HUD": {"nagi0000"},
}


STRICT_TEXT_BYTES = (set(range(0x30, 0x100)) | set(range(0x26, 0x30)) |
                     {0x00, 0x03, 0x04, 0x06, 0x07, 0x09, 0x0A, 0x0B,
                      0x10, 0x12, 0x13, 0x19, 0x20})


def mech_of(row):
    """Name-consensus mechanism label (structural class stays in `class`)."""
    name = row.get("name", "")
    if name in MECH_NAMES["PLAYGO_SLOT"]:
        return "PLAYGO_SLOT"
    if name in MECH_NAMES["VITA_SAVEWARN"]:
        return "VITA_SAVEWARN"
    if name in MECH_NAMES["SNDTRK_REMOVED"]:
        return "SNDTRK_REMOVED"
    if name in MECH_NAMES["MINIGAME_HUD"]:
        return "MINIGAME_HUD"
    if "PLAYGO" in str(row.get("kw_ps3", "")) and \
            "PLAYGO" not in str(row.get("kw_psv", "")):
        return "STUB_ON_PS3"          # inverted: dev stub left on ps3 side
    return row.get("class", "?")


def classify_pair(tree, rel3, rel5):
    loc = TREE2LOC.get(tree, "us")
    dloc = "us" if loc in ("de", "fr", "it", "sp") else loc
    a = open(os.path.join(ROOT, tree, rel3), "rb").read()
    b = open(os.path.join(ROOT, tree, rel5), "rb").read()
    row = {"tree": tree, "rel": rel3, "name": rel3.split("/")[-2],
           "size_ps3": len(a), "size_psv": len(b), "delta": len(b) - len(a)}
    ia, ib = parse_index(a), parse_index(b)
    row["dialectB"] = bool(ia and ib)
    if not (ia and ib):
        row["class"] = "NON_DIALECT_B"
        return row, []

    idxA, entA = ia
    idxB, entB = ib
    row.update(idx_ps3=idxA, idx_psv=idxB,
               n_ent_a=len(entA), n_ent_b=len(entB))

    # ---- index alignment ----
    n_shift, n_flag, n_add, n_del = hunk_align(entA, entB)
    row.update(idx_shift=n_shift, idx_flag=n_flag,
               idx_add=n_add, idx_del=n_del)

    # ---- payload hunks ----
    pay_a, pay_b = a[idxA:], b[idxB:]
    sm = difflib.SequenceMatcher(None, pay_a, pay_b, autojunk=False)
    hunks = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            continue
        hunks.append({"tag": tag, "a_off": idxA + i1, "a_len": i2 - i1,
                      "b_off": idxB + j1, "b_len": j2 - j1,
                      "a_b": pay_a[i1:i2], "b_b": pay_b[j1:j2]})
    row["n_hunks"] = len(hunks)
    row["first_payload_diff"] = hunks[0]["a_off"] if hunks else -1
    row["last_payload_diff"] = (max(h["a_off"] + h["a_len"]
                                    for h in hunks) if hunks else -1)

    changed = b"".join(h["b_b"] if h["tag"] != "delete" else h["a_b"]
                       for h in hunks)
    row["changed_bytes"] = len(changed)
    row["textiness"] = round(textiness(changed), 2)
    row["nontext_bytes"] = sum(1 for c in changed
                             if c not in STRICT_TEXT_BYTES)

    # point-diff detection: <=2B replaces preceded by a control byte both sides
    n_point = 0
    for h in hunks:
        if h["tag"] == "replace" and h["a_len"] <= 2 and h["b_len"] <= 2:
            pa = a[h["a_off"] - 1] if h["a_off"] > 0 else 0x30
            pb = b[h["b_off"] - 1] if h["b_off"] > 0 else 0x30
            if pa < 0x30 and pb < 0x30:
                n_point += 1
    row["point_diffs"] = n_point

    # ---- keyword scan on full decoded payload ----
    txt_a = norm(decode(pay_a, dloc))
    txt_b = norm(decode(pay_b, dloc))
    hits_a = {k for k, vs in KW.items() if any(v in txt_a for v in vs)}
    hits_b = {k for k, vs in KW.items() if any(v in txt_b for v in vs)}
    row["kw_ps3"] = "|".join(sorted(hits_a))
    row["kw_psv"] = "|".join(sorted(hits_b))

    # ---- mechanism class ----
    # PLAYGO stub: psv has Msg Missing / MES PLAYGO marker, or ps3 has the
    # Installing message and the psv side dropped/replaced it.
    if "PLAYGO" in hits_b or ("PLAYGO" in hits_a and n_del >= 1):
        cls = "PLAYGO_STUB"
    elif "SNDTRK" in hits_a and "SNDTRK" not in hits_b:
        cls = "SNDTRK_REMOVED"
    elif "SAVEWARN" in hits_b and "SAVEWARN" not in hits_a:
        cls = "VITA_SAVEWARN"
    elif not hunks:
        cls = "INDEX_ONLY"
    elif n_point and n_point == len(hunks):
        cls = "ICON_PARAM"
    elif all(h["tag"] == "insert" for h in hunks):
        cls = "INSERT_TEXT" if textiness(changed) >= 0.6 else "INSERT_BIN"
    elif all(h["tag"] == "delete" for h in hunks):
        cls = "DELETE_TEXT" if textiness(changed) >= 0.6 else "DELETE_BIN"
    elif row["textiness"] >= 0.6:
        cls = "TEXT_EDIT"
    else:
        cls = "BIN_MIX"
    row["class"] = cls

    # decoded preview of first sizeable hunk
    for h in sorted(hunks, key=lambda h: -max(h["a_len"], h["b_len"])):
        buf = h["b_b"] if h["tag"] != "delete" else h["a_b"]
        if buf:
            row["decoded_preview"] = decode(buf[:110], dloc)
            break
    hunk_rows = [(tree, rel3, h["tag"], h["a_off"], h["a_len"],
                  h["b_off"], h["b_len"], round(textiness(
                      h["b_b"] if h["tag"] != "delete" else h["a_b"]), 2),
                  decode((h["b_b"] if h["tag"] != "delete" else h["a_b"])[:120],
                         dloc))
                 for h in hunks]
    return row, hunk_rows


def main():
    pairs = []
    with open(PAIRS_TSV, encoding="utf-8") as f:
        next(f)
        for line in f:
            t = line.rstrip("\n").split("\t")
            if len(t) >= 6 and t[5] == "VARIANT" and t[1].endswith(".bin"):
                pairs.append((t[0], t[1], t[3]))
    print(f"{len(pairs)} VARIANT .bin pairs")

    os.makedirs(OUT, exist_ok=True)
    rows, all_hunks = [], []
    classes, delta_hist, first_hist = Counter(), Counter(), Counter()
    per_tree = defaultdict(Counter)
    per_name = defaultdict(Counter)
    errors = []

    for tree, rel3, rel5 in pairs:
        try:
            row, hunk_rows = classify_pair(tree, rel3, rel5)
        except OSError as e:
            errors.append((tree, rel3, str(e)))
            continue
        row["mech"] = mech_of(row)
        rows.append(row)
        all_hunks.extend(hunk_rows)
        classes[row["class"]] += 1
        per_tree[tree][row["class"]] += 1
        per_name[row["name"]][row["mech"]] += 1
        delta_hist[row["delta"]] += 1
        if row.get("first_payload_diff", -1) >= 0:
            first_hist[row["first_payload_diff"] // 0x100] += 1

    cols = ["tree", "name", "rel", "size_ps3", "size_psv", "delta",
            "dialectB", "idx_ps3", "idx_psv", "n_ent_a", "n_ent_b",
            "idx_shift", "idx_flag", "idx_add", "idx_del", "n_hunks",
            "first_payload_diff", "last_payload_diff", "point_diffs",
            "changed_bytes", "textiness", "nontext_bytes", "kw_ps3",
            "kw_psv", "class", "mech", "decoded_preview"]
    with open(os.path.join(OUT, "bin_ps3psv_pairs.tsv"), "w",
              encoding="utf-8") as f:
        f.write("\t".join(cols) + "\n")
        for r in rows:
            f.write("\t".join(str(r.get(c, "")).replace("\t", " ").replace(
                "\n", " ") for c in cols) + "\n")

    with open(os.path.join(OUT, "bin_ps3psv_hunks.tsv"), "w",
              encoding="utf-8") as f:
        f.write("tree\trel\ttag\ta_off\ta_len\tb_off\tb_len\ttextiness\t"
                "decoded\n")
        for h in all_hunks:
            f.write("\t".join(str(x).replace("\t", " ").replace("\n", " ")
                              for x in h) + "\n")

    with open(os.path.join(OUT, "bin_ps3psv_names.tsv"), "w",
              encoding="utf-8") as f:
        f.write("name\ttrees_diverging\tclasses\n")
        for name in sorted(per_name):
            f.write(f"{name}\t{sum(per_name[name].values())}\t"
                    f"{dict(per_name[name])}\n")

    with open(os.path.join(OUT, "size_delta_hist.tsv"), "w",
              encoding="utf-8") as f:
        f.write("delta_bytes\tcount\n")
        for k in sorted(delta_hist):
            f.write(f"{k}\t{delta_hist[k]}\n")

    with open(os.path.join(OUT, "first_diff_hist.tsv"), "w",
              encoding="utf-8") as f:
        f.write("first_payload_diff_bucket_0x100\tcount\n")
        for k in sorted(first_hist):
            f.write(f"{k:#05x}\t{first_hist[k]}\n")

    with open(os.path.join(OUT, "summary.txt"), "w", encoding="utf-8") as f:
        f.write(f"BIN-PS3PSV divergence decomposition — {len(rows)} pairs "
                f"(errors {len(errors)})\n\n")
        f.write("== class distribution ==\n")
        for c, n in classes.most_common():
            f.write(f"{c:22s} {n:4d}  {100.0*n/max(len(rows),1):5.1f}%\n")
        mechs = Counter(r["mech"] for r in rows)
        f.write("\n== mechanism (name-consensus) distribution ==\n")
        for c, n in mechs.most_common():
            f.write(f"{c:22s} {n:4d}  {100.0*n/max(len(rows),1):5.1f}%\n")
        f.write("\n== per-tree ==\n")
        for t in TREES:
            f.write(f"{t}: {dict(per_tree[t])}\n")
        f.write("\n== size-delta histogram ==\n")
        for k, n in sorted(delta_hist.items()):
            f.write(f"  {k:6d}: {n}\n")
        f.write("\n== first-payload-diff histogram (0x100 buckets) ==\n")
        for k in sorted(first_hist):
            f.write(f"  @{k*0x100:06x}: {first_hist[k]}\n")
        # global integrity stats
        n_pure_reflow = sum(1 for r in rows
                            if not int(r.get("idx_flag") or 0)
                            and not int(r.get("idx_add") or 0)
                            and not int(r.get("idx_del") or 0))
        n_cnt = sum(1 for r in rows
                    if int(r.get("idx_add") or 0) or int(r.get("idx_del") or 0))
        nt_bytes = sum(int(r.get("nontext_bytes") or 0) for r in rows)
        nt_pairs = sum(1 for r in rows if int(r.get("nontext_bytes") or 0))
        f.write(f"\n== index integrity ==\n"
                f"pure offset-reflow pairs: {n_pure_reflow}\n"
                f"record add/del pairs:     {n_cnt}\n"
                f"hunks total:              {len(all_hunks)}\n"
                f"changed bytes outside strict event-text set: "
                f"{nt_bytes} (pairs: {nt_pairs})\n")
        f.write("\n== per-name mechanisms (top 40) ==\n")
        for name, cc in sorted(per_name.items(),
                               key=lambda kv: -sum(kv[1].values()))[:40]:
            f.write(f"  {name:12s} x{sum(cc.values())}: {dict(cc)}\n")
        if errors:
            f.write("\n== errors ==\n")
            for e in errors[:30]:
                f.write(f"  {e}\n")

    print("done:", classes.most_common())


if __name__ == "__main__":
    main()
