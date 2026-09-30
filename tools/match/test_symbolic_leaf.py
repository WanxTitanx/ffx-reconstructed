import unittest

import symbolic_leaf as symbolic


class SymbolicSourceTests(unittest.TestCase):
    def test_address_return_uses_external_symbol(self):
        spec = symbolic.source_spec(bytes.fromhex('b88cc7b700c3'), [1], 'sym_00b7c78c')
        self.assertEqual(spec['body'], 'return sym_00b7c78c;')
        self.assertNotIn('0x00b7c78c', spec['body'])
        self.assertEqual(spec['return_type'], 'const void *')

    def test_vtable_assignment_has_a_pointer_initializer(self):
        spec = symbolic.source_spec(bytes.fromhex('c701ccd9b000c3'), [2], 'sym_00b0d9cc')
        self.assertEqual(spec['convention'], '__fastcall')
        self.assertEqual(spec['body'], '*(const void **)(p) = sym_00b0d9cc;')

    def test_wrong_relocation_offset_is_rejected(self):
        with self.assertRaises(ValueError):
            symbolic.source_spec(bytes.fromhex('b88cc7b700c3'), [2], 'sym_00b7c78c')

    def test_unrecorded_pointer_constant_is_rejected(self):
        with self.assertRaises(ValueError):
            symbolic.source_spec(bytes.fromhex('b88cc7b700c3'), [], 'sym_00b7c78c')

    def test_member_offset_is_not_discarded(self):
        spec = symbolic.source_spec(bytes.fromhex('c74104ccd9b000c3'), [3], 'sym_00b0d9cc')
        self.assertEqual(spec['body'], '*(const void **)(p + 4) = sym_00b0d9cc;')

    def test_extra_side_effect_is_rejected(self):
        with self.assertRaises(ValueError):
            symbolic.source_spec(bytes.fromhex('c701ccd9b00040c3'), [2], 'sym_00b0d9cc')


if __name__ == '__main__':
    unittest.main()
