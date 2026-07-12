// Function: sub_8EF830
// Address: 0x8ef830
int __cdecl sub_8EF830(int a1, int a2, int a3, int a4)
{
  *(_QWORD *)a1 = __PAIR64__(
                    (a2 >> 31) | (unsigned int)((a3 | (unsigned __int64)((__int64)a4 << 8)) >> 24),
                    a2 | ((a3 | (unsigned int)(a4 << 8)) << 8));
  *(_DWORD *)(a1 + 8) = 61;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
