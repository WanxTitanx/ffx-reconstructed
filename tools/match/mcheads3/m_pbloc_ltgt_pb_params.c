#include <string.h>
int __cdecl M(const void *p1, const void *p2)
{
        const unsigned *pb = (const unsigned *)p2;
    if (pb[0] > ((const unsigned *)p1)[0])
            return -1;
        if (pb[0] < ((const unsigned *)p1)[0])
            return 1;

        if (((const unsigned *)p1)[1] > pb[1])
            return 1;
        if (((const unsigned *)p1)[1] == pb[1])
        {
            p1 = (const void *)((const unsigned *)p1 + 2);
                    p2 = (const void *)((const unsigned *)p2 + 2);
                    return memcmp(p1, p2, ((const unsigned *)p1)[-1] - 4) == 0;
        }
        return -1;

}
