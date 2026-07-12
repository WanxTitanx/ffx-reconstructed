// Function: sub_9B3740
// Address: 0x9b3740
int __stdcall sub_9B3740(float *a1, float *a2, float *a3, float *a4, float *a5)
{
  double v5; // st4
  float v7; // [esp-40h] [ebp-4Ch]
  float v8; // [esp-3Ch] [ebp-48h]
  float v9; // [esp-38h] [ebp-44h]
  float v10; // [esp-30h] [ebp-3Ch]
  float v11; // [esp-30h] [ebp-3Ch]
  float v12; // [esp-2Ch] [ebp-38h]
  float v13; // [esp-2Ch] [ebp-38h]
  float v14; // [esp-28h] [ebp-34h]
  float v15; // [esp-28h] [ebp-34h]
  float v16; // [esp-20h] [ebp-2Ch]
  float v17; // [esp-20h] [ebp-2Ch]
  float v18; // [esp-1Ch] [ebp-28h]
  float v19; // [esp-1Ch] [ebp-28h]
  float v20; // [esp-18h] [ebp-24h]
  float v21; // [esp-18h] [ebp-24h]
  float v22; // [esp-Ch] [ebp-18h]
  float v23; // [esp-Ch] [ebp-18h]
  float v24; // [esp-Ch] [ebp-18h]
  float v25; // [esp-8h] [ebp-14h]

  v16 = *a4 - *a2;
  v25 = a2[1];
  v18 = a4[1] - v25;
  v22 = a2[2];
  v20 = a4[2] - v22;
  v10 = *a3 - *a2;
  v12 = a3[1] - v25;
  v14 = a3[2] - v22;
  v7 = v12 * v20 - v14 * v18;
  v8 = v14 * v16 - v20 * v10;
  v9 = v18 * v10 - v12 * v16;
  v21 = a1[2] - v22;
  v11 = *a5 - *a2;
  v13 = a5[1] - v25;
  v15 = a5[2] - v22;
  v23 = v15 * v9 + v11 * v7 + v13 * v8;
  v5 = v23;
  if ( v5 * v5 < 0.000000009999999051046871 )
    return -1;
  v17 = *a1 - *a2;
  v19 = a1[1] - v25;
  v24 = v7 * v17 + v8 * v19 + v9 * v21;
  return v5 * v24 < 0.0;
}
