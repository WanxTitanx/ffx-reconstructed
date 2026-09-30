#!/usr/bin/env python3
"""Census of ATEL funcIds (operands of CALL=0xB5 / CALLPOPA=0xD8) across the
.ebp event corpus. Walk = linear opcode scan (proven to close on codeLen).
"""
import os, struct, sys
from collections import Counter

ROOT = "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/event/obj"
OUT  = "/home/wanderson/Documents/ffx-editor-main/work/_atel_ns"

def parse_ebp(path):
    b = open(path, "rb").read()
    if b[:4] != b"EV01":
        return None
    # chunk offset table: u32s from +4 until 0xFFFFFFFF
    offs = []
    p = 4
    while p + 4 <= len(b):
        v = struct.unpack_from("<I", b, p)[0]
        if v == 0xFFFFFFFF:
            break
        offs.append(v); p += 4
    if not offs:
        return None
    c0 = offs[0]
    if c0 + 0x38 > len(b):
        return None
    code_len   = struct.unpack_from("<I", b, c0 + 0x00)[0]
    off_code   = struct.unpack_from("<I", b, c0 + 0x30)[0]
    if off_code == 0 or c0 + off_code + code_len > len(b) or code_len > len(b):
        return None
    return b[c0 + off_code : c0 + off_code + code_len]

CALL_OPS = {0xB5, 0xD8}

def scan(code):
    """yield (op, operand) for 3-byte instrs; skip operand bytes."""
    i = 0
    n = len(code)
    while i < n:
        op = code[i]
        if op & 0x80:
            if i + 3 > n:
                break
            operand = struct.unpack_from("<H", code, i + 1)[0]
            yield op, operand
            i += 3
        else:
            yield op, None
            i += 1

def main():
    files = []
    for dp, _, fns in os.walk(ROOT):
        for fn in fns:
            if fn.endswith(".ebp"):
                files.append(os.path.join(dp, fn))
    files.sort()
    ns_counter   = Counter()   # namespace -> count of call-sites
    fid_counter  = Counter()   # funcId -> count
    per_file_ns  = {}          # file -> set(namespaces) for unk ns only
    bad = []
    unk_ns = {2, 3, 0xA, 0xE, 0xF}
    for path in files:
        code = parse_ebp(path)
        if code is None:
            bad.append(path); continue
        rel = os.path.relpath(path, ROOT)
        for op, operand in scan(code):
            if op in CALL_OPS and operand is not None:
                ns = operand >> 12
                ns_counter[ns] += 1
                fid_counter[operand] += 1
                if ns in unk_ns:
                    per_file_ns.setdefault(rel, set()).add(operand)
    print(f"files={len(files)} bad={len(bad)}")
    print("namespace histogram (call-site count):")
    for ns in sorted(ns_counter):
        tag = " <== UNREGISTERED" if ns in unk_ns else ""
        print(f"  ns {ns:#04x}: {ns_counter[ns]}{tag}")
    print(f"distinct funcIds: {len(fid_counter)}")
    print("unregistered-namespace call sites per file:")
    for rel, ids in sorted(per_file_ns.items()):
        print(f"  {rel}: {sorted(hex(i) for i in ids)}")
    with open(os.path.join(OUT, "funcid_census.txt"), "w") as f:
        f.write("ns histogram:\n")
        for ns in sorted(ns_counter):
            f.write(f"{ns:#06x} {ns_counter[ns]}\n")
        f.write("\nall funcIds:\n")
        for fid, c in sorted(fid_counter.items()):
            f.write(f"{fid:#06x} {c}\n")
    if bad:
        print("BAD FILES:", *bad, sep="\n  ")

main()
