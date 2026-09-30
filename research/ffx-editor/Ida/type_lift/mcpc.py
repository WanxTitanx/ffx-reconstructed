#!/usr/bin/env python3
"""mcpc.py — persistent-session JSON-RPC client for the FFX idalib-mcp server.

Usage (as module):
    from mcpc import call
    res = call("xrefs_to", {"addrs": ["0x794030"], "limit": 1000})

Usage (CLI):
    mcpc.py <tool> '<json-args>'        # prints text content
"""
import json, os, sys, urllib.request

URL = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp")
HDRS = {"Content-Type": "application/json",
        "Accept": "application/json, text/event-stream"}
_sess = None
_id = [0]


def _post(payload):
    global _sess
    h = dict(HDRS)
    if _sess:
        h["mcp-session-id"] = _sess
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(), headers=h)
    resp = urllib.request.urlopen(req, timeout=300)
    _sess = resp.headers.get("mcp-session-id", _sess)
    body = resp.read().decode()
    out = []
    for line in body.splitlines():
        if line.startswith("data: "):
            out.append(line[6:])
        elif line and not line.startswith("event:") and not line.startswith(":"):
            out.append(line)
    return "\n".join(out)


def _init():
    global _sess
    _id[0] += 1
    _post({"jsonrpc": "2.0", "id": _id[0], "method": "initialize",
           "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                      "clientInfo": {"name": "type-lift-r2", "version": "1.0"}}})
    _post({"jsonrpc": "2.0", "method": "notifications/initialized"})


def call(tool, args):
    """Call a tool; returns parsed result (or raw text)."""
    if _sess is None:
        _init()
    _id[0] += 1
    body = _post({"jsonrpc": "2.0", "id": _id[0], "method": "tools/call",
                  "params": {"name": tool, "arguments": args}})
    try:
        d = json.loads(body)
    except Exception:
        return body
    res = d.get("result", d)
    if isinstance(res, dict) and "content" in res:
        texts = [c.get("text", "") for c in res["content"] if c.get("type") == "text"]
        joined = "\n".join(texts)
        try:
            return json.loads(joined)
        except Exception:
            pass
        # try parsing first text only (truncation note may follow)
        if texts:
            try:
                return json.loads(texts[0])
            except Exception:
                return joined
        return joined
    return res


if __name__ == "__main__":
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    r = call(tool, args)
    if isinstance(r, str):
        print(r)
    else:
        print(json.dumps(r, indent=1))
