int __cdecl FFX_memcmp(const void *a, const void *b, unsigned int n)
{
    unsigned int k = n;
    unsigned int *pa = (unsigned int *)a;
    unsigned int *pb = (unsigned int *)b;
    if (!k)
        return 0;
    k -= 4;
    if ((int)k >= 0) {
        do {
            if (*pa != *pb)
                return 1;
            pa++;
            pb++;
            k -= 4;
        } while ((int)k >= 0);
    }
    if ((int)k == -4)
        return 0;
    if (*(unsigned char *)pa != *(unsigned char *)pb)
        return 1;
    if ((int)k == -3)
        return 0;
    if (((unsigned char *)pa)[1] != ((unsigned char *)pb)[1])
        return 1;
    if ((int)k == -2)
        return 0;
    if (((unsigned char *)pa)[2] != ((unsigned char *)pb)[2])
        return 1;
    if ((int)k == -1)
        return 0;
    return ((unsigned char *)pa)[3] == ((unsigned char *)pb)[3] ? 0 : 1;
}
