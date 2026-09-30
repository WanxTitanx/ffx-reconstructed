#!/usr/bin/env python3
# ── G2G3 BONUS: ordered store-sequence dump per writer script ──
#
# Lane: FFX-STRUCTURES / G2G3-BONUS · 2026-09-15 · Python stdlib only.
# For each .ebp writer of slots 0x119-0x130 / 0x261-0x265 (Fh 0x305-0x31C,
# 0x44D,0x450,0x451), dump every POPV into those slots IN ORDER with the
# folded abstract-stack value + a small opcode window, so the write pattern
# (init block vs scattered; const vs computed) is directly visible.
#
# Same walk as work/_g2g3_re/store_value_miner.py (credit: G2G3 lane).

import os, sys, glob

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
SAVEDATA_BASE = 0x1EC

SLOT_MIN, SLOT_MAX = 0x119, 0x130
SLOTS_2 = {0x261, 0x262, 0x263, 0x264, 0x265}

BINOPS = {0x97: '+', 0x98: '-', 0x99: '*', 0x9A: '/',
          0x92: '<<', 0x93: '>>', 0x85: '&', 0x83: '|', 0x84: '^'}
BINFN = {'+': lambda a,b:a+b, '-': lambda a,b:a-b, '*': lambda a,b:a*b,
         '/': lambda a,b:(a//b if b else None), '<<': lambda a,b:a<<b,
         '>>': lambda a,b:a>>b, '&': lambda a,b:a&b, '|': lambda a,b:a|b,
         '^': lambda a,b:a^b}

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
    vars_lo = [u32(blob, vars_off + 8*k) for k in range(var_count)]
    return code_len, script_start, vars_lo

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
    if op == 0xAD: return f"PUSHPOOL {o}"
    if op in (0xD8,0xB5): return f"{'CALL' if op==0xD8 else 'CALLW'} {NS.get((o>>12)&0xF, hex((o>>12)&0xF))}:{o&0xFFF:03X}"
    if op == 0xB0: return f"B0 0x{o:x}"
    return f"{op:02X}" + (f" {o:#x}" if o is not None else "")

def dump_file(path, targets):
    d = open(path, 'rb').read()
    c0, _ = parse_ebp_chunk0(d)
    blob = d[c0:]
    code_len, ss, vars_lo = parse_atel_blob(blob)
    ops = decode_ops(blob, ss, code_len)
    name = os.path.basename(path)
    stack = []
    out = []
    for k, (pc, op, operand) in enumerate(ops):
        if op is None: continue
        if op < 0x80:
            if op != 0x00: stack = []
            continue
        if op == 0xAE:
            v = operand if operand < 0x8000 else operand - 0x10000
            stack.append(v)
        elif op in (0xAD, 0x9F, 0xA2, 0xA7):
            stack.append(None)
        elif op in (0xA0,0xA1,0xA3,0xA4):
            s = slot_of(vars_lo, operand)
            val = stack.pop() if stack else 'EMPTY'
            if op in (0xA3,0xA4):
                idx = stack.pop() if stack else 'EMPTY'
                val = ('IDX', idx, val)
            if s in targets:
                ctx = ' '.join(opstr(o2,o3) for _,o2,o3 in ops[max(0,k-6):k])
                out.append((pc, s, op, val, ctx))
            stack = []
        elif op in BINOPS:
            b = stack.pop() if stack else None
            a = stack.pop() if stack else None
            stack.append(BINFN[BINOPS[op]](a,b) if (a is not None and b is not None) else None)
        elif op in range(0x81,0x90) or op in (0x9C,0x9D,0x9E):
            if stack: stack.pop()
            if stack: stack.pop()
            stack.append(None)
        else:
            stack = []
    return name, out

def main():
    which = sys.argv[1] if len(sys.argv) > 1 else 'cluster'
    if which == 'cluster':
        targets = set(range(SLOT_MIN, SLOT_MAX+1))
        pats = ['bsvr', 'bsyt', 'test2', 'test3']
    else:
        targets = SLOTS_2
        pats = ['hiku', 'bltz', 'test21']
    files = sorted(glob.glob(ROOT + '/**/event/obj/**/*.ebp', recursive=True))
    for p in files:
        n = os.path.basename(p)
        if not any(n.startswith(x) for x in pats):
            continue
        name, out = dump_file(p, targets)
        if not out:
            continue
        print(f"\n#### {name} — {len(out)} stores into targets")
        for pc, s, op, val, ctx in out:
            tag = f"{pc:06x} slot0x{s:03x} (Fh 0x{s+SAVEDATA_BASE:03x}) {'idx' if op in (0xA3,0xA4) else '  '} val={val}"
            print(f"  {tag}   | prev: {ctx}")

if __name__ == '__main__':
    main()
