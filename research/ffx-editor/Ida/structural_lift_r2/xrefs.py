#!/usr/bin/env python3
"""structural-r2: fetch xrefs_to for the three frontier groups; find table refs."""
import sys, json, re, urllib.request

sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_r2'


def call(tool, args, sess):
    _, body = post({"jsonrpc": "2.0", "id": 99, "method": "tools/call",
                    "params": {"name": tool, "arguments": args}}, sess)
    m = re.search(r'(https?://\S+/output/\S+\.json)', body)
    if m:
        body = urllib.request.urlopen(m.group(1), timeout=300).read().decode()
    d = json.loads(body)
    res = d.get("result", d)
    if isinstance(res, dict) and "content" in res:
        txt = "\n".join(c["text"] for c in res["content"] if c.get("type") == "text")
        m = re.search(r'(https?://\S+/output/\S+\.json)', txt)
        if m:
            txt = urllib.request.urlopen(m.group(1), timeout=300).read().decode()
        try:
            res = json.loads(txt)
        except Exception:
            return {"_raw": txt}
    return res


def main():
    sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                    "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                               "clientInfo": {"name": "structural-r2", "version": "1"}}})
    post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)

    targets = []
    for p in ("FFX_MagicCoreOp", "FFX_Field", "FFX_SoundCmd"):
        targets += json.load(open(f"{OUT}/grp_{p}.json"))
    print("targets:", len(targets))

    out = open(f"{OUT}/xrefs.jsonl", "w")
    BATCH = 20
    for i in range(0, len(targets), BATCH):
        chunk = targets[i:i+BATCH]
        addrs = [f["addr"] for f in chunk]
        res = call("xrefs_to", {"addrs": addrs}, sess)
        items = res if isinstance(res, list) else res.get("data", res) if isinstance(res, dict) else res
        out.write(json.dumps({"batch": i, "addrs": addrs, "res": items}) + "\n")
        print(f"batch {i}: {len(addrs)} addrs -> {type(items).__name__}", flush=True)
    out.close()
    print("DONE")


if __name__ == "__main__":
    main()
