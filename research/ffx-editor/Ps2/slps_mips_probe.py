#!/usr/bin/env python3
"""slps_mips_probe.py — offline probe for the FFX International PS2 executable.

Mission (Jarvis-SLPS-MIPS, wave-15 residual lane 2026-09-18): crack open
`SLPS_250.88` (ELF32 MIPS-R5900, ET_EXEC, entry 0x00100008) for the
`.clp`<->`.fmt` palette binding residual and related loaders. The binding is
by cdidx `fid`/slot, not by name — there is no `TEX2.CBP` string — so the
mechanism has to be read out of the MIPS code that programs the GS and the
cdrom.fid/fnd/mdg slot loaders.

WHAT IT DOES
  - parses ELF32 section + program headers (sections <-> vaddr <-> file off)
  - extracts NUL-terminated ASCII strings from every loaded section,
    recording file offset, vaddr and section name
  - resolves string xrefs the way MIPS code actually references them:
      * `lui $rt, %hi(V)` + `addiu/daddiu $rt, $rt, %lo(V)`  (address
        materialization — e.g. passing the string to a function)
      * `lui $rt, %hi(V)` + `lw/sw/lb/lh/... $x, %lo(V)($rt)` (direct data
        access to the address — e.g. a global holding the string)
      * `ori/xori/andi` low-half forms (raw hi/lo split, non-adjusted)
      * plain u32 data pointers == V inside any loaded section (pointer
        tables in .data/.rodata — how most string tables are consumed)
  - targeted capstone disassembly windows around any vaddr
  - dumps the SN/SCE `.DVP.ovlytab` overlay table + overlay stub sections

USAGE
  python3 slps_mips_probe.py --sections [--csv out.csv]
  python3 slps_mips_probe.py --strings <substr|/regex/> [-i] [--csv out.csv]
  python3 slps_mips_probe.py --xrefs <substr|/regex/> [-i] [--csv out.csv]
  python3 slps_mips_probe.py --xrefs-addr 0x21370f0
  python3 slps_mips_probe.py --disasm 0x100008 [--before N] [--after N]
  python3 slps_mips_probe.py --disasm-off 0x1c8c [--before N] [--after N]
  python3 slps_mips_probe.py --ovlytab [--csv out.csv]

Default ELF: the canonical SLPS_250.88 copy (override with --elf).
Capstone is only needed for --disasm; everything else is stdlib-only.
Exit codes: 0 ok, 2 usage error, 3 capstone missing for --disasm.
"""

import argparse
import csv
import os
import re
import struct
import sys

DEFAULT_ELF = ('/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/'
               'FFXINTERNATIONAL/unipyx/SLPS_250.88')

STR_MIN_LEN = 4          # minimum printable run to count as a string
XREF_LOOKAHEAD = 24      # instrs to scan after a matching `lui`

SHT_NOBITS = 8
SHF_ALLOC = 0x2

ELF_TYPES = {0: 'NULL', 1: 'REL', 2: 'EXEC', 3: 'DYN', 4: 'CORE',
             0xFF80: 'SCE-IOP-REL-EXEC', 0xFF91: 'SCE-EE-REL'}

# MIPS opcodes (primary opcode field = word>>26)
OP_SPECIAL, OP_REGIMM = 0x00, 0x01
OP_J, OP_JAL, OP_BEQ, OP_BNE, OP_BLEZ, OP_BGTZ = 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
OP_ADDI, OP_ADDIU, OP_SLTI, OP_SLTIU = 0x08, 0x09, 0x0A, 0x0B
OP_ANDI, OP_ORI, OP_XORI, OP_LUI = 0x0C, 0x0D, 0x0E, 0x0F
OP_DADDI, OP_DADDIU = 0x18, 0x19
OP_LDL, OP_LDR, OP_LB, OP_LH, OP_LWL, OP_LW = 0x1A, 0x1B, 0x20, 0x21, 0x22, 0x23
OP_LBU, OP_LHU, OP_LWR, OP_SB, OP_SH, OP_SWL, OP_SW = 0x24, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B
OP_SDL, OP_SDR, OP_SWR = 0x2C, 0x2D, 0x2E
OP_LL, OP_LWC1, OP_LWC2, OP_LDC1 = 0x30, 0x31, 0x33, 0x35
OP_LD, OP_SC, OP_SWC1, OP_SWC2, OP_SDC1, OP_SD = 0x37, 0x38, 0x39, 0x3B, 0x3D, 0x3F

# I-type ops whose rt field is a DESTINATION (write kills a lui chain)
I_DEST_OPS = {OP_ADDI, OP_ADDIU, OP_SLTI, OP_SLTIU, OP_ANDI, OP_ORI, OP_XORI,
              OP_LUI, OP_DADDI, OP_DADDIU,
              OP_LDL, OP_LDR, OP_LB, OP_LH, OP_LWL, OP_LW, OP_LBU, OP_LHU,
              OP_LWR, OP_LL, OP_LWC1, OP_LWC2, OP_LDC1, OP_LD}
# loads/stores using rs as base register: `op rt, imm(rs)` — lo16 can pair
MEM_OPS = {OP_LDL, OP_LDR, OP_LB, OP_LH, OP_LWL, OP_LW, OP_LBU, OP_LHU,
           OP_LWR, OP_SB, OP_SH, OP_SWL, OP_SW, OP_SDL, OP_SDR, OP_SWR,
           OP_LL, OP_LWC1, OP_LWC2, OP_LDC1, OP_LD, OP_SC, OP_SWC1,
           OP_SWC2, OP_SDC1, OP_SD}
# ALU-immediate ops that can materialize %lo (rs == rt source+dest)
LO_MATERIALIZE_OPS = {OP_ADDIU: 'addiu', OP_DADDIU: 'daddiu', OP_ORI: 'ori',
                      OP_XORI: 'xori', OP_ANDI: 'andi', OP_ADDI: 'addi',
                      OP_DADDI: 'daddi'}
MNEMONIC = {OP_LUI: 'lui', OP_LW: 'lw', OP_SW: 'sw', OP_LB: 'lb', OP_LBU: 'lbu',
            OP_LH: 'lh', OP_LHU: 'lhu', OP_SB: 'sb', OP_SH: 'sh', OP_LD: 'ld',
            OP_SD: 'sd', OP_LWC1: 'lwc1', OP_SWC1: 'swc1', OP_LDC1: 'ldc1',
            OP_SDC1: 'sdc1', OP_LWL: 'lwl', OP_LWR: 'lwr', OP_SWL: 'swl',
            OP_SWR: 'swr', OP_LL: 'll', OP_SC: 'sc', OP_LDL: 'ldl',
            OP_LDR: 'ldr', OP_SDL: 'sdl', OP_SDR: 'sdr', OP_LWC2: 'lwc2',
            OP_SWC2: 'swc2', **LO_MATERIALIZE_OPS}


def u32(b, o):
    return struct.unpack_from('<I', b, o)[0]


# ── ELF parsing ────────────────────────────────────────────────────────────

class Section:
    __slots__ = ('name', 'shtype', 'flags', 'addr', 'off', 'size', 'entsz')

    def __init__(self, name, shtype, flags, addr, off, size, entsz):
        self.name, self.shtype, self.flags = name, shtype, flags
        self.addr, self.off, self.size, self.entsz = addr, off, size, entsz

    @property
    def loadable(self):
        # resident in the EE image: ALLOC + has file bytes (not NOBITS)
        return bool(self.flags & SHF_ALLOC) and self.shtype != SHT_NOBITS \
            and self.size > 0

    def contains(self, vaddr):
        return self.addr <= vaddr < self.addr + self.size


class ElfImage:
    def __init__(self, path):
        self.path = path
        self.blob = open(path, 'rb').read()
        b = self.blob
        if b[:4] != b'\x7fELF' or b[4] != 1 or b[5] != 1:
            raise ValueError(f'{path}: not a little-endian ELF32')
        self.e_type = struct.unpack_from('<H', b, 16)[0]
        self.e_machine = struct.unpack_from('<H', b, 18)[0]
        self.e_entry = u32(b, 24)
        self.e_phoff = u32(b, 28)
        self.e_shoff = u32(b, 32)
        self.e_flags = u32(b, 36)
        self.e_phentsize, self.e_phnum = struct.unpack_from('<HH', b, 42)
        self.e_shentsize, self.e_shnum, self.e_shstrndx = \
            struct.unpack_from('<HHH', b, 46)
        self.phdrs = []
        for i in range(self.e_phnum):
            o = self.e_phoff + i * self.e_phentsize
            self.phdrs.append(struct.unpack_from('<8I', b, o))
        # section header string table
        shstr_off = u32(b, self.e_shoff + self.e_shstrndx * self.e_shentsize + 16)
        self.sections = []
        for i in range(self.e_shnum):
            o = self.e_shoff + i * self.e_shentsize
            (no, st, fl, addr, off, size, _l, _i, _a, esz) = \
                struct.unpack_from('<10I', b, o)
            end = b.index(b'\0', shstr_off + no)
            name = b[shstr_off + no:end].decode('ascii', 'replace')
            self.sections.append(Section(name, st, fl, addr, off, size, esz))

    def section_at_vaddr(self, vaddr):
        for s in self.sections:
            if s.loadable and s.contains(vaddr):
                return s
        return None

    def vaddr_to_off(self, vaddr):
        s = self.section_at_vaddr(vaddr)
        if s is None:
            return None
        return s.off + (vaddr - s.addr)

    def read_vaddr(self, vaddr, n):
        off = self.vaddr_to_off(vaddr)
        if off is None:
            return None
        return self.blob[off:off + n]

    def section_named(self, name):
        for s in self.sections:
            if s.name == name:
                return s
        return None


# ── string extraction ──────────────────────────────────────────────────────

def extract_strings(img, min_len=STR_MIN_LEN):
    """Scan every loaded section for NUL-terminated printable-ASCII runs.

    Returns list of (file_off, vaddr, section_name, text). Runs may contain
    C-string whitespace (\\t \\n \\r) — e.g. `sceGs...%d!!\\n` diagnostics —
    as long as the whole run terminates at NUL. Shift-JIS / other non-ASCII
    bytes simply terminate a run — English diagnostic strings come through
    clean.
    """
    _WS = frozenset((0x09, 0x0A, 0x0D))
    out = []
    for s in img.sections:
        if not s.loadable:
            continue
        data = img.blob[s.off:s.off + s.size]
        i = 0
        n = len(data)
        while i < n:
            if 0x20 <= data[i] < 0x7F:
                j = i
                ok = True
                while j < n:
                    c = data[j]
                    if c == 0:
                        break
                    if not (0x20 <= c < 0x7F or c in _WS):
                        ok = False
                        break
                    j += 1
                if ok and j < n and data[j] == 0 and j - i >= min_len:
                    out.append((s.off + i, s.addr + i, s.name,
                                data[i:j].decode('ascii')))
                i = j + 1
            else:
                i += 1
    return out


def _matcher(arg, ci):
    """<arg> as plain substring, or /regex/ when wrapped in slashes."""
    if len(arg) > 2 and arg.startswith('/') and arg.endswith('/'):
        rx = re.compile(arg[1:-1], re.IGNORECASE if ci else 0)
        return rx.search
    needle = arg.lower() if ci else arg
    return lambda s: needle in (s.lower() if ci else s)


# ── xref resolver (lui/addiu address formation + data pointers) ────────────

def _hi_lo(vaddr):
    """(hi16, lo16) for the GAS %hi/%lo convention: lo is sign-extended, so
    hi is rounded up when lo >= 0x8000."""
    hi = (vaddr + 0x8000) >> 16
    lo = vaddr - (hi << 16)
    return hi & 0xFFFF, lo & 0xFFFF


def jump_xrefs(img, vaddr):
    """Find `jal`/`j` sites targeting `vaddr` — direct call/jump encoding
    (instr[25:0] = target>>2). This is how function addresses are actually
    referenced; lui/addiu only appears for function *pointers*."""
    text = img.section_named('.text')
    if text is None:
        return []
    # MIPS jump targets use the instr's own region bits; restrict to the
    # 256MB segment the .text lives in (same as every real caller).
    if (vaddr & 0xF0000000) != (text.addr & 0xF0000000) or vaddr & 3:
        return []
    idx = vaddr >> 2
    data = img.blob[text.off:text.off + text.size]
    hits = []
    for i in range(text.size // 4):
        w = u32(data, i * 4)
        op = w >> 26
        if op in (OP_J, OP_JAL) and (w & 0x3FFFFFF) == idx:
            hits.append({'addr': text.addr + i * 4,
                         'kind': 'jal' if op == OP_JAL else 'j'})
    return hits


def code_xrefs(img, vaddr):
    """Find .text sites that reference `vaddr` via a lui+op pair.

    Scans every `lui $rt, imm` in .text; when imm == %hi(V) (adjusted or raw
    split), scans forward up to XREF_LOOKAHEAD instructions for the first
    instruction that completes the address in $rt. Returns a list of dicts:
    {lui_addr, pair_addr, kind, pair_desc}.
    """
    text = img.section_named('.text')
    if text is None:
        return []
    hiA, loA = _hi_lo(vaddr)          # %hi/%lo (lo sign-extended)
    hiB, loB = (vaddr >> 16) & 0xFFFF, vaddr & 0xFFFF  # raw split (ori-style)
    data = img.blob[text.off:text.off + text.size]
    n_instr = text.size // 4
    hits = []
    for i in range(n_instr):
        w = u32(data, i * 4)
        if w >> 26 != OP_LUI:
            continue
        imm = w & 0xFFFF
        if imm not in (hiA, hiB):
            continue
        rt = (w >> 16) & 0x1F
        lui_addr = text.addr + i * 4
        conv_A = (imm == hiA)
        # scan forward for the completing instruction on the same register
        for k in range(1, XREF_LOOKAHEAD + 1):
            j = i + k
            if j >= n_instr:
                break
            w2 = u32(data, j * 4)
            op2 = w2 >> 26
            rs2 = (w2 >> 21) & 0x1F
            rt2 = (w2 >> 16) & 0x1F
            rd2 = (w2 >> 11) & 0x1F
            imm2 = w2 & 0xFFFF
            addr2 = text.addr + j * 4
            if rs2 == rt and op2 in LO_MATERIALIZE_OPS:
                lo = loA if op2 in (OP_ADDIU, OP_DADDIU, OP_ADDI, OP_DADDI) \
                    and conv_A else loB
                # also accept the same numeric lo under either convention
                if imm2 == loA or imm2 == loB:
                    hits.append({
                        'lui_addr': lui_addr, 'pair_addr': addr2,
                        'kind': 'addr-materialize',
                        'pair_desc': f'{MNEMONIC[op2]} $r{rt},$r{rt},0x{imm2:04x}'})
                    break
            if rs2 == rt and op2 in MEM_OPS:
                if imm2 == loA:
                    hits.append({
                        'lui_addr': lui_addr, 'pair_addr': addr2,
                        'kind': 'data-access',
                        'pair_desc': f'{MNEMONIC.get(op2, op2)} 0x{imm2:04x}($r{rt})'})
                    break
                # non-matching offset: reg still holds hi<<16, keep scanning
            # register clobbered -> chain dead
            if op2 in I_DEST_OPS and rt2 == rt:
                break
            if op2 == OP_SPECIAL and rd2 == rt:
                break
    return hits


def data_xrefs(img, vaddr):
    """Find u32 little-endian words == vaddr in any loaded section
    (pointer tables, global pointers, jump/data references)."""
    needle = struct.pack('<I', vaddr)
    hits = []
    for s in img.sections:
        if not s.loadable or s.name == '.text':
            continue
        data = img.blob[s.off:s.off + s.size]
        start = 0
        while True:
            idx = data.find(needle, start)
            if idx < 0:
                break
            hits.append({'off': s.off + idx, 'vaddr': s.addr + idx,
                         'section': s.name})
            start = idx + 1
    return hits


# ── disassembly ────────────────────────────────────────────────────────────

def disasm(img, vaddr, before, after):
    try:
        from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS64, \
            CS_MODE_LITTLE_ENDIAN
    except ImportError:
        sys.stderr.write('capstone required for --disasm (pip install '
                         'capstone)\n')
        return 3
    start = max(0, vaddr - before * 4)
    # align to the containing section so we don't read out of bounds
    sec = img.section_at_vaddr(vaddr)
    if sec is None:
        sys.stderr.write(f'vaddr {vaddr:#x} is not inside a loaded section\n')
        return 2
    start = max(start, sec.addr)
    end = min(vaddr + after * 4, sec.addr + sec.size)
    code = img.read_vaddr(start, end - start)
    md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 | CS_MODE_LITTLE_ENDIAN)
    # capstone aborts on R5900-only encodings it doesn't know (e.g. the EE
    # `mult rd,rs,rt` form). Walk word-by-word so one bad instruction only
    # emits a `.word` marker instead of truncating the whole window.
    pos = 0
    while pos < len(code):
        addr = start + pos
        ins = next(md.disasm(code[pos:pos + 4], addr), None)
        mark = '>>' if addr == vaddr else '  '
        if ins is None:
            print(f'{mark} {addr:#010x}: {code[pos:pos+4].hex():8}  '
                  f'.word      0x{u32(code, pos):08x}')
        else:
            print(f'{mark} {ins.address:#010x}: {ins.bytes.hex():8}  '
                  f'{ins.mnemonic:10} {ins.op_str}')
        pos += 4
    return 0


# ── DVP overlay table ──────────────────────────────────────────────────────

def ovlytab(img):
    """Parse `.DVP.ovlytab` — array of 12-byte {name_ptr, target_vaddr, f3}
    records; names point into `.DVP.ovlystrtab` (both carry a runtime vaddr
    of 0x21370f0 — they are link-time bookkeeping, not in the load image).
    """
    tab = img.section_named('.DVP.ovlytab')
    strtab = img.section_named('.DVP.ovlystrtab')
    if tab is None or strtab is None:
        return []
    rows = []
    for i in range(tab.size // (tab.entsz or 12)):
        name_ptr, target, f3 = struct.unpack_from(
            '<3I', img.blob, tab.off + i * 12)
        # name_ptr is a vaddr into .DVP.ovlystrtab
        off = strtab.off + (name_ptr - strtab.addr)
        if 0 <= off - strtab.off < strtab.size:
            end = img.blob.index(b'\0', off)
            name = img.blob[off:end].decode('ascii', 'replace')
        else:
            name = f'<bad ptr {name_ptr:#x}>'
        rows.append({'idx': i, 'name_ptr': name_ptr, 'target': target,
                     'f3': f3, 'name': name})
    return rows


def overlay_sections(img):
    return [s for s in img.sections if s.name.startswith('.DVP.overlay.')]


# ── CLI ────────────────────────────────────────────────────────────────────

def _write_csv(path, fields, rows):
    os.makedirs(os.path.dirname(os.path.abspath(path)) or '.', exist_ok=True)
    with open(path, 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(fields)
        w.writerows(rows)
    print(f'wrote {len(rows)} rows -> {path}')


def main(argv=None):
    ap = argparse.ArgumentParser(
        description='SLPS_250.88 MIPS probe (ELF/strings/xrefs/disasm)')
    ap.add_argument('--elf', default=DEFAULT_ELF)
    ap.add_argument('-i', '--ignore-case', action='store_true')
    ap.add_argument('--sections', action='store_true')
    ap.add_argument('--strings', metavar='PAT')
    ap.add_argument('--xrefs', metavar='PAT',
                    help='resolve code+data xrefs for strings matching PAT')
    ap.add_argument('--xrefs-addr', metavar='VADDR',
                    help='resolve xrefs to a literal vaddr (hex)')
    ap.add_argument('--disasm', metavar='VADDR')
    ap.add_argument('--disasm-off', metavar='FOFF',
                    help='disasm window at a file offset instead of vaddr')
    ap.add_argument('--before', type=int, default=16)
    ap.add_argument('--after', type=int, default=48)
    ap.add_argument('--ovlytab', action='store_true')
    ap.add_argument('--csv', metavar='OUT.csv')
    ap.add_argument('--min-len', type=int, default=STR_MIN_LEN)
    args = ap.parse_args(argv)

    img = ElfImage(args.elf)
    print(f'# {args.elf}')
    print(f'# ELF32 machine={img.e_machine} type={ELF_TYPES.get(img.e_type, img.e_type)}'
          f' entry={img.e_entry:#x} flags={img.e_flags:#x} '
          f'{img.e_phnum} phdrs {img.e_shnum} sections')

    did = False

    if args.sections:
        did = True
        rows = []
        for i, (t, off, va, pa, fsz, msz, fl, al) in enumerate(img.phdrs):
            rows.append(('phdr', i, f'{t:#x}', f'{off:#x}', f'{va:#x}',
                         f'{fsz:#x}', f'{msz:#x}', f'{fl:#x}'))
            print(f'phdr[{i}] type={t:#x} off={off:#x} vaddr={va:#x} '
                  f'filesz={fsz:#x} memsz={msz:#x} flags={fl:#x}')
        for i, s in enumerate(img.sections):
            rows.append(('shdr', i, s.name, f'{s.off:#x}', f'{s.addr:#x}',
                         f'{s.size:#x}', f'{s.shtype:#x}', f'{s.flags:#x}'))
            print(f'shdr[{i:2}] {s.name:38} type={s.shtype:#010x} '
                  f'flags={s.flags:#x} addr={s.addr:#x} off={s.off:#x} '
                  f'size={s.size:#x}')
        if args.csv:
            _write_csv(args.csv,
                       ['kind', 'idx', 'name_or_type', 'file_off', 'vaddr',
                        'size_or_filesz', 'type_or_memsz', 'flags'],
                       rows)

    if args.strings is not None:
        did = True
        match = _matcher(args.strings, args.ignore_case)
        rows = [(f'{o:#x}', f'{v:#x}', s, t)
                for o, v, s, t in extract_strings(img, args.min_len)
                if match(t)]
        for r in rows:
            print(f'{r[0]:>10} {r[1]:>10} {r[2]:>10} {r[3]!r}')
        print(f'# {len(rows)} matching strings')
        if args.csv:
            _write_csv(args.csv, ['file_off', 'vaddr', 'section', 'string'],
                       rows)

    if args.xrefs is not None:
        did = True
        match = _matcher(args.xrefs, args.ignore_case)
        strs = [(o, v, s, t) for o, v, s, t in extract_strings(img, args.min_len)
                if match(t)]
        rows = _resolve_and_print(img, strs)
        if args.csv:
            _write_csv(args.csv,
                       ['string', 'string_vaddr', 'string_off', 'section',
                        'xref_kind', 'xref_vaddr', 'detail'],
                       rows)

    if args.xrefs_addr:
        did = True
        vaddr = int(args.xrefs_addr, 0)
        rows = _resolve_and_print(
            img, [(None, vaddr, '', f'<vaddr {vaddr:#x}>')])
        if args.csv:
            _write_csv(args.csv,
                       ['string', 'string_vaddr', 'string_off', 'section',
                        'xref_kind', 'xref_vaddr', 'detail'],
                       rows)

    if args.ovlytab:
        did = True
        rows = []
        for r in ovlytab(img):
            print(f'ovly[{r["idx"]}] name_ptr={r["name_ptr"]:#x} '
                  f'target={r["target"]:#x} f3={r["f3"]:#x} name={r["name"]}')
            rows.append((r['idx'], f'{r["name_ptr"]:#x}', f'{r["target"]:#x}',
                         f'{r["f3"]:#x}', r['name']))
        for s in overlay_sections(img):
            nonzero = any(img.blob[s.off:s.off + s.size])
            print(f'stub {s.name:45} off={s.off:#x} size={s.size:#x} '
                  f'nonzero_bytes={nonzero}')
            rows.append(('stub', s.name, f'{s.off:#x}', f'{s.size:#x}',
                         f'nonzero={nonzero}'))
        if args.csv:
            _write_csv(args.csv,
                       ['idx', 'name_ptr_or_name', 'target_or_off',
                        'f3_or_size', 'name_or_flag'],
                       rows)

    if args.disasm or args.disasm_off:
        did = True
        if args.disasm:
            vaddr = int(args.disasm, 0)
        else:
            vaddr = img.sections[1].addr + \
                (int(args.disasm_off, 0) - img.sections[1].off)
            s = None
            for sec in img.sections:
                if sec.off <= int(args.disasm_off, 0) < sec.off + sec.size \
                        and sec.loadable:
                    s = sec
                    break
            if s is None:
                sys.stderr.write('file off not inside a loaded section\n')
                return 2
            vaddr = s.addr + (int(args.disasm_off, 0) - s.off)
        return disasm(img, vaddr, args.before, args.after)

    if not did:
        ap.print_help()
        return 2
    return 0


def _resolve_and_print(img, strs):
    rows = []
    for off, v, s, t in strs:
        cx = code_xrefs(img, v) if v is not None else []
        jx = jump_xrefs(img, v) if v is not None else []
        dx = data_xrefs(img, v) if v is not None else []
        print(f'== {t!r} @ off={off and hex(off)} vaddr={v:#x} ({s}) — '
              f'{len(cx)} code + {len(jx)} jump + {len(dx)} data xrefs')
        for h in jx:
            print(f'   jump {h["kind"]}@={h["addr"]:#x}')
            rows.append((t, f'{v:#x}', f'{off:#x}' if off else '', s,
                         h['kind'], f'{h["addr"]:#x}', ''))
        for h in cx:
            print(f'   code lui@={h["lui_addr"]:#x} pair@={h["pair_addr"]:#x} '
                  f'{h["kind"]}: {h["pair_desc"]}')
            rows.append((t, f'{v:#x}', f'{off:#x}' if off else '', s,
                         h['kind'], f'{h["lui_addr"]:#x}',
                         f'pair@{h["pair_addr"]:#x} {h["pair_desc"]}'))
        for h in dx:
            print(f'   data ptr@ off={h["off"]:#x} vaddr={h["vaddr"]:#x} '
                  f'({h["section"]})')
            rows.append((t, f'{v:#x}', f'{off:#x}' if off else '', s,
                         'data-ptr', f'{h["vaddr"]:#x}',
                         f'{h["section"]} off={h["off"]:#x}'))
    return rows


if __name__ == '__main__':
    sys.exit(main())
