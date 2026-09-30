#!/usr/bin/env python3
"""LocKit reader/decoder — FFX / FFX-2 HD regional LocKit .BIN files.

Real corpus (extracted PS3 gamedata):
  .../gamedata/ps3data/lockit/ffx_loc_kit_ps3_{jp,us,fr,sp,de,it,kr,ch}.bin
  .../gamedata/ps3data/lockit/ffx2_loc_kit_ps3_{...}.bin

WHAT THE FILE IS (verified 2026-09-16 against the real corpus):
  * LF (0x0A) separated lines; CR (0x0D) is stripped per line — this matches the
    runtime: FFX_LocKit_GetLineByIndex splits on 0x0A and drops 0x0D.
  * Each line payload is one of two encodings, mixed freely inside a file:
      a) FFX custom text encoding (the game "bytecode" text):
           - byte 0x30..0xFF        -> glyph index (b - 0x30) into sjistbl
           - 2-byte glyph pair (lead,next) with next in 0x30..0xFF:
                 idx = 208*lead + next + BIAS  (BIAS per bank, see BANKS)
             (authoritative formula from FfxEncoding.glyph.cs /
              FFX_EventText_AdvanceCharGlyph@0x8B92E0)
           - bytes < 0x30 (that are not glyph leads) are control codes
             (0x03 = paragraph/break marker, 0x05 = variable slot, ...)
      b) plain UTF-8 text (ASCII counts). JP save-dialog lines such as
         "新規セーブデータを作成" are stored as real UTF-8.
  * The game picks the interpretation by line index/context, not by content.
    For display we heuristically show the reading that looks more like text:
    strict-UTF-8 decode vs custom-table decode; lines whose raw bytes are not
    valid UTF-8 are almost always custom-encoded.

  * The per-language glyph table is the UTF-8 "sjistbl" (one glyph per index):
        ffx_ps2/ffx/master/jppc/ffx_encoding/ffxsjistbl_{us,jp,kr,ch,cn}.bin
        ffx_ps2/ffx2/master/jppc/ffx2_encoding/ffx2sjistbl_{us,jp,kr,ch,cn}.bin
    Western languages (us/de/fr/it/sp) share the `us` table; cn uses ch/cn.

SECOND FAMILY — PC-version per-system lockit containers
  (.../GameData/PS3Data/{de,us,...}_lockit/*.bin — 24 files/dir):
  * header: u32LE = 1 then u16 fields (0x0A/0x0C/0x0E = section descriptors;
    exact per-field semantics UNKNOWN — e.g. build_txt/arms_txt share
    0x15/0x10/0x160).
  * index table from ~0x14: u16LE pairs (poolRelOffset, keyId); the offset
    element is PROVEN to match pool-relative string starts (0,0x28,0x2a,...)
    while keyId semantics are UNKNOWN (0x000A dominates; larger values like
    0x00E6/0x004D/0x0088/0x00E4 attach to full sentences — probably text IDs).
    Some offsets point MID-string (substring references).
  * string pool: 0x00-terminated strings in the FFX custom encoding
    (decodes to e.g. German "Welchen Ausrüstungsgegenstand umbauen?").
  * invoked with --pool, or auto-detected when u32@0 == 1.

  * EARLIER "-15 per byte" hypothesis (QA notes) is WRONG — it only coincides
    on the US ASCII subrange because table[i] == chr(i + 0x21) there
    ('U'->'F' both ways). It diverges on ':'->' ' (not '+'), 'H'->'.'
    (not '9'), 'O'->'?' (not '@'), and all of JP/KR/CH. Do not use it.

Usage:
  lockit_reader.py FILE.bin [--table SJISTBL] [--lang L] [--list] [--get N] [--raw] [--stats]
  lockit_reader.py DIR    --all of the above per *.bin found in DIR

  --table PATH  sjistbl UTF-8 table to use (auto-detected by --lang otherwise:
                searches <file_dir>/../../ffx_encoding, .../ffx2_encoding,
                FFX_ENCODING_DIR env, and the extracted-corpus defaults below)
  --lang L      jp|kr|ch|cn|us|de|fr|it|sp (default: parsed from filename)
  --list        one line per record: idx, class, decoded text
  --get N       print only line N
  --raw         show raw bytes instead of decoded text
  --stats       control-byte / class census only
  --pool        force *_lockit/*.bin index+pool mode (auto when u32@0==1)

Exit code 0 = file(s) read; 1 = a file failed; 2 = usage error.
"""
import os, sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# 2-byte glyph banks — authoritative formula idx = 208*lead + next + Bias,
# from FfxEncoding.glyph.cs (runtime: FFX_EventText_AdvanceCharGlyph@0x8B92E0).
# FONT0 = base.ftc -> indexes the sjistbl char table directly (proven on corpus:
#   ',5' = [0x2C,0x35] -> idx 213 -> 'Ｆ' in ffxsjistbl_jp).
# FONT2/FONT3/FONT5/FTCX are OTHER font banks; their indices do NOT address the
# sjistbl — emitted as <BANK:idx> markers (UNKNOWN glyph semantics).
#   Observed: <F5:1> renders as '®' in "PlayStation<F5:1>4" (KR file).
BANKS = [
    (0x2C, 0x2F, -8992, "F0", True),    # FONT0  -> sjistbl[idx]
    (0x2A, 0x2B, -8784, "FTCX", False), # event FTCX (not seen in LocKit)
    (0x28, 0x29, -8368, "F2", False),
    (0x26, 0x27, -7952, "F3", False),
    (0x06, 0x06, -1296, "F5", False),   # idx = next - 0x30
]
LEADS = frozenset(b for lo, hi, *_ in BANKS for b in range(lo, hi + 1))
WESTERN = {"us", "de", "fr", "it", "sp"}

# Default corpus search paths (Linux mounts of the extracted PS2 trees).
CORPUS_HINTS = [
    "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/ffx_encoding",
    "/mnt/nvme-samsung/FFX Extracted/FFX2/ffx_ps2/ffx2/master/jppc/ffx2_encoding",
]


def lang_of(path: str) -> str:
    base = os.path.basename(path).lower()
    # ffx_loc_kit_ps3_us.bin / ffx2_loc_kit_ps3_jp.bin -> last token
    stem = base.rsplit(".", 1)[0]
    lang = stem.rsplit("_", 1)[-1] if "_" in stem else "us"
    if lang in ("jp", "kr", "ch", "cn", "us", "de", "fr", "it", "sp"):
        return lang
    # *_lockit/*.bin containers: language is the parent dir prefix (de_lockit)
    par = os.path.basename(os.path.dirname(os.path.abspath(path))).lower()
    if par.endswith("_lockit"):
        return par[:-7]
    return "us"


def is_ffx2(path: str) -> bool:
    return os.path.basename(path).lower().startswith("ffx2")


def find_table(path: str, lang: str, game2: bool):
    """Locate the sjistbl UTF-8 file for lang/game. Returns path or None."""
    tlang = lang if lang in ("jp", "kr", "ch", "cn") else "us"
    names = ([f"ffx2sjistbl_{tlang}.bin"] if game2 else []) + \
            [f"ffxsjistbl_{tlang}.bin",
             f"ffx2sjistbl_{tlang}.bin" if not game2 else f"ffxsjistbl_{tlang}.bin"]
    cands = []
    env = os.environ.get("FFX_ENCODING_DIR")
    if env:
        cands += [os.path.join(env, n) for n in names]
    # relative to the .bin: .../ps3data/lockit -> walk up looking for *_encoding
    d = os.path.dirname(os.path.abspath(path))
    for up in range(5):
        cands += [os.path.join(d, n) for n in names]
        for sub in os.listdir(d) if os.path.isdir(d) else []:
            sd = os.path.join(d, sub)
            if os.path.isdir(sd) and "encoding" in sub.lower():
                cands += [os.path.join(sd, n) for n in names]
        d = os.path.dirname(d)
    for hint in CORPUS_HINTS:
        cands += [os.path.join(hint, n) for n in names]
    for c in cands:
        if os.path.isfile(c):
            return c
    return None


def load_table(path):
    """sjistbl = UTF-8 string, one character per glyph index."""
    return list(open(path, "rb").read().decode("utf-8"))


def dec_custom(raw: bytes, T):
    """Decode FFX custom-encoding bytes. Returns (text, used_2byte, ctrls)."""
    out = []
    n2 = 0
    ctrls = []
    i = 0
    while i < len(raw):
        b = raw[i]
        bank = None
        if i + 1 < len(raw) and 0x30 <= raw[i + 1] <= 0xFF:
            for lo, hi, bias, name, in_tbl in BANKS:
                if lo <= b <= hi:
                    bank = (208 * b + raw[i + 1] + bias, name, in_tbl)
                    break
        if bank is not None:
            idx, name, in_tbl = bank
            if in_tbl and 0 <= idx < len(T):
                out.append(T[idx])
            else:
                out.append(f"<{name}:{idx}>")
            n2 += 1
            i += 2
        elif b >= 0x30:
            idx = b - 0x30
            out.append(T[idx] if idx < len(T) else f"<{b:02X}>")
            i += 1
        else:
            out.append(f"<{b:02X}>")
            ctrls.append(b)
            i += 1
    return "".join(out), n2, ctrls


def textiness(s: str) -> float:
    if not s:
        return 1.0
    return sum(1 for c in s if c.isprintable()) / len(s)


def classify(raw: bytes, T):
    """-> (kind, text). kind in {empty, utf8, ffx}.

    A line with >=3 valid 2-byte glyph pairs is almost certainly custom
    (plain text rarely packs lead+next pairs like 'X,X,X'). Otherwise keep
    the more text-like reading; ties prefer plain UTF-8."""
    if not raw:
        return "empty", ""
    try:
        u = raw.decode("utf-8", "strict")
        utf8_ok = True
    except UnicodeDecodeError:
        u, utf8_ok = "", False
    if not utf8_ok:
        # stray >=0x80 singles cannot be display text as stored -> custom
        txt, _, _ = dec_custom(raw, T)
        return "ffx", txt
    c, n2, _ = dec_custom(raw, T)
    if n2 >= 3:
        return "ffx", c
    if n2 and textiness(c) >= textiness(u):
        return "ffx", c
    if n2 == 0 and textiness(c) > textiness(u):
        return "ffx", c
    return "utf8", u


def census(data: bytes, T):
    lines = data.split(b"\n")
    n_cls = {"empty": 0, "utf8": 0, "ffx": 0}
    ctrl_hist = {}
    g2 = 0
    for l in lines:
        l = l.replace(b"\r", b"")
        k, _ = classify(l, T)
        n_cls[k] = n_cls.get(k, 0) + 1
        if k == "ffx":
            _, n2, ctrls = dec_custom(l, T)
            g2 += 1 if n2 else 0
            for b in ctrls:
                ctrl_hist[b] = ctrl_hist.get(b, 0) + 1
    return len(lines), n_cls, g2, ctrl_hist


def show_pool(path, data, T, argv):
    """Index+pool mode for *_lockit/*.bin containers (u32@0 == 1)."""
    import struct
    f0, f1, f2 = (struct.unpack_from("<H", data, o)[0] for o in (0x0A, 0x0C, 0x0E))
    # u16@0x0E = index-section byte size -> pool = 0x14 + f2 (proven:
    # build_txt/arms_txt 0x14+0x160=0x174 == observed pool start)
    pool = 0x14 + f2 if 0x14 + f2 < len(data) else None
    if pool is None:
        # fallback: first >=0x30 run terminated by 0x00
        i = 0x14
        while i < len(data):
            j = i
            while j < len(data) and data[j] != 0:
                j += 1
            if j > i + 2 and all(0x30 <= x for x in data[i:j]):
                pool = i
                break
            i = j + 1
    print(f"== {os.path.basename(path)}: {len(data)}B POOL-CONTAINER "
          f"fields(a/c/e)={f0:#x}/{f1:#x}/{f2:#x} "
          f"pool@{pool:#x}" if pool is not None else
          f"== {os.path.basename(path)}: {len(data)}B POOL-CONTAINER "
          f"fields(a/c/e)={f0:#x}/{f1:#x}/{f2:#x} pool@NOT-FOUND")
    # index pairs until pool
    if "--list" in argv or "--stats" in argv:
        npairs = (pool - 0x14) // 4 if pool else 0
        keyhist = {}
        for o in range(0x14, 0x14 + npairs * 4, 4):
            off, key = struct.unpack_from("<HH", data, o)
            keyhist[key] = keyhist.get(key, 0) + 1
        print(f"   index: {npairs} u16-pairs; key histogram: "
              + " ".join(f"{k:#06x}:{v}" for k, v in sorted(keyhist.items())))
    # decode pool strings
    strings = []
    if pool:
        k = pool
        while k < len(data):
            j = data.find(b"\x00", k)
            if j < 0:
                break
            s = data[k:j]
            if s:
                strings.append((k - pool, s))
            k = j + 1
    print(f"   pool: {len(strings)} strings")
    lim = len(strings) if "--list" in argv else 8
    for rel, s in strings[:lim]:
        txt, n2, ctrls = dec_custom(s, T)
        print(f"   [{rel:5d}] {txt[:80]}")
    return 0


def show(path, argv, table_cache={}):
    lang = lang_of(path)
    game2 = is_ffx2(path)
    table_path = None
    if "--table" in argv:
        table_path = argv[argv.index("--table") + 1]
    else:
        table_path = find_table(path, lang, game2)
    T = table_cache.get(table_path)
    if T is None:
        if table_path is None:
            print(f"[WARN] {path}: no sjistbl found for lang={lang} "
                  f"(pass --table); decoding 1-byte range only", file=sys.stderr)
            T = [f"<{i:02X}>" for i in range(0x1000)]
        else:
            T = load_table(table_path)
        table_cache[table_path] = T
    data = open(path, "rb").read()
    if "--pool" in argv or (len(data) >= 4 and data[:4] == b"\x01\x00\x00\x00"
                            and "_lockit" in path.lower()):
        return show_pool(path, data, T, argv)
    lines = [l.replace(b"\r", b"") for l in data.split(b"\n")]

    if "--stats" in argv:
        n, cls, g2, hist = census(data, T)
        hs = " ".join(f"0x{b:02X}:{c}" for b, c in sorted(hist.items()))
        print(f"{os.path.basename(path)}: {len(data)}B {n} lines "
              f"{cls} 2byte-glyph-lines={g2} ctrls[{hs}]")
        return 0

    get = None
    if "--get" in argv:
        try:
            get = int(argv[argv.index("--get") + 1])
        except (IndexError, ValueError):
            print("--get needs an index", file=sys.stderr)
            return 2

    hdr = f"== {os.path.basename(path)}: {len(data)} bytes, {len(lines)} lines" \
          f" (lang={lang} table={os.path.basename(table_path) if table_path else 'none'})"
    print(hdr)
    if get is not None:
        rng = [get] if 0 <= get < len(lines) else []
    elif "--list" in argv:
        rng = range(len(lines))
    else:
        rng = range(12)
    for i in rng:
        raw = lines[i]
        if "--raw" in argv:
            print(f"  [{i:4d}] {raw[:80]!r}")
            continue
        k, txt = classify(raw, T)
        print(f"  [{i:4d}] {k:5s} {txt[:100]}")
    return 0


def main(argv):
    if not argv:
        print(__doc__)
        return 2
    paths = []
    for a in argv:
        if a.startswith("--"):
            continue
        if os.path.isdir(a):
            paths += sorted(os.path.join(a, f) for f in os.listdir(a)
                            if f.lower().endswith(".bin"))
        elif os.path.isfile(a):
            paths.append(a)
        elif a.isdigit():
            continue
        else:
            # may be a --table/--get value or a bad path; only flag bad paths
            pass
    if not paths:
        print(__doc__)
        return 2
    rc = 0
    for p in paths:
        try:
            rc = show(p, argv) or rc
        except OSError as e:
            print(f"[FAIL] {p}: {e}", file=sys.stderr)
            rc = 1
    return rc


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
