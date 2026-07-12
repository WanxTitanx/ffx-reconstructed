// Function: sub_8EFA00
// Address: 0x8efa00
int __cdecl sub_8EFA00(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  *(_QWORD *)a1 = __PAIR64__(
                    (a2 >> 31)
                  | (unsigned int)((a3
                                  | ((a4
                                    | ((a5
                                      | (16
                                       * (a6
                                        | (16
                                         * (a7
                                          | (2
                                           * (a8
                                            | (4
                                             * (a9
                                              | ((a10 | (16 * (a11 | (2 * (a12 | (unsigned __int64)(32LL * a13)))))) << 14)))))))))) << 6)) << 6)) >> 18),
                    a2
                  | ((a3
                    | ((a4
                      | ((a5
                        | (16
                         * (a6
                          | (16
                           * (a7
                            | (2
                             * (a8 | (4 * (a9 | ((a10 | (16 * (a11 | (2 * (a12 | (unsigned int)(32 * a13)))))) << 14)))))))))) << 6)) << 6)) << 14));
  *(_DWORD *)(a1 + 8) = 6;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
