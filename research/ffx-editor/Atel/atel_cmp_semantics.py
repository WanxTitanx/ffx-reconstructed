#!/usr/bin/env python3
"""ATEL comparison-opcode semantics validator — Jarvis-ATEL-CMP-VALIDATOR (2026-09-18).

Decodes a byte sequence of ATEL event-VM instructions and reports the TRUE
comparison semantics, proven by native decompile + the in-binary name table
`g_FFX_Atel_OpcodeNameTable @0xC54600` (consumed by
`FFX_FieldDebug_AiOpcodeNameLookup @0x8855A0`).

GROUND TRUTH (docs/reverse/FFX_EVENTVM_OPS_2026-09-17.md §7 +
docs/reverse/data/wave13/eventvm_ops.csv):

  Stack convention:  b = pop (TOS, last pushed) · a = pop (base, first pushed)
  Result pushed:     a <rel> b    (U opcodes: unsigned; other opcodes: signed;
                                   int path if both operand tags==int,
                                   else float — `CheckFlagBytePair` decides
                                   int-vs-float at RUNTIME, not the opcode)

  opcode name   pushes      twin
  0x08   OPGTU  a > b       0x0A
  0x09   OPLSU  a < b       0x0B
  0x0A   OPGT   a > b       0x08
  0x0B   OPLS   a < b       0x09
  0x0C   OPGTEU a >= b      0x0E
  0x0D   OPLSEU a <= b      0x0F
  0x0E   OPGTE  a >= b      0x0C
  0x0F   OPLSE  a <= b      0x0D
  0x06   OPEQ   a == b      —
  0x07   OPNE   a != b      —

The U / non-U pairs differ for integer values across the sign bit: native JBE/JB
at 0x86462D/0x86469C versus JLE/JL at 0x864711/0x864786. The original decompile
lost this distinction. See FFX_ATEL_CODEC_VALIDATION_2026-09-20.md. There are no
float-only comparison opcodes: operand tags select the int/float path.

THE HISTORICAL PRODUCT BUG this tool demonstrates (fixed in the 2026-09-20 lane):
  The old editor codec (`FFXProjectEditor/FfxLib/Ai/`) declared `LE = 0x0A`
  ("0x0A = a <= b") — WRONG. 0x0A computes `a > b`. So that editor emitted
    var <= N : [PUSHV var, PUSHII N, 0x0A]  -> actually computes  var > N   (INVERTED)
    var >= N : [PUSHII N, PUSHV var, 0x0A]  -> actually computes  N > var   (i.e. var < N, INVERTED)
  while  var < N  ([PUSHV,PUSHII,0x0B]) and  var > N ([PUSHII,PUSHV,0x0B])
  are valid swapped-operand forms.

Usage:
  atel_cmp_semantics.py --bytes "9F 00 00 AE 05 00 0A"      # raw instruction bytes (hex)
  atel_cmp_semantics.py --insns "PUSHV 0 ; PUSHII 5 ; 0x0A"
  atel_cmp_semantics.py --emit  "var <= 5"               # correct emission idioms
  atel_cmp_semantics.py --table                          # print the truth table
  atel_cmp_semantics.py --selftest                       # prove ground truth + the bug

Exit status: 0 ok / 2 usage / 1 selftest failure.
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass

# ── opcode name table (in-binary truth, g_FFX_Atel_OpcodeNameTable @0xC54600) ──
# Only the ops relevant to comparison validation are given explicit stack
# semantics; everything else still gets its proven name for the disasm trace.

OP_NAMES = {
    0x00: "NOP", 0x01: "OPLOR", 0x02: "OPLAND", 0x03: "OPOR", 0x04: "OPEOR",
    0x05: "OPAND", 0x06: "OPEQ", 0x07: "OPNE", 0x08: "OPGTU", 0x09: "OPLSU",
    0x0A: "OPGT", 0x0B: "OPLS", 0x0C: "OPGTEU", 0x0D: "OPLSEU", 0x0E: "OPGTE",
    0x0F: "OPLSE", 0x10: "OPBON", 0x11: "OPBOFF", 0x12: "OPSLL", 0x13: "OPSRL",
    0x14: "OPADD", 0x15: "OPSUB", 0x16: "OPMUL", 0x17: "OPDIV", 0x18: "OPMOD",
    0x19: "OPNOT", 0x1A: "OPUMINUS", 0x1B: "OPFIXADRS", 0x1C: "OPBNOT",
    0x1D: "LABEL", 0x1E: "TAG", 0x1F: "PUSHV", 0x20: "POPV", 0x21: "POPVL",
    0x22: "PUSHAR", 0x23: "POPAR", 0x24: "POPARL", 0x25: "POPA", 0x26: "PUSHA",
    0x27: "PUSHARP", 0x28: "PUSHX", 0x29: "PUSHY", 0x2A: "POPX", 0x2B: "REPUSH",
    0x2C: "POPY", 0x2D: "PUSHI", 0x2E: "PUSHII", 0x2F: "PUSHF", 0x30: "JMP",
    0x31: "CJMP", 0x32: "NCJMP", 0x33: "JSR", 0x34: "RTS", 0x35: "CALL",
    0x36: "REQ", 0x37: "REQSW", 0x38: "REQEW", 0x39: "PREQ", 0x3A: "PREQSW",
    0x3B: "PREQEW", 0x3C: "RET", 0x3D: "RETN", 0x3E: "RETT", 0x3F: "RETTN",
    0x40: "HALT", 0x41: "PUSHN", 0x42: "PUSHT", 0x43: "PUSHVP", 0x44: "PUSHFIX",
    0x54: "DRET", 0x55: "POPXJMP", 0x56: "POPXCJMP", 0x57: "POPXNCJMP",
    0x58: "CALLPOPA",
    0x59: "POPI0", 0x5A: "POPI1", 0x5B: "POPI2", 0x5C: "POPI3",
    0x5D: "POPF0", 0x5E: "POPF1", 0x5F: "POPF2", 0x60: "POPF3", 0x61: "POPF4",
    0x62: "POPF5", 0x63: "POPF6", 0x64: "POPF7", 0x65: "POPF8", 0x66: "POPF9",
    0x67: "PUSHI0", 0x68: "PUSHI1", 0x69: "PUSHI2", 0x6A: "PUSHI3",
    0x6B: "PUSHF0", 0x6C: "PUSHF1", 0x6D: "PUSHF2", 0x6E: "PUSHF3",
    0x6F: "PUSHF4", 0x70: "PUSHF5", 0x71: "PUSHF6", 0x72: "PUSHF7",
    0x73: "PUSHF8", 0x74: "PUSHF9",
    0x75: "PUSHAINTER", 0x76: "SYSTEM", 0x77: "REQWAIT", 0x78: "PREQWAIT",
    0x79: "REQCHG", 0x7A: "ACTREQ",
}

# comparison opcode -> (in-binary name, relation symbol pushed = a <rel> b)
CMP_REL = {
    0x06: ("OPEQ", "=="),
    0x07: ("OPNE", "!="),
    0x08: ("OPGTU", ">"),
    0x09: ("OPLSU", "<"),
    0x0A: ("OPGT", ">"),
    0x0B: ("OPLS", "<"),
    0x0C: ("OPGTEU", ">="),
    0x0D: ("OPLSEU", "<="),
    0x0E: ("OPGTE", ">="),
    0x0F: ("OPLSE", "<="),
}

# Same relation with DIFFERENT integer signedness (U / non-U counterparts).
CMP_TWIN = {0x08: 0x0A, 0x0A: 0x08, 0x09: 0x0B, 0x0B: 0x09,
            0x0C: 0x0E, 0x0E: 0x0C, 0x0D: 0x0F, 0x0F: 0x0D}

CMP_UNSIGNED = frozenset((0x08, 0x09, 0x0C, 0x0D))


def compare_int(opcode: int, a: int, b: int) -> bool:
    """Native integer path only; this is not an emulator for float-tagged cells."""
    a, b = a & 0xFFFFFFFF, b & 0xFFFFFFFF
    if opcode not in CMP_UNSIGNED:
        a, b = (a ^ 0x80000000) - 0x80000000, (b ^ 0x80000000) - 0x80000000
    rel = CMP_REL[opcode][1]
    return {"==": a == b, "!=": a != b, ">": a > b, "<": a < b,
            ">=": a >= b, "<=": a <= b}[rel]


# binary arithmetic/logic ops: opcode -> symbol (pop 2, push (a sym b))
BIN_OPS = {
    0x01: "||", 0x02: "&&", 0x03: "|", 0x04: "^", 0x05: "&",
    0x10: "bit_on", 0x11: "bit_off",
    0x12: "<<", 0x13: ">>",
    0x14: "+", 0x15: "-", 0x16: "*", 0x17: "/", 0x18: "%",
}

UNARY_OPS = {0x19: "!", 0x1A: "negf", 0x1C: "~"}


@dataclass
class Insn:
    offset: int          # byte offset in the source blob
    raw: int             # raw opcode byte (0x80-bit set => carries u16 operand)
    opcode: int          # raw & 0x7F
    has_operand: bool
    operand: int | None = None

    @property
    def name(self) -> str:
        return OP_NAMES.get(self.opcode, f"?0x{self.opcode:02X}")

    @property
    def length(self) -> int:
        return 3 if self.has_operand else 1


def decode(data: bytes) -> list[Insn]:
    """Decode a raw ATEL instruction stream (FFX_Atel_FetchOpcode @0x869D00 rule:
    bit7 set => 3-byte insn w/ u16 LE operand; else 1-byte)."""
    insns: list[Insn] = []
    i = 0
    while i < len(data):
        raw = data[i]
        if raw & 0x80:
            if i + 3 > len(data):
                raise ValueError(f"truncated 3-byte insn @ +0x{i:04X}")
            insns.append(Insn(i, raw, raw & 0x7F, True,
                              data[i + 1] | (data[i + 2] << 8)))
            i += 3
        else:
            insns.append(Insn(i, raw, raw & 0x7F, False))
            i += 1
    return insns


@dataclass
class Item:
    """One symbolic operand-stack value."""
    label: str                      # human description ("var0", "5", "(a+b)")
    is_cmp: bool = False            # True when produced by a comparison op
    cmp: tuple[str, str, str] | None = None   # (a_label, rel, b_label)

    def __str__(self) -> str:
        return self.label


def _imm_label(u16: int) -> str:
    """PUSHII pushes the SIGN-EXTENDED imm16; show the signed value."""
    s = u16 - 0x10000 if u16 & 0x8000 else u16
    return f"{s} (0x{u16:04X})" if s < 0 else str(s)


def simulate(insns: list[Insn], call_argc: int = 2, verbose: bool = True
             ) -> list[str]:
    """Replay the stack for the subset of the VM needed to read guards.
    Returns report lines; every comparison pop/push is narrated."""
    out: list[str] = []
    stack: list[Item] = []
    xreg: Item | None = None
    stores: list[str] = []

    def pop() -> Item:
        if not stack:
            out.append("  !! stack UNDERFLOW (pop on empty) — stream desynced?")
            return Item("<underflow>")
        return stack.pop()

    def peek_state() -> str:
        return "[" + ", ".join(i.label for i in stack) + "]"

    def push_cmp(opcode: int, a: Item, b: Item) -> None:
        name, rel = CMP_REL[opcode]
        rel = rel + " (u32 for int tags)" if opcode in CMP_UNSIGNED else rel
        cmp = (a.label, rel, b.label)
        stack.append(Item(f"({a.label} {rel} {b.label})", True, cmp))
        out.append(f"    >> {name} (0x{opcode:02X}): pop b={b.label} ; pop a={a.label} "
                   f"-> push (a {rel} b) = ({a.label} {rel} {b.label})")

    for insn in insns:
        op = insn.opcode
        head = f"+0x{insn.offset:04X}  {insn.name}" + (
            f" 0x{insn.operand:04X}" if insn.has_operand else "")
        if verbose:
            out.append(head)

        if op in CMP_REL:                      # ── comparisons ──
            b = pop(); a = pop()
            push_cmp(op, a, b)
        elif op in BIN_OPS:                    # ── binary arith/logic ──
            b = pop(); a = pop()
            sym = BIN_OPS[op]
            label = (f"({a.label} {sym} {b.label})" if sym not in ("bit_on", "bit_off")
                     else f"({a.label} {sym} {b.label})")
            stack.append(Item(label))
            out.append(f"    {insn.name}: pop {b.label}, pop {a.label} -> push {label}")
        elif op in UNARY_OPS:                  # ── unary ──
            a = pop()
            sym = UNARY_OPS[op]
            label = f"({sym}{a.label})" if sym != "negf" else f"(-{a.label})f"
            stack.append(Item(label))
            out.append(f"    {insn.name}: pop {a.label} -> push {label}")
        elif op == 0x1F:                       # PUSHV var-desc
            stack.append(Item(f"var{insn.operand}"))
            out.append(f"    push var{insn.operand}  {peek_state()}")
        elif op == 0x2D:                       # PUSHI int-pool idx
            stack.append(Item(f"intpool[{insn.operand}]"))
            out.append(f"    push intpool[{insn.operand}]  {peek_state()}")
        elif op == 0x2E:                       # PUSHII sign-ext imm16
            stack.append(Item(_imm_label(insn.operand or 0)))
            out.append(f"    push {_imm_label(insn.operand or 0)}  {peek_state()}")
        elif op == 0x2F:                       # PUSHF float-pool idx
            stack.append(Item(f"f32pool[{insn.operand}]"))
            out.append(f"    push f32pool[{insn.operand}]  {peek_state()}")
        elif op == 0x22:                       # PUSHAR: i=pop; push elem[i]
            i = pop()
            stack.append(Item(f"elem[{i.label}]"))
            out.append(f"    PUSHAR: pop idx {i.label} -> push elem[{i.label}]")
        elif op == 0x27:                       # PUSHARP: push elem-address
            i = pop()
            stack.append(Item(f"&elem[{i.label}]"))
            out.append(f"    PUSHARP: pop idx {i.label} -> push &elem[{i.label}]")
        elif op == 0x28:
            stack.append(Item("X"))
            out.append(f"    push X  {peek_state()}")
        elif op == 0x29:
            stack.append(Item("Y"))
            out.append(f"    push Y  {peek_state()}")
        elif op == 0x26:
            stack.append(Item("faccum"))
            out.append(f"    push faccum  {peek_state()}")
        elif 0x67 <= op <= 0x6A:               # PUSHI0-3
            stack.append(Item(f"iReg{op - 0x67}"))
            out.append(f"    push iReg{op - 0x67}  {peek_state()}")
        elif 0x6B <= op <= 0x74:               # PUSHF0-9
            stack.append(Item(f"fReg{op - 0x6B}"))
            out.append(f"    push fReg{op - 0x6B}  {peek_state()}")
        elif op == 0x75:
            stack.append(Item(f"ainter[{insn.operand}]"))
            out.append(f"    push ainter[{insn.operand}]  {peek_state()}")
        elif op == 0x2B:                       # REPUSH: dup TOS
            top = stack[-1] if stack else Item("<underflow>")
            stack.append(Item(top.label))
            out.append(f"    REPUSH dup {top.label}  {peek_state()}")
        elif op in (0x20, 0x21):               # POPV / POPVL var-desc
            a = pop()
            stores.append(f"var{insn.operand} <- {a.label}")
            out.append(f"    {insn.name}: pop {a.label} -> var{insn.operand}")
        elif op in (0x23, 0x24):               # POPAR / POPARL
            i = pop(); a = pop()
            stores.append(f"elem[{i.label}] <- {a.label}")
            out.append(f"    {insn.name}: pop idx {i.label}, pop {a.label} -> store")
        elif op == 0x25:                       # POPA faccum
            a = pop()
            stores.append(f"faccum <- {a.label}")
            out.append(f"    POPA: pop {a.label} -> faccum")
        elif op == 0x2A:                       # POPX
            a = pop()
            xreg = a
            stores.append(f"X <- {a.label}")
            out.append(f"    POPX: pop {a.label} -> X reg")
        elif op == 0x2C:                       # POPY
            a = pop()
            stores.append(f"Y <- {a.label}")
            out.append(f"    POPY: pop {a.label} -> Y reg")
        elif 0x59 <= op <= 0x5C:               # POPI0-3
            a = pop()
            stores.append(f"iReg{op - 0x59} <- {a.label}")
            out.append(f"    POPI{op - 0x59}: pop {a.label}")
        elif 0x5D <= op <= 0x66:               # POPF0-9
            a = pop()
            stores.append(f"fReg{op - 0x5D} <- {a.label}")
            out.append(f"    POPF{op - 0x5D}: pop {a.label}")
        elif op in (0x35, 0x58):               # CALL / CALLPOPA
            args = [pop().label for _ in range(min(call_argc, len(stack)))]
            args.reverse()
            fid = insn.operand or 0
            if op == 0x35:
                stack.append(Item(f"call_{fid:04X}({', '.join(args)})"))
                out.append(f"    CALL 0x{fid:04X}: pop {len(args)} arg(s) "
                           f"({', '.join(args)}) -> push result")
            else:
                out.append(f"    CALLPOPA 0x{fid:04X}: pop {len(args)} arg(s) "
                           f"({', '.join(args)}) -> void")
        elif op == 0x30:
            out.append(f"    JMP -> jumpTable[{insn.operand}]")
        elif op in (0x31, 0x32):               # CJMP / NCJMP use X reg
            cond = xreg.label if xreg else "X"
            out.append(f"    {insn.name}: jump if {cond} "
                       f"{'!= 0' if op == 0x31 else '== 0'} -> jumpTable[{insn.operand}]")
            if xreg and xreg.is_cmp and xreg.cmp:
                a, rel, b = xreg.cmp
                out.append(f"    == GUARD: ({a} {rel} {b}) {'' if op == 0x31 else 'INVERTED (jump-if-false)'}")
        elif op in (0x55, 0x56, 0x57):         # POPX{,C,NC}JMP: X=pop (+jump)
            a = pop()
            xreg = a
            kind = {0x55: "JMP", 0x56: "CJMP (jump if X!=0)", 0x57: "NCJMP (jump if X==0)"}[op]
            out.append(f"    {insn.name}: pop {a.label} -> X ; then {kind} "
                       f"-> jumpTable[{insn.operand}]")
            if a.is_cmp and a.cmp:
                aa, rel, bb = a.cmp
                out.append(f"    == GUARD: ({aa} {rel} {bb})"
                           f"{' INVERTED (jump-if-false)' if op == 0x57 else ''}")
        elif op in (0x33,):
            out.append("    JSR -> script call (models as no stack effect)")
        elif op in (0x34, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x54):
            out.append(f"    {insn.name}: control/terminator (no stack model)")
        elif op in (0x1D, 0x1E, 0x76, 0x00, 0x1B):
            out.append(f"    {insn.name}: marker/NOP")
        elif op in (0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
                    0x45, 0x46, 0x47, 0x48, 0x49,
                    0x4A, 0x4B, 0x4C, 0x4D, 0x4E,
                    0x4F, 0x50, 0x51, 0x52, 0x53,
                    0x77, 0x78, 0x79, 0x7A):
            n = 3 if op in (0x36, 0x37, 0x38, 0x45, 0x46, 0x47, 0x48, 0x49,
                            0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53,
                            0x39, 0x3A, 0x3B) else 2
            args = [pop().label for _ in range(min(n, len(stack)))]
            out.append(f"    {insn.name}: pop {len(args)} ({', '.join(args)}) -> queue/park")
        else:
            out.append(f"    {insn.name}: (no stack model — skipped)")

    out.append("")
    out.append(f"final stack: {peek_state()}")
    if xreg is not None:
        out.append(f"X register : {xreg.label}")
    if stores:
        out.append("stores     : " + " ; ".join(stores))
    cmps = [i for i in stack if i.is_cmp] + ([xreg] if xreg and xreg.is_cmp else [])
    if cmps:
        out.append("")
        out.append("== COMPARISON(S) FOUND ==")
        seen = set()
        for c in cmps:
            if c.cmp and c.cmp not in seen:
                seen.add(c.cmp)
                a, rel, b = c.cmp
                out.append(f"    ({a} {rel} {b})")
    return out


# ── emission idioms ──────────────────────────────────────────────────────────
# For `a <rel> b` the VM offers TWO shapes:
#   direct : push a ; push b ; OP            (a <rel> b)
#   swap   : push b ; push a ; OP'           (b <rel'> a  ==  a <rel> b)
EMIT = {
    "<":  dict(direct=(0x0B, 0x09), swap=(0x0A, 0x08), swap_note="b > a"),
    "<=": dict(direct=(0x0F, 0x0D), swap=(0x0E, 0x0C), swap_note="b >= a"),
    ">":  dict(direct=(0x0A, 0x08), swap=(0x0B, 0x09), swap_note="b < a"),
    ">=": dict(direct=(0x0E, 0x0C), swap=(0x0F, 0x0D), swap_note="b <= a"),
    "==": dict(direct=(0x06, None), swap=(0x06, None), swap_note="b == a (commutative)"),
    "!=": dict(direct=(0x07, None), swap=(0x07, None), swap_note="b != a (commutative)"),
}


def emit_lines(expr: str) -> list[str]:
    m = re.match(r"^\s*(\w+)\s*(==|!=|<=|>=|<|>)\s*(\w+)\s*$", expr)
    if not m:
        return [f"!! cannot parse '{expr}' — expected 'a <rel> b' (a/b = varN | int | name)"]
    a, rel, b = m.group(1), m.group(2), m.group(3)
    info = EMIT[rel]
    da, db = info["direct"], info["swap"]

    def push(x: str) -> str:
        return f"PUSHII {x}" if re.fullmatch(r"-?\d+|0x[0-9A-Fa-f]+", x) else f"PUSHV {x}"

    lines = [f"semantic target: ({a} {rel} {b})", ""]
    lines.append(f"  direct : [{push(a)} ; {push(b)} ; {OP_NAMES[da[0]]} (0x{da[0]:02X})]"
                 + (f"   (unsigned counterpart, NOT a signed alias: 0x{da[1]:02X})" if da[1] is not None else ""))
    if db[0] is not None and db[0] != da[0]:
        lines.append(f"  swap   : [{push(b)} ; {push(a)} ; {OP_NAMES[db[0]]} (0x{db[0]:02X})]"
                     f"  = {info['swap_note']}"
                     + (f"   (unsigned counterpart, NOT a signed alias: 0x{db[1]:02X})" if db[1] is not None else ""))
    else:
        lines.append(f"  swap   : [{push(b)} ; {push(a)} ; {OP_NAMES[db[0]]} (0x{db[0]:02X})]  (commutative)")
    if rel in ("<=", ">="):
        bad_op = "0x0A"
        seq = (f"[{push(a)} ; {push(b)} ; 0x0A]" if rel == "<="
               else f"[{push(b)} ; {push(a)} ; 0x0A]")
        lines += ["",
                  f"  ⚠ HISTORICAL EDITOR BUG ({rel}): emits {seq}",
                  f"    → actually computes {_buggy_meaning(rel, a, b)} — INVERTED"]
    return lines


def _buggy_meaning(rel: str, a: str, b: str) -> str:
    if rel == "<=":   # editor emits [a, b, 0x0A] = a > b
        return f"({a} > {b})"
    return f"({b} > {a})  ≡  ({a} < {b})"  # >= case: [b, a, 0x0A] = b > a


def truth_table() -> list[str]:
    out = ["opcode  name    pushes      integer path / counterpart", "------  ------  ----------  --------------------------"]
    for op in range(0x08, 0x10):
        name, rel = CMP_REL[op]
        out.append(f"0x{op:02X}    {name:<7} a {rel:<3} b     {'uint32' if op in CMP_UNSIGNED else 'int32'} / 0x{CMP_TWIN[op]:02X}")
    out += ["0x06    OPEQ    a == b      —", "0x07    OPNE    a != b      —",
            "",
            "convention: b = pop (TOS, last pushed) · a = pop (base, first pushed).",
            "U integer comparisons use uint32; non-U use int32. Int-vs-float is",
            "chosen at RUNTIME by operand tags (CheckFlagBytePair), not by opcode."]
    return out


# ── byte / insn parsing helpers ──────────────────────────────────────────────

def parse_bytes(text: str) -> bytes:
    toks = re.findall(r"[0-9A-Fa-f]{2}", text.replace(" ", "").replace(",", ""))
    if not toks:
        raise ValueError(f"no hex bytes in '{text}'")
    return bytes(int(t, 16) for t in toks)


def parse_insns(text: str) -> list[Insn]:
    """Parse 'PUSHV 0 ; PUSHII 5 ; 0x0A' / 'PUSHV:0|PUSHII:5|OPGT' forms."""
    out: list[Insn] = []
    off = 0
    for tok in re.split(r"[;|]", text):
        tok = tok.strip()
        if not tok:
            continue
        m = re.match(r"^(0x[0-9A-Fa-f]{1,2}|[A-Za-z?][\w?]*)(?:\s*[: ]\s*(0x[0-9A-Fa-f]+|\d+))?$", tok)
        if not m:
            raise ValueError(f"bad insn token '{tok}' (want NAME[:op] | 0xNN[:op])")
        head, ops = m.group(1), m.group(2)
        if head.lower().startswith("0x"):
            op = int(head, 16) & 0x7F
        else:
            rev = {v: k for k, v in OP_NAMES.items()}
            key = head.upper()
            if key == "LABEL":
                key = "LABEL"
            if key not in rev:
                raise ValueError(f"unknown opcode name '{head}'")
            op = rev[key]
        # operand-bearing ops (bit7-set forms) get has_operand even when the
        # DSL omits the value (defaults to 0).
        OPERAND_OPS = {0x1B, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24,
                       0x27, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x35,
                       0x41, 0x42, 0x43, 0x44, 0x55, 0x56, 0x57, 0x58,
                       0x75, 0x76}
        has = ops is not None or op in OPERAND_OPS
        operand = (int(ops, 0) & 0xFFFF) if ops is not None else (0 if has else None)
        out.append(Insn(off, op | (0x80 if has else 0), op, has, operand))
        off += 3 if has else 1
    return out


# ── selftest ─────────────────────────────────────────────────────────────────

def _cmp_of(insns: list[Insn]) -> tuple[str, str, str]:
    """Run sim, return the single comparison triple (a, rel, b)."""
    lines = simulate(insns, verbose=False)
    triples = []
    for l in lines:
        m = re.search(r"-> push \(a ((?:==|!=|<=|>=|<|>)(?: \(u32 for int tags\))?) b\) = \((.+) ((?:==|!=|<=|>=|<|>)(?: \(u32 for int tags\))?) (.+)\)$", l)
        if m:
            triples.append((m.group(2), m.group(3), m.group(4)))
    if len(triples) != 1:
        raise AssertionError(f"expected exactly 1 comparison, got {triples}")
    return triples[0]


def _b(*hx: int) -> bytes:
    return bytes(hx)


def selftest() -> int:
    checks: list[tuple[str, bool]] = []

    def chk(label: str, cond: bool):
        checks.append((label, cond))

    # 1. truth table sanity
    for op, (name, rel) in CMP_REL.items():
        chk(f"name table 0x{op:02X}={name}", OP_NAMES[op] == name)
    chk("0x0A name is OPGT", OP_NAMES[0x0A] == "OPGT")
    chk("0x0A semantics is >", CMP_REL[0x0A][1] == ">")
    chk("0x0B semantics is <", CMP_REL[0x0B][1] == "<")
    chk("0x0F semantics is <=", CMP_REL[0x0F][1] == "<=")
    chk("0x0E semantics is >=", CMP_REL[0x0E][1] == ">=")
    chk("twin(0x0A)=0x08", CMP_TWIN[0x0A] == 0x08)
    chk("twin(0x0F)=0x0D", CMP_TWIN[0x0F] == 0x0D)

    # 2. decoding: 3-byte vs 1-byte
    ins = decode(_b(0x9F, 0x00, 0x00, 0xAE, 0x05, 0x00, 0x0A))
    chk("decode count=3", len(ins) == 3)
    chk("decode PUSHV op=0x1F oper=0", ins[0].opcode == 0x1F and ins[0].operand == 0)
    chk("decode PUSHII op=0x2E oper=5", ins[1].opcode == 0x2E and ins[1].operand == 5)
    chk("decode 0x0A op", ins[2].opcode == 0x0A and not ins[2].has_operand)

    # 3. THE BUG — editor-emitted bytes decode to the INVERTED operator
    #    editor for `var <= 5` emits [PUSHV var0, PUSHII 5, 0x0A]
    chk("buggy <= emits var>5",
        _cmp_of(ins) == ("var0", ">", "5"))
    #    editor for `var >= 5` emits [PUSHII 5, PUSHV var0, 0x0A]
    chk("buggy >= emits 5>var (var<5)",
        _cmp_of(decode(_b(0xAE, 0x05, 0x00, 0x9F, 0x00, 0x00, 0x0A))) == ("5", ">", "var0"))

    # 4. correct emissions
    chk("x<5 direct", _cmp_of(decode(_b(0x9F, 0x00, 0x00, 0xAE, 0x05, 0x00, 0x0B)))
        == ("var0", "<", "5"))
    chk("x<=5 direct", _cmp_of(decode(_b(0x9F, 0x00, 0x00, 0xAE, 0x05, 0x00, 0x0F)))
        == ("var0", "<=", "5"))
    chk("x>5 direct", _cmp_of(decode(_b(0x9F, 0x00, 0x00, 0xAE, 0x05, 0x00, 0x0A)))
        == ("var0", ">", "5"))
    chk("x>=5 direct", _cmp_of(decode(_b(0x9F, 0x00, 0x00, 0xAE, 0x05, 0x00, 0x0E)))
        == ("var0", ">=", "5"))
    chk("x>5 swap (5<var)", _cmp_of(decode(_b(0xAE, 0x05, 0x00, 0x9F, 0x00, 0x00, 0x0B)))
        == ("5", "<", "var0"))
    chk("x>=5 swap (5<=var)", _cmp_of(decode(_b(0xAE, 0x05, 0x00, 0x9F, 0x00, 0x00, 0x0F)))
        == ("5", "<=", "var0"))
    chk("x==5", _cmp_of(decode(_b(0x9F, 0x00, 0x00, 0xAE, 0x05, 0x00, 0x06)))
        == ("var0", "==", "5"))
    chk("x!=5", _cmp_of(decode(_b(0x9F, 0x00, 0x00, 0xAE, 0x05, 0x00, 0x07)))
        == ("var0", "!=", "5"))
    # U counterparts use the same relation, but preserve unsigned integer semantics
    chk("x>5 via GTU(0x08)", _cmp_of(decode(_b(0x9F, 0, 0, 0xAE, 5, 0, 0x08))) == ("var0", "> (u32 for int tags)", "5"))
    chk("x<5 via LSU(0x09)", _cmp_of(decode(_b(0x9F, 0, 0, 0xAE, 5, 0, 0x09))) == ("var0", "< (u32 for int tags)", "5"))
    chk("x>=5 via GTEU(0x0C)", _cmp_of(decode(_b(0x9F, 0, 0, 0xAE, 5, 0, 0x0C))) == ("var0", ">= (u32 for int tags)", "5"))
    chk("x<=5 via LSEU(0x0D)", _cmp_of(decode(_b(0x9F, 0, 0, 0xAE, 5, 0, 0x0D))) == ("var0", "<= (u32 for int tags)", "5"))

    # 5. imm16 sign extension
    chk("PUSHII 0xFFF3 -> -13",
        _cmp_of(decode(_b(0x9F, 0, 0, 0xAE, 0xF3, 0xFF, 0x0B))) == ("var0", "<", "-13 (0xFFF3)"))

    # 6. insns-DSL parity with raw bytes
    chk("insns DSL == bytes",
        _cmp_of(parse_insns("PUSHV 0 ; PUSHII 5 ; 0x0A")) == ("var0", ">", "5"))
    chk("insns DSL names",
        _cmp_of(parse_insns("PUSHV:0|PUSHII:5|OPLSE")) == ("var0", "<=", "5"))

    # 7. emit idiom sanity
    el = "\n".join(emit_lines("var <= 5"))
    chk("emit <= direct uses 0x0F", "0x0F" in el and "OPLSE" in el)
    chk("emit <= flags editor bug", "0x0A" in el and "INVERTED" in el)
    el2 = "\n".join(emit_lines("var >= 5"))
    chk("emit >= direct uses 0x0E", "0x0E" in el2 and "OPGTE" in el2)

    # Direct machine-code distinction: -1 is UINT_MAX for U, negative for signed.
    for unsigned, signed in ((0x08, 0x0A), (0x09, 0x0B), (0x0C, 0x0E), (0x0D, 0x0F)):
        chk(f"unsigned vs signed 0x{unsigned:02X}/0x{signed:02X}: -1 vs 0",
            compare_int(unsigned, -1, 0) != compare_int(signed, -1, 0))
        chk(f"unsigned vs signed 0x{unsigned:02X}/0x{signed:02X}: 0 vs -1",
            compare_int(unsigned, 0, -1) != compare_int(signed, 0, -1))

    n_ok = sum(1 for _, c in checks if c)
    for label, cond in checks:
        print(f"  [{'PASS' if cond else 'FAIL'}] {label}")
    print(f"\nselftest: {n_ok}/{len(checks)} passed")
    return 0 if n_ok == len(checks) else 1


# ── CLI ──────────────────────────────────────────────────────────────────────

def main(argv: list[str]) -> int:
    p = argparse.ArgumentParser(
        prog="atel_cmp_semantics",
        description="Validate ATEL comparison-opcode semantics (true: 0x0A=a>b, "
                    "0x0B=a<b, 0x0E=a>=b, 0x0F=a<=b; b=TOS popped first).")
    p.add_argument("--bytes", metavar="HEX",
                   help="raw instruction bytes, e.g. \"9F 00 00 AE 05 00 0A\"")
    p.add_argument("--insns", metavar="DSL",
                   help="insn list 'PUSHV 0 ; PUSHII 5 ; 0x0A' "
                        "(NAME[:op] | 0xNN[:op], ; or | separated)")
    p.add_argument("--emit", metavar="EXPR",
                   help="show correct emission idioms for 'a <rel> b'")
    p.add_argument("--call-argc", type=int, default=2,
                   help="args popped per CALL/CALLPOPA in the sim (default 2; "
                        "arity is funcId-dependent in the real VM)")
    p.add_argument("--table", action="store_true", help="print the truth table")
    p.add_argument("--quiet", action="store_true", help="summary only, no per-insn trace")
    p.add_argument("--selftest", action="store_true", help="run the built-in proofs")
    args = p.parse_args(argv)

    if args.selftest:
        return selftest()
    if args.table:
        print("\n".join(truth_table()))
        return 0
    if args.emit:
        print("\n".join(emit_lines(args.emit)))
        return 0
    if args.bytes or args.insns:
        try:
            insns = decode(parse_bytes(args.bytes)) if args.bytes else parse_insns(args.insns)
        except ValueError as e:
            print(f"error: {e}", file=sys.stderr)
            return 2
        print("\n".join(simulate(insns, call_argc=args.call_argc, verbose=not args.quiet)))
        return 0

    p.print_help()
    return 2


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
