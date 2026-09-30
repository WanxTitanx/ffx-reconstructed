#include <string.h>
int __cdecl M6(const void *p1, const void *p2)
{
    const unsigned *pb = (const unsigned *)p2;
    const unsigned *pa = (const unsigned *)p1;
    if (pa[0] != pb[0])
        return pa[0] > pb[0] ? 1 : -1;
    if (pa[1] != pb[1])
        return pa[1] > pb[1] ? 1 : -1;
    return memcmp(pa + 2, pb + 2, pa[1] - 4) == 0;
}
