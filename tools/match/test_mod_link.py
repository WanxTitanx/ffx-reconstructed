"""Whole-image integration keeps baseline identity and requires proven entry bounds."""
import gzip
import json
from pathlib import Path
import struct
import tempfile
import unittest

import coff_emit
import coff_relocations as coff
import mod_objects
try:
    import mod_link
except ModuleNotFoundError:
    mod_link = None


class IntegrationGateTests(unittest.TestCase):
    def test_missing_reconstruction_is_not_accepted(self):
        self.assertIsNotNone(mod_link, 'modified executable build path is missing')

    def test_changes_outside_declared_regions_fail(self):
        self.assertIsNotNone(mod_link, 'modified executable build path is missing')
        with self.assertRaisesRegex(ValueError, 'undeclared'):
            mod_link.check_changes(b'abcdef', b'abxdef', [(3, 1)])

    def test_changed_fields_and_appended_sources_are_counted_exactly(self):
        self.assertIsNotNone(mod_link, 'modified executable build path is missing')
        result = mod_link.check_changes(b'abcdef', b'abxyefzz', [(2, 2), (6, 2)])
        self.assertEqual(result['different_bytes'], 4)
        self.assertEqual(result['added_bytes'], 2)


class CompiledCallerGateTests(unittest.TestCase):
    start = 0x401ff0
    target = 0x402000

    def check_caller(self, caller, relocations=(), target_body=bytes([0xc3, 0xc3])):
        with tempfile.TemporaryDirectory(prefix='ffx-coff-entry-') as temporary:
            root = Path(temporary)
            folder = root / 'recon/ffx/text_program'
            folder.mkdir(parents=True)
            padding = self.target - self.start - len(caller)
            self.assertGreater(padding, 0)
            raw = caller + bytes([0xcc]) * padding + target_body
            records = [
                {'kind': 'coff', 'ip': self.start, 'size': len(caller), 'provider': 'caller'},
                {'kind': 'padding', 'ip': self.start + len(caller), 'size': padding,
                 'value': 0xcc, 'classification': 'alignment'},
                {'kind': 'coff', 'ip': self.target, 'size': len(target_body), 'provider': 'target'},
            ]
            (folder / 'probe.jsonl.gz').write_bytes(gzip.compress(
                chr(10).join(json.dumps(row) for row in records).encode()))
            obj = coff.parse_coff(coff_emit.make_object('.probe', raw, list(relocations), {}))
            plan = {'chunks': [{'source': 'probe.jsonl.gz', 'section': '.probe', 'va': self.start}]}
            bindings = {'_sym_00402000': self.target}
            replacements = [{'va': self.target, 'size': len(target_body), 'new_va': 0x2400000}]
            mod_link.source_entry_guards(root, plan, replacements, bindings, {'.probe': obj})
            return obj['sections'][0], bindings, replacements

    def test_compiled_unrelocated_direct_branches_to_entry_or_interior_fail(self):
        for offset in (0, 1):
            destination = self.target + offset
            callers = {
                'near_call': bytes([0xe8]) + struct.pack('<i', destination - self.start - 5),
                'short_jump': bytes([0xeb, destination - self.start - 2]),
                'far_call': bytes([0x9a]) + struct.pack('<IH', destination, 0x23),
            }
            for name, caller in callers.items():
                with self.subTest(name=name, offset=offset):
                    with self.assertRaisesRegex(ValueError, 'unrelocated'):
                        self.check_caller(caller + bytes([0xc3]))

    def test_compiled_call_with_real_relocation_is_admitted_and_relinked(self):
        caller = bytes.fromhex('e800000000c3')
        section, bindings, replacements = self.check_caller(caller, [
            {'offset': 1, 'type': coff.REL32, 'symbol_name': '_sym_00402000'}])
        linked, changes, _ = mod_objects.relink(section, self.start, bindings, replacements)
        self.assertEqual(self.start + 5 + struct.unpack_from('<i', linked, 1)[0], 0x2400000)
        self.assertEqual(len(changes), 1)

    def test_unrelated_compiled_branch_does_not_block_replacement(self):
        caller = bytes([0xe8]) + struct.pack('<i', 0x403000 - self.start - 5) + bytes([0xc3])
        self.check_caller(caller)

    def test_retained_original_body_keeps_its_internal_branches(self):
        self.check_caller(bytes([0xc3]), target_body=bytes.fromhex('ebfec3'))


if __name__ == '__main__':
    unittest.main()
