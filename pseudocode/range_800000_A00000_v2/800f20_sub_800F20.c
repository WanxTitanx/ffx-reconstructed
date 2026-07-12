// Function: sub_800F20
// Address: 0x800f20
int __cdecl sub_800F20(int a1)
{
  int result; // eax

  result = 0;
  while ( dword_119FE80[result] != a1 )
  {
    if ( ++result >= 4 )
      return -1;
  }
  return result;
}
