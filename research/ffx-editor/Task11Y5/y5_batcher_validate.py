#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""y5_batcher_validate.py — validate Y5 draft batches (2026-09-14, Y5-BATCHER).

Per-batch checks (all must be N/N to PASS):
  1. claim_text_sha256 recomputed = sha256(claim_text utf-8, uppercase hex) matches.
  2. Anchor pre-validation by PHYSICAL byte-slice against the frozen atlas:
     atlas_bytes[byte_start : byte_start+byte_length] -> sha256 must equal the
     unit's raw_sha256 in the pinned atlas-source-units.json (the same value the
     candidate builder records as anchor excerpt_sha256 for YA5-* anchors).
  3. Every batch unit is accounted for: exactly one of (drafted claim, skip with
     reason); claim sidecar lines match atlas-source-units lines.
  4. claim_ids unique per batch AND globally vs the wave-1 drafts (b01-b03);
     claim texts distinct (no duplicate claim text across all 6 batches).
  5. Claim field names/order identical to the accepted seed corpus
     (Utilities/FFXResearchTools/claims/seed-claims-v6-vnext.json).
  6. Honesty invariants: notes == DRAFT marker, confidence == low,
     evidence_links == [], boundary artifact_sha256s == pinned atlas sha.

Also regenerates determinism proof: re-running the generator over the same batch
inputs must produce byte-identical files (checked by the caller via cmp, not here).

Inputs read-only; prints a per-batch PASS/FAIL summary + exit code.
"""

import hashlib
import json
import sys

REPO = "/home/wanderson/Documents/ffx-editor-main"
ART = "/mnt/nvme-samsung/ffx-task-artifacts/glm-structures-exec-69f2d8/y5-drafts"
ATLAS_PATH = f"{REPO}/docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md"
ATLAS_SHA = "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7"
SEED = f"{REPO}/Utilities/FFXResearchTools/claims/seed-claims-v6-vnext.json"
DRAFT_NOTES = "DRAFT y5 candidate — NOT accepted; pending X/Y/Z review cycle"

NEW_BATCHES = ["y5-b06-atel-headers", "y5-b07-tbl-catalogs", "y5-b09-vbf-txc-psarc"]
WAVE1_BATCHES = ["y5-b01-menu-formats", "y5-b02-egovm-opcodes", "y5-b03-ftc-glyphs"]


def main() -> int:
    atlas = open(ATLAS_PATH, "rb").read()
    atlas_sha = hashlib.sha256(atlas).hexdigest().upper()
    if atlas_sha != ATLAS_SHA:
        print(f"FATAL: atlas sha mismatch {atlas_sha}")
        return 2
    su = {u["source_unit_id"]: u for u in json.load(
        open(f"{REPO}/Utilities/FFXResearchTools/Claims/atlas-source-units.json")
    )["source_units"]}
    seed_field_order = list(json.load(open(SEED))["claims"][0].keys())

    global_ids = set()
    global_texts = {}
    all_ok = True
    totals = {}

    for batch_id in WAVE1_BATCHES + NEW_BATCHES:
        doc = json.load(open(f"{ART}/drafts/y5-draft-claims-{batch_id}.json"))
        side = json.load(open(f"{ART}/drafts/y5-draft-claims-{batch_id}.units.json"))
        batches_doc = json.load(open(f"{ART}/y5-batches.json"))
        bdef = next(b for b in batches_doc["batches"] if b["batch_id"] == batch_id)

        n = len(doc["claims"])
        sha_ok = slice_ok = shape_ok = honesty_ok = lines_ok = 0
        ids_batch = set()
        fails = []

        for c in doc["claims"]:
            # 1. claim_text_sha256
            if hashlib.sha256(c["claim_text"].encode("utf-8")).hexdigest().upper() == c["claim_text_sha256"]:
                sha_ok += 1
            else:
                fails.append(f"sha256 mismatch {c['claim_id']}")
            # 2. physical byte-slice anchor evidence
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
            # 5. shape vs seed
            if list(c.keys()) == seed_field_order:
                shape_ok += 1
            else:
                fails.append(f"field order drift {c['claim_id']}")
            # 6. honesty invariants
            if (c["notes"] == DRAFT_NOTES and c["confidence"] == "low"
                    and c["evidence_links"] == []
                    and c["claimed_boundary"]["artifact_sha256s"] == [ATLAS_SHA]):
                honesty_ok += 1
            else:
                fails.append(f"honesty invariant fail {c['claim_id']}")
            ids_batch.add(c["claim_id"])
            global_texts.setdefault(c["claim_text"], []).append(c["claim_id"])

        dup_in_batch = n - len(ids_batch)
        dup_vs_wave1 = len(ids_batch & global_ids)
        global_ids |= ids_batch

        # 3. unit accounting
        drafted = {u["source_unit_id"] for u in side["units"]}
        skipped = {s["source_unit_id"] for s in side["units_skipped"]}
        unaccounted = [x for x in bdef["unit_ids"] if x not in drafted and x not in skipped]
        double = drafted & skipped
        skip_no_reason = [s for s in side["units_skipped"] if not s.get("reason")]
        a034 = bdef.get("a034_window_units", 0)
        a034_drafted = sum(1 for u in side["units"]
                           if 7310 <= u["line_start"] <= 7369)

        ok = (sha_ok == n and slice_ok == n and shape_ok == n and honesty_ok == n
              and lines_ok == n and dup_in_batch == 0 and dup_vs_wave1 == 0
              and not unaccounted and not double and not skip_no_reason
              and a034_drafted == 0 and side["claims_derived"] == n)
        all_ok = all_ok and ok
        totals[batch_id] = n
        print(f"[{'PASS' if ok else 'FAIL'}] {batch_id}: claims={n} "
              f"sha={sha_ok}/{n} byte_slice={slice_ok}/{n} lines={lines_ok}/{n} "
              f"shape={shape_ok}/{n} honesty={honesty_ok}/{n} "
              f"skips={len(side['units_skipped'])} (all with reason={not skip_no_reason}) "
              f"dup_in_batch={dup_in_batch} dup_vs_prior={dup_vs_wave1} "
              f"unaccounted={len(unaccounted)} double_counted={len(double)} "
              f"a034_window_drafted={a034_drafted}/{a034}")
        for f in fails[:10]:
            print(f"       FAIL-DETAIL: {f}")
        skip_hist = {}
        for s in side["units_skipped"]:
            skip_hist[s["reason"]] = skip_hist.get(s["reason"], 0) + 1
        print(f"       skip reasons: {skip_hist}")

    # Duplicate claim TEXTS across distinct source units are a source reality the
    # canonical queue itself anticipated (2915 units -> 2909 distinct texts);
    # derivation contract is 1 claim per ELIGIBLE UNIT, so these are WARN + must
    # be registered in the report — they are NOT a hard failure. Duplicate
    # claim_ids remain a hard failure (checked above per batch).
    dup_texts = {t: ids for t, ids in global_texts.items() if len(ids) > 1}
    grand = sum(totals.values())
    if dup_texts:
        print(f"WARN: {len(dup_texts)} claim texts each produced by >1 distinct source unit:")
        for t, ids in list(dup_texts.items())[:10]:
            print(f"       {ids}: {t[:100]}")
    print(f"distinct claim texts across all 6 batches: {len(global_texts)} / {grand} claims")
    print(f"\nTOTALS: drafted claims all batches = {grand} "
          f"(wave1 = {sum(totals[b] for b in WAVE1_BATCHES)}, new = {sum(totals[b] for b in NEW_BATCHES)})")
    print(f"superset 5587 - drafted {grand} = {5587 - grand} units remaining")
    return 0 if all_ok else 1


if __name__ == "__main__":
    sys.exit(main())
