// Function: sub_808CE0
// Address: 0x808ce0
void __cdecl sub_808CE0(float *a1, float *a2, float a3, float a4, float a5, float a6)
{
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7

  v6 = a3;
  if ( a3 < (double)*a2 )
    v6 = *a2;
  *a1 = v6;
  v7 = a4;
  if ( a4 < (double)a2[1] )
    v7 = a2[1];
  a1[1] = v7;
  v8 = a5;
  if ( a5 < (double)a2[2] )
    v8 = a2[2];
  a1[2] = v8;
  v9 = a6;
  if ( a6 < (double)a2[3] )
    v9 = a2[3];
  a1[3] = v9;
}
