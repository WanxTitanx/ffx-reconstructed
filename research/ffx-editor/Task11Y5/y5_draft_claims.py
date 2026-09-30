#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""y5_draft_claims.py — deterministic DRAFT claim generator for the Y5 vnext cycle.

Purpose
-------
For a batch defined in y5-batches.json, derive one DRAFT claim per claim-worthy
source unit (tier A: text carries a factual marker) following EXACTLY the shape of
the accepted claims in Utilities/FFXResearchTools/Claims/atlas-migration.claims.json
(same field names, same field order, same boundary vocabulary).

Honesty contract (READ BEFORE TRUSTING ANYTHING HERE)
-----------------------------------------------------
- Every claim produced by this tool is a CANDIDATE DRAFT — never accepted, never
  validated, never "fully decoded". Each claim asserts ONLY what the legacy FFX
  structure atlas (2026-08-17 snapshot, sha256 F5439414...) RECORDS at the unit's
  byte range; it does NOT assert that the recorded fact is true of any live game
  artifact. Live-artifact verification is future work inside the X/Y/Z cycle.
- claim_text is derived mechanically from the unit's real text (markdown stripped,
  whitespace collapsed). Nothing is invented; over-long units are truncated and
  the truncation is flagged in the sidecar.
- scope_id / boundary_id are DRAFT ids computed as sha256 over a documented
  literal basis ("draft-y5-scope|<claim_id>"). They are NOT the canonical service
  ids and MUST be recomputed with the real CanonicalJson/ClaimAuditService at
  materialization (same rule the vnext C1 attestations used for binding ids).
- claim_text_sha256 IS the real derivation: sha256(claim_text utf-8, uppercase hex)
  — verified identical to the accepted corpus derivation.

Inputs (read-only): y5-batches.json, y5-units-reconstruction.json (same directory),
legacy atlas in the repo (for table captions). Outputs: drafts/y5-draft-claims-
batch-<id>.json + drafts/y5-draft-claims-batch-<id>.units.json (sidecar).

--tierb (2026-09-15, Y5-TIERB-X5): second pass over the units the normal path
skips as "tier-b-ambiguous". Drafts the claimable technical subset as virtual
batch y5-b24-tierb-secondpass (not part of y5-batches.json — that file stays
pinned). See the TIERB_* block below for the predicate definition.

Dependencies: Python 3.8+ standard library only. Deterministic: document order,
no timestamps, no randomness.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import sys

DEFAULT_REPO = "/home/wanderson/Documents/ffx-editor-main"
ATLAS_REL = os.path.join("docs", "reverse", "FFX_STRUCTURE_COMPLETE_2026-08-17.md")
EXPECTED_SOURCE_SHA256 = "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7"

DRAFT_NOTES = "DRAFT y5 candidate — NOT accepted; pending X/Y/Z review cycle"
MAX_CLAIM_CHARS = 460

# Per-batch claim subject vocabulary (draft values; re-issued at materialization).
# 2026-09-14 (Y5-BATCHER): added wave-2 entries b06/b07/b09 ONLY (additive dict
# entries — batches b01-b03 emit byte-identical output, verified by regression
# test before/after; sec_short strings mirror the batch themes in y5-batches.json).
# 2026-09-15 (Y5-BATCHES): added the REMAINING wave-2 entries b10/b08/b11/b04/b05
# (queue order of y5-coverage-plan.md §5) — same additive pattern; sec_short strings
# mirror the batch themes in y5-batches.json. Regression re-proven: b01-b03 +
# b06/b07/b09 emit byte-identical output with this extension (12/12 files, cmp).
# 2026-09-15 (Y5-DRAFTS): added the FINAL entries b12..b23 (waves 3-5, queue order
# of y5-coverage-plan.md §5: b14->b13->b15->b12, b18->b20->b17->b19->b16,
# b21->b22->b23) — same additive pattern; sec_short strings mirror the batch
# themes in y5-batches.json. Regression re-proven: all 11 previously covered
# batches emit byte-identical output with this extension (22/22 files, cmp).
BATCH_SUBJECTS = {
    "y5-b01-menu-formats": {"format_id": "menu", "sec_short": "section 11.21 (menu formats .clp/.dcp/.fmt/.sps2)"},
    "y5-b02-egovm-opcodes": {"format_id": "egovm", "sec_short": "section 11.33 (Magic EgoVM opcode mapping)"},
    "y5-b03-ftc-glyphs": {"format_id": "ftc", "sec_short": "section 11.34 (FTC glyph mapping)"},
    "y5-b06-atel-headers": {"format_id": "atel", "sec_short": "section 11.16 (ATEL headers .ath/.atd)"},
    "y5-b07-tbl-catalogs": {"format_id": "tbl", "sec_short": "section 11.19 (.tbl catalogs + MonsterMagic/Particle VM)"},
    "y5-b09-vbf-txc-psarc": {"format_id": "vbf", "sec_short": "sections 11.11/11.31 (VBF pack/unpack + .txc binary + .psarc writer)"},
    "y5-b10-sjis-encoding": {"format_id": "sjis", "sec_short": "section 11.12 (SJIS encoding reference)"},
    "y5-b08-mapout-vpa": {"format_id": "vpa", "sec_short": "section 11.29 (mapout.vpa 4 families + YNDT)"},
    "y5-b11-font-texture-phyre": {"format_id": "phyre", "sec_short": "sections 11.25/11.22 (Phyre textures + font/texture formats)"},
    "y5-b04-fev-fsb-audio": {"format_id": "fev", "sec_short": "section 11.24 (FEV/FSB audio formats)"},
    "y5-b05-abmap-assets": {"format_id": "abmap", "sec_short": "section 11.18 (ABMap assets .anm/.an2/.omd)"},
    "y5-b14-runtime-pc": {"format_id": "runtime", "sec_short": "sections 8/11.9 (FFX.exe PC runtime overview + IDA module addresses)"},
    "y5-b13-save-payloads": {"format_id": "save", "sec_short": "sections 11.17/11.37/11.32 (save modules + payload maps G1-G12)"},
    "y5-b15-runtime-ida": {"format_id": "ida", "sec_short": "sections 11.26-11.28/11.30 (IDA decompile runtimes: sphere grid, magic system, blitzball, field events)"},
    "y5-b12-ctb-status": {"format_id": "ctb", "sec_short": "sections 11.15/11.36 (CTB & status system + open questions)"},
    "y5-b18-encoder-gaps": {"format_id": "encoder", "sec_short": "section 11.14 (encoder/decoder gaps audit)"},
    "y5-b20-workspace-layout": {"format_id": "workspace", "sec_short": "sections 1-6/6.1/9/10/11.10 (workspace & directory structures + parsers + data flow)"},
    "y5-b17-format-families": {"format_id": "formats", "sec_short": "section 7 (format families overview)"},
    "y5-b19-magic-dll": {"format_id": "ppp", "sec_short": "section 11.20 (Magic DLL PPP/EgoVM catalog)"},
    "y5-b16-noclip-api": {"format_id": "noclip", "sec_short": "sections 11.13/11.7 (noclip.website API catalogs)"},
    "y5-b21-indexes": {"format_id": "index", "sec_short": "sections 13/13.1-13.3 (reference indexes: docs/labs/tools)"},
    "y5-b22-mateditor-blocks": {"format_id": "mateditor", "sec_short": "L1 blocks (MatEditor raw dump blocks: vertex/normal/polygon/groups)"},
    "y5-b23-editorial-misc": {"format_id": "editorial", "sec_short": "editorial/misc sections (platform diffs, PS2 ground truth, header verification, PSARC/PS4, Fahrenheit, resolved questions, RSD/PLY/MA2, honest gaps)"},
}

# A034 window (atlas lines 7310-7369, section 11.25): units here overlap the anchor
# A034 window routed in the vnext C1 cycle and may belong to the a034-context/bound
# buckets instead of the Y5 queue (y5-batches.json a034_window_note; coverage plan
# §3.2 — window units "não foram usadas em nenhum draft"). y5_batcher_validate.py
# enforces this as a hard invariant (a034_drafted == 0 with the same predicate).
# 2026-09-15 (Y5-BATCHES): before this rule the generator had no A034 exclusion —
# it was trivially satisfied for b01-b03/b06/b07/b09 (0 window units each). Batch
# b11 carries 8 window units; 1 of them (L7366, tier-A table header) would have
# been drafted without this rule.
A034_WINDOW = (7310, 7369)
# Formats recognized inside menu-format rows (claim_id slug precision for batch 01).
MENU_FORMAT_RE = re.compile(r"\.(clp|dcp|fmt|sps2)\b", re.I)

# ── 2026-09-15 (Y5-TIERB-X5): tier-B second pass ──────────────────────────────
# The skip audit (docs/reverse/FFX_Y5_SKIP_AUDIT_2026-09-15.md) proved the 1,331
# units parked as "tier-b-ambiguous" are not pure editorial noise: ~36.7% carry
# draftable technical fact the 4-marker tier-A test misses (struct-field dumps
# "Byte N:", "+N:" offsets, "(u16)" type tags, "--" field comments; enum maps
# "NAME=val"; formulas; "->" mappings; asm lines; asset filenames; code idents).
#
# --tierb drafts that claimable subset as a VIRTUAL batch "y5-b24-tierb-secondpass"
# (group fsc-20260817-043, next free id after b23=042). The batch is deliberately
# NOT added to y5-batches.json: that file is pinned identical across 3 locations
# (sha 0ce67a99...) and the b01..b23 queue is immutable. Instead the tier-B
# universe is re-derived here by replaying the exact skip chain of the normal
# pass (a034-window -> heading-candidate -> table-separator -> !factual_marker)
# over every defined batch; units landing in tier-b-ambiguous form the universe
# (verified 1,331 == recorded sidecar skips). Claimable units are drafted;
# residuals are skipped with a bucket-named reason (tierb-residual-<bucket>).
#
# Content-shape buckets (deterministic regexes, first match wins in
# TIERB_DECISION_ORDER). Claimable buckets: struct-field, index-map, enum-map,
# formula, code-assign, cond-expr, mapping-arrow, asm-dump, asset-ref,
# code-ident. Residual: doc-meta, hrule, bold-label, doc-ref, lead-in, prose.
TIERB_BATCH_ID = "y5-b24-tierb-secondpass"
TIERB_BATCH = {
    "batch_id": TIERB_BATCH_ID,
    "theme": "Tier-B second pass (X5): claimable technical units deferred as "
            "tier-b-ambiguous across b01..b23",
    "group_id": "fsc-20260817-043",
}
BATCH_SUBJECTS[TIERB_BATCH_ID] = {
    "format_id": "tierb",
    "sec_short": "tier-B deferred units (X5 second pass)",
}
TIERB_CLAIMABLE = {"struct-field", "index-map", "enum-map", "formula",
                   "code-assign", "cond-expr", "mapping-arrow", "asm-dump",
                   "asset-ref", "code-ident"}

_TB_DOC_META_RE = re.compile(
    r"^[\s>\-*#]*(?:\*\*)?\s*(date|data|lane|author|status|fontes?|escopo|sources?|"
    r"artefatos?|generated|research completed|base auditada|papel|generated by|"
    r"fim da|consolidates)\b", re.I)
_TB_HRULE_RE = re.compile(r"^[\s\-*_=·—]+$")
_TB_BOLD_ONLY_RE = re.compile(r"^(\*\*[^*]+\*\*\s*)+:?$")
_TB_BYTE_FIELD_RE = re.compile(r"\b[Bb]yte\s*\d+\s*[:=]|\b[Bb]ytes\s*\d+\s*[-–:]")
_TB_BIT_FIELD_RE = re.compile(r"\bbits?\s*\d+(?:\s*\.\.\s*\d+)?\s*[:=]", re.I)
_TB_INDEX_MAP_RE = re.compile(r"^\s*\d{1,4}\s*:\s+\S", re.M)
_TB_OFFS_FIELD_RE = re.compile(r"(?:^|[\s,])\+\s*\d+\s*[:=]|\boffset\s*\+?\d+|"
                               r"\boffs?\s*[:=]\s*\d+", re.I | re.M)
_TB_TYPE_TAG_RE = re.compile(
    r"\((?:u?int\d*|byte|word|dword|qword|short|ushort|long|float|double|"
    r"s8|s16|s32|u8|u16|u32|u64|char|bool|string|ptr|pointer)[^)]*\)", re.I)
_TB_BARE_TYPE_RE = re.compile(r"\b(u8|u16|u32|u64|s8|s16|s32|uint8|uint16|uint32|"
                              r"int16|int32|ushort|dword|qword|float32|VLQ|vlq)\b")
_TB_DASH_COMMENT_RE = re.compile(r"\s--\s|--\s*$")
_TB_DOC_EXTS = {"md", "ts", "cs", "py", "cpp", "h", "json", "txt", "log", "c",
                "cc", "js"}
_TB_DOTTED_PAREN_RE = re.compile(r"\b[A-Za-z_]\w*(?:\.[A-Za-z_]\w*)+\s*\(")
_TB_ENUM_RUN_RE = re.compile(r"\b[A-Za-z_][A-Za-z0-9_]{1,}\s*=\s*"
                             r"(?:0x[0-9A-Fa-f]+|\d+|[A-Z_][A-Z0-9_]{1,})\b")
_TB_FORMULA_RE = re.compile(r"\bformula\b\s*[:=]|\w+\s*=\s*[\w.()]+\s*[-+*/×]|"
                            r"/\s*256\b|\*\s*256\b|<<\s*\d+|>>\s*\d+|\bmod\s+\d+",
                            re.I)
_TB_ASSIGN_RE = re.compile(r"[A-Za-z_\)\]*]\s*=(?![=>])\s*[^=\s]")
_TB_CMP_OP_RE = re.compile(r">=|<=|!=|==|&&|\|\|")
_TB_ARROW_RE = re.compile(r"->|→|↔|=>|<=>")
_TB_ASM_MNEM = ("push|pop|mov|movzx|movsx|cmp|jmp|call|lea|xor|test|add|sub|inc|"
                "dec|ret|retn|nop|shl|shr|sar|and|or|imul|mul|idiv|div|jne|je|jz|"
                "jnz|jg|jge|jl|jle|ja|jb|jae|jbe|xchg|leave|int3|fld|fstp|fmul|"
                "fadd|cvtsi")
_TB_ASM_LINE_RE = re.compile(r"^\s*(" + _TB_ASM_MNEM + r")\b(.*)$", re.I | re.M)
_TB_ASM_OPERAND_OK = re.compile(
    r"[0-9A-Z_,;\[\]()*+]|$|\b(e?[abcd]x|e?[sd]i|e?[sb]p|[abcd][lh]|r\d+|xmm\d+|"
    r"byte|word|dword|qword|ptr|short|near|far)\b", re.I)
_TB_ASSET_EXT_RE = re.compile(
    r"\b[\w][\w.\-]*\.(dll|bin|txc|clt|dds|phyre|fev|fsb|vpa|ath|atd|clp|dcp|fmt|"
    r"sps2|anm|an2|omd|psarc|vbf|yndt|bkm|tbl|dat|exe|i64|tm2|pbd|sgb|mdl|pss|"
    r"vag|irx|elf|ftc|ftcx|arc|ffb|kit|sga|xwb|xsb|ma2|rsd|ply|ccd)\b", re.I)
_TB_ANY_EXT_RE = re.compile(r"\b[\w][\w.\-]*\.(\w{1,6})\b")
_TB_PATH_TOKEN_RE = re.compile(r"\S*/\S*|\b\S+\.\w{1,6}\b")
_TB_SNAKE_IDENT_RE = re.compile(r"\b[A-Za-z]\w*_\w+\b")
_TB_CAMEL_IDENT_RE = re.compile(r"\b[a-z]{2,}[A-Z][A-Za-z0-9]*\b")


def _tb_is_asm(t: str) -> bool:
    """Line starts with an x86 mnemonic AND the operand is code-ish (register,
    immediate, punctuation or empty) — rejects English words ("And the flags:").
    """
    for m in _TB_ASM_LINE_RE.finditer(t):
        rest = m.group(2).strip()
        if rest == "" or _TB_ASM_OPERAND_OK.search(rest):
            first = rest.split()[0] if rest else ""
            if first and first[0].islower() and not _TB_ASM_OPERAND_OK.search(first):
                continue
            return True
    return False


def tierb_shape(text: str) -> str:
    """Deterministic content-shape bucket for a tier-B unit's raw text."""
    t = text.replace("\r", " ")
    flat = re.sub(r"\s+", " ", t).strip()
    if _TB_DOC_META_RE.match(flat):
        return "doc-meta"
    if _TB_HRULE_RE.fullmatch(flat) and len(flat) >= 3:
        return "hrule"
    if _TB_BOLD_ONLY_RE.fullmatch(flat):
        return "bold-label"
    dotted = any(
        m.group(0).rstrip(" (").rsplit(".", 1)[-1].lower() not in _TB_DOC_EXTS
        for m in _TB_DOTTED_PAREN_RE.finditer(flat))
    if (_TB_BYTE_FIELD_RE.search(flat) or _TB_BIT_FIELD_RE.search(t)
            or _TB_OFFS_FIELD_RE.search(t) or _TB_TYPE_TAG_RE.search(flat)
            or _TB_DASH_COMMENT_RE.search(flat) or dotted
            or _TB_BARE_TYPE_RE.search(flat)):
        return "struct-field"
    if _TB_INDEX_MAP_RE.search(t):
        return "index-map"
    if len(_TB_ENUM_RUN_RE.findall(flat)) >= 2:
        return "enum-map"
    if _TB_FORMULA_RE.search(flat):
        return "formula"
    if _TB_ASSIGN_RE.search(flat):
        return "code-assign"
    if _TB_CMP_OP_RE.search(flat):
        return "cond-expr"
    if _TB_ARROW_RE.search(flat):
        return "mapping-arrow"
    if _tb_is_asm(t):
        return "asm-dump"
    if _TB_ASSET_EXT_RE.search(flat):
        return "asset-ref"
    masked = _TB_PATH_TOKEN_RE.sub(" ", flat)
    if _TB_SNAKE_IDENT_RE.search(masked) or _TB_CAMEL_IDENT_RE.search(masked):
        return "code-ident"
    exts = {m.group(1).lower() for m in _TB_ANY_EXT_RE.finditer(flat)}
    if exts and exts <= _TB_DOC_EXTS:
        return "doc-ref"
    if flat.endswith(":"):
        return "lead-in"
    return "prose"


def fail(msg: str):
    sys.stderr.write(f"y5_draft_claims: ERROR: {msg}\n")
    sys.exit(2)


def norm_cell(s: str) -> str:
    """Strip markdown emphasis/code and collapse whitespace in a table cell."""
    s = s.replace("**", "").replace("`", "")
    s = re.sub(r"\[([^\]]+)\]\([^)]*\)", r"\1", s)
    s = re.sub(r"\s+", " ", s).strip()
    return s


def norm_fact(s: str) -> str:
    """Normalize a unit text into a quotable fact string (markdown stripped)."""
    s = s.replace("\r", " ").replace("\n", " ")
    s = s.strip()
    s = re.sub(r"^>\s*", "", s)                 # blockquote marker
    s = re.sub(r"^[-*]\s+", "", s)              # list marker
    s = re.sub(r"^\d+[.)]\s+", "", s)           # ordered list marker
    s = s.replace("**", "").replace("`", "")
    s = re.sub(r"\[([^\]]+)\]\([^)]*\)", r"\1", s)
    s = re.sub(r"\s+", " ", s).strip()
    if s and not s.endswith((".", "!", "?", "…")):
        s += "."
    return s


def truncate(text: str) -> tuple[str, bool]:
    if len(text) <= MAX_CLAIM_CHARS:
        return text, False
    cut = text[:MAX_CLAIM_CHARS]
    sp = cut.rfind(" ")
    if sp > MAX_CLAIM_CHARS // 2:
        cut = cut[:sp]
    return cut.rstrip(" .,;") + " … [truncated]", True


def table_cells(text: str) -> list[str] | None:
    t = text.strip()
    if not (t.startswith("|") and t.endswith("|") and t.count("|") >= 2):
        return None
    return [norm_cell(c) for c in t[1:-1].split("|")]


def is_separator(cells: list[str]) -> bool:
    return bool(cells) and all(re.fullmatch(r"[-: ]*", c) for c in cells)


def draft_sha(basis: str) -> str:
    return hashlib.sha256(basis.encode("utf-8")).hexdigest().upper()


def classify_table_roles(sel: list) -> tuple[dict, list]:
    """Pass 1: classify table rows (header / separator / data) in document order."""
    kinds: dict[str, str] = {}  # unit_id -> row role
    headers: list[list[str] | None] = []  # parallel to sel: active header cells
    cur_header: list[str] | None = None
    for i, r in enumerate(sel):
        cells = table_cells(r["text"]) if r["kind"] == "table-row" else None
        if cells is None:
            cur_header = None
            headers.append(None)
            continue
        nxt = table_cells(sel[i + 1]["text"]) if i + 1 < len(sel) else None
        if is_separator(cells):
            kinds[r["source_unit_id"]] = "separator"
            headers.append(None)
            continue
        if nxt is not None and is_separator(nxt):
            kinds[r["source_unit_id"]] = "header"
            cur_header = cells
            headers.append(None)
            continue
        kinds[r["source_unit_id"]] = "data"
        headers.append(cur_header)
    return kinds, headers


def derive_tierb_universe(batches_doc: dict, rows_by_id: dict) -> list:
    """Re-derive the tier-b-ambiguous unit set across all defined batches.

    Replays the exact pass-2 skip chain of the normal path (a034-window ->
    heading-candidate -> table-separator -> !factual_marker); units that would
    be skipped as "tier-b-ambiguous" form the --tierb universe, returned in
    atlas document order (line_start, then unit id for a total order).
    """
    out = []
    for b in batches_doc["batches"]:
        sel = [rows_by_id[u] for u in b["unit_ids"]]
        kinds, _headers = classify_table_roles(sel)
        for r in sel:
            if A034_WINDOW[0] <= r["line_start"] <= A034_WINDOW[1]:
                continue
            if r["kind"] == "heading-candidate":
                continue
            if kinds.get(r["source_unit_id"]) == "separator":
                continue
            if r["factual_marker"]:
                continue
            out.append(r)
    out.sort(key=lambda r: (r["line_start"], r["source_unit_id"]))
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description="Generate DRAFT y5 claims for a batch (candidate, not accepted).")
    ap.add_argument("--batch-id")
    ap.add_argument("--tierb", action="store_true",
                    help="X5 second pass: draft the claimable subset of the "
                         "tier-b-ambiguous units skipped across b01..b23 as "
                         "virtual batch " + TIERB_BATCH_ID)
    ap.add_argument("--repo", default=DEFAULT_REPO)
    ap.add_argument("--artifacts", default=os.path.dirname(os.path.abspath(__file__)))
    args = ap.parse_args()

    art = args.artifacts
    batches_doc = json.load(open(os.path.join(art, "y5-batches.json"), encoding="utf-8"))
    if args.tierb:
        if args.batch_id and args.batch_id != TIERB_BATCH_ID:
            fail("--tierb only supports virtual batch " + TIERB_BATCH_ID)
        batch = TIERB_BATCH
    else:
        if not args.batch_id:
            fail("--batch-id required (or use --tierb for the tier-B second pass)")
        batch = next((b for b in batches_doc["batches"] if b["batch_id"] == args.batch_id), None)
        if batch is None:
            fail(f"unknown batch {args.batch_id}")
    subj = BATCH_SUBJECTS.get(batch["batch_id"])
    if subj is None:
        fail(f"no draft subject vocabulary registered for {batch['batch_id']}")

    rows = json.load(open(os.path.join(art, "y5-units-reconstruction.json"), encoding="utf-8"))
    rows_by_id = {r["source_unit_id"]: r for r in rows}
    with open(os.path.join(args.repo, ATLAS_REL), "rb") as fh:
        atlas = fh.read()
    atlas_sha = hashlib.sha256(atlas).hexdigest().upper()
    if atlas_sha != EXPECTED_SOURCE_SHA256:
        fail("legacy atlas sha mismatch")
    atlas_lines = atlas.split(b"\n")

    if args.tierb:
        sel = derive_tierb_universe(batches_doc, rows_by_id)
    else:
        unit_ids = batch["unit_ids"]
        sel = [rows_by_id[u] for u in unit_ids]
        if len(sel) != len(unit_ids):
            fail("batch references units missing from reconstruction")

    kinds, headers = classify_table_roles(sel)

    def caption_for(line_start: int, section_line: int | None) -> str:
        """Nearest meaningful atlas line above the table (stops at the section heading)."""
        floor = (section_line or 1) - 1
        j = line_start - 2  # 0-based index of the line above
        while j >= floor and j >= 0:
            raw = atlas_lines[j].decode("utf-8", errors="replace").strip()
            if raw and not raw.startswith("|") and not raw.lstrip().startswith("#"):
                cap = norm_cell(raw)
                if cap:
                    return cap[:140]
            j -= 1
        return subj["sec_short"]

    # ── Pass 2: build one draft claim per eligible unit.
    group_id = batch["group_id"]
    claims = []
    side_units = []
    skipped = []
    ordinal = 0
    for i, r in enumerate(sel):
        uid = r["source_unit_id"]
        role = kinds.get(uid)
        # A034 window exclusion — checked FIRST so every window unit is explicitly
        # accounted for with this reason (deterministic predicate, same as the
        # validator: 7310 <= line_start <= 7369). See A034_WINDOW note above.
        if A034_WINDOW[0] <= r["line_start"] <= A034_WINDOW[1]:
            skipped.append({"source_unit_id": uid, "reason": "a034-window (lines 7310-7369; anchor A034 routed in vnext C1; excluded from Y5 queue per coverage plan §3.2)"})
            continue
        if r["kind"] == "heading-candidate":
            skipped.append({"source_unit_id": uid, "reason": "heading-label-unit"})
            continue
        if role == "separator":
            skipped.append({"source_unit_id": uid, "reason": "table-separator"})
            continue
        tierb_bucket = None
        if args.tierb:
            # X5 second pass: every unit in sel is tier-b-ambiguous by
            # construction; eligibility is the claimable content shape.
            tierb_bucket = tierb_shape(r["text"])
            if tierb_bucket not in TIERB_CLAIMABLE:
                skipped.append({"source_unit_id": uid,
                                "reason": f"tierb-residual-{tierb_bucket} "
                                          "(no claimable technical shape; stays deferred)"})
                continue
        elif not r["factual_marker"]:
            skipped.append({"source_unit_id": uid, "reason": "tier-b-ambiguous (no factual marker; deferred to reconciliation)"})
            continue

        if args.tierb:
            sec = r.get("section_title") or subj["sec_short"]
            prefix = f"Legacy FFX structure atlas (2026-08-17 snapshot), section {sec}: "
        else:
            prefix = f"Legacy FFX structure atlas (2026-08-17 snapshot), {subj['sec_short']}: "
        if role in ("header", "data"):
            cap = caption_for(r["line_start"], r["section_line"])
            if role == "header":
                fact = f"the table “{cap}” defines columns: " + ", ".join(c for c in table_cells(r["text"]) if c)
            else:
                hdr = headers[i]
                cells = table_cells(r["text"])
                if hdr:
                    pairs = [f"{h}={v}" for h, v in zip(hdr, cells) if v]
                    fact = f"the table “{cap}” records: " + "; ".join(pairs)
                else:
                    fact = f"the table “{cap}” records a row: " + "; ".join(c for c in cells if c)
        else:
            fact = norm_fact(r["text"])
        if not fact.strip():
            skipped.append({"source_unit_id": uid, "reason": "empty-fact-after-normalization"})
            continue
        fact, truncated = truncate(fact)
        claim_text = prefix + fact

        ordinal += 1
        fmt = subj["format_id"]
        if batch["batch_id"] == "y5-b01-menu-formats":
            m = MENU_FORMAT_RE.search(r["text"])
            if m:
                fmt = m.group(1).lower()
        claim_id = f"{group_id}-ffx-pc-{fmt}-{ordinal:02d}"
        claim = {
            "claim_id": claim_id,
            "claim_group_id": group_id,
            "source_relation_ids": [],
            "claim_text": claim_text,
            "claim_text_sha256": hashlib.sha256(claim_text.encode("utf-8")).hexdigest().upper(),
            "subject": {
                "scope_id": "scope-" + draft_sha("draft-y5-scope|" + claim_id),
                "kind": "exact",
                "format_id": fmt,
                "game": "ffx",
                "platform": "pc",
                "region_or_build": "legacy-atlas-snapshot-2026-08-17",
            },
            "claimed_boundary": {
                "boundary_id": "boundary-" + draft_sha("draft-y5-boundary|" + claim_id),
                "kind": "declared-sample-set",
                "exact_artifact_sha256": None,
                "artifact_sha256s": [EXPECTED_SOURCE_SHA256],
                "sample_ids": [f"legacy-atlas-20260817-L{r['line_start']}"],
                "byte_ranges": [],
                "procedure_id": None,
                "blocker_kind": None,
                "required_authority_or_asset_id": None,
                "statement": "Declared sample set containing 1 item(s).",
            },
            "required_proof_state": None,
            "evidence_links": [],
            "confidence": "low",
            "notes": DRAFT_NOTES,
        }
        claims.append(claim)
        side_unit = {
            "claim_id": claim_id,
            "source_unit_id": uid,
            "line_start": r["line_start"],
            "line_end": r["line_end"],
            "kind": r["kind"],
            "table_role": role,
            "derivation": "table-header-columns" if role == "header" else
                          ("table-row-pairs" if role == "data" else "normalized-unit-text"),
            "truncated": truncated,
            "scope_id_basis": "draft-y5-scope|" + claim_id,
            "boundary_id_basis": "draft-y5-boundary|" + claim_id,
        }
        if args.tierb:
            side_unit["tierb_shape"] = tierb_bucket
        side_units.append(side_unit)

    group = {
        "claim_group_id": group_id,
        "title": batch["theme"],
        "children": [{"target_id": c["claim_id"], "target_kind": "format-claim"} for c in claims],
    }
    doc = {
        "schema_version": {"major": 1, "minor": 0},
        "groups": [group],
        "anchors": [],
        "snapshots": [],
        "claims": claims,
        "deferred_atlas_facts": [],
        "relations": [],
        "wording_atoms": [],
    }
    out_dir = os.path.join(art, "drafts")
    os.makedirs(out_dir, exist_ok=True)
    base = os.path.join(out_dir, f"y5-draft-claims-{batch['batch_id']}")
    with open(base + ".json", "w", encoding="utf-8") as fh:
        json.dump(doc, fh, ensure_ascii=False, indent=1)
    side = {
        "document_kind": "y5-draft sidecar (derivation map; not part of the accepted claim shape)",
        "batch_id": batch["batch_id"],
        "claim_group_id": group_id,
        "status": "CANDIDATE DRAFT — nothing here is accepted or validated",
        "queue_basis": batches_doc["method"],
        "claims_derived": len(claims),
        "units_skipped": skipped,
        "units": side_units,
    }
    with open(base + ".units.json", "w", encoding="utf-8") as fh:
        json.dump(side, fh, ensure_ascii=False, indent=1)

    print(f"{batch['batch_id']}: {len(claims)} draft claims ({len(skipped)} units skipped) -> {base}.json")
    return 0


if __name__ == "__main__":
    sys.exit(main())
