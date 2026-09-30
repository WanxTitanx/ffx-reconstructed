"""Verify provenance and unique, inventory-backed coverage using real file parsers."""
import contextlib
import copy
import hashlib
import io
import json
import os
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import leaf_reconstruct as leaf


def sha(data):
    return hashlib.sha256(data).hexdigest()


def encode(value):
    return (json.dumps(value, indent=2) + '\n').encode()


def pe_image(code):
    image = bytearray(0x400)
    image[:2] = b'MZ'
    struct.pack_into('<I', image, 0x3c, 0x80)
    image[0x80:0x84] = b'PE\0\0'
    struct.pack_into('<HHIIIHH', image, 0x84, 0x14c, 1, 0, 0, 0, 224, 0x102)
    struct.pack_into('<H', image, 0x98, 0x10b)
    struct.pack_into('<I', image, 0x98 + 28, 0x400000)
    image[0x178:0x180] = b'.text\0\0\0'
    struct.pack_into('<IIII', image, 0x180, 512, 0x1000, 512, 0x200)
    image[0x200:0x200 + len(code)] = code
    image[0x220:0x220 + len(code)] = code
    return bytes(image)


def coff_object(code, symbol='leaf_00401000'):
    name = ('_' + symbol).encode() + b'\0'
    symptr = 60 + len(code)
    header = struct.pack('<HHIIIHH', 0x14c, 1, 0, symptr, 1, 0, 0)
    section = b'.text\0\0\0' + struct.pack('<IIIIIIHHI', 0, 0, len(code), 60, 0, 0, 0, 0, 0x60001020)
    sym = struct.pack('<IIIhHBB', 0, 4, 0, 1, 0x20, 2, 0)
    return header + section + code + sym + struct.pack('<I', 4 + len(name)) + name


class LeafProvenanceTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.package = self.root / 'package'
        self.build = self.package / 'build'
        (self.build / 'inputs').mkdir(parents=True)
        self.project = self.root / 'project'
        (self.project / 'tools/match').mkdir(parents=True)
        self.inventory = self.project / 'tools/match/inventory.tsv'
        self.code = bytes.fromhex('b87b000000c3')
        self.inventory.write_text('start\tend\tsize\tsha256\tname\n'
                                  '0x401000\t0x401006\t6\t' + sha(self.code) + '\tsample\n')
        self.reference = self.root / 'reference.exe'
        self.reference.write_bytes(pe_image(self.code))
        self.source = (b'/* Generated C operations; no embedded reference instruction bytes. */\n'
                       b'typedef char require_x86_pointers[sizeof(void *) == 4 ? 1 : -1];\n'
                       b'__declspec(noinline) unsigned int __cdecl leaf_00401000(void) { return 0x0000007bu; }\n')
        self.jobs = {'target_sha256': sha(self.reference.read_bytes()),
                     'inventory_sha256': sha(self.inventory.read_bytes()),
                     'source_sha256': sha(self.source), 'groups': [{
                         'symbol': 'leaf_00401000',
                         'source': {'return_type': 'unsigned int', 'convention': '__cdecl',
                                    'arguments': 'void', 'body': 'return 0x0000007bu;'},
                         'targets': [{'va': 0x401000, 'size': 6, 'sha256': sha(self.code), 'idb_name': 'sample'}]}]}
        self.names = {'source': 'ffx_leaf.c', 'jobs': 'jobs.json', 'recipe': 'build.bat', 'helper': 'leaf_build.py'}
        contents = {'source': self.source, 'jobs': encode(self.jobs),
                    'recipe': b'@echo off\npy -3 leaf_build.py\n', 'helper': b'# retained helper\n'}
        self.manifest = {'schema_version': 1, 'status': 'complete', 'inputs': {}, 'outputs': {},
                         'compiler_version': '17.00.50727.1', 'compiler_architecture': 'x86', 'files': {}}
        for key, name in self.names.items():
            (self.package / name).write_bytes(contents[key])
            (self.build / 'inputs' / name).write_bytes(contents[key])
            self.manifest['inputs'][key] = {'file': 'inputs/' + name, 'sha256': sha(contents[key])}
            self.manifest['files'][name] = sha(contents[key])
        # Legacy fields allow the old verifier to reach the acceptance bug during RED.
        (self.package / 'leaf_manifest.ps1').write_bytes(b'# legacy manifest\n')
        self.manifest['files']['leaf_manifest.ps1'] = sha(b'# legacy manifest\n')
        for variant in ('O2', 'O1', 'Oy'):
            self.set_object(variant, coff_object(self.code))
        self.log = b'Microsoft (R) C/C++ Optimizing Compiler Version 17.00.50727.1 for x86\n' * 3
        (self.build / 'build.log').write_bytes(self.log)
        self.manifest['outputs']['build_log'] = {'file': 'build.log', 'sha256': sha(self.log)}
        self.manifest['files']['build.log'] = sha(self.log)
        self.manifest_path = self.build / 'build-manifest.json'
        self.write_manifest()
        self.proof = self.package / 'proof.json'
        self.addCleanup(patch.stopall)
        patch.object(leaf.exact, 'EXE_DEFAULT', str(self.reference)).start()
        patch.object(leaf.exact, 'EXE_SHA256', self.jobs['target_sha256']).start()

    def set_object(self, variant, blob):
        name = variant + '.obj'
        (self.build / name).write_bytes(blob)
        self.manifest['outputs'][variant] = {'file': name, 'sha256': sha(blob)}
        self.manifest['files'][name] = sha(blob)

    def write_manifest(self):
        self.manifest_path.write_bytes(encode(self.manifest))

    def write_jobs(self, bind=False):
        data = encode(self.jobs)
        (self.package / 'jobs.json').write_bytes(data)
        if bind:
            (self.build / 'inputs/jobs.json').write_bytes(data)
            self.manifest['inputs']['jobs']['sha256'] = sha(data)
            self.manifest['files']['jobs.json'] = sha(data)
            self.write_manifest()

    def run_verify(self):
        argv = ['leaf_reconstruct.py', 'verify', '--output', str(self.package), '--project', str(self.project)]
        with patch.object(sys, 'argv', argv), contextlib.redirect_stdout(io.StringIO()):
            leaf.main()
        return json.loads(self.proof.read_text())

    def rejected(self, pattern):
        with self.assertRaisesRegex((ValueError, OSError), pattern):
            self.run_verify()
        self.assertFalse(self.proof.exists(), 'invalid evidence must not leave a success proof')

    def test_valid_build_accepts_exact_body(self):
        report = self.run_verify()
        self.assertEqual((report['exact_target_functions'], report['exact_target_code_bytes']), (1, 6))

    def test_proof_records_inventory_and_build_binding(self):
        report = self.run_verify()
        self.assertEqual(report.get('inventory_sha256'), sha(self.inventory.read_bytes()))
        self.assertIs(report.get('build_provenance_verified'), True)

    def test_changed_jobs_fail_with_untouched_manifest(self):
        self.jobs['groups'][0]['targets'][0]['idb_name'] = 'edited after build'
        self.write_jobs()
        self.rejected('jobs|snapshot|manifest')

    def test_duplicate_address_is_rejected_even_when_manifest_is_refreshed(self):
        self.jobs['groups'][0]['targets'].append(copy.deepcopy(self.jobs['groups'][0]['targets'][0]))
        self.write_jobs(bind=True)
        self.rejected('duplicate|overlap')

    def test_duplicate_address_across_groups_is_rejected(self):
        group = copy.deepcopy(self.jobs['groups'][0])
        group['symbol'] = 'leaf_00401020'
        self.jobs['groups'].append(group)
        self.write_jobs(bind=True)
        self.rejected('duplicate|overlap|symbol')

    def test_overlapping_original_ranges_are_rejected(self):
        target = copy.deepcopy(self.jobs['groups'][0]['targets'][0])
        target['va'] += 1
        self.jobs['groups'][0]['targets'].append(target)
        self.write_jobs(bind=True)
        self.rejected('overlap')

    def test_changed_current_inventory_fails_even_if_target_bytes_are_same(self):
        self.inventory.write_bytes(self.inventory.read_bytes() + b'\n')
        self.rejected('inventory')

    def test_target_must_be_an_exact_current_inventory_boundary(self):
        self.jobs['groups'][0]['targets'][0]['va'] = 0x401020
        self.jobs['groups'][0]['symbol'] = 'leaf_00401020'
        self.write_jobs(bind=True)
        self.rejected('inventory|source|symbol')

    def test_stale_source_and_metadata_cannot_reuse_old_build(self):
        changed = self.source.replace(b'0x0000007bu', b'0x0000007cu')
        (self.package / 'ffx_leaf.c').write_bytes(changed)
        self.jobs['source_sha256'] = sha(changed)
        self.jobs['groups'][0]['source']['body'] = 'return 0x0000007cu;'
        self.write_jobs()
        # Simulate the old late hash receipt; the retained inputs must disagree.
        self.manifest['files']['ffx_leaf.c'] = sha(changed)
        self.write_manifest()
        self.rejected('source|jobs|snapshot')

    def test_missing_manifest_rejects_and_invalidates_old_proof(self):
        self.run_verify()
        self.manifest_path.unlink()
        self.rejected('manifest')

    def test_missing_snapshot_fails(self):
        (self.build / 'inputs/jobs.json').unlink()
        self.rejected('jobs|snapshot')

    def test_changed_recipe_fails(self):
        (self.package / 'build.bat').write_bytes(b'@echo off\nexit /b 0\n')
        self.rejected('recipe|build.bat')

    def test_changed_helper_fails(self):
        (self.package / 'leaf_build.py').write_bytes(b'# different helper\n')
        self.rejected('helper|leaf_build.py')

    def test_tampered_snapshot_fails(self):
        (self.build / 'inputs/ffx_leaf.c').write_bytes(b'int changed;\n')
        self.rejected('source|snapshot')

    def test_changed_object_header_fails(self):
        path = self.build / 'O2.obj'
        data = bytearray(path.read_bytes())
        struct.pack_into('<I', data, 4, 99)
        path.write_bytes(data)
        self.rejected('object|O2')

    def test_changed_log_fails(self):
        (self.build / 'build.log').write_bytes(self.log + b'other run\n')
        self.rejected('log')

    def test_manifest_without_complete_status_fails(self):
        self.manifest.pop('status')
        self.write_manifest()
        self.rejected('manifest|complete')

    def test_duplicate_json_keys_fail(self):
        text = encode(self.jobs).decode().replace('"groups":', '"groups": [], "groups":', 1)
        (self.package / 'jobs.json').write_text(text)
        self.rejected('duplicate|jobs')

    def test_invalid_target_types_fail_before_output(self):
        self.jobs['groups'][0]['targets'][0]['size'] = True
        self.write_jobs(bind=True)
        self.rejected('target|size|range')

    def test_distinct_alias_addresses_are_counted_once_each(self):
        self.inventory.write_text(self.inventory.read_text() +
                                  '0x401020\t0x401026\t6\t' + sha(self.code) + '\talias\n')
        self.jobs['inventory_sha256'] = sha(self.inventory.read_bytes())
        self.jobs['groups'][0]['targets'].append({'va': 0x401020, 'size': 6,
                                                  'sha256': sha(self.code), 'idb_name': 'alias'})
        self.write_jobs(bind=True)
        report = self.run_verify()
        self.assertEqual((report['distinct_c_implementations'], report['exact_target_functions'],
                          report['exact_target_code_bytes']), (1, 2, 12))

    def test_codegen_mismatch_has_an_explicit_reason(self):
        for variant in ('O2', 'O1', 'Oy'):
            self.set_object(variant, coff_object(bytes.fromhex('b87c000000c3')))
        self.write_manifest()
        report = self.run_verify()
        self.assertEqual(report['exact_target_functions'], 0)
        self.assertEqual(report['unmatched'][0].get('reason'), 'codegen_mismatch')


@unittest.skipUnless(os.name == 'posix', 'fake compiler uses a POSIX executable')
class LeafBuildTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.package = Path(self.tmp.name)
        self.helper = self.package / 'leaf_build.py'
        self.helper.write_bytes(Path(leaf.__file__).with_name('leaf_build.py').read_bytes())
        self.source = (b'/* Generated C operations; no embedded reference instruction bytes. */\n'
                       b'typedef char require_x86_pointers[sizeof(void *) == 4 ? 1 : -1];\n'
                       b'__declspec(noinline) unsigned int __cdecl leaf_00401000(void) { return 0x0000007bu; }\n')
        self.jobs = {'target_sha256': 'a' * 64, 'inventory_sha256': 'b' * 64,
                     'source_sha256': sha(self.source), 'groups': [{
                         'symbol': 'leaf_00401000', 'source': {
                             'return_type': 'unsigned int', 'convention': '__cdecl',
                             'arguments': 'void', 'body': 'return 0x0000007bu;'},
                         'targets': [{'va': 0x401000, 'size': 6, 'idb_name': 'sample',
                                      'sha256': sha(bytes.fromhex('b87b000000c3'))}]}]}
        self.contents = {'ffx_leaf.c': self.source, 'jobs.json': encode(self.jobs),
                         'build.bat': leaf.BATCH.encode(), 'leaf_build.py': self.helper.read_bytes()}
        for name, data in self.contents.items():
            (self.package / name).write_bytes(data)
        self.build = self.package / 'build'
        self.build.mkdir()
        self.manifest = self.build / 'build-manifest.json'
        self.proof = self.package / 'proof.json'
        self.tools = self.package / 'bin'
        self.tools.mkdir()
        compiler = self.tools / 'cl.exe'
        script = '''import hashlib, os, sys
from pathlib import Path
source = Path(next(arg for arg in sys.argv[1:] if arg.endswith('.c')))
obj = next(arg[3:] for arg in sys.argv[1:] if arg.startswith('/Fo'))
mode = os.environ.get('LEAF_TEST_MODE', '')
version = '19.0.0' if mode == 'wrong-compiler' else '17.00.50727.1'
print('Microsoft (R) C/C++ Optimizing Compiler Version ' + version + ' for x86')
print('consumed-source-sha256=' + hashlib.sha256(source.read_bytes()).hexdigest())
print('consumed-jobs-sha256=' + hashlib.sha256((source.parent/'jobs.json').read_bytes()).hexdigest())
assert not any(key.upper() in ('CL', '_CL_', 'LINK', '_LINK_') for key in os.environ)
if mode == 'fail-second' and obj == 'O1.obj': sys.exit(7)
if mode in ('change-current', 'change-snapshot'):
    name = os.environ['LEAF_TEST_CHANGE']
    changed = Path(os.environ['LEAF_TEST_PACKAGE'])/name if mode == 'change-current' else source.parent/name
    changed.write_bytes(b'changed during compilation')
if mode != 'missing-output':
    Path(obj).write_bytes(bytes.fromhex(OBJECT_HEX))
'''
        script = script.replace('OBJECT_HEX', repr(coff_object(bytes.fromhex('b87b000000c3')).hex()))
        compiler.write_text('#!' + sys.executable + '\n' + script)
        compiler.chmod(0o755)

    def run_build(self, mode='', change='ffx_leaf.c'):
        env = dict(os.environ, PATH=str(self.tools) + os.pathsep + os.environ.get('PATH', ''),
                   CL='/unexpected', _CL_='/unexpected', LEAF_TEST_MODE=mode,
                   LEAF_TEST_CHANGE=change, LEAF_TEST_PACKAGE=str(self.package))
        return subprocess.run([sys.executable, str(self.helper)], env=env, capture_output=True, text=True)

    def seed_old_build(self):
        self.manifest.write_bytes(b'{"status":"complete"}')
        self.proof.write_bytes(b'{"exact_bytes":true}')
        for variant in ('O2', 'O1', 'Oy'):
            (self.build / (variant + '.obj')).write_bytes(b'stale object')

    def assert_failed_build(self, result):
        self.assertNotEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertFalse(self.manifest.exists(), 'failed build retained a success manifest')
        self.assertFalse(self.proof.exists(), 'failed build retained a success proof')

    def test_fresh_build_binds_snapshots_objects_and_captured_log(self):
        result = self.run_build()
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertTrue(self.manifest.is_file(), 'successful build did not publish its manifest')
        manifest = json.loads(self.manifest.read_text())
        self.assertEqual(manifest['status'], 'complete')
        for section in ('inputs', 'outputs'):
            for record in manifest[section].values():
                self.assertEqual(sha((self.build / record['file']).read_bytes()), record['sha256'])
        for name, data in self.contents.items():
            self.assertEqual((self.build / 'inputs' / name).read_bytes(), data)
        self.assertEqual(len(manifest['commands']), 3)
        for command in manifest['commands']:
            self.assertIn('inputs/ffx_leaf.c', command)
        log = (self.build / 'build.log').read_text()
        self.assertEqual(log.count('consumed-source-sha256=' + sha(self.source)), 3)
        self.assertEqual(log.count('consumed-jobs-sha256=' + sha(self.contents['jobs.json'])), 3)
        self.assertEqual(log.count('exit_code=0'), 3)
        self.assertFalse(self.proof.exists(), 'build alone cannot claim byte identity')

    def test_failed_second_compile_invalidates_previous_success(self):
        self.seed_old_build()
        result = self.run_build('fail-second')
        self.assert_failed_build(result)
        self.assertIn('exit_code=7', (self.build / 'build.log').read_text())

    def test_missing_source_invalidates_previous_success(self):
        self.seed_old_build()
        (self.package / 'ffx_leaf.c').unlink()
        self.assert_failed_build(self.run_build())

    def test_missing_jobs_invalidates_previous_success(self):
        self.seed_old_build()
        (self.package / 'jobs.json').unlink()
        self.assert_failed_build(self.run_build())

    def test_current_input_changes_prevent_publication(self):
        for name in self.contents:
            with self.subTest(input=name):
                for original, data in self.contents.items():
                    (self.package / original).write_bytes(data)
                self.seed_old_build()
                result = self.run_build('change-current', name)
                self.assert_failed_build(result)
                self.assertIn('changed during build', result.stderr)

    def test_snapshot_changes_prevent_publication(self):
        for name in self.contents:
            with self.subTest(input=name):
                self.seed_old_build()
                result = self.run_build('change-snapshot', name)
                self.assert_failed_build(result)
                self.assertIn('changed during build', result.stderr)

    def test_missing_compiler_output_cannot_reuse_old_objects(self):
        self.seed_old_build()
        self.assert_failed_build(self.run_build('missing-output'))

    def test_wrong_compiler_cannot_publish_a_manifest(self):
        self.seed_old_build()
        result = self.run_build('wrong-compiler')
        self.assert_failed_build(result)
        self.assertIn('compiler', result.stderr)

    def test_duplicate_jobs_are_rejected_before_compilation(self):
        self.jobs['groups'][0]['targets'] *= 2
        (self.package / 'jobs.json').write_bytes(encode(self.jobs))
        self.seed_old_build()
        result = self.run_build()
        self.assert_failed_build(result)
        self.assertIn('duplicate', result.stderr)
        self.assertNotIn('consumed-source', (self.build / 'build.log').read_text())



if __name__ == '__main__':
    unittest.main()
