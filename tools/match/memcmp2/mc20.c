#include <string.h>
int __cdecl M20(const void *p1, const void *p2)
{
    unsigned k;
    if (((const unsigned *)p1)[0] > ((const unsigned *)p2)[0])
        return 1;
    if (((const unsigned *)p1)[0] < ((const unsigned *)p2)[0])
        return -1;
    if (((const unsigned *)p1)[1] > ((const unsigned *)p2)[1])
        return 1;
    if (((const unsigned *)p1)[1] == ((const unsigned *)p2)[1])
    {
        k = ((const unsigned *)p1)[1];
        p1 = (const void *)((const unsigned *)p1 + 2);
        p2 = (const void *)((const unsigned *)p2 + 2);
        return memcmp(p1, p2, k - 4);
    }
    return -1;
}
