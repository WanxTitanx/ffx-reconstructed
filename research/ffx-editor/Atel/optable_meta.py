#!/usr/bin/env python3
# ── optable_meta.py — dump g_FFX_Atel_OpcodeNameTable + f1/f2 semantic map ────
#
# Lane: Jarvis-EVOPS-TAIL (2026-09-18). Dumps the 123 x 16B opcode meta records
# of the FFX event-VM at g_FFX_Atel_OpcodeNameTable @0xC54600 via the canonical
# ida-pro-mcp endpoint, resolves each record's name string, and classifies the
# dead assembler fields f1 (+4) / f2 (+8):
#
#   record layout: { u32 name_ptr; u32 f1; u32 f2; u16 instr_len; u16 cls }
#
#   f1 = input operand tag-constraint (assembler type-check signature):
#        0 = unchecked  |  1 = int-required (PopOperand path)
#        2 = numeric (int|float via CheckFlagBytePair)
#   f2 = result tag:   0 = none  |  1 = int  |  2 = numeric (preserve input)
#   instr_len = encoded length (0 = assembler marker LABEL/TAG/FIXADRS)
#   cls = operand-kind tag used by FFX_FieldDebug_AiOperandFormatter @0x8855F0
#
# PROVEN: f1/f2/instr_len have ZERO in-binary readers (only name_ptr@+0 ->
# FFX_FieldDebug_AiOpcodeNameLookup and cls@+0xE -> AiOperandFormatter are
# consumed). The {f1,f2} partition maps 1:1 onto the proven interpreter
# families: {1,1}=int-only ops, {2,1}=comparisons, {2,2}=arithmetic,
# {0,0}=everything else (incl. forced-float OPUMINUS). The constraint
# interpretation is PARTIAL (dead toolchain metadata; no consumer to check).
#
# Usage:
#   optable_meta.py [--csv out.csv] [--json out.json]
#   IDA_MCP_URL env overrides http://192.168.122.85:8745/mcp.
# stdlib only.
import argparse
import csv
import json
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from ida_mcp_client import call  # noqa: E402  canonical MCP client

TABLE_VA = 0xC54600
REC_SIZE = 16
N_OPS = 123
STR_REGION = 0xB5DB00          # primary name-string pool 0xB5DB00..0xB5DCxx
STR_SIZE = 0x800
_str_cache = {}                # ptr -> name, lazy per-ptr fetch for outliers

CLS_NAME = {
    0: "none", 1: "imm16", 2: "int-pool idx", 3: "var-desc idx",
    4: "funcId", 5: "float-pool idx", 6: "tag", 7: "label/jump idx",
    8: "script-id",
}
F1_NAME = {0: "unchecked", 1: "int-required", 2: "numeric"}
F2_NAME = {0: "none", 1: "int", 2: "numeric-preserved"}


def get_bytes(addr, size):
    d = json.loads(call("get_bytes", {"regions": [{"addr": hex(addr), "size": size}]}))
    return bytes(int(b, 16) for b in d[0]["data"].split())


def family(f1, f2):
    if (f1, f2) == (0, 0):
        return "non-formula / unchecked"
    if (f1, f2) == (1, 1):
        return "int-only op"
    if (f1, f2) == (2, 1):
        return "comparison"
    if (f1, f2) == (2, 2):
        return "arithmetic"
    return f"unexpected-{{{f1},{f2}}}"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--csv")
    ap.add_argument("--json")
    args = ap.parse_args()

    data = get_bytes(TABLE_VA, REC_SIZE * N_OPS)
    sdata = get_bytes(STR_REGION, STR_SIZE)

    def cstr(ptr):
        off = ptr - STR_REGION
        if 0 <= off < len(sdata):
            return sdata[off:sdata.find(b"\x00", off)].decode("ascii", "replace")
        if ptr not in _str_cache:                      # out-of-pool ptr: lazy fetch
            try:
                b = get_bytes(ptr, 64)
                _str_cache[ptr] = b[:b.find(b"\x00")].decode("ascii", "replace")
            except Exception:
                _str_cache[ptr] = f"<{ptr:x}>"
        return _str_cache[ptr]

    rows = []
    for op in range(N_OPS):
        name_ptr, f1, f2, ilen, cls = struct.unpack_from("<IIIHH", data, op * REC_SIZE)
        rows.append({
            "op": f"0x{op:02x}", "name": cstr(name_ptr), "f1": f1, "f2": f2,
            "f1_sem": F1_NAME.get(f1, "?"), "f2_sem": F2_NAME.get(f2, "?"),
            "family": family(f1, f2), "instr_len": ilen,
            "cls": cls, "cls_sem": CLS_NAME.get(cls, "?"),
        })

    if args.csv:
        with open(args.csv, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(rows[0]))
            w.writeheader()
            w.writerows(rows)
    if args.json:
        with open(args.json, "w") as f:
            json.dump(rows, f, indent=1)
    for r in rows:
        print(f"{r['op']} {r['name']:<10} f1={r['f1']}({r['f1_sem']}) "
              f"f2={r['f2']}({r['f2_sem']}) len={r['instr_len']} "
              f"cls={r['cls']}({r['cls_sem']}) -> {r['family']}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
