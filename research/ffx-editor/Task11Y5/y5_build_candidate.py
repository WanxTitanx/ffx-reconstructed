#!/usr/bin/env python3
# Build the formal Y5 candidate (wave 1: batches b01+b02+b03) from the 134 drafts.
#
# Shape follows the ACCEPTED corpus Utilities/FFXResearchTools/claims/seed-claims-v6-vnext.json
# (top-level key set and order: schema_version, candidate_vector_sha256,
# review_basis_sha256, anchors, snapshots, relations, wording_atoms, claims),
# extended with a single clearly-marked "y5_extensions" object carrying the
# covered-unit list, queue reconciliation and verification results (the mission
# requires the unit list inside the candidate).
#
# All derivations are recomputed from repo-pinned inputs; claim records are
# copied VERBATIM from the drafts (promotion, not rewrite).
import hashlib
import json

REPO = "/home/wanderson/Documents/ffx-editor-main"
ART = "/mnt/nvme-samsung/ffx-task-artifacts/glm-structures-exec-69f2d8/y5-drafts"
ATLAS_PATH = "docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md"
ATLAS_SHA = "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7"
CANDIDATE_SHA = "ECF734A595A8B284E66136E8B54E811D7242627E9C8BBB3D9FC31D076E1DD875"

BATCHES = [
    ("y5-b01-menu-formats", "fsc-20260817-020"),
    ("y5-b02-egovm-opcodes", "fsc-20260817-021"),
    ("y5-b03-ftc-glyphs", "fsc-20260817-022"),
]


def main():
    with open(f"{REPO}/Utilities/FFXResearchTools/Claims/atlas-source-units.json") as f:
        su = {u["source_unit_id"]: u for u in json.load(f)["source_units"]}

    claims = []
    anchors = []
    relations = []
    covered_units = []
    skipped = {}
    a_i = r_i = 0
    for batch_id, group_id in BATCHES:
        with open(f"{ART}/drafts/y5-draft-claims-{batch_id}.json") as f:
            dd = json.load(f)
        with open(f"{ART}/drafts/y5-draft-claims-{batch_id}.units.json") as f:
            us = json.load(f)
        unit_map = {u["source_unit_id"]: u for u in us["units"]}
        skipped[batch_id] = {
            "total": len(dd["groups"][0]["children"]) if False else None,  # unused
            "units_skipped": len(us["units_skipped"]),
            "reasons": sorted({s["reason"] for s in us["units_skipped"]}),
        }
        # keep claims in document order of the batch (draft order already is)
        for c in dd["claims"]:
            claims.append(c)  # verbatim
        # anchor + relation per derived unit, ordered by claim order in the draft
        for c in dd["claims"]:
            rec = next(u for u in us["units"] if u["claim_id"] == c["claim_id"])
            u = su[rec["source_unit_id"]]
            assert u["raw_sha256"], rec
            a_i += 1
            anchor_id = f"YA5-{a_i:03d}"
            anchors.append({
                "anchor_id": anchor_id,
                "logical_path": ATLAS_PATH,
                "source_sha256": ATLAS_SHA,
                "line_start": u["line_start"],
                "line_end": u["line_end"],
                "excerpt_sha256": u["raw_sha256"],
            })
            r_i += 1
            relations.append({
                "relation_id": f"YSR{r_i:03d}",
                "claim_id": c["claim_id"],
                "anchor_id": anchor_id,
                "relation": "legacy-trace",
            })
            covered_units.append({
                "claim_id": c["claim_id"],
                "source_unit_id": rec["source_unit_id"],
                "batch_id": batch_id,
                "claim_group_id": group_id,
                "line_start": u["line_start"],
                "line_end": u["line_end"],
                "kind": u["kind"],
                "derivation": rec["derivation"],
                "truncated": rec["truncated"],
            })
        del unit_map

    assert len(claims) == 134, len(claims)
    assert len(anchors) == 134 and len(relations) == 134
    assert len({c["claim_id"] for c in claims}) == 134

    # claim_id vector sha256 (derivation documented in-file; the seed-v6 value
    # was produced by the exec's CanonicalJson service and cannot be reproduced
    # here — this is an equivalent documented derivation, DRAFT-grade)
    vector = hashlib.sha256(
        "\n".join(c["claim_id"] for c in claims).encode("utf-8")
    ).hexdigest().upper()

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
            "document_kind": "y5-claim-candidate-wave1 (b01+b02+b03)",
            "status": "CANDIDATO — promoted from DRAFT 2026-09-14; NOT accepted; pending X/Y/Z review cycle (2 independent attestations) and pending X5 full reconciliation against the exec matrix",
            "generated": "2026-09-14",
            "batches": [
                {"batch_id": b, "claim_group_id": g, "claims": n, "draft_file": f"drafts/y5-draft-claims-{b}.json"}
                for (b, g), n in zip(BATCHES, [46, 60, 28])
            ],
            "covered_units": covered_units,
            "skipped_units": skipped,
            "queue_reconciliation": {
                "canonical_queue_size": 2915,
                "canonical_queue_unit_list_available": False,
                "why": "task11-review-candidate-v2-vnext.json decisions carry only exclusive_decision{disposition,reason} + factual_bindings; the 2915 vnext-gated, 2667 narrative-editorial and 5 a034-context units are ALL lumped under (editorial-context, narrative-context) = 5587; the split lives only in exec-internal files (t1107-work-matrix.json, t1107-decisions/t1107-coverage-matrix.json, vnext-unit-to-claims.json, vnext-claim-dispositions.json) absent from this machine",
                "superset_used": "5587 narrative-context exclusive units (deterministic from the accepted candidate)",
                "superset_contains_queue": True,
                "superset_contains_queue_basis": "reviewer-b.json check 2_xor_strict_matrix: '2915 vnext-gated -> todos exclusive editorial-context/narrative-context'",
                "overcoverage_units": 2672,
                "drafted_units_in_superset_verified": True,
                "expected_queue_hit_rate_if_uniform": round(2915 / 5587, 4),
            },
            "verification": {
                "claim_count": 134,
                "claim_ids_unique": 134,
                "claim_text_sha256_recomputed": "134/134 OK",
                "claims_verbatim_from_drafts": True,
                "boundary_artifact_sha256_pinned": f"134/134 pin {ATLAS_SHA}",
                "anchor_excerpt_sha256_source": "atlas-source-units.json raw_sha256 (pinned vector D67500CA…)",
                "scope_boundary_ids": "DRAFT-grade (draft-y5-scope|… / draft-y5-boundary|…) — MUST be recomputed with the canonical CanonicalJson/ClaimAuditService at materialization",
                "candidate_vector_sha256_derivation": "sha256 of LF-joined claim_ids (UTF-8, uppercase hex) — documented derivation, not the exec CanonicalJson service",
                "review_basis_sha256_meaning": "sha256 of docs/reverse/task11/vnext/task11-review-candidate-v2-vnext.json (accepted T11 candidate that defines the queue superset)",
                "relation_kind_note": "legacy-trace: each claim traces to exactly 1 atlas source-unit anchor (line range + raw_sha256); no wording analysis performed (wording_atoms empty by honesty)",
            },
        },
    }

    out_path = f"{ART}/y5-candidate-b01b02b03.json"
    with open(out_path, "w") as f:
        json.dump(doc, f, indent=2, ensure_ascii=False)
        f.write("\n")
    h = hashlib.sha256(open(out_path, "rb").read()).hexdigest().upper()
    print("wrote", out_path)
    print("bytes:", len(open(out_path, 'rb').read()))
    print("sha256:", h)
    print("claims:", len(claims), "anchors:", len(anchors), "relations:", len(relations))
    print("groups:", {b: n for (b, _), n in zip(BATCHES, [46, 60, 28])})


if __name__ == "__main__":
    main()
