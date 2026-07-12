// Function: sub_A974B0
// Address: 0xa974b0
// Size: 0x8ca
// Prototype: int __usercall@<eax>(void *@<ecx>, int, int, int)

float *__fastcall sub_A974B0(_DWORD *a1, int a2, _DWORD *a3, int i_2, int n46000)
{
  _DWORD *v5; // ebx
  double v6; // xmm0_8
  int v7; // esi
  signed int i_1; // edi
  int v9; // esi
  int n87_1; // eax
  int i_3; // esi
  double v12; // xmm0_8
  int i_4; // edx
  float v14; // xmm1_4
  float v15; // xmm2_4
  int i_5; // ecx
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  int v21; // ecx
  int i_6; // esi
  signed int i_7; // edx
  double v24; // xmm0_8
  int v25; // edx
  int i_12; // ecx
  float v27; // xmm0_4
  int v28; // ebx
  int v29; // edi
  double v30; // xmm0_8
  int v31; // edx
  int v32; // eax
  int v33; // ebx
  int v34; // ecx
  double v35; // xmm0_8
  int i; // esi
  double v37; // xmm0_8
  int j; // esi
  float *result; // eax
  int i_8; // esi
  double v41; // xmm1_8
  float v42; // xmm3_4
  int n1098907648; // xmm0_4
  int v44; // ecx
  float v45; // xmm3_4
  double v46; // xmm2_8
  float v47; // xmm0_4
  float v48; // xmm0_4
  int v49; // eax
  double v50; // xmm1_8
  float v51; // xmm0_4
  float v52; // xmm0_4
  double i_9; // [esp+20h] [ebp-44h]
  double v54; // [esp+20h] [ebp-44h]
  float v55; // [esp+34h] [ebp-30h]
  float v56; // [esp+3Ch] [ebp-28h]
  int i_10; // [esp+3Ch] [ebp-28h]
  int n87; // [esp+40h] [ebp-24h]
  int v59; // [esp+40h] [ebp-24h]
  int i_13; // [esp+48h] [ebp-1Ch]
  int v62; // [esp+48h] [ebp-1Ch]
  int v63; // [esp+4Ch] [ebp-18h]
  int v64; // [esp+50h] [ebp-14h]
  int v65; // [esp+54h] [ebp-10h]
  signed int i_11; // [esp+58h] [ebp-Ch]
  int n87_2; // [esp+6Ch] [ebp+8h]
  int v69; // [esp+6Ch] [ebp+8h]

  v5 = a1;
  v64 = -99;
  memset(a1, 0, 0x34u);
  v5[9] = *a3;
  v6 = (float)((float)(int)*a3 * 8.0);
  libm_sse2_log_precise();
  libm_sse2_log_precise();
  v7 = (int)(floor(v6 / 2.0 + 0.5) - 1.0);
  v5[8] = v7;
  i_9 = (double)i_2;
  libm_sse2_log_precise();
  i_1 = i_2;
  v9 = (int)(((float)((float)n46000 * 0.25) * 0.5 / (double)i_2 * 1.442695021629333 - 5.965784072875977)
           * (double)(1 << (v7 + 1))
           - (double)(int)*a3);
  v5[7] = v9;
  libm_sse2_log_precise();
  v5[10] = (int)(((float)((float)((float)i_2 + 0.25) * (float)n46000) * 0.5 / (double)i_2 * 1.442695021629333
                - 5.965784072875977)
               * (double)(1 << (*((_BYTE *)v5 + 32) + 1))
               + 0.5)
         - v9
         + 1;
  v5[4] = malloc_0(4 * i_2);
  v5[5] = malloc_0(4 * i_2);
  v5[6] = malloc_0(4 * i_2);
  v5[1] = a2;
  *v5 = i_2;
  v5[11] = n46000;
  v5[12] = 1065353216;
  if ( n46000 >= 26000 )
  {
    if ( n46000 >= 38000 )
    {
      if ( n46000 > 46000 )
        v5[12] = 1067660083;
    }
    else
    {
      v5[12] = 1064346583;
    }
  }
  else
  {
    v5[12] = 0;
  }
  n87_1 = 0;
  n87_2 = 0;
  i_3 = 0;
  do
  {
    n87 = n87_1 + 1;
    v12 = ((double)(n87_1 + 1) * 0.125 - 2.0 + 5.965784072875977) * 0.6931470036506653;
    libm_sse2_exp_precise();
    i_4 = (int)floor(v12 * 2.0 * i_9 / (double)n46000 + 0.5);
    v14 = *(float *)&dword_B81508[n87_2];
    if ( i_3 < i_4 )
    {
      v15 = (float)(dword_B8150C[n87_2] - v14) / (float)(i_4 - i_3);
      if ( i_4 - i_3 < 4 )
      {
LABEL_16:
        while ( i_3 < i_4 )
        {
          if ( i_3 >= i_2 )
            break;
          ++i_3;
          v20 = v14 + 100.0;
          *(float *)(v5[4] + 4 * i_3 - 4) = v20;
          v14 = v14 + v15;
        }
      }
      else
      {
        i_5 = i_3 + 2;
        while ( i_3 < i_2 )
        {
          v17 = v15 + v14;
          *(float *)(v5[4] + 4 * i_3) = v14 + 100.0;
          if ( i_5 - 1 >= i_2 )
          {
            ++i_3;
            break;
          }
          v18 = v15 + v17;
          *(float *)(v5[4] + 4 * i_3 + 4) = v17 + 100.0;
          if ( i_5 >= i_2 )
          {
            i_3 += 2;
            break;
          }
          v19 = v15 + v18;
          *(float *)(v5[4] + 4 * i_3 + 8) = v18 + 100.0;
          if ( i_5 + 1 >= i_2 )
          {
            i_3 += 3;
            break;
          }
          i_3 += 4;
          i_5 += 4;
          v14 = v15 + v19;
          *(float *)(v5[4] + 4 * i_3 - 4) = v19 + 100.0;
          if ( i_3 >= i_4 - 3 )
            goto LABEL_16;
        }
      }
    }
    n87_1 = n87;
    n87_2 = n87;
  }
  while ( n87 < 87 );
  if ( i_3 < i_2 )
  {
    if ( i_2 - i_3 >= 4 )
    {
      do
      {
        i_3 += 4;
        *(_DWORD *)(v5[4] + 4 * i_3 - 16) = *(_DWORD *)(v5[4] + 4 * i_3 - 20);
        *(_DWORD *)(v5[4] + 4 * i_3 - 12) = *(_DWORD *)(v5[4] + 4 * i_3 - 16);
        *(_DWORD *)(v5[4] + 4 * i_3 - 8) = *(_DWORD *)(v5[4] + 4 * i_3 - 12);
        *(_DWORD *)(v5[4] + 4 * i_3 - 4) = *(_DWORD *)(v5[4] + 4 * i_3 - 8);
      }
      while ( i_3 < i_2 - 3 );
    }
    for ( ; i_3 < i_2; *(_DWORD *)(v5[4] + 4 * i_3 - 4) = *(_DWORD *)(v5[4] + 4 * i_3 - 8) )
      ++i_3;
  }
  i_11 = 0;
  if ( i_2 > 0 )
  {
    v65 = n46000 / (2 * i_2);
    v69 = v65 * v65;
    v21 = 0;
    v63 = 0;
    v59 = 0;
    i_6 = 1;
    i_7 = 0;
    do
    {
      v24 = (float)((float)(i_7 * v21) * 0.0000000185);
      libm_sse2_atan_precise();
      libm_sse2_atan_precise();
      v25 = v64;
      i_12 = i_11;
      i_13 = v64 + *(_DWORD *)(a2 + 120);
      v27 = v24 * 2.240000009536743
          + (float)((float)v63 * 0.00073999999) * 13.10000038146973
          + (float)((float)v63 * 0.000099999997);
      v55 = v27;
      if ( i_13 < i_11 )
      {
        v28 = v64 * v65;
        v56 = v27 - *(float *)(a2 + 112);
        v29 = v64 * v69;
        do
        {
          v30 = (float)((float)(v25 * v29) * 0.0000000185);
          libm_sse2_atan_precise();
          libm_sse2_atan_precise();
          i_12 = i_11;
          if ( v56 <= v30 * 2.240000009536743
                    + (float)((float)v28 * 0.00073999999) * 13.10000038146973
                    + (float)((float)v28 * 0.000099999997) )
            break;
          v29 += v69;
          v28 += v65;
          v25 = ++v64;
          ++i_13;
        }
        while ( i_13 < i_11 );
        v5 = a1;
        i_1 = i_2;
      }
      if ( i_6 <= i_1 )
      {
        v31 = n46000 / (2 * i_2) * (n46000 / (2 * i_2));
        i_10 = i_12 + *(_DWORD *)(a2 + 124);
        v32 = n46000 / (2 * i_2);
        v33 = i_6 * v65;
        v34 = i_6 * v69;
        v62 = i_6 * v69;
        do
        {
          if ( i_6 >= i_10 )
          {
            v35 = (float)((float)(v34 * i_6) * 0.0000000185);
            libm_sse2_atan_precise();
            libm_sse2_atan_precise();
            if ( (float)(*(float *)(a2 + 116) + v55) <= v35 * 2.240000009536743
                                                      + (float)((float)v33 * 0.00073999999) * 13.10000038146973
                                                      + (float)((float)v33 * 0.000099999997) )
              break;
            v34 = v62;
            v32 = n46000 / (2 * i_2);
            v31 = v32 * v32;
          }
          ++i_6;
          v34 += v31;
          v33 += v32;
          v62 = v34;
        }
        while ( i_6 <= i_1 );
        v5 = a1;
      }
      *(_DWORD *)(v5[6] + 4 * i_11) = i_6 + (v64 << 16) - 65537;
      v21 = v69 + v59;
      i_7 = i_11 + 1;
      i_11 = i_7;
      v59 += v69;
      v63 += v65;
    }
    while ( i_7 < i_1 );
  }
  for ( i = 0;
        i < i_1;
        *(_DWORD *)(v5[5] + 4 * i - 4) = (int)((v37 * 1.442695021629333 - 5.965784072875977)
                                             * (double)(1 << (v5[8] + 1))
                                             + 0.5) )
  {
    v37 = (float)((float)i + 0.25) * 0.5 * (double)n46000 / i_9;
    libm_sse2_log_precise();
    ++i;
  }
  v5[2] = sub_A96840(
            i_1,
            (unsigned int *)(a2 + 36),
            (double)n46000 * 0.5 / i_9,
            *(_DWORD *)(a2 + 24),
            *(float *)(a2 + 28));
  v5[3] = malloc_0(0xCu);
  for ( j = 0; j < 12; *(_DWORD *)(j + v5[3] - 4) = result )
  {
    result = (float *)malloc_0(4 * i_2);
    j += 4;
  }
  i_8 = 0;
  if ( i_2 > 0 )
  {
    v41 = i_9 * 2.0;
    v54 = i_9 * 2.0;
    do
    {
      libm_sse2_log_precise();
      v42 = (((double)i_8 + 0.5) * (double)n46000 / v41 * 1.442695021629333 - 5.965784072875977) * 2.0;
      n1098907648 = 0;
      if ( v42 < 0.0 || (n1098907648 = 1098907648, v42 >= 16.0) )
        v42 = *(float *)&n1098907648;
      v44 = (int)v42;
      ++i_8;
      v45 = v42 - (float)(int)v42;
      v46 = 1.0 - v45;
      v47 = (float)(*(float *)(v5[1] + 4 * v44 + 136) * v45) + *(float *)(v5[1] + 4 * v44 + 132) * v46;
      *(float *)(*(_DWORD *)v5[3] + 4 * i_8 - 4) = v47;
      v48 = (float)(*(float *)(v5[1] + 4 * v44 + 204) * v45) + *(float *)(v5[1] + 4 * v44 + 200) * v46;
      *(float *)(*(_DWORD *)(v5[3] + 4) + 4 * i_8 - 4) = v48;
      v49 = v5[1];
      v50 = (float)(*(float *)(v49 + 4 * v44 + 272) * v45);
      v51 = *(float *)(v49 + 4 * v44 + 268);
      result = *(float **)(v5[3] + 8);
      v52 = v50 + v51 * v46;
      v41 = v54;
      result[i_8 - 1] = v52;
    }
    while ( i_8 < i_2 );
  }
  return result;
}

