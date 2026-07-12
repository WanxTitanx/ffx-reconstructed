// Function: sub_800EF0
// Address: 0x800ef0
int __cdecl sub_800EF0(int a1)
{
  int v1; // eax

  v1 = 0;
  while ( byte_119FE7C[v1] != a1 )
  {
    if ( ++v1 >= 4 )
      return 0;
  }
  return dword_119FE80[v1];
}
