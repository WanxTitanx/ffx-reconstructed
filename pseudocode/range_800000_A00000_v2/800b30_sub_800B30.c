// Function: sub_800B30
// Address: 0x800b30
double __cdecl sub_800B30(int a1, int a2)
{
  char v2; // si
  float v3; // edi
  double v4; // st7
  float v6; // [esp+10h] [ebp+8h]
  float v8; // [esp+14h] [ebp+Ch]

  v2 = a1;
  v3 = flt_12A80C0[a1];
  if ( a2 )
  {
    v6 = sub_795100(a1);
    v4 = sub_795A30(v2);
  }
  else
  {
    v6 = sub_82AC20(LODWORD(v3));
    v4 = sub_82ADF0(LODWORD(v3));
  }
  v8 = v4;
  if ( v8 > (double)v6 )
    v6 = v4;
  return (float)(v6 / 18.0);
}
