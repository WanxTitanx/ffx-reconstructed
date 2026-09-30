#!/usr/bin/env python3
# ── T11-07 semantic triage v1 (deterministic first-pass classifier) ──
# X5-REDERIVE copy of /mnt/nvme-samsung/ffx-task-artifacts/t1107-semtriage-v1/rules.py.recovered
# (sha256 8def03f4d9dac02549aeda5c6ce9db2a4fdc3d7f5d5ca3e257d3f52eda37e5e8 — bytes-original
# from zcode subagent ed5298ea artifacts). ONLY the MATRIX/OUTDIR paths changed: they pointed
# at the deleted glm-structures-exec-69f2d8 dir; here they point at the re-derived work matrix
# produced by x5_phase1.py (stats validated PASS against all phase-1 arbiters).
# Purpose: draft semantic classification of the pending units of the T11-07 work
# matrix (cls == 'pending-semantic-review') into the 6 triage buckets, using
# ONLY re-executable regex/keyword rules (first match wins, fixed priority).
# WHY: 6,599 pending units cannot be hand-reviewed in one pass; this script is
# a PRIORITIZATION DRAFT, never an accepted semantic review (see RESULT.md).
# Usage: python3 x5_semtriage_rules.py

import json
import random
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

MATRIX = Path("/home/wanderson/Documents/ffx-editor-main/work/_x5_rederive/work-matrix.rederived.json")
OUTDIR = Path("/home/wanderson/Documents/ffx-editor-main/work/_x5_rederive")
SEED = 20260905
SAMPLE_N = 20
TEXT_CAP = 180  # matrix texts are truncated to ~180 chars; near-cap => ambiguity risk

# ── Rule regexes (priority order, first match wins) ──
RE_HEX = re.compile(r"0x[0-9A-Fa-f]{2,}")
RE_ADDR = re.compile(r"0x[0-9A-Fa-f]{5,}|@0x[0-9A-Fa-f]+")  # PS2 addresses are 6-8 hex digits
RE_BYTE_RUN = re.compile(r"\b[0-9A-F]{2}(?:\s+[0-9A-F]{2}){2,}\b")
RE_NUM = re.compile(r"\b\d{2,}\b")
RE_FNAME = re.compile(r"[A-Za-z0-9_.\-]+\.(?:bin|dat|pak|exe|dll|md|py|ts|js|json|phyre|fsh|tm2|img|iso|wav|ogg|txt|ha|db|c|cpp|h)\b", re.I)
RE_PATH = re.compile(r"(?:[A-Za-z]:\\|[a-z]+://|\.\./|(?<=\s)/)[^\s`|]+", re.I)

RE_RUNTIME = re.compile(
    r"(?i)(?:"
    r"0x[0-9a-f]{5,}|@0x[0-9a-f]+|\bsub_[0-9a-f]{4,}\b|\bffx_[a-z0-9_]{3,}\b|"
    r"\b(?:function|fun[cç][ãa]o|funcao|fun[çc][õo]es|call|calls?|cham\w*|invoca\w*|"
    r"returns?|retorna\w*|register|registrador\w*|runtime|engine|execut\w*|thread|"
    r"callback|handler|handlers?|opcode|opcodes?|dispatcher|pool|aloca\w*|alloc\w*|"
    r"desaloca\w*|free[sd]?\b|write[sd]?\b\s*(?:to|em)\b|bit\b|bitmap|mask|shift|"
    r">>|<<|carrega\w*|loader|load\w*|hook|detour|patch\w*|pointer\s*chain|"
    r"fluxe?s?|flow|executa|rodando|roda\b|processa\w*|interpreta\w*)\b"
    r")"
)
RE_FORMAT = re.compile(
    r"(?i)(?:"
    r"\+0x[0-9a-f]{1,4}\b|"
    r"\b(?:offset|offsets?|bytes?|dxt[1-5]?|bc[1-5]|codec|header|headers?|magic|"
    r"mips?\b|mipmap\w*|texture|textura\w*|pixel\w*|formato|formats?|format\b|"
    r"layout|stride|struct|structs?|campo|campos?|field|fields?|u8\b|u16\b|u32\b|"
    r"u64\b|i8\b|i16\b|i32\b|i64\b|f32\b|float|double|char\b|little.endian|big.endian|"
    r"\ble\b|\bbe\b|chunk|chunks?|section|se[çc][ãa]o|se[çc][õo]es|compress\w*|"
    r"descompress\w*|palette|paleta\w*|rgba?\b|bgra?\b|clut|vertex|vertexes|"
    r"v[ée]rtice\w*|mesh|triangle\w*|bloco|bloco?s?|blocks?\b|tamanho|sizes?|size\b|"
    r"width|height|resolu[çc][ãa]o|record|records?|entrada\w*|entradas?|entry|"
    r"entries|array|tabela|tabelas|table\b|indice|índice|índices|glyph\w*|"
    r"encoding|encode|decode|wides?|scanline\w*|swizzle\w*|padding|pad\b|align\w*|"
    r"str\[\d+\]|char\[\d+\]|\bns?\b\s*bytes)"
    r")\b"
)
RE_META = re.compile(
    r"(?i)\b(?:arquivos?|files?|pastas?|folders?|directory|directories|diret[óo]ri\w*|"
    r"dir\b|dirs\b|count|contagem|conta\b|total|lista\w*|listagem|tools?|ferramentas?|"
    r"tool\b|parser|parsers?|parsing|writer|writers?|exists?|existem|exist\w*|"
    r"cobertura|coverage|provenance|proced[êe]ncia|proveni\w*|fontes?|sources?|"
    r"cr[ée]ditos?|credits?|extra[íi]d\w*|extracted|extra[çc][õo]es|dump|dumps?|"
    r"docs\b|documenta[çc][ãa]o|subagentes?|subagent|revers\w*|ida\b|ghidra|"
    # NOTE (X5): the recovered file has 'x := r"vers[ãa]o|...|sets? total)"' followed by
    # 'r")\b"' — that exact form does not parse (SyntaxError; 'x :=' and the stray ')\b'
    # are replay/recovery artifacts). Two balanced interpretations were tested against
    # the RESULT.md bucket counts (1595/1187/1318/1830/438/231): WITH a trailing '\b'
    # meta=210 (FAIL), WITHOUT it meta=231 (EXACT — flips exactly 21 units: 14
    # R90-ambiguous + 7 R60-editorial). The no-trailing-b form is therefore the
    # functionally-original regex:
    r"vers[ãa]o|version|builds?|release\w*|reposit[óo]ri\w*|repo\b|sets? total)"
)
RE_EDITORIAL = re.compile(
    r"(?i)\b(?:describes?|descreve\w*|descrev\w*|note\b|nota\b|notes?|see\b|ver\b|"
    r"veja|refer\w*|refer[êe]ncia|acima|above|below|abaixo|chapter|cap[íi]tulo|"
    r"neste|nesta|a seguir|resumo|summary|introdu[çc][ãa]o|conclus[ãa]o|contexto|"
    r"explica\w*|detalhe\w*|vis[ãa]o geral|overview|guia|compreens[ãa]o|"
    r"hist[óo]ria|breve|exemplo\b|exemplos?)\b"
)

# Words that are technical jargon, not narrative prose (for prose counting)
TECH_STOPWORDS = {
    "offset", "offsets", "bytes", "byte", "data", "dados", "hex", "value", "valor",
    "valores", "nome", "names", "name", "type", "tipo", "tipos", "size", "tamanho",
    "total", "count", "index", "indice", "value", "struct", "campo", "campos",
    "magic", "header", "format", "formato", "layout", "block", "bloco", "registros",
    "records", "entrada", "entry", "entries", "arquivo", "arquivos", "file", "files",
    "pasta", "pastas", "lista", "lista", "tool", "ferramenta", "parser", "writer",
    "engine", "runtime", "funcao", "função", "funções", "retorno", "returns",
    "textura", "texture", "pixel", "paleta", "vertex", "tabela", "tabelas",
}
RE_WORD = re.compile(r"[A-Za-zÀ-ÿ]{3,}")
RE_CAMEL = re.compile(r"[a-zà-ÿ][A-Z]")


def prose_words(text_no_code):
    """Count narrative words: alphabetic tokens >=3 chars, not jargon, not
    CamelCase identifiers, not hex-ish (pure A-F handled by context)."""
    out = []
    for w in RE_WORD.findall(text_no_code):
        if w.lower() in TECH_STOPWORDS:
            continue
        # CamelCase token (e.g. ComputeFormationAnchorTransform) = identifier
        if RE_CAMEL.search(w):
            continue
        out.append(w)
    return out


def strip_code_spans(t):
    return re.sub(r"`[^`]*`", " ", t)


def classify(unit):
    """Return (cls_suggested, rule_id) for one unit. Deterministic."""
    t = (unit.get("text") or "").strip()
    kind = unit.get("kind", "")
    no_code = strip_code_spans(t)

    # R10 code/data — raw data cells/lines: hex/nums/path/fname signal AND almost
    # no narrative prose (<=1 prose word).
    has_data_signal = bool(
        RE_HEX.search(t) or RE_BYTE_RUN.search(t) or RE_NUM.search(t)
        or RE_FNAME.search(t) or RE_PATH.search(t)
    )
    if has_data_signal and len(prose_words(no_code)) <= 1:
        return "code/data", "R10-code-data"

    # R20 editorial table header — table row whose every cell is a short
    # alphabetic label, no digits (e.g. "| Valor | Nome | Valor | Nome |").
    if kind == "table-row" and t.count("|") >= 2:
        cells = [c.strip().strip("`") for c in t.strip().strip("|").split("|")]
        cells = [c for c in cells if c]
        if (
            cells
            and len(cells) <= 12
            and all(
                re.fullmatch(r"[A-Za-zÀ-ÿ_][A-Za-zÀ-ÿ_ /.-]{0,29}", c)
                for c in cells
            )
        ):
            return "editorial", "R20-table-header-label"

    # R30 factual-runtime — addresses (0x5+ hex), FFX_/sub_ symbols, execution
    # vocabulary. Addresses with 5+ hex digits are PS2 memory addresses, while
    # file offsets are typically 1-4 hex digits (kept for R40).
    if RE_RUNTIME.search(t):
        return "factual-runtime", "R30-runtime"

    # R40 factual-format — file/format structure vocabulary.
    if RE_FORMAT.search(t):
        return "factual-format", "R40-format"

    # R50 factual-meta — coverage/tools/provenance vocabulary.
    if RE_META.search(t):
        return "factual-meta", "R50-meta"

    # R60 editorial — explicit narrative markers, or long flowing prose with
    # zero technical signals.
    pw = prose_words(no_code)
    if RE_EDITORIAL.search(no_code) or (kind == "paragraph" and len(pw) >= 6):
        return "editorial", "R60-editorial"

    # R90 ambiguous fallback.
    return "ambiguous", "R90-fallback"


PENDING_CLASS_BY_KIND = {
    "paragraph": "pending-paragraph",
    "table-row": "pending-table-row",
    "list-item": "pending-list-item",
}


def run_triage():
    data = json.loads(MATRIX.read_text(encoding="utf-8"))
    pending = [r for r in data["rows"] if r.get("cls", "").startswith("pending")]

    units = []
    rule_counts = Counter()
    cross = defaultdict(Counter)
    for r in sorted(pending, key=lambda x: x["id"]):
        cls_s, rule = classify(r)
        rule_counts[rule] += 1
        pc = PENDING_CLASS_BY_KIND.get(r["kind"], f"pending-{r['kind']}")
        cross[pc][cls_s] += 1
        units.append(
            {
                "id": r["id"],
                "kind": r["kind"],
                "line": r["line"],
                "pending_class": pc,
                "cls_suggested": cls_s,
                "rule": rule,
                "truncated_likely": len(r.get("text") or "") >= TEXT_CAP - 2,
                "text": r.get("text"),
            }
        )

    out = {
        "meta": {
            "task": "T11-07 semantic triage v1 (first pass, deterministic draft) — X5-REDERIVE re-execution 2026-09-15",
            "generated": "re-executed 2026-09-15 from rules.py sha 8def03f4 (recovered)",
            "source_matrix": str(MATRIX),
            "source_cls": "pending-semantic-review",
            "units_classified": len(units),
            "note": "Heuristic draft for prioritization only; NOT an accepted semantic review. "
                    "Texts truncated at ~180 chars may bias toward ambiguous.",
            "sample_seed": SEED,
        },
        "counts_by_cls_suggested": dict(Counter(u["cls_suggested"] for u in units)),
        "counts_by_pending_class": dict(Counter(u["pending_class"] for u in units)),
        "cross_tab": {pc: dict(c) for pc, c in cross.items()},
        "units": units,
    }
    (OUTDIR / "semantic-triage-v1.rederived.json").write_text(
        json.dumps(out, ensure_ascii=False, indent=1), encoding="utf-8"
    )
    print("units:", len(units))
    print("by cls_suggested:", dict(Counter(u["cls_suggested"] for u in units)))
    return out


if __name__ == "__main__":
    run_triage()
