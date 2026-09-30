#!/usr/bin/env python3
"""structural-r2: dump MagicCoreOp table @0xC48EC8, classify the 73 names."""
import sys, json, re, struct, urllib.request
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
                             "clientInfo":{"name":"r2-mco","version":"1"}}})
    post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
    BASE = 0xC48EC8; N = 256
    raw = get_bytes(BASE, N*4, sess)
    open(f"{OUT}/magiccoreop_table.bin","wb").write(raw)
    ptr2idx = {}
    filled=[]
    for i in range(N):
        v = struct.unpack_from("<I", raw, i*4)[0]
        if v:
            ptr2idx.setdefault(v, []).append(i)
            filled.append(i)
    print("filled slots:", len(filled), "max idx:", hex(max(filled)) if filled else '-')
    # what's beyond? try next 256
    raw2 = get_bytes(BASE+N*4, 1024, sess)
    extra=[i for i in range(256) if struct.unpack_from("<I",raw2,i*4)[0]]
    print("extra filled beyond 256:", len(extra), "first:", extra[:8])

    grp = json.load(open(f"{OUT}/grp_FFX_MagicCoreOp.json"))
    allf = {f['addr']: f['name'] for f in json.load(open(f"{OUT}/structural_funcs_now.json"))}
    NAME_RE = re.compile(r'^FFX_MagicCoreOp_([0-9A-F]{2})(?:_[0-9A-F]{2})?_([A-Za-z0-9]+)_structural$')
    ver, mis, notin, odd = [], [], [], []
    for f in grp:
        a = int(f['addr'],16); nm = f['name']
        m = NAME_RE.match(nm)
        claimed = int(m.group(1),16) if m else None
        idxs = ptr2idx.get(a, [])
        if not idxs:
            notin.append((f['addr'], nm, claimed))
        elif claimed is not None and claimed in idxs:
            ver.append((f['addr'], nm, claimed, idxs))
        else:
            mis.append((f['addr'], nm, claimed, idxs))
    print(f"\nVERIFIED {len(ver)}  MISLABEL {len(mis)}  NOT_IN_TABLE {len(notin)}")
    for a,n,c,i in mis: print("  MISLABEL", a, n, "claimed",hex(c) if c is not None else '?', "actual",[hex(x) for x in i])
    for a,n,c in notin: print("  NOTIN", a, n, "claimed",hex(c) if c is not None else '?')
    # other structural funcs sitting in the table
    others = [(hex(a),allf[hex(a)] if hex(a) in allf else None, idxs)
              for a,idxs in ptr2idx.items() if hex(a) in allf and not allf[hex(a)].startswith('FFX_MagicCoreOp_')]
    print("\nnon-MagicCoreOp *_structural in table:")
    for a,n,i in sorted(others, key=lambda t:t[2][0]):
        print(f"  slot {[hex(x) for x in i]} -> {a} {n}")
    # unknown ptrs (not structural-named) — for gap analysis
    json.dump({hex(k):v for k,v in ptr2idx.items()}, open(f"{OUT}/magiccoreop_ptr2idx.json","w"), indent=0)
if __name__ == "__main__":
    main()
