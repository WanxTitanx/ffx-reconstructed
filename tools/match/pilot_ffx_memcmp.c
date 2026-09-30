
int __cdecl FFX_memcmp(const void *a, const void *b, unsigned int n)
{
    const unsigned int *pa = (const unsigned int *)a;
    const unsigned int *pb = (const unsigned int *)b;
    const unsigned char *ca;
    const unsigned char *cb;
    unsigned int q = n >> 2;
    unsigned int r = n & 3;
    unsigned int i;
    for (i = 0; i < q; i++) {
        if (pa[i] != pb[i])
            break;
    }
    if (i != q)
        return -1;
    ca = (const unsigned char *)(pa + q);
    cb = (const unsigned char *)(pb + q);
    while (r--) {
        if (*ca != *cb)
            return -1;
        ca++;
        cb++;
    }
    return 0;
}
