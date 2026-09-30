#!/usr/bin/env python3
# ── MODELS-UNLOCK mgrp round-trip: parse → re-serialização → comparação byte-a-byte ──
# Prova de COBERTURA ESTRUTURAL do container .mgrp (span model da sonda
# 2026-09-19, docs/reverse/FFX_MODELS_UNLOCK_MGRP_SONDA_2026-09-19.md):
#
#   spans RE-ENCODADOS (semântica modelada, determinística):
#     header 20B, record table (campos raw), tableA, tableB, bytecode seqProg
#     (ops + operandos s16), a2 headers (2 emissores), mode streams 2-bit
#     (bit re-pack LSB-first; pad bits do último byte = campo opaco parsed),
#     consts i16 do value region.
#   spans VERBATIM (opacos, inventariados — cobertura sem semântica):
#     preludes [ptrA,ptrB), lbl→code gaps, gap 4B do emissor completo,
#     padding entre mode stream e keyedOff, payloads keyed RLE (validados por
#     decode de bounds; bytes copiados), align-2 antes da event region,
#     event regions (extraCount×8B), gaps residuais do data region.
#
# encode(parse(x)) == x  ⇒  (1) o span model delimita 100% dos bytes sem
# buracos nem sobreposições; (2) todo campo re-encodado é determinístico.
# Falhas = lista exata de onde o modelo ainda não cobre.
#
# Corpus (READ-ONLY): /mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc
# Uso: python3 mgrp_roundtrip.py [root]   (report também em stdout)
import struct, os, sys, collections

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc"
RESIDUALS = []   # (path, offset, bytes) — inventário dos gaps opacos

def u16(d, o): return struct.unpack_from("<H", d, o)[0]
def u32(d, o): return struct.unpack_from("<I", d, o)[0]

class Fail(Exception):
    """Divergência de layout com contexto para o report."""

def decode_rle_ok(d, pos, nframes):
    """Delta-RLE walk (FFX_Mseq_AdvanceKeyedChannelCursors 0x839550) — só bounds."""
    for _ in range(nframes):
        if pos >= len(d): return False
        c = d[pos]
        if c < 0x80: pos += 1
        elif c & 0x40: pos += 2
    return True

def rle_tokenize(payload):
    """Tokeniza o payload keyed no formato exato do decoder 0x839550:
    byte <0x80  → delta 7-bit  (sext7);  byte >=0xC0 → delta 14-bit
    (payload14 = (b0&0x3F)|(b1<<6), sext14);  0x80..0xBF → run N=b&0x3F
    (segura o delta anterior por N+1 frames). Retorna lista de tokens ou None."""
    toks, i, n = [], 0, len(payload)
    while i < n:
        b = payload[i]
        if b < 0x80:
            v7 = b & 0x7F
            toks.append(("d7", v7 - 0x80 if b & 0x40 else v7))  # sext7
            i += 1
        elif b >= 0xC0:
            if i + 1 >= n: return None
            p14 = (b & 0x3F) | (payload[i+1] << 6)
            toks.append(("d14", p14 - 0x4000 if p14 & 0x2000 else p14))  # sext14
            i += 2
        else:
            toks.append(("run", b & 0x3F))
            i += 1
    return toks

def rle_encode(toks):
    """Re-serializa tokens → bytes (inverso bijetor do tokenizer)."""
    out = bytearray()
    for t, v in toks:
        if t == "d7":
            out.append(v & 0x7F)
        elif t == "d14":
            p = v & 0x3FFF
            out.append(0xC0 | (p & 0x3F)); out.append((p >> 6) & 0xFF)
        else:
            out.append(0x80 | (v & 0x3F))
    return bytes(out)

class Spans:
    """Mapa de cobertura + buffer de re-serialização."""
    def __init__(self, size):
        self.size = size
        self.buf = bytearray(size)
        self.cov = bytearray(size)      # 0=livre, 1=escrito
        self.stats = collections.Counter()
        self.anoms = []
    def put(self, start, data, kind):
        end = start + len(data)
        if start < 0 or end > self.size:
            raise Fail(f"{kind} OOB [{start:#x},{end:#x}) size={self.size:#x}")
        if any(self.cov[start:end]):
            # spans idênticos re-apontados (records clonados compartilham tabelas)
            if self.cov[start:end] == b"\x01"*(end-start) and self.buf[start:end] == data:
                return
            raise Fail(f"{kind} COLISÃO em [{start:#x},{end:#x})")
        self.buf[start:end] = data
        for i in range(start, end): self.cov[i] = 1
        self.stats[kind] += len(data)

def parse_programs(d, oa, ca):
    """tableA + bytecode + lbl gaps. Retorna spans e anomalias."""
    sp = []
    for i in range(ca):
        eo = oa + i*16
        if eo + 16 > len(d): raise Fail(f"tableA[{i}] OOB @{eo:#x}")
        clipId, key, fl, pad6 = u16(d,eo), u16(d,eo+2), u16(d,eo+4), u16(d,eo+6)
        lbl, code = u32(d,eo+8), u32(d,eo+12)
        sp.append(("tableA", eo, struct.pack("<HHHHII", clipId, key, fl, pad6, lbl, code)))
        if not (0x14 <= code < len(d)): raise Fail(f"prog[{i}] code OOB @{code:#x}")
        if lbl:
            if not (0x14 <= lbl <= code): raise Fail(f"prog[{i}] lbl>{code:#x} @{lbl:#x}")
            if lbl < code:
                sp.append(("lblgap", lbl, d[lbl:code]))   # u16 0/9 — opaco
        # bytecode: walk + re-encode ops
        ops, pc, n = [], code, 0
        while True:
            if pc >= len(d) or n > 4096: raise Fail(f"prog[{i}] walk OOB @{pc:#x}")
            op = d[pc]; n += 1
            if op in (0, 2, 5):
                ops.append(bytes([op]))
                if op in (0, 5): pc += 1; break
                pc += 1
            elif op == 1:
                if pc + 9 > len(d): raise Fail(f"prog[{i}] PLAY OOB @{pc:#x}")
                ops.append(struct.pack("<Bhhhh", 1, *struct.unpack_from("<hhhh", d, pc+1)))
                pc += 9
            elif op in (3, 4, 6):
                if pc + 3 > len(d): raise Fail(f"prog[{i}] op{op} OOB @{pc:#x}")
                ops.append(struct.pack("<Bh", op, *struct.unpack_from("<h", d, pc+1)))
                pc += 3
            else:
                raise Fail(f"prog[{i}] op inválida {op} @{pc:#x}")
        sp.append(("code", code, b"".join(ops)))
    return sp

def parse_clip(d, eo):
    """tableB entry + prelude + a2 blob completo. Retorna spans."""
    if eo + 16 > len(d): raise Fail(f"tableB OOB @{eo:#x}")
    f0, tag, ptrA, blob = u32(d,eo), u32(d,eo+4), u32(d,eo+8), u32(d,eo+12)
    sp = [("tableB", eo, struct.pack("<IIII", f0, tag, ptrA, blob))]
    if not (0x14 <= blob < len(d) - 20): raise Fail(f"clip blob OOB @{blob:#x}")
    fc, tc, rate, xc = u16(d,blob), u16(d,blob+2), u16(d,blob+4), u16(d,blob+6)
    mo, ko, xo = u32(d,blob+8), u32(d,blob+12), u32(d,blob+16)
    if rate != 7680 or fc == 0 or tc == 0:
        raise Fail(f"clip degenerado (rate={rate} fc={fc} tc={tc}) @{blob:#x} — caso w001")
    nchan = 9 * tc
    # prelude: sempre adjacente (probes 2026-09-19: 2..16 u16 terminando no blob)
    if ptrA < blob:
        sp.append(("prelude", ptrA, d[ptrA:blob]))
    elif ptrA != blob:
        raise Fail(f"prelude ptrA={ptrA:#x} > blob={blob:#x}")
    # a2 header — 2 emissores: compacto mo=0x10 (mode stream sobrepõe extraOff,
    # header efetivo 16B) e completo mo>=0x14 (header 20B + gap até mo)
    if mo == 0x10:
        sp.append(("a2hdr", blob, struct.pack("<HHHHII", fc, tc, rate, xc, mo, ko)))
        mode_base = blob + 0x10
    else:
        if mo < 0x14: raise Fail(f"modeOff ímpar {mo:#x} @{blob:#x}")
        sp.append(("a2hdr", blob, struct.pack("<HHHHIII", fc, tc, rate, xc, mo, ko, xo)))
        if mo > 0x14:
            sp.append(("hdrgap", blob + 0x14, d[blob+0x14:blob+mo]))
        mode_base = blob + mo
    # mode stream 2-bit LSB-first + pad bits do último byte (opaco)
    nbytes = (nchan*2 + 7)//8
    if mode_base + nbytes > len(d): raise Fail(f"mode stream OOB @{mode_base:#x}")
    modes = [(d[mode_base + (c*2)//8] >> ((c*2) % 8)) & 3 for c in range(nchan)]
    mb = bytearray(nbytes)
    for c, m in enumerate(modes):
        if m: mb[(c*2)//8] |= m << ((c*2) % 8)
    used_bits = nchan*2
    pad_bits = d[mode_base+nbytes-1] >> (used_bits - (nbytes-1)*8) if used_bits % 8 else 0
    mb[-1] |= pad_bits << (used_bits - (nbytes-1)*8) if used_bits % 8 else 0
    sp.append(("modes", mode_base, bytes(mb)))
    # padding entre mode stream e value region
    val_base = blob + ko
    if mode_base + nbytes > val_base: raise Fail(f"mode>keyed @{blob:#x} mo={mo:#x} ko={ko:#x}")
    if mode_base + nbytes < val_base:
        sp.append(("modepad", mode_base + nbytes, d[mode_base+nbytes:val_base]))
    if val_base >= len(d): raise Fail(f"value region OOB @{val_base:#x}")
    # value region: consts i16 re-encodadas; keyed RLE = payload validado verbatim
    vp = val_base
    for c, m in enumerate(modes):
        if m == 2:
            if vp + 2 > len(d): raise Fail(f"const OOB @{vp:#x}")
            sp.append(("const", vp, d[vp:vp+2])); vp += 2
        elif m == 3:
            if vp + 2 > len(d): raise Fail(f"keyed L OOB @{vp:#x}")
            L = u16(d, vp)
            if L < 2 or vp + L > len(d): raise Fail(f"keyed L={L} OOB @{vp:#x}")
            payload = d[vp+2:vp+L]
            toks = rle_tokenize(payload)
            if toks is None or rle_encode(toks) != payload:
                raise Fail(f"keyed RLE re-encode divergiu @{vp:#x}")
            if not decode_rle_ok(d, vp+2, fc):
                raise Fail(f"keyed RLE decode falhou @{vp:#x}")
            # spans: prefixo u16 (len) + tokens re-serializados semanticamente
            sp.append(("keyedhdr", vp, struct.pack("<H", L)))
            sp.append(("keyed", vp + 2, rle_encode(toks)))
            vp += L
    # event region (FFX_Chr_LogMotionEvent 0x8343D0): entradas de stride
    # variável {u8 type, s8 payloadCount, s16 startFrame, s16 endFrame,
    # u16 arg, u32[payloadCount]}; disparam na janela de frames
    if xc > 0:
        xo_abs = blob + xo
        xo_eff = xo_abs if vp <= xo_abs <= vp + 2 else vp + (vp & 1)
        if xo_eff != xo_abs:
            sp.append(("_anom", 0,
                f"extraOff desalinhado @{blob:#x}: campo={xo_abs:#x} efetivo={xo_eff:#x}".encode()))
        if xo_eff - vp:
            sp.append(("evpad", vp, d[vp:xo_eff]))
        q, ent = xo_eff, bytearray()
        for e in range(xc):
            if q + 8 > len(d): raise Fail(f"event[{e}] OOB @{q:#x}")
            et = d[q]; pc = struct.unpack_from("<b", d, q+1)[0]
            ent += struct.pack("<BbHHH", et, pc,
                               u16(d, q+2), u16(d, q+4), u16(d, q+6))
            q += 8
            for k in range(pc):
                if q + 4 > len(d): raise Fail(f"event[{e}] payload OOB @{q:#x}")
                ent += struct.pack("<I", u32(d, q)); q += 4
        sp.append(("event", xo_eff, bytes(ent)))
    return sp, blob

def roundtrip(path):
    """Parse completo + re-serialização. Retorna (classe, stats, anoms, ok, diff)."""
    d = open(path, "rb").read()
    if len(d) == 16 and d == b"\x00"*12 + b"\x10\x00\x00\x00":
        buf = struct.pack("<IIII", 0, 0, 0, 0x10)
        return ("stub16", {"stub16": 16}, [], buf == d, None)
    if len(d) < 0x14:
        return ("tiny", {"tiny": len(d)}, [], False, "size<0x14")
    flag, mc, res, dl = u32(d,0), u32(d,4), u32(d,8), u32(d,0xC)
    if dl + mc*20 != len(d):
        return ("SIZELAW_FAIL", {}, [], False, f"dl={dl:#x} mc={mc}")
    S = Spans(len(d))
    S.put(0, struct.pack("<IIII", flag, mc, res, dl), "header")
    anoms = []
    for ri in range(mc):
        ro = dl + ri*20
        f0, subid = u32(d,ro), u32(d,ro+4)
        ca, cb = u16(d,ro+8), u16(d,ro+10)
        oa, ob = u32(d,ro+12), u32(d,ro+16)
        S.put(ro, struct.pack("<IIHHII", f0, subid, ca, cb, oa, ob), "record")
        if ca == 0 and cb == 0: continue          # record dummy slot-0
        if not (0x14 <= oa < len(d) and 0x14 <= ob < len(d)):
            raise Fail(f"rec[{ri}] ptrs OOB oa={oa:#x} ob={ob:#x}")
        for kind, off, data in parse_programs(d, oa, ca):
            S.put(off, data, kind)
        for i in range(cb):
            spans, blob = parse_clip(d, ob + i*16)
            for kind, off, data in spans:
                if kind == "_anom":
                    anoms.append(data.decode()); continue
                S.put(off, data, kind)
    # gaps residuais: tudo que o span model não cobriu (inventariado verbatim)
    pos = 0
    while pos < len(d):
        if S.cov[pos]: pos += 1; continue
        j = pos
        while j < len(d) and not S.cov[j]: j += 1
        S.put(pos, d[pos:j], "residual")
        RESIDUALS.append((path, pos, d[pos:j]))
        pos = j
    ok = bytes(S.buf) == d
    diff = None
    if not ok:
        for i in range(len(d)):
            if S.buf[i] != d[i]:
                diff = f"@{i:#x}: reemit={S.buf[i]:.2x} orig={d[i]:.2x} ctx={d[max(0,i-8):i+8].hex()}"
                break
    return ("ok", dict(S.stats), anoms, ok, diff)

if __name__ == "__main__":
    root = sys.argv[1] if len(sys.argv) > 1 else ROOT
    files = []
    for dp, _, fns in os.walk(root):
        for fn in fns:
            if fn.lower().endswith(".mgrp"): files.append(os.path.join(dp, fn))
    files.sort()
    tot = collections.Counter(); kinds_b = collections.Counter(); kinds_n = collections.Counter()
    fails, anoms, outliers = [], [], []
    for p in files:
        rel = os.path.relpath(p, root)
        try:
            cls, stats, fa, ok, diff = roundtrip(p)
        except Fail as e:
            tot["PARSE_FAIL"] += 1
            (outliers if "degenerado" in str(e) else fails).append((rel, str(e)))
            continue
        tot[cls] += 1
        if cls == "stub16": continue
        for k, v in stats.items():
            kinds_b[k] += v; kinds_n[k] += 1
        if fa: tot["ANOM_EXTRAOFF"] += len(fa); anoms += [(rel, a) for a in fa[:2]]
        if cls == "ok":
            tot["PASS" if ok else "DIFF"] += 1
            if not ok: fails.append((rel, f"DIFF {diff}"))
        elif cls != "stub16":
            fails.append((rel, f"cls={cls}"))
    print(f"=== MGRP ROUND-TRIP ({len(files)} arquivos, root={root}) ===")
    print("classes:", dict(tot))
    print("\nspans (kind: n, bytes):")
    for k, v in sorted(kinds_b.items(), key=lambda x: -x[1]):
        print(f"  {k:12s} n={kinds_n[k]:7d} bytes={v:10d}")
    re_enc = sum(v for k, v in kinds_b.items() if k not in
                 ("prelude", "lblgap", "hdrgap", "modepad", "evpad", "residual"))
    verb  = sum(v for k, v in kinds_b.items()) - re_enc
    print(f"\nre-encodado: {re_enc} B | verbatim opaco: {verb} B")
    if fails:
        print(f"\nFALHAS ({len(fails)}):")
        for rel, why in fails[:25]: print(f"  {rel}: {why}")
    if outliers:
        print(f"\nOUTLIERS degenerados ({len(outliers)}):")
        for rel, why in outliers[:5]: print(f"  {rel}: {why}")
    if anoms:
        print(f"\nANOMALIAS extraOff ({len(anoms)} mostradas):")
        for rel, a in anoms[:5]: print(f"  {rel}: {a}")
    if RESIDUALS:
        out = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                           "../../work/_models_unlock/residual_spans.txt")
        with open(out, "w") as f:
            for p, off, seg in RESIDUALS:
                f.write(f"{os.path.relpath(p, root)}\t{off:#x}\t{len(seg)}\t{seg[:24].hex()}"
                        f"{'' if len(seg) <= 24 else ' …'}\n")
        nz = sum(1 for _, _, s in RESIDUALS if s.strip(b"\x00"))
        print(f"\nresiduais: {len(RESIDUALS)} spans, {nz} com bytes não-zero "
              f"(dump: {os.path.normpath(out)})")
