#include <string.h>
typedef struct { unsigned n; unsigned d[1]; } Buf;
int __cdecl Q9(const void *p1, const Buf *p2)
{
    const unsigned *pa = (const unsigned *)p1;
    if (pa[0] > p2->n)
        return 1;
    if (pa[0] < p2->n)
        return -1;
    if (pa[1] > p2->d[0])
        return 1;
    if (pa[1] == p2->d[0])
    {
        pa += 2;
        return memcmp(pa, p2->d + 1, pa[-1] - 4);
    }
    return -1;
}
