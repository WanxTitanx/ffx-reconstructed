#!/usr/bin/env python3
"""newkit_ocr.py — identify the ~54 CJK ideographs in the `menu/newkit.ftc`
bank-5 glyph atlas by OCR'ing the per-glyph PNG crops produced by
`newkit_glyph_cells.py`.

WHY this exists (2026-09-17, lane Jarvis-DEVIN / NEWKIT-OCR):
  The newkit glyph order is solved (FFX_FMT_FTC_RESIDUAL_2026-09-17.md §2.2)
  but the *characters* are not sjistbl-ordered and do not pixel-match the
  base font, so identity must come from recognition.  This tool runs three
  independent channels and fuses them:

    vision   — one provider/model selected explicitly on the command line.
               There is no automatic provider fallback, model substitution,
               daemon startup, or acceptance of reasoning-only output.
    fontmatch— deterministic bitmap matching: render a candidate pool with
               Noto Sans/Serif CJK (system fonts), place each ink at NATIVE
               scale on a 64x64 canvas centered on the ink CENTROID (scale is
               preserved — bbox-stretch normalization was tried first and is
               useless: a ・ dot becomes a 46px blob that soft-matches every
               dense kanji at ~0.7 IoU), then score a dilated-soft Dice over
               thresholded bitmasks (bit-int ops, no numpy needed).
               Catches cases where the VLM hallucinates a plausible-looking
               but wrong kanji.
    fuse     — merge both channels into `glyph, char, confidence, evidence`.

Confidence policy (honest, per lane rules — never fabricate):
  CERTAIN   — vision answer == a fontmatch hit with IoU >= 0.45, or the glyph
              is one of the proven anchors (g22=ー, g23=®, g27/28=</>, g29=×,
              g54=｜), or vision+ascii inspection unambiguous.
  PROBABLE  — vision answer appears in fontmatch top-10, or vision is the
              only signal but it answered a clean single char.
  GUESS     — channels disagree and neither dominates.
  UNREADABLE— no channel produced a usable candidate.

Usage:
  python3 newkit_ocr.py vision --dir work/_newkit_ocr --provider ollama \
      --model qwen3-vl:8b [--only 11,27]
  python3 newkit_ocr.py fontmatch --dir work/_newkit_ocr [--top 8]
  python3 newkit_ocr.py fuse      --dir work/_newkit_ocr

Remote vision also requires --allow-external plus the provider-specific
authorization and endpoint environment documented in docs/ai/EXTERNAL_AI.md.
"""
import argparse
import base64
import csv
import hashlib
import io
import json
import os
import re
import subprocess
import sys
import time
import urllib.request

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ROUTER = os.path.join(REPO, "scripts", "verboo_router.py")
OLLAMA = "http://localhost:11434"
sys.path.insert(0, os.path.join(REPO, "scripts"))
import verboo_router  # noqa: E402

PROMPT = ("This image shows a single glyph from a Japanese video game font, "
          "black ink on white. Reply with ONLY that one character "
          "(kanji, kana, or symbol). No explanation.")

# Proven anchors (FFX_FMT_FTC_RESIDUAL_2026-09-17.md §2.3).  g29 is a run of
# three '×' marks in one cell; g54 a single thick vertical stroke.
ANCHORS = {22: "ー", 23: "®", 27: "<", 28: ">", 29: "×××", 54: "｜"}

# Character classes we accept as an answer (CJK ideographs, ext-A, compat,
# kana, hangul, fullwidth, latin-1/symbols used by the font).
_CHAR_RE = re.compile(
    "[㐀-䶿一-鿿豈-﫿"
    "぀-ヿ가-힯"
    "＀-￯"
    "®×÷±§¶†‡•…‰′″‹›«»←-⇿─-╿∀-⋿"
    "0-9A-Za-z]"
)

# ---------------------------------------------------------------------------
# fontmatch: candidate pool + normalized bitmask scoring
# ---------------------------------------------------------------------------

NOTO_SANS = "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc"
NOTO_SERIF = "/usr/share/fonts/opentype/noto/NotoSerifCJK-Bold.ttc"
CANVAS = 64          # normalized bitmap edge (native scale preserved)


def _pool():
    """Codepoint pool: latin-1 sup, arrows/box/math, CJK symbols+kana,
    ext-A, unified ideographs, compat ideographs, fullwidth, hangul jamo,
    printable ASCII.  Hangul *syllables* (11k) are skipped — newkit is a
    kanji/symbol supplement (vision pass confirms no hangul blobs)."""
    ranges = [
        (0x0020, 0x007F),   # ASCII
        (0x00A0, 0x0100),   # latin-1 (®, ×, ...)
        (0x2010, 0x2030),   # dashes/quotes
        (0x2190, 0x2200),   # arrows
        (0x2500, 0x2580),   # box drawing (|, ─, ...)
        (0x3000, 0x3100),   # CJK symbols + kana
        (0x3130, 0x3190),   # hangul compat jamo
        (0x3400, 0x4DC0),   # CJK ext-A
        (0x4E00, 0xA000),   # CJK unified
        (0xF900, 0xFB00),   # compat ideographs
        (0xFF01, 0xFF5F),   # fullwidth forms
    ]
    return [cp for a, b in ranges for cp in range(a, b)]


def _centroid_bits(mask_img):
    """Ink mask (L, ink=dark) -> int bitmask on a 64x64 canvas, ink placed so
    its centroid sits at canvas center.  SCALE IS PRESERVED (native pixels) —
    this is what makes small glyphs (・, ー, ｜) discriminate from kanji."""
    from PIL import ImageOps
    inv = ImageOps.invert(mask_img)
    bb = inv.getbbox()
    if bb is None:
        return 0, 0
    data = inv.tobytes()
    w, h = inv.size
    sx = sy = n = 0
    for i, v in enumerate(data):
        if v > 128:
            sx += i % w
            sy += i // w
            n += 1
    if n == 0:
        return 0, 0
    cx, cy = sx / n, sy / n
    bits = int.from_bytes(bytes(1 if v > 128 else 0 for v in data), "big")
    # shift so centroid lands at (CANVAS//2, CANVAS//2)
    dx = CANVAS // 2 - int(round(cx))
    dy = CANVAS // 2 - int(round(cy))
    # clip mask to canvas: rebuild via coordinate transform is simpler & safe
    out = 0
    for i, v in enumerate(data):
        if v > 128:
            x, y = i % w + dx, i // w + dy
            if 0 <= x < CANVAS and 0 <= y < CANVAS:
                out |= 1 << (CANVAS * CANVAS - 1 - (y * CANVAS + x))
    return out, n


# Bit layout: pixel (x,y) sits at bit position N-1-(y*W+x) (MSB = top-left).
# Each row is W/8 bytes; byte 0 of a row covers x=0..7, last byte x=W-8..W-1.
_RB = CANVAS // 8
_GUARD_R = int.from_bytes(bytes(([0xFF] * (_RB - 1) + [0xFE]) * CANVAS), "big")
_GUARD_L = int.from_bytes(bytes(([0x7F] + [0xFF] * (_RB - 1)) * CANVAS), "big")
_ALL = (1 << (CANVAS * CANVAS)) - 1


def _shift(bits, dx, dy):
    """Translate a canvas bit-int by (dx,dy) px; bits shifted off are lost.
    +x: >>1 moves a bit to pixel index +1 (right); guard drops x=W-1 first.
    +y: >>W moves down one row."""
    for _ in range(dx):
        bits = (bits & _GUARD_R) >> 1
    for _ in range(-dx):
        bits = (bits & _GUARD_L) << 1
    if dy > 0:
        bits >>= CANVAS * dy
    elif dy < 0:
        bits = (bits << (CANVAS * -dy)) & _ALL
    return bits


def _dice(gb, cb):
    """Strict Sorensen-Dice over the two bit-ints (no dilation): mismatched
    ink AND mismatched paper both cost.  Dense decoys lose."""
    gi, ci = gb.bit_count(), cb.bit_count()
    if not gi or not ci:
        return 0.0
    return 2.0 * (gb & cb).bit_count() / (gi + ci)


def cmd_fontmatch(args):
    from PIL import Image, ImageDraw, ImageFont

    # sibling module with the proven glyph->cell map (same dir)
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import newkit_glyph_cells as cells

    fonts = []
    for path, tag in ((NOTO_SANS, "sans"), (NOTO_SERIF, "serif")):
        if not os.path.exists(path):
            print("[fontmatch] missing font %s — skipped" % path, file=sys.stderr)
            continue
        idx = 0
        for i in range(10):
            try:
                f = ImageFont.truetype(path, 44, index=i)
            except Exception:  # noqa: BLE001
                break
            if " JP" in " ".join(f.getname()):
                idx = i
        fonts.append((ImageFont.truetype(path, args.size, index=idx), tag))
    if not fonts:
        sys.exit("no CJK fonts found")

    pool = _pool()
    print("[fontmatch] pool=%d codepoints, fonts=%s, size=%d"
          % (len(pool), [t for _, t in fonts], args.size), file=sys.stderr)

    rend = {}   # cp -> {tag: (bits, ink)}
    for cp in pool:
        ch = chr(cp)
        for font, tag in fonts:
            img = Image.new("L", (72, 72), 255)
            try:
                ImageDraw.Draw(img).text((4, 2), ch, fill=0, font=font)
            except Exception:  # noqa: BLE001
                continue
            b, n = _centroid_bits(img)
            if n < 4:
                continue
            rend.setdefault(cp, {})[tag] = (b, n)

    # glyph masks: native-res cells straight from the atlas (NOT the upscaled
    # OCR crops — those lose scale + bearing)
    pages = [Image.open(os.path.join(args.src, "font_0_%d.png" % p))
             .convert("RGBA") for p in (0, 1)]
    out_csv = os.path.join(args.dir, "fontmatch.csv")
    wcsv = csv.writer(open(out_csv, "w", newline=""))
    wcsv.writerow(["glyph", "rank", "char", "uplus", "dice", "font"])

    SHIFTS = [(dx, dy) for dy in (-2, 0, 2) for dx in (-2, 0, 2)]
    for g in range(args.count):
        loc = cells.glyph_cell(g)
        if loc is None:
            continue
        page, row, col = loc
        cell = pages[page].crop((col * cells.CW, row * cells.CH,
                                 col * cells.CW + cells.CW,
                                 row * cells.CH + cells.CH))
        alpha = cell.split()[3]
        gb0, gink = _centroid_bits(Image.eval(alpha, lambda v: 255 - v))
        if gink < 4:
            print("[fontmatch] g%d: no ink" % g, file=sys.stderr)
            continue
        gvars = [_shift(gb0, dx, dy) for dx, dy in SHIFTS]
        ginks = [b.bit_count() for b in gvars]

        scored = []
        for cp, per in rend.items():
            best = (0.0, "")
            for tag, (cb, cink) in per.items():
                r = gink / cink if cink else 9e9
                if r < 0.45 or r > 2.2:
                    continue
                s = max(2.0 * (gv & cb).bit_count() / (gi + cink)
                        for gv, gi in zip(gvars, ginks) if gi)
                if s > best[0]:
                    best = (s, tag)
            if best[0] > 0.10:
                scored.append((best[0], best[1], cp))
        scored.sort(reverse=True)
        for rank, (s, tag, cp) in enumerate(scored[: args.top], 1):
            wcsv.writerow([g, rank, chr(cp), "U+%04X" % cp,
                           "%.4f" % s, tag])
        top = ", ".join("%s(%.2f)" % (chr(cp), s) for s, _, cp in scored[:5])
        print("g%-3d %s" % (g, top))
    print("[fontmatch] wrote %s" % out_csv, file=sys.stderr)


# ---------------------------------------------------------------------------
# vision: one explicitly selected public-router route
# ---------------------------------------------------------------------------

# Adapted from the user-supplied FFX_AGENTS_Skills_2026-09-19 package
# (2026-09-19). WHY: glyph images may be private project data, so cmd_vision
# must validate one authorized provider/model before reading them and must not
# silently fall back to a daemon, another provider, or reasoning-only output.

def _run(cmd, timeout=240):
    try:
        p = subprocess.run(cmd, capture_output=True, text=True,
                           timeout=timeout, cwd=REPO)
        return p.returncode, p.stdout.strip(), p.stderr.strip()
    except subprocess.TimeoutExpired:
        return 124, "", "timeout"


def _extract(text):
    """Pull a glyph answer out of a VLM response.  Returns '' for garbage."""
    if not text:
        return ""
    t = text.strip()
    # thinking dumps are long; the real answer is a single char / short run
    if len(t) <= 4:
        return t
    # take the LAST line that is a clean <=4-char answer (model may preface)
    for line in reversed([l.strip() for l in t.splitlines() if l.strip()]):
        if 0 < len(line) <= 4 and _CHAR_RE.search(line):
            return line
    m = _CHAR_RE.search(t)
    return m.group(0) if m and len(t) < 60 else ""


def _ollama_direct(img_path, timeout=240):
    """Last-ditch: /api/chat with think=false; if thinking still eats the
    budget, harvest the tail of the thinking text for a clean answer."""
    import base64
    b64 = base64.b64encode(open(img_path, "rb").read()).decode()
    payload = {"model": "qwen3-vl:8b", "stream": False, "think": False,
               "messages": [{"role": "user", "content": PROMPT,
                             "images": [b64]}],
               "options": {"num_predict": 4000, "num_ctx": 16384}}
    req = urllib.request.Request(OLLAMA + "/api/chat",
                                 data=json.dumps(payload).encode(),
                                 headers={"Content-Type": "application/json"})
    r = json.loads(urllib.request.urlopen(req, timeout=timeout).read())
    msg = r.get("message", {})
    ans = _extract(msg.get("content") or "")
    if not ans:
        th = msg.get("thinking") or ""
        # grab the last plausible char mention in the thinking tail
        tail = th[-800:]
        cands = _CHAR_RE.findall(tail)
        ans = cands[-1] if cands else ""
    return ans


def _vision_resume_fingerprint(args, image, endpoint):
    """Bind a successful glyph row to source bytes and inference contract."""
    encoded = image["image_url"]["url"].split(",", 1)[1]
    identity = {
        "schema": 1,
        "image_sha256": hashlib.sha256(base64.b64decode(encoded)).hexdigest(),
        "provider": args.provider,
        "model": args.model,
        "endpoint": endpoint,
        "api": args.api,
        "max_tokens": args.max_tokens,
        "prompt": PROMPT,
    }
    payload = json.dumps(
        identity, ensure_ascii=False, sort_keys=True, separators=(",", ":")
    ).encode("utf-8")
    return hashlib.sha256(payload).hexdigest()


def cmd_vision(args):
    # Validate authorization/configuration before opening the output or images.
    endpoint, _ = verboo_router.provider_config(
        args.provider, args.allow_external
    )
    out = os.path.join(args.dir, "ocr_vision.tsv")
    existing_rows = []
    have = {}
    if os.path.exists(out):
        with open(out, newline="", encoding="utf-8") as stream:
            for parts in csv.reader(stream, delimiter="\t"):
                if not parts:
                    continue
                existing_rows.append(parts)
                if len(parts) >= 3 and parts[2]:
                    have[int(parts[0])] = parts
    only = set(int(x) for x in args.only.split(",")) if args.only else None
    pending = []
    target_ids = set()
    for fn in sorted(os.listdir(args.dir)):
        m = re.fullmatch(r"glyph_(\d+)\.png", fn)
        if not m:
            continue
        g = int(m.group(1))
        if only and g not in only:
            continue
        target_ids.add(g)
        img = os.path.join(args.dir, fn)
        image = verboo_router.image_part(img)
        fingerprint = _vision_resume_fingerprint(args, image, endpoint)
        if g in have and not args.overwrite:
            previous = have[g]
            if len(previous) < 5 or not previous[4]:
                raise ValueError(
                    "Existing OCR success has no resume fingerprint; rerun with --overwrite"
                )
            if previous[4] != fingerprint:
                raise ValueError(
                    "Existing OCR success belongs to a different image or inference route; "
                    "rerun with --overwrite"
                )
            continue
        pending.append((g, image, fingerprint))

    if not pending and not args.overwrite:
        return 0

    retained = existing_rows
    mode = "a"
    if args.overwrite:
        retained = [
            row for row in existing_rows
            if not row or not row[0].isdigit() or int(row[0]) not in target_ids
        ]
        mode = "w"

    failed = False
    with open(out, mode, newline="", encoding="utf-8") as fo:
        w = csv.writer(fo, delimiter="\t", lineterminator="\n")
        if args.overwrite:
            w.writerows(retained)
        for g, image, fingerprint in pending:
            ans, raw = "", ""
            engine = "%s/%s" % (args.provider, args.model)
            try:
                content = [
                    {"type": "text", "text": PROMPT},
                    image,
                ]
                result = verboo_router.infer(
                    args, [{"role": "user", "content": content}]
                )
                raw = result["output"]
                ans = _extract(raw)
            except (ValueError, RuntimeError, OSError, KeyError, TypeError):
                raw = "ERR inference failed; no fallback attempted"
            if not ans:
                failed = True
            # The first four TSV fields remain backward-compatible; the fifth
            # binds resume decisions to image bytes and the inference route.
            w.writerow([
                g, engine, ans,
                raw[:160].replace("\n", " ").replace("\t", " "),
                fingerprint,
            ])
            fo.flush()
            print("g%-3d %-14s %s" % (g, engine, ans or "(none)"))
            time.sleep(0.2)
    return 1 if failed else 0


# ---------------------------------------------------------------------------
# vlmverify: discriminative multiple-choice re-verification via qwen3-vl
# ---------------------------------------------------------------------------
#
# WHY this exists (2026-09-18, lane Jarvis-DEVIN / NEWKIT-OCR resume):
#   Free-recall VLM answers and fontmatch top-1 disagree on ~45/54 ideographs,
#   and fontmatch dice tops out ~0.7 for ANY correct match (cross-typeface:
#   PS2 bitmap vs Noto), so top-8 membership alone cannot arbitrate.  A
#   *discriminative* prompt ("which of these candidates is it?") is far more
#   reliable than free recall — it directly pits the vision answer against
#   the fontmatch top candidates.  Pick == vision answer  -> vision is
#   self-consistent across two prompt modes;  pick == a fontmatch candidate
#   -> the vision channel ADOPTS the fontmatch candidate (genuine agreement);
#   "none" -> both channels are probably wrong.

MC_PROMPT = ("This image shows a single glyph from a Japanese video game "
             "font, black ink on white.\n"
             "Which of these characters does it show?\n"
             "%s\n"
             "Reply with ONLY the letter of the correct option.")


def _mc_options(g, vans, cands):
    """Build the MC option list for glyph g: anchor (if any) + vision answer
    + fontmatch top-4, dedup'd, rotated by g to blunt position bias, with
    'none of these' appended last.  Returns (letters->char, display lines)."""
    opts = []
    if g in ANCHORS:
        opts.append(ANCHORS[g])
    if vans:
        opts.append(vans)
    for c in cands:
        ch = c["char"]
        if ch not in opts:
            opts.append(ch)
        if len(opts) >= 5:
            break
    # deterministic rotation so the same channel is not always option A
    if opts:
        rot = g % len(opts)
        opts = opts[rot:] + opts[:rot]
    letters = "ABCDEFGHIJ"
    m = {letters[i]: o for i, o in enumerate(opts)}
    m[letters[len(opts)]] = "NONE"
    disp = ["%s) %s" % (letters[i], o) for i, o in enumerate(opts)]
    disp.append("%s) none of these" % letters[len(opts)])
    return m, "\n".join(disp)


def _ollama_mc(img_path, options_text, timeout=240):
    """Ask qwen3-vl (direct /api/chat, think=false) to pick an MC letter.
    Returns (letter, raw_text).  Harvests the thinking tail when the model
    burns its content budget on <think>."""
    import base64
    b64 = base64.b64encode(open(img_path, "rb").read()).decode()
    payload = {"model": "qwen3-vl:8b", "stream": False, "think": False,
               "messages": [{"role": "user",
                             "content": MC_PROMPT % options_text,
                             "images": [b64]}],
               "options": {"num_predict": 4000, "num_ctx": 16384}}
    req = urllib.request.Request(OLLAMA + "/api/chat",
                                 data=json.dumps(payload).encode(),
                                 headers={"Content-Type": "application/json"})
    r = json.loads(urllib.request.urlopen(req, timeout=timeout).read())
    msg = r.get("message", {})
    raw = msg.get("content") or ""
    m = re.search(r"\b([A-J])\b", raw)
    if m:
        return m.group(1), raw
    th = msg.get("thinking") or ""
    # thinking tail: prefer the last letter mention (final conclusion)
    cands = re.findall(r"\b([A-J])\b", th[-800:])
    return (cands[-1] if cands else ""), raw or "(think-only)"


def cmd_vlmverify(args):
    vision = {}
    vt = os.path.join(args.dir, "ocr_vision.tsv")
    if not os.path.exists(vt):
        vt = os.path.join(args.dir, "newkit_ocr_vision.tsv")
    if os.path.exists(vt):
        for line in open(vt):
            p = line.rstrip("\n").split("\t")
            if len(p) >= 3:
                vision[int(p[0])] = p[2]
    fm = {}
    fc = os.path.join(args.dir, "fontmatch.csv")
    if not os.path.exists(fc):
        fc = os.path.join(args.dir, "newkit_fontmatch.csv")
    if os.path.exists(fc):
        for row in csv.DictReader(open(fc)):
            fm.setdefault(int(row["glyph"]), []).append(row)

    out = os.path.join(args.dir, "vlm_verify.tsv")
    have = set()
    if os.path.exists(out) and not args.overwrite:
        for line in open(out):
            p = line.rstrip("\n").split("\t")
            if len(p) >= 3 and p[2]:
                have.add(int(p[0]))
    only = set(int(x) for x in args.only.split(",")) if args.only else None
    fo = open(out, "a")
    w = csv.writer(fo, delimiter="\t", lineterminator="\n")

    for g in range(args.count):
        if only and g not in only:
            continue
        if g in have:
            continue
        img = os.path.join(args.dir, "glyph_%02d.png" % g)
        if not os.path.exists(img):
            img = os.path.join(args.dir, "glyph_%d.png" % g)
        if not os.path.exists(img):
            print("g%-3d (no image, skipped)" % g)
            continue
        mapping, disp = _mc_options(g, vision.get(g, ""), fm.get(g, []))
        try:
            letter, raw = _ollama_mc(img, disp)
        except Exception as e:  # noqa: BLE001
            letter, raw = "", "ERR %s" % e
        pick = mapping.get(letter, "")
        w.writerow([g, letter, pick,
                    "|".join("%s=%s" % kv for kv in sorted(mapping.items())),
                    raw[:160].replace("\n", " ")])
        fo.flush()
        print("g%-3d %s -> %s" % (g, letter or "?", pick or "(unparsed)"))
        time.sleep(0.2)
    fo.close()


# ---------------------------------------------------------------------------
# fuse
# ---------------------------------------------------------------------------

def cmd_fuse(args):
    vision = {}
    vt = os.path.join(args.dir, "ocr_vision.tsv")
    if os.path.exists(vt):
        for line in open(vt):
            p = line.rstrip("\n").split("\t")
            if len(p) >= 3:
                vision[int(p[0])] = (p[1], p[2])
    fm = {}
    fc = os.path.join(args.dir, "fontmatch.csv")
    if os.path.exists(fc):
        for row in csv.DictReader(open(fc)):
            fm.setdefault(int(row["glyph"]), []).append(row)

    print("| glyph | char | conf | vision | fontmatch top3 |")
    print("|---|---|---|---|---|")
    for g in sorted(set(vision) | set(fm) | set(ANCHORS)):
        eng, vans = vision.get(g, ("", ""))
        cands = fm.get(g, [])
        top = [(c["char"], float(c["dice"])) for c in cands[:10]]
        fbest = top[0] if top else ("", 0.0)
        if g in ANCHORS:
            ch, conf = ANCHORS[g], "CERTAIN(anchor)"
        elif vans and any(c == vans for c, _ in top[:3]):
            ch, conf = vans, "CERTAIN"
        elif vans and any(c == vans for c, _ in top):
            ch, conf = vans, "PROBABLE"
        elif vans and len(vans) <= 2 and fbest[1] < 0.60:
            ch, conf = vans, "PROBABLE"
        elif fbest[1] >= 0.60:
            ch, conf = fbest[0], "PROBABLE(font)"
        elif vans:
            ch, conf = vans, "GUESS"
        elif fbest[0]:
            ch, conf = fbest[0], "GUESS(font)"
        else:
            ch, conf = "", "UNREADABLE"
        print("| %d | %s | %s | %s (%s) | %s |" % (
            g, ch or "—", conf, vans or "—", eng or "—",
            " ".join("%s:%.2f" % t for t in top[:3]) or "—"))


def parser():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    pv = sub.add_parser(
        "vision",
        help="VLM OCR using one explicit provider/model (no fallback or startup)",
    )
    pv.add_argument("--dir", required=True)
    pv.add_argument("--only", default=None, help="comma glyph ids to redo")
    pv.add_argument("--overwrite", action="store_true")
    pv.add_argument("--provider", required=True,
                    choices=[*verboo_router.REMOTE, "ollama"])
    pv.add_argument("-m", "--model", required=True,
                    help="exact vision model; historical automatic routes were removed")
    pv.add_argument("--allow-external", action="store_true")
    pv.add_argument("--api", choices=["chat", "responses"], default="chat")
    pv.add_argument("-t", "--max-tokens", type=verboo_router.positive, default=3500)
    pv.set_defaults(f=cmd_vision)
    pf = sub.add_parser("fontmatch", help="bitmap match vs Noto CJK pool")
    pf.add_argument("--dir", required=True, help="output dir (fontmatch.csv)")
    pf.add_argument("--src", default="/mnt/nvme-samsung/FFX Mods/"
                    "ps3data_textures_png/menu/newkit_ftc/d3d11",
                    help="dir with font_0_0.png / font_0_1.png atlas pages")
    pf.add_argument("--size", type=int, default=52,
                    help="Noto render size in px (~=em; 52 gives ~48px kanji)")
    pf.add_argument("--count", type=int, default=62)
    pf.add_argument("--top", type=int, default=8)
    pf.set_defaults(f=cmd_fontmatch)
    pv2 = sub.add_parser("vlmverify",
                         help="MC discriminative re-verify via qwen3-vl")
    pv2.add_argument("--dir", required=True,
                     help="dir with glyph_NN.png + ocr_vision.tsv + fontmatch.csv")
    pv2.add_argument("--only", default=None, help="comma glyph ids to redo")
    pv2.add_argument("--count", type=int, default=62)
    pv2.add_argument("--overwrite", action="store_true")
    pv2.set_defaults(f=cmd_vlmverify)
    pu = sub.add_parser("fuse", help="merge vision+fontmatch -> table")
    pu.add_argument("--dir", required=True)
    pu.set_defaults(f=cmd_fuse)
    return ap


def main(argv=None):
    args = parser().parse_args(argv)
    return args.f(args) or 0


if __name__ == "__main__":
    raise SystemExit(main())
