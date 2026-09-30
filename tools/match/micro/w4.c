#include <string.h>
int __cdecl W4(const void *p1, const void *p2, unsigned len)
{
    unsigned r;
    if (!len)
        return 0;
    r = memcmp(p1, p2, len & ~3u);
    if (r)
        return 1;
    return memcmp((const char *)p1 + (len & ~3u), (const char *)p2 + (len & ~3u), len & 3u);
}
