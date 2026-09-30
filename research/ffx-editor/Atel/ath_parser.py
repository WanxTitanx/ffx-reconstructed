#!/usr/bin/env python3
# ── FFX/FFX2 `.ath` ATEL header parser + deterministic JSON emitter ───────────
#
# Purpose: parse the TEXT `.ath` C-header files that define ATEL function and
# command IDs (btlatel.ath, atelcam.ath, command.ath, monmagic.ath, monster.ath,
# item.ath, a_ability.ath, btlmap.ath, btlmapalias.ath, btlmot.ath, voice/*.ath,
# lastmiss lm_*.ath ...) and expose the name <-> ID mapping plus namespace
# math. Python stdlib only (re/json/os/sys/argparse) — research tool, does NOT
# ship in the editor.
#
# WHY a Python port: the reference parser is the C# `AtelHeaderFile.cs` in
# this same folder (docs/reverse/FFX_ATEL_HEADERS_ATH_ATD_2026-08-19.md §8).
# This file re-implements the same grammar so the codec lane can run it on
# Linux against the mounted extraction without a .NET build, and emit a
# deterministic JSON corpus dump (same input -> byte-identical JSON: fixed
# field order, files sorted by relative path, entries in file order, no
# timestamps).
#
# Grammar (2 dialects + sub-variants, all Shift-JIS text files):
#
#   Dialect A — funcspace function list (btlatel.ath / atelcam.ath):
#       funcspace 7
#       int    btlTerminateAction();
#       float  btlMoveTargetDist(int);
#       funcspace 0
#     Each declaration gets an implicit ID = (funcspace << 12) | index-in-list
#     (0-based). The trailing `funcspace 0` resets the namespace.
#
#   Dialect B — #define list with explicit IDs (command.ath / monmagic.ath /
#   monster.ath / item.ath / a_ability.ath / ply_save.ath / setype.ath /
#   btlmot.ath / btlmap.ath / voice/*.ath):
#       #define pcom_アイテム 0x03000          (hex direct)
#       #define bmap_グリッド ( 1025 )         (decimal in parens + comment)
#       #define VOICE_130101TS ( 0x1fc35513 )  (hex in parens)
#       #define 木の桟橋 0                     (decimal, no parens)
#       #define camsleep camSleep              (symbol alias — camera.ath)
#       #define header_btl_command             (guard, no value — skipped)
#
#   Directive: `#alias bmap_グリッド grid00_a` (btlmapalias.ath).
#   Trailing `// comment` is captured as the entry comment (JP description).
#
# ID math: namespace = id >> 12, index = id & 0xFFF (matches the runtime
# dispatch AtelCallTargets[namespace] + 16*index documented in the ATEL doc).
#
# MAINT: research-only (research_tools/Atel/). Encoding is autodetected:
# strict UTF-8 first, cp932 (Shift-JIS superset) fallback — the original
# game files are Shift-JIS but the mounted extraction stores UTF-8
# (byte-verified 2026-09-14). Replacement chars are counted and reported
# per file so mojibake never passes silently.

import argparse
import json
import os
import re
import sys

FUNCSPACE_RE = re.compile(r"^funcspace\s+([0-9A-Fa-fx]+)\s*$")
ALIAS_RE = re.compile(r"^#alias\s+(\S+)\s+(\S+)\s*$")
DEFINE_RE = re.compile(r"^#define\s+(\S+)\s*(.*)$")
FUNC_RE = re.compile(r"^(int|float|void|char|short|long)\s+"
                     r"([A-Za-z_][A-Za-z0-9_]*)\s*\(")
SKIP_PREFIXES = ("#ifndef", "#ifdef", "#if ", "#else", "#endif",
                 "#include", "#pragma")

# Expected counts for the 12 canonical battle/header files — the arbitration
# values from docs/reverse/FFX_ATEL_HEADERS_ATH_ATD_2026-08-19.md §5/§8 and
# errata E4 of FFX_STRUCTURE_ERRATA_REGISTRY_2026-09-13.md (the legacy atlas
# §8.2 said 336/150 — WRONG; real counts are 357/156).
EXPECTED_HEADER_COUNTS = {
    "btlatel.ath": (357, 0),
    "atelcam.ath": (156, 0),
    "command.ath": (554, 0),
    "monmagic.ath": (568, 0),
    "monster.ath": (370, 0),
    "item.ath": (68, 0),
    "ply_save.ath": (23, 0),
    "setype.ath": (17, 0),
    "btlmot.ath": (218, 0),
    "btlmap.ath": (114, 0),
    "btlmapalias.ath": (0, 57),
    "camera.ath": (83, 75),
}


def _strip_comment(line):
    """Split a raw line into (code, comment). A trailing // comment is kept
    without the marker; returns comment=None when absent."""
    idx = line.find("//")
    if idx < 0:
        return line, None
    return line[:idx], line[idx + 2:].strip()


def _try_parse_int(s):
    s = s.strip()
    try:
        if s.lower().startswith("0x"):
            return int(s[2:], 16)
        return int(s, 10)
    except ValueError:
        return None


class AtelEntry:
    """One parsed entry of an .ath header file (see AtelHeaderEntry in the
    C# reference parser — field-for-field equivalent)."""

    __slots__ = ("name", "id", "is_alias", "alias_target", "comment",
                 "source_line", "is_computed_id", "is_explicit_id")

    def __init__(self, name, id_=None, is_alias=False, alias_target=None,
                 comment=None, source_line=0, is_computed_id=False,
                 is_explicit_id=False):
        self.name = name
        self.id = id_
        self.is_alias = is_alias
        self.alias_target = alias_target
        self.comment = comment
        self.source_line = source_line
        self.is_computed_id = is_computed_id
        self.is_explicit_id = is_explicit_id

    @property
    def namespace(self):
        return None if self.id is None else self.id >> 12

    @property
    def index(self):
        return None if self.id is None else self.id & 0xFFF

    def to_json(self):
        # Fixed key order (deterministic output; None fields kept explicit).
        return {
            "name": self.name,
            "id": self.id,
            "namespace": self.namespace,
            "index": self.index,
            "isAlias": self.is_alias,
            "aliasTarget": self.alias_target,
            "comment": self.comment,
            "line": self.source_line,
            "computedId": self.is_computed_id,
            "explicitId": self.is_explicit_id,
        }


class AtelHeaderFile:
    """Parsed representation of one `.ath` header file."""

    def __init__(self, source_path=""):
        self.entries = []
        self.funcspaces = []
        self.source_path = source_path
        self.decode_replacements = 0

    # ── Counts / lookups ───────────────────────────────────────────────────

    @property
    def id_count(self):
        return sum(1 for e in self.entries if e.id is not None)

    @property
    def alias_count(self):
        return sum(1 for e in self.entries if e.is_alias)

    def by_namespace(self):
        out = {}
        for e in self.entries:
            if e.namespace is not None:
                out.setdefault(e.namespace, []).append(e)
        return dict(sorted(out.items()))

    def resolve(self, name):
        """name -> full ATEL id, or None when unknown (first wins)."""
        for e in self.entries:
            if e.name.lower() == name.lower():
                return e.id
        return None

    def resolve_id(self, id_):
        """id -> symbol name, or None."""
        for e in self.entries:
            if e.id == id_:
                return e.name
        return None

    # ── Parsing ────────────────────────────────────────────────────────────

    @classmethod
    def parse_file(cls, path):
        # Encoding autodetection: try strict UTF-8 first; on failure fall
        # back to cp932 (Windows-31J, the Shift-JIS superset the JP
        # toolchain wrote). WHY both: the original game files are Shift-JIS,
        # but the mounted extraction stores them converted to UTF-8
        # (verified byte-level 2026-09-14: command.ath name bytes are
        # e3 82 a2... = UTF-8 "アイテム"; the C# reference parser worked
        # because File.ReadAllText defaults to UTF-8). errors="replace" in
        # the fallback keeps parsing alive on stray bytes; the replacement
        # count is reported so mojibake never passes silently.
        with open(path, "rb") as fh:
            raw = fh.read()
        try:
            text = raw.decode("utf-8")
        except UnicodeDecodeError:
            text = raw.decode("cp932", errors="replace")
        parsed = cls.parse_text(text, path)
        parsed.decode_replacements = text.count("\ufffd")
        return parsed

    @classmethod
    def parse_text(cls, text, source_path=""):
        file = cls(source_path)
        current_funcspace = 0
        funcspace_index = 0        # running index within the current funcspace
        in_local_block = False     # local { ... } blocks in .src files
        in_line_block = False      # line NAME { ... } blocks in .src files

        for i, raw in enumerate(text.replace("\r\n", "\n").split("\n")):
            line, comment = _strip_comment(raw)
            trimmed = line.strip()
            line_no = i + 1
            if not trimmed:
                continue

            # Block state machine for .src files (local { } / line NAME { }).
            if trimmed.startswith("local") and "{" in trimmed:
                in_local_block = True
                continue
            if trimmed.startswith("line") and "{" in trimmed:
                in_line_block = True
                continue
            if trimmed == "}":
                in_local_block = in_line_block = False
                continue
            if in_local_block or in_line_block:
                continue

            # Preprocessor guards / includes — skipped entirely.
            if trimmed.startswith(SKIP_PREFIXES):
                continue

            m = FUNCSPACE_RE.match(trimmed)
            if m:
                current_funcspace = _try_parse_int(m.group(1)) or 0
                funcspace_index = 0
                file.funcspaces.append(current_funcspace)
                continue

            m = ALIAS_RE.match(trimmed)
            if m:
                file.entries.append(AtelEntry(
                    m.group(1), is_alias=True, alias_target=m.group(2),
                    comment=comment, source_line=line_no))
                continue

            m = DEFINE_RE.match(trimmed)
            if m:
                name, value = m.group(1), m.group(2).strip()
                if not value:            # guard define (#define __X__) — skip
                    continue
                inner = value
                # Strip surrounding parentheses: ( 0x1fc35513 ) / ( 1025 ).
                if inner.startswith("(") and inner.endswith(")"):
                    inner = inner[1:-1].strip()
                id_ = _try_parse_int(inner)
                if id_ is not None:
                    file.entries.append(AtelEntry(
                        name, id_=id_, is_explicit_id=True, comment=comment,
                        source_line=line_no))
                else:
                    # Value is another symbol -> alias (camera.ath style).
                    file.entries.append(AtelEntry(
                        name, is_alias=True, alias_target=inner,
                        comment=comment, source_line=line_no))
                continue

            m = FUNC_RE.match(trimmed)
            if m:
                id_ = (current_funcspace << 12) | (funcspace_index & 0xFFF)
                file.entries.append(AtelEntry(
                    m.group(2), id_=id_, is_computed_id=True,
                    comment=comment, source_line=line_no))
                funcspace_index += 1
                continue
            # Unknown line — recorded nowhere (resilient to .src boilerplate).

        return file

    # ── JSON ───────────────────────────────────────────────────────────────

    def to_json(self, rel_path):
        ns_counts = {str(ns): len(v)
                     for ns, v in self.by_namespace().items()}
        id_entries = [e for e in self.entries if e.id is not None]
        first = id_entries[0] if id_entries else None
        last = id_entries[-1] if id_entries else None
        return {
            "path": rel_path,
            "idCount": self.id_count,
            "aliasCount": self.alias_count,
            "funcspaces": self.funcspaces,
            "decodeReplacementChars": self.decode_replacements,
            "namespaceCounts": ns_counts,
            "firstId": ({"name": first.name, "id": first.id}
                        if first else None),
            "lastId": ({"name": last.name, "id": last.id}
                       if last else None),
            "entries": [e.to_json() for e in self.entries],
        }


def collect_ath_files(root):
    """All *.ath under root (recursively), sorted by relative path —
    deterministic iteration order for the JSON dump."""
    if os.path.isfile(root):
        return [(os.path.basename(root), root)]
    out = []
    for dirpath, _dirs, files in os.walk(root):
        for name in files:
            if name.lower().endswith(".ath"):
                full = os.path.join(dirpath, name)
                out.append((os.path.relpath(full, root), full))
    return sorted(out)


def parse_corpus(root):
    files = collect_ath_files(root)
    per_file = []
    totals = {"files": 0, "ids": 0, "aliases": 0,
              "decodeReplacementChars": 0}
    for rel, full in files:
        parsed = AtelHeaderFile.parse_file(full)
        doc = parsed.to_json(rel.replace(os.sep, "/"))
        per_file.append(doc)
        totals["files"] += 1
        totals["ids"] += doc["idCount"]
        totals["aliases"] += doc["aliasCount"]
        totals["decodeReplacementChars"] += doc["decodeReplacementChars"]
    corpus = {
        "generator": "research_tools/Atel/ath_parser.py",
        "root": root,
        "totals": totals,
        "files": per_file,
    }
    return corpus


def check_expected(corpus):
    """Match battle/header/<name> files against EXPECTED_HEADER_COUNTS.
    Returns (n_checked, n_pass, lines)."""
    lines = []
    n_pass = 0
    checked = 0
    for doc in corpus["files"]:
        p = doc["path"]
        base = p.rsplit("/", 1)[-1]
        if base not in EXPECTED_HEADER_COUNTS:
            continue
        if not (p.endswith("battle/header/" + base)
                or "/" not in p):       # single-file invocation
            continue
        exp_ids, exp_alias = EXPECTED_HEADER_COUNTS[base]
        checked += 1
        ok = (doc["idCount"] == exp_ids and doc["aliasCount"] == exp_alias)
        n_pass += ok
        verdict = "PASS" if ok else "FAIL"
        lines.append(f"[{verdict}] {base}: ids={doc['idCount']}"
                     f"{'' if doc['aliasCount'] == 0 else ' aliases=' + str(doc['aliasCount'])}"
                     f" (expected {exp_ids} ids"
                     f"{'' if exp_alias == 0 else ', ' + str(exp_alias) + ' aliases'})")
    return checked, n_pass, lines


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="FFX/FFX2 .ath ATEL header parser -> deterministic JSON "
                    "(stdlib-only research tool; Python port of "
                    "AtelHeaderFile.cs)")
    ap.add_argument("root", help=".ath file or directory to parse "
                                 "(recursively)")
    ap.add_argument("--out", help="write deterministic JSON here")
    ap.add_argument("--expect", action="store_true",
                    help="check counts against the 12 canonical "
                         "battle/header files (errata E4)")
    args = ap.parse_args(argv)

    corpus = parse_corpus(args.root)

    print(f"== .ath corpus: {args.root}")
    print(f"files parsed        : {corpus['totals']['files']}")
    print(f"total ids           : {corpus['totals']['ids']}")
    print(f"total aliases       : {corpus['totals']['aliases']}")
    print(f"decode replacements : {corpus['totals']['decodeReplacementChars']}")
    for doc in corpus["files"]:
        fs = (f", funcspaces {doc['funcspaces']}" if doc["funcspaces"]
              else "")
        al = f", {doc['aliasCount']} aliases" if doc["aliasCount"] else ""
        first = doc["firstId"]
        last = doc["lastId"]
        rng = (f"  {first['name']}=0x{first['id'] & 0xFFFFFFFF:05X}.."
               f"{last['name']}=0x{last['id'] & 0xFFFFFFFF:05X}"
               if first and last else "")
        print(f"    {doc['path']}: {doc['idCount']} ids{al}{fs}{rng}")

    if args.out:
        with open(args.out, "w", encoding="utf-8") as fh:
            json.dump(corpus, fh, ensure_ascii=False, indent=1)
            fh.write("\n")
        print(f"== deterministic JSON written: {args.out}")

    if args.expect:
        checked, n_pass, lines = check_expected(corpus)
        print(f"== expected-count check: {n_pass}/{checked} PASS")
        for ln in lines:
            print(f"    {ln}")
        if checked and n_pass != checked:
            return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
