"""Load the retained native function-boundary map under a pinned contract.

The modification linker uses this inventory to decide whether an original
function has one complete, non-shared extent.  This loader validates the
retained exporter/validator receipts and the compressed table without opening
the original executable.
"""
import csv
import gzip
import io
from pathlib import Path
import re

import leaf_build as support


REFERENCE_SHA256 = '78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced'
REFERENCE_SIZE = 10675712
IMAGE_BASE = 0x400000
TEXT_START = 0x401000
TEXT_END = 0xB0C000
FUNCTIONS = 66557
FUNCTION_RANGE_ROWS = 72473
FUNCTION_RANGE_BYTES = 3342074
FUNCTION_RANGE_SHA256 = '6a94d0ac5190ad374ee8ec333e2dfd49e5e0fca680d5597fd8aed3dc0e7995bc'
FUNCTION_RANGE_COLUMNS = (
    'function_start',
    'start',
    'end',
    'size',
    'kind',
    'db_sha256',
    'readable_bytes',
)
TABLE_NAME = 'function_ranges.tsv.gz'
ADDRESS = re.compile(r'0x[0-9a-f]{8}')


def _invalid(detail):
    raise ValueError('invalid native function-boundary inventory: ' + detail)


def _read(path, retained):
    data = path.read_bytes()
    retained[path] = data
    return data


def _metadata_contract(metadata, exporter_digest):
    if type(metadata.get('schema_version')) is not int or metadata['schema_version'] != 1:
        _invalid('metadata schema is not version 1')
    expected = {
        'status': 'complete',
        'classification_source': 'saved native IDA item flags and boundaries',
        'input_filename': 'FFX.exe',
        'input_size_recorded_in_db': REFERENCE_SIZE,
        'input_sha256_recorded_in_db': REFERENCE_SHA256,
        'image_base': f'0x{IMAGE_BASE:08x}',
        'processor': 'metapc',
        'is_64bit': False,
        'autoanalysis_run': False,
        'close_database_save': False,
        'pinned_reference_sha256_expected': REFERENCE_SHA256,
        'machine_byte_truth': 'Original pinned PE, never modified DB bytes.',
        'functions': FUNCTIONS,
        'function_ranges': FUNCTION_RANGE_ROWS,
        'exporter_sha256': exporter_digest,
    }
    for key, value in expected.items():
        if metadata.get(key) != value or type(metadata.get(key)) is not type(value):
            _invalid('metadata field disagrees with retained contract: ' + key)

    format_ = metadata.get('format')
    if not isinstance(format_, dict) or any(format_.get(key) != value for key, value in {
            'encoding': 'UTF-8', 'delimiter': 'tab', 'compression': 'gzip',
            'addresses': 'hexadecimal VA', 'intervals': '[start,end)',
    }.items()):
        _invalid('metadata table format is unsupported')

    tables = metadata.get('tables')
    table = tables.get(TABLE_NAME) if isinstance(tables, dict) else None
    if not isinstance(table, dict) or set(table) != {
            'columns', 'rows', 'compressed_bytes', 'sha256'}:
        _invalid('function-range table receipt is missing or malformed')
    if (table.get('columns') != list(FUNCTION_RANGE_COLUMNS)
            or type(table.get('rows')) is not int or table['rows'] != FUNCTION_RANGE_ROWS
            or type(table.get('compressed_bytes')) is not int
            or table['compressed_bytes'] != FUNCTION_RANGE_BYTES
            or table.get('sha256') != FUNCTION_RANGE_SHA256):
        _invalid('function-range table receipt differs from the pinned inventory')

    segments = metadata.get('segments')
    text = ([item for item in segments
             if isinstance(item, dict) and item.get('name') == '.text']
            if isinstance(segments, list) else [])
    if len(text) != 1:
        _invalid('metadata must contain one native .text segment')
    text = text[0]
    if any(text.get(key) != value for key, value in {
            'start': TEXT_START, 'end': TEXT_END, 'class': 'CODE',
            'bitness': 1, 'permissions': 5, 'segment_type': 2,
            'covered_bytes': TEXT_END - TEXT_START,
    }.items()):
        _invalid('native .text segment differs from the retained map')

    database = metadata.get('database')
    if not isinstance(database, dict):
        _invalid('database provenance is missing')
    hash_keys = ('original_sha256_before', 'original_sha256_after',
                 'private_sha256_before', 'private_sha256_after')
    hashes = [database.get(key) for key in hash_keys]
    if (any(not support.is_digest(value) for value in hashes) or len(set(hashes)) != 1
            or database.get('original_unchanged') is not True
            or database.get('private_unchanged') is not True
            or type(database.get('database_size')) is not int
            or database['database_size'] <= 0):
        _invalid('database provenance does not prove an unchanged private export')
    return table, text, hashes[0]


def _validation_contract(validation, metadata_data, validator_digest, database_digest):
    expected = {
        'status': 'validated',
        'metadata_sha256': support.digest(metadata_data),
        'validator_sha256': validator_digest,
        'reference_sha256': REFERENCE_SHA256,
        'reference_unchanged': True,
        'all_table_hashes_and_row_counts_match': True,
        'database_sha256': database_digest,
        'original_and_private_db_unchanged': True,
        'functions': FUNCTIONS,
        'function_ranges': FUNCTION_RANGE_ROWS,
        'text_ranges_contiguous': True,
        'ida_text_start': hex(TEXT_START),
        'ida_text_end': hex(TEXT_END),
        'ida_text_size': TEXT_END - TEXT_START,
    }
    for key, value in expected.items():
        if validation.get(key) != value or type(validation.get(key)) is not type(value):
            _invalid('validation receipt disagrees with retained contract: ' + key)
    pe_text = validation.get('pe_text')
    if not isinstance(pe_text, dict) or any(pe_text.get(key) != value for key, value in {
            'name': '.text', 'start': TEXT_START, 'virtual_size': 7383675,
            'raw_size': 7384064, 'raw_offset': 1024,
    }.items()):
        _invalid('validation receipt has an unexpected original .text layout')


def _parse_rows(table_data):
    if len(table_data) != FUNCTION_RANGE_BYTES or support.digest(table_data) != FUNCTION_RANGE_SHA256:
        _invalid('compressed function-range table differs from the pinned inventory')
    try:
        plain = gzip.decompress(table_data)
        text = plain.decode('utf-8')
    except (OSError, UnicodeError) as exc:
        raise ValueError('invalid native function-boundary inventory: unreadable gzip table') from exc
    if not text.endswith('\n') or '\x00' in text:
        _invalid('function-range table is not canonical UTF-8 text')
    try:
        reader = csv.DictReader(io.StringIO(text, newline=''), delimiter='\t')
        if reader.fieldnames != list(FUNCTION_RANGE_COLUMNS):
            _invalid('function-range table columns differ from the receipt')
        rows = list(reader)
    except csv.Error as exc:
        raise ValueError('invalid native function-boundary inventory: malformed TSV') from exc
    if len(rows) != FUNCTION_RANGE_ROWS:
        _invalid('function-range table row count differs from the receipt')

    seen = set()
    entry_owners = set()
    owners = set()
    previous = None
    for number, row in enumerate(rows, 2):
        if set(row) != set(FUNCTION_RANGE_COLUMNS) or any(
                not isinstance(row.get(key), str) or not row[key] for key in FUNCTION_RANGE_COLUMNS):
            _invalid('malformed function-range row %d' % number)
        if any(ADDRESS.fullmatch(row[key]) is None for key in ('function_start', 'start', 'end')):
            _invalid('noncanonical address in function-range row %d' % number)
        try:
            owner = int(row['function_start'], 16)
            start = int(row['start'], 16)
            end = int(row['end'], 16)
            size = int(row['size'])
            readable = int(row['readable_bytes'])
        except ValueError as exc:
            raise ValueError('invalid native function-boundary inventory: invalid integer row') from exc
        if (row['kind'] not in ('entry', 'tail') or not support.is_digest(row['db_sha256'])
                or not TEXT_START <= owner < TEXT_END or not TEXT_START <= start < end <= TEXT_END
                or end - start != size or size <= 0 or readable != size):
            _invalid('invalid function-range geometry or hash at row %d' % number)
        if (row['kind'] == 'entry') != (owner == start):
            _invalid('entry/tail ownership disagrees at row %d' % number)
        key = (owner, start, end, row['kind'])
        order = (owner, start, end, 0 if row['kind'] == 'entry' else 1)
        if key in seen or (previous is not None and order < previous):
            _invalid('duplicate or unsorted function-range row %d' % number)
        previous = order
        seen.add(key)
        owners.add(owner)
        if row['kind'] == 'entry':
            if owner in entry_owners:
                _invalid('function has multiple entry ranges at %#x' % owner)
            entry_owners.add(owner)
    if len(entry_owners) != FUNCTIONS or owners != entry_owners:
        _invalid('function owners do not have exactly one entry range')
    return rows


def load_inventory(root: Path, observed: dict) -> list[dict]:
    """Validate and return the real ``function_ranges.tsv.gz`` rows.

    All retained files are read from ``root``; the original executable is not
    consulted.  On success their immutable byte snapshots are merged into
    ``observed`` for the caller's final provenance check.
    """
    if not isinstance(observed, dict):
        raise TypeError('observed must be a path-to-bytes dictionary')
    root = Path(root).resolve()
    folder = root / 'recon/ffx/analysis_map'
    paths = {
        'metadata': folder / 'metadata.json',
        'validation': folder / 'validation.json',
        'validator': folder / 'validate_export.py',
        'table': folder / TABLE_NAME,
        'exporter': root / 'tools/match/export_reassembly_map.py',
    }
    retained = {}
    metadata_data = _read(paths['metadata'], retained)
    validation_data = _read(paths['validation'], retained)
    validator_data = _read(paths['validator'], retained)
    table_data = _read(paths['table'], retained)
    exporter_data = _read(paths['exporter'], retained)

    metadata = support.parse_json(metadata_data, 'native analysis metadata')
    validation = support.parse_json(validation_data, 'native analysis validation receipt')
    table, _text, database_digest = _metadata_contract(metadata, support.digest(exporter_data))
    _validation_contract(validation, metadata_data, support.digest(validator_data), database_digest)
    if (table['compressed_bytes'] != len(table_data)
            or table['sha256'] != support.digest(table_data)):
        _invalid('function-range table bytes differ from metadata')
    rows = _parse_rows(table_data)

    support.check_unchanged(retained)
    for path, data in retained.items():
        if path in observed and observed[path] != data:
            _invalid('caller observed a different retained input: ' + str(path))
    observed.update(retained)
    return rows
