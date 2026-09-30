"""Mixed instruction/C/data assembly must cover its declared span exactly."""
import copy
import unittest
from unittest.mock import patch
from iced_x86 import Decoder
import text_program as program
import x86_source


class TextAssemblyTests(unittest.TestCase):
    def instruction(self, raw, ip):
        decoder=Decoder(32,bytes.fromhex(raw),ip=ip)
        ins=decoder.decode()
        return {'kind':'instruction','instruction':x86_source.describe(ins,decoder.get_constant_offsets(ins)),
                'classification':'ida_code'}

    def test_full_instruction_chunk_is_assembled_from_fields(self):
        records=[self.instruction('b801000000',0x401000),self.instruction('c3',0x401005)]
        with patch.object(x86_source,'Decoder',side_effect=AssertionError('build must not decode')):
            raw,fixups,stats=program.assemble_records(records,0x401000,6,{}, {})
        self.assertEqual(raw,bytes.fromhex('b801000000c3'))
        self.assertEqual(fixups,[])
        self.assertEqual(stats['instruction_bytes'],6)

    def test_declared_gap_is_not_silently_filled(self):
        records=[self.instruction('90',0x401001)]
        with self.assertRaises(ValueError):
            program.assemble_records(records,0x401000,2,{}, {})

    def test_overlap_and_partial_extent_are_rejected(self):
        record=self.instruction('90',0x401000)
        for records,size in (([record,record],2),([record],2),([record],0)):
            with self.subTest(size=size):
                with self.assertRaises(ValueError): program.assemble_records(records,0x401000,size,{}, {})

    def test_compiled_provider_uses_object_and_real_fixup(self):
        record={'kind':'coff','ip':0x401000,'size':6,'provider':'compiled:f'}
        provider={'va':0x401000,'size':6,'key':'compiled:f','family':'c_reloc',
                  'section':{'raw':bytes.fromhex('b800000000c3'),
                             'relocations':[{'offset':1,'type':6,'symbol_name':'_sym_00b00000'}]}}
        raw,fixups,stats=program.assemble_records([record],0x401000,6,
              {'_sym_00b00000':0xb00000},{0x401000:provider})
        self.assertEqual(raw,bytes.fromhex('b800000000c3'))
        self.assertEqual(fixups,[{'offset':1,'type':6,'symbol_name':'_sym_00b00000','base_relocation':True}])
        self.assertEqual(stats['c_bytes'],6)

    def test_raw_reference_instruction_payload_is_rejected(self):
        record={'kind':'raw_code','ip':0x401000,'size':1,'values':[0xc3]}
        with self.assertRaises(ValueError): program.assemble_records([record],0x401000,1,{}, {})

    def test_declared_pointer_data_emits_fixup_instead_of_address_bytes(self):
        record={'kind':'data','ip':0x401000,'size':5,'classification':'ida_data',
                'elements':[{'width':4,'symbol':'_sym_00402000'},{'width':1,'values':[7]}]}
        raw,fixups,stats=program.assemble_records([record],0x401000,5,
                                                  {'_sym_00402000':0x402000},{})
        self.assertEqual(raw,b'\0\0\0\0\x07')
        self.assertEqual(fixups[0]['type'],6)
        self.assertEqual(stats['data_bytes'],5)

    def test_wrong_coff_provider_cannot_claim_a_body(self):
        record={'kind':'coff','ip':0x401000,'size':1,'provider':'expected'}
        provider={'key':'different','va':0x401000,'size':1,'family':'c_leaf',
                  'section':{'raw':b'\xc3','relocations':[]}}
        with self.assertRaises(ValueError):
            program.assemble_records([record],0x401000,1,{}, {0x401000:provider})

    def test_padding_is_restricted_to_declared_alignment_values(self):
        record={'kind':'padding','ip':0x401000,'size':4,'value':0xcc,'classification':'ida_alignment'}
        raw,_,stats=program.assemble_records([record],0x401000,4,{}, {})
        self.assertEqual(raw,b'\xcc'*4)
        record['value']=0xc3
        with self.assertRaises(ValueError): program.assemble_records([record],0x401000,4,{}, {})


if __name__=='__main__': unittest.main()
