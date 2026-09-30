#!/usr/bin/env python3
# G2G3-COUNTERS: decode EV01/ATEL bytecode windows in djyt*.ebp around given PCs.
# Reuses proven walk from research_tools/Atel/ev01_savevar_mining.py (same lane).
import os, sys, glob

NS = {0x00: 'Common', 0x10: 'Math', 0x20: 'SgEvent', 0x30: 'ChEvent',
      0x60: 'Camera', 0x70: 'Battle', 0x80: 'Map', 0x90: 'Mount',
      0xA0: 'Movie', 0xB0: 'Debug', 0xC0: 'AbiMap'}

def u16(b, o): return b[o] | (b[o+1] << 8)
def u32(b, o): return b[o] | (b[o+1] << 8) | (b[o+2] << 16) | (b[o+3] << 24)

def parse_ebp_chunk0(data):
    offs, i = [], 4
    while i + 4 <= len(data):
        v = u32(data, i)
        if v == 0xFFFFFFFF: break
        offs.append(v); i += 4
    present = [o for o in offs[:-1] if o]
    return 0x40, (present[1] if len(present) > 1 else offs[-1]), present

def parse_atel_blob(blob):
    code_len = u32(blob, 0x00); script_start = u32(blob, 0x30)
    w0 = u32(blob, 0x38)
    vars_off = u32(blob, w0 + 0x14); int_off = u32(blob, w0 + 0x18)
    var_count = (int_off - vars_off) // 8 if vars_off and int_off > vars_off else 0
    vars = [(u32(blob, vars_off+8*k), u32(blob, vars_off+8*k+4)) for k in range(var_count)]
    return code_len, script_start, vars

def decode(op, operand, vars):
    if op == 0xD8:
        ns = (operand >> 8) & 0xFF
        return f"CALL {NS.get(ns & 0xF0, hex(ns))}:{operand:04X}"
    if op == 0xB5:
        ns = (operand >> 8) & 0xFF
        return f"CALLW {NS.get(ns & 0xF0, hex(ns))}:{operand:04X}"
    if op == 0xB6:
        ns = (operand >> 8) & 0xFF
        return f"CALLNW {NS.get(ns & 0xF0, hex(ns))}:{operand:04X}"
    if op == 0xAE:
        v = operand if operand < 0x8000 else operand - 0x10000
        return f"PUSHI {v}"
    if op == 0x9F:
        if operand < len(vars):
            lo, hi = vars[operand]
            return f"PUSHV vi={operand} [{lo & 0xFFFFFF:#x} t{(lo>>25)&7}]"
        return f"PUSHV vi={operand}"
    if op in (0xA0, 0xA1):
        if operand < len(vars):
            lo, hi = vars[operand]
            return f"{'POPV' if op == 0xA0 else 'POPVL'} vi={operand} [{lo & 0xFFFFFF:#x} t{(lo>>25)&7}]"
        return f"{'POPV' if op == 0xA0 else 'POPVL'} vi={operand}"
    if op == 0xAD: return f"PUSHPOOL {operand}"
    if op == 0xAF: return f"PUSHF pool={operand}"
    if op == 0x29: return "DUP?"       # hypothesis: stack dup
    if op == 0x06: return "06"         # unknown
    if op == 0xD6: return "D6"         # unknown (often after 29 06)
    if op == 0x0E: return f"JIF? ->{operand:#x}" if operand is not None else "0E"
    if op == 0xD7: return f"D7 {operand:#x}" if operand is not None else "D7"
    if op == 0x2C: return "2C"
    if op == 0x3C: return "POP?"
    if op == 0x25: return "25"
    if op == 0x36: return "36"
    if op == 0x77: return "77"
    if op == 0xB0: return f"B0 {operand:#x}"
    if op == 0x38: return "38"
    return f"{op:02X} {operand:04X}" if operand is not None else f"{op:02X}"

def dump(path, centers, before=70, after=18):
    data = open(path, 'rb').read()
    s, e, _ = parse_ebp_chunk0(data)
    blob = data[s:e]
    code_len, script_start, vars = parse_atel_blob(blob)
    end = script_start + code_len
    # linear decode into list
    ops = []
    i = script_start
    while i < end:
        op = blob[i]
        if not (op & 0x80):
            ops.append((i - script_start, op, None)); i += 1; continue
        if i + 3 > end: break
        ops.append((i - script_start, op, blob[i+1] | (blob[i+2] << 8)))
        i += 3
    for c in centers:
        print(f"\n######## {os.path.basename(path)} around pc {c:#x} ########")
        idx = next((k for k, (pc, _, _) in enumerate(ops) if pc >= c), None)
        if idx is None: continue
        for pc, op, operand in ops[max(0, idx-before):idx+after]:
            mark = '>>>' if pc == c else '   '
            print(f"{mark} @{pc:05x}: {decode(op, operand, vars)}")

if __name__ == '__main__':
    base = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/event/obj"
    jobs = {
        'dj/djyt0900/djyt0900.ebp': [0x1867],
        'dj/djyt0100/djyt0100.ebp': [0x7053, 0xbdd2, 0xbeea, 0xc0f4],
        'dj/djyt0200/djyt0200.ebp': [0x1691, 0x16ed],
        'dj/djyt0300/djyt0300.ebp': [0x6300, 0x6eca, 0x8da4, 0x8dde],
    }
    for rel, centers in jobs.items():
        p = os.path.join(base, rel)
        if os.path.exists(p):
            dump(p, centers)
        else:
            print("MISSING", p)
