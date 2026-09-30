#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# ── atel_source_hunt.py — Jarvis-ATEL-SOURCE (2026-09-18) ──
#
# WHY: B-LETTER (docs/reverse/FFX_EVENTVM_BPREFIX_2026-09-18.md) proved the B-op
# mechanism (admission-gate veto via ctrl[+0x60]) but left the letter expansion
# PARTIAL — "B" = Branching? Buffered? Blocking? Bind? The only evidence class
# that can promote it to PROVEN is a SOURCE-LEVEL ATEL artifact: an authored
# string/comment/macro naming the expansion. The ATEL toolchain was internal
# Square, so the hunt covers *derivative* residue:
#   1. shipped binaries (PC exe / PS2 SLPS / PS3 EBOOT / magic_*.dll / IRX):
#      opcode-name tables, assert strings, debug prints, SJIS diagnostics;
#   2. shipped source artifacts (.src/.ath/.inc/.h/.lst/.txt) in game data;
#   3. IDB anonymous strings (handled separately via ida_mcp_client.py).
#
# The PC exe embeds an ATEL source preprocessor (AtelLoadSourceDataMain +
# ".src"/".bdb" extensions + Shift_JIS macro-error diagnostics ~0x756e1b in
# FFX.exe) — so SJIS-aware string extraction is required, not optional.
#
# Usage: python3 atel_source_hunt.py [--bin <path>] [--srcroot <dir>] [--out <csv>]
# No third-party deps. ASCII + CP932(SJIS) + UTF-8 aware.

import os
import re
import sys
import csv
import argparse

# ── Search terms ─────────────────────────────────────────────────────────
# Grouped by hypothesis class. ASCII terms are matched raw; JP terms are
# encoded per-target (SJIS for binaries, UTF-8 for .src corpus which is UTF-8).
ASCII_TERMS = [
    # opcode mnemonics (name-table residue)
    'BREQ', 'BFREQ', 'BTREQ', 'BREQSW', 'BFREQSW', 'BTREQSW',
    'BREQEW', 'BFREQEW', 'BTREQEW', 'FREQ', 'TREQ', 'PREQ',
    'REQSW', 'REQEW', 'REQWAIT', 'REQCHG', 'ACTREQ', 'REQF',
    # expansion candidates (word-level, case-insensitive)
    'branch', 'buffer', 'block', 'bind', 'broadcast', 'barrier',
    'batch', 'battle', 'gate', 'veto', 'admit', 'allow', 'deny',
    'predicate', 'conditional',
    # ATEL toolchain residue
    'atel', '.src', '.bdb', '.ath', '.ebp', 'funcspace',
    'AtelLoadSourceData', 'opcode', 'mnemonic',
]
JP_TERMS = [
    '分岐', 'ブランチ', 'ブロック', 'バッファ', 'バインド', '放送', '同報',
    '要求', '送信', '条件', '許可', '拒否', '要求送信', 'リクエスト',
    '分岐要求', '条件付き', '保留', '予約', 'ゲート', '束縛', '結合',
    '受付', '受理', '発行', '指示',
]

MIN_ASCII = 4
MIN_SJIS_RUN = 6      # bytes; a real message is longer
JP_MIN_CHARS = 2      # require >=2 kanji/kana to call it a JP string


def extract_ascii_strings(data, minlen=MIN_ASCII):
    """Yield (offset, bytes) for NUL-bounded printable-ASCII runs."""
    for m in re.finditer(rb'[\x20-\x7e]{%d,}' % minlen, data):
        yield m.start(), m.group()


def _sjis_ok_pair(b0, b1):
    return ((0x81 <= b0 <= 0x9F) or (0xE0 <= b0 <= 0xEF)) and \
           (0x40 <= b1 <= 0xFC and b1 != 0x7F)


def extract_sjis_strings(data):
    """Yield (offset, decoded_str) for NUL-bounded runs that decode as clean
    CP932 text containing >=JP_MIN_CHARS kana/kanji. NUL-bounded requirement
    kills the false-positive noise that raw sliding-window scans produce."""
    out = []
    n = len(data)
    i = 0
    while i < n:
        # find a SJIS lead byte
        b = data[i]
        if not ((0x81 <= b <= 0x9F) or (0xE0 <= b <= 0xEF)):
            i += 1
            continue
        # grow a candidate run: ASCII-printable or valid SJIS pairs
        j = i
        buf = bytearray()
        jp_chars = 0
        clean = True
        while j < n:
            c = data[j]
            if 0x20 <= c <= 0x7E or c == 0x09:
                buf.append(c)
                j += 1
            elif _sjis_ok_pair(c, data[j + 1] if j + 1 < n else 0):
                buf += data[j:j + 2]
                j += 2
                jp_chars += 1
            else:
                break
        # candidate must end at NUL (or EOF) and start right after a NUL —
        # real strings in .rodata are NUL-terminated
        end_ok = (j >= n) or (data[j] == 0)
        start_ok = (i == 0) or (data[i - 1] == 0) or (data[i - 1] < 0x20)
        if clean and end_ok and len(buf) >= MIN_SJIS_RUN and jp_chars >= JP_MIN_CHARS:
            try:
                txt = bytes(buf).decode('cp932')
                out.append((i, txt))
                i = j
                continue
            except UnicodeDecodeError:
                pass
        i += 1
    return out


def scan_binary(path, terms_ascii, terms_sjis):
    """Scan one binary; returns list of hit dicts."""
    rows = []
    try:
        data = open(path, 'rb').read()
    except OSError:
        return rows
    low = data.lower()
    for t in terms_ascii:
        needle = t.encode('ascii', 'ignore')
        if not needle:
            continue
        start = 0
        nl = needle.lower()
        while True:
            i = low.find(nl, start)
            if i < 0:
                break
            ctx = data[max(0, i - 40):i + len(needle) + 40]
            ctx = bytes(c if 0x20 <= c <= 0x7e else 0x2e for c in ctx)
            rows.append(dict(file=path, kind='bin-ascii', term=t,
                             offset=hex(i), text=ctx.decode('ascii', 'replace')))
            start = i + 1
            if sum(1 for r in rows if r['term'] == t and r['file'] == path) > 200:
                break  # cap spammy terms
    for t, needle in terms_sjis:
        start = 0
        while True:
            i = data.find(needle, start)
            if i < 0:
                break
            ctx = data[max(0, i - 40):i + len(needle) + 60]
            try:
                ctxs = ctx.decode('cp932', 'replace')
            except Exception:
                ctxs = repr(ctx)
            rows.append(dict(file=path, kind='bin-sjis', term=t,
                             offset=hex(i), text=ctxs[:160]))
            start = i + 1
    return rows


def scan_textfile(path, terms_ascii, terms_utf8):
    """Scan one text file (UTF-8/SJIS/auto). Returns hit rows with line no."""
    rows = []
    try:
        raw = open(path, 'rb').read()
    except OSError:
        return rows
    for enc in ('utf-8', 'cp932', 'latin-1'):
        try:
            text = raw.decode(enc)
            break
        except UnicodeDecodeError:
            text = None
    if text is None:
        return rows
    low = text.lower()
    for t in terms_ascii:
        idx = low.find(t.lower())
        if idx < 0:
            continue
        # count all occurrences but record up to 20
        cnt = 0
        pos = idx
        while pos >= 0 and cnt < 20:
            line = text.count('\n', 0, pos) + 1
            snippet = text[max(0, pos - 60):pos + 80].replace('\n', ' ').replace('\r', ' ')
            rows.append(dict(file=path, kind='src', term=t,
                             offset=f'L{line}', text=snippet.strip()))
            cnt += 1
            pos = low.find(t.lower(), pos + 1)
    for t in terms_utf8:
        pos = text.find(t)
        cnt = 0
        while pos >= 0 and cnt < 20:
            line = text.count('\n', 0, pos) + 1
            snippet = text[max(0, pos - 60):pos + 80].replace('\n', ' ').replace('\r', ' ')
            rows.append(dict(file=path, kind='src-jp', term=t,
                             offset=f'L{line}', text=snippet.strip()))
            cnt += 1
            pos = text.find(t, pos + 1)
    return rows


SRC_EXTS = ('.src', '.ath', '.inc', '.h', '.lst', '.txt', '.ath', '.ha',
            '.evs', '.atel', '.scr', '.mac', '.def', '.cdm')


def main():
    ap = argparse.ArgumentParser(description='Hunt source-level ATEL artifacts '
                                             'that expand the B-prefix of REQ-family opcodes.')
    ap.add_argument('--bin', action='append', default=[], help='binary file to scan (repeatable)')
    ap.add_argument('--binlist', default='', help='file listing binaries, one per line')
    ap.add_argument('--srcroot', action='append', default=[], help='dir of source artifacts (repeatable)')
    ap.add_argument('--out', default='', help='CSV output path')
    ap.add_argument('--terms', default='', help='extra comma-separated ASCII terms')
    args = ap.parse_args()

    terms_ascii = list(ASCII_TERMS)
    if args.terms:
        terms_ascii += [t for t in args.terms.split(',') if t]
    terms_sjis = [(t, t.encode('cp932')) for t in JP_TERMS]
    terms_utf8 = list(JP_TERMS)

    bins = list(args.bin)
    if args.binlist:
        with open(args.binlist) as f:
            bins += [l.strip() for l in f if l.strip()]

    rows = []
    for b in bins:
        rows += scan_binary(b, terms_ascii, terms_sjis)
    for root in args.srcroot:
        for r, _dirs, files in os.walk(root):
            for fn in files:
                if os.path.splitext(fn)[1].lower() in SRC_EXTS:
                    rows += scan_textfile(os.path.join(r, fn), terms_ascii, terms_utf8)

    if args.out:
        with open(args.out, 'w', newline='', encoding='utf-8') as f:
            w = csv.DictWriter(f, fieldnames=['file', 'kind', 'term', 'offset', 'text'])
            w.writeheader()
            w.writerows(rows)
        print(f'wrote {len(rows)} hits -> {args.out}')
    else:
        for r in rows:
            print(f"{r['kind']:9} {r['term']:12} {r['offset']:>10} {r['file']}: {r['text'][:100]}")
        print(f'{len(rows)} hits')


if __name__ == '__main__':
    main()
