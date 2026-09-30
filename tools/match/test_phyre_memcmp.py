"""Compile the instruction reconstruction and compare the entire function."""
import hashlib
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / 'recon/ffx/phyre_memcmp_with_length.S'
REFERENCE = ROOT / 'recon/ffx/mcwl.ref.bin'


class PhyreMemcmpByteTests(unittest.TestCase):
    def test_assembled_function_matches_all_144_reference_bytes(self):
        expected = REFERENCE.read_bytes()
        self.assertEqual(hashlib.sha256(expected).hexdigest(),
                         'ebb4774a12c17019189c53e2d05203ea717465e67c1505894f2f43f0ac8b6a96')
        with tempfile.TemporaryDirectory() as tmp:
            obj = Path(tmp) / 'function.o'
            blob = Path(tmp) / 'function.bin'
            subprocess.run(['as', '--32', str(SOURCE), '-o', str(obj)], check=True)
            subprocess.run(['objcopy', '-O', 'binary', '--only-section=.text',
                            str(obj), str(blob)], check=True)
            actual = blob.read_bytes()
        self.assertEqual(len(actual), 144)
        differences = [(offset, got, want) for offset, (got, want)
                       in enumerate(zip(actual, expected)) if got != want]
        self.assertEqual(differences, [], 'offset / actual / original byte')


if __name__ == '__main__':
    unittest.main()
