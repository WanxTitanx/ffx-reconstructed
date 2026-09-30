import sys, json, re
funcs = json.load(open("work/_mislabel_audit/ffx_funcs_all.json"))
recs={}
for l in open("work/_mislabel_audit/export_all.jsonl"):
    d=json.loads(l); recs.setdefault(d.get("addr"),d)
band=[f for f in funcs if 0xAEA000<=int(f["addr"],16)<=0xB0FFFF and f["name"].startswith(("FFX_Sound","FFX_Fmod","FFX_Spu","FFX_Se","FFX_Music","FFX_Stream","FFX_Voice","FFX_Sfx"))]
existing={f["name"] for f in funcs}
used=set()
def uniq(b):
    n=b;i=0
    while n in existing or n in used: i+=1;n=f"{b}_{i}"
    used.add(n);return n
def clean_sym(s):
    s=re.sub(r"^p_\?\?_7","",s); s=re.sub(r"@@6B@.*$","",s)   # p_??_7Type@NS@@6B@ -> Type@NS
    s=re.sub(r"@.*$","",s); s=re.sub(r"^(unk_|byte_|dword_|word_|qword_|loc_|sub_|a)","",s)
    s=re.sub(r"\W","",s); return s[:28]
def obj(asm):
    # first 'offset <sym>' push OR 'mov ecx, <glob>' OR 'mov <glob>,'
    for pat in (r"push\s+offset\s+([A-Za-z_?][\w?@.]*)", r"mov\s+ecx,\s*(?:dword\s+ptr\s+)?([A-Za-z_]\w*|0x[0-9A-Fa-f]+)", r"mov\s+([A-Za-z_]\w*|0x[0-9A-Fa-f]+)\s*,"):
        m=re.search(pat,asm)
        if m:
            c=clean_sym(m.group(1))
            if c and c.lower() not in ("dword","byte","word","offset","ptr","short"): return c
    return None
plan=[]
for f in band:
    a=f["addr"]; asm=(recs.get(a) or {}).get("asm","")
    calls=re.findall(r"\b(?:call|jmp)\s+(\S+)",asm)
    g=obj(asm) or a[2:].upper()
    tm=re.search(r"PClassDescriptorForType<\s*([\w:]+)\s*>",asm)
    typ=re.sub(r"\W","_",tm.group(1).split("::")[-1]) if tm else None
    sm=re.search(r"offset\s+a([A-Z]\w+)",asm)   # 'aKeyNumpad2' -> KeyNumpad2
    sname=sm.group(1)[:24] if sm else None
    kind=None
    if "PClassDescriptor_ctor" in calls and re.search(r"SetField",asm):
        kind=f"FFX_Phyre_RegisterClass_{typ or g}"
    elif "PNamespace_GetSingleton" in calls and ("PClassDescriptor_ctor" in calls or "parentCD" in asm):
        kind=f"FFX_Phyre_RegisterClassDesc_{typ or g}"
    elif not calls and re.search(r"mov\s+dword\s+ptr\s+\w+,\s*0\b",asm):
        kind=f"FFX_Phyre_StaticZero_{g}"
    elif not calls:
        kind=f"FFX_Phyre_StaticStub_{g}"
    elif re.search(r"nullsub_\d+",asm):
        kind=f"FFX_Phyre_StaticDtorNoOp_{g}"
    elif "PClassDataMemberArray" in asm:
        kind=f"FFX_Phyre_MemberArrayDtor_{g}"
    elif "PClassDataMember_Destructor" in asm:
        kind=f"FFX_Phyre_ClassMemberDtor_{g}"
    elif "PClassDescriptor_Destructor" in asm:
        kind=f"FFX_Phyre_ClassDescDtor_{typ or g}"
    elif "PAnnotation" in asm:
        kind=f"FFX_Phyre_AnnotationStaticDtor_{g}"
    elif "LinkedList_Unlink" in asm or "List_Unlink" in asm or "UnlinkNode" in asm:
        t=re.search(r"Phyre_(PInput\w+?Semantic|PInput\w+|PLight\w+|P\w+?)_(?:LinkedList_)?Unlink|Phyre_(\w+)_List_Unlink",asm)
        tt=(t.group(1) or t.group(2)) if t else g
        kind=f"FFX_Phyre_StaticObjDtor_{tt or g}"
    elif "Engine_AlignedFree" in calls:
        kind=f"FFX_Phyre_StaticListNodeDtor_{g}"
    elif "_atexit" in calls:
        tt=sname or g
        kind=f"FFX_Phyre_StaticCtor_{tt}"
    elif re.search(r"ctorNoCopy|_Ctor\b",asm):
        kind=f"FFX_Phyre_StaticCtor_{sname or g}"
    elif "RemoveNodeWithRotation" in asm:
        kind=f"FFX_Phyre_TreeNodeRemove_{g}"
    elif re.search(r"SEH_|security_cookie",asm) and ("GetDefaultPool" in calls or "parentCD" in asm or "push" in asm):
        kind=f"FFX_Phyre_ClassDescArrayCtor_{g}"
    else:
        t=re.sub(r"\W","_",calls[-1].replace("Phyre_","").replace("FFX_",""))[:24] if calls else g
        kind=f"FFX_Phyre_StaticReg_{t}_{g}"
    plan.append({"addr":a,"old":f["name"],"new":uniq(kind),
        "evidence":"Phyre runtime class-registration/static-init region 0xAEA7B0-0xB0FFFF; calls "+", ".join(dict.fromkeys(calls))[:110]+" — not sound; mislabeled by proximity sweep"})
json.dump(plan,open("work/_mislabel_audit/phyre_plan.json","w"),indent=1)
print("generated",len(plan),"unique")
from collections import Counter
for k,c in Counter(re.sub(r"_\d+$","",p["new"]) for p in plan).most_common(30): print("  ",c,k)
