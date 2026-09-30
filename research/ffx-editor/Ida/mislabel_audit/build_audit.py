import json
plan=json.load(open("work/_mislabel_audit/rename_plan.json"))
phyre=json.load(open("work/_mislabel_audit/phyre_plan.json"))
res=json.load(open("work/_mislabel_audit/rename_result.json"))
pres=json.load(open("work/_mislabel_audit/phyre_result.json"))
sus=json.load(open("work/_mislabel_audit/suspects.json"))
done={a.lower() for a in res["renamed"]}|{a.lower() for a in pres["renamed"]}
byaddr={}
def add(addr,old,new,verdict,ev):
    a=addr.lower()
    if a in byaddr: return
    byaddr[a]={"addr":addr,"old":old,"new":new if verdict=="CONFIRMED" else None,"verdict":verdict,"evidence":ev}
# prefer rename_plan (round-1 applied names)
for p in plan:
    v="CONFIRMED" if p["addr"].lower() in done else "SKIPPED"
    ev=p["evidence"]+("" if v=="CONFIRMED" else " | skipped: already DEAD_-flagged by parallel lane")
    add(p["addr"],p["old"],p["new"],v,ev)
for p in phyre:
    v="CONFIRMED" if p["addr"].lower() in done else "SKIPPED"
    ev=p["evidence"]+("" if v=="CONFIRMED" else " | skipped: already DEAD_-flagged by parallel lane")
    add(p["addr"],p["old"],p["new"],v,ev)
for s in sus: add(s["addr"],s["old"],None,"SUSPECTED",s["evidence"])
for a,n,why in [
    ("0x8783a0","FFX_Atel_SaveRamToFile","opens file + serializes RAM — real save op"),
    ("0x878410","FFX_Atel_LoadRamFromFile","opens file + reads — real load op"),
    ("0x7e5be0","FFX_File_GetFileSize_structural","builds path + seek — real file-size getter"),
    ("0x8881e0","FFX_Save_GetFileOpenMode","returns unk_13301F0 — true getter"),
    ("0x8883a0","FFX_Save_SetFileOpenMode","writes unk_13301F0 — true setter"),
    ("0x8ab300","FFX_Battle_CheckFlagId","bit-test word table 1130F1C — real flag check"),
    ("0x8d3720","FFX_SphereGrid_GetMenuActiveFlag","returns global flag — true getter"),
    ("0x8ab1d0","FFX_BootScene_SetFadeSpeed","writes fade-speed field — true setter"),
]: add(a,n,None,"VALID",why)
audit=list(byaddr.values())
conf=[x for x in audit if x["verdict"]=="CONFIRMED"]
out={"generated":"2026-09-16","lane":"Jarvis-DEVIN","audit":"FFX_* mislabel audit (FFX-STRUCTURES leva 7)",
 "coverage":{"total_ffx_funcs":13556,"game_band":11081,
   "confirmed":len(conf),
   "skipped_deadflagged":len([x for x in audit if x['verdict']=='SKIPPED']),
   "suspected":len(sus),"verified_valid_sample":8},
 "records":sorted(audit,key=lambda x:int(x["addr"],16))}
json.dump(out,open("work/_mislabel_audit/mislabel_audit.json","w"),indent=1)
print("audit:",out["coverage"],"total records",len(audit))
# count phre vs non
print("phyre renames:",sum(1 for x in conf if x['new'] and x['new'].startswith('FFX_Phyre')))
