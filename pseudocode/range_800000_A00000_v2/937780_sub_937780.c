// Function: sub_937780
// Address: 0x937780
void __cdecl sub_937780(int a1, _DWORD *a2)
{
  _DWORD *v2; // esi

  if ( *a2 )
  {
    v2 = a2 + 5;
    do
    {
      if ( *(v2 - 5) == 1 )
      {
        sub_84A470(a1, *(v2 - 4), *(v2 - 3), *(v2 - 2), *(v2 - 1), *v2, v2[1]);
      }
      else if ( *(v2 - 5) == 2 )
      {
        sub_84A4D0(a1, 1, *(v2 - 3), *(v2 - 2), *(v2 - 1), *v2, v2[1]);
      }
      v2 += 7;
    }
    while ( *(v2 - 5) );
  }
}
