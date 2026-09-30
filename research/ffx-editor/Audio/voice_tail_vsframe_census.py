#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""voice_tail_vsframe_census.py — wave-19 VOICE-TAIL lane.

Census of the `VS\0\0` stream-frame header params (+0x10/+0x14) across every
VS-bearing artifact of the FFX PS2 disc (SLPS-25088):

  * the 42 voiceNN.pvs containers (FND grp25 slots 1..21 / grp27 slots 21..41),
  * proj/sound/us/voice/shout/shout.dat  (grp24 slot5, LBA 388644),
  * optionally wave_wd.dat (grp44 slot0) as a negative/other-format check.

VS frame layout (2048-B sector, fields little-endian):
  +0x00 "VS\0\0"   +0x04 u32 0
  +0x08 u32 frame index within stream (0 = stream start)
  +0x0C u32 frames-remaining-including-self (== stream length on frame 0,
        counts down to 1 on the last frame — REFINES w18's "total frames";
        proven on shout.dat where idx!=0 frames carry the countdown)
  +0x10 u32 param A  (0x0AAA on all 45 shout.dat streams; 0x1000 family on
        event/battle .pvs streams — census below)
  +0x14 u32 param B  (per-stream value; ~0x2A..0x46 in shout.dat)
  +0x18.. payload (VAG/ADPCM audio)

Outputs (csvs dir):
  voice_tail_vsframe_params.csv   one row per STREAM (start frame) with bank
                                  join vs voiceinfo leaves
  voice_tail_vsframe_hist.csv     histogram of (paramA,paramB) by family
  voice_tail_shoutdir.csv         the 45-entry shout.dat directory decoded

Usage:
  voice_tail_vsframe_census.py --iso ISO --fnd cdrom_fnd_map.csv \
      --voiceinfo voiceinfo.bin --shout shout.dat --csvs OUTDIR [--quick]
"""
import argparse, csv, os, struct, sys

VS = b'VS\x00\x00'


def frames_iter(buf, base_off=0):
    """yield (file_off, idx, remain, pA, pB) for each VS sector in buf."""
    n = len(buf) // 2048
    for s in range(n):
        o = s * 2048
        if buf[o:o + 4] != VS:
            yield (base_off + o, None, None, None, None, False)
            continue
        f4, f8, fC, f10, f14 = struct.unpack_from('<IIIII', buf, o + 4)
        yield (base_off + o, f8, fC, f10, f14, True)


def read_iso_range(iso, lba, nbytes):
    iso.seek(lba * 2048)
    return iso.read(((nbytes + 2047) // 2048) * 2048)


def load_fnd(path):
    ent = {}
    for line in open(path):
        c = line.rstrip('\r\n').split(',')
        if len(c) > 11 and c[11].rstrip().endswith('.pvs'):
            try:
                grp, slot, lba, size = int(c[1]), int(c[3]), int(c[4]), int(c[5])
            except ValueError:
                continue
            ent[(grp, slot)] = (c[11].rsplit('/', 1)[-1].strip(), lba, size)
    return ent


def voiceinfo_leaves(path):
    """-> {i1: {leaf_sector: bank}} using the proven u16 trie decode."""
    d = open(path, 'rb').read()
    t = struct.unpack('<%dH' % (len(d) // 2), d)
    n1 = t[0]
    out = {}
    for i1 in range(n1):
        b2 = t[1 + i1]
        n2 = t[b2 // 2]
        m = {}
        for i2 in range(n2):
            b3 = t[b2 // 2 + 1 + i2]
            n3 = t[b3 // 2]
            for i3 in range(n3):
                leaf = t[b3 // 2 + 1 + i3]
                if leaf != 0xFFFF:
                    m[leaf] = i1 * 10000 + i2 * 100 + i3
        out[i1] = m
    return out


def census_pvs(iso, name, lba, size, leafmap):
    """returns (streams:list[dict], novs:int, frames:int)"""
    buf = read_iso_range(iso, lba, size)
    streams = []
    novs = frames = 0
    cur = None
    for off, idx, rem, pA, pB, isvs in frames_iter(buf):
        if not isvs:
            novs += 1
            continue
        frames += 1
        sec = off // 2048
        if idx == 0:
            cur = {'stream_sector': sec, 'frames_declared': rem,
                   'p10': pA, 'p14': pB,
                   'bank': leafmap.get(sec, '')}
            streams.append(cur)
        else:
            # countdown check: rem should equal cur.frames_declared - idx
            pass
    return streams, novs, frames, buf


def census_shout(path):
    d = open(path, 'rb').read()
    dirn = [struct.unpack_from('<I', d, i * 4)[0] for i in range(45)]
    rows = []
    for i, o in enumerate(dirn):
        magic = d[o:o + 4]
        f4, f8, fC, f10, f14 = struct.unpack_from('<IIIII', d, o + 4)
        nxt = dirn[i + 1] if i + 1 < 45 else len(d)
        rows.append({'slot': i, 'off': o, 'magic': magic.decode('latin1'),
                     'idx': f8, 'frames': fC, 'p10': f10, 'p14': f14,
                     'sectors_span': (nxt - o) // 2048})
    return dirn, rows, d


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--iso', required=True)
    ap.add_argument('--fnd', required=True)
    ap.add_argument('--voiceinfo', required=True)
    ap.add_argument('--shout')
    ap.add_argument('--csvs', required=True)
    ap.add_argument('--only', help='limit to comma-separated i1 values')
    args = ap.parse_args()

    os.makedirs(args.csvs, exist_ok=True)
    fnd = load_fnd(args.fnd)
    leaves = voiceinfo_leaves(args.voiceinfo)
    iso = open(args.iso, 'rb')

    only = None
    if args.only:
        only = set(int(x) for x in args.only.split(','))

    stream_rows = []
    hist = {}
    for i1 in range(42):
        if only and i1 not in only:
            continue
        grp, slot = (25, i1 + 1) if i1 < 21 else (27, i1)
        ent = fnd.get((grp, slot))
        if not ent or ent[2] == 0:
            print('voice%02d: NO FND ENTRY' % i1)
            continue
        name, lba, size = ent
        streams, novs, frames, _ = census_pvs(iso, name, lba, size,
                                            leaves.get(i1, {}))
        for st in streams:
            st['i1'] = i1
            st['container'] = name
            st['family'] = 'event' if i1 < 21 else ('shout' if i1 == 21 else 'battle')
            stream_rows.append(st)
            key = (st['family'], st['p10'], st['p14'])
            hist[key] = hist.get(key, 0) + 1
        print('voice%02d %s lba=%d streams=%d novs=%d' %
              (i1, name, lba, len(streams), novs))

    if args.shout:
        dirn, srows, d = census_shout(args.shout)
        for r in srows:
            r2 = dict(r)
            r2.update({'i1': '', 'container': 'shout.dat',
                       'family': 'shoutdat', 'stream_sector': r['off'] // 2048,
                       'frames_declared': r['frames'], 'p10': r['p10'],
                       'p14': r['p14'], 'bank': ''})
            stream_rows.append(r2)
            key = ('shoutdat', r['p10'], r['p14'])
            hist[key] = hist.get(key, 0) + 1
        with open(os.path.join(args.csvs, 'voice_tail_shoutdir.csv'), 'w',
                  newline='') as fh:
            w = csv.DictWriter(fh, fieldnames=list(srows[0].keys()))
            w.writeheader(); w.writerows(srows)
        print('shout.dat: 45 streams, params p10 set=%s p14 range=%s' %
              (sorted({r['p10'] for r in srows}),
               (min(r['p14'] for r in srows), max(r['p14'] for r in srows))))

    fields = ['family', 'i1', 'container', 'bank', 'stream_sector',
              'frames_declared', 'p10', 'p14']
    with open(os.path.join(args.csvs, 'voice_tail_vsframe_params.csv'), 'w',
              newline='') as fh:
        w = csv.DictWriter(fh, fieldnames=fields, extrasaction='ignore')
        w.writeheader()
        for r in stream_rows:
            w.writerow(r)
    with open(os.path.join(args.csvs, 'voice_tail_vsframe_hist.csv'), 'w',
              newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['family', 'p10_hex', 'p10_dec', 'p14_hex', 'p14_dec', 'streams'])
        for (fam, p10, p14), n in sorted(hist.items()):
            w.writerow([fam, hex(p10), p10, hex(p14), p14, n])
    print('wrote %d stream rows; %d distinct (p10,p14) pairs' %
          (len(stream_rows), len(hist)))


if __name__ == '__main__':
    main()
