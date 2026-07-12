// Function: sub_8EF6E0
// Address: 0x8ef6e0
int __cdecl sub_8EF6E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  *(_QWORD *)a1 = __PAIR64__(
                    (a2 >> 31)
                  | (unsigned int)((a3 | (4 * (a4 | ((a5 | ((a6 | (unsigned __int64)((__int64)a7 << 10)) << 10)) << 10)))) >> 30),
                    a2 | (4 * (a3 | (4 * (a4 | ((a5 | ((a6 | (unsigned int)(a7 << 10)) << 10)) << 10))))));
  *(_DWORD *)(a1 + 8) = 8;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
