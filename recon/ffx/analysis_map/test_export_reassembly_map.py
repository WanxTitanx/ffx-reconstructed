"""Safety and coverage checks; native IDA is exercised separately in the VM."""
import importlib.util
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

SOURCE = Path(__file__).resolve().parents[3] / 'tools/match/export_reassembly_map.py'


class FakeBytes:
    def __init__(self):
        self.items = {100: (103, 'code'), 103: (104, 'code'),
                      106: (110, 'data'), 110: (114, 'string'),
                      114: (120, 'alignment')}

    def get_item_head(self, ea):
        return next((start for start, (end, _) in self.items.items()
                     if start <= ea < end), ea)

    def get_flags(self, ea):
        return self.items.get(ea, (ea + 1, 'unknown'))[1]

    def get_item_end(self, ea):
        return self.items.get(self.get_item_head(ea), (ea + 1, 'unknown'))[0]

    def next_head(self, ea, end):
        return min((x for x in self.items if ea < x < end), default=2**64 - 1)

    def is_code(self, flags): return flags == 'code'
    def is_data(self, flags): return flags in ('data', 'string', 'alignment')
    def is_align(self, flags): return flags == 'alignment'
    def is_strlit(self, flags): return flags == 'string'
    def is_unknown(self, flags): return flags == 'unknown'
    def is_tail(self, flags): return flags == 'tail'


class ExportTests(unittest.TestCase):
    def setUp(self):
        self.assertTrue(SOURCE.is_file(), 'metadata exporter is missing')
        spec = importlib.util.spec_from_file_location('reassembly_export_under_test', SOURCE)
        self.export = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(self.export)
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def test_instruction_boundaries_and_data_kinds_partition_segment(self):
        rows = list(self.export.iter_typed_ranges(FakeBytes(), 100, 120))
        self.assertEqual([(r['start'], r['end'], r['kind']) for r in rows],
                         [(100, 103, 'code'), (103, 104, 'code'),
                          (104, 106, 'unknown'), (106, 110, 'data'),
                          (110, 114, 'string'), (114, 120, 'alignment')])
        self.assertEqual(sum(r['size'] for r in rows), 20)
        self.assertFalse(any('bytes' in r or 'opcode' in r for r in rows))

    def test_unknown_gap_is_coalesced_to_next_defined_item(self):
        api = FakeBytes()
        api.items = {10_000_000: (10_000_005, 'code')}
        rows = list(self.export.iter_typed_ranges(api, 100, 10_000_005))
        self.assertEqual(len(rows), 2)
        self.assertEqual(rows[0]['size'], 9_999_900)

    def test_clipped_item_retains_real_instruction_head(self):
        row = next(self.export.iter_typed_ranges(FakeBytes(), 101, 103))
        self.assertEqual((row['start'], row['end'], row['item_head'], row['item_end']),
                         (101, 103, 100, 103))

    def test_invalid_item_end_fails_instead_of_looping(self):
        api = FakeBytes()
        api.get_item_end = lambda ea: ea
        with self.assertRaisesRegex(ValueError, 'item|range'):
            list(self.export.iter_typed_ranges(api, 100, 120))

    def test_private_copy_is_exact_and_original_is_unchanged(self):
        original = self.root / 'original.i64'
        original.write_bytes(b'database snapshot for copy validation')
        private = self.root / 'private/analysis-readonly.i64'
        record = self.export.prepare_private_copy(original, private)
        self.assertEqual(original.read_bytes(), private.read_bytes())
        self.assertEqual(record['original_sha256_before'], record['private_sha256_before'])

    def test_copy_refuses_original_and_existing_private_file(self):
        original = self.root / 'original.i64'
        original.write_bytes(b'original')
        with self.assertRaises((ValueError, FileExistsError)):
            self.export.prepare_private_copy(original, original)
        private = self.root / 'private.i64'
        private.write_bytes(b'other task')
        with self.assertRaises((ValueError, FileExistsError)):
            self.export.prepare_private_copy(original, private)
        self.assertEqual(private.read_bytes(), b'other task')
        self.assertEqual(original.read_bytes(), b'original')

    def test_collection_failure_closes_private_db_without_saving(self):
        original = self.root / 'original.i64'
        original.write_bytes(b'original')
        private = self.root / 'private.i64'
        calls = []
        native = SimpleNamespace(idapro=SimpleNamespace(
            open_database=lambda *a, **k: calls.append(('open', a, k)) or 0,
            close_database=lambda save: calls.append(('close', save))))
        with patch.object(self.export, 'load_ida', return_value=native), \
                patch.object(self.export, 'collect_metadata', side_effect=RuntimeError('fixture failure')):
            with self.assertRaisesRegex(RuntimeError, 'fixture failure'):
                self.export.run_export(original, private, self.root / 'output')
        self.assertEqual(calls[0][1][0], str(private.resolve()))
        self.assertIs(calls[0][1][1], False)
        self.assertEqual(calls[-1], ('close', False))
        self.assertEqual(original.read_bytes(), b'original')
        self.assertFalse((self.root / 'output/metadata.json').exists())

    def test_native_license_failure_is_not_retried(self):
        original = self.root / 'original.i64'
        original.write_bytes(b'original')
        with patch.object(self.export, 'load_ida', side_effect=ImportError('init_library license failure')) as loader:
            with self.assertRaisesRegex(ImportError, 'license failure'):
                self.export.run_export(original, self.root / 'private.i64', self.root / 'output')
        self.assertEqual(loader.call_count, 1)
        self.assertEqual(original.read_bytes(), b'original')


if __name__ == '__main__':
    unittest.main()
