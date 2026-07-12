// Function: sub_81CB30
// Address: 0x81cb30
void __cdecl sub_81CB30(int a1, int i_1, int i_2, int a4)
{
  int i; // esi
  int v5; // ecx

  for ( i = i_1; i <= i_2; ++i )
  {
    v5 = sub_7E3720(a1, 4, i);
    if ( v5 )
      sub_A69DE0(v5, a4, a4 >> 31);
  }
}
