import sys, json, re
funcs = json.load(open("work/_mislabel_audit/ffx_funcs_all.json"))
recs={}
for l in open("work/_mislabel_audit/export_all.jsonl"):
    d=json.loads(l); recs.setdefault(d.get("addr"),d)
# check sound funcs in the big non-AF/B0 clusters
for band_lo,band_hi,tag in [(0x670000,0x68FFFF,"0x67"),(0x700000,0x71FFFF,"0x70"),(0x810000,0x82FFFF,"0x81"),(0x880000,0x89FFFF,"0x88"),(0xAE0000,0xAFFFFF,"0xAE")]:
    grp=[f for f in funcs if band_lo<=int(f["addr"],16)<=band_hi and f["name"].startswith(("FFX_Sound","FFX_Fmod","FFX_Spu","FFX_Se"))]
    if not grp: continue
    real=phy=0
    for f in grp:
        a=f["addr"]; asm=(recs.get(a) or {}).get("asm","")
        calls=re.findall(r"\b(?:call|jmp)\s+(\S+)",asm)
        soundish=[c for c in calls if re.match(r"FFX_(Sound|Se|Music|Fmod|Stream|Spu|Arai|Sfx|Voice|Audio)",c)]
        ph=[c for c in calls if c.startswith(("Phyre_","PClass","PAnnotation","PArray","PLight","PInput","PText","PShader","nullsub","_atexit","Engine_AlignedFree"))]
        if ph and not soundish: phy+=1
        else: real+=1
    print(f"{tag}: total={len(grp)} phyre-only={phy} other={real}")
    # sample a few 'other'
    samp=0
    for f in grp:
        a=f["addr"]; asm=(recs.get(a) or {}).get("asm","")
        calls=re.findall(r"\b(?:call|jmp)\s+(\S+)",asm)
        soundish=[c for c in calls if re.match(r"FFX_(Sound|Se|Music|Fmod|Stream|Spu|Arai|Sfx|Voice|Audio)",c)]
        ph=[c for c in calls if c.startswith(("Phyre_","PClass","PAnnotation","PArray","PLight","PInput","PText","PShader","nullsub","_atexit","Engine_AlignedFree"))]
        if not(ph and not soundish) and samp<6:
            samp+=1; print("   real? ",a,f["name"],"calls",calls[:5])
