// Function: sub_81E6E0
// Address: 0x81e6e0
int __cdecl sub_81E6E0(int a1)
{
  void *v1; // eax

  if ( a1 != -1 )
    return sub_67A650(a1);
  v1 = off_C49458;
  *(_DWORD *)off_C49458 = -1;
  return sub_67A630((int)v1);
}
