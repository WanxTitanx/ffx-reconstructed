#!/usr/bin/env python3
"""Persistent-session MCP client for idalib-mcp (FFX string-naming lane)."""
import json, sys, urllib.request

URL = "http://192.168.122.85:8745/mcp"
H = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream"}


class Mcp:
    def __init__(self):
        self.sid = None
        self._init()

    def post(self, payload):
        h = dict(H)
        if self.sid:
            h["mcp-session-id"] = self.sid
        r = urllib.request.urlopen(
            urllib.request.Request(URL, data=json.dumps(payload).encode(), headers=h),
            timeout=300)
        self.sid = r.headers.get("mcp-session-id", self.sid)
        body = r.read().decode()
        out = []
        for l in body.splitlines():
            if l.startswith("data: "):
                out.append(l[6:])
            elif l and not l.startswith("event:") and not l.startswith(":"):
                out.append(l)
        return "\n".join(out)

    def _init(self):
        self.post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                   "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                              "clientInfo": {"name": "strlane", "version": "1"}}})
        self.post({"jsonrpc": "2.0", "method": "notifications/initialized"})

    def call(self, tool, args):
        body = self.post({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
                          "params": {"name": tool, "arguments": args}})
        try:
            d = json.loads(body)
            res = d.get("result", d)
            if isinstance(res, dict) and "content" in res:
                texts = [c["text"] for c in res["content"] if c.get("type") == "text"]
                return "\n".join(texts)
            return json.dumps(res)
        except Exception:
            return body
