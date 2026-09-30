#!/usr/bin/env python3
# ── WD-DIRTY dossier probe (2026-09-15, Jarvis lane FFX-STRUCTURES) ────────────
# Purpose: independent re-derivation and per-bank diagnosis of the 25 `.wd`
# banks that were marked DIRTY by the wave-1 validator (anchor =
# align32up(desc_end)). For EVERY bank in the corpus this probe:
#   1. parses the container with the current reader (wave-2 law);
#   2. computes desc_end, k = desc_end mod 16, and the wave-1 anchor
#      (desc_end + align32_pad, pad = (-desc_end) mod 32) exactly as wave 1 did;
#   3. structurally validates every distinct body under BOTH anchors
#      (filter<=4, shift<=12) -> valid-frame fractions;
#   4. records SPU frame-flag semantics under the wave-2 anchor (first-frame
#      flag, last-frame flag) — a body must start with flag 0 (play) and end
#      with an END marker (1/3/7) for the anchor to be byte-exact;
#   5. collects quirks (external descriptors, aliases, sbo[0] bias, program
#      sentinels, SDBse tag, empty stubs).
# Output: work/_wd_dirty/wd_dirty_dossier.json + wd_dirty_dossier.md
# The wave-1-DIRTY set is RE-DERIVED here (banks with >=1 invalid frame under
# the wave-1 anchor) — not trusted from any doc.
# MAINT: research evidence only; corpus at /mnt is READ-ONLY (never written).
import json
import os
import sys
from collections import Counter

sys.path.insert(0, os.path.join(
    os.path.dirname(os.path.abspath(__file__)), "..", "..",
    "research_tools", "Ps2"))
from ps2_wd_reader import WdFile, WdFormatError  # noqa: E402

CORPUS = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
OUT_DIR = os.path.dirname(os.path.abspath(__file__))
END_FLAGS = {1, 3, 7}


def body_regions(wd, anchor):
    """Distinct body regions under a given anchor (wave-1/wave-2 sizing rule:
    distinct starts sorted, each ends at the next start, last at EOF;
    external descriptors excluded). Mirrors the reader's resolution but with
    a caller-supplied anchor so we can replay the wave-1 law."""
    sbo0 = wd.descriptors[0].sbo
    starts = [anchor + (d.sbo - sbo0) for d in wd.descriptors
              if d.reserved18 == 0]
    in_bank = sorted({s for s in starts
                      if anchor <= s < len(wd.data)})
    return [(s, in_bank[i + 1] if i + 1 < len(in_bank) else len(wd.data))
            for i, s in enumerate(in_bank)]


def validate(data, start, end):
    """Structural SPU-ADPCM validation of one region -> (frames, bad, flags)."""
    frames = (end - start) // 16
    bad = 0
    for f in range(frames):
        o = start + f * 16
        hdr = data[o]
        if (hdr >> 4) > 4 or (hdr & 0xF) > 12:
            bad += 1
    return frames, bad


def first_last_flags(data, start, end):
    n = (end - start) // 16
    if n <= 0:
        return None, None
    return data[start + 1], data[start + (n - 1) * 16 + 1]


def main():
    banks = []
    for dirpath, _dirs, files in os.walk(CORPUS):
        for name in sorted(files):
            if not name.lower().endswith(".wd"):
                continue
            path = os.path.join(dirpath, name)
            rel = os.path.relpath(path, CORPUS)
            try:
                with open(path, "rb") as fh:
                    wd = WdFile(fh.read(), path)
            except (OSError, WdFormatError) as exc:
                banks.append({"file": rel, "error": str(exc)})
                continue

            desc_end = wd.desc_base + wd.n_samples * 0x20
            pad = (-desc_end) % 32
            w1_anchor = desc_end + pad

            row = {
                "file": rel,
                "size": len(wd.data),
                "n_programs": wd.n_programs,
                "prog_sentinels": wd.prog_sentinels,
                "n_samples": wd.n_samples,
                "desc_base": wd.desc_base,
                "desc_end": desc_end,
                "k16": desc_end % 16,
                "align32_pad": pad,
                "sbo0_bias": wd.descriptors[0].sbo,
                "sdbse": wd.sdbse_tag,
                "aliases": sum(1 for s in wd.samples if s.is_alias),
                "externals": sum(1 for s in wd.samples if s.external),
            }

            # wave-1 replay (align32 anchor)
            w1 = {"bodies": 0, "frames": 0, "bad": 0, "dirty_bodies": 0}
            for s, e in body_regions(wd, w1_anchor):
                fr, bad = validate(wd.data, s, e)
                w1["bodies"] += 1
                w1["frames"] += fr
                w1["bad"] += bad
                if bad:
                    w1["dirty_bodies"] += 1
            row["wave1"] = w1

            # wave-2 (current law, anchor = desc_end): frames + flag semantics
            w2 = {"bodies": 0, "frames": 0, "bad": 0,
                  "first_flag0": 0, "last_END": 0, "flagged_bodies": 0}
            ff_hist, lf_hist = Counter(), Counter()
            for s, e in body_regions(wd, desc_end):
                fr, bad = validate(wd.data, s, e)
                w2["bodies"] += 1
                w2["frames"] += fr
                w2["bad"] += bad
                ff, lf = first_last_flags(wd.data, s, e)
                if ff is not None:
                    ff_hist[ff] += 1
                    lf_hist[lf] += 1
                    w2["flagged_bodies"] += 1
                    if ff == 0:
                        w2["first_flag0"] += 1
                    if lf in END_FLAGS:
                        w2["last_END"] += 1
            row["wave2"] = w2
            row["wave2_first_flag_hist"] = dict(ff_hist)
            row["wave2_last_flag_hist"] = dict(lf_hist)
            banks.append(row)

    # Re-derived wave-1 DIRTY set: >=1 body with invalid frames under the
    # wave-1 anchor. Wave-1 counted a bank DIRTY exactly when some distinct
    # body (>=1 frame) had bad>0.
    dirty = [b for b in banks
             if "wave1" in b and b["wave1"]["dirty_bodies"] > 0]
    clean_w1 = [b for b in banks
                if "wave1" in b and b["wave1"]["dirty_bodies"] == 0]
    empty = [b for b in banks
             if "wave1" in b and b["wave1"]["bodies"] == 0]
    parse_err = [b for b in banks if "error" in b]

    summary = {
        "corpus_root": CORPUS,
        "banks_total": len(banks),
        "parse_errors": len(parse_err),
        "wave1_dirty_rederived": len(dirty),
        "wave1_dirty_list": [b["file"] for b in dirty],
        "wave1_clean": len(clean_w1),
        "empty_stubs": [b["file"] for b in empty],
        "wave2_dirty": [b["file"] for b in dirty if b["wave2"]["bad"] > 0],
        "wave2_bad_frames_total": sum(b["wave2"]["bad"] for b in banks
                                      if "wave2" in b),
        "wave2_frames_total": sum(b["wave2"]["frames"] for b in banks
                                  if "wave2" in b),
        "k16_histogram_of_dirty": dict(Counter(b["k16"] for b in dirty)),
        "clean_banks_with_k16_nonzero": sum(
            1 for b in clean_w1 if b["k16"] != 0),
    }

    with open(os.path.join(OUT_DIR, "wd_dirty_dossier.json"), "w") as fh:
        json.dump({"summary": summary, "banks": banks}, fh, indent=1)

    # Markdown dossier
    lines = ["# WD-DIRTY dossier — rederivacao independente (2026-09-15)", "",
             f"corpus: `{CORPUS}` — {len(banks)} bancos", "",
             "| banco | desc_end | k16 | pad | w1 frames val | w2 frames val | "
             "bodies | 1o-frame=0 | last-END | quirks |",
             "|---|---|---|---|---|---|---|---|---|---|"]
    for b in dirty:
        w1, w2 = b["wave1"], b["wave2"]
        w1v = (100 * (w1["frames"] - w1["bad"]) / max(w1["frames"], 1))
        w2v = (100 * (w2["frames"] - w2["bad"]) / max(w2["frames"], 1))
        quirks = []
        if b["externals"]:
            quirks.append(f"ext={b['externals']}")
        if b["aliases"]:
            quirks.append(f"alias={b['aliases']}")
        if b["sbo0_bias"]:
            quirks.append(f"sbo0={b['sbo0_bias']}")
        if b["prog_sentinels"]:
            quirks.append(f"sent={b['prog_sentinels']}")
        if b["sdbse"]:
            quirks.append("SDBse")
        lines.append(
            f"| {b['file']} | {b['desc_end']:#x} | {b['k16']} | "
            f"{b['align32_pad']} | {w1v:.1f}% | {w2v:.1f}% | "
            f"{w2['bodies']} | {w2['first_flag0']}/{w2['flagged_bodies']} | "
            f"{w2['last_END']}/{w2['flagged_bodies']} | "
            f"{','.join(quirks) or '-'} |")
    lines += ["", "## summary", "```json",
              json.dumps(summary, indent=1), "```"]
    with open(os.path.join(OUT_DIR, "wd_dirty_dossier.md"), "w") as fh:
        fh.write("\n".join(lines) + "\n")

    print(json.dumps(summary, indent=1))


if __name__ == "__main__":
    main()
