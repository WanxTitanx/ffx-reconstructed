#include <string.h>
int __cdecl R(const void *p1, const void *p2)
{
    const unsigned *pa = (const unsigned *)p1;
    const unsigned *pb = (const unsigned *)p2;
    unsigned k;
    if (pa[0] == pb[0])
        goto second0;
    if (pb[0] < pa[0])
        return 1;
    return -1;
second0:
    k = pa[1];
    if (k > pb[1])
        return 1;
    if (k == pb[1])
        goto second;
    return -1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, k - 4);
}
