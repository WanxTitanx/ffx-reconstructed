#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""y5_batcher_validate_tierb.py — validate the X5 tier-B second-pass draft
(y5-b24-tierb-secondpass) with the same check battery as
research_tools/Task11Y5/y5_batcher_validate_b12b23.py, adapted for a virtual
batch (b24 is NOT in y5-batches.json; its universe is the 1,331 recorded
tier-b-ambiguous skips across b01..b23).

Checks:
  1. claim_text_sha256 recomputed = sha256(claim_text utf-8, uppercase hex).
  2. Physical byte-slice anchor vs pinned atlas (F5439414...) through
     atlas-source-units.json raw_sha256.
  3. Sidecar line ranges match atlas-source-units.
  4. Claim field names/order identical to seed-claims-v6-vnext.json.
  5. Honesty invariants: DRAFT notes, confidence low, evidence_links [],
     boundary artifact_sha256s == pinned atlas sha.
  6. Universe accounting: every one of the 1,331 recorded tier-b-ambiguous
     units is either drafted or skipped-with-reason; no extras, no doubles.
  7. claim_ids unique in batch AND globally vs all 23 prior batches.
  8. a034-window units drafted == 0.

--candidate <path> (2026-09-15, Y5-B24-ACCEPT): promotion gate. Validates a
formal candidate file built from this draft (same contract as
y5-candidate-b01b02b03.json): claims copied VERBATIM, 1 anchor + 1
"legacy-trace" relation per claim, anchor byte-slices physically verified
against the pinned atlas, covered_units consistent with the sidecar, and the
queue_reconciliation block honestly recomputed against the functionally
re-derived vnext queue (artifacts/2026-09-15/x5-rederivation/). A candidate
that fails this gate must not enter the X/Y/Z review cycle.
"""
import glob
import hashlib
import json
import os
import sys

REPO = "/home/wanderson/Documents/ffx-editor-main"
ART = "/mnt/nvme-samsung/ffx-task-artifacts/glm-structures-exec-69f2d8/y5-drafts"
ATLAS_PATH = f"{REPO}/docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md"
ATLAS_SHA = "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7"
SEED = f"{REPO}/Utilities/FFXResearchTools/claims/seed-claims-v6-vnext.json"
DRAFT_NOTES = "DRAFT y5 candidate — NOT accepted; pending X/Y/Z review cycle"
B24 = "y5-b24-tierb-secondpass"
QUEUE = f"{REPO}/artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json"
SEED_TOP_KEYS = ["schema_version", "candidate_vector_sha256",
                 "review_basis_sha256", "anchors", "snapshots", "relations",
                 "wording_atoms", "claims"]


def validate_candidate(path: str, doc: dict, side: dict, su: dict,
                       atlas: bytes, seed_field_order: list) -> int:
    """Promotion gate: candidate file must be a faithful, honestly-labeled
    promotion of the b24 draft (claims verbatim + verified anchors/relations +
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

    # 3. anchors: 1:1, correct pins, physical byte-slice vs atlas
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
        if (a.get("logical_path") !=
                "docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md"
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
    if os.path.exists(QUEUE):
        qids = {u["source_unit_id"] for u in
                json.load(open(QUEUE))["vnext_units"]}
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
    else:
        print("       WARN: rederived queue file absent — queue_reconciliation "
              "not recomputed")

    # 5. namespace hygiene: tierb anchor/relation ids must not collide with
    #    the wave-1 YA5-###/YSR### ids (tierb uses YA5-T###/YSR-T###)
    if any(str(a.get("anchor_id", "")).startswith("YA5-") and "-T" not in
           str(a.get("anchor_id")) for a in anchors):
        fails.append("anchor ids collide with wave-1 YA5-### namespace")

    ok = not fails
    print(f"[{'PASS' if ok else 'FAIL'}][tierb-promotion] {os.path.basename(path)}: "
          f"claims_verbatim={n}/{n} anchors_ok+slice={rel_ok}/{n} "
          f"anchors={len(anchors)} relations={len(rels)} "
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
        print("FATAL: atlas sha mismatch")
        return 2
    su = {u["source_unit_id"]: u for u in json.load(
        open(f"{REPO}/Utilities/FFXResearchTools/Claims/atlas-source-units.json")
    )["source_units"]}
    seed_field_order = list(json.load(open(SEED))["claims"][0].keys())

    doc = json.load(open(f"{ART}/drafts/y5-draft-claims-{B24}.json"))
    side = json.load(open(f"{ART}/drafts/y5-draft-claims-{B24}.units.json"))

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

    # global uniqueness vs prior 23 batches
    prior_ids = set()
    prior_texts = {}
    for f in glob.glob(f"{ART}/drafts/y5-draft-claims-y5-b*.json"):
        if B24 in f or f.endswith(".units.json"):
            continue
        for c in json.load(open(f))["claims"]:
            prior_ids.add(c["claim_id"])
            prior_texts.setdefault(c["claim_text"], []).append(c["claim_id"])
    dup_vs_prior = len(ids & prior_ids)

    # universe accounting: recorded tier-b-ambiguous skips in b01..b23
    recorded = set()
    for f in glob.glob(f"{ART}/drafts/y5-draft-claims-y5-b*.units.json"):
        if B24 in f:
            continue
        s = json.load(open(f))
        for x in s["units_skipped"]:
            if x["reason"].startswith("tier-b-ambiguous"):
                recorded.add(x["source_unit_id"])
    drafted = {u["source_unit_id"] for u in side["units"]}
    skipped = {s["source_unit_id"] for s in side["units_skipped"]}
    unaccounted = recorded - drafted - skipped
    extras = (drafted | skipped) - recorded
    double = drafted & skipped
    skip_no_reason = [s for s in side["units_skipped"] if not s.get("reason")]
    a034_drafted = sum(1 for u in side["units"] if 7310 <= u["line_start"] <= 7369)
    # claimable units must carry the tierb_shape tag in a claimable bucket
    bad_shape = [u["claim_id"] for u in side["units"]
                 if u.get("tierb_shape") not in
                 {"struct-field", "index-map", "enum-map", "formula",
                  "code-assign", "cond-expr", "mapping-arrow", "asm-dump",
                  "asset-ref", "code-ident"}]
    dup_texts = {}
    for c in doc["claims"]:
        dup_texts.setdefault(c["claim_text"], []).append(c["claim_id"])
    dup_texts = {t: i for t, i in dup_texts.items() if len(i) > 1}

    ok = (sha_ok == n and slice_ok == n and shape_ok == n and honesty_ok == n
          and lines_ok == n and len(ids) == n and dup_vs_prior == 0
          and not unaccounted and not extras and not double
          and not skip_no_reason and a034_drafted == 0 and not bad_shape
          and side["claims_derived"] == n)
    print(f"[{'PASS' if ok else 'FAIL'}][tierb] {B24}: claims={n} "
          f"sha={sha_ok}/{n} byte_slice={slice_ok}/{n} lines={lines_ok}/{n} "
          f"shape={shape_ok}/{n} honesty={honesty_ok}/{n} ids_unique={len(ids)}/{n} "
          f"dup_vs_prior23={dup_vs_prior} universe={len(recorded)} "
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
                                seed_field_order)
        return 0 if (ok and rc == 0) else 1
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
