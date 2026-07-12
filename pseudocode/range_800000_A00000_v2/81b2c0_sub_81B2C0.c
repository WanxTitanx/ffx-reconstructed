// Function: sub_81B2C0
// Address: 0x81b2c0
float *__cdecl sub_81B2C0(int a1, float *a2)
{
  float *result; // eax
  double v3; // st7

  result = (float *)LODWORD(flt_12A80C0[a1]);
  if ( result )
  {
    v3 = sub_82AD60(LODWORD(flt_12A80C0[a1]));
    *a2 = v3;
    return a2;
  }
  return result;
}
