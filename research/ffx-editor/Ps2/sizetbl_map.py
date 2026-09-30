#!/usr/bin/env python3
"""sizetbl_map.py — decode sizetbl.bin and map every entry to its FND record.

Mission (Jarvis lane SIZETBL-MAP, wave-19, 2026-09-18): close the sizetbl.bin
residual left by wave-18 CDFND-TAIL. Findings implemented here (all proven
from shipped artifacts — retail ISO bytes + SLPS_250.88 MIPS disasm +
dev master corpus; see docs/reverse/FFX_SIZETBL_MAP_2026-09-18.md):

  * sizetbl.bin (retail FND idx15, alias idx14, LBA 2988) is a PURE ARRAY of
    16,304 x u24 LE entries — NO header, NO trailer. Entry i covers file
    index i (identity map); index 16,304 (dvd_last, alias) has no entry.
  * entry[i] = file i's logical size in 8-byte units:
      runtime (SLPS 0x162EB8): s2 = index*3; v0 = *(0x595AE8)+s2;
      size = (lbu(v0) | lbu(v0+1)<<8 | lbu(v0+2)<<16) << 3.
      Used ONLY for mdg flag1 (bit22, 0x400000) entries that the member
      table (0x165D70) does not cover; bit31 entries early-out to 0.
  * aliases (flags==2) always have entry 0 (8,887/8,887 in range).
  * every flag1 member's on-disc record starts at lba*2048 with
      {u8 tag, u24 unpacked_size, u16 aux, stored_stream}
    where unpacked_size == sizetbl*8 minus 0..7 pad (sizetbl = align8(u24))
    — verified 6,823/6,823. tag in {0,1,2}; aux low byte always 0,
    aux>>8 = a per-type code (1=battle/kernel, 4=map, 18=music,
    136/144/200=chr/event...). u24 = the member's logical size
    (== master file size for 5,364/5,761 comparable members; the rest
    is dev-vs-retail build drift). The stored stream is a PACKED
    re-serialization (not byte-identical; leading format magics like
    "MAP1"/"BGM " survive verbatim): stored length = mdg delta - 6
    < u24 for 6,815/6,823 — this is why "sizetbl > lba-delta" for most
    members (wave-18's "overlap" guess is refuted by a byte test:
    zeroes follow the stored stream, nothing spills into the next
    extent). 8 members store ~raw bytes (stored = u24 + 1..2 pad,
    e.g. idx13 system.cnf.hdd is verbatim plaintext).
  * flag0 members: sizetbl == delta for 590/594; exceptions are sizetbl.bin
    itself (stale constant 45,208 — see doc) and the three big adpcm movie
    .dat files where sizetbl = real content size < overallocated LBA range.

USAGE
  sizetbl_map.py --csv out.csv            # full 16,305-row map
  sizetbl_map.py --dir outdir             # map + regional + anomalies + packhdr census
  sizetbl_map.py --summary                # census + verdict stats
  sizetbl_map.py --dump N                 # record header hex for index N

Defaults: canonical corpus paths; override --iso/--master/--cddata/--cdidx.
stdlib only. Exit 0 ok, 2 usage, 4 missing input.
"""

import argparse
import csv
import os
import struct
import sys

ISO = ('/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/'
       'Final Fantasy X International (Japan) (En,Ja).iso')
MASTER1 = '/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master'
MASTER2 = '/mnt/nvme-xpg/ffx_ps2/ffx/master'
CDDATA = '/mnt/nvme-xpg/ffx_ps2/ffx/proj/battle/jp/cddata'
CDIDX = '/mnt/nvme-xpg/ffx_ps2/ffx/proj/prog/cdidx'
CENSUS = ('docs/reverse/data/wave15/cdfnd_tail_bit31_census.csv')

DISC_FAT_LBA, DISC_FAT_SECTORS = 280, 64
SIZETBL_LBA = 2988          # retail mdg idx15/14 lba
LBA_MASK = 0x3FFFFF


def _read(p):
    with open(p, 'rb') as f:
        return f.read()


def load_mdg(iso_path):
    with open(iso_path, 'rb') as f:
        f.seek(DISC_FAT_LBA * 2048)
        return list(struct.unpack('<32768I', f.read(DISC_FAT_SECTORS * 2048)))


def load_sizetbl(iso_path, entries):
    """Read the on-disc sizetbl.bin extent (mdg idx15), return u24 list."""
    lba = entries[15] & LBA_MASK
    nxt = entries[16] & LBA_MASK
    top8 = entries[15] >> 24
    size = (nxt - lba) * 2048 - top8 * 8
    with open(iso_path, 'rb') as f:
        f.seek(lba * 2048)
        d = f.read(size)
    return [d[i * 3] | (d[i * 3 + 1] << 8) | (d[i * 3 + 2] << 16)
            for i in range(size // 3)], d


def master_path(path, masters):
    if not path.startswith('host0:/ffx/master/'):
        return None
    rel = path[len('host0:/ffx/master/'):]
    for m in masters:
        c = os.path.join(m, rel)
        if os.path.exists(c):
            return c
    return None


def build_rows(a):
    E = load_mdg(a.iso)
    V, raw = load_sizetbl(a.iso, E)
    census = list(csv.DictReader(open(a.census)))
    masters = [m for m in (a.master, a.master2) if m and os.path.isdir(m)]
    rows = []
    with open(a.iso, 'rb') as f:
        for r in census:
            i = int(r['index'])
            fl = int(r['flags_22_23'])
            lb = E[i] & LBA_MASK
            dl = int(r['delta_size'])
            sz = V[i] * 8 if i < len(V) else None
            tag = u24 = aux = ''
            if fl == 1 and dl > 0 and i < len(V):
                f.seek(lb * 2048)
                h = f.read(6)
                tag = h[0]
                u24 = h[1] | (h[2] << 8) | (h[3] << 16)
                aux = h[4] | (h[5] << 8)
            mf = master_path(r['path'], masters)
            real = os.path.getsize(mf) if mf else ''
            # verdict columns
            st = sz if sz is not None else ''
            if i >= len(V):
                verdict = 'no_entry'
            elif fl == 2:
                verdict = 'alias' if st == 0 else 'alias_nonzero'
            elif fl == 1:
                if u24 == '':
                    verdict = 'no_record'
                elif st == u24:
                    verdict = 'u24_eq'
                elif st is not None and st - 8 < u24 < st:
                    verdict = 'u24_eq_align8'
                else:
                    verdict = 'u24_mismatch'
            else:
                verdict = ('flag0_eq_delta' if st == dl
                           else 'flag0_anomaly')
            rows.append(dict(
                file_idx=i, group=r['group'], group_name=r['group_name'],
                slot=r['slot'], path=r['path'], flags=fl,
                bit31=r['bit31'], cls=r['class'], lba=lb,
                top8=r['top8'], mdg_extent=dl,
                sizetbl_entry=(V[i] if i < len(V) else ''),
                sizetbl_size=st, rec_tag=tag, rec_u24=u24, rec_aux=aux,
                stored_len=(dl - 6 if fl == 1 and dl > 0 else ''),
                real_size=real,
                delta=((st - real) if (st != '' and real != '') else ''),
                verdict=verdict))
    return rows, V


MAP_COLS = ['file_idx', 'group', 'group_name', 'slot', 'path', 'flags',
            'bit31', 'cls', 'lba', 'top8', 'mdg_extent', 'sizetbl_entry',
            'sizetbl_size', 'rec_tag', 'rec_u24', 'rec_aux', 'stored_len',
            'real_size', 'delta', 'verdict']


def _write(path, cols, rows):
    with open(path, 'w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=cols)
        w.writeheader()
        w.writerows(rows)
    print(f'wrote {path}: {len(rows)} rows')


def cmd_csv(a):
    rows, _ = build_rows(a)
    _write(a.csv, MAP_COLS, rows)


def cmd_dir(a):
    """Emit the full wave-19 artefact set into a directory."""
    import glob
    rows, _ = build_rows(a)
    _write(os.path.join(a.dir, 'sizetbl_map.csv'), MAP_COLS, rows)
    # ── anomalies: every non-clean verdict (exception set for the doc) ──
    anom = [r for r in rows
            if r['verdict'] not in ('u24_eq', 'flag0_eq_delta', 'alias')]
    _write(os.path.join(a.dir, 'sizetbl_anomalies.csv'), MAP_COLS, anom)
    # ── curated exceptions: raw members + flag0 anomalies + no_entry ──
    exc = []
    for r in rows:
        kind = note = None
        if r['verdict'] == 'no_entry':
            kind, note = 'no_entry', 'idx 16304 dvd_last alias - beyond table'
        elif r['verdict'] == 'flag0_anomaly':
            kind = 'flag0_sizetbl_ne_delta'
            note = ('stale self-entry' if r['file_idx'] == 15 else
                    'overallocated LBA region; sizetbl=real size')
        elif (r['flags'] == 1 and r['stored_len'] != ''
              and r['rec_u24'] != ''
              and int(r['stored_len']) >= int(r['rec_u24'])):
            kind, note = ('flag1_stored_ge_u24',
                          'raw/incompressible member (slack<=8B)')
        if kind:
            exc.append(dict(r, kind=kind, note=note))
    _write(os.path.join(a.dir, 'sizetbl_exceptions.csv'),
           MAP_COLS + ['kind', 'note'], exc)
    # ── packed-member header census: tag x aux_lo x aux_hi + samples ──
    from collections import defaultdict
    agg = defaultdict(lambda: [0, None])
    for r in rows:
        if r['flags'] == 1 and r['rec_aux'] != '':
            k = (int(r['rec_tag']), int(r['rec_aux']) & 0xFF,
                 int(r['rec_aux']) >> 8)
            agg[k][0] += 1
            if agg[k][1] is None:
                agg[k][1] = r['path']
    cen = [dict(rec_tag=t, aux_lo=lo, aux_hi=hi, count=c, sample_path=p)
           for (t, lo, hi), (c, p) in sorted(agg.items())]
    _write(os.path.join(a.dir, 'sizetbl_packhdr_census.csv'),
           ['rec_tag', 'aux_lo', 'aux_hi', 'count', 'sample_path'], cen)
    # ── regional table census: one row per shipped sizetbl.bin variant ──
    reg = []
    pats = ([os.path.join(a.cdidx, 'sizetbl.bin')]
            + sorted(glob.glob(os.path.join(a.cdidx, '*', 'sizetbl.bin'))))
    for p in pats:
        if not os.path.exists(p):
            continue
        d = _read(p)
        V = [d[i * 3] | (d[i * 3 + 1] << 8) | (d[i * 3 + 2] << 16)
             for i in range(len(d) // 3)]
        rel = os.path.relpath(p, a.cdidx)
        variant = rel.split(os.sep)[0] if os.sep in rel else '(root)'
        reg.append(dict(
            variant=variant, bytes=len(d), entries=len(V),
            mod3=len(d) % 3, entry14=(V[14] if len(V) > 14 else ''),
            entry15=(V[15] if len(V) > 15 else ''),
            entry15_size=(V[15] * 8 if len(V) > 15 else ''),
            nonzero=sum(1 for v in V if v), max_entry=max(V) if V else 0))
    _write(os.path.join(a.dir, 'sizetbl_regional.csv'),
           ['variant', 'bytes', 'entries', 'mod3', 'entry14', 'entry15',
            'entry15_size', 'nonzero', 'max_entry'], reg)


def cmd_summary(a):
    from collections import Counter
    rows, V = build_rows(a)
    st = Counter(r['verdict'] for r in rows)
    print(f'sizetbl entries: {len(V)} (u24 LE, x8B units; covers idx 0..{len(V)-1})')
    for k, c in st.most_common():
        print(f'  {k:22s} {c}')
    f1 = [r for r in rows if r['flags'] == 1]
    tagc = Counter(r['rec_tag'] for r in f1)
    print('flag1 rec tags:', dict(tagc))
    compr = sum(1 for r in f1
                if r['stored_len'] != '' and r['rec_u24'] != ''
                and int(r['stored_len']) < int(r['rec_u24']))
    print(f'flag1 stored<u24 (compressed): {compr}/{len(f1)}')


def cmd_dump(a):
    E = load_mdg(a.iso)
    V, _ = load_sizetbl(a.iso, E)
    i = int(a.dump, 0)
    lb = E[i] & LBA_MASK
    e = E[i]
    print(f'idx{i} mdg={e:#010x} lba={lb} top8={e>>24} flags={(e>>22)&3} '
          f'sizetbl[{i}]={V[i] if i < len(V) else "-"} '
          f'({V[i]*8 if i < len(V) else 0} B)')
    with open(a.iso, 'rb') as f:
        f.seek(lb * 2048)
        d = f.read(64)
    print('record head:', d[:32].hex())


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument('--iso', default=ISO)
    ap.add_argument('--master', default=MASTER1)
    ap.add_argument('--master2', default=MASTER2)
    ap.add_argument('--cddata', default=CDDATA)
    ap.add_argument('--cdidx', default=CDIDX)
    ap.add_argument('--census', default=CENSUS)
    ap.add_argument('--csv', metavar='OUT')
    ap.add_argument('--dir', metavar='OUTDIR')
    ap.add_argument('--summary', action='store_true')
    ap.add_argument('--dump', metavar='IDX')
    a = ap.parse_args()
    if not os.path.exists(a.iso):
        sys.exit(f'missing iso {a.iso}')
    if not os.path.exists(a.census):
        sys.exit(f'missing census {a.census}')
    did = False
    if a.csv:
        cmd_csv(a); did = True
    if a.dir:
        cmd_dir(a); did = True
    if a.summary:
        cmd_summary(a); did = True
    if a.dump is not None:
        cmd_dump(a); did = True
    if not did:
        ap.print_help()
        return 2
    return 0


if __name__ == '__main__':
    sys.exit(main())
