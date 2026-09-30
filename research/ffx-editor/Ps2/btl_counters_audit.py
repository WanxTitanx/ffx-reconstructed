#!/usr/bin/env python3
"""btl_counters_audit.py — Jarvis-BTL-COUNTERS (wave-13 residual lane).

Regenerates the three btl_counters_* maps from the canonical IDA DB via the
idalib-mcp server (research_tools/ida_mcp_client.py):

  1. Env/debug flag map  — decodes FFX_Menu2D_EnvKeyTable @0xC443E0
     (48 x {char* key, u32 idx, u32 pad}) and the ParseEnvConfig @0x7CE380
     switch targets (idx -> flag address). Prints idx,key,addr,name.

  2. actor+0xDC0 census  — search_text sweep for the exact 0xDC0 offset
     pattern inside battle functions; prints site, direction (read/write
     by opcode form), containing function.

  3. Flag xref census    — xrefs_to for every env flag address; separates
     parser (0x7CE3xx-0x7CE7xx) and menu-UI (0x7C6xxx-0x7CE1xx) refs from
     real battle/engine consumers.

Usage:
  python3 btl_counters_audit.py env      # env key -> flag addr map
  python3 btl_counters_audit.py dc0      # +0xDC0 site census
  python3 btl_counters_audit.py xrefs    # flag -> consumer census
  python3 btl_counters_audit.py all      # everything

Requires the MCP at http://192.168.122.85:8745/mcp (see ida_mcp_client.py).
Research-only; performs no IDB mutation.
"""

import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import ida_mcp_client as mcp  # noqa: E402

ENV_KEY_TABLE = 0xC443E0
ENV_KEY_COUNT = 48
ENV_STR_BASE = 0xB55A48
ENV_STR_SIZE = 0x200

# idx -> flag VA, resolved from ParseEnvConfig case bodies (wave-13 census).
# Cases 1 (env) and 9 (p3) store to globals that the decompiler renders as
# locals; VAs recovered from the raw instruction bytes @0x7CE415/0x7CE493.
ENV_CASE_TARGET = {
    1: 0x112A8F6, 2: None, 3: 0x112A8E1, 4: 0x112A8F8, 5: 0x112A8F5,
    6: 0x112A8FC, 7: 0x112C895, 8: 0x112C896, 9: 0x112C897,
    10: 0x112A900, 11: 0x112A901, 12: 0x112A8F9, 13: 0x112A8FA,
    14: 0x112A8FB, 15: 0x112A903, 16: 0x112A908, 17: 0x112A909,
    18: 0x112A90A, 19: 0x112A90B, 20: 0x112A902, 21: 0x112A904,
    22: 0x112A906, 23: 0x112A907, 24: 0x112A905, 25: 0x112A90C,
    26: 0x112A922, 27: 0x112A915, 28: 0x112A916, 29: 0x112A918,
    30: 0x112A91A, 31: 0x112A917, 32: 0x112A914, 33: 0x112A90D,
    34: 0x112A91B, 35: 0x112A91C, 36: 0x112A91D, 37: 0x112A91E,
    38: 0x112A91F, 39: 0x112A920, 40: 0x112A921, 41: 0x112A924,
    42: 0x112A925, 43: 0x112A926, 44: 0x112A927,
    45: "locale_thunk", 46: "btlevent_name", 47: None, 48: "locale",
}


def _bytes(addr, size):
    txt = mcp.call("get_bytes", {"regions": [{"addr": hex(addr), "size": size}]},
                   retries=3, timeout=60)
    d = json.loads(txt)
    return bytes(int(x, 16) for x in d[0]["data"].split())


def env_keys():
    """Return [(idx, key, flag_addr)] decoded live from the IDB."""
    tbl = _bytes(ENV_KEY_TABLE, ENV_KEY_COUNT * 12)
    strs = _bytes(ENV_STR_BASE, ENV_STR_SIZE)
    out = []
    for off in range(0, len(tbl) - 11, 12):
        ptr, idx, _pad = struct.unpack_from("<III", tbl, off)
        if not (0x400000 <= ptr <= 0xD00000):
            break
        key = strs[ptr - ENV_STR_BASE:].split(b"\0")[0].decode("ascii", "replace")
        out.append((idx, key, ENV_CASE_TARGET.get(idx)))
    return out


def cmd_env():
    print("idx,key,flag_addr")
    for idx, key, addr in env_keys():
        a = f"0x{addr:08X}" if isinstance(addr, int) else (addr or "-")
        print(f"{idx},{key},{a}")


def cmd_dc0():
    """Sweep battle code for actor+0xDC0 accesses (disp32 == 0xDC0)."""
    txt = mcp.call("search_text",
                   {"queries": ["0DC0h"], "limit": 400}, retries=3, timeout=90)
    d = json.loads(txt)
    hits = d[0].get("hits", d if isinstance(d, list) else [])
    print("site,function,instruction")
    for h in hits:
        fn = (h.get("function") or "")
        for mt in h.get("matches", []):
            if mt.get("kind") != "disasm":
                continue
            ins = mt.get("text", "")
            if "0DC0h" in ins and "10DC0" not in ins:
                print(f"{h['addr']},{fn},{ins.split()[-1][:80]}")


def cmd_xrefs():
    addrs = [a for a in ENV_CASE_TARGET.values() if isinstance(a, int)]
    txt = mcp.call("xrefs_to", {"addrs": [hex(a) for a in addrs]},
                   retries=3, timeout=180)
    d = json.loads(txt)
    print("flag_addr,ref_count,non_menu_consumers")
    for e in d:
        addr = e.get("addr")
        xs = e.get("xrefs", [])
        real = [x["addr"] for x in xs
                if not (0x7C6000 <= int(x["addr"], 16) <= 0x7CE800)]
        print(f"{addr},{len(xs)},{' '.join(real)}")


if __name__ == "__main__":
    cmd = sys.argv[1] if len(sys.argv) > 1 else "all"
    if cmd in ("env", "all"):
        cmd_env()
    if cmd in ("dc0", "all"):
        cmd_dc0()
    if cmd in ("xrefs", "all"):
        cmd_xrefs()
