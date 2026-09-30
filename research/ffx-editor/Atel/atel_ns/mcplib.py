"""Shared JSON-RPC client for idalib-mcp (importable)."""
import json, urllib.request

URL = "http://192.168.122.85:8745/mcp"
HDRS = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream"}

def _post(payload, sess=None):
    h = dict(HDRS)
    if sess:
        h["mcp-session-id"] = sess
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(), headers=h)
    resp = urllib.request.urlopen(req, timeout=180)
    sid = resp.headers.get("mcp-session-id", sess)
    body = resp.read().decode()
    out = []
    for line in body.splitlines():
        if line.startswith("data: "):
            out.append(line[6:])
        elif line and not line.startswith("event:") and not line.startswith(":"):
            out.append(line)
    return sid, "\n".join(out)

class Mcp:
    def __init__(self):
        self.sess, _ = _post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                              "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                                         "clientInfo": {"name": "atel-ns", "version": "1"}}})
        _post({"jsonrpc": "2.0", "method": "notifications/initialized"}, self.sess)
        self._id = 10

    def call(self, tool, args=None):
        self._id += 1
        _, body = _post({"jsonrpc": "2.0", "id": self._id, "method": "tools/call",
                         "params": {"name": tool, "arguments": args or {}}}, self.sess)
        try:
            d = json.loads(body)
        except Exception:
            return body
        res = d.get("result", d)
        if isinstance(res, dict) and "content" in res:
            return "\n".join(c.get("text", "") for c in res["content"] if c.get("type") == "text")
        return json.dumps(d, indent=1)

    def tools(self):
        self._id += 1
        _, body = _post({"jsonrpc": "2.0", "id": self._id, "method": "tools/list", "params": {}}, self.sess)
        return json.loads(body)
