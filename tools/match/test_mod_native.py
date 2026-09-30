"""Execute the real compiled PE callee selected by a statically relinked call."""
import copy
import json
from pathlib import Path
import tempfile
import unittest
try:
    import mod_native
except ModuleNotFoundError:
    mod_native = None

ROOT = Path(__file__).resolve().parents[2]
BUILD = ROOT/'recon/ffx/mods/build/compare_demo'


class NativeTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(mod_native, 'reproducible native PE harness is missing')
        self.manifest = json.loads((BUILD/'manifest.json').read_text())
        self.data = (BUILD/'FFX.exe').read_bytes()

    def test_config_uses_a_real_relinked_call_and_current_module_symbols(self):
        config = mod_native.configuration(self.data, self.manifest)
        self.assertEqual(config['CALL_SITE_RVA'], 0x3c38)
        self.assertEqual(config['FN_RVA']+config['IMAGE_BASE'],
                         self.manifest['module_symbols']['_FFX_memcmp_modified'])

    def test_manifest_cannot_substitute_an_unrelated_call_target(self):
        forged = copy.deepcopy(self.manifest)
        for record in forged['changed_references']:
            record['to'] += 1
        with self.assertRaises(ValueError):
            mod_native.configuration(self.data, forged)

    def test_native_execution_at_preferred_and_two_rebased_addresses(self):
        with tempfile.TemporaryDirectory() as directory:
            report = mod_native.validate(BUILD/'FFX.exe', self.manifest, Path(directory)/'native')
            self.assertTrue(report['passed'])
            self.assertEqual(report['total_cases'], 101400)
            self.assertEqual([r['load_base'] for r in report['runs']],
                             ['0x00400000', '0x10000000', '0x50000000'])
            self.assertFalse(report['whole_original_caller_executed'])
            self.assertFalse(report['gameplay_executed'])


if __name__ == '__main__':
    unittest.main()
