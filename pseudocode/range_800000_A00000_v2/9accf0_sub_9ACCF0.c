// Function: sub_9ACCF0
// Address: 0x9accf0
double __cdecl sub_9ACCF0(float *a1, float *a2, float *a3, int a4)
{
  double v4; // st7
  double v5; // st5
  double v6; // st4
  double v7; // st6
  double v8; // st3
  double v9; // st2
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // st3
  double v14; // st2
  float v16; // [esp-50h] [ebp-5Ch]
  float v17; // [esp-50h] [ebp-5Ch]
  float v18; // [esp-4Ch] [ebp-58h]
  float v19; // [esp-4Ch] [ebp-58h]
  float v20; // [esp-48h] [ebp-54h]
  float v21; // [esp-48h] [ebp-54h]
  float v22; // [esp-40h] [ebp-4Ch]
  float v23; // [esp-40h] [ebp-4Ch]
  float v24; // [esp-3Ch] [ebp-48h]
  float v25; // [esp-3Ch] [ebp-48h]
  float v26; // [esp-38h] [ebp-44h]
  float v27; // [esp-38h] [ebp-44h]
  float v28; // [esp-30h] [ebp-3Ch]
  float v29; // [esp-30h] [ebp-3Ch]
  float v30; // [esp-30h] [ebp-3Ch]
  float v31; // [esp-2Ch] [ebp-38h]
  float v32; // [esp-2Ch] [ebp-38h]
  float v33; // [esp-2Ch] [ebp-38h]
  float v34; // [esp-28h] [ebp-34h]
  float v35; // [esp-28h] [ebp-34h]
  float v36; // [esp-28h] [ebp-34h]
  float v37; // [esp-14h] [ebp-20h]
  float v39; // [esp-10h] [ebp-1Ch]
  float v40; // [esp-Ch] [ebp-18h]
  float v41; // [esp-4h] [ebp-10h]
  float v42; // [esp-4h] [ebp-10h]

  v28 = *a3 - *a1;
  v40 = a1[1];
  v31 = a3[1] - v40;
  v39 = a1[2];
  v34 = a3[2] - v39;
  v22 = *a2 - *a1;
  v24 = a2[1] - v40;
  v26 = a2[2] - v39;
  v4 = v24;
  v5 = v31;
  v6 = v22;
  v7 = v28;
  v8 = v34;
  v41 = v26 * v34 + v22 * v28 + v24 * v31;
  if ( v41 <= 0.0 )
  {
    v10 = 0.0;
    v11 = v22;
    v13 = v31;
    v14 = v28;
    v12 = v34;
  }
  else
  {
    v37 = v6 * v6 + v4 * v4 + v26 * v26;
    if ( v37 <= (double)v41 )
    {
      v30 = v7 - v6;
      v33 = v5 - v4;
      v36 = v8 - v26;
      v10 = 1.0;
      v11 = v22;
      v12 = v36;
      v14 = v30;
      v13 = v33;
    }
    else
    {
      v42 = v41 / v37;
      v16 = v6 * v42;
      v18 = v4 * v42;
      v20 = v26 * v42;
      v9 = v7 - v16;
      v10 = v42;
      v29 = v9;
      v32 = v5 - v18;
      v11 = v22;
      v35 = v8 - v20;
      v12 = v35;
      v13 = v32;
      v14 = v29;
    }
  }
  v17 = v11 * v10;
  v19 = v4 * v10;
  v21 = v10 * v26;
  v23 = *a1 + v17;
  *(float *)a4 = v23;
  v25 = v40 + v19;
  *(float *)(a4 + 4) = v25;
  v27 = v39 + v21;
  *(float *)(a4 + 8) = v27;
  *(_DWORD *)(a4 + 12) = 0;
  return (float)(v14 * v14 + v13 * v13 + v12 * v12);
}
