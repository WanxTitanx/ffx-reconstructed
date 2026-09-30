#!/usr/bin/env python3
"""mcp8745.py — DEPRECATED shim. Canonical client: ../ida_mcp_client.py

Reconciled 2026-09-18 (Jarvis-MCP-CLIENT-RECONCILE): this file used to be a
standalone urllib client for the idalib/ida-pro-mcp server on
192.168.122.85:8745. It now re-exports the canonical client's primitives with
the SAME signatures, so existing callers keep working:

    rpc(method, params, rid=1, tries=5) -> envelope dict
    call(tool, args)                    -> envelope dict

CLI kept: ``mcp8745.py --list`` | ``mcp8745.py <tool> '<json-args>'``
New work should import ``research_tools/ida_mcp_client.py`` instead.
"""
import json
import os
import sys
import warnings

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import ida_mcp_client as _c  # noqa: E402  (canonical client, one dir up)

warnings.warn(
    "research_tools/Ida/mcp8745.py is deprecated — use "
    "research_tools/ida_mcp_client.py (canonical MCP client)",
    DeprecationWarning, stacklevel=2)


def rpc(method, params, rid=1, tries=5):
    """Same contract as the original: JSON-RPC envelope dict, retry/backoff."""
    return _c.rpc(method, params, rid=rid, tries=tries)


def call(tool, args):
    """Same contract as the original: tools/call envelope dict."""
    return _c.call_raw(tool, args)


if __name__ == "__main__":
    if len(sys.argv) < 2 or sys.argv[1] == "--list":
        print(json.dumps(rpc("tools/list", {}), indent=1)[:8000])
        sys.exit(0)
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    out = call(tool, args)
    print(json.dumps(out, indent=1, ensure_ascii=False))
