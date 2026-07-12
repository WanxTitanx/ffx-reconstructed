// Function: sub_93C800
// Address: 0x93c800
int __cdecl sub_93C800(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 24) = 0;
  return result;
}
