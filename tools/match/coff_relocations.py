"""Bounded, fail-closed normal i386 COFF parsing and record-driven relocation.

parse_coff returns one-based section indexes and actual zero-based COFF symbol
indexes: auxiliary entries are retained under their owner, never as symbols.
raw_offset is a file offset, raw is exactly the file-backed section contents,
and raw_size also preserves a BSS section's declared size without inventing bytes.
Relocation offsets are normalized to section-relative offsets.

relocate requires explicit FINAL symbol VAs, including for section-defined and
undefined external symbols. The caller must resolve names and section placement;
this component never reads an executable, guesses an address, or adds symbol.value
again. In-place addends are signed little-endian int32. Address results must fit
uint32 and REL32 displacements int32; arithmetic never silently wraps.

Supported records: ABSOLUTE (0), DIR32 (6), DIR32NB (7), REL32 (20).
PE images, archives, bigobj/LTCG, and other relocation types are rejected.
Reference: https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
"""
import struct


ABSOLUTE = 0
DIR32 = 6
DIR32NB = 7
REL32 = 20
_NAMES = {ABSOLUTE: 'ABSOLUTE', DIR32: 'DIR32', DIR32NB: 'DIR32NB', REL32: 'REL32'}
_U32_MAX = 0xffffffff
_HEADER = struct.Struct('<HHIIIHH')
_SECTION = struct.Struct('<8sIIIIIIHHI')
_SYMBOL = struct.Struct('<8sIhHBB')
_RELOCATION = struct.Struct('<IIH')
_NRELOC_OVFL = 0x01000000
_UNINITIALIZED_DATA = 0x00000080


def _uint32(value, label):
    if type(value) is not int or not 0 <= value <= _U32_MAX:
        raise ValueError(f'{label} is outside the uint32 range: {value!r}')
    return value


def _nonoverlapping(spans, label):
    previous_end, previous_name = -1, ''
    for start, end, name in sorted(spans):
        if start < previous_end:
            raise ValueError(f'{label} overlap or duplicate: {previous_name} and {name}')
        previous_end, previous_name = end, name


def _validate_relocations(records, size):
    if not isinstance(records, list):
        raise ValueError('section relocations must be a list')
    spans = []
    for index, record in enumerate(records):
        if not isinstance(record, dict):
            raise ValueError('malformed relocation record')
        type_ = record.get('type')
        if type(type_) is not int or type_ not in _NAMES:
            raise ValueError(f'unsupported i386 relocation type: {type_!r}')
        # ABSOLUTE is padding, not a reference; its remaining fields are ignored.
        if type_ == ABSOLUTE:
            continue
        offset = _uint32(record.get('offset'), 'relocation offset')
        _uint32(record.get('symbol_index'), 'relocation symbol index')
        name = record.get('symbol_name')
        if not isinstance(name, str) or not name or '\0' in name:
            raise ValueError('relocation has an undefined symbol name')
        if offset + 4 > size:
            raise ValueError(f'relocation at {offset:#x} exceeds file-backed section bytes')
        spans.append((offset, offset + 4, f'record {index}'))
    _nonoverlapping(spans, 'relocation write sites')


def parse_coff(data: bytes) -> dict:
    """Parse a normal 0x14c object; reject incomplete or aliased file ranges.

    Each section exposes name/index/raw/raw_offset/raw_size/characteristics and
    relocations with offset/type/symbol_index/symbol_name/record_offset. Symbols
    expose name/index/value/section/storage/type/auxiliary_count/auxiliary.
    Undefined externals and common symbols are valid parsed symbols; relocate
    requires explicit bindings. No weak-external fallback is inferred.
    """
    if not isinstance(data, bytes):
        raise ValueError('COFF data must be bytes')
    if len(data) < _HEADER.size:
        raise ValueError('truncated COFF header')
    machine, count, timestamp, symptr, nsym, optsize, flags = _HEADER.unpack_from(data)
    if machine != 0x14c or optsize or flags & 0x0002:
        raise ValueError('expected a normal i386 COFF object, not a PE/image/bigobj/LTCG file')
    if count > 0x7fff:
        raise ValueError('invalid normal COFF section count')
    header_end = _HEADER.size + count * _SECTION.size
    if header_end > len(data):
        raise ValueError('truncated COFF section table')
    spans = [(0, header_end, 'headers')]

    def file_range(offset, size, label):
        if offset < header_end or offset > len(data) or size > len(data) - offset:
            raise ValueError(f'{label} is outside the file or overlaps headers')
        if size:
            spans.append((offset, offset + size, label))
        return data[offset:offset + size]

    strings = b''
    string_start = 0
    if symptr:
        file_range(symptr, nsym * _SYMBOL.size, 'symbol table')
        string_start = symptr + nsym * _SYMBOL.size
        if string_start + 4 > len(data):
            raise ValueError('truncated COFF string table size')
        string_size = struct.unpack_from('<I', data, string_start)[0]
        if string_size < 4:
            raise ValueError('invalid COFF string table size')
        strings = file_range(string_start, string_size, 'string table')
    elif nsym:
        raise ValueError('nonempty symbol table has a null file pointer')

    def decode_name(raw, label):
        # Reversible decoding avoids collisions between distinct non-UTF8 names.
        if not raw:
            raise ValueError(f'empty {label}')
        return raw.decode('utf-8', errors='surrogateescape')

    def long_name(offset, label):
        if not 4 <= offset < len(strings):
            raise ValueError(f'invalid string table offset for {label}')
        end = strings.find(b'\0', offset)
        if end < 0:
            raise ValueError(f'unterminated string table {label}')
        return decode_name(strings[offset:end], label)

    def inline_name(raw, label):
        end = raw.find(b'\0')
        if end >= 0:
            if any(raw[end:]):
                raise ValueError(f'nonzero bytes after terminator in {label}')
            raw = raw[:end]
        return decode_name(raw, label)

    sections = []
    for number in range(count):
        fields = _SECTION.unpack_from(data, _HEADER.size + number * _SECTION.size)
        (rawname, virtual_size, virtual_address, raw_size, rawptr, relocptr,
         lineptr, nreloc, nline, characteristics) = fields
        if rawname.startswith(b'/'):
            inline_name(rawname, 'section name reference')
            encoded = rawname.split(b'\0', 1)[0][1:]
            if not encoded or not encoded.isdigit():
                raise ValueError('invalid long section name reference')
            name = long_name(int(encoded), 'section name')
        else:
            name = inline_name(rawname, 'section name')
        label = f'section {number + 1} {name!r}'
        if not rawptr:
            if raw_size and not characteristics & _UNINITIALIZED_DATA:
                raise ValueError(f'{label} has nonempty raw data with a null pointer')
            raw = b''
        else:
            raw = file_range(rawptr, raw_size, label + ' raw data')
        if nline:
            file_range(lineptr, nline * 6, label + ' line-number table')
        elif lineptr:
            file_range(lineptr, 0, label + ' line-number pointer')
        skip = 0
        total_records = nreloc
        if characteristics & _NRELOC_OVFL:
            if nreloc != 0xffff or relocptr < header_end or relocptr + 10 > len(data):
                raise ValueError(f'{label} has invalid extended relocation header')
            total_records, reserved_index, reserved_type = _RELOCATION.unpack_from(data, relocptr)
            # The stored count includes the sentinel itself, which is not applied.
            if total_records < 0x10000 or reserved_index or reserved_type:
                raise ValueError(f'{label} has invalid extended relocation count record')
            skip = 1
        if total_records:
            file_range(relocptr, total_records * _RELOCATION.size, label + ' relocation table')
        elif relocptr:
            file_range(relocptr, 0, label + ' relocation pointer')
        sections.append(dict(name=name, index=number + 1, raw=raw,
                             raw_offset=rawptr, raw_size=raw_size,
                             virtual_size=virtual_size, virtual_address=virtual_address,
                             characteristics=characteristics, relocation_offset=relocptr,
                             relocation_count=total_records - skip, relocations=[],
                             _skip=skip))

    _nonoverlapping(spans, 'COFF file ranges')
    symbols = {}
    auxiliary_indexes = set()
    index = 0
    while index < nsym:
        offset = symptr + index * _SYMBOL.size
        rawname, value, section, type_, storage, naux = _SYMBOL.unpack_from(data, offset)
        if index + 1 + naux > nsym:
            raise ValueError('auxiliary symbol entries exceed the symbol table')
        if section < -2 or section > count:
            raise ValueError('symbol has an invalid section index')
        if rawname[:4] == b'\0' * 4:
            name = long_name(struct.unpack_from('<I', rawname, 4)[0], 'symbol name')
        else:
            name = inline_name(rawname, 'symbol name')
        auxiliary = [data[offset + (i + 1) * 18:offset + (i + 2) * 18] for i in range(naux)]
        symbols[index] = dict(name=name, index=index, value=value, section=section,
                              storage=storage, type=type_, auxiliary_count=naux,
                              auxiliary=auxiliary, raw_offset=offset)
        auxiliary_indexes.update(range(index + 1, index + 1 + naux))
        index += 1 + naux

    for section in sections:
        skip = section.pop('_skip')
        for number in range(section['relocation_count']):
            offset = section['relocation_offset'] + (number + skip) * _RELOCATION.size
            address, symbol_index, type_ = _RELOCATION.unpack_from(data, offset)
            if type_ not in _NAMES:
                raise ValueError(f'unsupported i386 relocation type: {type_:#x}')
            target = symbols.get(symbol_index)
            if type_ != ABSOLUTE:
                if target is None:
                    detail = 'auxiliary' if symbol_index in auxiliary_indexes else 'absent'
                    raise ValueError(f'relocation references {detail} symbol index {symbol_index}')
                if target['section'] == -2:
                    raise ValueError('relocation cannot target a debug-only symbol')
                site = address - section['virtual_address']
            else:
                site = address
            section['relocations'].append(dict(offset=site, type=type_,
                                                symbol_index=symbol_index,
                                                symbol_name=target['name'] if target else None,
                                                record_offset=offset))
        _validate_relocations(section['relocations'], len(section['raw']))
    return dict(machine=machine, characteristics=flags, timestamp=timestamp,
                sections=sections, symbols=symbols, symbol_table_offset=symptr,
                symbol_count=nsym, string_table_offset=string_start)


def relocate(section: dict, section_va: int, symbol_addresses: dict[str, int],
             image_base: int = 0x400000) -> tuple[bytes, list[dict]]:
    """Return relocated bytes and per-record evidence without mutating inputs.

    With signed addend A, final symbol VA S, image base B and write-site VA P:
      DIR32 = S + A; DIR32NB = S + A - B; REL32 = S + A - (P + 4).
    ABSOLUTE is ignored even when its unused site or symbol index is invalid.
    Evidence follows record order and includes before/after hex, addend and
    resolved address. A missing binding or invalid record aborts the whole call.
    """
    if not isinstance(section, dict) or not isinstance(section.get('raw'), bytes):
        raise ValueError('section must contain raw bytes')
    if not isinstance(symbol_addresses, dict):
        raise ValueError('symbol_addresses must be a dict of final symbol VAs')
    _uint32(section_va, 'section VA')
    _uint32(image_base, 'image base')
    raw = section['raw']
    if section_va + len(raw) > _U32_MAX + 1:
        raise ValueError('section address range overflows uint32')
    records = section.get('relocations')
    _validate_relocations(records, len(raw))
    patches, evidence = [], []
    for record in records:
        type_ = record['type']
        item = {key: record.get(key) for key in ('offset', 'type', 'symbol_index', 'symbol_name')}
        item.update(type_name=_NAMES[type_], applied=type_ != ABSOLUTE)
        if type_ == ABSOLUTE:
            evidence.append(item)
            continue
        name = record['symbol_name']
        if name not in symbol_addresses:
            raise ValueError(f'undefined symbol binding: {name!r}')
        target = _uint32(symbol_addresses[name], f'symbol address {name!r}')
        offset = record['offset']
        site_va = section_va + offset
        addend = struct.unpack_from('<i', raw, offset)[0]
        effective_target = _uint32(target + addend, 'symbol plus addend result')
        if type_ == DIR32:
            value = effective_target
        elif type_ == DIR32NB:
            value = _uint32(effective_target - image_base, 'DIR32NB result')
        else:
            value = effective_target - (site_va + 4)
            if not -0x80000000 <= value <= 0x7fffffff:
                raise ValueError('REL32 result overflows signed int32 range')
        encoded = struct.pack('<i' if type_ == REL32 else '<I', value)
        patches.append((offset, encoded))
        item.update(site_va=site_va, symbol_address=target, addend=addend, value=value,
                    before=raw[offset:offset + 4].hex(), after=encoded.hex())
        evidence.append(item)
    result = bytearray(raw)
    for offset, encoded in patches:
        result[offset:offset + 4] = encoded
    return bytes(result), evidence
