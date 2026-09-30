#!/usr/bin/env python3
"""Verify compiled x86 functions after resolving their COFF REL32 calls."""
import argparse
import csv
import hashlib
import json
import os
import re
import sys
from collections import defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import definitive_match as D


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('dis_dir')
    parser.add_argument('reloc_dir')
    parser.add_argument('inventory')
    parser.add_argument('output')
    parser.add_argument('--exe', default=D.EXE_DEFAULT)
    parser.add_argument('--text-section', type=int, default=3)
    args = parser.parse_args()
    D.EXE_DEFAULT = args.exe
    import corpus_va_verify2 as C

    with open(args.inventory, encoding='utf-8') as f:
        rows = list(csv.DictReader(f, delimiter='\t'))
    by_va = {int(row['start'], 16): row for row in rows}
    symbols = defaultdict(set)
    for row in rows:
        symbols[row['name']].add(int(row['start'], 16))

    data, sections = D.load_pe(args.exe)
    read = D.va_reader(data, sections)
    stats = defaultdict(int)
    matches = []
    for filename in sorted(os.listdir(args.dis_dir)):
        match = re.fullmatch(r'dis_f([0-9A-Fa-f]{6,8})\.txt', filename)
        if not match:
            continue
        va = int(match.group(1), 16)
        row = by_va.get(va)
        if row is None:
            stats['missing_inventory'] += 1
            continue
        size = int(row['size'])
        ref = read(va, size)
        if ref is None:
            stats['missing_pe_bytes'] += 1
            continue
        by_addr, labels = C.merge_units(os.path.join(args.dis_dir, filename))
        code = C.contiguous_all(by_addr)
        if code is None:
            stats['non_contiguous'] += 1
            continue
        if len(code) != size:
            stats['size_mismatch'] += 1
            continue
        reloc_path = os.path.join(args.reloc_dir, 'rel_f%08X.txt' % va)
        if not os.path.isfile(reloc_path):
            stats['missing_relocation_dump'] += 1
            continue
        relocations = D.parse_dumpbin_relocations(
            open(reloc_path, encoding='utf-8', errors='replace').read(),
            args.text_section,
        )
        stats['rel32_candidates'] += len(relocations)
        try:
            fixed = D.resolve_rel32_relocations(code, va, relocations, symbols)
        except ValueError as error:
            stats['unresolved_or_unsupported'] += 1
            continue
        if fixed != ref:
            stats['resolved_byte_mismatch'] += 1
            continue
        matches.append({
            'va': va,
            'size': size,
            'idb_name': row['name'],
            'source_name': labels[0] if labels else '?',
            'relocations': [
                {
                    'offset': offset,
                    'type': relocation_type,
                    'symbol': symbol,
                    'target_va': next(iter(symbols[D.normalize_coff_symbol(symbol)])),
                }
                for offset, relocation_type, symbol in relocations
            ],
            'sha256': hashlib.sha256(ref).hexdigest(),
        })
        stats['strict_exact'] += 1
        stats['strict_bytes'] += size

    result = {
        'executable_sha256': hashlib.sha256(data).hexdigest(),
        'text_relocation_section': args.text_section,
        'summary': dict(stats),
        'matches': matches,
    }
    with open(args.output, 'w', encoding='utf-8') as f:
        json.dump(result, f, indent=2)
        f.write('\n')
    print(json.dumps(result['summary'], sort_keys=True))


if __name__ == '__main__':
    main()
