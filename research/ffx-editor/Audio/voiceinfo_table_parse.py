#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""voiceinfo_table_parse.py — FFX PS2/PC voiceinfo.bin table decoder (wave-18 research).

Decodes the runtime voice bank -> stream-sector table `voiceinfo.bin`
(FND group 25 'event_voice' entry 0; SLPS-25088 LBA 3013, 25856 bytes;
PC build loads the same file into `TkVoicePtr` via FFX_AnimatedBg_LoadInit).

Format (PROVEN against PC FFX.exe decompile @0x887700 + on-disc .pvs scan):
  u16 t[] (LE). All internal links are BYTE offsets from t[0].
    t[0]        = n1 (group count, 42 on SLPS-25088)
    t[1+i1]     -> L2 block of group i1
    L2 block:   t[b/2] = n2; t[b/2+1+i2] -> L3 block
    L3 block:   t[b/2] = n3; t[b/2+1+i3] = leaf, 0xFFFF = "no voice"

Operand decode (voice id n1284, ATEL voice operand):
    bank = n1284 >> 12            (6-digit decimal)
    i1   = bank // 10000          -> container group
    i2   = (bank // 100) % 100    -> L2 index
    i3   = bank % 100             -> L3 index / stream index
    leaf = L3[i3]                 -> sector (2048B) of VS stream in container
    span = next non-FFFF leaf - leaf  -> stream length in sectors

Routing (validator; PS2 0x2D70C0, PC 0x885B00):
    i1 < 21 -> FND group 25 event_voice, slot = i1+1 -> voice{i1:02d}.pvs
    i1 >=21 -> FND group 27 battle_voice, slot = i1   -> voice{i1:02d}.pvs

Usage:
    voiceinfo_table_parse.py <voiceinfo.bin> [--csvs DIR] [--iso PATH --fnd CSV]
"""
import argparse, csv, os, struct, sys

SENT = 0xFFFF

def parse(path):
    d = open(path, 'rb').read()
    t = struct.unpack('<%dH' % (len(d) // 2), d)
    n1 = t[0]
    rows, groups = [], []
    for i1 in range(n1):
        b2 = t[1 + i1]
        n2 = t[b2 // 2]
        gvalid = gsent = 0
        gmin = None; gmax = None
        for i2 in range(n2):
            b3 = t[b2 // 2 + 1 + i2]
            n3 = t[b3 // 2]
            for i3 in range(n3):
                cell_off = b3 + 2 + 2 * i3
                leaf = t[cell_off // 2]
                bank = i1 * 10000 + i2 * 100 + i3
                sent = leaf == SENT
                if sent:
                    gsent += 1
                else:
                    gvalid += 1
                    gmin = leaf if gmin is None else min(gmin, leaf)
                    gmax = leaf if gmax is None else max(gmax, leaf)
                rows.append({
                    'i1': i1, 'i2': i2, 'i3': i3, 'bank': bank,
                    'leaf': '' if sent else leaf,
                    'sentinel': int(sent),
                    'cell_byte_off': cell_off,
                    'l2_byte_off': b2, 'l3_byte_off': b3,
                    'n2': n2, 'n3': n3,
                })
        groups.append({
            'i1': i1, 'n2': n2, 'cells': gvalid + gsent,
            'valid': gvalid, 'sentinels': gsent,
            'leaf_min': '' if gmin is None else gmin,
            'leaf_max': '' if gmax is None else gmax,
            'l2_byte_off': b2,
            'fnd_group': 25 if i1 < 21 else 27,
            'fnd_slot': i1 + 1 if i1 < 21 else i1,
            'container': 'voice%02d.pvs' % i1,
        })
    # span = distance to next non-FFFF leaf in the same L3 block
    by_bank = {r['bank']: r for r in rows}
    for r in rows:
        r['span_sectors'] = ''
    for i1 in range(n1):
        b2 = t[1 + i1]
        n2 = t[b2 // 2]
        for i2 in range(n2):
            b3 = t[b2 // 2 + 1 + i2]
            n3 = t[b3 // 2]
            leaves = [t[b3 // 2 + 1 + k] for k in range(n3)]
            for i3, leaf in enumerate(leaves):
                if leaf == SENT:
                    continue
                nxt = None
                for k in range(i3 + 1, n3):
                    if leaves[k] != SENT:
                        nxt = leaves[k]; break
                span = 0 if (nxt is None or nxt <= leaf) else nxt - leaf
                by_bank[i1 * 10000 + i2 * 100 + i3]['span_sectors'] = span
    return d, t, rows, groups

def scan_pvs(f, lba, size):
    nsec = (size + 2047) // 2048
    f.seek(lba * 2048)
    dd = f.read(nsec * 2048)
    starts = []
    novs = 0
    for s in range(nsec):
        o = s * 2048
        if dd[o:o + 4] != b'VS\x00\x00':
            novs += 1
            continue
        if struct.unpack_from('<I', dd, o + 8)[0] == 0:
            starts.append(s)
    return starts, novs

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('voiceinfo')
    ap.add_argument('--csvs', help='output dir for CSVs')
    ap.add_argument('--iso', help='PS2 ISO for .pvs correlation')
    ap.add_argument('--fnd', help='cdrom_fnd_map.csv for LBA/size lookup')
    args = ap.parse_args()

    d, t, rows, groups = parse(args.voiceinfo)
    print('file %s  bytes=%d u16=%d n1=%d' % (args.voiceinfo, len(d), len(t), t[0]))
    valid = sum(1 for r in rows if not r['sentinel'])
    sent = sum(1 for r in rows if r['sentinel'])
    print('cells=%d valid=%d sentinel=%d' % (len(rows), valid, sent))

    # pvs correlation
    corr = []
    if args.iso and args.fnd:
        fnd = {}
        with open(args.fnd, newline='') as fh:
            for line in fh:
                c = line.rstrip('\r\n').split(',')
                if len(c) > 11 and 'voice' in c[11] and c[11].rstrip().endswith('.pvs'):
                    grp = int(c[1]); idx = int(c[3])
                    lba = int(c[4]); size = int(c[5])
                    fnd[(grp, idx)] = (c[11].rsplit('/', 1)[-1].strip(), lba, size)
        iso = open(args.iso, 'rb')
        for g in groups:
            i1 = g['i1']
            grp = g['fnd_group']; slot = g['fnd_slot']
            ent = fnd.get((grp, slot))
            if not ent or ent[2] == 0:
                corr.append({**g, 'pvs_file': '', 'lba': '', 'size': '',
                             'streams': '', 'novs_sectors': '', 'match': 'NO_FND_ENTRY'})
                continue
            name, lba, size = ent
            starts, novs = scan_pvs(iso, lba, size)
            leaves = sorted(int(r['leaf']) for r in rows
                            if r['i1'] == i1 and not r['sentinel'])
            match = 'EXACT' if starts == leaves else 'MISMATCH'
            corr.append({**g, 'pvs_file': name, 'lba': lba, 'size': size,
                         'streams': len(starts), 'novs_sectors': novs,
                         'match': match})
            print('voice%02d lba=%d size=%d streams=%d leaves=%d %s'
                  % (i1, lba, size, len(starts), len(leaves), match))
        iso.close()

    if args.csvs:
        os.makedirs(args.csvs, exist_ok=True)
        with open(os.path.join(args.csvs, 'voiceinfo_rows.csv'), 'w', newline='') as fh:
            w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
            w.writeheader(); w.writerows(rows)
        with open(os.path.join(args.csvs, 'voiceinfo_groups.csv'), 'w', newline='') as fh:
            w = csv.DictWriter(fh, fieldnames=list(groups[0].keys()))
            w.writeheader(); w.writerows(groups)
        with open(os.path.join(args.csvs, 'voiceinfo_header.csv'), 'w', newline='') as fh:
            w = csv.writer(fh)
            w.writerow(['field', 'value'])
            w.writerow(['file', args.voiceinfo])
            w.writerow(['bytes', len(d)])
            w.writerow(['n1_groups', t[0]])
            w.writerow(['cells_total', len(rows)])
            w.writerow(['valid_leaves', valid])
            w.writerow(['sentinels', sent])
            w.writerow(['l1_ptr_table', 'u16 t[1..42] byte offsets'])
            w.writerow(['l2_record', 'u16 n2 + u16 ptr[n2] (byte offsets)'])
            w.writerow(['l3_record', 'u16 n3 + u16 leaf[n3] (0xFFFF=sentinel)'])
        if corr:
            with open(os.path.join(args.csvs, 'voiceinfo_pvs_correlation.csv'), 'w', newline='') as fh:
                w = csv.DictWriter(fh, fieldnames=list(corr[0].keys()))
                w.writeheader(); w.writerows(corr)
        print('csvs written to', args.csvs)

if __name__ == '__main__':
    main()
