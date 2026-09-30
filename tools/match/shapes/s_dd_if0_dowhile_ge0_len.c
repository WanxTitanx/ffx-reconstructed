int __cdecl F(const void *p1, const void *p2, unsigned int len)
{
    if (!len)
            return 0;
    if ((int)len >= 0)
        {
            do
            {
    
                if (*(unsigned int *)p1 != *(unsigned int *)p2)
                    return 1;
                p1 = (const void *)((const unsigned int *)p1 + 1);
                p2 = (const void *)((const unsigned int *)p2 + 1);
                len -= 4;
            } while ((int)len >= 0);
        }

        if ((int)len != -4)
        {
            const unsigned char *ca = (const unsigned char *)p1;
            const unsigned char *cb = (const unsigned char *)p2;
            if (*ca != *cb)
                return ((*ca < *cb) ? -1 : 0) | 1;
            if ((int)len != -3)
            {
                if (ca[1] != cb[1])
                    return ((ca[1] < cb[1]) ? -1 : 0) | 1;
                if ((int)len != -2)
                {
                    if (ca[2] != cb[2])
                        return ((ca[2] < cb[2]) ? -1 : 0) | 1;
                    if ((int)len != -1)
                        return ca[3] == cb[3] ? 0 : 1;
                }
            }
        }
        return 0;

}
