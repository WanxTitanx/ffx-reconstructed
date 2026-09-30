"""The final gate compares every byte, independent of recorded section hashes."""
import unittest
import verify_complete_image as complete


class FullComparisonTests(unittest.TestCase):
    def test_equal_files_report_all_compared_bytes(self):
        report=complete.compare_bytes(b'MZabc',b'MZabc')
        self.assertTrue(report['literal_equal'])
        self.assertEqual(report['compared_bytes'],5)
        self.assertEqual(report['different_bytes'],0)

    def test_one_changed_byte_is_a_failure_with_its_offset(self):
        report=complete.compare_bytes(b'MZabc',b'MZaxc')
        self.assertFalse(report['literal_equal'])
        self.assertEqual(report['first_difference'],3)
        self.assertEqual(report['different_bytes'],1)

    def test_equal_prefix_is_not_equal_file(self):
        report=complete.compare_bytes(b'MZabc',b'MZabc\0')
        self.assertFalse(report['literal_equal'])
        self.assertEqual(report['first_difference'],5)
        self.assertEqual(report['different_bytes'],1)


if __name__=='__main__': unittest.main()
