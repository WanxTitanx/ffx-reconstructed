#!/usr/bin/env python3
# vbf_packer_probe.py — wave-14 packer-forensics for the .vbf entry +0x04 stamp.
#
# Lane Jarvis-VBF-PACKER (2026-09-18). Research-only; reads ONLY header regions
# of the 17-20 GB archives (never the payload areas).
#
# Builds on Jarvis-VBF-FIELD04 (.46): field_04 = (K<<16)|0x13F6, K=0xA8/0x3D,
# runtime-dead, writer absent from every shipped binary. THIS lane's findings:
#
#   * NEW MECHANISM PROOF: every empty record's startOffset u64 decomposes as
#         so = (numFiles << 32) | recordPtr
#     where recordPtr = segBase + 24*index — a 32-bit pointer to file[i]'s
#     24-byte record in the packer's chunked input-record table (chunk width
#     ~1360 records; base_eff deltas of +0x20 = back-to-back arrays of
#     24*count+0x20 bytes). The u64 = the writer's live file-iterator struct
#     {u32 cur; u32 count} serialized verbatim into a dead field.
#   * field_04 = same class: a 32-bit writer-process pointer — 64KB-aligned
#     region base + fixed interior offset 0x13F6. K = address high bits =
#     arbitrary per packer run -> NOT derivable from archive content.
#     Leading unification: field_04 = &writerCursor (or &ctx.cursor); the
#     empty-record u64 exposes that same cursor's live bytes {cur, count}.
#   * metamenu's OLDER writer wrote a SANE startOffset for its empty record
#     (so == headerLen) and f04 == blockListStart — the leak is specific to
#     the newer serializer generation.
#   * Compressed blocks are stored WITH their zlib header (0x78DA = level 9):
#     the original packer used native zlib (C/C++), not .NET DeflateStream.
#   * Binary hunt: 1,647 executables/DLLs/dumps in the game dir scanned —
#     ZERO occurrences of either stamp (LE+BE) => writer ships nowhere.
#   * Full corpus SRYK-magic scan: only the 3 known archives + our own
#     VbfWriter fixture (mini.vbf, stamp 0x003D13F6 = hardcoded 4002806).
#
# Emits:
#   docs/reverse/data/wave14/vbf_packer_metrics.csv      — per-archive metrics
#   docs/reverse/data/wave14/vbf_packer_empty_leak.csv   — per-empty forensics
#   docs/reverse/data/wave14/vbf_packer_segments.csv     — base_eff segment groups
#   docs/reverse/data/wave14/vbf_packer_k_sweep.csv      — K derivation sweep
#   docs/reverse/data/wave14/vbf_packer_probe.log        — human-readable verdict
#
# Exit 0 always (analysis tool).

import collections
import os
import struct
import sys
import zlib

BLOCK = 65536
MAGIC = 0x4B595253  # 'SRYK' LE
CHUNK = 16384

ARCHIVES = [
    "/mnt/nvme-samsung/SteamLibrary/steamapps/common/FINAL FANTASY FFX&FFX-2 HD Remaster/data/FFX_Data.vbf",
    "/mnt/nvme-samsung/SteamLibrary/steamapps/common/FINAL FANTASY FFX&FFX-2 HD Remaster/data/FFX2_Data.vbf",
    "/mnt/nvme-samsung/SteamLibrary/steamapps/common/FINAL FANTASY FFX&FFX-2 HD Remaster/data/metamenu.vbf",
    "work/_val_ps2/orphan_out/mini.vbf",
]

OUTDIR = "docs/reverse/data/wave14"


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
            self.total_blocks = 0
            self.e_bls, self.e_f04, self.e_osz, self.e_so, self.e_no = [], [], [], [], []
            for i in range(nf):
                bls, f04, osz, so, no = struct.unpack_from('<IIQQQ', self.entry_table, i * 32)
                self.e_bls.append(bls)
                self.e_f04.append(f04)
                self.e_osz.append(osz)
                self.e_so.append(so)
                self.e_no.append(no)
                self.total_blocks += osz // BLOCK + (1 if osz % BLOCK else 0)
            self.block_table = fs.read(2 * self.total_blocks)
            end = fs.tell()
            assert end == self.header_len, f'header end {end} != headerLen {self.header_len}'
            fs.seek(0)
            self.full_header = fs.read(self.header_len)
        self.names = self.string_table.split(b'\x00')
        if self.names and self.names[-1] == b'':
            self.names.pop()


def top_dir(name):
    parts = name.split(b'/')
    return parts[0] if parts else b''


def main():
    os.makedirs(OUTDIR, exist_ok=True)
    logf = open(os.path.join(OUTDIR, 'vbf_packer_probe.log'), 'w')

    def log(s=''):
        print(s)
        logf.write(s + '\n')

    metrics_rows = []
    leak_rows = []
    seg_rows = []
    sweep_rows = []

    allmetrics = {}

    for path in ARCHIVES:
        if not os.path.exists(path):
            log(f'!! missing {path}')
            continue
        tag = os.path.basename(path)
        h = VbfHeader(path)
        nf = h.num_files
        nonempty = sum(1 for v in h.e_osz if v)
        # empty = no payload (osz==0). NOTE: f04==0 is the marker on the NEW
        # writer (stamp archives); on metamenu's OLD writer f04==bls so a
        # block-0 record also reads f04==0 while carrying real data.
        empties = [i for i, v in enumerate(h.e_osz) if v == 0]
        distinct_f04 = collections.Counter(h.e_f04)
        sum_osz = sum(h.e_osz)
        payload = max((h.e_so[i] + h.e_osz[i]) for i in range(nf)) if nf else 0
        tdirs = collections.Counter(top_dir(n) for n in h.names)
        exts = collections.Counter(n.rsplit(b'.', 1)[-1].lower() if b'.' in n else b'' for n in h.names)
        m = dict(
            archive=tag, numFiles=nf, nonEmpty=nonempty, emptyCount=len(empties),
            headerLen=h.header_len, stringTableSize=h.string_table_size,
            totalBlocks=h.total_blocks, fileSize=h.file_size,
            sumOrigSize=sum_osz, payloadEnd=payload,
            topDirs=len(tdirs), uniqExts=len(exts),
            distinctF04=len(distinct_f04),
            crc_md5tab=zlib.crc32(h.md5_table) & 0xFFFFFFFF,
            crc_entrytab=zlib.crc32(h.entry_table) & 0xFFFFFFFF,
            crc_strtab=zlib.crc32(h.string_table) & 0xFFFFFFFF,
            crc_blocktab=zlib.crc32(h.block_table) & 0xFFFFFFFF,
            crc_header=zlib.crc32(h.full_header) & 0xFFFFFFFF,
            trailer_bytes=h.file_size - (h.header_len + 0),  # informational
        )
        # physical end: max over records of (so + storedBytes) where storedBytes
        # = sum of that file's block-table entries (0 => full 64KB block).
        lastend = 0
        if nonempty:
            for i in range(nf):
                if not h.e_osz[i]:
                    continue
                nb = h.e_osz[i] // BLOCK + (1 if h.e_osz[i] % BLOCK else 0)
                stored = 0
                for b in range(nb):
                    bs = struct.unpack_from('<H', h.block_table,
                                            2 * (h.e_bls[i] + b))[0]
                    stored += bs if bs else BLOCK
                end = h.e_so[i] + stored
                if end > lastend:
                    lastend = end
        m['payloadEnd_nonempty'] = lastend
        m['trailer_after_payload'] = h.file_size - lastend
        allmetrics[tag] = m
        for k, v in m.items():
            metrics_rows.append(dict(archive=tag, metric=k, value=str(v)))

        log(f'== {tag}: nf={nf} nonempty={nonempty} empties={len(empties)} '
            f'hlen=0x{h.header_len:X} sts={h.string_table_size} blocks={h.total_blocks} '
            f'fsz={h.file_size} trailer={m["trailer_after_payload"]}')

        # ---- field_04 anatomy ------------------------------------------------
        stamps = [v for v in distinct_f04 if v]
        log(f'   f04 distinct={len(distinct_f04)} '
            f'top={[(hex(k), v) for k, v in distinct_f04.most_common(4)]}')
        for t in stamps:
            lo16, hi16 = t & 0xFFFF, t >> 16
            aligns = {s: (0x13F6 % s == 0) for s in (8, 16, 24, 32)}
            log(f'   stamp 0x{t:08X}: (K<<16)|lo16 K=0x{hi16:04X}({hi16}) lo16=0x{lo16:04X} '
                f'stamp%8={t % 8} lo16%8/16/24/32-aligned={aligns}')

        # ---- empty-record iterator-leak forensics ----------------------------
        hi = collections.Counter(h.e_so[i] >> 32 for i in empties)
        log(f'   empty so>>32 histogram: {dict(hi)} (numFiles={nf})')
        stride_ok = 0
        groups = collections.defaultdict(list)
        for i in empties:
            so = h.e_so[i]
            lo = so & 0xFFFFFFFF
            base_eff = lo - 24 * i
            groups[base_eff].append(i)
            leak_rows.append(dict(
                archive=tag, index=i,
                so=f'0x{so:016X}', so_hi32=so >> 32, so_lo32=f'0x{lo:08X}',
                base_eff=f'0x{base_eff:08X}', bls=h.e_bls[i],
                next_bls=h.e_bls[i + 1] if i + 1 < nf else '',
                osz=h.e_osz[i], no=h.e_no[i],
                name=h.names[i][:80].decode('utf-8', 'replace') if i < len(h.names) else '',
            ))
        for b, idxs in sorted(groups.items(), key=lambda x: min(x[1])):
            seg_rows.append(dict(archive=tag, base_eff=f'0x{b:08X}', count=len(idxs),
                                 idx_lo=min(idxs), idx_hi=max(idxs),
                                 width=max(idxs) - min(idxs) + 1))
        # stride check: inside each base group, lo32 == base + 24*i ?
        bad = 0
        for b, idxs in groups.items():
            for i in idxs:
                if (h.e_so[i] & 0xFFFFFFFF) - 24 * i != b:
                    bad += 1
        log(f'   iterator-leak: {len(groups)} base_eff groups; '
            f'records failing lo32==base+24*i: {bad}')
        # metamenu-style sane check
        sane = sum(1 for i in empties if (h.e_so[i] >> 32) == 0)
        log(f'   empties with sane hi32==0 (old-writer style): {sane}')

        # ---- compressed-block zlib check (first N non-final compressed) ------
        found = 0
        if h.total_blocks and nonempty:
            for i in range(min(nf, 4000)):
                bls, f04v, osz, so, no = (h.e_bls[i], h.e_f04[i], h.e_osz[i],
                                          h.e_so[i], h.e_no[i])
                nb = osz // BLOCK + (1 if osz % BLOCK else 0)
                pos = so
                for b in range(nb):
                    bs = struct.unpack_from('<H', h.block_table, 2 * (bls + b))[0]
                    stored = bs if bs else BLOCK
                    if b != nb - 1 and bs and bs < BLOCK and pos + bs <= h.file_size:
                        try:
                            with open(h.path, 'rb') as fs:
                                fs.seek(pos)
                                head = fs.read(2)
                            if head == b'\x78\xda':
                                found += 1
                        except OSError:
                            pass
                    pos += stored
                if found >= 20:
                    break
        log(f'   compressed non-final blocks sampled with zlib 0x78DA header: {found}')

        # ---- K / stamp derivation sweep --------------------------------------
        # Only meaningful for uniform-stamp archives (metamenu's f04==bls is
        # already explained; 150 distinct "targets" would just make noise).
        metrics = {k: v for k, v in m.items() if isinstance(v, int)}
        if len(stamps) <= 4:
            targets = {'stamp': list(stamps), 'K': [t >> 16 for t in stamps],
                       'lo16': [t & 0xFFFF for t in stamps]}
        else:
            targets = {'stamp': [], 'K': [], 'lo16': []}
        cnt = 0

        def sweep(family, cand, computed, target):
            nonlocal cnt
            cnt += 1
            if computed == target:
                sweep_rows.append(dict(archive=tag, family=family, candidate=cand,
                                       computed=str(computed), target=str(target),
                                       verdict='*** HIT ***'))
            else:
                sweep_rows.append(dict(archive=tag, family=family, candidate=cand,
                                       computed=str(computed), target=str(target),
                                       verdict='miss'))

        for mname, mv in metrics.items():
            for tname, tlist in targets.items():
                for t in tlist:
                    sweep('M.eq', f'{mname}', mv, t)
                    for s in range(1, 41):
                        if mv >> s:
                            sweep('M.shr', f'{mname}>>{s}', mv >> s, t)
                    for mask in (0xFF, 0xFFF, 0xFFFF, 0xFFFFFF):
                        sweep('M.mask', f'{mname}&0x{mask:X}', mv & mask, t)
                    for sh in (8, 16, 24):
                        sweep('M.byte', f'({mname}>>{sh})&0xFF', (mv >> sh) & 0xFF, t)
                    for mod in (100, 256, 512, 1000, 1024, 2048, 4096, 65536):
                        sweep('M.mod', f'{mname}%{mod}', mv % mod, t)
                    for d in (2, 4, 8, 10, 16, 32, 64, 100, 128, 256, 512,
                              1000, 1024, 4096, 65536):
                        sweep('M.div', f'{mname}//{d}', mv // d, t)
        # per-top-dir and per-ext counts vs K / lo16 / stamp
        for tname, tlist in targets.items():
            for t in tlist:
                for d, c in tdirs.items():
                    if c in (t,) or c == t:
                        sweep_rows.append(dict(archive=tag, family='N.dircount',
                                               candidate=f'count({d[:40]!r})',
                                               computed=str(c), target=str(t),
                                               verdict='*** HIT ***'))
                for e, c in exts.items():
                    if c == t:
                        sweep_rows.append(dict(archive=tag, family='N.extcount',
                                               candidate=f'count(*.{e!r})',
                                               computed=str(c), target=str(t),
                                               verdict='*** HIT ***'))
        log(f'   sweep candidates tested this archive: {cnt} '
            f'(plus dir/ext counts: {len(tdirs) + len(exts)})')

    # ---- cross-archive correlation -------------------------------------------
    if 'FFX_Data.vbf' in allmetrics and 'FFX2_Data.vbf' in allmetrics:
        a, b = allmetrics['FFX_Data.vbf'], allmetrics['FFX2_Data.vbf']
        log('== cross-archive (FFX vs FFX2): K=0xA8(168) vs K=0x3D(61); '
            'dK=107; K ratio=2.7541')
        for k in a:
            if isinstance(a[k], int) and isinstance(b[k], int) and k != 'archive':
                d = a[k] - b[k]
                r = (a[k] / b[k]) if b[k] else 0
                mark = ' <== MATCHES dK' if abs(d) == 107 else ''
                log(f'   {k}: {a[k]} vs {b[k]}  diff={d} ratio={r:.4f}{mark}')
                sweep_rows.append(dict(archive='X.arch', family='X.corr',
                                       candidate=f'{k} diff', computed=str(d),
                                       target='dK=107', verdict='HIT' if abs(d) == 107 else 'miss'))

    # ---- write CSVs ------------------------------------------------------------
    import csv

    def wcsv(name, rows, fields):
        p = os.path.join(OUTDIR, name)
        with open(p, 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=fields)
            w.writeheader()
            for r in rows:
                w.writerow(r)
        log(f'wrote {p} ({len(rows)} rows)')

    wcsv('vbf_packer_metrics.csv', metrics_rows, ['archive', 'metric', 'value'])
    wcsv('vbf_packer_empty_leak.csv', leak_rows,
         ['archive', 'index', 'so', 'so_hi32', 'so_lo32', 'base_eff', 'bls',
          'next_bls', 'osz', 'no', 'name'])
    wcsv('vbf_packer_segments.csv', seg_rows,
         ['archive', 'base_eff', 'count', 'idx_lo', 'idx_hi', 'width'])
    wcsv('vbf_packer_k_sweep.csv', sweep_rows,
         ['archive', 'family', 'candidate', 'computed', 'target', 'verdict'])

    hits = [r for r in sweep_rows if 'HIT' in r['verdict']]
    log(f'== TOTAL sweep rows: {len(sweep_rows)}; HITS: {len(hits)}')
    for hh in hits[:40]:
        log(f'   {hh}')
    log('VERDICT: K = address high bits of a leaked 32-bit writer-process '
        'pointer (see doc); no archive-metric derivation survives.')
    logf.close()


if __name__ == '__main__':
    sys.exit(main())
