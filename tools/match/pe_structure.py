"""Structured, lossless NT headers and ordinary imports for file-backed PE32 x86.

The NT region is emitted from fields, never retained as a header blob. DOS bytes,
section contents and overlay bytes are outside the emitter's remit. Only normal
import-directory payloads are decoded; other directory entries are preserved and
range-checked, not interpreted. The security directory uses a file offset.

Layout dictionaries contain canonical 'coff' and 'optional_header' fields. The
top-level image_base/entry_rva aliases must agree when editing a layout. Each
section's eight-byte name_bytes field preserves padding; name is its decoded
prefix. optional_header_tail preserves extension/padding bytes beyond the last
declared directory, rather than treating them as undeclared directory entries.

Format: https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
All malformed or unsupported binary structures raise ValueError.
"""
import struct


COFF_FIELDS = (
    ('machine', 'H'), ('number_of_sections', 'H'), ('time_date_stamp', 'I'),
    ('pointer_to_symbol_table', 'I'), ('number_of_symbols', 'I'),
    ('size_of_optional_header', 'H'), ('characteristics', 'H'),
)
OPTIONAL_FIELDS = (
    ('magic', 'H'), ('major_linker_version', 'B'), ('minor_linker_version', 'B'),
    ('size_of_code', 'I'), ('size_of_initialized_data', 'I'),
    ('size_of_uninitialized_data', 'I'), ('address_of_entry_point', 'I'),
    ('base_of_code', 'I'), ('base_of_data', 'I'), ('image_base', 'I'),
    ('section_alignment', 'I'), ('file_alignment', 'I'),
    ('major_operating_system_version', 'H'), ('minor_operating_system_version', 'H'),
    ('major_image_version', 'H'), ('minor_image_version', 'H'),
    ('major_subsystem_version', 'H'), ('minor_subsystem_version', 'H'),
    ('win32_version_value', 'I'), ('size_of_image', 'I'), ('size_of_headers', 'I'),
    ('checksum', 'I'), ('subsystem', 'H'), ('dll_characteristics', 'H'),
    ('size_of_stack_reserve', 'I'), ('size_of_stack_commit', 'I'),
    ('size_of_heap_reserve', 'I'), ('size_of_heap_commit', 'I'),
    ('loader_flags', 'I'), ('number_of_rva_and_sizes', 'I'),
)
SECTION_FIELDS = (
    ('virtual_size', 'I'), ('virtual_address', 'I'), ('raw_size', 'I'),
    ('raw_offset', 'I'), ('relocation_offset', 'I'), ('line_number_offset', 'I'),
    ('relocation_count', 'H'), ('line_number_count', 'H'), ('characteristics', 'I'),
)
DIRECTORY_NAMES = (
    'export', 'import', 'resource', 'exception', 'security', 'base_relocation',
    'debug', 'architecture', 'global_pointer', 'tls', 'load_config',
    'bound_import', 'iat', 'delay_import', 'clr', 'reserved',
)


def _uint(value, bits, label):
    if type(value) is not int or not 0 <= value < 1 << bits:
        raise ValueError(f'{label} must be an unsigned {bits}-bit integer')
    return value


def _range(start, size, limit, label):
    if start < 0 or size < 0 or start > limit or size > limit - start:
        raise ValueError(f'{label} is truncated or outside its containing range')


def _unpack_fields(data, at, fields):
    fmt = '<' + ''.join(kind for _, kind in fields)
    _range(at, struct.calcsize(fmt), len(data), 'header fields')
    return dict(zip((name for name, _ in fields), struct.unpack_from(fmt, data, at)))


def _pack_fields(record, fields, label):
    if not isinstance(record, dict):
        raise ValueError(f'{label} must be a dictionary')
    values = [_uint(record.get(name), {'B': 8, 'H': 16, 'I': 32}[kind], f'{label}.{name}')
              for name, kind in fields]
    return struct.pack('<' + ''.join(kind for _, kind in fields), *values)


def _nonoverlapping(spans, label):
    end = 0
    for start, stop in sorted(spans):
        if start < end:
            raise ValueError(f'overlapping {label} ranges')
        end = stop


def _piece(layout, rva, *, backed):
    """Return the file offset (or None) and remaining extent of one RVA region."""
    _uint(rva, 32, 'RVA')
    opt = layout['optional_header']
    if rva < opt['size_of_headers']:
        return rva, opt['size_of_headers'] - rva
    for section in layout['sections']:
        start = section['virtual_address']
        extent = max(section['virtual_size'], section['raw_size'])
        if start <= rva < start + extent:
            delta = rva - start
            if not backed:
                return None, extent - delta
            if delta >= section['raw_size']:
                raise ValueError(f'RVA {rva:#x} points into unbacked zero-fill data')
            return section['raw_offset'] + delta, section['raw_size'] - delta
    raise ValueError(f'RVA {rva:#x} is outside the mapped headers and sections')


def _rva_range(layout, rva, size, *, backed):
    _range(rva, size, layout['optional_header']['size_of_image'], 'RVA range')
    current, left = rva, size
    while left:
        _, available = _piece(layout, current, backed=backed)
        step = min(left, available)
        current += step
        left -= step


def _validate_layout(layout):
    if not isinstance(layout, dict):
        raise ValueError('layout must be a dictionary')
    pe_offset = _uint(layout.get('pe_offset'), 32, 'pe_offset')
    file_size = _uint(layout.get('file_size'), 64, 'file_size')
    if pe_offset < 64 or layout.get('signature') != 0x4550:
        raise ValueError('invalid PE signature or NT-header offset')
    coff, opt = layout.get('coff'), layout.get('optional_header')
    _pack_fields(coff, COFF_FIELDS, 'coff')
    _pack_fields(opt, OPTIONAL_FIELDS, 'optional_header')
    if coff['machine'] != 0x14c or opt['magic'] != 0x10b:
        raise ValueError('only PE32 x86 images are supported')
    sections, directories = layout.get('sections'), layout.get('directories')
    if not isinstance(sections, list) or len(sections) != coff['number_of_sections']:
        raise ValueError('section count disagrees with the COFF header')
    if not isinstance(directories, list) or len(directories) != opt['number_of_rva_and_sizes']:
        raise ValueError('directory count disagrees with the optional header')
    tail = layout.get('optional_header_tail')
    if not isinstance(tail, bytes):
        raise ValueError('optional_header_tail must be bytes')
    expected_size = 96 + 8 * len(directories) + len(tail)
    if coff['size_of_optional_header'] != expected_size:
        raise ValueError('optional header size disagrees with its fields and directories')
    nt_size = 24 + expected_size + 40 * len(sections)
    _range(pe_offset, nt_size, file_size, 'NT headers and section table')
    if not pe_offset + nt_size <= opt['size_of_headers'] <= file_size:
        raise ValueError('SizeOfHeaders does not cover the complete file-backed header region')
    if layout.get('image_base') != opt['image_base'] or layout.get('entry_rva') != opt['address_of_entry_point']:
        raise ValueError('layout image_base/entry_rva aliases disagree with the optional header')
    _uint(layout.get('image_base'), 32, 'image_base')
    _uint(layout.get('entry_rva'), 32, 'entry_rva')
    if opt['size_of_image'] < opt['size_of_headers'] or not opt['size_of_image']:
        raise ValueError('SizeOfImage is smaller than the headers')
    _range(opt['image_base'], opt['size_of_image'], 1 << 32, '32-bit virtual image')
    if opt['address_of_entry_point'] >= opt['size_of_image']:
        raise ValueError('entry RVA is outside the virtual image')
    raw_spans, virtual_spans = [], []
    for index, section in enumerate(sections, 1):
        _pack_fields(section, SECTION_FIELDS, f'section {index}')
        name_bytes = section.get('name_bytes')
        if not isinstance(name_bytes, bytes) or len(name_bytes) != 8:
            raise ValueError('section name_bytes must be the exact eight-byte name field')
        if section.get('name') != name_bytes.split(b'\0', 1)[0].decode('latin-1'):
            raise ValueError('section name disagrees with name_bytes')
        if section.get('index') != index:
            raise ValueError('section indexes must preserve table order, starting at 1')
        raw, size = section['raw_offset'], section['raw_size']
        _range(raw, size, file_size, f'section {index} raw data')
        if size:
            if raw < opt['size_of_headers']:
                raise ValueError('section raw data overlaps the headers')
            raw_spans.append((raw, raw + size))
        rva = section['virtual_address']
        extent = max(section['virtual_size'], size)
        _range(rva, extent, opt['size_of_image'], f'section {index} virtual data')
        if extent:
            if rva < opt['size_of_headers']:
                raise ValueError('section virtual data overlaps the headers')
            virtual_spans.append((rva, rva + extent))
        for prefix, width in (('relocation', 10), ('line_number', 6)):
            at, count = section[prefix + '_offset'], section[prefix + '_count']
            if count and at < opt['size_of_headers']:
                raise ValueError(f'section {prefix} table has an invalid file pointer')
            _range(at, count * width, file_size, f'section {prefix} table')
    _nonoverlapping(raw_spans, 'section raw')
    _nonoverlapping(virtual_spans, 'section virtual')
    symptr, nsym = coff['pointer_to_symbol_table'], coff['number_of_symbols']
    if nsym and symptr < opt['size_of_headers']:
        raise ValueError('COFF symbol table has an invalid file pointer')
    _range(symptr, nsym * 18, file_size, 'COFF symbol table')
    for index, directory in enumerate(directories):
        if not isinstance(directory, dict):
            raise ValueError('directory entry must be a dictionary')
        rva = _uint(directory.get('rva'), 32, 'directory address')
        size = _uint(directory.get('size'), 32, 'directory size')
        if not rva:
            if size:
                raise ValueError('nonempty directory has a null address')
            continue
        if index == 4:
            _range(rva, size, file_size, 'security directory file range')
        else:
            # Directory entry bounds include virtual zero-fill. A payload decoder
            # must additionally require file bytes for every field it consumes.
            _rva_range(layout, rva, size or 1, backed=False)
    return nt_size


def parse_layout(data: bytes) -> dict:
    """Parse all NT/COFF/PE32/section fields, without retaining the DOS prefix."""
    if not isinstance(data, bytes):
        raise TypeError('data must be bytes')
    if len(data) < 64 or data[:2] != b'MZ':
        raise ValueError('missing or truncated DOS header')
    pe_offset = struct.unpack_from('<I', data, 0x3c)[0]
    _range(pe_offset, 24, len(data), 'PE signature and COFF header')
    signature = struct.unpack_from('<I', data, pe_offset)[0]
    if pe_offset < 64 or signature != 0x4550:
        raise ValueError('invalid PE signature or NT-header offset')
    coff = _unpack_fields(data, pe_offset + 4, COFF_FIELDS)
    optional_at = pe_offset + 24
    optional_size = coff['size_of_optional_header']
    if optional_size < 96:
        raise ValueError('truncated PE32 optional header')
    _range(optional_at, optional_size + coff['number_of_sections'] * 40,
           len(data), 'optional header and section table')
    opt = _unpack_fields(data, optional_at, OPTIONAL_FIELDS)
    if coff['machine'] != 0x14c or opt['magic'] != 0x10b:
        raise ValueError('only PE32 x86 images are supported')
    count = opt['number_of_rva_and_sizes']
    if count > (optional_size - 96) // 8:
        raise ValueError('declared data directories extend beyond the optional header')
    directories = []
    for index in range(count):
        rva, size = struct.unpack_from('<II', data, optional_at + 96 + index * 8)
        directories.append({'index': index, 'rva': rva, 'size': size,
                            'name': DIRECTORY_NAMES[index] if index < 16 else f'directory_{index}',
                            'address_kind': 'file_offset' if index == 4 else 'rva'})
    sections = []
    table = optional_at + optional_size
    for index in range(coff['number_of_sections']):
        at = table + index * 40
        name_bytes = data[at:at + 8]
        sections.append({'index': index + 1,
                         'name': name_bytes.split(b'\0', 1)[0].decode('latin-1'),
                         'name_bytes': name_bytes, **_unpack_fields(data, at + 8, SECTION_FIELDS)})
    layout = {'pe_offset': pe_offset, 'signature': signature, 'coff': coff,
              'optional_header': opt, 'image_base': opt['image_base'],
              'entry_rva': opt['address_of_entry_point'], 'file_size': len(data),
              'directories': directories, 'sections': sections,
              'optional_header_tail': data[optional_at + 96 + count * 8:table]}
    _validate_layout(layout)
    # The deprecated image COFF symbol table can still have a following string
    # table. Its contents are not decoded here, but its declared size must fit.
    if coff['pointer_to_symbol_table']:
        at = coff['pointer_to_symbol_table'] + coff['number_of_symbols'] * 18
        _range(at, 4, len(data), 'COFF string-table length')
        size = struct.unpack_from('<I', data, at)[0]
        if size < 4:
            raise ValueError('invalid COFF string-table size')
        _range(at, size, len(data), 'COFF string table')
    return layout


def emit_nt_headers(layout: dict) -> bytes:
    """Emit exactly signature through section-table end from validated fields.

    The caller places this at pe_offset; the returned bytes exclude that prefix
    and exclude alignment padding between the section table and SizeOfHeaders.
    """
    _validate_layout(layout)
    parts = [struct.pack('<I', layout['signature']),
             _pack_fields(layout['coff'], COFF_FIELDS, 'coff'),
             _pack_fields(layout['optional_header'], OPTIONAL_FIELDS, 'optional_header')]
    parts.extend(struct.pack('<II', entry['rva'], entry['size']) for entry in layout['directories'])
    parts.append(layout['optional_header_tail'])
    for section in layout['sections']:
        parts.extend((section['name_bytes'], _pack_fields(section, SECTION_FIELDS, 'section')))
    return b''.join(parts)


def _read_rva(data, layout, rva, size):
    _rva_range(layout, rva, size, backed=True)
    result = []
    while size:
        at, available = _piece(layout, rva, backed=True)
        count = min(size, available)
        _range(at, count, len(data), 'RVA file data')
        result.append(data[at:at + count])
        rva += count
        size -= count
    return b''.join(result)


def _cstring(data, layout, rva, label):
    if not rva:
        raise ValueError(f'{label} has a null RVA')
    parts = []
    while True:
        at, available = _piece(layout, rva, backed=True)
        end = data.find(b'\0', at, at + available)
        if end >= 0:
            parts.append(data[at:end])
            value = b''.join(parts)
            if not value:
                raise ValueError(f'{label} is empty')
            try:
                return value.decode('ascii')
            except UnicodeDecodeError as exc:
                raise ValueError(f'{label} is not ASCII') from exc
        parts.append(data[at:at + available])
        rva += available


def parse_imports(data: bytes, layout: dict) -> list[dict]:
    """Decode ordinary IMAGE_IMPORT_DESCRIPTOR tables, preserving bound IATs.

    Each DLL record contains descriptor_rva/va/offset, all five raw descriptor
    fields, lookup_rva, iat_rva and imports. Each import includes its hint/name or
    ordinal, both raw thunk values, and lookup_slot_* / iat_slot_* RVA, VA and
    file-offset fields. With a zero OriginalFirstThunk, an unbound IAT is used as
    the lookup table. Bound IAT-only images cannot reveal names and are rejected.
    Delay imports and bound-import-directory payloads are not decoded here.
    """
    if not isinstance(data, bytes):
        raise TypeError('data must be bytes')
    headers = emit_nt_headers(layout)
    at = layout['pe_offset']
    if (len(data) != layout['file_size'] or len(data) < 64 or data[:2] != b'MZ'
            or struct.unpack_from('<I', data, 0x3c)[0] != at
            or data[at:at + len(headers)] != headers):
        raise ValueError('layout does not describe the supplied image headers')
    if len(layout['directories']) <= 1:
        return []
    directory = layout['directories'][1]
    if directory['rva'] == directory['size'] == 0:
        return []
    if not directory['rva'] or directory['size'] < 20:
        raise ValueError('import directory is missing a complete descriptor terminator')
    _rva_range(layout, directory['rva'], directory['size'], backed=True)
    result = []
    base = layout['image_base']
    for delta in range(0, directory['size'] - 19, 20):
        descriptor_rva = directory['rva'] + delta
        fields = struct.unpack('<IIIII', _read_rva(data, layout, descriptor_rva, 20))
        if fields == (0, 0, 0, 0, 0):
            return result
        original_lookup, timestamp, forwarder, name_rva, iat = fields
        if not name_rva or not iat:
            raise ValueError('import descriptor is missing its DLL name or IAT')
        if not original_lookup and timestamp:
            raise ValueError('bound IAT without an original lookup table is unsupported')
        lookup = original_lookup or iat
        descriptor = {'dll': _cstring(data, layout, name_rva, 'import DLL name'),
                      'descriptor_rva': descriptor_rva, 'descriptor_va': base + descriptor_rva,
                      'descriptor_offset': _piece(layout, descriptor_rva, backed=True)[0],
                      'original_first_thunk': original_lookup, 'time_date_stamp': timestamp,
                      'forwarder_chain': forwarder, 'name_rva': name_rva, 'first_thunk': iat,
                      'lookup_rva': lookup, 'iat_rva': iat, 'imports': []}
        # Both tables must terminate in file-backed bytes. The bound also guards
        # against any future mapping regression allowing an unbounded traversal.
        for index in range(len(data) // 4 + 1):
            lookup_slot, iat_slot = lookup + index * 4, iat + index * 4
            value = struct.unpack('<I', _read_rva(data, layout, lookup_slot, 4))[0]
            iat_value = struct.unpack('<I', _read_rva(data, layout, iat_slot, 4))[0]
            if not value:
                if iat_value:
                    raise ValueError('IAT is not terminated at the lookup-table terminator')
                break
            if not iat_value:
                raise ValueError('IAT terminates before the import lookup table')
            ordinal, hint, name, hint_name_rva = None, None, None, None
            if value & 0x80000000:
                if value & 0x7fff0000:
                    raise ValueError('ordinal import has nonzero reserved bits')
                ordinal = value & 0xffff
            else:
                hint_name_rva = value
                hint = struct.unpack('<H', _read_rva(data, layout, value, 2))[0]
                name = _cstring(data, layout, value + 2, 'import function name')
            descriptor['imports'].append({
                'index': index, 'name': name, 'hint': hint, 'ordinal': ordinal,
                'hint_name_rva': hint_name_rva, 'lookup_value': value, 'iat_value': iat_value,
                'lookup_slot_rva': lookup_slot, 'lookup_slot_va': base + lookup_slot,
                'lookup_slot_offset': _piece(layout, lookup_slot, backed=True)[0],
                'iat_slot_rva': iat_slot, 'iat_slot_va': base + iat_slot,
                'iat_slot_offset': _piece(layout, iat_slot, backed=True)[0],
            })
        else:
            raise ValueError('unterminated import lookup table')
        result.append(descriptor)
    raise ValueError('import descriptor table is unterminated within its directory size')
