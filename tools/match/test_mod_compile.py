"""Fresh compiler output and a closed source package, independent of baseline bytes."""
import json
from pathlib import Path
import tempfile
import unittest

try:
    import mod_compile
except ModuleNotFoundError:
    mod_compile = None


class CompileTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.package = self.root / "package"
        self.package.mkdir()
        self.recipe = {"schema_version": 1, "name": "test", "source": "change.c",
                       "files": ["change.c", "values.h"], "replacements": [], "bindings": {}}
        (self.package / "values.h").write_text("extern volatile int value;\n")
        (self.package / "change.c").write_text(
            "#include \"values.h\"\nvolatile int value = 7;\nint changed(int x) { return x + value; }\n")
        self.save()

    def save(self):
        (self.package / "mod.json").write_text(json.dumps(self.recipe))

    def require(self):
        self.assertIsNotNone(mod_compile, "fresh source compilation path is missing")

    def test_fresh_object_defines_code_data_and_real_relocation(self):
        self.require()
        recipe, obj, observed, receipt = mod_compile.compile_package(self.package, self.root / "build")
        names = {s["name"] for s in obj["symbols"].values()}
        self.assertTrue({"_changed", "_value"}.issubset(names))
        self.assertTrue(any(r["symbol_name"] == "_value" for s in obj["sections"] for r in s["relocations"]))
        self.assertIn(self.package / "values.h", observed)
        self.assertEqual(receipt["object_sha256"], mod_compile.support.digest((self.root / "build/module.obj").read_bytes()))
        self.assertEqual(json.loads((self.root / "build/compile.json").read_text()), receipt)

    def test_clean_recompile_is_deterministic(self):
        self.require()
        a = mod_compile.compile_package(self.package, self.root / "a")[3]
        b = mod_compile.compile_package(self.package, self.root / "b")[3]
        self.assertEqual(a, b)

    def test_receipt_binds_actual_compiler_elf_dependency_closure(self):
        self.require()
        _, _, observed, receipt = mod_compile.compile_package(self.package, self.root / "build")
        dependencies = receipt['elf_dependencies']
        paths = [Path(item['path']) for item in dependencies]
        self.assertEqual(len(paths), len(set(paths)))
        self.assertTrue(any(path.name.startswith('libclang-cpp.so') for path in paths))
        self.assertTrue(any(path.name.startswith('libLLVM.so') for path in paths))
        inputs = {Path(item['path']): item for item in receipt['inputs']}
        for item, path in zip(dependencies, paths):
            self.assertIn(path, observed)
            self.assertIn(path, inputs)
            self.assertEqual(item['sha256'], mod_compile.support.digest(observed[path]))
            self.assertEqual(inputs[path]['sha256'], item['sha256'])
            self.assertEqual((self.root / 'build' / inputs[path]['snapshot']).read_bytes(),
                             observed[path])

    def test_edit_changes_fresh_object(self):
        self.require()
        a = mod_compile.compile_package(self.package, self.root / "build")[3]
        (self.package / "change.c").write_text("int changed(int x) { return x + 91; }\n")
        b = mod_compile.compile_package(self.package, self.root / "build")[3]
        self.assertNotEqual(a["object_sha256"], b["object_sha256"])

    def test_fresh_typed_ir_matches_receipt_and_has_closed_dependencies(self):
        self.require()
        _, obj, _, receipt = mod_compile.compile_package(self.package, self.root / 'build')
        self.assertIn('ir_sha256', receipt, 'fresh typed compiler IR is not retained')
        raw = (self.root / 'build/module.ll').read_bytes()
        self.assertEqual(receipt['ir_sha256'], mod_compile.support.digest(raw))
        self.assertEqual(obj['llvm_ir'], raw.decode('utf-8'))
        self.assertEqual(receipt['ir_dependencies'], receipt['dependencies'])
        self.assertIn('-emit-llvm', receipt['ir_command'])
        self.assertIn('@changed', obj['llvm_ir'])

    def test_source_edit_replaces_ir_instead_of_accepting_a_retained_file(self):
        self.require()
        first = mod_compile.compile_package(self.package, self.root / 'build')[3]
        self.assertIn('ir_sha256', first, 'fresh typed compiler IR is not retained')
        (self.package / 'change.c').write_text('int changed(int x) { return x + 91; }')
        second = mod_compile.compile_package(self.package, self.root / 'build')[3]
        self.assertNotEqual(first['ir_sha256'], second['ir_sha256'])
        self.assertEqual(second['ir_sha256'],
                         mod_compile.support.digest((self.root / 'build/module.ll').read_bytes()))

    def test_kernel_interpreter_is_fingerprinted_separately_from_opened_libraries(self):
        self.require()
        _, _, observed, receipt = mod_compile.compile_package(self.package, self.root / 'build')
        self.assertIn('elf_interpreter', receipt, 'kernel-loaded interpreter is not distinguished')
        interpreter = Path(receipt['elf_interpreter']['path'])
        self.assertIn(interpreter, observed)
        self.assertEqual(receipt['elf_interpreter']['sha256'],
                         mod_compile.support.digest(observed[interpreter]))
        dependencies = {item['path'] for item in receipt['elf_dependencies']}
        self.assertEqual(set(receipt['runtime_libraries']), dependencies - {str(interpreter)})
        self.assertTrue(receipt['runtime_libraries'])

    def test_undeclared_header_is_not_silently_used(self):
        self.require()
        self.recipe["files"] = ["change.c"]
        self.save()
        with self.assertRaises(ValueError):
            mod_compile.compile_package(self.package, self.root / "build")
        self.assertFalse((self.root / "build/compile.json").exists())

    def test_parent_path_in_source_list_is_rejected(self):
        self.require()
        self.recipe["files"].append("../outside.h")
        self.save()
        with self.assertRaises(ValueError):
            mod_compile.compile_package(self.package, self.root / "build")

    def test_wrapped_compiler_dependency_lines_preserve_all_declared_headers(self):
        self.require()
        headers = ['long_declared_header_name_that_wraps_dependency_receipts_%s.h' % n for n in range(3)]
        for number, name in enumerate(headers):
            (self.package/name).write_text('#define VALUE_%s %s' % (number, number)+chr(10))
        (self.package/'change.c').write_text(''.join('#include "'+name+'"'+chr(10) for name in headers)
                                            + 'int changed(void) { return VALUE_0+VALUE_1+VALUE_2; }'+chr(10))
        self.recipe['files'] = ['change.c', *headers]
        self.save()
        _, _, _, receipt = mod_compile.compile_package(self.package, self.root/'build')
        self.assertEqual(receipt['dependencies'], sorted('source/'+name for name in self.recipe['files']))

    def test_integrated_assembler_cannot_import_undeclared_binary(self):
        self.require()
        outside = self.root / 'outside.bin'
        outside.write_bytes(b'UNDECLARED_PAYLOAD_9f31')
        assembler = '.incbin "' + str(outside) + '"'
        (self.package / 'change.c').write_text('__asm__(' + json.dumps(assembler) + ');' + chr(10)
                                              + 'int changed(int x) { return x; }' + chr(10))
        with self.assertRaises(ValueError):
            mod_compile.compile_package(self.package, self.root / 'build')
        self.assertFalse((self.root / 'build/compile.json').exists())

    def test_microsoft_inline_assembly_is_outside_c_profile(self):
        self.require()
        (self.package / 'change.c').write_text('int changed(void) { __asm { nop } return 1; }' + chr(10))
        with self.assertRaises(ValueError):
            mod_compile.compile_package(self.package, self.root / 'build')

    def test_c_and_cpp_keep_explicit_windows_abi_declarations(self):
        self.require()
        for suffix, prefix in (('c', ''), ('cpp', 'extern "C" ')):
            with self.subTest(language=suffix):
                name = 'abi.' + suffix
                (self.package/name).write_text(prefix +
                    '__declspec(noinline) int __cdecl changed(int x) { return x + 1; }' + chr(10))
                self.recipe['source'], self.recipe['files'] = name, [name]
                self.save()
                _, obj, _, _ = mod_compile.compile_package(self.package, self.root/('build-'+suffix))
                self.assertTrue(any(s['name'] == '_changed' and s['type'] & 0x20
                                    for s in obj['symbols'].values()))

    def test_cpp_vtable_and_multiple_text_sections_have_real_linked_relocations(self):
        self.require()
        import mod_objects
        source = ('class Counter { public: int step; Counter(int v):step(v){} '
                  'virtual int value(int x) { return x + step; } };' + chr(10)
                  + 'extern "C" __declspec(noinline) int dispatch(Counter *p,int x) '
                  '{ return p->value(x); }' + chr(10)
                  + 'extern "C" int changed(int x) { Counter c(7); return dispatch(&c,x); }' + chr(10))
        (self.package/'change.cpp').write_text(source)
        self.recipe['source'], self.recipe['files'] = 'change.cpp', ['change.cpp']
        self.save()
        _, obj, _, _ = mod_compile.compile_package(self.package, self.root/'cpp-build')
        sizes, entries = mod_objects.allocate(obj)
        group_addresses = {'.modtxt': 0x2400000, '.modro': 0x2500000, '.moddat': 0x2600000}
        addresses, exported = mod_objects.symbols(obj, entries, group_addresses, {}, {})
        contents, highlow, records = mod_objects.emit_module(obj, sizes, entries,
                                                              group_addresses, addresses, 0x400000)
        self.assertTrue(any('??_7Counter' in name for name in exported))
        self.assertIn('_changed', exported)
        self.assertIn('.modro', contents)
        self.assertGreaterEqual(len(highlow), 2)
        self.assertGreaterEqual(len([r for r in records if r['group'] == '.modtxt']), 2)


if __name__ == "__main__":
    unittest.main()
