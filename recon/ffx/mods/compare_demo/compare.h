/* Freestanding i386 interface: cdecl and 32-bit unsigned match FFX_memcmp. */
struct ComparisonRecord {
    unsigned sequence;
    unsigned length;
    int ordering;
    int returned_value;
};
extern volatile unsigned ffx_compare_calls;
extern volatile int ffx_compare_scale;
extern volatile struct ComparisonRecord ffx_compare_recent[8];
int __cdecl FFX_memcmp_modified(const void *left, const void *right, unsigned length);
