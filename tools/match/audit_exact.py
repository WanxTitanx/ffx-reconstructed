#!/usr/bin/env python3
"""Audit cached candidate disassemblies without changing shared coverage files.

Inventory rows with incorrect hashes receive no coverage, but remain ambiguity
competitors. The original inventory and full executable are hashed in the report.
"""
import argparse
import csv
import hashlib
import json
import tempfile
from pathlib import Path

import definitive_match as match

DEFAULT_GROUPS = ('lua_all_out/dis', 'phyre_all_dis', 'phyre_fi2_dis',
                  'phyre_ia32_dis', 'phyre_ia32full_dis', 'phyre_gs_dis',
                  'lua_gs_dis', 'ext3_dis')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, required=True)
    parser.add_argument('--output-dir', type=Path, required=True)
    parser.add_argument('--exe', type=Path, default=Path(match.EXE_DEFAULT))
    args = parser.parse_args()
    data, sections = match.load_pe(args.exe)
    digest = hashlib.sha256(data).hexdigest()
    if digest != match.EXE_SHA256:
        raise ValueError('target SHA-256 differs from the pinned executable')
    reader = match.va_reader(data, sections)
    inventory = args.project / 'tools/match/inventory.tsv'
    inventory_data = inventory.read_bytes()
    rows = list(csv.DictReader(inventory_data.decode().splitlines(), delimiter=chr(9)))
    good, bad, seen = [], [], set()
    for row in rows:
        va, size = int(row['start'], 16), int(row['size'])
        raw = reader(va, size)
        actual = hashlib.sha256(raw).hexdigest() if raw is not None else None
        if va in seen or actual != row['sha256'].lower():
            bad.append({'va': row['start'], 'size': size, 'name': row['name'],
                        'recorded_sha256': row['sha256'], 'actual_sha256': actual,
                        'duplicate_address': va in seen})
        else:
            good.append(row)
        seen.add(va)
    output = args.output_dir.resolve()
    output.mkdir(parents=True, exist_ok=True)
    unique, groups, evidence = {}, [], {}
    with tempfile.TemporaryDirectory(prefix='ffx-inventory-') as tmp:
        full_inventory = Path(tmp) / 'inventory-snapshot.tsv'
        full_inventory.write_bytes(inventory_data)
        for group in DEFAULT_GROUPS:
            directory = args.project / 'tools/match' / group
            if not directory.is_dir():
                groups.append({'group': group, 'status': 'missing'})
                continue
            destination = output / (group.replace('/', '_') + '.exact.json')
            print('AUDIT', group, flush=True)
            match.main([str(directory), str(full_inventory), str(destination),
                        '--exe', str(args.exe), '--quarantine-invalid-inventory'])
            records = json.loads(destination.read_text())
            current = {r['va']: r['size'] for r in records}
            unique.update(current)
            for record in records:
                entry = {key: record[key] for key in (
                    'va', 'size', 'idb_name', 'object', 'source_name',
                    'candidate_sha256', 'disassembly_sha256')}
                entry['source_group'] = group
                evidence.setdefault(record['va'], entry)
            groups.append({'group': group, 'status': 'audited',
                           'unique_exact_functions': len(current),
                           'unique_exact_bytes': sum(current.values()),
                           'report_sha256': hashlib.sha256(destination.read_bytes()).hexdigest()})
    report = {
        'target_sha256': digest, 'inventory_sha256': hashlib.sha256(inventory_data).hexdigest(),
        'matcher_sha256': hashlib.sha256(Path(match.__file__).read_bytes()).hexdigest(),
        'inventory_rows': len(rows), 'validated_rows': len(good), 'excluded_rows': bad,
        'groups': groups, 'unique_exact_functions': len(unique),
        'unique_exact_code_bytes': sum(unique.values()),
        'minimum_function_size': 16, 'ambiguous_addresses_included': False,
        'scope': 'cached disassembly bodies, unique boundary, no relocation masking',
        'whole_executable_reconstructed': False,
        'functions': [evidence[va] for va in sorted(evidence)],
    }
    (output / 'audit.json').write_text(json.dumps(report, indent=2) + chr(10))
    print('EXACT UNION:', len(unique), 'functions;', sum(unique.values()), 'bytes;')
    print('EXCLUDED INVENTORY ROWS:', len(bad))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
