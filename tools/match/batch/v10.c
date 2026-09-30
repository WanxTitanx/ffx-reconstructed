int __cdecl F(const void *p1, const void *p2, unsigned int len)
{
    unsigned int *pa = (unsigned int *)p1;
    unsigned int *pb = (unsigned int *)p2;
    unsigned int k = len;
    if (!k)
        return 0;
    k -= 4;
    if ((int)k >= 0)
    {
        do
        {
            if (*pa != *pb)
                return 1;
            ++pa;
            ++pb;
            k -= 4;
        } while ((int)k >= 0);
    }
    if ((int)k != -4)
    {
        const unsigned char *ca = (const unsigned char *)pa;
        const unsigned char *cb = (const unsigned char *)pb;
        if (*ca != *cb)
            return ((*ca < *cb) ? -1 : 0) | 1;
        if ((int)k != -3)
        {
            if (ca[1] != cb[1])
                return ((ca[1] < cb[1]) ? -1 : 0) | 1;
            if ((int)k != -2)
            {
                if (ca[2] != cb[2])
                    return ((ca[2] < cb[2]) ? -1 : 0) | 1;
                if ((int)k != -1)
                    return ca[3] == cb[3] ? 0 : 1;
            }
        }
    }
    return 0;
}
