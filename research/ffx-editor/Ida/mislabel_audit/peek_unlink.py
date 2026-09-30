import json, re
recs={}
for l in open("work/_mislabel_audit/export_all.jsonl"):
    d=json.loads(l); recs.setdefault(d.get("addr"),d)
for a in ["0xb0a570","0xb0a6a0","0xb09510","0xaf0850","0xaf8df0","0xaf3e70","0xaea7b0","0xaf0000"]:
    print("="*50,a)
    print((recs.get(a) or {}).get("asm","")[:420])
