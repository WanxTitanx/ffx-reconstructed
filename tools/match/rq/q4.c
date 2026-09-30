#include <string.h>
int __cdecl Q4(const void *p1, const void *p2)
{
    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned t1;
    unsigned t2;
    t1 = pb[0];
    t2 = pa[0];
    if (t2 > t1)
        return 1;
    if (t2 < t1)
        return -1;
    if (pa[1] > pb[1])
        return 1;
    if (pa[1] != pb[1])
        return -1;
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, pa[-1] - 4);
}
