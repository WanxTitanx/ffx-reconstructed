#!/usr/bin/env python3
"""Batch export_funcs fetcher — one MCP session, chunks of addrs, handles
the server's 'Output truncated -> /output/<uuid>.json' offload.

Usage: batch_export.py <addrs-file> <out.jsonl> [start-idx] [chunk]
Writes JSONL records: {addr,name,prototype,size,asm,comments}.
"""
import json, os, re, sys, time, urllib.request

BASE = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp")
ORIGIN = re.sub(r"/mcp$", "", BASE)
HDRS = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream"}
_sess = None
_reqid = 0

def post(payload):
    global _sess
    h = dict(HDRS)
    if _sess:
        h["mcp-session-id"] = _sess
    req = urllib.request.Request(BASE, data=json.dumps(payload).encode(), headers=h)
    for attempt in range(5):
        try:
            resp = urllib.request.urlopen(req, timeout=300)
            sid = resp.headers.get("mcp-session-id")
            if sid:
                _sess = sid
            body = resp.read().decode()
            out = []
            for line in body.splitlines():
                if line.startswith("data: "):
                    out.append(line[6:])
                elif line and not line.startswith("event:") and not line.startswith(":"):
                    out.append(line)
            return "\n".join(out)
        except Exception:
            if attempt == 4:
                raise
            time.sleep(2 * (attempt + 1))

def fetch_offload(url):
    if url.startswith("/"):
        url = ORIGIN + url
    for attempt in range(5):
        try:
            return urllib.request.urlopen(url, timeout=300).read().decode()
        except Exception:
            if attempt == 4:
                raise
            time.sleep(2 * (attempt + 1))

def call(tool, args):
    global _reqid
    _reqid += 1
    body = post({"jsonrpc": "2.0", "id": _reqid, "method": "tools/call",
                 "params": {"name": tool, "arguments": args}})
    texts = []
    try:
        d = json.loads(body)
        res = d.get("result", d)
        if isinstance(res, dict) and "content" in res:
            for c in res["content"]:
                if c.get("type") == "text":
                    texts.append(c["text"])
    except Exception:
        texts = [body]
    out = []
    for t in texts:
        m = re.search(r"curl -o \S+ (https?://\S+)", t)
        if m:
            t = fetch_offload(m.group(1))
        out.append(t)
    return out

def init():
    post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
          "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                     "clientInfo": {"name": "mislabel-audit", "version": "1.0"}}})
    post({"jsonrpc": "2.0", "method": "notifications/initialized"})

def main():
    addrs_file, out_path = sys.argv[1], sys.argv[2]
    start = int(sys.argv[3]) if len(sys.argv) > 3 else 0
    chunk = int(sys.argv[4]) if len(sys.argv) > 4 else 150
    addrs = [l.strip() for l in open(addrs_file) if l.strip()]
    init()
    done = 0
    mode = "a" if start else "w"
    with open(out_path, mode) as fh:
        i = start
        while i < len(addrs):
            part = addrs[i:i+chunk]
            try:
                texts = call("export_funcs", {"addrs": part, "format": "json"})
                n = 0
                for t in texts:
                    try:
                        d = json.loads(t)
                    except Exception:
                        continue
                    for f in d.get("functions", []):
                        fh.write(json.dumps({"addr": f.get("addr"), "name": f.get("name"),
                                             "prototype": f.get("prototype"), "size": f.get("size"),
                                             "asm": f.get("asm", ""), "comments": f.get("comments", {})}) + "\n")
                        n += 1
                done += n
                if n < len(part):
                    print(f"WARN chunk@{i}: got {n}/{len(part)}", flush=True)
            except Exception as e:
                print(f"ERR chunk@{i}: {e}", flush=True)
                for a in part:
                    fh.write(json.dumps({"addr": a, "error": str(e)[:200]}) + "\n")
            fh.flush()
            i += chunk
            if (i // chunk) % 5 == 0:
                print(f"[{i}/{len(addrs)}] done={done}", flush=True)
    print("DONE", done)

if __name__ == "__main__":
    main()
