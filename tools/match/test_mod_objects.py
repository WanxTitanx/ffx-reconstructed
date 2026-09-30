"""Static symbol replacement uses real relocations, never guessed operand bytes."""
import copy
import struct
import unittest
import coff_emit
import coff_relocations as coff

try:
    import mod_objects
except ModuleNotFoundError:
    mod_objects = None


class ReplacementTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(mod_objects, 'static modification linking is missing')
        self.bindings = {'_sym_00402000': 0x402000, '_sym_00401ff0': 0x401ff0}
        self.replacements = [{'va': 0x402000, 'size': 16, 'new_va': 0x2400000}]

    def section(self, name='_sym_00402000', addend=0, kind=coff.REL32):
        data = coff_emit.make_object('.test', b'\xe8' + struct.pack('<i', addend),
            [{'offset': 1, 'type': kind, 'symbol_name': name}], {})
        return coff.parse_coff(data)['sections'][0]

    def test_real_call_moves_without_changing_original_object(self):
        original = self.section()
        saved = copy.deepcopy(original)
        raw, records, sites = mod_objects.relink(original, 0x401000, self.bindings, self.replacements)
        self.assertEqual(raw[0], 0xe8)
        self.assertEqual(0x401005 + struct.unpack_from('<i', raw, 1)[0], 0x2400000)
        self.assertEqual(original, saved)
        self.assertEqual(len(records), 1)
        self.assertEqual(sites, [])

    def test_actual_addend_is_honored_when_rebinding(self):
        raw, _, _ = mod_objects.relink(self.section('_sym_00401ff0', 16),
                                      0x401000, self.bindings, self.replacements)
        self.assertEqual(0x401005 + struct.unpack_from('<i', raw, 1)[0], 0x2400000)

    def test_interior_reference_is_rejected(self):
        with self.assertRaisesRegex(ValueError, 'interior'):
            mod_objects.relink(self.section(addend=1), 0x401000, self.bindings, self.replacements)

    def test_old_body_internal_references_remain_self_contained(self):
        raw, records, _ = mod_objects.relink(self.section(addend=1), 0x402004,
                                             self.bindings, self.replacements)
        self.assertEqual(0x402009 + struct.unpack_from('<i', raw, 1)[0], 0x402001)
        self.assertFalse(records)

    def test_multiple_replacements_preserve_references_between_retained_bodies(self):
        replacements = self.replacements + [{'va': 0x403000, 'size': 16, 'new_va': 0x2401000}]
        bindings = dict(self.bindings, _sym_00403000=0x403000)
        raw, records, _ = mod_objects.relink(self.section('_sym_00403000'),
                                              0x402004, bindings, replacements)
        self.assertEqual(0x402009 + struct.unpack_from('<i', raw, 1)[0], 0x403000)
        self.assertFalse(records)

    def test_data_pointer_moves_and_retains_highlow(self):
        raw, records, sites = mod_objects.relink(self.section(kind=coff.DIR32),
            0x501000, self.bindings, self.replacements)
        self.assertEqual(struct.unpack_from('<I', raw, 1)[0], 0x2400000)
        self.assertEqual(sites, [0x501001])
        self.assertEqual(records[0]['to'], 0x2400000)

    def test_short_branch_reference_cannot_be_silently_left_behind(self):
        records = [{'kind': 'instruction', 'classification': 'ida_code', 'instruction':
            {'ip': 0x401ff0, 'length': 2, 'code': 'JMP_REL8_32', 'prefixes': {},
             'operands': [{'kind': 'NEAR_BRANCH32', 'target': {'symbol': '_sym_00402000'}}],
             'base_relocations': []}}]
        with self.assertRaisesRegex(ValueError, 'short|unrelocated'):
            mod_objects.check_instruction_references(records, self.bindings, self.replacements)

    def test_numeric_function_address_without_relocation_is_rejected(self):
        from iced_x86 import Decoder
        import x86_source
        decoder = Decoder(32, bytes.fromhex('b820204000'), ip=0x401100)
        instruction = next(iter(decoder))
        # 0x402020 is outside the selected extent; an unrelated value is allowed.
        record = {'kind': 'instruction', 'instruction': x86_source.describe(
            instruction, decoder.get_constant_offsets(instruction))}
        mod_objects.check_instruction_references([record], self.bindings, self.replacements)
        record['instruction']['operands'][1]['value'] = 0x402000
        with self.assertRaisesRegex(ValueError, 'numeric'):
            mod_objects.check_instruction_references([record], self.bindings, self.replacements)

    def test_numeric_memory_address_without_relocation_is_rejected(self):
        from iced_x86 import Decoder
        import x86_source
        decoder = Decoder(32, bytes.fromhex('a100204000'), ip=0x401100)
        instruction = next(iter(decoder))
        record = {'kind': 'instruction', 'instruction': x86_source.describe(
            instruction, decoder.get_constant_offsets(instruction))}
        with self.assertRaisesRegex(ValueError, 'numeric'):
            mod_objects.check_instruction_references([record], self.bindings, self.replacements)

    def test_compiled_symbols_are_resolved_by_index_including_locals(self):
        obj = coff.parse_coff(coff_emit.make_object('.text', b'\xc3', [], {'_changed': 0}))
        groups, entries = mod_objects.allocate(obj)
        self.assertEqual(groups['.modtxt'], 1)
        addresses, exported = mod_objects.symbols(obj, entries, {'.modtxt': 0x2400000}, {}, {})
        self.assertEqual(exported['_changed'], 0x2400000)
        self.assertIn(0x2400000, addresses.values())
        contents, highlow, _ = mod_objects.emit_module(obj, groups, entries,
            {'.modtxt': 0x2400000}, addresses, 0x400000)
        self.assertEqual(contents['.modtxt'], bytes([0xc3]))
        self.assertEqual(highlow, [])

    def test_dollar_subsections_follow_coff_linker_order_and_keep_symbol_addresses(self):
        def section(index, name, raw, flags):
            return {'index': index, 'name': name, 'raw_size': len(raw), 'raw': raw,
                    'characteristics': flags, 'relocations': []}

        obj = {'sections': [
            section(1, '.text', bytes([0xc3]), 0x60500020),
            section(2, '.rdata$Z', b'ZZZZ', 0x40500040),
            section(3, '.rdata$A', b'AAAA', 0x40500040),
            section(4, '.rdata$M', b'MMMM', 0x40500040),
            section(5, '.rdata', b'PPPP', 0x40500040),
        ], 'symbols': {
            0: {'name': '_end_marker', 'section': 2, 'storage': 2, 'value': 0},
            1: {'name': '_begin_marker', 'section': 3, 'storage': 2, 'value': 0},
            2: {'name': '_middle_marker', 'section': 4, 'storage': 2, 'value': 0},
            3: {'name': '_plain_marker', 'section': 5, 'storage': 2, 'value': 0},
        }}
        sizes, entries = mod_objects.allocate(obj)
        ordered = [entries[index]['source_section']
                   for index in sorted(entries, key=lambda item: entries[item]['offset'])
                   if entries[index]['group'] == '.modro']
        self.assertEqual(ordered, ['.rdata', '.rdata$A', '.rdata$M', '.rdata$Z'])

        base = 0x2500000
        groups = {'.modtxt': 0x2400000, '.modro': base}
        addresses, exported = mod_objects.symbols(obj, entries, groups, {}, {})
        for symbol_index, section_index in ((0, 2), (1, 3), (2, 4), (3, 5)):
            expected = base + entries[section_index]['offset']
            self.assertEqual(addresses[symbol_index], expected)
            self.assertEqual(exported[obj['symbols'][symbol_index]['name']], expected)
        contents, _, _ = mod_objects.emit_module(obj, sizes, entries, groups, addresses, 0x400000)
        self.assertEqual(contents['.modro'][entries[5]['offset']:entries[5]['offset'] + 4], b'PPPP')
        self.assertEqual(contents['.modro'][entries[3]['offset']:entries[3]['offset'] + 4], b'AAAA')
        self.assertEqual(contents['.modro'][entries[4]['offset']:entries[4]['offset'] + 4], b'MMMM')
        self.assertEqual(contents['.modro'][entries[2]['offset']:entries[2]['offset'] + 4], b'ZZZZ')

    def test_explicit_subsection_alignment_does_not_invent_table_gaps(self):
        for alignment, encoded in ((1, 1), (2, 2), (4, 3), (8, 4), (16, 5)):
            with self.subTest(alignment=alignment):
                obj = coff.parse_coff(coff_emit.make_object('.text', bytes([0xc3]), [], {'_changed': 0}))
                for index, suffix, raw in ((2, 'Z', b'ZZZZ'), (3, 'A', b'AAAA')):
                    obj['sections'].append({'index': index, 'name': '.rdata$' + suffix,
                        'raw_size': len(raw), 'raw': raw, 'relocations': [],
                        'characteristics': 0x40000040 | (encoded << 20)})
                sizes, entries = mod_objects.allocate(obj)
                expected = (4 + alignment - 1) // alignment * alignment
                self.assertEqual(entries[3]['offset'], 0)
                self.assertEqual(entries[2]['offset'], expected)
                self.assertEqual(sizes['.modro'], expected + 4)

    def test_discardable_compiler_debug_metadata_is_not_runtime_storage(self):
        obj = coff.parse_coff(coff_emit.make_object('.text', bytes([0xc3]), [], {'_changed': 0}))
        obj['sections'].append({'index': 2, 'name': '.debug$S', 'raw_size': 4,
                                'raw': bytes(4), 'characteristics': 0x42300040, 'relocations': []})
        sizes, entries = mod_objects.allocate(obj)
        self.assertEqual(sizes, {'.modtxt': 1})
        self.assertNotIn(2, entries)
        obj['sections'][1]['characteristics'] |= 0x20000000
        with self.assertRaises(ValueError):
            mod_objects.allocate(obj)


if __name__ == '__main__':
    unittest.main()
