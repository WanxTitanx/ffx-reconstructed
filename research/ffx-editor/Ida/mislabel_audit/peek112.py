import json, re
recs={}
for l in open("work/_mislabel_audit/export_all.jsonl"):
    d=json.loads(l); recs.setdefault(d.get("addr"),d)
funcs = json.load(open("work/_mislabel_audit/ffx_funcs_all.json"))
band=[f for f in funcs if 0xB00000<=int(f["addr"],16)<=0xB0FFFF and f["name"].startswith("FFX_Sound")]
seen=set()
for f in band[:8]:
    a=f["addr"]; asm=(recs.get(a) or {}).get("asm","")
    m=re.search(r"push\s+offset\s+(\S+)",asm); mm=re.search(r"mov\s+(\S+),\s*offset",asm)
    print(a,f["name"],"| push:",m.group(1) if m else "-","| movdst:",(mm.group(1) if mm else "-"))
