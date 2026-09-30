#!/usr/bin/env python3
"""analyze.py — classify each FFXBattleActorRecord-typed caller of the
0xF90 dispatcher: which regs/sources feed proven offsets, real stack args,
fastcall-reg usage, return style."""
import json, re, os, sys

DIS = "disasm"
PROVEN = {0x5D0,0x5D4,0x5DE,0x5F7,0x604,0x606,0x608,0x616,0x618,0x61A,0x628,
          0x62A,0x630,0x636,0x63C,0x63D,0x63E,0x63F,0x640,0x641,0x65A,0x65C,
          0x65D,0x65E,0x65F,0x660,0x661,0x662,0x663,0x690,0x6BC,0x6C2,0x6D2,
          0x6E1,0x6E4,0x6E8,0x6EC,0x6F4,0x701,0x714,0x715,0x726,0x728,0x72C,
          0x7AC,0x7B1,0x7CA,0x7CB,0x7CE,0x7D1,0x7D3,0x7D9,0x7DC,0x7F8,0x8AE,
          0x93F,0xD34,0xDC8,0xDCC,0xDD4,0xDD6,0xDD7,0xDE5,0xDE6,0xDE8,0xDF8,
          0xE30,0x594,0x598,0x5A8,0x5AF,0x5B8,0x5BA,0x5BC,0x5BD,0x5C4,0x5C5}
LEGACY_MAX = 0xC8A  # FFXBattleActorRecord size

regs32 = ["eax","ebx","ecx","edx","esi","edi","ebp","esp"]
alias = {"al":"eax","ah":"eax","ax":"eax","bl":"ebx","bh":"ebx","bx":"ebx",
         "cl":"ecx","ch":"ecx","cx":"ecx","dl":"edx","dh":"edx","dx":"edx",
         "si":"esi","di":"edi","bp":"ebp","sp":"esp"}
def norm(r): return alias.get(r, r)

re_insn = re.compile(r"^([0-9a-f]+)\s+(\w+)\s*(.*?);?\s*$")
re_mem  = re.compile(r"\[(e[a-d]x|e[sb]p|e[sd]i)([+-])([0-9A-Fa-f]+)h\]")
re_argn = re.compile(r"\[ebp\+(arg_\w+|n0x[0-9A-Fa-f]+|n[0-9A-Fa-f]+|[0-9A-Fa-f]+h?)\]")

def analyze(path):
    lines = open(path).read().splitlines()
    name = lines[0][2:].strip() if lines and lines[0].startswith("; ") else "?"
    proto = lines[1][9:].strip() if len(lines)>1 and lines[1].startswith("; PROTO:") else "?"
    reg_src = {}            # reg -> source tag
    args_read = []          # named stack args read
    fc_reads = {"ecx": False, "edx": False}
    fc_written = set()
    hits = []               # (src, off, insn_addr, text)
    ret_eax_ptr = None      # 'dispatch'|'field'|'int'|'none'
    calls_disp = 0
    pushed = []             # recent pushes (for call-arg analysis)
    for ln in lines[2:]:
        m = re_insn.match(ln)
        if not m: continue
        addr, mnem, ops = m.group(1), m.group(2), m.group(3)
        ops_clean = ops.split(";")[0]
        # stack-arg reads
        for am in re_argn.finditer(ops_clean):
            tok = am.group(1)
            if tok not in args_read: args_read.append(tok)
        # mem derefs with displacement
        for mm in re_mem.finditer(ops_clean):
            base = norm(mm.group(1)); sign = mm.group(2); off = int(mm.group(3),16)
            if sign == "-": off = -off
            if base in ("ebp","esp"):  continue
            src = reg_src.get(base, base+"?")
            if off in PROVEN or off > LEGACY_MAX or off >= 0x3F0:
                hits.append((src, off, addr, ops_clean.strip()[:60]))
        # track sources
        parts = [p.strip() for p in ops_clean.split(",")]
        if mnem == "mov" and len(parts) >= 2:
            dst, src = parts[0], parts[1]
            if dst in regs32:
                if src == "eax" and reg_src.get("eax") == "dispatch":
                    reg_src[dst] = "dispatch"
                elif src in regs32:
                    reg_src[dst] = reg_src.get(src, src)
                elif re_argn.search(src):
                    reg_src[dst] = "arg:" + re_argn.search(src).group(1)
                elif src.startswith("dword ptr [ebp+") :
                    reg_src[dst] = "arg:" + src
                else:
                    reg_src[dst] = "?"
            for r in regs32:
                if r != dst and r in src.split():
                    pass
        elif mnem == "lea" and len(parts) >= 2 and parts[0] in regs32:
            mm = re_mem.search(parts[1])
            if mm:
                reg_src[parts[0]] = reg_src.get(norm(mm.group(1)), norm(mm.group(1))) + "+lea"
        elif mnem == "pop" and parts and parts[0] in regs32:
            reg_src[parts[0]] = "stack"
        elif mnem in ("push","call","jmp"):
            if mnem == "push":
                pushed.append((addr, ops_clean.strip()))
            if mnem == "call":
                tgt = ops_clean.strip()
                if "794030" in tgt or "AccessCurrentActorData" in tgt:
                    calls_disp += 1
                    reg_src["eax"] = "dispatch"
                    ret_eax_ptr = "dispatch?"
                else:
                    reg_src["eax"] = "?"
                reg_src["ecx"] = "?"; reg_src["edx"] = "?"
                pushed = []
        elif mnem == "retn" or mnem == "ret":
            pass
        # writes kill src tracking
        if mnem in ("xor","sub","add","mov","lea","pop","imul","shl","shr","and","or","inc","dec","neg","not","cdq","movzx","movsx","sete","setne","setz","setnz","setb","seta","setbe","setae","sets","setns","setl","setge","setle","setg"):
            if parts and parts[0] in regs32:
                if not (mnem=="mov" and reg_src.get(parts[0])):
                    if mnem != "mov" or parts[0] not in reg_src or reg_src[parts[0]] in ("?",):
                        if mnem == "mov":
                            pass  # handled above
                        else:
                            reg_src[parts[0]] = "?"
        # fastcall reg reads before write
        for r in ("ecx","edx"):
            if r not in fc_written:
                if re.search(r"\b"+r+r"\b", ops_clean):
                    # is it read as source (not dest of mov)?
                    if not (mnem=="mov" and parts and parts[0]==r):
                        fc_reads[r] = True
                if mnem=="mov" and parts and parts[0]==r:
                    fc_written.add(r)
        if mnem in ("mov","xor","sub","add","lea","pop","imul","movzx","movsx","or","and") and parts and parts[0] in ("ecx","edx"):
            fc_written.add(parts[0])
        # return style
        if mnem == "retn":
            if reg_src.get("eax") == "dispatch": ret_eax_ptr = "dispatch"
    return {"name": name, "proto": proto, "args": args_read,
            "ecx_read": fc_reads["ecx"], "edx_read": fc_reads["edx"],
            "hits": hits, "disp_calls": calls_disp, "ret": ret_eax_ptr}

def main():
    protos = json.load(open("caller_protos.json"))
    rows = []
    for fn in sorted(os.listdir(DIS)):
        if not fn.endswith(".asm"): continue
        a = fn[:-4]
        r = analyze(os.path.join(DIS, fn))
        r["addr"] = a
        rows.append(r)
    json.dump(rows, open("analysis.json","w"), indent=1)
    for r in rows:
        offs = sorted({hex(h[1]) for h in r["hits"]})
        srcs = sorted({h[0] for h in r["hits"]})
        print(f'{r["addr"]} {r["name"][:46]:<46} args={r["args"]} ecx={r["ecx_read"]} edx={r["edx_read"]} disp={r["disp_calls"]} ret={r["ret"]}')
        print(f'    proto: {r["proto"]}')
        print(f'    offs: {offs} srcs: {srcs}')

if __name__ == "__main__":
    main()
