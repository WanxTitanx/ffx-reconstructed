#include <string.h>
int __cdecl W2(const void *p1, const void *p2, unsigned len)
{
    unsigned k = len;
    if (!k)
        return 0;
    k -= 4;
    if ((int)k >= 0)
    {
        do
        {
            if (memcmp(p1, p2, 4))
                return 1;
            p1 = (const void *)((const unsigned *)p1 + 1);
            p2 = (const void *)((const unsigned *)p2 + 1);
            k -= 4;
        } while ((int)k >= 0);
    }
    return memcmp(p1, p2, k + 4);
}
