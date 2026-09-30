#!/usr/bin/env python3
# ── G2G3 slot READER map — who READS a SaveData slot and what runs next? ──
#
# Lane: FFX-STRUCTURES / G2G3-WRITERS · 2026-09-15 · Python stdlib only.
# Research tool, read-only. Complement of store_value_miner.py (which maps
# WRITERS): this one finds every PUSHV (0x9F) into the given ATEL SaveData
# slots across the .ebp corpus and dumps the opcodes that follow, so the
# CONSUMER pattern is visible (e.g. "PUSHV C54; PUSHV C58; CALL Common:0AB"
# -> the scene-jump-back op).
#
# Proven 2026-09-15 on slots 0x0A68/0x0A6C/0x0A74/0x0A98 (Fh 0xC54/0xC58/
# 0xC60/0xC84): all 13 reads of 0xC54 and all 8 of 0xC58 are consumed by
# Common:0AB = FFX_FieldVM_Op_SceneJumpExB@0x858220 (bltz* variants) or by a
# 0x2C switch (hiku* airship scripts); all 15 reads of 0xC84 are
# "PUSHI 1; EQ(0x06); D7 <label>" boolean tests in djyt* (Djose) scripts.
#
# ATEL opcode notes (matching interpreter 0x864180 + sibling miner):
#   op >= 0x80 -> 3-byte op with u16 LE operand; op < 0x80 -> 1-byte op.
#   0xAE=PUSHI s16  0x9F=PUSHV  0xA0/A1=POPV(L)  0xA3/A4=POPAR(L)
#   0xAD=PUSHPOOL   0xD8=CALL   0xB5=CALLW      0xB0=label mark   0x2C=switch
# Var table entry = 8B (lo,hi); SaveData slot = lo & 0xFFFFFF when
# (lo>>25)&7 == 0; Fahrenheit offset = slot + 0x1EC.
#
# Usage: python3 ev01_slot_readers.py [slot_hex ...]   (default: the G2G3 four)

import os, sys, glob

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
SAVEDATA_BASE = 0x1EC

NS = {0x0: 'Common', 0x1: 'Movie', 0x2: 'Mount', 0x3: 'Battle',
      0x4: 'SgEvent', 0x5: 'ChEvent', 0x6: 'Camera', 0x7: 'Map'}


def u32(b, o): return b[o] | (b[o+1] << 8) | (b[o+2] << 16) | (b[o+3] << 24)


def parse_ebp_chunk0(data):
    offs, i = [], 4
    while i + 4 <= len(data):
        v = u32(data, i)
        if v == 0xFFFFFFFF:
            break
        offs.append(v); i += 4
    present = [o for o in offs[:-1] if o]
    return 0x40, (present[1] if len(present) > 1 else offs[-1])


def parse_atel_blob(blob):
    code_len = u32(blob, 0x00)
    script_start = u32(blob, 0x30)
    w0 = u32(blob, 0x38)
    vars_off = u32(blob, w0 + 0x14)
    int_off = u32(blob, w0 + 0x18)
    var_count = (int_off - vars_off) // 8 if vars_off and int_off > vars_off else 0
    return code_len, script_start, [u32(blob, vars_off + 8*k) for k in range(var_count)]


def decode_ops(blob, ss, code_len):
    end, i, out = ss + code_len, ss, []
    while i < end:
        op = blob[i]; pc = i - ss
        if op < 0x80:
            out.append((pc, op, None)); i += 1; continue
        if i + 3 > end:
            break
        out.append((pc, op, blob[i+1] | blob[i+2] << 8)); i += 3
    return out


def slot_of(vars_lo, vi):
    if vi < len(vars_lo) and ((vars_lo[vi] >> 25) & 7) == 0:
        return vars_lo[vi] & 0xFFFFFF
    return None


def opstr(op, o):
    if op == 0xAE:
        return f"PUSHI {o if o < 0x8000 else o - 0x10000}"
    if op == 0x9F:
        return f"PUSHV vi={o}"
    if op in (0xA0, 0xA1, 0xA3, 0xA4):
        return f"POPV vi={o}"
    if op == 0xAD:
        return f"PUSHPOOL {o}"
    if op in (0xD8, 0xB5):
        return f"{'CALL' if op == 0xD8 else 'CALLW'} {NS.get((o >> 12) & 0xF, hex((o >> 12) & 0xF))}:{o & 0xFFF:03X}"
    if op == 0xB0:
        return f"B0 0x{o:x}"
    return f"{op:02X}" + (f" {o:#x}" if o is not None else "")


def main(slots):
    targets = set(slots)
    files = sorted(glob.glob(ROOT + '/**/event/obj/**/*.ebp', recursive=True))
    readers = {s: [] for s in targets}
    for p in files:
        try:
            d = open(p, 'rb').read()
            c0, _ = parse_ebp_chunk0(d)
            blob = d[c0:]
            code_len, ss, vars_lo = parse_atel_blob(blob)
        except Exception:
            continue
        ops = decode_ops(blob, ss, code_len)
        name = os.path.basename(p)
        for k, (pc, op, operand) in enumerate(ops):
            if op == 0x9F:
                s = slot_of(vars_lo, operand)
                if s in targets:
                    nxt = [opstr(o2, o3) for _, o2, o3 in ops[k+1:k+4]]
                    readers[s].append((name, pc, nxt))
    for s in sorted(targets):
        print(f"== slot {s:#06x} (Fh {s + SAVEDATA_BASE:#06x}) readers: {len(readers[s])}")
        for n, pc, nx in readers[s]:
            print(f"   {n:28s} @{pc:06x}  next: {' | '.join(nx)}")


if __name__ == '__main__':
    slots = [int(a, 0) for a in sys.argv[1:]] or [0x0A68, 0x0A6C, 0x0A74, 0x0A98]
    main(slots)
