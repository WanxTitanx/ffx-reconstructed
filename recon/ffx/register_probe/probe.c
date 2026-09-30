/* Compiler-allocation probes. Only complete reference matches may be promoted. */
extern "C" {
__declspec(noinline) const float *__cdecl leaf_00000001(float *dst, const float *src, float scale) {
    dst[0] = src[0] * scale; dst[1] = src[1] * scale;
    dst[2] = src[2] * scale; dst[3] = src[3] * scale;
    return src;
}
__declspec(noinline) unsigned __cdecl leaf_00000002(const unsigned *p, unsigned count) {
    unsigned sum = 0;
    while (count--) sum += *p++;
    return sum;
}
__declspec(noinline) unsigned __cdecl leaf_00000003(const unsigned *p, unsigned count) {
    unsigned sum = 0;
    if (count) do { sum += *p++; } while (--count);
    return sum;
}
__declspec(noinline) unsigned __cdecl leaf_00000004(const unsigned *p, unsigned count) {
    unsigned sum = 0;
    for (unsigned i = count; i; --i, ++p) sum += *p;
    return sum;
}
__declspec(noinline) unsigned __cdecl leaf_00000005(const unsigned *p, unsigned count) {
    unsigned sum = 0;
    if (!count) return 0;
    do { sum += *p; p = p + 1; count = count - 1; } while (count);
    return sum;
}
}
