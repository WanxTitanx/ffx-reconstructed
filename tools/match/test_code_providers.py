import hashlib
import unittest
import code_providers as providers
import coff_relocations as coff
import coff_emit


class CompiledProviderTests(unittest.TestCase):
    def test_only_complete_defined_function_can_supply_code(self):
        obj=coff.parse_coff(coff_emit.make_object('a0001000',bytes.fromhex('33c0c3'),[],{'_leaf_00401000':0}))
        # Normal assembler labels have type0; mark this fixture as a C function.
        next(iter(obj['symbols'].values()))['type']=0x20
        section=providers.section_for_symbol(obj,'leaf_00401000')
        self.assertEqual(section['raw'],bytes.fromhex('33c0c3'))
        next(iter(obj['symbols'].values()))['value']=1
        with self.assertRaises(ValueError): providers.section_for_symbol(obj,'leaf_00401000')

    def test_wrong_symbol_cannot_reuse_an_equal_body(self):
        obj=coff.parse_coff(coff_emit.make_object('a0001000',b'\xc3',[],{'_other':0}))
        with self.assertRaises(ValueError): providers.section_for_symbol(obj,'leaf_00401000')

    def test_reference_hash_does_not_allow_partial_body(self):
        section={'raw':bytes.fromhex('33c0c3'),'characteristics':0x60000020,'relocations':[]}
        target={'va':0x401000,'size':2,'sha256':hashlib.sha256(bytes.fromhex('33c0')).hexdigest()}
        with self.assertRaises(ValueError): providers.validate_body(section,target,{})


if __name__=='__main__': unittest.main()
