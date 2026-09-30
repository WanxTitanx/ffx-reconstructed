import unittest
import coff_emit
import coff_relocations as coff


class CoffWriterTests(unittest.TestCase):
    def test_section_and_symbol_records_survive_parse_and_link(self):
        raw=bytes.fromhex('b800000000c3')
        fixups=[{'offset':1,'type':6,'symbol_name':'_sym_00b7c78c'}]
        obj=coff.parse_coff(coff_emit.make_object('a0001000',raw,fixups,{'_sym_00401000':0}))
        self.assertEqual(obj['sections'][0]['raw'],raw)
        linked,evidence=coff.relocate(obj['sections'][0],0x401000,{'_sym_00b7c78c':0xb7c78c})
        self.assertEqual(linked,bytes.fromhex('b88cc7b700c3'))
        defined=next(s for s in obj['symbols'].values() if s['name']=='_sym_00401000')
        self.assertEqual((defined['section'],defined['value']),(1,0))

    def test_relative_call_uses_real_rel32(self):
        obj=coff.parse_coff(coff_emit.make_object('a0001000',bytes.fromhex('e800000000c3'),
              [{'offset':1,'type':20,'symbol_name':'_sym_00402000'}],{}))
        linked,_=coff.relocate(obj['sections'][0],0x401000,{'_sym_00402000':0x402000})
        self.assertEqual(linked,bytes.fromhex('e8fb0f0000c3'))

    def test_overlapping_relocations_are_rejected(self):
        with self.assertRaises(ValueError):
            coff_emit.make_object('a0001000',bytes(8),[
                {'offset':0,'type':6,'symbol_name':'_a'},
                {'offset':2,'type':6,'symbol_name':'_b'}],{})

    def test_out_of_range_definition_is_rejected(self):
        with self.assertRaises(ValueError):
            coff_emit.make_object('a0001000',bytes(8),[],{'_outside':9})


if __name__=='__main__': unittest.main()
