import sys, json, re
sys.path.insert(0, "work/_mislabel_audit")
funcs = json.load(open("work/_mislabel_audit/ffx_funcs_all.json"))
band = [f for f in funcs if 0xAF8000 <= int(f["addr"],16) <= 0xB0FFFF and f["name"].startswith("FFX_Sound")]
print("remaining FFX_Sound_* in band:", len(band))
recs={}
for l in open("work/_mislabel_audit/export_all.jsonl"):
    d=json.loads(l); recs.setdefault(d.get("addr"),d)
sus=[]; tiny_ph=0
for f in band:
    a=f["addr"]; r=recs.get(a); asm=(r or {}).get("asm","")
    body = "\n".join(l for l in asm.splitlines()[1:] if re.match(r"\s*[0-9a-f]+\s+\S",l))
    nops = len(body.splitlines())
    calls = re.findall(r"\b(?:call|jmp)\s+(\S+)", asm)
    soundish = [c for c in calls if re.match(r"FFX_(Sound|Se|Music|Fmod|Stream|Spu|Arai|Sfx)", c)]
    if nops <= 14 and not soundish and calls:
        sus.append((a, f["name"], nops, calls[:3]))
print("tiny w/ non-sound calls:", len(sus))
for s in sus: print("  ", s[0], s[1], "ops",s[2], "calls", s[3])
