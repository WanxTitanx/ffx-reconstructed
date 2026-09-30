#!/usr/bin/env python3
# ── MODELS-UNLOCK chr census: valida os invariantes do header de seções ───────
# Layout (PROVEN por decompile, lane 2026-09-19 — ver FFX_CHR_SONDA_2026-09-19):
#   FFX_Chr_RelocatePtrsInWorkBuffer@0x825770: delta = base − u32@0 (anchor=0
#   no disco); u32@4 = sectionCount; seções a partir de +0x10:
#     sec[i] = {u32 offset @+0x10+8i, u32 count @+0x14+8i}
#   FFX_Chr_InitFromFfxmapFile@0x825F60 consome: sec[0]=esqueleto (sklPtr),
#   sec[1]=mesh buffer SG (+count=meshCount), sec[4]=offset-array,
#   sec[9]=params (primeiro u32 = gate de tamanho 0x1624=5668),
#   sec[10]=bloco-cauda. SgMem_RelocateBufferPointers@0x83CBA0: buffer SG com
#   anchor próprio, version gates 0x1029/0x1126, tabela 8B em +24.
# Corpus (READ-ONLY): jppc/chr/{mon,npc,obj,pc,skl,sum,wep}/**/mdl/*.chr
import struct, os, sys, collections

def u16(d, o): return struct.unpack_from("<H", d, o)[0]
def u32(d, o): return struct.unpack_from("<I", d, o)[0]

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc"

def dissect(path):
    r = {"cls": None, "nsec": 0, "secs": [], "sg": None}
    d = open(path, "rb").read()
    if len(d) < 0x18:
        r["cls"] = "tiny"; return r
    if u32(d, 0) != 0:
        r["cls"] = "ANCHOR_NZ"; return r
    nsec = u32(d, 4)
    r["nsec"] = nsec
    hdr_end = 0x10 + 8 * nsec
    if hdr_end > len(d):
        r["cls"] = "HDR_OOB"; return r
    if nsec < 8 or nsec > 12:
        r["cls"] = "NSEC_ODD"; return r
    last_end = hdr_end
    for i in range(nsec):
        off, cnt = u32(d, 0x10 + 8 * i), u32(d, 0x14 + 8 * i)
        r["secs"].append((off, cnt))
        if off:
            if off < hdr_end or off >= len(d):
                r["cls"] = f"SEC{i}_OOB"; return r
            # NOTA: seções NÃO são ordenadas por offset — são slots semânticos
            # (m001: sec[2]=0x70 < sec[0]=0x4D0); ordenação não é invariante.
    r["cls"] = "ok"
    # buffer SG (sec[1]): version gates
    off1 = r["secs"][1][0]
    if off1 and off1 + 0x24 <= len(d):
        ver = u16(d, off1 + 16)
        r["sg"] = {"ver": ver, "g1029": ver >= 0x1029, "g1126": ver >= 0x1126,
                   "anchor": u32(d, off1), "n": u16(d, off1 + 8)}
    return r

if __name__ == "__main__":
    root = sys.argv[1] if len(sys.argv) > 1 else ROOT
    files = []
    for dp, _, fns in os.walk(root):
        for fn in fns:
            if fn.lower().endswith(".chr"): files.append(os.path.join(dp, fn))
    files.sort()
    tot = collections.Counter(); nsec_dist = collections.Counter()
    sec_used = collections.Counter(); sec_cnt_nz = collections.Counter()
    sg_ver = collections.Counter(); params_gate = collections.Counter()
    fams = collections.Counter(); anomalies = []
    for p in files:
        rel = os.path.relpath(p, root)
        fam = rel.split("/")[1] if rel.startswith("chr/") else "?"
        r = dissect(p)
        tot[r["cls"]] += 1; fams[f"{fam}:{r['cls']}"] += 1
        nsec_dist[r["nsec"]] += 1
        for i, (off, cnt) in enumerate(r["secs"]):
            if off: sec_used[i] += 1
            if cnt: sec_cnt_nz[i] += 1
        if r["sg"]: sg_ver[(r["sg"]["ver"], r["sg"]["g1029"], r["sg"]["g1126"])] += 1
        # sec[9] params gate
        if r["cls"] == "ok" and len(r["secs"]) > 9 and r["secs"][9][0]:
            d = open(p, "rb").read()
            params_gate[u32(d, r["secs"][9][0])] += 1
        if r["cls"] not in ("ok",) and len(anomalies) < 10:
            anomalies.append((rel, r["cls"]))
    print(f"=== CHR CENSUS ({len(files)} arquivos) ===")
    print("classes:", dict(tot))
    print("nsec dist:", dict(nsec_dist))
    print("seções usadas (offset≠0):", dict(sorted(sec_used.items())))
    print("seções com count≠0:", dict(sorted(sec_cnt_nz.items())))
    print("SG ver (ver, ≥0x1029, ≥0x1126):", dict(sorted(sg_ver.items())[:8]))
    print("sec[9] primeiro u32 (gate params):", params_gate.most_common(5))
    if anomalies:
        print("anomalias:", anomalies)
