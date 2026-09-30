import sys, json, re
funcs = json.load(open("work/_mislabel_audit/ffx_funcs_all.json"))
recs={}
for l in open("work/_mislabel_audit/export_all.jsonl"):
    d=json.loads(l); recs.setdefault(d.get("addr"),d)
band = [f for f in funcs if 0xAF0000 <= int(f["addr"],16) <= 0xB0FFFF and f["name"].startswith("FFX_Sound")]
print("FFX_Sound in AF-B0:", len(band))
real=[]; phy=[]
for f in band:
    a=f["addr"]; asm=(recs.get(a) or {}).get("asm","")
    calls = re.findall(r"\b(?:call|jmp)\s+(\S+)", asm)
    soundish=[c for c in calls if re.match(r"FFX_(Sound|Se|Music|Fmod|Stream|Spu|Arai|Sfx|Voice)",c)]
    nops=len([l for l in asm.splitlines()[1:] if re.match(r"\s*[0-9a-f]+\s+\S",l)])
    (real if (soundish or nops>20) else phy).append((a,f["name"],nops,calls[:3]))
print("real-ish:",len(real)," phyre-ish:",len(phy))
print("-- possible REAL (bigger or sound-call) --")
for r in real[:40]: print("  ",r[0],r[1],"ops",r[2],r[3])
