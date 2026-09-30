#!/usr/bin/env python3
import os, struct, sys
from collections import Counter, defaultdict
ROOT = "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/event/obj"

def parse_ebp(path):
    b = open(path, "rb").read()
    if b[:4] != b"EV01": return None
    offs = []; p = 4
    while p + 4 <= len(b):
        v = struct.unpack_from("<I", b, p)[0]
        if v == 0xFFFFFFFF: break
        offs.append(v); p += 4
    if not offs: return None
    c0 = offs[0]
    code_len = struct.unpack_from("<I", b, c0)[0]
    off_code = struct.unpack_from("<I", b, c0 + 0x30)[0]
    if not off_code or c0 + off_code + code_len > len(b) or code_len > len(b): return None
    return b[c0 + off_code : c0 + off_code + code_len]

files = []
for dp,_,fns in os.walk(ROOT):
    for fn in fns:
        if fn.endswith(".ebp"): files.append(os.path.join(dp,fn))
files.sort()

# per-opcode: histogram of operand>>12 (funcId-shaped high nibble)
op_ns = defaultdict(Counter)
call_fids = Counter()
unk_ns = {2,3,0xA,0xE,0xF}
unk_hits = []
for path in files:
    code = parse_ebp(path)
    if code is None: continue
    rel = os.path.relpath(path, ROOT)
    i, n = 0, len(code)
    while i < n:
        op = code[i]
        if op & 0x80:
            if i+3 > n: break
            operand = struct.unpack_from("<H", code, i+1)[0]
            op_ns[op][operand >> 12] += 1
            if op in (0xB5, 0xD8):
                call_fids[operand] += 1
                if (operand>>12) in unk_ns:
                    unk_hits.append((rel, i, op, operand))
            i += 3
        else:
            i += 1

print("opcode -> namespace-of-operand histogram (ns: count):")
for op in sorted(op_ns):
    ns = op_ns[op]
    unk = sum(ns[k] for k in unk_ns)
    mark = f"  <== {unk} unk-ns operands!" if unk else ""
    top = ", ".join(f"{k:#x}:{v}" for k,v in sorted(ns.items()))
    print(f"  op {op:#04x}: total={sum(ns.values()):>8}  {{{top}}}{mark}")
print()
print("unk-ns CALL/CALLPOPA hits:", len(unk_hits), unk_hits[:10])
# check funcId ranges used per ns
per_ns = defaultdict(list)
for fid,c in call_fids.items(): per_ns[fid>>12].append(fid&0xFFF)
print("\nfuncId index ranges actually used per ns:")
for ns in sorted(per_ns):
    idx = sorted(per_ns[ns])
    print(f"  ns {ns:#x}: n={len(idx)} min={idx[0]:#x} max={idx[-1]:#x}")
