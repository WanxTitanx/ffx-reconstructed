"""Reject incomplete native reports instead of promoting unexecuted test cases."""
import unittest
try:
    import recovered_native as native
except ModuleNotFoundError:
    native = None


class NativeReportTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(native, 'native recovered-function verification is missing')
        self.lines = ['PASS vec3 base=%08x cases=110592 calls=221184 modes=12 alias_modes=2 relocations=283602'
                      % base for base in (0x10000000, 0x20000000, 0x50000000)]

    def test_windows_cases_include_both_complete_acceptance_rebase_addresses(self):
        self.assertTrue({0x10000000, 0x50000000}.issubset(native.BASES))

    def test_full_report_has_all_bases_and_actual_call_counts(self):
        result = native.parse_success('\n'.join(self.lines)+'\n')
        self.assertEqual(result['cases'], 331776)
        self.assertEqual(result['calls'], 663552)

    def test_missing_or_duplicate_base_is_rejected(self):
        for lines in (self.lines[:2], [self.lines[0], self.lines[0], self.lines[2]]):
            with self.subTest(lines=lines), self.assertRaises(ValueError):
                native.parse_success('\n'.join(lines))

    def test_zero_cases_wrong_relocations_or_extra_failure_is_rejected(self):
        original = '\n'.join(self.lines)
        for text in (original.replace('110592', '0'), original.replace('283602', '0'),
                     original+'\nFAIL case=0', original.replace('modes=12', 'modes=1')):
            with self.subTest(text=text[-80:]), self.assertRaises(ValueError):
                native.parse_success(text)

    def test_vs2012_linker_reports_search_paths_without_loaded_member_lines(self):
        log = b'Searching libraries\r\n    Searching C:\\VC\\LIB\\LIBCMT.lib:\r\n    Searching C:\\SDK\\x86\\kernel32.lib:\r\n    Searching C:\\VC\\LIB\\LIBCMT.lib:\r\nFinished searching libraries\r\n'
        self.assertEqual(native.library_searches(log),
                         ['C:\\SDK\\x86\\kernel32.lib', 'C:\\VC\\LIB\\LIBCMT.lib'])


if __name__ == '__main__':
    unittest.main()
