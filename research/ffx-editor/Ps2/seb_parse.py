#!/usr/bin/env python3
"""seb_parse.py — parser/census for FFX PS2 `.seb` SE-bank containers.

Wave-18 (Jarvis-RESEARCH lane, 2026-09-18). Format recovered from
IOPSOUND.IRX disassembly (IopSoundDriver v2.14, IOP R3000):

  * RPC fno 12 -> trampoline 0x11e48 -> `seb_load` 0xbec4:
      sprintf("%ssave/block/se%3.3u.seb", root, bank) -> file_size(0xf4c8)
      -> dual-mode read 0xf714 -> `seb_commit` 0xbe50 -> heap image *(0x1873c)
  * header (validated vs se000.seb):
      +0x00  char[8]  "SeBlock "
      +0x08  u16 LE   reserved (0)
      +0x0a  u16 LE   index count N (128 in shipping banks)
      +0x0c  u32 LE   total file size (read by 0xbe50 for the heap copy)
      +0x10  u32 LE   offsets[N] relative to records_base = +0x10+N*4;
                      -1 (0xffffffff) = slot absent
  * record (variable length; walked by 0x79a0/0xbb10, played by 0x75fc):
      +0     u8       track count T (number of SE-program streams)
      +1..2  u16 LE   resource id -> se-entry table *(0x19308) (+4) / cmd40
                      (0 in every shipping record = no prefetch resource)
      +3     u8       arg A (0x71c8 a1; -> state+0x50)
      +4     u8       arg B (0x71c8 a2; nonzero -> 0x6d80(A,B))
      +5     BE-u16   track deltas[T] — each is the BYTE DISTANCE from this
                      track's program start to the next; bit15 (0x8000) =
                      "another track chained" (0x75fc pre-count loop)
      +5+2T  blob     T back-to-back SE-program bytecode streams
                      (varint-prefixed, read by 0x6118; opcodes via the
                      144-entry SE-opcode table @0x174c0)
      record size = 5 + 2*T + sum(delta & 0x7fff)

  * consumers: ring cmd40 0x11e6c (index->id->play/queue),
    ring cmd41 0x12078 / cmd42 0x120f0 (index->0x79a0->0x75fc full play;
    block&1 -> 0x7a84 stop variant). Dead-code resolver 0xbb10 documents
    the same walk (returns id, calls wave-cache 0xaaa8 — no live caller).

USAGE
  seb_parse.py <file.seb> [--records] [--csv out.csv]
  seb_parse.py --census <dir>...   # walk dirs, census every *.seb
"""
import argparse
import os
import struct
import sys


def parse(path):
    d = open(path, 'rb').read()
    if d[:8] != b'SeBlock ':
        raise ValueError(f'{path}: bad magic {d[:8]!r}')
    rsv, count, size = struct.unpack_from('<HHI', d, 8)
    base = 0x10 + count * 4
    recs = []
    for i in range(count):
        off = struct.unpack_from('<i', d, 0x10 + i * 4)[0]
        if off < 0:
            recs.append({'idx': i, 'off': -1})
            continue
        r = base + off
        n = d[r]
        rid = d[r + 1] | (d[r + 2] << 8)
        a, b = d[r + 3], d[r + 4]
        deltas = [((d[r + 6 + t * 2] << 8) | d[r + 5 + t * 2])
                  for t in range(n)]
        chains = [bool(x & 0x8000) for x in deltas]
        lens = [x & 0x7fff for x in deltas]
        recs.append({'idx': i, 'off': off, 'vaddr': r, 'tracks': n,
                     'id': rid, 'a': a, 'b': b, 'deltas': lens,
                     'chains': chains,
                     'size': 5 + 2 * n + sum(lens)})
    return {'path': path, 'size_field': size, 'size_actual': len(d),
            'reserved': rsv, 'count': count, 'base': base, 'recs': recs}


def census(paths):
    rows = []
    for root in paths:
        for dp, _dn, fn in os.walk(root):
            for f in fn:
                if not f.lower().endswith('.seb'):
                    continue
                p = os.path.join(dp, f)
                try:
                    s = parse(p)
                    pres = sum(1 for r in s['recs'] if r['off'] >= 0)
                    trks = sum(r.get('tracks', 0) for r in s['recs'])
                    rows.append((p, s['size_actual'], s['size_field'],
                                 s['count'], pres, trks,
                                 'OK' if s['size_actual'] == s['size_field']
                                 else 'SIZE-MISMATCH'))
                except Exception as e:
                    rows.append((p, os.path.getsize(p), '', '', '', '',
                                 f'ERR {e}'))
    return rows


def main(argv=None):
    ap = argparse.ArgumentParser(description='FFX .seb SE-bank parser')
    ap.add_argument('files', nargs='*')
    ap.add_argument('--records', action='store_true',
                    help='dump every record of each file')
    ap.add_argument('--census', action='store_true',
                    help='treat files[] as dirs, census all *.seb')
    ap.add_argument('--csv', metavar='OUT.csv')
    args = ap.parse_args(argv)

    rows = []
    if args.census:
        for r in census(args.files):
            print('  '.join(str(c) for c in r))
            rows.append(r)
        if args.csv:
            import csv
            with open(args.csv, 'w', newline='') as f:
                w = csv.writer(f)
                w.writerow(['path', 'size_actual', 'size_field', 'count',
                            'records_present', 'total_tracks', 'status'])
                w.writerows(rows)
            print(f'# wrote {len(rows)} rows -> {args.csv}')
        return 0

    for p in args.files:
        s = parse(p)
        pres = [r for r in s['recs'] if r['off'] >= 0]
        print(f'# {p}')
        print(f'# magic="SeBlock " count={s["count"]} '
              f'size_field={s["size_field"]} actual={s["size_actual"]} '
              f'records_base=0x{s["base"]:x} present={len(pres)}')
        for r in (s['recs'] if args.records else pres):
            if r['off'] < 0:
                if args.records:
                    print(f"  [{r['idx']:3}] <absent>")
                continue
            print(f"  [{r['idx']:3}] @0x{r['vaddr']:05x} sz={r['size']:4} "
                  f"tracks={r['tracks']:2} id={r['id']} "
                  f"a={r['a']} b={r['b']} deltas={r['deltas']} "
                  f"chain={''.join('1' if c else '0' for c in r['chains'])}")
            rows.append((p, r['idx'], f"0x{r['vaddr']:x}", r['size'],
                         r['tracks'], r['id'], r['a'], r['b'],
                         ' '.join(str(x) for x in r['deltas'])))
    if args.csv:
        import csv
        with open(args.csv, 'w', newline='') as f:
            w = csv.writer(f)
            w.writerow(['file', 'index', 'file_off', 'size', 'tracks',
                        'resource_id', 'arg_a', 'arg_b', 'track_deltas'])
            w.writerows(rows)
        print(f'# wrote {len(rows)} rows -> {args.csv}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
