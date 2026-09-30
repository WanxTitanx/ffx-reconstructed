#include <string.h>
int __cdecl W5(const void *p1, const void *p2, unsigned len)
{
    if (!len)
        return 0;
    if (len >= 4)
    {
        unsigned q = len >> 2;
        unsigned i;
        for (i = 0; i < q; ++i)
            if (((const unsigned *)p1)[i] != ((const unsigned *)p2)[i])
                return 1;
    }
    return memcmp((const char *)p1 + (len & ~3u), (const char *)p2 + (len & ~3u), len & 3u);
}
