#!/usr/bin/env python3
# ── FFX/FFX2 `.ath` ATEL header RT0 writer (lossless parse -> re-serialize) ──
#
# Purpose: prove a real `.ath` ENCODER with RT0 (round-trip level 0,
# byte-identical) over the extracted game corpus — closing the ".ath encoder"
# item of the P1 queue in FFX_STRUCTURE_ERRATA_REGISTRY_2026-09-13.md §5.5.
# This is the writer counterpart of the reader `ath_parser.py` in this same
# folder (semantic name<->ID census). Python stdlib only — research tool,
# does NOT ship in the editor.
#
# WHY a line-token AST instead of "canonical formatting": the .ath files are
# C-preprocessor-style TEXT headers (Shift-JIS toolchain origin, stored UTF-8
# in the mounted extraction) whose columns are hand-aligned with runs of
# tabs/spaces that vary per file (`#define\tcam_chr_nop\t\t\t\t(-1)` etc.).
# Byte identity therefore requires the AST to account for every byte: each
# line is LEXED into typed tokens (WS runs kept verbatim, directives, words,
# numbers, macro-args, punctuation) and MATCHED against the grammar below.
# The raw bytes never travel through as an opaque blob: a line that does not
# match a production raises AthFormatError (fail-loud, no verbatim fallback).
#
# Grammar (verified against the full FFX-2 corpus, 44 files — see
# docs/reverse/FFX_ATH_WRITER_RT0_2026-09-15.md):
#   line      := BLANK | COMMENT | guard | funcspace | funcdecl | define
#              | alias | macrodef | endm | macrobody
#   guard      := "#ifndef" WS name | "#define" WS name | "#endif"
#              | "#undef" WS name
#   funcspace  := "funcspace" WS NUMBER          (sets namespace, resets idx)
#   funcdecl   := TYPE WS name "(" params ")" ";"   (id = (fs<<12)|idx++)
#   define     := "#define" WS name WS value
#   value      := NUMBER                          (bare hex/dec)
#              | "(" ["-"] NUMBER ")"             (paren numeric)
#              | name                             (symbol alias)
#              | name "(" ")"                     (call alias)
#              | "(" name ("+" name)* ")"         (bit-or expression)
#   alias      := "#alias" WS name WS name
#   macrodef   := "#macro" WS name "(" macroargs ")"
#   macrobody  := name "(" macroargs ")"          (only inside #macro..#endm)
#   COMMENT    := "//" <free text to end of line> (may follow any production)
#
# Encoding/EOL model: per-file codec autodetected (strict UTF-8 first, cp932
# fallback — corpus is 100% UTF-8, no BOM, CRLF, trailing final newline);
# every line keeps its own EOL string so mixed endings would round-trip too.
#
# MAINT: research-only (research_tools/Atel/). Cross-checks per-file
# id/alias counts against ath_parser.py (independent semantic reader) —
# both must agree for a file to count as PASS.

import argparse
import hashlib
import json
import os
import re
import sys
from collections import namedtuple

RET_TYPES = ("int", "float", "void", "char", "short", "long")
PUNCT_CHARS = "();,*+-"
HEX_DIGITS = "0123456789abcdefABCDEF"

Token = namedtuple("Token", ["kind", "text"])
# kinds: WS (space/tab run, verbatim), DIR (#directive), W (word/name),
#        NUM (numeric literal), MAC ($N macro arg), P (punctuation)

# Production ids (reported in stats/evidence).
PRODUCTIONS = (
    "blank", "comment", "guard_ifndef", "guard_define", "endif", "undef",
    "funcspace", "funcdecl", "define_num", "define_alias_sym",
    "define_alias_call", "define_expr", "alias", "macrodef", "endm",
    "macrobody",
)


class AthFormatError(Exception):
    """Raised when a line does not match the .ath grammar (fail-loud)."""


# ── Lexer ────────────────────────────────────────────────────────────────────

def _is_ws(c):
    return c == " " or c == "\t"


# Word-body delimiters: these ASCII chars end a word and are lexed as their
# own tokens (or start a comment). Everything else printable is word body.
_WORD_DELIMS = set(" \t#$();,*+-/")


def _is_word_char(c):
    # Words cover ASCII identifiers AND the Japanese/full-width name body
    # (pcom_アイテム, job_調教士（ユウナ）, bid_…＿０, accessory_パワー＋１ —
    # full-width （）＿＋ etc. are NAME characters here, not punctuation).
    # Control chars (< 0x21, tab handled as WS) are never word chars, so the
    # lexer fails loudly on stray control bytes instead of copying them.
    if c in _WORD_DELIMS:
        return False
    return ord(c) >= 0x21 and c != "\x7f"


def tokenize(code, line_no):
    """Lex one code part (comment already split off) into typed tokens.
    Every byte of `code` must be consumed by exactly one token, otherwise
    AthFormatError — the writer never carries opaque bytes."""
    toks = []
    i, n = 0, len(code)
    while i < n:
        c = code[i]
        if _is_ws(c):
            j = i + 1
            while j < n and _is_ws(code[j]):
                j += 1
            toks.append(Token("WS", code[i:j]))
        elif c == "#":
            j = i + 1
            while j < n and _is_word_char(code[j]):
                j += 1
            if j == i + 1:
                raise AthFormatError(
                    f"line {line_no}: bare '#' (unknown directive)")
            toks.append(Token("DIR", code[i:j]))
        elif c == "$":
            j = i + 1
            while j < n and "0" <= code[j] <= "9":
                j += 1
            if j == i + 1:
                raise AthFormatError(
                    f"line {line_no}: bare '$' (macro arg expected)")
            toks.append(Token("MAC", code[i:j]))
        elif c in PUNCT_CHARS:
            toks.append(Token("P", c))
            j = i + 1
        elif "0" <= c <= "9":
            j = i
            if c == "0" and i + 1 < n and code[i + 1] in "xX":
                j = i + 2
                while j < n and code[j] in HEX_DIGITS:
                    j += 1
            else:
                while j < n and "0" <= code[j] <= "9":
                    j += 1
            toks.append(Token("NUM", code[i:j]))
        elif c == "/":
            # Comments were split at the FIRST '//' before lexing; a '/'
            # reaching here means unexpected division/slash in code.
            raise AthFormatError(f"line {line_no}: unexpected '/' in code")
        else:
            j = i
            while j < n and _is_word_char(code[j]):
                j += 1
            if j == i:  # control char / unmappable — never silently copy
                raise AthFormatError(
                    f"line {line_no}: unlexable char {c!r} (0x{ord(c):02x})")
            toks.append(Token("W", code[i:j]))
        i = j
    return toks


def parse_number(text, line_no):
    """Numeric literal text -> int (hex keeps its spelling; spelling itself
    is preserved by the AST, this only validates/derives the value)."""
    try:
        if text.lower().startswith("0x"):
            return int(text[2:], 16)
        return int(text, 10)
    except ValueError:
        raise AthFormatError(f"line {line_no}: bad number {text!r}")


# ── Parser state (namespace math + macro region) ─────────────────────────────

class ParserState:
    def __init__(self):
        self.line_no = 0
        self.funcspace = 0
        self.fs_index = 0            # running index inside current funcspace
        self.in_macro = False
        self.guard_depth = 0


# ── Line AST ─────────────────────────────────────────────────────────────────

class AthLine:
    """One parsed line: full token list (WS included, verbatim), optional
    trailing comment, own EOL, production id and semantic payload."""

    __slots__ = ("tokens", "has_comment", "comment_text", "eol", "line_no",
                 "production", "entry_kind", "name", "value")

    def __init__(self, tokens, has_comment, comment_text, eol, line_no,
                 production, entry_kind=None, name=None, value=None):
        self.tokens = tuple(tokens)
        self.has_comment = has_comment
        self.comment_text = comment_text
        self.eol = eol
        self.line_no = line_no
        self.production = production
        self.entry_kind = entry_kind      # 'id' | 'alias' | None
        self.name = name
        self.value = value                # int for numeric defines / funcdecl

    def to_text(self):
        s = "".join(t.text for t in self.tokens)
        if self.has_comment:
            s += "//" + self.comment_text
        return s + self.eol

    def key(self):
        """Structural fingerprint (for idempotency checks)."""
        return (tuple((t.kind, t.text) for t in self.tokens),
                self.has_comment, self.comment_text, self.eol, self.production)


def _shape(core, seq):
    """Match core (WS-stripped) tokens against [(kind, text_or_None), ...]."""
    if len(core) != len(seq):
        return False
    for t, (kind, text) in zip(core, seq):
        if t.kind != kind or (text is not None and t.text != text):
            return False
    return True


def _check_param_tokens(inner, line_no, allow_mac):
    """Tokens between '(' and ')' of a funcdecl/macro signature: basic types,
    ',', '*' (and '$N' args when allow_mac). Anything else -> error."""
    for t in inner:
        if t.kind == "W":
            if t.text not in RET_TYPES:
                raise AthFormatError(
                    f"line {line_no}: param {t.text!r} is not a basic type")
        elif t.kind == "P" and t.text in (",", "*"):
            pass
        elif t.kind == "MAC" and allow_mac:
            pass
        else:
            raise AthFormatError(
                f"line {line_no}: token {t.text!r} not valid in signature")


def _classify_define_value(vcore, line_no):
    """Classify the value part of `#define name <value>` (core tokens)."""
    if len(vcore) == 1 and vcore[0].kind == "NUM":
        return "define_num", "id", parse_number(vcore[0].text, line_no)
    if len(vcore) >= 3 and _shape(vcore[:1], [("P", "(")]) \
            and _shape(vcore[-1:], [("P", ")")]):
        inner = vcore[1:-1]
        if len(inner) == 1 and inner[0].kind == "NUM":
            return "define_num", "id", parse_number(inner[0].text, line_no)
        if len(inner) == 2 and _shape(inner[:1], [("P", "-")]) \
                and inner[1].kind == "NUM":
            return "define_num", "id", -parse_number(inner[1].text, line_no)
        # (name+name+...) bit-or expression — counted as alias (matches
        # ath_parser.py, which cannot resolve it to an int either).
        if len(inner) >= 3 and len(inner) % 2 == 1:
            ok = inner[0].kind == "W" and inner[-1].kind == "W"
            for k in range(1, len(inner) - 1, 2):
                if not _shape(inner[k:k + 1], [("P", "+")]) \
                        or inner[k + 1].kind != "W":
                    ok = False
                    break
            if ok:
                return "define_expr", "alias", None
    if len(vcore) == 1 and vcore[0].kind == "W":
        return "define_alias_sym", "alias", None
    if len(vcore) == 3 and _shape(vcore, [("W", None), ("P", "("), ("P", ")")]):
        return "define_alias_call", "alias", None
    raise AthFormatError(
        f"line {line_no}: unrecognized #define value shape "
        + " ".join(t.kind + ":" + t.text for t in vcore))


def classify_line(tokens, state):
    """Token list -> (production, entry_kind, name, value). Fail-loud."""
    core = [t for t in tokens if t.kind != "WS"]
    ln = state.line_no

    # BLANK / COMMENT-only line (tokens are [] or a single leading-WS run)
    if not core:
        if not tokens or (len(tokens) == 1 and tokens[0].kind == "WS"):
            if any(True for t in tokens if t.text.strip()):
                raise AthFormatError(f"line {ln}: whitespace-only with junk")
            return ("blank" if not tokens else "comment", None, None, None)
        raise AthFormatError(f"line {ln}: only WS tokens expected")

    if core[0].kind == "DIR":
        d = core[0].text
        if d == "#ifndef" and _shape(core, [("DIR", None), ("W", None)]):
            state.guard_depth += 1
            return ("guard_ifndef", None, core[1].text, None)
        if d == "#define":
            if _shape(core, [("DIR", None), ("W", None)]):
                return ("guard_define", None, core[1].text, None)
            if len(core) >= 3 and core[1].kind == "W":
                prod, kind, val = _classify_define_value(core[2:], ln)
                return (prod, kind, core[1].text, val)
            raise AthFormatError(f"line {ln}: bad #define shape")
        if d == "#endif" and _shape(core, [("DIR", None)]):
            state.guard_depth -= 1
            if state.guard_depth < 0:
                raise AthFormatError(f"line {ln}: #endif without #ifndef")
            return ("endif", None, None, None)
        if d == "#undef" and _shape(core, [("DIR", None), ("W", None)]):
            return ("undef", None, core[1].text, None)
        if d == "#alias" and _shape(core, [("DIR", None), ("W", None),
                                           ("W", None)]):
            return ("alias", "alias", core[1].text, None)
        if d == "#macro" and len(core) >= 4 and _shape(core[:3], [
                ("DIR", None), ("W", None), ("P", "(")]) \
                and _shape(core[-1:], [("P", ")")]):
            _check_param_tokens(core[3:-1], ln, allow_mac=True)
            if state.in_macro:
                raise AthFormatError(f"line {ln}: nested #macro")
            state.in_macro = True
            return ("macrodef", None, core[1].text, None)
        if d == "#endm" and _shape(core, [("DIR", None)]):
            if not state.in_macro:
                raise AthFormatError(f"line {ln}: #endm without #macro")
            state.in_macro = False
            return ("endm", None, None, None)
        raise AthFormatError(f"line {ln}: unknown directive {d!r}")

    if _shape(core, [("W", "funcspace"), ("NUM", None)]):
        state.funcspace = parse_number(core[1].text, ln)
        state.fs_index = 0
        return ("funcspace", None, None, state.funcspace)

    # FUNCDECL: TYPE name ( params ) ;
    if len(core) >= 5 and core[0].kind == "W" and core[0].text in RET_TYPES \
            and core[1].kind == "W" and _shape(core[2:3], [("P", "(")]) \
            and _shape(core[-2:], [("P", ")"), ("P", ";")]):
        _check_param_tokens(core[3:-2], ln, allow_mac=False)
        value = (state.funcspace << 12) | (state.fs_index & 0xFFF)
        state.fs_index += 1
        return ("funcdecl", "id", core[1].text, value)

    # MACROBODY: name ( $args ) — only valid inside a #macro..#endm block
    if state.in_macro and len(core) >= 3 and core[0].kind == "W" \
            and _shape(core[1:2], [("P", "(")]) \
            and _shape(core[-1:], [("P", ")")]):
        _check_param_tokens(core[2:-1], ln, allow_mac=True)
        return ("macrobody", None, core[0].text, None)

    raise AthFormatError(
        f"line {ln}: unrecognized line shape "
        + " ".join(t.kind + ":" + t.text for t in core[:8]))


# ── File model ───────────────────────────────────────────────────────────────

class AthFile:
    """Lossless parsed representation of one `.ath` file."""

    def __init__(self):
        self.encoding = "utf-8"
        self.lines = []

    # ── parse ──
    @classmethod
    def parse_bytes(cls, raw):
        try:
            text = raw.decode("utf-8")
            enc = "utf-8"
        except UnicodeDecodeError:
            # cp932 strict: replacement chars would break byte identity, so
            # a decode error here is fatal rather than silent mojibake.
            text = raw.decode("cp932")
            enc = "cp932"
        doc = cls()
        doc.encoding = enc
        state = ParserState()
        for content, eol in _split_eol(text):
            state.line_no += 1
            doc.lines.append(_parse_one_line(content, eol, state))
        if state.guard_depth != 0:
            raise AthFormatError(
                f"{state.line_no} lines: unbalanced guards "
                f"(depth {state.guard_depth} at EOF)")
        if state.in_macro:
            raise AthFormatError("EOF inside #macro block")
        return doc

    # ── serialize ──
    def to_text(self):
        return "".join(line.to_text() for line in self.lines)

    def to_bytes(self):
        return self.to_text().encode(self.encoding)

    # ── semantic stats (same entry definitions as ath_parser.py) ──
    def id_count(self):
        return sum(1 for l in self.lines if l.entry_kind == "id")

    def alias_count(self):
        return sum(1 for l in self.lines if l.entry_kind == "alias")

    def production_counts(self):
        out = {}
        for l in self.lines:
            out[l.production] = out.get(l.production, 0) + 1
        return out


def _split_eol(text):
    """Split text into (content, eol) pairs keeping each line's terminator.
    A final line without terminator yields eol=''."""
    out = []
    start, n = 0, len(text)
    while start < n:
        nl = text.find("\n", start)
        if nl < 0:
            out.append((text[start:], ""))
            break
        if nl > start and text[nl - 1] == "\r":
            out.append((text[start:nl - 1], "\r\n"))
        else:
            out.append((text[start:nl], "\n"))
        start = nl + 1
    return out


def _parse_one_line(content, eol, state):
    idx = content.find("//")
    if idx >= 0:
        code, comment_text, has_comment = content[:idx], content[idx + 2:], True
    else:
        code, comment_text, has_comment = content, None, False
    tokens = tokenize(code, state.line_no)
    production, kind, name, value = classify_line(tokens, state)
    return AthLine(tokens, has_comment, comment_text, eol, state.line_no,
                   production, kind, name, value)


# ── RT0 harness ──────────────────────────────────────────────────────────────

def collect_ath_files(root):
    if os.path.isfile(root):
        return [root]
    out = []
    for dirpath, _dirs, files in os.walk(root):
        for name in files:
            if name.lower().endswith(".ath"):
                out.append(os.path.join(dirpath, name))
    return sorted(out)


def _crosscheck(path, doc):
    """Compare id/alias counts with the independent semantic reader
    (ath_parser.py). Returns (parser_ids, parser_aliases) or raises."""
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import ath_parser  # local sibling (research_tools/Atel/)
    ref = ath_parser.AtelHeaderFile.parse_file(path)
    return ref.id_count, ref.alias_count


def rt0_file(path, crosscheck=False):
    """Parse -> re-serialize -> compare. Returns a result dict."""
    with open(path, "rb") as fh:
        raw = fh.read()
    result = {
        "file": path,
        "bytes": len(raw),
        "sha256In": hashlib.sha256(raw).hexdigest(),
        "match": False,
        "error": None,
    }
    try:
        doc = AthFile.parse_bytes(raw)
        out = doc.to_bytes()
        result["sha256Out"] = hashlib.sha256(out).hexdigest()
        result["match"] = (out == raw)
        result["encoding"] = doc.encoding
        result["lines"] = len(doc.lines)
        result["idCount"] = doc.id_count()
        result["aliasCount"] = doc.alias_count()
        result["productions"] = doc.production_counts()
        # Idempotency at AST level: re-parsing our own output must yield
        # the exact same structure (stronger than byte equality alone).
        doc2 = AthFile.parse_bytes(out)
        result["idempotentAst"] = (
            [l.key() for l in doc.lines] == [l.key() for l in doc2.lines])
        if crosscheck:
            pids, palias = _crosscheck(path, doc)
            result["crosscheck"] = {
                "parserIds": pids, "parserAliases": palias,
                "ok": (pids == result["idCount"]
                       and palias == result["aliasCount"]),
            }
        if not result["match"]:
            # First divergence offset for diagnostics.
            for off in range(min(len(raw), len(out))):
                if raw[off] != out[off]:
                    result["firstDiffOffset"] = off
                    result["firstDiffContext"] = {
                        "in": raw[max(0, off - 24):off + 24],
                        "out": out[max(0, off - 24):off + 24],
                    }
                    break
            else:
                result["firstDiffOffset"] = min(len(raw), len(out))
    except AthFormatError as exc:
        result["error"] = str(exc)
    except UnicodeDecodeError as exc:
        result["error"] = f"decode failure: {exc}"
    return result


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="FFX/FFX2 .ath RT0 writer — lossless parse/re-serialize "
                    "with byte-identical round-trip proof over a corpus")
    ap.add_argument("root", help=".ath file or directory (recursive)")
    ap.add_argument("--report", help="write JSON evidence report here")
    ap.add_argument("--emit-dir",
                    help="write re-serialized outputs under this dir "
                         "(spot inspection)")
    ap.add_argument("--crosscheck", action="store_true",
                    help="compare id/alias counts with ath_parser.py")
    args = ap.parse_args(argv)

    files = collect_ath_files(args.root)
    results = []
    n_ok = 0
    for path in files:
        res = rt0_file(path, crosscheck=args.crosscheck)
        results.append(res)
        if res["match"] and res.get("idempotentAst") \
                and (not args.crosscheck or res["crosscheck"]["ok"]):
            n_ok += 1
        status = "RT0-OK" if res["match"] else ("ERROR " + str(res["error"])
                                                if res["error"] else "DIFF")
        print(f"[{status}] {path} ({res['bytes']} B)")
        if args.emit_dir and res["match"]:
            rel = path[len(args.root.rstrip('/')) + 1:] \
                if os.path.isdir(args.root) else os.path.basename(path)
            dest = os.path.join(args.emit_dir, rel)
            os.makedirs(os.path.dirname(dest) or ".", exist_ok=True)
            with open(dest, "wb") as fh:
                fh.write(AthFile.parse_bytes(open(path, "rb").read())
                         .to_bytes())

    totals = {
        "files": len(files),
        "byteIdentical": sum(1 for r in results if r["match"]),
        "errors": sum(1 for r in results if r["error"]),
        "astIdempotent": sum(1 for r in results if r.get("idempotentAst")),
    }
    if args.crosscheck:
        totals["crosscheckOk"] = sum(1 for r in results
                                     if r.get("crosscheck", {}).get("ok"))
    print(f"== RT0: {totals['byteIdentical']}/{totals['files']} "
          f"byte-identical, AST-idempotent {totals['astIdempotent']}")
    if args.report:
        os.makedirs(os.path.dirname(os.path.abspath(args.report)),
                    exist_ok=True)
        payload = {
            "generator": "research_tools/Atel/ath_writer.py",
            "root": args.root,
            "totals": totals,
            "files": results,
        }
        with open(args.report, "w", encoding="utf-8") as fh:
            json.dump(payload, fh, ensure_ascii=False, indent=1)
            fh.write("\n")
        print(f"== report: {args.report}")
    ok = totals["byteIdentical"] == totals["files"]
    if args.crosscheck:
        ok = ok and totals["crosscheckOk"] == totals["files"]
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
