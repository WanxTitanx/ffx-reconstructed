// Function: sub_93AF60
// Address: 0x93af60
int __cdecl sub_93AF60(float *a1, int a2)
{
  int result; // eax
  float *v3; // esi
  long double v4; // st7
  int n3; // edi
  double v6; // st6
  float v7; // [esp+4h] [ebp-4h]
  float v8; // [esp+4h] [ebp-4h]
  float v9; // [esp+4h] [ebp-4h]

  result = sub_92BFB0(a2);
  if ( !result )
  {
    if ( sub_92BE40(a2, off_C60EA4) ) // "//"
    {
      sub_92BA30(a2);
      sub_92BA30(a2);
      a1[26] = sub_92BBB0(a2);
      a1[27] = -sub_92BBB0(a2);
      a1[28] = -sub_92BBB0(a2);
      a1[30] = sub_92BBB0(a2);
      a1[31] = -sub_92BBB0(a2);
      a1[32] = -sub_92BBB0(a2);
      a1[34] = 0.0;
      a1[35] = -1.0;
      a1[36] = 0.0;
      sub_92BBB0(a2);
      sub_92BBB0(a2);
      sub_92BBB0(a2);
      a1[42] = sub_92BBB0(a2);
      return sub_920C00(a1);
    }
    else
    {
      sub_92BA30(a2);
      a1[26] = sub_92BBB0(a2);
      a1[27] = -sub_92BBB0(a2);
      a1[28] = -sub_92BBB0(a2);
      v3 = a1 + 38;
      a1[38] = sub_92BBB0(a2);
      a1[39] = -sub_92BBB0(a2);
      a1[40] = -sub_92BBB0(a2);
      a1[42] = sub_92BBB0(a2);
      v4 = 360.0;
      n3 = 3;
      do
      {
        v7 = fmod(*v3, v4);
        if ( v7 >= -180.0 )
        {
          v6 = v7;
          v4 = 360.0;
        }
        else
        {
          v4 = 360.0;
          v8 = v7 + 360.0;
          v6 = v8;
        }
        if ( v6 > 180.0 )
        {
          v9 = v6 - v4;
          v6 = v9;
        }
        *v3++ = v6;
        --n3;
      }
      while ( n3 );
      sub_93B110(a1);
      return sub_920C00(a1);
    }
  }
  return result;
}
