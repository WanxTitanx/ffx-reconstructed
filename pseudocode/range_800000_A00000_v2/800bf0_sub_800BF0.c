// Function: sub_800BF0
// Address: 0x800bf0
double __cdecl sub_800BF0(int a1, int a2)
{
  double v2; // st7
  float v4; // [esp+Ch] [ebp+Ch]

  if ( a2 )
    v2 = sub_795A30(a1);
  else
    v2 = sub_82ADF0(LODWORD(flt_12A80C0[a1]));
  v4 = v2;
  return (float)(v4 / 6.0);
}
