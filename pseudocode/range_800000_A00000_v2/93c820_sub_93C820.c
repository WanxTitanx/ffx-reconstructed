// Function: sub_93C820
// Address: 0x93c820
int __cdecl sub_93C820(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a1 + 28) = 0;
  return result;
}
