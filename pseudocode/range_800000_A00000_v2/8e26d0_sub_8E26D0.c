// Function: sub_8E26D0
// Address: 0x8e26d0
int __cdecl sub_8E26D0(int a1)
{
  int i; // eax
  int result; // eax

  sub_8BE3E0();
  sub_8BE440();
  sub_8BE480();
  for ( i = *(_DWORD *)(a1 + 28); !i; i = 1 )
  {
    result = sub_8A8E00();
    if ( !result )
      return result;
    sub_A54B40();
    *(_DWORD *)(a1 + 28) = 1;
  }
  result = i - 1;
  if ( !result )
    return sub_A53570();
  return result;
}
