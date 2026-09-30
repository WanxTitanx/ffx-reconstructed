#!/usr/bin/env python3
"""w20-seplifecycle helper: call MCP tools pinned to the ffxoficial.exe.i64 session.

The shared server hosts multiple IDB sessions; other lanes re-activate theirs.
This wrapper checks the active module before every call and re-opens
C:\\IDA_DB\\ffxoficial.exe.i64 when the active session is wrong.
"""
import json
import sys
import time

sys.path.insert(0, "/home/wanderson/Documents/ffx-editor-main/research_tools")
import ida_mcp_client as C

FFX_I64 = "C:\\IDA_DB\\ffxoficial.exe.i64"


def active_module():
    txt = C.call("server_health", {}, retries=2, timeout=20)
    try:
        return json.loads(txt).get("module", "")
    except Exception:
        return ""


def ensure_ffx(tries=8):
    for _ in range(tries):
        if active_module() == "FFX.exe":
            return True
        C.call("idb_open", {"input_path": FFX_I64, "run_auto_analysis": False,
                            "build_caches": False, "init_hexrays": True,
                            "idle_ttl_sec": 1800}, retries=2, timeout=60)
        time.sleep(0.5)
    return active_module() == "FFX.exe"


def call(name, args, retries=8, timeout=None, verify=True):
    """Call tool; if verify, ensure FFX.exe active first. Returns text."""
    if verify and not ensure_ffx():
        return "ERROR: could not activate ffxoficial.exe.i64 (server busy?)"
    return C.call(name, args, retries=retries, timeout=timeout)


def callj(name, args, retries=8, timeout=None, verify=True):
    txt = call(name, args, retries=retries, timeout=timeout, verify=verify)
    try:
        return json.loads(txt)
    except Exception:
        return {"_raw": txt}


if __name__ == "__main__":
    name = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    print(call(name, args))
