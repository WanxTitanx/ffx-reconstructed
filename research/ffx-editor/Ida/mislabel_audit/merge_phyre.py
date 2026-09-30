import sys, json
sys.path.insert(0, "work/_mislabel_audit")
from apply_renames import call, init
init()
plan=json.load(open("work/_mislabel_audit/phyre_plan.json"))
done=set(json.load(open("work/_mislabel_audit/rename_result.json"))["renamed"])
plan=[p for p in plan if p["addr"].lower() not in {a.lower() for a in done}]
print("band plan after excluding done:",len(plan))
# verify current names still FFX_Sound*
cur={}
addrs=[p["addr"] for p in plan]
for i in range(0,len(addrs),50):
    for t in call("lookup_funcs",{"queries":addrs[i:i+50]}):
        try:
            d=json.loads(t)
            for e in d:
                if e.get("fn"): cur[e["fn"]["addr"].lower()]=e["fn"]["name"]
        except Exception: pass
todo=[];skip=[]
for p in plan:
    now=cur.get(p["addr"].lower())
    if now==p["old"]: todo.append(p)
    else: skip.append((p["addr"],p["old"],now))
print("still-old-name:",len(todo),"| drifted/other:",len(skip))
for s in skip[:30]: print("  drift",s)
json.dump(todo,open("work/_mislabel_audit/phyre_todo.json","w"),indent=1)
