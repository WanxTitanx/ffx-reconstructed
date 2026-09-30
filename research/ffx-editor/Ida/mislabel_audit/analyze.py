#!/usr/bin/env python3
"""Heuristic mislabel analyzer over export_all.jsonl.

Each record: {addr,name,prototype,size,asm,comments}.
Emits audit JSONL with per-name verdicts: OK / SUSPECT:<reason> / CONFIRM:<reason>.
CONFIRM only for mechanically-provable cases (void-returning Get/Is/Check,
pure-tail-thunk named as impl). SUSPECT needs human decompile review.
"""
import json, re, sys
from collections import defaultdict

IN = "work/_mislabel_audit/export_all.jsonl"
OUT = "work/_mislabel_audit/audit_flags.jsonl"

FILE_PAT = re.compile(r"FFX_File|FileIO|FileSystem|__imp_f?(open|read|write|close|seek|tell)|CreateFile|ReadFile|WriteFile|FileStream|StreamReader|StreamWriter|Cdrom|FFX_Hdd|FFX_Mscd_|UnifyFilename|BigFile|LoadSaveFile|SaveFile|_CHAPPU|ffxps2|Ps2Path|DataPath|ReadWholeFile", re.I)
RENDER_PAT = re.compile(r"FFX_(Render|GS|Menu2D|Font|Text|Sprite|Prim|Video|Post|Blur|Distortion|Draw|Fx|Effect|Shader)|Phyre|__imp_d3d|Direct3D|Present|SceneGraph|PNode|Material|Texture|Vertex|Index.*Buffer|DrawPrim", re.I)
ALLOC_PAT = re.compile(r"malloc|calloc|realloc|__imp__?new|operator new|HeapAlloc|VirtualAlloc|FFX_\w*Alloc|FFX_\w*Create|CreateHeap|_nh_malloc", re.I)
FREE_PAT = re.compile(r"__imp_?free|operator delete|HeapFree|VirtualFree|FFX_\w*Free|FFX_\w*Destroy|FFX_\w*Release|FFX_\w*Delete|FFX_\w*Cleanup|CloseHandle", re.I)
COPY_PAT = re.compile(r"memcpy|memmove|strcpy|strncpy|strcat|lstrcpy|wcscpy|movsd|rep movs|FFX_\w*Copy|FFX_\w*Duplicate|FFX_\w*Clone", re.I)
ARITH_PAT = re.compile(r"\b(add|sub|imul|mul|idiv|div|shl|shr|sar|inc|dec|fadd|fsub|fmul|fdiv|addps|mulps|xor|and|or)\b", re.I)
SOUND_PAT = re.compile(r"Fmod|Sound|Audio|Sfx|Voice|Spu|Bgm|Mscd|Stream", re.I)

def callees_of(asm):
    out = []
    for line in asm.splitlines():
        m = re.search(r"\b(?:call|jmp)\s+(.+?)(?:;|$)", line)
        if m:
            out.append(m.group(1).strip())
    return out

def has_store_to_global(asm):
    # writes to named globals / absolute addrs (not [ebp])
    return bool(re.search(r"mov\s+(?:byte|word|dword|qword)?\s*(?:ptr\s+)?(?!.*ebp)(?:ds:)?\[?(?:0x)?[0-9A-Fa-f]{6,}|mov\s+\w*(?:FFX|g_|dword_|unk_|byte_|flt_)", asm))

def body_is_tail_jmp(asm):
    insns = [l for l in asm.splitlines()[1:] if l.strip()]
    ops = []
    for l in insns:
        m = re.match(r"\s*[0-9a-fA-F]+\s+(\S+)(.*)", l)
        if m:
            ops.append((m.group(1), m.group(2).strip()))
    # allow prologue-less: single jmp target
    realops = [o for o in ops if o[0] not in ("nop", "int3")]
    if len(realops) <= 4:
        for op, rest in realops:
            if op == "jmp" and rest and not rest.startswith("short") and not rest.startswith("loc"):
                return rest.split()[0]
        if len(realops) == 1 and realops[0][0] == "jmp":
            return realops[0][1].split()[0]
    # last insn jmp to external/other func with only reg-sets before
    if realops and realops[-1][0] == "jmp" and len(realops) <= 6:
        tgt = realops[-1][1].split(";")[0].strip()
        if not tgt.startswith(("short", "loc", "dword")):
            return tgt
    return None

def proto_ret(proto):
    if not proto:
        return None
    m = re.match(r"^\s*(.+?)\s+__\w+\s*\(", proto)
    if m:
        return m.group(1).strip()
    m = re.match(r"^\s*(\w[\w\s\*]*?)\s*\(", proto)
    return m.group(1).strip() if m else None

def main():
    recs = {}
    for l in open(IN):
        d = json.loads(l)
        a = d.get("addr")
        if a and a not in recs:
            recs[a] = d
    flags = []
    for addr, r in sorted(recs.items(), key=lambda kv: int(kv[0], 16)):
        name = r.get("name") or ""
        asm = r.get("asm") or ""
        proto = r.get("prototype") or ""
        if not name.startswith("FFX_"):
            continue
        ret = proto_ret(proto)
        calls = callees_of(asm)
        trunc = "chars total]" in asm
        reasons = []

        has = lambda pat: bool(pat.search(asm))
        is_thunk_named = bool(re.search(r"thunk|wrapper|dispatch|stub|callback|handler|trampoline|proxy", name, re.I))
        is_gray = bool(re.search(r"structural|candidate", name, re.I))

        # 1. void-returning getters/checkers — mechanically provable
        if re.search(r"FFX_\w+_(Get|Is|Check|Query|Count|Find|Search|Read|Compute|Calc)", name) and ret == "void":
            reasons.append(f"CONFIRM:void-return:{name.split('_')[-2] if '_' in name else name} claims value-return but proto={proto}")

        # 2. pure tail jmp named as impl
        tj = body_is_tail_jmp(asm)
        if tj and not is_thunk_named and tj != name:
            reasons.append(f"SUSPECT:tail-thunk:jmp->{tj}")

        # 3. file-claim verbs with zero file callees (skip truncated asms for this check)
        file_claim = re.search(r"(Load|Read|Save|Write|Open|Parse|Fetch|Import|Export|Unpack|Decode)", name)
        obj_is_file = re.search(r"(File|Bin|Dat|Save|Ini|Tbl|Vpa|Ebp|Disk|Data|Text|Config|Shader|Chunk|Entry|Table|Blob|Resource|Stream|Module|Sector)", name, re.I)
        if file_claim and obj_is_file and not trunc:
            if not has(FILE_PAT):
                # but maybe it delegates entirely to one callee
                reasons.append("SUSPECT:no-file-call:" + ",".join(calls[:6]))

        # 4. Draw/Render names w/o render evidence
        if re.search(r"_(Draw|Render|Display|Paint|Present)", name) and not trunc:
            if not has(RENDER_PAT):
                reasons.append("SUSPECT:no-render-call:" + ",".join(calls[:6]))

        # 5. Init w/o stores or init-ish callees
        if re.search(r"_(Init|Initialize|Reset|Clear)([A-Z_]|$)", name) and not trunc:
            if not has_store_to_global(asm) and not calls:
                reasons.append("SUSPECT:init-no-stores-no-calls")

        # 6. Alloc/Create w/o alloc callee
        if re.search(r"_(Alloc|Allocate|Malloc|Create|New)([A-Z_]|$)", name) and not trunc:
            if not has(ALLOC_PAT) and not has_store_to_global(asm):
                reasons.append("SUSPECT:alloc-no-alloc:" + ",".join(calls[:5]))

        # 7. Free/Destroy/Release w/o free callee
        if re.search(r"_(Free|Destroy|Release|Delete|Cleanup|Dealloc|Close)([A-Z_]|$)", name) and not trunc:
            if not has(FREE_PAT):
                reasons.append("SUSPECT:free-no-free:" + ",".join(calls[:5]))

        # 8. Copy/Duplicate w/o copy callee
        if re.search(r"_(Copy|Duplicate|Clone|Memcpy)([A-Z_]|$)", name) and not trunc:
            if not has(COPY_PAT):
                reasons.append("SUSPECT:copy-no-copy:" + ",".join(calls[:5]))

        # 9. Count/Calc/Compute w/o arithmetic
        if re.search(r"_(Count|Calc|Compute|Sum|Total)([A-Z_]|$)", name) and not trunc:
            if not has(ARITH_PAT):
                reasons.append("SUSPECT:calc-no-arith")

        # 10. Set* that never stores
        if re.search(r"_(Set|Write|Store|Assign)([A-Z_]|$)", name) and not trunc:
            if not has_store_to_global(asm) and re.search(r"mov\s+e[a-d]x,\s*\[|mov\s+\w+,\s*\[ebp", asm):
                reasons.append("SUSPECT:set-no-store")

        # 11. Is/Check returning clearly non-bool
        if re.search(r"_(Is|Check|Has|Can)([A-Z_]|$)", name) and ret and ret not in ("bool","char","int","_BOOL","BYTE","unsigned char","uchar","uint","unsigned int","DWORD","_DWORD","short","unsigned short","void","_UNKNOWN"):
            reasons.append(f"SUSPECT:bool-name-nonstr-ret:{ret}")

        # 12. subsystem mismatch via callee prefix votes
        m = re.match(r"FFX_([A-Za-z0-9]+)_", name)
        if m and calls:
            sub = m.group(1)
            votes = defaultdict(int)
            for c in calls:
                mm = re.match(r"FFX_([A-Za-z0-9]+)_", c)
                if mm:
                    votes[mm.group(1)] += 1
            tot = sum(votes.values())
            if tot >= 3 and votes.get(sub, 0) == 0:
                top, cnt = max(votes.items(), key=lambda kv: kv[1])
                if cnt >= max(2, tot * 0.6) and top != sub:
                    reasons.append(f"SUSPECT:subsystem-drift:name={sub} callees={top}({cnt}/{tot})")

        if reasons:
            flags.append({"addr": addr, "name": name, "proto": proto,
                          "size": r.get("size"), "trunc": trunc,
                          "reasons": reasons, "calls": calls[:12]})
    with open(OUT, "w") as fh:
        for f in flags:
            fh.write(json.dumps(f) + "\n")
    from collections import Counter
    c = Counter()
    for f in flags:
        for r in f["reasons"]:
            c[r.split(":")[0] + ":" + (r.split(":")[1] if r.startswith("SUSPECT:") else "")] += 1
    print("flagged:", len(flags))
    for k, v in c.most_common(30):
        print(f"  {k}: {v}")

if __name__ == "__main__":
    main()
