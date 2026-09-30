#!/usr/bin/env python3
"""eC! node-chain walker for FFX PS2 mapout.vpa files (M-F11 decode, 2026-09-15).

Runtime model proven by IDA decompile of FFX_GS_ProcessDmaPacketData @0x90F900
(PC FFX.exe, canonical db) + FFX_GS_ProcessDmaPacketIf272 @0x90F8E0:

  - MAP1 header slot +0x14 -> eC! packet base (btlmap: always 0x80).
  - eC!+0x00 magic 0x00214365 ("eC!"), eC!+0x04 == 0x110 (272, gate value),
    eC!+0x0C == node count (loop runs exactly count iterations;
    `if (lpBuffer_1[3]-- == 1) return;`).
  - Node cursor starts at eC!+0x40. Each node:
        node+0x00 u32 type (switch in the consumer)
        node+0x04 u32 size  (bytes after the 64-byte header)
        node+0x08..0x3F   reserved (observed all-zero)
        node+0x40..       payload[size]
    next_node = node + 0x40 + size.
  - Node types seen in the consumer switch:
        0 -> sprite/object init: InitSpriteStruct + ReadDmaPacketHeader(64B)
             + TransformPosition + ApplySkinning(u16@hdr+0x30 count)
        1 -> sprite coord batch: ReadSpriteCoords(64B) then
             count = (size-64)/16 quadwords of inline VIF/GS data;
             payload+0x0C must equal count (hard abort on mismatch)
        2 -> texture DMA packet (FFX_GS_ProcessTextureDmaPacket)
        3 -> palette upload (sub-type node+0x24 in {2,3,4})
        4 -> scene lighting state (RGBA colors + fog floats)
        5 -> pointer-table store (indexed by node+0x24 when node+0x20)
        6 -> per-object-index slot table (index=*payload, 456B slots)
        7 -> matrix copy (FFX_GS_CopyMatrixData)
        8 -> pointer-table store #2 (entries 32B, count = size>>5)
"""
import struct, sys, os, glob, json, collections

def walk_ec(d, base, limit):
    """Walk eC! nodes. Returns (header dict, list of node dicts)."""
    if base + 0x110 > len(d):
        return None, []
    if struct.unpack_from("<I", d, base)[0] != 0x00214365:
        return None, []
    hdr = {
        "base": base,
        "mark": struct.unpack_from("<I", d, base + 4)[0],   # 0x110 expected
        "f08": struct.unpack_from("<I", d, base + 8)[0],
        "count": struct.unpack_from("<I", d, base + 0xC)[0],
        "f10": struct.unpack_from("<I", d, base + 0x10)[0],
    }
    if hdr["mark"] != 0x110:
        hdr["bad_mark"] = True
    nodes = []
    cur = base + 0x40
    for _ in range(20000):
        if cur + 0x40 > len(d):
            break
        typ = struct.unpack_from("<I", d, cur)[0]
        size = struct.unpack_from("<I", d, cur + 4)[0]
        nodes.append({"off": cur, "type": typ, "size": size})
        nxt = cur + 0x40 + size
        if nxt <= cur or nxt > limit:
            break
        cur = nxt
        if len(nodes) >= hdr["count"] + 2:
            break
    return hdr, nodes


def scan_file(path):
    d = open(path, "rb").read()
    if len(d) < 0x84 or d[:4] != b"MAP1":
        return {"file": path, "size": len(d), "map1": False}
    out = {"file": path, "size": len(d)}
    # locate eC! : map files use MAP1 slot +0x14; btlmap has it at 0x80.
    slot14 = struct.unpack_from("<I", d, 0x14)[0]
    cands = []
    if 0x80 <= slot14 < len(d) and struct.unpack_from("<I", d, slot14)[0] == 0x00214365:
        cands.append(slot14)
    if len(d) > 0x84 and struct.unpack_from("<I", d, 0x80)[0] == 0x00214365:
        cands.append(0x80)
    # fallback: brute scan for eC! magic near 0x80 if slots empty
    if not cands:
        o = d.find(b"eC!\x00", 0x80, min(len(d), 0x400000))
        if o > 0:
            cands.append(o)
    out["ec_off"] = cands
    if not cands:
        return out
    base = cands[0]
    # section end = next MAP1 slot > base (or file size)
    slots = [struct.unpack_from("<I", d, i)[0] for i in range(0x10, 0x44, 4)]
    after = [s for s in slots if base < s <= len(d)]
    lim = min(after) if after else len(d)
    hdr, nodes = walk_ec(d, base, lim)
    out["hdr"] = hdr
    out["limit"] = lim
    out["ec_span"] = lim - base
    out["nodes"] = len(nodes)
    out["types"] = dict(collections.Counter(n["type"] for n in nodes))
    # type-1 detail
    t1 = [n for n in nodes if n["type"] == 1]
    t1ok = 0
    mid = 0
    nz = 0
    for n in t1:
        pl = n["off"] + 0x40
        if pl + 0x40 > len(d):
            continue
        cnt = struct.unpack_from("<I", d, pl + 0xC)[0]
        calc = (n["size"] - 64) // 16
        if cnt == calc:
            t1ok += 1
        a = struct.unpack_from("<4f", d, pl + 0x10)
        b = struct.unpack_from("<4f", d, pl + 0x20)
        c = struct.unpack_from("<4f", d, pl + 0x30)
        err = max(abs((b[i] + c[i]) / 2 - a[i]) for i in range(3))
        if err < 1e-4:
            mid += 1
        # payload fill (quadwords after 64B coord header)
        qstart, qend = pl + 0x40, n["off"] + 0x40 + n["size"]
        nz += sum(1 for i in range(qstart, min(qend, len(d))) if d[i])
    out["t1"] = {"n": len(t1), "count_ok": t1ok, "midpoint_ok": mid, "payload_nz_bytes": nz}
    return out


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc"
    outdir = sys.argv[2] if len(sys.argv) > 2 else "work/_mf11/census"
    os.makedirs(outdir, exist_ok=True)
    files = sorted(glob.glob(os.path.join(root, "**", "mapout.vpa"), recursive=True))
    rep = []
    for f in files:
        try:
            rep.append(scan_file(f))
        except Exception as e:
            rep.append({"file": f, "error": repr(e)})
    with open(os.path.join(outdir, "ec_census.json"), "w") as fh:
        json.dump(rep, fh, indent=1)
    # summary
    withEc = [r for r in rep if r.get("hdr")]
    print(f"files: {len(rep)}; with eC!: {len(withEc)}")
    agg = collections.Counter()
    nodefiles = 0
    for r in withEc:
        if r.get("nodes"):
            nodefiles += 1
        for t, c in r.get("types", {}).items():
            agg[t] += c
    print("node-type totals across files:", dict(agg))
    print("files with nodes:", nodefiles)
    markbad = [r["file"] for r in withEc if r["hdr"].get("bad_mark")]
    print("files where eC+4 != 0x110:", len(markbad), markbad[:10])
    # count mismatch audit
    mism = []
    for r in withEc:
        if r.get("nodes") and r["nodes"] != r["hdr"]["count"]:
            mism.append((r["file"], r["nodes"], r["hdr"]["count"]))
    print("walk-count != hdr count:", len(mism))
    for m in mism[:15]:
        print("   ", m)


if __name__ == "__main__":
    main()
