#!/usr/bin/env python3
"""mcp_batch.py — batch JSON-RPC helper for the IDA MCP server.

Runs N tool calls from an ops JSON file over ONE MCP session (initialize
once, then tools/call per op). KEPT as a lane tool — the batch orchestration
is real logic — but its transport now delegates to the canonical client
``research_tools/ida_mcp_client.py`` (Jarvis-MCP-LEGACY, 2026-09-18): retry/
backoff + lazy initialize/mcp-session-id reuse now come for free, which is
exactly what the "one session for N calls" contract wants (the canonical
client reuses one session per process). Prefer ``ida_mcp_client.call`` for
new work.

usage: mcp_batch.py ops.json     # ops.json = [{"tool": "...", "args": {...}}]

Legacy public surface kept for compatibility:
    post(payload, sess=None) -> (sid, body_text)   # SSE-stripped body
    call(sess, tool, args)   -> text               # sess ignored (see below)
"""
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import ida_mcp_client as _c  # noqa: E402  (canonical client, one dir up)


def post(payload, sess=None):
    """Legacy raw transport — delegates to canonical ``post`` (same contract:
    returns (session_id, SSE-stripped body text), raises urllib errors)."""
    return _c.post(payload, sess)


def call(sess, tool, args):
    """Legacy call — ``sess`` is accepted for signature compat but ignored:
    the canonical client owns the handshake and reuses one session per
    process, which is the whole point of this batch helper.

    Extraction semantics preserved from the original: joined text blocks,
    else compact JSON of the envelope ([:4000]).
    """
    d = _c.call_raw(tool, args)
    res = d.get("result", d)
    if isinstance(res, dict) and "content" in res:
        return "\n".join(c.get("text", "") for c in res["content"]
                         if c.get("type") == "text")
    return json.dumps(d)[:4000]


def main():
    _c.initialize()  # explicit handshake up front (was: manual initialize +
    # notifications/initialized); canonical then reuses the session for all ops.
    ops = json.load(open(sys.argv[1]))
    for i, op in enumerate(ops):
        tool, args = op["tool"], op["args"]
        out = call(None, tool, args)
        print(f"--- [{i}] {tool} {json.dumps(args)[:120]}")
        print(out[:2500])
        print()


if __name__ == "__main__":
    main()
