"""Regression tests for the byte-identity acceptance gate."""
import hashlib
import contextlib
import io
import json
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import definitive_match as match
import verify_inventory as inventory_check
import audit_exact


class ExactComparisonTests(unittest.TestCase):
    def test_changed_constant_is_not_a_relocation(self):
        self.assertFalse(match.equal_modulo_relocations(
            bytes.fromhex("b8efbeaddec3"), bytes.fromhex("b801004000c3"))[0])

    def test_e8_inside_an_immediate_is_not_a_call(self):
        self.assertFalse(match.equal_modulo_relocations(
            bytes.fromhex("b8e8020000c3"), bytes.fromhex("b8e8010000c3"))[0])

    def test_unresolved_call_target_is_not_exact(self):
        self.assertFalse(match.equal_modulo_relocations(
            bytes.fromhex("e801000000c3"), bytes.fromhex("e802000000c3"))[0])

    def test_exact_instructions_are_accepted_without_masking(self):
        code = bytes.fromhex("558bec8b45085dc3")
        self.assertEqual(match.equal_modulo_relocations(code, code), (True, 0))

    def test_a_shorter_candidate_is_rejected(self):
        self.assertFalse(match.equal_modulo_relocations(b"\xc3", b"\xc3\x90")[0])

    def test_a_longer_candidate_is_rejected(self):
        self.assertFalse(match.equal_modulo_relocations(b"\xc3\x90", b"\xc3")[0])


class ReferenceRangeTests(unittest.TestCase):
    def test_inventory_reader_rejects_truncated_files(self):
        read = inventory_check.make_rva_reader(b'AB', [('.text', 0x401000, 4, 0, 4)])
        self.assertIsNone(read(0x401000, 4))

    def setUp(self):
        self.read = match.va_reader(b"ABCDNEXT", [(".text", 0x401000, 8, 0, 4)])

    def test_reads_the_complete_file_backed_range(self):
        self.assertEqual(self.read(0x401000, 4), b"ABCD")

    def test_does_not_read_the_next_section_as_a_function_tail(self):
        self.assertIsNone(self.read(0x401002, 4))

    def test_does_not_read_bss_as_disk_bytes(self):
        self.assertIsNone(self.read(0x401004, 1))

    def test_does_not_accept_a_truncated_file_range(self):
        read = match.va_reader(b"AB", [(".text", 0x401000, 4, 0, 4)])
        self.assertIsNone(read(0x401000, 4))

    def test_invalid_sizes_are_rejected(self):
        for size in (0, -1):
            with self.subTest(size=size):
                self.assertIsNone(self.read(0x401000, size))


class CandidateParsingTests(unittest.TestCase):
    def assert_local_matcher(self, filename):
        script = Path(match.__file__).with_name(filename)
        program = ('import runpy; from pathlib import Path; '
                   + 'd = runpy.run_path(' + repr(str(script)) + ')["D"]; '
                   + 'assert Path(d.__file__).resolve() == Path('
                   + repr(str(Path(match.__file__).resolve())) + '); '
                   + 'assert not d.equal_modulo_relocations('
                   + 'bytes.fromhex("b8efbeaddec3"), bytes.fromhex("b801004000c3"))[0]')
        result = subprocess.run([sys.executable, '-c', program],
                                capture_output=True, text=True)
        self.assertEqual(result.returncode, 0, result.stderr)

    def test_symbol_attribution_uses_the_same_worktree_matcher(self):
        self.assert_local_matcher('symbol_attrib.py')

    def test_bulk_attribution_uses_the_same_worktree_matcher(self):
        self.assert_local_matcher('symbol_bulk.py')

    def test_snapshot_is_used_after_the_file_changes(self):
        snapshot = '_sample:' + chr(10) + '  00000000: C3  ret' + chr(10)
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'candidate.txt'
            path.write_text('_changed:' + chr(10) + '  00000000: 90  nop' + chr(10))
            functions = match.functions_from_dump(path, source_text=snapshot)
            self.assertEqual(match.contiguous(functions[0][1]), bytes.fromhex('c3'))

    def test_empty_candidate_does_not_raise(self):
        self.assertIsNone(match.contiguous([]))

    def test_address_gap_rejects_the_candidate(self):
        self.assertIsNone(match.contiguous([(0, b"\x55"), (2, b"\xc3")]))

    def test_uppercase_mnemonic_does_not_become_a_byte(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "candidate.txt"
            path.write_text("_sample:\n  00000000: 83 C0 01           ADD eax,1\n"
                            "  00000003: C3                 RET\n")
            functions = match.functions_from_dump(path)
            self.assertEqual(match.contiguous(functions[0][1]), bytes.fromhex("83c001c3"))


class CommandLineTests(unittest.TestCase):
    def test_inventory_verifier_fails_a_bad_hash(self):
        self.inventory.write_text(self.inventory.read_text().replace(
            hashlib.sha256(self.code).hexdigest(), '0' * 64))
        script = Path(match.__file__).with_name('verify_inventory.py')
        result = subprocess.run([sys.executable, str(script), str(self.exe),
                                 str(self.inventory)], capture_output=True, text=True)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn('sha256 mismatches    : 1', result.stdout)

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.code = bytes.fromhex("b801004000c3") + b"\x90" * 10
        image = bytearray(0x210)
        image[:2] = b"MZ"
        struct.pack_into("<I", image, 0x3c, 0x80)
        image[0x80:0x84] = b"PE\x00\x00"
        struct.pack_into("<HHIIIHH", image, 0x84, 0x14c, 1, 0, 0, 0, 224, 0x102)
        struct.pack_into("<H", image, 0x98, 0x10b)
        struct.pack_into("<I", image, 0x98 + 28, 0x400000)
        image[0x178:0x180] = b".text\x00\x00\x00"
        struct.pack_into("<IIII", image, 0x180, 16, 0x1000, 16, 0x200)
        image[0x200:] = self.code
        self.exe = self.root / "reference.exe"
        self.exe.write_bytes(image)
        self.digest = hashlib.sha256(image).hexdigest()
        self.inventory = self.root / "inventory.tsv"
        self.inventory.write_text("start\tend\tsize\tchunks\tsha256\tname\n"
                                  "0x401000\t0x401010\t16\t1\t"
                                  + hashlib.sha256(self.code).hexdigest() + "\tsample\n")
        self.dumps = self.root / "dis"
        self.dumps.mkdir()
        self.output = self.root / "result.json"

    def run_match(self, code, *flags):
        (self.dumps / "sample.txt").write_text(
            "_sample:\n  00000000: " + code.hex(" ").upper() + "  nop\n")
        return subprocess.run([sys.executable, str(Path(match.__file__)),
                               str(self.dumps), str(self.inventory), str(self.output),
                               "--exe", str(self.exe), "--expected-sha256", self.digest,
                               *flags], capture_output=True, text=True)

    def add_quarantined_duplicate(self):
        image = bytearray(self.exe.read_bytes() + self.code)
        struct.pack_into('<I', image, 0x180, 32)
        struct.pack_into('<I', image, 0x188, 32)
        self.exe.write_bytes(image)
        self.digest = hashlib.sha256(image).hexdigest()
        self.inventory.write_text(self.inventory.read_text()
                                  + '0x401010\t0x401020\t16\t1\t'
                                  + '0' * 64 + '\trival\n')

    def test_quarantined_competitor_preserves_ambiguity(self):
        self.add_quarantined_duplicate()
        result = self.run_match(self.code, '--quarantine-invalid-inventory')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(json.loads(self.output.read_text()), [])

    def test_quarantined_address_does_not_receive_coverage(self):
        self.inventory.write_text(self.inventory.read_text().replace(
            hashlib.sha256(self.code).hexdigest(), '0' * 64))
        result = self.run_match(self.code, '--quarantine-invalid-inventory')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(json.loads(self.output.read_text()), [])

    def test_audit_preserves_quarantined_competitors(self):
        self.add_quarantined_duplicate()
        project = self.root / 'project'
        directory = project / 'tools/match/lua_all_out/dis'
        directory.mkdir(parents=True)
        (directory / 'sample.txt').write_text(
            '_sample:\n  00000000: ' + self.code.hex(' ').upper() + '  nop\n')
        (project / 'tools/match/inventory.tsv').write_bytes(self.inventory.read_bytes())
        output = self.root / 'audit'
        argv = ['audit_exact.py', '--project', str(project), '--exe', str(self.exe),
                '--output-dir', str(output)]
        with patch.object(match, 'EXE_SHA256', self.digest), patch.object(sys, 'argv', argv):
            with contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(audit_exact.main(), 0)
        report = json.loads((output / 'audit.json').read_text())
        self.assertEqual(report['unique_exact_functions'], 0)
        self.assertEqual(len(report['excluded_rows']), 1)

    def run_inventory_check(self):
        return subprocess.run([sys.executable, str(Path(inventory_check.__file__)),
                               str(self.exe), str(self.inventory)],
                              capture_output=True, text=True)

    def test_inventory_verifier_rejects_truncated_reference(self):
        self.exe.write_bytes(self.exe.read_bytes()[:-2])
        self.inventory.write_text(self.inventory.read_text().replace(
            hashlib.sha256(self.code).hexdigest(), hashlib.sha256(self.code[:-2]).hexdigest()))
        self.assertNotEqual(self.run_inventory_check().returncode, 0)

    def test_inventory_verifier_rejects_malformed_row(self):
        self.inventory.write_text(self.inventory.read_text() + '0x401004\tTRUNCATED_ROW\n')
        self.assertNotEqual(self.run_inventory_check().returncode, 0)

    def test_inventory_verifier_rejects_duplicate_addresses(self):
        original = self.inventory.read_text()
        self.inventory.write_text(original + original.splitlines()[1] + '\n')
        self.assertNotEqual(self.run_inventory_check().returncode, 0)

    def test_inventory_verifier_reports_empty_inventory(self):
        self.inventory.write_text(self.inventory.read_text().splitlines()[0] + '\n')
        result = self.run_inventory_check()
        self.assertNotEqual(result.returncode, 0)
        self.assertIn('inventory is empty', result.stderr)

    def test_cli_records_exact_bytes_and_provenance(self):
        result = self.run_match(self.code)
        self.assertEqual(result.returncode, 0, result.stderr)
        records = json.loads(self.output.read_text())
        self.assertEqual(len(records), 1)
        self.assertEqual(records[0]["match_kind"], "exact_bytes")
        self.assertTrue(records[0]["byte_identical"])
        self.assertEqual(records[0]["candidate_sha256"], records[0]["reference_sha256"])

    def test_cli_does_not_count_the_false_positive(self):
        result = self.run_match(bytes.fromhex("b8efbeaddec3") + b"\x90" * 10)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(json.loads(self.output.read_text()), [])

    def test_heuristic_mode_is_explicitly_unverified(self):
        result = self.run_match(bytes.fromhex("b8efbeaddec3") + b"\x90" * 10,
                                "--heuristic-candidates")
        self.assertEqual(result.returncode, 0, result.stderr)
        records = json.loads(self.output.read_text())
        self.assertEqual(records[0]["match_kind"], "heuristic_candidate")
        self.assertFalse(records[0]["byte_identical"])

    def test_wrong_target_hash_fails_before_writing_results(self):
        self.digest = "0" * 64
        result = self.run_match(self.code)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("SHA-256", result.stderr)
        self.assertFalse(self.output.exists())

    def test_wrong_inventory_hash_fails_before_writing_results(self):
        self.inventory.write_text(self.inventory.read_text().replace(
            hashlib.sha256(self.code).hexdigest(), "0" * 64))
        result = self.run_match(self.code)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("inventory", result.stderr.lower())
        self.assertFalse(self.output.exists())

    def test_matcher_rejects_ambiguous_or_truncated_inventory_columns(self):
        header, row = self.inventory.read_text().splitlines()
        invalid = (
            header + '\tstart\n' + row + '\t0x401000\n',
            header + '\n' + row + '\tEXTRA_FIELD\n',
            header + '\n' + row.rsplit('\t', 1)[0] + '\n',
        )
        for text in invalid:
            with self.subTest(inventory=text):
                self.inventory.write_text(text)
                result = self.run_match(self.code)
                self.assertNotEqual(result.returncode, 0)


if __name__ == "__main__":
    unittest.main()
