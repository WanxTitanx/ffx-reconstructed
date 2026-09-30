"""Negative gates for complete-image placement and real symbol definitions."""
import unittest
from pathlib import Path
import coff_emit
import coff_relocations as coff
import pe_link


class LinkerCommandDependencyTests(unittest.TestCase):
    def test_command_wrapper_is_part_of_the_link_input_closure(self):
        wrapper = Path(pe_link.__file__).resolve().with_name('run_source_only.py')
        observed = pe_link.tool_inputs()
        self.assertIn(wrapper, set(observed))
        self.assertEqual(observed[wrapper], wrapper.read_bytes())


class FilePlacementTests(unittest.TestCase):
    def test_exact_partition_builds_the_file_in_offset_order(self):
        result = pe_link.place_file(6, [(2, b'CDEF', 'text'), (0, b'AB', 'headers')])
        self.assertEqual(result, b'ABCDEF')

    def test_even_a_zero_filled_gap_needs_a_declared_owner(self):
        with self.assertRaisesRegex(ValueError, 'gap'):
            pe_link.place_file(4, [(0, b'AB', 'headers'), (3, b'D', 'data')])

    def test_overlap_is_rejected_even_when_bytes_agree(self):
        with self.assertRaisesRegex(ValueError, 'overlap'):
            pe_link.place_file(4, [(0, b'ABC', 'headers'), (2, b'CD', 'data')])

    def test_uncovered_tail_is_rejected(self):
        with self.assertRaisesRegex(ValueError, 'cover|gap'):
            pe_link.place_file(4, [(0, b'ABC', 'headers')])

    def test_oversized_fragment_cannot_resize_the_target(self):
        with self.assertRaises(ValueError):
            pe_link.place_file(4, [(0, b'ABCDE', 'headers')])

    def test_duplicate_owner_is_rejected(self):
        with self.assertRaises(ValueError):
            pe_link.place_file(4, [(0, b'AB', 'same'), (2, b'CD', 'same')])


class SymbolPlacementTests(unittest.TestCase):
    def obj(self, name='_sym_00401002', offset=2):
        return coff.parse_coff(coff_emit.make_object('a0001000', b'\x90'*4, [], {name:offset}))

    def test_definition_comes_from_its_actual_coff_section(self):
        self.assertEqual(pe_link.definitions(self.obj(), 'a0001000', 0x401000, 4),
                         {'_sym_00401002':0x401002})

    def test_symbol_name_cannot_override_its_actual_placement(self):
        with self.assertRaises(ValueError):
            pe_link.definitions(self.obj('_sym_00401003'), 'a0001000', 0x401000, 4)

    def test_unbacked_or_missing_owner_is_not_a_definition(self):
        with self.assertRaises(ValueError):
            pe_link.definitions(self.obj(), 'missing', 0x401000, 4)

    def test_section_end_label_is_not_an_interior_symbol(self):
        with self.assertRaises(ValueError):
            pe_link.definitions(self.obj('_sym_00401004',4), 'a0001000', 0x401000, 4)


class ChunkLayoutTests(unittest.TestCase):
    def setUp(self):
        self.layout={'image_base':0x400000, 'sections':[
            {'name':'.data','virtual_address':0x2000,'raw_offset':0x400,
             'raw_size':16,'virtual_size':32}]}

    def test_file_backed_chunk_maps_to_correct_file_offset(self):
        self.assertEqual(pe_link.chunk_offset(self.layout, '.data',0x402004,4),0x404)

    def test_file_backed_chunk_cannot_cross_into_bss(self):
        with self.assertRaises(ValueError):
            pe_link.chunk_offset(self.layout, '.data',0x40200f,4)

    def test_bss_chunk_is_an_explicit_virtual_allocation(self):
        self.assertIsNone(pe_link.chunk_offset(self.layout,'.data',0x402010,16,True))

    def test_bss_must_not_overlap_file_backed_data(self):
        with self.assertRaises(ValueError):
            pe_link.chunk_offset(self.layout,'.data',0x40200f,4,True)

    def test_virtual_extent_is_bounded(self):
        with self.assertRaises(ValueError):
            pe_link.chunk_offset(self.layout,'.data',0x402020,1,True)

    def test_complete_bss_tail_can_be_partitioned(self):
        chunks=[{'original_section':'.data','va':0x402010,'size':8,'zero_storage':True},
                {'original_section':'.data','va':0x402018,'size':8,'zero_storage':True}]
        pe_link.validate_zero_storage(self.layout,chunks)

    def test_unreferenced_virtual_tail_still_requires_a_source_owner(self):
        chunks=[{'original_section':'.data','va':0x402010,'size':13,'zero_storage':True}]
        with self.assertRaisesRegex(ValueError,'zero|BSS|tail'):
            pe_link.validate_zero_storage(self.layout,chunks)

    def test_missing_entire_virtual_tail_is_rejected(self):
        with self.assertRaises(ValueError):
            pe_link.validate_zero_storage(self.layout,[])

    def test_bss_gap_and_overlap_are_rejected(self):
        for start in (0x402019,0x402017):
            chunks=[{'original_section':'.data','va':0x402010,'size':8,'zero_storage':True},
                    {'original_section':'.data','va':start,'size':0x402020-start,'zero_storage':True}]
            with self.subTest(start=start),self.assertRaises(ValueError):
                pe_link.validate_zero_storage(self.layout,chunks)


if __name__=='__main__':
    unittest.main()
