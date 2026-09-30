#!/usr/bin/env python3
"""structural-r2: dump regions, map any *_structural ptrs into slots."""
import sys, json, re, struct, urllib.request
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

def get_bytes(addr, size, sess):
    res = call("get_bytes", {"regions": {"addr": hex(addr), "size": size}}, sess)
    if isinstance(res, list): res = res[0]
    data = res.get("data") if isinstance(res, dict) else None
    if data is None: return b"\x00"*size
    if isinstance(data, str): return bytes(int(t,16) for t in data.split())
    return bytes(data)

def main():
    sess,_ = post({"jsonrpc":"2.0","id":1,"method":"initialize",
                   "params":{"protocolVersion":"2025-03-26","capabilities":{},
                             "clientInfo":{"name":"r2-scan","version":"1"}}})
    post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
    sf = {int(f['addr'],16): f['name'] for f in json.load(open(f"{OUT}/structural_funcs_now.json"))}
    regions = [
        ("magic_host_ctx", 0xC64CE8, 0x400),
        ("post_magiccoreop", 0xC492C8, 0x800),
        ("soundcmd_table", 0xC3A200, 0x800),
        ("field_aifunc", 0xC5387C, 0x200),
        ("field_sceneblk", 0xC53354, 0x200),
    ]
    out = {}
    for tag, base, size in regions:
        raw = get_bytes(base, size, sess)
        open(f"{OUT}/{tag}.bin","wb").write(raw)
        hits=[]
        for i in range(0, size-3, 4):
            v = struct.unpack_from("<I", raw, i)[0]
            if v in sf:
                hits.append({"off": i, "idx": i//4, "addr": hex(v), "name": sf[v]})
        out[tag] = {"base": hex(base), "hits": hits}
        print(f"== {tag} @ {hex(base)} hits={len(hits)}")
        for h in hits:
            print(f"   +{h['off']:04x} (idx {h['idx']:#04x}) {h['addr']} {h['name']}")
    json.dump(out, open(f"{OUT}/region_hits.json","w"), indent=1)
if __name__ == "__main__":
    main()
