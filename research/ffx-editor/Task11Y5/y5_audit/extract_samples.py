#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Y5 audit — seeded sampler. READ-ONLY over drafts/artifacts/atlas.
Extracts per-skip-class samples + a draft-quality sample into _samples.json
for manual inspection. Seed fixed => reproducible.
"""
import json, glob, hashlib, os, random, re, collections

REPO = "/home/wanderson/Documents/ffx-editor-main"
ART = "/mnt/nvme-samsung/ffx-task-artifacts/glm-structures-exec-69f2d8/y5-drafts"
OUT = os.path.dirname(os.path.abspath(__file__))
SEED = 20260915

rows = json.load(open(f"{ART}/y5-units-reconstruction.json", encoding="utf-8"))
byid = {r["source_unit_id"]: r for r in rows}
batches = json.load(open(f"{ART}/y5-batches.json", encoding="utf-8"))["batches"]
bdef = {b["batch_id"]: b for b in batches}

skips = []          # (batch_id, unit_id, reason)
claims_meta = []    # (batch_id, claim_id, unit_id, claim_text, truncated)
for f in sorted(glob.glob(f"{ART}/drafts/*.units.json")):
    s = json.load(open(f, encoding="utf-8"))
    b = s["batch_id"]
    for x in s["units_skipped"]:
        skips.append((b, x["source_unit_id"], x["reason"]))
    cmap = {u["claim_id"]: u for u in s["units"]}
    d = json.load(open(f.replace(".units.json", ".json"), encoding="utf-8"))
    for c in d["claims"]:
        u = cmap[c["claim_id"]]
        claims_meta.append((b, c["claim_id"], u["source_unit_id"], c["claim_text"], u["truncated"], u["line_start"], u["line_end"], u["derivation"]))

def short_reason(r):
    return r.split(" ")[0]

by_class = collections.defaultdict(list)
for b, u, r in skips:
    by_class[short_reason(r)].append((b, u))

rng = random.Random(SEED)
sample = {}
for cls, lst in sorted(by_class.items()):
    n = min(30, len(lst))
    sample[cls] = sorted(rng.sample(lst, n), key=lambda t: byid[t[1]]["line_start"])

out = {"seed": SEED, "skip_class_sizes": {k: len(v) for k, v in by_class.items()},
       "skip_samples": {}, "a034_all": [], "draft_sample": []}
for cls, lst in sample.items():
    out["skip_samples"][cls] = [
        {"batch": b, "unit": u, "line": byid[u]["line_start"], "kind": byid[u]["kind"],
         "marker": byid[u]["factual_marker"], "text": byid[u]["text"]} for b, u in lst]

# all 8 a034-window skips
for b, u, r in skips:
    if r.startswith("a034-window"):
        rr = byid[u]
        out["a034_all"].append({"batch": b, "unit": u, "line": rr["line_start"],
                                "kind": rr["kind"], "marker": rr["factual_marker"],
                                "text": rr["text"]})
out["a034_all"].sort(key=lambda x: x["line"])

# draft sample: ~40 claims across b12-b23 (the new batches), seeded
new_batches = ["y5-b12-ctb-status","y5-b13-save-payloads","y5-b14-runtime-pc",
               "y5-b15-runtime-ida","y5-b16-noclip-api","y5-b17-format-families",
               "y5-b18-encoder-gaps","y5-b19-magic-dll","y5-b20-workspace-layout",
               "y5-b21-indexes","y5-b22-mateditor-blocks","y5-b23-editorial-misc"]
pool = [c for c in claims_meta if c[0] in new_batches]
ds = rng.sample(pool, 40)
for b, cid, u, text, trunc, ls, le, deriv in sorted(ds, key=lambda t: (t[0], t[5])):
    out["draft_sample"].append({"batch": b, "claim_id": cid, "unit": u, "line": ls,
                                "line_end": le, "derivation": deriv, "truncated": trunc,
                                "claim_text": text, "unit_text": byid[u]["text"]})

json.dump(out, open(f"{OUT}/_samples.json", "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)
print("skip classes:", {k: len(v) for k, v in by_class.items()})
print("sample sizes:", {k: len(v) for k, v in out["skip_samples"].items()})
print("a034:", len(out["a034_all"]), "draft sample:", len(out["draft_sample"]))
print("claims pool b12-b23:", len(pool), "all claims:", len(claims_meta))
