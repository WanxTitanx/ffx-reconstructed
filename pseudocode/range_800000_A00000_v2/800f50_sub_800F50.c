// Function: sub_800F50
// Address: 0x800f50
int __cdecl sub_800F50(int a1)
{
  int result; // eax

  result = 0;
  while ( byte_119FE7C[result] != a1 )
  {
    if ( ++result >= 4 )
      return -1;
  }
  return result;
}
