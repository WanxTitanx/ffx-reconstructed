#!/usr/bin/env python3
# ── X5-REDERIVE step 3 — re-derive the vnext_required separation inside the 6 semantic lots ──
# Ground truth for LOT SIZES: recovered rules.py (sha 8def03f4) re-executed PASS —
#   A code/data 1595 | B factual-runtime 1187 | C factual-format 1318 |
#   D ambiguous 1830 | E editorial 438 | F factual-meta 231   (total 6599)
# Ground truth for PER-LOT vnext counts: recovered ledger.md (verboo ac9fda8ead75ff97@v3,
# entry 2026-09-08 ~07:40Z "T11-07 RODADA COMPLETA"):
#   A 1595: 100% exclusive  -> vnext 0
#   B 1187: 750 exclusive + 435 vnext + 2 binding
#   C 1318: 178 exclusive + 1138 vnext + 2 binding
#   D 1830: 596 exclusive + 1234 vnext + 0 binding
#   E 438 : exclusive/vnext (not itemized -> derived: 68 vnext, 370 exclusive)
#   F 231 : 190 exclusive + 40 vnext + 1 binding (provenance)
#   TOTAL vnext = 435+1138+1234+68+40 = 2915 (arbiter: reviewer-a routing_c17 vnext_unrouted)
# The per-unit identity inside each lot was an LLM semantic decision (lost); here it is
# re-derived DETERMINISTICALLY by a factual-payload score (same signal vocabulary as the
# recovered rules.py R30/R40 regexes + the Y5 tier-A factual marker). Count per lot is
# exact BY CONSTRUCTION; unit identity is the best deterministic approximation.
import json
import re
from collections import Counter
from pathlib import Path

WORK = Path("/home/wanderson/Documents/ffx-editor-main/work/_x5_rederive")
REPO = "/home/wanderson/Documents/ffx-editor-main"
OUTDIR = Path("/mnt/nvme-samsung/ffx-task-artifacts/glm-structures-exec-69f2d8/rederived")

# per-lot vnext targets from the recovered ledger (see header)
VNEXT_TARGET = {"code/data": 0, "factual-runtime": 435, "factual-format": 1138,
                "ambiguous": 1234, "editorial": 68, "factual-meta": 40}
BINDING_TARGET = {"factual-runtime": 2, "factual-format": 2, "factual-meta": 1}
# semantic bindings (from lots, not a034) — identified from the accepted candidate:
# lines 411 (F provenance), 645 (B), 7316 (B/C), 8352 (C), 8403 (C) — lots resolved below
SEMANTIC_BINDING_IDS = None  # filled from candidate

LOT_BY_CLS = {"code/data": "A", "factual-runtime": "B", "factual-format": "C",
              "ambiguous": "D", "editorial": "E", "factual-meta": "F"}

# ── score: factual-payload strength of a unit text (deterministic) ──
RE_ADDR = re.compile(r"0x[0-9A-Fa-f]{5,}|@0x[0-9A-Fa-f]+")
RE_SYMBOL = re.compile(r"\bsub_[0-9a-f]{4,}\b|\bffx_[a-z0-9_]{3,}\b", re.I)
RE_OFF = re.compile(r"\+0x[0-9a-f]{1,4}\b")
RE_HEXSMALL = re.compile(r"\b0x[0-9A-Fa-f]{1,4}\b")
RE_BYTESIZE = re.compile(r"(?i)\b\d+\s*(?:b|kb|mb|bytes?|bpp)\b")
RE_MARKER = re.compile(r"0x[0-9A-Fa-f]|\b\d+\s*(?:b|kb|mb)\b|\||`")

# markdown table separator rows (|---|---|...) are STRUCTURAL, never claim-bearing —
# the original Y5 batcher independently skipped them ("3 table-separator" excluded in
# b06, y5-drafts-REPORT) and 239 of them sit in lot D near the score cut. They can
# never be vnext; excluded from selection deterministically.
RE_TABLE_SEP = re.compile(r"^\|?(?:\s*:?-{2,}:?\s*\|)+\s*:?\s*$")

# reuse rule vocabulary from the recovered classifier
src = (WORK / "x5_semtriage_rules.py").read_text()
head = src.split("PENDING_CLASS_BY_KIND")[0]
ns = {}
exec(compile(head, "x5rules_head", "exec"), ns)
RE_RUNTIME, RE_FORMAT, RE_META, RE_EDITORIAL = ns["RE_RUNTIME"], ns["RE_FORMAT"], ns["RE_META"], ns["RE_EDITORIAL"]
prose_words, strip_code_spans = ns["prose_words"], ns["strip_code_spans"]


def cap(count, maximum):
    return min(count, maximum)


def score_unit(text):
    t = (text or "").strip()
    no_code = strip_code_spans(t)
    pw = prose_words(no_code)
    s = 0.0
    s += 3.0 * cap(len(RE_ADDR.findall(t)), 2)            # PS2/PC address = strongest claim signal
    s += 2.0 * cap(len(RE_SYMBOL.findall(t)), 2)          # sub_/FFX_ symbols
    s += 2.0 * cap(len(RE_OFF.findall(t)), 2)             # struct field offsets +0xNN
    s += 1.0 * cap(len(RE_RUNTIME.findall(t)), 3)         # execution vocabulary
    s += 1.0 * cap(len(RE_FORMAT.findall(t)), 4)          # format vocabulary
    s += 0.5 * cap(len(RE_META.findall(t)), 2)            # meta vocabulary
    s += 1.0 * cap(len(RE_HEXSMALL.findall(t)), 3)        # small hex constants
    s += 1.0 if RE_BYTESIZE.search(t) else 0.0            # byte sizes
    s += 1.0 if RE_MARKER.search(t) else 0.0              # Y5 tier-A factual marker proxy
    s += 0.25 * min(len(pw), 8)                           # moderate prose => redacted claim
    if RE_EDITORIAL.search(no_code):
        s -= 1.5                                          # narrative markers pull to editorial
    if len(pw) >= 10 and not (RE_ADDR.search(t) or RE_SYMBOL.search(t) or RE_OFF.search(t)):
        s -= 1.0                                          # long flowing narrative, no hard payload
    return round(s, 3)


def main():
    tri = json.loads((WORK / "semantic-triage-v1.rederived.json").read_text())
    cand = json.load(open(f"{REPO}/docs/reverse/task11/vnext/task11-review-candidate-v2-vnext.json"))
    y5 = {x["source_unit_id"]: x for x in json.load(open(f"{REPO}/artifacts/2026-09-14/y5/y5-units-reconstruction.json"))}

    binding_ids = {d["source_unit_id"] for d in cand["decisions"] if d.get("factual_bindings")}
    # CANONICAL INVARIANT (reviewer-a attestation): the vnext queue is a subset of the
    # accepted candidate's narrative pool (reason=narrative-context, no bindings). The
    # original lots pre-date the candidate, but T11-27 re-typed all vnext units to
    # editorial-context/narrative-context — so units the final review typed as
    # code-literal/malformed/etc. can never have been vnext. Restricting the selection
    # pool to narrative units enforces this invariant (239 units would otherwise leak).
    narrative_ids = {d["source_unit_id"] for d in cand["decisions"]
                     if (d.get("exclusive_decision") or {}).get("reason") == "narrative-context"}

    units = tri["units"]
    by_lot = {}
    semantic_binding_lots = Counter()
    excluded_non_narrative = Counter()
    excluded_separators = Counter()
    for u in units:
        lot = u["cls_suggested"]
        if u["id"] in binding_ids:
            semantic_binding_lots[lot] += 1
            continue  # semantic bindings consume binding slots, never vnext
        if u["id"] not in narrative_ids:
            excluded_non_narrative[lot] += 1
            continue  # canonical invariant: vnext ⊆ narrative pool
        if u["kind"] == "table-row" and RE_TABLE_SEP.match((u["text"] or "").strip().replace("\r\n", "")):
            excluded_separators[lot] += 1
            continue  # structural table separator, never claim-bearing
        by_lot.setdefault(lot, []).append(u)
    print("non-narrative pending excluded from selection pools:",
          {LOT_BY_CLS[k]: v for k, v in sorted(excluded_non_narrative.items(), key=lambda x: LOT_BY_CLS[x[0]])})
    print("table separators excluded (structural, never claim):",
          {LOT_BY_CLS[k]: v for k, v in sorted(excluded_separators.items(), key=lambda x: LOT_BY_CLS[x[0]])})

    print("semantic bindings per lot (ledger arbiter: B=2, C=2, F=1):",
          {LOT_BY_CLS[k]: v for k, v in sorted(semantic_binding_lots.items(), key=lambda x: LOT_BY_CLS[x[0]])})

    # deterministic selection: top-K by (score desc, line asc), with the DOCUMENTED
    # duplicate-of rule from the original pipeline (recovered ledger 2026-09-08 ~08:20Z:
    # 91 duplicate-of units were emitted as editorial — "DuplicateOf herda bindings da
    # origem"; none were legally routable). Deterministic echo: a unit whose raw text
    # (stripped) was already selected as vnext in an earlier line is skipped (becomes
    # editorial-duplicate) and the slot goes to the next-ranked unit.
    vnext = []
    detail = {}
    seen_texts = set()
    dup_skipped = Counter()
    for lot, pool in by_lot.items():
        K = VNEXT_TARGET[lot]
        scored = sorted(pool, key=lambda u: (-score_unit(u["text"]), u["line"], u["id"]))
        chosen = []
        for u in scored:
            if len(chosen) >= K:
                break
            key = (u["text"] or "").strip()
            if key in seen_texts:
                dup_skipped[lot] += 1
                continue
            seen_texts.add(key)
            chosen.append(u)
        vnext.extend(u["id"] for u in chosen)
        threshold = score_unit(chosen[-1]["text"]) if chosen else None
        detail[lot] = {"lot": LOT_BY_CLS[lot], "pool": len(pool), "vnext": K,
                       "duplicates_skipped": dup_skipped[lot],
                       "score_threshold": threshold}
        print(f"lot {LOT_BY_CLS[lot]} {lot:<15} pool={len(pool):>5} vnext={K:>5} "
              f"dup_skipped={dup_skipped[lot]:>3} cut=[{threshold}]")

    vnext = sorted(set(vnext))
    print("\nvnext total:", len(vnext), "(arbiter 2915)")

    # ── validations ──
    # 1. disjointness vs binding/a034/context
    assert not (set(vnext) & binding_ids), "vnext overlaps binding units!"
    # 2. distinct claim texts (arbiter: 2915 units -> 2909 distinct texts)
    texts = []
    for uid in vnext:
        x = y5[uid]
        texts.append((x["text"] or "").strip())
    distinct = len(set(texts))
    print("distinct vnext texts:", distinct, "(arbiter 2909)")
    dup_groups = Counter(texts)
    dups = {t: c for t, c in dup_groups.items() if c > 1}
    print("duplicate text groups:", len(dups), "excess units:", sum(c - 1 for c in dups.values()))

    out = {
        "document_kind": "x5-vnext-required-rederived",
        "generated": "2026-09-15",
        "lane": "FFX-STRUCTURES / X5-REDERIVE (Jarvis)",
        "provenance": {
            "method": "phase-1 + rules.py recovered & re-executed (stats PASS); per-lot vnext "
                      "counts from recovered ledger entry 2026-09-08 ~07:40Z; per-unit identity "
                      "re-derived deterministically by factual-payload score (top-K per lot, "
                      "tie-break line asc). Count exact by construction; identity = best "
                      "deterministic approximation of the lost LLM semantic decision.",
            "lot_targets": {LOT_BY_CLS[k]: {"pool": len(by_lot[k]), "vnext": v} for k, v in VNEXT_TARGET.items()},
            "inputs": {
                "atlas_units_sha256": "D67500CA1DBAA1F7F5BA84E778A5A7D985264DA4370FA0860DFBE0CD38849549",
                "atlas_md_sha256": "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7",
                "candidate_sha256": "ECF734A595A8B284E66136E8B54E811D7242627E9C8BBB3D9FC31D076E1DD875",
                "rules_py_recovered_sha256": "8def03f4d9dac02549aeda5c6ce9db2a4fdc3d7f5d5ca3e257d3f52eda37e5e8",
            },
        },
        "counts": {
            "vnext_units": len(vnext),
            "distinct_claim_texts": distinct,
            "per_lot": detail,
            "semantic_bindings_per_lot": {LOT_BY_CLS[k]: v for k, v in semantic_binding_lots.items()},
        },
        "vnext_units": [
            {"source_unit_id": uid, "lot": LOT_BY_CLS[[k for k, pool in by_lot.items()
                                                       if any(u["id"] == uid for u in pool)][0]],
             "line": y5[uid]["line_start"], "kind": y5[uid]["kind"]}
            for uid in vnext
        ],
    }
    # faster lot lookup
    lot_of = {}
    for lot, pool in by_lot.items():
        for u in pool:
            lot_of[u["id"]] = LOT_BY_CLS[lot]
    out["vnext_units"] = [{"source_unit_id": uid, "lot": lot_of[uid],
                           "line": y5[uid]["line_start"], "kind": y5[uid]["kind"]}
                          for uid in vnext]
    OUTDIR.mkdir(parents=True, exist_ok=True)
    (OUTDIR / "vnext_required.rederived.json").write_text(json.dumps(out, ensure_ascii=False, indent=1))
    print(f"\nwritten: {OUTDIR}/vnext_required.rederived.json")


if __name__ == "__main__":
    main()
