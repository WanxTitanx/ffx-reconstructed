int __cdecl FFX_memcmp(const void *a, const void *b, unsigned int n)
{
    unsigned int k = n;
    unsigned char *pa = (unsigned char *)a;
    unsigned char *pb = (unsigned char *)b;
    if (!k)
        return 0;
    k -= 4;
    if ((int)k >= 0) {
        do {
            if (*(unsigned int *)pa != *(unsigned int *)pb)
                return 1;
            pa += 4;
            pb += 4;
            k -= 4;
        } while ((int)k >= 0);
    }
    if ((int)k == -4)
        return 0;
    if (*pa != *pb)
        return 1;
    if ((int)k == -3)
        return 0;
    if (pa[1] != pb[1])
        return 1;
    if ((int)k == -2)
        return 0;
    if (pa[2] != pb[2])
        return 1;
    if ((int)k == -1)
        return 0;
    return pa[3] == pb[3] ? 0 : 1;
}
