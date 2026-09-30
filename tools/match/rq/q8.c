#include <string.h>
int __cdecl Q8(const void *p1, const void *p2)
{
    const unsigned *pa = (const unsigned *)p2;
    const unsigned *pb = (const unsigned *)p1;
    if (pb[0] > pa[0])
        return 1;
    if (pb[0] < pa[0])
        return -1;
    if (pb[1] > pa[1])
        return 1;
    if (pb[1] == pa[1])
    {
        pa += 2;
        pb += 2;
        return memcmp(pa, pb, pa[-1] - 4);
    }
    return -1;
}
