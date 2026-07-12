// Function: sub_8EFAD0
// Address: 0x8efad0
int __cdecl sub_8EFAD0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  *(_QWORD *)a1 = __PAIR64__(
                    (a2 >> 31)
                  | (unsigned int)((a3
                                  | (8
                                   * (a4 | (2 * (a5 | (8 * (a6 | ((a7 | (unsigned __int64)((__int64)a8 << 13)) << 10)))))))) >> 30),
                    a2 | (4 * (a3 | (8 * (a4 | (2 * (a5 | (8 * (a6 | ((a7 | (unsigned int)(a8 << 13)) << 10))))))))));
  *(_DWORD *)(a1 + 8) = 20;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
