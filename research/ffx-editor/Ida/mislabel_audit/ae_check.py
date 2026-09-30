import sys, json, re
funcs = json.load(open("work/_mislabel_audit/ffx_funcs_all.json"))
recs={}
for l in open("work/_mislabel_audit/export_all.jsonl"):
    d=json.loads(l); recs.setdefault(d.get("addr"),d)
# lowest soundish addr in AE-B0 and all no-call ones in AE-B0
band=[f for f in funcs if 0xAE0000<=int(f["addr"],16)<=0xB0FFFF and f["name"].startswith(("FFX_Sound","FFX_Fmod","FFX_Spu","FFX_Se","FFX_Music","FFX_Stream","FFX_Voice","FFX_Sfx"))]
print("soundish in AE-B0:",len(band),"| lowest:",hex(min(int(f['addr'],16) for f in band)))
# what is just BELOW AE0000 — the boundary
below=sorted((int(f['addr'],16),f['name']) for f in funcs if 0xAD0000<=int(f['addr'],16)<0xAE0000)
print("--- funcs just below AE0000 (boundary) ---")
for a,n in below[-14:]: print("  ",hex(a),n)
# no-call ones in band: dump asm
nocall=[f for f in band if not re.findall(r"\b(?:call|jmp)\s+(\S+)",(recs.get(f['addr']) or {}).get("asm",""))]
print("no-call count:",len(nocall))
for f in nocall[:12]:
    a=f["addr"]; print("====",a,f["name"])
    print((recs.get(a) or {}).get("asm","")[:380])
