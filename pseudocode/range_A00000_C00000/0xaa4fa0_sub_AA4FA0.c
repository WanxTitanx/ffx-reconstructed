// Function: sub_AA4FA0
// Address: 0xaa4fa0
// Size: 0x233
// Prototype: 

void __fastcall sub_AA4FA0(int a1, int *a2, int a3, int a4, double *a5, int n2, float a7, float a8)
{
  double *v8; // ebx
  int n2_2; // edi
  int n2_3; // esi
  double v11; // xmm0_8
  int v12; // edi
  int v13; // esi
  int v14; // eax
  double v15; // xmm0_8
  int n2_1; // eax
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // [esp+4h] [ebp-18h]
  int v29; // [esp+18h] [ebp-4h]

  v8 = a5;
  n2_2 = n2;
  n2_3 = 0;
  if ( n2 > 0 )
  {
    if ( (unsigned int)n2 >= 2 )
    {
      do
      {
        n2_3 += 2;
        *v8++ = *(double *)sub_AA51E0().m128_u64 * 2.0;
      }
      while ( n2_3 < n2 - (n2 & 1) );
      v8 = a5;
      n2_2 = n2;
    }
    for ( ; n2_3 < n2_2; *((_DWORD *)v8 + n2_3 - 1) = LODWORD(v11) )
    {
      v11 = *((float *)v8 + n2_3);
      libm_sse2_cos_precise();
      ++n2_3;
      *(float *)&v11 = v11 * 2.0;
    }
  }
  v12 = 0;
  if ( a3 > 0 )
  {
    v13 = 0;
    v14 = *a2;
    do
    {
      v26 = 0.5;
      v29 = v14;
      v15 = (float)((float)v14 * (float)(3.1415927 / (float)a4));
      libm_sse2_cos_precise();
      n2_1 = 1;
      v17 = v15 * 2.0;
      if ( n2 <= 1 )
      {
        v20 = 0.5;
        v18 = 0.5;
      }
      else
      {
        v18 = 0.5;
        do
        {
          v19 = v17 - *((float *)v8 + n2_1 - 1);
          n2_1 += 2;
          v18 = v18 * v19;
          v20 = (float)(v17 - *((float *)v8 + n2_1 - 2)) * v26;
          v26 = v20;
        }
        while ( n2_1 < n2 );
      }
      v21 = v17;
      if ( n2_1 == n2 )
      {
        v22 = 4.0;
        v17 = v17 * v17;
        v23 = (float)(v21 - *((float *)v8 + n2_1 - 1)) * v18;
        v24 = v23 * v23;
      }
      else
      {
        v22 = 2.0;
        v24 = (float)((float)(v17 + 2.0) * v18) * v18;
      }
      libm_sse2_sqrt_precise();
      libm_sse2_exp_precise();
      v25 = (a7 / (float)(v24 + (float)((float)((float)(v22 - v17) * v20) * v20)) - a8) * 0.1151292473077774;
      ++v12;
      *(float *)(v13 + a1) = v25 * *(float *)(v13 + a1);
      v13 = 4 * v12;
      v14 = a2[v12];
      if ( v14 == v29 )
      {
        do
        {
          ++v12;
          *(float *)(v13 + a1) = v25 * *(float *)(v13 + a1);
          v13 = 4 * v12;
          v14 = a2[v12];
        }
        while ( v14 == v29 );
        v8 = a5;
      }
    }
    while ( v12 < a3 );
  }
}

