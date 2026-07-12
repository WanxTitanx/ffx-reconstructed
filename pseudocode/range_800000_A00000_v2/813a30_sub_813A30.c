// Function: sub_813A30
// Address: 0x813a30
int __cdecl sub_813A30(__int16 *n2622, int a2, int a3, unsigned int a4, unsigned int a5, char n66)
{
  char n72; // [esp+Ch] [ebp-8h]

  n72 = 72;
  if ( n2622[4] )
  {
    if ( n66 == 66 )
      n72 = 66;
    if ( !sub_645580((int)n2622) )
      sub_8141D0((int)n2622, (int)n2622, n72);
    sub_813D80((int)n2622, n2622, a2, a4, a5);
  }
  return a3;
}
