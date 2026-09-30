#!/usr/bin/env python3
"""vu1_disasm.py — wave-18 research tool (RESEARCH ONLY).

Standalone VU1 microprogram disassembler for the `.vutext` staging stream in
`SLPS_250.88` (FFX International, PS2 ELF32/R5900).  No IDA dependency.

Decoding reference (public): Goatman13's `ps2_ida_vu_micro` field tables and
the PS2Tek "VU Instruction Format and Decoding" page — both are clean-room
documentations of Sony's published LIW encoding.  This file re-implements the
decode in a standalone form for reproducible inventory CSVs.

Stream model proven in waves 17/18:
  .vutext = {DMA REF tag}{VIF stream: FLUSHA + MPG + body}* records.
  Each record's body = N 8-byte LIW pairs stored LOWER-word-first
  (+0 = lower pipe, +4 = upper pipe — canonical order, verified by the
  canonical NOP encodings 0x8000033C (lower) / 0x000002FF (upper)).
  Upper word bit31=I (lower word becomes a LOI imm32), bit30=E, 29=M,
  28=D, 27=T.  Upper op = word&0x3F (0x3C-0x3F -> "special" sub-table).
  Lower word bit31 selects family1 (imm-ops/special) vs family2 (op[31:25]).

Usage:
    python3 research_tools/Ps2/vu1_disasm.py [ELF] [--csv DIR]
Outputs per-program summary + (optionally) full instruction listing CSVs.
"""
from __future__ import annotations

import csv
import os
import struct
import sys

ELF = ('/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/FFXINTERNATIONAL/'
       'unipyx/SLPS_250.88')
VUTEXT_VMA, VUTEXT_OFF, VUTEXT_SIZE = 0x578980, 0x479980, 0x3850

# resident records (from .DVP.ovlytab — wave-17): (module, body_vma, size)
RECORDS = [
    (8,   0x578998, 0x800),
    (447, 0x5791A0, 0x4E0),
    (15,  0x579698, 0x800),
    (343, 0x579EA0, 0x800),
    (95,  0x57A6A8, 0x800),
    (146, 0x57AEB0, 0x800),
    (165, 0x57B6B8, 0x800),
    (619, 0x57BEC0, 0x300),
]

SLOT = {8: 0, 15: 0, 447: 1, 343: 1, 95: 2, 146: 3, 165: 4, 619: 5}

XYZW = 'xyzw'
F4 = {0: '_', 1: 'w', 2: 'z', 3: 'zw', 4: 'y', 5: 'yw', 6: 'yz', 7: 'yzw',
      8: 'x', 9: 'xw', 10: 'xz', 11: 'xzw', 12: 'xy', 13: 'xyw', 14: 'xyz',
      15: 'xyzw'}
F2 = 'xyzw'

UP_OPS = {
    0x00: 'addbc', 0x01: 'addbc', 0x02: 'addbc', 0x03: 'addbc',
    0x04: 'subbc', 0x05: 'subbc', 0x06: 'subbc', 0x07: 'subbc',
    0x08: 'maddbc', 0x09: 'maddbc', 0x0A: 'maddbc', 0x0B: 'maddbc',
    0x0C: 'msubbc', 0x0D: 'msubbc', 0x0E: 'msubbc', 0x0F: 'msubbc',
    0x10: 'maxbc', 0x11: 'maxbc', 0x12: 'maxbc', 0x13: 'maxbc',
    0x14: 'minibc', 0x15: 'minibc', 0x16: 'minibc', 0x17: 'minibc',
    0x18: 'mulbc', 0x19: 'mulbc', 0x1A: 'mulbc', 0x1B: 'mulbc',
    0x1C: 'mulq', 0x1D: 'maxi', 0x1E: 'muli', 0x1F: 'minii',
    0x20: 'addq', 0x21: 'maddq', 0x22: 'addi', 0x23: 'maddi',
    0x24: 'subq', 0x25: 'msubq', 0x26: 'subi', 0x27: 'msubi',
    0x28: 'add', 0x29: 'madd', 0x2A: 'mul', 0x2B: 'max',
    0x2C: 'sub', 0x2D: 'msub', 0x2E: 'opmsub', 0x2F: 'mini',
}
UP_SPEC = {
    0x00: 'addabc', 0x01: 'addabc', 0x02: 'addabc', 0x03: 'addabc',
    0x04: 'subabc', 0x05: 'subabc', 0x06: 'subabc', 0x07: 'subabc',
    0x08: 'maddabc', 0x09: 'maddabc', 0x0A: 'maddabc', 0x0B: 'maddabc',
    0x0C: 'msubabc', 0x0D: 'msubabc', 0x0E: 'msubabc', 0x0F: 'msubabc',
    0x10: 'itof0', 0x11: 'itof4', 0x12: 'itof12', 0x13: 'itof15',
    0x14: 'ftoi0', 0x15: 'ftoi4', 0x16: 'ftoi12', 0x17: 'ftoi15',
    0x18: 'mulabc', 0x19: 'mulabc', 0x1A: 'mulabc', 0x1B: 'mulabc',
    0x1C: 'mulaq', 0x1D: 'abs', 0x1E: 'mulai', 0x1F: 'clip',
    0x20: 'addaq', 0x21: 'maddaq', 0x22: 'addai', 0x23: 'maddai',
    0x25: 'msubaq', 0x26: 'subai', 0x27: 'msubai',
    0x28: 'adda', 0x29: 'madda', 0x2A: 'mula',
    0x2C: 'suba', 0x2D: 'msuba', 0x2E: 'opmula', 0x2F: 'nop',
}
# lower1: bit31=1 -> op = w&0x3F ; 0x3C-0x3F -> lower1_special (op=(w&3)|((w>>4)&0x7C))
LO1_OPS = {0x30: 'iadd', 0x31: 'isub', 0x32: 'iaddi',
           0x34: 'iand', 0x35: 'ior'}
LO1_SPEC = {0x30: 'move', 0x31: 'mr32', 0x34: 'lqi', 0x35: 'sqi',
            0x36: 'lqd', 0x37: 'sqd', 0x38: 'div', 0x39: 'sqrt',
            0x3A: 'rsqrt', 0x3B: 'waitq', 0x3C: 'mtir', 0x3D: 'mfir',
            0x3E: 'ilwr', 0x3F: 'iswr', 0x40: 'rnext', 0x41: 'rget',
            0x42: 'rinit', 0x43: 'rxor', 0x64: 'mfp', 0x68: 'xtop',
            0x69: 'xitop', 0x6C: 'xgkick', 0x70: 'esadd', 0x71: 'ersadd',
            0x72: 'eleng', 0x73: 'erleng', 0x74: 'eatanxy', 0x75: 'eatanxz',
            0x76: 'esum', 0x78: 'esqrt', 0x79: 'ersqrt', 0x7A: 'ercpr',
            0x7B: 'waitp', 0x7C: 'esin', 0x7D: 'eatan', 0x7E: 'eexp'}
# lower2: bit31=0 -> op = (w>>25)&0x7F
LO2_OPS = {0x00: 'lq', 0x01: 'sq', 0x04: 'ilw', 0x05: 'isw',
           0x08: 'iaddiu', 0x09: 'isubiu', 0x10: 'fceq', 0x11: 'fcset',
           0x12: 'fcand', 0x13: 'fcor', 0x14: 'fseq', 0x15: 'fsset',
           0x16: 'fsand', 0x17: 'fsor', 0x18: 'fmeq', 0x1A: 'fmand',
           0x1B: 'fmor', 0x1C: 'fcget', 0x20: 'b', 0x21: 'bal',
           0x24: 'jr', 0x25: 'jalr', 0x28: 'ibeq', 0x29: 'ibne',
           0x2C: 'ibltz', 0x2D: 'ibgtz', 0x2E: 'iblez', 0x2F: 'ibgez'}

REGS_32_33 = {32: 'Q', 33: 'I'}


def u32(b, o):
    return struct.unpack_from('<I', b, o)[0]


def f32(b):
    return struct.unpack('<f', struct.pack('<I', b))[0]


def flags_up(w):
    s = ''
    if w & 0x80000000:
        s += 'I'
    if w & 0x40000000:
        s += 'E'
    if w & 0x20000000:
        s += 'M'
    if w & 0x10000000:
        s += 'D'
    if w & 0x08000000:
        s += 'T'
    return s


def decode_upper(w):
    """(mnemonic, operand-string, raw-op) for an upper-pipe word."""
    op = w & 0x3F
    fl = flags_up(w)
    if w & 0x80000000:  # I bit — lower word is imm32
        return 'LOI', '(lower word = imm32)', op, fl
    field = F4.get((w >> 21) & 0xF, '?')
    fd = (w >> 6) & 0x1F
    fs = (w >> 11) & 0x1F
    ft = (w >> 16) & 0x1F
    if op in UP_OPS:
        m = UP_OPS[op]
        if m.endswith('bc'):
            bc = w & 3
            base = m[:-2]
            d = 'ACC' if fd == 34 else f'vf{fd}'
            return f'{base}{XYZW[bc]}.{field}', f'{d}, vf{fs}, vf{ft}.{XYZW[bc]}', op, fl
        if m in ('mulq', 'maxi', 'muli', 'minii', 'addq', 'maddq', 'addi',
                 'maddi', 'subq', 'msubq', 'subi', 'msubi'):
            src2 = {32: 'Q', 33: 'I'}.get({0x1C: 32, 0x1D: 33, 0x1E: 33,
                                           0x1F: 33, 0x20: 32, 0x21: 32,
                                           0x22: 33, 0x23: 33, 0x24: 32,
                                           0x25: 32, 0x26: 33, 0x27: 33}[op], '?')
            d = 'ACC' if fd == 34 else f'vf{fd}'
            return f'{m}.{field}', f'{d}, vf{fs}, {src2}', op, fl
        # plain fs,ft ops
        d = 'ACC' if fd == 34 else f'vf{fd}'
        return f'{m}.{field}', f'{d}, vf{fs}, vf{ft}', op, fl
    if 0x3C <= op <= 0x3F:
        sop = (w & 3) | ((w >> 4) & 0x7C)
        m = UP_SPEC.get(sop, f'?spec{sop:#x}')
        if m == 'nop':
            return 'nop', '', op, fl
        if m.endswith('abc'):
            bc = w & 3
            base = m[:-3] + 'a'
            src = (w >> 11) & 0x1F
            bcr = (w >> 16) & 0x1F
            return f'{base}bc{XYZW[bc]}.{field}', \
                f'ACC, vf{src}, vf{bcr}.{XYZW[bc]}', op, fl
        if m.startswith('itof') or m.startswith('ftoi'):
            src = (w >> 11) & 0x1F
            dst = (w >> 16) & 0x1F
            return f'{m}.{field}', f'vf{dst}, vf{src}', op, fl
        if m == 'clip':
            r1 = (w >> 11) & 0x1F
            r2 = (w >> 16) & 0x1F
            return 'clip', f'vf{r1}, vf{r2}.w', op, fl
        if m in ('mulaq', 'mulai', 'addaq', 'maddaq', 'addai', 'maddai',
                 'msubaq', 'subai', 'msubai'):
            src = (w >> 11) & 0x1F
            r2 = 'Q' if 'q' in m else 'I'
            return f'{m}.{field}', f'ACC, vf{src}, {r2}', op, fl
        if m in ('adda', 'madda', 'mula', 'suba', 'msuba', 'opmula'):
            r1 = (w >> 11) & 0x1F
            r2 = (w >> 16) & 0x1F
            return f'{m}.{field}', f'ACC, vf{r1}, vf{r2}', op, fl
        if m == 'abs':
            src = (w >> 11) & 0x1F
            dst = (w >> 16) & 0x1F
            return f'abs.{field}', f'vf{dst}, vf{src}', op, fl
        return m, '', op, fl
    return f'?up{op:#x}', '', op, fl


def decode_lower(w):
    """(mnemonic, operand-string, raw-op, class) for a lower-pipe word.
    class: 'f1'/'f2'/'nop'/'imm'/'?'"""
    if w == 0x8000033C:
        return 'nop', '', -1, 'nop'
    if w & 0x80000000:
        op = w & 0x3F
        if op in LO1_OPS:
            m = LO1_OPS[op]
            d = (w >> 6) & 0xF
            r1 = (w >> 11) & 0xF
            if m == 'iaddi':
                imm = w & 0x1F
                r2 = (w >> 16) & 0xF
                return m, f'vi{d}, vi{r2}, #{imm}', op, 'f1'
            r2 = (w >> 16) & 0xF
            return m, f'vi{d}, vi{r1}, vi{r2}', op, 'f1'
        if 0x3C <= op <= 0x3F:
            sop = (w & 3) | ((w >> 4) & 0x7C)
            m = LO1_SPEC.get(sop, f'?lo1s{sop:#x}')
            fs = (w >> 11) & 0x1F
            it = (w >> 16) & 0x1F
            field = F4.get((w >> 21) & 0xF, '?')
            if m in ('move', 'mr32', 'abs'):
                dst = (w >> 16) & 0x1F
                return f'{m}.{field}', f'vf{dst}, vf{fs}', sop, 'f1s'
            if m in ('lqi', 'lqd'):
                return f'{m}.{field}', f'vf{it}, (vi{fs}{"++" if m=="lqi" else "--"})', sop, 'f1s'
            if m in ('sqi', 'sqd'):
                return f'{m}.{field}', f'vf{fs}, (vi{it}{"++" if m=="sqi" else "--"})', sop, 'f1s'
            if m == 'div':
                fsf = F2[(w >> 21) & 3]
                ftf = F2[(w >> 23) & 3]
                return 'div', f'Q, vf{fs}.{fsf}, vf{it}.{ftf}', sop, 'f1s'
            if m == 'sqrt':
                ftf = F2[(w >> 23) & 3]
                return 'sqrt', f'Q, vf{it}.{ftf}', sop, 'f1s'
            if m == 'rsqrt':
                fsf = F2[(w >> 21) & 3]
                ftf = F2[(w >> 23) & 3]
                return 'rsqrt', f'Q, vf{fs}.{fsf}, vf{it}.{ftf}', sop, 'f1s'
            if m == 'mtir':
                fsf = F2[(w >> 21) & 3]
                return 'mtir', f'vi{it&0xF}, vf{fs}.{fsf}', sop, 'f1s'
            if m == 'mfir':
                return f'mfir.{field}', f'vf{it}, vi{fs}', sop, 'f1s'
            if m in ('ilwr', 'iswr'):
                return f'{m}.{field}', f'vi{it}, (vi{fs})', sop, 'f1s'
            if m in ('rnext', 'rget', 'rxor'):
                dst = (w >> 16) & 0x1F
                return f'{m}.{field}', f'vf{dst}, R', sop, 'f1s'
            if m == 'rinit':
                dst = (w >> 16) & 0x1F
                return 'rinit', f'R, vf{dst}.{F2[(w>>21)&3]}', sop, 'f1s'
            if m == 'mfp':
                dst = (w >> 16) & 0x1F
                return f'mfp.{field}', f'vf{dst}, P', sop, 'f1s'
            if m in ('xtop', 'xitop'):
                dst = (w >> 16) & 0x1F
                return m, f'vi{dst}', sop, 'f1s'
            if m == 'xgkick':
                return 'xgkick', f'vi{it&0xF}', sop, 'f1s'
            if m.startswith('e') or m in ('waitp', 'waitq'):
                if m in ('esin', 'eatan', 'eexp', 'esqrt', 'ersqrt',
                         'ercpr', 'eleng', 'erleng', 'eatanxy', 'eatanxz',
                         'esadd', 'ersadd', 'esum'):
                    return m, f'(P), vf{fs}', sop, 'f1s'
                return m, '', sop, 'f1s'
            return m, '', sop, 'f1s'
        return f'?lo1{op:#x}', '', op, 'f1?'
    # family2
    op = (w >> 25) & 0x7F
    m = LO2_OPS.get(op)
    if m is None:
        return f'?lo2{op:#x}', '', op, 'f2?'
    _is = (w >> 11) & 0x1F
    it = (w >> 16) & 0x1F
    field = F4.get((w >> 21) & 0xF, '?')
    imm = w & 0x7FF
    if m in ('lq', 'sq', 'ilw', 'isw'):
        reg = it if m in ('ilw', 'isw', 'sq') else (it if m == 'sq' else it)
        fs_ = (w >> 11) & 0x1F
        return f'{m}.{field}', f'v{("i" if m in ("ilw","isw") else "f")}{it}, 0x{imm*16:x}(vi{fs_&0xF})', op, 'f2'
    if m in ('iaddiu', 'isubiu'):
        imm15 = imm | (((w >> 21) & 0xF) << 11)
        return m, f'vi{it}, vi{_is&0xF}, #{imm15}', op, 'f2'
    if m.startswith('fc') or m.startswith('fs') or m.startswith('fm'):
        v = it
        return m, f'vi{v}, #{imm}', op, 'f2'
    if m in ('b', 'bal'):
        off = imm if imm <= 0x3FF else -(~imm & 0x3FF)
        return m, f'{off*8:+d}', op, 'f2'
    if m == 'jr':
        return 'jr', f'vi{_is&0xF}', op, 'f2'
    if m == 'jalr':
        return 'jalr', f'vi{it}, vi{_is&0xF}', op, 'f2'
    if m in ('ibeq', 'ibne'):
        off = imm if imm <= 0x3FF else -(~imm & 0x3FF)
        return m, f'vi{it}, vi{_is&0xF}, {off*8:+d}', op, 'f2'
    if m.startswith('ib'):
        off = imm if imm <= 0x3FF else -(~imm & 0x3FF)
        return m, f'vi{_is&0xF}, {off*8:+d}', op, 'f2'
    return m, '', op, 'f2'


def decode_program(blob, base_vma, size):
    """Decode `size` bytes of LIW pairs at file offset of `base_vma`."""
    off = base_vma - VUTEXT_VMA + VUTEXT_OFF
    rows = []
    for i in range(0, size, 8):
        lo = u32(blob, off + i)
        up = u32(blob, off + i + 4)
        um, uops, uop, ufl = decode_upper(up)
        if ufl.startswith('I'):
            lm, lops, lop, lcls = 'LOI', f'#0x{lo:08x} (={f32(lo):.6g})', -1, 'imm'
        else:
            lm, lops, lop, lcls = decode_lower(lo)
        rows.append(dict(
            idx=i // 8, vma=base_vma + i, lower=lo, upper=up,
            u_mnem=um, u_ops=uops, u_flags=ufl, u_op=uop,
            l_mnem=lm, l_ops=lops, l_op=lop, l_cls=lcls))
    return rows


def classify(rows):
    """Heuristic program-category signature from opcode mix."""
    mn = [r['u_mnem'].split('.')[0].rstrip('xyzw0123456789')
          for r in rows] + [r['l_mnem'] for r in rows]
    s = set(mn)
    sig = []
    if 'xgkick' in s:
        sig.append('kicks-GIF (draw output)')
    if 'clip' in s:
        sig.append('clipping')
    if {'div', 'rsqrt', 'sqrt'} & s:
        sig.append('attribute-divide (persp/interp)')
    if {'esadd', 'ersadd', 'eleng', 'erleng', 'esin', 'eatan', 'eexp',
            'eatanxy', 'eatanxz', 'esqrt', 'ersqrt', 'ercpr'} & s:
        sig.append('elementary-func block')
    if {'madd', 'maddq', 'maddi', 'maddbc', 'maddabc', 'mula', 'madda'} & s:
        sig.append('matrix/FMAC transform')
    if {'lq', 'sq', 'lqi', 'sqi', 'lqd', 'sqd', 'ilw', 'isw'} & s:
        sig.append('VU-mem streaming')
    if {'xtop', 'xitop'} & s:
        sig.append('VU0/VU1 top ptr (kick base)')
    if {'fcset', 'fcand', 'fcor', 'fceq', 'fmeq', 'fmand', 'fmor',
            'fcget', 'fsand', 'fsor', 'fseq', 'fsset'} & s:
        sig.append('flag-cond vertex select')
    if {'mtir', 'mfir'} & s:
        sig.append('vi<->vf bridge')
    if {'rnext', 'rget', 'rinit', 'rxor'} & s:
        sig.append('R-register sampling')
    return '; '.join(sig) if sig else 'unclassified'


def main():
    elf = sys.argv[1] if len(sys.argv) > 1 and not sys.argv[1].startswith('--') else ELF
    csv_dir = None
    if '--csv' in sys.argv:
        i = sys.argv.index('--csv')
        csv_dir = sys.argv[i + 1] if i + 1 < len(sys.argv) else '.'
    blob = open(elf, 'rb').read()
    all_rows = []
    prog_rows = []
    for mod, base, size in RECORDS:
        rows = decode_program(blob, base, size)
        n = len(rows)
        e_at = [r['idx'] for r in rows if 'E' in r['u_flags']]
        nop_u = sum(1 for r in rows if r['u_mnem'] == 'nop')
        nop_l = sum(1 for r in rows if r['l_mnem'] == 'nop')
        loi = sum(1 for r in rows if 'I' in r['u_flags'])
        bad_u = sum(1 for r in rows if r['u_mnem'].startswith('?'))
        bad_l = sum(1 for r in rows if r['l_mnem'].startswith('?'))
        cat = classify(rows)
        first = rows[0]
        sig = (f'{first["upper"]:08x}/{first["lower"]:08x}')
        print(f'mod{mod:4d} slot{SLOT[mod]} @{base:#x} size={size:#x} '
              f'instrs={n} E@idx{e_at[:6]}{"..." if len(e_at)>6 else ""} '
              f'upNOP={nop_u} loNOP={nop_l} LOI={loi} '
              f'badU={bad_u} badL={bad_l}')
        print(f'        first={sig} cat: {cat}')
        prog_rows.append(dict(module=mod, slot=SLOT[mod],
                              body_vma=f'{base:#x}', size=f'{size:#x}',
                              instrs=n, e_idx='|'.join(map(str, e_at)),
                              up_nop=nop_u, lo_nop=nop_l, loi=loi,
                              bad_u=bad_u, bad_l=bad_l, first_words=sig,
                              category=cat))
        for r in rows:
            r['module'] = mod
            r['slot'] = SLOT[mod]
            all_rows.append(r)
    if csv_dir:
        os.makedirs(csv_dir, exist_ok=True)
        pf = os.path.join(csv_dir, 'vu1_programs.csv')
        with open(pf, 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=list(prog_rows[0].keys()))
            w.writeheader()
            w.writerows(prog_rows)
        ifile = os.path.join(csv_dir, 'vu1_instrs.csv')
        with open(ifile, 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=list(all_rows[0].keys()))
            w.writeheader()
            w.writerows(all_rows)
        print(f'wrote {pf} + {ifile}')


if __name__ == '__main__':
    main()
