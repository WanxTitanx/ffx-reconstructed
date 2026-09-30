import sys, json, re
funcs = json.load(open("work/_mislabel_audit/ffx_funcs_all.json"))
recs={}
for l in open("work/_mislabel_audit/export_all.jsonl"):
    d=json.loads(l); recs.setdefault(d.get("addr"),d)
# all remaining FFX_Sound in band not yet renamed (still start with FFX_Sound)
band = [f for f in funcs if 0xAF0000 <= int(f["addr"],16) <= 0xB0FFFF and f["name"].startswith("FFX_Sound")]
existing={f["name"] for f in funcs}
used=set()

def ecx_global(asm):
    m=re.search(r"mov\s+ecx,\s*(?:dword\s+ptr\s+)?(?:ds:)?([A-Za-z_][\w]*)",asm)
    if not m: m=re.search(r"mov\s+ecx,\s*(0x[0-9A-Fa-f]+|[0-9A-Fa-f]+h?)",asm)
    if m:
        g=m.group(1)
        return re.sub(r"^(unk_|byte_|dword_|word_|loc_|sub_)","",g)[:24]
    return None

def uniq(base):
    n=base; i=0
    while n in existing or n in used:
        i+=1; n=f"{base}_{i}"
    used.add(n); return n

def classify(a, name, asm):
    calls = re.findall(r"\b(?:call|jmp)\s+(\S+)", asm)
    g = ecx_global(asm) or a[2:].upper()
    tgt = calls[-1] if calls else ""
    m=re.search(r"PClassDescriptorForType<\s*([\w:]+(?:::[\w]+)*)\s*>", asm)
    typ = re.sub(r"\W","_",m.group(1).split("::")[-1]) if m else None
    m2=re.search(r"Phyre_PInput(Semantic|JoypadButton|MouseButton|ChannelSemantic)", asm)
    if "PClassDescriptor_ctor" in calls and "PNamespace_GetSingleton" in calls:
        return uniq(f"FFX_Phyre_RegisterClassDesc_{typ or g}")
    if "nullsub" in tgt or re.search(r"nullsub", asm):
        return uniq(f"FFX_Phyre_StaticDtorNoOp_{g}")
    if "PClassDataMemberArray" in tgt or "PClassDataMemberArray" in asm:
        return uniq(f"FFX_Phyre_MemberArrayDtor_{g}")
    if "PClassDataMember_Destructor" in tgt:
        return uniq(f"FFX_Phyre_ClassMemberDtor_{g}")
    if "PClassDescriptor_Destructor" in tgt:
        return uniq(f"FFX_Phyre_ClassDescDtor_{typ or g}")
    if "PAnnotation" in asm:
        return uniq(f"FFX_Phyre_AnnotationStaticDtor_{g}")
    if "Engine_AlignedFree" in calls:
        return uniq(f"FFX_Phyre_StaticListNodeDtor_{g}")
    if "LinkedList_Unlink" in asm or "List_Unlink" in asm or "UnlinkNode" in asm:
        t = (m2.group(0).replace("Phyre_","") if m2 else "List")
        return uniq(f"FFX_Phyre_StaticNodeUnlink_{t}")
    if "_atexit" in calls or "_atexit" in asm:
        ctor=[c for c in calls if re.search(r"[Cc]tor|_Ctor|FindByName",c)]
        t = ctor[0].replace("Phyre_","").replace("_ctorNoCopy","").replace("_Ctor","")[:30] if ctor else g
        return uniq(f"FFX_Phyre_StaticCtor_{t}")
    if "PShaderNode_ctorNoCopy" in calls:
        return uniq(f"FFX_Phyre_StaticCtor_ShaderNode_{g}")
    if "RemoveNodeWithRotation" in asm:
        return uniq(f"FFX_Phyre_TreeNodeRemove_{g}")
    if not calls:
        return uniq(f"FFX_Phyre_StaticRegStruct_{g}")
    t=tgt.replace("Phyre_","").replace("FFX_","")[:30]
    return uniq(f"FFX_Phyre_StaticReg_{t}_{g}")

plan=[]
for f in band:
    a=f["addr"]; asm=(recs.get(a) or {}).get("asm","")
    newn=classify(a,f["name"],asm)
    plan.append({"addr":a,"old":f["name"],"new":newn,
        "evidence":"Phyre static class-registration/dtor region (calls "+
            ",".join(dict.fromkeys(re.findall(r"\b(?:call|jmp)\s+(\S+)",asm)))[:120]+
            "); not a sound function — mislabeled by proximity sweep"})
print("generated:",len(plan))
from collections import Counter
print(Counter(re.sub(r"_[0-9A-F]+$","",p["new"]) for p in plan).most_common(20))
json.dump(plan, open("work/_mislabel_audit/phyre_plan.json","w"), indent=1)
# show samples per category
seen=set()
for p in plan:
    k=re.sub(r"_[0-9A-Fa-f]+$","",p["new"])
    if k not in seen:
        seen.add(k); print("  eg",p["addr"],p["old"],"->",p["new"])
