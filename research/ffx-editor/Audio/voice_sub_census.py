#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""voice_sub_census.py — wave-20 VOICE-SUB lane.

Answers the two residual questions left by waves 18-19, with byte-level proof:

  1. voice21 (i1==21) "event/shout-like" subfamily — full trie census, per-stream
     VS params, and a BYTE-LEVEL comparison of the 45 voice21.pvs streams vs the
     45 shout.dat directory slots (same logical set? same audio?).
  2. Speaker-pair (f2/f3 variant chars) semantics beyond speaker-pack — the
     pair->character census, per-bank-line pair stability (collision check),
     and whether the f3 axis is a uniform sub-class or pair-specific.

Inputs:
  --iso        PS2 ISO (SLPS-25088 master image)
  --fnd        cdrom_fnd_map.csv (grp25/grp27 -> voiceNN.pvs LBA/size)
  --voiceinfo  voiceinfo.bin (u16 trie)
  --shout      shout.dat (45-entry dir + VS streams, grp24 slot5)
  --mapper     wave13 voice_mapper_records.csv (voiceId -> NNNNNNcc names)
  --csvs       output dir

Outputs (csvs dir):
  voice_sub_voice21_trie.csv       45 trie rows: bank, sector, span, pair,
                                   speaker, shout-slot index
  voice_sub_voice21_vs_shout.csv   per-slot voice21.pvs[k] vs shout.dat[k]:
                                   frames/p10/p14 + payload prefix-match bytes
  voice_sub_speaker_pairs.csv      pair -> character census (banks, lines,
                                   f1/f2 axis role)
  voice_sub_pair_stability.csv     per-pair stability + line-collision stats
  voice_sub_voice17_shoutlike.csv  the separate 1718xx shout-like family

Usage:
  voice_sub_census.py --iso ISO --fnd FND.csv --voiceinfo voiceinfo.bin \
      --shout shout.dat --mapper voice_mapper_records.csv --csvs OUTDIR
"""
import argparse
import csv
import os
import struct

VS = b'VS\x00\x00'

# Canonical speaker labels for the 23 real alphabetic pairs (wave-13/19 census).
SPEAKER = {
    'td': 'Tidus', 'yn': 'Yuna', 'an': 'Auron', 'km': 'Kimahri',
    'wk': 'Wakka', 'rr': 'Lulu', 'rk': 'Rikku', 'sm': 'Seymour',
    'jc': 'Jecht(?)', 'bs': 'boss(?)', 'sd': 'side(?)', 'dn': '(?)',
    'yr': 'blitz-announcer(?)', 'am': 'announcer(?)',
    'ga': 'crowd-a', 'gb': 'crowd-b', 'gc': 'crowd-c', 'gd': 'crowd-d',
    'ge': 'crowd-e', 'gf': 'crowd-f', 'gg': 'crowd-g', 'gh': 'crowd-h',
    'gi': 'crowd-i',
}


def read_iso_range(iso, lba, nbytes):
    iso.seek(lba * 2048)
    return iso.read(((nbytes + 2047) // 2048) * 2048)


def load_fnd(path):
    ent = {}
    for line in open(path):
        c = line.rstrip('\r\n').split(',')
        if len(c) > 11:
            try:
                grp, slot, lba, size = int(c[1]), int(c[3]), int(c[4]), int(c[5])
            except ValueError:
                continue
            ent[(grp, slot)] = (c[11].rsplit('/', 1)[-1].strip(), lba, size)
    return ent


def voiceinfo_trie(path):
    """-> rows [{i1,i2,i3,bank,sector,sentinel}] in walk order."""
    d = open(path, 'rb').read()
    t = struct.unpack('<%dH' % (len(d) // 2), d)
    n1 = t[0]
    rows = []
    for i1 in range(n1):
        b2 = t[1 + i1]
        n2 = t[b2 // 2]
        for i2 in range(n2):
            b3 = t[b2 // 2 + 1 + i2]
            n3 = t[b3 // 2]
            for i3 in range(n3):
                leaf = t[b3 // 2 + 1 + i3]
                rows.append({'i1': i1, 'i2': i2, 'i3': i3,
                             'bank': i1 * 10000 + i2 * 100 + i3,
                             'sector': leaf if leaf != 0xFFFF else '',
                             'sentinel': 1 if leaf == 0xFFFF else 0})
    return rows


def vs_streams(buf, base_sector=0):
    """yield dict(stream_sector, frames, p10, p14, start_off, end_off)."""
    n = len(buf) // 2048
    streams = []
    cur = None
    for s in range(n):
        o = s * 2048
        if buf[o:o + 4] != VS:
            continue
        _f4, f8, fC, f10, f14 = struct.unpack_from('<IIIII', buf, o + 4)
        if f8 == 0:
            cur = {'stream_sector': base_sector + s, 'frames': fC,
                   'p10': f10, 'p14': f14, 'start_off': o, 'end_off': o + 2048}
            streams.append(cur)
        elif cur is not None:
            cur['end_off'] = o + 2048
    return streams


def shout_dir(path):
    d = open(path, 'rb').read()
    dirn = [struct.unpack_from('<I', d, i * 4)[0] for i in range(45)]
    rows = []
    for i, o in enumerate(dirn):
        f4, f8, fC, f10, f14 = struct.unpack_from('<IIIII', d, o + 4)
        nxt = dirn[i + 1] if i + 1 < 45 else len(d)
        rows.append({'slot': i, 'off': o, 'frames': fC, 'p10': f10, 'p14': f14,
                     'end_off': nxt})
    return rows, d


def pack_chars(vid):
    return ((vid >> 6) & 0x1F) + 0x60, (vid & 0x1F) + 0x60


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--iso', required=True)
    ap.add_argument('--fnd', required=True)
    ap.add_argument('--voiceinfo', required=True)
    ap.add_argument('--shout', required=True)
    ap.add_argument('--mapper', required=True)
    ap.add_argument('--csvs', required=True)
    args = ap.parse_args()

    os.makedirs(args.csvs, exist_ok=True)
    fnd = load_fnd(args.fnd)
    trie = voiceinfo_trie(args.voiceinfo)
    iso = open(args.iso, 'rb')

    # ---- voice21.pvs + voice17.pvs streams -----------------------------------
    v21_name, v21_lba, v21_size = fnd[(27, 21)]
    v21_buf = read_iso_range(iso, v21_lba, v21_size)
    v21_streams = vs_streams(v21_buf)

    v17_name, v17_lba, v17_size = fnd[(25, 18)]  # slot 18 -> voice17.pvs
    v17_buf = read_iso_range(iso, v17_lba, v17_size)
    v17_streams = vs_streams(v17_buf)

    # voice21 valid leaves in walk order (sector order == stream order)
    v21_rows = [r for r in trie if r['i1'] == 21]
    v21_valid = [r for r in v21_rows if not r['sentinel']]
    # map sector -> stream
    by_sec = {s['stream_sector']: s for s in v21_streams}

    # speaker pair per bank from mapper names (formula) + legacy id names
    pair_of_bank = {}
    for line in open(args.mapper):
        c = line.rstrip('\r\n').split(',')
        if len(c) >= 3 and c[2] and c[2][0].isdigit() and len(c[2]) == 8:
            pair_of_bank[int(c[2][:6])] = c[2][6:8]

    # ---- 1. voice21 trie census ----------------------------------------------
    srows, sbuf = shout_dir(args.shout)
    order = [r for r in v21_valid]  # already sector-ordered
    with open(os.path.join(args.csvs, 'voice_sub_voice21_trie.csv'), 'w',
              newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['shout_slot', 'i1', 'i2', 'i3', 'bank', 'sector',
                    'span_sectors', 'pair', 'speaker', 'frames', 'p10_hex',
                    'p14_dec'])
        for k, r in enumerate(order):
            st = by_sec.get(r['sector'], {})
            pair = pair_of_bank.get(r['bank'], '')
            spk = SPEAKER.get(pair, '')
            # span = sectors to next valid leaf (== stream length); last leaf
            # runs to the .pvs end.
            if k + 1 < len(order):
                span = order[k + 1]['sector'] - r['sector']
            else:
                span = (v21_size // 2048) - r['sector']
            w.writerow([k, r['i1'], r['i2'], r['i3'], r['bank'], r['sector'],
                        span, pair, spk, st.get('frames', ''),
                        hex(st['p10']) if st else '', st.get('p14', '')])
    print('voice21 trie: %d valid leaves, %d streams in .pvs' %
          (len(v21_valid), len(v21_streams)))

    # ---- 2. voice21.pvs[k] vs shout.dat[k] ------------------------------------
    with open(os.path.join(args.csvs, 'voice_sub_voice21_vs_shout.csv'), 'w',
              newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['slot', 'bank', 'pair', 'speaker',
                    'v21_frames', 'v21_p10', 'v21_p14',
                    'shout_frames', 'shout_p10', 'shout_p14',
                    'p14_match', 'frames_delta', 'payload_prefix_match_bytes',
                    'payload_prefix_match_pct'])
        for k, r in enumerate(order):
            st = by_sec.get(r['sector'])
            sd = srows[k] if k < len(srows) else None
            pair = pair_of_bank.get(r['bank'], '')
            spk = SPEAKER.get(pair, '')
            v_payload = v21_buf[st['start_off']:st['end_off']] if st else b''
            s_payload = sbuf[sd['off']:sd['end_off']] if sd else b''
            n = min(len(v_payload), len(s_payload))
            match = 0
            while match < n and v_payload[match] == s_payload[match]:
                match += 1
            pct = round(100.0 * match / n, 2) if n else 0
            w.writerow([k, r['bank'], pair, spk,
                        st['frames'] if st else '',
                        hex(st['p10']) if st else '',
                        st['p14'] if st else '',
                        sd['frames'] if sd else '',
                        hex(sd['p10']) if sd else '',
                        sd['p14'] if sd else '',
                        int(st and sd and st['p14'] == sd['p14']),
                        (st['frames'] - sd['frames']) if st and sd else '',
                        match, pct])
    print('voice21 vs shout.dat: compared %d slots' % len(order))

    # ---- 3. pair -> character census ------------------------------------------
    recs = []
    first = True
    for line in open(args.mapper):
        if first:
            first = False
            continue
        c = line.rstrip('\r\n').split(',')
        if len(c) >= 8:
            recs.append(c)
    # formula records: name NNNNNNcc, kind=formula
    stats = {}   # pair -> {records, banks:set(bank), i1:set, lines:set((i1,i2,i3))}
    line_pairs = {}  # (i1,i2,i3) -> set(pairs)
    for c in recs:
        name = c[2]
        if not (len(name) == 8 and name[:6].isdigit()):
            continue
        bank = int(name[:6]); pair = name[6:8]
        i1, i2, i3 = bank // 10000, (bank // 100) % 100, bank % 100
        s = stats.setdefault(pair, {'records': 0, 'banks': set(),
                                    'i1': set(), 'lines': set()})
        s['records'] += 1
        s['banks'].add(bank); s['i1'].add(i1); s['lines'].add((i1, i2, i3))
        line_pairs.setdefault((i1, i2, i3), set()).add(pair)

    with open(os.path.join(args.csvs, 'voice_sub_speaker_pairs.csv'), 'w',
              newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['pair', 'speaker', 'records', 'distinct_banks',
                    'distinct_i1_groups', 'distinct_lines', 'f1_char',
                    'f1_shared_with', 'axis_role'])
        for pair in sorted(stats):
            s = stats[pair]
            f1 = pair[0]
            shared = sorted(p for p in stats if p[0] == f1)
            role = ('crowd-member-index' if f1 == 'g' and len(shared) > 1
                    else 'opaque-2letter-code')
            w.writerow([pair, SPEAKER.get(pair, '?'), s['records'],
                        len(s['banks']), len(s['i1']), len(s['lines']),
                        f1, '|'.join(shared), role])
    print('pairs: %d real speaker pairs' % len(stats))

    # ---- 4. pair stability / line collisions ----------------------------------
    multi = {ln: ps for ln, ps in line_pairs.items() if len(ps) > 1}
    g_multi = {ln: ps for ln, ps in line_pairs.items()
               if sum(1 for p in ps if p[0] == 'g') > 1}
    with open(os.path.join(args.csvs, 'voice_sub_pair_stability.csv'), 'w',
              newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['metric', 'value'])
        w.writerow(['formula_records', sum(s['records'] for s in stats.values())])
        w.writerow(['real_speaker_pairs', len(stats)])
        w.writerow(['distinct_lines(i1i2i3)', len(line_pairs)])
        w.writerow(['lines_with_>1_pair', len(multi)])
        w.writerow(['lines_with_>1_g_family_pair', len(g_multi)])
        w.writerow(['pairs_seen_in_>1_i1_group',
                    sum(1 for s in stats.values() if len(s['i1']) > 1)])
        w.writerow(['max_banks_per_pair', max(len(s['banks'])
                                              for s in stats.values())])
        w.writerow(['pair_is_speaker_stable_across_banks', 'YES'
                    if not multi else 'NO'])
        for ln, ps in sorted(multi.items()):
            w.writerow(['COLLISION %d/%02d/%02d' % ln, '|'.join(sorted(ps))])
    print('stability: lines=%d multi-pair-lines=%d' %
          (len(line_pairs), len(multi)))

    # ---- 5. voice17 shout-like family ------------------------------------------
    v17_valid = [r for r in trie if r['i1'] == 17 and not r['sentinel']
                 and r['i2'] == 18]
    v17_by_sec = {s['stream_sector']: s for s in v17_streams}
    with open(os.path.join(args.csvs, 'voice_sub_voice17_shoutlike.csv'), 'w',
              newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['i1', 'i2', 'i3', 'bank', 'sector', 'pair', 'frames',
                    'p10_hex', 'p14_dec'])
        for r in v17_valid:
            st = v17_by_sec.get(r['sector'], {})
            w.writerow([r['i1'], r['i2'], r['i3'], r['bank'], r['sector'],
                        pair_of_bank.get(r['bank'], ''), st.get('frames', ''),
                        hex(st['p10']) if st else '', st.get('p14', '')])
    print('voice17 shout-like: %d streams' % len(v17_valid))


if __name__ == '__main__':
    main()
