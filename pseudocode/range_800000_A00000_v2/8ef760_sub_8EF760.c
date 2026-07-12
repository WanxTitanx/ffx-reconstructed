// Function: sub_8EF760
// Address: 0x8ef760
int __cdecl sub_8EF760(int a1, int a2)
{
  *(_QWORD *)a1 = a2;
  *(_DWORD *)(a1 + 8) = 70;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
