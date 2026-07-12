// Function: sub_8EF7D0
// Address: 0x8ef7d0
int __cdecl sub_8EF7D0(int a1, int a2)
{
  *(_QWORD *)a1 = a2;
  *(_DWORD *)(a1 + 8) = 74;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
