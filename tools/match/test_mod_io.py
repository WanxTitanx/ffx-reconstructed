"""Existing output aliases must never overwrite source or external files."""
import os
from pathlib import Path
import tempfile
import unittest
import mod_link
try:
    import mod_io
except ModuleNotFoundError:
    mod_io = None


class OutputTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.package = self.root/'package'
        self.package.mkdir()
        self.output = self.root/'build'
        self.output.mkdir()
        self.outside = self.root/'external'
        self.outside.mkdir()
        self.sentinel = self.outside/'sentinel'
        self.sentinel.write_bytes(b'preserve')

    def test_output_beneath_source_package_is_rejected(self):
        with self.assertRaises(ValueError):
            mod_link.output_guard(self.root, self.package, self.package/'build')

    def test_compiler_directory_symlink_is_rejected(self):
        (self.output/'compiler').symlink_to(self.outside, target_is_directory=True)
        with self.assertRaises(ValueError):
            mod_link.output_guard(self.root, self.package, self.output)

    def test_pending_executable_symlink_is_rejected(self):
        (self.output/'FFX.exe.tmp').symlink_to(self.sentinel)
        with self.assertRaises(ValueError):
            mod_link.output_guard(self.root, self.package, self.output)
        self.assertEqual(self.sentinel.read_bytes(), b'preserve')

    def test_existing_snapshot_hardlink_is_rejected(self):
        (self.output/'inputs').mkdir()
        os.link(self.sentinel, self.output/'inputs/copied')
        with self.assertRaises(ValueError):
            mod_link.output_guard(self.root, self.package, self.output)

    def test_safe_write_rejects_symlink_created_after_validation(self):
        self.assertIsNotNone(mod_io, 'output writer does not reject aliases')
        mod_link.output_guard(self.root, self.package, self.output)
        target = self.output/'FFX.exe.tmp'
        target.symlink_to(self.sentinel)
        with self.assertRaises((ValueError, OSError)):
            mod_io.write(target, b'changed')
        self.assertEqual(self.sentinel.read_bytes(), b'preserve')

    def test_safe_write_does_not_truncate_a_hardlink(self):
        self.assertIsNotNone(mod_io, 'output writer does not reject aliases')
        target = self.output/'FFX.exe.tmp'
        os.link(self.sentinel, target)
        with self.assertRaises(ValueError):
            mod_io.write(target, b'changed')
        self.assertEqual(self.sentinel.read_bytes(), b'preserve')

    def test_safe_write_replaces_an_owned_regular_output(self):
        self.assertIsNotNone(mod_io, 'output writer is missing')
        target = self.output/'manifest.json'
        target.write_text('long previous output')
        mod_io.write(target, b'new')
        self.assertEqual(target.read_bytes(), b'new')

    def test_unlink_rejects_parent_swap_after_output_validation(self):
        (self.output/'manifest.json').write_bytes(b'owned')
        external = self.outside/'manifest.json'
        external.write_bytes(b'preserve')
        mod_link.output_guard(self.root, self.package, self.output)
        self.output.rename(self.root/'moved')
        self.output.symlink_to(self.outside, target_is_directory=True)
        operation = getattr(mod_io, 'unlink', lambda path, **kw: path.unlink(**kw))
        with self.assertRaises((ValueError, OSError)):
            operation(self.output/'manifest.json', missing_ok=True)
        self.assertEqual(external.read_bytes(), b'preserve')

    def test_publish_rejects_parent_swap_after_output_validation(self):
        (self.output/'FFX.exe.tmp').write_bytes(b'owned')
        external = self.outside/'FFX.exe'
        external.write_bytes(b'preserve')
        (self.outside/'FFX.exe.tmp').write_bytes(b'planted')
        mod_link.output_guard(self.root, self.package, self.output)
        self.output.rename(self.root/'moved')
        self.output.symlink_to(self.outside, target_is_directory=True)
        operation = getattr(mod_io, 'replace', lambda source, target: source.replace(target))
        with self.assertRaises((ValueError, OSError)):
            operation(self.output/'FFX.exe.tmp', self.output/'FFX.exe')
        self.assertEqual(external.read_bytes(), b'preserve')

    def test_descriptor_publication_and_invalidation_work_for_owned_files(self):
        self.assertTrue(hasattr(mod_io, 'replace'), 'descriptor publication is missing')
        temporary = self.output/'manifest.json.tmp'
        destination = self.output/'manifest.json'
        mod_io.write(temporary, b'published')
        mod_io.replace(temporary, destination)
        self.assertEqual(destination.read_bytes(), b'published')
        self.assertFalse(temporary.exists())
        mod_io.unlink(destination, missing_ok=True)
        self.assertFalse(destination.exists())
        mod_io.unlink(destination, missing_ok=True)


if __name__ == '__main__':
    unittest.main()
