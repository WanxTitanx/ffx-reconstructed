// Function: sub_9AC6F0
// Address: 0x9ac6f0
float *__cdecl sub_9AC6F0(float *a1, float *a2, float *a3, float *a4, float *a5, float *a6)
{
  double v6; // st3
  double v7; // st7
  float v9; // [esp-30h] [ebp-3Ch]
  float v10; // [esp-2Ch] [ebp-38h]
  float v11; // [esp-28h] [ebp-34h]
  float v12; // [esp-18h] [ebp-24h]
  float v13; // [esp-18h] [ebp-24h]
  float v14; // [esp-18h] [ebp-24h]
  float v15; // [esp-14h] [ebp-20h]
  float v16; // [esp-10h] [ebp-1Ch]
  float v17; // [esp-10h] [ebp-1Ch]
  float v18; // [esp-Ch] [ebp-18h]
  float v19; // [esp-4h] [ebp-10h]
  float v20; // [esp-4h] [ebp-10h]

  v9 = *a3 - *a1;
  v10 = a3[1] - a1[1];
  v11 = a3[2] - a1[2];
  v16 = a2[1];
  v18 = a4[1];
  v12 = a2[2];
  v6 = a4[2];
  v15 = v6 * v12 + v18 * v16 + *a4 * *a2;
  v17 = v12 * v11 + v16 * v10 + *a2 * v9;
  v13 = v11 * v6 + v10 * v18 + v9 * *a4;
  v14 = -v13;
  v7 = v15;
  v19 = 1.0 - v15 * v15;
  if ( v19 > 0.00009999999747378752 )
  {
    v20 = 1.0 / v19;
    *a5 = (v14 * v7 + v17) * v20;
    *a6 = v20 * (v14 + v7 * v17);
    return a6;
  }
  else
  {
    *a5 = 0.0;
    *a6 = 0.0;
    return a6;
  }
}
