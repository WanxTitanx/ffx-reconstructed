"""Typed pointer admission distinguishes addresses from identical scalar constants."""
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest

try:
    import mod_admission
except ModuleNotFoundError:
    mod_admission = None


class PointerAdmissionTests(unittest.TestCase):
    layout = {'image_base': 0x400000, 'optional_header': {'size_of_image': 0x2380000}}
    header = ('target datalayout = "e-m:x-p:32:32-i64:64-n8:16:32-S32"' + chr(10)
              + 'target triple = "i686-pc-windows-msvc19.20.0"' + chr(10))

    def check(self, body):
        self.assertIsNotNone(mod_admission, 'typed absolute-address admission is missing')
        return mod_admission.validate_ir(self.header + body, self.layout)

    def test_literal_pointer_into_original_image_is_rejected(self):
        for body in ('@p = constant ptr inttoptr (i32 4198432 to ptr)',
                     '%r = call i32 inttoptr (i32 4198432 to ptr)()',
                     '%p = inttoptr i64 4299165728 to ptr',
                     '%p = inttoptr i64 -4290768864 to ptr'):
            with self.subTest(body=body):
                with self.assertRaisesRegex(ValueError, 'absolute.*symbolic'):
                    self.check(body)

    def test_matching_integer_and_string_contents_are_not_treated_as_pointers(self):
        result = self.check('@n = constant i32 4198432' + chr(10)
            + '@s = constant [33 x i8] c"inttoptr (i32 4198432 to ptr)"' + chr(10)
            + '; inttoptr (i32 4198432 to ptr)')
        self.assertEqual(result['literal_pointer_count'], 0)
        self.assertEqual(result['dynamic_inttoptr_count'], 0)

    def test_external_symbols_and_non_image_sentinels_are_allowed(self):
        result = self.check('@p = constant ptr @original_function' + chr(10)
            + '@sentinel = constant ptr inttoptr (i32 -1 to ptr)' + chr(10)
            + '%null = inttoptr i32 0 to ptr')
        self.assertEqual(result['literal_pointer_count'], 2)
        self.assertEqual(result['dynamic_inttoptr_count'], 0)

    def test_computed_pointer_is_reported_as_requiring_semantic_review(self):
        result = self.check('%p = inttoptr i32 %runtime_address to ptr')
        self.assertEqual(result['dynamic_inttoptr_count'], 1)
        self.assertTrue(result['computed_addresses_require_review'])

    def test_ir_for_another_pointer_width_or_target_is_rejected(self):
        self.assertIsNotNone(mod_admission, 'typed absolute-address admission is missing')
        for text in ('', self.header.replace('p:32:32', 'p:64:64'),
                     self.header.replace('i686-pc-windows-msvc19.20.0', 'x86_64-linux-gnu')):
            with self.subTest(text=text):
                with self.assertRaisesRegex(ValueError, 'IR|target|pointer'):
                    mod_admission.validate_ir(text, self.layout)

    @unittest.skipUnless(shutil.which('clang'), 'Clang is required for the genuine IR regression')
    def test_real_compiler_distinguishes_pointer_and_scalar_with_the_same_value(self):
        self.assertIsNotNone(mod_admission, 'typed absolute-address admission is missing')
        with tempfile.TemporaryDirectory(prefix='ffx-pointer-admission-') as temporary:
            root = Path(temporary)
            source = root / 'change.c'
            output = root / 'module.ll'
            command = [shutil.which('clang'), '--target=i686-pc-windows-msvc',
                       '-O2', '-ffreestanding', '-S', '-emit-llvm', str(source), '-o', str(output)]
            source.write_text('unsigned const ordinary_integer = 0x00401020;')
            subprocess.run(command, check=True, capture_output=True)
            mod_admission.validate_ir(output.read_text(), self.layout)
            source.write_text('int (*const absolute_pointer)(void) = (int (*)(void))0x00401020;'
                              + 'int changed(void) { return ((int (*)(void))0x00401020)(); }')
            subprocess.run(command, check=True, capture_output=True)
            with self.assertRaisesRegex(ValueError, 'absolute.*symbolic'):
                mod_admission.validate_ir(output.read_text(), self.layout)


if __name__ == '__main__':
    unittest.main()
