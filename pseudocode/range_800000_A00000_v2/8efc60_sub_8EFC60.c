// Function: sub_8EFC60
// Address: 0x8efc60
int __cdecl sub_8EFC60(int a1, int a2, unsigned int a3)
{
  *(_QWORD *)a1 = __PAIR64__((a2 >> 31) | a3, a2);
  *(_DWORD *)(a1 + 8) = 24;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
