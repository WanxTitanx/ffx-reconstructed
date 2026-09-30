#!/usr/bin/env python3
"""decide2.py — final signature proposals for all 97 candidates."""
import json, re, os, sys

frames = json.load(open("stack_frames.json"))
protos = json.load(open("caller_protos.json"))
REGS = ["eax","ebx","ecx","edx","esi","edi"]
ALIAS = {"al":"eax","ah":"eax","ax":"eax","bl":"ebx","bh":"ebx","bx":"ebx",
         "cl":"ecx","ch":"ecx","cx":"ecx","dl":"edx","dh":"edx","dx":"edx",
         "si":"esi","di":"edi"}
def norm(r): return ALIAS.get(r,r)
re_insn = re.compile(r"^([0-9a-f]+)\s+(\w+)\s*(.*)$")

def get_args(addr):
    fr = frames.get(addr.lower()) or frames.get(addr) or {}
    vars = fr.get("vars") or []
    ret = None
    for v in vars:
        if v["name"] == "__return_address": ret = int(v["offset"],16)
    if ret is None: return []
    out = []
    for v in vars:
        o = int(v["offset"],16)
        if o > ret:
            out.append((o-ret-4, v["name"], v.get("type","int")))
    out.sort()
    return out

def run(path):
    ins=[]
    for ln in open(path).read().splitlines()[2:]:
        m=re_insn.match(ln)
        if m: ins.append((m.group(1),m.group(2),m.group(3).split(";")[0].strip()))
    return ins

def analyze(addr):
    ins = run(f"disasm/{addr}.asm")
    reg_src={}
    pushes=[]           # (value-desc) rolling since last call
    call_after={}       # call addr -> pushed args
    arg_to_disp=set()   # arg names pushed to dispatcher
    arg_deref={}        # arg name -> offsets derefed (via reg loaded from arg)
    arg_direct_deref={} # arg name -> [ebp+arg+X]? rare
    eax_hist=[]
    ecx_used=False; edx_used=False
    ecx_first_read=None; edx_first_read=None
    disp_offs=set()
    other_offs={}       # src->offs
    ecx_written=False; edx_written=False
    for a,mn,ops in ins:
        parts=[p.strip() for p in ops.split(",")]
        # reg read tracking for ecx/edx (before first write)
        for r,wrflag in (("ecx",ecx_written),("edx",edx_written)):
            if not wrflag and re.search(r"\b"+r+r"\b", ops):
                iswrite = mn in ("mov","xor","sub","add","lea","pop","movzx","movsx","or","and","inc","dec","shl","shr","neg","not") and parts and parts[0]==r
                if not iswrite:
                    if r=="ecx":
                        ecx_used=True; ecx_first_read=ecx_first_read or (a,ops)
                    else:
                        edx_used=True; edx_first_read=edx_first_read or (a,ops)
        if mn=="push":
            pushes.append(ops)
        # mem deref offsets per source reg
        for mm in re.finditer(r"\[(e[a-d]x|e[sd]i)([+-])([0-9A-Fa-f]+)h\]",ops):
            b=norm(mm.group(1)); off=int(mm.group(3),16)*(1 if mm.group(2)=="+" else -1)
            src=reg_src.get(b)
            if src=="dispatch": disp_offs.add(off)
            elif src and src.startswith("arg:"): arg_deref.setdefault(src[4:],set()).add(off)
            elif src in ("ecx","edx"):
                other_offs.setdefault(src,set()).add(off)
        if mn=="mov" and len(parts)>=2:
            d,s=parts[0],parts[1]
            if d in REGS or d=="ebp" or d=="esp":
                if s=="eax" and reg_src.get("eax")=="dispatch": reg_src[d]="dispatch"
                elif s in reg_src: reg_src[d]=reg_src[s]
                elif s in ("ecx","edx") and s not in reg_src: reg_src[d]=s
                else:
                    am=re.match(r"(?:dword ptr |byte ptr |word ptr )?\[ebp\+(\w+)\]",s)
                    reg_src[d]="arg:"+am.group(1) if am else "?"
            if d in ("ecx","edx"):
                if d=="ecx": ecx_written=True
                else: edx_written=True
        elif mn in ("movzx","movsx") and len(parts)>=2:
            if parts[0] in reg_src or parts[0] in REGS:
                s=parts[1]
                am=re.match(r"(?:dword ptr |byte ptr |word ptr )?\[ebp\+(\w+)\]",s)
                reg_src[parts[0]]="arg:"+am.group(1) if am else "?"
        elif mn=="lea" and len(parts)>=2 and parts[0] in REGS:
            mm=re.search(r"\[(e[a-d]x|e[sd]i)([+-])([0-9A-Fa-f]+)h\]",parts[1])
            reg_src[parts[0]]=reg_src.get(norm(mm.group(1)),"?") if mm else "?"
        elif mn=="pop" and parts and parts[0] in REGS:
            reg_src[parts[0]]="stack"
        elif mn=="call":
            if pushes: call_after[a]=list(pushes)
            if "AccessCurrentActorData" in ops:
                reg_src["eax"]="dispatch"
                for p in pushes:
                    am=re.match(r"(?:dword ptr )?\[ebp\+(\w+)\]",p)
                    if am: arg_to_disp.add(am.group(1))
            else:
                reg_src["eax"]="callret"
            reg_src["ecx"]="?"; reg_src["edx"]="?"
            ecx_written=True; edx_written=True
            pushes=[]
        elif mn in ("xor","sub","add","imul","shl","shr","and","or","inc","dec","neg","not","cdq","sete","setne","setz","setnz","setb","seta","setbe","setae","setl","setge","setle","setg","mul","div","idiv","xchg","bswap","xadd","cmp","test"):
            if parts and parts[0] in REGS and mn not in ("cmp","test"):
                if mn=="mov": pass
                reg_src[parts[0]]="?"
            if parts and parts[0] in ("ecx","edx"):
                if parts[0]=="ecx": ecx_written=True
                else: edx_written=True
        if mn=="retn":
            eax_hist.append(reg_src.get("eax","?"))
    return {"ins":ins,"args":get_args(addr),"arg_to_disp":arg_to_disp,
            "arg_deref":{k:sorted(v) for k,v in arg_deref.items()},
            "disp_offs":sorted(disp_offs),"ecx_used":ecx_used,"edx_used":edx_used,
            "ecx_first":ecx_first_read,"edx_first":edx_first_read,
            "other_offs":{k:sorted(v) for k,v in other_offs.items()},
            "eax_end":eax_hist,"call_args":call_after}

def main():
    only=set(sys.argv[1:]) if len(sys.argv)>1 else None
    out={}
    for fn in sorted(os.listdir("disasm")):
        if not fn.endswith(".asm"): continue
        a=fn[:-4]
        if only and a not in only: continue
        d=analyze(a)
        d["name"]=protos[a]["name"]; d["proto"]=protos[a]["prototype"]
        # serialize sets
        d["arg_to_disp"]=sorted(d["arg_to_disp"])
        out[a]={k:v for k,v in d.items() if k!="ins"}
        # proposal
        arglist=[]
        for o,n,t in d["args"]:
            if n in d["arg_to_disp"]: ty="int /*actorIndex*/"
            elif n in d["arg_deref"]: ty="void* /*deref*/"
            else: ty=t
            nm=n
            arglist.append(f'{ty} {nm}'.replace("/*","").replace("*/",""))
        rets=set(d["eax_end"])
        ret="void"
        if "dispatch" in rets: ret="FFXBattleActorData *"
        elif rets and rets!={"?"}: ret="int"
        elif rets=={"?"}: ret="int /*eax?*/"
        if d["ecx_used"] or d["edx_used"]:
            conv="__fastcall?ecx/edx"
        else:
            conv="__cdecl"
        prop=f'{ret} {conv}({", ".join(arglist)})' if arglist else f'{ret} {conv}(void)'
        print(f'{a} {d["name"]}')
        print(f'   OLD: {d["proto"]}')
        print(f'   NEW: {prop}')
        if d["ecx_used"]: print(f'      ecx_first_read: {d["ecx_first"]}')
        if d["edx_used"]: print(f'      edx_first_read: {d["edx_first"]}')
        if d["other_offs"]: print(f'      other_offs: {d["other_offs"]}')
        d["proposed"]=prop
    json.dump(out,open("decisions.json","w"),indent=1,default=str)
main()
