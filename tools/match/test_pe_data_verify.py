import unittest
import pe_data_verify as verifier


class DataBindingTests(unittest.TestCase):
    def test_binding_is_derived_from_real_defined_coff_symbol(self):
        obj={'sections':[{'index':1,'raw_size':8,'name':'d0000100'}],
             'symbols':{0:{'name':'_sym_00400104','section':1,'value':4,'storage':2}}}
        self.assertEqual(verifier.defined_bindings(obj,{'d0000100':0x400100}),
                         {'_sym_00400104':0x400104})

    def test_symbol_outside_declared_section_fails(self):
        obj={'sections':[{'index':1,'raw_size':8,'name':'d0000100'}],
             'symbols':{0:{'name':'_sym_00400120','section':1,'value':32,'storage':2}}}
        with self.assertRaises(ValueError):
            verifier.defined_bindings(obj,{'d0000100':0x400100})

    def test_symbol_label_must_agree_with_placed_address(self):
        obj={'sections':[{'index':1,'raw_size':8,'name':'d0000100'}],
             'symbols':{0:{'name':'_sym_00400106','section':1,'value':4,'storage':2}}}
        with self.assertRaises(ValueError):
            verifier.defined_bindings(obj,{'d0000100':0x400100})


if __name__=='__main__':
    unittest.main()
