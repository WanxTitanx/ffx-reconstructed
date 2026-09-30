#!/usr/bin/env python3
"""Export saved IDA item metadata from a private database copy under py -3.11.

TSV output contains half-open VA ranges, names, declared types, and hashes.
It does not contain opcode blobs or string contents. Original PE bytes remain
authoritative. No autoanalysis or database saving is performed.
"""
import argparse
import collections
import contextlib
import csv
import datetime
import gzip
import hashlib
import io
import json
import shutil
import sys
import time
import traceback
from pathlib import Path
from types import SimpleNamespace

REFERENCE_SHA256 = '78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced'
KNOWN_DISAGREEMENT_VA = 0x90E2E0


def file_hash(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(chunk)
    return digest.hexdigest()


def hex_ea(value):
    return f'0x{int(value):08x}'


def classify(api, flags):
    for name, predicate in (('alignment', api.is_align), ('string', api.is_strlit),
                            ('code', api.is_code), ('data', api.is_data),
                            ('unknown', api.is_unknown)):
        if predicate(flags):
            return name
    raise ValueError('unclassifiable item flags or orphan tail')


def iter_typed_ranges(api, start, end):
    """Partition saved items; preserve instruction boundaries and unknown gaps."""
    if start < 0 or end < start:
        raise ValueError('invalid segment range')
    cursor = start
    while cursor < end:
        head = int(api.get_item_head(cursor))
        if head < 0 or head > cursor:
            raise ValueError(f'invalid item head at {hex_ea(cursor)}')
        kind = classify(api, api.get_flags(head))
        if kind == 'unknown':
            if head != cursor:
                raise ValueError('unknown range cannot be a defined item tail')
            item_end = min(int(api.next_head(cursor, end)), end)
        else:
            item_end = int(api.get_item_end(head))
        stop = min(item_end, end)
        if stop <= cursor:
            raise ValueError(f'invalid item end at {hex_ea(cursor)}')
        yield {'start': cursor, 'end': stop, 'size': stop - cursor,
               'kind': kind, 'item_head': head, 'item_end': item_end}
        cursor = stop


def prepare_private_copy(original, private):
    original, private = Path(original).resolve(), Path(private).resolve()
    if original == private or private.exists():
        raise ValueError('private copy must be a distinct, previously unused path')
    if original.suffix.lower() not in ('.i64', '.idb') or private.suffix.lower() != original.suffix.lower():
        raise ValueError('source and private copy must have matching IDA database extensions')
    before = file_hash(original)
    size = original.stat().st_size
    private.parent.mkdir(parents=True, exist_ok=True)
    with original.open('rb') as src, private.open('xb') as dst:
        shutil.copyfileobj(src, dst, length=1024 * 1024)
    private_hash = file_hash(private)
    if file_hash(original) != before or private_hash != before or private.stat().st_size != size:
        raise ValueError('database changed during private-copy creation')
    return {'original_path': str(original), 'private_path': str(private),
            'database_size': size, 'original_sha256_before': before,
            'private_sha256_before': private_hash}


def load_ida():
    # idapro initializes the native library and may raise a license error.
    import idapro
    import ida_auto
    import ida_bytes
    import ida_funcs
    import ida_ida
    import ida_kernwin
    import ida_name
    import ida_nalt
    import ida_segment
    import idautils
    import idc
    return SimpleNamespace(idapro=idapro, auto=ida_auto, bytes=ida_bytes,
                           funcs=ida_funcs, info=ida_ida, kernel=ida_kernwin,
                           name=ida_name, nalt=ida_nalt, segment=ida_segment,
                           utils=idautils, idc=idc)


def normalized_hash(value):
    if value is None:
        return None
    if isinstance(value, bytes):
        return value.hex() if len(value) in (16, 32) else value.decode('ascii').lower()
    return str(value).lower()


def data_kind(api, flags):
    for name in ('byte', 'word', 'dword', 'qword', 'oword', 'yword', 'zword',
                 'tbyte', 'float', 'double', 'pack_real', 'struct', 'custom'):
        predicate = getattr(api, 'is_' + name, None)
        if predicate is not None and predicate(flags):
            return name
    return ''


@contextlib.contextmanager
def tsv_writer(path, columns):
    with Path(path).open('wb') as binary:
        with gzip.GzipFile(filename='', mode='wb', fileobj=binary, mtime=0, compresslevel=3) as compressed:
            with io.TextIOWrapper(compressed, encoding='utf-8', newline='') as stream:
                writer = csv.writer(stream, delimiter='\t', lineterminator='\n')
                writer.writerow(columns)
                yield writer


def collect_metadata(native, output):
    b, seg_api, util = native.bytes, native.segment, native.utils
    native.auto.enable_auto(False)
    if native.auto.is_auto_enabled():
        raise RuntimeError('could not disable autoanalysis for metadata export')
    tables = {}

    def table_info(name, columns, rows):
        path = output / name
        tables[name] = {'columns': columns, 'rows': rows,
                        'compressed_bytes': path.stat().st_size, 'sha256': file_hash(path)}

    segments = []
    for ea in util.Segments():
        seg = seg_api.getseg(ea)
        if seg is None:
            raise ValueError(f'missing IDA segment at {hex_ea(ea)}')
        segments.append({'start': int(seg.start_ea), 'end': int(seg.end_ea),
                         'name': seg_api.get_segm_name(seg),
                         'class': seg_api.get_segm_class(seg), 'bitness': int(seg.bitness),
                         'permissions': int(seg.perm), 'segment_type': int(seg.type)})
    segments.sort(key=lambda row: row['start'])
    for previous, following in zip(segments, segments[1:]):
        if previous['end'] > following['start']:
            raise ValueError('overlapping IDA segments')
    if not any(s['name'] == '.text' for s in segments):
        raise ValueError('database has no .text segment')
    global_names = {int(ea): name for ea, name in util.Names()}
    names = dict(global_names)

    function_columns = ['start', 'end', 'size', 'flags', 'name', 'chunk_count',
                        'total_chunk_bytes', 'db_sha256', 'readable_bytes']
    chunk_columns = ['function_start', 'start', 'end', 'size', 'kind', 'db_sha256', 'readable_bytes']
    seen = set()
    chunks_count = 0
    known_disagreement = None
    print('[export] function entries and actual function chunks', flush=True)
    with tsv_writer(output / 'functions.tsv.gz', function_columns) as writer, \
            tsv_writer(output / 'function_ranges.tsv.gz', chunk_columns) as chunk_writer:
        for ea in util.Functions():
            function = native.funcs.get_func(ea)
            if function is None:
                raise ValueError(f'missing function at {hex_ea(ea)}')
            start, end = int(function.start_ea), int(function.end_ea)
            if start in seen:
                continue
            if end <= start:
                raise ValueError(f'invalid function range at {hex_ea(start)}')
            seen.add(start)
            chunks = sorted((int(a), int(z)) for a, z in util.Chunks(start))
            if not chunks or any(z <= a for a, z in chunks):
                raise ValueError(f'invalid function chunks at {hex_ea(start)}')
            if any(a[1] > z[0] for a, z in zip(chunks, chunks[1:])):
                raise ValueError(f'overlapping chunks within function at {hex_ea(start)}')
            raw = b.get_bytes(start, end - start)
            readable = len(raw) if raw is not None else 0
            checksum = hashlib.sha256(raw).hexdigest() if raw is not None else ''
            name = native.funcs.get_func_name(start) or ''
            writer.writerow([hex_ea(start), hex_ea(end), end - start, hex(int(function.flags)),
                             name, len(chunks), sum(z - a for a, z in chunks), checksum, readable])
            for a, z in chunks:
                chunk = raw if (a, z) == (start, end) else b.get_bytes(a, z - a)
                chunk_writer.writerow([hex_ea(start), hex_ea(a), hex_ea(z), z - a,
                                       'entry' if a == start else 'tail',
                                       hashlib.sha256(chunk).hexdigest() if chunk is not None else '',
                                       len(chunk) if chunk is not None else 0])
                chunks_count += 1
            if start == KNOWN_DISAGREEMENT_VA:
                known_disagreement = {'va': hex_ea(start), 'end': hex_ea(end), 'size': end - start,
                                      'name': name, 'db_sha256': checksum,
                                      'policy': 'Record separately; original pinned PE bytes remain truth.'}
    table_info('functions.tsv.gz', function_columns, len(seen))
    table_info('function_ranges.tsv.gz', chunk_columns, chunks_count)

    item_columns = ['segment', 'start', 'end', 'size', 'kind', 'item_head', 'item_end',
                    'data_type', 'string_type']
    data_columns = ['segment', 'start', 'end', 'size', 'kind', 'data_type', 'string_type', 'name', 'type_decl']
    text_rows = data_rows = 0
    text_counts, text_bytes = collections.Counter(), collections.Counter()
    has_any_name = getattr(b, 'has_any_name', b.has_name)
    with tsv_writer(output / 'text_items.tsv.gz', item_columns) as text_writer, \
            tsv_writer(output / 'data_items.tsv.gz', data_columns) as data_writer:
        for segment in segments:
            is_text = segment['name'] == '.text'
            count = 0
            covered = 0
            print('[export] items', segment['name'], hex_ea(segment['start']), hex_ea(segment['end']), flush=True)
            for row in iter_typed_ranges(b, segment['start'], segment['end']):
                head = row['item_head']
                kind = row['kind']
                subtype = string_type = ''
                if kind != 'unknown':
                    flags = b.get_flags(head)
                    if head not in names and has_any_name(flags):
                        found_name = native.name.get_name(head)
                        if found_name:
                            names[head] = found_name
                    if kind == 'data':
                        subtype = data_kind(b, flags)
                    elif kind == 'string':
                        string_type = int(native.nalt.get_str_type(head))
                if is_text:
                    text_writer.writerow([segment['name'], hex_ea(row['start']), hex_ea(row['end']),
                                          row['size'], kind, hex_ea(head), hex_ea(row['item_end']),
                                          subtype, string_type])
                    text_counts[kind] += 1
                    text_bytes[kind] += row['size']
                    text_rows += 1
                if kind in ('data', 'alignment', 'string'):
                    data_writer.writerow([segment['name'], hex_ea(row['start']), hex_ea(row['end']),
                                          row['size'], kind, subtype, string_type, names.get(head, ''),
                                          native.idc.get_type(head) or ''])
                    data_rows += 1
                count += 1
                covered += row['size']
            if covered != segment['end'] - segment['start']:
                raise ValueError('typed range coverage does not cover the entire segment')
            segment['typed_ranges'] = count
            segment['covered_bytes'] = covered
    table_info('text_items.tsv.gz', item_columns, text_rows)
    table_info('data_items.tsv.gz', data_columns, data_rows)

    name_columns = ['va', 'name', 'segment', 'kind', 'item_head', 'item_end', 'item_size',
                    'offset_in_item', 'function_start', 'user_named', 'name_source', 'type_decl']
    print('[export] names and declared types', len(names), flush=True)
    with tsv_writer(output / 'names.tsv.gz', name_columns) as writer:
        for ea, name in sorted(names.items()):
            head = int(b.get_item_head(ea))
            stop = int(b.get_item_end(head))
            flags = b.get_flags(head)
            segment = seg_api.getseg(ea)
            owner = native.funcs.get_func(ea)
            writer.writerow([hex_ea(ea), name, seg_api.get_segm_name(segment) if segment else '',
                             classify(b, flags), hex_ea(head), hex_ea(stop), stop - head, ea - head,
                             hex_ea(owner.start_ea) if owner else '', int(b.has_user_name(b.get_flags(ea))),
                             'name_list' if ea in global_names else 'named_item_head',
                             native.idc.get_type(ea) or ''])
    table_info('names.tsv.gz', name_columns, len(names))
    return {'schema_version': 1, 'classification_source': 'saved native IDA item flags and boundaries',
            'input_filename': native.nalt.get_root_filename(),
            'input_path_recorded_in_db': native.nalt.get_input_file_path(),
            'input_size_recorded_in_db': int(native.nalt.retrieve_input_file_size()),
            'input_sha256_recorded_in_db': normalized_hash(native.nalt.retrieve_input_file_sha256()),
            'image_base': hex_ea(native.nalt.get_imagebase()),
            'ida_version': native.kernel.get_kernel_version(),
            'idalib_version': native.idapro.get_library_version(),
            'processor': native.info.inf_get_procname(), 'is_64bit': bool(native.info.inf_is_64bit()),
            'autoanalysis_run': False, 'autoanalysis_enabled_at_export': bool(native.auto.is_auto_enabled()),
            'autoanalysis_queues_empty': bool(native.auto.auto_is_ok()),
            'segments': segments, 'text_classification_rows': dict(text_counts),
            'text_classification_bytes': dict(text_bytes), 'tables': tables,
            'functions': len(seen), 'function_ranges': chunks_count, 'names': len(names),
            'known_reference_disagreement': known_disagreement,
            'pinned_reference_sha256_expected': REFERENCE_SHA256,
            'machine_byte_truth': 'Original pinned PE, never modified DB bytes.',
            'format': {'encoding': 'UTF-8', 'delimiter': 'tab', 'compression': 'gzip',
                       'addresses': 'hexadecimal VA', 'intervals': '[start,end)',
                       'unknown': 'coalesced gaps between defined items',
                       'code': 'one saved instruction item per row, without reanalysis',
                       'strings': 'type/size only; no string contents',
                       'names': 'global name list plus named item heads, including local heads',
                       'db_sha256': 'IDA bytes digest only; no raw bytes exported'}}


def run_export(original, private, output):
    original, private, output = Path(original).resolve(), Path(private).resolve(), Path(output).resolve()
    output.mkdir(parents=True, exist_ok=True)
    manifest_path = output / 'metadata.json'
    if manifest_path.exists():
        raise FileExistsError('output already has metadata.json; choose an unused export directory')
    started = datetime.datetime.now(datetime.timezone.utc).isoformat()
    t0 = time.monotonic()
    stage = 'copy'
    provenance = {}
    native = None
    script_hash = file_hash(__file__)
    try:
        provenance = prepare_private_copy(original, private)
        print('[copy] database SHA-256', provenance['original_sha256_before'], flush=True)
        stage = 'native_ida_initialization'
        native = load_ida()
        stage = 'private_database_open'
        print('[open]', private, 'autoanalysis=False, args=-a', flush=True)
        code = native.idapro.open_database(str(private), False, args='-a')
        if code != 0:
            raise RuntimeError(f'idapro.open_database returned {code}')
        try:
            stage = 'metadata_collection'
            metadata = collect_metadata(native, output)
        finally:
            native.idapro.close_database(False)
        stage = 'post_close_integrity'
        provenance['original_sha256_after'] = file_hash(original)
        provenance['private_sha256_after'] = file_hash(private)
        provenance['original_unchanged'] = provenance['original_sha256_after'] == provenance['original_sha256_before']
        provenance['private_unchanged'] = provenance['private_sha256_after'] == provenance['private_sha256_before']
        if not provenance['original_unchanged'] or not provenance['private_unchanged']:
            raise ValueError('database hash changed during read-only export')
        if script_hash != file_hash(__file__):
            raise ValueError('exporter source changed during execution')
        metadata.update({'status': 'complete', 'started_utc': started,
                         'finished_utc': datetime.datetime.now(datetime.timezone.utc).isoformat(),
                         'elapsed_seconds': round(time.monotonic() - t0, 3),
                         'database': provenance, 'exporter_sha256': script_hash,
                         'python_version': sys.version, 'command': sys.argv,
                         'open_database_path': str(private), 'close_database_save': False})
        pending = output / 'metadata.json.tmp'
        pending.write_text(json.dumps(metadata, indent=2, ensure_ascii=False) + '\n', encoding='utf-8')
        pending.replace(manifest_path)
        print('[complete]', json.dumps({'functions': metadata['functions'], 'names': metadata['names'],
                                       'text_rows': metadata['tables']['text_items.tsv.gz']['rows'],
                                       'seconds': metadata['elapsed_seconds']}), flush=True)
        return metadata
    except Exception as exc:
        for key, path in (('original', original), ('private', private)):
            if path.is_file():
                provenance[key + '_sha256_after'] = file_hash(path)
        failure = {'status': 'failed', 'stage': stage, 'error_type': type(exc).__name__,
                   'error': str(exc), 'traceback': traceback.format_exc(),
                   'database': provenance, 'exporter_sha256': script_hash,
                   'native_attempts': 1 if stage != 'copy' else 0, 'close_database_save': False}
        (output / 'failure.json').write_text(json.dumps(failure, indent=2) + '\n', encoding='utf-8')
        raise


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source-db', type=Path, default=Path('C:/IDA_DB/ffxoficial.exe.i64'))
    parser.add_argument('--private-db', type=Path, default=Path('C:/IDA_DB/cos41719-reloc/analysis-readonly.i64'))
    parser.add_argument('--output', type=Path, default=Path('C:/IDA_DB/cos41719-reloc/analysis_map'))
    args = parser.parse_args(argv)
    run_export(args.source_db, args.private_db, args.output)
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except Exception:
        traceback.print_exc()
        raise SystemExit(2)
