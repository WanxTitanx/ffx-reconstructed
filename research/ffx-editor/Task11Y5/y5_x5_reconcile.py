#!/usr/bin/env python3
# Y5-CYCLE X5 reconciliation (repo-based) — lane FFX-STRUCTURES, 2026-09-14.
#
# Purpose: answer, with evidence from the REPO ONLY (no MEGA artifacts):
#   (1) Is the exact list of the 2,915 canonical "vnext-required" units derivable
#       from task11-review-candidate-v2-vnext.json / attestations / envelope?
#   (2) If not, what CAN be reconciled: superset containment (5,587 narrative-context),
#       per-batch bounds, A034 window overlap, coverage of the 134 drafted claims.
#
# Read-only against the repo; writes summary JSON to the y5-drafts artifacts dir.
import hashlib
import json
import os
from collections import Counter

REPO = "/home/wanderson/Documents/ffx-editor-main"
ART = "/mnt/nvme-samsung/ffx-task-artifacts/glm-structures-exec-69f2d8/y5-drafts"

CANDIDATE = f"{REPO}/docs/reverse/task11/vnext/task11-review-candidate-v2-vnext.json"
SOURCE_UNITS = f"{REPO}/Utilities/FFXResearchTools/Claims/atlas-source-units.json"
ENVELOPE = f"{REPO}/docs/reverse/task11/vnext/task11-acceptance-envelope-v2.json"
ATTEST_A = f"{REPO}/docs/reverse/task11/vnext/attestations/reviewer-a.json"
ATTEST_B = f"{REPO}/docs/reverse/task11/vnext/attestations/reviewer-b.json"
BATCHES = f"{ART}/y5-batches.json"


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest().upper()


def deep_key_scan(node, needle_terms, path="$", hits=None):
    """Recursively collect JSON key paths whose key name matches a needle term."""
    if hits is None:
        hits = []
    if isinstance(node, dict):
        for k, v in node.items():
            p = f"{path}.{k}"
            if any(t in k.lower() for t in needle_terms):
                hits.append(p)
            deep_key_scan(v, needle_terms, p, hits)
    elif isinstance(node, list):
        for i, v in enumerate(node):
            deep_key_scan(v, needle_terms, f"{path}[{i}]", hits)
    return hits


def main():
    out = {"document_kind": "y5-x5-repo-reconciliation", "generated": "2026-09-14"}

    with open(CANDIDATE) as f:
        cand = json.load(f)
    with open(SOURCE_UNITS) as f:
        su = json.load(f)
    with open(BATCHES) as f:
        batches = json.load(f)

    decisions = cand["decisions"]
    assert len(decisions) == 10281

    # ── (1a) Field inventory of decisions — is there ANY vnext marker? ──
    key_paths = Counter()
    for d in decisions:
        for k in d:
            key_paths[k] += 1
        ed = d.get("exclusive_decision")
        if ed:
            for k in ed:
                key_paths[f"exclusive_decision.{k}"] += 1
    needles = ["vnext", "gated", "queue", "required", "unrouted", "routed"]
    marker_paths = deep_key_scan(decisions, needles)
    out["decision_field_usage"] = dict(key_paths)
    out["vnext_marker_key_paths_in_decisions"] = marker_paths  # expect []

    # also scan whole candidate top-level + bindings/targets for vnext-ish keys
    out["vnext_marker_key_paths_whole_candidate"] = deep_key_scan(cand, needles)

    # ── (1b) disposition x reason histogram (the derivable classification) ──
    hist = Counter()
    narrative_ids = set()
    for d in decisions:
        ed = d["exclusive_decision"]
        if ed is None:
            hist[("<BOUND>", f"n={len(d['factual_bindings'])}")] += 1
        else:
            hist[(ed["disposition"], ed["reason"])] += 1
            if ed["reason"] == "narrative-context" and not d["factual_bindings"]:
                narrative_ids.add(d["source_unit_id"])
    out["disposition_reason_histogram"] = {f"{k[0]}/{k[1]}": v for k, v in sorted(hist.items())}
    out["narrative_context_superset_size"] = len(narrative_ids)  # expect 5587

    # ── (1c) Composition arithmetic from reviewer-b vs candidate labels ──
    # matrix exclusive 7329 = 1+2278+757+2667+1620+6 ; vnext 2915 ; a034-context 5
    # candidate narrative-context 5587 must equal 2667 + 2915 + 5
    out["composition_check"] = {
        "matrix_narrative_editorial": 2667,
        "matrix_vnext_gated": 2915,
        "matrix_a034_context": 5,
        "sum": 2667 + 2915 + 5,
        "candidate_narrative_context": hist[("editorial-context", "narrative-context")],
        "lumped": 2667 + 2915 + 5 == hist[("editorial-context", "narrative-context")],
        "grand_total_check": 7329 + 2915 + 5 + 27 + 5 == 10281,
    }

    # ── (1d) envelope + attestations: queue mentioned only as counts/strings ──
    with open(ENVELOPE) as f:
        env = json.load(f)
    queue_str = [s for s in env["limitations"] if "vnext-required" in s]
    out["envelope_queue_limitation"] = queue_str
    with open(ATTEST_A) as f:
        ra = json.load(f)
    with open(ATTEST_B) as f:
        rb = json.load(f)
    out["attest_a_routing_c17"] = ra["checks"]["routing_c17"]
    out["attest_b_matrix_rows"] = rb["coverage"]["matrix_rows"]
    out["attest_a_matrix_files_referenced"] = ra["review_basis"]["t1107_matrix"]["files"]
    out["attest_a_unit_to_claims_file"] = ra["review_basis"]["unit_to_claims"]["file"]
    out["attest_a_dispositions_file"] = ra["review_basis"]["dispositions"]["file"]
    # do those files exist anywhere in repo?
    missing = []
    for name in ra["review_basis"]["t1107_matrix"]["files"] + [
        ra["review_basis"]["unit_to_claims"]["file"],
        ra["review_basis"]["dispositions"]["file"],
        "vnext-extended-ledger.json",
    ]:
        base = os.path.basename(name)
        found = os.system(
            f"find {REPO} -name '{base}' -not -path '*/bin/*' -not -path '*/obj/*' >/dev/null 2>&1"
        ) == 0 and os.popen(
            f"find {REPO} -name '{base}' -not -path '*/bin/*' -not -path '*/obj/*' 2>/dev/null"
        ).read().strip() != ""
        missing.append({"file": base, "in_repo": found})
    out["matrix_family_files_in_repo"] = missing

    # ── (2a) superset identity: batches union == narrative set? ──
    batch_union = set()
    per_batch = []
    su_by_id = {u["source_unit_id"]: u for u in su["source_units"]}
    for b in batches["batches"]:
        ids = set(b["unit_ids"])
        batch_union |= ids
        a034 = [u for u in ids if 7310 <= su_by_id[u]["line_start"] <= 7369]
        per_batch.append({
            "batch_id": b["batch_id"],
            "wave": b["wave"],
            "units": b["unit_count"],
            "tier_a": b["tier_a_factual"],
            "tier_b": b["tier_b_ambiguous"],
            "risk": b["risk"],
            "a034_window_units": len(a034),
            # queue-coverage bounds: extras outside the 2,915 queue total 2,672
            # (2,667 narrative-editorial + 5 a034-context) and can sit in any batch.
            "queue_min": max(0, b["unit_count"] - (2667 + 5)),
            "queue_max": min(b["unit_count"], 2915),
        })
    out["batches_union_size"] = len(batch_union)
    out["batches_union_equals_narrative_superset"] = batch_union == narrative_ids
    out["narrative_not_in_batches"] = len(narrative_ids - batch_union)
    out["batch_union_not_narrative"] = len(batch_union - narrative_ids)
    out["per_batch"] = per_batch

    # ── (2b) A034 window units across whole superset ──
    a034_all = sorted(
        su_by_id[u]["line_start"] for u in narrative_ids
        if 7310 <= su_by_id[u]["line_start"] <= 7369
    )
    out["a034_window_narrative_units_total"] = len(a034_all)

    # ── (2c) drafted claims coverage ──
    drafted = []
    for b in ["y5-b01-menu-formats", "y5-b02-egovm-opcodes", "y5-b03-ftc-glyphs"]:
        with open(f"{ART}/drafts/y5-draft-claims-{b}.json") as f:
            dd = json.load(f)
        with open(f"{ART}/drafts/y5-draft-claims-{b}.units.json") as f:
            us = json.load(f)
        batch_rec = next(x for x in batches["batches"] if x["batch_id"] == b)
        unit_ids = set(batch_rec["unit_ids"])
        derived_units = {u["source_unit_id"] for u in us["units"]}
        # verify every derived unit is in the batch and in the superset
        in_batch = derived_units <= unit_ids
        in_superset = derived_units <= narrative_ids
        # verify claim texts hash
        sha_ok = all(
            hashlib.sha256(c["claim_text"].encode("utf-8")).hexdigest().upper()
            == c["claim_text_sha256"]
            for c in dd["claims"]
        )
        drafted.append({
            "batch_id": b,
            "group_id": dd["groups"][0]["claim_group_id"],
            "claims": len(dd["claims"]),
            "units_derived": len(us["units"]),
            "units_in_batch": in_batch,
            "units_in_superset": in_superset,
            "claim_text_sha256_recomputed_ok": sha_ok,
            "boundary_pins_atlas": all(
                c["claimed_boundary"].get("artifact_sha256s") == [
                    "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7"
                ]
                for c in dd["claims"]
            ),
        })
    out["drafted_batches"] = drafted
    out["drafted_total_claims"] = sum(x["claims"] for x in drafted)

    # ── pins ──
    out["pins"] = {
        "candidate_file_sha256": sha256_file(CANDIDATE),
        "envelope_candidate_sha256": env["candidate_sha256"],
        "candidate_sha256_match": sha256_file(CANDIDATE) == env["candidate_sha256"],
        "source_units_sha256_file": sha256_file(SOURCE_UNITS),
        "atlas_source_pinned": su["source_sha256"],
    }

    with open(f"{ART}/y5-x5-reconciliation.json", "w") as f:
        json.dump(out, f, indent=2, ensure_ascii=False)
    # console digest
    print(json.dumps({k: v for k, v in out.items() if k != "per_batch"}, indent=1)[:4000])
    print("per_batch rows:", len(out["per_batch"]))


if __name__ == "__main__":
    main()
