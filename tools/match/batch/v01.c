int __cdecl F(const void *p1, const void *p2, unsigned int len)
{
    unsigned int *pa;
    unsigned int *pb;
    if (!len)
        return 0;
    pa = (unsigned int *)p1;
    pb = (unsigned int *)p2;
    len -= 4;
    if ((int)len >= 0)
    {
        do
        {
            if (*pa != *pb)
                return 1;
            ++pa;
            ++pb;
            len -= 4;
        } while ((int)len >= 0);
    }
    if ((int)len != -4)
    {
        const unsigned char *ca = (const unsigned char *)pa;
        const unsigned char *cb = (const unsigned char *)pb;
        int t;
        t = (*ca < *cb) ? -1 : 0;
        if (*ca != *cb)
            return t | 1;
        if ((int)len != -3)
        {
            t = (ca[1] < cb[1]) ? -1 : 0;
            if (ca[1] != cb[1])
                return t | 1;
            if ((int)len != -2)
            {
                t = (ca[2] < cb[2]) ? -1 : 0;
                if (ca[2] != cb[2])
                    return t | 1;
                if ((int)len != -1)
                    return ca[3] == cb[3] ? 0 : 1;
            }
        }
    }
    return 0;
}
