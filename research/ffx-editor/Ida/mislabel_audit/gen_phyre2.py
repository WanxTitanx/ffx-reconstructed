import sys, json, re
funcs = json.load(open("work/_mislabel_audit/ffx_funcs_all.json"))
recs={}
for l in open("work/_mislabel_audit/export_all.jsonl"):
    d=json.loads(l); recs.setdefault(d.get("addr"),d)
band=[f for f in funcs if 0xAEA000<=int(f["addr"],16)<=0xB0FFFF and f["name"].startswith(("FFX_Sound","FFX_Fmod","FFX_Spu","FFX_Se","FFX_Music","FFX_Stream","FFX_Voice","FFX_Sfx"))]
existing={f["name"] for f in funcs}
used=set()
KW={"offset","dword","byte","word","ptr","ds","short","near","unk_","byte_","dword_","word_","qword"}
def globhex(asm):
    # first static operand in mov ecx/dword/..., <opnd>
    for m in re.finditer(r"mov\s+(?:e?cx|e?ax|dword\s+ptr|qword\s+ptr|word\s+ptr|byte\s+ptr)\s*,?\s*(?:dword\s+ptr\s+)?(?:ds:)?([A-Za-z_]\w*|0x[0-9A-Fa-f]+|[0-9A-Fa-f]+h)\b", asm):
        t=m.group(1)
        base=t.split("_",1)[0]+"_" if "_" in t else t
        if t.lower() in KW or t in ("esp","ebp","eax","ecx","edx","ebx","esi","edi"): continue
        mm=re.match(r"(?:unk_|byte_|dword_|word_|qword_|loc_|sub_)?(0x?[0-9A-Fa-f]{5,}|[0-9A-Fa-f]{6,}h?)$", t)
        if mm:
            h=mm.group(1).rstrip("h").lstrip("0x").upper()
            return h
        return t[:22]
    return None
def uniq(b):
    n=b;i=0
    while n in existing or n in used: i+=1;n=f"{b}_{i}"
    used.add(n);return n
plan=[]
for f in band:
    a=f["addr"]; asm=(recs.get(a) or {}).get("asm","")
    calls=re.findall(r"\b(?:call|jmp)\s+(\S+)",asm)
    g=globhex(asm) or a[2:].upper()
    tm=re.search(r"PClassDescriptorForType<\s*([\w:]+)\s*>",asm)
    typ=re.sub(r"\W","_",tm.group(1).split("::")[-1]) if tm else None
    if "PClassDescriptor_ctor" in calls and "SetField" in "".join(calls):
        nm=uniq(f"FFX_Phyre_RegisterClass_{typ or g}")
    elif "PNamespace_GetSingleton" in calls and "PClassDescriptor_ctor" in calls:
        nm=uniq(f"FFX_Phyre_RegisterClassDesc_{typ or g}")
    elif not calls and re.search(r"mov\s+dword\s+ptr\s+\w+,\s*0\b",asm):
        nm=uniq(f"FFX_Phyre_StaticZero_{g}")
    elif not calls:
        nm=uniq(f"FFX_Phyre_StaticStub_{g}")
    elif re.search(r"nullsub_\d+",asm):
        nm=uniq(f"FFX_Phyre_StaticDtorNoOp_{g}")
    elif "PClassDataMemberArray" in asm:
        nm=uniq(f"FFX_Phyre_MemberArrayDtor_{g}")
    elif "PClassDataMember_Destructor" in asm:
        nm=uniq(f"FFX_Phyre_ClassMemberDtor_{g}")
    elif "PClassDescriptor_Destructor" in asm:
        nm=uniq(f"FFX_Phyre_ClassDescDtor_{typ or g}")
    elif "PAnnotation" in asm:
        nm=uniq(f"FFX_Phyre_AnnotationStaticDtor_{g}")
    elif "Engine_AlignedFree" in calls:
        nm=uniq(f"FFX_Phyre_StaticListNodeDtor_{g}")
    elif "LinkedList_Unlink" in asm or "List_Unlink" in asm or "UnlinkNode" in asm:
        t=re.search(r"Phyre_(PInput\w+|PLight\w+|P\w+?)_LinkedList|Phyre_(\w+?)_List_Unlink|(\w+?)_UnlinkNode",asm)
        tt=(t.group(1) or t.group(2) or t.group(3)) if t else "List"
        nm=uniq(f"FFX_Phyre_StaticListUnlink_{tt}")
    elif "_atexit" in calls:
        ctor=[c for c in calls if re.search(r"tor|FindByName|Init",c)]
        tt=re.sub(r"\W","_", (ctor[0].replace("Phyre_","") if ctor else g))[:26]
        nm=uniq(f"FFX_Phyre_StaticCtor_{tt}")
    elif "ctorNoCopy" in "".join(calls) or "_Ctor" in "".join(calls):
        nm=uniq(f"FFX_Phyre_StaticCtor_{g}")
    elif "RemoveNodeWithRotation" in asm:
        nm=uniq(f"FFX_Phyre_TreeNodeRemove_{g}")
    else:
        t=calls[-1].replace("Phyre_","").replace("FFX_","")
        t=re.sub(r"\W","_",t)[:24]
        nm=uniq(f"FFX_Phyre_StaticReg_{t}_{g}")
    plan.append({"addr":a,"old":f["name"],"new":nm,
        "evidence":"Phyre runtime class-registration/static-init region 0xAEA7B0-0xB0FFFF; body calls "+", ".join(dict.fromkeys(calls))[:110]+" — not a sound function; mislabeled by proximity sweep"})
json.dump(plan,open("work/_mislabel_audit/phyre_plan.json","w"),indent=1)
print("generated",len(plan))
from collections import Counter
for k,c in Counter(re.sub(r"_\d+$","",re.sub(r"_[0-9A-F]{6,}$","",p["new"])) for p in plan).most_common(30):
    print("  ",c,k)
