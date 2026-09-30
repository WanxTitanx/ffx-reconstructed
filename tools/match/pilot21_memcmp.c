int __cdecl FFX_memcmp(const void *p1, const void *p2, unsigned int len)
{
    unsigned int *pa;
    unsigned int *pb;
    pa = (unsigned int *)p1;
    pb = (unsigned int *)p2;
    if (len)
    {
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
            if (*ca != *cb)
                return 1;
            if ((int)len != -3)
            {
                if (ca[1] != cb[1])
                    return 1;
                if ((int)len != -2)
                {
                    if (ca[2] != cb[2])
                        return 1;
                    if ((int)len != -1)
                        return ca[3] == cb[3] ? 0 : 1;
                }
            }
        }
    }
    return 0;
}
