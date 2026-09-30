import hashlib
import json
import tempfile
import unittest
from pathlib import Path
import text_build as builder
import x86_source
from iced_x86 import Decoder


class SourcePlanTests(unittest.TestCase):
    def instruction(self):
        decoder=Decoder(32,bytes.fromhex('33c0'),ip=0x401000)
        instruction=decoder.decode()
        return {'kind':'instruction','classification':'ida_code',
                'instruction':x86_source.describe(instruction,decoder.get_constant_offsets(instruction))}

    def test_code_range_accepts_explicit_instruction(self):
        check=builder.ClassificationGuard([(0x401000,0x401002,'code')],[],[],{})
        check.validate(self.instruction(),{})

    def test_code_cannot_be_laundered_as_data_with_the_same_bytes(self):
        check=builder.ClassificationGuard([(0x401000,0x401002,'code')],[],[],{})
        record={'kind':'data','ip':0x401000,'size':2,'classification':'ida_data',
                'elements':[{'width':1,'values':[0x33,0xc0]}]}
        with self.assertRaisesRegex(ValueError,'classification|code'):
            check.validate(record,{})

    def test_data_range_does_not_accept_instruction_record(self):
        check=builder.ClassificationGuard([(0x401000,0x401002,'data')],[],[],{})
        with self.assertRaises(ValueError): check.validate(self.instruction(),{})

    def test_data_record_cannot_cross_a_native_kind_boundary(self):
        check=builder.ClassificationGuard([(0x401000,0x401001,'data'),(0x401001,0x401002,'code')],[],[],{})
        record={'kind':'data','ip':0x401000,'size':2,'classification':'ida_data',
                'elements':[{'width':1,'values':[0x33,0xc0]}]}
        with self.assertRaises(ValueError): check.validate(record,{})

    def test_unknown_range_requires_a_documented_override(self):
        check=builder.ClassificationGuard([(0x401000,0x401002,'unknown')],[],[],{})
        record={'kind':'padding','ip':0x401000,'size':2,'classification':'reviewed_alignment','value':0x90}
        with self.assertRaises(ValueError): check.validate(record,{})

    def test_unknown_selector_override_rejects_opcode_bytes(self):
        override={'va':0x401000,'size':2,'reason':'reviewed small selector table; all scalar values 0..2'}
        check=builder.ClassificationGuard([(0x401000,0x401002,'unknown')],[],[override],{})
        record={'kind':'data','ip':0x401000,'size':2,'classification':'reviewed_selector_data',
                'elements':[{'width':1,'values':[0x33,0xc0]}]}
        with self.assertRaises(ValueError): check.validate(record,{})

    def test_known_compiled_provider_cannot_be_replaced_with_a_data_blob(self):
        provider={0x401000:{'size':2,'key':'c_leaf:test'}}
        check=builder.ClassificationGuard([(0x401000,0x401002,'code')],[],[],provider)
        record={'kind':'data','ip':0x401000,'size':2,'classification':'ida_data',
                'elements':[{'width':1,'values':[0x33,0xc0]}]}
        with self.assertRaises(ValueError): check.validate(record,{})

    def test_changed_source_is_not_accepted_with_an_old_digest(self):
        with tempfile.TemporaryDirectory() as tmp:
            path=Path(tmp)/'source.jsonl.gz'
            path.write_bytes(b'changed')
            with self.assertRaises(ValueError):
                builder.read_verified(path,hashlib.sha256(b'original').hexdigest())

    def test_declared_label_must_have_an_actual_mapped_owner(self):
        layout={'image_base':0x400000,'optional_header':{'size_of_headers':1024},
                'sections':[{'name':'.text','virtual_address':0x1000,'virtual_size':16,'raw_size':16}]}
        symbol={'name':'_sym_00401008','va':0x401008,'owner':'.text','offset':8,'file_backed':True}
        self.assertEqual(builder.layout_bindings([symbol],layout),{'_sym_00401008':0x401008})
        symbol['offset']=4
        with self.assertRaises(ValueError): builder.layout_bindings([symbol],layout)
        symbol['offset']=8
        symbol['owner']='.data'
        with self.assertRaises(ValueError): builder.layout_bindings([symbol],layout)

    def test_duplicate_labels_and_undefined_virtual_ranges_fail(self):
        layout={'image_base':0x400000,'optional_header':{'size_of_headers':1024},
                'sections':[{'name':'.text','virtual_address':0x1000,'virtual_size':16,'raw_size':16}]}
        symbol={'name':'_sym_00401008','va':0x401008,'owner':'.text','offset':8,'file_backed':True}
        with self.assertRaises(ValueError): builder.layout_bindings([symbol,symbol],layout)
        symbol.update(name='_sym_00401020',va=0x401020,offset=32)
        with self.assertRaises(ValueError): builder.layout_bindings([symbol],layout)

    def test_header_symbol_is_bound_to_the_emitted_header(self):
        layout={'image_base':0x400000,'optional_header':{'size_of_headers':1024},'sections':[]}
        symbol={'name':'_sym_00400000','va':0x400000,'owner':'headers','offset':0}
        self.assertEqual(builder.layout_bindings([symbol],layout),{'_sym_00400000':0x400000})


if __name__=='__main__': unittest.main()
