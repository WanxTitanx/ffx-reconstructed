#!/usr/bin/env python3
"""structural-r2: census all *_structural + xrefs for target prefixes."""
import sys, json, re, collections, urllib.request, os

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
                               "clientInfo": {"name": "structural-r2", "version": "1"}}})
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
        print(f"page offset={offset} got={len(items)} total={len(all_funcs)} next={next_off}", flush=True)
        if not items or next_off is None:
            break
        offset = next_off

    json.dump(all_funcs, open(f"{OUT}/structural_funcs.json", "w"), indent=1)

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
    print("\n=== CENSUS ===")
    for mod, n in bymod.most_common():
        print(f"{n:6d}  {mod}")
    print("TOTAL", len(all_funcs))

    # dump the three frontier groups with addrs
    for pref in ("FFX_MagicCoreOp_", "FFX_Field_", "FFX_SoundCmd_"):
        grp = [f for f in all_funcs if f["name"].startswith(pref)]
        json.dump(grp, open(f"{OUT}/grp_{pref.strip('_')}.json", "w"), indent=1)
        print(pref, len(grp))


if __name__ == "__main__":
    main()
