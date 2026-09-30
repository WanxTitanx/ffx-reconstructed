#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# ── src_census.py — Jarvis-SRC-CENSUS (2026-09-18) ──
#
# WHY: ATEL-SOURCE (docs/reverse/FFX_ATEL_SOURCE_2026-09-18.md) located the
# biggest authored-ATEL dataset ever found — FFX-2 ships ~10,805 `.src` files
# (nvme extraction) + ~9,775 `.src` (PSARC HD) under
# `master/jppc/battle/`. These sources never name VM opcodes — they call
# high-level APIs (`btlSetStat`, `camSetPolar`, `btlReqMotion`…) declared in
# `funcspace N` blocks inside `.ath` headers, through a thick `#define`
# lowercase-alias layer (`setstat`→`btlSetStat`, `evtreq`→`btlEvtReq`) plus
# `#macro` libraries and compiler builtins (`wait`, `halt`, `ret`, `goto`).
#
# This tool inventories that corpus — the authored-side vocabulary map that
# any future decompiler must emit:
#   pass 1 (symbol tables, all .src/.ath/.inc/.h/.ha):
#       * `funcspace N` + typed decls   -> canonical API table (ns/index/funcId)
#       * `#define a b` / `#alias a b`   -> alias layer (a -> b, b may carry ())
#       * `#macro name(`                 -> macro definitions (name -> site)
#   pass 2 (per-.src census):
#       * calls: `name(` on code lines (comments/strings stripped, `#` lines
#         skipped so #define bodies are not counted as use-sites)
#       * bare uses: alias tokens used WITHOUT parens (zero-arg defines like
#         `#define motion_wait btlWaitMotion()` are statements, not calls)
#       * structure: `line <name>` workers, `*label` event labels, `name:`
#         labels, `local {}`, `author`, goto/switch/if counts, #include list
#       * REQ-family surface calls (name carries `Req`/`_req`/`req`)
#       * b-variant probe: any identifier matching `b…req` that is NOT the
#         `btl` battle prefix — the source-level counterpart of the BREQ hunt
#
# Usage:
#   python3 src_census.py \
#       --srcroot nvme="/mnt/nvme-samsung/FFX Extracted/FFX2" \
#       --srcroot psarc="/mnt/.../PSARC_EXTRACTED" \
#       --api-out docs/reverse/data/wave15/src_api_census.csv \
#       --files-out docs/reverse/data/wave15/src_file_stats.csv \
#       --json-out /tmp/src_census.json
#
# No third-party deps. UTF-8 first, cp932 fallback (same rule as ath_parser.py).
# MAINT: research-only (research_tools/Atel/). Read-only on the corpus —
# nothing under the game dirs is written.

import argparse
import csv
import hashlib
import json
import os
import re
import sys
from collections import defaultdict

# ── Grammar ──────────────────────────────────────────────────────────────
# Identifier: ASCII C ident, or any non-ASCII lead (Japanese macro/label
# names, incl. full-width ＊ tag constants and ＿ separators). \w under
# Unicode covers kanji/kana/full-width alnum but NOT ＿ (U+FF3F, category
# Pc) — without it, アビリティ＿ユウナ＿フレア() truncates to フレア().
# FIX 2026-09-18: added ＿ to lead/continuation classes after finding
# ~50 unresolved names that were really ＿-joined macro invocations.
# Same fix round 2: macro names also embed ・ (U+30FB), ＆ (U+FF06) and
# fullwidth （） pairs (e.g. ギップル・アカギ銃, スロット＆サイコロ,
# お祭り士（パイン）) — all inert in C-like exprs, safe as ident chars.
IDENT = r'[^\W\d][\w＊＿・＆（）]*|[＊＿][\w＊＿・＆（）]+'
CALL_RE = re.compile(r'(%s)\s*\(' % IDENT)
IDENT_RE = re.compile(r'[^\W\d][\w＊＿・＆（）]*|[＊＿][\w＊＿・＆（）]+')

FUNCSPACE_RE = re.compile(r'^\s*funcspace\s+([0-9A-Fa-fx]+)\s*$')
FUNCDECL_RE = re.compile(
    r'^\s*(?:int|float|void|char|short|long|unsigned)\s+(%s)\s*\(' % IDENT)
DEFINE_RE = re.compile(r'^\s*#\s*define\s+(\S+)\s*(.*)$')
ALIAS_RE = re.compile(r'^\s*#\s*alias\s+(\S+)\s+(\S+)')
MACRO_RE = re.compile(r'^\s*#\s*macro\s+(\S+)')
INCLUDE_RE = re.compile(r'^\s*#\s*include\s*[<"]([^>"]+)')
AUTHOR_RE = re.compile(r'^\s*author\s+(.+?)\s*$')
LINE_RE = re.compile(r'^\s*line\s+([^\s{]+)')
LOCAL_RE = re.compile(r'^\s*local\b')
STARLABEL_RE = re.compile(r'^\s*\*([^\s(:]+)')
COLONLABEL_RE = re.compile(r'^\s*([^\W\d][\w]*)\s*:')
COMMENT_RE = re.compile(r'//')
STRING_RE = re.compile(r'"[^"\n]*"')
BLOCKC_RE = re.compile(r'/\*.*?\*/', re.S)

KEYWORDS = {
    'if', 'else', 'switch', 'case', 'default', 'while', 'for', 'do',
    'return', 'ret', 'goto', 'break', 'continue', 'sizeof',
    'int', 'float', 'char', 'short', 'long', 'void', 'unsigned', 'signed',
    'const', 'static', 'struct', 'union', 'enum', 'typedef', 'extern',
    'line', 'local', 'author', 'include', 'funcspace', 'define', 'macro',
    'endm', 'ifdef', 'ifndef', 'endif', 'pragma', 'true', 'false',
}
# Tokens after which the next identifier is a NAME not a use (var decl,
# label target, worker name, case constant).
NAMECTX = {
    'int', 'float', 'char', 'short', 'long', 'void', 'unsigned', 'struct',
    'case', 'goto', 'line', 'author', 'local', 'label', 'default',
}
# Language builtins — emitted as VM ops directly, never funcspace decls.
BUILTINS = {'wait', 'halt', 'sleep', 'exit', 'ret', 'goto', 'break',
            'continue', 'return', 'yield'}

# REQ-family surface test: `Req` camelCase, `_req`/`req` token, `request`.
# Deliberately does NOT match plain 'req' substring (mf_preque false-hit
# from the ATEL-SOURCE hunt) nor 'reg'/'recom'/'reverbe'.
REQ_RE = re.compile(r'Req|(?:^|_)req(?:_uest|_)?$|_req_|^req_|request',
                    re.IGNORECASE)

# b-variant probe: identifier whose name is `b…req…` but the `b` is NOT the
# `btl`/`btls`/`btlmes` battle prefix. Catches breq/bfreq/btreq/bevtreq/
# b_evtreq/bMotionReq if any exist (hunt says none — we verify per-name).
BVAR_RE = re.compile(r'(?i)(?:^|[_\W])b(?!tl)[a-z0-9_]*req[a-z0-9_]*')
BVAR_SUBSTR = re.compile(r'(?i)breq|bfreq|btreq|bevtreq')

SRC_EXTS = ('.src',)
SYM_EXTS = ('.src', '.ath', '.inc', '.h', '.ha', '.def')


def decode_file(path):
    """Return (text, encoding, n_replacement_chars). UTF-8 first, cp932
    fallback — the JP toolchain wrote Shift_JIS but the mounted extraction
    stores most files converted to UTF-8 (ath_parser.py convention)."""
    raw = open(path, 'rb').read()
    try:
        return raw.decode('utf-8'), 'utf-8', 0
    except UnicodeDecodeError:
        text = raw.decode('cp932', errors='replace')
        return text, 'cp932', text.count('�')


def strip_comments_strings(text):
    """Remove /* */ blocks, // line comments and "..." strings. Keeps line
    structure (newlines preserved inside removed spans). Returns
    (code, n_comment_chars, n_strings)."""
    n_str = len(STRING_RE.findall(text))
    code = BLOCKC_RE.sub(lambda m: '\n' * m.group().count('\n'), text)
    n_com = 0
    out = []
    for ln in code.split('\n'):
        i = ln.find('//')
        if i >= 0:
            n_com += len(ln) - i
            ln = ln[:i]
        out.append(ln)
    code = '\n'.join(out)
    code = STRING_RE.sub('""', code)
    return code, n_com, n_str


class SymbolTables:
    """Corpus-wide symbol resolution: canonical funcspace decls + alias
    layer + macro defs + data defines."""

    def __init__(self):
        self.api = {}          # lower -> {name, ns, idx, file, line}
        self.alias = {}        # lower -> {name, target, target_call, file}
        self.macros = {}       # lower -> {name, file, line}
        self.data_defines = set()   # lower — #define name <number>
        self.funcspace_files = defaultdict(list)  # ns -> [files]

    def resolve(self, name):
        """surface name -> (canonical_name or None). Follows alias chains
        (max 8 hops); canonical hit = name in api table."""
        seen = set()
        cur = name.lower()
        for _ in range(8):
            if cur in self.api:
                return self.api[cur]['name']
            if cur in seen or cur not in self.alias:
                return None
            seen.add(cur)
            cur = self.alias[cur]['target'].lower()
        return self.api.get(cur, {}).get('name') if cur in self.api else None

    def is_func_alias(self, name):
        """True when `name` resolves (through defines) to a declared API —
        used for bare-token counting."""
        return self.resolve(name) is not None


def scan_symbols(path, rel, tables):
    """Pass 1: pull funcspace decls, defines, aliases, macros from one file."""
    try:
        text, _enc, _rep = decode_file(path)
    except OSError:
        return
    code, _nc, _ns = strip_comments_strings(text)
    cur_ns = 0
    idx = 0
    for i, raw in enumerate(code.split('\n')):
        ln = raw.strip()
        if not ln:
            continue
        m = FUNCSPACE_RE.match(ln)
        if m:
            try:
                cur_ns = int(m.group(1), 0)
            except ValueError:
                cur_ns = 0
            idx = 0
            tables.funcspace_files[cur_ns].append(rel)
            continue
        m = FUNCDECL_RE.match(ln)
        if m and cur_ns:
            name = m.group(1)
            key = name.lower()
            if key not in tables.api:          # first decl wins
                tables.api[key] = {'name': name, 'ns': cur_ns, 'idx': idx,
                                   'file': rel, 'line': i + 1}
            idx += 1
            continue
        m = MACRO_RE.match(ln)
        if m:
            name = m.group(1).split('(')[0]
            tables.macros.setdefault(
                name.lower(), {'name': name, 'file': rel, 'line': i + 1})
            continue
        m = ALIAS_RE.match(ln)
        if m:
            name, target = m.group(1), m.group(2)
            tables.alias.setdefault(
                name.lower(),
                {'name': name, 'target': target.split('(')[0],
                 'target_call': '(' in target, 'file': rel})
            continue
        m = DEFINE_RE.match(ln)
        if m:
            name, value = m.group(1), m.group(2).strip()
            base = name.split('(')[0]          # #define NAME(...) -> NAME
            if not value:
                continue
            inner = value
            if inner.startswith('(') and inner.endswith(')'):
                inner = inner[1:-1].strip()
            try:
                int(inner, 0)
                tables.data_defines.add(base.lower())
                continue
            except ValueError:
                pass
            tgt = inner.split('(')[0].strip()
            if tgt and re.fullmatch(IDENT, tgt):
                tables.alias.setdefault(
                    base.lower(),
                    {'name': base, 'target': tgt,
                     'target_call': '(' in inner, 'file': rel})
            continue


def classify_family(surface, canonical, kind):
    """Coarse family bucket for grouping (mission: evtreq/camReq/btlReq*/
    motion/se/weather…). Checks surface + canonical forms."""
    names = ' '.join(x for x in (surface, canonical) if x).lower()
    if REQ_RE.search(surface) or (canonical and REQ_RE.search(canonical)):
        return 'req'
    if 'voice' in names:
        return 'voice'
    if re.search(r'\bse_|sound|_se\b', names) or 'seplay' in names:
        return 'se'
    if ('cam' in names or 'camera' in names or 'bindbtlcam' in names
            or re.search(r'\bref', names) or names.startswith('ref')):
        return 'camera'
    if ('mes' in names or 'print' in names or 'sysmes' in names):
        return 'message'
    if re.search(r'motion|move|dir|pos|homing|spline|dist|height|gravity|'
                 r'fly|scale|trans|fase|face|walk|jump|speed|leave|step',
                 names):
        return 'motion/move'
    if 'map' in names or 'scene' in names or 'weather' in names:
        return 'map/scene'
    if 'eff' in names or 'effect' in names or 'bind' in names:
        return 'effect'
    if 'stat' in names:
        return 'status'
    if 'com' in names or 'command' in names:
        return 'command'
    if 'mon' in names or 'monster' in names:
        return 'monster'
    if 'btl' in names or 'battle' in names or 'chr' in names:
        return 'battle'
    return kind


def categorize(rel):
    """Coarse corpus category from the path inside master/jppc/battle/."""
    p = rel.replace('\\', '/')
    base = p.rsplit('/', 1)[-1]
    low = p.lower()
    if '/header/' in low or low.startswith('header/'):
        return 'header'
    if '/mag/' in low:
        return 'magic'
    if '/mon/' in low:
        return 'monster'
    if '/mot/' in low:
        return 'motion'
    if '/btl/' in low or low.startswith('btl/'):
        if base.startswith('evt_'):
            return 'battle-event'
        if base.startswith('cam_'):
            return 'battle-camera'
        if base.startswith('scn_'):
            return 'battle-scene'
        if '/focus' in low or base.startswith('focus'):
            return 'battle-focus'
        if '/light' in low or base.startswith('light'):
            return 'battle-light'
        if 'system' in base:
            return 'battle-system'
        if 'zzzz' in low:
            return 'battle-test'
        return 'battle-other'
    return 'other'


def backup_flag(rel):
    low = rel.lower()
    for tag in ('backup', '/old', 'old_', 'yas_tmp', '$~', '_old', '/old/'):
        if tag in low:
            return 'backup'
    return ''


def scan_src(path, rel, corpus, tables):
    """Pass 2: per-file census. Returns (file_row, call_hits, bvar_hits)."""
    raw = open(path, 'rb').read()
    md5 = hashlib.md5(raw).hexdigest()
    try:
        text = raw.decode('utf-8')
        enc = 'utf-8'
        rep = 0
    except UnicodeDecodeError:
        text = raw.decode('cp932', errors='replace')
        enc = 'cp932'
        rep = text.count('�')
    code, n_com, n_str = strip_comments_strings(text)
    lines_raw = text.replace('\r\n', '\n').split('\n')
    lines = code.split('\n')

    row = {
        'corpus': corpus, 'relpath': rel, 'category': categorize(rel),
        'bytes': len(raw), 'encoding': enc, 'repl_chars': rep, 'md5': md5,
        'loc_total': len(lines), 'loc_code': 0, 'loc_comment': 0,
        'loc_blank': 0, 'n_strings': n_str,
        'workers': [], 'star_labels': [], 'colon_labels': [],
        'authors': [], 'includes': [], 'macro_defs': [],
        'n_local': 0, 'n_goto': 0, 'n_switch': 0, 'n_if': 0, 'n_while': 0,
        'n_for': 0, 'n_break': 0, 'n_ret': 0, 'n_case': 0,
        'n_define': 0, 'n_macro': 0, 'n_ifdef': 0, 'n_alias': 0,
        'calls': defaultdict(int),       # name -> count (with parens)
        'bare': defaultdict(int),        # name -> count (alias, no parens)
        'call_sites': defaultdict(list), # name -> [lineno] (cap 3)
    }

    for i, ln in enumerate(lines):
        raw_ln = lines_raw[i] if i < len(lines_raw) else ln
        stripped = ln.strip()
        if not stripped:
            # Raw had text but the code view is empty -> comment-only line
            # (// line, /* */ interior). Truly empty raw -> blank.
            if raw_ln.strip():
                row['loc_comment'] += 1
            else:
                row['loc_blank'] += 1
            continue
        row['loc_code'] += 1

        # ── preprocessor lines: feature flags only, never call sites ──
        if stripped.startswith('#'):
            if INCLUDE_RE.match(stripped):
                row['includes'].append(INCLUDE_RE.match(stripped).group(1))
            elif MACRO_RE.match(stripped):
                row['n_macro'] += 1
                row['macro_defs'].append(
                    MACRO_RE.match(stripped).group(1).split('(')[0])
            elif DEFINE_RE.match(stripped):
                row['n_define'] += 1
            elif ALIAS_RE.match(stripped):
                row['n_alias'] += 1
            elif re.match(r'#\s*(if|ifdef|ifndef|elif|else|endif)', stripped):
                row['n_ifdef'] += 1
            continue

        # ── structure markers ──
        m = LINE_RE.match(ln)
        if m:
            row['workers'].append(m.group(1))
        if LOCAL_RE.match(ln):
            row['n_local'] += 1
        m = STARLABEL_RE.match(ln)
        star_lbl = m.group(1) if m else None
        if m:
            row['star_labels'].append(star_lbl)
        m = COLONLABEL_RE.match(ln)
        colon_lbl = None
        if m and m.group(1) not in KEYWORDS and m.group(1) != 'case':
            colon_lbl = m.group(1)
            row['colon_labels'].append(colon_lbl)
        # author is matched on the RAW line — string-strip would reduce
        # `author "keisuke"` to `author ""` and lose the name.
        m = AUTHOR_RE.match(raw_ln)
        if m:
            row['authors'].append(m.group(1).strip('"').strip())

        for kw, key in (('goto', 'n_goto'), ('switch', 'n_switch'),
                        ('if', 'n_if'), ('while', 'n_while'),
                        ('for', 'n_for'), ('break', 'n_break'),
                        ('ret', 'n_ret'), ('case', 'n_case')):
            row[key] += len(re.findall(r'\b%s\b' % kw, ln))

        # ── call sites: name( on code lines ──
        called_spans = []
        for m in CALL_RE.finditer(ln):
            name = m.group(1)
            if name.lower() in KEYWORDS:
                continue
            called_spans.append((m.start(1), name))
            row['calls'][name] += 1
            if len(row['call_sites'][name]) < 3:
                row['call_sites'][name].append(i + 1)

        # ── bare-token uses (zero-arg aliases used without parens) ──
        toks = list(IDENT_RE.finditer(ln))
        prev_word = None
        for t in toks:
            tok = t.group(0)
            tlow = tok.lower()
            rest = ln[t.end():]
            is_call = rest.lstrip().startswith('(')
            skip = (
                tlow in KEYWORDS or tlow in NAMECTX or is_call or
                (prev_word in NAMECTX) or
                (prev_word is None and tok == star_lbl) or
                tok == colon_lbl)
            if not skip and tlow in tables.alias and \
                    tables.is_func_alias(tok):
                row['bare'][tok] += 1
            prev_word = tlow

    call_hits = []
    for name, cnt in row['calls'].items():
        call_hits.append((name, cnt, row['call_sites'][name], 'call'))
    for name, cnt in row['bare'].items():
        call_hits.append((name, cnt, [], 'bare'))

    # b-variant probe on every distinct surface identifier
    bvar_hits = []
    for name in list(row['calls']) + list(row['bare']):
        if BVAR_RE.search(name) or BVAR_SUBSTR.search(name):
            bvar_hits.append(name)

    return row, call_hits, bvar_hits


def collect(root, exts):
    out = []
    for dirpath, _dirs, files in os.walk(root):
        for fn in files:
            if os.path.splitext(fn)[1].lower() in exts:
                full = os.path.join(dirpath, fn)
                out.append((os.path.relpath(full, root)
                            .replace(os.sep, '/'), full))
    return sorted(out)


def main(argv=None):
    ap = argparse.ArgumentParser(
        description='Authored ATEL .src corpus census — API calls, '
                    'structure markers, REQ-family surface, b-variant probe.')
    ap.add_argument('--srcroot', action='append', default=[],
                    help='label=path corpus root (repeatable)')
    ap.add_argument('--api-out', default='',
                    help='CSV: per-API-name census')
    ap.add_argument('--files-out', default='',
                    help='CSV: per-file stats')
    ap.add_argument('--json-out', default='',
                    help='JSON summary dump')
    ap.add_argument('--top', type=int, default=40,
                    help='print top-N API names')
    args = ap.parse_args(argv)

    roots = []
    for spec in args.srcroot:
        if '=' in spec:
            label, path = spec.split('=', 1)
        else:
            label, path = os.path.basename(spec.rstrip('/')) or 'root', spec
        roots.append((label, path))
    if not roots:
        ap.error('at least one --srcroot required')

    tables = SymbolTables()
    # ── pass 1: symbol tables over ALL source-ish files ──
    sym_files = []
    for label, root in roots:
        sym_files += [(label, rel, full)
                      for rel, full in collect(root, SYM_EXTS)]
    for label, rel, full in sym_files:
        scan_symbols(full, '%s:%s' % (label, rel), tables)
    # resolve which aliases are *function* aliases (target -> api)
    # (is_func_alias resolves lazily via resolve())

    # ── pass 2: per-.src census ──
    file_rows = []
    api = {}       # surface-lower -> aggregate
    bvar = defaultdict(list)   # name -> sites
    seen_md5 = {}              # md5 -> first relpath
    n_src = 0
    tot_bytes = 0
    tot_loc = 0
    tot_code = 0
    cat_stats = defaultdict(lambda: [0, 0, 0])  # cat -> [files, loc, code]
    corpus_stats = defaultdict(int)
    enc_stats = defaultdict(int)

    for label, root in roots:
        for rel, full in collect(root, SRC_EXTS):
            n_src += 1
            try:
                row, hits, bv = scan_src(full, rel, label, tables)
            except OSError:
                continue
            tot_bytes += row['bytes']
            tot_loc += row['loc_total']
            tot_code += row['loc_code']
            c = row['category']
            cat_stats[c][0] += 1
            cat_stats[c][1] += row['loc_total']
            cat_stats[c][2] += row['loc_code']
            corpus_stats[label] += 1
            enc_stats[row['encoding']] += 1
            dup_of = seen_md5.get(row['md5'], '')
            seen_md5.setdefault(row['md5'], '%s:%s' % (label, rel))
            row['dup_of'] = dup_of
            row['flags'] = backup_flag(rel)
            if row['loc_code'] == 0:
                row['flags'] = (row['flags'] + ';empty').strip(';')
            file_rows.append(row)
            for name, cnt, sites, kind in hits:
                key = name.lower()
                e = api.setdefault(key, {
                    'name': name, 'calls': 0, 'bare': 0, 'files': set(),
                    'sites': []})
                if kind == 'call':
                    e['calls'] += cnt
                else:
                    e['bare'] += cnt
                e['files'].add('%s:%s' % (label, rel))
                for ln in sites:
                    if len(e['sites']) < 3:
                        e['sites'].append('%s:%s:L%d' % (label, rel, ln))
            for name in bv:
                if len(bvar[name]) < 5:
                    bvar[name].append('%s:%s' % (label, rel))

    # md5 fixup — scan_src returns rows w/o md5; recompute for dup map
    # (done inline above via row['md5'] when present)

    # ── API census rows ──
    api_rows = []
    for key, e in sorted(api.items(),
                         key=lambda kv: -(kv[1]['calls'] + kv[1]['bare'])):
        surface = e['name']
        canon = tables.resolve(surface)
        info = tables.api.get((canon or '').lower(), {})
        if surface.lower() in tables.api:
            kind = 'api'
        elif canon:
            kind = 'alias'
        elif surface.lower() in tables.macros:
            kind = 'macro'
        elif surface.lower() in BUILTINS:
            kind = 'builtin'
        elif surface.lower() in tables.data_defines:
            kind = 'define-name'
        else:
            kind = 'unresolved'
        fam = classify_family(surface, canon, kind)
        ns = info.get('ns')
        fid = ((ns << 12) | info.get('idx', 0)) if ns is not None else ''
        api_rows.append({
            'name': surface, 'family': fam, 'kind': kind,
            'canonical': canon or '', 'funcspace': ns if ns is not None else '',
            'func_id': ('0x%04X' % fid) if fid != '' else '',
            'call_count': e['calls'], 'bare_count': e['bare'],
            'total': e['calls'] + e['bare'],
            'file_count': len(e['files']),
            'example_sites': ';'.join(e['sites']),
            'is_req': bool(REQ_RE.search(surface) or
                           (canon and REQ_RE.search(canon))),
        })

    # ── write CSVs ──
    if args.api_out:
        with open(args.api_out, 'w', newline='', encoding='utf-8') as f:
            w = csv.DictWriter(f, fieldnames=[
                'name', 'family', 'kind', 'canonical', 'funcspace',
                'func_id', 'call_count', 'bare_count', 'total',
                'file_count', 'is_req', 'example_sites'])
            w.writeheader()
            w.writerows(api_rows)
        print('wrote %d api rows -> %s' % (len(api_rows), args.api_out))

    if args.files_out:
        with open(args.files_out, 'w', newline='', encoding='utf-8') as f:
            w = csv.writer(f)
            w.writerow(['corpus', 'relpath', 'category', 'flags', 'dup_of',
                        'bytes', 'encoding', 'repl_chars',
                        'loc_total', 'loc_code', 'loc_comment', 'loc_blank',
                        'n_strings', 'n_workers', 'n_starlabels',
                        'n_colonlabels', 'n_local', 'n_authors',
                        'n_goto', 'n_switch', 'n_case', 'n_if', 'n_while',
                        'n_for', 'n_break', 'n_ret', 'n_define', 'n_macro',
                        'n_ifdef', 'n_alias', 'n_includes',
                        'n_calls', 'n_distinct_calls', 'n_bare',
                        'n_req_calls',
                        'workers', 'star_labels', 'authors', 'includes'])
            for r in file_rows:
                n_req = sum(c for n, c in r['calls'].items()
                            if REQ_RE.search(n))
                w.writerow([
                    r['corpus'], r['relpath'], r['category'], r['flags'],
                    r.get('dup_of', ''), r['bytes'], r['encoding'],
                    r['repl_chars'], r['loc_total'], r['loc_code'],
                    r['loc_comment'], r['loc_blank'], r['n_strings'],
                    len(r['workers']), len(r['star_labels']),
                    len(r['colon_labels']), r['n_local'],
                    len(r['authors']),
                    r['n_goto'], r['n_switch'], r['n_case'], r['n_if'],
                    r['n_while'], r['n_for'], r['n_break'], r['n_ret'],
                    r['n_define'], r['n_macro'], r['n_ifdef'], r['n_alias'],
                    len(r['includes']),
                    sum(r['calls'].values()), len(r['calls']),
                    sum(r['bare'].values()), n_req,
                    ';'.join(r['workers']), ';'.join(r['star_labels'][:40]),
                    ';'.join(r['authors']), ';'.join(r['includes'][:20])])
        print('wrote %d file rows -> %s' % (len(file_rows), args.files_out))

    # ── summary ──
    summary = {
        'roots': [{'label': l, 'path': p} for l, p in roots],
        'src_files': n_src,
        'per_corpus': dict(corpus_stats),
        'encodings': dict(enc_stats),
        'total_bytes': tot_bytes,
        'total_loc': tot_loc,
        'total_loc_code': tot_code,
        'categories': {k: {'files': v[0], 'loc': v[1], 'loc_code': v[2]}
                       for k, v in sorted(cat_stats.items())},
        'distinct_call_names': len(api_rows),
        'api_decls': len(tables.api),
        'funcspace_namespaces': sorted({v['ns'] for v in
                                        tables.api.values()}),
        'aliases': len(tables.alias),
        'func_aliases': sum(1 for k in tables.alias
                            if tables.is_func_alias(k)),
        'macros': len(tables.macros),
        'data_defines': len(tables.data_defines),
        'unresolved_names': sum(1 for r in api_rows
                              if r['kind'] == 'unresolved'),
        'req_names': sum(1 for r in api_rows if r['is_req']),
        'bvariant_hits': {k: v for k, v in bvar.items()},
        'top_apis': [
            {'name': r['name'], 'total': r['total'],
             'files': r['file_count'], 'family': r['family'],
             'canonical': r['canonical']}
            for r in api_rows[:args.top]],
    }
    if args.json_out:
        with open(args.json_out, 'w', encoding='utf-8') as f:
            json.dump(summary, f, ensure_ascii=False, indent=1)
        print('wrote summary -> %s' % args.json_out)

    print('== src census ==')
    print('src files        : %d %s' % (n_src, dict(corpus_stats)))
    print('bytes            : %d' % tot_bytes)
    print('loc total/code   : %d / %d' % (tot_loc, tot_code))
    print('distinct call names : %d' % len(api_rows))
    print('api decls (funcspace): %d ns=%s' %
          (len(tables.api), summary['funcspace_namespaces']))
    print('aliases          : %d (func-resolving %d)' %
          (len(tables.alias), summary['func_aliases']))
    print('macros           : %d' % len(tables.macros))
    print('unresolved names : %d' % summary['unresolved_names'])
    print('req-family names : %d' % summary['req_names'])
    print('b-variant hits   : %d' % len(bvar))
    for k in sorted(cat_stats):
        v = cat_stats[k]
        print('  %-14s %5d files  %8d loc  %8d code' %
              (k, v[0], v[1], v[2]))
    print('-- top %d call names --' % args.top)
    for r in api_rows[:args.top]:
        print('  %-28s %-12s %-10s tot=%-6d files=%-5d %s' %
              (r['name'], r['family'], r['kind'], r['total'],
               r['file_count'], r['canonical']))
    return 0


if __name__ == '__main__':
    sys.exit(main())
