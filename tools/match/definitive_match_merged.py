#!/usr/bin/env python3
"""Strict verifier with dumpbin label merging.

definitive_match.py starts a new candidate at every label, so a function whose
dumpbin output contains an internal jump target ($LN35:) is measured as its
entry basic block only. That under-counts every candidate directory whose
objects place internal labels. This merges all bytes of one file into a single
candidate before applying the same one-boundary rule.

Usage: definitive_match_merged.py <dump-dis-dir> <inventory.tsv> <out.json>
"""
import collections, csv, json, os, re, sys

sys.path.insert(0, '/mnt/ssd-kingston/ffx-reconstructed/tools/match')
import definitive_match as D
import corpus_va_verify2 as V2


def main():
    dis_dir, inv_path, out_path = sys.argv[1], sys.argv[2], sys.argv[3]
    data, secs = D.load_pe(D.EXE_DEFAULT)
    read = D.va_reader(data, secs)
    by_size = collections.defaultdict(list)
    va_name = {}
    for r in csv.DictReader(open(inv_path, encoding='utf-8'), delimiter='\t'):
        va = int(r['start'], 16)
        by_size[int(r['size'])].append(va)
        va_name[va] = r['name']

    confirmed, ambiguous, scanned = [], 0, 0
    for fn in sorted(os.listdir(dis_dir)):
        if not fn.endswith('.txt'):
            continue
        by_addr, names = V2.merge_units(os.path.join(dis_dir, fn))
        blob = V2.contiguous_all(by_addr)
        if blob is None or len(blob) < 16:
            continue
        scanned += 1
        hits = [va for va in by_size.get(len(blob), ())
                if (lambda ref: ref is not None and D.equal_modulo_relocations(blob, ref)[0])(read(va, len(blob)))]
        if len(hits) == 1:
            confirmed.append({'object': fn[:-4], 'source_name': names[0] if names else '?',
                              'size': len(blob), 'va': hits[0], 'idb_name': va_name[hits[0]]})
        elif len(hits) > 1:
            ambiguous += 1
    json.dump(confirmed, open(out_path, 'w'), indent=1)
    print(f'candidates scanned            : {scanned}')
    print(f'exactly one boundary          : {len(confirmed)}')
    print(f'ambiguous                     : {ambiguous}')
    print(f'bytes                         : {sum(c["size"] for c in confirmed):,}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())

