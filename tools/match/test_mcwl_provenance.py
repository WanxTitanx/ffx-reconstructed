"""Real native build receipts must reject stale assembly source and objects."""
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch
import mcwl_build

ROOT=Path(__file__).resolve().parents[2]


class McwlBuildTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root=Path(self.temp.name)
        self.source=self.root/'recon/ffx/phyre_memcmp_with_length.S'
        self.harness=self.root/'recon/ffx/byteproof/mcwl_semantics.c'
        self.harness.parent.mkdir(parents=True)
        for destination in (self.source,self.harness):
            destination.write_bytes((ROOT/destination.relative_to(self.root)).read_bytes())
        self.output=self.harness.parent/'build'

    def test_fresh_build_binds_inputs_and_actual_semantic_run(self):
        receipt=mcwl_build.build(self.root,self.output)
        _manifest,outputs,_seen=mcwl_build.read_bundle(self.root,self.output)
        self.assertEqual(receipt['semantic_checks'],87645)
        self.assertEqual(len(outputs['mcwl.bin']),144)

    def test_changed_source_cannot_acquire_an_old_build_receipt(self):
        mcwl_build.build(self.root,self.output)
        self.source.write_text('.code32\n.text\nmov $123,%eax\nret\n')
        with self.assertRaisesRegex(ValueError,'source|snapshot'):
            mcwl_build.read_bundle(self.root,self.output)

    def test_changed_coff_header_is_rejected(self):
        mcwl_build.build(self.root,self.output)
        path=self.output/'mcwl.obj'
        raw=bytearray(path.read_bytes())
        raw[4]^=1
        path.write_bytes(raw)
        with self.assertRaisesRegex(ValueError,'mcwl.obj|artifact'):
            mcwl_build.read_bundle(self.root,self.output)

    def test_failed_rebuild_invalidates_old_success(self):
        mcwl_build.build(self.root,self.output)
        (self.output/'proof.json').write_text('{"exact_bytes":true}')
        with patch.object(mcwl_build.subprocess,'run',side_effect=OSError('compiler failed')):
            with self.assertRaises(OSError):
                mcwl_build.build(self.root,self.output)
        self.assertFalse((self.output/'build-manifest.json').exists())
        self.assertFalse((self.output/'proof.json').exists())

    def test_source_mutation_during_assembly_prevents_receipt(self):
        original_run=subprocess.run
        def mutate(command,*args,**kwargs):
            result=original_run(command,*args,**kwargs)
            if '--32' in command:
                self.source.write_text(self.source.read_text()+'\n# changed\n')
            return result
        with patch.object(mcwl_build.subprocess,'run',side_effect=mutate):
            with self.assertRaisesRegex(ValueError,'changed'):
                mcwl_build.build(self.root,self.output)
        self.assertFalse((self.output/'build-manifest.json').exists())


if __name__=='__main__': unittest.main()
