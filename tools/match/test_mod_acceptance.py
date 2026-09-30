"""A matching binary with a false modification receipt cannot be accepted."""
import copy
import unittest
import tempfile
from unittest.mock import patch
from pathlib import Path
import leaf_build as support
try:
    import mod_acceptance
except ModuleNotFoundError:
    mod_acceptance = None


class AcceptanceTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(mod_acceptance, 'independent modification acceptance is missing')

    def test_replay_compares_every_manifest_field(self):
        claimed = {'candidate_sha256': support.digest(b'a'), 'inputs': ['real']}
        forged = dict(claimed, inputs=[])
        with self.assertRaisesRegex(ValueError, 'manifest'):
            mod_acceptance.compare_replay(claimed, b'a', forged, b'a')

    def test_replay_compares_every_image_byte(self):
        with self.assertRaisesRegex(ValueError, 'image'):
            mod_acceptance.compare_replay({}, b'abc', {}, b'abd')

    def test_replay_requires_fresh_compiler_object_identity(self):
        claimed = {'compiler': {'object_sha256': 'a'}}
        rebuilt = {'compiler': {'object_sha256': 'b'}}
        with self.assertRaisesRegex(ValueError, 'manifest'):
            mod_acceptance.compare_replay(claimed, b'abc', rebuilt, b'abc')

    def test_exact_replay_accepts(self):
        self.assertTrue(mod_acceptance.compare_replay({'x': [1]}, b'abc', {'x': [1]}, b'abc'))

    def compare_compiler_pair(self, changed=None):
        compare = getattr(mod_acceptance, 'compare_compiler_outputs', None)
        self.assertIsNotNone(compare, 'literal object/IR replay comparison is missing')
        with tempfile.TemporaryDirectory() as temporary:
            left, right = Path(temporary) / 'left', Path(temporary) / 'right'
            left.mkdir()
            right.mkdir()
            for name in ('module.obj', 'module.ll'):
                (left / name).write_bytes(b'whole artifact including its final byte')
                (right / name).write_bytes((left / name).read_bytes())
            if changed is not None:
                (right / changed).write_bytes((right / changed).read_bytes()[:-1] + b'X')
            return compare(left, right)

    def test_compiler_replay_requires_literal_object_equality(self):
        with self.assertRaisesRegex(ValueError, 'object'):
            self.compare_compiler_pair('module.obj')

    def test_compiler_replay_requires_literal_ir_equality(self):
        with self.assertRaisesRegex(ValueError, 'IR'):
            self.compare_compiler_pair('module.ll')

    def test_literal_compiler_artifacts_match(self):
        self.assertTrue(self.compare_compiler_pair())

    def test_baseline_cache_refresh_precedes_modification_input_snapshot(self):
        class BuildReached(Exception):
            pass
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            cache = root/'cache.json'
            cache.write_text('{"a":1,"b":2}')
            def refresh(*args):
                cache.write_text('{"b":2,"a":1}')
                return {'sha256': 'verified'}
            def capture(*args):
                self.assertEqual(cache.read_text(), '{"b":2,"a":1}',
                                 'modification snapshot captured before baseline cache refresh')
                raise BuildReached()
            with patch.object(mod_acceptance, 'verify_baseline', side_effect=refresh), \
                    patch.object(mod_acceptance, 'build_once', side_effect=capture):
                with self.assertRaises(BuildReached):
                    mod_acceptance.verify(root, root/'package', root/'output')

    def trace_fixture(self):
        output = Path('/tmp/ffx-mod-test')
        runtime = ['/python', '/source/run_source_only.py', '/source/mod_link.py']
        command = ['/clang', '-c', 'source/change.c', '-o', 'module.obj']
        ir_command = ['/clang', '-S', '-emit-llvm', 'source/change.c', '-o', 'module.ll']
        manifest = {'inputs': [{'path': '/source/change.c'}],
                    'compiler': {'command': command, 'dependencies': ['source/change.c'],
                                 'ir_command': ir_command, 'ir_dependencies': ['source/change.c'],
                                 'runtime_libraries': ['/lib/libcompiler.so']}}
        import json
        def execution(pid, argv):
            return str(pid)+' execve('+json.dumps(argv[0])+', '+json.dumps(argv)+', 0x0) = 0'
        def opened(pid, path, flags):
            return str(pid)+' openat(AT_FDCWD, '+json.dumps(path)+', '+flags+') = 3<'+path+'>'
        lines = [execution(10, runtime), execution(11, command),
                 opened(10, '/source/change.c', 'O_RDONLY'),
                 opened(11, '/tmp/ffx-mod-test/compiler/.compile-abc/source/change.c', 'O_RDONLY'),
                 opened(11, '/tmp/ffx-mod-test/compiler/.compile-abc/module.obj', 'O_WRONLY|O_CREAT'),
                 opened(10, '/tmp/ffx-mod-test/compiler/.compile-abc/module.obj', 'O_RDONLY'),
                 opened(10, '/tmp/ffx-mod-test/FFX.exe.tmp', 'O_WRONLY|O_CREAT'),
                 opened(10, '/tmp/ffx-mod-test/manifest.json.tmp', 'O_WRONLY|O_CREAT'),
                 opened(11, '/lib/libcompiler.so', 'O_RDONLY'),
                 execution(12, ir_command),
                 opened(12, '/tmp/ffx-mod-test/compiler/.compile-abc/source/change.c', 'O_RDONLY'),
                 opened(12, '/tmp/ffx-mod-test/compiler/.compile-abc/module.ll', 'O_WRONLY|O_CREAT'),
                 opened(10, '/tmp/ffx-mod-test/compiler/.compile-abc/module.ll', 'O_RDONLY'),
                 opened(12, '/lib/libcompiler.so', 'O_RDONLY')]
        return output, runtime, manifest, lines

    def test_trace_binds_actual_compiler_inputs_and_object_creation(self):
        output, runtime, manifest, lines = self.trace_fixture()
        result = mod_acceptance.bind_trace(chr(10).join(lines).encode(), manifest, output, runtime)
        self.assertTrue(result['fresh_object_created_and_read'])
        self.assertTrue(result.get('fresh_ir_created_and_read', False))
        self.assertEqual(result.get('runtime_libraries_opened'), 1)

    def test_unrelated_compiler_trace_cannot_certify_build(self):
        output, runtime, manifest, lines = self.trace_fixture()
        lines[1] = lines[1].replace('change.c', 'different.c')
        with self.assertRaisesRegex(ValueError, 'exact'):
            mod_acceptance.bind_trace(chr(10).join(lines).encode(), manifest, output, runtime)

    def test_parent_read_of_header_does_not_prove_compiler_consumed_it(self):
        output, runtime, manifest, lines = self.trace_fixture()
        lines[3] = lines[3].replace('11 openat', '10 openat')
        with self.assertRaisesRegex(ValueError, 'consumption'):
            mod_acceptance.bind_trace(chr(10).join(lines).encode(), manifest, output, runtime)

    def test_retained_object_without_compiler_creation_is_rejected(self):
        output, runtime, manifest, lines = self.trace_fixture()
        del lines[4]
        with self.assertRaisesRegex(ValueError, 'fresh'):
            mod_acceptance.bind_trace(chr(10).join(lines).encode(), manifest, output, runtime)

    def test_ir_not_created_by_its_exact_compiler_invocation_is_rejected(self):
        output, runtime, manifest, lines = self.trace_fixture()
        lines = [line for line in lines if not ('module.ll' in line and 'O_WRONLY' in line)]
        with self.assertRaisesRegex(ValueError, 'IR'):
            mod_acceptance.bind_trace(chr(10).join(lines).encode(), manifest, output, runtime)

    def test_unrelated_ir_compiler_command_is_rejected(self):
        output, runtime, manifest, lines = self.trace_fixture()
        lines = [line.replace('source/change.c', 'source/other.c')
                 if line.startswith('12 execve') else line for line in lines]
        with self.assertRaisesRegex(ValueError, 'IR|exact'):
            mod_acceptance.bind_trace(chr(10).join(lines).encode(), manifest, output, runtime)

    def test_parent_library_reads_do_not_prove_compiler_dependency_consumption(self):
        for pid in (11, 12):
            with self.subTest(compiler_pid=pid):
                output, runtime, manifest, lines = self.trace_fixture()
                lines = [line.replace(str(pid) + ' openat', '10 openat')
                         if '/lib/libcompiler.so' in line else line for line in lines]
                with self.assertRaisesRegex(ValueError, 'librar'):
                    mod_acceptance.bind_trace(chr(10).join(lines).encode(), manifest, output, runtime)


if __name__ == '__main__':
    unittest.main()
