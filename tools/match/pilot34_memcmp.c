int __cdecl FFX_memcmp(const void *p1, const void *p2, unsigned int len)
{
    unsigned int *pa;
    unsigned int *pb;
    if (!len)
        return 0;
    pa = (unsigned int *)p1;
    pb = (unsigned int *)p2;
    while (len >= 4)
    {
        if (*pa != *pb)
            return 1;
        ++pa;
        ++pb;
        len -= 4;
    }
    if (len)
    {
        const unsigned char *ca = (const unsigned char *)pa;
        const unsigned char *cb = (const unsigned char *)pb;
        unsigned int t = len;
        if (*ca != *cb)
            return 1;
        if (t == 1)
            return 0;
        if (ca[1] != cb[1])
            return 1;
        if (t == 2)
            return 0;
        if (ca[2] != cb[2])
            return 1;
        if (t == 3)
            return 0;
        return ca[3] == cb[3] ? 0 : 1;
    }
    return 0;
}
