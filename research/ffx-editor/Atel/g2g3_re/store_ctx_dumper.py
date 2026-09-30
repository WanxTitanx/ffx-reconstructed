#!/usr/bin/env python3
# ── Focused context dumper: which natives feed the target slots? ──
# For every POPV/POPVL store into target slots, print the preceding ops with
# the fahrenheit namespace decode of D8 <id> calls (0x00xx Common, 0x10xx Math,
# 0x20xx SgEvent, 0x30xx ChEvent, 0x60xx Camera, 0x70xx Battle, 0x80xx Map,
# 0x90xx Mount, 0xA0xx Movie, 0xB0xx Debug, 0xC0xx AbiMap).
import json, os, sys
from collections import Counter, defaultdict

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
SAVEDATA_BASE = 0x1EC
NS = {0x00: 'Common', 0x10: 'Math', 0x20: 'SgEvent', 0x30: 'ChEvent',
      0x60: 'Camera', 0x70: 'Battle', 0x80: 'Map', 0x90: 'Mount',
      0xA0: 'Movie', 0xB0: 'Debug', 0xC0: 'AbiMap'}
TARGET_SLOTS = {0xC54-0x1EC: '0xC54', 0xC58-0x1EC: '0xC58',
                0xC60-0x1EC: '0xC60', 0xC84-0x1EC: '0xC84'}

def u16(b, o): return b[o] | (b[o+1] << 8)
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
    if op in (0xB6,):  # no-wait native?
        ns = (operand >> 8) & 0xFF
        return f"CALLNW {NS.get(ns & 0xF0, hex(ns))}:{operand:04X}"
    if op == 0xAE:
        v = operand if operand < 0x8000 else operand - 0x10000
        return f"PUSHI {v}"
    if op == 0x9F: return f"PUSHV vi={operand}"
    if op in (0xA0, 0xA1): return f"{'POPV' if op == 0xA0 else 'POPVL'} vi={operand}"
    if op == 0xAD: return f"PUSHPOOL {operand}"
    if op == 0xAF: return f"PUSHF pool={operand}"
    return f"{op:02X} {operand:04X}" if operand is not None else f"{op:02X}"

native_before = defaultdict(Counter)   # slot -> Counter of native ids seen in window
samples = defaultdict(list)

for dirpath, _dn, fns in os.walk(ROOT):
    for fn in fns:
        if not fn.lower().endswith('.ebp'): continue
        path = os.path.join(dirpath, fn); name = fn
        try:
            data = open(path, 'rb').read()
            s, e = parse_ebp_chunk0(data)
            blob = data[s:e]
            code_len, script_start, vars = parse_atel_blob(blob)
        except Exception:
            continue
        end = script_start + code_len
        i = script_start
        window = []
        while i < end:
            op = blob[i]
            if not (op & 0x80):
                window.append((i - script_start, op, None))
                if len(window) > 10: window.pop(0)
                i += 1; continue
            if i + 3 > end: break
            operand = blob[i+1] | (blob[i+2] << 8)
            pc = i - script_start
            window.append((pc, op, operand))
            if len(window) > 10: window.pop(0)
            if op in (0xA0, 0xA1) and operand < len(vars):
                lo, hi = vars[operand]
                if ((lo >> 25) & 7) == 0 and (lo & 0xFFFFFF) in TARGET_SLOTS:
                    tgt = TARGET_SLOTS[lo & 0xFFFFFF]
                    # record natives in window
                    for wpc, wop, wopr in window[:-1]:
                        if wop in (0xD8,) and wopr is not None:
                            native_before[tgt][wopr] += 1
                    if len(samples[tgt]) < 14:
                        samples[tgt].append(
                            name + ' @' + hex(pc) + ' | ' +
                            ' '.join(decode(wop2, wopr2, vars) for _p, wop2, wopr2 in window))
            i += 3

for tgt in sorted(samples):
    print(f"\n===== stores to Fh {tgt} — natives seen in preceding window =====")
    for nid, n in native_before[tgt].most_common(15):
        ns = (nid >> 8) & 0xFF
        print(f"  {NS.get(ns & 0xF0, '?'):>8}:{nid:04X}  x{n}")
    print("  samples:")
    for smp in samples[tgt][:12]:
        print('   ', smp)
