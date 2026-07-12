// Function: sub_93C730
// Address: 0x93c730
int __cdecl sub_93C730(int a1, int a2, int a3, int n100)
{
  int v4; // esi
  int i; // ebx
  int v6; // eax
  int v7; // esi

  sub_848530(a1);
  sub_848480(1);
  sub_8484C0(0, 0, 0, 0);
  sub_848680(a2 + 8, a3);
  sub_848680(a2 + 8, a3 + 100);
  v4 = a3;
  for ( i = 0; i <= 100; i += 10 )
  {
    if ( i % 0x32u )
    {
      sub_848680(a2 + 4, v4);
      v6 = a2 + 12;
    }
    else
    {
      sub_848680(a2, v4);
      v6 = a2 + 16;
    }
    sub_848680(v6, v4);
    v4 += 10;
  }
  if ( n100 <= 100 )
  {
    sub_8484C0(255, 0, 0, 0);
    v7 = a3 - n100 + 100;
    sub_848680(a2, v7);
    sub_848680(a2 + 16, v7);
  }
  return sub_848460();
}
