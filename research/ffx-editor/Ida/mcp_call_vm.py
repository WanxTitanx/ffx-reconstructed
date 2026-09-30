#!/usr/bin/env python3
"""mcp_call_vm.py — DEPRECATED shim. Canonical client: ../ida_mcp_client.py

Folded 2026-09-18 (Jarvis-MCP-LEGACY): this was the MICRO-FIXES lane's
(2026-09-14) thin urllib wrapper for ``tools/call`` on the ida-pro-mcp/idalib
server at http://192.168.122.85:8745/mcp (DB ffxoficial.exe.i64). It now
delegates transport to the canonical client — retry/backoff, lazy
initialize/mcp-session-id handshake, SSE multi-frame parsing — while keeping
the original public contract:

    call(name, args, tid=1) -> resp["result"] dict | {"rpc_error": ...}
    python3 mcp_call_vm.py <tool> '<json-args>'   -> prints text blocks

Legacy quirk moved to env: the CLI used to inject ``database="2894d7a5"`` (an
idalib session id) into every non-session tool call. The CURRENT server build
rejects the arg outright ("Invalid params: unexpected parameters:
['database']"), so the injection only happens when IDA_MCP_DATABASE is set —
canonical ``_inject_database`` applies it and keeps the same
idb_list/idb_open exclusion this file used. (The hardcoded session id is stale
anyway — session ids do not survive server restarts.)

Callers: none found repo-wide (2026-09-18) — docs reference it as the
MICRO-FIXES lane CLI helper (`docs/reverse/FFX_MICRO_FIXES_2026-09-14.md`).
New work should import ``research_tools/ida_mcp_client.py`` instead.
"""
import json
import os
import sys
import warnings

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import ida_mcp_client as _c  # noqa: E402  (canonical client, one dir up)

warnings.warn(
    "research_tools/Ida/mcp_call_vm.py is deprecated — use "
    "research_tools/ida_mcp_client.py (canonical MCP client)",
    DeprecationWarning, stacklevel=2)


def call(name, args, tid=1):
    """Same contract as the original: result dict on success,
    ``{"rpc_error": ...}`` on JSON-RPC/transport failure.

    ``tid`` is accepted for signature compat but ignored — the canonical
    client picks its own request id (unobservable in the returned result).
    """
    d = _c.call_raw(name, args)
    if "error" in d:
        return {"rpc_error": d["error"]}
    return d.get("result", d)


if __name__ == "__main__":
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    # Legacy injected args["database"]="2894d7a5" for all tools except
    # idb_list/idb_open; now env-gated via IDA_MCP_DATABASE inside the
    # canonical client (current server rejects the arg — see module docstring).
    out = call(tool, args)
    txt = out.get("content") if isinstance(out, dict) else out
    if isinstance(txt, list):
        for blk in txt:
            print(blk.get("text", ""))
    else:
        print(json.dumps(out, indent=1)[:20000])
