"""Field-built DOS/Rich/NT headers and a complete PE32 x86 .reloc section.

Only prepare() reads an image. Emitters use the JSON-safe model exclusively.
The bounded DOS profile is the 64-byte MZ header and seven-instruction Microsoft
message stub. Reserved DOS words and all uncovered padding must be zero.
Rich product/build/count records retain their order, XOR key and checksum.
Base relocations support HIGHLOW and ABSOLUTE, retaining ABSOLUTE offsets too.
expected_highlow_sites is an iterable of actual absolute linker/assembler VAs,
not a count, mask or list of RVAs. Omitting it proves no linker-site agreement.

NT layout names are Latin-1 strings including their eight-byte zero padding;
the optional-header extension is represented only by its verified zero length.
No DOS/opcode/header byte arrays are stored in the source model.
"""
import argparse
import bisect
import gzip
import hashlib
import importlib.metadata
import json
import struct
import sys
from collections.abc import Mapping
from pathlib import Path

from iced_x86 import Decoder
import pe_structure
import x86_source

ROOT = Path(__file__).resolve().parents[2]
EXE_DEFAULT = Path('/home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe')
EXE_SHA256 = '78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced'
ICED_VERSION = '1.21.0'
DOS_MESSAGE = 'This program cannot be run in DOS mode.' + chr(13) * 2 + chr(10) + '$'
DOS_FIELDS = ('e_magic', 'e_cblp', 'e_cp', 'e_crlc', 'e_cparhdr', 'e_minalloc',
              'e_maxalloc', 'e_ss', 'e_sp', 'e_csum', 'e_ip', 'e_cs', 'e_lfarlc', 'e_ovno')
MODEL_FIELDS = {'schema_version', 'layout', 'dos_header', 'dos_stub', 'rich',
                'zero_padding', 'base_relocations'}


def _uint(value, bits, label):
    if type(value) is not int or not 0 <= value < 1 << bits:
        raise ValueError(f'{label} must be an unsigned {bits}-bit integer')
    return value


def _keys(value, keys, label):
    if not isinstance(value, dict) or set(value) != set(keys):
        raise ValueError(f'{label} has missing or unsupported source fields')


def _model(model):
    _keys(model, MODEL_FIELDS, 'model')
    if type(model['schema_version']) is not int or model['schema_version'] != 1:
        raise ValueError('unsupported model schema_version')


def _range(start, size, limit, label):
    if start < 0 or size < 0 or start > limit or size > limit - start:
        raise ValueError(f'{label} is outside its containing range')


def native_layout(model: dict) -> dict:
    """Recover a validated pe_structure layout without reading an image."""
    _model(model)
    source = model['layout']
    _keys(source, {'pe_offset', 'signature', 'coff', 'optional_header', 'image_base',
                  'entry_rva', 'file_size', 'directories', 'sections',
                  'optional_header_tail_zero_size'}, 'layout')
    layout = dict(source)
    tail_size = _uint(layout.pop('optional_header_tail_zero_size'), 16, 'optional header zero tail')
    layout['optional_header_tail'] = bytes(tail_size)
    if not isinstance(source['sections'], list):
        raise ValueError('layout sections must be a list')
    layout['sections'] = []
    for item in source['sections']:
        if not isinstance(item, dict) or not isinstance(item.get('name_bytes'), str):
            raise ValueError('section name_bytes must be a Latin-1 field string')
        section = dict(item)
        try:
            section['name_bytes'] = item['name_bytes'].encode('latin-1')
        except UnicodeEncodeError as exc:
            raise ValueError('section name field is not Latin-1') from exc
        layout['sections'].append(section)
    pe_structure.emit_nt_headers(layout)
    return layout


def _dos_bytes(dos, pe_offset):
    _keys(dos, set(DOS_FIELDS) | {'e_res', 'e_oemid', 'e_oeminfo', 'e_res2', 'e_lfanew'}, 'DOS header')
    values = [_uint(dos[name], 16, 'DOS ' + name) for name in DOS_FIELDS]
    for name, count in (('e_res', 4), ('e_res2', 10)):
        if not isinstance(dos[name], list) or len(dos[name]) != count:
            raise ValueError('invalid DOS reserved word count')
        if any(_uint(v, 16, 'DOS reserved word') for v in dos[name]):
            raise ValueError('unsupported nonzero DOS reserved fields')
    if (dos['e_magic'] != 0x5a4d or dos['e_cparhdr'] != 4 or dos['e_crlc']
            or dos['e_ip'] or dos['e_cs'] or dos['e_ovno'] or dos['e_lfarlc'] != 64):
        raise ValueError('unsupported DOS header/stub or DOS relocation layout')
    if dos['e_cblp'] > 511 or dos['e_cp'] == 0:
        raise ValueError('invalid DOS page fields')
    if _uint(dos['e_lfanew'], 32, 'DOS e_lfanew') != pe_offset:
        raise ValueError('DOS e_lfanew and NT offset disagree')
    values += dos['e_res']
    values += [_uint(dos[name], 16, 'DOS ' + name) for name in ('e_oemid', 'e_oeminfo')]
    values += dos['e_res2'] + [pe_offset]
    return struct.pack('<30HI', *values)


def _stub_bytes(stub):
    _keys(stub, {'offset', 'bitness', 'instructions', 'message_offset', 'message'}, 'DOS stub')
    if (stub['offset'] != 64 or type(stub['offset']) is not int
            or stub['bitness'] != 16 or type(stub['bitness']) is not int
            or stub['message_offset'] != 78 or type(stub['message_offset']) is not int
            or stub['message'] != DOS_MESSAGE):
        raise ValueError('unsupported DOS stub/message placement or text')
    register = lambda name: {'kind': 'REGISTER', 'register': name}
    immediate = lambda bits, value: {'kind': 'IMMEDIATE' + str(bits), 'value': value}
    shapes = [(0, 1, 'PUSHW_CS', [register('CS')]),
              (1, 1, 'POPW_DS', [register('DS')]),
              (2, 3, 'MOV_R16_IMM16', [register('DX'), immediate(16, 14)]),
              (5, 2, 'MOV_R8_IMM8', [register('AH'), immediate(8, 9)]),
              (7, 2, 'INT_IMM8', [immediate(8, 33)]),
              (9, 3, 'MOV_R16_IMM16', [register('AX'), immediate(16, 0x4c01)]),
              (12, 2, 'INT_IMM8', [immediate(8, 33)])]
    instructions = stub['instructions']
    if not isinstance(instructions, list) or len(instructions) != len(shapes):
        raise ValueError('unsupported DOS instruction count')
    result = []
    for record, (ip, length, code, operands) in zip(instructions, shapes):
        if not isinstance(record, dict) or set(record) - {
                'ip', 'length', 'code', 'operands', 'prefixes', 'base_relocations', 'text'}:
            raise ValueError('unsupported DOS instruction source field')
        if (record.get('ip') != ip or type(record.get('ip')) is not int
                or record.get('length') != length or type(record.get('length')) is not int
                or record.get('code') != code or record.get('operands') != operands
                or record.get('prefixes') != {} or record.get('base_relocations') != []):
            raise ValueError('unrecognized DOS instruction source')
        raw, fixups = x86_source.encode(record, {}, bitness=16)
        if fixups:
            raise ValueError('DOS stub must not introduce PE relocations')
        result.append(raw)
    return b''.join(result), stub['message'].encode('ascii')


def _rol(value, shift):
    shift %= 32
    return ((value << shift) | (value >> (32 - shift))) & 0xffffffff


def _rich_fields(rich, pe_offset):
    _keys(rich, {'offset', 'marker_offset', 'key', 'magic', 'marker', 'reserved', 'records'}, 'Rich')
    start = _uint(rich['offset'], 32, 'Rich offset')
    marker = _uint(rich['marker_offset'], 32, 'Rich marker offset')
    _uint(rich['key'], 32, 'Rich XOR key')
    if (rich['magic'] != 'DanS' or rich['marker'] != 'Rich'
            or rich['reserved'] != [0, 0, 0]
            or any(type(v) is not int for v in rich['reserved'])):
        raise ValueError('invalid Rich DanS signature or reserved fields')
    records = rich['records']
    if not isinstance(records, list):
        raise ValueError('Rich records must be a list')
    if start < 121 or start % 4 or marker != start + 16 + 8 * len(records):
        raise ValueError('Rich offsets disagree with record layout')
    _range(start, marker + 8 - start, pe_offset, 'Rich header')
    words = [int.from_bytes(b'DanS', 'little'), 0, 0, 0]
    for record in records:
        _keys(record, {'product_id', 'build', 'count'}, 'Rich product record')
        product = _uint(record['product_id'], 16, 'Rich product_id')
        build = _uint(record['build'], 16, 'Rich build')
        count = _uint(record['count'], 32, 'Rich count')
        words.extend(((product << 16) | build, count))
    return words


def _rich_checksum(prefix, records):
    checksum = len(prefix)
    for offset, value in enumerate(prefix):
        if not 0x3c <= offset < 0x40:
            checksum = (checksum + _rol(value, offset)) & 0xffffffff
    for record in records:
        checksum = (checksum + _rol((record['product_id'] << 16) | record['build'], record['count'])) & 0xffffffff
    return checksum


def _gaps(spans, limit):
    result, cursor = [], 0
    for start, size in sorted(spans):
        _range(start, size, limit, 'header region')
        if start < cursor:
            raise ValueError('overlapping header regions')
        if start > cursor:
            result.append({'offset': cursor, 'size': start - cursor})
        cursor = start + size
    if cursor < limit:
        result.append({'offset': cursor, 'size': limit - cursor})
    return result


def emit_headers(model: dict) -> bytes:
    """Serialize DOS/Rich/NT fields and assemble the 16-bit stub, reference-free."""
    layout = native_layout(model)
    nt = pe_structure.emit_nt_headers(layout)
    dos = _dos_bytes(model['dos_header'], layout['pe_offset'])
    stub, message = _stub_bytes(model['dos_stub'])
    rich = model['rich']
    words = _rich_fields(rich, layout['pe_offset'])
    size = layout['optional_header']['size_of_headers']
    parts = [(0, dos), (64, stub), (78, message), (layout['pe_offset'], nt)]
    spans = [(at, len(raw)) for at, raw in parts] + [(rich['offset'], 8 + len(words) * 4)]
    gaps = _gaps(spans, size)
    padding = model['zero_padding']
    if not isinstance(padding, list):
        raise ValueError('zero padding must be a list')
    for region in padding:
        _keys(region, {'offset', 'size'}, 'zero padding')
        _uint(region['offset'], 32, 'padding offset')
        _uint(region['size'], 32, 'padding size')
    if padding != gaps:
        raise ValueError('padding coverage is missing, out of order or overlapping')
    result = bytearray(size)
    for at, raw in parts:
        result[at:at + len(raw)] = raw
    if _rich_checksum(result[:rich['offset']], rich['records']) != rich['key']:
        raise ValueError('Rich checksum does not match DOS fields and product records')
    for index, word in enumerate(words):
        struct.pack_into('<I', result, rich['offset'] + index * 4, word ^ rich['key'])
    result[rich['marker_offset']:rich['marker_offset'] + 4] = b'Rich'
    struct.pack_into('<I', result, rich['marker_offset'] + 4, rich['key'])
    return bytes(result)


def _reloc_section(layout):
    sections = [s for s in layout['sections'] if s['name'] == '.reloc']
    if len(sections) != 1 or len(layout['directories']) <= 5:
        raise ValueError('one .reloc section and a base-relocation directory are required')
    section, directory = sections[0], layout['directories'][5]
    delta = directory['rva'] - section['virtual_address']
    if not directory['rva'] or not directory['size'] or delta < 0:
        raise ValueError('missing base-relocation directory in .reloc')
    _range(delta, directory['size'], section['raw_size'], 'base-relocation directory')
    return section, directory, delta


def _emit_relocations(model, expected_highlow_sites):
    layout = native_layout(model)
    section, directory, prefix = _reloc_section(layout)
    source = model['base_relocations']
    _keys(source, {'section_index', 'raw_offset', 'raw_size', 'directory_rva',
                   'directory_size', 'zero_prefix_size', 'zero_tail_size', 'blocks'}, 'base relocations')
    expected_fields = {'section_index': section['index'], 'raw_offset': section['raw_offset'],
                       'raw_size': section['raw_size'], 'directory_rva': directory['rva'],
                       'directory_size': directory['size'], 'zero_prefix_size': prefix,
                       'zero_tail_size': section['raw_size'] - prefix - directory['size']}
    for key, value in expected_fields.items():
        if _uint(source[key], 32, 'relocation ' + key) != value:
            raise ValueError('relocation declaration disagrees with NT fields: ' + key)
    if not isinstance(source['blocks'], list):
        raise ValueError('base relocation blocks must be a list')
    regions = [(0, layout['optional_header']['size_of_headers'])]
    regions.extend((s['virtual_address'], s['virtual_address'] + max(s['virtual_size'], s['raw_size']))
                   for s in layout['sections'] if max(s['virtual_size'], s['raw_size']))
    regions.sort()
    starts = [start for start, _ in regions]
    raw = bytearray(section['raw_size'])
    cursor, sites = 0, []
    for block in source['blocks']:
        _keys(block, {'page_rva', 'block_size', 'entries'}, 'relocation block')
        page = _uint(block['page_rva'], 32, 'relocation page RVA')
        size = _uint(block['block_size'], 32, 'relocation block size')
        entries = block['entries']
        if (page % 4096 or page >= layout['optional_header']['size_of_image']
                or not isinstance(entries, list) or size != 8 + 2 * len(entries)
                or size % 4 or size < 8):
            raise ValueError('invalid relocation block size, page alignment or image range')
        _range(cursor, size, directory['size'], 'relocation block')
        struct.pack_into('<II', raw, prefix + cursor, page, size)
        for index, entry in enumerate(entries):
            _keys(entry, {'type', 'offset'}, 'relocation entry')
            type_ = _uint(entry['type'], 4, 'relocation type')
            offset = _uint(entry['offset'], 12, 'relocation page offset')
            if type_ not in (0, 3):
                raise ValueError(f'unsupported x86 base relocation type {type_}')
            if type_ == 3:
                rva = page + offset
                region = bisect.bisect_right(starts, rva) - 1
                if region < 0 or rva + 4 > regions[region][1]:
                    raise ValueError(f'HIGHLOW site {rva:#x} is outside a mapped image range')
                site = layout['image_base'] + rva
                _range(site, 4, 1 << 32, 'HIGHLOW site VA')
                sites.append(site)
            struct.pack_into('<H', raw, prefix + cursor + 8 + index * 2, (type_ << 12) | offset)
        cursor += size
    if cursor != directory['size']:
        raise ValueError('relocation blocks do not cover the active directory')
    sites.sort()
    if any(right < left + 4 for left, right in zip(sites, sites[1:])):
        raise ValueError('duplicate or overlapping HIGHLOW write sites')
    if expected_highlow_sites is not None:
        if isinstance(expected_highlow_sites, (str, bytes, Mapping)):
            raise ValueError('HIGHLOW sites must be actual absolute VAs, not counts or a mapping')
        try:
            supplied = list(expected_highlow_sites)
        except TypeError as exc:
            raise ValueError('HIGHLOW sites must be an iterable of actual absolute VAs') from exc
        for site in supplied:
            _uint(site, 32, 'expected HIGHLOW site VA')
        supplied_set = set(supplied)
        if len(supplied_set) != len(supplied):
            raise ValueError('duplicate expected HIGHLOW sites')
        decoded_set = set(sites)
        if supplied_set != decoded_set:
            missing, extra = decoded_set - supplied_set, supplied_set - decoded_set
            raise ValueError(f'HIGHLOW site mismatch: {len(missing)} missing, {len(extra)} extra')
    return bytes(raw), sites


def emit_base_relocations(model: dict, expected_highlow_sites=None) -> bytes:
    """Emit ordered actual entries and declared zero fill; optionally check VAs."""
    return _emit_relocations(model, expected_highlow_sites)[0]


def prepare(data: bytes) -> dict:
    """Describe supported header fields/instructions and active .reloc entries."""
    layout = pe_structure.parse_layout(data)
    if any(layout['optional_header_tail']):
        raise ValueError('unsupported nonzero optional-header padding')
    values = struct.unpack_from('<30HI', data)
    dos = dict(zip(DOS_FIELDS, values[:14]))
    dos.update(e_res=list(values[14:18]), e_oemid=values[18], e_oeminfo=values[19],
               e_res2=list(values[20:30]), e_lfanew=values[30])
    _dos_bytes(dos, layout['pe_offset'])
    _range(64, 57, len(data), 'DOS stub and message')
    decoder = Decoder(16, data[64:78], ip=0)
    try:
        instructions = [x86_source.describe(i, decoder.get_constant_offsets(i)) for i in decoder]
    except ValueError as exc:
        raise ValueError(f'unrecognized DOS stub instruction: {exc}') from exc
    if data[78:121] != DOS_MESSAGE.encode('ascii'):
        raise ValueError('unrecognized DOS message')
    stub = {'offset': 64, 'bitness': 16, 'instructions': instructions,
            'message_offset': 78, 'message': DOS_MESSAGE}
    if _stub_bytes(stub)[0] != data[64:78]:
        raise ValueError('DOS stub is not exactly reproduced by explicit instructions')
    markers = [i for i in range(124, layout['pe_offset'] - 7, 4) if data[i:i + 4] == b'Rich']
    if len(markers) != 1:
        raise ValueError('Rich marker is missing or ambiguous')
    marker = markers[0]
    key = struct.unpack_from('<I', data, marker + 4)[0]
    starts = [i for i in range(124, marker - 15, 4)
              if struct.unpack_from('<I', data, i)[0] ^ key == int.from_bytes(b'DanS', 'little')]
    if len(starts) != 1 or (marker - starts[0] - 16) % 8:
        raise ValueError('Rich DanS start or record extent is invalid')
    start = starts[0]
    reserved = [struct.unpack_from('<I', data, start + i)[0] ^ key for i in (4, 8, 12)]
    records = []
    for at in range(start + 16, marker, 8):
        compid, count = struct.unpack_from('<II', data, at)
        compid ^= key
        records.append({'product_id': compid >> 16, 'build': compid & 0xffff, 'count': count ^ key})
    rich = {'offset': start, 'marker_offset': marker, 'key': key, 'magic': 'DanS',
            'marker': 'Rich', 'reserved': reserved, 'records': records}
    _rich_fields(rich, layout['pe_offset'])
    serialized = dict(layout)
    serialized['sections'] = [dict(s, name_bytes=s['name_bytes'].decode('latin-1')) for s in layout['sections']]
    serialized['optional_header_tail_zero_size'] = len(serialized.pop('optional_header_tail'))
    spans = [(0, 64), (64, 14), (78, 43), (start, marker + 8 - start),
             (layout['pe_offset'], len(pe_structure.emit_nt_headers(layout)))]
    padding = _gaps(spans, layout['optional_header']['size_of_headers'])
    for gap in padding:
        if any(data[gap['offset']:gap['offset'] + gap['size']]):
            raise ValueError('unknown nonzero header padding')
    model = {'schema_version': 1, 'layout': serialized, 'dos_header': dos, 'dos_stub': stub,
             'rich': rich, 'zero_padding': padding, 'base_relocations': {}}
    if emit_headers(model) != data[:layout['optional_header']['size_of_headers']]:
        raise ValueError('structured header roundtrip differs')
    section, directory, prefix = _reloc_section(layout)
    raw = data[section['raw_offset']:section['raw_offset'] + section['raw_size']]
    tail = section['raw_size'] - prefix - directory['size']
    if any(raw[:prefix]) or any(raw[prefix + directory['size']:]):
        raise ValueError('nonzero bytes outside relocation directory; zero prefix/tail required')
    blocks, cursor = [], 0
    while cursor < directory['size']:
        _range(cursor, 8, directory['size'], 'relocation block header')
        page, size = struct.unpack_from('<II', raw, prefix + cursor)
        if size < 8 or size % 4:
            raise ValueError('invalid relocation block size')
        _range(cursor, size, directory['size'], 'relocation block')
        entries = []
        for at in range(prefix + cursor + 8, prefix + cursor + size, 2):
            word = struct.unpack_from('<H', raw, at)[0]
            entries.append({'type': word >> 12, 'offset': word & 0xfff})
        blocks.append({'page_rva': page, 'block_size': size, 'entries': entries})
        cursor += size
    model['base_relocations'] = {'section_index': section['index'], 'raw_offset': section['raw_offset'],
                                'raw_size': section['raw_size'], 'directory_rva': directory['rva'],
                                'directory_size': directory['size'], 'zero_prefix_size': prefix,
                                'zero_tail_size': tail, 'blocks': blocks}
    if emit_base_relocations(model) != raw:
        raise ValueError('structured relocation roundtrip differs')
    return model


def _digest(data):
    return hashlib.sha256(data).hexdigest()


def _json_bytes(value):
    return (json.dumps(value, ensure_ascii=True, separators=(',', ':')) + chr(10)).encode('utf-8')


def _distinct(pairs):
    result = {}
    for key, value in pairs:
        if key in result:
            raise ValueError('duplicate JSON source key: ' + key)
        result[key] = value
    return result


def _read_source(path):
    data = path.read_bytes()
    decoded = gzip.decompress(data) if path.suffix == '.gz' else data
    return json.loads(decoded, object_pairs_hook=_distinct), data


def _tools():
    version = importlib.metadata.version('iced-x86')
    if version != ICED_VERSION:
        raise ValueError('this build requires iced_x86 ' + ICED_VERSION)
    paths = {Path(__file__).resolve(), Path(pe_structure.__file__).resolve(),
             Path(x86_source.__file__).resolve(), Path(sys.executable).resolve()}
    for name, module in list(sys.modules.items()):
        at = getattr(module, '__file__', None)
        if name.startswith('iced_x86') and at and (name == 'iced_x86' or str(at).endswith(('.so', '.pyd'))):
            paths.add(Path(at).resolve())
    return {'python_version': sys.version, 'iced_x86_version': version,
            'files': {str(p): _digest(p.read_bytes()) for p in sorted(paths)}}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('prepare', 'build'))
    parser.add_argument('--output', type=Path, default=ROOT / 'recon/ffx/pe_headers')
    parser.add_argument('--source', type=Path)
    parser.add_argument('--exe', type=Path, help='preparation only; must be the pinned original')
    parser.add_argument('--expected-highlow-sites', type=Path, help='JSON array of actual absolute linker/assembler VAs')
    args = parser.parse_args(argv)
    if args.action == 'build' and args.exe is not None:
        parser.error('--exe is preparation-only; the builder takes structured source')
    # A failed source parse/build must not leave an earlier success report.
    (args.output / 'proof.json').unlink(missing_ok=True)
    tools = _tools()
    original = None
    if args.action == 'prepare':
        original_path = args.exe or EXE_DEFAULT
        original = original_path.read_bytes()
        if _digest(original) != EXE_SHA256:
            raise ValueError('reference SHA-256 differs from the pinned FFX.exe')
        model = prepare(original)
        source_data = gzip.compress(_json_bytes(model), mtime=0)
    else:
        model, source_data = _read_source(args.source or args.output / 'source.json.gz')
        # Always retain a canonical JSON-safe source in the output package.
        source_data = gzip.compress(_json_bytes(model), mtime=0)
    expected, expected_hash = None, None
    if args.expected_highlow_sites is not None:
        expected_data = args.expected_highlow_sites.read_bytes()
        expected = json.loads(expected_data, object_pairs_hook=_distinct)
        expected_hash = _digest(expected_data)
    header_bytes = emit_headers(model)
    reloc_bytes, sites = _emit_relocations(model, expected)
    layout = native_layout(model)
    section, directory, _ = _reloc_section(layout)
    exact_headers = exact_relocations = None
    if original is not None:
        exact_headers = header_bytes == original[:len(header_bytes)]
        exact_relocations = reloc_bytes == original[section['raw_offset']:section['raw_offset'] + section['raw_size']]
        if not exact_headers or not exact_relocations:
            raise ValueError('fragment roundtrip differs from the original')
        if original_path.read_bytes() != original:
            raise ValueError('reference changed during preparation')
    if tools != _tools():
        raise ValueError('input modules or tool binaries changed during this build')
    entries = [e for b in model['base_relocations']['blocks'] for e in b['entries']]
    proof = {'schema_version': 1, 'action': args.action, 'source_sha256': _digest(source_data),
             'source_json_sha256': _digest(_json_bytes(model)),
             'input_image_sha256': _digest(original) if original is not None else None,
             'tools': tools, 'headers_size': len(header_bytes), 'headers_sha256': _digest(header_bytes),
             'header_roundtrip_exact': exact_headers, 'pe_offset': layout['pe_offset'],
             'nt_header_size': len(pe_structure.emit_nt_headers(layout)),
             'rich_records': len(model['rich']['records']), 'rich_xor_key': model['rich']['key'],
             'rich_checksum_valid': True, 'dos_stub_instructions': len(model['dos_stub']['instructions']),
             'reloc_raw_offset': section['raw_offset'], 'reloc_raw_size': len(reloc_bytes),
             'reloc_sha256': _digest(reloc_bytes), 'reloc_roundtrip_exact': exact_relocations,
             'active_directory_size': directory['size'], 'zero_tail_size': model['base_relocations']['zero_tail_size'],
             'relocation_blocks': len(model['base_relocations']['blocks']), 'highlow_sites': len(sites),
             'absolute_padding_entries': sum(e['type'] == 0 for e in entries),
             'expected_highlow_sites_sha256': expected_hash,
             'supplied_linker_highlow_sites_verified': expected is not None,
             'whole_executable_reconstructed': False,
             'scope': 'field-built headers and relocation section only; no reference input to emitters'}
    args.output.mkdir(parents=True, exist_ok=True)
    for name, data in (('source.json.gz', source_data), ('headers.bin', header_bytes), ('reloc.bin', reloc_bytes)):
        (args.output / name).write_bytes(data)
    pending = args.output / 'proof.json.tmp'
    pending.write_text(json.dumps(proof, indent=2) + chr(10), encoding='utf-8')
    pending.replace(args.output / 'proof.json')
    print(json.dumps({key: proof[key] for key in ('headers_size', 'header_roundtrip_exact', 'reloc_raw_size',
          'reloc_roundtrip_exact', 'rich_records', 'relocation_blocks', 'highlow_sites',
          'supplied_linker_highlow_sites_verified')}, indent=2))
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, ValueError, TypeError, KeyError, struct.error) as exc:
        print('error: ' + str(exc), file=sys.stderr)
        raise SystemExit(2)
