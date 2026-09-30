"""Independent COFF fixtures; no reference executable is used by these tests."""
import copy
import struct
import unittest

try:
    import coff_relocations as coff
except ModuleNotFoundError as exc:
    if exc.name != 'coff_relocations':
        raise
    coff = None


def symbol(name='_target', value=0, section=0, storage=2, type_=0, aux=()):
    return dict(name=name, value=value, section=section, storage=storage,
                type=type_, aux=aux)


def object_bytes(raw=b'\0' * 12, relocations=(), symbols=None,
                 section_name='.text', section_rva=0, characteristics=0x60000020,
                 bss_size=None, extended=False):
    """Encode normal COFF independently of the production parser."""
    if symbols is None:
        symbols = [symbol()]
    strings = bytearray(b'\0' * 4)

    def name_field(name, section=False):
        encoded = name.encode('utf-8')
        if len(encoded) <= 8:
            return encoded.ljust(8, b'\0')
        offset = len(strings)
        strings.extend(encoded + b'\0')
        if section:
            return ('/' + str(offset)).encode().ljust(8, b'\0')
        return struct.pack('<II', 0, offset)

    name = name_field(section_name, True)
    symdata = bytearray()
    for item in symbols:
        symdata.extend(struct.pack('<8sIhHBB', name_field(item['name']),
                                   item['value'], item['section'], item['type'],
                                   item['storage'], len(item['aux'])))
        for aux in item['aux']:
            assert len(aux) == 18
            symdata.extend(aux)
    image = bytearray(60)
    raw_offset = len(image) if raw else 0
    image.extend(raw)
    reloc_offset = len(image) if relocations or extended else 0
    if extended:
        image.extend(struct.pack('<IIH', len(relocations) + 1, 0, 0))
        characteristics |= 0x01000000
    for offset, type_, index in relocations:
        image.extend(struct.pack('<IIH', offset + section_rva, index, type_))
    symptr = len(image)
    image.extend(symdata)
    struct.pack_into('<I', strings, 0, len(strings))
    image.extend(strings)
    struct.pack_into('<HHIIIHH', image, 0, 0x14c, 1, 0, symptr,
                     len(symdata) // 18, 0, 0)
    struct.pack_into('<8sIIIIIIHHI', image, 20, name, 0, section_rva,
                     len(raw) if bss_size is None else bss_size, raw_offset,
                     reloc_offset, 0, 0xffff if extended else len(relocations),
                     0, characteristics)
    return bytes(image)


def replaced(data, offset, fmt, *values):
    result = bytearray(data)
    struct.pack_into(fmt, result, offset, *values)
    return bytes(result)


class RequiresImplementation(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(coff, 'standalone coff_relocations implementation is missing')


class CoffParsingTests(RequiresImplementation):
    def test_section_bytes_offsets_flags_and_full_symbol_fields(self):
        data = object_bytes(symbols=[symbol('_target', 7, 1, 3, 0x20)],
                            relocations=[(4, 6, 0)])
        parsed = coff.parse_coff(data)
        self.assertEqual(parsed['machine'], 0x14c)
        sec = parsed['sections'][0]
        self.assertEqual((sec['name'], sec['index'], sec['raw_offset']), ('.text', 1, 60))
        self.assertEqual(sec['raw'], data[60:72])
        self.assertEqual(sec['characteristics'], 0x60000020)
        self.assertEqual({k: parsed['symbols'][0][k] for k in
                          ('name', 'index', 'value', 'section', 'storage', 'type')},
                         dict(name='_target', index=0, value=7, section=1, storage=3, type=0x20))
        rel = sec['relocations'][0]
        self.assertEqual((rel['offset'], rel['type'], rel['symbol_index'], rel['symbol_name']),
                         (4, 6, 0, '_target'))

    def test_zero_section_object_can_be_parsed_without_invented_sections(self):
        data = struct.pack('<HHIIIHH', 0x14c, 0, 0, 0, 0, 0, 0)
        parsed = coff.parse_coff(data)
        self.assertEqual(parsed['sections'], [])
        self.assertEqual(parsed['symbols'], {})

    def test_long_section_reference_rejects_nonzero_terminator_padding(self):
        data = object_bytes(section_name='.text$long_suffix')
        with self.assertRaisesRegex(ValueError, 'section|padding|terminator'):
            coff.parse_coff(replaced(data, 20, '<8s', b'/4\0JUNK!'))

    def test_multiple_sections_use_own_offsets_and_cross_section_symbols(self):
        image = bytearray(142)
        struct.pack_into('<HHIIIHH', image, 0, 0x14c, 2, 0, 120, 1, 0, 0)
        struct.pack_into('<8sIIIIIIHHI', image, 20, b'.text', 0, 0, 6, 100,
                         110, 0, 1, 0, 0x60000020)
        struct.pack_into('<8sIIIIIIHHI', image, 60, b'.data', 0, 0, 4, 106,
                         0, 0, 0, 0, 0xc0000040)
        image[100:106] = bytes.fromhex('e800000000c3')
        image[106:110] = b'DATA'
        struct.pack_into('<IIH', image, 110, 1, 0, 20)
        struct.pack_into('<8sIhHBB', image, 120, b'_target', 0, 2, 0, 2, 0)
        struct.pack_into('<I', image, 138, 4)
        parsed = coff.parse_coff(bytes(image))
        self.assertEqual([s['index'] for s in parsed['sections']], [1, 2])
        self.assertEqual(parsed['sections'][1]['raw'], b'DATA')
        output, _ = coff.relocate(parsed['sections'][0], 0x401000, {'_target': 0x402000})
        self.assertEqual(output, bytes.fromhex('e8fb0f0000c3'))
        with self.assertRaisesRegex(ValueError, 'overlap'):
            coff.parse_coff(replaced(image, 80, '<I', 100))

    def test_long_utf8_and_exact_eight_byte_names(self):
        for name in ('12345678', '?long_symbol_name@@YAXXZ', 'função_longa'):
            with self.subTest(name=name):
                parsed = coff.parse_coff(object_bytes(symbols=[symbol(name)],
                                                     section_name='.text$long_suffix'))
                self.assertEqual(parsed['symbols'][0]['name'], name)
                self.assertEqual(parsed['sections'][0]['name'], '.text$long_suffix')

    def test_auxiliary_slots_are_not_symbols_and_preserve_actual_indexes(self):
        data = object_bytes(symbols=[symbol('.file', section=-2, storage=103,
                                           aux=(b'A' * 18, b'B' * 18)), symbol()],
                            relocations=[(0, 6, 3)])
        parsed = coff.parse_coff(data)
        self.assertEqual(set(parsed['symbols']), {0, 3})
        self.assertEqual(parsed['symbols'][3]['index'], 3)
        self.assertEqual(parsed['sections'][0]['relocations'][0]['symbol_name'], '_target')

    def test_duplicate_symbol_names_keep_separate_coff_indexes(self):
        parsed = coff.parse_coff(object_bytes(symbols=[symbol('same'), symbol('same', value=4)]))
        self.assertEqual(set(parsed['symbols']), {0, 1})
        self.assertEqual(parsed['symbols'][1]['value'], 4)

    def test_nonzero_object_section_rva_is_normalized_at_relocation_site(self):
        sec = coff.parse_coff(object_bytes(relocations=[(4, 6, 0)], section_rva=0x100))['sections'][0]
        self.assertEqual(sec['relocations'][0]['offset'], 4)

    def test_object_without_symbol_table_and_relocations_is_allowed(self):
        data = object_bytes(symbols=[])
        symptr = struct.unpack_from('<I', data, 8)[0]
        data = replaced(data[:symptr], 8, '<II', 0, 0)
        self.assertEqual(coff.parse_coff(data)['symbols'], {})

    def test_uninitialized_section_does_not_invent_file_bytes(self):
        sec = coff.parse_coff(object_bytes(raw=b'', symbols=[], section_name='.bss',
                                          characteristics=0xc0000080, bss_size=64))['sections'][0]
        self.assertEqual(sec['raw'], b'')
        self.assertEqual(sec['raw_offset'], 0)
        self.assertEqual(sec['raw_size'], 64)

    def test_every_truncated_prefix_is_rejected(self):
        data = object_bytes(symbols=[symbol('a_long_symbol_name')], relocations=[(0, 6, 0)])
        for length in range(len(data)):
            with self.subTest(length=length), self.assertRaises(ValueError):
                coff.parse_coff(data[:length])

    def test_invalid_machine_optional_header_and_counts_fail(self):
        data = object_bytes()
        for offset, fmt, value in ((0, '<H', 0x8664), (16, '<H', 224),
                                   (2, '<H', 0x7fff), (8, '<I', 0xffffffff),
                                   (12, '<I', 0xffffffff), (8, '<I', 0)):
            with self.subTest(offset=offset, value=value), self.assertRaises(ValueError):
                coff.parse_coff(replaced(data, offset, fmt, value))

    def test_raw_relocation_and_symbol_tables_cannot_alias_headers_or_each_other(self):
        data = object_bytes(relocations=[(0, 6, 0)])
        for offset, value in ((40, 4), (40, len(data)), (44, 0), (44, 60),
                              (44, len(data)-4), (8, 60)):
            with self.subTest(offset=offset, value=value), self.assertRaises(ValueError):
                coff.parse_coff(replaced(data, offset, '<I', value))

    def test_truncated_line_number_table_is_rejected(self):
        data = object_bytes()
        data = replaced(data, 48, '<I', len(data)-2)
        data = replaced(data, 54, '<H', 1)
        with self.assertRaises(ValueError):
            coff.parse_coff(data)

    def test_invalid_string_table_size_offsets_and_termination_fail(self):
        data = object_bytes(symbols=[symbol('long_symbol_name')])
        symptr = struct.unpack_from('<I', data, 8)[0]
        strings = symptr + 18
        invalid = [replaced(data, strings, '<I', 3),
                   replaced(data, strings, '<I', 0xffffffff),
                   replaced(data, symptr+4, '<I', 2),
                   replaced(data, symptr+4, '<I', len(data)), data[:-1]+b'X']
        for image in invalid:
            with self.subTest(image=image), self.assertRaises(ValueError):
                coff.parse_coff(image)

    def test_invalid_long_section_name_offset_fails(self):
        data = object_bytes()
        for name in (b'/9999999', b'/oops\0\0\0'):
            with self.subTest(name=name), self.assertRaises(ValueError):
                coff.parse_coff(replaced(data, 20, '<8s', name))

    def test_auxiliary_count_cannot_consume_past_symbol_table(self):
        data = object_bytes()
        symptr = struct.unpack_from('<I', data, 8)[0]
        with self.assertRaisesRegex(ValueError, 'auxiliary'):
            coff.parse_coff(replaced(data, symptr+17, '<B', 1))

    def test_relocation_cannot_reference_auxiliary_or_absent_symbol(self):
        for index in (1, 2, 0xffffffff):
            with self.subTest(index=index), self.assertRaisesRegex(ValueError, 'symbol'):
                coff.parse_coff(object_bytes(symbols=[symbol(aux=(b'\0'*18,))],
                                             relocations=[(0, 6, index)]))

    def test_invalid_symbol_section_is_rejected(self):
        for section in (-3, 2):
            with self.subTest(section=section), self.assertRaises(ValueError):
                coff.parse_coff(object_bytes(symbols=[symbol(section=section)]))

    def test_unsupported_relocation_type_is_rejected(self):
        with self.assertRaisesRegex(ValueError, 'unsupported'):
            coff.parse_coff(object_bytes(relocations=[(0, 0x1234, 0)]))

    def test_relocation_must_fit_four_file_backed_bytes(self):
        for offset in (9, 12, 0xffffffff):
            with self.subTest(offset=offset), self.assertRaises(ValueError):
                coff.parse_coff(object_bytes(relocations=[(offset, 6, 0)]))

    def test_duplicate_and_overlapping_write_sites_fail_even_unsorted(self):
        for second in (0, 1, 2, 3):
            with self.subTest(second=second), self.assertRaisesRegex(ValueError, 'overlap|duplicate'):
                coff.parse_coff(object_bytes(relocations=[(second, 6, 0), (0, 20, 0)]))

    def test_absolute_padding_ignores_unused_symbol_and_site_fields(self):
        sec = coff.parse_coff(object_bytes(relocations=[(0xffffffff, 0, 0xffffffff),
                                                       (0, 0, 0), (0, 6, 0)]))['sections'][0]
        self.assertEqual(len(sec['relocations']), 3)
        relocated, evidence = coff.relocate(sec, 0x401000, {'_target': 0x402000})
        self.assertEqual(relocated[:4], struct.pack('<I', 0x402000))
        self.assertFalse(evidence[0]['applied'])

    def test_extended_relocation_count_excludes_the_first_count_record(self):
        data = object_bytes(raw=b'', symbols=[], extended=True,
                            relocations=[(0, 0, 0)] * 0xffff)
        parsed = coff.parse_coff(data)
        self.assertEqual(len(parsed['sections'][0]['relocations']), 0xffff)

    def test_malformed_extended_relocation_counts_fail(self):
        data = object_bytes(extended=True, relocations=[(0, 0, 0)])
        ptr = struct.unpack_from('<I', data, 44)[0]
        invalid = [data, replaced(data, 52, '<H', 1),
                   replaced(data, ptr, '<I', 0xffffffff),
                   replaced(data, ptr+4, '<I', 1), replaced(data, ptr+8, '<H', 6)]
        for image in invalid:
            with self.subTest(image=image), self.assertRaises(ValueError):
                coff.parse_coff(image)


class CoffRelocationTests(RequiresImplementation):
    def section(self, type_=6, addend=0, offset=0, raw=None, symbols=None):
        if raw is None:
            raw = b'\x90'*offset + struct.pack('<i', addend) + b'\xc3'
        return coff.parse_coff(object_bytes(raw=raw, relocations=[(offset, type_, 0)],
                                             symbols=symbols))['sections'][0]

    def test_dir32_applies_positive_zero_and_signed_negative_addends(self):
        for addend in (0, 23, -4, -0x400000):
            with self.subTest(addend=addend):
                sec = self.section(addend=addend, offset=1)
                output, evidence = coff.relocate(sec, 0x401000, {'_target': 0x405000})
                self.assertEqual(output, b'\x90'+struct.pack('<I', 0x405000+addend)+b'\xc3')
                self.assertEqual(evidence[0]['addend'], addend)
                self.assertEqual(evidence[0]['symbol_index'], 0)
                self.assertTrue(evidence[0]['applied'])

    def test_dir32nb_subtracts_image_base_after_signed_addend(self):
        output, _ = coff.relocate(self.section(7, -0x20), 0x701000,
                                  {'_target': 0x704020}, image_base=0x700000)
        self.assertEqual(struct.unpack_from('<I', output)[0], 0x4000)

    def test_rel32_uses_address_after_the_relocation_field(self):
        for addend in (0, -4, 17):
            for target in (0x401020, 0x400000):
                with self.subTest(addend=addend, target=target):
                    raw = b'\xe8' + struct.pack('<i', addend) + b'\xc3'
                    output, _ = coff.relocate(self.section(20, offset=1, raw=raw),
                                              0x401000, {'_target': target})
                    self.assertEqual(output, b'\xe8'+struct.pack('<i', target+addend-0x401005)+b'\xc3')

    def test_symbol_bindings_are_final_addresses_without_double_adding_symbol_value(self):
        sec = self.section(symbols=[symbol(value=0x34, section=1)])
        output, _ = coff.relocate(sec, 0x401000, {'_target': 0x401034})
        self.assertEqual(struct.unpack_from('<I', output)[0], 0x401034)

    def test_undefined_external_requires_explicit_binding(self):
        with self.assertRaisesRegex(ValueError, 'undefined|unresolved|binding'):
            coff.relocate(self.section(), 0x401000, {})

    def test_absolute_record_needs_no_binding_and_does_not_change_bytes(self):
        sec = self.section(type_=0, addend=-123)
        output, evidence = coff.relocate(sec, 0x401000, {})
        self.assertEqual(output, sec['raw'])
        self.assertFalse(evidence[0]['applied'])

    def test_unrecorded_pointer_looking_words_are_untouched(self):
        raw = struct.pack('<III', 0, 0x402000, 0xe8123456)
        output, evidence = coff.relocate(self.section(raw=raw), 0x401000, {'_target': 0x403000})
        self.assertEqual(output[4:], raw[4:])
        self.assertEqual(len(evidence), 1)

    def test_dir32_accepts_uint32_limit_without_wrapping(self):
        output, _ = coff.relocate(self.section(addend=0x7fffffff), 0x401000,
                                  {'_target': 0x80000000})
        self.assertEqual(output[:4], b'\xff'*4)

    def test_dir32_overflow_and_underflow_fail(self):
        for target, addend in ((0xffffffff, 1), (0, -1)):
            with self.subTest(target=target), self.assertRaisesRegex(ValueError, 'overflow|range'):
                coff.relocate(self.section(addend=addend), 0x401000, {'_target': target})

    def test_dir32nb_underflow_fails(self):
        with self.assertRaisesRegex(ValueError, 'overflow|range'):
            coff.relocate(self.section(7, -1), 0x401000, {'_target': 0x400000})

    def test_rel32_signed_limits_and_overflow(self):
        for site, target, expected in ((0x100, 0x80000103, 0x7fffffff),
                                       (0x80000000, 4, -0x80000000)):
            with self.subTest(site=site):
                result, _ = coff.relocate(self.section(20), site, {'_target': target})
                self.assertEqual(struct.unpack_from('<i', result)[0], expected)
        for site, target in ((0x100, 0x80000104), (0x80000000, 3)):
            with self.subTest(site=site), self.assertRaisesRegex(ValueError, 'overflow|range'):
                coff.relocate(self.section(20), site, {'_target': target})

    def test_address_and_section_extent_validation(self):
        for bad in (-1, 0x100000000, True, 1.5, '0x401000'):
            with self.subTest(bad=bad):
                for which in ('section', 'symbol', 'base'):
                    args = [self.section(), 0x401000, {'_target': 0x402000}, 0x400000]
                    if which == 'section':
                        args[1] = bad
                    elif which == 'symbol':
                        args[2]['_target'] = bad
                    else:
                        args[3] = bad
                    with self.assertRaises(ValueError):
                        coff.relocate(*args)
        with self.assertRaisesRegex(ValueError, 'overflow|range'):
            coff.relocate(self.section(), 0xfffffffe, {'_target': 0x402000})

    def test_relocate_rechecks_invalid_or_overlapping_records(self):
        for kind in ('unknown', 'outside', 'duplicate', 'overlap', 'missing-name'):
            sec = self.section(raw=b'\0'*12)
            if kind == 'unknown':
                sec['relocations'][0]['type'] = 1
            elif kind == 'outside':
                sec['relocations'][0]['offset'] = 9
            elif kind in ('duplicate', 'overlap'):
                extra = dict(sec['relocations'][0])
                extra['offset'] = 0 if kind == 'duplicate' else 2
                sec['relocations'].append(extra)
            else:
                sec['relocations'][0]['symbol_name'] = None
            with self.subTest(kind=kind), self.assertRaises(ValueError):
                coff.relocate(sec, 0x401000, {'_target': 0x402000})

    def test_multiple_records_read_original_addends_and_preserve_inputs(self):
        raw = struct.pack('<iii', 4, -8, 0)
        sec = coff.parse_coff(object_bytes(raw=raw,
                    relocations=[(8, 20, 1), (0, 6, 0), (4, 7, 0)],
                    symbols=[symbol('_data'), symbol('_func')]))['sections'][0]
        before = copy.deepcopy(sec)
        bindings = {'_data': 0x405000, '_func': 0x402000}
        output, evidence = coff.relocate(sec, 0x401000, bindings)
        self.assertEqual(output, struct.pack('<IIi', 0x405004, 0x4ff8, 0xff4))
        self.assertEqual([e['offset'] for e in evidence], [8, 0, 4])
        self.assertEqual(sec, before)
        self.assertEqual(bindings, {'_data': 0x405000, '_func': 0x402000})
        with self.assertRaises(ValueError):
            coff.relocate(sec, 0x401000, {'_data': 0x405000})
        self.assertEqual(sec, before)


if __name__ == '__main__':
    unittest.main()
