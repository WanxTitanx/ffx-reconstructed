#!/usr/bin/env python3
"""structural-r2 retry: fresh census of *_structural; diff vs pre-crash census."""
import sys, json, re, collections, urllib.request
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

def unwrap(res):
    if isinstance(res, list):
        res = res[0] if res else {}
    if isinstance(res, dict):
        data = res.get("data") or res.get("functions") or res.get("items") or res.get("results") or []
        return data, res.get("next_offset")
    return [], None

def main():
    sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                    "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                               "clientInfo": {"name": "structural-r2-re", "version": "1"}}})
    post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)
    all_funcs, offset = [], 0
    while True:
        r = call("func_query", {"queries": {"name_regex": "_structural$",
                                            "offset": offset, "count": 1000,
                                            "sort_by": "name"}}, sess)
        items, next_off = unwrap(r)
        all_funcs.extend(items)
        if not items or next_off is None:
            break
        offset = next_off
    json.dump(all_funcs, open(f"{OUT}/structural_funcs_now.json", "w"), indent=1)

    old = {f["addr"]: f["name"] for f in json.load(open(f"{OUT}/structural_funcs.json"))}
    now = {f["addr"]: f["name"] for f in all_funcs}
    gone = sorted(set(old) - set(now))
    print(f"then={len(old)} now={len(now)} gone={len(gone)}")
    for a in gone:
        print("  RENAMED-AWAY", a, old[a])
    bymod = collections.Counter()
    for fn in all_funcs:
        base = re.sub(r"_structural$", "", fn.get("name",""))
        base = re.sub(r"^DEAD_", "", base)
        m = re.match(r"^((?:FFX|Phyre|FFXPE)_[A-Za-z0-9]+|[A-Za-z0-9]+)", base)
        bymod[m.group(1) if m else base.split("_")[0]] += 1
    with open(f"{OUT}/census_now.txt", "w") as f:
        for mod, n in bymod.most_common():
            f.write(f"{n:6d}  {mod}\n")
        f.write(f"\nTOTAL {len(all_funcs)}\n")

if __name__ == "__main__":
    main()
