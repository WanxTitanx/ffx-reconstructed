#!/usr/bin/env python3
"""structural-r2: batch-decompile target funcs into decompiles_r2.jsonl."""
import sys, json, re, urllib.request, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post
OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_r2'

def call(tool, args, sess):
    _, body = post({"jsonrpc":"2.0","id":99,"method":"tools/call",
                    "params":{"name":tool,"arguments":args}}, sess)
    m = re.search(r'(https?://\S+/output/\S+\.json)', body)
    if m: body = urllib.request.urlopen(m.group(1), timeout=300).read().decode()
    d = json.loads(body); res = d.get("result", d)
    if isinstance(res, dict) and "content" in res:
        txt = "\n".join(c["text"] for c in res["content"] if c.get("type")=="text")
        m = re.search(r'(https?://\S+/output/\S+\.json)', txt)
        if m: txt = urllib.request.urlopen(m.group(1), timeout=300).read().decode()
        try: res = json.loads(txt)
        except Exception: return {"_raw": txt}
    return res

def main():
    sess,_ = post({"jsonrpc":"2.0","id":1,"method":"initialize",
                   "params":{"protocolVersion":"2025-03-26","capabilities":{},
                             "clientInfo":{"name":"r2-dec","version":"1"}}})
    post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
    targets = json.load(open(f"{OUT}/decompile_targets.json"))
    out = open(f"{OUT}/decompiles_r2.jsonl","w")
    for i, a in enumerate(targets):
        try:
            res = call("decompile", {"addr": a}, sess)
            if isinstance(res, list): res = res[0] if res else {}
            code = res.get("code") if isinstance(res, dict) else str(res)
        except Exception as e:
            code = f"// DECOMPILE_ERROR {e}"
        out.write(json.dumps({"addr": a, "code": code})+"\n")
        if i % 20 == 0: print(i, a, flush=True)
    out.close(); print("DONE", len(targets))
if __name__ == "__main__":
    main()
