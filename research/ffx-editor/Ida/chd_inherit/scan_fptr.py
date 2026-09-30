#!/usr/bin/env python3
"""scan_fptr.py — find runs of >=3 consecutive aligned dwords that are all
valid .text function starts, inside .data/.rodata/_RDATA (0xC0A000+).
Excludes addrs already covered by known vtables (vtables2.json)."""
import json, struct, pickle, sys

W = '/home/wanderson/Documents/ffx-editor-main/work/_chd_inherit/'
VR = '/home/wanderson/Documents/ffx-editor-main/work/_vtable_recon/'
BASE, END = 0xC0A000, 0x25D9000
TEXT_LO, TEXT_HI = 0x401000, 0xB0C000

buf = open(W + 'data_seg.bin', 'rb').read()
funcs = pickle.load(open(VR + 'all_funcs.pkl', 'rb'))
func_starts = set(int(f['addr'], 16) for f in funcs)
func_names = {int(f['addr'], 16): f['name'] for f in funcs}

# known vtable ranges to exclude
vt = json.load(open(VR + 'vtables2.json'))
vt_ranges = []
for e in vt:
    s = int(e['vtable'], 16)
    vt_ranges.append((s - 4, s + 4 * e['slots']))  # incl. the COL-ptr dword


def in_vt(a):
    for lo, hi in vt_ranges:
        if lo <= a < hi:
            return True
    return False


runs = []
i = 0
n = len(buf)
while i + 4 <= n:
    v = struct.unpack_from('<I', buf, i)[0]
    if v in func_starts:
        start = i
        while i + 4 <= n and struct.unpack_from('<I', buf, i)[0] in func_starts:
            i += 4
        ln = (i - start) // 4
        if ln >= 3:
            runs.append((BASE + start, ln))
    else:
        i += 4

# merge/filter: drop runs fully inside known vtables
out = []
for a, ln in runs:
    if in_vt(a) and in_vt(a + 4 * ln - 4):
        continue
    out.append({'addr': hex(a), 'count': ln,
                'first': hex(struct.unpack_from('<I', buf, a - BASE)[0]),
                'first_name': func_names.get(struct.unpack_from('<I', buf, a - BASE)[0]),
                'targets': [hex(struct.unpack_from('<I', buf, a - BASE + 4 * k)[0])
                            for k in range(ln)]})
json.dump(out, open(W + 'fptr_runs.json', 'w'), indent=1)
print('raw runs:', len(runs), 'after vtable exclusion:', len(out))
for r in out[:40]:
    print(r['addr'], 'n=%d' % r['count'], r['first_name'], 'in_vt_partial' if in_vt(int(r['addr'],16)) else '')
