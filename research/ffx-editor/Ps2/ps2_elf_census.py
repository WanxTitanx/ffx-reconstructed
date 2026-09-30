#!/usr/bin/env python3
"""ps2_elf_census.py — PS2 executable census scanner (stdlib-only).

Mission (Jarvis-ELF-HUNT, wave-15 lane 2026-09-18): locate every PS2-
executable-like asset in the FFX corpus — standalone ELFs (SLPS_*/SCUS_*/
SLES_*/MENU*.ELF), IOP modules (*.IRX), IOPRP ROMDIR images, embedded ELFs
inside blobs (.bin/.dat/.iso/.vbf/SRYK/raw chunks) — and classify each hit
as EE main code vs IOP module vs non-PS2 so the .clp<->.fmt binding and
Voice*Mapper residuals know which binary answers their questions.

WHAT IT DOES
  - walks root dirs (skips VCS/cache/system dirs by name)
  - header-checks every file's first 64 bytes (ELF/PE/SRYK/ROMDIR/ZIP/ISO9660)
  - name-matches executable-ish files (*.elf, *.irx, SLPS_*, IOPRP*.IMG,
    SYSTEM.CNF, MENU*.*) and records even non-ELF ones as PARTIAL rows
  - byte-scans candidate containers for embedded \\x7fELF at any offset
    (files >= --embed-min, or any file whose extension looks container-ish)
  - parses ELF32 headers: class/endian/e_type/e_machine/entry/phdrs/shdrs
    and classifies MIPS EE-exec vs IOP-module (e_type 0xFF80) vs other-arch
  - parses IOPRP*.IMG ROMDIR tables into per-module rows (each embedded
    IOP module is itself an IRX-style image)
  - for .vbf (SRYK) archives: reads the TOC (u64 numFiles + 16B MD5 table +
    32B entries + UTF-8 name table, format per
    docs/reverse/FFX_STRUCTURE_COMPLETE_2026-09-14.md sec 11.11) and reports
    member names that look executable — a definitive negative when zero hit
  - for .zip archives: checks member names + member magic for ELFs
  - for .iso: reports volume id; the raw byte-scan then finds the embedded
    boot ELF/IRX at their LBA offsets
  - optional --needles: ASCII needle census inside every parsed MIPS ELF
    (TEX2.CBP, .clp, .fmt, voice/mapper, IRX/module names, host0:, cdrom)
    so callers get direct evidence that e.g. SLPS_250.88 contains the menu
    texture-bind + voice-mapper code

OUTPUT
  CSV rows: path,size,magic,type,verdict,evidence,container,container_offset
  verdicts: PROVEN (header parsed), PARTIAL (name-matched but not ELF /
    structure found semantics open), NEGATIVE (container fully enumerated,
    no exec members), NOT-PS2 (non-MIPS executable), SKIP (unreadable).

Evidence-standard note (repo convention): PROVEN = parsed bytes/header +
decoded semantics; PARTIAL = structure found but semantics open; OPEN =
not found (census-level conclusion, recorded in the doc not per-row).

USAGE
  python3 ps2_elf_census.py ROOT [ROOT ...] --csv OUT.csv [--needles]
  python3 ps2_elf_census.py --default-roots --csv out.csv
  python3 ps2_elf_census.py FILE --csv out.csv   (single file mode)

Exit code: 0 always for the scan itself; 2 on argument errors.
"""

import argparse
import csv
import os
import re
import struct
import sys
import zipfile

# ── tunables ──────────────────────────────────────────────────────────────
CHUNK = 8 * 1024 * 1024          # scan block size
OVERLAP = 64                     # overlap so \\x7fELF at block edge is caught
EMBED_MIN_DEFAULT = 512 * 1024   # files >= this get the embedded-ELF scan
MAX_EMBEDDED_PER_FILE = 256      # safety cap vs pathological fake-ELF spam
ELF_MIN_HEADER = 52              # ELF32 e_ehsize

# extensions that look like they could CONTAIN an embedded ELF at any size
CONTAINER_EXTS = {
    '.bin', '.dat', '.img', '.iso', '.vbf', '.sryk', '.msb', '.pak', '.arc',
    '.vol', '.big', '.fsq', '.ps2', '.rbin', '.sbin', '.dcp', '.ffx', '.cat',
    '.hdr', '.raw', '.chunk', '.lba', '.pack', '.bundle', '.assets', '.i64',
    '.id0', '.id1', '.id2', '.nam', '.til', '.res', '.rom', '.dvd', '.cd',
}
# compressed containers: raw byte-scan is pointless; handled via member APIs
ARCHIVE_SKIP_SCAN = {'.zip', '.jar', '.7z', '.rar', '.gz', '.xz', '.zst',
                     '.lz4', '.cab', '.bz2', '.tar'}

SKIP_DIRNAMES = {
    '.git', '.svn', '.hg', 'node_modules', '__pycache__', '$recycle.bin',
    'system volume information', 'lost+found', '.venv', 'venv', '.mypy_cache',
    '.pytest_cache', '.idea', '.vs', '.terraform',
}

# file names that mark PS2 executables even before magic is checked
RE_PS2_SERIAL = re.compile(
    r'^(SLPS|SCUS|SLES|SCES|SCPS|SLPM|SLUS|SLKA|SCED|SCPH|PBPX|SLAJ|TCPS|'
    r'CPCS|GUST|KIDM|NPJA|NPUA|NPUD|PAPX|PCPX|SCAJ|SCPB|TCES)_?[\d.]+',
    re.IGNORECASE)
RE_MENU_ELF = re.compile(r'^menu.*\.(elf|ELF)$|^menu_?main', re.IGNORECASE)

# needles for the relevance pass (hit => substring exists inside the ELF)
NEEDLES = [
    b'TEX2.CBP', b'tex2.cbp', b'.CBP', b'.cbp', b'.CLP', b'.clp',
    b'.FMT', b'.fmt', b'Voice', b'voice', b'Mapper', b'mapper',
    b'.IRX', b'.irx', b'IOPRP', b'SIO2MAN', b'MCMAN', b'LIBSD',
    b'module', b'MODULE', b'rom0:', b'rom1:', b'host0:', b'cdrom',
    b'menu', b'MENU', b'.ebp', b'.EBP', b'FFX', b'EE/', b'IOP',
]

ELF_TYPES = {0: 'NONE', 1: 'REL', 2: 'EXEC', 3: 'DYN', 4: 'CORE',
             0xFF80: 'SCE-IOP-REL-EXEC', 0xFF81: 'SCE-IOP-REL',
             0xFF91: 'SCE-EE-REL', 0xFEFF: 'SCE-EE-IRX2?',
             0x7000: 'LOPROC', 0xFFFF: 'HIPROC'}
ELF_MACHINES = {0: 'NONE', 2: 'SPARC', 3: 'x86', 8: 'MIPS', 20: 'PPC',
                21: 'PPC64', 40: 'ARM', 42: 'SH', 50: 'IA64', 62: 'x86-64',
                75: 'VAX', 87: 'NEC-V800', 88: 'M20', 89: 'CPU32',
                140: 'TILE-Gx', 183: 'AArch64', 190: 'CUDA', 243: 'RISCV',
                0xFFFF: 'SCE-EE-R5900-ALIAS'}


def u16(b, o): return struct.unpack_from('<H', b, o)[0]
def u32(b, o): return struct.unpack_from('<I', b, o)[0]
def u64(b, o): return struct.unpack_from('<Q', b, o)[0]


def parse_elf32(hdr, off=0):
    """Validate+parse an ELF32 header at hdr[off:off+64]. Returns dict|None."""
    if len(hdr) - off < ELF_MIN_HEADER:
        return None
    if hdr[off:off + 4] != b'\x7fELF':
        return None
    ei_class = hdr[off + 4]      # 1=32 2=64
    ei_data = hdr[off + 5]       # 1=LE 2=BE
    ei_ver = hdr[off + 6]
    if ei_ver != 1 or ei_class not in (1, 2) or ei_data != 1:
        # PS2 is always LE 32-bit; BE/64 recorded only when clearly valid
        if ei_class not in (1, 2) or ei_data not in (1, 2):
            return None
    if ei_class != 1:
        # ELF64: still record, but header layout differs — parse common fields
        e_type = u16(hdr, off + 16)
        e_machine = u16(hdr, off + 18)
        e_entry = u64(hdr, off + 24)
        e_phoff = u64(hdr, off + 32)
        e_shoff = u64(hdr, off + 40)
        e_flags = u32(hdr, off + 48)
        e_ehsize = u16(hdr, off + 52)
        e_phentsize = u16(hdr, off + 54)
        e_phnum = u16(hdr, off + 56)
        e_shentsize = u16(hdr, off + 58)
        e_shnum = u16(hdr, off + 60)
        e_shstrndx = u16(hdr, off + 62)
    else:
        e_type = u16(hdr, off + 16)
        e_machine = u16(hdr, off + 18)
        e_version = u32(hdr, off + 20)
        if e_version != 1:
            return None
        e_entry = u32(hdr, off + 24)
        e_phoff = u32(hdr, off + 28)
        e_shoff = u32(hdr, off + 32)
        e_flags = u32(hdr, off + 36)
        e_ehsize = u16(hdr, off + 40)
        e_phentsize = u16(hdr, off + 42)
        e_phnum = u16(hdr, off + 44)
        e_shentsize = u16(hdr, off + 46)
        e_shnum = u16(hdr, off + 48)
        e_shstrndx = u16(hdr, off + 50)
        if e_ehsize < ELF_MIN_HEADER or e_phnum > 512 or e_shnum > 0x8000:
            return None
        if e_phnum and e_phentsize != 32:
            return None
    return {
        'class': ei_class, 'data': ei_data,
        'e_type': e_type, 'e_machine': e_machine, 'e_entry': e_entry,
        'e_phoff': e_phoff, 'e_shoff': e_shoff, 'e_flags': e_flags,
        'e_ehsize': e_ehsize, 'e_phentsize': e_phentsize, 'e_phnum': e_phnum,
        'e_shentsize': e_shentsize, 'e_shnum': e_shnum,
        'e_shstrndx': e_shstrndx,
    }


def classify_elf(info):
    """Return (type_label, verdict) for a parsed ELF dict."""
    mach = info['e_machine']
    etype = info['e_type']
    entry = info['e_entry']
    mach_name = ELF_MACHINES.get(mach, 'mach-0x%X' % mach)
    if mach == 8:  # MIPS
        if etype == 0xFF80 or etype == 0xFF81:
            return 'iop-module', 'PROVEN'
        if etype == 2:  # EXEC
            if 0x00100000 <= entry < 0x02000000:
                return 'ee-executable', 'PROVEN'
            if entry < 0x00100000:
                return 'iop-executable', 'PROVEN'
            return 'mips-exec-highaddr', 'PARTIAL'
        if etype in (0xFF91,):
            return 'ee-relocatable', 'PARTIAL'
        return 'mips-elf-other', 'PARTIAL'
    return 'elf-%s' % mach_name, 'NOT-PS2'


def elf_evidence(info):
    return ('ELF%d %s type=%s(0x%04X) entry=0x%08X phnum=%d shnum=%d '
            'phoff=0x%X shoff=0x%X flags=0x%08X' % (
                32 if info['class'] == 1 else 64,
                ELF_MACHINES.get(info['e_machine'],
                                 'mach-0x%X' % info['e_machine']),
                ELF_TYPES.get(info['e_type'], '0x%X' % info['e_type']),
                info['e_type'], info['e_entry'], info['e_phnum'],
                info['e_shnum'], info['e_phoff'], info['e_shoff'],
                info['e_flags']))


def section_names(path, info):
    """Best-effort ELF section-name list (for evidence); '' on failure."""
    if info['class'] != 1 or not info['e_shoff'] or not info['e_shnum'] \
            or info['e_shentsize'] < 40 or info['e_shnum'] > 512:
        return ''
    try:
        with open(path, 'rb') as f:
            f.seek(info['e_shoff'])
            sh = f.read(info['e_shnum'] * info['e_shentsize'])
            if len(sh) < info['e_shnum'] * info['e_shentsize']:
                return ''
            strx = info['e_shstrndx']
            if strx >= info['e_shnum']:
                return ''
            str_off = u32(sh, strx * info['e_shentsize'] + 16)
            str_sz = u32(sh, strx * info['e_shentsize'] + 20)
            if str_sz == 0 or str_sz > 0x100000:
                return ''
            f.seek(str_off)
            strs = f.read(str_sz)
            names = []
            for i in range(info['e_shnum']):
                no = u32(sh, i * info['e_shentsize'])
                if no >= len(strs):
                    names.append('?')
                    continue
                end = strs.find(b'\x00', no)
                nm = strs[no:end if end >= 0 else len(strs)]
                names.append(nm.decode('ascii', 'replace'))
            return ' '.join(n for n in names if n)
    except OSError:
        return ''


def parse_ioprp(path, rows, container_label):
    """Parse an IOPRP*.IMG (RESET+ROMDIR) and emit per-module rows."""
    try:
        with open(path, 'rb') as f:
            head = f.read(0x1000)
    except OSError:
        return 0
    if not head.startswith(b'RESET'):
        return 0
    entries = []
    off = 0
    # ROMDIR entries are 16B: name[10] | u16 extinfo_size | u32 file_size
    while off + 16 <= len(head):
        name = head[off:off + 10].split(b'\x00', 1)[0]
        extinfo = u16(head, off + 10)
        fsize = u32(head, off + 12)
        if not name:
            break
        try:
            nm = name.decode('ascii')
        except UnicodeDecodeError:
            break
        if not re.match(r'^[A-Za-z0-9_.+\-]+$', nm):
            break
        entries.append((nm, extinfo, fsize, off))
        off += 16
    # locate EXTINFO entry -> extinfo region byte size
    extinfo_sz = next((s for n, _, s, _ in entries if n == 'EXTINFO'), 0)
    # Module data starts after the 16B zeroed terminator entry that follows
    # the last romdir entry, plus the extinfo region, 16B-aligned.
    # Verified against IOPRP234.IMG (FFX Intl SLPS-25088 disc): entries end
    # at 0x120, terminator 0x120-0x12F, extinfo 0x130+0x244=0x374 -> first
    # module LOADCORE at 0x380 (16B align). (Jarvis-ELF-HUNT 2026-09-18)
    end_of_tables = off + 16 + extinfo_sz
    cursor = (end_of_tables + 15) & ~15
    count = 0
    try:
        fsize_total = os.path.getsize(path)
    except OSError:
        fsize_total = 0
    for nm, ext, fsz, eoff in entries:
        if nm in ('RESET', 'ROMDIR', 'EXTINFO'):
            continue
        # find module data offset: sequential layout after tables, 16B-aligned
        magic = ''
        detail = ''
        if fsz and cursor < fsize_total:
            try:
                with open(path, 'rb') as f:
                    f.seek(cursor)
                    hdr = f.read(64)
                info = parse_elf32(hdr)
                if info:
                    t, v = classify_elf(info)
                    magic = 'ELF32'
                    detail = elf_evidence(info)
                    rows.append(row(path, fsz, 'ELF32', 'romdir-module:%s' % t,
                                    'PROVEN', 'module=%s off=0x%X %s' %
                                    (nm, cursor, detail), path, cursor))
                else:
                    rows.append(row(path, fsz, 'raw', 'romdir-module',
                                    'PARTIAL',
                                    'module=%s off=0x%X no-elf-magic' %
                                    (nm, cursor), path, cursor))
                count += 1
            except OSError:
                pass
            cursor = (cursor + fsz + 15) & ~15
        else:
            rows.append(row(path, fsz, 'romdir-entry', 'romdir-module',
                            'PARTIAL', 'module=%s size=0' % nm, path, 0))
            count += 1
    return count


def row(path, size, magic, ftype, verdict, evidence, container='',
        container_offset=0):
    return {'path': path, 'size': size, 'magic': magic, 'type': ftype,
            'verdict': verdict, 'evidence': evidence, 'container': container,
            'container_offset': container_offset}


def name_classify(fn):
    lo = fn.lower()
    if lo.endswith('.irx'):
        return 'irx-name'
    if lo.endswith('.elf'):
        return 'elf-name'
    if RE_PS2_SERIAL.match(fn):
        return 'ps2-serial'
    if lo.startswith('ioprp') and lo.endswith('.img'):
        return 'ioprp-name'
    if fn.upper() == 'SYSTEM.CNF':
        return 'system-cnf'
    if RE_MENU_ELF.match(fn):
        return 'menu-candidate'
    return ''


def looks_iso9660(path):
    try:
        with open(path, 'rb') as f:
            f.seek(0x8001)
            return f.read(5) == b'CD001'
    except OSError:
        return False


def iso_volume_id(path):
    try:
        with open(path, 'rb') as f:
            f.seek(0x8028)
            return f.read(32).decode('ascii', 'replace').strip()
    except OSError:
        return ''


def vbf_members(path, cap=400000):
    """Read a SRYK/VBF TOC and return member names. Stdlib parse of the
    documented layout: u32 'SRYK' | u32 headerLength | u64 numFiles |
    numFiles*16B md5 | numFiles*32B entries | u32 strTableSize | names."""
    try:
        with open(path, 'rb') as f:
            head = f.read(24)
            if len(head) < 24 or head[:4] != b'SRYK':
                return None
            # layout: u32 'SRYK' | u32 headerLength | u64 numFiles @+8 |
            # numFiles*16B md5 | numFiles*32B entries | u32 strTableSize|names
            num = u64(head, 8)
            if num > cap:
                return None
            f.seek(16 + num * 16)
            ents = f.read(num * 32)
            st = f.read(4)
            if len(st) < 4:
                return None
            stsz = u32(st, 0)
            strs = f.read(max(0, stsz - 4))
            names = strs.split(b'\x00')
            out = []
            for n in names:
                if n:
                    out.append(n.decode('utf-8', 'replace'))
            return out
    except OSError:
        return None


def zip_exec_members(path):
    out = []
    try:
        with zipfile.ZipFile(path) as z:
            for zi in z.infolist():
                n = zi.filename
                hit = bool(RE_PS2_SERIAL.search(os.path.basename(n))) or \
                    n.lower().endswith(('.irx', '.elf')) or \
                    'ioprp' in n.lower()
                magic = ''
                try:
                    with z.open(zi) as mf:
                        m = mf.read(4)
                    if m == b'\x7fELF':
                        magic = 'ELF'
                except (OSError, zipfile.BadZipFile, RuntimeError):
                    pass
                if hit or magic == 'ELF':
                    out.append((n, zi.file_size, magic or 'name-match'))
    except (OSError, zipfile.BadZipFile):
        return None
    return out


def embedded_scan(path, fsize, max_hits=MAX_EMBEDDED_PER_FILE):
    """Chunked \\x7fELF search. Yields (offset, info) for validated headers."""
    hits = 0
    pos = 0
    try:
        with open(path, 'rb') as f:
            tail = b''
            while True:
                buf = f.read(CHUNK)
                if not buf:
                    break
                data = tail + buf
                base = pos - len(tail)
                start = 0
                while True:
                    i = data.find(b'\x7fELF', start)
                    if i < 0:
                        break
                    abspos = base + i
                    start = i + 1
                    # validate: need 52B from i; if at buffer end, refetch
                    if i + ELF_MIN_HEADER <= len(data):
                        info = parse_elf32(data, i)
                        if info and info['e_machine'] == 8:
                            yield abspos, info
                            hits += 1
                            if hits >= max_hits:
                                return
                    else:
                        # header straddles block edge — read it directly
                        f2 = open(path, 'rb')
                        try:
                            f2.seek(abspos)
                            hdr = f2.read(64)
                        finally:
                            f2.close()
                        info = parse_elf32(hdr)
                        if info and info['e_machine'] == 8:
                            yield abspos, info
                            hits += 1
                            if hits >= max_hits:
                                return
                pos += len(buf)
                tail = data[-OVERLAP:] if len(data) >= OVERLAP else data
    except OSError:
        return


def needle_scan(path):
    """Return {needle: count} inside a file (single pass, read whole file —
    only called on parsed MIPS ELFs which are small enough)."""
    res = {}
    try:
        with open(path, 'rb') as f:
            data = f.read()
    except OSError:
        return res
    for n in NEEDLES:
        c = data.count(n)
        if c:
            res[n.decode('ascii', 'replace')] = c
    return res


def scan_file(path, args, rows):
    try:
        st = os.stat(path)
    except OSError:
        return
    fsize = st.st_size
    fn = os.path.basename(path)
    ext = os.path.splitext(fn)[1].lower()
    ncls = name_classify(fn)

    try:
        with open(path, 'rb') as f:
            head = f.read(64)
    except OSError:
        if ncls:
            rows.append(row(path, fsize, 'unreadable', ncls, 'SKIP',
                            'open failed'))
        return

    magic4 = head[:4]
    is_elf = magic4 == b'\x7fELF'
    is_mz = head[:2] == b'MZ'
    is_sryk = magic4 == b'SRYK'
    is_reset = head.startswith(b'RESET')
    is_zip = magic4 in (b'PK\x03\x04', b'PK\x05\x06')
    is_sce = magic4 == b'SCE\x00'
    is_psar = magic4 == b'PSAR'

    # ── 1. direct ELF ────────────────────────────────────────────────────
    if is_elf:
        info = parse_elf32(head)
        if info:
            t, v = classify_elf(info)
            ev = elf_evidence(info)
            secs = section_names(path, info) if args.sections else ''
            if secs:
                ev += ' | sections: ' + secs
            if args.needles and info['e_machine'] == 8:
                nh = needle_scan(path)
                if nh:
                    ev += ' | needles: ' + ','.join(
                        '%s=%d' % kv for kv in sorted(nh.items()))
            rows.append(row(path, fsize, 'ELF%d' %
                            (32 if info['class'] == 1 else 64), t, v, ev))
        else:
            rows.append(row(path, fsize, 'ELF-magic', 'elf-name' if ncls
                            else 'elf-badhdr', 'PARTIAL',
                            'magic ok, header invalid'))

    # ── 2. IOPRP / ROMDIR image ─────────────────────────────────────────
    ioprp_modules = 0
    if is_reset and (b'ROMDIR' in head[:64] or ncls == 'ioprp-name'):
        ioprp_modules = parse_ioprp(path, rows, path)
        rows.append(row(path, fsize, 'RESET+ROMDIR', 'ioprp-image', 'PROVEN',
                        'romdir modules=%d' % ioprp_modules))

    # ── 3. PE / MZ ──────────────────────────────────────────────────────
    if is_mz and (ext in ('.exe', '.dll', '.sys', '.irx', '.elf', '')
                  or ncls):
        rows.append(row(path, fsize, 'MZ/PE', 'pe-image', 'NOT-PS2',
                        'x86/windows image%s' %
                        (' (name match: %s)' % ncls if ncls else '')))

    # ── 3b. PS3 SCE-encrypted SELF / PSARC containers ───────────────────
    if is_sce:
        ver = u32(head, 8)
        hdr_sz = u16(head, 12)
        rows.append(row(path, fsize, 'SCE', 'ps3-self', 'NOT-PS2',
                        'PS3 SELF encrypted image ver=0x%08X hdrsz=0x%X '
                        '(not MIPS; body encrypted)' % (ver, hdr_sz)))
    if is_psar:
        rows.append(row(path, fsize, 'PSAR', 'ps3-psarc', 'PARTIAL',
                        'PSARC zlib container (PS3 data; not MIPS code)'))

    # ── 4. name-matched non-ELF files ───────────────────────────────────
    if ncls and not is_elf and not is_reset and not is_mz:
        mg = magic4.hex()
        if ncls == 'system-cnf':
            try:
                txt = head.decode('ascii', 'replace')
            except UnicodeDecodeError:
                txt = ''
            rows.append(row(path, fsize, 'text', 'system-cnf', 'PROVEN',
                            'cnf: ' + ' '.join(txt.split())))
        else:
            rows.append(row(path, fsize, 'magic-0x' + mg, ncls, 'PARTIAL',
                            'exec-ish name but magic is not ELF'))

    # ── 5. containers ───────────────────────────────────────────────────
    if is_sryk:
        members = vbf_members(path) if args.vbf_list else None
        if members is None:
            rows.append(row(path, fsize, 'SRYK', 'vbf-archive', 'PARTIAL',
                            'SRYK container; member list not read'))
        else:
            exec_names = [m for m in members if name_classify(
                os.path.basename(m)) or
                m.lower().endswith(('.irx', '.elf')) or
                RE_PS2_SERIAL.search(os.path.basename(m))]
            if exec_names:
                rows.append(row(path, fsize, 'SRYK', 'vbf-archive',
                                'PARTIAL',
                                'members=%d exec-names=%d: %s' % (
                                    len(members), len(exec_names),
                                    ';'.join(exec_names[:10]))))
            else:
                rows.append(row(path, fsize, 'SRYK', 'vbf-archive',
                                'NEGATIVE',
                                'members=%d exec-names=0 (TOC enumerated)'
                                % len(members)))
    elif ext == '.zip' or is_zip:
        zm = zip_exec_members(path)
        if zm is None:
            rows.append(row(path, fsize, 'ZIP?', 'zip-archive', 'PARTIAL',
                            'zip open failed'))
        elif zm:
            for n, s, mg in zm:
                rows.append(row(path, s, mg, 'zip-member:' +
                                (name_classify(os.path.basename(n)) or
                                 'elf'), 'PROVEN',
                                'member=%s' % n, path, 0))
        else:
            rows.append(row(path, fsize, 'ZIP', 'zip-archive', 'NEGATIVE',
                            'no exec-looking members'))
    elif ext == '.iso' and args.iso_check:
        iso = looks_iso9660(path)
        rows.append(row(path, fsize, 'CD001' if iso else 'no-cd001',
                        'iso-image', 'PARTIAL' if iso else 'PARTIAL',
                        ('ISO9660 vol=%s; byte-scan follows' %
                         iso_volume_id(path)) if iso else
                        'no ISO9660 descriptor at 0x8001'))

    # ── 6. embedded ELF scan ────────────────────────────────────────────
    want_embed = not args.no_embed and ext not in ARCHIVE_SKIP_SCAN and (
        fsize >= args.embed_min or (ext in CONTAINER_EXTS and fsize >= 64))
    # IOPRP already produced authoritative named-module rows; a raw embedded
    # scan would only duplicate them.
    if ioprp_modules:
        want_embed = False
    if want_embed and not is_elf:
        found = 0
        for off, info in embedded_scan(path, fsize):
            t, v = classify_elf(info)
            rows.append(row(path, fsize, 'ELF32@0x%X' % off,
                            'embedded-%s' % t, v,
                            'off=0x%X ' % off + elf_evidence(info),
                            path, off))
            found += 1
        if found == 0 and fsize >= args.embed_min:
            rows.append(row(path, fsize, 'no-elf-sig',
                            'blob-scanned', 'NEGATIVE',
                            'scanned %dB: no \\x7fELF' % fsize))


def walk_roots(roots, args, rows):
    for root in roots:
        if os.path.isfile(root):
            scan_file(root, args, rows)
            continue
        for dirpath, dirnames, filenames in os.walk(root):
            dirnames[:] = [d for d in dirnames
                           if d.lower() not in SKIP_DIRNAMES]
            for fn in filenames:
                scan_file(os.path.join(dirpath, fn), args, rows)


DEFAULT_ROOTS = [
    '/mnt/nvme-xpg/ffx_ps2',
    '/mnt/nvme-samsung/FFX Extracted',
    '/mnt/nvme-samsung/PS2_Dev',
    '/mnt/nvme-samsung/PS2_FFX_BACKUP_20260731',
    '/mnt/nvme-samsung/FFX_Extract',
    '/mnt/nvme-samsung/FFX-2',
    '/mnt/nvme-samsung/FFX_Backups',
    '/mnt/nvme-samsung/FFX Labs',
    '/mnt/nvme-samsung/ffx-goal-active',
    '/mnt/nvme-samsung/ffx-vm-archive-staging',
    '/mnt/nvme-samsung/ffx_ida_headless',
    '/mnt/nvme-samsung/ffx-task-artifacts',
    '/mnt/nvme-samsung/ffx-azit03-pre-vertexcolor-backup-2026-06-06',
    '/mnt/nvme-samsung/ffx-worktree-backup-2026-06-05',
    '/mnt/nvme-samsung/mapout_zone_decode',
    '/mnt/nvme-samsung/extractor_reconstruction',
    '/mnt/nvme-samsung/editor-stage',
    '/mnt/nvme-samsung/sPCK GS',
    '/mnt/nvme-samsung/psarc_repair_2026-09-15',
    '/mnt/nvme-samsung/SteamLibrary/steamapps/common/'
    'FINAL FANTASY FFX&FFX-2 HD Remaster',
    '/mnt/nvme-xpg/FFX_Data',
    '/mnt/nvme-xpg/Final Fantasy X-X2 - HD Remaster [FitGirl Re-repack]',
    '/mnt/nvme-xpg/FFX LOUCURAS',
    '/mnt/nvme-xpg/FFXProjectEditor',
    '/mnt/nvme-xpg/PCK Module',
    '/mnt/nvme-xpg/ffx-editor-velho',
    '/mnt/nvme-xpg/ffx-reconstructed bkp',
    '/mnt/nvme-xpg/ffx-editor-main',
    '/mnt/nvme-xpg/SteamLibrary/steamapps/common/'
    'FINAL FANTASY FFX&FFX-2 HD Remaster',
    '/mnt/ssd-kingston/ffx-reconstructed',
    '/mnt/ssd-kingston/ffx-editor-main',
    '/mnt/disco-velho/D/ffx-reconstructed',
    '/mnt/disco-velho/Backup C 2026-09-02/Root/f/ffx-reconstructed',
    '/mnt/disco-velho/FFX-Cloud-Receipts',
    '/mnt/disco-velho/Old C/Users/wande/ffx-editor-main',
    '/mnt/disco-velho/Old C/Users/wande/ffxed_source',
    '/mnt/disco-velho/Old C/Users/wande/ffx-verify-event',
    os.path.expanduser('~/Documents/ffx-editor-main'),
    os.path.expanduser('~/Documents/ffx-magic-re'),
    os.path.expanduser('~/Documents/ffx_reconstructed.pre-branch-switch.'
                       '2026-07-20'),
    os.path.expanduser('~/Documents/ffx-hooks'),
    os.path.expanduser('~/Documents/ffx-hooks-public'),
    os.path.expanduser('~/Documents/ffx-mod-launcher'),
    os.path.expanduser('~/Documents/ffx-mod-website'),
    os.path.expanduser('~/Documents/ffx-editor-worktrees'),
    os.path.expanduser('~/Documents/ffx-editor-release-staging'),
    os.path.expanduser('~/Documents/ffx-launcher-release-staging'),
    os.path.expanduser('~/Documents/FFX Mod Studio Backups'),
]


def main(argv=None):
    ap = argparse.ArgumentParser(description='PS2 executable census scanner')
    ap.add_argument('roots', nargs='*', help='files/dirs to scan')
    ap.add_argument('--default-roots', action='store_true',
                    help='use the built-in FFX corpus root list')
    ap.add_argument('--csv', help='write CSV rows here')
    ap.add_argument('--needles', action='store_true',
                    help='ASCII-needle census inside parsed MIPS ELFs')
    ap.add_argument('--sections', action='store_true',
                    help='include ELF section names in evidence')
    ap.add_argument('--vbf-list', action='store_true',
                    help='enumerate SRYK/VBF member names')
    ap.add_argument('--iso-check', action='store_true',
                    help='check .iso files for ISO9660 descriptor')
    ap.add_argument('--no-embed', action='store_true',
                    help='disable embedded \\x7fELF scan')
    ap.add_argument('--embed-min', type=int, default=EMBED_MIN_DEFAULT,
                    help='min file size for embedded scan (default %d)'
                    % EMBED_MIN_DEFAULT)
    ap.add_argument('--quiet', action='store_true')
    args = ap.parse_args(argv)

    roots = list(args.roots)
    if args.default_roots:
        roots += [r for r in DEFAULT_ROOTS if os.path.exists(r)]
    if not roots:
        ap.error('no roots given')

    rows = []
    walk_roots(roots, args, rows)

    if args.csv:
        with open(args.csv, 'w', newline='', encoding='utf-8') as f:
            w = csv.DictWriter(f, fieldnames=[
                'path', 'size', 'magic', 'type', 'verdict', 'evidence',
                'container', 'container_offset'])
            w.writeheader()
            w.writerows(rows)
    if not args.quiet:
        from collections import Counter
        c = Counter(r['verdict'] for r in rows)
        t = Counter(r['type'] for r in rows)
        print('rows=%d verdicts=%s' % (len(rows), dict(c)))
        for k, n in t.most_common(20):
            print('  type %-28s %d' % (k, n))
        for r in rows:
            if r['verdict'] == 'PROVEN' and 'embedded' not in r['type']:
                print('  HIT %-16s %s (%dB) %s' % (
                    r['type'], r['path'], r['size'], r['evidence'][:110]))
    return 0


if __name__ == '__main__':
    sys.exit(main())
