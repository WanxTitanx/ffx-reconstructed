// Function: sub_93C670
// Address: 0x93c670
int __cdecl sub_93C670(float *a1, float *p_X, const char *DepthZ, int a4)
{
  int n99_1; // eax
  double Y_1; // st7
  int n99; // edi
  int Y_2; // eax
  double Y; // [esp+14h] [ebp-8h] BYREF

  sub_937EF0(a1, 8, 8, 190, 125, 6, (int)sub_93C860, (int)DepthZ, a4);
  sub_84B560(*(_DWORD *)a1, a1);
  *((_DWORD *)a1 + 1) = p_X;
  a1[2] = *p_X;
  n99_1 = (int)(modf(*p_X, &Y) * 100.0);
  Y_1 = Y;
  n99 = n99_1;
  *((_DWORD *)a1 + 4) = n99_1;
  Y_2 = (int)Y_1;
  *((_DWORD *)a1 + 3) = (int)Y_1;
  a1[5] = 0.0;
  a1[7] = 0.0;
  if ( (int)Y_1 >= 0 )
  {
    if ( Y_2 > 999 )
      Y_2 = 999;
  }
  else
  {
    Y_2 = 0;
  }
  *((_DWORD *)a1 + 3) = Y_2;
  if ( n99 >= 0 )
  {
    if ( n99 <= 99 )
      *((_DWORD *)a1 + 4) = n99;
    else
      *((_DWORD *)a1 + 4) = 99;
  }
  else
  {
    a1[4] = 0.0;
  }
  return Y_2;
}
