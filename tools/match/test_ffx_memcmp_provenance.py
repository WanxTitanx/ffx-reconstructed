"""The byte proof must describe the inputs that produced the candidate image."""
import contextlib
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

import verify_ffx_memcmp as verify


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def pe_image(code, rva):
    image = bytearray(0x400)
    image[:2] = b'MZ'
    struct.pack_into('<I', image, 0x3c, 0x80)
    image[0x80:0x84] = b'PE\x00\x00'
    struct.pack_into('<HHIIIHH', image, 0x84, 0x14c, 1, 0, 0, 0, 224, 0x102)
    struct.pack_into('<H', image, 0x98, 0x10b)
    struct.pack_into('<I', image, 0x98 + 16, rva)
    struct.pack_into('<I', image, 0x98 + 28, 0x400000)
    image[0x178:0x180] = b'.text\x00\x00\x00'
    struct.pack_into('<IIII', image, 0x180, len(code), rva, 512, 0x200)
    image[0x200:0x200 + len(code)] = code
    return bytes(image)


class MemcmpProvenanceTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.package = self.root / 'recon/ffx/byteproof'
        self.output = self.package / 'build_c'
        (self.output / 'inputs').mkdir(parents=True)
        self.current = {
            'source': self.package.parent / 'ffx_memcmp.c',
            'recipe': self.package / 'build_memcmp.bat',
            'helper': self.package / 'build_memcmp.py',
        }
        contents = {
            'source': b'int FFX_memcmp(void) { return 0; }\n',
            'recipe': b'@echo off\r\npy -3 build_memcmp.py\r\n',
            'helper': b'# Build-time provenance helper snapshot.\n',
        }
        self.inputs = {}
        for name, path in self.current.items():
            path.write_bytes(contents[name])
            relative = 'inputs/' + path.name
            (self.output / relative).write_bytes(contents[name])
            self.inputs[name] = {'file': relative, 'sha256': sha256(contents[name])}
        self.code = bytes.fromhex('558bec33c05dc3') + b'\x90' * 105
        self.reference = self.root / 'reference.exe'
        self.reference.write_bytes(pe_image(self.code, 0x1020))
        self.candidate = self.output / 'ffx_memcmp.exe'
        self.candidate.write_bytes(pe_image(self.code, 0x1000))
        self.log = self.output / 'build.log'
        self.log.write_bytes(
            b'Microsoft (R) C/C++ Optimizing Compiler Version 17.00.50727.1 for x86\r\n'
            b'ffx_memcmp.c\r\nGenerating code\r\nFinished generating code\r\n')
        self.manifest = {
            'schema_version': 1, 'status': 'complete',
            'inputs': self.inputs,
            'outputs': {
                'candidate': {'file': self.candidate.name, 'sha256': sha256(self.candidate.read_bytes())},
                'build_log': {'file': self.log.name, 'sha256': sha256(self.log.read_bytes())},
            },
            'compiler_version': '17.00.50727.1', 'compiler_architecture': 'x86',
        }
        self.manifest_path = self.output / 'build-manifest.json'
        self.write_manifest()
        self.proof = self.output / 'proof.json'
        self.addCleanup(patch.stopall)
        patch.object(verify, 'ROOT', self.root).start()
        patch.object(verify.match, 'EXE_DEFAULT', str(self.reference)).start()
        patch.object(verify.match, 'EXE_SHA256', sha256(self.reference.read_bytes())).start()
        patch.object(sys, 'argv', ['verify_ffx_memcmp.py', str(self.candidate)]).start()

    def write_manifest(self):
        self.manifest_path.write_text(json.dumps(self.manifest), encoding='utf-8')

    def run_verify(self):
        with contextlib.redirect_stdout(io.StringIO()):
            return verify.main()

    def assert_rejected(self, pattern):
        with self.assertRaisesRegex((ValueError, OSError), pattern):
            self.run_verify()
        self.assertFalse(self.proof.exists(), 'failure must not mint a byte proof')

    def test_matching_manifest_inputs_and_image_are_accepted(self):
        self.assertEqual(self.run_verify(), 0)
        proof = json.loads(self.proof.read_text())
        self.assertEqual(proof['candidate_image_sha256'], self.manifest['outputs']['candidate']['sha256'])
        self.assertEqual(proof['source_sha256'], self.inputs['source']['sha256'])
        self.assertEqual(proof['candidate_sha256'], proof['reference_sha256'])

    def test_proof_records_the_validated_manifest(self):
        self.assertEqual(self.run_verify(), 0)
        proof = json.loads(self.proof.read_text())
        self.assertEqual(proof.get('build_manifest_sha256'), sha256(self.manifest_path.read_bytes()))
        self.assertIs(proof.get('build_provenance_verified'), True)

    def test_missing_manifest_is_rejected(self):
        self.manifest_path.unlink()
        self.assert_rejected('manifest')

    def test_malformed_manifest_is_rejected(self):
        self.manifest_path.write_text('{invalid JSON', encoding='utf-8')
        self.assert_rejected('manifest')

    def test_incomplete_build_is_rejected(self):
        self.manifest['status'] = 'failed'
        self.write_manifest()
        self.assert_rejected('manifest|complete')

    def test_unknown_manifest_version_is_rejected(self):
        self.manifest['schema_version'] = 99
        self.write_manifest()
        self.assert_rejected('manifest|schema')

    def test_stale_current_source_cannot_claim_an_old_candidate(self):
        self.current['source'].write_bytes(b'int FFX_memcmp(void) { return 123; }\n')
        self.assert_rejected('source')

    def test_stale_current_recipe_is_rejected(self):
        self.current['recipe'].write_bytes(b'@echo off\r\nexit /b 1\r\n')
        self.assert_rejected('recipe')

    def test_stale_current_build_helper_is_rejected(self):
        self.current['helper'].write_bytes(b'raise RuntimeError("different build")\n')
        self.assert_rejected('helper')

    def test_missing_current_source_is_rejected(self):
        self.current['source'].unlink()
        self.assert_rejected('source|ffx_memcmp.c')

    def test_tampered_source_snapshot_is_rejected(self):
        (self.output / self.inputs['source']['file']).write_bytes(b'int changed;\n')
        self.assert_rejected('source')

    def test_missing_recipe_snapshot_is_rejected(self):
        (self.output / self.inputs['recipe']['file']).unlink()
        self.assert_rejected('recipe|build_memcmp.bat')

    def test_manifest_cannot_redirect_snapshot_to_current_source(self):
        self.inputs['source']['file'] = '../../ffx_memcmp.c'
        self.write_manifest()
        self.assert_rejected('source|snapshot|manifest')

    def test_changed_image_header_is_rejected_even_if_function_bytes_match(self):
        image = bytearray(self.candidate.read_bytes())
        struct.pack_into('<I', image, 0x88, 1)  # COFF timestamp, outside the code body.
        self.candidate.write_bytes(image)
        self.assert_rejected('candidate|image')

    def test_changed_build_log_is_rejected(self):
        self.log.write_bytes(self.log.read_bytes() + b'unrelated build\n')
        self.assert_rejected('log')

    def test_wrong_compiler_in_manifest_is_rejected(self):
        self.manifest['compiler_version'] = '19.00.00000.0'
        self.write_manifest()
        self.assert_rejected('compiler')

    def test_byte_difference_still_fails_after_manifest_hash_is_updated(self):
        image = bytearray(self.candidate.read_bytes())
        image[0x200] ^= 1
        self.candidate.write_bytes(image)
        self.manifest['outputs']['candidate']['sha256'] = sha256(image)
        self.write_manifest()
        self.assert_rejected('byte-identical')


@unittest.skipUnless(os.name == 'posix', 'fake executable toolchain uses POSIX scripts')
class BuildManifestTests(unittest.TestCase):
    def setUp(self):
        package = Path(__file__).resolve().parents[2] / 'recon/ffx/byteproof'
        self.assertTrue((package / 'build_memcmp.py').is_file(),
                        'snapshot-based build helper is missing')
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.helper = self.root / 'build_memcmp.py'
        self.helper.write_bytes((package / self.helper.name).read_bytes())
        (self.root / 'build_memcmp.bat').write_bytes((package / 'build_memcmp.bat').read_bytes())
        self.source = self.root / 'ffx_memcmp.c'
        self.source.write_bytes(b'int FFX_memcmp(void) { return 0; }\n')
        self.original_source = self.source.read_bytes()
        self.output = self.root / 'out'
        self.output.mkdir()
        self.manifest_path = self.output / 'build-manifest.json'
        self.proof_path = self.output / 'proof.json'
        self.tools = self.root / 'bin'
        self.tools.mkdir()
        self.image = pe_image(bytes.fromhex('558bec33c05dc3') + b'\x90' * 105, 0x1000)
        script = (
            '#!' + sys.executable + '\n'
            'import hashlib, os, sys\n'
            'from pathlib import Path\n'
            'name = Path(sys.argv[0]).name\n'
            'mode = os.environ.get("MEMCMP_TEST_MODE", "")\n'
            'if name == "cl.exe":\n'
            '    print("Microsoft (R) C/C++ Optimizing Compiler Version 17.00.50727.1 for x86")\n'
            '    source = Path(next(a for a in sys.argv[1:] if a.endswith(".c")))\n'
            '    print("consumed-source-sha256=" + hashlib.sha256(source.read_bytes()).hexdigest())\n'
            '    if mode == "compile-fails": sys.exit(7)\n'
            '    if mode == "change-current": Path(os.environ["MEMCMP_TEST_SOURCE"]).write_bytes(b"changed after snapshot\\n")\n'
            '    if mode == "change-snapshot": source.write_bytes(b"changed compiler input\\n")\n'
            '    Path("ffx_memcmp.obj").write_bytes(b"test object")\n'
            'elif name == "link.exe":\n'
            '    Path("ffx_memcmp.exe").write_bytes(bytes.fromhex(' + repr(self.image.hex()) + '))\n'
            '    Path("ffx_memcmp.map").write_text("test map")\n'
            'else:\n'
            '    print("test disassembly")\n'
        )
        for name in ('cl.exe', 'link.exe', 'dumpbin.exe'):
            tool = self.tools / name
            tool.write_text(script, encoding='utf-8')
            tool.chmod(0o755)

    def run_build(self, mode=''):
        env = dict(os.environ, PATH=str(self.tools) + os.pathsep + os.environ.get('PATH', ''),
                   MEMCMP_TEST_MODE=mode, MEMCMP_TEST_SOURCE=str(self.source))
        return subprocess.run([sys.executable, str(self.helper), '--source', str(self.source),
                               '--output-dir', str(self.output)],
                              env=env, capture_output=True, text=True)

    def seed_old_proof(self):
        self.manifest_path.write_text('{"status": "old build"}', encoding='utf-8')
        self.proof_path.write_text('{"exact_bytes": true}', encoding='utf-8')

    def test_success_captures_compiler_input_and_binds_published_files(self):
        result = self.run_build()
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        manifest = json.loads(self.manifest_path.read_text())
        self.assertEqual(manifest['status'], 'complete')
        self.assertEqual(manifest['compiler_version'], '17.00.50727.1')
        for group in ('inputs', 'outputs'):
            for record in manifest[group].values():
                self.assertEqual(sha256((self.output / record['file']).read_bytes()), record['sha256'])
        self.assertEqual((self.output / 'inputs/ffx_memcmp.c').read_bytes(), self.original_source)
        self.assertIn('inputs/ffx_memcmp.c', ' '.join(manifest['commands'][0]))
        log = (self.output / 'build.log').read_text()
        self.assertIn('consumed-source-sha256=' + sha256(self.original_source), log)
        self.assertFalse(self.proof_path.exists(), 'the build itself must not claim byte identity')

    def test_failed_compile_invalidates_old_manifest_and_proof(self):
        self.seed_old_proof()
        result = self.run_build('compile-fails')
        self.assertNotEqual(result.returncode, 0)
        self.assertFalse(self.manifest_path.exists())
        self.assertFalse(self.proof_path.exists())
        self.assertIn('7', (self.output / 'build.log').read_text())

    def test_missing_source_invalidates_old_manifest_and_proof(self):
        self.seed_old_proof()
        self.source.unlink()
        result = self.run_build()
        self.assertNotEqual(result.returncode, 0)
        self.assertFalse(self.manifest_path.exists())
        self.assertFalse(self.proof_path.exists())

    def test_current_source_changes_during_build_prevent_publication(self):
        result = self.run_build('change-current')
        self.assertNotEqual(result.returncode, 0)
        self.assertFalse(self.manifest_path.exists())
        self.assertIn('source', result.stderr)

    def test_compiler_input_changes_during_build_prevent_publication(self):
        result = self.run_build('change-snapshot')
        self.assertNotEqual(result.returncode, 0)
        self.assertFalse(self.manifest_path.exists())
        self.assertIn('source', result.stderr)


if __name__ == '__main__':
    unittest.main()
