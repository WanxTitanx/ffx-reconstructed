#!/usr/bin/env python3
# ── G2G3 BONUS: PUSHAR (0xA2) reader map — array-indexed reads of target slots ──
#
# Lane: FFX-STRUCTURES / G2G3-BONUS · 2026-09-15 · Python stdlib only.
# ev01_slot_readers.py only scans 0x9F PUSHV. The hiku* writers access
# slots 0x261/0x265 via the ARRAY form (PUSHI idx; 2B dup; A2 arr; mask; 03 OR;
# POPAR) — reads of the same arrays will likewise come through 0xA2.
# This tool finds every 0xA2 (and 0xA7 PUSHARP) whose var-index resolves to a
# target slot and dumps the following ops (mask tests etc.).

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
        if v == 0xFFFFFFFF: break
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
        if i + 3 > end: break
        out.append((pc, op, blob[i+1] | blob[i+2] << 8)); i += 3
    return out

def slot_of(vars_lo, vi):
    if vi < len(vars_lo) and ((vars_lo[vi] >> 25) & 7) == 0:
        return vars_lo[vi] & 0xFFFFFF
    return None

def opstr(op, o):
    if op == 0xAE: return f"PUSHI {o if o < 0x8000 else o-0x10000}"
    if op == 0x9F: return f"PUSHV vi={o}"
    if op in (0xA0,0xA1,0xA3,0xA4): return f"POPV vi={o}"
    if op in (0xA2,0xA7): return f"PUSHAR vi={o}"
    if op == 0xAD: return f"PUSHPOOL {o}"
    if op in (0xD8,0xB5): return f"{'CALL' if op==0xD8 else 'CALLW'} {NS.get((o>>12)&0xF, hex((o>>12)&0xF))}:{o&0xFFF:03X}"
    if op == 0xB0: return f"B0 0x{o:x}"
    return f"{op:02X}" + (f" {o:#x}" if o is not None else "")

def main(slots):
    targets = set(slots)
    files = sorted(glob.glob(ROOT + '/**/event/obj/**/*.ebp', recursive=True))
    hits = {s: [] for s in targets}
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
            if op in (0xA2, 0xA7):
                s = slot_of(vars_lo, operand)
                if s in targets:
                    nxt = [opstr(o2, o3) for _, o2, o3 in ops[k+1:k+6]]
                    prev = [opstr(o2, o3) for _, o2, o3 in ops[max(0,k-3):k]]
                    hits[s].append((name, pc, ' | '.join(prev), ' | '.join(nxt)))
    for s in sorted(targets):
        print(f"== PUSHAR-reads slot {s:#06x} (Fh {s + SAVEDATA_BASE:#06x}): {len(hits[s])}")
        for n, pc, pv, nx in hits[s]:
            print(f"   {n:26s} @{pc:06x}  prev: {pv}   next: {nx}")

if __name__ == '__main__':
    slots = [int(a, 0) for a in sys.argv[1:]] or [0x261, 0x265, 0x119, 0x130]
    main(slots)
