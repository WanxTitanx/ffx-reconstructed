// Function: sub_9C9C30
// Address: 0x9c9c30
float *__thiscall sub_9C9C30(float *this, int a2, float *a3, float *a4, float *a5)
{
  float v5; // xmm1_4
  float *result; // eax
  int v7; // xmm0_4
  double v8; // st6
  double v9; // rt0
  double v10; // st5
  double v11; // st6
  double v12; // st6
  double v13; // st7
  int v14; // [esp-1Ch] [ebp-28h]
  float v15; // [esp-8h] [ebp-14h]
  float v16; // [esp-8h] [ebp-14h]
  float v17; // [esp-8h] [ebp-14h]
  float v18; // [esp-8h] [ebp-14h]
  float v19; // [esp-8h] [ebp-14h]
  float v20; // [esp-8h] [ebp-14h]
  float v21; // [esp-8h] [ebp-14h]
  float v22; // [esp-8h] [ebp-14h]
  float v23; // [esp-8h] [ebp-14h]
  float v24; // [esp-8h] [ebp-14h]
  float v25; // [esp-8h] [ebp-14h]
  float v26; // [esp-8h] [ebp-14h]
  float v27; // [esp-4h] [ebp-10h]
  float v28; // [esp-4h] [ebp-10h]
  float v29; // [esp-4h] [ebp-10h]
  float v30; // [esp-4h] [ebp-10h]

  v5 = *(float *)(a2 + 12);
  v27 = v5;
  if ( v5 >= -1.0 )
  {
    if ( v5 > 1.0 )
      v27 = 1.0;
  }
  else
  {
    v27 = -1.0;
  }
  v28 = acos(v27);
  result = a3;
  v29 = v28 + v28;
  *a3 = v29;
  if ( v29 > 0.00000011920929 )
  {
    v14 = *(_DWORD *)(a2 + 4);
    v7 = *(_DWORD *)(a2 + 8);
    *a4 = *(float *)a2;
    *((_DWORD *)a4 + 1) = v14;
    *((_DWORD *)a4 + 2) = v7;
    result = 0;
    a4[3] = 0.0;
    v15 = *a4 * *a4 + a4[1] * a4[1] + a4[2] * a4[2];
    v16 = sqrt(v15);
    v17 = 1.0 / v16;
    v8 = v17;
    *a4 = *a4 * v17;
    v18 = v17 * a4[1];
    a4[1] = v18;
    v9 = v18;
    v19 = v8 * a4[2];
    v10 = v19;
    a4[2] = v19;
    v20 = v9;
    *a5 = *(this + 120);
    v11 = v20;
    v21 = fabs(v20);
    if ( v21 > 0.00000011920929 )
    {
      v30 = -v10;
      v22 = v30 * v30 / (v11 * v11);
      v12 = v22 + 1.0;
      v13 = v22;
      v23 = 1.0 / (*(this + 121) * *(this + 121));
      v24 = v13 / (*(this + 120) * *(this + 120)) + v23;
      v25 = v12 / v24;
      v26 = sqrt(v25);
      *a5 = v26;
    }
  }
  return result;
}
