#!/usr/bin/env python3
# ── reqpath_ev_audit.py — corpus-wide bound of the REQ-path `ev` operand ─────
#
# Lane: Jarvis-REQPATH-EV (wave-18, 2026-09-18). Stdlib only, no repo deps.
#
# Closes the last OPEN residual of docs/reverse/FFX_MAP_EPTABLE_2026-09-18.md
# §4c / w17_mapeptable handoff item 1: the `ev` operand of REQ-family ATEL
# opcodes is a POPPED script operand (runtime), not MsgBlob section data, so
# the ep_bounds_audit (authored map[] bound) does not cover it.
#
# Handler chain (decompile-verified this lane, FFX.exe):
#   FFX_Field_EventParser @0x864180 switch (jump table 0x8643C7):
#     case 0x36,0x45-0x49 -> FFX_AtelOp_QueueActorNodeType0 @0x8671D0
#     case 0x37,0x4A-0x4E -> FFX_AtelOp_QueueActorNodeType1 @0x867510
#                          (the "ops J-N" of the mission brief = ASCII 'J'..'N'
#                          = opcodes 0x4A..0x4E = FREQSW/TREQSW/BREQSW/
#                          BFREQSW/BTREQSW; case 'L' (BREQSW) + REQSW(0x37)
#                          take the default QueuePriorityNodeIfAbsent path)
#     case 0x38,0x4F-0x53 -> FFX_AtelOp_QueueActorNodeType2 @0x867370
#     case 0x39/0x3A/0x3B (PREQ/PREQSW/PREQEW) -> inline, same pop order
#   In ALL handlers the FIRST popped operand v5 -> req[4]/arg5 -> node+8
#   (RequeuePriorityNode a1[4]->node+8) -> epTable[ev] index, unclamped
#   @0x869152. ev = the LAST value pushed before the REQ opcode.
#   B-gate: ops 0x47-0x49/0x4C-0x4E/0x51-0x53 call AtelCurCtrlWork[+0x60]
#   veto first (PROVEN dormant, stock = Return1).
#
#   Companion ops that also pop `ev`-family operands but do NOT queue a node:
#     0x77 REQWAIT  pop ev,pop actorCtx -> ctx+2C (park until node drains)
#     0x78 PREQWAIT pop ev,pop pslot    -> same
#     0x79 REQCHG   pop val,slot,addrDesc -> actor word slot (not ev)
#     0x7A ACTREQ   pop ctxv,id -> actor slot table (not ev)
#   These are scanned too (class 'wait'/'misc') since their first popped
#   operand shares the `ev` semantics.
#
# Method — backward symbolic stack slice per REQ site:
#   Linear-decode the code region (proven reliable by btlai_census). For each
#   REQ site, walk backwards tracking stack depth (pushes -, pops +) until the
#   producer of the top slot (ev) is found; expression producers (ADD/SUB/…)
#   recurse into their operand slots. Stop conditions: producer found;
#   a split point crossed (jumpTable label / entry point / dead-code edge →
#   'crossblock'); a variable-effect op crossed (CALL/JSR/SYSTEM/CALLPOPA →
#   'indirect'); window exhausted ('deep'); code start ('start').
#   PUSHII operands are SIGN-EXTENDED (evops comment: _push_sign_extended_
#   imm16) so ev can be negative -> u16 wraps to 0xFFxx at node+8.
#
# Stack effects decompile-verified (EventParser + array helpers):
#   PUSHV(0x1F)+1 var[imm] · PUSHAR(0x22) pop idx push var[imm][idx] (net0)
#   PUSHARP(0x27) pop idx push elem-addr (net0) · POPV/POPVL -1 ·
#   POPAR/POPARL -2 (value+index) · POPA/POPX/POPY/POPI0-3/POPF0-9 -1 ·
#   PUSHA/PUSHX/PUSHY/REPUSH/PUSHI/PUSHII/PUSHF/PUSHI0-3/PUSHF0-9/
#   PUSHAINTER +1 · CJMP/NCJMP/POPX*JMP/RETN/RETTN -1 · binary(0x01-0x18) -1
#   net · unary(0x19/1A/1C) net0 · REQ queues (3,1) · REQWAIT/PREQWAIT -2 ·
#   REQCHG -3 · ACTREQ (2,1) · CALL/CALLPOPA/JSR/SYSTEM variable.
#
# Outputs:
#   reqpath_ev_sites.csv   one row per REQ site (operand triple classified)
#   reqpath_ev_summary.csv per-file maxima vs funcCount + corpus summary rows
#
# Usage:
#   reqpath_ev_audit.py [--root DIR] [--outdir DIR] [--max-files N] [--verbose]
# ────────────────────────────────────────────────────────────────────────────
import argparse
import collections
import csv
import glob
import os
import struct
import sys

ROOTS = ["/mnt/nvme-xpg/ffx_ps2/ffx/master",
         "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"]
OUTDIR = os.path.join(os.path.dirname(__file__), "..", "..",
                      "docs", "reverse", "data", "wave15")

OP_NAMES = [
    "NOP", "OPLOR", "OPLAND", "OPOR", "OPEOR", "OPAND", "OPEQ", "OPNE",
    "OPGTU", "OPLSU", "OPGT", "OPLS", "OPGTEU", "OPLSEU", "OPGTE", "OPLSE",
    "OPBON", "OPBOFF", "OPSLL", "OPSRL", "OPADD", "OPSUB", "OPMUL", "OPDIV",
    "OPMOD", "OPNOT", "OPUMINUS", "OPFIXADRS", "OPBNOT", "LABEL", "TAG",
    "PUSHV", "POPV", "POPVL", "PUSHAR", "POPAR", "POPARL", "POPA", "PUSHA",
    "PUSHARP", "PUSHX", "PUSHY", "POPX", "REPUSH", "POPY", "PUSHI", "PUSHII",
    "PUSHF", "JMP", "CJMP", "NCJMP", "JSR", "RTS", "CALL", "REQ", "REQSW",
    "REQEW", "PREQ", "PREQSW", "PREQEW", "RET", "RETN", "RETT", "RETTN",
    "HALT", "PUSHN", "PUSHT", "PUSHVP", "PUSHFIX", "FREQ", "TREQ", "BREQ",
    "BFREQ", "BTREQ", "FREQSW", "TREQSW", "BREQSW", "BFREQSW", "BTREQSW",
    "FREQEW", "TREQEW", "BREQEW", "BFREQEW", "BTREQEW", "DRET", "POPXJMP",
    "POPXCJMP", "POPXNCJMP", "CALLPOPA", "POPI0", "POPI1", "POPI2", "POPI3",
    "POPF0", "POPF1", "POPF2", "POPF3", "POPF4", "POPF5", "POPF6", "POPF7",
    "POPF8", "POPF9", "PUSHI0", "PUSHI1", "PUSHI2", "PUSHI3", "PUSHF0",
    "PUSHF1", "PUSHF2", "PUSHF3", "PUSHF4", "PUSHF5", "PUSHF6", "PUSHF7",
    "PUSHF8", "PUSHF9", "PUSHAINTER", "SYSTEM", "REQWAIT", "PREQWAIT",
    "REQCHG", "ACTREQ",
]
assert len(OP_NAMES) == 123

# ── op classes ───────────────────────────────────────────────────────────────
# queue ops: first-popped operand -> req[4] -> node+8 (ev)
REQ_QUEUE = {0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
             0x45, 0x46, 0x47, 0x48, 0x49,
             0x4A, 0x4B, 0x4C, 0x4D, 0x4E,
             0x4F, 0x50, 0x51, 0x52, 0x53}
# wait ops: first-popped operand is an ev too (park target, not node+8)
REQ_WAIT = {0x77, 0x78}
REQ_MISC = {0x79, 0x7A}
REQ_ALL = REQ_QUEUE | REQ_WAIT | REQ_MISC

# ── stack effects (pops, pushes) — 'V' = variable/indirect ──────────────────
EFFECT = {}
for _i in range(0x7B):
    EFFECT[_i] = (0, 0)
for _i in range(0x01, 0x19):
    EFFECT[_i] = (2, 1)                      # binary ops
for _i in (0x19, 0x1A, 0x1C):
    EFFECT[_i] = (1, 1)                      # unary ops
EFFECT.update({
    0x1F: (0, 1),                            # PUSHV var[imm]
    0x20: (1, 0), 0x21: (1, 0),              # POPV / POPVL
    0x22: (1, 1),                            # PUSHAR var[imm][pop idx]
    0x23: (2, 0), 0x24: (2, 0),              # POPAR / POPARL (value+index)
    0x25: (1, 0),                            # POPA -> ctx float accum
    0x26: (0, 1),                            # PUSHA faccum
    0x27: (1, 1),                            # PUSHARP elem addr
    0x28: (0, 1), 0x29: (0, 1),              # PUSHX / PUSHY
    0x2A: (1, 0),                            # POPX
    0x2B: (0, 1),                            # REPUSH (dup top)
    0x2C: (1, 0),                            # POPY
    0x2D: (0, 1), 0x2E: (0, 1), 0x2F: (0, 1),  # PUSHI / PUSHII / PUSHF
    0x30: (0, 0), 0x31: (1, 0), 0x32: (1, 0),  # JMP / CJMP / NCJMP
    0x33: 'V',                               # JSR (callee eats stack)
    0x34: (0, 0),                            # RTS
    0x35: 'V',                               # CALL (native, callee-defined)
    0x3C: (0, 0), 0x3D: (1, 0),              # RET / RETN
    0x3E: (0, 0), 0x3F: (1, 0),              # RETT / RETTN
    0x40: (0, 0),                            # HALT
    0x54: (0, 0),                            # DRET
    0x55: (1, 0), 0x56: (1, 0), 0x57: (1, 0),  # POPXJMP family
    0x58: 'V',                               # CALLPOPA
    0x76: 'V',                               # SYSTEM
    0x77: (2, 0), 0x78: (2, 0),              # REQWAIT / PREQWAIT
    0x79: (3, 0),                            # REQCHG
    0x7A: (2, 1),                            # ACTREQ
})
for _i in REQ_QUEUE:
    EFFECT[_i] = (3, 1)
for _i in range(0x59, 0x5D):
    EFFECT[_i] = (1, 0)                      # POPI0-3
for _i in range(0x5D, 0x67):
    EFFECT[_i] = (1, 0)                      # POPF0-9
for _i in range(0x67, 0x6B):
    EFFECT[_i] = (0, 1)                      # PUSHI0-3 (ctx slots)
for _i in range(0x6B, 0x75):
    EFFECT[_i] = (0, 1)                      # PUSHF0-9 (ctx fslots)
EFFECT[0x75] = (0, 1)                        # PUSHAINTER

# ops whose stack effect is unknown / control-flow — crossing them while
# walking back means "value produced on another path/context".
# CJMP/NCJMP are deliberately NOT here: they are conditional branches whose
# pop-1 effect is known, and values pushed BEFORE them exist on both the
# taken and fall-through paths (branches only affect forward flow), so
# crossing them backward is sound.
INDIRECT = {0x30: 'jmp', 0x33: 'jsr',
            0x34: 'rts', 0x35: 'call', 0x3C: 'ret', 0x3D: 'retn',
            0x3E: 'rett', 0x3F: 'rettn', 0x40: 'halt', 0x54: 'dret',
            0x55: 'popxjmp', 0x56: 'popxcjmp', 0x57: 'popxncjmp',
            0x58: 'callpopa', 0x76: 'system'}
# unconditional terminators: the NEXT linear instruction is a hard split
TERMINATOR = {0x30, 0x33, 0x34, 0x35, 0x3C, 0x3D, 0x3E, 0x3F, 0x40,
              0x54, 0x55, 0x58}
# (JSR/CALL are calls — execution continues after them, but the callee may
#  consume operands; crossing them = 'indirect' via INDIRECT anyway)

BINARY = set(range(0x01, 0x19))
UNARY = {0x19, 0x1A, 0x1C}

MAX_WALK = 64       # instructions to walk back before 'deep'
MAX_FUEL = 48       # recursive eval budget


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def i16(b, o):
    return struct.unpack_from("<h", b, o)[0]


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def i32(b, o):
    return struct.unpack_from("<i", b, o)[0]


def f32(b, o):
    return struct.unpack_from("<f", b, o)[0]


# ── ATEL chunk parse (same grammar as btlai_census/ep_bounds_audit) ──────────
def valid_atel(b, off):
    if off < 0 or off + 0x38 > len(b):
        return False
    code_len = u32(b, off)
    code_off = u32(b, off + 0x30)
    wcount = u16(b, off + 0x34)
    if not (0 < code_len <= len(b)):
        return False
    if not (0x38 <= code_off < len(b)):
        return False
    if wcount == 0 or wcount > 64:
        return False
    if off + 0x38 + 4 * wcount > len(b):
        return False
    w0 = u32(b, off + 0x38)
    if w0 < 0x38 or off + w0 + 0x34 > len(b):
        return False
    return True


def parse_chunk(b, base):
    """Parse ATEL chunk at file offset `base`. Returns dict or None."""
    if not valid_atel(b, base):
        return None
    code_len = u32(b, base)
    code_off = u32(b, base + 0x30)
    wcount = u16(b, base + 0x34)
    cs, ce = code_off, code_off + code_len
    workers = []
    for w in range(wcount):
        wo = u32(b, base + 0x38 + 4 * w)
        w = {"idx": w, "bad": True}
        if 0x38 <= wo and base + wo + 0x34 <= len(b):
            d = base + wo
            fc = u16(b, d + 0x08)
            w = {"idx": w, "bad": False,
                 "eventType": u16(b, d + 0x00),
                 "varCount": u16(b, d + 0x02),
                 "intConstCount": u16(b, d + 0x04),
                 "floatConstCount": u16(b, d + 0x06),
                 "funcCount": fc,
                 "jumpCount": u16(b, d + 0x0A),
                 "intConstOff": u32(b, d + 0x18),
                 "floatConstOff": u32(b, d + 0x1C),
                 "funcTableOff": u32(b, d + 0x20),
                 "jumpTableOff": u32(b, d + 0x24)}
            eps, jl = [], []
            fo = w["funcTableOff"]
            if fo and base + fo + 4 * fc <= len(b):
                eps = [u32(b, base + fo + 4 * j) for j in range(fc)]
            jo = w["jumpTableOff"]
            if jo and base + jo + 4 * w["jumpCount"] <= len(b):
                jl = [u32(b, base + jo + 4 * j)
                      for j in range(w["jumpCount"])]
            io = w["intConstOff"]
            ic = w["intConstCount"]
            if io and base + io + 4 * ic <= len(b):
                w["intConsts"] = [i32(b, base + io + 4 * j)
                                  for j in range(ic)]
            else:
                w["intConsts"] = []
            w["entryPoints"], w["jumpLabels"] = eps, jl
        workers.append(w)
    return {"base": base, "code_len": code_len, "code_off": code_off,
            "code_span": (cs, ce), "workers": workers}


def decode(b, base, cs, ce):
    """Linear decode of [base+cs, base+ce). Returns list of
    (rel_addr, idx, operand_or_None)."""
    out = []
    i = base + cs
    end = base + ce
    while i < end:
        op = b[i]
        idx = op & 0x7F
        if op & 0x80:
            if i + 3 > end:
                break
            out.append((i - base, idx, u16(b, i + 1)))
            i += 3
        else:
            out.append((i - base, idx, None))
            i += 1
    return out


# ── symbolic backward eval ───────────────────────────────────────────────────
class Slice:
    """Backward symbolic evaluator over one decoded code region."""

    def __init__(self, insns, splits, const_resolver):
        self.insns = insns
        self.idx_by_addr = {a: k for k, (a, _, _) in enumerate(insns)}
        self.splits = splits                    # set of rel addrs
        self.const_resolver = const_resolver    # (addr)->worker|None
        self.fuel = MAX_FUEL

    def _producer(self, j, depth):
        """Instruction that pushed the slot `depth`-below-top before insn j.
        Returns (kind, insn_index)."""
        i = j - 1
        steps = 0
        while i >= 0 and steps < MAX_WALK:
            addr, idx, operand = self.insns[i]
            eff = EFFECT.get(idx, (0, 0))
            if eff == 'V' or idx in INDIRECT:
                return ("indirect:" + (INDIRECT.get(idx)
                                       or OP_NAMES[idx].lower()), i)
            pops, pushes = eff
            if pushes:
                if depth < pushes:
                    return ("found", i)
                depth -= pushes
            if pops:
                depth += pops
            if addr in self.splits and depth >= 0:
                # slot was pushed BEFORE a join point -> path-dependent
                return ("crossblock", i)
            i -= 1
            steps += 1
        if i < 0:
            return ("start", -1)
        return ("deep", -1)

    def _eval_binop(self, idx, a, b):
        """Fold a binary op over consts. a = deeper operand, b = top."""
        av, bv = a[1], b[1]
        try:
            if idx == 0x01:
                return ("const", 1 if (av or bv) else 0)
            if idx == 0x02:
                return ("const", 1 if (av and bv) else 0)
            if idx == 0x03:
                return ("const", (av | bv) & 0xFFFFFFFF)
            if idx == 0x04:
                return ("const", (av ^ bv) & 0xFFFFFFFF)
            if idx == 0x05:
                return ("const", (av & bv) & 0xFFFFFFFF)
            if idx == 0x06:
                return ("const", 1 if av == bv else 0)
            if idx == 0x07:
                return ("const", 1 if av != bv else 0)
            if idx == 0x08:
                return ("const", 1 if (av & 0xFFFFFFFF) > (bv & 0xFFFFFFFF)
                        else 0)
            if idx == 0x09:
                return ("const", 1 if (av & 0xFFFFFFFF) < (bv & 0xFFFFFFFF)
                        else 0)
            if idx == 0x0A:
                return ("const", 1 if av > bv else 0)
            if idx == 0x0B:
                return ("const", 1 if av < bv else 0)
            if idx in (0x0C, 0x0E):
                return ("const", 1 if av >= bv else 0)
            if idx in (0x0D, 0x0F):
                return ("const", 1 if av <= bv else 0)
            if idx == 0x10:
                return ("const", 1 if (bv & (1 << av)) else 0)
            if idx == 0x11:
                return ("const", 0 if (bv & (1 << av)) else 1)
            if idx == 0x12:
                return ("const", (bv << av) & 0xFFFFFFFF)
            if idx == 0x13:
                return ("const", (bv & 0xFFFFFFFF) >> (av & 31))
            if idx == 0x14:
                return ("const", (av + bv) & 0xFFFFFFFF)
            if idx == 0x15:
                return ("const", (av - bv) & 0xFFFFFFFF)
            if idx == 0x16:
                return ("const", (av * bv) & 0xFFFFFFFF)
            if idx == 0x17:
                return ("const", int(av / bv) if bv else 0)
            if idx == 0x18:
                return ("const", av % bv if bv else 0)
        except Exception:
            pass
        return ("dyn", "expr:" + OP_NAMES[idx])

    def eval(self, j, depth):
        """Symbolic value of slot `depth` before insn j.
        Returns ('const', v, desc) | ('dyn', kind, desc) | ('unres', kind, d)."""
        if self.fuel <= 0:
            return ("unres", "fuel", "")
        self.fuel -= 1
        kind, i = self._producer(j, depth)
        if kind != "found":
            return ("unres", kind, "")
        addr, idx, operand = self.insns[i]
        nm = OP_NAMES[idx]
        here = "@0x%x" % addr
        if idx == 0x2E:                          # PUSHII (sign-extended imm16)
            v = operand if operand < 0x8000 else operand - 0x10000
            return ("const", v, "PUSHII %d%s" % (v, here))
        if idx == 0x2D:                          # PUSHI intConst[imm]
            w = self.const_resolver(addr)
            ics = w.get("intConsts", []) if w else []
            if operand < len(ics):
                return ("const", ics[operand],
                        "PUSHI c%d=%d%s" % (operand, ics[operand], here))
            return ("dyn", "constidx:%d" % operand, "PUSHI %d%s"
                    % (operand, here))
        if idx == 0x2F:
            return ("dyn", "fconst", "PUSHF %d%s" % (operand, here))
        if idx == 0x1F:
            return ("dyn", "var:%d" % operand, "PUSHV %d%s" % (operand, here))
        if idx == 0x22:
            return ("dyn", "arr:%d" % operand, "PUSHAR %d%s" % (operand, here))
        if idx == 0x27:
            return ("dyn", "arraddr:%d" % operand,
                    "PUSHARP %d%s" % (operand, here))
        if idx == 0x26:
            return ("dyn", "facc", "PUSHA" + here)
        if idx == 0x28:
            return ("dyn", "xreg", "PUSHX" + here)
        if idx == 0x29:
            return ("dyn", "yreg", "PUSHY" + here)
        if idx == 0x2B:                          # REPUSH: dup of slot below
            return self.eval(i, 0)
        if 0x67 <= idx <= 0x6A:
            return ("dyn", "ctxslot", "%s%s" % (nm, here))
        if 0x6B <= idx <= 0x74:
            return ("dyn", "fctxslot", "%s%s" % (nm, here))
        if idx == 0x75:
            return ("dyn", "ainter:%d" % operand,
                    "PUSHAINTER %d%s" % (operand, here))
        if idx in REQ_QUEUE:
            return ("dyn", "reqres", "%s%s" % (nm, here))
        if idx in (0x35, 0x58):
            return ("dyn", "callres", "%s%s" % (nm, here))
        if idx in REQ_WAIT or idx in REQ_MISC:
            return ("dyn", "reqres", "%s%s" % (nm, here))
        if idx in BINARY:
            b = self.eval(i, 0)
            a = self.eval(i, 1)
            if a[0] == "const" and b[0] == "const":
                r = self._eval_binop(idx, a, b)
                if r[0] == "const":
                    return ("const", r[1],
                            "%s(%s,%s)=%d%s" % (nm, a[2], b[2], r[1], here))
            leaves = ";".join(x[2] for x in (a, b) if x[0] != "const")
            return ("dyn", "expr:%s" % nm,
                    "%s%s leaves[%s]" % (nm, here, leaves))
        if idx in UNARY:
            x = self.eval(i, 0)
            if x[0] == "const":
                if idx == 0x19:
                    return ("const", 0 if x[1] else 1, "NOT(%s)" % x[2])
                if idx == 0x1C:
                    return ("const", (~x[1]) & 0xFFFFFFFF,
                            "BNOT(%s)" % x[2])
                return ("const", (-x[1]) & 0xFFFFFFFF, "UMINUS(%s)" % x[2])
            return ("dyn", "expr:%s" % nm, "%s%s leaves[%s]"
                    % (nm, here, x[2]))
        return ("dyn", "op:" + nm, "%s%s" % (nm, here))


# ── per-chunk scan ───────────────────────────────────────────────────────────
def scan_chunk(b, chunk, fpath, locale, ctag):
    """Scan one ATEL chunk for REQ sites. Returns (site_rows, stats)."""
    cs, ce = chunk["code_span"]
    insns = decode(b, chunk["base"], cs, ce)
    workers = chunk["workers"]

    # split points: every jumpTable label + entry point + code start +
    # fallthrough-after-terminator
    splits = {cs}
    ep_owner = {}
    for w in workers:
        for ep in w.get("entryPoints", []):
            splits.add(cs + ep)
            ep_owner.setdefault(cs + ep, w)
        for lb in w.get("jumpLabels", []):
            splits.add(cs + lb)
    addr_set = set(a for a, _, _ in insns)
    for k, (a, idx, operand) in enumerate(insns[:-1]):
        if idx in TERMINATOR:
            splits.add(insns[k + 1][0])
    splits &= addr_set

    # ep -> owning worker map (for PUSHI const resolution): owner of the
    # function containing addr = the worker whose EP list covers it.
    eps_sorted = sorted(ep_owner)
    def resolver(addr):
        cand = None
        for ep in eps_sorted:
            if ep <= addr:
                cand = ep
            else:
                break
        return ep_owner.get(cand) if cand is not None else None

    sl = Slice(insns, splits, resolver)
    rows = []
    for j, (a, idx, operand) in enumerate(insns):
        if idx not in REQ_ALL:
            continue
        cls = ("queue" if idx in REQ_QUEUE else
               "wait" if idx in REQ_WAIT else "misc")
        sl.fuel = MAX_FUEL
        ev = sl.eval(j, 0)
        sl.fuel = MAX_FUEL
        tgt = sl.eval(j, 1)
        sl.fuel = MAX_FUEL
        pay = sl.eval(j, 2)
        rows.append({
            "locale": locale, "file": fpath, "chunk": ctag,
            "rel": "0x%x" % a, "op_idx": "0x%02x" % idx,
            "op": OP_NAMES[idx], "cls": cls,
            "site_is_target": "yes" if a in splits else "",
            "ev_class": ev[0], "ev_value": ev[1] if ev[0] == "const" else "",
            "ev_u16": (ev[1] & 0xFFFF) if ev[0] == "const" else "",
            "ev_kind": ev[1] if ev[0] != "const" else "",
            "ev_desc": ev[2],
            "tgt_class": tgt[0],
            "tgt_value": tgt[1] if tgt[0] == "const" else tgt[1],
            "tgt_desc": tgt[2],
            "pay_class": pay[0],
            "pay_value": pay[1] if pay[0] == "const" else pay[1],
            "pay_desc": pay[2],
        })
    funcs = [w["funcCount"] for w in workers if not w["bad"]]
    stats = {"workers": len(workers),
             "funcCounts": funcs,
             "min_fc": min(funcs) if funcs else -1,
             "max_fc": max(funcs) if funcs else -1,
             "w0_fc": workers[0]["funcCount"] if workers and
             not workers[0]["bad"] else -1,
             "insns": len(insns)}
    return rows, stats


# ── container discovery ──────────────────────────────────────────────────────
def chunks_in_file(path):
    """Yield (tag, chunk_dict) for every ATEL chunk in the file."""
    try:
        b = open(path, "rb").read()
    except OSError:
        return None, []
    if len(b) < 0x38:
        return b, []
    out = []
    if b[:4] == b"EV01":
        c0 = u32(b, 4)
        ch = parse_chunk(b, c0)
        if ch:
            out.append(("ev01_c0", ch))
        return b, out
    sig = u32(b, 0)
    p0 = u32(b, 4)
    nptr = (p0 - 4) // 4 if 4 <= p0 <= len(b) else 0
    if sig in (5, 7, 8) and 1 <= nptr <= 16:
        for i in range(nptr):
            p = u32(b, 4 + 4 * i)
            if p:
                ch = parse_chunk(b, p)
                if ch:
                    out.append(("ptr%d" % i, ch))
        return b, out
    ch = parse_chunk(b, 0)
    if ch:
        out.append(("raw", ch))
    return b, out


def iter_corpus(roots):
    seen = set()
    for root in roots:
        if not os.path.isdir(root):
            continue
        for loc in sorted(os.listdir(root)):
            ld = os.path.join(root, loc)
            if not os.path.isdir(ld):
                continue
            for pat in ("**/*.ebp", "**/*.bin"):
                for p in sorted(glob.glob(os.path.join(ld, pat),
                                          recursive=True)):
                    key = os.path.realpath(p)
                    if key in seen:
                        continue
                    seen.add(key)
                    yield p, loc


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="FFX REQ-path ev operand corpus dataflow audit")
    ap.add_argument("--root", action="append", default=[])
    ap.add_argument("--outdir", default=OUTDIR)
    ap.add_argument("--max-files", type=int, default=0)
    ap.add_argument("--verbose", action="store_true")
    a = ap.parse_args(argv)
    roots = [r for r in (a.root or ROOTS) if os.path.isdir(r)]
    if not roots:
        print("no corpus root found")
        return 2

    site_rows = []
    file_rows = []
    n_files = n_atel = 0
    kind_ctr = collections.Counter()
    for path, loc in iter_corpus(roots):
        if a.max_files and n_files >= a.max_files:
            break
        n_files += 1
        b, chunks = chunks_in_file(path)
        if b is None:
            continue
        if not chunks:
            continue
        n_atel += 1
        f_sites = []
        f_funcs = []
        f_workers = 0
        for tag, ch in chunks:
            rows, st = scan_chunk(b, ch, path, loc, tag)
            f_sites += rows
            f_funcs += st["funcCounts"]
            f_workers += st["workers"]
        site_rows += f_sites
        if f_sites:
            const_evs = [r["ev_value"] for r in f_sites
                         if r["ev_class"] == "const"]
            dyn = collections.Counter(r["ev_kind"] for r in f_sites
                                      if r["ev_class"] != "const")
            for k, v in dyn.items():
                kind_ctr[k.split(":")[0]] += v
            min_fc = min(f_funcs) if f_funcs else -1
            max_fc = max(f_funcs) if f_funcs else -1
            # authored intent: ev indexes the largest EP table in the script
            # (corpus invariant max_ev == max_fc-1) -> record which worker
            tgt_widx = f_funcs.index(max_fc) if f_funcs else -1
            w0_fc = f_funcs[0] if f_funcs else -1
            mx = max(const_evs) if const_evs else ""
            mx_u16 = max((r["ev_u16"] for r in f_sites
                          if r["ev_class"] == "const"), default="")
            file_rows.append({
                "locale": loc, "file": path, "chunks": len(chunks),
                "workers": f_workers,
                "min_fc": min_fc, "max_fc": max_fc,
                "ev_target_widx": tgt_widx, "w0_fc": w0_fc,
                "n_sites": len(f_sites),
                "n_queue": sum(1 for r in f_sites
                               if r["cls"] == "queue"),
                "n_wait": sum(1 for r in f_sites if r["cls"] == "wait"),
                "n_misc": sum(1 for r in f_sites if r["cls"] == "misc"),
                "n_const_ev": len(const_evs),
                "n_dyn_ev": sum(dyn.values()),
                "max_ev_signed": mx, "max_ev_u16": mx_u16,
                "min_ev_signed": min(const_evs) if const_evs else "",
                "ev_ge_min_fc": sum(1 for r in f_sites
                                    if r["ev_class"] == "const"
                                    and min_fc >= 0
                                    and (r["ev_u16"] >= min_fc
                                         or r["ev_value"] < 0)),
                "ev_ge_max_fc": sum(1 for r in f_sites
                                    if r["ev_class"] == "const"
                                    and max_fc >= 0
                                    and (r["ev_u16"] >= max_fc
                                         or r["ev_value"] < 0)),
                "dyn_kinds": ";".join("%s:%d" % kv
                                      for kv in dyn.most_common()),
                "target_sites": sum(1 for r in f_sites
                                    if r["site_is_target"]),
            })
        if a.verbose and f_sites:
            print("%s [%s]: %d sites" % (os.path.basename(path), loc,
                                         len(f_sites)))

    os.makedirs(a.outdir, exist_ok=True)
    p1 = os.path.join(a.outdir, "reqpath_ev_sites.csv")
    fields = ["locale", "file", "chunk", "rel", "op_idx", "op", "cls",
              "site_is_target", "ev_class", "ev_value", "ev_u16",
              "ev_kind", "ev_desc", "tgt_class", "tgt_value", "tgt_desc",
              "pay_class", "pay_value", "pay_desc"]
    with open(p1, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fields)
        w.writeheader()
        for r in site_rows:
            w.writerow(r)

    p2 = os.path.join(a.outdir, "reqpath_ev_summary.csv")
    fields2 = ["locale", "file", "chunks", "workers", "min_fc", "max_fc",
               "ev_target_widx", "w0_fc",
               "n_sites", "n_queue", "n_wait", "n_misc", "n_const_ev",
               "n_dyn_ev", "max_ev_signed", "max_ev_u16", "min_ev_signed",
               "ev_ge_min_fc", "ev_ge_max_fc", "dyn_kinds", "target_sites"]
    with open(p2, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fields2)
        w.writeheader()
        for r in file_rows:
            w.writerow(r)
        wcsv = csv.writer(f)
        wcsv.writerow([])
        wcsv.writerow(["=== SUMMARY ==="])
        all_const = [r["ev_value"] for r in site_rows
                     if r["ev_class"] == "const"]
        wcsv.writerow(["files_scanned", n_files, "files_with_atel", n_atel,
                       "files_with_req", len(file_rows)])
        wcsv.writerow(["req_sites_total", len(site_rows),
                       "queue", sum(1 for r in site_rows
                                    if r["cls"] == "queue"),
                       "wait", sum(1 for r in site_rows
                                   if r["cls"] == "wait"),
                       "misc", sum(1 for r in site_rows
                                   if r["cls"] == "misc")])
        wcsv.writerow(["const_ev", len(all_const),
                       "dyn_ev", sum(1 for r in site_rows
                                     if r["ev_class"] != "const")])
        if all_const:
            wcsv.writerow(["max_ev_signed", max(all_const),
                           "max_ev_u16",
                           max(v & 0xFFFF for v in all_const),
                           "min_ev_signed", min(all_const)])
        wcsv.writerow([])
        wcsv.writerow(["=== DYNAMIC PRODUCER KINDS ==="])
        for k, v in kind_ctr.most_common():
            wcsv.writerow([k, v])
        wcsv.writerow([])
        wcsv.writerow(["=== CONST EV HISTOGRAM (top 40) ==="])
        hc = collections.Counter(all_const)
        for v, c in sorted(hc.items()):
            wcsv.writerow([v, c])
    print("files scanned: %d (atel containers %d, req-bearing %d)"
          % (n_files, n_atel, len(file_rows)))
    print("req sites: %d | const ev %d | dyn/unres %d"
          % (len(site_rows), len(all_const),
             len(site_rows) - len(all_const)))
    if all_const:
        print("ev range: %d..%d (u16 max %d)"
              % (min(all_const), max(all_const),
                 max(v & 0xFFFF for v in all_const)))
    print("wrote %s\nwrote %s" % (p1, p2))
    return 0


if __name__ == "__main__":
    sys.exit(main())
