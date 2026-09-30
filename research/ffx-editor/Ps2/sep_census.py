#!/usr/bin/env python3
"""sep_census.py — census of embedded `.sep` ("SeSep   ") SE-program records.

Wave-19 (SEP-VARIANT lane, 2026-09-18). Residual of wave-18 SEB-LOADER.

WHAT `.sep` IS (byte-verified, this lane):
  * NOT a file on disc. No `*.sep` exists in any mounted FFX corpus.
  * A 16-byte-headed record: `+0x00 char[8] "SeSep   "`, `+0x08 u32 LE sep id`
    (registered on the IOP tagged `id|0x80000000`), `+0x0c u32 LE record size`
    (includes header; %4==0), `+0x10` a `.seb`-grammar record blob
    {u8 tracks, u16LE waveDataId, u8 argA, u8 argB, LE-u16 deltas[T]
    (bit15=chain), T program streams} + 0..3 pad bytes.
  * Lives inside event `.ebp` files, inside the EV01 chunk-2 "SeSep chunk":
    `+0x00 u32 = 0x40000000|len0` (bit30 tag required), `+0x04..+0x1c u32
    segLen[7]`, `+0x20` segment0 records, then segments 1..7 back-to-back
    (PC decode: FFX_SeSep_WalkRecordsAndSubmit 0x871720 — idb-event wave).
  * PS2 transport: EE DMAs the chosen segment to IOP staging 0x18fb4 via
    `SeSepSend` (SLPS_250.88 0x2525a8) + ring cmd 39 {+0 size,+4 flag};
    IOP worker 0x149f4 registers each record into the 192-entry sep table
    *(0x1938c). Play: ring cmd 41/42 with block+4 bit0=1 -> 0x7a84.

WHAT THIS DOES
  * scans every *.ebp under the given roots for the 8-byte "SeSep   " magic,
    parses each record (seid/size/inner record), clusters contiguous runs
    into segments, and validates each run head for the optional
    {0x40000000|len0, segLen[7]} chunk header 0x20 bytes before it.
  * emits a per-record CSV and a per-file CSV.

USAGE
  sep_census.py <root>... --records sep_records.csv --files sep_files.csv
"""
import argparse
import csv
import os
import struct
import sys

MAGIC = b'SeSep   '


def parse_record(d, pos):
    """Parse one SeSep record at pos. Returns dict or None."""
    if d[pos:pos + 8] != MAGIC:
        return None
    seid, size = struct.unpack_from('<II', d, pos + 8)
    if size < 0x14 or (size & 3) or pos + size > len(d):
        return None
    p = pos + 0x10
    t = d[p]
    if t == 0 or t > 32:
        return None
    end = pos + size
    if p + 5 + 2 * t > end:
        return None
    rid = d[p + 1] | (d[p + 2] << 8)
    a, b = d[p + 3], d[p + 4]
    deltas = [(d[p + 5 + 2 * i] | (d[p + 6 + 2 * i] << 8)) for i in range(t)]
    lens = [x & 0x7fff for x in deltas]
    chains = [bool(x & 0x8000) for x in deltas]
    inner = 5 + 2 * t + sum(lens)
    pad = size - 0x10 - inner
    if pad < 0 or pad > 3:
        return None
    return {'pos': pos, 'seid': seid, 'size': size, 'tracks': t, 'rid': rid,
            'arg_a': a, 'arg_b': b, 'deltas': lens, 'chains': chains,
            'inner': inner, 'pad': pad}


def scan_file(path):
    d = open(path, 'rb').read()
    recs = []
    pos = 0
    while True:
        i = d.find(MAGIC, pos)
        if i < 0:
            break
        r = parse_record(d, i)
        if r:
            recs.append(r)
            pos = i + r['size']
        else:
            pos = i + 8
    # cluster contiguous runs -> segments
    segs = []
    cur = None
    for r in recs:
        if cur and r['pos'] == cur['end']:
            cur['recs'].append(r)
            cur['end'] = r['pos'] + r['size']
        else:
            cur = {'start': r['pos'], 'end': r['pos'] + r['size'], 'recs': [r],
                   'hdr_ok': False, 'seg_index': -1}
            segs.append(cur)
    # validate a chunk header 0x20 before each run that starts a chunk:
    # header = {0x40000000|len0, segLen[7]}; each declared segment length ==
    # the record run plus a zero pad trailer (observed: run + 4 in corpus).
    for si, seg in enumerate(segs):
        h = seg['start'] - 0x20
        if h >= 0:
            tag = struct.unpack_from('<I', d, h)[0]
            run_len = seg['end'] - seg['start']
            len0 = tag & 0x3FFFFFFF
            gap = len0 - run_len
            if (tag & 0xC0000000) == 0x40000000 and 0 <= gap <= 0x1f \
               and all(b == 0 for b in d[seg['end']:seg['end'] + gap]):
                seg['hdr_ok'] = True
                seg['seg_index'] = 0
                # following runs are segments 1..7 of this chunk, placed at
                # DECLARED offsets from the run start
                nxt = seg['start'] + len0
                lens = struct.unpack_from('<7I', d, h + 4)
                for k, ln in enumerate(lens):
                    if not ln:
                        continue
                    for s2 in segs:
                        if s2['start'] == nxt:
                            s2['seg_index'] = k + 1
                            s2['hdr_ok'] = True
                    nxt += ln
    return recs, segs


def main(argv=None):
    ap = argparse.ArgumentParser(description='FFX .sep (SeSep) census')
    ap.add_argument('roots', nargs='+')
    ap.add_argument('--records', metavar='CSV')
    ap.add_argument('--files', metavar='CSV')
    args = ap.parse_args(argv)

    rec_rows, file_rows = [], []
    seen = set()
    for root in args.roots:
        for dp, _dn, fn in os.walk(root):
            for f in fn:
                if not f.lower().endswith('.ebp'):
                    continue
                p = os.path.join(dp, f)
                rel = p[p.find('/master/') + 8:] if '/master/' in p else p
                key = rel
                if key in seen:
                    continue
                seen.add(key)
                try:
                    recs, segs = scan_file(p)
                except Exception as e:
                    file_rows.append([rel, p, 'ERR', str(e), '', '', '', ''])
                    continue
                if not recs:
                    continue
                game = 'ffx2' if '/ffx2/' in p else 'ffx'
                nseg = sum(1 for s in segs if s['seg_index'] >= 0)
                file_rows.append([rel, p, 'OK', game, len(recs),
                                  len(segs), nseg,
                                  ';'.join(hex(s['start']) for s in segs)])
                for s in segs:
                    for r in s['recs']:
                        rec_rows.append([
                            rel, r['pos'], s['seg_index'], hex(r['seid']),
                            hex(r['size']), r['tracks'], hex(r['rid']),
                            r['arg_a'], r['arg_b'],
                            ' '.join(str(x) for x in r['deltas']),
                            int(any(r['chains'])), r['inner'], r['pad']])

    rec_rows.sort(key=lambda x: (x[0], x[1]))
    file_rows.sort(key=lambda x: x[0])
    if args.records:
        with open(args.records, 'w', newline='') as f:
            w = csv.writer(f)
            w.writerow(['file', 'file_off', 'segment', 'sep_id', 'size',
                        'tracks', 'wave_id', 'arg_a', 'arg_b',
                        'track_deltas', 'any_chain_bit', 'inner_size', 'pad'])
            w.writerows(rec_rows)
        print(f'# {len(rec_rows)} records -> {args.records}')
    if args.files:
        with open(args.files, 'w', newline='') as f:
            w = csv.writer(f)
            w.writerow(['rel_path', 'abs_path', 'status', 'game',
                        'records', 'runs', 'tagged_segments',
                        'run_offsets_hex'])
            w.writerows(file_rows)
        print(f'# {len(file_rows)} files with SeSep -> {args.files}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
