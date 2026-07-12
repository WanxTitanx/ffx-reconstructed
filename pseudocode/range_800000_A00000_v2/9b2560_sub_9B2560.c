// Function: sub_9B2560
// Address: 0x9b2560
double __cdecl sub_9B2560(float *a1, float *a2, float *a3, _DWORD *a4)
{
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st4
  float v9; // [esp-30h] [ebp-3Ch]
  float v10; // [esp-2Ch] [ebp-38h]
  float v11; // [esp-28h] [ebp-34h]
  float v12; // [esp-20h] [ebp-2Ch]
  float v13; // [esp-20h] [ebp-2Ch]
  float v14; // [esp-1Ch] [ebp-28h]
  float v15; // [esp-1Ch] [ebp-28h]
  float v16; // [esp-18h] [ebp-24h]
  float v17; // [esp-18h] [ebp-24h]
  float v18; // [esp-8h] [ebp-14h]
  float v19; // [esp-8h] [ebp-14h]
  float v22; // [esp-4h] [ebp-10h]
  float v23; // [esp-4h] [ebp-10h]

  v4 = *a1;
  v12 = *a2 - v4;
  v5 = a1[1];
  v14 = a2[1] - v5;
  v22 = a1[2];
  v16 = a2[2] - v22;
  v6 = v14;
  v18 = v12 * v12 + v14 * v14 + v16 * v16;
  if ( v18 <= 0.0 )
    return -1.0;
  v23 = v4 * v12 + v5 * v6 + v22 * v16;
  v19 = -v23 / v18;
  v7 = v19;
  if ( v19 < 1.0 )
  {
    if ( v19 > 0.0 )
    {
      a3[1] = v19;
      *a3 = 1.0 - v7;
      *a4 = 3;
      v13 = v12 * v7;
      v15 = v6 * v7;
      v17 = v16 * v7;
      v9 = *a1 + v13;
      v10 = v15 + a1[1];
      v11 = a1[2] + v17;
      return (float)(v9 * v9 + v10 * v10 + v11 * v11);
    }
    else
    {
      *a3 = 1.0;
      a3[1] = 0.0;
      *a4 = 1;
      return (float)(*a1 * *a1 + a1[1] * a1[1] + a1[2] * a1[2]);
    }
  }
  else
  {
    *a3 = 0.0;
    a3[1] = 1.0;
    *a4 = 2;
    return (float)(*a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2]);
  }
}
