#!/usr/bin/env python3
# vbf_field04_derive.py — derivation hunt for the .vbf entry +0x04 packer stamp.
#
# Lane Jarvis-VBF-FIELD04 (2026-09-18). Reads ONLY the header region of each
# archive (never the 17-20GB payload areas). Emits:
#   docs/reverse/data/vbf_field04_derive.csv  — every candidate tested, hit/miss
#   docs/reverse/data/vbf_field04_derive.log  — human-readable verdict summary
#
# FIELD STATE (wave-13 machine-proof, re-verified this lane):
#   entry layout (32B LE): u32 blockListStart | u32 field_04 | u64 originalSize
#                          | u64 startOffset | u64 fileNameOffset
#   FFX_Data.vbf  : field_04 = 0x00A813F6 on all 71,972 non-empty records, 0 x7
#   FFX2_Data.vbf : field_04 = 0x003D13F6 on all 130,631 non-empty, 0 x6,755
#   metamenu.vbf  : field_04 == blockListStart verbatim on all 150 records
#   Runtime never reads +0x04 (FFX_BigFile_ReadVerifyHeader @0x61DC80 entry loop
#   touches only +0x00/+0x08/+0x0C/+0x18).
#
# THIS LANE'S NEW EVIDENCE (baked into the tests below):
#   * empty records leak `numFiles` into the hi32 of startOffset (+0x14):
#     so == (numFiles << 32) | stale_u32 for EVERY f04==0 record (7/7 FFX,
#     6755/6755 FFX2) — proves the packer serializes uninitialized/internal
#     state into dead fields => field_04 is consistent with a leaked
#     packer-process constant (pointer/seed/stamp), not content-derived.
#   * both stamps are (X << 16) | 0x13F6 with 64KB-aligned high part
#     (0xA80000 / 0x3D0000) — the exact shape of a leaked address
#     (region_base + fixed 0x13F6 offset) or a (tag<<16)|const composite.
#
# CANDIDATE FAMILIES TESTED (all previously-refuted ones re-run for the record):
#   A. per-entry relations: equality/xor/sub vs blockListStart, originalSize,
#      startOffset, fileNameOffset, entry index, md5-of-name prefix
#   B. region hashes: crc32/adler32/fnv1/fnv1a/djb2/sdbm/jenkins/murmur2/
#      murmur3/xxh32/fletcher16/fletcher32/sum16/bsd-sum over the md5 table,
#      entry table (raw + f04-zeroed), string table, block-size table,
#      full header, and header-without-entry-table — targets: both full
#      stamps, shared low16 0x13F6, and hi16 tags 0x00A8/0x003D
#   C. crypto digests: md5/sha1/sha256 of the same regions — all 4-byte
#      windows (LE+BE) and u16 windows vs targets
#   D. CRC16 battery (16 variants) over the same regions vs 0x13F6/0xA8/0x3D
#   E. name/label hashes: crc32/adler32/fnv1a/djb2/md5-windows of archive
#      file names and path spellings vs both stamps
#   F. timestamp decodes: DOS datetime (date<<16|time), unix, FILETIME-low
#   G. structural: stamp vs numFiles/headerLen/stringTableSize/blockCount/
#      fileSize linear & modular relations; factorization; byte anatomy
#
# Exit 0 always (analysis tool). Verdict printed at end.

import argparse
import binascii
import collections
import hashlib
import os
import struct
import sys
import zlib

BLOCK = 65536
MAGIC = 0x4B595253  # 'SRYK' LE

# ---------------------------------------------------------------- hash impls

def h_crc32(b):    return zlib.crc32(b) & 0xFFFFFFFF
def h_adler32(b):  return zlib.adler32(b) & 0xFFFFFFFF

def h_fnv1_32(b):
    h = 0x811C9DC5
    for c in b: h = (h * 0x01000193 ^ c) & 0xFFFFFFFF
    return h

def h_fnv1a_32(b):
    h = 0x811C9DC5
    for c in b: h = ((h ^ c) * 0x01000193) & 0xFFFFFFFF
    return h

def h_djb2(b):
    h = 5381
    for c in b: h = ((h << 5) + h + c) & 0xFFFFFFFF
    return h

def h_sdbm(b):
    h = 0
    for c in b: h = (c + (h << 6) + (h << 16) - h) & 0xFFFFFFFF
    return h

def h_jenkins(b):
    h = 0
    for c in b:
        h = (h + c) & 0xFFFFFFFF; h = (h + (h << 10)) & 0xFFFFFFFF; h ^= h >> 6
    h = (h + (h << 3)) & 0xFFFFFFFF; h ^= h >> 11; h = (h + (h << 15)) & 0xFFFFFFFF
    return h

def h_murmur2(b, seed=0x9747B28C):
    m, r = 0x5BD1E995, 24
    ln = len(b); h = (seed ^ ln) & 0xFFFFFFFF
    n = ln // 4
    for i in range(n):
        k = struct.unpack_from('<I', b, i * 4)[0]
        k = (k * m) & 0xFFFFFFFF; k ^= k >> r; k = (k * m) & 0xFFFFFFFF
        h = (h * m) & 0xFFFFFFFF; h ^= k
    tail = b[n * 4:]
    if len(tail) == 3: h ^= tail[2] << 16
    if len(tail) >= 2: h ^= tail[1] << 8
    if len(tail) >= 1: h ^= tail[0]; h = (h * m) & 0xFFFFFFFF
    h ^= h >> 13; h = (h * m) & 0xFFFFFFFF; h ^= h >> 15
    return h

def h_murmur3(b, seed=0):
    c1, c2 = 0xCC9E2D51, 0x1B873593
    h = seed & 0xFFFFFFFF
    n = len(b) // 4
    for i in range(n):
        k = struct.unpack_from('<I', b, i * 4)[0]
        k = (k * c1) & 0xFFFFFFFF; k = ((k << 15) | (k >> 17)) & 0xFFFFFFFF; k = (k * c2) & 0xFFFFFFFF
        h ^= k; h = ((h << 13) | (h >> 19)) & 0xFFFFFFFF
        h = (h * 5 + 0xE6546B64) & 0xFFFFFFFF
    tail = b[n * 4:]; k = 0
    for i, c in enumerate(tail): k |= c << (8 * i)
    if tail:
        k = (k * c1) & 0xFFFFFFFF; k = ((k << 15) | (k >> 17)) & 0xFFFFFFFF; k = (k * c2) & 0xFFFFFFFF
        h ^= k
    h ^= len(b)
    h ^= h >> 16; h = (h * 0x85EBCA6B) & 0xFFFFFFFF
    h ^= h >> 13; h = (h * 0xC2B2AE35) & 0xFFFFFFFF
    h ^= h >> 16
    return h

def h_xxh32(b, seed=0):
    P1, P2, P3, P4, P5 = 0x9E3779B1, 0x85EBCA77, 0xC2B2AE3D, 0x27D4EB2F, 0x165667B1
    rol = lambda v, r: ((v << r) | (v >> (32 - r))) & 0xFFFFFFFF
    ln = len(b); i = 0
    if ln >= 16:
        v1 = (seed + P1 + P2) & 0xFFFFFFFF; v2 = (seed + P2) & 0xFFFFFFFF
        v3 = seed & 0xFFFFFFFF;            v4 = (seed - P1) & 0xFFFFFFFF
        while i <= ln - 16:
            for vi in range(4):
                v = (v1, v2, v3, v4)[vi]
                v = (v + struct.unpack_from('<I', b, i)[0] * P2) & 0xFFFFFFFF
                v = (rol(v, 13) * P1) & 0xFFFFFFFF
                if vi == 0: v1 = v
                elif vi == 1: v2 = v
                elif vi == 2: v3 = v
                else: v4 = v
                i += 4
        h = (rol(v1, 1) + rol(v2, 7) + rol(v3, 12) + rol(v4, 18)) & 0xFFFFFFFF
    else:
        h = (seed + P5) & 0xFFFFFFFF
    h = (h + ln) & 0xFFFFFFFF
    while i <= ln - 4:
        h = (h + struct.unpack_from('<I', b, i)[0] * P3) & 0xFFFFFFFF
        h = (rol(h, 17) * P4) & 0xFFFFFFFF; i += 4
    while i < ln:
        h = (h + b[i] * P5) & 0xFFFFFFFF
        h = (rol(h, 11) * P1) & 0xFFFFFFFF; i += 1
    h ^= h >> 15; h = (h * P2) & 0xFFFFFFFF
    h ^= h >> 13; h = (h * P3) & 0xFFFFFFFF
    h ^= h >> 16
    return h

def h_fletcher16(b):
    s1 = s2 = 0
    for i in range(0, len(b) - 1, 2):
        w = b[i] | (b[i + 1] << 8)
        s1 = (s1 + w) % 255; s2 = (s2 + s1) % 255
    if len(b) & 1:
        s1 = (s1 + b[-1]) % 255; s2 = (s2 + s1) % 255
    return (s2 << 8) | s1

def h_fletcher32(b):
    if len(b) % 4: b = b + b'\0' * (4 - len(b) % 4)
    s1 = s2 = 0
    for i in range(0, len(b), 4):
        w = struct.unpack_from('<I', b, i)[0]
        s1 = (s1 + w) % 65535; s2 = (s2 + s1) % 65535
    return (s2 << 16) | s1

def h_sum16(b):
    s = 0
    for i in range(0, len(b) - 1, 2): s = (s + (b[i] | (b[i + 1] << 8))) & 0xFFFF
    return s

def h_bsd16(b):
    s = 0
    for c in b: s = (((s >> 1) | ((s & 1) << 15)) + c) & 0xFFFF
    return s

# CRC16 battery: name -> (poly, init, refin, refout, xorout)
CRC16_VARIANTS = {
    'IBM/ARC':    (0x8005, 0x0000, True,  True,  0x0000),
    'MODBUS':     (0x8005, 0xFFFF, True,  True,  0x0000),
    'USB':        (0x8005, 0xFFFF, True,  True,  0xFFFF),
    'MAXIM':      (0x8005, 0x0000, True,  True,  0xFFFF),
    'CCITT-FALSE':(0x1021, 0xFFFF, False, False, 0x0000),
    'XMODEM':     (0x1021, 0x0000, False, False, 0x0000),
    'AUG-CCITT':  (0x1021, 0x1D0F, False, False, 0x0000),
    'GENIBUS':    (0x1021, 0xFFFF, False, False, 0xFFFF),
    'KERMIT':     (0x1021, 0x0000, True,  True,  0x0000),
    'X25':        (0x1021, 0xFFFF, True,  True,  0xFFFF),
    'MCRF4XX':    (0x1021, 0xFFFF, True,  True,  0x0000),
    'DNP':        (0x3D65, 0x0000, True,  True,  0xFFFF),
    'DECT-X':     (0x0589, 0x0000, False, False, 0x0000),
    'T10-DIF':    (0x8BB7, 0x0000, False, False, 0x0000),
    'BUYPASS':    (0x8005, 0x0000, False, False, 0x0000),
    'TELEDISK':   (0xA097, 0x0000, False, False, 0x0000),
}

def _reflect(v, w):
    r = 0
    for i in range(w): r |= ((v >> i) & 1) << (w - 1 - i)
    return r

def crc16(b, poly, init, refin, refout, xorout):
    crc = init
    for c in b:
        if refin: c = _reflect(c, 8)
        crc ^= c << 8
        for _ in range(8):
            crc = ((crc << 1) ^ poly) & 0xFFFF if crc & 0x8000 else (crc << 1) & 0xFFFF
    if refout: crc = _reflect(crc, 16)
    return crc ^ xorout

HASHES32 = {
    'crc32': h_crc32, 'adler32': h_adler32, 'fnv1_32': h_fnv1_32,
    'fnv1a_32': h_fnv1a_32, 'djb2': h_djb2, 'sdbm': h_sdbm,
    'jenkins': h_jenkins, 'murmur2': h_murmur2, 'murmur3': h_murmur3,
    'xxh32': h_xxh32, 'fletcher32': h_fletcher32,
}
HASHES16 = {'fletcher16': h_fletcher16, 'sum16': h_sum16, 'bsd16': h_bsd16}
DIGESTS = {'md5': hashlib.md5, 'sha1': hashlib.sha1, 'sha256': hashlib.sha256}

# ---------------------------------------------------------------- archive io

class VbfHeader:
    """Parses only the header region of an SRYK archive."""
    def __init__(self, path):
        self.path = path
        with open(path, 'rb') as fs:
            self.file_size = os.path.getsize(path)
            self.magic, self.header_len, self.num_files = struct.unpack('<IIQ', fs.read(16))
            assert self.magic == MAGIC, 'bad magic'
            nf = self.num_files
            self.md5_table = fs.read(16 * nf)
            self.entry_table = fs.read(32 * nf)
            self.string_table_size = struct.unpack('<I', fs.read(4))[0]
            self.string_table = fs.read(self.string_table_size - 4)
            # block list: derive count from origSizes
            self.total_blocks = 0
            self.e_bls, self.e_f04, self.e_osz, self.e_so, self.e_no = [], [], [], [], []
            for i in range(nf):
                bls, f04, osz, so, no = struct.unpack_from('<IIQQQ', self.entry_table, i * 32)
                self.e_bls.append(bls); self.e_f04.append(f04); self.e_osz.append(osz)
                self.e_so.append(so);  self.e_no.append(no)
                self.total_blocks += osz // BLOCK + (1 if osz % BLOCK else 0)
            self.block_table = fs.read(2 * self.total_blocks)
            end = fs.tell()
            assert end == self.header_len, f'header end {end} != headerLen {self.header_len}'
            fs.seek(0)
            self.full_header = fs.read(self.header_len)
        self.names = self.string_table.decode('utf-8', 'replace').strip('\x00').split('\x00')

# ---------------------------------------------------------------- test infra

class Results:
    def __init__(self):
        self.rows = []
    def add(self, archive, family, candidate, computed, target, verdict, note=''):
        self.rows.append(dict(archive=archive, family=family, candidate=candidate,
                              computed=computed, target=target, verdict=verdict, note=note))
    def write_csv(self, path):
        import csv
        with open(path, 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=['archive', 'family', 'candidate', 'computed',
                                              'target', 'verdict', 'note'])
            w.writeheader()
            for r in self.rows: w.writerow(r)

def u32wins(digest):
    """All LE and BE u32 windows of a digest as (label, value)."""
    for off in range(len(digest) - 3):
        yield f'le@{off}', int.from_bytes(digest[off:off + 4], 'little')
        yield f'be@{off}', int.from_bytes(digest[off:off + 4], 'big')

def u16wins(digest):
    for off in range(len(digest) - 1):
        yield f'le@{off}', int.from_bytes(digest[off:off + 2], 'little')
        yield f'be@{off}', int.from_bytes(digest[off:off + 2], 'big')

# ---------------------------------------------------------------- main sweep

def analyze(hdr, res, log):
    tag = os.path.basename(hdr.path)
    nf = hdr.num_files
    f04 = hdr.e_f04
    stamps = collections.Counter(f04)
    log(f'== {tag}: numFiles={nf} headerLen={hdr.header_len} '
        f'stringTable={hdr.string_table_size} totalBlocks={hdr.total_blocks} fileSize={hdr.file_size}')
    log(f'   f04 histogram: ' + ', '.join(f'0x{k:08X}x{v}' for k, v in
                                           sorted(stamps.items(), key=lambda x: -x[1])[:8]))
    # ---------------- A. per-entry relations ----------------
    nz = [i for i, v in enumerate(f04) if v != 0]
    z = [i for i, v in enumerate(f04) if v == 0]
    if len(stamps) <= 8:  # skip the trivially-uniform cases for big archives below
        pass
    res.add(tag, 'A.struct', 'distinct f04 values', str(len(stamps)), '-', 'info',
            f'top={dict(sorted(stamps.items(),key=lambda x:-x[1])[:4])}')
    # eq_blockListStart (metamenu pattern)
    eq = sum(1 for i in nz if f04[i] == hdr.e_bls[i])
    res.add(tag, 'A.struct', 'f04 == blockListStart', f'{eq}/{len(nz)}', 'all', 'HIT' if eq == len(nz) and nz else 'miss')
    eqi = sum(1 for i in nz if f04[i] == i)
    res.add(tag, 'A.struct', 'f04 == entry index', f'{eqi}/{len(nz)}', 'all', 'HIT' if eqi == len(nz) and nz else 'miss')
    eqs = sum(1 for i in nz if f04[i] == hdr.e_so[i])
    res.add(tag, 'A.struct', 'f04 == startOffset', f'{eqs}/{len(nz)}', 'all', 'HIT' if eqs == len(nz) and nz else 'miss')
    eql = sum(1 for i in nz if f04[i] == hdr.e_so[i] - hdr.header_len)
    res.add(tag, 'A.struct', 'f04 == so-headerLen', f'{eql}/{len(nz)}', 'all', 'HIT' if eql == len(nz) and nz else 'miss')
    eqn = sum(1 for i in nz if f04[i] == hdr.e_no[i])
    res.add(tag, 'A.struct', 'f04 == fileNameOffset', f'{eqn}/{len(nz)}', 'all', 'HIT' if eqn == len(nz) and nz else 'miss')
    eqm = sum(1 for i in nz if f04[i] == struct.unpack_from('<I', hdr.md5_table, i * 16)[0])
    res.add(tag, 'A.struct', 'f04 == md5name[0:4]LE', f'{eqm}/{len(nz)}', 'all', 'HIT' if eqm == len(nz) and nz else 'miss')
    zsz = sum(1 for i in z if hdr.e_osz[i] == 0)
    res.add(tag, 'A.struct', 'f04==0 & osz==0', f'{zsz}/{len(z)}', 'all', 'HIT' if zsz == len(z) and z else 'miss')

    # ---------------- A2. empty-record startOffset junk ----------------
    if z:
        hi = collections.Counter(hdr.e_so[i] >> 32 for i in z)
        res.add(tag, 'A2.junk', 'empty-rec so>>32', str(dict(hi)), 'numFiles' if nf in hi else '?',
                'HIT' if list(hi) == [nf] else 'partial',
                f'nf={nf}; so=(nf<<32)|lo32 for all f04==0 records' if list(hi) == [nf] else '')
        lo = [hdr.e_so[i] & 0xFFFFFFFF for i in z]
        res.add(tag, 'A2.junk', 'empty-rec so_lo32 ascending', str(all(lo[k] <= lo[k+1] for k in range(len(lo)-1))),
                '-', 'info', f'range 0x{min(lo):X}..0x{max(lo):X}')

    # ---------------- B/C/D. region hashes ----------------
    if len(stamps) > 8:  # uniform-stamp archives: run the hash battery
        targets = {v for v in stamps if v != 0}
        lo16 = {t & 0xFFFF for t in targets}
        hi16 = {t >> 16 for t in targets}
        # entry-table variant with f04 zeroed (candidate self-consistent hash input)
        et_zero = bytearray(hdr.entry_table)
        for i in range(nf): struct.pack_into('<I', et_zero, i * 32 + 4, 0)
        regions = {
            'md5_table': hdr.md5_table, 'entry_table': hdr.entry_table,
            'entry_table_f04zero': bytes(et_zero), 'string_table': hdr.string_table,
            'string_table+size': struct.pack('<I', hdr.string_table_size) + hdr.string_table,
            'block_table': hdr.block_table, 'full_header': hdr.full_header,
            'full_header_f04zero': hdr.full_header[:16 + 16 * nf] + bytes(et_zero)
                                   + hdr.full_header[16 + 16 * nf + 32 * nf:],
            'names_joined': hdr.string_table.rstrip(b'\x00'),
        }
        for rname, data in regions.items():
            for hname, fn in HASHES32.items():
                v = fn(data)
                for t in targets:
                    if v == t:
                        res.add(tag, 'B.hash32', f'{hname}({rname})', f'0x{v:08X}', f'0x{t:08X}', '*** HIT ***')
                if (v & 0xFFFF) in lo16:
                    res.add(tag, 'B.hash32', f'{hname}({rname})&FFFF', f'0x{v&0xFFFF:04X}',
                            f'lo16={sorted(hex(x) for x in lo16)}', 'HIT-lo16')
                elif (v >> 16) in hi16:
                    res.add(tag, 'B.hash32', f'{hname}({rname})>>16', f'0x{v>>16:04X}',
                            f'hi16={sorted(hex(x) for x in hi16)}', 'HIT-hi16')
            for hname, fn in HASHES16.items():
                v = fn(data)
                if v in lo16 or v in hi16:
                    res.add(tag, 'B.hash16', f'{hname}({rname})', f'0x{v:04X}', '-', 'HIT')
            for dname, mk in DIGESTS.items():
                dg = mk(data).digest()
                for lab, v in u32wins(dg):
                    if v in targets:
                        res.add(tag, 'C.digest', f'{dname}({rname}).{lab}', f'0x{v:08X}', '-', '*** HIT ***')
                for lab, v in u16wins(dg):
                    if v in lo16 or v in hi16:
                        res.add(tag, 'C.digest', f'{dname}({rname}).{lab}', f'0x{v:04X}', '-', 'HIT-u16')
            for cname, (p, ini, ri, ro, xo) in CRC16_VARIANTS.items():
                v = crc16(data, p, ini, ri, ro, xo)
                if v in lo16 or v in hi16:
                    res.add(tag, 'D.crc16', f'{cname}({rname})', f'0x{v:04X}', '-', 'HIT')

        # ---------------- E. name/label hashes ----------------
        cands = []
        base = os.path.basename(hdr.path)
        for s in {base, base.lower(), base.upper(), base.rsplit('.', 1)[0],
                  base.rsplit('.', 1)[0].lower(), 'data/' + base, 'data/' + base.lower(),
                  'data\\' + base, 'data\\' + base.lower(), 'SRYK', 'vbf', 'VBF',
                  'VirtuosBigFile', 'virtuos', 'Virtuos', 'metamenu'}:
            cands.append(s.encode('utf-8'))
            cands.append(s.encode('utf-16-le'))
        for cb in cands:
            for hname, fn in {**HASHES32, 'crc16ccitt': lambda b: crc16(b, 0x1021, 0xFFFF, False, False, 0)}.items():
                v = fn(cb)
                if v in targets or (v & 0xFFFF) in lo16 or (v >> 16) in hi16:
                    res.add(tag, 'E.namehash', f'{hname}({cb[:40]!r})', f'0x{v:08X}', '-', 'HIT')
            dg = hashlib.md5(cb).digest()
            for lab, v in u32wins(dg):
                if v in targets:
                    res.add(tag, 'E.namehash', f'md5({cb[:40]!r}).{lab}', f'0x{v:08X}', '-', 'HIT')

        # ---------------- F. timestamp decodes ----------------
        for t in sorted(targets):
            dw, tw = t >> 16, t & 0xFFFF
            mo, dy, yr = (dw >> 5) & 0xF, dw & 0x1F, (dw >> 9) + 1980
            hh, mm, ss = tw >> 11, (tw >> 5) & 0x3F, (tw & 0x1F) * 2
            ok = (1 <= mo <= 12) and (1 <= dy <= 31) and mm < 60
            res.add(tag, 'F.time', f'DOS datetime 0x{t:08X}', f'{yr}-{mo:02d}-{dy:02d} {hh:02d}:{mm:02d}:{ss:02d}',
                    'valid', 'miss' if not ok else 'CHECK', '' if not ok else 'decodes cleanly!')
            res.add(tag, 'F.time', f'unix epoch 0x{t:08X}', str(__import__('datetime').datetime.fromtimestamp(t, __import__('datetime').timezone.utc)),
                    '-', 'info')
            res.add(tag, 'F.time', f'factorization 0x{t:08X}', '-', '-', 'info',
                    f'{t} = {_factor(t)} ; hi16={t>>16}={_factor(t>>16)} lo16={t&0xFFFF}={_factor(t&0xFFFF)}')

        # ---------------- G. structural ----------------
        for t in sorted(targets):
            for qname, q in [('numFiles', nf), ('headerLen', hdr.header_len),
                             ('stringTableSize', hdr.string_table_size),
                             ('totalBlocks', hdr.total_blocks), ('fileSize', hdr.file_size)]:
                if t % q == 0 or q % t == 0:
                    res.add(tag, 'G.struct', f'stamp vs {qname}', f'{t}/{q}', 'divisible', 'CHECK')
                res.add(tag, 'G.struct', f'stamp mod {qname}', f'0x{t % q:X}', '-', 'info')
        # bit anatomy
        for t in sorted(targets):
            res.add(tag, 'G.struct', f'anatomy 0x{t:08X}', f'hi=0x{t>>16:04X} lo=0x{t&0xFFFF:04X}',
                    '-', 'info', f'hi 64KB-aligned={((t>>16)&0xFF)!=0 or (t>>16)==0}; '
                                 f'bytes={t.to_bytes(4,"little").hex()}')

    return stamps

def _factor(n):
    if n == 0: return '0'
    f = []; d = 2
    while d * d <= n:
        while n % d == 0: f.append(d); n //= d
        d += 1
    if n > 1: f.append(n)
    return 'x'.join(map(str, f))

def main():
    ap = argparse.ArgumentParser(description='vbf field_04 derivation hunt')
    ap.add_argument('vbf', nargs='+', help='.vbf archives')
    ap.add_argument('--csv', default='docs/reverse/data/vbf_field04_derive.csv')
    ap.add_argument('--log', default='docs/reverse/data/vbf_field04_derive.log')
    args = ap.parse_args()

    res = Results()
    loglines = []
    def log(*a):
        s = ' '.join(str(x) for x in a)
        loglines.append(s); print(s)

    for p in args.vbf:
        try:
            hdr = VbfHeader(p)
        except Exception as e:
            log(f'!! {p}: {e}')
            continue
        analyze(hdr, res, log)

    # cross-archive constant anatomy
    log('== cross-archive anatomy ==')
    for name, v in [('FFX_Data', 0x00A813F6), ('FFX2_Data', 0x003D13F6)]:
        log(f'   {name}: 0x{v:08X} = ({v>>16} << 16) | 0x{v&0xFFFF:04X} '
            f'| hi*64KB=0x{(v>>16)<<16:08X} | mod4={v%4} mod8={v%8} mod16={v%16}')
    log('   shared lo16 0x13F6 = 5110; hi16 delta 0xA8-0x3D = 0x6B = 107')
    log('   alignment note: stamp%8=6 => NOT an 8-aligned heap ptr; consistent with')
    log('   u16* / mid-struct char* / (tag<<16)|const composite')

    res.write_csv(args.csv)
    with open(args.log, 'w') as f:
        f.write('\n'.join(loglines) + '\n')
    hits = [r for r in res.rows if 'HIT' in r['verdict']]
    log(f'-- wrote {len(res.rows)} candidates -> {args.csv} ; hits: {len(hits)}')
    for h in hits:
        log(f"   {h['verdict']}: {h['archive']} {h['family']} {h['candidate']} = {h['computed']}")
    return 0

if __name__ == '__main__':
    sys.exit(main())
