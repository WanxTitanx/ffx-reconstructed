"""Behavioral regressions for structured header and relocation emission."""
import copy
import contextlib
import gzip
import hashlib
import io
import json
import struct
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch
from iced_x86 import Code, Encoder, Instruction, Register
import pe_structure

try:
    import pe_headers as headers
except ModuleNotFoundError as exc:
    if exc.name != 'pe_headers':
        raise
    headers = None

MESSAGE = 'This program cannot be run in DOS mode.' + chr(13) * 2 + chr(10) + '$'


def rol(value, shift):
    shift %= 32
    return ((value << shift) | (value >> (32 - shift))) & 0xffffffff


def fixture():
    """Independent field-built PE fixture with freshly assembled instructions."""
    data = bytearray(0x800)
    words = [0x5a4d, 0x90, 3, 0, 4, 0, 0xffff, 0, 0xb8, 0, 0, 0, 0x40, 0]
    struct.pack_into('<30HI', data, 0, *(words + [0] * 16 + [0x100]))
    instructions = [Instruction.create_reg(Code.PUSHW_CS, Register.CS),
                    Instruction.create_reg(Code.POPW_DS, Register.DS),
                    Instruction.create_reg_i32(Code.MOV_R16_IMM16, Register.DX, 14),
                    Instruction.create_reg_i32(Code.MOV_R8_IMM8, Register.AH, 9),
                    Instruction.create_i32(Code.INT_IMM8, 0x21),
                    Instruction.create_reg_i32(Code.MOV_R16_IMM16, Register.AX, 0x4c01),
                    Instruction.create_i32(Code.INT_IMM8, 0x21)]
    encoder, ip = Encoder(16), 0
    for instruction in instructions:
        ip += encoder.encode(instruction, ip)
    code = encoder.take_buffer()
    assert len(code) == 14
    data[0x40:0x4e] = code
    data[0x4e:0x79] = MESSAGE.encode('ascii')
    records = [(0x00d3c627, 79), (0x00010000, 540)]
    key = 0x80
    for at, byte in enumerate(data[:0x80]):
        if not 0x3c <= at < 0x40:
            key = (key + rol(byte, at)) & 0xffffffff
    for product, count in records:
        key = (key + rol(product, count)) & 0xffffffff
    decoded = [0x536e6144, 0, 0, 0] + [v for pair in records for v in pair]
    for index, value in enumerate(decoded):
        struct.pack_into('<I', data, 0x80 + index * 4, value ^ key)
    data[0xa0:0xa4] = b'Rich'
    struct.pack_into('<I', data, 0xa4, key)
    data[0x100:0x104] = b'PE' + bytes(2)
    struct.pack_into('<HHIIIHH', data, 0x104, 0x14c, 2, 123456, 0, 0, 224, 0x102)
    opt = 0x118
    struct.pack_into('<HBBIIIIII', data, opt, 0x10b, 11, 0, 0x200, 0x200, 0, 0x1000, 0x1000, 0x2000)
    struct.pack_into('<III', data, opt + 28, 0x400000, 0x1000, 0x200)
    struct.pack_into('<III', data, opt + 56, 0x3000, 0x400, 0)
    struct.pack_into('<HHIIIIII', data, opt + 68, 3, 0x140, 0x100000, 0x1000, 0x100000, 0x1000, 0, 16)
    struct.pack_into('<II', data, opt + 96 + 5 * 8, 0x2000, 16)
    for index, (name, rva, raw, flags) in enumerate([(b'.text', 0x1000, 0x400, 0x60000020),
                                                   (b'.reloc', 0x2000, 0x600, 0x42000040)]):
        struct.pack_into('<8sIIIIIIHHI', data, opt + 224 + index * 40, name,
                         0x200, rva, 0x200, raw, 0, 0, 0, 0, flags)
    struct.pack_into('<IIHHHH', data, 0x600, 0x1000, 16, 0x3010, 0x3024, 0, 5)
    return bytes(data)


class HeaderTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(headers, 'structured header builder is missing')
        self.data = fixture()
        self.model = headers.prepare(self.data)

    def test_exact_roundtrip_and_json_safe_source(self):
        model = json.loads(json.dumps(self.model))
        self.assertEqual(headers.emit_headers(model), self.data[:0x400])
        self.assertEqual(headers.native_layout(model), pe_structure.parse_layout(self.data))

    def test_explicit_fields_and_instruction_source(self):
        self.assertEqual(self.model['dos_header']['e_cparhdr'], 4)
        self.assertEqual(self.model['rich']['records'][0], {'product_id': 211, 'build': 50727, 'count': 79})
        stub = self.model['dos_stub']
        self.assertEqual((stub['bitness'], len(stub['instructions'])), (16, 7))
        self.assertEqual(stub['instructions'][2]['operands'][1]['value'], 14)
        self.assertEqual(stub['message'], MESSAGE)

    def test_emitters_never_read_or_parse_reference_image(self):
        with patch.object(Path, 'read_bytes', side_effect=AssertionError('file read')):
            with patch.object(pe_structure, 'parse_layout', side_effect=AssertionError('PE parse')):
                self.assertEqual(headers.emit_headers(self.model), self.data[:0x400])
                self.assertEqual(headers.emit_base_relocations(self.model), self.data[0x600:])

    def test_mutated_nt_timestamp_changes_only_its_field(self):
        self.model['layout']['coff']['time_date_stamp'] += 1
        expected = bytearray(self.data[:0x400])
        struct.pack_into('<I', expected, 0x108, 123457)
        self.assertEqual(headers.emit_headers(self.model), bytes(expected))

    def test_unknown_nonzero_padding_fails(self):
        for offset in (0x79, 0xac, 0x250, 0x3ff):
            data = bytearray(self.data)
            data[offset] = 1
            with self.subTest(offset=offset), self.assertRaisesRegex(ValueError, 'padding|Rich|zero'):
                headers.prepare(bytes(data))

    def test_unknown_dos_code_message_reserved_and_relocations_fail(self):
        for offset in (6, 28, 40, 0x40, 0x4e):
            data = bytearray(self.data)
            data[offset] ^= 1
            with self.subTest(offset=offset), self.assertRaisesRegex(ValueError, 'DOS|stub|message|reserved'):
                headers.prepare(bytes(data))

    def test_rich_checksum_signature_and_reserved_words_are_checked(self):
        for offset in (0x80, 0x84, 0x90, 0xa4):
            data = bytearray(self.data)
            data[offset] ^= 1
            with self.subTest(offset=offset), self.assertRaisesRegex(ValueError, 'Rich|DanS|checksum'):
                headers.prepare(bytes(data))

    def test_rich_count_or_key_mutation_requires_checksum_update(self):
        for field in ('count', 'key'):
            model = copy.deepcopy(self.model)
            record = model['rich']['records'][0] if field == 'count' else model['rich']
            record[field] += 1
            with self.subTest(field=field), self.assertRaisesRegex(ValueError, 'Rich|checksum'):
                headers.emit_headers(model)

    def test_rich_records_are_editable_with_an_explicit_new_checksum(self):
        self.model['rich']['records'][0]['count'] += 1
        prefix = self.data[:self.model['rich']['offset']]
        key = len(prefix)
        for at, value in enumerate(prefix):
            if not 0x3c <= at < 0x40:
                key = (key + rol(value, at)) & 0xffffffff
        for item in self.model['rich']['records']:
            key = (key + rol(item['product_id'] * 65536 + item['build'], item['count'])) & 0xffffffff
        self.model['rich']['key'] = key
        result = headers.emit_headers(self.model)
        self.assertNotEqual(result, self.data[:0x400])
        reparsed = headers.prepare(result + self.data[0x400:])
        self.assertEqual(reparsed['rich'], self.model['rich'])

    def test_dos_field_edits_are_serialized_after_updating_rich_checksum(self):
        self.model['dos_header']['e_sp'] += 2
        prefix = bytearray(self.data[:self.model['rich']['offset']])
        struct.pack_into('<H', prefix, 16, self.model['dos_header']['e_sp'])
        key = len(prefix)
        for at, value in enumerate(prefix):
            if not 0x3c <= at < 0x40:
                key = (key + rol(value, at)) & 0xffffffff
        for item in self.model['rich']['records']:
            key = (key + rol(item['product_id'] * 65536 + item['build'], item['count'])) & 0xffffffff
        self.model['rich']['key'] = key
        result = headers.emit_headers(self.model)
        self.assertEqual(struct.unpack_from('<H', result, 16)[0], 0xba)
        self.assertEqual(headers.prepare(result + self.data[0x400:])['dos_header'], self.model['dos_header'])

    def test_rich_offsets_and_field_widths_are_checked(self):
        for field in ('offset', 'marker_offset', 'product_id', 'build'):
            model = copy.deepcopy(self.model)
            if field in ('offset', 'marker_offset'):
                model['rich'][field] += 4
            else:
                model['rich']['records'][0][field] = 65536
            with self.subTest(field=field), self.assertRaises(ValueError):
                headers.emit_headers(model)

    def test_dos_pe_offset_must_agree_with_layout(self):
        self.model['dos_header']['e_lfanew'] += 4
        with self.assertRaisesRegex(ValueError, 'DOS|offset'):
            headers.emit_headers(self.model)

    def test_padding_overlap_and_missing_coverage_fail(self):
        for mode in ('overlap', 'missing'):
            model = copy.deepcopy(self.model)
            if mode == 'overlap':
                model['zero_padding'][0]['offset'] -= 1
            else:
                model['zero_padding'].pop()
            with self.subTest(mode=mode), self.assertRaisesRegex(ValueError, 'padding|overlap|coverage'):
                headers.emit_headers(model)

    def test_opcode_blob_is_not_an_instruction_source(self):
        self.model['dos_stub']['instructions'][0]['raw'] = [14]
        with self.assertRaisesRegex(ValueError, 'source|field|stub|instruction'):
            headers.emit_headers(self.model)

    def test_truncated_image_and_unsupported_schema_fail(self):
        with self.assertRaises(ValueError):
            headers.prepare(self.data[:-1])
        self.model['schema_version'] = 999
        with self.assertRaisesRegex(ValueError, 'schema'):
            headers.emit_headers(self.model)


class RelocationTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(headers, 'structured relocation builder is missing')
        self.data = fixture()
        self.model = headers.prepare(self.data)
        self.reloc = self.model['base_relocations']

    def test_full_section_roundtrip_preserves_abs_offsets_and_zero_tail(self):
        self.assertEqual(headers.emit_base_relocations(self.model), self.data[0x600:])
        self.assertEqual(self.reloc['zero_tail_size'], 0x200 - 16)
        self.assertEqual(self.reloc['blocks'][0]['entries'][3], {'type': 0, 'offset': 5})

    def test_exact_highlow_sets_ignore_order_but_not_values(self):
        for sites in ({0x401010, 0x401024}, [0x401024, 0x401010]):
            self.assertEqual(headers.emit_base_relocations(self.model, sites), self.data[0x600:])

    def test_missing_extra_and_same_count_wrong_sites_fail(self):
        for sites in ([], [0x401010], [0x401010, 0x401025], [0x401010, 0x401024, 0x401030]):
            with self.subTest(sites=sites), self.assertRaisesRegex(ValueError, 'HIGHLOW|site'):
                headers.emit_base_relocations(self.model, sites)

    def test_duplicate_and_malformed_expected_sites_fail(self):
        for sites in ([0x401010, 0x401024, 0x401024], [True, 0x401024],
                      ['0x401010', 0x401024], [-1, 0x401024], {0x401010: 1, 0x401024: 1}):
            with self.subTest(sites=sites), self.assertRaisesRegex(ValueError, 'HIGHLOW|site'):
                headers.emit_base_relocations(self.model, sites)

    def test_editing_an_offset_changes_emitted_record(self):
        self.reloc['blocks'][0]['entries'][1]['offset'] = 0x30
        expected = bytearray(self.data[0x600:])
        struct.pack_into('<H', expected, 10, 0x3030)
        self.assertEqual(headers.emit_base_relocations(self.model, [0x401010, 0x401030]), bytes(expected))

    def test_duplicate_and_overlapping_highlow_sites_fail(self):
        for offset in (0x10, 0x11, 0x12, 0x13):
            self.reloc['blocks'][0]['entries'][1]['offset'] = offset
            with self.subTest(offset=offset), self.assertRaisesRegex(ValueError, 'duplicate|overlap'):
                headers.emit_base_relocations(self.model)

    def test_invalid_block_size_alignment_and_field_widths_fail(self):
        for field in ('block_size', 'page_rva', 'offset', 'type'):
            model = copy.deepcopy(self.model)
            block = model['base_relocations']['blocks'][0]
            if field == 'block_size':
                block[field] += 2
            elif field == 'page_rva':
                block[field] += 1
            else:
                block['entries'][0][field] = 4096 if field == 'offset' else 16
            with self.subTest(field=field), self.assertRaises(ValueError):
                headers.emit_base_relocations(model)

    def test_unsupported_type_fails(self):
        self.reloc['blocks'][0]['entries'][0]['type'] = 4
        with self.assertRaisesRegex(ValueError, 'unsupported|type'):
            headers.emit_base_relocations(self.model)

    def test_sites_must_fit_mapped_image(self):
        for page in (0, 0x3000, 0xfffff000):
            self.reloc['blocks'][0]['page_rva'] = page
            self.reloc['blocks'][0]['entries'][0]['offset'] = 0xffe
            with self.subTest(page=page), self.assertRaisesRegex(ValueError, 'site|mapped|range|image'):
                headers.emit_base_relocations(self.model)

    def test_nonzero_tail_and_invalid_block_rejected_during_prepare(self):
        for offset, value in ((0x7ff, 1), (0x604, 7)):
            data = bytearray(self.data)
            data[offset] = value
            with self.subTest(offset=offset), self.assertRaisesRegex(ValueError, 'tail|zero|block'):
                headers.prepare(bytes(data))

    def test_raw_and_directory_declarations_must_agree_with_nt_fields(self):
        for field in ('raw_size', 'directory_size', 'directory_rva', 'zero_tail_size'):
            model = copy.deepcopy(self.model)
            model['base_relocations'][field] += 4
            with self.subTest(field=field), self.assertRaises(ValueError):
                headers.emit_base_relocations(model)

    def test_truncated_directory_and_duplicate_sites_fail_on_prepare(self):
        data = bytearray(self.data)
        struct.pack_into('<H', data, 0x60a, 0x3010)
        with self.assertRaisesRegex(ValueError, 'duplicate|overlap'):
            headers.prepare(bytes(data))
        data = bytearray(self.data)
        struct.pack_into('<I', data, 0x118 + 96 + 5 * 8 + 4, 14)
        with self.assertRaisesRegex(ValueError, 'block|directory'):
            headers.prepare(bytes(data))

    def test_leading_zero_gap_before_active_directory_is_preserved(self):
        data = bytearray(self.data)
        data[0x620:0x630] = data[0x600:0x610]
        data[0x600:0x610] = bytes(16)
        struct.pack_into('<I', data, 0x118 + 96 + 5 * 8, 0x2020)
        model = headers.prepare(bytes(data))
        self.assertEqual(model['base_relocations']['zero_prefix_size'], 32)
        self.assertEqual(headers.emit_base_relocations(model), bytes(data[0x600:]))


class CommandLineTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(headers, 'structured header builder is missing')
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.source = self.root / 'input.json.gz'
        self.model = headers.prepare(fixture())
        self.source.write_bytes(gzip.compress(json.dumps(self.model).encode('utf-8'), mtime=0))
        self.output = self.root / 'build'

    def test_build_uses_source_and_records_tool_hashes_without_original(self):
        with patch.object(headers, 'EXE_DEFAULT', self.root / 'MISSING.exe'):
            with contextlib.redirect_stdout(io.StringIO()):
                result = headers.main(['build', '--source', str(self.source), '--output', str(self.output)])
        self.assertEqual(result, 0)
        proof = json.loads((self.output / 'proof.json').read_text())
        self.assertIsNone(proof['input_image_sha256'])
        self.assertIsNone(proof['header_roundtrip_exact'])
        self.assertFalse(proof['supplied_linker_highlow_sites_verified'])
        self.assertFalse(proof['whole_executable_reconstructed'])
        self.assertEqual(proof['tools']['iced_x86_version'], '1.21.0')
        self.assertTrue(any(p.endswith('x86_source.py') for p in proof['tools']['files']))
        self.assertEqual(proof['source_sha256'], hashlib.sha256((self.output / 'source.json.gz').read_bytes()).hexdigest())
        self.assertEqual((self.output / 'headers.bin').read_bytes(), fixture()[:0x400])

    def test_failed_rebuild_does_not_leave_a_stale_success_proof(self):
        self.output.mkdir()
        old_proof = self.output / 'proof.json'
        old_proof.write_text('{"header_roundtrip_exact":true}')
        self.source.write_bytes(gzip.compress(b'{bad JSON', mtime=0))
        with self.assertRaises(ValueError):
            headers.main(['build', '--source', str(self.source), '--output', str(self.output)])
        self.assertFalse(old_proof.exists(), 'failed rebuild left an earlier success report')


if __name__ == '__main__':
    unittest.main()
