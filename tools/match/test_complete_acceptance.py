"""Acceptance must establish a source link, not merely a matching file copy."""
import contextlib
import copy
import gzip
import io
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import leaf_build as support
import verify_complete_image as complete
from test_pe_headers import fixture

try:
    import complete_acceptance as gate
except ModuleNotFoundError:
    gate = None


class ForgedAcceptanceTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.directory = self.root / 'candidate'
        self.directory.mkdir()
        self.image = fixture()
        self.reference = self.root / 'original.exe'
        self.reference.write_bytes(self.image)
        (self.directory / 'FFX.exe').write_bytes(self.image)
        self.digest = support.digest(self.image)
        self.manifest = {
            'schema_version': 1, 'status': 'complete', 'candidate': 'FFX.exe',
            'target_sha256': self.digest, 'candidate_sha256': self.digest,
            'file_size': len(self.image), 'inputs': [],
            'reference_read_by_linker': False, 'raw_code_blob_fallbacks': 0,
            'masked_bytes': 0, 'highlow_sites': [0x401010, 0x401024],
            'text_stats': {}, 'imports': [], 'section_hashes': [],
            'placed_fragments': [], 'defined_symbols': 0,
        }
        self.addCleanup(patch.stopall)
        patch.object(complete.exact, 'EXE_SHA256', self.digest).start()

    def verify(self):
        (self.directory / 'manifest.json').write_text(json.dumps(self.manifest))
        with contextlib.redirect_stdout(io.StringIO()):
            return complete.verify(self.directory, self.reference)

    def rejected(self, message):
        (self.directory / 'proof.json').write_text('{"whole_executable_reconstructed":true}')
        with self.assertRaisesRegex(ValueError, message):
            self.verify()
        self.assertFalse((self.directory / 'proof.json').exists())

    def test_equal_copy_with_forged_claims_cannot_get_source_proof(self):
        self.manifest.update(reference_read_by_linker=True, raw_code_blob_fallbacks=999,
                             masked_bytes=999, text_stats={'forged': 999})
        self.rejected('reference|source|manifest')

    def test_equal_copy_with_empty_input_closure_is_rejected(self):
        self.rejected('input|source|manifest')

    def test_nonzero_masking_is_rejected_even_with_equal_bytes(self):
        self.manifest['masked_bytes'] = 1
        self.rejected('mask|source|manifest')

    def test_boolean_does_not_impersonate_integer_zero(self):
        self.manifest['raw_code_blob_fallbacks'] = False
        self.rejected('source|manifest|raw')


class ReceiptAndTraceTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(gate, 'source acceptance gate is missing')
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.directory = self.root / 'candidate'
        (self.directory / 'inputs').mkdir(parents=True)
        self.source = self.root / 'function.c'
        self.source.write_bytes(b'int f(void) { return 7; }\n')
        digest = support.digest(self.source.read_bytes())
        (self.directory / 'inputs' / digest).write_bytes(self.source.read_bytes())
        self.image = b'MZfixture'
        self.manifest = {
            'schema_version': 1, 'status': 'complete', 'candidate': 'FFX.exe',
            'target_sha256': support.digest(self.image),
            'candidate_sha256': support.digest(self.image), 'file_size': len(self.image),
            'reference_read_by_linker': False, 'raw_code_blob_fallbacks': 0, 'masked_bytes': 0,
            'inputs': [{'path': str(self.source), 'sha256': digest, 'snapshot': 'inputs/' + digest}],
            'placed_fragments': [], 'defined_symbols': 1, 'highlow_sites': [],
            'text_stats': {'instructions': 1}, 'imports': [], 'section_hashes': [],
        }
        self.reference = self.root / 'original.exe'
        self.trace = (b'17 openat(AT_FDCWD, "/source/f.c", O_RDONLY) = 3\n'
                      b'18 openat(AT_FDCWD, "/source/f.obj", O_WRONLY|O_CREAT, 0666) = 4\n'
                      b'18 +++ exited with 0 +++\n17 +++ exited with 0 +++\n')

    def inputs(self):
        return gate.validate_inputs(self.manifest, self.directory, self.reference)

    def test_input_snapshot_and_current_source_are_both_checked(self):
        observed = self.inputs()
        self.assertEqual(observed[self.source], self.source.read_bytes())
        self.source.write_bytes(b'int f(void) { return 8; }\n')
        with self.assertRaisesRegex(ValueError, 'input|source'):
            self.inputs()

    def test_duplicate_inputs_are_rejected(self):
        self.manifest['inputs'] *= 2
        with self.assertRaisesRegex(ValueError, 'duplicate'):
            self.inputs()

    def test_snapshot_cannot_escape_the_evidence_directory(self):
        self.manifest['inputs'][0]['snapshot'] = '../function.c'
        with self.assertRaisesRegex(ValueError, 'snapshot'):
            self.inputs()

    def test_original_cannot_be_a_build_input(self):
        with self.assertRaisesRegex(ValueError, 'reference|original'):
            gate.validate_inputs(self.manifest, self.directory, self.source)

    def test_replayed_manifest_matches_the_entire_closure(self):
        gate.compare_replay(self.manifest, self.image, copy.deepcopy(self.manifest), self.image)

    def test_omitted_input_fails_despite_equal_binary(self):
        claimed = copy.deepcopy(self.manifest)
        claimed['inputs'] = []
        with self.assertRaisesRegex(ValueError, 'replay|closure'):
            gate.compare_replay(claimed, self.image, self.manifest, self.image)

    def test_forged_stats_and_relocations_fail_despite_equal_binary(self):
        for field, value in (('text_stats', {'forged': 999}), ('highlow_sites', [0x401000]),
                             ('defined_symbols', 999), ('placed_fragments', [{}])):
            claimed = copy.deepcopy(self.manifest)
            claimed[field] = value
            with self.subTest(field=field), self.assertRaisesRegex(ValueError, 'replay'):
                gate.compare_replay(claimed, self.image, self.manifest, self.image)

    def test_linked_output_must_match_all_bytes(self):
        with self.assertRaisesRegex(ValueError, 'replay|bytes'):
            gate.compare_replay(self.manifest, self.image, self.manifest, self.image + b'\0')

    def test_trace_recomputes_open_count_and_descendants(self):
        result = gate.trace_facts(self.trace, [self.reference])
        self.assertEqual(result['observed_open_syscalls'], 2)
        self.assertEqual(result['traced_processes'], 2)

    def test_os_open_of_original_in_child_is_rejected(self):
        extra = ('18 openat(AT_FDCWD, ' + json.dumps(str(self.reference)) + ', O_RDONLY) = 5\n').encode()
        with self.assertRaisesRegex(ValueError, 'original|forbidden|reference'):
            gate.trace_facts(extra + self.trace, [self.reference])

    def test_decoded_descriptor_path_exposes_a_symlink_alias(self):
        extra = ('18 openat(AT_FDCWD, "/tmp/alias", O_RDONLY) = 5<' + str(self.reference) + '>\n').encode()
        with self.assertRaisesRegex(ValueError, 'original|forbidden|reference'):
            gate.trace_facts(extra + self.trace, [self.reference])

    def test_missing_root_exit_and_nonzero_child_exit_are_rejected(self):
        bad = (b'', self.trace.replace(b'17 +++ exited with 0 +++\n', b''),
               self.trace.replace(b'18 +++ exited with 0 +++', b'18 +++ exited with 7 +++'))
        for trace in bad:
            with self.subTest(trace=trace), self.assertRaisesRegex(ValueError, 'trace|exit'):
                gate.trace_facts(trace, [self.reference])

    def make_audit(self):
        data = (json.dumps(self.manifest) + '\n').encode()
        (self.directory / 'manifest.json').write_bytes(data)
        (self.directory / 'FFX.exe').write_bytes(self.image)
        trace, command = self.bound_trace()
        (self.directory / 'build.trace').write_bytes(trace)
        (self.directory / 'build.log').write_bytes(b'complete\n')
        gate.record_audit(self.directory, self.reference, command)
        return data

    def bound_trace(self):
        runtime = [sys.executable, str(gate.ROOT / 'tools/match/run_source_only.py'),
                   str(gate.ROOT / 'tools/match/rebuild_complete.py'),
                   '--root', str(gate.ROOT), '--output', str(self.directory)]
        command = ['strace', '-f', '-s', '4096', '-yy', '-e', 'trace=open,openat,openat2,execve',
                   '-o', str(self.directory / 'build.trace'), *runtime]
        trace = ('17 execve(' + json.dumps(runtime[0]) + ', ' + json.dumps(runtime) + ', 0xabc /* 3 vars */) = 0\n')
        for path, flags in ((self.source, 'O_RDONLY'),
                            (self.directory / 'FFX.exe.tmp', 'O_WRONLY|O_CREAT|O_TRUNC'),
                            (self.directory / 'manifest.json.tmp', 'O_WRONLY|O_CREAT|O_TRUNC')):
            trace += '17 openat(AT_FDCWD, ' + json.dumps(str(path)) + ', ' + flags + ') = 3\n'
        return trace.encode() + self.trace, command

    def test_unrelated_clean_trace_cannot_certify_current_output(self):
        trace, command = self.bound_trace()
        with self.assertRaisesRegex(ValueError, 'trace|command|input'):
            gate.validate_trace_binding(self.trace, self.manifest, self.directory, command)

    def test_trace_must_show_each_source_input_successfully_opened(self):
        trace, command = self.bound_trace()
        trace = trace.replace(json.dumps(str(self.source)).encode(), b'"/another/file"')
        with self.assertRaisesRegex(ValueError, 'input|trace'):
            gate.validate_trace_binding(trace, self.manifest, self.directory, command)

    def test_trace_must_show_actual_output_creation(self):
        trace, command = self.bound_trace()
        trace = trace.replace(b'FFX.exe.tmp', b'other.exe.tmp')
        with self.assertRaisesRegex(ValueError, 'output|trace'):
            gate.validate_trace_binding(trace, self.manifest, self.directory, command)

    def test_failed_input_open_is_not_build_evidence(self):
        trace, command = self.bound_trace()
        trace = trace.replace((json.dumps(str(self.source)) + ', O_RDONLY) = 3').encode(),
                              (json.dumps(str(self.source)) + ', O_RDONLY) = -1 ENOENT').encode())
        with self.assertRaisesRegex(ValueError, 'input|trace'):
            gate.validate_trace_binding(trace, self.manifest, self.directory, command)

    def test_command_metadata_must_match_the_actual_execve(self):
        trace, command = self.bound_trace()
        trace = trace.replace(b'rebuild_complete.py', b'other_script.py')
        with self.assertRaisesRegex(ValueError, 'execve|command|trace'):
            gate.validate_trace_binding(trace, self.manifest, self.directory, command)

    def test_link_only_cannot_certify_full_source_build(self):
        trace, command = self.bound_trace()
        command.append('--link-only')
        with self.assertRaisesRegex(ValueError, 'link-only|full build|command'):
            gate.validate_trace_binding(trace, self.manifest, self.directory, command)

    def test_hidden_extra_execve_argument_is_not_accepted_as_the_recorded_command(self):
        trace, command = self.bound_trace()
        runtime = command[command.index('-o') + 2:]
        prefix = ('17 execve(' + json.dumps(runtime[0]) + ', '
                  + json.dumps(runtime + ['--link-only']) + ', 0xabc) = 0\n')
        trace = prefix.encode() + trace.split(b'\n', 1)[1]
        with self.assertRaisesRegex(ValueError, 'execve|command|trace'):
            gate.validate_trace_binding(trace, self.manifest, self.directory, command)

    def test_same_basenames_in_another_directory_are_not_trusted(self):
        trace, command = self.bound_trace()
        old = str(gate.ROOT / 'tools/match')
        command = [part.replace(old, '/tmp/foreign-builder') for part in command]
        trace = trace.replace(old.encode(), b'/tmp/foreign-builder')
        with self.assertRaisesRegex(ValueError, 'trusted|command|runtime'):
            gate.validate_trace_binding(trace, self.manifest, self.directory, command)

    def test_runtime_root_must_be_the_trusted_source_root(self):
        trace, command = self.bound_trace()
        command[command.index('--root') + 1] = '/tmp/foreign-root'
        runtime = command[command.index('-o') + 2:]
        prefix = '17 execve(' + json.dumps(runtime[0]) + ', ' + json.dumps(runtime) + ', 0xabc) = 0\n'
        trace = prefix.encode() + trace.split(b'\n', 1)[1]
        with self.assertRaisesRegex(ValueError, 'trusted|command|runtime'):
            gate.validate_trace_binding(trace, self.manifest, self.directory, command)

    def test_full_build_audit_rejects_reading_the_existing_candidate(self):
        self.trace = ('17 openat(AT_FDCWD, ' + json.dumps(str(self.directory / 'FFX.exe'))
                      + ', O_RDONLY) = 9\n').encode() + self.trace
        with self.assertRaisesRegex(ValueError, 'forbidden|candidate|reference'):
            self.make_audit()

    def test_new_temp_output_is_not_confused_with_the_forbidden_candidate(self):
        prefix = ('17 openat(AT_FDCWD, ' + json.dumps(str(self.reference) + '.tmp')
                  + ', O_WRONLY|O_CREAT) = 9\n').encode()
        self.assertEqual(gate.trace_facts(prefix + self.trace, [self.reference])['observed_open_syscalls'], 3)

    def test_build_audit_binds_trace_log_manifest_and_candidate(self):
        data = self.make_audit()
        result, observed = gate.validate_audit(self.directory, self.reference, data, self.image)
        self.assertEqual(result['observed_open_syscalls'], 5)
        self.assertIn(self.directory / 'build.trace.gz', observed)

    def test_audit_cannot_attach_to_another_manifest(self):
        data = self.make_audit()
        with self.assertRaisesRegex(ValueError, 'manifest|audit'):
            gate.validate_audit(self.directory, self.reference, data + b' ', self.image)

    def test_forged_zero_open_count_is_not_trusted(self):
        data = self.make_audit()
        path = self.directory / 'source_only_audit.json'
        audit = json.loads(path.read_bytes())
        audit['observed_open_syscalls'] = 0
        path.write_text(json.dumps(audit))
        with self.assertRaisesRegex(ValueError, 'count|audit|trace'):
            gate.validate_audit(self.directory, self.reference, data, self.image)

    def test_changed_compressed_trace_is_rejected(self):
        data = self.make_audit()
        (self.directory / 'build.trace.gz').write_bytes(gzip.compress(b'edited'))
        with self.assertRaisesRegex(ValueError, 'trace'):
            gate.validate_audit(self.directory, self.reference, data, self.image)


if __name__ == '__main__':
    unittest.main()
