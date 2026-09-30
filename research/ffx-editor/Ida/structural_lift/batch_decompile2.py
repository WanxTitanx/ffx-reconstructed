#!/usr/bin/env python3
"""Batch-decompile candidate *_structural funcs into JSONL for evidence review."""
import sys, json, re, urllib.request

sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_lift'

TARGETS = ["0x864180","0x6ecd80","0x7e1e90","0x7e2160","0x837790","0x8377b0","0x840560","0x840dd0","0x8715f0","0x86e920","0x86eb70","0x86e350","0x7c04c0","0x83c610","0x65ee30","0x9055c0"]

def call(tool, args, sess):
    _, body = post({"jsonrpc": "2.0", "id": 99, "method": "tools/call",
                    "params": {"name": tool, "arguments": args}}, sess)
    m = re.search(r'(https?://\S+/output/\S+\.json)', body)
    if m:
        body = urllib.request.urlopen(m.group(1), timeout=180).read().decode()
    d = json.loads(body)
    res = d.get("result", d)
    if isinstance(res, dict) and "content" in res:
        return "\n".join(c["text"] for c in res["content"] if c.get("type") == "text")
    return json.dumps(res)

def main():
    sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                    "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                               "clientInfo": {"name": "structural-lift", "version": "1"}}})
    post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)
    with open(f"{OUT}/decompiles_r2.jsonl", "w") as f:
        for a in TARGETS:
            try:
                f.write(call("decompile", {"addr": a, "include_addresses": False}, sess) + "\n")
            except Exception as e:
                f.write(json.dumps({"addr": a, "error": str(e)}) + "\n")
            print("done", a, flush=True)

if __name__ == "__main__":
    main()
