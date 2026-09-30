#!/usr/bin/env python3
"""Census of *_structural function names in ffxoficial.exe.i64 via ida MCP."""
import sys, json, re, collections, urllib.request, os

sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_lift'
BASE = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp").rsplit('/', 1)[0]


def call(tool, args, sess):
    _, body = post({"jsonrpc": "2.0", "id": 99, "method": "tools/call",
                    "params": {"name": tool, "arguments": args}}, sess)
    # body may itself be a truncated notice containing an output URL
    m = re.search(r'(https?://\S+/output/\S+\.json)', body)
    if m:
        body = urllib.request.urlopen(m.group(1), timeout=120).read().decode()
    d = json.loads(body)
    res = d.get("result", d)
    # res may be MCP content envelope
    if isinstance(res, dict) and "content" in res:
        txt = "\n".join(c["text"] for c in res["content"] if c.get("type") == "text")
        m = re.search(r'(https?://\S+/output/\S+\.json)', txt)
        if m:
            txt = urllib.request.urlopen(m.group(1), timeout=120).read().decode()
        try:
            res = json.loads(txt)
        except Exception:
            return {"_raw": txt}
    return res


def unwrap(res):
    """Normalize tool result -> (items, next_offset)."""
    if isinstance(res, list):
        res = res[0] if res else {}
    if isinstance(res, dict):
        data = res.get("data") or res.get("functions") or res.get("items") or res.get("results") or []
        return data, res.get("next_offset")
    return [], None


def main():
    sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                    "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                               "clientInfo": {"name": "structural-lift", "version": "1"}}})
    post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)

    all_funcs = []
    offset = 0
    PAGE = 1000
    while True:
        r = call("func_query", {"queries": {"name_regex": "_structural$",
                                            "offset": offset, "count": PAGE,
                                            "sort_by": "name"}}, sess)
        items, next_off = unwrap(r)
        all_funcs.extend(items)
        print(f"page offset={offset} got={len(items)} total={len(all_funcs)} next={next_off}")
        if not items or next_off is None:
            break
        offset = next_off

    with open(f"{OUT}/structural_funcs.json", "w") as f:
        json.dump(all_funcs, f, indent=1)

    bymod = collections.Counter()
    for fn in all_funcs:
        name = fn.get("name", "")
        base = re.sub(r"_structural$", "", name)
        base = re.sub(r"^DEAD_", "", base)
        m = re.match(r"^((?:FFX|Phyre|FFXPE)_[A-Za-z0-9]+|[A-Za-z0-9]+)", base)
        mod = m.group(1) if m else base.split("_")[0]
        bymod[mod] += 1

    with open(f"{OUT}/census_by_module.txt", "w") as f:
        for mod, n in bymod.most_common():
            f.write(f"{n:6d}  {mod}\n")
        f.write(f"\nTOTAL {len(all_funcs)}\n")

    print("\n=== CENSUS BY MODULE ===")
    for mod, n in bymod.most_common():
        print(f"{n:6d}  {mod}")
    print(f"\nTOTAL: {len(all_funcs)}")


if __name__ == "__main__":
    main()
