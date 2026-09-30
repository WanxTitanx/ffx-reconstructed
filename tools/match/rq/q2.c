#include <string.h>
int __cdecl Q2(const void *p1, const void *p2)
{
    const unsigned *pa = (const unsigned *)p1;
    volatile const unsigned *pb = (volatile const unsigned *)p2;
    if (pb[0] > pa[0])
        return -1;
    if (pb[0] < pa[0])
        return 1;
    if (pa[1] > pb[1])
        return 1;
    if (pa[1] != pb[1])
        return -1;
    p1 = (const void *)(pa + 2);
    p2 = (const void *)((const unsigned *)pb + 2);
    return memcmp(p1, p2, pa[1] - 4);
}
