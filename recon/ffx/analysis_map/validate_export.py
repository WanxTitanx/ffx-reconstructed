"""Validate fetched IDA metadata and compare digests with the pinned original PE."""
import argparse
import collections
import csv
import gzip
import hashlib
import json
import struct
from pathlib import Path

PIN = '78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced'


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def rows(path):
    with gzip.open(path, 'rt', encoding='utf-8', newline='') as stream:
        yield from csv.DictReader(stream, delimiter='\t')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference', type=Path, required=True)
    args = parser.parse_args()
    output = Path(__file__).resolve().parent
    root = output.parents[2]
    metadata = json.loads((output / 'metadata.json').read_text(encoding='utf-8'))
    assert metadata['status'] == 'complete'
    assert metadata['close_database_save'] is False
    assert metadata['autoanalysis_run'] is False
    database = metadata['database']
    hashes = [database[key] for key in ('original_sha256_before', 'original_sha256_after',
                                      'private_sha256_before', 'private_sha256_after')]
    assert len(set(hashes)) == 1
    assert metadata['exporter_sha256'] == sha(root / 'tools/match/export_reassembly_map.py')
    assert all(sha(output / name) == table['sha256'] for name, table in metadata['tables'].items())

    reference = args.reference.read_bytes()
    assert hashlib.sha256(reference).hexdigest() == PIN
    pe = struct.unpack_from('<I', reference, 0x3c)[0]
    section_count = struct.unpack_from('<H', reference, pe + 6)[0]
    optional_size = struct.unpack_from('<H', reference, pe + 20)[0]
    image_base = struct.unpack_from('<I', reference, pe + 24 + 28)[0]
    sections = []
    for number in range(section_count):
        off = pe + 24 + optional_size + 40 * number
        name = reference[off:off + 8].rstrip(b'\0').decode('ascii')
        virtual_size, rva, raw_size, raw_offset = struct.unpack_from('<IIII', reference, off + 8)
        sections.append(dict(name=name, start=image_base + rva, virtual_size=virtual_size,
                             raw_size=raw_size, raw_offset=raw_offset))

    def original_hash(va, size):
        for section in sections:
            delta = va - section['start']
            if 0 <= delta and delta + size <= section['raw_size']:
                begin = section['raw_offset'] + delta
                return hashlib.sha256(reference[begin:begin + size]).hexdigest()
        return None

    functions = {}
    differences = []
    for row in rows(output / 'functions.tsv.gz'):
        start, end, size = int(row['start'], 16), int(row['end'], 16), int(row['size'])
        assert end - start == size and size > 0 and start not in functions
        assert int(row['readable_bytes']) == size
        functions[start] = row
        actual = original_hash(start, size)
        if row['db_sha256'] != actual:
            differences.append(dict(va=row['start'], size=size, name=row['name'],
                                    db_sha256=row['db_sha256'], original_pe_sha256=actual))
    assert len(functions) == metadata['tables']['functions.tsv.gz']['rows']
    chunks_per_function = collections.Counter()
    chunk_sizes = collections.Counter()
    chunk_rows = 0
    for row in rows(output / 'function_ranges.tsv.gz'):
        owner = int(row['function_start'], 16)
        assert owner in functions
        assert int(row['end'], 16) - int(row['start'], 16) == int(row['size']) > 0
        assert int(row['readable_bytes']) == int(row['size'])
        chunks_per_function[owner] += 1
        chunk_sizes[owner] += int(row['size'])
        chunk_rows += 1
    assert chunk_rows == metadata['tables']['function_ranges.tsv.gz']['rows']
    for owner, row in functions.items():
        assert chunks_per_function[owner] == int(row['chunk_count'])
        assert chunk_sizes[owner] == int(row['total_chunk_bytes'])

    text = next(s for s in metadata['segments'] if s['name'] == '.text')
    pe_text = next(s for s in sections if s['name'] == '.text')
    cursor = text['start']
    counts, sizes, unbacked = collections.Counter(), collections.Counter(), collections.Counter()
    runs = []
    for row in rows(output / 'text_items.tsv.gz'):
        start, end, size = int(row['start'], 16), int(row['end'], 16), int(row['size'])
        kind = row['kind']
        assert start == cursor and end - start == size > 0
        assert int(row['item_head'], 16) <= start < end <= int(row['item_end'], 16)
        if kind == 'code':
            assert start == int(row['item_head'], 16) and end == int(row['item_end'], 16)
            assert 1 <= size <= 15
        cursor = end
        counts[kind] += 1
        sizes[kind] += size
        unbacked[kind] += max(0, end - max(start, pe_text['start'] + pe_text['raw_size']))
        if runs and runs[-1]['kind'] == kind and runs[-1]['end'] == start:
            runs[-1]['end'] = end
            runs[-1]['items'] += 1
        else:
            runs.append(dict(start=start, end=end, kind=kind, items=1))
    assert cursor == text['end']
    assert dict(counts) == metadata['text_classification_rows']
    assert dict(sizes) == metadata['text_classification_bytes']
    assert sum(counts.values()) == metadata['tables']['text_items.tsv.gz']['rows']
    with gzip.open(output / 'text_runs.tsv.gz', 'wt', encoding='utf-8', newline='') as stream:
        writer = csv.writer(stream, delimiter='\t', lineterminator='\n')
        writer.writerow(['start', 'end', 'size', 'kind', 'item_count'])
        for run in runs:
            writer.writerow([hex(run['start']), hex(run['end']), run['end'] - run['start'],
                             run['kind'], run['items']])
    for filename in ('data_items.tsv.gz', 'names.tsv.gz'):
        count = 0
        for row in rows(output / filename):
            if filename.startswith('data_'):
                assert row['kind'] in ('data', 'alignment', 'string')
                assert int(row['end'], 16) - int(row['start'], 16) == int(row['size']) > 0
            else:
                assert int(row['item_size']) == int(row['item_end'], 16) - int(row['item_head'], 16)
                assert int(row['offset_in_item']) == int(row['va'], 16) - int(row['item_head'], 16)
            count += 1
        assert count == metadata['tables'][filename]['rows']
    assert sha(args.reference) == PIN
    report = {'status': 'validated', 'metadata_sha256': sha(output / 'metadata.json'),
              'validator_sha256': sha(__file__), 'reference_sha256': PIN,
              'reference_unchanged': True, 'all_table_hashes_and_row_counts_match': True,
              'database_sha256': hashes[0], 'original_and_private_db_unchanged': True,
              'functions': len(functions), 'function_ranges': chunk_rows,
              'function_byte_matches': len(functions) - len(differences),
              'function_byte_disagreements': differences, 'text_counts': dict(counts),
              'text_bytes': dict(sizes), 'text_ranges_contiguous': True,
              'text_run_count': len(runs), 'text_runs_sha256': sha(output / 'text_runs.tsv.gz'),
              'ida_text_start': hex(text['start']), 'ida_text_end': hex(text['end']),
              'ida_text_size': text['end'] - text['start'], 'pe_text': pe_text,
              'text_unbacked_bytes_by_kind': dict(unbacked),
              'scope': 'Native saved IDA typing; original PE bytes retain precedence.'}
    (output / 'validation.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
