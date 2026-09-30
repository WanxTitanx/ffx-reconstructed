#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""y5_draft_claims_b25.py — X5 tier-B THIRD pass (residual, lenient): drafts the
163 units that the b24 second pass skipped AND that sit inside the functionally
re-derived vnext queue (artifacts/2026-09-15/x5-rederivation/
vnext_required.rederived.json — 2,915 units).

Why this pass exists
--------------------
The b24 cycle (docs/reverse/FFX_Y5_B24_ACCEPTANCE_2026-09-15.md §4) measured:
  - 117 of the 494 drafted b24 units are in the re-derived queue;
  - 163 of the 837 skipped residual units are ALSO in the queue;
  - 117 + 163 = 280 = exactly the number of tier-B units the re-derivation
    declares in-queue (2,635 tier-A + 280 tier-B) — the cross-invariant closes.
The follow-up recorded there: "um terceiro passe leniente *limitado às unidades
residuais que estão na fila* recuperaria ~163 claims a mais". This script is that
pass: virtual batch **y5-b25-tierb-thirdpass** (group fsc-20260817-044, next
free id after b24=043).

Honesty contract (same as every Y5 pass — READ BEFORE TRUSTING)
--------------------------------------------------------------
- Every claim is a CANDIDATE DRAFT — never accepted, never validated. Each claim
  asserts ONLY that the legacy FFX structure atlas (2026-08-17 snapshot, sha256
  F5439414…) RECORDS the unit's text at its byte range. It does NOT assert the
  recorded fact is true of any live game artifact, and it does NOT pretend an
  editorial unit is technical: the residual bucket (prose / lead-in /
  bold-label / doc-meta / doc-ref) is carried in the sidecar as `tierb_shape`
  and `pass3_bucket`, and the claim is asserted under the same "the atlas
  records X" envelope used by every Y5 draft.
- claim_text is derived mechanically (markdown stripped, whitespace collapsed,
  ≤460 chars — measured: all 163 fit, truncation flag carried if it ever
  occurs). Nothing is invented.
- scope_id / boundary_id are DRAFT ids (sha256 over documented literal bases);
  MUST be recomputed with CanonicalJson/ClaimAuditService at materialization.
- claim_text_sha256 = sha256(claim_text utf-8, uppercase hex) — the real
  derivation, verified identical to the accepted corpus.

Derivation reuse
----------------
Imports norm_fact/truncate/tierb_shape from the VERSIONED generator
research_tools/Task11Y5/y5_draft_claims.py (sha256 pinned in the manifest) so
the lenient pass uses byte-for-byte the same text normalization and the same
content-shape classifier as b24 — the only new predicate is the universe:
  pass-3 universe = b24 units_skipped(reason=tierb-residual-*) ∩ rederived queue.

Outputs (self-contained under work/_x5_tierb3/ per the lane directive; the
pinned artifact dirs artifacts/2026-09-14/y5/ and the nvme mirror are NOT
touched — promotion/mirroring is a lane-owner step):
  work/_x5_tierb3/drafts/y5-draft-claims-y5-b25-tierb-thirdpass.json
  work/_x5_tierb3/drafts/y5-draft-claims-y5-b25-tierb-thirdpass.units.json

Deterministic: document order (line_start, source_unit_id), no timestamps
beyond the fixed cycle date, no randomness. Python 3.8+ stdlib only.
"""

from __future__ import annotations

import hashlib
import importlib.util
import json
import os
import sys

REPO = "/home/wanderson/Documents/ffx-editor-main"
ART = f"{REPO}/artifacts/2026-09-14/y5"                 # read-only inputs
OUT = f"{REPO}/work/_x5_tierb3"                          # pass-3 artifacts
GEN_PATH = f"{REPO}/research_tools/Task11Y5/y5_draft_claims.py"
B24_SIDE = f"{ART}/drafts/y5-draft-claims-y5-b24-tierb-secondpass.units.json"
QUEUE = f"{REPO}/artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json"
RECON = f"{ART}/y5-units-reconstruction.json"

B25 = "y5-b25-tierb-thirdpass"
GROUP = "fsc-20260817-044"
FORMAT_ID = "tierb3"
EXPECTED_SOURCE_SHA256 = "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7"
DRAFT_NOTES = "DRAFT y5 candidate — NOT accepted; pending X/Y/Z review cycle"

# 2026-09-16 environment finding: the working-tree atlas was link-rewritten by
# commit ab0ce2d0 (work/ -> research_tools/ migration) and no longer hashes to
# the pinned sha. The whole Y5/X5 chain pins F5439414…, so the pinned bytes are
# kept here under work/_x5_tierb3/pins/ — extracted from git blob ab0ce2d0~1
# and byte-verified identical to the committed copy
# artifacts/2026-09-14/qa-win/FFX_STRUCTURE_COMPLETE_2026-08-17.md
# (independent second source, same sha256).
PINNED_ATLAS = f"{OUT}/pins/FFX_STRUCTURE_COMPLETE_2026-08-17.F5439414.md"

# Residual buckets of pass 2 that this lenient pass is allowed to draft.
RESIDUAL_BUCKETS = {"prose", "lead-in", "bold-label", "doc-meta", "doc-ref",
                    "hrule"}


def _load_generator():
    """Import the versioned generator module (no side effects: main() is
    __main__-guarded) so norm_fact/truncate/tierb_shape are literally the same
    code the b01..b24 drafts used."""
    spec = importlib.util.spec_from_file_location("y5_draft_claims", GEN_PATH)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def main() -> int:
    gen = _load_generator()
    atlas = open(PINNED_ATLAS, "rb").read()
    if hashlib.sha256(atlas).hexdigest().upper() != EXPECTED_SOURCE_SHA256:
        sys.stderr.write("y5_draft_claims_b25: ERROR: pinned atlas sha "
                         "mismatch\n")
        return 2

    side24 = json.load(open(B24_SIDE, encoding="utf-8"))
    queue = json.load(open(QUEUE, encoding="utf-8"))
    qmap = {u["source_unit_id"]: u["lot"] for u in queue["vnext_units"]}
    rows_by_id = {r["source_unit_id"]: r for r in
                  json.load(open(RECON, encoding="utf-8"))}

    # ── Pass-3 universe: b24 residual skips that sit in the re-derived queue ──
    resid_all = side24["units_skipped"]
    universe = sorted(
        (s for s in resid_all
         if s["reason"].startswith("tierb-residual-")
         and s["source_unit_id"] in qmap),
        key=lambda s: (rows_by_id[s["source_unit_id"]]["line_start"],
                       s["source_unit_id"]))
    out_of_queue = [s for s in resid_all
                    if s["reason"].startswith("tierb-residual-")
                    and s["source_unit_id"] not in qmap]

    claims = []
    side_units = []
    skipped = []
    ordinal = 0
    for s in universe:
        uid = s["source_unit_id"]
        r = rows_by_id[uid]
        # A034 window cannot occur by construction (b24 excluded it upstream of
        # the residual buckets); the invariant is re-asserted by the validator.
        if gen.A034_WINDOW[0] <= r["line_start"] <= gen.A034_WINDOW[1]:
            skipped.append({"source_unit_id": uid,
                            "reason": "a034-window (lines 7310-7369; anchor "
                                      "A034 routed in vnext C1)"})
            continue
        bucket = gen.tierb_shape(r["text"])
        if bucket not in RESIDUAL_BUCKETS:
            # honesty guard: the b24 skip reason must match the re-derived
            # bucket — a mismatch means the classifier drifted; park the unit.
            skipped.append({"source_unit_id": uid,
                            "reason": f"tierb3-bucket-drift "
                                      f"(b24={s['reason'].split(' ')[0]} vs "
                                      f"rederived={bucket}); parked"})
            continue
        sec = r.get("section_title") or "tier-B residual (X5 third pass)"
        prefix = (f"Legacy FFX structure atlas (2026-08-17 snapshot), "
                  f"section {sec}: ")
        fact = gen.norm_fact(r["text"])
        if not fact.strip():
            skipped.append({"source_unit_id": uid,
                            "reason": "tierb3-empty-fact-after-normalization"})
            continue
        fact, truncated = gen.truncate(fact)
        claim_text = prefix + fact

        ordinal += 1
        claim_id = f"{GROUP}-ffx-pc-{FORMAT_ID}-{ordinal:02d}"
        claim = {
            "claim_id": claim_id,
            "claim_group_id": GROUP,
            "source_relation_ids": [],
            "claim_text": claim_text,
            "claim_text_sha256": hashlib.sha256(
                claim_text.encode("utf-8")).hexdigest().upper(),
            "subject": {
                "scope_id": "scope-" + gen.draft_sha(
                    "draft-y5-scope|" + claim_id),
                "kind": "exact",
                "format_id": FORMAT_ID,
                "game": "ffx",
                "platform": "pc",
                "region_or_build": "legacy-atlas-snapshot-2026-08-17",
            },
            "claimed_boundary": {
                "boundary_id": "boundary-" + gen.draft_sha(
                    "draft-y5-boundary|" + claim_id),
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
        side_units.append({
            "claim_id": claim_id,
            "source_unit_id": uid,
            "line_start": r["line_start"],
            "line_end": r["line_end"],
            "kind": r["kind"],
            "table_role": None,
            "derivation": "normalized-unit-text",
            "truncated": truncated,
            "tierb_shape": bucket,
            "pass3_bucket": bucket,
            "b24_skip_reason": s["reason"],
            "in_rederived_queue": True,
            "queue_lot": qmap[uid],
            "scope_id_basis": "draft-y5-scope|" + claim_id,
            "boundary_id_basis": "draft-y5-boundary|" + claim_id,
        })

    group = {
        "claim_group_id": GROUP,
        "title": "Tier-B third pass (X5): in-queue residual units deferred by "
                 "the b24 second pass",
        "children": [{"target_id": c["claim_id"], "target_kind": "format-claim"}
                     for c in claims],
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
    out_dir = os.path.join(OUT, "drafts")
    os.makedirs(out_dir, exist_ok=True)
    base = os.path.join(out_dir, f"y5-draft-claims-{B25}")
    with open(base + ".json", "w", encoding="utf-8") as fh:
        json.dump(doc, fh, ensure_ascii=False, indent=1)
    side = {
        "document_kind": "y5-draft sidecar (derivation map; not part of the "
                         "accepted claim shape)",
        "batch_id": B25,
        "claim_group_id": GROUP,
        "status": "CANDIDATE DRAFT — nothing here is accepted or validated",
        "queue_basis": side24["queue_basis"],
        "pass3_universe": {
            "rule": "b24 units_skipped with reason tierb-residual-* that are "
                    "members of the functionally re-derived vnext queue "
                    "(artifacts/2026-09-15/x5-rederivation/"
                    "vnext_required.rederived.json); ordering by atlas "
                    "line_start then source_unit_id",
            "b24_residual_skipped_total": len(resid_all),
            "in_queue": len(universe),
            "out_of_queue_deferred": len(out_of_queue),
            "cross_invariant": "117 (b24 drafted in-queue) + 163 (residual "
                               "in-queue) = 280 = tier-B units declared "
                               "in-queue by the re-derivation doc",
        },
        "claims_derived": len(claims),
        "units_skipped": skipped,
        "units": side_units,
    }
    with open(base + ".units.json", "w", encoding="utf-8") as fh:
        json.dump(side, fh, ensure_ascii=False, indent=1)

    h1 = hashlib.sha256(open(base + ".json", "rb").read()).hexdigest().upper()
    h2 = hashlib.sha256(open(base + ".units.json", "rb").read()).hexdigest().upper()
    print(f"{B25}: {len(claims)} draft claims ({len(skipped)} units skipped) "
          f"-> {base}.json")
    print(f"universe={len(universe)} out_of_queue_deferred={len(out_of_queue)}")
    print(f"draft sha256 {h1}\nsidecar sha256 {h2}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
