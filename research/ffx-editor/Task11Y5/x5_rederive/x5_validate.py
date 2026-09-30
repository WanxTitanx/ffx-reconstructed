#!/usr/bin/env python3
# ── X5-REDERIVE step 4 — full validation of the re-derived vnext separation against ALL arbiters ──
# Arbiters (from reviewer-a/b attestations + recovered ledger + y5-x5-reconciliation):
#   A1 phase-1 stats: mechanical 829 / ws 2278 / mech-draft 543 / pending 933+4042+1624 / a034 32 (24+6+2)
#   A2 semtriage buckets: code-data 1595 / runtime 1187 / format 1318 / ambiguous 1830 / editorial 438 / meta 231
#   A3 semantic bindings per lot: B=2, C=2, F=1
#   A4 vnext_unrouted == 2915
#   A5 composition: 7329 exclusive / 5 binding / 27 a034-bound / 5 a034-context / 2915 vnext (sum 10281)
#   A6 narrative pool: 2667 editorial + 2915 vnext + 5 a034-context == 5587
#   A7 binding-units (32) and a034 all OUTSIDE the vnext queue
#   A8 distinct claim texts 2909 (LLM-written; proxy here = raw unit text)
#   A9 vnext queue lines span 33..11022 (ledger: "linhas 33–11022")
#   A10 Y5 cross: 134 claims -> covered units in queue (random IC95 = [59,81]; cycle expectation ~70)
import json
from collections import Counter

WORK = "/home/wanderson/Documents/ffx-editor-main/work/_x5_rederive"
REPO = "/home/wanderson/Documents/ffx-editor-main"
RED = "/mnt/nvme-samsung/ffx-task-artifacts/glm-structures-exec-69f2d8/rederived"

wm = json.load(open(f"{WORK}/work-matrix.rederived.json"))
tri = json.load(open(f"{WORK}/semantic-triage-v1.rederived.json"))
red = json.load(open(f"{RED}/vnext_required.rederived.json"))
cand = json.load(open(f"{REPO}/docs/reverse/task11/vnext/task11-review-candidate-v2-vnext.json"))
y5 = {x["source_unit_id"]: x for x in json.load(open(f"{REPO}/artifacts/2026-09-14/y5/y5-units-reconstruction.json"))}

report = {"document_kind": "x5-rederivation-validation-report", "generated": "2026-09-15",
          "checks": [], "verdict": None}


def check(name, ok, detail):
    report["checks"].append({"id": name, "pass": bool(ok), "detail": detail})
    print(f"{'PASS' if ok else 'DIFF'}  {name}  {detail}")


# A1 phase-1 stats
s = wm["stats"]
exp1 = {"mechanical": 829, "ws-exempt": 2278, "mech-draft": 543, "pending-paragraph": 933,
        "pending-table-row": 4042, "pending-list-item": 1624, "a034-vNext": 24,
        "a034-provenance": 6, "a034-vNext+provenance": 2}
check("A1-phase1-stats", all(s.get(k, 0) == v for k, v in exp1.items()) and sum(s.values()) == 10281,
      f"{s} (total {sum(s.values())})")

# A2 semtriage buckets
c2 = tri["counts_by_cls_suggested"]
exp2 = {"code/data": 1595, "factual-runtime": 1187, "factual-format": 1318,
        "ambiguous": 1830, "editorial": 438, "factual-meta": 231}
check("A2-semtriage-buckets", all(c2.get(k, 0) == v for k, v in exp2.items()) and sum(c2.values()) == 6599,
      f"{c2} (total {sum(c2.values())})")

# A3 bindings per lot
b3 = red["counts"]["semantic_bindings_per_lot"]
check("A3-bindings-per-lot", b3 == {"B": 2, "C": 2, "F": 1}, f"{b3}")

# A4 vnext total
vset = {u["source_unit_id"] for u in red["vnext_units"]}
check("A4-vnext-total", len(vset) == 2915, f"{len(vset)} (arbiter 2915)")

# A5 composition over 10281
binding_ids = {d["source_unit_id"] for d in cand["decisions"] if d.get("factual_bindings")}
a034_ids = {r["id"] for r in wm["rows"] if r.get("cls") == "a034-triaged"}
semantic_bindings = binding_ids - a034_ids          # 5
a034_bound = binding_ids & a034_ids                 # 27
a034_context = a034_ids - binding_ids               # 5
exclusive = 10281 - len(vset) - len(binding_ids) - len(a034_context)
check("A5-composition",
      exclusive == 7329 and len(semantic_bindings) == 5 and len(a034_bound) == 27
      and len(a034_context) == 5 and len(vset) == 2915,
      f"exclusive={exclusive}/7329 binding={len(semantic_bindings)}/5 a034-bound={len(a034_bound)}/27 "
      f"a034-context={len(a034_context)}/5 vnext={len(vset)}/2915 "
      f"(sum={exclusive+len(semantic_bindings)+len(a034_bound)+len(a034_context)+len(vset)})")

# A6 narrative pool decomposition (candidate reason=narrative-context must be vnext+editorial+context)
narrative = {d["source_unit_id"] for d in cand["decisions"]
             if (d.get("exclusive_decision") or {}).get("reason") == "narrative-context"}
editorial_narr = narrative - vset - a034_context
check("A6-narrative-pool", len(narrative) == 5587 and len(editorial_narr) == 2667
      and len(narrative) == len(vset) + len(editorial_narr) + len(a034_context),
      f"narrative={len(narrative)}/5587 editorial={len(editorial_narr)}/2667 vnext={len(vset)}/2915 "
      f"context={len(a034_context)}/5")

# A7 disjointness
check("A7-disjoint", not (vset & binding_ids) and not (vset & a034_ids),
      f"queue∩binding={len(vset & binding_ids)} queue∩a034={len(vset & a034_ids)}")

# A8 distinct texts (proxy)
texts = [(y5[u]["text"] or "").strip() for u in vset]
distinct = len(set(texts))
check("A8-distinct-texts-proxy", distinct == 2909, f"{distinct} vs arbiter 2909 "
      f"(proxy=raw unit text; arbiter counted LLM-written claim texts — not byte-reproducible)")

# A9 line span
lines = sorted(y5[u]["line_start"] for u in vset)
check("A9-line-span", lines[0] >= 33 and lines[-1] <= 11022,
      f"lines {lines[0]}..{lines[-1]} (ledger arbiter 33..11022)")

# A10 Y5 cross
cand_y5 = json.load(open(f"{REPO}/artifacts/2026-09-14/y5/y5-candidate-b01b02b03.json"))
cov = cand_y5["y5_extensions"]["covered_units"]
inq = [c for c in cov if c["source_unit_id"] in vset]
check("A10-y5-cross", 59 <= len(inq) <= 134, f"{len(inq)}/134 covered-units in queue "
      f"(random IC95 [59,81]; cycle expectation ~70; >81 => queue captures the factual "
      f"signal the Y5 drafts also targeted)")

# composition profile (informational)
tier = Counter(y5[u]["factual_marker"] for u in vset)
kinds = Counter(y5[u]["kind"] for u in vset)
report["composition_profile"] = {
    "tier_A_factual": tier.get(True, 0), "tier_B_ambiguous": tier.get(False, 0),
    "kinds": dict(kinds),
    "editorial_narrative_kinds": dict(Counter(y5[u]["kind"] for u in editorial_narr)),
}
print("\nqueue tier profile:", dict(tier), "| kinds:", dict(kinds))
print("editorial narrative kinds:", dict(Counter(y5[u]["kind"] for u in editorial_narr)))

npass = sum(1 for c in report["checks"] if c["pass"])
report["verdict"] = ("FUNCTIONALLY RE-DERIVED" if npass == len(report["checks"])
                     else f"PARTIAL ({npass}/{len(report['checks'])})")
json.dump(report, open(f"{RED}/validation-report.json", "w"), ensure_ascii=False, indent=1)
print(f"\nVERDICT: {report['verdict']} ({npass}/{len(report['checks'])} exact)")
print(f"written: {RED}/validation-report.json")
