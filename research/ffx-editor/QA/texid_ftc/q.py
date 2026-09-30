#!/usr/bin/env python3
"""Batch MCP query helper: reads tool+args JSON pairs from argv-file or runs presets."""
import json, sys, urllib.request

URL = "http://192.168.122.85:8745/mcp"
HDRS = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream"}

def post(payload, sess=None):
    h = dict(HDRS)
    if sess: h["mcp-session-id"] = sess
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(), headers=h)
    resp = urllib.request.urlopen(req, timeout=180)
    sid = resp.headers.get("mcp-session-id", sess)
    body = resp.read().decode()
    out = []
    for line in body.splitlines():
        if line.startswith("data: "): out.append(line[6:])
        elif line and not line.startswith("event:") and not line.startswith(":"): out.append(line)
    return sid, "\n".join(out)

class S:
    def __init__(self):
        self.sess, _ = post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"texid-ftc","version":"1.0"}}})
        post({"jsonrpc":"2.0","method":"notifications/initialized"}, self.sess)
    def call(self, tool, args=None, i=[2]):
        i[0] += 1
        _, body = post({"jsonrpc":"2.0","id":i[0],"method":"tools/call","params":{"name":tool,"arguments":args or {}}}, self.sess)
        try:
            d = json.loads(body)
            res = d.get("result", d)
            if isinstance(res, dict) and "content" in res:
                txt = "\n".join(c.get("text","") for c in res["content"] if c.get("type")=="text")
                return txt
            return json.dumps(d)[:400000]
        except Exception:
            return body[:400000]

if __name__ == "__main__":
    s = S()
    # each argv line: tool <json-args>
    for spec in json.loads(open(sys.argv[1]).read()):
        print("##### CALL", spec)
        print(s.call(spec[0], spec[1])[:60000])
        print()
