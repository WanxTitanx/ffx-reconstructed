// Function: sub_8E89D0
// Address: 0x8e89d0
int sub_8E89D0()
{
  int n10; // esi
  char *v1; // edi
  int result; // eax

  n10 = 0;
  if ( n10_2 <= 0 )
  {
    n10_2 = 0;
  }
  else
  {
    v1 = (char *)&unk_18756D0;
    do
    {
      result = sub_642510((int)v1);
      ++n10;
      v1 += 256;
    }
    while ( n10 < n10_2 );
    n10_2 = 0;
  }
  return result;
}
