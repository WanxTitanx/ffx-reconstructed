// Function: sub_800D40
// Address: 0x800d40
int __cdecl sub_800D40(int a1)
{
  char v1; // cl
  int n2; // eax
  char v3; // cl

  v1 = *((_BYTE *)&unk_119FED0 + a1);
  n2 = 0;
  if ( v1 )
  {
    v3 = v1 & 1;
    do
    {
      if ( v3 )
        break;
      ++n2;
    }
    while ( n2 < 2 );
    return 8 * n2 + 16320;
  }
  return n2;
}
