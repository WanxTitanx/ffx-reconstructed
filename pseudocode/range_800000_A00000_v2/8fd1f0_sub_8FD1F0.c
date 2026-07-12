// Function: sub_8FD1F0
// Address: 0x8fd1f0
__int64 __cdecl sub_8FD1F0(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // edi

  v4 = dword_187168C;
  *dword_187168C = 32769;
  v4[1] = 0x10000000;
  v4[2] = 14;
  v4[3] = 0;
  *((_QWORD *)v4 + 2) = __PAIR64__(
                          (a1 >> 31) | (unsigned int)((a2 | ((a3 | (unsigned __int64)((__int64)a4 << 8)) << 8)) >> 16),
                          a1 | ((a2 | ((a3 | (unsigned int)(a4 << 8)) << 8)) << 16));
  v4[6] = 76;
  v4[7] = 0;
  dword_187168C = v4 + 8;
  return a1;
}
