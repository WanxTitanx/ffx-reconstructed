#!/usr/bin/env python3
# ============================================================================
# atel_mon_ref_scan.py — opcode-level census of monster-id references in ATEL
# scripts, across ALL three ATEL containers in the PS2 master corpus:
#
#   * event/obj/**/*.ebp        -> EV01 chunk0        (field event scripts, 397)
#   * battle/btl/**/*.bin       -> chunked blob ch0   (battle event scripts, 863)
#   * battle/mon/_mNNN/mNNN.bin -> chunked blob ch0   (monster AI scripts, 361)
#
# WHY this exists: the formation census
# (docs/reverse/FFX_MONSTER_FORMATION_CENSUS_2026-09-15.md) proved 36 kernel
# monster ids (0, 275, 319-333, 347-365) are never referenced by formation
# chunk2 slots. "Not in a formation" != "never invoked" — scripts can still
# reach monsters through ATEL call args. The decisive encoding is the
# btlChr/monster/model "type token" 0x1NNN:
#
#   * PROVEN in IDA: FFX_Battle_QueryActorBitmask@0x794340 special-cases
#     (targetType & 0xFFFFF000) == 0x1000 -> match HIWORD(actor->m_state) ==
#     targetType over the battle actor slots; actor->m_state hiword stores the
#     formation slot raw value 0x1NNN (id = NNN = kernel monster id).
#   * FFXDataParser StackObject.asString(): ("btlChr"|"monster") &&
#     0x1000 <= v < 0x2000 -> DataAccess.getMonster(v) = MONSTERS[v & 0x0FFF].
#   * model-typed params: (v >> 12) == 1 -> "mon/mNNN" — the SAME kernel id
#     space (battle/mon/_mNNN/mNNN.bin), so 0x1NNN in a model arg is also a
#     direct reference to kernel monster NNN.
#   * NOT monster ids: monsterArenaUnlock is an arena-flag enum
#     (ScriptConstants "monsterArenaUnlock" = Area/Species/Original Conquest
#     unlock flags) — recorded but never counted as a kernel id.
#
# Operand grammar (PROVEN):
#   opcode <  0x80 -> 1-byte instruction
#   opcode >= 0x80 -> opcode + u16LE operand (3 bytes)
#   0xAE PUSHII pushes i16 immediate; 0xAD PUSHI pushes u32 refInts[operand]
#   resolved against the CURRENT worker's int pool (worker = owner of the
#   function entry point that most recently started at or before the pc —
#   entry-point addrs are CODE-relative per ScriptWorker.functions).
#
# Container grammar (PROVEN vs FFXDataParser BytesHelper.bytesToChunks):
#   u32(0) - 1 = chunkCount; chunkCount+1 u32 offsets at +4; 0xFFFFFFFF
#   truncates the count; chunk i = bytes[off_i : first off_j >= off_i, j>i].
#   .ebp wraps the same chunk list behind an "EV01" magic instead of a count.
#
# Stack model follows Karifean/FFXDataParser (atel/model/*): CALL(0xB5) pops
# ct.inputs.size() args and pushes a result; CALLPOPA(0xD8) pops the same and
# routes the result to rA. REQ family (0x36-0x3B,0x45-0x53) pops 3, pushes bool.
# Arity precedence: Java lib inputs > fahrenheit call.cs arg_count (call.cs is
# proven lossy: e.g. 0x700F readBtlChrProperty stubbed 0 there but pops 2 per
# its handler @0x7A4D70).
#
# External-source credit: call-target signature table, container grammar and
# opcode stack model re-derived from Karifean/FFXDataParser
# (work/_external_research/FFXDataParser, built on the Fahrenheit Ghidra RE)
# and fahrenheit-main call.cs/insn.cs. Fresh implementation — no code copied.
#
# Output: compact JSON + CSV under --out. Read-only on the corpus.
# ============================================================================
import os, re, json, struct, sys, argparse
from collections import Counter, defaultdict

REPO = "/home/wanderson/Documents/ffx-editor-main"
LIB_JAVA = os.path.join(REPO, "work/_external_research/FFXDataParser/src/main/java/atel/model/ScriptCallTargetLib.java")
CALL_CS = os.path.join(REPO, "Utilities/fahrenheit/src/core/atel/call.cs")

# Monster "type token" window. 0x1NNN -> kernel monster id NNN (0x000-0xFFF).
# 0x0014-0x001B = actor SLOTS, 0xFFE6-0xFFFF = special selectors — neither is
# a kernel id, so the window is deliberately ONLY [0x1000, 0x1FFF].
MON_MIN, MON_MAX = 0x1000, 0x1FFF
MON_TYPED = {"btlChr", "monster", "model"}      # decl types where 0x1NNN = kernel id
BATTLE_TYPED = {"battle"}                        # composite (field<<16)|encIdx
# 36 formation-orphan ids from FFX_MONSTER_FORMATION_CENSUS_2026-09-15.md
ORPHAN_IDS = sorted({0, 275} | set(range(319, 334)) | set(range(347, 366)))

def in_mon_range(u):
    return u is not None and MON_MIN <= (u & 0xFFFFFFFF) <= MON_MAX

# ---------------------------------------------------------------------------
# call-target signature extraction (Java lib -> {funcId: {name, ret, args}})
# Handles: putCtWithIdx/putVoidWithIdx(0xXXXX, new ScriptCallTarget(...)),
#          putCtWithIdx(0xXXXX, new ScriptCallTargetAccessor(...)),
#          putUnknownCt(0xXXXX, "internal"[, "ret"], N | inputs...)
# ---------------------------------------------------------------------------
def parse_field(tok):
    """p(N) -> {name:pN,type:unknown}; p("x") -> {name:x,type:x}; p("n","t") -> {name,type:t}"""
    tok = tok.strip()
    m = re.fullmatch(r'p\((\d+)\)', tok)
    if m: return {"name": f"p{m.group(1)}", "type": "unknown"}
    m = re.fullmatch(r'p\("([^"]*)",\s*"([^"]*)",\s*"([^"]*)"\)', tok)
    if m: return {"name": m.group(1), "type": m.group(2)}
    m = re.fullmatch(r'p\("([^"]*)",\s*"([^"]*)"\)', tok)
    if m: return {"name": m.group(1), "type": m.group(2)}
    m = re.fullmatch(r'p\("([^"]*)"\)', tok)
    if m: return {"name": m.group(1), "type": m.group(1)}
    m = re.fullmatch(r'"([^"]*)"', tok)
    if m: return {"name": m.group(1), "type": m.group(1)}
    return {"name": tok, "type": "unknown"}

def split_args(s):
    """Split a Java arg list on top-level commas (paren-aware)."""
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == '(': depth += 1
        if ch == ')': depth -= 1
        if ch == ',' and depth == 0:
            out.append(cur); cur = ""
        else:
            cur += ch
    if cur.strip(): out.append(cur)
    return [a.strip() for a in out if a.strip()]

def parse_call_targets(path):
    src = open(path, encoding="utf-8").read()
    table = {}
    for m in re.finditer(r'(putCtWithIdx|putVoidWithIdx|putUnknownCt)\s*\((.*?)\)\s*;', src, re.S):
        kind, body = m.group(1), m.group(2)
        mm = re.match(r'\s*0x([0-9A-Fa-f]+)\s*,', body)
        if not mm:
            continue
        idx = int(mm.group(1), 16)
        rest = body[mm.end():]
        ent = {"name": None, "ret": "unknown", "internal": None, "args": None, "decl": kind}
        if kind == "putUnknownCt":
            toks = split_args(rest)
            strs = [x for x in (re.fullmatch(r'"([^"]*)"', t) for t in toks) if x]
            nums = [t for t in toks if re.fullmatch(r'\d+', t)]
            fields = [parse_field(t) for t in toks if t.startswith('p(')]
            if strs: ent["internal"] = strs[0].group(1)
            if len(strs) >= 2: ent["ret"] = strs[1].group(1)
            if nums:
                ent["args"] = [{"name": f"p{i+1}", "type": "unknown"} for i in range(int(nums[-1]))]
            elif fields:
                ent["args"] = fields
            else:
                ent["args"] = []
            table[idx] = ent
            continue
        am = re.search(r'new\s+ScriptCallTargetAccessor\s*\((.*)\)\s*$', rest, re.S)
        if am:
            toks = split_args(am.group(1))
            def s(t):
                q = re.fullmatch(r'"([^"]*)"', t)
                return q.group(1) if q else None
            ent["name"] = s(toks[0]) if len(toks) > 0 else None
            subject = s(toks[1]) if len(toks) > 1 else None
            ent["internal"] = s(toks[2]) if len(toks) > 2 else None
            write = s(toks[3]) if len(toks) > 3 else None
            pred_tok = toks[4] if len(toks) > 4 else "null"
            extras = toks[5:] if len(toks) > 5 else []
            # ScriptCallTargetAccessor.setInputs() order: extras addAll(0,..)
            # AFTER subject add(0,..) => [extras.., subject?, property?, value?]
            args = [parse_field(t) for t in extras]
            if subject is not None:
                args.append({"name": "subject", "type": subject})
            if not pred_tok.startswith("p("):
                args.append({"name": "property", "type": s(pred_tok) or "unknown"})
            else:
                args.append({"name": "property", "type": parse_field(pred_tok)["type"]})
            if write is not None and write != "null":
                args.append({"name": "value", "type": "unknown"})
            ent["args"] = args
            ent["accessor"] = True
            table[idx] = ent
            continue
        cm = re.search(r'new\s+ScriptCallTarget\s*\((.*)\)\s*$', rest, re.S)
        if not cm:
            continue
        toks = split_args(cm.group(1))
        # ctor forms (name/ret/internal may be "..." or null):
        #  (name, ret, internal, true|false) -> brackets (variable arity)
        #  (name, ret, internal, p...)       -> typed args
        #  (name, p...)                      -> name + args
        #  (p...)                            -> args only
        def is_str_tok(t): return re.fullmatch(r'"[^"]*"|null', t) is not None
        def sval(t):
            q = re.fullmatch(r'"([^"]*)"', t)
            return q.group(1) if q else None
        i = 0
        if toks and is_str_tok(toks[0]):
            ent["name"] = sval(toks[0]); i = 1
            if (i < len(toks) and is_str_tok(toks[i])
                    and i + 1 < len(toks) and (is_str_tok(toks[i + 1]) or toks[i + 1] in ("true", "false"))):
                ent["ret"] = sval(toks[i]); i += 1
                if i < len(toks) and is_str_tok(toks[i]):
                    ent["internal"] = sval(toks[i]); i += 1
        if i < len(toks) and toks[i] in ("true", "false"):
            ent["args"] = []
            ent["brackets"] = True
        else:
            ent["args"] = [parse_field(t) for t in toks[i:]]
        table[idx] = ent
    return table

def parse_call_cs(path):
    """fahrenheit call.cs: new(0xXXXX, argc) inside named namespace tables."""
    src = open(path, encoding="utf-8-sig").read()
    out = {}
    cur = None
    for m in re.finditer(r'CallTarget\[\]\s+(\w+)\s*=\s*\[|new\(0x([0-9A-Fa-f]+),\s*(\d+)\)', src):
        if m.group(1):
            cur = m.group(1)
        else:
            out[int(m.group(2), 16)] = {"argc": int(m.group(3)), "tbl": cur}
    return out

# ---------------------------------------------------------------------------
# ATEL containers (grammar proven vs BytesHelper.bytesToChunks, see header)
# ---------------------------------------------------------------------------
def ev01_chunk0(b):
    """EV01: magic + u32 offset list terminated by 0xFFFFFFFF; [0] = chunk0."""
    if len(b) < 0x20 or b[:4] != b"EV01":
        return None
    offs = []
    p = 4
    while p + 4 <= len(b):
        v = struct.unpack_from("<I", b, p)[0]
        if v == 0xFFFFFFFF:
            break
        offs.append(v); p += 4
    if not offs or offs[0] == 0 or offs[0] >= len(b):
        return None
    end = len(b)
    for v in offs[1:]:
        if v >= offs[0] and v <= len(b):
            end = v; break
    return b[offs[0]:end]

def bin_chunk0(b):
    """chunked blob: u32(0)-1 = chunkCount; offsets at +4; chunk0 = script."""
    if len(b) < 8:
        return None
    cnt = struct.unpack_from("<i", b, 0)[0] - 1
    if not (0 < cnt <= 16):
        return None
    offs = []
    for i in range(cnt + 1):
        v = struct.unpack_from("<I", b, 4 + i * 4)[0]
        if v == 0xFFFFFFFF:
            cnt = i - 1
            break
        offs.append(v)
    if cnt <= 0 or not offs or offs[0] == 0 or offs[0] >= len(b):
        return None
    end = len(b)
    for j in range(1, cnt + 1):
        if j < len(offs) and offs[j] >= offs[0]:
            end = offs[j]; break
    return b[offs[0]:end]

# ---------------------------------------------------------------------------
# AtelScriptObject parse -> (code, workers, regions)
# static header 0x38B: codeLen@0, codeOff@0x30, workerCount@0x34 u16,
# worker u32 offset table @0x38. ScriptWorker header = 0x34B (offsets u32).
# ---------------------------------------------------------------------------
def parse_script_chunk(buf):
    if buf is None or len(buf) < 0x38:
        return {"code": b"", "workers": [], "ok": False, "err": "no-script-region", "buf": buf}
    code_len = struct.unpack_from("<I", buf, 0x00)[0]
    off_code = struct.unpack_from("<I", buf, 0x30)[0]
    n_workers = struct.unpack_from("<H", buf, 0x34)[0]
    if code_len == 0 or off_code == 0 or off_code + code_len > len(buf):
        return {"code": b"", "workers": [], "ok": code_len == 0,
                "err": None if code_len == 0 else "bad-code-range", "buf": buf}
    code = buf[off_code:off_code + code_len]
    regions = [("code", off_code, off_code + code_len)]
    workers = []
    for i in range(min(n_workers, 0x200)):
        wp = 0x38 + 4 * i
        if wp + 4 > len(buf):
            break
        woff = struct.unpack_from("<I", buf, wp)[0]
        if woff + 0x34 > len(buf):
            break
        d = buf[woff:woff + 0x34]
        stype, vcnt, icnt, fcnt, ecnt, jcnt = struct.unpack_from("<6H", d, 0)
        priv_len = struct.unpack_from("<I", d, 0x10)[0]
        offs = struct.unpack_from("<7I", d, 0x14)
        def tab(off, cnt):
            if off == 0 or off + 4 * cnt > len(buf):
                return []
            return list(struct.unpack_from("<%dI" % cnt, buf, off))
        names = ("vardecl", "refints", "reffloats", "entrypts", "jumps", "zero28", "privdata")
        for k, (off, cnt) in enumerate(zip(offs, (vcnt * 2, icnt, fcnt, ecnt, jcnt, 0, priv_len // 4))):
            if off and off + 4 * cnt <= len(buf):
                regions.append((f"w{i}:{names[k]}", off, off + 4 * cnt))
        workers.append({
            "idx": i, "type": stype,
            "var_count": vcnt, "ref_int_count": icnt, "ref_float_count": fcnt,
            "entry_count": ecnt, "jump_count": jcnt,
            "ref_ints": tab(offs[1], icnt),
            "ref_floats": tab(offs[2], fcnt),
            "entry_pts": tab(offs[3], ecnt),
            "jumps": tab(offs[4], jcnt),
        })
    return {"code": code, "workers": workers, "ok": True, "err": None,
            "buf": buf, "regions": regions, "off_code": off_code}

# ---------------------------------------------------------------------------
# opcode model (proven set; corpus uses exactly these — see insn.cs /
# AtelScriptObject decompiler loop)
# ---------------------------------------------------------------------------
BIN_OPS = set(range(0x01, 0x19))                        # pop2 push1
UN_OPS = {0x19, 0x1A, 0x1C}                             # NOT UMINUS BNOT: pop1 push1
PUSH_OPS = {0x26: "rA", 0x28: "rX", 0x29: "rY"}         # PUSHA/PUSHX/PUSHY
POP_REG = {0x25: "rA", 0x2A: "rX", 0x2C: "rY"}          # POPA/POPX/POPY
POPI = set(range(0x59, 0x5D))                           # POPI0..3 -> tmpI
POPF = set(range(0x5D, 0x67))                           # POPF0..9 -> tmpF
PUSHI_N = set(range(0x67, 0x6B))                        # PUSHI0..3 <- tmpI
PUSHF_N = set(range(0x6B, 0x75))                        # PUSHF0..9 <- tmpF
REQ3 = set(range(0x36, 0x3C)) | set(range(0x45, 0x54))  # REQ family: pop3 push bool
FUNC_END = {0x34, 0x3C, 0x3E, 0x40, 0x54}               # RTS RET RETT HALT DRET
POP1_END = {0x3D, 0x3F}                                 # RETN RETTN
POP1_JMP = {0xB1, 0xB2, 0xD5, 0xD6, 0xD7}               # CJMP NCJMP POPXJMP POPXCJMP POPXNCJMP
PUSH_UNK = {0xC1, 0xC2, 0xC3, 0xC4, 0xF5}               # PUSHN PUSHT PUSHVP PUSHFIX PUSHAINTER
NOOP_1B = {0x00, 0x1B, 0x1D, 0x1E, 0x7A}                # NOP FIXADRS LABEL TAG ACTREQ(unused)
NOOP_3B = {0x9D, 0x9E, 0xB0, 0xB3, 0xF6}                # LABEL TAG JMP JSR SYSTEM

LINE_END = ({0x25, 0x2A, 0x2C, 0x34, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x54,
             0x77, 0x78, 0x79, 0xA0, 0xA1, 0xA3, 0xA4, 0xB0, 0xB1, 0xB2, 0xB3,
             0xD5, 0xD6, 0xD7, 0xD8, 0xF6} | set(POP_REG) | POPI | POPF)

def fold2(op, a, b):
    try:
        if op == 0x01: return int(bool(a) or bool(b))
        if op == 0x02: return int(bool(a) and bool(b))
        if op == 0x03: return a | b
        if op == 0x04: return a ^ b
        if op == 0x05: return a & b
        if op == 0x06: return int(a == b)
        if op == 0x07: return int(a != b)
        if op == 0x08: return int((a & 0xFFFFFFFF) > (b & 0xFFFFFFFF))
        if op == 0x09: return int((a & 0xFFFFFFFF) < (b & 0xFFFFFFFF))
        if op == 0x0A: return int(a > b)
        if op == 0x0B: return int(a < b)
        if op == 0x0C: return int((a & 0xFFFFFFFF) >= (b & 0xFFFFFFFF))
        if op == 0x0D: return int((a & 0xFFFFFFFF) <= (b & 0xFFFFFFFF))
        if op == 0x0E: return int(a >= b)
        if op == 0x0F: return int(a <= b)
        if op == 0x10: return a | (1 << (b & 0x1F))
        if op == 0x11: return a & ~(1 << (b & 0x1F))
        if op == 0x12: return (a << (b & 0x1F)) & 0xFFFFFFFF
        if op == 0x13: return (a & 0xFFFFFFFF) >> (b & 0x1F)
        if op == 0x14: return (a + b) & 0xFFFFFFFF
        if op == 0x15: return (a - b) & 0xFFFFFFFF
        if op == 0x16: return (a * b) & 0xFFFFFFFF
        if op == 0x17: return 0 if b == 0 else int(a / b)
        if op == 0x18: return 0 if b == 0 else a % b
    except Exception:
        return None
    return None

def fold1(op, a):
    try:
        if op == 0x19: return int(not a)
        if op == 0x1A: return (-a) & 0xFFFFFFFF
        if op == 0x1C: return (~a) & 0xFFFFFFFF
    except Exception:
        return None
    return None

class V:
    """One symbolic stack entry: k=kind, v=signed int, u=unsigned u32."""
    __slots__ = ("k", "v", "u", "src", "op", "extra")
    def __init__(s, k, v=None, u=None, src=-1, op=0, extra=None):
        s.k, s.v, s.u, s.src, s.op, s.extra = k, v, u, src, op, extra
    def as_int(s):
        return s.u if s.u is not None else s.v
    def ser(s):
        d = {"kind": s.k}
        if s.v is not None: d["value"] = s.v
        if s.u is not None: d["u32"] = s.u
        if s.src >= 0: d["src_off"] = s.src
        if s.extra is not None: d["extra"] = s.extra
        return d

# ---------------------------------------------------------------------------
# main scan over one script blob — linear decode + symbolic stack
# ---------------------------------------------------------------------------
def scan_script(code, workers, ct_lib, arity_map, ctx):
    entry2w = {}
    for w in workers:
        for ep in w["entry_pts"]:
            if 0 <= ep < len(code):
                entry2w[ep] = w["idx"]
    sites, uses, lits = [], [], []
    operand_pos = {}                    # operand byte offset -> opcode (audit)
    st = []
    cur_w = 0
    reg = {"rA": V("reg", extra="rA"), "rX": V("reg", extra="rX"), "rY": V("reg", extra="rY")}
    tmpI = [V("tmpI", extra=i) for i in range(4)]
    tmpF = [V("tmpF", extra=i) for i in range(10)]
    diags = Counter()

    def pop(pc, op):
        if st:
            return st.pop()
        diags["stack_underflow"] += 1
        return V("underflow", src=pc, op=op)

    def push(v):
        u = v.as_int()
        if in_mon_range(u):
            lits.append({"off": v.src, "val": u & 0xFFFFFFFF, "kind": v.k,
                         "op": v.op, "worker": cur_w})
        st.append(v)

    def ref_ints():
        return workers[cur_w]["ref_ints"] if cur_w < len(workers) else []

    i, n = 0, len(code)
    while i < n:
        if i in entry2w:
            cur_w = entry2w[i]
            if st:
                diags["stack_residual_at_entry"] += 1
        op = code[i]
        arg = None
        if op & 0x80:
            if i + 3 > n:
                diags["truncated_operand"] += 1
                break
            arg = struct.unpack_from("<H", code, i + 1)[0]
            operand_pos[i + 1] = op
            adv = 3
        else:
            adv = 1

        def record_use(v, consumer, detail=None):
            u = v.as_int()
            if not in_mon_range(u):
                return
            uses.append({"off": v.src, "val": u & 0xFFFFFFFF, "kind": v.k,
                         "consumer": consumer, "consumer_off": i,
                         "detail": detail, "worker": cur_w})

        if op == 0xAE:                                   # PUSHII i16
            s16 = arg - 0x10000 if arg >= 0x8000 else arg
            push(V("i16", v=s16, u=arg, src=i, op=op))
        elif op == 0xAD:                                 # PUSHI -> refInts[arg]
            ri = ref_ints()
            if arg is not None and arg < len(ri):
                push(V("i32", v=None, u=ri[arg], src=i, op=op))
            else:
                diags["pushi_oob"] += 1
                push(V("i32unk", src=i, op=op))
        elif op == 0xAF:                                 # PUSHF
            push(V("f32", src=i, op=op))
        elif op == 0x9F:                                 # PUSHV
            push(V("var", extra=arg, src=i, op=op))
        elif op == 0xA2:                                 # PUSHAR
            idx = pop(i, op); record_use(idx, "arr_index")
            push(V("arr", extra=arg, src=i, op=op))
        elif op == 0xA7:                                 # PUSHARP
            idx = pop(i, op); record_use(idx, "arr_index")
            push(V("ptr", extra=arg, src=i, op=op))
        elif op in PUSH_OPS:
            push(reg[PUSH_OPS[op]])
        elif op in PUSHI_N:
            push(tmpI[op - 0x67])
        elif op in PUSHF_N:
            push(tmpF[op - 0x6B])
        elif op in PUSH_UNK:
            push(V("special", src=i, op=op))
        elif op in BIN_OPS:
            b = pop(i, op); a = pop(i, op)
            r = None
            if a.as_int() is not None and b.as_int() is not None:
                r = fold2(op, a.as_int(), b.as_int())
            record_use(a, "binop", f"{op:#04x}"); record_use(b, "binop", f"{op:#04x}")
            push(V("int" if r is not None else "expr", v=None if r is None else r,
                   u=None if r is None else r & 0xFFFFFFFF, src=i, op=op))
        elif op in UN_OPS:
            a = pop(i, op)
            r = fold1(op, a.as_int()) if a.as_int() is not None else None
            record_use(a, "unop", f"{op:#04x}")
            push(V("int" if r is not None else "expr", v=None if r is None else r,
                   u=None if r is None else r & 0xFFFFFFFF, src=i, op=op))
        elif op == 0x2B:                                 # REPUSH (dup)
            a = pop(i, op); record_use(a, "repush"); push(a)
        elif op in POP_REG:
            a = pop(i, op); record_use(a, "reg_store", POP_REG[op])
            reg[POP_REG[op]] = a
        elif op in POPI:
            a = pop(i, op); record_use(a, "tmpI_store", op - 0x59)
            tmpI[op - 0x59] = a
        elif op in POPF:
            a = pop(i, op); record_use(a, "tmpF_store", op - 0x5D)
            tmpF[op - 0x5D] = a
        elif op in (0xA0, 0xA1):                         # POPV(L)
            a = pop(i, op); record_use(a, "var_store", arg)
        elif op in (0xA3, 0xA4):                         # POPAR(L)
            val = pop(i, op); idx = pop(i, op)
            record_use(val, "arr_store_val", arg); record_use(idx, "arr_store_idx", arg)
        elif op in REQ3:
            f = pop(i, op); w = pop(i, op); lv = pop(i, op)
            record_use(lv, "req_level"); record_use(w, "req_worker"); record_use(f, "req_func")
            push(V("callret", extra=f"req{op:#04x}", src=i, op=op))
        elif op in (0x77, 0x78):                         # REQWAIT/PREQWAIT
            f = pop(i, op); w = pop(i, op)
            record_use(w, "reqwait_tgt"); record_use(f, "reqwait_func")
        elif op == 0x79:                                 # REQCHG
            nw = pop(i, op); old = pop(i, op); th = pop(i, op)
            for v, d in ((th, "reqchg_table"), (old, "reqchg_old"), (nw, "reqchg_new")):
                record_use(v, d)
        elif op in POP1_JMP:
            a = pop(i, op); record_use(a, "cond_jump", f"{op:#04x}")
            if op in (0xD5, 0xD6, 0xD7):
                reg["rX"] = a
        elif op in POP1_END:
            a = pop(i, op); record_use(a, "ret_value")
        elif op in FUNC_END:
            if st:
                diags["stack_residual_at_ret"] += 1
            st.clear()
            reg["rA"] = V("reg", extra="rA"); reg["rX"] = V("reg", extra="rX"); reg["rY"] = V("reg", extra="rY")
        elif op in (0xB5, 0xD8):                         # CALL / CALLPOPA
            fid = arg
            ent = ct_lib.get(fid)
            if ent is not None and ent["args"] is not None:
                argc = len(ent["args"]); argtypes = ent["args"]
            elif fid in arity_map:
                argc = arity_map[fid]["argc"]; argtypes = None
            else:
                argc = 0; argtypes = None
                diags["unknown_arity"] += 1
            params = [pop(i, op) for _ in range(argc)]
            params.reverse()                             # params[0] = first pushed
            arg_recs = []
            keep = False
            for j, p in enumerate(params):
                rec = p.ser()
                dt = argtypes[j]["type"] if argtypes and j < len(argtypes) else None
                if dt:
                    rec["decl_type"] = dt
                    rec["decl_name"] = argtypes[j]["name"]
                u = p.as_int()
                if in_mon_range(u):
                    rec["cls"] = "kernel_mon_ref" if dt in MON_TYPED else "candidate_mon_ref"
                    rec["mon_id"] = (u & 0xFFFFFFFF) & 0x0FFF
                    keep = True
                elif dt in BATTLE_TYPED and u is not None:
                    rec["cls"] = "battle_token"
                    rec["field_key"] = (u & 0xFFFFFFFF) >> 16
                    rec["encounter_idx"] = u & 0xFFFF
                    keep = True
                elif dt in MON_TYPED and u is None:
                    rec["cls"] = "dynamic_mon_arg"
                    keep = True
                arg_recs.append(rec)
                record_use(p, "call_arg", f"{fid:#06x}")
            if keep:
                site = {"off": i, "func": fid, "callop": op, "worker": cur_w,
                        "argc": argc, "args": arg_recs}
                if ent is not None:
                    site["name"] = ent["name"] or ent["internal"]
                sites.append(site)
            diags["calls"] += 1
            if op == 0xB5:
                push(V("callret", extra=f"{fid:#06x}", src=i, op=op))
            else:
                reg["rA"] = V("callret", extra=f"{fid:#06x}", src=i, op=op)
        elif op in NOOP_1B or op in NOOP_3B:
            pass
        else:
            diags[f"unhandled_op_{op:#04x}"] += 1
        if op in LINE_END and st:
            diags["line_residual"] += 1
        i += adv
    for v in st:
        record_use(v, "residual_eof", None)
    diags["insns"] = n
    return sites, uses, lits, diags, operand_pos

# ---------------------------------------------------------------------------
# raw-sweep audit: find every u16/u32 in [0x1000,0x1FFF] inside the script
# chunk that the typed decode did NOT consume — catches table-embedded or
# data-region monster tokens that never flow through the stack.
# ---------------------------------------------------------------------------
def raw_sweep(sc, operand_pos):
    buf = sc.get("buf")
    if not buf:
        return {"u16_code": [], "u32_chunk": []}
    code_lo = sc.get("off_code", 0)
    code_hi = code_lo + len(sc["code"])
    regions = sc.get("regions", [])
    def region_of(o, width):
        for name, a, b in regions:
            if a <= o and o + width <= b:
                return name
        return "other"
    u16_hits = []
    code = sc["code"]
    for o in range(len(code) - 1):
        v = struct.unpack_from("<H", code, o)[0]
        if MON_MIN <= v <= MON_MAX:
            u16_hits.append({"coff": o, "val": v})
    # classify u16 hits: operand of PUSHII? operand of other op? unaligned?
    for h in u16_hits:
        if h["coff"] in operand_pos:
            h["where"] = f"operand_of_{operand_pos[h['coff']]:#04x}"
        else:
            h["where"] = "code_bytes"
    u32_hits = []
    for o in range(len(buf) - 3):
        v = struct.unpack_from("<I", buf, o)[0]
        if MON_MIN <= v <= MON_MAX:
            u32_hits.append({"off": o, "val": v, "region": region_of(o, 4)})
    return {"u16_code": u16_hits, "u32_chunk": u32_hits}

# ---------------------------------------------------------------------------
# driver
# ---------------------------------------------------------------------------
def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--obj", default="/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/event/obj")
    ap.add_argument("--btl", default="/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/battle/btl")
    ap.add_argument("--mon", default="/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/battle/mon")
    ap.add_argument("--out", required=True)
    ap.add_argument("--no-mon", action="store_true")
    ap.add_argument("--no-btl", action="store_true")
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)

    ct_lib = parse_call_targets(LIB_JAVA)
    arity_map = parse_call_cs(CALL_CS)
    print(f"[lib] java call-targets: {len(ct_lib)}  fahrenheit arity entries: {len(arity_map)}")

    all_sites, all_uses, all_lits = [], [], []
    file_diags = {}
    sweeps = {}
    n_files = 0
    totals = Counter()

    def walk(root, kind, reader, accept):
        nonlocal n_files
        for dp, _, fns in os.walk(root):
            for fn in sorted(fns):
                if not accept(fn):
                    continue
                path = os.path.join(dp, fn)
                rel = os.path.relpath(path, root)
                try:
                    raw = open(path, "rb").read()
                except OSError as e:
                    file_diags[rel] = {"err": f"read: {e}", "container": kind}
                    continue
                blob = reader(raw)
                ctx = {"file": rel, "container": kind}
                sc = parse_script_chunk(blob)
                if not sc["ok"]:
                    file_diags[rel] = {"err": sc["err"], "container": kind}
                    continue
                if not sc["code"]:
                    file_diags[rel] = {"ok": True, "empty": True, "container": kind}
                    continue
                sites, uses, lits, diags, operand_pos = scan_script(
                    sc["code"], sc["workers"], ct_lib, arity_map, ctx)
                for r in sites: r.update(ctx)
                for r in uses: r.update(ctx)
                for r in lits: r.update(ctx)
                all_sites.extend(sites); all_uses.extend(uses); all_lits.extend(lits)
                sw = raw_sweep(sc, operand_pos)
                if sw["u16_code"] or sw["u32_chunk"]:
                    sweeps[rel] = {"container": kind, **{k: v for k, v in sw.items() if v}}
                fd = {"ok": True, "container": kind,
                      "workers": len(sc["workers"]), "code_len": len(sc["code"])}
                fd.update({k: v for k, v in diags.items() if v})
                file_diags[rel] = fd
                totals.update(diags)
                n_files += 1

    walk(a.obj, "ebp", ev01_chunk0, lambda f: f.endswith(".ebp"))
    if not a.no_btl:
        walk(a.btl, "btl", bin_chunk0, lambda f: f.endswith(".bin"))
    if not a.no_mon:
        walk(a.mon, "mon", bin_chunk0, lambda f: re.fullmatch(r"m\d{3}\.bin", f))

    # ---- partition call sites -------------------------------------------
    kernel_refs, candidate_refs, battle_tokens, dynamic_args = [], [], [], []
    for s in all_sites:
        k = {"file": s["file"], "container": s["container"], "off": s["off"],
             "func": s["func"], "name": s.get("name"), "callop": s["callop"],
             "worker": s["worker"], "argc": s["argc"]}
        for j, ar in enumerate(s["args"]):
            cls = ar.get("cls")
            if cls == "kernel_mon_ref":
                kernel_refs.append({**k, "arg_idx": j, "decl_type": ar.get("decl_type"),
                                    "decl_name": ar.get("decl_name"), "val": ar.get("u32", ar.get("value")),
                                    "mon_id": ar["mon_id"], "arg_kind": ar["kind"]})
            elif cls == "candidate_mon_ref":
                candidate_refs.append({**k, "arg_idx": j, "decl_type": ar.get("decl_type"),
                                       "decl_name": ar.get("decl_name"), "val": ar.get("u32", ar.get("value")),
                                       "mon_id": ar["mon_id"], "arg_kind": ar["kind"]})
            elif cls == "battle_token":
                battle_tokens.append({**k, "arg_idx": j, "decl_name": ar.get("decl_name"),
                                      "val": ar.get("u32", ar.get("value")),
                                      "field_key": ar["field_key"], "encounter_idx": ar["encounter_idx"]})
            elif cls == "dynamic_mon_arg":
                dynamic_args.append({**k, "arg_idx": j, "decl_type": ar.get("decl_type"),
                                     "decl_name": ar.get("decl_name"), "arg_kind": ar["kind"]})

    # ---- orphan cross-reference ------------------------------------------
    for r in kernel_refs + candidate_refs:
        r["orphan"] = r["mon_id"] in ORPHAN_IDS
    for r in all_lits + all_uses:
        r["mon_id"] = r["val"] & 0x0FFF
        r["orphan"] = r["mon_id"] in ORPHAN_IDS
    orphan_report = {}
    for oid in ORPHAN_IDS:
        kr = [r for r in kernel_refs if r["mon_id"] == oid]
        cr = [r for r in candidate_refs if r["mon_id"] == oid]
        lt = [r for r in all_lits if r["mon_id"] == oid]
        us = [r for r in all_uses if r["mon_id"] == oid]
        orphan_report[str(oid)] = {
            "kernel_refs": len(kr), "candidate_refs": len(cr),
            "literals": len(lt), "uses": len(us),
            "kernel_sites": kr[:50], "candidate_sites": cr[:50],
            "lit_sites": lt[:50], "use_sites": us[:50]}

    # ---- aggregate stats ---------------------------------------------------
    by_id = Counter(r["mon_id"] for r in kernel_refs)
    cand_by_id = Counter(r["mon_id"] for r in candidate_refs)
    stats = {
        "files_with_code": n_files,
        "files_errored": sum(1 for v in file_diags.values() if v.get("err")),
        "files_empty": sum(1 for v in file_diags.values() if v.get("empty")),
        "call_sites_decoded": totals["calls"],
        "unknown_arity_calls": totals["unknown_arity"],
        "stack_underflows": totals["stack_underflow"],
        "pushi_oob": totals["pushi_oob"],
        "kernel_mon_refs": len(kernel_refs),
        "candidate_mon_refs": len(candidate_refs),
        "battle_tokens": len(battle_tokens),
        "dynamic_mon_args": len(dynamic_args),
        "mon_literals": len(all_lits),
        "mon_literal_distinct_ids": len({r["mon_id"] for r in all_lits}),
        "kernel_ref_distinct_ids": len(by_id),
        "orphan_ids_with_kernel_refs": sorted({r["mon_id"] for r in kernel_refs if r["orphan"]}),
        "orphan_ids_with_candidate_refs": sorted({r["mon_id"] for r in candidate_refs if r["orphan"]}),
        "orphan_ids_with_any_literal": sorted({r["mon_id"] for r in all_lits if r["orphan"]}),
    }
    unhandled = {k: v for k, v in totals.items() if k.startswith("unhandled_op_")}
    stats["unhandled_opcodes"] = unhandled

    out = {
        "meta": {
            "corpus": {"obj": a.obj, "btl": a.btl, "mon": a.mon},
            "mon_range": [MON_MIN, MON_MAX],
            "mon_typed_params": sorted(MON_TYPED),
            "orphan_ids": ORPHAN_IDS,
            "java_targets": len(ct_lib), "fh_arities": len(arity_map),
        },
        "stats": stats,
        "kernel_refs": kernel_refs,
        "candidate_refs": candidate_refs,
        "battle_tokens": battle_tokens,
        "dynamic_mon_args": dynamic_args,
        "literals": all_lits,
        "uses": all_uses,
        "files": file_diags,
        "raw_sweeps": sweeps,
    }
    with open(os.path.join(a.out, "atel_mon_refs.json"), "w") as fh:
        json.dump(out, fh)
    with open(os.path.join(a.out, "orphan_report.json"), "w") as fh:
        json.dump(orphan_report, fh, indent=1)

    # CSV: one row per kernel/candidate ref
    import csv
    with open(os.path.join(a.out, "kernel_refs.csv"), "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["container", "file", "off", "func", "name", "arg_idx",
                    "decl_type", "decl_name", "val", "mon_id", "orphan", "arg_kind"])
        for r in kernel_refs:
            w.writerow([r["container"], r["file"], hex(r["off"]), hex(r["func"]),
                        r["name"], r["arg_idx"], r["decl_type"], r["decl_name"],
                        hex(r["val"]) if r["val"] is not None else "", r["mon_id"],
                        r["orphan"], r["arg_kind"]])
        for r in candidate_refs:
            w.writerow([r["container"], r["file"], hex(r["off"]), hex(r["func"]),
                        r["name"], r["arg_idx"], "CANDIDATE:" + str(r["decl_type"]),
                        r["decl_name"], hex(r["val"]) if r["val"] is not None else "",
                        r["mon_id"], r["orphan"], r["arg_kind"]])

    print(f"[scan] files with code: {n_files}  call sites decoded: {totals['calls']}  kept: {len(all_sites)}")
    print(f"[scan] kernel_mon_refs: {len(kernel_refs)} (distinct ids {len(by_id)})  "
          f"candidates: {len(candidate_refs)}  battle_tokens: {len(battle_tokens)}  "
          f"dynamic: {len(dynamic_args)}  literals: {len(all_lits)}")
    print(f"[scan] orphans w/ kernel refs: {stats['orphan_ids_with_kernel_refs']}")
    print(f"[scan] orphans w/ any literal: {stats['orphan_ids_with_any_literal']}")
    bad = {k: v for k, v in file_diags.items() if v.get("err")}
    print(f"[scan] files with errors: {len(bad)}")
    for k in list(bad)[:10]:
        print("   ", k, bad[k])
    if unhandled:
        print(f"[scan] unhandled opcodes: {unhandled}")

if __name__ == "__main__":
    main()
