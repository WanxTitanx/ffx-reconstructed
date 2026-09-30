#!/usr/bin/env python3
"""ida_mcp.py — DEPRECATED shim. Canonical client: ../ida_mcp_client.py

Reconciled 2026-09-18 (Jarvis-MCP-CLIENT-RECONCILE): this was the "consolidated"
one-shot JSON-RPC client (initialize -> mcp-session-id handshake -> tools/call).
It now re-exports the canonical client so the ~30 existing callers that do
``from ida_mcp import post`` keep working unchanged:

    post(payload, sess=None) -> (sid, body_text)   # SSE-stripped body
    python3 research_tools/Ida/ida_mcp.py <tool> '<args-json>'   # prints text

New work should import ``research_tools/ida_mcp_client.py`` instead — it adds
retry/backoff, --selftest/--ping, env overrides (IDA_MCP_URL, ...).

Server: env IDA_MCP_URL overrides the default VM endpoint
(http://192.168.122.85:8745/mcp — ida-pro-mcp/idalib-mcp on the Windows IDA VM,
DB C:\\IDA_DB\\ffxoficial.exe.i64, imagebase 0x400000).
"""
import os
import sys
import warnings

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import ida_mcp_client as _c  # noqa: E402  (canonical client, one dir up)

warnings.warn(
    "research_tools/Ida/ida_mcp.py is deprecated — use "
    "research_tools/ida_mcp_client.py (canonical MCP client)",
    DeprecationWarning, stacklevel=2)

# Re-exports — the legacy public surface of this module.
URL = _c.URL
HDRS = _c.HDRS
post = _c.post
rpc = _c.rpc
call = _c.call
tools_list = _c.tools_list
initialize = _c.initialize


def main():
    """Legacy CLI: ``ida_mcp.py <tool> '<args-json>'`` -> prints tool text."""
    sys.exit(_c.main())


if __name__ == "__main__":
    main()
