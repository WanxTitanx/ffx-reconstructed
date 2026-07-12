// Function: sub_930830
// Address: 0x930830
int __cdecl sub_930830(int a1)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-4h]

  result = *(_DWORD *)(a1 + 12);
  if ( result )
  {
    result = j_FFX_Memory_Delete_2(*(_DWORD *)(a1 + 12), v2);
    *(_DWORD *)(a1 + 12) = 0;
  }
  return result;
}
