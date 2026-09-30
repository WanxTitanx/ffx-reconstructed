#include <string.h>
int __cdecl Q1(const void * __restrict p1, const void * __restrict p2)
{
    if (((const unsigned *)p2)[0] > ((const unsigned *)p1)[0])
        return -1;
    if (((const unsigned *)p2)[0] < ((const unsigned *)p1)[0])
        return 1;
    if (((const unsigned *)p1)[1] > ((const unsigned *)p2)[1])
        return 1;
    if (((const unsigned *)p1)[1] != ((const unsigned *)p2)[1])
        return -1;
    p1 = (const void *)((const unsigned *)p1 + 2);
    p2 = (const void *)((const unsigned *)p2 + 2);
    return memcmp(p1, p2, ((const unsigned *)p1)[-1] - 4);
}
