// Function: sub_800DA0
// Address: 0x800da0
int __cdecl sub_800DA0(int a1)
{
  int result; // eax

  if ( !a1 )
    return -1;
  result = 0;
  while ( dword_119FEB0[result] != a1 )
  {
    if ( ++result >= 8 )
      return -1;
  }
  return result;
}
