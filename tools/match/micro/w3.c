#include <string.h>
int __cdecl W3(const void *p1, const void *p2, unsigned len)
{
    if (!len)
        return 0;
    len -= 4;
    if ((int)len >= 0)
    {
        do
        {
            if (*(unsigned *)p1 != *(unsigned *)p2)
                return 1;
            p1 = (const void *)((const unsigned *)p1 + 1);
            p2 = (const void *)((const unsigned *)p2 + 1);
            len -= 4;
        } while ((int)len >= 0);
    }
    if ((int)len == -4)
        return 0;
    return memcmp(p1, p2, len + 4);
}
