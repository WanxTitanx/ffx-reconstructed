// Function: sub_A7C6F0
// Address: 0xa7c6f0
// Size: 0xf1
// Prototype: 

double __cdecl sub_A7C6F0(__int16 a1, int a2, int a3)
{
  double v3; // st7
  int n0x2000; // eax
  long double v5; // st7
  float v7; // [esp+Ch] [ebp+Ch]
  float v8; // [esp+Ch] [ebp+Ch]
  float v9; // [esp+Ch] [ebp+Ch]
  float v10; // [esp+Ch] [ebp+Ch]
  float v13; // [esp+Ch] [ebp+Ch]
  float v15; // [esp+10h] [ebp+10h]
  float v16; // [esp+10h] [ebp+10h]
  float v17; // [esp+10h] [ebp+10h]
  float v18; // [esp+10h] [ebp+10h]

  v7 = (float)a2;
  v3 = v7;
  v8 = (float)a3;
  v9 = v3 / v8;
  if ( !a3 )
    return (float)1.0;
  n0x2000 = a1 & 0x7000;
  if ( n0x2000 == 0x2000 )
  {
    v13 = 1.0 - v9;
    v18 = v13 * v13;
    return (float)(1.0 - v18);
  }
  if ( n0x2000 == 12288 )
    return (float)(v9 * v9);
  if ( n0x2000 != 0x4000 )
    return v9;
  v15 = 1.0 - v9;
  v10 = v15 * 3.141592741012573;
  v5 = v10;
  if ( v10 <= 3.141592741012573 )
  {
    if ( v5 < 0.0 )
      v5 = (float)0.0;
  }
  else
  {
    v5 = (float)3.1415927;
  }
  v16 = cos(v5);
  v17 = v16 + 1.0;
  return (float)(v17 * 0.5);
}

