// Function: sub_8EF670
// Address: 0x8ef670
int __cdecl sub_8EF670(int a1, int a2, int a3, int a4, int a5, int a6)
{
  *(_QWORD *)a1 = __PAIR64__(
                    (a2 >> 31)
                  | (unsigned int)((a3 | (4 * (a4 | (4 * (a5 | (unsigned __int64)((__int64)a6 << 26)))))) >> 30),
                    a2 | (4 * (a3 | (4 * (a4 | (4 * (a5 | (unsigned int)(a6 << 26))))))));
  *(_DWORD *)(a1 + 8) = 66;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
