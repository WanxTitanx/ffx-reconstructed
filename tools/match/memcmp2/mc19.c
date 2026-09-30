#include <string.h>
int __cdecl M19(const void *p1, const void *p2)
{
    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pa[0] > pb[0])
        return 1;
    if (pa[0] < pb[0])
        return -1;
    if (pa[1] > pb[1])
        return 1;
    if (pa[1] == pb[1])
    {
        k = pa[1];
        pa += 2;
        pb += 2;
        return memcmp(pa, pb, k - 4);
    }
    return -1;
}
