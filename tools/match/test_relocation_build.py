import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import relocation_build as builder


class SnapshotTests(unittest.TestCase):
    def test_failed_source_read_invalidates_old_proof(self):
        with tempfile.TemporaryDirectory() as tmp:
            package = Path(tmp)
            output = package / 'build'
            output.mkdir()
            for name in ('proof.json','build-manifest.json'):
                (output/name).write_text('{"status":"complete"}')
            with self.assertRaises(OSError):
                builder.build(package,output)
            self.assertFalse((output/'build-manifest.json').exists())
            self.assertFalse((output/'proof.json').exists())

    def test_snapshot_read_rejects_any_changed_input(self):
        with tempfile.TemporaryDirectory() as tmp:
            path=Path(tmp)/'source.c'
            path.write_bytes(b'first version')
            observed={path:path.read_bytes()}
            path.write_bytes(b'second version')
            with self.assertRaises(ValueError):
                builder.support.check_unchanged(observed)


if __name__ == '__main__':
    unittest.main()
