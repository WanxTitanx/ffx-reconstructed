"""Independent PE fixtures for exact header emission and bounded import reads."""
import copy
import struct
import unittest

try:
    import pe_structure as pe
except ModuleNotFoundError:
    pe = None


PE = 0x80
OPT = PE + 24


def fixture(directory_count=16, tail=b''):
    data = bytearray(0xc80)
    data[:2] = b'MZ'
    data[0x40:0x60] = b'DOS prefix is outside this API!!!'
    struct.pack_into('<I', data, 0x3c, PE)
    data[PE:PE + 4] = b'PE\0\0'
    opt_size = 96 + 8 * directory_count + len(tail)
    struct.pack_into('<HHIIIHH', data, PE + 4, 0x14c, 2, 0x55667788, 0, 0, opt_size, 0x102)
    struct.pack_into('<HBBIIIIII', data, OPT, 0x10b, 11, 7, 0x200, 0x600, 0x200,
                     0x1000, 0x1000, 0x2000)
    struct.pack_into('<IIIHHHHHHIIIIHHIIIIII', data, OPT + 28,
                     0x400000, 0x1000, 0x200, 6, 1, 3, 4, 6, 2,
                     0x1234, 0x3000, 0x400, 0xaabbccdd, 3, 0x8140,
                     0x100000, 0x1000, 0x200000, 0x2000, 0x44, directory_count)
    data[OPT + 96 + directory_count * 8:OPT + opt_size] = tail
    table = OPT + opt_size
    struct.pack_into('<8sIIIIIIHHI', data, table, b'.text\0\0\0', 0x200, 0x1000,
                     0x200, 0x400, 0, 0, 0, 0, 0x60000020)
    struct.pack_into('<8sIIIIIIHHI', data, table + 40, b'.idata\0\0', 0x800, 0x2000,
                     0x600, 0x600, 0, 0, 0, 0, 0xc0000040)
    data[0x400:0x600] = b'\x90' * 0x200
    if directory_count > 1:
        put_directory(data, 1, 0x2000, 40)
        put_descriptor(data, 0x2000, 0x2080, 0, 0, 0x2040, 0x20a0)
        put_rva(data, 0x2040, b'KERNEL32.dll\0')
        put_rva(data, 0x2080, struct.pack('<III', 0x20c0, 0x80000007, 0))
        put_rva(data, 0x20a0, struct.pack('<III', 0x20c0, 0x80000007, 0))
        put_rva(data, 0x20c0, struct.pack('<H', 19) + b'ExitProcess\0')
    return data


def put_directory(data, index, rva, size):
    struct.pack_into('<II', data, OPT + 96 + index * 8, rva, size)


def offset(rva):
    return rva if rva < 0x400 else 0x600 + rva - 0x2000


def put_rva(data, rva, value):
    at = offset(rva)
    data[at:at + len(value)] = value


def put_descriptor(data, rva, lookup, timestamp, forwarder, name, iat):
    put_rva(data, rva, struct.pack('<IIIII', lookup, timestamp, forwarder, name, iat))


class HeaderTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(pe, 'PE metadata component is missing')

    def test_exact_roundtrip_preserves_every_header_field(self):
        data = bytes(fixture())
        layout = pe.parse_layout(data)
        self.assertEqual(layout['pe_offset'], PE)
        self.assertEqual(layout['image_base'], 0x400000)
        self.assertEqual(layout['entry_rva'], 0x1000)
        self.assertEqual(layout['file_size'], len(data))
        self.assertEqual(layout['signature'], 0x4550)
        self.assertEqual(layout['coff']['time_date_stamp'], 0x55667788)
        opt = layout['optional_header']
        for field, expected in {'minor_linker_version': 7, 'minor_operating_system_version': 1,
                                'major_image_version': 3, 'minor_image_version': 4,
                                'minor_subsystem_version': 2, 'win32_version_value': 0x1234,
                                'checksum': 0xaabbccdd, 'loader_flags': 0x44,
                                'size_of_heap_reserve': 0x200000,
                                'size_of_uninitialized_data': 0x200}.items():
            self.assertEqual(opt[field], expected, field)
        self.assertEqual(layout['sections'][1]['raw_offset'], 0x600)
        self.assertEqual(layout['sections'][1]['virtual_size'], 0x800)
        self.assertEqual(layout['sections'][1]['raw_size'], 0x600)
        self.assertEqual(layout['directories'][1]['rva'], 0x2000)
        self.assertEqual(layout['directories'][1]['size'], 40)
        self.assertEqual(pe.emit_nt_headers(layout), data[PE:OPT + 224 + 80])

    def test_emitter_uses_fields_and_excludes_dos_prefix(self):
        data = bytes(fixture())
        layout = pe.parse_layout(data)
        layout['coff']['time_date_stamp'] = 12345
        emitted = pe.emit_nt_headers(layout)
        self.assertEqual(struct.unpack_from('<I', emitted, 8)[0], 12345)
        self.assertTrue(emitted.startswith(b'PE\0\0'))
        self.assertNotIn(b'DOS prefix', emitted)
        self.assertEqual(len(emitted), 24 + 224 + 80)

    def test_optional_extension_and_all_declared_directories_roundtrip(self):
        for count, tail in ((0, b'\xa1\xb2\xc3'), (3, b'\xfe\x12'), (17, b'')):
            with self.subTest(count=count):
                data = bytes(fixture(count, tail))
                layout = pe.parse_layout(data)
                self.assertEqual(len(layout['directories']), count)
                self.assertEqual(layout['optional_header_tail'], tail)
                self.assertEqual(pe.emit_nt_headers(layout), data[PE:OPT + 96 + count * 8 + len(tail) + 80])

    def test_section_name_bytes_and_deprecated_section_fields_roundtrip(self):
        data = fixture()
        table = OPT + 224
        data[table:table + 8] = b'EightChr'
        data[table + 40:table + 48] = b'.id\0ABCD'
        struct.pack_into('<IIHH', data, table + 24, 0xc00, 0xc20, 2, 3)
        layout = pe.parse_layout(bytes(data))
        self.assertEqual(layout['sections'][0]['name'], 'EightChr')
        self.assertEqual(layout['sections'][1]['name_bytes'], b'.id\0ABCD')
        self.assertEqual(layout['sections'][0]['relocation_offset'], 0xc00)
        self.assertEqual(layout['sections'][0]['line_number_count'], 3)
        self.assertEqual(pe.emit_nt_headers(layout), bytes(data[PE:table + 80]))

    def test_bss_section_is_described_without_inventing_disk_bytes(self):
        data = fixture(0)
        table = OPT + 96
        struct.pack_into('<II', data, table + 40 + 16, 0, 0)
        layout = pe.parse_layout(bytes(data))
        self.assertEqual(layout['sections'][1]['raw_size'], 0)
        self.assertEqual(layout['sections'][1]['virtual_size'], 0x800)

    def test_non_pe32_x86_and_invalid_signatures_fail(self):
        cases = [(0, b'XX'), (0x3c, struct.pack('<I', 32)), (PE, b'PX\0\0'),
                 (PE + 4, struct.pack('<H', 0x8664)), (OPT, struct.pack('<H', 0x20b))]
        for at, replacement in cases:
            with self.subTest(at=at, replacement=replacement):
                data = fixture()
                data[at:at + len(replacement)] = replacement
                with self.assertRaises(ValueError):
                    pe.parse_layout(bytes(data))

    def test_truncated_headers_and_section_bytes_fail(self):
        data = bytes(fixture())
        for length in (0, 63, PE + 23, OPT + 95, OPT + 224 + 79, 0xbff):
            with self.subTest(length=length), self.assertRaises(ValueError):
                pe.parse_layout(data[:length])

    def test_impossible_header_and_directory_counts_fail(self):
        for at, fmt, value in ((PE + 6, '<H', 0xffff), (PE + 20, '<H', 95),
                               (OPT + 92, '<I', 17), (OPT + 60, '<I', 0x100),
                               (OPT + 60, '<I', 0x100000)):
            data = fixture()
            struct.pack_into(fmt, data, at, value)
            with self.subTest(at=at, value=value), self.assertRaises(ValueError):
                pe.parse_layout(bytes(data))

    def test_raw_and_virtual_bounds_and_overlaps_fail(self):
        table = OPT + 224
        cases = [(table + 20, 0), (table + 20, 0xc70), (table + 20, 0xffffffff),
                 (table + 40 + 20, 0x500), (table + 12, 0x200),
                 (table + 40 + 12, 0x1100), (table + 12, 0xffffff00),
                 (OPT + 56, 0x2100), (OPT + 28, 0xfffff000)]
        for at, value in cases:
            data = fixture()
            struct.pack_into('<I', data, at, value)
            with self.subTest(at=at, value=value), self.assertRaises(ValueError):
                pe.parse_layout(bytes(data))

    def test_directory_bounds_and_security_file_offset(self):
        data = fixture()
        put_directory(data, 4, 0xc00, 16)
        put_directory(data, 8, 0x2200, 0)
        layout = pe.parse_layout(bytes(data))
        self.assertEqual(layout['directories'][4]['address_kind'], 'file_offset')
        self.assertEqual(pe.emit_nt_headers(layout), bytes(data[PE:OPT + 224 + 80]))
        for index, rva, size in ((4, 0xc78, 16), (2, 0x1800, 16),
                                  (2, 0x27fc, 8), (1, 0, 40)):
            bad = fixture()
            put_directory(bad, index, rva, size)
            with self.subTest(index=index, rva=rva), self.assertRaises(ValueError):
                pe.parse_layout(bytes(bad))

    def test_deprecated_table_bounds_fail(self):
        table = OPT + 224
        cases = [(table + 24, '<IIHH', (0xc7c, 0, 1, 0)),
                 (table + 24, '<IIHH', (0, 0xc7c, 0, 1)),
                 (PE + 12, '<II', (0xc70, 2)), (PE + 12, '<II', (0, 1))]
        for at, fmt, values in cases:
            data = fixture()
            struct.pack_into(fmt, data, at, *values)
            with self.subTest(at=at, values=values), self.assertRaises(ValueError):
                pe.parse_layout(bytes(data))

    def test_emitter_rejects_inconsistent_counts_aliases_and_field_widths(self):
        for group, key, value in (('coff', 'number_of_sections', 3),
                                  ('coff', 'time_date_stamp', 1 << 32),
                                  ('coff', 'machine', -1),
                                  ('optional_header', 'minor_image_version', True),
                                  ('optional_header', 'number_of_rva_and_sizes', 99)):
            layout = pe.parse_layout(bytes(fixture()))
            layout[group][key] = value
            with self.subTest(key=key), self.assertRaises(ValueError):
                pe.emit_nt_headers(layout)
        layout = pe.parse_layout(bytes(fixture()))
        layout['image_base'] += 4096
        with self.assertRaises(ValueError):
            pe.emit_nt_headers(layout)


class ImportTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(pe, 'PE metadata component is missing')

    def parse(self, data):
        data = bytes(data)
        return pe.parse_imports(data, pe.parse_layout(data))

    def test_hint_name_ordinal_and_exact_slot_addresses(self):
        imports = self.parse(fixture())
        self.assertEqual(len(imports), 1)
        dll = imports[0]
        self.assertEqual(dll['dll'], 'KERNEL32.dll')
        self.assertEqual(dll['descriptor_rva'], 0x2000)
        self.assertEqual(dll['descriptor_va'], 0x402000)
        self.assertEqual(dll['descriptor_offset'], 0x600)
        self.assertEqual(dll['original_first_thunk'], 0x2080)
        self.assertEqual(dll['first_thunk'], 0x20a0)
        first, second = dll['imports']
        self.assertEqual((first['hint'], first['name'], first['ordinal']), (19, 'ExitProcess', None))
        self.assertEqual((first['lookup_slot_rva'], first['lookup_slot_va']), (0x2080, 0x402080))
        self.assertEqual((first['iat_slot_rva'], first['iat_slot_va']), (0x20a0, 0x4020a0))
        self.assertEqual(first['iat_slot_offset'], 0x6a0)
        self.assertEqual((second['hint'], second['name'], second['ordinal']), (None, None, 7))
        self.assertEqual(second['iat_slot_va'], 0x4020a4)

    def test_bound_iat_is_preserved_while_names_come_from_lookup(self):
        data = fixture()
        put_descriptor(data, 0x2000, 0x2080, 0x12345678, 0xffffffff, 0x2040, 0x20a0)
        put_rva(data, 0x20a0, struct.pack('<III', 0x7ff01020, 0x7ff01234, 0))
        dll = self.parse(data)[0]
        self.assertEqual(dll['time_date_stamp'], 0x12345678)
        self.assertEqual(dll['forwarder_chain'], 0xffffffff)
        self.assertEqual(dll['imports'][0]['name'], 'ExitProcess')
        self.assertEqual(dll['imports'][0]['iat_value'], 0x7ff01020)

    def test_missing_lookup_uses_unbound_iat(self):
        data = fixture()
        put_descriptor(data, 0x2000, 0, 0, 0, 0x2040, 0x20a0)
        dll = self.parse(data)[0]
        self.assertEqual(dll['lookup_rva'], 0x20a0)
        self.assertEqual(dll['imports'][0]['lookup_slot_va'], 0x4020a0)
        self.assertEqual(dll['imports'][0]['name'], 'ExitProcess')

    def test_bound_iat_without_lookup_is_explicitly_unsupported(self):
        data = fixture()
        put_descriptor(data, 0x2000, 0, 0x12345678, 0, 0x2040, 0x20a0)
        with self.assertRaisesRegex(ValueError, 'bound|lookup'):
            self.parse(data)

    def test_absent_and_empty_import_tables(self):
        self.assertEqual(self.parse(fixture(0)), [])
        data = fixture()
        put_directory(data, 1, 0, 0)
        self.assertEqual(self.parse(data), [])
        data = fixture()
        put_rva(data, 0x2000, bytes(20))
        self.assertEqual(self.parse(data), [])

    def test_multiple_descriptors_preserve_each_iat(self):
        data = fixture()
        put_directory(data, 1, 0x2000, 60)
        put_descriptor(data, 0x2014, 0x2080, 0, 0, 0x2100, 0x2120)
        put_rva(data, 0x2100, b'OTHER.dll\0')
        put_rva(data, 0x2120, struct.pack('<III', 0x20c0, 0x80000007, 0))
        parsed = self.parse(data)
        self.assertEqual([d['dll'] for d in parsed], ['KERNEL32.dll', 'OTHER.dll'])
        self.assertEqual(parsed[1]['imports'][1]['iat_slot_va'], 0x402124)

    def test_imports_can_be_backed_by_headers(self):
        data = fixture()
        put_directory(data, 1, 0x280, 40)
        put_descriptor(data, 0x280, 0x300, 0, 0, 0x2c0, 0x320)
        put_rva(data, 0x2c0, b'HEADER.dll\0')
        put_rva(data, 0x300, struct.pack('<II', 0x340, 0))
        put_rva(data, 0x320, struct.pack('<II', 0x340, 0))
        put_rva(data, 0x340, b'\x01\0Func\0')
        dll = self.parse(data)[0]
        self.assertEqual(dll['dll'], 'HEADER.dll')
        self.assertEqual(dll['imports'][0]['iat_slot_offset'], 0x320)

    def test_descriptor_termination_is_bounded_by_directory_size(self):
        for size in (1, 19, 20, 39):
            data = fixture()
            put_directory(data, 1, 0x2000, size)
            with self.subTest(size=size), self.assertRaises(ValueError):
                self.parse(data)

    def test_partial_descriptors_missing_dll_or_iat_fail(self):
        for name, iat in ((0, 0x20a0), (0x2040, 0)):
            data = fixture()
            put_descriptor(data, 0x2000, 0x2080, 0, 0, name, iat)
            with self.subTest(name=name, iat=iat), self.assertRaises(ValueError):
                self.parse(data)

    def test_unterminated_dll_and_function_names_fail(self):
        data = fixture()
        put_descriptor(data, 0x2000, 0x2080, 0, 0, 0x25fd, 0x20a0)
        put_rva(data, 0x25fd, b'XYZ')
        with self.assertRaises(ValueError):
            self.parse(data)
        data = fixture()
        put_rva(data, 0x2080, struct.pack('<I', 0x25fc))
        put_rva(data, 0x25fc, b'\x02\0XY')
        with self.assertRaises(ValueError):
            self.parse(data)

    def test_non_ascii_and_empty_names_fail(self):
        for rva, value in ((0x2040, b'\0'), (0x2040, b'\xff\0'),
                            (0x20c2, b'\0'), (0x20c2, b'\xff\0')):
            data = fixture()
            put_rva(data, rva, value)
            with self.subTest(rva=rva, value=value), self.assertRaises(ValueError):
                self.parse(data)

    def test_gap_zero_fill_and_truncated_hint_reads_fail(self):
        for name_rva in (0x1800, 0x2600, 0x25ff, 0x7ffffffe):
            data = fixture()
            put_rva(data, 0x2080, struct.pack('<I', name_rva))
            with self.subTest(rva=name_rva), self.assertRaises(ValueError):
                self.parse(data)

    def test_unterminated_and_truncated_lookup_tables_fail(self):
        for rva in (0x25fc, 0x25fd, 0x2600, 0x1800):
            data = fixture()
            put_descriptor(data, 0x2000, rva, 0, 0, 0x2040, 0x20a0)
            if rva == 0x25fc:
                put_rva(data, rva, struct.pack('<I', 0x20c0))
            with self.subTest(rva=rva), self.assertRaises(ValueError):
                self.parse(data)

    def test_short_or_unterminated_iat_fails(self):
        data = fixture()
        put_descriptor(data, 0x2000, 0x2080, 0, 0, 0x2040, 0x25fc)
        put_rva(data, 0x25fc, struct.pack('<I', 0x20c0))
        with self.assertRaises(ValueError):
            self.parse(data)
        for rva, value in ((0x20a0, 0), (0x20a8, 0x1234)):
            data = fixture()
            put_rva(data, rva, struct.pack('<I', value))
            with self.subTest(rva=rva), self.assertRaises(ValueError):
                self.parse(data)

    def test_ordinal_reserved_bits_fail(self):
        data = fixture()
        put_rva(data, 0x2080, struct.pack('<I', 0x80010007))
        with self.assertRaisesRegex(ValueError, 'ordinal'):
            self.parse(data)

    def test_layout_must_describe_the_supplied_image(self):
        data = fixture()
        layout = pe.parse_layout(bytes(data))
        struct.pack_into('<I', data, PE + 8, 0x9999)
        with self.assertRaisesRegex(ValueError, 'layout|header'):
            pe.parse_imports(bytes(data), layout)


if __name__ == '__main__':
    unittest.main()
