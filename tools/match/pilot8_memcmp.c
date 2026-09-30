int __cdecl FFX_memcmp(const void *p1, const void *p2, unsigned int len)
{
    unsigned int *a = (unsigned int *)p1;
    unsigned int *b = (unsigned int *)p2;
    unsigned int n = len;
    if (n)
    {
        n -= 4;
        if ((int)n >= 0)
        {
            do
            {
                if (*a != *b)
                    return 1;
                ++a;
                ++b;
                n -= 4;
            } while ((int)n >= 0);
        }
        if ((int)n != -4)
        {
            if (*(unsigned char *)a != *(unsigned char *)b)
                return 1;
            if ((int)n != -3)
            {
                if (((unsigned char *)a)[1] != ((unsigned char *)b)[1])
                    return 1;
                if ((int)n != -2)
                {
                    if (((unsigned char *)a)[2] != ((unsigned char *)b)[2])
                        return 1;
                    if ((int)n != -1)
                        return ((unsigned char *)a)[3] == ((unsigned char *)b)[3] ? 0 : 1;
                }
            }
        }
    }
    return 0;
}
