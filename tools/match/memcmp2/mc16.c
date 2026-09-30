#include <string.h>
int __cdecl M16(const unsigned *pa, const unsigned *pb)
{
    if (pa[0] > pb[0])
        return 1;
    if (pa[0] < pb[0])
        return -1;
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
