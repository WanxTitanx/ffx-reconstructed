#include <string.h>
int __cdecl H(const void *p1, const void *p2)
{
    const unsigned *pa;
        const unsigned *pb;
        pa = (const unsigned *)p1;
        pb = (const unsigned *)p2;
    if (pb[0] != pa[0])
            return pa[0] > pb[0] ? 1 : -1;

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
