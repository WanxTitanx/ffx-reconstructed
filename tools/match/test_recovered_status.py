"""Coverage is emitted ranges, never catalog size or source-file count."""
import copy
import unittest
from unittest import mock
from pathlib import Path
import tempfile
try:
    import recovered_status as status
except ModuleNotFoundError:
    status = None


class CoverageTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(status, 'build-derived recovered coverage is missing')
        self.start = 0x401000
        self.providers = {self.start: {'va': self.start, 'size': 6, 'key': 'c_recovered:unit:00401000',
            'family': 'c_recovered', 'implementation': 'unit.c:_function'}}
        self.records = [{'kind': 'coff', 'ip': self.start, 'size': 6,
                         'provider': self.providers[self.start]['key']},
                        {'kind': 'padding', 'ip': self.start+6, 'size': 2, 'value': 0xcc}]
        self.runs = [(self.start, self.start+6, 'code'), (self.start+6, self.start+8, 'alignment')]

    def summarize(self):
        return status.summarize(self.records, self.providers, self.runs, self.start, 8)

    def test_actual_selected_provider_is_counted_once(self):
        value = self.summarize()
        self.assertEqual(value['c_provider_bytes'], 6)
        self.assertEqual(value['c_instruction_bytes'], 6)
        self.assertEqual(value['declared_padding_bytes'], 2)
        self.assertEqual(value['c_implementations'], 1)
        self.assertEqual(value['c_instances'], 1)
        self.assertEqual(value['partition_bytes'], 8)

    def test_data_and_alignment_inside_c_extent_are_not_code_credit(self):
        self.runs = [(self.start, self.start+3, 'code'), (self.start+3, self.start+4, 'data'),
                     (self.start+4, self.start+8, 'alignment')]
        value = self.summarize()
        self.assertEqual(value['c_provider_bytes'], 6)
        self.assertEqual(value['c_instruction_bytes'], 3)
        self.assertEqual(value['c_data_bytes'], 1)
        self.assertEqual(value['c_padding_bytes'], 2)

    def test_unemitted_source_and_catalog_do_not_increase_coverage(self):
        # Extra declarations without an emitted record are not credited.
        old = self.summarize()
        self.providers[self.start+100] = dict(self.providers[self.start], va=self.start+100,
            key='c_recovered:unused:00401064', implementation='unused.c:_unlinked')
        self.assertEqual(self.summarize(), old)

    def test_alias_or_repeated_record_cannot_double_the_count(self):
        self.records.insert(1, copy.deepcopy(self.records[0]))
        with self.assertRaises(ValueError):
            self.summarize()

    def test_same_implementation_at_two_addresses_is_two_instances(self):
        self.providers[self.start+6] = dict(self.providers[self.start], va=self.start+6, size=2, key='other')
        self.records[1] = {'kind': 'coff', 'ip': self.start+6, 'size': 2, 'provider': 'other'}
        value = self.summarize()
        self.assertEqual(value['c_provider_bytes'], 8)
        self.assertEqual(value['c_instances'], 2)
        self.assertEqual(value['c_implementations'], 1)

    def test_manual_assembly_never_receives_c_credit(self):
        self.providers[self.start]['family'] = 'asm_mcwl'
        value = self.summarize()
        self.assertEqual(value['manual_assembly_bytes'], 6)
        self.assertEqual(value['c_provider_bytes'], 0)
        self.assertEqual(value['c_instances'], 0)

    def test_unrecognized_family_missing_provider_and_wrong_identity_fail(self):
        original = copy.deepcopy(self.providers)
        for kind in ('missing', 'family', 'identity'):
            self.providers = copy.deepcopy(original)
            if kind == 'missing':
                self.providers.clear()
            elif kind == 'family':
                self.providers[self.start]['family'] = 'c_fake'
            else:
                self.providers[self.start]['key'] = 'not-selected'
            with self.subTest(kind=kind), self.assertRaises(ValueError):
                self.summarize()

    def test_native_classification_must_cover_the_entire_provider(self):
        self.runs = [(self.start+1, self.start+8, 'code')]
        with self.assertRaises(ValueError):
            self.summarize()

    def test_assembly_instructions_and_declared_data_remain_separate(self):
        self.records[0] = {'kind': 'instruction', 'instruction': {'ip': self.start, 'length': 6}}
        self.records[1] = {'kind': 'data', 'ip': self.start+6, 'size': 2}
        value = self.summarize()
        self.assertEqual(value['assembly_instruction_bytes'], 6)
        self.assertEqual(value['declared_data_bytes'], 2)
        self.assertEqual(value['c_provider_bytes'], 0)


class CoverageEvidenceTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(status)
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.directory = Path(self.temporary.name)
        self.audit = {'verified_audit': 'expected'}
        self.proof = {'source_only_audit': self.audit.copy(),
            'independent_source_link_replay': {'replay_manifest_sha256': status.support.digest(b'{}'),
                                             'replay_candidate_sha256': status.support.digest(b'image')}}

    def validate(self):
        return status.validate_evidence(self.directory, self.directory, b'{}', {}, b'image', self.proof)

    def test_failed_build_audit_cannot_be_replaced_with_proof_booleans(self):
        with mock.patch.object(status.complete_acceptance, 'validate_audit', side_effect=ValueError('bad build audit')):
            with self.assertRaisesRegex(ValueError, 'bad build audit'):
                self.validate()

    def test_source_audit_must_be_bound_to_this_proof(self):
        self.proof['source_only_audit'] = {'verified_audit': 'another'}
        with mock.patch.object(status.complete_acceptance, 'validate_audit', return_value=(self.audit, {})):
            with self.assertRaisesRegex(ValueError, 'audit'):
                self.validate()

    def test_replay_of_another_manifest_cannot_certify_coverage(self):
        self.proof['independent_source_link_replay']['replay_manifest_sha256'] = '0'*64
        with mock.patch.object(status.complete_acceptance, 'validate_audit', return_value=(self.audit, {})):
            with self.assertRaisesRegex(ValueError, 'replay'):
                self.validate()

    def test_missing_retained_replay_fails(self):
        with mock.patch.object(status.complete_acceptance, 'validate_audit', return_value=(self.audit, {})):
            with self.assertRaises((ValueError, OSError)):
                self.validate()


if __name__ == '__main__':
    unittest.main()
