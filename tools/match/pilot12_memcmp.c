int __cdecl FFX_memcmp(const void *a, const void *b, unsigned int n)
{
    const unsigned int *pa = (const unsigned int *)a;
    const unsigned int *pb = (const unsigned int *)b;
    unsigned int k = n;
    if (k)
    {
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
    }
    return 0;
}
