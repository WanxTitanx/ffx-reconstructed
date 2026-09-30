#!/usr/bin/env python3
# ── MODELS-UNLOCK mgrp census em massa: valida os invariantes nos 3.157 files ──
# Verifica: SIZE LAW, reloc-offsets in-bounds/ordenados, seqProg grammar walk,
# clip-entry tag/f0, a2 header sanity (rate=7680, frames/targets bounds),
# modeOff/keyedOff padrões, decode RLE dos keyed streams (via reader logic).
import struct, os, sys, collections

def u16(d, o): return struct.unpack_from("<H", d, o)[0]
def u32(d, o): return struct.unpack_from("<I", d, o)[0]
def s16(d, o): return struct.unpack_from("<h", d, o)[0]

def disasm_check(d, code):
    """Walk linear do seqProg; retorna n_ops ou -1 (erro)."""
    pc, n = code, 0
    while n < 4096:
        if pc >= len(d): return -1
        op = d[pc]; n += 1
        if op in (0, 2, 5):
            if op in (0, 5): return n
            pc += 1
        elif op == 1:
            if pc + 9 > len(d): return -1
            pc += 9
        elif op in (3, 4, 6):
            if pc + 3 > len(d): return -1
            pc += 3
        else:
            return -1
    return -1

def decode_rle(d, pos, nframes):
    """Delta-RLE (FFX_Mseq_AdvanceKeyedChannelCursors). Retorna (n_consumed, ok)."""
    start = pos
    for _ in range(nframes):
        if pos >= len(d): return pos - start, False
        c = d[pos]
        if c < 0x80: pos += 1
        elif c & 0x40: pos += 2
        else: pass  # run: 0 extra bytes
    return pos - start, True

def dissect_file(path):
    r = {"size": 0, "cls": None, "mc": 0, "recs": 0, "progs": 0, "prog_err": 0,
         "clips": 0, "clip_err": 0, "streams": 0, "stream_err": 0,
         "tags": collections.Counter(), "pads": collections.Counter(),
         "modeoffs": collections.Counter(), "f0nz": 0, "seg_nonmono": 0,
         "dummy0": 0, "segidx_gt0": 0, "plays": 0, "modes_c": collections.Counter(),
         "waits": collections.Counter()}
    d = open(path, "rb").read()
    r["size"] = len(d)
    if len(d) == 16 and d == b"\x00"*12 + b"\x10\x00\x00\x00":
        r["cls"] = "stub16"; return r
    if len(d) < 0x14:
        r["cls"] = "tiny"; return r
    mc, dl = u32(d, 4), u32(d, 0xC)
    r["mc"] = mc
    if dl + mc*20 != len(d):
        r["cls"] = "SIZELAW_FAIL"; return r
    r["cls"] = "ok"
    for ri in range(mc):
        ro = dl + ri*20
        if u32(d, ro) != 0: r["f0nz"] += 1
        ca, cb = u16(d, ro+8), u16(d, ro+10)
        oa, ob = u32(d, ro+12), u32(d, ro+16)
        if ca == 0 and cb == 0:
            r["dummy0"] += 1; continue
        if not (0x14 <= oa < len(d) and 0x14 <= ob < len(d)):
            r["cls"] = "RECPTR_OOB"; return r
        r["recs"] += 1
        for i in range(ca):
            eo = oa + i*16
            if eo + 16 > len(d): r["prog_err"] += 1; continue
            r["pads"][u16(d, eo+6)] += 1
            code = u32(d, eo+12)
            if not (0x14 <= code < len(d)): r["prog_err"] += 1; continue
            n = disasm_check(d, code)
            if n < 0: r["prog_err"] += 1
            else:
                r["progs"] += 1
                pc2 = code
                for _ in range(n):
                    op = d[pc2]
                    if op == 1:
                        r["plays"] += 1
                        seg, md = s16(d, pc2+5), s16(d, pc2+7)
                        if seg > 0: r["segidx_gt0"] += 1
                        r["modes_c"][md] += 1
                        pc2 += 9
                    elif op in (3, 4, 6):
                        r["waits"][op] += 1
                        pc2 += 3
                    else: pc2 += 1
        for i in range(cb):
            eo = ob + i*16
            if eo + 16 > len(d): r["clip_err"] += 1; continue
            r["tags"][u32(d, eo+4)] += 1
            blob = u32(d, eo+12)
            sft = u32(d, eo+8)
            if not (0x14 <= blob < len(d) - 20 and 0x10 <= sft < len(d)):
                r["clip_err"] += 1; continue
            fc, tc, rate, xc = u16(d, blob), u16(d, blob+2), u16(d, blob+4), u16(d, blob+6)
            mo, ko = u32(d, blob+8), u32(d, blob+12)
            if rate != 7680 or fc == 0 or fc > 65535 or tc == 0:
                r["clip_err"] += 1; continue
            r["clips"] += 1
            r["modeoffs"][mo] += 1
            # segFrameTbl monotonia para os 2 primeiros slots
            if sft + 4 <= len(d) and u16(d, sft+1*2) != 0 and u16(d, sft) > u16(d, sft+2):
                r["seg_nonmono"] += 1
            # mode/value streams bounds + decode keyed (só se offsets plausíveis)
            mode_base, val_base = blob + mo, blob + ko
            nchan = 9 * tc
            if mode_base + (nchan*2+7)//8 > len(d) or val_base >= len(d):
                r["clip_err"] += 1; continue
            # walk channels (como o reader C#): consts 2B, keyed L-prefix
            vp = val_base
            mb = mode_base << 0
            ok = True
            for c in range(nchan):
                mode = (d[mode_base + (c*2)//8] >> ((c*2) % 8)) & 3
                if mode == 2: vp += 2
                elif mode == 3:
                    if vp + 2 > len(d): ok = False; break
                    L = u16(d, vp)
                    if L < 2 or vp + L > len(d): ok = False; break
                    used, dok = decode_rle(d, vp+2, fc)
                    r["streams"] += 1
                    if not dok: r["stream_err"] += 1
                    vp += L
                if not ok: break
            if not ok: r["clip_err"] += 1
    return r

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc"
if __name__ == "__main__":
    tot = collections.Counter(); agg = collections.Counter()
    TAGS = collections.Counter(); PADS = collections.Counter(); MODEOFFS = collections.Counter(); MODES = collections.Counter()
    files = []
    for dp, _, fns in os.walk(ROOT):
        for fn in fns:
            if fn.lower().endswith(".mgrp"): files.append(os.path.join(dp, fn))
    files.sort()
    for p in files:
        r = dissect_file(p)
        tot[r["cls"]] += 1
        for k in ("recs","progs","prog_err","clips","clip_err","streams","stream_err","f0nz","dummy0","segidx_gt0","plays"):
            agg[k] += r[k]
        TAGS += r["tags"]; PADS += r["pads"]; MODEOFFS += r["modeoffs"]; MODES += r["modes_c"]
        for k in ("dummy0","segidx_gt0","plays"): agg[k] += r[k]
        if r["cls"] not in ("ok", "stub16"):
            print(f"ANOMALY {r['cls']}: {os.path.relpath(p, ROOT)}")
    print("\n=== CENSUS TOTALS ===")
    print("classes:", dict(tot))
    for k in ("recs","progs","prog_err","clips","clip_err","streams","stream_err","f0nz","dummy0","segidx_gt0","plays"):
        print(f"  {k}: {agg[k]}")
    print("  tags:", dict(TAGS))
    print("  seqProg pads (u16@+6) top:", PADS.most_common(8))
    print("  a2 modeOff values top:", MODEOFFS.most_common(8))
    print("  PLAY mode operand dist:", MODES.most_common(10))
