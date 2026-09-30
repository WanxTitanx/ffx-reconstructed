"""Regressions for deterministic PE model extension with standalone mod sections."""
import copy
import gzip
import json
import unittest
from pathlib import Path

import pe_headers
import pe_structure
from test_pe_headers import fixture

try:
    import mod_layout
except ModuleNotFoundError as exc:
    if exc.name != 'mod_layout':
        raise
    mod_layout = None


ROOT = Path(__file__).resolve().parents[2]


def load_real_model():
    source = ROOT / 'recon/ffx/pe_headers/source.json.gz'
    return json.loads(gzip.decompress(source.read_bytes()))


def synthetic_image(model, sites):
    layout = pe_headers.native_layout(model)
    headers = pe_headers.emit_headers(model)
    reloc = pe_headers.emit_base_relocations(model, sites)
    section = next(item for item in layout['sections'] if item['name'] == '.reloc')
    image = bytearray(layout['file_size'])
    image[:len(headers)] = headers
    image[section['raw_offset']:section['raw_offset'] + len(reloc)] = reloc
    return bytes(image)


class ModLayoutTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(mod_layout, 'mod layout extension is missing')
        self.data = fixture()
        self.model = pe_headers.prepare(self.data)

    def test_appends_aligned_sections_and_preserves_the_original_model(self):
        original = copy.deepcopy(self.model)
        sizes = {'.moddat': 0x111, '.modtxt': 0x123, '.modro': 0x201}
        sites = [0x405004, 0x401024, 0x403010, 0x401010]

        result = mod_layout.extend_model(self.model, sizes, sites)

        self.assertEqual(self.model, original)
        self.assertIsNot(result, self.model)
        self.assertEqual(result['layout']['sections'][:2], original['layout']['sections'])
        added = result['layout']['sections'][2:]
        self.assertEqual([item['name'] for item in added], ['.modtxt', '.modro', '.moddat'])
        self.assertEqual([item['index'] for item in added], [3, 4, 5])
        self.assertEqual([item['characteristics'] for item in added],
                         [0x60000020, 0x40000040, 0xc0000040])
        self.assertEqual([item['virtual_size'] for item in added], [0x123, 0x201, 0x111])
        self.assertEqual([item['virtual_address'] for item in added], [0x3000, 0x4000, 0x5000])
        self.assertEqual([item['raw_offset'] for item in added], [0x800, 0xa00, 0xe00])
        self.assertEqual([item['raw_size'] for item in added], [0x200, 0x400, 0x200])
        for item in added:
            self.assertEqual((item['relocation_offset'], item['line_number_offset'],
                              item['relocation_count'], item['line_number_count']), (0, 0, 0, 0))
            self.assertEqual(len(item['name_bytes'].encode('latin-1')), 8)

        old_opt = original['layout']['optional_header']
        opt = result['layout']['optional_header']
        self.assertEqual(result['layout']['coff']['number_of_sections'], 5)
        self.assertEqual(opt['size_of_code'], old_opt['size_of_code'] + 0x200)
        self.assertEqual(opt['size_of_initialized_data'],
                         old_opt['size_of_initialized_data'] + 0x400 + 0x200)
        self.assertEqual(opt['size_of_uninitialized_data'], old_opt['size_of_uninitialized_data'])
        self.assertEqual(opt['checksum'], 0)
        self.assertEqual(opt['size_of_image'], 0x6000)
        self.assertEqual(result['layout']['file_size'], 0x1000)

        json_model = json.loads(json.dumps(result))
        image = synthetic_image(json_model, sites)
        parsed = pe_structure.parse_layout(image)
        self.assertEqual(parsed, pe_headers.native_layout(json_model))
        self.assertEqual(pe_structure.emit_nt_headers(parsed),
                         pe_structure.emit_nt_headers(pe_headers.native_layout(json_model)))

    def test_requested_subset_uses_canonical_section_order(self):
        result = mod_layout.extend_model(
            self.model, {'.moddat': 1, '.modtxt': 1}, [0x401010])
        self.assertEqual([item['name'] for item in result['layout']['sections'][-2:]],
                         ['.modtxt', '.moddat'])

    def test_relocation_blocks_are_sorted_and_canonically_padded(self):
        sites = [0x404008, 0x401024, 0x40300c, 0x401010, 0x403004]
        result = mod_layout.extend_model(self.model, {'.modtxt': 0x1200}, sites)
        blocks = result['base_relocations']['blocks']

        self.assertEqual([block['page_rva'] for block in blocks], [0x1000, 0x3000, 0x4000])
        self.assertEqual(blocks[0], {
            'page_rva': 0x1000, 'block_size': 12,
            'entries': [{'type': 3, 'offset': 0x10}, {'type': 3, 'offset': 0x24}],
        })
        self.assertEqual(blocks[1], {
            'page_rva': 0x3000, 'block_size': 12,
            'entries': [{'type': 3, 'offset': 4}, {'type': 3, 'offset': 0xc}],
        })
        self.assertEqual(blocks[2], {
            'page_rva': 0x4000, 'block_size': 12,
            'entries': [{'type': 3, 'offset': 8}, {'type': 0, 'offset': 0}],
        })
        self.assertEqual(result['layout']['directories'][5]['size'], 36)
        self.assertEqual(result['base_relocations']['directory_size'], 36)
        self.assertEqual(result['base_relocations']['zero_tail_size'], 0x200 - 36)
        self.assertEqual(pe_headers.emit_base_relocations(result, sites),
                         synthetic_image(result, sites)[0x600:0x800])

    def test_duplicate_overlapping_and_malformed_highlow_sites_fail_without_mutation(self):
        invalid = (
            [0x401010, 0x401010],
            [0x401010, 0x401011],
            [0x401010, 0x401013],
            [True],
            ['0x401010'],
            (0x401010,),
        )
        for sites in invalid:
            model = copy.deepcopy(self.model)
            before = copy.deepcopy(model)
            with self.subTest(sites=sites), self.assertRaisesRegex(
                    (TypeError, ValueError), 'HIGHLOW|site|list|overlap|duplicate'):
                mod_layout.extend_model(model, {'.modtxt': 1}, sites)
            self.assertEqual(model, before)

    def test_highlow_site_must_fit_a_mapped_range(self):
        before = copy.deepcopy(self.model)
        with self.assertRaisesRegex(ValueError, 'HIGHLOW|site|mapped|range'):
            mod_layout.extend_model(self.model, {'.modtxt': 1}, [0x402800])
        self.assertEqual(self.model, before)

    def test_relocation_directory_overflow_fails_instead_of_moving_sections(self):
        first_new_rva = 0x3000
        sites = [0x400000 + first_new_rva + page * 0x1000 + 0x100 for page in range(43)]
        before = copy.deepcopy(self.model)
        with self.assertRaisesRegex(ValueError, 'relocation|capacity|overflow'):
            mod_layout.extend_model(self.model, {'.modtxt': 43 * 0x1000}, sites)
        self.assertEqual(self.model, before)
        self.assertEqual(self.model['layout']['sections'][-1]['raw_offset'], 0x600)

    def test_exact_three_header_capacity_and_exhaustion(self):
        model = load_real_model()
        original_sections = copy.deepcopy(model['layout']['sections'])
        site = model['layout']['image_base'] + model['layout']['sections'][0]['virtual_address']
        expanded = mod_layout.extend_model(
            model, {'.modtxt': 1, '.modro': 1, '.moddat': 1}, [site])
        self.assertEqual(expanded['layout']['sections'][:7], original_sections)

        layout = expanded['layout']
        table_end = (layout['pe_offset'] + 24 + layout['coff']['size_of_optional_header']
                     + 40 * len(layout['sections']))
        self.assertEqual(layout['optional_header']['size_of_headers'] - table_end, 32)
        for index, section in enumerate(layout['sections'][-3:], 1):
            name = f'.x{index}'
            section['name'] = name
            section['name_bytes'] = name + chr(0) * (8 - len(name))
        crowded = copy.deepcopy(expanded)
        with self.assertRaisesRegex(ValueError, 'header|capacity'):
            mod_layout.extend_model(expanded, {'.modtxt': 1}, [site])
        self.assertEqual(expanded, crowded)

    def test_invalid_sizes_certificate_and_overlay_are_rejected_without_mutation(self):
        invalid_sizes = (
            {'.bad': 1},
            {1: 1},
            {'.modtxt': 0},
            {'.modtxt': -1},
            {'.modtxt': True},
            {'.modtxt': '1'},
            [],
        )
        for sizes in invalid_sizes:
            model = copy.deepcopy(self.model)
            before = copy.deepcopy(model)
            with self.subTest(sizes=sizes), self.assertRaisesRegex(
                    (TypeError, ValueError), 'size|section|key|mapping|dictionary'):
                mod_layout.extend_model(model, sizes, [0x401010])
            self.assertEqual(model, before)

        certificate = copy.deepcopy(self.model)
        certificate['layout']['directories'][4]['rva'] = 0x700
        certificate['layout']['directories'][4]['size'] = 1
        before = copy.deepcopy(certificate)
        with self.assertRaisesRegex(ValueError, 'certificate|security'):
            mod_layout.extend_model(certificate, {'.modtxt': 1}, [0x401010])
        self.assertEqual(certificate, before)

        overlay = copy.deepcopy(self.model)
        overlay['layout']['file_size'] += 1
        before = copy.deepcopy(overlay)
        with self.assertRaisesRegex(ValueError, 'overlay|file size'):
            mod_layout.extend_model(overlay, {'.modtxt': 1}, [0x401010])
        self.assertEqual(overlay, before)


if __name__ == '__main__':
    unittest.main()
