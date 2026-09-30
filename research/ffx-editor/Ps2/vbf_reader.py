#!/usr/bin/env python3
# vbf_reader.py — VBF (Virtuos Big File) reader: list / extract / verify (stdlib-only)
#
# Provenance: promoted from work/_vbf_reader.py scratch on 2026-09-14 after the
# small-RAW-block extract fix was proven 3/3 byte-identical against the disk
# extraction (docs/reverse/FFX_MICRO_FIXES_2026-09-14.md F2; C# reference:
# research_tools/Ps2/VbfReader.cs EB()). 2026-09-16 (Jarvis-ZCODE, FMT-ARCHIVE
# audit): module side-effects removed, argparse CLI added; the VbfReader class
# API is unchanged (path arg, index_by_name(), extract()).
#
# FORMAT (SRYK, all LE — spec: docs/reverse/FFX_STRUCTURE_COMPLETE_2026-09-14.md
# §11.11 + VBF_FORMAT_COMPLETE_2026-08-19.md):
#   u32 magic "SRYK" | u32 headerLength | u64 numFiles
#   numFiles x 16B  MD5-of-path table (path normalized: lowercase, '/' slashes)
#   numFiles x 32B  entries: u32 blockListStart | u32 field_04 (packer stamp,
#                   never read by the runtime — proven at machine level in the
#                   FFX_BigFile_ReadVerifyHeader @0x61DC80 entry loop, which
#                   touches only +0x00/+0x08/+0x0C/+0x18) | u64 originalSize |
#                   u64 startOffset | u64 fileNameOffset
#
#   field_04 verdict (wave-13 corpus lane 2026-09-18): opaque per-archive
#   packer stamp. Derivation hunt (Jarvis-VBF-FIELD04, same day):
#   docs/reverse/FFX_VBF_FIELD04_2026-09-18.md + data/vbf_field04_derive.csv —
#   stamp = (K<<16)|0x13F6 (K=0xA8/0x3D); every empty record's startOffset
#   leaks numFiles into hi32 => packer serializes internal state into dead
#   fields => field_04 = leaked packer-process value (arena+0x13F6 pointer or
#   tag<<16|const signature), not derivable from content. In the big archives
#   it is a constant for every non-empty
#   record (FFX_Data=0x00A813F6 x71,972; FFX2_Data=0x003D13F6 x130,631) and
#   0 for empty entries; in metamenu.vbf it instead equals blockListStart on
#   all 150 records (a sparse block-position ordinal — different tool
#   generation). The PC launcher writer hardcodes 0x003D13F6 as an ignored
#   compatibility field (VbfWriter.cs). Exhaustively refuted as checksum/
#   hash/ordinal/size (crc32+adler32+md5 of every index sub-table and of
#   payloads, name hashes, sums, blockListStart/startOffset correlation,
#   entry rank). Shared low word 0x13F6 also fails DOS-datetime decode
#   (month nibble = 15, invalid) and appears nowhere in the launcher
#   binary. Exact derivation remains OPEN — most consistent with a
#   build/version stamp or random nonce baked by the Virtuos packing
#   tool; runtime semantics are unaffected either way.
#   u32 stringTableSize (incl. itself) + UTF-8 NUL-separated names
#   totalBlocks x u16 compressed-size-per-64KB-block (0 == stored 65536)
#   data blocks: zlib stream per block when storedSize < logical size;
#                the LAST block is stored raw when storedSize == remainder
#                (small-RAW fix — see extract()); a 65536 raw block is slot 0.
#   footer: MD5 of the first headerLength bytes (integrity, CryptoAPI-verified
#           by the runtime per IDA RE of FFX_BigFile_ReadVerifyHeader @0x61DC80)
#
# USAGE
#   python3 vbf_reader.py FILE.vbf --list [-o names.txt]
#   python3 vbf_reader.py FILE.vbf --find SUBSTR          (case-insensitive)
#   python3 vbf_reader.py FILE.vbf --extract NAME OUT
#   python3 vbf_reader.py FILE.vbf --verify NAME DISKFILE (byte-compare)
#   python3 vbf_reader.py FILE.vbf --verify-root ROOT [--sample N]
#           ROOT = dir that contains the vbf paths (e.g. extracted corpus);
#           --sample N checks N evenly spread entries (default: all)
#
# Exit 0 on success; non-zero on any verify mismatch / missing name.

import argparse
import hashlib
import os
import struct
import sys
import zlib

BLOCK = 65536
MAGIC = 1264144979  # 'SRYK' as u32 LE


def u32(b, o): return struct.unpack_from('<I', b, o)[0]
def u64(b, o): return struct.unpack_from('<Q', b, o)[0]
def u16(b, o): return struct.unpack_from('<H', b, o)[0]


class VbfReader:
    def __init__(self, path, quiet=False):
        self.path = path
        self.quiet = quiet
        self.fs = open(path, 'rb')
        self._parse()

    def _log(self, *a):
        if not self.quiet:
            print(*a)

    def _read(self, n):
        d = self.fs.read(n)
        if len(d) != n:
            raise EOFError('short read')
        return d

    def _parse(self):
        magic = u32(self._read(4), 0)
        if magic != MAGIC:
            raise RuntimeError('bad magic %d' % magic)
        self.headerLength = u32(self._read(4), 0)
        self.numFiles = u64(self._read(8), 0)
        self._log('magic ok headerLength=', self.headerLength, 'numFiles=', self.numFiles)
        self.md5s = [self._read(16).hex().upper() for _ in range(self.numFiles)]
        self.blockListStarts = []
        self.counts = []          # entry +0x04 (packer stamp, runtime-unused)
        self.origSizes = []
        self.startOffsets = []
        self.nameOffsets = []
        for i in range(self.numFiles):
            bls = u32(self._read(4), 0)
            cnt = u32(self._read(4), 0)
            osz = u64(self._read(8), 0)
            so = u64(self._read(8), 0)
            no = u64(self._read(8), 0)
            self.blockListStarts.append(bls)
            self.counts.append(cnt)
            self.origSizes.append(osz)
            self.startOffsets.append(so)
            self.nameOffsets.append(no)
        sts = u32(self._read(4), 0)
        self.stringTable = self._read(sts - 4).decode('utf-8', 'replace')
        self.names = self.stringTable.strip('\x00').split('\x00')
        self._log('stringTableSize=', sts, 'names parsed=', len(self.names))
        blockCount = 0
        for osz in self.origSizes:
            blockCount += osz // BLOCK + (1 if osz % BLOCK else 0)
        self.blockList = []
        for _ in range(blockCount):
            self.blockList.append(u16(self._read(2), 0))
        self._log('blockCount=', blockCount, 'blockList len=', len(self.blockList))
        if len(self.names) != self.numFiles:
            self._log('WARN names(%d)!=numFiles(%d)' % (len(self.names), self.numFiles))

    def index_by_name(self, name):
        low = name.lower().replace('\\', '/')
        h = hashlib.md5(low.encode('utf-8')).hexdigest().upper()
        return self.md5s.index(h) if h in self.md5s else -1

    def extract_bytes(self, i):
        """Decode entry index i and return the logical bytes."""
        osz = self.origSizes[i]
        so = self.startOffsets[i]
        bls = self.blockListStarts[i]
        bc = osz // BLOCK + (1 if osz % BLOCK else 0)
        rem = osz % BLOCK or BLOCK
        if bc == 0:
            # FIX 2026-09-16 (FMT-ARCHIVE audit): empty entries (origSize==0) carry
            # sentinel offsets (observed 0xFFFFFFFFFFFFFFFF in FFX2_Data.vbf) —
            # seeking them raises EINVAL. Return empty payload before touching
            # the stream. Same behaviour as the C# EB() loop over 0 blocks.
            return b''
        self.fs.seek(so)
        out = bytearray()
        for bi in range(bc):
            bl = self.blockList[bls + bi]
            if bl == 0:
                bl = BLOCK
            cb = self.fs.read(bl)
            decsz = BLOCK if bi != bc - 1 else rem
            if bl == BLOCK:
                out += cb[:decsz]
            elif bi == bc - 1 and bl == rem:
                # FIX 2026-09-14 (MICRO-FIXES F2, lane FFX-STRUCTURES): small RAW
                # stored block — when the LAST block's stored length equals the
                # remaining logical size (rem), the block is uncompressed and must
                # be copied verbatim. Mirrors EB() in research_tools/Ps2/VbfReader.cs
                # (`if (bi == bc-1 && bl == br) db = cb;`, ported from kaldaien/VBFExtract
                # <- topher-au). Without this case, zlib fails with "invalid stored
                # block lengths" or silently returns 0 bytes — evidence in
                # docs/reverse/FFX_FFX2_MATERIAL_SURVEY_2026-09-14.md section 4.1.
                out += cb[:decsz]
            else:
                d = zlib.decompressobj(-15)
                out += d.decompress(cb[2:], decsz)[:decsz]
        if len(out) != osz:
            raise RuntimeError('decoded %d != origSize %d' % (len(out), osz))
        return bytes(out)

    def extract(self, name, out):
        i = self.index_by_name(name)
        if i < 0:
            return False
        with open(out, 'wb') as o:
            o.write(self.extract_bytes(i))
        return True


def _verify_against_disk(r, i, name, root):
    """Extract entry i and byte-compare to root/name. Returns (ok, detail)."""
    data = r.extract_bytes(i)
    disk_path = os.path.join(root, name.replace('/', os.sep))
    if not os.path.isfile(disk_path):
        return None, 'disk-missing %s' % disk_path
    disk = open(disk_path, 'rb').read()
    if data == disk:
        return True, '%d B == disk' % len(data)
    return False, 'MISMATCH extracted=%d B disk=%d B' % (len(data), len(disk))


def main(argv=None):
    ap = argparse.ArgumentParser(description='FFX VBF (SRYK) reader: list/extract/verify')
    ap.add_argument('vbf')
    ap.add_argument('--list', action='store_true', help='print all names')
    ap.add_argument('-o', '--out', help='output path for --list')
    ap.add_argument('--find', help='substring filter (case-insensitive) for --list')
    ap.add_argument('--extract', nargs=2, metavar=('NAME', 'OUT'))
    ap.add_argument('--verify', nargs=2, metavar=('NAME', 'DISKFILE'),
                    help='extract NAME and byte-compare to DISKFILE')
    ap.add_argument('--verify-root', metavar='ROOT',
                    help='verify every (or --sample) entry against files under ROOT')
    ap.add_argument('--sample', type=int, default=0,
                    help='with --verify-root: check N evenly spread entries')
    ap.add_argument('--quiet', action='store_true')
    args = ap.parse_args(argv)

    r = VbfReader(args.vbf, quiet=args.quiet)

    if args.list or args.find:
        names = r.names
        if args.find:
            names = [n for n in names if args.find.lower() in n.lower()]
        if args.out:
            with open(args.out, 'w') as f:
                f.write('\n'.join(names) + '\n')
            print('wrote %d names -> %s' % (len(names), args.out))
        else:
            for n in names:
                print(n)
            print('(%d names)' % len(names), file=sys.stderr)
        return 0

    if args.extract:
        name, out = args.extract
        i = r.index_by_name(name)
        if i < 0:
            print('NOT IN VBF:', name)
            return 1
        data = r.extract_bytes(i)
        with open(out, 'wb') as o:
            o.write(data)
        print('extracted idx=%d %d B -> %s' % (i, len(data), out))
        return 0

    if args.verify:
        name, diskfile = args.verify
        i = r.index_by_name(name)
        if i < 0:
            print('NOT IN VBF:', name)
            return 1
        data = r.extract_bytes(i)
        disk = open(diskfile, 'rb').read()
        ok = data == disk
        print('[%s] %s extracted=%d B disk=%d B' % ('OK' if ok else 'FAIL', name, len(data), len(disk)))
        return 0 if ok else 1

    if args.verify_root:
        idxs = range(len(r.names))
        if args.sample and args.sample < len(r.names):
            step = len(r.names) / args.sample
            idxs = [int(k * step) for k in range(args.sample)]
        ok = bad = missing = 0
        for i in idxs:
            res, detail = _verify_against_disk(r, i, r.names[i], args.verify_root)
            if res is None:
                missing += 1
                continue
            if res:
                ok += 1
            else:
                bad += 1
                print('[FAIL] %s — %s' % (r.names[i], detail))
        print('verify-root: %d ok, %d mismatch, %d missing-on-disk (of %d checked)'
              % (ok, bad, missing, len(list(idxs))))
        return 0 if bad == 0 else 1

    # default: index summary only (parse already printed the header stats)
    print('names:', len(r.names), '— use --list/--find/--extract/--verify/--verify-root')
    return 0


if __name__ == '__main__':
    sys.exit(main())
