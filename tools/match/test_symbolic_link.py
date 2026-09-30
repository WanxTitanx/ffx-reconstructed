import unittest
import symbolic_verify as linker


class SymbolLinkTests(unittest.TestCase):
    def setUp(self):
        self.section={'raw':bytes.fromhex('b800000000c3'),'characteristics':0x60000020,
                      'relocations':[{'offset':1,'type':6,'symbol_name':'_sym_00b7c78c','symbol_index':1}]}
        self.expected=[{'offset':1,'type':6,'symbol':'_sym_00b7c78c','addend':0}]

    def test_true_relocation_produces_literal_function(self):
        raw,evidence=linker.link_function(self.section,0x4013a0,6,self.expected,
                                          {'_sym_00b7c78c':0xb7c78c})
        self.assertEqual(raw,bytes.fromhex('b88cc7b700c3'))
        self.assertEqual(evidence[0]['site_va'],0x4013a1)

    def test_wrong_symbol_is_not_accepted_as_same_shape(self):
        self.section['relocations'][0]['symbol_name']='_other'
        with self.assertRaises(ValueError):
            linker.link_function(self.section,0x4013a0,6,self.expected,{'_other':0xb7c78c})

    def test_hidden_addend_is_rejected(self):
        self.section['raw']=bytes.fromhex('b801000000c3')
        with self.assertRaises(ValueError):
            linker.link_function(self.section,0x4013a0,6,self.expected,{'_sym_00b7c78c':0xb7c78c})

    def test_truncated_body_and_missing_relocation_fail(self):
        with self.assertRaises(ValueError):
            linker.link_function(self.section,0x4013a0,5,self.expected,{'_sym_00b7c78c':0xb7c78c})
        self.section['relocations']=[]
        with self.assertRaises(ValueError):
            linker.link_function(self.section,0x4013a0,6,self.expected,{'_sym_00b7c78c':0xb7c78c})


if __name__=='__main__':
    unittest.main()
