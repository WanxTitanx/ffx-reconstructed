"""Source reconstruction tests: instructions, not embedded original byte arrays."""
import copy
import unittest
from unittest.mock import patch
import x86_source as assembler
import coff_relocations as coff
import coff_emit
from iced_x86 import Decoder


class InstructionSourceTests(unittest.TestCase):
    def test_memory_operand_cannot_impersonate_an_immediate_relocation(self):
        record=self.make_record(bytes.fromhex('c70000000000'))
        record['operands'][0]['value']={'symbol':'_target'}
        record['base_relocations']=[{'field':'operand:0','offset':2,'size':4}]
        for relocatable in (False,True):
            with self.subTest(relocatable=relocatable),self.assertRaises(ValueError):
                assembler.encode(record,{'_target':0x501234},relocatable=relocatable)

    def test_immediate_values_cannot_silently_narrow(self):
        for raw,index,value in [('b801000000',1,0x100000001),('b001',1,257),
                                ('83c001',1,255),('c8000000',1,256)]:
            record=self.make_record(bytes.fromhex(raw))
            record['operands'][index]['value']=value
            with self.subTest(raw=raw),self.assertRaises(ValueError):
                assembler.encode(record,{})

    def test_canonical_sign_extension_is_preserved(self):
        record=self.make_record(bytes.fromhex('83c0ff'))
        self.assertEqual(record['operands'][1]['value'],2**64-1)
        self.assertEqual(assembler.encode(record,{})[0],bytes.fromhex('83c0ff'))

    def test_both_real_pointer_operands_agree_before_and_after_linking(self):
        record=self.make_record(bytes.fromhex('c7050020500034126000'),sites=(0x401002,0x401006))
        bindings={'_sym_00502000':0x502000,'_sym_00601234':0x601234}
        direct,_=assembler.encode(record,bindings)
        raw,fixups=assembler.encode(record,bindings,relocatable=True)
        obj=coff.parse_coff(coff_emit.make_object('test',raw,fixups,{}))
        linked,_=coff.relocate(obj['sections'][0],0x401000,bindings)
        self.assertEqual(linked,direct)

    def test_relocation_field_must_name_its_own_immediate(self):
        record=self.make_record(bytes.fromhex('b801005000'),sites=(0x401001,))
        record['base_relocations'][0]['field']='operand:7'
        with self.assertRaises(ValueError):
            assembler.encode(record,{'_sym_00500001':0x500001},relocatable=True)

    def test_memory_displacement_cannot_silently_wrap_address_size(self):
        record=self.make_record(bytes.fromhex('8b45fc'))
        record['memory']['displacement']+=2**32
        with self.assertRaises(ValueError):
            assembler.encode(record,{})

    def make_record(self, data, ip=0x401000, sites=()):
        decoder=Decoder(32,data,ip=ip)
        instruction=decoder.decode()
        self.assertEqual(instruction.len,len(data))
        return assembler.describe(instruction,decoder.get_constant_offsets(instruction),set(sites))

    def test_instruction_fields_roundtrip_including_encoding_choices(self):
        for raw in ('8bec','83c8ff','648b0d00000000','d94510','8da42400000000','660fefc0','f3a5'):
            with self.subTest(raw=raw):
                record=self.make_record(bytes.fromhex(raw))
                encoded,relocations=assembler.encode(record,{},32)
                self.assertEqual(encoded,bytes.fromhex(raw))
                self.assertFalse(relocations)
                self.assertNotIn('raw',record)
                self.assertNotIn('bytes',record)

    def test_symbolic_pointer_gets_a_real_relocation_and_no_reference_word(self):
        record=self.make_record(bytes.fromhex('b88cc7b700'),sites=(0x401001,))
        result,fixups=assembler.encode(record,{'_sym_00b7c78c':0xb7c78c},32,relocatable=True)
        self.assertEqual(result,bytes.fromhex('b800000000'))
        self.assertEqual(fixups,[{'offset':1,'type':6,'symbol_name':'_sym_00b7c78c','base_relocation':True}])
        self.assertEqual(assembler.encode(record,{'_sym_00b7c78c':0xb7c78c},32)[0],bytes.fromhex('b88cc7b700'))

    def test_relative_call_is_linked_from_its_symbol(self):
        record=self.make_record(bytes.fromhex('e805000000'))
        result,fixups=assembler.encode(record,{'_sym_0040100a':0x40100a},32,relocatable=True)
        self.assertEqual(result,bytes.fromhex('e800000000'))
        self.assertEqual(fixups[0]['type'],20)
        self.assertEqual(fixups[0]['symbol_name'],'_sym_0040100a')
        self.assertFalse(fixups[0]['base_relocation'])

    def test_build_consumes_source_fields_without_decoding_reference_bytes(self):
        record=self.make_record(bytes.fromhex('b801000000'))
        record['operands'][1]['value']=123
        with patch.object(assembler,'Decoder',side_effect=AssertionError('decoder forbidden during build')):
            result,_=assembler.encode(record,{},32)
        self.assertEqual(result,bytes.fromhex('b87b000000'))

    def test_missing_symbol_fails(self):
        record=self.make_record(bytes.fromhex('e805000000'))
        with self.assertRaises(ValueError):
            assembler.encode(record,{},32)

    def test_fake_instruction_payload_is_rejected(self):
        record=self.make_record(bytes.fromhex('90'))
        record['raw']='90'
        with self.assertRaises(ValueError):
            assembler.encode(record,{},32)
        record.pop('raw')
        record['code']='DECLAREBYTE'
        with self.assertRaises(ValueError):
            assembler.encode(record,{},32)

    def test_pointer_relocation_cannot_start_inside_an_opcode(self):
        with self.assertRaises(ValueError):
            self.make_record(bytes.fromhex('b88cc7b700'),sites=(0x401000,))


if __name__=='__main__':
    unittest.main()
