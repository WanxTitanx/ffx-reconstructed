"""Pure PE32 model extension for statically linked reconstructed modules.

The extension consumes and returns the JSON-safe model used by pe_headers. It
never reads an executable and never moves an existing section. Requested mod
sections are appended in a fixed order, while the existing .reloc allocation is
reused for a canonical relocation directory built from actual HIGHLOW VAs.
"""
import copy

import pe_headers
import pe_structure


SECTION_SPECS = (
    ('.modtxt', 0x60000020),
    ('.modro', 0x40000040),
    ('.moddat', 0xc0000040),
)
SECTION_NAMES = {name for name, _ in SECTION_SPECS}
UINT32_LIMIT = 1 << 32


def _align(value, alignment, label):
    if type(alignment) is not int or alignment <= 0:
        raise ValueError(f'{label} alignment must be a positive integer')
    result = (value + alignment - 1) // alignment * alignment
    if result >= UINT32_LIMIT:
        raise ValueError(f'{label} alignment overflows a PE32 field')
    return result


def _checked_add(value, increment, label):
    result = value + increment
    if type(value) is not int or type(increment) is not int or not 0 <= result < UINT32_LIMIT:
        raise ValueError(f'{label} overflows a PE32 field')
    return result


def _validate_sizes(sizes):
    if not isinstance(sizes, dict):
        raise TypeError('section sizes must be a dictionary')
    for name, size in sizes.items():
        if name not in SECTION_NAMES:
            raise ValueError(f'unsupported mod section key: {name!r}')
        if type(size) is not int or not 0 < size < UINT32_LIMIT:
            raise ValueError(f'{name} size must be a positive 32-bit integer')


def _validate_sites_shape(highlow_sites):
    if not isinstance(highlow_sites, list):
        raise TypeError('HIGHLOW sites must be a list of absolute VAs')
    if not highlow_sites:
        raise ValueError('at least one actual HIGHLOW site is required')
    for site in highlow_sites:
        if type(site) is not int or not 0 <= site < UINT32_LIMIT:
            raise ValueError('HIGHLOW site must be an unsigned 32-bit absolute VA')


def _mapped_ranges(layout):
    ranges = [(0, layout['optional_header']['size_of_headers'])]
    ranges.extend(
        (section['virtual_address'],
         section['virtual_address'] + max(section['virtual_size'], section['raw_size']))
        for section in layout['sections']
        if max(section['virtual_size'], section['raw_size'])
    )
    return sorted(ranges)


def _canonical_blocks(layout, highlow_sites):
    base = layout['image_base']
    ranges = _mapped_ranges(layout)
    sites = sorted(highlow_sites)
    for left, right in zip(sites, sites[1:]):
        if right < left + 4:
            raise ValueError('duplicate or overlapping HIGHLOW sites')

    pages = {}
    for site in sites:
        if site < base or site + 4 > UINT32_LIMIT:
            raise ValueError(f'HIGHLOW site {site:#x} is outside the mapped image range')
        rva = site - base
        if not any(start <= rva and rva + 4 <= stop for start, stop in ranges):
            raise ValueError(f'HIGHLOW site {site:#x} is outside the mapped image range')
        page = rva & ~0xfff
        pages.setdefault(page, []).append(rva & 0xfff)

    blocks = []
    for page in sorted(pages):
        entries = [{'type': 3, 'offset': offset} for offset in sorted(pages[page])]
        if len(entries) % 2:
            entries.append({'type': 0, 'offset': 0})
        blocks.append({'page_rva': page, 'block_size': 8 + 2 * len(entries),
                       'entries': entries})
    return blocks


def _gaps(spans, limit):
    result = []
    cursor = 0
    for start, size in sorted(spans):
        if start < cursor or start < 0 or size < 0 or start + size > limit:
            raise ValueError('header regions overlap or exceed SizeOfHeaders')
        if start > cursor:
            result.append({'offset': cursor, 'size': start - cursor})
        cursor = start + size
    if cursor < limit:
        result.append({'offset': cursor, 'size': limit - cursor})
    return result


def _header_padding(model):
    layout = pe_headers.native_layout(model)
    nt_size = len(pe_structure.emit_nt_headers(layout))
    stub = model['dos_stub']
    rich = model['rich']
    spans = [
        (0, 64),
        (stub['offset'], sum(item['length'] for item in stub['instructions'])),
        (stub['message_offset'], len(stub['message'].encode('ascii'))),
        (rich['offset'], rich['marker_offset'] + 8 - rich['offset']),
        (layout['pe_offset'], nt_size),
    ]
    return _gaps(spans, layout['optional_header']['size_of_headers'])


def _reject_unsupported_file_tail(layout):
    security = layout['directories'][4] if len(layout['directories']) > 4 else None
    if security is None or security['rva'] or security['size']:
        raise ValueError('certificate/security directory is unsupported')
    raw_end = max(
        [layout['optional_header']['size_of_headers']]
        + [section['raw_offset'] + section['raw_size'] for section in layout['sections']]
    )
    if layout['file_size'] != raw_end:
        raise ValueError('unsupported overlay or trailing file size')


def _append_sections(model, sizes):
    layout = model['layout']
    coff = layout['coff']
    opt = layout['optional_header']
    requested = [(name, flags, sizes[name]) for name, flags in SECTION_SPECS if name in sizes]
    existing_names = {section['name'] for section in layout['sections']}
    collision = existing_names & {name for name, _, _ in requested}
    if collision:
        raise ValueError('mod section already exists: ' + sorted(collision)[0])

    new_count = len(layout['sections']) + len(requested)
    table_end = layout['pe_offset'] + 24 + coff['size_of_optional_header'] + 40 * new_count
    if table_end > opt['size_of_headers']:
        raise ValueError('insufficient PE header capacity for mod section headers')

    section_alignment = opt['section_alignment']
    file_alignment = opt['file_alignment']
    virtual_cursor = opt['size_of_image']
    raw_cursor = layout['file_size']
    code_growth = initialized_growth = uninitialized_growth = 0

    for name, characteristics, size in requested:
        virtual_address = _align(virtual_cursor, section_alignment, name + ' virtual')
        raw_offset = _align(raw_cursor, file_alignment, name + ' raw')
        raw_size = _align(size, file_alignment, name + ' raw size')
        virtual_extent = max(size, raw_size)
        virtual_end = virtual_address + virtual_extent
        raw_end = raw_offset + raw_size
        if virtual_end > UINT32_LIMIT or raw_end > UINT32_LIMIT:
            raise ValueError(f'{name} placement overflows PE32 section fields')
        section = {
            'index': len(layout['sections']) + 1,
            'name': name,
            'name_bytes': name + chr(0) * (8 - len(name)),
            'virtual_size': size,
            'virtual_address': virtual_address,
            'raw_size': raw_size,
            'raw_offset': raw_offset,
            'relocation_offset': 0,
            'line_number_offset': 0,
            'relocation_count': 0,
            'line_number_count': 0,
            'characteristics': characteristics,
        }
        layout['sections'].append(section)
        virtual_cursor = virtual_end
        raw_cursor = raw_end
        if characteristics & 0x20:
            code_growth += raw_size
        if characteristics & 0x40:
            initialized_growth += raw_size
        if characteristics & 0x80:
            uninitialized_growth += raw_size

    coff['number_of_sections'] = new_count
    if requested:
        opt['size_of_image'] = _align(virtual_cursor, section_alignment, 'SizeOfImage')
        layout['file_size'] = raw_cursor
    opt['size_of_code'] = _checked_add(opt['size_of_code'], code_growth, 'SizeOfCode')
    opt['size_of_initialized_data'] = _checked_add(
        opt['size_of_initialized_data'], initialized_growth, 'SizeOfInitializedData')
    opt['size_of_uninitialized_data'] = _checked_add(
        opt['size_of_uninitialized_data'], uninitialized_growth, 'SizeOfUninitializedData')
    opt['checksum'] = 0


def _replace_relocations(model, highlow_sites):
    layout = pe_headers.native_layout(model)
    reloc_sections = [section for section in layout['sections'] if section['name'] == '.reloc']
    if len(reloc_sections) != 1 or len(layout['directories']) <= 5:
        raise ValueError('one existing .reloc section and directory are required')
    section = reloc_sections[0]
    directory = model['layout']['directories'][5]
    prefix = directory['rva'] - section['virtual_address']
    if not directory['rva'] or prefix < 0 or prefix > section['raw_size']:
        raise ValueError('base-relocation directory is outside .reloc')

    blocks = _canonical_blocks(layout, highlow_sites)
    active_size = sum(block['block_size'] for block in blocks)
    capacity = section['raw_size'] - prefix
    if active_size > capacity:
        raise ValueError('base-relocation directory exceeds existing .reloc capacity')

    directory['size'] = active_size
    model['base_relocations'] = {
        'section_index': section['index'],
        'raw_offset': section['raw_offset'],
        'raw_size': section['raw_size'],
        'directory_rva': directory['rva'],
        'directory_size': active_size,
        'zero_prefix_size': prefix,
        'zero_tail_size': capacity - active_size,
        'blocks': blocks,
    }


def extend_model(model, sizes: dict[str, int], highlow_sites: list[int]):
    """Return a JSON-safe PE model with appended mod sections and rebuilt relocations.

    ``highlow_sites`` contains the complete actual set of absolute VAs emitted by
    the linker. The source model is validated and remains unchanged on success or
    failure. Existing sections, including .reloc, retain their RVA and file offset.
    """
    _validate_sizes(sizes)
    _validate_sites_shape(highlow_sites)
    if not isinstance(model, dict):
        raise TypeError('PE model must be a dictionary')

    # Validate every source declaration before extending a detached copy.
    pe_headers.emit_headers(model)
    pe_headers.emit_base_relocations(model)
    source_layout = pe_headers.native_layout(model)
    _reject_unsupported_file_tail(source_layout)

    result = copy.deepcopy(model)
    _append_sections(result, sizes)
    _replace_relocations(result, highlow_sites)
    result['zero_padding'] = _header_padding(result)

    # Both emitters provide the final field-level validation, including exact
    # HIGHLOW agreement and all section/directory bounds.
    pe_headers.emit_headers(result)
    pe_headers.emit_base_relocations(result, expected_highlow_sites=highlow_sites)
    pe_structure.emit_nt_headers(pe_headers.native_layout(result))
    return result
