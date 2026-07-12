// Function: sub_93D900
// Address: 0x93d900
int __cdecl sub_93D900(int a1)
{
  int n2; // eax
  double v2; // st5
  int v3; // ecx
  double v4; // st5
  double v5; // st5
  double v6; // st5

  for ( n2 = 0; n2 < 4; ++n2 )
  {
    if ( n2 )
      v2 = 0.0;
    else
      v2 = 1.0;
    v3 = 4 * n2;
    *(float *)(a1 + 16 * n2) = v2;
    if ( n2 == 1 )
      v4 = 1.0;
    else
      v4 = 0.0;
    *(float *)(a1 + 16 * n2 + 4) = v4;
    if ( n2 == 2 )
      v5 = 1.0;
    else
      v5 = 0.0;
    *(float *)(a1 + 16 * n2 + 8) = v5;
    if ( n2 == 3 )
      v6 = 1.0;
    else
      v6 = 0.0;
    *(float *)(a1 + 4 * v3 + 12) = v6;
  }
  return n2;
}
