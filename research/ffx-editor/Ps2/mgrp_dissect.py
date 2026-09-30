#!/usr/bin/env python3
# ── MODELS-UNLOCK mgrp sonda: dissector estrutural dos 7 samples ──────────────
# Purpose: aplicar os layouts dos docs consolidados contra bytes reais e
#          VERIFICAR cada invariante (SIZE LAW, reloc offsets, seqProg grammar,
#          clip a2 header, mode/value streams). Output: report textual.
# Layouts aplicados (fontes no mgrp_sonda.md):
#   container: +0 u32 flag(0) | +4 u32 motionCount | +8 u32 reserved(0) |
#              +0xC u32 dataLen (offset da record table; SIZE LAW
#              fileSize == dataLen + motionCount*20)
#   record 20B: +0 u32 f0 | +4 u32 subid(groupKey) | +8 u16 countA | +10 u16
#              countB | +12 u32 offA (seqProg table) | +16 u32 offB (clip table)
#   tableA entry 16B: +0 u16 clipId | +2 u16 key | +4 u16 flags | +6 u16 pad |
#              +8 u32 lblOffTbl | +0xC u32 codeBase
#   tableB entry 16B: +0 u32 f0 | +4 u32 tag(=2) | +8 u32 segFrameTbl |
#              +0xC u32 clipBlob(a2)
#   a2 header: +0 u16 frameCount | +2 u16 targetCount | +4 u16 frameRate(7680)
#              | +6 u16 extraCount | +8 u32 modeOff | +12 u32 keyedOff |
#              +16 u32 extraOff
#   seqProg ISA (wave12 mseq_opcode_map.csv): op0/2/5 len1; op3/4/6 len3;
#              op1 len9 {i16 clipTblIdx,repeat,segIdx,mode}; end em 0/5.
import struct, sys, os

def u16(d, o): return struct.unpack_from("<H", d, o)[0]
def u32(d, o): return struct.unpack_from("<I", d, o)[0]
def s16(d, o): return struct.unpack_from("<h", d, o)[0]

OPN = {0:"END",1:"PLAY",2:"GATE",3:"WAIT",4:"GOTO",5:"ENDREL",6:"WAITCNT"}

def disasm_prog(d, code, lbls, max_ops=64):
    """Walk linear do bytecode seqProg; retorna (ops, err)."""
    ops, pc, n = [], code, 0
    while n < max_ops:
        if pc >= len(d): return ops, f"OOB pc=0x{pc:X}"
        op = d[pc]; n += 1
        if op in (0, 2, 5):
            ops.append((pc, OPN[op], ()))
            if op in (0, 5): return ops, None
            pc += 1
        elif op == 1:
            if pc + 9 > len(d): return ops, f"OOB op1 pc=0x{pc:X}"
            a, b, c, e = s16(d, pc+1), s16(d, pc+3), s16(d, pc+5), s16(d, pc+7)
            ops.append((pc, "PLAY", (a, b, c, e)))
            pc += 9
        elif op in (3, 4, 6):
            if pc + 3 > len(d): return ops, f"OOB op{op} pc=0x{pc:X}"
            v = s16(d, pc+1)
            ops.append((pc, OPN[op], (v,)))
            pc += 3
        else:
            return ops, f"BAD op={op} pc=0x{pc:X}"
    return ops, "max_ops"

def hd(d, base, length, width=16):
    out = []
    for i in range(0, min(length, len(d)-base), width):
        row = d[base+i:base+i+width]
        hexs = " ".join(f"{b:02x}" for b in row)
        asc = "".join(chr(b) if 32 <= b < 127 else "." for b in row)
        out.append(f"  {base+i:06x}  {hexs:<47}  |{asc}|")
    return out

def dissect(path, label, tail_n=0x40, deep_clip=True):
    d = open(path, "rb").read()
    L = []
    L.append(f"\n{'='*78}\n[{label}] {path}\n  size={len(d)} (0x{len(d):X})")
    if len(d) < 0x14:
        L.append("  !! menor que header 0x14 — stub puro")
        L += hd(d, 0, len(d))
        return "\n".join(L)
    flag, mc, res, dl = u32(d,0), u32(d,4), u32(d,8), u32(d,0xC)
    L.append(f"  header: flag={flag} motionCount={mc} reserved={res} dataLen=0x{dl:X}({dl})")
    law = (dl + mc*20 == len(d))
    L.append(f"  SIZE LAW (dataLen+mc*20==size): {'PASS' if law else 'FAIL'}"
             f"  [table@0x{dl:X}..0x{dl+mc*20:X})")
    L.append("  hex head 0x00-0x60:"); L += hd(d, 0, 0x60)
    L.append(f"  hex tail -0x40:"); L += hd(d, max(0, len(d)-tail_n), tail_n)
    if not law: return "\n".join(L)
    for r in range(mc):
        ro = dl + r*20
        f0, subid = u32(d,ro), u32(d,ro+4)
        ca, cb = u16(d,ro+8), u16(d,ro+10)
        oa, ob = u32(d,ro+12), u32(d,ro+16)
        L.append(f"  record[{r}] @0x{ro:X}: f0={f0} subid=0x{subid:X} "
                 f"(hi16=0x{subid>>16:X} lo16=0x{subid&0xFFFF:X})")
        L.append(f"           +8 countA(seqProg)={ca} +0xA countB(clips)={cb} "
                 f"+0xC offA=0x{oa:X} +0x10 offB=0x{ob:X}")
        L.append(f"           hex:"); L += hd(d, ro, 20)
        # tableA = seqProg entries
        for i in range(min(ca, 6)):
            eo = oa + i*16
            cid, key, fl, pad = u16(d,eo), u16(d,eo+2), u16(d,eo+4), u16(d,eo+6)
            lbl, code = u32(d,eo+8), u32(d,eo+12)
            L.append(f"    seqProg[{i}] @0x{eo:X}: clipId=0x{cid:X}({cid}) key=0x{key:X} "
                     f"flags=0x{fl:X} pad=0x{pad:X} lblOffTbl=0x{lbl:X} code=0x{code:X}")
            if i == 0 and ca > 6: L.append(f"    ... (+{ca-6} mais)")
        ops_ct = {}
        prog_ok = prog_err = 0
        for i in range(ca):
            eo = oa + i*16
            code = u32(d, eo+12)
            ops, err = disasm_prog(d, code, None)
            if err: prog_err += 1
            else:
                prog_ok += 1
                for _, nm, _ in ops: ops_ct[nm] = ops_ct.get(nm, 0) + 1
        L.append(f"    seqProg walk: {ca} programs, ok={prog_ok}, err={prog_err}, "
                 f"opcount={ops_ct}")
        # dump do primeiro programa (se pequeno)
        if ca:
            code = u32(d, oa+12)
            ops, err = disasm_prog(d, code, None, max_ops=12)
            for pc, nm, args in ops[:10]:
                L.append(f"      0x{pc:06X}: {nm} {args if args else ''}")
        # tableB = clip entries
        for i in range(min(cb, 8)):
            eo = ob + i*16
            bf0, tag = u32(d,eo), u32(d,eo+4)
            sft, blob = u32(d,eo+8), u32(d,eo+12)
            extra = ""
            if deep_clip and 0 < blob < len(d) - 20:
                fc, tc, fr, xc = u16(d,blob), u16(d,blob+2), u16(d,blob+4), u16(d,blob+6)
                mo, ko, eo2 = u32(d,blob+8), u32(d,blob+12), u32(d,blob+16)
                extra = (f" -> a2: frames={fc} targets={tc} rate={fr} extra={xc} "
                         f"modeOff=0x{mo:X} keyedOff=0x{ko:X} extraOff=0x{eo2:X}")
            L.append(f"    clip[{i}] @0x{eo:X}: f0={bf0} tag={tag} segFrameTbl=0x{sft:X} "
                     f"blob=0x{blob:X}{extra}")
            if i == 7 and cb > 8: L.append(f"    ... (+{cb-8} mais)")
        # segFrameTbl do primeiro clip (u16 values)
        if cb:
            sft = u32(d, ob+8)
            n_seg = 8
            vals = [u16(d, sft+2*j) for j in range(n_seg) if sft+2*j < len(d)]
            L.append(f"    segFrameTbl[0..{len(vals)-1}] @0x{sft:X}: {vals}")
    return "\n".join(L)

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc"
SAMPLES = [
    ("STUB-16",   "chr/mon/m001/mot/resident0.mgrp"),
    ("MINI-116",  "chr/obj/f011/mot/resident0.mgrp"),
    ("SMALL-348", "chr/obj/f001/mot/resident0.mgrp"),
    ("MED-EV",    "event/obj/pt/ptkl0000/ptkl000000.mgrp"),
    ("BIG-50K",   "chr/mon/m002/mot/resident1.mgrp"),
    ("REGMOT",    "battle/mot/regmot.mgrp"),
    ("BIG-EV",    "event/obj/gu/guad0700/guad070000.mgrp"),
]
if __name__ == "__main__":
    out = []
    for label, rel in SAMPLES:
        out.append(dissect(os.path.join(ROOT, rel), label))
    text = "\n".join(out)
    with open(os.path.join(os.path.dirname(os.path.abspath(__file__)),
                           "mgrp_dissect_out.txt"), "w") as f:
        f.write(text)
    print(text[:12000])
    print("\n[full output saved to mgrp_dissect_out.txt]")
