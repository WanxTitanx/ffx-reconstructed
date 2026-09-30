#!/usr/bin/env python3
# ── MODELS-UNLOCK chr round-trip v1: cobertura estrutural do container FFXMAP ──
# Modelo (FFX_CHR_SONDA_2026-09-19):
#   header {u32 anchor=0, u32 nsec, u32 f8, 0, sec[i]={u32 off, u32 cnt}}
#   sec[0]=SKL {magic 0x1521@+4, meshCount@+6, ?@+8, boneCount@+0xA, ...,
#               offsets de arquivo +0x10/+0x14/+0x1C(boneTable)...}
#   sec[1]=SG {anchor=0, n@+8, ver 0x1029/0x1126@+0x10, ...}
#   sec[9]=params (primeiro u32 = tamanho do bloco; gate runtime ≥5668)
# v1: header + section table RE-ENCODADOS; sub-headers skl/SG re-encodados
# campo a campo (raw); blocos = spans delimitados pelos offsets de seção
# ordenados (tiling) — tudo entre blocos é padding/residual inventariado.
# encode(parse(x)) == x prova o span model de cobertura.
# v4 (lane w21 2026-09-20, FFX_PHYRE_PMESH_AND_DIRECT_POSE_2026-09-20.md):
#   - descritores 12 B TAMBÉM no nível SKL — reloc do SKL 0x827610 prova
#     tabela A @skl+0x14 (countA@+8) e tabela C @skl+0x24 (countC@+0x20),
#     entradas 12 B {n u16, 0 u16, stride u32, ptr skl-rel}; só o ptr@+8 é
#     relocado (n/stride ficam crus);
#   - REGISTROS apontados pelos descritores re-encodados: stride 60 = 15
#     células 2×u16 (skin stream — 3.851+ descritores/636 arquivos no
#     corpus; strides do corpus são múltiplos de 3); strides pares em
#     células u16; ímpares raw.
import struct, os, sys, collections

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc"

def u16(d, o): return struct.unpack_from("<H", d, o)[0]
def u32(d, o): return struct.unpack_from("<I", d, o)[0]

class Fail(Exception): pass

class Spans:
    def __init__(self, size):
        self.size = size; self.buf = bytearray(size)
        self.cov = bytearray(size); self.stats = collections.Counter()
    def put(self, start, data, kind):
        end = start + len(data)
        if start < 0 or end > self.size:
            raise Fail(f"{kind} OOB [{start:#x},{end:#x})")
        if any(self.cov[start:end]):
            if self.buf[start:end] == data: return
            raise Fail(f"{kind} COLISÃO [{start:#x},{end:#x})")
        self.buf[start:end] = data
        for i in range(start, end): self.cov[i] = 1
        self.stats[kind] += len(data)

RESIDUALS = []
OVERLAP_WINDOWS = [0]

def put_desc12_records(S, d, s0, tbl_rel, count, len_d, tag):
    """Re-encode dos descritores 12B e dos registros por eles apontados.
    Layout PROVEN pelo reloc do SKL (0x827610): {n u16, 0 u16, stride u32,
    ptr u32 skl-rel}; somente o ptr@+8 é relocado.
    Janelas SOBREPOSTAS (skin partition: tabela A do m001 tem descritores
    f4=60 com n cumulativo por osso e inícios NÃO múltiplos de 60 — os
    descritores compartilham trechos do pool) degradam para o tiling em
    vez de falhar o round-trip."""
    if not (tbl_rel and count) or s0 + tbl_rel + 12*count > len_d:
        return
    for i in range(count):
        de = s0 + tbl_rel + 12*i
        n, z, stride, ptr = u16(d,de), u16(d,de+2), u32(d,de+4), u32(d,de+8)
        S.put(de, struct.pack("<HHII", n, z, stride, ptr), tag)
        if not (n and ptr and stride):
            continue
        base = s0 + ptr
        if base + stride*n > len_d:
            continue  # registro OOB: fica no tiling (mesma política v3)
        try:
            if stride == 60:
                buf = bytearray()
                for r in range(n):
                    # skin stream: 15 células de 2×u16 = 30 u16 (consumidor
                    # de draw ainda aberto; census em massa §doc v4)
                    buf += struct.pack("<30H",
                        *struct.unpack_from("<30H", d, base + 60*r))
                S.put(base, bytes(buf), "skin60")
            elif stride % 2 == 0:
                buf = bytearray()
                for r in range(n):
                    buf += struct.pack(f"<{stride//2}H",
                        *struct.unpack_from(f"<{stride//2}H", d, base + stride*r))
                S.put(base, bytes(buf), "descrec16")
            else:
                for r in range(n):
                    S.put(base + stride*r,
                          d[base+stride*r : base+stride*r+stride], "descrec8")
        except Fail:
            OVERLAP_WINDOWS[0] += 1  # janela compartilhada: tiling cobre

def roundtrip(path):
    d = open(path, "rb").read()
    if len(d) < 0x18: raise Fail("tiny")
    anchor, nsec, f8, fC = u32(d,0), u32(d,4), u32(d,8), u32(d,0xC)
    if anchor != 0: raise Fail(f"anchor={anchor:#x}≠0")
    if fC != 0: raise Fail(f"+0xC={fC:#x}≠0")
    if not 8 <= nsec <= 12: raise Fail(f"nsec={nsec}")
    hdr_end = 0x10 + 8*nsec
    if hdr_end > len(d): raise Fail("header OOB")
    S = Spans(len(d))
    S.put(0, struct.pack("<IIII", anchor, nsec, f8, fC), "hdr_core")
    secs = []
    for i in range(nsec):
        off, cnt = u32(d, 0x10+8*i), u32(d, 0x14+8*i)
        if off and not (hdr_end <= off < len(d)):
            raise Fail(f"sec[{i}] off=0x{off:X} OOB")
        secs.append((off, cnt))
        S.put(0x10+8*i, struct.pack("<II", off, cnt), "sectbl")
    # sub-header SKL (sec[0]) — re-encode campo a campo (raw), 0x34 B
    s0 = secs[0][0]
    if s0:
        S.put(s0, struct.pack("<IHHHHHHIIIIII",
            u32(d,s0), u16(d,s0+4), u16(d,s0+6), u16(d,s0+8), u16(d,s0+0xA),
            u16(d,s0+0xC), u16(d,s0+0xE), u32(d,s0+0x10), u32(d,s0+0x14),
            u32(d,s0+0x18), u32(d,s0+0x1C), u32(d,s0+0x20), u32(d,s0+0x24)),
            "skl_hdr")
        # bones: skl+0x1C é offset RELATIVO AO BLOCO skl (invariante PROVEN
        # 862/862: 858 rigs com 1-4 raízes + 4 rigs planos m257-262); entry
        # 20 B = 10×i16 {parentIdx, rotXYZ(centésimos de grau), transXYZ
        # (/1000), scaleXYZ(/4096)} — walk do AllocateRigArraysAndInitPose
        nb, bt_rel = u16(d, s0+0xA), u32(d, s0+0x1C)
        if nb and bt_rel and s0 + bt_rel + 20*nb <= len(d):
            bones = bytearray()
            for i in range(nb):
                bones += struct.pack("<10h",
                    *struct.unpack_from("<10h", d, s0 + bt_rel + 20*i))
            S.put(s0 + bt_rel, bytes(bones), "bones")
        # v3: mesh entries 40 B (versão skl+4 ≥ 4884; ComputeKeyframeStride
        # 0x828C60) via meshArray skl-relativo; posições/normais 3×i16 e
        # descritores 12 B re-encodados estruturados
        if u16(d, s0+4) >= 4884 and u16(d, s0+6):
            ma_rel = u32(d, s0+0x10)
            for mi in range(u16(d, s0+6)):
                me = s0 + ma_rel + 40*mi
                if me + 40 > len(d): raise Fail(f"mesh[{mi}] OOB")
                S.put(me, struct.pack("<HHHHIIIHHHHI",
                    u16(d,me), u16(d,me+2), u16(d,me+4), u16(d,me+6),
                    u32(d,me+8), u32(d,me+0xC), u32(d,me+0x10),
                    u16(d,me+0x14), u16(d,me+0x16), u16(d,me+0x18),
                    u16(d,me+0x1A), u32(d,me+0x1C)) + d[me+0x20:me+0x28],
                    "mesh_hdr")
                for cnt_f, ptr_f, kind in ((0x4, 0x8, "verts"), (0x16, 0xC, "norms")):
                    n = u16(d, me+cnt_f); pr = u32(d, me+ptr_f)
                    if n and pr and s0+pr+6*n <= len(d):
                        buf = bytearray()
                        for i in range(n):
                            buf += struct.pack("<hhh",
                                *struct.unpack_from("<hhh", d, s0+pr+6*i))
                        S.put(s0+pr, bytes(buf), kind)
                nb12 = u16(d, me+6); pb12 = u32(d, me+0x10)
                put_desc12_records(S, d, s0, pb12, nb12, len(d), "desc12")
        # v4: descritores 12 B no nível SKL — reloc 0x827610: tabela A em
        # skl+0x14 (countA u16@+8) e tabela C em skl+0x24 (countC u16@+0x20)
        if u16(d, s0+4) >= 2097:
            put_desc12_records(S, d, s0, u32(d, s0+0x14), u16(d, s0+8),
                               len(d), "desc12sklA")
            put_desc12_records(S, d, s0, u32(d, s0+0x24), u16(d, s0+0x20),
                               len(d), "desc12sklC")
    # sub-header SG (sec[1]) — 9×u32 {anchor, n, ?, ?, ver@+0x10, +0x14,
    # tblOff@+0x18, +0x1C, +0x20} re-encodados raw
    s1 = secs[1][0]
    if s1 and s1 + 0x24 <= len(d):
        S.put(s1, struct.pack("<IIIIIIIII",
            u32(d,s1), u32(d,s1+4), u32(d,s1+8), u32(d,s1+0xC), u32(d,s1+0x10),
            u32(d,s1+0x14), u32(d,s1+0x18), u32(d,s1+0x1C), u32(d,s1+0x20)),
            "sg_hdr")
    # params (sec[9]): primeiro u32 = tamanho NOMINAL do bloco (nos stubs o
    # bloco vem truncado — o runtime lê só as primeiras ~72 posições; gate
    # estendido ≥5668). Span semântico = o u32; corpo entra no tiling.
    if nsec > 9 and secs[9][0]:
        S.put(secs[9][0], struct.pack("<I", u32(d, secs[9][0])), "params_hdr")
    # blocos: tiling pelos offsets de seção usados (ordenados); dentro de cada
    # intervalo, apenas os trechos ainda não cobertos por sub-headers
    starts = sorted({o for o, _ in secs if o} | {hdr_end})
    bounds = starts + [len(d)]
    for a, b in zip(bounds, bounds[1:]):
        pos = a
        while pos < b:
            if S.cov[pos]: pos += 1; continue
            j = pos
            while j < b and not S.cov[j]: j += 1
            S.put(pos, d[pos:j], "block" if pos != hdr_end else "pad0")
            pos = j
    # residuais
    pos = 0
    while pos < len(d):
        if S.cov[pos]: pos += 1; continue
        j = pos
        while j < len(d) and not S.cov[j]: j += 1
        S.put(pos, d[pos:j], "residual"); RESIDUALS.append((path, pos, d[pos:j]))
        pos = j
    ok = bytes(S.buf) == d
    diff = None
    if not ok:
        for i in range(len(d)):
            if S.buf[i] != d[i]:
                diff = f"@{i:#x}"; break
    return dict(S.stats), ok, diff

if __name__ == "__main__":
    root = sys.argv[1] if len(sys.argv) > 1 else ROOT
    files = []
    for dp, _, fns in os.walk(root):
        for fn in fns:
            if fn.lower().endswith(".chr"): files.append(os.path.join(dp, fn))
    files.sort()
    tot = collections.Counter(); kinds_b = collections.Counter(); kinds_n = collections.Counter()
    fails = []
    for p in files:
        rel = os.path.relpath(p, root)
        try:
            stats, ok, diff = roundtrip(p)
        except Fail as e:
            tot["FAIL"] += 1; fails.append((rel, str(e))); continue
        for k, v in stats.items(): kinds_b[k] += v; kinds_n[k] += 1
        tot["PASS" if ok else "DIFF"] += 1
        if not ok: fails.append((rel, f"DIFF {diff}"))
    print(f"=== CHR ROUND-TRIP v4 ({len(files)} arquivos) ===")
    print("totais:", dict(tot))
    for k, v in sorted(kinds_b.items(), key=lambda x: -x[1]):
        print(f"  {k:10s} n={kinds_n[k]:5d} bytes={v}")
    if fails:
        print(f"\nFALHAS ({len(fails)}):")
        for rel, why in fails[:20]: print(f"  {rel}: {why}")
    if RESIDUALS:
        nz = sum(1 for _,_,s in RESIDUALS if s.strip(b"\x00"))
        print(f"\nresiduais: {len(RESIDUALS)} spans ({nz} não-zero)")
        from collections import Counter
        c = Counter(len(s) for _,_,s in RESIDUALS)
        print("  tamanhos:", dict(sorted(c.items())[:10]))
    if OVERLAP_WINDOWS[0]:
        print(f"janelas de descritor sobrepostas (degradadas ao tiling): "
              f"{OVERLAP_WINDOWS[0]}")
        out = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                           "../../work/_models_unlock/chr_residual_spans.txt")
        with open(out, "w") as f:
            for pth, off, seg in RESIDUALS:
                f.write(f"{os.path.relpath(pth, root)}\t{off:#x}\t{len(seg)}\t{seg[:24].hex()}\n")
