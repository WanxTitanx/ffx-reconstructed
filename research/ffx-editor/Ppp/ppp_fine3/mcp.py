#!/usr/bin/env python3
"""mcp.py — DEPRECATED shim. Canonical client: ../../ida_mcp_client.py

Folded 2026-09-18 (Jarvis-MCP-LEGACY): this was the ppp_fine3 lane's tiny
JSON-RPC CLI for the idalib/ida-pro-mcp server (ffxoficial.exe.i64). It now
delegates transport to the canonical client — retry/backoff, lazy
initialize/mcp-session-id handshake — while keeping the original public
contract:

    call(tool, args)                      -> response body as JSON text
    python3 mcp.py <tool> '<args-json>'   -> prints unwrapped result text

Callers: none found (2026-09-18) — this lane's scan*.py/dec2.py/disptable.py
each embed their own private _post transport instead of importing this file.
New work should import ``research_tools/ida_mcp_client.py`` instead.
"""
import json
import os
import sys
import warnings

sys.path.insert(0, os.path.dirname(os.path.dirname(
    os.path.dirname(os.path.abspath(__file__)))))  # research_tools/
import ida_mcp_client as _c  # noqa: E402  (canonical client, two dirs up)

warnings.warn(
    "research_tools/Ppp/ppp_fine3/mcp.py is deprecated — use "
    "research_tools/ida_mcp_client.py (canonical MCP client)",
    DeprecationWarning, stacklevel=2)


def call(tool, args):
    """Same contract as the original: the tools/call response body as text.

    The original returned only joined SSE ``data:`` lines (empty for plain
    JSON replies); the canonical envelope serialized back to JSON is the same
    content for SSE replies and strictly better for plain ones.
    """
    return json.dumps(_c.call_raw(tool, args), ensure_ascii=False)


if __name__ == "__main__":
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    out = call(tool, args)
    try:
        d = json.loads(out)
        # unwrap content blocks
        res = d.get("result", d)
        if isinstance(res, dict) and "content" in res:
            for c in res["content"]:
                if c.get("type") == "text":
                    try:
                        inner = json.loads(c["text"])
                        print(json.dumps(inner, indent=2))
                    except Exception:
                        print(c["text"])
        else:
            print(json.dumps(res, indent=2)[:20000])
    except Exception:
        print(out[:20000])
