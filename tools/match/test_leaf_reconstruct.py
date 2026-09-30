import struct
import unittest

import leaf_reconstruct as leaf
import definitive_match as exact


class LeafRecognitionTests(unittest.TestCase):
    def test_float_add_retains_the_unused_third_parameter_slot(self):
        spec = leaf.recognize(bytes.fromhex('558bec8b450cd9008b4508d84514d9185dc3'))
        self.assertIsNotNone(spec)
        self.assertEqual(spec['arguments'], 'float *dst, const float *src, unsigned int unused, float amount')
        self.assertEqual(spec['body'], '*dst = *src + amount;')

    def test_float_sub_tail_call_cannot_be_treated_as_a_leaf(self):
        self.assertIsNone(leaf.recognize(bytes.fromhex('558bec8b450cd9008b4508d86510d9185de9ea76ccff')))

    def test_member_load_preserves_signed_displacement(self):
        spec = leaf.recognize(bytes.fromhex('8b41fcc3'))
        self.assertIsNotNone(spec)
        self.assertIn('p - 4', spec['body'])
        self.assertEqual(spec['convention'], '__fastcall')

    def test_signed_and_unsigned_byte_loads_differ(self):
        signed = leaf.recognize(bytes.fromhex('0fbe4103c3'))
        unsigned = leaf.recognize(bytes.fromhex('0fb64103c3'))
        self.assertIn('signed char', signed['body'])
        self.assertIn('unsigned char', unsigned['body'])

    def test_unresolved_absolute_address_is_not_a_leaf_candidate(self):
        self.assertIsNone(leaf.recognize(bytes.fromhex('a100104000c3')))

    def test_external_call_and_extra_instruction_are_not_accepted(self):
        self.assertIsNone(leaf.recognize(bytes.fromhex('e800000000c3')))
        self.assertIsNone(leaf.recognize(bytes.fromhex('8b4104c390')))

    def test_stack_argument_reader_uses_cdecl(self):
        spec = leaf.recognize(bytes.fromhex('558bec8b45088b400c5dc3'))
        self.assertEqual(spec['convention'], '__cdecl')
        self.assertIn('p + 12', spec['body'])

    def test_constant_is_preserved_as_unsigned_bits(self):
        spec = leaf.recognize(bytes.fromhex('b8efbeaddec3'))
        self.assertIn('0xdeadbeef', spec['body'])


class CoffTests(unittest.TestCase):
    def test_truncated_and_non_x86_objects_fail_closed(self):
        for data in (b'', b'ABCD', struct.pack('<HHIIIHH', 0x8664, 0, 0, 0, 0, 0, 0)):
            with self.subTest(data=data), self.assertRaises(ValueError):
                leaf.coff_functions(data)


class RelocationTests(unittest.TestCase):
    def reference(self, entry=0x3001, block_size=12):
        data = bytearray(0x400)
        data[:2] = b'MZ'
        struct.pack_into('<I', data, 0x3c, 0x80)
        data[0x80:0x84] = b'PE\0\0'
        struct.pack_into('<HHIIIHH', data, 0x84, 0x14c, 2, 0, 0, 0, 224, 0x102)
        struct.pack_into('<H', data, 0x98, 0x10b)
        struct.pack_into('<I', data, 0x98 + 28, 0x400000)
        struct.pack_into('<I', data, 0x98 + 92, 16)
        struct.pack_into('<II', data, 0x98 + 96 + 5 * 8, 0x2000, 12)
        data[0x178:0x180] = b'.text\0\0\0'
        struct.pack_into('<IIII', data, 0x180, 256, 0x1000, 256, 0x200)
        data[0x1a0:0x1a8] = b'.reloc\0\0'
        struct.pack_into('<IIII', data, 0x1a8, 12, 0x2000, 12, 0x300)
        struct.pack_into('<IIHH', data, 0x300, 0x1000, block_size, entry, 0)
        return exact.parse_pe(bytes(data))

    def test_address_immediate_is_not_a_relocation_free_constant(self):
        data, sections = self.reference()
        relocations = leaf.pe_relocations(data, sections)
        self.assertEqual(relocations, [0x401001])
        self.assertTrue(leaf.overlaps_relocation(relocations, 0x401000, 6))
        self.assertTrue(leaf.overlaps_relocation(relocations, 0x401003, 2))
        self.assertFalse(leaf.overlaps_relocation(relocations, 0x401005, 2))

    def test_unknown_relocation_type_is_not_silently_ignored(self):
        data, sections = self.reference(entry=0x5001)
        with self.assertRaises(ValueError):
            leaf.pe_relocations(data, sections)

    def test_incomplete_relocation_block_fails(self):
        data, sections = self.reference(block_size=16)
        with self.assertRaises(ValueError):
            leaf.pe_relocations(data, sections)


if __name__ == '__main__':
    unittest.main()
