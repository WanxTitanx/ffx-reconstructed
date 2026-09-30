import sys, json
sys.path.insert(0, "work/_mislabel_audit")
from apply_renames import call, init
init()
plan = json.load(open("work/_mislabel_audit/rename_plan.json"))
res = json.load(open("work/_mislabel_audit/rename_result.json"))
todo = res["renamed"]
cur = {}
for i in range(0, len(todo), 50):
    for t in call("lookup_funcs", {"queries": todo[i:i+50]}):
        try:
            d = json.loads(t)
            for e in d:
                if e.get("fn"): cur[e["fn"]["addr"].lower()] = e["fn"]["name"]
        except Exception: pass
bymap = {p["addr"].lower(): p for p in plan}
ok, bad = 0, []
for a in todo:
    want = bymap[a]["new"]
    got = cur.get(a.lower())
    if got == want: ok += 1
    else: bad.append((a, want, got))
print("applied OK:", ok, "| still old/different:", len(bad))
for a,w,g in bad[:20]: print("  ", a, "want", w, "got", g)
