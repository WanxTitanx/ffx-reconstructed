#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""y5_build_candidate_b25.py — build the formal Y5 CANDIDATE for the virtual
batch y5-b25-tierb-thirdpass (163 DRAFT claims, X5 tier-B third pass over the
in-queue residual units) following the exact precedent of
research_tools/Task11Y5/y5_b24_accept/y5_build_candidate_b24.py (itself a 1:1
adaptation of work/y5_build_candidate.py, wave-1 candidate
y5-candidate-b01b02b03.json, sha 0F435C68…).

Shape: same top-level key set/order as the accepted corpus
seed-claims-v6-vnext.json (schema_version, candidate_vector_sha256,
review_basis_sha256, anchors, snapshots, relations, wording_atoms, claims)
+ one clearly-marked "y5_extensions" object.

Promotion contract (same as waves 1 + b24):
- claims copied VERBATIM from the draft file (no rewrite);
- 1 anchor per claim: YA5-R### (pass-3 namespaced to stay collision-free vs
  the wave-1 YA5-### and the b24 YA5-T### ids) pointing at the pinned atlas
  (F5439414…) via line range + raw_sha256 from atlas-source-units.json;
- 1 relation per claim: YSR-R###, kind "legacy-trace" (existing vocabulary);
- snapshots/wording_atoms empty BY HONESTY (no wording/snapshot analysis done);
- candidate_vector_sha256 = sha256 of LF-joined claim_ids (documented own
  derivation, DRAFT-grade — MUST be recomputed by CanonicalJson/
  ClaimAuditService at materialization, same gate as wave 1 and b24);
- scope_id/boundary_id inside claims remain DRAFT-grade (unchanged, verbatim).

Queue disclosure (X5): by construction every drafted unit of b25 sits inside
the functionally re-derived queue
(artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json). The
queue_reconciliation block is recomputed live by the promotion gate. The
re-derived list's adoption as routing basis remains a lane-owner decision;
unit-level identity is a quantified deterministic approximation (987 units
within ±0.5 of the score cutoff).

Deterministic: document order, no timestamps beyond the fixed cycle date.
"""
import hashlib
import json

REPO = "/home/wanderson/Documents/ffx-editor-main"
OUT = f"{REPO}/work/_x5_tierb3"
ART = f"{REPO}/artifacts/2026-09-14/y5"
ATLAS_PATH = "docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md"
ATLAS_SHA = "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7"
CANDIDATE_SHA = "ECF734A595A8B284E66136E8B54E811D7242627E9C8BBB3D9FC31D076E1DD875"
QUEUE = f"{REPO}/artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json"
B25 = "y5-b25-tierb-thirdpass"
B24 = "y5-b24-tierb-secondpass"
GROUP = "fsc-20260817-044"


def main():
    su = {u["source_unit_id"]: u for u in json.load(open(
        f"{REPO}/Utilities/FFXResearchTools/Claims/atlas-source-units.json")
    )["source_units"]}
    queue = json.load(open(QUEUE))
    qmap = {u["source_unit_id"]: u["lot"] for u in queue["vnext_units"]}

    dd = json.load(open(f"{OUT}/drafts/y5-draft-claims-{B25}.json"))
    us = json.load(open(f"{OUT}/drafts/y5-draft-claims-{B25}.units.json"))
    by_claim = {u["claim_id"]: u for u in us["units"]}

    claims = list(dd["claims"])          # verbatim, same order
    anchors, relations, covered = [], [], []
    n = len(claims)
    in_queue = 0
    for i, c in enumerate(claims, 1):
        rec = by_claim[c["claim_id"]]
        u = su[rec["source_unit_id"]]
        assert u["raw_sha256"], rec
        aid = f"YA5-R{i:03d}"
        anchors.append({
            "anchor_id": aid,
            "logical_path": ATLAS_PATH,
            "source_sha256": ATLAS_SHA,
            "line_start": u["line_start"],
            "line_end": u["line_end"],
            "excerpt_sha256": u["raw_sha256"],
        })
        relations.append({
            "relation_id": f"YSR-R{i:03d}",
            "claim_id": c["claim_id"],
            "anchor_id": aid,
            "relation": "legacy-trace",
        })
        inq = rec["source_unit_id"] in qmap
        in_queue += inq
        covered.append({
            "claim_id": c["claim_id"],
            "source_unit_id": rec["source_unit_id"],
            "batch_id": B25,
            "claim_group_id": GROUP,
            "line_start": u["line_start"],
            "line_end": u["line_end"],
            "kind": u["kind"],
            "derivation": rec["derivation"],
            "truncated": rec["truncated"],
            "tierb_shape": rec.get("tierb_shape"),
            "pass3_bucket": rec.get("pass3_bucket"),
            "b24_skip_reason": rec.get("b24_skip_reason"),
            "in_rederived_queue": inq,
            "queue_lot": qmap.get(rec["source_unit_id"]),
        })

    assert len({c["claim_id"] for c in claims}) == n

    vector = hashlib.sha256(
        "\n".join(c["claim_id"] for c in claims).encode("utf-8")
    ).hexdigest().upper()

    # residual accounting: skipped units that ARE in the re-derived queue
    skipped = us["units_skipped"]
    resid_in_q = [s for s in skipped if s["source_unit_id"] in qmap]
    resid_hist = {}
    for s in resid_in_q:
        r = s["reason"].split(" (")[0]
        resid_hist[r] = resid_hist.get(r, 0) + 1

    # pass-3 universe bookkeeping (recomputed from the sidecar's declared rule)
    p3u = us.get("pass3_universe", {})

    doc = {
        "schema_version": {"major": 1, "minor": 0},
        "candidate_vector_sha256": vector,
        "review_basis_sha256": CANDIDATE_SHA,
        "anchors": anchors,
        "snapshots": [],
        "relations": relations,
        "wording_atoms": [],
        "claims": claims,
        "y5_extensions": {
            "document_kind": "y5-claim-candidate-b25 (tier-B third pass, "
                             "virtual batch — NOT in y5-batches.json by "
                             "design; queue file pinned sha 0ce67a99… in 3 "
                             "locations)",
            "status": "CANDIDATO — promoted from DRAFT 2026-09-16; NOT "
                      "accepted; pending X/Y/Z review cycle (2 independent "
                      "attestations), lane-owner X5 routing-basis decision "
                      "and canonical-service id recomputation",
            "generated": "2026-09-16",
            "batches": [{
                "batch_id": B25,
                "claim_group_id": GROUP,
                "claims": n,
                "draft_file": f"work/_x5_tierb3/drafts/"
                              f"y5-draft-claims-{B25}.json",
                "virtual": True,
            }],
            "covered_units": covered,
            "skipped_units": {
                "units_skipped": len(skipped),
                "reasons": sorted({s["reason"].split(" (")[0]
                                   for s in skipped}),
            },
            "queue_reconciliation": {
                "canonical_queue_size": 2915,
                "canonical_queue_unit_list_available": "functional-rederived",
                "queue_source": "artifacts/2026-09-15/x5-rederivation/"
                                "vnext_required.rederived.json (counts exact by "
                                "construction; unit identity = deterministic "
                                "approximation, 987 units ±0.5 of cutoff; "
                                "adoption as routing basis = lane-owner "
                                "decision)",
                "drafted_units_in_queue": in_queue,
                "drafted_units_total": n,
                "queue_hit_rate": round(in_queue / n, 4),
                "residual_skipped_units_in_queue": len(resid_in_q),
                "residual_in_queue_by_reason": resid_hist,
                "pass3_universe_size": p3u.get("in_queue"),
                "pass3_universe_rule": p3u.get("rule"),
                "tierb_in_queue_total": 280,
                "tierb_in_queue_after_pass3": {
                    "b24_drafted_in_queue": 117,
                    "b25_drafted_in_queue": in_queue,
                    "b25_residual_skipped_in_queue": len(resid_in_q),
                    "tierb_in_queue_fully_dispositioned":
                        117 + in_queue + len(resid_in_q) == 280,
                },
                "tierb_residual_out_of_queue_deferred":
                    p3u.get("out_of_queue_deferred"),
                "tierb_universe_size": 1331,
            },
            "verification": {
                "claim_count": n,
                "claim_ids_unique": n,
                "claims_verbatim_from_drafts": True,
                "boundary_artifact_sha256_pinned": f"{n}/{n} pin {ATLAS_SHA}",
                "anchor_excerpt_sha256_source": "atlas-source-units.json "
                                              "raw_sha256 (pinned vector "
                                              "D67500CA…)",
                "scope_boundary_ids": "DRAFT-grade (draft-y5-scope|… / "
                                      "draft-y5-boundary|…) — MUST be "
                                      "recomputed with CanonicalJson/"
                                      "ClaimAuditService at materialization",
                "candidate_vector_sha256_derivation": "sha256 of LF-joined "
                    "claim_ids (UTF-8, uppercase hex) — documented derivation, "
                    "not the exec CanonicalJson service",
                "relation_kind_note": "legacy-trace: each claim traces to "
                    "exactly 1 atlas source-unit anchor (line range + "
                    "raw_sha256); no wording analysis performed "
                    "(wording_atoms empty by honesty)",
                "atlas_pin_note": "working-tree atlas link-rewritten by commit "
                    "ab0ce2d0 (2026-09-16); all byte-slice verification runs "
                    "against the pinned bytes F5439414… recovered from git "
                    "blob ab0ce2d0~1 and cross-verified vs the committed copy "
                    "artifacts/2026-09-14/qa-win/FFX_STRUCTURE_COMPLETE_"
                    "2026-08-17.md (identical sha256)",
            },
        },
    }

    out_path = f"{OUT}/y5-candidate-b25-tierb3.json"
    with open(out_path, "w", encoding="utf-8") as f:
        json.dump(doc, f, indent=2, ensure_ascii=False)
        f.write("\n")
    h = hashlib.sha256(open(out_path, "rb").read()).hexdigest().upper()
    print("wrote", out_path)
    print("bytes:", len(open(out_path, "rb").read()), "sha256:", h)
    print("claims:", n, "anchors:", len(anchors), "relations:", len(relations),
          "in_queue:", in_queue, f"({in_queue / n * 100:.1f}%)",
          "resid_in_queue:", len(resid_in_q))


if __name__ == "__main__":
    main()
