// Function: sub_93C840
// Address: 0x93c840
int __cdecl sub_93C840(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a1 + 20) = 0;
  return result;
}
