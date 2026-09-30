#!/usr/bin/env python3
"""mcpc.py — persistent-session client for idalib-mcp (dead-sweep lane).

Handles SSE framing + the server's big-output fallback (truncated responses
print a hint to fetch http://.../output/<id>.json — we detect & auto-fetch).
"""
import json, os, re, sys, urllib.request

URL = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp")
OUT_BASE = URL.rsplit("/mcp", 1)[0] + "/output/"
HDRS = {"Content-Type": "application/json",
        "Accept": "application/json, text/event-stream"}


class Ida:
    def __init__(self):
        self.sess = None
        self._init()

    def _post(self, payload):
        h = dict(HDRS)
        if self.sess:
            h["mcp-session-id"] = self.sess
        req = urllib.request.Request(URL, data=json.dumps(payload).encode(),
                                     headers=h)
        resp = urllib.request.urlopen(req, timeout=600)
        self.sess = resp.headers.get("mcp-session-id", self.sess)
        body = resp.read().decode()
        out = []
        for line in body.splitlines():
            if line.startswith("data: "):
                out.append(line[6:])
            elif line and not line.startswith("event:") \
                    and not line.startswith(":"):
                out.append(line)
        return "\n".join(out)

    def _init(self):
        self._post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                    "params": {"protocolVersion": "2025-03-26",
                               "capabilities": {},
                               "clientInfo": {"name": "dead-sweep",
                                              "version": "1.0"}}})
        self._post({"jsonrpc": "2.0",
                    "method": "notifications/initialized"})

    def call(self, tool, args):
        body = self._post({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
                           "params": {"name": tool, "arguments": args}})
        # server-side truncation fallback: "...curl -o .ida-mcp/<id>.json
        # http://HOST/output/<id>.json"
        m = re.search(r"(https?://\S+/output/[0-9a-f\-]+\.json)", body)
        text = body
        if m:
            big = urllib.request.urlopen(m.group(1), timeout=600) \
                .read().decode()
            try:
                d = json.loads(big)
                text = self._extract(d)
            except Exception:
                text = big
        else:
            try:
                d = json.loads(body)
                res = d.get("result", d)
                if isinstance(res, dict) and "content" in res:
                    text = "".join(c.get("text", "") for c in res["content"]
                                   if c.get("type") == "text")
                    m2 = re.search(
                        r"(https?://\S+/output/[0-9a-f\-]+\.json)", text)
                    if m2:
                        big = urllib.request.urlopen(
                            m2.group(1), timeout=600).read().decode()
                        text = big
                else:
                    text = json.dumps(d)
            except Exception:
                pass
        try:
            d = json.loads(text)
            # output-file payloads arrive as {"result": <tool-payload>}
            if isinstance(d, dict) and set(d.keys()) == {"result"}:
                return d["result"]
            return d
        except Exception:
            return text

    @staticmethod
    def _extract(d):
        res = d.get("result", d)
        if isinstance(res, dict) and "content" in res:
            return "".join(c.get("text", "") for c in res["content"]
                           if c.get("type") == "text")
        return json.dumps(d)


if __name__ == "__main__":
    ida = Ida()
    print(json.dumps(ida.call(sys.argv[1],
                              json.loads(sys.argv[2]) if len(sys.argv) > 2
                              else {}))[:5000])
