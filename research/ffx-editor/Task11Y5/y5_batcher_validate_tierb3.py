#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""y5_batcher_validate_tierb3.py — validate the X5 tier-B THIRD-pass draft
(y5-b25-tierb-thirdpass, 163 in-queue residual units) with the same check
battery as research_tools/Task11Y5/y5_batcher_validate_tierb.py, adapted to the
pass-3 universe.

Pass-3 universe (recomputed live, not trusted from the sidecar):
  b24 sidecar units_skipped(reason startswith "tierb-residual-")
    ∩ artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json
  = 163 source units.

Checks:
  1. claim_text_sha256 recomputed = sha256(claim_text utf-8, uppercase hex).
  2. Physical byte-slice anchor vs PINNED atlas (F5439414…) through
     atlas-source-units.json raw_sha256.
  3. Sidecar line ranges match atlas-source-units.
  4. Claim field names/order identical to seed-claims-v6-vnext.json.
  5. Honesty invariants: DRAFT notes, confidence low, evidence_links [],
     boundary artifact_sha256s == pinned atlas sha.
  6. Universe accounting: every one of the 163 in-queue residual units is
     either drafted or skipped-with-reason; no extras, no doubles.
  7. claim_ids unique in batch AND globally vs all 23 official batches + b24.
  8. a034-window units drafted == 0.
  9. Every drafted unit carries tierb_shape in a residual bucket
     (prose/lead-in/bold-label/doc-meta/doc-ref/hrule) — the pass-3 claimable
     set IS the pass-2 residual set, restricted to in-queue units.

--candidate <path> : promotion gate, same contract as the b24 gate — claims
copied VERBATIM, 1 anchor + 1 "legacy-trace" relation per claim, anchor
byte-slices physically verified against the pinned atlas, covered_units
consistent with the sidecar, queue_reconciliation honestly recomputed against
the re-derived queue, namespace hygiene (YA5-R###/YSR-R### must not collide
with wave-1 YA5-###/YSR### or b24 YA5-T###/YSR-T###).

ATLAS PIN NOTE (2026-09-16): the working-tree atlas was link-rewritten by
commit ab0ce2d0 and no longer matches the chain pin F5439414…. Byte-slice
verification therefore runs against the pinned copy extracted from git blob
ab0ce2d0~1 (sha-verified, byte-identical to the committed copy
artifacts/2026-09-14/qa-win/FFX_STRUCTURE_COMPLETE_2026-08-17.md).
"""
import glob
import hashlib
import json
import os
import sys

REPO = "/home/wanderson/Documents/ffx-editor-main"
ART = f"{REPO}/work/_x5_tierb3"                        # pass-3 artifacts
PRIOR_ART = f"{REPO}/artifacts/2026-09-14/y5"          # b01..b23 + b24 drafts
ATLAS_PATH = f"{ART}/pins/FFX_STRUCTURE_COMPLETE_2026-08-17.F5439414.md"
ATLAS_REL = "docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md"
ATLAS_SHA = "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7"
SEED = f"{REPO}/Utilities/FFXResearchTools/claims/seed-claims-v6-vnext.json"
DRAFT_NOTES = "DRAFT y5 candidate — NOT accepted; pending X/Y/Z review cycle"
B25 = "y5-b25-tierb-thirdpass"
B24 = "y5-b24-tierb-secondpass"
QUEUE = f"{REPO}/artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json"
RESIDUAL_BUCKETS = {"prose", "lead-in", "bold-label", "doc-meta", "doc-ref",
                    "hrule"}
SEED_TOP_KEYS = ["schema_version", "candidate_vector_sha256",
                 "review_basis_sha256", "anchors", "snapshots", "relations",
                 "wording_atoms", "claims"]


def load_universe():
    """Recompute the pass-3 universe: b24 residual skips that are in-queue."""
    side24 = json.load(open(
        f"{PRIOR_ART}/drafts/y5-draft-claims-{B24}.units.json"))
    qids = {u["source_unit_id"] for u in
            json.load(open(QUEUE))["vnext_units"]}
    return {s["source_unit_id"] for s in side24["units_skipped"]
            if s["reason"].startswith("tierb-residual-")
            and s["source_unit_id"] in qids}, qids


def validate_candidate(path: str, doc: dict, side: dict, su: dict,
                       atlas: bytes, seed_field_order: list,
                       universe: set, qids: set) -> int:
    """Promotion gate: candidate file must be a faithful, honestly-labeled
    promotion of the b25 draft (claims verbatim + verified anchors/relations +
    complete extensions). Exit 0 = eligible for the X/Y/Z review cycle."""
    fails = []
    cand = json.load(open(path))
    n = len(doc["claims"])

    # 1. top-level shape == accepted corpus + exactly one marked extension
    if list(cand.keys()) != SEED_TOP_KEYS + ["y5_extensions"]:
        fails.append(f"top-level key drift: {list(cand.keys())}")

    # 2. claims verbatim (deep equality, same order) + shape still seed-grade
    cc = cand.get("claims", [])
    if len(cc) != n or any(cc[i] != doc["claims"][i] for i in
                           range(min(len(cc), n))):
        fails.append("claims not verbatim-equal to draft (count or content)")
    else:
        bad = sum(1 for c in cc if list(c.keys()) != seed_field_order)
        if bad:
            fails.append(f"{bad} claims with field-order drift in candidate")

    # 3. anchors: 1:1, correct pins, physical byte-slice vs pinned atlas
    anchors = cand.get("anchors", [])
    rels = cand.get("relations", [])
    if len(anchors) != n:
        fails.append(f"anchors {len(anchors)} != claims {n}")
    if len(rels) != n:
        fails.append(f"relations {len(rels)} != claims {n}")
    by_claim = {u["claim_id"]: u for u in side["units"]}
    anchor_ids, rel_ok = set(), 0
    for i, c in enumerate(doc["claims"]):
        a = anchors[i] if i < len(anchors) else None
        r = rels[i] if i < len(rels) else None
        u = by_claim[c["claim_id"]]
        src = su[u["source_unit_id"]]
        if a is None:
            continue
        anchor_ids.add(a.get("anchor_id"))
        if (a.get("logical_path") != ATLAS_REL
                or a.get("source_sha256") != ATLAS_SHA
                or (a.get("line_start"), a.get("line_end"))
                != (src["line_start"], src["line_end"])
                or a.get("excerpt_sha256") != src["raw_sha256"]):
            fails.append(f"anchor mismatch claim {c['claim_id']}")
            continue
        sl = atlas[src["byte_start"]:src["byte_start"] + src["byte_length"]]
        if hashlib.sha256(sl).hexdigest().upper() != src["raw_sha256"]:
            fails.append(f"anchor byte-slice sha mismatch {a['anchor_id']}")
            continue
        if (r and r.get("claim_id") == c["claim_id"]
                and r.get("anchor_id") == a["anchor_id"]
                and r.get("relation") == "legacy-trace"):
            rel_ok += 1
        else:
            fails.append(f"relation mismatch claim {c['claim_id']}")
    if len(anchor_ids) != len(anchors):
        fails.append("anchor ids not unique")

    # 4. extensions: honesty + completeness
    ext = cand.get("y5_extensions", {})
    if "CANDIDATO" not in str(ext.get("status", "")) \
            or "NOT accepted" not in str(ext.get("status", "")):
        fails.append("candidate status does not declare CANDIDATE/not-accepted")
    cov = ext.get("covered_units", [])
    if len(cov) != n or {x["claim_id"] for x in cov} != set(by_claim):
        fails.append("covered_units incomplete vs sidecar")
    qr = ext.get("queue_reconciliation", {})
    if qids:
        inq = sum(1 for u in side["units"] if u["source_unit_id"] in qids)
        if qr.get("drafted_units_in_queue") != inq:
            fails.append(f"queue_reconciliation: file says "
                         f"{qr.get('drafted_units_in_queue')} in-queue, "
                         f"recomputed {inq}")
        resid = sum(1 for s in side["units_skipped"]
                    if s["source_unit_id"] in qids)
        if qr.get("residual_skipped_units_in_queue") != resid:
            fails.append(f"queue_reconciliation: residual in-queue file="
                         f"{qr.get('residual_skipped_units_in_queue')} "
                         f"recomputed={resid}")
        if qr.get("pass3_universe_size") != len(universe):
            fails.append(f"queue_reconciliation: pass3_universe file="
                         f"{qr.get('pass3_universe_size')} "
                         f"recomputed={len(universe)}")

    # 5. namespace hygiene: pass-3 ids must not collide with wave-1
    #    YA5-###/YSR### or b24 YA5-T###/YSR-T### — reserved prefix is
    #    YA5-R###/YSR-R###
    for a in anchors:
        aid = str(a.get("anchor_id", ""))
        if not aid.startswith("YA5-R"):
            fails.append(f"anchor id outside pass-3 namespace: {aid}")
            break
    for r in rels:
        rid = str(r.get("relation_id", ""))
        if not rid.startswith("YSR-R"):
            fails.append(f"relation id outside pass-3 namespace: {rid}")
            break

    ok = not fails
    print(f"[{'PASS' if ok else 'FAIL'}][tierb3-promotion] "
          f"{os.path.basename(path)}: claims_verbatim={n}/{n} "
          f"anchors_ok+slice={rel_ok}/{n} anchors={len(anchors)} "
          f"relations={len(rels)} "
          f"extensions={'ok' if ext else 'MISSING'}")
    for f_ in fails[:15]:
        print(f"       FAIL-DETAIL: {f_}")
    return 0 if ok else 1


def main() -> int:
    cand_path = None
    argv = sys.argv[1:]
    if "--candidate" in argv:
        i = argv.index("--candidate")
        if i + 1 >= len(argv):
            print("FATAL: --candidate requires a path")
            return 2
        cand_path = argv[i + 1]
    atlas = open(ATLAS_PATH, "rb").read()
    if hashlib.sha256(atlas).hexdigest().upper() != ATLAS_SHA:
        print("FATAL: pinned atlas sha mismatch")
        return 2
    su = {u["source_unit_id"]: u for u in json.load(
        open(f"{REPO}/Utilities/FFXResearchTools/Claims/atlas-source-units.json")
    )["source_units"]}
    seed_field_order = list(json.load(open(SEED))["claims"][0].keys())
    universe, qids = load_universe()

    doc = json.load(open(f"{ART}/drafts/y5-draft-claims-{B25}.json"))
    side = json.load(open(f"{ART}/drafts/y5-draft-claims-{B25}.units.json"))

    fails = []
    n = len(doc["claims"])
    sha_ok = slice_ok = shape_ok = honesty_ok = lines_ok = 0
    ids = set()
    for c in doc["claims"]:
        if hashlib.sha256(c["claim_text"].encode("utf-8")).hexdigest().upper() == c["claim_text_sha256"]:
            sha_ok += 1
        else:
            fails.append(f"sha256 mismatch {c['claim_id']}")
        rec = next((u for u in side["units"] if u["claim_id"] == c["claim_id"]), None)
        if rec is None:
            fails.append(f"no sidecar unit for {c['claim_id']}")
            continue
        u = su.get(rec["source_unit_id"])
        if u is None:
            fails.append(f"unknown source unit {rec['source_unit_id']}")
            continue
        sl = atlas[u["byte_start"]:u["byte_start"] + u["byte_length"]]
        if hashlib.sha256(sl).hexdigest().upper() == u["raw_sha256"]:
            slice_ok += 1
        else:
            fails.append(f"byte-slice sha mismatch {rec['source_unit_id']}")
        if (u["line_start"], u["line_end"]) == (rec["line_start"], rec["line_end"]):
            lines_ok += 1
        else:
            fails.append(f"line range mismatch {rec['source_unit_id']}")
        if list(c.keys()) == seed_field_order:
            shape_ok += 1
        else:
            fails.append(f"field order drift {c['claim_id']}")
        if (c["notes"] == DRAFT_NOTES and c["confidence"] == "low"
                and c["evidence_links"] == []
                and c["claimed_boundary"]["artifact_sha256s"] == [ATLAS_SHA]):
            honesty_ok += 1
        else:
            fails.append(f"honesty invariant fail {c['claim_id']}")
        ids.add(c["claim_id"])

    # global uniqueness vs prior 23 batches + b24 (all published drafts)
    prior_ids = set()
    for f in glob.glob(f"{PRIOR_ART}/drafts/y5-draft-claims-y5-b*.json"):
        if f.endswith(".units.json"):
            continue
        for c in json.load(open(f))["claims"]:
            prior_ids.add(c["claim_id"])
    dup_vs_prior = len(ids & prior_ids)

    # universe accounting: the 163 in-queue residual units
    drafted = {u["source_unit_id"] for u in side["units"]}
    skipped = {s["source_unit_id"] for s in side["units_skipped"]}
    unaccounted = universe - drafted - skipped
    extras = (drafted | skipped) - universe
    double = drafted & skipped
    skip_no_reason = [s for s in side["units_skipped"] if not s.get("reason")]
    a034_drafted = sum(1 for u in side["units"] if 7310 <= u["line_start"] <= 7369)
    bad_shape = [u["claim_id"] for u in side["units"]
                 if u.get("tierb_shape") not in RESIDUAL_BUCKETS]
    dup_texts = {}
    for c in doc["claims"]:
        dup_texts.setdefault(c["claim_text"], []).append(c["claim_id"])
    dup_texts = {t: i for t, i in dup_texts.items() if len(i) > 1}

    ok = (sha_ok == n and slice_ok == n and shape_ok == n and honesty_ok == n
          and lines_ok == n and len(ids) == n and dup_vs_prior == 0
          and not unaccounted and not extras and not double
          and not skip_no_reason and a034_drafted == 0 and not bad_shape
          and side["claims_derived"] == n)
    print(f"[{'PASS' if ok else 'FAIL'}][tierb3] {B25}: claims={n} "
          f"sha={sha_ok}/{n} byte_slice={slice_ok}/{n} lines={lines_ok}/{n} "
          f"shape={shape_ok}/{n} honesty={honesty_ok}/{n} ids_unique={len(ids)}/{n} "
          f"dup_vs_prior24={dup_vs_prior} universe={len(universe)} "
          f"drafted={len(drafted)} skipped={len(skipped)} "
          f"unaccounted={len(unaccounted)} extras={len(extras)} "
          f"double={len(double)} a034_window_drafted={a034_drafted} "
          f"bad_shape={len(bad_shape)}")
    for f_ in fails[:15]:
        print(f"       FAIL-DETAIL: {f_}")
    if dup_texts:
        print(f"WARN: {len(dup_texts)} claim texts produced by >1 source unit "
              f"(same WARN-only contract as the 23-batch validator)")
    hist = {}
    for s in side["units_skipped"]:
        r = s["reason"].split(" (")[0]
        hist[r] = hist.get(r, 0) + 1
    print(f"       residual skip histogram: {hist}")
    if cand_path:
        rc = validate_candidate(cand_path, doc, side, su, atlas,
                                seed_field_order, universe, qids)
        return 0 if (ok and rc == 0) else 1
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
