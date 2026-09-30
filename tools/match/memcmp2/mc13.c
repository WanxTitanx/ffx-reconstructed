#include <string.h>
int __cdecl M13(const void * __restrict p1, const void * __restrict p2)
{
    const unsigned * __restrict pa = (const unsigned * __restrict)p1;
    const unsigned * __restrict pb = (const unsigned * __restrict)p2;
    if (pa[0] > pb[0])
        return 1;
    if (pa[0] < pb[0])
        return -1;
    if (pa[1] > pb[1])
        return 1;
    if (pa[1] == pb[1])
    {
        pa += 2;
        pb += 2;
        return memcmp(pa, pb, pa[-1] - 4) == 0;
    }
    return -1;
}
