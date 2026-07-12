// Function: sub_930260
// Address: 0x930260
int __cdecl sub_930260(int a1)
{
  int result; // eax

  for ( result = *(_DWORD *)(a1 + 192); result != a1; result = *(_DWORD *)(a1 + 192) )
    sub_92ED50(result);
  return result;
}
