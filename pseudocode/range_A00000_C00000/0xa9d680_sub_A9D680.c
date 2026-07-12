// Function: sub_A9D680
// Address: 0xa9d680
// Size: 0x2b9
// Prototype: int __fastcall(_DWORD, int n128)

int __fastcall sub_A9D680(int a1, int n128)
{
  int n128_1; // edi
  float v3; // xmm2_4
  float *v4; // esi
  int v5; // ecx
  float *v6; // edi
  float v7; // xmm0_4
  float v8; // xmm0_4
  int result; // eax
  float v10; // xmm1_4
  int n2; // edi
  float *v12; // esi
  float v13; // xmm0_4
  bool v14; // zf
  float v15; // xmm0_4
  int v16; // edi
  int v17; // esi
  int v18; // edx
  char v19; // cl
  int v20; // eax
  _DWORD *v21; // [esp+14h] [ebp-3Ch]
  int v22; // [esp+1Ch] [ebp-34h]
  int v23; // [esp+1Ch] [ebp-34h]
  float v24; // [esp+24h] [ebp-2Ch]
  float v25; // [esp+28h] [ebp-28h]
  float v26; // [esp+2Ch] [ebp-24h]
  int v29; // [esp+34h] [ebp-1Ch]
  int v30; // [esp+38h] [ebp-18h]
  int v31; // [esp+38h] [ebp-18h]
  float n128_2; // [esp+3Ch] [ebp-14h]
  float *v33; // [esp+40h] [ebp-10h]
  int v34; // [esp+44h] [ebp-Ch]
  int v35; // [esp+48h] [ebp-8h]
  int v36; // [esp+4Ch] [ebp-4h]

  n128_1 = n128;
  v34 = n128 / 4;
  v21 = malloc_0(4 * (n128 / 4));
  v33 = (float *)malloc_0(4 * (v34 + n128_1));
  n128_2 = (float)n128_1;
  libm_sse2_log_precise();
  libm_sse2_log_precise();
  v22 = (int)floor((float)n128_1 / 2.0 + 0.5);
  *(_DWORD *)(a1 + 4) = v22;
  *(_DWORD *)a1 = n128_1;
  *(_DWORD *)(a1 + 8) = v33;
  *(_DWORD *)(a1 + 12) = v21;
  v36 = 0;
  if ( v34 <= 0 )
  {
    v4 = v33;
  }
  else
  {
    v3 = 3.1415927 / n128_2;
    v4 = v33;
    v5 = 0;
    v25 = 3.1415927 / (float)(2 * n128_1);
    v30 = 0;
    v35 = 1;
    v6 = &v33[n128_1 >> 1];
    do
    {
      v26 = (float)v5 * v3;
      libm_sse2_cos_precise();
      v33[2 * v36] = v26;
      libm_sse2_sin_precise();
      v7 = -v26;
      v33[2 * v36 + 1] = v7;
      libm_sse2_cos_precise();
      v8 = (float)v35 * v25;
      *v6 = v8;
      libm_sse2_sin_precise();
      v35 += 2;
      v3 = 3.1415927 / n128_2;
      v5 = v30 + 4;
      v6[1] = v8;
      ++v36;
      v30 += 4;
      v6 += 2;
    }
    while ( v36 < v34 );
    n128_1 = n128;
  }
  result = n128_1 / 8;
  v31 = n128_1 / 8;
  if ( n128_1 / 8 > 0 )
  {
    v10 = 3.1415927 / n128_2;
    n2 = 2;
    v12 = &v4[n128];
    v29 = result;
    do
    {
      v24 = (float)n2 * v10;
      libm_sse2_cos_precise();
      v13 = v24 * 0.5;
      *v12 = v13;
      libm_sse2_sin_precise();
      v10 = 3.1415927 / n128_2;
      n2 += 4;
      v14 = v29-- == 1;
      v15 = v24 * -0.5;
      v12 += 2;
      *(v12 - 1) = v15;
    }
    while ( !v14 );
    result = v31;
  }
  v16 = 1 << (v22 - 2);
  v17 = 0;
  v23 = (1 << (v22 - 1)) - 1;
  if ( result > 0 )
  {
    do
    {
      v18 = 0;
      v19 = 0;
      if ( v16 )
      {
        v20 = v16;
        do
        {
          if ( (v20 & v17) != 0 )
            v18 |= 1 << v19;
          v20 = v16 >> ++v19;
        }
        while ( v16 >> v19 );
      }
      v21[2 * v17 + 1] = v18;
      result = (v23 & ~v18) - 1;
      v21[2 * v17++] = result;
    }
    while ( v17 < v31 );
  }
  *(float *)(a1 + 16) = 4.0 / n128_2;
  return result;
}

