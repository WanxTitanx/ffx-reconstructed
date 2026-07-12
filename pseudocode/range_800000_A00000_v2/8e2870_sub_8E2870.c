// Function: sub_8E2870
// Address: 0x8e2870
int __cdecl sub_8E2870(int a1)
{
  int v1; // eax
  int result; // eax

  sub_8BE3E0();
  sub_8BE440();
  sub_8BE480();
  v1 = *(_DWORD *)(a1 + 28);
  if ( v1 )
  {
    result = v1 - 1;
    if ( !result )
    {
      if ( unk_23CC130 )
      {
        sub_8AAD20(20);
        return sub_8AA0B0(1, 0);
      }
    }
  }
  else
  {
    result = sub_8E2930();
    *(_DWORD *)(a1 + 28) = 1;
  }
  return result;
}
