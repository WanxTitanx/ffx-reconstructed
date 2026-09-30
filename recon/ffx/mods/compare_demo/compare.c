#include "compare.h"

/* Demonstration: preserve ordering/equality, return +/-7 and record comparisons. */
volatile unsigned ffx_compare_calls;
volatile int ffx_compare_scale = 7;
volatile struct ComparisonRecord ffx_compare_recent[8];
const char ffx_compare_description[] =
    "Source-built comparison demo: static calls, added code and data, no runtime installer.";

__declspec(noinline) static int finish_comparison(unsigned length, int ordering)
{
    unsigned sequence = ffx_compare_calls + 1;
    volatile struct ComparisonRecord *record = &ffx_compare_recent[sequence & 7];
    int value = ordering * ffx_compare_scale;
    ffx_compare_calls = sequence;
    record->sequence = sequence;
    record->length = length;
    record->ordering = ordering;
    record->returned_value = value;
    return value;
}

int __cdecl FFX_memcmp_modified(const void *left, const void *right, unsigned length)
{
    const unsigned char *a = (const unsigned char *)left;
    const unsigned char *b = (const unsigned char *)right;
    unsigned i;
    for (i = 0; i < length; ++i) {
        if (a[i] != b[i])
            return finish_comparison(length, a[i] < b[i] ? -1 : 1);
    }
    return finish_comparison(length, 0);
}
