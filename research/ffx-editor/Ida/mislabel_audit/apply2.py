import sys, json
sys.path.insert(0, "work/_mislabel_audit")
from apply_renames import call, init
init()
todo=json.load(open("work/_mislabel_audit/phyre_todo.json"))
print("applying",len(todo))
for i in range(0,len(todo),25):
    batch=[{"addr":p["addr"],"name":p["new"]} for p in todo[i:i+25]]
    for t in call("rename",{"batch":{"func":batch}}): pass
    print("  renamed",min(i+25,len(todo)),flush=True)
items=[{"addr":p["addr"],
        "comment":f"// MISLABEL-FIX: was {p['old']}; real role: {p['evidence']} [Jarvis-DEVIN mislabel-audit 2026-09-16]"}
       for p in todo]
for i in range(0,len(items),25):
    for t in call("append_comments",{"items":items[i:i+25]}): pass
    print("  comments",min(i+25,len(items)),flush=True)
# verify
cur={}
addrs=[p["addr"] for p in todo]
for i in range(0,len(addrs),50):
    for t in call("lookup_funcs",{"queries":addrs[i:i+50]}):
        try:
            d=json.loads(t)
            for e in d:
                if e.get("fn"): cur[e["fn"]["addr"].lower()]=e["fn"]["name"]
        except Exception: pass
bm={p["addr"].lower():p["new"] for p in todo}
ok=sum(1 for a in addrs if cur.get(a.lower())==bm[a.lower()])
print("verified applied:",ok,"of",len(todo))
json.dump({"renamed":addrs},open("work/_mislabel_audit/phyre_result.json","w"),indent=1)
