import unittest
import subprocess
import tempfile
import contextlib
import hashlib
import io
import json
from pathlib import Path
import coff_relocations as coff
import pe_data_source as data_source


class DataDeclarationTests(unittest.TestCase):
    def test_native_build_retains_source_and_generator_snapshots(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp)
            (root/'sources').mkdir()
            text=data_source.render_chunk('d0000100',0x400100,b'abcd',{},set()).encode()
            generator=Path(data_source.__file__).read_bytes()
            chunk={'source':'sources/d0000100.S','section':'d0000100','source_sha256':hashlib.sha256(text).hexdigest()}
            plan={'generator_sha256':hashlib.sha256(generator).hexdigest(),'chunks':[chunk]}
            (root/chunk['source']).write_bytes(text)
            (root/'generator.py').write_bytes(generator)
            (root/'plan.json').write_text(json.dumps(plan))
            with contextlib.redirect_stdout(io.StringIO()):
                manifest=data_source.build(root)
            self.assertEqual((root/'build/inputs'/chunk['source']).read_bytes(),text)
            self.assertEqual((root/'build/inputs/generator.py').read_bytes(),generator)
            self.assertEqual(manifest['generator_sha256'],plan['generator_sha256'])
            self.assertEqual(manifest['build_log_sha256'],hashlib.sha256((root/'build/build.log').read_bytes()).hexdigest())

    def test_direct_coff_assembly_emits_a_real_dir32_record(self):
        text=data_source.render_chunk('d0000100',0x400100,bytes.fromhex('00104000'),
                                      {0x400100:0x401000},{0x400100})
        with tempfile.TemporaryDirectory() as tmp:
            source=Path(tmp)/'input.S'
            output=Path(tmp)/'data.obj'
            source.write_text(text)
            result=subprocess.run(['clang','--target=i686-pc-windows-msvc','-c','-x','assembler',
                                   str(source),'-o',str(output)],capture_output=True,text=True)
            self.assertEqual(result.returncode,0,result.stderr)
            obj=coff.parse_coff(output.read_bytes())
            section=next(s for s in obj['sections'] if s['name']=='d0000100')
            self.assertEqual([(r['offset'],r['type'],r['symbol_name']) for r in section['relocations']],
                             [(0,coff.DIR32,'_sym_00401000')])

    def test_pointer_field_is_symbolic_and_payload_remains_data(self):
        text=data_source.render_chunk('seg0',0xb00000,b'ABCD'+bytes.fromhex('00104000'),
                                      {0xb00004:0x401000},{0xb00000,0xb00005})
        self.assertIn('.long _sym_00401000',text)
        self.assertIn('_sym_00b00000:',text)
        self.assertIn('.set _sym_00b00005, . + 1',text)
        self.assertNotIn('.byte 0x00, 0x10, 0x40, 0x00',text)

    def test_crossing_pointer_field_is_rejected(self):
        with self.assertRaises(ValueError):
            data_source.render_chunk('seg0',0xb00000,b'12345',{0xb00002:0x401000},set())

    def test_overlapping_pointer_fields_are_rejected(self):
        with self.assertRaises(ValueError):
            data_source.render_chunk('seg0',0xb00000,b'12345678',
                                      {0xb00000:0x401000,0xb00002:0x402000},set())

    def test_chunking_never_splits_a_relocation_word(self):
        spans=data_source.chunk_ranges(0xb00000,20,[0xb00006],8)
        self.assertEqual(spans,[(0xb00000,6),(0xb00006,8),(0xb0000e,6)])


if __name__=='__main__':
    unittest.main()
