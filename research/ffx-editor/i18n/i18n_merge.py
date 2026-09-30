#!/usr/bin/env python3
# i18n_merge.py - junta o i18n_out.jsonl (save incremental) nos 7 *_result.json
# (2026-08-14, Jarvis-MAGIC/Shiva). jobmap (work/i18n_jobmap.json) mapeia
# job_idx -> source. Extrai o array JSON da resposta (tolera fences markdown).

import json
import pathlib
import re

WORK = pathlib.Path(__file__).parent.parent / "work"

jobmap = json.loads((WORK / "i18n_jobmap.json").read_text(encoding="utf-8"))
records = []
for line in (WORK / "i18n_out.jsonl").read_text(encoding="utf-8").splitlines():
    if line.strip():
        records.append(json.loads(line))

results_by_source = {}
for jm in jobmap:
    results_by_source[jm["source"]] = []

def extract_array(text):
    if not text:
        return None
    t = text.strip()
    # tira fences markdown
    t = re.sub(r"^```(?:json)?\s*", "", t)
    t = re.sub(r"\s*```$", "", t)
    start, end = t.find("["), t.rfind("]")
    if start == -1 or end == -1 or end <= start:
        return None
    try:
        return json.loads(t[start : end + 1])
    except Exception:
        return None

ok_jobs = 0
bad_jobs = []
for r in records:
    idx = r.get("job")
    if idx is None or idx >= len(jobmap):
        bad_jobs.append(("sem-job", str(idx)))
        continue
    src = jobmap[idx]["source"]
    if not r.get("ok"):
        bad_jobs.append(("erro", (r.get("error") or "")[:100]))
        continue
    arr = extract_array(r.get("output", ""))
    if arr is None:
        bad_jobs.append(("sem-array", (r.get("output") or "")[:100]))
        continue
    valid = []
    for item in arr:
        if not isinstance(item, dict) or "file" not in item or "line" not in item:
            continue
        t = item.get("type")
        if t not in ("ui", "log"):
            continue
        if not item.get("en"):
            continue
        valid.append(item)
    results_by_source[src].extend(valid)
    ok_jobs += 1

total = 0
for src_name, _out in [
    ("i18n_s1_chunk0.json", "i18n_s1_chunk0_result.json"),
    ("i18n_s1_chunk1.json", "i18n_s1_chunk1_result.json"),
    ("i18n_s1_chunk2.json", "i18n_s1_chunk2_result.json"),
    ("i18n_s1_chunk3.json", "i18n_s1_chunk3_result.json"),
    ("i18n_s2_ffxlib.json", "i18n_s2_ffxlib_result.json"),
    ("i18n_s3_tools.json", "i18n_s3_tools_result.json"),
    ("i18n_s4_rest.json", "i18n_s4_rest_result.json"),
]:
    items = results_by_source.get(src_name, [])
    total += len(items)
    out_path = WORK / _out
    out_path.write_text(json.dumps(items, ensure_ascii=False, indent=1), encoding="utf-8")
    print(f"{src_name}: {len(items)} itens ui/log -> {_out}")

print(f"---")
print(f"jobs ok: {ok_jobs}/{len(jobmap)} | jobs com problema: {len(bad_jobs)} | total ui/log: {total}")
for kind, detail in bad_jobs[:10]:
    print(f"  [!] {kind}: {detail}")
