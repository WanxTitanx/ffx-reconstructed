int __cdecl FFX_memcmp(const void *p1, const void *p2, unsigned int len)
{
    unsigned int *pa;
    unsigned int *pb;
    unsigned int k;
    if (!len)
        return 0;
    k = len - 4;
    pa = (unsigned int *)p1;
    pb = (unsigned int *)p2;
    if ((int)k < 0)
        goto tail;
    do
    {
        if (*pa != *pb)
            return 1;
        ++pa;
        ++pb;
        k -= 4;
    } while ((int)k >= 0);
tail:
    if ((int)k != -4)
    {
        const unsigned char *ca = (const unsigned char *)pa;
        const unsigned char *cb = (const unsigned char *)pb;
        if (*ca != *cb)
            return 1;
        if ((int)k != -3)
        {
            if (ca[1] != cb[1])
                return 1;
            if ((int)k != -2)
            {
                if (ca[2] != cb[2])
                    return 1;
                if ((int)k != -1)
                    return ca[3] == cb[3] ? 0 : 1;
            }
        }
    }
    return 0;
}
