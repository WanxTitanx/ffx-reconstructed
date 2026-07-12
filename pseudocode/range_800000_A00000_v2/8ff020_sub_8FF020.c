// Function: sub_8FF020
// Address: 0x8ff020
__int64 __cdecl sub_8FF020(int a1, unsigned int a2)
{
  _DWORD *v2; // edi

  v2 = dword_187168C;
  *dword_187168C = 32769;
  v2[1] = 0x10000000;
  v2[2] = 14;
  v2[3] = 0;
  *((_QWORD *)v2 + 2) = __PAIR64__((a1 >> 31) | a2, a1);
  v2[6] = 24;
  v2[7] = 0;
  dword_187168C = v2 + 8;
  return a1;
}
