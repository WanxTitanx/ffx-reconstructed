#!/usr/bin/env python3
"""Paginate list_funcs FFX_* until exhausted; save full list."""
import json, os, subprocess, sys

HELPER = "research_tools/Ida/ida_mcp.py"
OUT = "work/_mislabel_audit/ffx_funcs_all.json"

all_funcs = {}
offset = 0
PAGE = 500
while True:
    args = json.dumps({"queries": [{"filter": "FFX_*", "offset": offset, "count": PAGE}]})
    r = subprocess.run(["python3", HELPER, "list_funcs", args],
                       capture_output=True, text=True, timeout=300)
    try:
        data = json.loads(r.stdout)
    except Exception:
        print("PARSE FAIL at offset", offset, file=sys.stderr)
        print(r.stdout[:2000], file=sys.stderr)
        print(r.stderr[:2000], file=sys.stderr)
        break
    got = 0
    for q in data:
        for f in q.get("data", []):
            all_funcs[f["addr"]] = {"addr": f["addr"], "name": f["name"], "size": f["size"]}
            got += 1
    print(f"offset={offset} got={got} total={len(all_funcs)}", flush=True)
    if got < PAGE:
        break
    offset += PAGE

funcs = sorted(all_funcs.values(), key=lambda f: int(f["addr"], 16))
with open(OUT, "w") as fh:
    json.dump(funcs, fh, indent=0)
print("SAVED", len(funcs), "->", OUT)
