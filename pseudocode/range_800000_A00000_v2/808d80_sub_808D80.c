// Function: sub_808D80
// Address: 0x808d80
void __cdecl sub_808D80(float *a1, float *a2, float a3)
{
  double v3; // st7
  bool v4; // c0
  bool v5; // c3
  double v6; // st7

  v3 = *a2;
  v4 = a3 < v3;
  v5 = a3 == v3;
  v6 = a3;
  if ( v4 || v5 )
    *a1 = a3;
  else
    *a1 = *a2;
  if ( a2[1] >= v6 )
    a1[1] = a3;
  else
    a1[1] = a2[1];
  if ( a2[2] >= v6 )
    a1[2] = a3;
  else
    a1[2] = a2[2];
  if ( a2[3] < v6 )
    v6 = a2[3];
  a1[3] = v6;
}
