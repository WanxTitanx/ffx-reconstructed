#!/usr/bin/env python3
"""decide.py — derive proposed signature per candidate from disasm + stack frame."""
import json, re, os, sys

frames = json.load(open("stack_frames.json"))
protos = json.load(open("caller_protos.json"))

REGS = ["eax","ebx","ecx","edx","esi","edi"]
ALIAS = {"al":"eax","ah":"eax","ax":"eax","bl":"ebx","bh":"ebx","bx":"ebx",
         "cl":"ecx","ch":"ecx","cx":"ecx","dl":"edx","dh":"edx","dx":"edx",
         "si":"esi","di":"edi"}
def norm(r): return ALIAS.get(r,r)

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
            out.append((o-ret-4, v["name"], v.get("type","?"), int(v.get("size","0x4"),16)))
    out.sort()
    return out

re_insn = re.compile(r"^([0-9a-f]+)\s+(\w+)\s*(.*)$")

def parse(path):
    ins = []
    for ln in open(path).read().splitlines()[2:]:
        m = re_insn.match(ln)
        if m: ins.append((m.group(1), m.group(2), m.group(3).split(";")[0].strip()))
    return ins

def arg_use_class(ins, argname):
    """classify how a named stack arg is used."""
    cls = set()
    pat = re.escape(argname)
    for a,mn,ops in ins:
        if re.search(r"\[ebp\+"+pat+r"\]", ops):
            if mn == "push":
                cls.add("pushed")
            elif mn == "mov" and ops.startswith("["):
                cls.add("written?")
            else:
                cls.add("read:"+mn)
        if re.search(r"\b"+pat+r"\b", ops) and "[ebp" not in ops:
            cls.add("ref:"+mn)
    return cls

def decide(addr):
    ins = parse(f"disasm/{addr}.asm")
    proto = protos[addr]["prototype"]
    args = get_args(addr)
    # track reg sources linearly
    reg_src = {}
    ecx_reads=[]; edx_reads=[]
    ecx_first=None; edx_first=None
    disp_hits=[]   # (off, addr, ops)
    arg_hits={}    # argname -> [(off,addr)]
    ecx_hits=[]; edx_hits=[]
    eax_end=[]     # what eax holds at each retn
    for a,mn,ops in ins:
        parts=[p.strip() for p in ops.split(",")]
        # mem derefs
        for mm in re.finditer(r"\[(e[a-d]x|e[sd]i)([+-])([0-9A-Fa-f]+)h\]", ops):
            b=norm(mm.group(1)); off=int(mm.group(3),16)*(1 if mm.group(2)=="+" else -1)
            src=reg_src.get(b,b)
            if src=="dispatch" or (src=="?" and b in reg_src):
                disp_hits.append((off,a,ops,src))
            elif src=="ecx": ecx_hits.append((off,a,ops))
            elif src=="edx": edx_hits.append((off,a,ops))
            elif src.startswith("arg:"):
                arg_hits.setdefault(src[4:],[]).append((off,a,ops))
        # fastcall reg read-before-write
        if "ecx" in ops and "ecx" not in reg_src:
            if not (mn=="mov" and parts and parts[0]=="ecx") and mn!="push":
                if not any(parts[0]=="ecx" for _ in [0]) or mn!="mov":
                    ecx_reads.append((a,ops))
        if "edx" in ops and "edx" not in reg_src:
            if not (mn=="mov" and parts and parts[0]=="edx"):
                edx_reads.append((a,ops))
        # propagate
        if mn=="mov" and len(parts)>=2:
            d,s=parts[0],parts[1]
            if d in REGS+["ebp","esp"]:
                if s=="eax" and reg_src.get("eax")=="dispatch": reg_src[d]="dispatch"
                elif s in reg_src: reg_src[d]=reg_src[s]
                elif s in ("ecx","edx"): reg_src[d]=s
                else:
                    am=re.match(r"dword ptr \[ebp\+(\w+)\]",s)
                    if am: reg_src[d]="arg:"+am.group(1)
                    elif am:=re.match(r"\[ebp\+(\w+)\]",s): reg_src[d]="arg:"+am.group(1)
                    else: reg_src[d]="?"
        elif mn=="lea" and len(parts)>=2 and parts[0] in REGS:
            mm=re.search(r"\[(e[a-d]x|e[sd]i)([+-])([0-9A-Fa-f]+)h\]",parts[1])
            if mm: reg_src[parts[0]]=reg_src.get(norm(mm.group(1)),norm(mm.group(1)))
        elif mn=="pop" and parts and parts[0] in REGS:
            reg_src[parts[0]]="stack"
        elif mn=="call":
            reg_src["eax"]="dispatch" if ("AccessCurrentActorData" in ops or "794030" in ops) else "?"
            reg_src["ecx"]="?"; reg_src["edx"]="?"
        elif mn in ("xor","sub","add","imul","shl","shr","and","or","inc","dec","neg","not","movzx","movsx","cdq","sete","setne","setz","setnz","setb","seta","setbe","setae","setl","setge","setle","setg","mul","div","idiv"):
            if parts and parts[0] in reg_src: reg_src[parts[0]]="?"
            if parts and parts[0] in ("ecx","edx") and parts[0] not in reg_src:
                reg_src[parts[0]]="?"
        if mn=="retn":
            eax_end.append(reg_src.get("eax","?"))
    return {"proto":proto,"args":args,"disp_hits":disp_hits,"arg_hits":arg_hits,
            "ecx_reads":ecx_reads,"edx_reads":edx_reads,"ecx_hits":ecx_hits,
            "edx_hits":edx_hits,"eax_end":eax_end,"ins":ins}

def main():
    only = set(sys.argv[1:]) if len(sys.argv)>1 else None
    for fn in sorted(os.listdir("disasm")):
        if not fn.endswith(".asm"): continue
        a=fn[:-4]
        if only and a not in only: continue
        d=decide(a)
        args_desc=[f'{n}@+{hex(o)}:{t}' for o,n,t,s in d["args"]]
        ret = "void"
        if d["eax_end"]:
            if any(x=="dispatch" for x in d["eax_end"]): ret="PTR!"
            elif any(x=="?" for x in d["eax_end"]): ret="eax?"
            else: ret="eax:"+",".join(set(d["eax_end"]))
        print(f'{a} {protos[a]["name"]}')
        print(f'   OLD {d["proto"]}')
        print(f'   args {args_desc} | ecx_reads={len(d["ecx_reads"])} edx_reads={len(d["edx_reads"])} | ret_eax={ret}')
        for o,ad,ops,src in d["disp_hits"][:6]:
            print(f'      [disp+{hex(o)}] @{ad}: {ops[:70]}')
        for n,hs in d["arg_hits"].items():
            for o,ad,ops in hs[:4]:
                print(f'      [arg {n}+ {hex(o)}] @{ad}: {ops[:70]}')
        for o,ad,ops in d["ecx_hits"][:5]:
            print(f'      [ecx+{hex(o)}] @{ad}: {ops[:70]}')
        for o,ad,ops in d["edx_hits"][:5]:
            print(f'      [edx+{hex(o)}] @{ad}: {ops[:70]}')
main()
