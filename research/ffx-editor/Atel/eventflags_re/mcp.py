#!/usr/bin/env python3
"""mcp.py — DEPRECATED shim. Canonical client: ../../ida_mcp_client.py

Folded 2026-09-18 (Jarvis-MCP-LEGACY): this was the EVENTFLAGS-RE lane's
(2026-09-14) JSON-RPC helper for the idalib/ida-pro-mcp server at
http://192.168.122.85:8745/mcp. It now delegates transport to the canonical
client — retry/backoff, lazy initialize/mcp-session-id handshake, SSE
multi-frame parsing (the original json.loads'ed the raw body and broke on
SSE-framed replies) — while keeping the original public contract:

    rpc(method, params, id_=1)           -> decoded JSON-RPC envelope dict
    python3 mcp.py --list                -> prints tool names
    python3 mcp.py <tool> '<json-args>'  -> prints text blocks

Legacy quirk moved to env: main() used to inject ``database="2894d7a5"`` (an
idalib session id, stale — session ids do not survive server restarts) into
every call. The CURRENT server build rejects the arg ("Invalid params:
unexpected parameters: ['database']"); the injection now only happens when
IDA_MCP_DATABASE is set (canonical ``_inject_database``).

Callers: none found (2026-09-18) — the only lane sibling is put_receiver.py
(an unrelated HTTP PUT server). New work should import
``research_tools/ida_mcp_client.py`` instead.
"""
import json
import os
import sys
import warnings

sys.path.insert(0, os.path.dirname(os.path.dirname(
    os.path.dirname(os.path.abspath(__file__)))))  # research_tools/
import ida_mcp_client as _c  # noqa: E402  (canonical client, two dirs up)

warnings.warn(
    "research_tools/Atel/eventflags_re/mcp.py is deprecated — use "
    "research_tools/ida_mcp_client.py (canonical MCP client)",
    DeprecationWarning, stacklevel=2)

DB = "2894d7a5"  # legacy idalib session id (C:\IDA_DB\ffxoficial.exe.i64) —
# kept for documentation; only injected when IDA_MCP_DATABASE is set (the
# current server build rejects the `database` arg — see module docstring).


def rpc(method, params, id_=1):
    """Same contract as the original: decoded JSON-RPC envelope dict.

    Canonical rpc() returns the same envelope shape and adds retry/backoff,
    session reuse and SSE parsing.
    """
    return _c.rpc(method, params, rid=id_)


def main():
    if sys.argv[1] == "--list":
        r = rpc("tools/list", {})
        for t in r.get("result", {}).get("tools", []):
            print(t["name"])
        return
    name = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    # Legacy did args["database"] = DB unconditionally; now env-gated because
    # the current server build rejects the arg outright.
    if os.environ.get("IDA_MCP_DATABASE"):
        args["database"] = os.environ["IDA_MCP_DATABASE"]
    r = rpc("tools/call", {"name": name, "arguments": args})
    res = r.get("result", {})
    if "content" in res:
        for c in res["content"]:
            print(c.get("text", ""))
    else:
        print(json.dumps(r, indent=1)[:6000])


if __name__ == "__main__":
    main()
