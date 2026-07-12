// Function: sub_8EF910
// Address: 0x8ef910
int __cdecl sub_8EF910(int a1, int a2, int a3, int a4, int a5)
{
  *(_QWORD *)a1 = __PAIR64__(
                    (a2 >> 31) | (unsigned int)((a3 | ((a4 | (unsigned __int64)((__int64)a5 << 16)) << 16)) >> 16),
                    a2 | ((a3 | ((a4 | (unsigned int)(a5 << 16)) << 16)) << 16));
  *(_DWORD *)(a1 + 8) = 64;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
