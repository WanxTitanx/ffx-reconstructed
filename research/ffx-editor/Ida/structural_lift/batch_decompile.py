#!/usr/bin/env python3
"""Batch-decompile candidate *_structural funcs into JSONL for evidence review."""
import sys, json, re, urllib.request

sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_lift'

TARGETS = [
 "0x575410","0x86a920","0x86a7c0","0x6ed4a0","0x630670","0x86e380","0x7e82c0",
 "0x79a4c0","0x8725f0","0x711260","0x7e78b0","0x640f60","0x785440","0x7e6610",
 "0x7e7f20","0x820640","0x7110b0","0x7e9760","0x6fa3a0","0x79f010","0x888e30",
 "0x7e9670","0x71b980","0x9055c0","0x865390","0x65ee30","0x86e990","0x7e9940",
 "0x7e7de0","0x780d80","0x7e2050","0x640590","0x6f77e0","0x869de0","0x836d10",
 "0x7b4b80","0x783730","0x783e30","0x890ee0","0x79cd10","0x837730","0x7e3d80",
 "0x8aafe0","0x7dabf0","0x7d9870","0x7d3630","0x820970","0xa182f0","0x6a3ca0",
 "0x6a4ba0","0x6e84d0","0x6b45f0","0xaa3640","0xa6cfb0","0x6429a0","0x643130",
 "0x7cf8a0","0x7cf820","0x76f960","0x770540","0x6f4a40","0x654fd0","0x6e8040",
 "0x7a7b50","0x857520","0x870cd0","0x85b120","0x860aa0","0x860740","0x8573c0",
 "0x8671d0","0x867510","0x867370",
]

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
    with open(f"{OUT}/decompiles.jsonl", "w") as f:
        for a in TARGETS:
            try:
                f.write(call("decompile", {"addr": a, "include_addresses": False}, sess) + "\n")
            except Exception as e:
                f.write(json.dumps({"addr": a, "error": str(e)}) + "\n")
            print("done", a, flush=True)

if __name__ == "__main__":
    main()
