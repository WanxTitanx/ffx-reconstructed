#include <string.h>
int __cdecl R(const void *p1, const void *p2)
{
    const unsigned *pa;
        const unsigned *pb;
        pb = (const unsigned *)p2;
        pa = (const unsigned *)p1;
    if (pb[0] > pa[0])
            return -1;
        if (pb[0] < pa[0])
            return 1;
    if (pa[1] > pb[1])
            return 1;
        if (pa[1] != pb[1])
            return -1;
        pa += 2;
        pb += 2;
        return memcmp(pa, pb, pa[-1] - 4);
}
