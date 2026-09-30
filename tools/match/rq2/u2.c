#include <string.h>
int __cdecl U2(const void *p1, const void *p2)
{
    const unsigned *pa;
    const unsigned *pb;
    unsigned b0;
    pa = (const unsigned *)p1;
    pb = (const unsigned *)p2;
    b0 = pb[0];
    if (pa[0] > b0)
        return 1;
    if (pa[0] < b0)
        return -1;
    if (pa[1] > pb[1])
        return 1;
    if (pa[1] == pb[1])
    {
        pa += 2;
        pb += 2;
        return memcmp(pa, pb, pa[-1] - 4);
    }
    return -1;
}
