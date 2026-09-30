#!/usr/bin/env python3
"""mcp.py — vtable-lane wrapper around ida_mcp.py that follows truncated-output URLs."""
import json, os, re, subprocess, sys, urllib.request

URL = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp")
HDRS = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream"}


def post(payload, sess=None):
    h = dict(HDRS)
    if sess:
        h["mcp-session-id"] = sess
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(), headers=h)
    resp = urllib.request.urlopen(req, timeout=300)
    sid = resp.headers.get("mcp-session-id", sess)
    body = resp.read().decode()
    out = []
    for line in body.splitlines():
        if line.startswith("data: "):
            out.append(line[6:])
        elif line and not line.startswith("event:") and not line.startswith(":"):
            out.append(line)
    return sid, "\n".join(out)


def call(tool, args):
    sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                    "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                               "clientInfo": {"name": "vtable-lane", "version": "1.0"}}})
    post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)
    _, body = post({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
                    "params": {"name": tool, "arguments": args}}, sess)
    # Follow truncated-output URL if present
    m = re.search(r'Output truncated\. Run: curl -o \S+ (http://[^\s"]+)', body)
    if m:
        import time
        last = None
        for attempt in range(120):
            try:
                with urllib.request.urlopen(m.group(1), timeout=300) as r:
                    body = r.read().decode()
                break
            except Exception as e:
                last = e
                time.sleep(2.0)
        else:
            raise last
    try:
        d = json.loads(body)
        res = d.get("result", d)
        if isinstance(res, dict) and "content" in res:
            return "\n".join(c["text"] for c in res["content"] if c.get("type") == "text")
        return res if not isinstance(res, str) else res
    except Exception:
        return body


if __name__ == "__main__":
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    out = call(tool, args)
    print(json.dumps(out) if not isinstance(out, str) else out)
