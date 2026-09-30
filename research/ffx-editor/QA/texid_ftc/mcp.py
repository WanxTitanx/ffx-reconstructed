#!/usr/bin/env python3
"""Helper: call idalib MCP tool. Usage: mcp.py <tool> '<args-json>'"""
import json, sys, urllib.request

URL = "http://192.168.122.85:8745/mcp"
HDRS = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream"}

def post(payload, sess=None):
    h = dict(HDRS)
    if sess: h["mcp-session-id"] = sess
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(), headers=h)
    resp = urllib.request.urlopen(req, timeout=120)
    sid = resp.headers.get("mcp-session-id", sess)
    body = resp.read().decode()
    out = []
    for line in body.splitlines():
        if line.startswith("data: "): out.append(line[6:])
        elif line and not line.startswith("event:") and not line.startswith(":"): out.append(line)
    return sid, "\n".join(out)

def main():
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    sess, _ = post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"texid-ftc","version":"1.0"}}})
    post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
    _, body = post({"jsonrpc":"2.0","id":2,"method":"tools/call","params":{"name":tool,"arguments":args}}, sess)
    try:
        d = json.loads(body)
        # unwrap content text
        res = d.get("result", d)
        if isinstance(res, dict) and "content" in res:
            for c in res["content"]:
                if c.get("type") == "text":
                    print(c["text"])
            if res.get("structuredContent") is not None:
                pass
        else:
            print(json.dumps(d, indent=1)[:200000])
    except Exception:
        print(body[:200000])

if __name__ == "__main__":
    main()
