#!/usr/bin/env python3
"""Profile all *_structural functions: callers, callees, strings, prototype."""
import sys, json, re, urllib.request, os

sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_lift'


def call(tool, args, sess):
    _, body = post({"jsonrpc": "2.0", "id": 99, "method": "tools/call",
                    "params": {"name": tool, "arguments": args}}, sess)
    m = re.search(r'(https?://\S+/output/\S+\.json)', body)
    if m:
        body = urllib.request.urlopen(m.group(1), timeout=180).read().decode()
    d = json.loads(body)
    res = d.get("result", d)
    if isinstance(res, dict) and "content" in res:
        txt = "\n".join(c["text"] for c in res["content"] if c.get("type") == "text")
        m = re.search(r'(https?://\S+/output/\S+\.json)', txt)
        if m:
            txt = urllib.request.urlopen(m.group(1), timeout=180).read().decode()
        try:
            res = json.loads(txt)
        except Exception:
            return {"_raw": txt}
    return res


def unwrap(res):
    if isinstance(res, list):
        res = res[0] if res else {}
    if isinstance(res, dict):
        return res.get("data") or [], res.get("next_offset")
    return [], None


def main():
    sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                    "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                               "clientInfo": {"name": "structural-lift", "version": "1"}}})
    post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)

    fout = open(f"{OUT}/profiles.jsonl", "w")
    offset = 0
    PAGE = 200
    total = 0
    while True:
        r = call("func_profile", {"queries": {"filter": "*_structural",
                                              "offset": offset, "count": PAGE,
                                              "sort_by": "name",
                                              "include_lists": True,
                                              "max_items": 25,
                                              "include_prototype": True}}, sess)
        items, next_off = unwrap(r)
        for it in items:
            fout.write(json.dumps(it) + "\n")
        total += len(items)
        print(f"offset={offset} got={len(items)} total={total} next={next_off}", flush=True)
        if not items or next_off is None:
            break
        offset = next_off
    fout.close()
    print("DONE", total)


if __name__ == "__main__":
    main()
