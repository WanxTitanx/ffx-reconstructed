#!/usr/bin/env python3
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
                             "clientInfo":{"name":"r2-s2","version":"1"}}})
    post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
    sf = {int(f['addr'],16): f['name'] for f in json.load(open(f"{OUT}/structural_funcs_now.json"))}
    for tag, base, size in [
        ("magic_host_ctx_full", 0xC64CE8, 0x1000),
        ("save_state_tbl", 0xC59FC0, 0x100),
        ("ui_cb_tbl", 0xC5B280, 0x120),
        ("mseq_tbl", 0xC49780, 0x80),
        ("aifunc_tbl", 0xC53840, 0x80),
        ("postproc_tbl", 0xC492C8, 0x100),
        ("sideop_tbl", 0xC48E78, 0x50),
    ]:
        raw = get_bytes(base, size, sess)
        open(f"{OUT}/{tag}.bin","wb").write(raw)
        print(f"== {tag} @ {hex(base)}")
        for i in range(0, size-3, 4):
            v = struct.unpack_from("<I", raw, i)[0]
            mark = " <<<" if v in sf else ""
            if v and (v in sf or 0x401000 <= v < 0xC00000):
                nm = sf.get(v, '')
                print(f"   +{i:04x} -> {v:#x} {nm}{mark}")
if __name__ == "__main__":
    main()
