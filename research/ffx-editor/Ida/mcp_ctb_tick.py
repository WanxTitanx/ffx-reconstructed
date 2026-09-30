#!/usr/bin/env python3
"""mcp_ctb_tick.py — DEPRECATED shim. Canonical client: ../ida_mcp_client.py

Folded 2026-09-18 (Jarvis-MCP-LEGACY): despite the name (it was the CTB lane's
one-shot helper), this file contained NO ctb-specific logic — just another
copy of the generic urllib+SSE client with a per-call initialize handshake.
It now delegates transport to the canonical client while keeping the original
public contract:

    post(payload, sess=None) -> (sid, body_text)   # SSE-stripped body
    call(tool, args)         -> response body as JSON text
    python3 mcp_ctb_tick.py <tool> '<json-args>'   -> prints text blocks

Callers: none found repo-wide (2026-09-18) — name lives only in docs/README.
New work should import ``research_tools/ida_mcp_client.py`` instead.
"""
import json
import os
import sys
import warnings

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import ida_mcp_client as _c  # noqa: E402  (canonical client, one dir up)

warnings.warn(
    "research_tools/Ida/mcp_ctb_tick.py is deprecated — use "
    "research_tools/ida_mcp_client.py (canonical MCP client)",
    DeprecationWarning, stacklevel=2)


def post(payload, sess=None):
    """Same contract as the original: (session_id, SSE-stripped body text)."""
    return _c.post(payload, sess)


def call(tool, args):
    """Same contract as the original: the tools/call response body as text.

    The original returned the raw SSE-stripped body; the canonical envelope
    serialized back to JSON carries the same content (callers json.loads it —
    see main() below). Canonical adds handshake reuse + retry/backoff.
    """
    return json.dumps(_c.call_raw(tool, args), ensure_ascii=False)


def main():
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    body = call(tool, args)
    try:
        d = json.loads(body)
        res = d.get("result", d)
        if isinstance(res, dict) and "content" in res:
            for c in res["content"]:
                if c.get("type") == "text":
                    print(c["text"])
        else:
            print(json.dumps(d, indent=1)[:300000])
    except Exception:
        print(body[:300000])


if __name__ == "__main__":
    main()
