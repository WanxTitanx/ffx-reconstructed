"""COFF admission fixtures test failure modes, not real compilation or coverage."""
import copy
import hashlib
import struct
import unittest
from unittest import mock
from pathlib import Path

import coff_emit
import coff_relocations as coff
try:
    import recovered_providers as providers
except ModuleNotFoundError:
    providers = None


def object_fixture(raw=b'\x55\x8b\xec\x5d\xc3', relocations=None, name='_fixture_long_symbol_name'):
    data = bytearray(coff_emit.make_object('.text', raw, relocations or [], {name: 0}))
    parsed = coff.parse_coff(bytes(data))
    for symbol in parsed['symbols'].values():
        if symbol['name'] == name:
            struct.pack_into('<H', data, symbol['raw_offset']+14, 0x20)
    return coff.parse_coff(bytes(data))


class AdmissionTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(providers, 'recovered COFF provider admission is missing')

    def test_full_long_symbol_selects_the_whole_executable_section(self):
        obj = object_fixture()
        section = providers.select_section(obj, '_fixture_long_symbol_name', 5)
        self.assertEqual(section['raw'], b'\x55\x8b\xec\x5d\xc3')
        with self.assertRaises(ValueError):
            providers.select_section(obj, '_fixture_long', 5)

    def test_wrong_size_internal_entry_and_duplicate_symbol_are_rejected(self):
        obj = object_fixture()
        with self.assertRaises(ValueError):
            providers.select_section(obj, '_fixture_long_symbol_name', 4)
        symbol = next(s for s in obj['symbols'].values() if s['section'] > 0)
        symbol['value'] = 1
        with self.assertRaises(ValueError):
            providers.select_section(obj, symbol['name'], 5)
        symbol['value'] = 0
        obj['symbols'][99] = dict(symbol, index=99)
        with self.assertRaises(ValueError):
            providers.select_section(obj, symbol['name'], 5)

    def test_another_function_or_alias_cannot_share_the_promoted_section(self):
        obj = object_fixture()
        symbol = next(iter(obj['symbols'].values()))
        obj['symbols'][99] = dict(symbol, name='_alias', index=99)
        with self.assertRaises(ValueError):
            providers.select_section(obj, '_fixture_long_symbol_name', 5)

    def test_data_array_cannot_be_admitted_as_a_function(self):
        obj = object_fixture()
        obj['sections'][0]['characteristics'] = 0x40000040
        with self.assertRaises(ValueError):
            providers.select_section(obj, '_fixture_long_symbol_name', 5)

    def test_rel32_keeps_compiler_addend_and_renames_only_symbol_identity(self):
        obj = object_fixture(b'\xe8\x04\x00\x00\x00\xc3',
                             [{'offset': 1, 'type': coff.REL32, 'symbol_name': '_callee'}])
        section = providers.select_section(obj, '_fixture_long_symbol_name', 6)
        expected, _ = coff.relocate(section, 0x401000, {'_callee': 0x402000})
        result = providers.resolve_section(section, 0x401000, {'_callee': '_sym_00402000'},
                                           hashlib.sha256(expected).hexdigest(), [])
        self.assertEqual(result['raw'], section['raw'])
        self.assertEqual(result['relocations'][0]['symbol_name'], '_sym_00402000')
        self.assertEqual(coff.relocate(result, 0x401000, {'_sym_00402000': 0x402000})[0], expected)
        self.assertEqual(section['relocations'][0]['symbol_name'], '_callee')

    def test_literal_pointer_without_highlow_is_rejected_even_when_bytes_match(self):
        raw = b'\xb8'+struct.pack('<I', 0x500000)+b'\xc3'
        section = object_fixture(raw)['sections'][0]
        with self.assertRaises(ValueError):
            providers.resolve_section(section, 0x401000, {}, hashlib.sha256(raw).hexdigest(), [1])

    def test_dir32_site_must_equal_original_site_and_rebases_normally(self):
        section = object_fixture(b'\xb8'+bytes(4)+b'\xc3',
            [{'offset': 1, 'type': coff.DIR32, 'symbol_name': '_global'}])['sections'][0]
        expected = b'\xb8'+struct.pack('<I', 0x500000)+b'\xc3'
        resolved = providers.resolve_section(section, 0x401000, {'_global': '_sym_00500000'},
                                             hashlib.sha256(expected).hexdigest(), [1])
        rebased = coff.relocate(resolved, 0x10001000, {'_sym_00500000': 0x10100000}, 0x10000000)[0]
        self.assertEqual(struct.unpack_from('<I', rebased, 1)[0], 0x10100000)
        with self.assertRaises(ValueError):
            providers.resolve_section(section, 0x401000, {'_global': '_sym_00500000'},
                                      hashlib.sha256(expected).hexdigest(), [])

    def test_missing_unused_and_noncanonical_bindings_fail(self):
        section = object_fixture(b'\xe8'+bytes(4)+b'\xc3',
            [{'offset': 1, 'type': coff.REL32, 'symbol_name': '_callee'}])['sections'][0]
        for bindings in ({}, {'_callee': '_sym_00402000', '_unused': '_sym_00403000'},
                         {'_callee': 0x402000}):
            with self.subTest(bindings=bindings), self.assertRaises(ValueError):
                providers.resolve_section(section, 0x401000, bindings, 'a'*64, [])

    def test_changed_compiler_constant_is_rejected_without_an_assembly_fallback(self):
        original = b'\xb8\x07\x00\x00\x00\xc3'
        edited = b'\xb8\x08\x00\x00\x00\xc3'
        section = object_fixture(edited)['sections'][0]
        with self.assertRaises(ValueError):
            providers.resolve_section(section, 0x401000, {}, hashlib.sha256(original).hexdigest(), [])


class IntegrationTests(unittest.TestCase):
    def test_admission_error_propagates_instead_of_returning_old_assembly_providers(self):
        import code_providers
        self.assertIsNotNone(providers)
        with mock.patch.object(providers, 'load', side_effect=ValueError('recovered provider rejected')):
            with self.assertRaisesRegex(ValueError, 'recovered provider rejected'):
                code_providers.load(Path(__file__).resolve().parents[2])

    def test_recovered_family_cannot_overwrite_an_existing_c_provider(self):
        import code_providers
        with mock.patch.object(providers, 'load', return_value={0x401020: {'va': 0x401020, 'size': 112}}):
            with self.assertRaisesRegex(ValueError, 'overwrite|overlap|duplicate'):
                code_providers.load(Path(__file__).resolve().parents[2])


if __name__ == '__main__':
    unittest.main()
