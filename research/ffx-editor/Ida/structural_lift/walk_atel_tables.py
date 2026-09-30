#!/usr/bin/env python3
"""Walk all ATEL funcspace tables; build ptr -> (ns, idx, slotname) map."""
import sys, json, re, struct, urllib.request

sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_lift'

TABLES = [
    (0x0, "Common",     0xC50050, 616),
    (0x1, "Math",       0xC52BE0, 30),
    (0x4, "SgEvent",    0xC88D88, 71),
    (0x5, "ChEvent",    0xC891F8, 145),
    (0x6, "Camera",     0xC43988, 138),
    (0x7, "Battle",     0xC42618, 296),
    (0x8, "Map",        0xC5DC90, 108),
    (0x9, "Mount",      0xC5D8C0, 8),    # declared 1; probe a few
    (0xB, "Movie",      0xC40E20, 160),  # physical extent observed ~0x89
    (0xC, "Debug",      0xC52DD8, 94),
    (0xD, "AbilityMap", 0xC85EB0, 8),    # declared 1; probe a few
]
SLOTS = ["CALL", "STATUS", "FLOATRET", "INTRET"]


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


def get_bytes(addr, size, sess):
    res = call("get_bytes", {"regions": {"addr": hex(addr), "size": size}}, sess)
    if isinstance(res, list):
        res = res[0]
    data = res.get("data") if isinstance(res, dict) else None
    if data is None:
        return b"\x00" * size
    if isinstance(data, str):
        return bytes(int(t, 16) for t in data.split())
    return bytes(data)


def main():
    sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                    "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                               "clientInfo": {"name": "structural-lift", "version": "1"}}})
    post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)

    ptr_map = {}   # addr -> list of (ns, idx, slot)
    tables_dump = {}
    for ns, fam, base, count in TABLES:
        raw = get_bytes(base, count * 16, sess)
        entries = []
        last_filled = -1
        for i in range(count):
            e = struct.unpack_from("<4I", raw, i * 16)
            entries.append([hex(x) for x in e])
            if any(e):
                last_filled = i
            for si, v in enumerate(e):
                if v and 0x401000 <= v < 0xC00000:  # .text range
                    ptr_map.setdefault(v, []).append((ns, i, SLOTS[si]))
        tables_dump[f"{ns:x}_{fam}"] = {"base": hex(base), "count": count,
                                        "last_filled": last_filled,
                                        "entries": entries}
        print(f"ns {ns:x} {fam:10s} base={hex(base)} count={count} last_filled={last_filled}")

    json.dump(ptr_map, open(f"{OUT}/atel_ptr_map.json", "w"), indent=0)
    json.dump(tables_dump, open(f"{OUT}/atel_tables_dump.json", "w"))
    print("total unique handler ptrs:", len(ptr_map))


if __name__ == "__main__":
    main()
