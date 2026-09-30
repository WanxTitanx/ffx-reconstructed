"""Strict admission tests for the retained native function-boundary inventory."""
import csv
import gzip
import hashlib
import io
import json
from pathlib import Path
import shutil
import tempfile
import unittest
from unittest.mock import patch

import mod_boundaries


ROOT = Path(__file__).resolve().parents[2]
MAP_FILES = (
    'metadata.json',
    'validation.json',
    'validate_export.py',
    'function_ranges.tsv.gz',
)


class BoundaryInventoryTests(unittest.TestCase):
    def clone_inventory(self):
        temporary = tempfile.TemporaryDirectory()
        self.addCleanup(temporary.cleanup)
        root = Path(temporary.name)
        source = ROOT / 'recon/ffx/analysis_map'
        target = root / 'recon/ffx/analysis_map'
        target.mkdir(parents=True)
        for name in MAP_FILES:
            shutil.copyfile(source / name, target / name)
        exporter = root / 'tools/match/export_reassembly_map.py'
        exporter.parent.mkdir(parents=True)
        shutil.copyfile(ROOT / 'tools/match/export_reassembly_map.py', exporter)
        return root

    @staticmethod
    def rewrite_json(path, update):
        value = json.loads(path.read_text(encoding='utf-8'))
        update(value)
        path.write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')
        return value

    @staticmethod
    def refresh_metadata_receipt(root):
        folder = root / 'recon/ffx/analysis_map'
        digest = hashlib.sha256((folder / 'metadata.json').read_bytes()).hexdigest()
        BoundaryInventoryTests.rewrite_json(
            folder / 'validation.json',
            lambda receipt: receipt.__setitem__('metadata_sha256', digest),
        )

    def test_real_inventory_has_pinned_contract_and_is_observed(self):
        observed = {}
        rows = mod_boundaries.load_inventory(ROOT, observed)
        self.assertEqual(len(rows), 72473)
        self.assertEqual(sum(row['kind'] == 'entry' for row in rows), 66557)
        self.assertEqual(
            [row for row in rows if row['function_start'] == '0x00401020'],
            [{
                'function_start': '0x00401020',
                'start': '0x00401020',
                'end': '0x00401090',
                'size': '112',
                'kind': 'entry',
                'db_sha256': 'f2b0182db5b34119500df06a9f4991d17119cfdc066fd9bb25231d7fa28ee163',
                'readable_bytes': '112',
            }],
        )
        expected = {
            ROOT / 'recon/ffx/analysis_map/metadata.json',
            ROOT / 'recon/ffx/analysis_map/validation.json',
            ROOT / 'recon/ffx/analysis_map/validate_export.py',
            ROOT / 'recon/ffx/analysis_map/function_ranges.tsv.gz',
            ROOT / 'tools/match/export_reassembly_map.py',
        }
        self.assertEqual(set(observed), expected)

    def test_loader_reads_only_retained_contract_files(self):
        accessed = set()
        original = Path.read_bytes

        def tracked(path):
            accessed.add(path.resolve())
            return original(path)

        with patch.object(Path, 'read_bytes', tracked):
            rows = mod_boundaries.load_inventory(ROOT, {})
        self.assertEqual(len(rows), 72473)
        self.assertEqual(accessed, {
            ROOT / 'recon/ffx/analysis_map/metadata.json',
            ROOT / 'recon/ffx/analysis_map/validation.json',
            ROOT / 'recon/ffx/analysis_map/validate_export.py',
            ROOT / 'recon/ffx/analysis_map/function_ranges.tsv.gz',
            ROOT / 'tools/match/export_reassembly_map.py',
        })

    def test_rejects_fabricated_metadata_even_with_rewritten_receipt(self):
        root = self.clone_inventory()
        metadata = root / 'recon/ffx/analysis_map/metadata.json'
        self.rewrite_json(metadata, lambda value: value.update(
            schema_version=999,
            status='incomplete',
            input_sha256_recorded_in_db='0' * 64,
            input_size_recorded_in_db=1,
            image_base='0x00000000',
            processor='other',
            is_64bit=True,
        ))
        self.refresh_metadata_receipt(root)
        with self.assertRaises(ValueError):
            mod_boundaries.load_inventory(root, {})

    def test_rejects_self_consistent_single_row_inventory(self):
        root = self.clone_inventory()
        folder = root / 'recon/ffx/analysis_map'
        columns = list(mod_boundaries.FUNCTION_RANGE_COLUMNS)
        source_rows = mod_boundaries.load_inventory(ROOT, {})
        stream = io.StringIO(newline='')
        writer = csv.DictWriter(stream, fieldnames=columns, delimiter='\t', lineterminator='\n')
        writer.writeheader()
        writer.writerow(source_rows[0])
        table = gzip.compress(stream.getvalue().encode('utf-8'), mtime=0)
        (folder / 'function_ranges.tsv.gz').write_bytes(table)

        def shrink(value):
            entry = value['tables']['function_ranges.tsv.gz']
            entry.update(rows=1, compressed_bytes=len(table),
                         sha256=hashlib.sha256(table).hexdigest())
            value['function_ranges'] = 1
            value['functions'] = 1

        self.rewrite_json(folder / 'metadata.json', shrink)
        self.refresh_metadata_receipt(root)
        self.rewrite_json(folder / 'validation.json',
                          lambda value: value.update(function_ranges=1, functions=1))
        with self.assertRaises(ValueError):
            mod_boundaries.load_inventory(root, {})

    def test_rejects_each_function_range_table_contract_mutation(self):
        mutations = {
            'columns': lambda entry: entry.__setitem__('columns', ['start']),
            'rows': lambda entry: entry.__setitem__('rows', 1),
            'compressed_bytes': lambda entry: entry.__setitem__('compressed_bytes', 1),
            'sha256': lambda entry: entry.__setitem__('sha256', '0' * 64),
        }
        for label, mutate in mutations.items():
            with self.subTest(label=label):
                root = self.clone_inventory()
                metadata = root / 'recon/ffx/analysis_map/metadata.json'
                self.rewrite_json(
                    metadata,
                    lambda value, mutate=mutate: mutate(value['tables']['function_ranges.tsv.gz']),
                )
                self.refresh_metadata_receipt(root)
                with self.assertRaises(ValueError):
                    mod_boundaries.load_inventory(root, {})

    def test_rejects_exporter_and_validation_provenance_mismatches(self):
        for relative in ('tools/match/export_reassembly_map.py',
                         'recon/ffx/analysis_map/validate_export.py'):
            with self.subTest(relative=relative):
                root = self.clone_inventory()
                path = root / relative
                path.write_bytes(path.read_bytes() + b'\n# modified\n')
                with self.assertRaises(ValueError):
                    mod_boundaries.load_inventory(root, {})

    def test_rejects_validation_receipt_claim_mutations(self):
        mutations = {
            'status': ('status', 'unvalidated'),
            'metadata': ('metadata_sha256', '0' * 64),
            'validator': ('validator_sha256', '0' * 64),
            'reference': ('reference_sha256', '0' * 64),
            'reference_unchanged': ('reference_unchanged', False),
            'tables_validated': ('all_table_hashes_and_row_counts_match', False),
            'database_unchanged': ('original_and_private_db_unchanged', False),
            'range_count': ('function_ranges', 1),
        }
        for label, (key, replacement) in mutations.items():
            with self.subTest(label=label):
                root = self.clone_inventory()
                receipt = root / 'recon/ffx/analysis_map/validation.json'
                self.rewrite_json(receipt,
                                  lambda value, key=key, replacement=replacement:
                                      value.__setitem__(key, replacement))
                with self.assertRaises(ValueError):
                    mod_boundaries.load_inventory(root, {})


if __name__ == '__main__':
    unittest.main()
