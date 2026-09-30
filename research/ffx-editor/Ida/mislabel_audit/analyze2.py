#!/usr/bin/env python3
"""Tight mislabel analyzer v2 — high-confidence patterns only."""
import json, re

IN = "work/_mislabel_audit/export_all.jsonl"
OUT = "work/_mislabel_audit/audit2.jsonl"

recs = {}
for l in open(IN):
    d = json.loads(l)
    a = d.get("addr")
    if a and a not in recs:
        recs[a] = d

def asm_ops(asm):
    ops = []
    for l in asm.splitlines()[1:]:
        m = re.match(r"\s*([0-9a-fA-F]+)\s+(\S+)\s*(.*)", l)
        if m:
            ops.append((m.group(1), m.group(2), m.group(3).strip()))
    return ops

def proto_ret(proto):
    if not proto: return None
    m = re.match(r"^\s*(.+?)\s+__\w+\s*\(", proto) or re.match(r"^\s*(\w[\w\s\*]*?)\s*\(", proto)
    return m.group(1).strip() if m else None

results = []
for addr, r in sorted(recs.items(), key=lambda kv: int(kv[0], 16)):
    name = r.get("name") or ""
    if not name.startswith("FFX_"): continue
    asm = r.get("asm") or ""
    proto = r.get("prototype") or ""
    ops = asm_ops(asm)
    ret = proto_ret(proto)
    flags = []

    # --- A: pure single-store / single-load bodies ---
    # strip prologue/epilogue/push/pop
    core = [(a,o,rest) for a,o,rest in ops if o not in ("push","pop","nop","retn","ret") and o != "mov" or True]
    nonframe = [(a,o,rest) for a,o,rest in ops
                if o not in ("push","pop","nop","retn","ret","leave","int3")
                and not (o=="mov" and re.match(r"ebp|esp", rest))
                and o not in ("sub","add","xor","and","test","cmp","jz","jnz","jmp","call","lea","movsd","cdq","fld","fstp","fild","fmul","fadd","movzx","movsx","shr","shl","inc","dec","setnz","setz","sbb","or","not","jle","jl","jge","jg","jb","jnb","jbe","ja","jns","js","jecxz","rep","pusha","popa","enter")]
    # detect pure setter: only meaningful insn is `mov <global/dest>, <reg|const>`
    memwrites = [(a,o,rest) for a,o,rest in ops if o in ("mov","movzx") and re.match(r"(?:byte|word|dword|qword)?\s*ptr\s+(?:ds:)?(unk_|dword_|byte_|word_|flt_|g_|ffx_|[0-9A-Fa-f]{6,}h?\b)", rest) and re.search(r",\s*(?:\d|e[a-d]x|ax|al|esi|edi|ebx|ecx|edx|[er][a-d]x|offset)", rest)]
    memreads = [(a,o,rest) for a,o,rest in ops if o=="mov" and re.match(r"e[a-d]x|ax|al|eax\b", rest.split(",")[0].strip()) and re.search(r"\[(?:ds:)?(unk_|dword_|byte_|g_|0x?[0-9A-Fa-f]{5,})", rest)]
    calls = [rest for a,o,rest in ops if o=="call"]
    jmps = [rest for a,o,rest in ops if o=="jmp" and not rest.startswith(("short","loc","locret","ds:jpt","dword","off"))]

    named_getter = re.search(r"_(Get|Is|Read|Fetch|Query)([A-Z_]|$)", name)
    named_setter = re.search(r"_(Set|Write|Store|Clear|Reset|Assign)([A-Z_]|$)", name)
    # pure store: 1-2 memwrites to named global, no calls, tiny body
    if named_getter and len(ops) <= 8 and memwrites and not calls and not jmps:
        flags.append(f"CONFIRM:getter-writes:{memwrites[0][2][:60]}")
    # pure read: mov eax,[global]; ret
    if named_setter and len(ops) <= 8 and memreads and not calls and not jmps and not memwrites:
        flags.append(f"CONFIRM:setter-reads:{memreads[0][2][:60]}")
    # const-write getter: mov <glob>, <const>
    if named_getter and len(ops) <= 8:
        cw = [x for x in ops if x[1]=="mov" and re.match(r"(?:byte|word|dword|qword)?\s*ptr\s+(?:ds:)?\w*[0-9A-Fa-f]{4,}", x[2]) and re.search(r",\s*\d+\s*$", x[2])]
        if cw and not calls:
            flags.append(f"CONFIRM:getter-writes-const:{cw[0][2][:60]}")

    # --- B: Is/Check/Has/Can returning pointer/non-scalar ---
    if re.search(r"_(Is|Check|Has|Can|Are)([A-Z_]|$)", name) and ret and ("*" in ret or ret in ("__int64","double","float","int64_t","long long")):
        flags.append(f"SUSPECT:bool-name-ptr-ret:{ret}")

    # --- C: file-verb + file-object, no file callee, no truncation ---
    trunc = "chars total]" in asm
    if not trunc and re.search(r"(LoadFile|ReadFile|SaveFile|WriteFile|OpenFile|CloseFile|LoadBin|ReadBin|ParseFile|LoadTable|ReadTable|LoadDat|ReadDat)", name, re.I):
        if not re.search(r"FFX_File|FileIO|FileSystem|__imp_f|fopen|fread|fwrite|CreateFile|ReadFile|WriteFile|UnifyFilename|DataPath|Ps2Path|Mscd|Hdd|Cdrom|Stream", asm):
            flags.append("SUSPECT:file-name-no-io:" + ",".join(calls[:5]))

    # --- D: tail-thunk to differently-subsystem'd target (drift) ---
    if jmps and len(ops) <= 7 and not calls:
        tgt = jmps[-1].split(";")[0].strip()
        m1 = re.match(r"FFX_([A-Za-z0-9]+)_", name); m2 = re.match(r"FFX_([A-Za-z0-9]+)_", tgt)
        if m1 and m2 and m1.group(1) != m2.group(1):
            flags.append(f"SUSPECT:thunk-drift:{m1.group(1)}->{m2.group(1)}:{tgt}")

    # --- E: name claims verb X but body is only `call nullsub` / `ret` ---
    realins = [o for a,o,rest in ops if o not in ("push","pop","mov","nop","retn","ret","leave","int3","sub","add","xor","mov edi, edi")]
    if not trunc and re.search(r"_(Load|Save|Init|Process|Update|Draw|Render|Play|Start|Stop|Run|Exec|Handle)([A-Z_]|$)", name):
        if not realins or all(o in ("call",) and re.search(r"nullsub|_Stub|IdentityFunc", rest) for a,o,rest in ops if o=="call") and not memwrites:
            only = [rest for a,o,rest in ops if o=="call"]
            if only and all(re.search(r"nullsub|IdentityFunc|_Stub", c) for c in only):
                flags.append("SUSPECT:verb-but-stub-only:" + ",".join(only[:4]))

    if flags:
        results.append({"addr": addr, "name": name, "proto": proto, "flags": flags})

with open(OUT, "w") as fh:
    for r in results:
        fh.write(json.dumps(r) + "\n")
from collections import Counter
c = Counter()
for r in results:
    for f in r["flags"]:
        c[f.split(":")[0]+":"+f.split(":")[1]] += 1
print("v2 flagged:", len(results))
for k,v in c.most_common(): print(f"  {k}: {v}")
