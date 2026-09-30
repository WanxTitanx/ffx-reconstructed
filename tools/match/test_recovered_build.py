"""Closed C/C++ packages and fresh compiler receipts; no coverage from fixtures."""
import copy
import json
from pathlib import Path
import tempfile
import unittest

try:
    import recovered_build as build
except ModuleNotFoundError:
    build = None

TARGET = '78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced'


def recipe_fixture():
    return {'schema_version': 1, 'language': 'c', 'source': 'src/example.c',
            'files': ['src/example.c', 'include/value.h'], 'include_dirs': ['include'],
            'flags': ['/O2', '/MD', '/Oy-', '/Oi', '/arch:IA32', '/GS-'],
            'intrinsics': [], 'libraries': [],
            'toolchain': {'version': '17.00.50727.1', 'architecture': 'x86',
                          'files': {name: 'a'*64 for name in
                                    ('cl.exe', 'c1.dll', 'c1xx.dll', 'c2.dll')}}}


class PackageTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(build, 'recovered compiler package path is missing')
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        self.package = self.root/'recon/ffx/recovered'
        for name in ('src', 'include', 'recipes', 'contracts'):
            (self.package/name).mkdir(parents=True)
        (self.package/'src/example.c').write_text('#include "value.h"\nint example(int x) { return x + VALUE; }\n')
        (self.package/'include/value.h').write_text('#define VALUE 3\n')
        self.recipe = recipe_fixture()
        self.module = {'id': 'example', 'enabled': True, 'language': 'c',
                       'recipe': 'recipes/example.json', 'build_dir': 'build/example/a',
                       'proof': 'proofs/example.json', 'functions': [
                           {'va': 0x401000, 'size': 8, 'symbol': '_example',
                            'contract': 'contracts/00401000.json', 'bindings': {}}]}
        self.registry = {'schema_version': 1, 'target_sha256': TARGET, 'modules': [self.module]}
        (self.package/'contracts/00401000.json').write_text(json.dumps(
            {'schema_version': 1, 'va': 0x401000, 'size': 8, 'symbol': '_example',
             'abi': 'cdecl: int(int)', 'reference_sha256': 'b'*64}))
        self.save()

    def save(self):
        (self.package/'registry.json').write_text(json.dumps(self.registry))
        (self.package/'recipes/example.json').write_text(json.dumps(self.recipe))

    def test_stage_binds_every_declared_file_and_build_helper(self):
        result = build.stage(self.root, 'example', self.root/'staged')
        self.assertEqual(set(result['sources']), set(self.recipe['files']))
        self.assertIn('recovered_build.py', result['helpers'])
        self.assertIn('recovered_win32.py', result['helpers'])
        self.assertIn('coff_relocations.py', result['helpers'])
        self.assertEqual((self.root/'staged/inputs/src/example.c').read_bytes(),
                         (self.package/'src/example.c').read_bytes())

    def test_stage_never_reuses_a_nonempty_output(self):
        output = self.root/'staged'
        output.mkdir()
        (output/'old.obj').write_bytes(b'old')
        with self.assertRaises(ValueError):
            build.stage(self.root, 'example', output)
        self.assertEqual((output/'old.obj').read_bytes(), b'old')

    def test_undeclared_include_is_rejected(self):
        self.recipe['files'].remove('include/value.h')
        self.save()
        with self.assertRaises(ValueError):
            build.stage(self.root, 'example', self.root/'staged')

    def test_absolute_parent_and_macro_includes_are_rejected(self):
        for line in ('#include "../../secret.h"', '#include "/etc/passwd"',
                     '#define H "value.h"\n#include H', '#include_next "value.h"'):
            with self.subTest(line=line):
                (self.package/'src/example.c').write_text(line+'\nint example(void){return 1;}')
                with self.assertRaises(ValueError):
                    build.stage(self.root, 'example', self.root/('staged'+str(len(line))))

    def test_source_symlink_and_hardlink_are_rejected(self):
        path = self.package/'src/example.c'
        saved = path.read_bytes()
        path.unlink()
        outside = self.root/'outside.c'
        outside.write_bytes(saved)
        path.symlink_to(outside)
        with self.assertRaises(ValueError):
            build.stage(self.root, 'example', self.root/'sym')
        path.unlink()
        path.hardlink_to(outside)
        with self.assertRaises(ValueError):
            build.stage(self.root, 'example', self.root/'hard')

    def test_duplicate_or_overlapping_active_targets_are_rejected(self):
        second = copy.deepcopy(self.module)
        second['id'] = 'other'
        for va in (0x401000, 0x401004):
            second['functions'][0]['va'] = va
            self.registry['modules'] = [self.module, second]
            self.save()
            with self.subTest(va=va), self.assertRaises(ValueError):
                build.read_registry(self.root, {})

    def test_wrong_target_and_boolean_geometry_are_rejected(self):
        self.registry['target_sha256'] = '0'*64
        self.save()
        with self.assertRaises(ValueError):
            build.read_registry(self.root, {})
        self.registry['target_sha256'] = TARGET
        self.module['functions'][0]['size'] = True
        self.save()
        with self.assertRaises(ValueError):
            build.read_registry(self.root, {})

    def test_recipe_rejects_compiler_replacement_ltcg_and_implicit_inputs(self):
        for flag in ('/B1else.exe', '@options.rsp', '/FIhidden.h', '/GL', '/Fohidden.obj', '/I../headers'):
            invalid = recipe_fixture()
            invalid['flags'].append(flag)
            with self.subTest(flag=flag), self.assertRaises(ValueError):
                build.validate_recipe(invalid)

    def test_recipe_rejects_wrong_compiler_or_missing_backend_hash(self):
        invalid = recipe_fixture()
        invalid['toolchain']['version'] = '19.0'
        with self.assertRaises(ValueError):
            build.validate_recipe(invalid)
        invalid = recipe_fixture()
        del invalid['toolchain']['files']['c2.dll']
        with self.assertRaises(ValueError):
            build.validate_recipe(invalid)

    def test_environment_removes_all_inherited_compiler_flags_case_insensitively(self):
        env = build.clean_environment({'PATH': 'compiler', 'cl': '/DUNSAFE', '_CL_': '/FIhidden',
                                       'Link': '/out:x', '_LINK_': 'x', 'KEEP': 'ok'})
        self.assertFalse({'CL', '_CL_', 'LINK', '_LINK_'} & {k.upper() for k in env})
        self.assertEqual(env['KEEP'], 'ok')

    def test_inline_assembly_and_executable_data_directives_are_rejected(self):
        for source in ('int f(){__asm {nop} return 0;}',
                       '__declspec(naked) int f(){return 0;}',
                       '#pragma code_seg(".text")\nint f(){return 0;}',
                       '#pragma section(".code",execute)\nchar code[]={1,2};',
                       'int f(){_emit(0x90);return 0;}',
                       '#pragma comment(lib,"hidden.lib")\nint f(){return 0;}'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                build.check_source(source, [])

    def test_ordinary_comments_and_strings_do_not_look_like_assembly(self):
        build.check_source('/* no __asm */ const char *s="naked _emit"; int f(){return 0;}', [])

    def test_unlisted_intrinsic_is_rejected(self):
        with self.assertRaises(ValueError):
            build.check_source('#pragma intrinsic(sqrt)\ndouble f(double x){return sqrt(x);}', [])
        build.check_source('#pragma intrinsic(sqrt)\ndouble f(double x){return sqrt(x);}', ['sqrt'])

    def test_staged_source_tampering_invalidates_the_package(self):
        output = self.root/'staged'
        build.stage(self.root, 'example', output)
        (output/'inputs/include/value.h').write_text('#define VALUE 99\n')
        with self.assertRaises(ValueError):
            build.read_stage(output)

    def test_debugger_structures_follow_the_host_pointer_width(self):
        import ctypes
        import recovered_win32
        self.assertEqual(ctypes.sizeof(recovered_win32.DebugEvent),
                         176 if ctypes.sizeof(ctypes.c_void_p) == 8 else 96)

    def test_compiler_include_receipt_rejects_a_real_external_path(self):
        with self.assertRaises(ValueError):
            build.include_dependencies(b'Note: including file: C:/outside/hidden.h\n', self.recipe, 'C:/build')
        log = b'Note: including file: C:/build/package/inputs/include/value.h\n'
        self.assertEqual(build.include_dependencies(log, self.recipe, 'C:/build'),
                         ['include/value.h', 'src/example.c'])

    def test_empty_runtime_receipt_cannot_certify_the_compiler(self):
        command = build.compiler_command('C:/VC/cl.exe', self.recipe, 'compile')
        with self.assertRaises(ValueError):
            build.validate_runtime({'schema_version': 1, 'argv': command,
                'exit_code': 0, 'all_processes_exited': True, 'all_processes_succeeded': True,
                'method': 'Windows DEBUG_PROCESS module/exit events', 'events': [],
                'loaded_files': {}, 'root_pid': 1}, command, self.recipe, 'compile')


if __name__ == '__main__':
    unittest.main()
