#!/usr/bin/env python3
"""ATEL disassembler for raw ATEL blobs (menumain.bin, EV01 chunk0).

Instruction model (from Utilities/fahrenheit/src/core/atel/insn.cs +
research_tools/Atel/fmt_event_audit.py walk):
  - opcode byte <  0x80 : 1-byte instruction, no operand
  - opcode byte >= 0x80 : 3-byte instruction, u16 LE operand

Blob header (AtelScriptParser.cs / audit_atel_blob):
  +0x00 i32 codeLen      +0x08 i32 creatorOffset   +0x0C i32 scriptIdOffset
  +0x10 i32 totalLen     +0x30 i32 scriptCodeOff   +0x34 u16 workerCount
  +0x36 u16 actorCount   +0x38 i32[workerCount] worker offsets
Worker header (0x34): +0x00 u16 eventType, +0x02 u16 varCount,
  +0x04 u16 intConstCount, +0x06 u16 floatConstCount,
  +0x08 u16 funcCount, +0x0A u16 jumpCount, +0x10 i32 privDataLen,
  +0x18 i32 intConstOff, +0x1C i32 floatConstOff, +0x20 i32 funcTableOff,
  +0x24 i32 jumpTableOff, +0x2C i32 privDataOff, +0x30 i32 sharedDataOff.
"""
import struct
import sys
from collections import Counter

OPS = {
    0x00: "NOP", 0x01: "LOR", 0x02: "LAND", 0x03: "OR", 0x04: "EOR",
    0x05: "AND", 0x06: "EQ", 0x07: "NE", 0x08: "GTU", 0x09: "LSU",
    0x0A: "GT", 0x0B: "LS", 0x0C: "GTEU", 0x0D: "LSEU", 0x0E: "GTE",
    0x0F: "LSE", 0x10: "BON", 0x11: "BOFF", 0x12: "SLL", 0x13: "SRL",
    0x14: "ADD", 0x15: "SUB", 0x16: "MUL", 0x17: "DIV", 0x18: "MOD",
    0x19: "NOT", 0x1A: "UMINUS", 0x1B: "FIXADRS", 0x1C: "BNOT",
    0x25: "POPA", 0x26: "PUSHA", 0x28: "PUSHX", 0x29: "PUSHY",
    0x2A: "POPX", 0x2B: "REPUSH", 0x2C: "POPY",
    0x34: "RTS", 0x36: "REQ", 0x37: "REQSW", 0x38: "REQEW",
    0x39: "PREQ", 0x3A: "PREQSW", 0x3B: "PREQEW", 0x3C: "RET",
    0x3D: "RETN", 0x3E: "RETT", 0x3F: "RETTN", 0x40: "HALT",
    0x45: "FREQ", 0x46: "TREQ", 0x47: "BREQ", 0x48: "BFREQ",
    0x49: "BTREQ", 0x4A: "FREQSW", 0x4B: "TREQSW", 0x4C: "BREQSW",
    0x4D: "BFREQSW", 0x4E: "BTREQSW", 0x4F: "FREQEW", 0x50: "TREQEW",
    0x51: "BREQEW", 0x52: "BFREQEW", 0x53: "BTREQEW", 0x54: "DRET",
    0x59: "POPI0", 0x5A: "POPI1", 0x5B: "POPI2", 0x5C: "POPI3",
    0x5D: "POPF0", 0x5E: "POPF1", 0x5F: "POPF2", 0x60: "POPF3",
    0x61: "POPF4", 0x62: "POPF5", 0x63: "POPF6", 0x64: "POPF7",
    0x65: "POPF8", 0x66: "POPF9", 0x67: "PUSHI0", 0x68: "PUSHI1",
    0x69: "PUSHI2", 0x6A: "PUSHI3", 0x6B: "PUSHF0", 0x6C: "PUSHF1",
    0x6D: "PUSHF2", 0x6E: "PUSHF3", 0x6F: "PUSHF4", 0x70: "PUSHF5",
    0x71: "PUSHF6", 0x72: "PUSHF7", 0x73: "PUSHF8", 0x74: "PUSHF9",
    0x77: "REQWAIT", 0x78: "PREQWAIT", 0x79: "REQCHG", 0x7A: "ACTREQ",
    0x9D: "LABEL", 0x9E: "TAG", 0x9F: "PUSHV", 0xA0: "POPV",
    0xA1: "POPVL", 0xA2: "PUSHAR", 0xA3: "POPAR", 0xA4: "POPARL",
    0xA7: "PUSHARP", 0xAD: "PUSHI", 0xAE: "PUSHII", 0xAF: "PUSHF",
    0xB0: "JMP", 0xB1: "CJMP", 0xB2: "NCJMP", 0xB3: "JSR",
    0xB5: "CALL", 0xC1: "PUSHN", 0xC2: "PUSHT", 0xC3: "PUSHVP",
    0xC4: "PUSHFIX", 0xD5: "POPXJMP", 0xD6: "POPXCJMP",
    0xD7: "POPXNCJMP", 0xD8: "CALLPOPA", 0xF5: "PUSHAINTER",
    0xF6: "SYSTEM",
}


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def i32(b, o):
    return struct.unpack_from("<i", b, o)[0]


def f32(b, o):
    return struct.unpack_from("<f", b, o)[0]


def cstr(b, o):
    e = b.find(b"\x00", o)
    if e < 0:
        e = len(b)
    return b[o:e].decode("ascii", "replace")


class AtelBlob:
    def __init__(self, path):
        self.path = path
        self.b = b = open(path, "rb").read()
        self.code_len = i32(b, 0)
        self.creator_off = i32(b, 8)
        self.script_id_off = i32(b, 0x0C)
        self.total_len = i32(b, 0x10)
        self.code_off = i32(b, 0x30)
        self.worker_count = u16(b, 0x34)
        self.actor_count = u16(b, 0x36)
        self.workers = []
        for i in range(self.worker_count):
            wo = i32(b, 0x38 + 4 * i)
            w = {"off": wo,
                 "eventType": u16(b, wo),
                 "varCount": u16(b, wo + 2),
                 "intConstCount": u16(b, wo + 4),
                 "floatConstCount": u16(b, wo + 6),
                 "funcCount": u16(b, wo + 8),
                 "jumpCount": u16(b, wo + 0x0A),
                 "privDataLen": i32(b, wo + 0x10),
                 "intConstOff": i32(b, wo + 0x18),
                 "floatConstOff": i32(b, wo + 0x1C),
                 "funcTableOff": i32(b, wo + 0x20),
                 "jumpTableOff": i32(b, wo + 0x24),
                 "privDataOff": i32(b, wo + 0x2C),
                 "sharedDataOff": i32(b, wo + 0x30)}
            w["funcs"] = [i32(b, w["funcTableOff"] + 4 * j)
                          for j in range(w["funcCount"])
                          if w["funcTableOff"] + 4 * j + 4 <= len(b)]
            w["jumps"] = [i32(b, w["jumpTableOff"] + 4 * j)
                          for j in range(w["jumpCount"])
                          if w["jumpTableOff"] + 4 * j + 4 <= len(b)]
            w["floats"] = [f32(b, w["floatConstOff"] + 4 * j)
                           for j in range(w["floatConstCount"])
                           if w["floatConstOff"] + 4 * j + 4 <= len(b)]
            w["ints"] = [i32(b, w["intConstOff"] + 4 * j)
                         for j in range(w["intConstCount"])
                         if w["intConstOff"] + 4 * j + 4 <= len(b)]
            self.workers.append(w)

    def disasm(self, start=None, end=None):
        """Linear sweep over code region; yields (addr, op, operand)."""
        b = self.b
        s = self.code_off if start is None else start
        e = min(len(b), s + self.code_len) if end is None else end
        out = []
        pos = s
        while pos < e:
            op = b[pos]
            if op & 0x80:
                if pos + 3 > e:
                    out.append((pos, op, None))
                    break
                out.append((pos, op, u16(b, pos + 1)))
                pos += 3
            else:
                out.append((pos, op, None))
                pos += 1
        return out


def fmt_insn(code_base, a):
    """Pretty-print one instruction (addr relative to code base)."""
    addr, op, operand = a
    rel = addr - code_base
    name = OPS.get(op, "op%02X" % op)
    if op & 0x80:
        return "%#06x  %-10s %#06x (%d)" % (rel, name, operand, operand)
    return "%#06x  %s" % (rel, name)


def main(argv):
    path = argv[0]
    blob = AtelBlob(path)
    print("%s: size=%#x codeLen=%#x code=[%#x,%#x) creator=%r scriptId=%r"
          % (path, len(blob.b), blob.code_len, blob.code_off,
             blob.code_off + blob.code_len,
             cstr(blob.b, blob.creator_off), cstr(blob.b, blob.script_id_off)))
    print("workers=%d actors=%d" % (blob.worker_count, blob.actor_count))
    for i, w in enumerate(blob.workers):
        print("  worker%d: eventType=%#x vars=%d iC=%d fC=%d funcs=%s jumps=%s"
              % (i, w["eventType"], w["varCount"], w["intConstCount"],
                 w["floatConstCount"],
                 [hex(x) for x in w["funcs"]], [hex(x) for x in w["jumps"]]))
        print("           floats=%s ints=%s"
              % ([round(f, 6) for f in w["floats"]], w["ints"]))
    ins = blob.disasm()
    print("%d instructions" % len(ins))
    opc = Counter(op for _, op, _ in ins)
    print("opcode census:", {hex(k): v for k, v in opc.most_common()})
    if "-v" in argv:
        for a in ins:
            print(fmt_insn(blob.code_off, a))


if __name__ == "__main__":
    main(sys.argv[1:])
