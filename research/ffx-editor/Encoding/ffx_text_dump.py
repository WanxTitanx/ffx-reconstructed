#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ffx_text_dump.py — FFX text/locale/dictionary format-family dumper (audit lane tool).

Self-contained Python port of the editor's proven C# readers
(FFXProjectEditor/FfxLib/Text/*.cs + FfxLib/Encoding/FfxEncoding.*.cs),
re-derived against the real corpus on nvme-xpg (2026-09-16, Jarvis-FMT lane).

Covered formats (auto-detected or forced via --format):
  excel    kernel `battle/kernel/*_txt.bin` family — 0x14B "Excel" header
           (u32 magic=1, u32 0, u16 MinIndex, u16 MaxIndex, u16 EntryLength,
           u16 DataBlockLength, u32 headerSize=0x14) + record table +
           NUL-terminated string pool. EntryLength 0x08 => 4x u16 word offsets
           (btl_txt); 0x10 => 4x (u16 offset, u16 key) pairs
           (name/simpl-name/desc/simpl-desc); other => generic u16 lanes.
  field8   "8-byte field-string" table (TextTable_File): u16 @0 = header bytes
           (%8==0); entries = 2x {u16 off, u8 flags, u8 choices} (regular +
           simplified); pool after header.
  ptr4     "4-byte pointer-script" table (PointerScriptTable_File): u32 @0 =
           header bytes (%4==0); N x u32 absolute offsets (0 = empty slot);
           pool after header. (menu_script/battle_script/system_script.)
  dcp      chunk container (macrodic.dcp): u32 LE offset directory @0
           (stops at 0xFFFFFFFF); each chunk = u16 headerLen (=> count =
           headerLen/4 entries of u16 regular/simplified offset pairs) + pool.
  albhed   albheddic.bin: flat 4B records [src u8, mapped u8, group u16 LE].
  albhedcjk battle/kernel/albhed.bin (new_krpc/new_chpc only): 10 x u32
           offset pairs (value duplicated X,X) + 10 NUL-terminated strings.
  sjistbl  ffx_encoding/ffxsjistbl_*.bin: UTF-8 char sequence; index i maps
           text byte (0x30+i) / glyph index i to char.
  sjistbl16 menu/ffxsjistbl.bin (PS2 legacy): u16 SJIS codepoints, cp932-decoded.
  lockit   LocKit/FFX_LOC_KIT_PS3_*.BIN — PS3 trophy glossary; Caesar +15
           per byte, sep 0xFE 0xFB (cipher 0x0D 0x0A), '+' = space.

Text decoding (FfxEncoding):
  0x00 NUL terminates; 0x01..0x25 control codes (0x03=\n, 0x0A=format+param,
  0x13=charname+param); 0x06 and 0x26..0x2F are 2-byte glyph leads.
  1-byte: char = table[byte-0x30]. 2-byte: glyphIdx = 208*L + N - 8992
  (empirically proven against ffxsjistbl_jp.bin: (0x2C,0xB1)+(0x2D,0x9F) ->
  U+6C7A U+5B9A = kanji "ketsu/tei"; matches generated JpGlyphTable keys in
  research_tools/Encoding/FfxEncoding.tables.cs). Out-of-range glyph pairs fall
  back to the editor's bank-token form (<FONT0/FONT2/FONT3/FTCX/FONT5:idx>).

Usage:
  python3 ffx_text_dump.py <file> [--table ffxsjistbl_XX.bin] [--format FMT]
  python3 ffx_text_dump.py --batch <rootdir> --table <tbl-or-auto> -o OUTDIR
"""
import argparse
import pathlib
import struct
import sys

# ── Control-code metadata (FfxEncoding.control.cs, ported verbatim) ──
C_NULL, C_NEW_LINE, C_FORMAT, C_CHAR_NAME = 0, 3, 10, 19
CONTROL_CODES = set(range(0x01, 0x26)) - {0x06}  # 0x06 = FONT5 glyph lead
FORMAT_CODES = {0x41: "</>", 0x43: "<W>", 0xB1: "<B>", 0x52: "<FMT52>"}
CHARNAME_CODES = {
    0x30: "<TIDUS>", 0x31: "<YUNA>", 0x32: "<AURON>", 0x33: "<KIMAHRI>",
    0x34: "<WAKKA>", 0x35: "<LULU>", 0x36: "<RIKKU>", 0x37: "<SEYMOUR>",
    0x38: "<VALEFOR>", 0x39: "<IFRIT>", 0x3A: "<IXION>", 0x3B: "<SHIVA>",
    0x3C: "<BAHAMUT>", 0x3D: "<ANIMA>", 0x3E: "<YOJIMBO>", 0x3F: "<CINDY>",
    0x40: "<SANDY>", 0x41: "<MINDY>",
}
# Editor glyph banks (fallback token form when the SJIS-table index is OOR).
GLYPH_BANKS = [  # (leadLow, leadHigh, bias, prefix) — idx = 208*L + N + bias
    (0x2C, 0x2F, -8992, "FONT0"), (0x2A, 0x2B, -8784, "FTCX"),
    (0x28, 0x29, -8368, "FONT2"), (0x26, 0x27, -7952, "FONT3"),
    (0x06, 0x06, -1296, "FONT5"),
]
GLYPH_LEADS = set([0x06]) | set(range(0x26, 0x30))
SJISTBL_GLYPH_BIAS = -8992  # idx into ffxsjistbl char list for ANY 0x26..0x2F pair


def load_sjistbl(path):
    """ffx_encoding/ffxsjistbl_*.bin -> list[str]: char at index i = glyph i."""
    return list(pathlib.Path(path).read_bytes().decode("utf-8"))


def load_sjistbl_u16(path):
    """menu/ffxsjistbl.bin (PS2 legacy) -> list[str] via cp932 (best effort)."""
    b = pathlib.Path(path).read_bytes()
    out = []
    for i in range(0, len(b) - 1, 2):
        v = b[i] << 8 | b[i + 1]
        try:
            out.append(bytes([b[i], b[i + 1]]).decode("cp932"))
        except UnicodeDecodeError:
            out.append(f"<SJIS:{v:04X}>")
    return out


def builtin_table(name):
    """Small built-in US/JP decoder (subset) used when no table file is given."""
    tbl = {}
    if name.lower().startswith("us"):
        seq = ("0123456789 !\u201D#$%&\u2019()*+,-./:;<=>?"
               "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`\u2018"
               "abcdefghijklmnopqrstuvwxyz")
        for i, ch in enumerate(seq):
            tbl[i] = ch
    return tbl


def decode_script(script, table, lossless=True):
    """Decode one NUL-stripped script blob -> display string.

    table = list[str] glyph table (index = byte-0x30 / glyph idx)."""
    out = []
    i = 0
    while i < len(script):
        b = script[i]
        if b == C_NULL:
            out.append("<NULL>" if lossless else "")
        elif b == C_NEW_LINE:
            out.append("\n")
        elif b in (C_FORMAT, C_CHAR_NAME):
            p = script[i + 1] if i + 1 < len(script) else 0
            i += 1
            if b == C_FORMAT:
                out.append(FORMAT_CODES.get(p, f"<C10:{p}>"))
            else:
                out.append(CHARNAME_CODES.get(p, f"<C19:{p}>"))
        elif b in GLYPH_LEADS:
            if i + 1 < len(script) and script[i + 1] >= 0x30:
                n = script[i + 1]
                i += 1
                idx = 208 * b + n + SJISTBL_GLYPH_BIAS
                if 0 <= idx < len(table):
                    out.append(table[idx])
                else:
                    for lo, hi, bias, pref in GLYPH_BANKS:
                        if lo <= b <= hi:
                            out.append(f"<{pref}:{208 * b + n + bias}>")
                            break
            else:
                out.append(f"<GLYPHLEAD:{b:02X}>")
        elif b in CONTROL_CODES:
            out.append(f"<C{b}>")
        elif b >= 0x30:
            idx = b - 0x30
            if idx < len(table):
                out.append(table[idx])
            else:
                out.append(f"<MISS:{b}>")
        else:
            out.append(f"<C{b}>")
        i += 1
    return "".join(out)


def read_cstr(b, off):
    if off < 0 or off >= len(b):
        return b""
    end = b.find(b"\x00", off)
    if end < 0:
        end = len(b)
    return b[off:end]


def u16(b, o):
    return b[o] | (b[o + 1] << 8) if 0 <= o + 1 < len(b) else 0


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0] if 0 <= o + 3 < len(b) else 0


# ── Format parsers ──────────────────────────────────────────────────

def parse_excel(b, table, name=""):
    """Kernel *_txt.bin (and other Excel-header tables with string pools)."""
    if len(b) < 0x14:
        return {"error": "too small for 0x14 header"}
    magic, z = u32(b, 0), u32(b, 4)
    min_i, max_i = u16(b, 8), u16(b, 0x0A)
    elen, dlen, hsize = u16(b, 0x0C), u16(b, 0x0E), u32(b, 0x10)
    rows = max_i - min_i + 1
    res = {"format": "excel", "magic": magic, "zero": z, "minIndex": min_i,
           "maxIndex": max_i, "entryLength": elen, "dataBlockLength": dlen,
           "headerSize": hsize, "rows": rows, "fileSize": len(b),
           "poolOffset": 0x14 + dlen, "poolLength": len(b) - 0x14 - dlen,
           "warnings": [], "entries": []}
    if magic != 1 or z != 0 or hsize != 0x14:
        res["warnings"].append(f"nonstandard header magic={magic} zero={z} hsize={hsize:#x}")
    if rows <= 0 or elen <= 0 or 0x14 + dlen > len(b):
        res["warnings"].append("invalid dims")
        return res
    pad = dlen - rows * elen
    res["entryTablePadding"] = pad
    if pad < 0:
        res["warnings"].append("entry table exceeds data block")
    pool = bytes(b[0x14 + dlen:])
    n_decode = 0
    for i in range(rows):
        eoff = 0x14 + i * elen
        ent = {"index": min_i + i, "raw": b[eoff:eoff + elen].hex()}
        if elen == 0x08:  # btl_txt: 4 x u16 word offsets into pool
            words = []
            for w in range(4):
                off = u16(b, eoff + w * 2)
                sc = read_cstr(pool, off)
                words.append({"off": off, "text": decode_script(sc, table)})
                n_decode += 1
            ent["words"] = words
        elif elen == 0x10:  # name/desc: 4 x (u16 offset, u16 key)
            fields = []
            for w in range(4):
                off, key = u16(b, eoff + w * 4), u16(b, eoff + w * 4 + 2)
                sc = read_cstr(pool, off)
                fields.append({"off": off, "key": key,
                               "text": decode_script(sc, table)})
                n_decode += 1
            ent["fields"] = fields
        else:
            ent["lanes"] = [u16(b, eoff + w * 2) for w in range(elen // 2)]
        res["entries"].append(ent)
    res["decodedStrings"] = n_decode
    return res


def parse_field8(b, table, name=""):
    """8-byte field-string table (TextTable_File): u16@0 = header len %8."""
    if len(b) < 2:
        return {"error": "too small"}
    hlen = u16(b, 0)
    res = {"format": "field8", "headerLength": hlen, "fileSize": len(b),
           "warnings": [], "entries": []}
    if hlen <= 0 or hlen % 8 or hlen > len(b):
        res["warnings"].append(f"bad header length {hlen:#x}")
        return res
    count = hlen // 8
    res["entryCount"] = count
    for i in range(count):
        eoff = i * 8
        r_off, r_fl, r_ch = u16(b, eoff), b[eoff + 2], b[eoff + 3]
        s_off, s_fl, s_ch = u16(b, eoff + 4), b[eoff + 6], b[eoff + 7]
        ent = {"index": i,
               "regular": {"off": r_off, "flags": r_fl, "choices": r_ch,
                           "text": decode_script(read_cstr(b, r_off), table)},
               "simplified": {"off": s_off, "flags": s_fl, "choices": s_ch,
                              "text": decode_script(read_cstr(b, s_off), table)}}
        for tag, off in (("regular", r_off), ("simplified", s_off)):
            if off and (off < hlen or off >= len(b)):
                res["warnings"].append(f"entry {i} {tag} off {off:#x} OOB")
        res["entries"].append(ent)
    return res


def parse_ptr4(b, table, name=""):
    """4-byte pointer-script table (PointerScriptTable_File): u32@0 = hdr len %4."""
    if len(b) < 0x10:
        return {"error": "too small"}
    hlen = u32(b, 0)
    res = {"format": "ptr4", "headerLength": hlen, "fileSize": len(b),
           "warnings": [], "entries": []}
    if hlen <= 0 or hlen % 4 or hlen > len(b):
        res["warnings"].append(f"bad header length {hlen:#x}")
        return res
    count = hlen // 4
    res["slotCount"] = count
    for i in range(count):
        off = u32(b, i * 4)
        ent = {"index": i, "off": off, "text": ""}
        if off == 0:
            ent["empty"] = True
        else:
            if off < hlen or off >= len(b):
                res["warnings"].append(f"slot {i} off {off:#x} OOB")
            ent["text"] = decode_script(read_cstr(b, off), table)
        res["entries"].append(ent)
    return res


def parse_dcp(b, table, name=""):
    """macrodic.dcp: u32 LE chunk-offset directory @0 (stop at 0xFFFFFFFF),
    each chunk: u16 headerLen -> count=headerLen/4 x (u16 reg, u16 simpl) +
    NUL-terminated pool inside the chunk."""
    offs = []
    for i in range(17):
        v = u32(b, i * 4)
        if v == 0xFFFFFFFF:
            break
        offs.append(v)
    res = {"format": "dcp", "directorySlots": len(offs), "fileSize": len(b),
           "warnings": [], "chunks": []}
    chunk_count = max(0, len(offs) - 1)  # last directory slot is an end sentinel
    for ci, off in enumerate(offs[:-1]):
        if off == 0:
            res["chunks"].append({"index": ci, "present": False})
            continue
        nxt = next((o for o in offs[ci + 1:] if o >= off), len(b))
        if off >= len(b):
            res["warnings"].append(f"chunk {ci} off {off:#x} OOB")
            continue
        chunk = b[off:min(nxt, len(b))]
        hlen = u16(chunk, 0)
        cnt = hlen // 4
        entries = []
        for i in range(cnt):
            ro, so = u16(chunk, i * 4), u16(chunk, i * 4 + 2)
            entries.append({"i": i, "macro": ci * 0x100 + i,
                            "regOff": ro, "simOff": so,
                            "reg": decode_script(read_cstr(chunk, ro), table),
                            "sim": decode_script(read_cstr(chunk, so), table)})
        res["chunks"].append({"index": ci, "present": True, "offset": off,
                              "length": len(chunk), "headerLen": hlen,
                              "entries": entries})
    return res


def parse_albhed(b, table, name=""):
    """albheddic.bin: flat 4B records [src u8, mapped u8, group u16 LE],
    trailing all-zero padding rows."""
    res = {"format": "albhed", "fileSize": len(b), "warnings": [], "entries": []}
    if len(b) % 4:
        res["warnings"].append("size %4 != 0")
    tbl = {i: c for i, c in enumerate(table)}
    def ch(code):
        idx = code - 0x30
        return tbl.get(idx, f"<{code:02X}>")
    pad = False
    for i in range(len(b) // 4):
        s, m, g = b[i * 4], b[i * 4 + 1], u16(b, i * 4 + 2)
        if s == 0 and m == 0 and g == 0:
            pad = True
            res["entries"].append({"index": i, "padding": True})
            continue
        if pad:
            res["warnings"].append(f"non-padding row {i} after padding began")
        res["entries"].append({"index": i, "src": s, "mapped": m, "group": g,
                               "srcChar": ch(s), "mappedChar": ch(m)})
    res["active"] = sum(1 for e in res["entries"] if not e.get("padding"))
    return res


def parse_albhedcjk(b, table, name=""):
    """battle/kernel/albhed.bin (new_krpc/new_chpc): 10 x u32 offset pairs
    (X,X duplicated) + blob of 10 NUL-terminated CJK strings."""
    res = {"format": "albhedcjk", "fileSize": len(b), "warnings": [], "entries": []}
    for i in range(10):
        a, c = u32(b, i * 8), u32(b, i * 8 + 4)
        if a != c:
            res["warnings"].append(f"pair {i} not duplicated ({a:#x}/{c:#x})")
        sc = read_cstr(b, a)
        res["entries"].append({"index": i, "off": a, "raw": sc.hex(),
                               "text": decode_script(sc, table)})
    return res


def parse_spcodedic(b, table, name=""):
    """menu/spcodedic.bin — 16B fixed: 4 x u32 words (jppc/uspc identical:
    08 00 08 00 | 0a 00 0a 00 | 4a 00 13 30 | 00 00 00 00). Likely a
    special-control-code dictionary; semantics UNKNOWN (audit 2026-09-16)."""
    words = [u32(b, i * 4) for i in range(len(b) // 4)]
    return {"format": "spcodedic", "fileSize": len(b), "words": words,
            "warnings": [] if len(b) == 16 else ["nonstandard size"],
            "text": " ".join(f"{w:08X}" for w in words)}


def parse_sjistbl(b, table, name=""):
    s = b.decode("utf-8")
    return {"format": "sjistbl", "bytes": len(b), "chars": len(s),
            "warnings": [], "text": s}


def parse_sjistbl16(b, table, name=""):
    out = []
    for i in range(0, len(b) - 1, 2):
        v = b[i] << 8 | b[i + 1]
        try:
            out.append(bytes([b[i], b[i + 1]]).decode("cp932"))
        except UnicodeDecodeError:
            out.append(f"<SJIS:{v:04X}>")
    return {"format": "sjistbl16", "bytes": len(b), "entryCount": len(out),
            "warnings": [], "text": "".join(out)}


def parse_lockit(b, table, name=""):
    """FFX_LOC_KIT_PS3_*.BIN — PS3 trophy-name/desc glossary (line records).

    Two PROVEN variants (2026-09-16, Jarvis-FMT):
      * Latin builds (us/de/fr/it/sp): every byte is Caesar +15 of ASCII
        plaintext (decode = byte - 15). Separators: cipher 0x0D 0x0A ->
        plain 0xFE 0xFB = record split; plain 0x39 ('9') = name|desc split;
        '+' is the space substitute. Verified on 5 PS3Data + 5 HD copies.
      * CJK builds (jp/kr/ch, HD repack only): NO cipher — raw bytes are
        already FFX font encoding, records separated by real 0x0D 0x0A;
        decode via the locale ffxsjistbl_* table. Verified jp/kr/ch.
    Detection: apply -15; if result is mostly printable ASCII -> Latin
    ciphered variant, else treat raw file as FFX-encoded CJK variant.
    """
    dec = bytes((x - 15) & 0xFF for x in b)
    ascii_frac = sum(1 for x in dec if 0x20 <= x < 0x7F) / max(1, len(dec))
    latin = ascii_frac > 0.7
    if latin:
        lines = [ln for ln in dec.split(b"\xfe\xfb") if ln]
        entries = [{"index": i,
                    "text": " | ".join(f.decode("latin1", "replace")
                                      for f in ln.split(b"9") if f)}
                   for i, ln in enumerate(lines)]
        variant = "caesar+15 ASCII"
    else:
        lines = [ln for ln in b.split(b"\x0d\x0a") if ln]
        entries = [{"index": i,
                    "text": decode_script(bytes(ln), table)}
                   for i, ln in enumerate(lines)]
        variant = "raw FFX-encoded (CJK)"
    return {"format": "lockit", "fileSize": len(b), "recordCount": len(entries),
            "cipher": variant, "warnings": [], "entries": entries}


def detect_format(b, name):
    n = pathlib.Path(name).name.lower()
    if n == "albheddic.bin":
        return "albhed"
    if n == "spcodedic.bin":
        return "spcodedic"
    if n == "albhed.bin":
        return "albhedcjk"
    if n.endswith(".dcp"):
        return "dcp"
    if n == "ffxsjistbl.bin":
        return "sjistbl16"
    if n.startswith("ffxsjistbl_") or n.startswith("ffx2sjistbl_"):
        return "sjistbl"
    if n.startswith("ffx_loc_kit"):
        return "lockit"
    # Filename dispatch mirrors the editor (StringExplorer_DataModel): the script
    # tables are the 4-byte pointer family even though u16@0 is also %8==0.
    if n in ("menu_script.bin", "battle_script.bin", "system_script.bin"):
        return "ptr4"
    if len(b) >= 0x14 and u32(b, 0) == 1 and u32(b, 4) == 0 and u32(b, 0x10) == 0x14:
        return "excel"
    # ptr4 signature: u32@0 = header length (%4); slots are u32 offsets that are
    # either 0 (empty) or point into the pool at >= hlen. Check first 4 slots.
    if len(b) >= 0x10:
        hlen = u32(b, 0)
        if hlen % 4 == 0 and 4 <= hlen <= len(b) and hlen >= 8:
            slots_ok = all(
                u32(b, i * 4) == 0 or hlen <= u32(b, i * 4) < len(b)
                for i in range(1, min(4, hlen // 4)))
            if slots_ok:
                return "ptr4"
    if len(b) >= 2 and u16(b, 0) % 8 == 0 and 8 <= u16(b, 0) <= len(b):
        return "field8"
    return "unknown"


PARSERS = {"excel": parse_excel, "field8": parse_field8, "ptr4": parse_ptr4,
           "dcp": parse_dcp, "albhed": parse_albhed, "albhedcjk": parse_albhedcjk,
           "sjistbl": parse_sjistbl, "sjistbl16": parse_sjistbl16,
           "lockit": parse_lockit, "spcodedic": parse_spcodedic}


def dump_text(res):
    """Render a parse result to a readable text dump."""
    out = []
    hdr = {k: v for k, v in res.items()
           if k not in ("entries", "chunks", "text", "warnings")}
    out.append("HEADER " + " ".join(f"{k}={v!r}" for k, v in hdr.items()))
    for w in res.get("warnings", []):
        out.append(f"  WARNING {w}")
    if "text" in res:
        out.append(res["text"])
    for ent in res.get("entries", []):
        if "words" in ent:
            ws = " | ".join(f"w{w['off']:04X}:{w['text']}" for w in ent["words"])
            out.append(f"[{ent['index']:3}] {ws}")
        elif "fields" in ent:
            fs = " | ".join(f"o{f['off']:04X}/k{f['key']:04X}:{f['text']}"
                            for f in ent["fields"])
            out.append(f"[{ent['index']:3}] {fs}")
        elif "regular" in ent:
            out.append(f"[{ent['index']:3}] R@{ent['regular']['off']:04X}"
                       f"(f{ent['regular']['flags']:02X} c{ent['regular']['choices']:02X}) "
                       f"{ent['regular']['text']!r}  S@{ent['simplified']['off']:04X} "
                       f"{ent['simplified']['text']!r}")
        elif "src" in ent:
            out.append(f"[{ent['index']:3}] {ent['srcChar']} ({ent['src']:02X}) -> "
                       f"{ent['mappedChar']} ({ent['mapped']:02X}) grp={ent['group']}")
        elif "raw" in ent:
            out.append(f"[{ent['index']:3}] @{ent['off']:04X} {ent['text']!r} ({ent['raw']})")
        elif "off" in ent:
            out.append(f"[{ent['index']:3}] @{ent['off']:04X} {ent.get('text','')!r}")
        elif "text" in ent:
            out.append(f"[{ent['index']:3}] {ent['text']}")
        elif "lanes" in ent:
            out.append(f"[{ent['index']:3}] lanes={ent['lanes']}")
        elif ent.get("padding"):
            out.append(f"[{ent['index']:3}] (padding)")
    for ch in res.get("chunks", []):
        if not ch.get("present"):
            out.append(f"chunk {ch['index']}: absent")
            continue
        out.append(f"chunk {ch['index']} @{ch['offset']:X} len={ch['length']:#x} "
                   f"entries={len(ch['entries'])}")
        for e in ch["entries"]:
            out.append(f"    [{e['i']:3}] macro {e['macro']:04X} "
                       f"R@{e['regOff']:04X} {e['reg']!r}  S@{e['simOff']:04X} {e['sim']!r}")
    return "\n".join(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file", nargs="?")
    ap.add_argument("--table", help="ffxsjistbl_*.bin (UTF-8) or menu ffxsjistbl.bin (u16)")
    ap.add_argument("--format", choices=list(PARSERS) + ["auto"], default="auto")
    ap.add_argument("--batch", help="walk dir, dump every recognized text file")
    ap.add_argument("-o", "--outdir", help="batch output dir")
    args = ap.parse_args()

    if args.batch:
        root = pathlib.Path(args.batch)
        outdir = pathlib.Path(args.outdir or ".")
        outdir.mkdir(parents=True, exist_ok=True)
        tbl_cache = {}
        report = []
        for p in sorted(root.rglob("*")):
            if not p.is_file():
                continue
            n = p.name.lower()
            want = (n.endswith("_txt.bin") or n.endswith("_txt2.bin") or n in
                    ("albheddic.bin", "albhed.bin", "macrodic.dcp",
                     "menu_script.bin", "battle_script.bin", "system_script.bin",
                     "ffxsjistbl.bin", "spcodedic.bin") or
                    n.startswith("ffxsjistbl_") or n.startswith("ffx2sjistbl_") or
                    n.startswith("ffx_loc_kit"))
            if not want:
                continue
            b = p.read_bytes()
            fmt = args.format if args.format != "auto" else detect_format(b, p.name)
            if fmt == "unknown":
                report.append((str(p), "UNKNOWN", 0))
                continue
            # pick table: nearest locale heuristic
            tbl_name = "us"
            parts = [x.lower() for x in p.parts]
            for cand in ("jp", "kr", "cn", "ch", "us"):
                if any(cand in x for x in parts):
                    tbl_name = cand
                    break
            if "jppc" in parts or "inpc" in parts:
                tbl_name = "jp"
            if args.table:
                tbl_path = pathlib.Path(args.table)
            else:
                tbl_path = (pathlib.Path(
                    "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/ffx_encoding")
                    / f"ffxsjistbl_{tbl_name}.bin")
            key = str(tbl_path)
            if key not in tbl_cache:
                try:
                    tbl_cache[key] = (load_sjistbl_u16(tbl_path)
                                      if tbl_path.name == "ffxsjistbl.bin"
                                      else load_sjistbl(tbl_path))
                except Exception as e:
                    tbl_cache[key] = []
                    print(f"WARN: table {tbl_path}: {e}", file=sys.stderr)
            table = tbl_cache[key]
            try:
                res = PARSERS[fmt](b, table, p.name)
            except Exception as e:
                report.append((str(p), fmt, f"PARSE-FAIL {e}"))
                continue
            rel = p.relative_to(root)
            out = outdir / (str(rel).replace("/", "__") + ".dump.txt")
            out.write_text(dump_text(res), encoding="utf-8")
            nstr = res.get("decodedStrings",
                           sum(len(c.get("entries", [])) for c in res.get("chunks", [])))
            report.append((str(p), fmt, nstr))
        for r in report:
            print("\t".join(str(x) for x in r))
        return

    if not args.file:
        ap.error("need a file or --batch")
    b = pathlib.Path(args.file).read_bytes()
    fmt = args.format if args.format != "auto" else detect_format(b, args.file)
    if fmt == "unknown":
        print("could not detect format", file=sys.stderr)
        sys.exit(2)
    if args.table:
        tp = pathlib.Path(args.table)
        table = load_sjistbl_u16(tp) if tp.name == "ffxsjistbl.bin" else load_sjistbl(tp)
    else:
        table = builtin_table("us")
    res = PARSERS[fmt](b, table, args.file)
    print(dump_text(res))


if __name__ == "__main__":
    main()
