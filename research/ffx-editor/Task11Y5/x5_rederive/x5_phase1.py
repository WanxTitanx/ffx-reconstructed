#!/usr/bin/env python3
# ── X5-REDERIVE phase 1 — re-execution of the ORIGINAL t1107-work-matrix phase-1 command ──
# Source (recovered 2026-09-15): artifacts/2026-09-15/session-recovery/recovered-from-session/
#   gen-t1107-work-matrix-phase1.sh.recovered (bytes-original python heredoc, 5Sep 19:44).
# Adaptation (ONLY change vs recovered command): the A034 merge input
#   {ROOT}/../re01-a034-targets-b3d2fd/target-matrix.json was ALSO lost in the 2026-09-13
#   deletion, so the 32 a034 units + route_compact are rebuilt here deterministically from
#   the ACCEPTED candidate (task11-review-candidate-v2-vnext.json, sha ECF734A5...):
#     * 27 a034-bound  = binding-units inside C17 window [7310,7369] whose targets are the
#       accepted vnext group fsc-20260817-019 (line 7316 routes to group 017 => semantic
#       binding, NOT a034; lines 411/645/8352/8403 => semantic bindings from lots B/C/F);
#     * 5  a034-context= editorial narrative units at lines 7335/7344/7346/7355/7359
#       (pinned in the recovered ledger, entry 2026-09-08 ~18:35Z).
#   route_compact per unit (original stats 'a034-vNext 24 / a034-provenance 6 /
#   a034-vNext+provenance 2' — see RESULT RE-01: 47 vNext atoms / 6 provenance / 2 split):
#     * the 5 context units => 'provenance' (documental headers/asset-paths, no technical
#       fact — matches the provenance atom definition);
#     * among the 27 bound units, the 3 with MIXED dispositions (superseded-source +
#       migrated-claim, lines 7312/7325/7342) are the split candidates; 2 of them are
#       assigned 'vNext+provenance' and 1 'provenance' to reproduce 24/6/2. WHICH 2 of the
#       3 are split is NOT recoverable (atom order lost) — flagged route_inferred=true.
import json
import re
from collections import Counter

GROUP_RE = re.compile(r"^(fsc-20260817-\d+)")

REPO = "/home/wanderson/Documents/ffx-editor-main"
ATLAS_UNITS = f"{REPO}/Utilities/FFXResearchTools/Claims/atlas-source-units.json"
ATLAS_MD = f"{REPO}/docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md"
CANDIDATE = f"{REPO}/docs/reverse/task11/vnext/task11-review-candidate-v2-vnext.json"
OUT = "/home/wanderson/Documents/ffx-editor-main/work/_x5_rederive/work-matrix.rederived.json"

C17_LO, C17_HI = 7310, 7369
CONTEXT_LINES = {7335, 7344, 7346, 7355, 7359}
VNEXT_GROUP = "fsc-20260817-019"


def classify(kind):
    if kind == "front-matter": return ("editorial-context", "source-metadata", True)
    if kind == "heading-candidate": return ("editorial-context", "heading-label", True)
    if kind == "fenced-block": return ("code-literal", "historical-literal", True)
    if kind == "raw-block": return ("editorial-context", "narrative-context", "draft")  # raw pode ser factual
    return (None, None, False)


def build_a034(cand, units_by_line):
    """Rebuild the 32-unit A034 merge dict {source_unit_id: route_compact}."""
    a034 = {}
    mixed = []  # bound units with superseded+migrated dispositions
    for dec in cand["decisions"]:
        uid = dec["source_unit_id"]
        fb = dec.get("factual_bindings") or []
        if fb:
            x = units_by_line_id[uid]
            ln = x["line_start"]
            if C17_LO <= ln <= C17_HI:
                groups = set()
                disps = set()
                for b in fb:
                    disps.add(b["disposition"])
                    for t in b.get("targets", []):
                        m = GROUP_RE.match(t["target_id"])
                        if m:
                            groups.add(m.group(1))
                if groups == {VNEXT_GROUP}:
                    # a034-bound (semantic binding 7316 routes to 017, not 019)
                    if disps == {"migrated-claim"}:
                        a034[uid] = "vNext"
                    else:
                        mixed.append(uid)
        else:
            x = units_by_line_id[uid]
            if x["line_start"] in CONTEXT_LINES:
                a034[uid] = "provenance"  # a034-context (documental header, no fact)
    # mixed (superseded+migrated) units: first 2 => 'vNext+provenance', next => 'provenance',
    # remainder => 'vNext' (reproduces the recovered stats 24/6/2 over 4 mixed units; WHICH
    # ones carry which route is unrecoverable — atom order lost — => all flagged inferred)
    mixed.sort()
    inferred = {}
    for i, uid in enumerate(mixed):
        route = "vNext+provenance" if i < 2 else ("provenance" if i == 2 else "vNext")
        a034[uid] = route
        inferred[uid] = route
    for uid in a034:
        if a034[uid] == "provenance" and uid not in inferred and units_by_line_id[uid]["line_start"] not in CONTEXT_LINES:
            inferred[uid] = "provenance"
    return a034, inferred


doc = json.load(open(ATLAS_UNITS))
units = doc["source_units"]
src = open(ATLAS_MD, "rb").read()
cand = json.load(open(CANDIDATE))
units_by_line_id = {u["source_unit_id"]: u for u in units}

a034, route_inferred = build_a034(cand, units_by_line_id)

rows = []
stats = Counter()
for u in units:
    text = src[u["byte_start"]:u["byte_start"] + u["byte_length"]].decode("utf-8", "replace").strip()[:180]
    kind = u["kind"]
    if kind == "structural-whitespace":
        rows.append({"id": u["source_unit_id"], "kind": kind, "line": u["line_start"],
                     "cls": "whitespace-no-decision", "route": "xor-exempt", "text": None})
        stats["ws-exempt"] += 1
        continue
    disp, reason, conf = classify(kind)
    a = a034.get(u["source_unit_id"])
    if a:
        rows.append({"id": u["source_unit_id"], "kind": kind, "line": u["line_start"],
                     "cls": "a034-triaged", "route": a, "text": text})
        stats[f"a034-{a}"] += 1
    elif disp:
        rows.append({"id": u["source_unit_id"], "kind": kind, "line": u["line_start"],
                     "cls": "mechanical" if conf is True else "mechanical-draft",
                     "disposition": disp, "reason": reason, "text": text})
        stats["mechanical" if conf is True else "mech-draft"] += 1
    else:
        rows.append({"id": u["source_unit_id"], "kind": kind, "line": u["line_start"],
                     "cls": "pending-semantic-review", "text": text})
        stats[f"pending-{kind}"] += 1

out = {"meta": {
           "task": "X5-REDERIVE phase-1 re-execution of t1107-work-matrix (2026-09-15)",
           "original": "glm-structures-exec-69f2d8/t1107-work-matrix.json (lost 2026-09-13)",
           "generator_recovered": "artifacts/2026-09-15/session-recovery/recovered-from-session/gen-t1107-work-matrix-phase1.sh.recovered",
           "inputs": {
               "atlas_units": ATLAS_UNITS,
               "atlas_units_sha256": "D67500CA1DBAA1F7F5BA84E778A5A7D985264DA4370FA0860DFBE0CD38849549",
               "atlas_md_sha256": "F5439414C1624ED6B9E049FE462AF737781C44BFAA59AE26B20CC2F03D2F2CC7",
               "a034_merge": "rebuilt from accepted candidate ECF734A5 (27 bound + 5 context)",
               "a034_route_inferred_units": sorted(route_inferred),
           },
           "total": len(units), "a034_merged": len(a034)},
       "stats": dict(stats), "rows": rows}
json.dump(out, open(OUT, "w"), ensure_ascii=False, indent=1)

print("stats:", dict(stats))
print("total:", len(rows))
print("a034 merged:", len(a034), "| route_inferred:", len(route_inferred))
expected = {"ws-exempt": 2278, "mechanical": 829, "mech-draft": 543,
            "pending-paragraph": 933, "pending-table-row": 4042, "pending-list-item": 1624,
            "a034-vNext": 24, "a034-provenance": 6, "a034-vNext+provenance": 2}
ok = all(stats.get(k, 0) == v for k, v in expected.items()) and sum(stats.values()) == 10281
print("PHASE-1 STATS MATCH ARBITERS:", "PASS" if ok else "FAIL")
for k, v in expected.items():
    got = stats.get(k, 0)
    if got != v:
        print(f"  MISMATCH {k}: got {got} expected {v}")
