#include <string.h>
int __cdecl FFX_memcmp(const void *p1, const void *p2, unsigned len)
{
    if (!len)
        return 0;
    return memcmp(p1, p2, len);
}
