#!/usr/bin/env python3
"""Batch-decompile a list of addrs via the pinned-FFX helper; save JSON + .c."""
import json
import sys
import time

sys.path.insert(0, "/home/wanderson/Documents/ffx-editor-main/research_tools")
import _w20_sep_lane as L

ADDRS = [a.strip() for a in sys.argv[1:] if a.strip()]
OUT = "/tmp/w20_decompiles.json"

all_d = {}
try:
    all_d = json.load(open(OUT))
except Exception:
    pass

for a in ADDRS:
    if a in all_d and "code" in all_d[a]:
        continue
    for attempt in range(6):
        txt = L.call("decompile", {"addr": a}, retries=8, timeout=180)
        try:
            d = json.loads(txt)
        except Exception:
            d = {"error": txt[:300]}
        if "code" in d:
            all_d[a] = d
            print("OK", a, len(d["code"]))
            break
        print("RETRY", a, str(d)[:120])
        time.sleep(2)
    json.dump(all_d, open(OUT, "w"))

with open("/tmp/w20_decompiles.c", "w") as f:
    for a, d in all_d.items():
        f.write("===== %s =====\n%s\n\n" % (a, d.get("code", d)))
print("saved", len(all_d), "to", OUT)
