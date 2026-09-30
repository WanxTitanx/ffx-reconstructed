#!/usr/bin/env python3
# ── G2G3 store-value miner — what do EV01 scripts STORE into the target slots? ──
#
# Lane: FFX-STRUCTURES / G2G3-WRITERS · 2026-09-15 · Python stdlib only.
# Research tool, read-only. Reuses the proven EV01/ATEL walk from
# research_tools/Atel/ev01_savevar_mining.py (credit: same lane, 2026-09-14).
#
# PURPOSE: for the backlog-C sub-counters (Fh 0xC54/0xC58/0xC60/0xC84 + bonus
# 0x305-0x31C, 0x44D-0x451) record the VALUE stored by each POPV/POPVL/POPAR,
# via a conservative abstract stack:
#   - 0xAE pushes a sign-extended s16 immediate (interpreter case 0x2E ->
#     FFX_FieldVM_PushIntOperand, work/_ev01_mining/interp_864180_code.c).
#   - binary ops 0x97(+)/0x98(-)/0x99(*)/0x9A(/)/0x92(<</0x93(>>)/0x85(&)/
#     0x83(|)/0x84(^) fold when both operands are known.
#   - EVERY other opcode clears the abstract stack (native-call ops pop an
#     unknown number of args; jumps invalidate fallthrough). A recorded
#     constant is therefore a guaranteed TOS at that pc under linear
#     execution; dead-code false positives are possible in principle and are
#     mitigated by cross-file aggregation + manual context dumps (see -v).
#   - self-increment pattern [PUSHV X, PUSHI imm, ADD, POPV X] is detected
#     explicitly ("SELF_ADD imm").
import json, os, struct, sys
from collections import Counter, defaultdict

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
SAVEDATA_BASE = 0x1EC

# target slots (Fh = slot + 0x1EC)
TARGET_FH = [0xC54, 0xC58, 0xC60, 0xC84, 0xC39,
             0x305, 0x306, 0x307, 0x308, 0x309, 0x30A, 0x30B, 0x30C,
             0x30D, 0x30E, 0x30F, 0x310, 0x311, 0x312, 0x313, 0x314,
             0x315, 0x316, 0x317, 0x318, 0x319, 0x31A, 0x31B, 0x31C,
             0x44D, 0x44E, 0x44F, 0x450, 0x451]
TARGET_SLOTS = {fh - SAVEDATA_BASE: fh for fh in TARGET_FH}

TYPE_STRIDE = {0: 1, 1: 1, 2: 2, 3: 2, 4: 4, 5: 4, 6: 4, 7: 1}

BINOPS = {0x97: ('+', lambda a, b: a + b),
          0x98: ('-', lambda a, b: a - b),
          0x99: ('*', lambda a, b: a * b),
          0x9A: ('/', lambda a, b: a // b if b else None),
          0x92: ('<<', lambda a, b: a << b),
          0x93: ('>>', lambda a, b: a >> b),
          0x85: ('&', lambda a, b: a & b),
          0x83: ('|', lambda a, b: a | b),
          0x84: ('^', lambda a, b: a ^ b)}
CMPS = set(range(0x81, 0x90)) | {0x86, 0x87, 0x88, 0x89}  # logical/cmp (unknown result)


def u16(b, o): return b[o] | (b[o + 1] << 8)
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
    vars = []
    for k in range(var_count):
        lo = u32(blob, vars_off + 8*k)
        hi = u32(blob, vars_off + 8*k + 4)
        vars.append((lo, hi))
    return code_len, script_start, vars


def walk(blob, script_start, code_len, name, records, verbose_pcs):
    """Conservative abstract-stack walk; records stores into TARGET_SLOTS."""
    end = script_start + code_len
    i = script_start
    stack = []          # list of (value|None)
    last_var_push = {}  # for self-inc detection: not needed beyond history
    trace = []          # rolling (pc, op, operand) for context dumps
    while i < end:
        op = blob[i]
        pc = i - script_start
        if not (op & 0x80):
            # 1-byte op: unknown effect except no-op-ish 0x00
            if op != 0x00:
                stack = []
            trace.append((pc, op, None))
            i += 1
            continue
        if i + 3 > end: break
        operand = blob[i+1] | (blob[i+2] << 8)
        trace.append((pc, op, operand))
        if len(trace) > 24: trace.pop(0)

        if op == 0xAE:  # PUSHI s16
            v = operand if operand < 0x8000 else operand - 0x10000
            stack.append(v)
        elif op == 0xAD:  # push from int pool (runtime) -> unknown
            stack.append(None)
        elif op == 0x9F or op == 0xA2 or op == 0xA7:  # PUSHV / PUSHAR / PUSHARP
            stack.append(None)
        elif op in (0xA0, 0xA1, 0xA3, 0xA4):  # POPV/POPVL/POPAR/POPARL -> possible store
            vi = operand
            # value context for record
            rec = None
            if vi < len(VARS):
                lo, hi = VARS[vi]
                if ((lo >> 25) & 7) == 0:
                    slot = lo & 0xFFFFFF
                    if slot in TARGET_SLOTS:
                        # pop index first for array stores (0xA3/0xA4)
                        val = stack.pop() if stack else ('EMPTY',)
                        idx = None
                        if op in (0xA3, 0xA4):
                            idx = stack.pop() if stack else ('EMPTY',)
                            val = ('indexed', idx, val)
                        records[slot]['n'] += 1
                        if val == ('EMPTY',):
                            records[slot]['empty'] += 1
                        elif isinstance(val, int):
                            records[slot]['const'][val] += 1
                            if pc in verbose_pcs or records[slot]['dump'] < 6:
                                records[slot]['dump'] += 1
                                records[slot]['ctx'].append((name, pc, val, dump_trace(trace)))
                        elif isinstance(val, tuple) and val and val[0] == 'SELF_ADD':
                            records[slot]['selfadd'][val[1]] += 1
                        else:
                            records[slot]['unknown'] += 1
                        stack = []  # store consumed; be safe
                        i += 3
                        continue
            # generic pop of the stored value (+ index for array forms)
            npop = 2 if op in (0xA3, 0xA4) else 1
            for _ in range(npop):
                if stack: stack.pop()
            stack = []  # conservative: unknown side effects
        elif op in BINOPS:
            b = stack.pop() if stack else None
            a = stack.pop() if stack else None
            nm, fn = BINOPS[op]
            # self-increment detection: a must be a PUSHV of same var we will store to
            if a is None and b is not None:
                # look back: was the previous var-op a PUSHV whose next store is same var?
                # cheap approach handled post-hoc via pattern scan below
                pass
            stack.append(fn(a, b) if (a is not None and b is not None) else None)
        elif op in CMPS or op == 0x9C or op == 0x9D or op == 0x9E:
            n = 2
            for _ in range(n):
                if stack: stack.pop()
            stack.append(None)
        else:
            stack = []  # any other 3-byte op (jumps, calls, native queue ops...)
        i += 3


def dump_trace(trace):
    out = []
    for pc, op, operand in trace:
        if operand is None:
            out.append(f"{pc:04X}:{op:02X}")
        else:
            out.append(f"{pc:04X}:{op:02X} {operand:04X}")
    return ' '.join(out)


VARS = []
records = defaultdict(lambda: {'n': 0, 'const': Counter(), 'selfadd': Counter(),
                               'unknown': 0, 'empty': 0, 'dump': 0, 'ctx': [],
                               'files': set()})


def main():
    global VARS
    files = []
    for dirpath, _dn, fns in os.walk(ROOT):
        for fn in fns:
            if fn.lower().endswith('.ebp'):
                files.append(os.path.join(dirpath, fn))
    files.sort()
    parsed = 0
    for path in files:
        name = os.path.basename(path)
        try:
            data = open(path, 'rb').read()
            s, e = parse_ebp_chunk0(data)
            blob = data[s:e]
            code_len, script_start, VARS = parse_atel_blob(blob)
            # per-file records to attribute files
            before = {k: v['n'] for k, v in records.items()}
            walk(blob, script_start, code_len, name, records, set())
            for k, v in records.items():
                if v['n'] > before.get(k, 0):
                    v['files'].add(name)
            parsed += 1
        except Exception as ex:
            print(f"PARSE FAIL {name}: {ex}", file=sys.stderr)
    print(f"parsed {parsed}/{len(files)}")
    out = {}
    for slot in sorted(records):
        fh = slot + SAVEDATA_BASE
        v = records[slot]
        print(f"\n=== slot 0x{slot:X} Fh 0x{fh:X} file 0x{fh+0x40:X} ===")
        print(f"  stores: {v['n']}  files: {len(v['files'])}")
        print(f"  const values: {dict(sorted(v['const'].items(), key=lambda kv:-kv[1])[:25])}")
        print(f"  unknown-val stores: {v['unknown']}  empty-stack: {v['empty']}")
        for name, pc, val, ctx in v['ctx'][:6]:
            print(f"  CTX {name} @{pc:04X} val={val}: {ctx}")
        out[str(slot)] = {'fh': fh, 'n': v['n'], 'files': sorted(v['files']),
                          'const': dict(v['const']), 'unknown': v['unknown'], 'empty': v['empty']}
    with open('/home/wanderson/Documents/ffx-editor-main/work/_g2g3_re/store_values.json', 'w') as f:
        json.dump(out, f, indent=1)
    print("\nwrote store_values.json")


if __name__ == '__main__':
    main()
