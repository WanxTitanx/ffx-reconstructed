// Function: sub_8EF970
// Address: 0x8ef970
int __cdecl sub_8EF970(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  *(_QWORD *)a1 = __PAIR64__(
                    (a2 >> 31)
                  | (unsigned int)((a3
                                  | (8
                                   * (a4
                                    | ((a5 | (4 * (a6 | (2 * (a7 | (2 * (a8 | (unsigned __int64)(2LL * a9)))))))) << 8)))) >> 31),
                    a2
                  | (2 * (a3 | (8 * (a4 | ((a5 | (4 * (a6 | (2 * (a7 | (2 * (a8 | (unsigned int)(2 * a9)))))))) << 8))))));
  *(_DWORD *)(a1 + 8) = 71;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
