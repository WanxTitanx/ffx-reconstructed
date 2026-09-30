"""Tamper tests against a real, retained VS2012 compilation from Task 1.

The fixture's original helper snapshots act as that historical package's source
root. They are hashed, not executed. These tests do not promote fixture bytes.
"""
import hashlib
import json
from pathlib import Path, PureWindowsPath
import shutil
import tempfile
import unittest
from unittest import mock
import zipfile

import recovered_build as build

FIXTURE = Path(__file__).resolve().parents[2]/'recon/ffx/recovered/control/math-probe-1-output.zip'


class ReceiptTests(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        self.folder = self.root/'recon/ffx/recovered'
        self.output = self.folder/'build/fixture'
        with zipfile.ZipFile(FIXTURE) as archive:
            for item in archive.infolist():
                name = PureWindowsPath(item.filename)
                if item.filename.endswith(('/', chr(92))):
                    continue
                target = self.output.joinpath(*name.parts)
                target.parent.mkdir(parents=True, exist_ok=True)
                target.write_bytes(archive.read(item))
        package = self.output/'package'
        declaration = json.loads((package/'module.json').read_text())
        self.module = dict(declaration, enabled=True, recipe='recipes/math_vec3.json',
                           build_dir='build/fixture', proof='proofs/math_vec3.json')
        registry = {'schema_version': 1, 'target_sha256': build.TARGET, 'modules': [self.module]}
        (self.folder/'registry.json').write_bytes(build.json_bytes(registry))
        for prefix in ('inputs', 'contracts'):
            for path in (package/prefix).rglob('*'):
                if path.is_file():
                    target = self.folder/path.relative_to(package/prefix)
                    target.parent.mkdir(parents=True, exist_ok=True)
                    target.write_bytes(path.read_bytes())
        (self.folder/'recipes').mkdir()
        shutil.copyfile(package/'recipe.json', self.folder/'recipes/math_vec3.json')
        self.patch = mock.patch.object(build, 'TOOLS', package/'helpers')
        self.patch.start()
        self.addCleanup(self.patch.stop)

    def verify(self):
        return build.read_receipt(self.root, 'math_vec3', self.output, {})

    def receipt(self):
        return json.loads((self.output/'compile.json').read_text())

    def save(self, receipt):
        (self.output/'compile.json').write_bytes(build.json_bytes(receipt))

    def change_output(self, name, transform):
        path = self.output/name
        path.write_bytes(transform(path.read_bytes()))
        receipt = self.receipt()
        receipt['outputs'][name] = hashlib.sha256(path.read_bytes()).hexdigest()
        self.save(receipt)

    def test_real_compiler_receipt_verifies_code_and_actual_loaded_backends(self):
        _, _, receipt, obj = self.verify()
        self.assertEqual(receipt['compiler_version'], '17.00.50727.1')
        self.assertTrue(any(s['name'] == '_FFX_Math_Vec3Normalize' for s in obj['symbols'].values()))
        trace = json.loads((self.output/'compile-trace.json').read_text())
        names = {PureWindowsPath(path).name.lower() for path in trace['loaded_files']}
        self.assertTrue({'cl.exe', 'c1.dll', 'c2.dll'}.issubset(names))

    def test_source_changed_after_compilation_fails(self):
        path = self.folder/'src/math/vec3_normalize.c'
        path.write_text(path.read_text().replace('1.0 / length', '2.0 / length'))
        with self.assertRaises(ValueError):
            self.verify()

    def test_missing_or_replaced_object_fails(self):
        path = self.output/'module.obj'
        raw = path.read_bytes()
        path.unlink()
        with self.assertRaises(ValueError):
            self.verify()
        path.write_bytes(raw[:-1]+bytes([raw[-1]^1]))
        with self.assertRaises(ValueError):
            self.verify()

    def test_old_receipt_cannot_describe_a_failed_compile(self):
        receipt = self.receipt()
        receipt['status'] = 'failed'
        self.save(receipt)
        with self.assertRaises(ValueError):
            self.verify()

    def test_new_output_assertion_is_required(self):
        receipt = self.receipt()
        receipt['invocations'][1]['output_was_absent'] = False
        self.save(receipt)
        with self.assertRaises(ValueError):
            self.verify()

    def test_inherited_flags_cannot_be_accepted(self):
        receipt = self.receipt()
        receipt['inherited_flags_cleared'] = False
        self.save(receipt)
        with self.assertRaises(ValueError):
            self.verify()

    def test_different_compiler_command_or_wrong_dependency_fails(self):
        receipt = self.receipt()
        receipt['invocations'][1]['argv'].append('/FIhidden.h')
        self.save(receipt)
        with self.assertRaises(ValueError):
            self.verify()

    def test_removed_backend_events_cannot_certify_code_generation(self):
        def remove(raw):
            trace = json.loads(raw)
            trace['events'] = [e for e in trace['events'] if not e.get('path', '').lower().endswith('c2.dll')]
            trace['loaded_files'] = {p: h for p, h in trace['loaded_files'].items() if not p.lower().endswith('c2.dll')}
            return build.json_bytes(trace)
        self.change_output('compile-trace.json', remove)
        with self.assertRaises(ValueError):
            self.verify()

    def test_failed_child_process_invalidates_a_successful_root(self):
        def fail(raw):
            trace = json.loads(raw)
            trace['events'].append({'kind': 'process', 'pid': 987654, 'path': 'C:/other.exe', 'sha256': 'a'*64})
            trace['events'].append({'kind': 'exit', 'pid': 987654, 'exit_code': 1})
            trace['loaded_files']['C:/other.exe'] = 'a'*64
            return build.json_bytes(trace)
        self.change_output('compile-trace.json', fail)
        with self.assertRaises(ValueError):
            self.verify()

    def test_hidden_assembly_in_preprocessed_output_is_rejected(self):
        self.change_output('preprocessed.i', lambda raw: raw+b'\nvoid f(){ __asm { nop } }\n')
        with self.assertRaises(ValueError):
            self.verify()

    def test_external_include_is_rejected_even_with_updated_log_hash(self):
        self.change_output('compile.log', lambda raw: raw+b'\nNote: including file: C:/outside/hidden.h\n')
        with self.assertRaises(ValueError):
            self.verify()

    def test_compile_output_metadata_must_describe_the_actual_coff(self):
        receipt = self.receipt()
        receipt['object_summary']['sections'][2]['size'] += 1
        self.save(receipt)
        with self.assertRaises(ValueError):
            self.verify()

    def test_staged_helper_edit_cannot_reuse_its_old_receipt(self):
        path = self.output/'package/helpers/recovered_build.py'
        path.write_bytes(path.read_bytes()+b'\n# edited\n')
        with self.assertRaises(ValueError):
            self.verify()


if __name__ == '__main__':
    unittest.main()
