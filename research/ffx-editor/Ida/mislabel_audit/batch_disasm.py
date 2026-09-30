#!/usr/bin/env python3
"""Batch disasm fetcher — keeps ONE MCP session, sequential tools/call.

Usage: batch_disasm.py <addrs-file> <out.jsonl> [start-idx]
Each input line: one hex addr (0x...). Appends JSONL: {addr,name,ret,args,callees[],ninstr,size}.
"""
import json, os, sys, urllib.request, time

URL = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp")
HDRS = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream"}
_sess = None
_reqid = 0

def post(payload):
    global _sess, _reqid
    h = dict(HDRS)
    if _sess:
        h["mcp-session-id"] = _sess
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(), headers=h)
    for attempt in range(4):
        try:
            resp = urllib.request.urlopen(req, timeout=180)
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
        except Exception as e:
            if attempt == 3:
                raise
            time.sleep(1.5 * (attempt + 1))

def call(tool, args):
    global _reqid
    _reqid += 1
    body = post({"jsonrpc": "2.0", "id": _reqid, "method": "tools/call",
                 "params": {"name": tool, "arguments": args}})
    d = json.loads(body)
    res = d.get("result", d)
    if isinstance(res, dict) and "content" in res:
        txt = "\n".join(c.get("text", "") for c in res["content"] if c.get("type") == "text")
        try:
            return json.loads(txt)
        except Exception:
            return {"_raw": txt}
    return res

def init():
    post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
          "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                     "clientInfo": {"name": "mislabel-audit", "version": "1.0"}}})
    post({"jsonrpc": "2.0", "method": "notifications/initialized"})

def summarize(addr, d):
    asm = d.get("asm", {}) if isinstance(d, dict) else {}
    callees = []
    stores = 0
    tail_jmp = None
    ninstr = 0
    for l in asm.get("lines", []):
        ins = l.get("instruction", "")
        ninstr += 1
        if ins.startswith("call ") or ins.startswith("jmp "):
            tgt = ins.split(None, 1)[1]
            tgt = tgt.split(";")[0].strip()
            callees.append(("jmp" if ins.startswith("jmp") else "call", tgt))
            if ins.startswith("jmp") and tgt.startswith(("FFX_", "sub_", "j_", "Phyre", "__", "ds:")):
                tail_jmp = tgt
        if ins.startswith("mov [") or ins.startswith("mov dword ptr") or ", [" in ins:
            stores += 1
    return {"addr": addr, "name": asm.get("name"), "ret": asm.get("return_type"),
            "args": [a.get("type", "?") + " " + a.get("name", "?") for a in asm.get("arguments", [])],
            "callees": callees, "ninstr": ninstr, "stores": stores,
            "tail_jmp": tail_jmp, "size": d.get("instruction_count")}

def main():
    addrs_file, out_path = sys.argv[1], sys.argv[2]
    start = int(sys.argv[3]) if len(sys.argv) > 3 else 0
    addrs = [l.strip() for l in open(addrs_file) if l.strip()]
    init()
    done = 0
    mode = "a" if start else "w"
    with open(out_path, mode) as fh:
        for i, a in enumerate(addrs):
            if i < start:
                continue
            try:
                d = call("disasm", {"addr": a})
                rec = summarize(a, d)
            except Exception as e:
                rec = {"addr": a, "error": str(e)[:200]}
            fh.write(json.dumps(rec) + "\n")
            fh.flush()
            done += 1
            if done % 200 == 0:
                print(f"[{done}/{len(addrs)-start}] last={a}", flush=True)
    print("DONE", done)

if __name__ == "__main__":
    main()
