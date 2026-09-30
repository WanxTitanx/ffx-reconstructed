#include <string.h>
int __cdecl R(const void *p1, const void *p2)
{
    const unsigned *pa;
    const unsigned *pb;
    pb = (const unsigned *)p2;
    pa = (const unsigned *)p1;
    if (pb[0] == pa[0])
        goto second0;
    if (pa[0] < pb[0])
        return -1;
    return 1;
second0:
    if (pa[1] > pb[1])
        return 1;
    if (pa[1] == pb[1])
        goto second;
    return -1;
second:
    pa += 2;
    pb += 2;
    return memcmp(pa, pb, pa[-1] - 4);
}
