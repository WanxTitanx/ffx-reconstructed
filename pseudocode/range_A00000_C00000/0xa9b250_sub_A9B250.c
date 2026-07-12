// Function: sub_A9B250
// Address: 0xa9b250
// Size: 0x4f5
// Prototype: 

int __fastcall sub_A9B250(float *a1, int a2, int a3, int a4, int a5)
{
  int n4; // ebx
  float v7; // xmm0_4
  void *v8; // esp
  float v9; // xmm1_4
  int v10; // kr00_4
  int n2_1; // edx
  float v12; // xmm2_4
  int n4_1; // esi
  float *v14; // edx
  int v15; // ebx
  int v16; // ecx
  unsigned int v17; // esi
  char *v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm0_4
  float *v21; // ecx
  float v22; // xmm0_4
  int v23; // eax
  float v24; // xmm2_4
  float v25; // xmm1_4
  int v26; // ecx
  int n15; // eax
  float v28; // xmm0_4
  __m128d v29; // xmm0
  __m128 v30; // xmm0
  __m128d v31; // xmm0
  __m128 v32; // xmm2
  float v33; // xmm0_4
  int v34; // eax
  __m128d v35; // xmm0
  int *n4_5; // esi
  int v37; // ebx
  int n4_2; // edx
  int n4_3; // edi
  float v40; // xmm2_4
  int v41; // ecx
  int v42; // eax
  unsigned int v43; // esi
  float v44; // xmm0_4
  float v45; // xmm1_4
  float *v46; // ecx
  int v47; // edx
  float *v48; // eax
  float v49; // xmm0_4
  int v50; // ecx
  float v51; // xmm4_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  int v54; // edi
  float v55; // xmm3_4
  float *v56; // eax
  float v57; // xmm5_4
  int n2_3; // edx
  float v59; // xmm3_4
  float v60; // xmm1_4
  int v61; // eax
  float *n2_4; // ecx
  int result; // eax
  float v64; // [esp+0h] [ebp-40h] BYREF
  float v65; // [esp+4h] [ebp-3Ch] BYREF
  float v66; // [esp+8h] [ebp-38h]
  int n2_2; // [esp+Ch] [ebp-34h]
  int v68; // [esp+10h] [ebp-30h]
  float v69; // [esp+14h] [ebp-2Ch]
  float v70; // [esp+18h] [ebp-28h]
  int v71; // [esp+1Ch] [ebp-24h]
  int v72; // [esp+20h] [ebp-20h]
  int v73; // [esp+24h] [ebp-1Ch]
  int n2; // [esp+28h] [ebp-18h]
  int v75; // [esp+2Ch] [ebp-14h]
  int *n4_4; // [esp+30h] [ebp-10h]
  float v77; // [esp+34h] [ebp-Ch]
  int v78; // [esp+38h] [ebp-8h]
  float *v79; // [esp+3Ch] [ebp-4h]

  n4 = *((_DWORD *)a1 + 1);
  v7 = a1[3];
  v68 = a2;
  n4_4 = (int *)n4;
  v78 = 0;
  v69 = v7;
  v8 = alloca(4 * n4);
  v9 = *(float *)(a2 + 60);
  v10 = *((_DWORD *)a1 + 39);
  n2_1 = v10 / 2;
  n2 = 2;
  if ( v10 / 2 < 2 )
    n2_1 = n2;
  v12 = v9 - (float)(v10 / 2 - 2);
  v79 = &v64;
  n2_2 = n2_1;
  v77 = v12;
  if ( v12 < 0.0 )
  {
    v12 = 0.0;
    v77 = 0.0;
  }
  if ( v12 > v9 )
    v77 = v9;
  n4_1 = 0;
  if ( n4 >= 4 )
  {
    v14 = &v65;
    v15 = a3 + 12;
    v75 = a3 - (_DWORD)&v64;
    v73 = 4 - (_DWORD)&v64;
    v72 = 8 - (_DWORD)&v64;
    v16 = -4 - (_DWORD)&v64;
    v71 = -4 - (_DWORD)&v64;
    LODWORD(v70) = 4 * (((unsigned int)(n4_4 - 1) >> 2) + 1);
    v17 = ((unsigned int)(n4_4 - 1) >> 2) + 1;
    do
    {
      v18 = (char *)v14 + v16;
      v14 += 4;
      v19 = *(float *)&v18[*((_DWORD *)a1 + 9)] * *(float *)(v15 - 12);
      v15 += 16;
      *(v14 - 5) = v19;
      v20 = *(float *)&v18[*((_DWORD *)a1 + 9) + 4];
      v16 = v71;
      *(v14 - 4) = v20 * *(float *)((char *)v14 + v75 - 16);
      *(v14 - 3) = *(float *)((char *)v14 + v73 + *((_DWORD *)a1 + 9) - 16) * *(float *)(v15 - 20);
      *(v14 - 2) = *(float *)((char *)v14 + v72 + *((_DWORD *)a1 + 9) - 16) * *(float *)(v15 - 16);
      --v17;
    }
    while ( v17 );
    n4_1 = LODWORD(v70);
    n4 = (int)n4_4;
  }
  if ( n4_1 < n4 )
  {
    v21 = &v64 + n4_1;
    do
    {
      ++n4_1;
      v22 = *(float *)(*((_DWORD *)a1 + 9) + 4 * n4_1 - 4) * *(float *)((char *)v21++ + a3 - (_DWORD)&v64);
      *(v21 - 1) = v22;
    }
    while ( n4_1 < n4 );
  }
  sub_A9D3E0(&v64);
  v23 = *(_DWORD *)(a5 + 140);
  v24 = v65 * 0.7 * v65 + (float)(v64 * v64) + v66 * 0.2 * v66;
  if ( v23 )
  {
    v25 = v24 + *(float *)(a5 + 132);
    *(float *)(a5 + 136) = v24 + *(float *)(a5 + 136);
  }
  else
  {
    v25 = v24 + *(float *)(a5 + 136);
    *(float *)(a5 + 136) = v24;
  }
  *(float *)(a5 + 132) = v25;
  v26 = 0;
  *(float *)(a5 + 132) = v25 - *(float *)(a5 + 4 * v23 + 72);
  *(float *)(a5 + 4 * v23 + 72) = v24;
  n15 = ++*(_DWORD *)(a5 + 140);
  if ( n15 >= 15 )
    n15 = 0;
  v28 = v25 * 0.0625;
  v70 = v28;
  *(_DWORD *)(a5 + 140) = n15;
  v29 = (__m128d)COERCE_UNSIGNED_INT64((double)(LODWORD(v70) & 0x7FFFFFFF));
  v29.m128d_f64[0] = v29.m128d_f64[0] + 0.0;
  v30 = _mm_cvtpd_ps(v29);
  v30.m128_f32[0] = (float)(v30.m128_f32[0] * 0.00000071771143) - 764.61621;
  v31 = _mm_cvtps_pd(v30);
  v31.m128d_f64[0] = v31.m128d_f64[0] * 0.5 - 15.0;
  v32 = _mm_cvtpd_ps(v31);
  if ( n4 / 2 > 0 )
  {
    do
    {
      v70 = (float)(*(&v64 + v26) * *(&v64 + v26)) + (float)(*(&v64 + v26 + 1) * *(&v64 + v26 + 1));
      v33 = (float)((float)((float)((double)(LODWORD(v70) & 0x7FFFFFFF) + 0.0) * 0.00000071771143) - 764.61621) * 0.5;
      if ( v32.m128_f32[0] > v33 )
        v33 = v32.m128_f32[0];
      if ( v69 > v33 )
        v33 = v69;
      v34 = v26 >> 1;
      v26 += 2;
      *(&v64 + v34) = v33;
      v35 = _mm_cvtps_pd(v32);
      v35.m128d_f64[0] = v35.m128d_f64[0] - 8.0;
      v32 = _mm_cvtpd_ps(v35);
    }
    while ( v26 < n4 / 2 );
  }
  n4_5 = (int *)(a5 + 68);
  v75 = 0;
  n2 = v68 + 32;
  n4_4 = (int *)(a5 + 68);
  v37 = a4 + 8;
  do
  {
    n4_2 = *(_DWORD *)(v37 - 4);
    n4_3 = 0;
    v40 = 0.0;
    if ( n4_2 >= 4 )
    {
      v41 = *(_DWORD *)v37 + 8;
      v42 = (int)&v79[*(_DWORD *)(v37 - 8) + 2];
      v43 = ((unsigned int)(n4_2 - 4) >> 2) + 1;
      n4_3 = 4 * v43;
      do
      {
        v44 = *(float *)(v42 - 4) * *(float *)(v41 - 4);
        v45 = (float)(*(float *)(v42 - 8) * *(float *)(v41 - 8)) + v40;
        v41 += 16;
        v42 += 16;
        v40 = (float)((float)(v45 + v44) + (float)(*(float *)(v41 - 16) * *(float *)(v42 - 16)))
            + (float)(*(float *)(v42 - 12) * *(float *)(v41 - 12));
        --v43;
      }
      while ( v43 );
      n4_5 = n4_4;
    }
    if ( n4_3 < n4_2 )
    {
      v46 = (float *)(*(_DWORD *)v37 + 4 * n4_3);
      v47 = n4_2 - n4_3;
      v48 = &v79[n4_3 + *(_DWORD *)(v37 - 8)];
      n4_5 = n4_4;
      do
      {
        v49 = *v46++ * *v48++;
        v40 = v40 + v49;
        --v47;
      }
      while ( v47 );
    }
    v50 = *n4_5 - 1;
    v51 = *(float *)(v37 + 4) * v40;
    v52 = -99999.0;
    v53 = 99999.0;
    if ( v50 < 0 )
      v50 = *n4_5 + 16;
    v54 = v75;
    v55 = *(float *)(a5 + 4 * (v75 + v50));
    v56 = (float *)(a5 + 4 * (v75 + v50));
    if ( v51 <= v55 )
      v57 = *(float *)(a5 + 4 * (v75 + v50));
    else
      v57 = v51;
    if ( v55 > v51 )
      v55 = v51;
    n2_3 = n2_2;
    if ( n2_2 > 0 )
    {
      do
      {
        --v56;
        if ( --v50 < 0 )
        {
          v50 += 17;
          v56 += 17;
        }
        if ( v52 <= *v56 )
          v52 = *v56;
        if ( *v56 <= v53 )
          v53 = *v56;
        --n2_3;
      }
      while ( n2_3 );
    }
    v59 = v55 - v53;
    v60 = v77;
    *(float *)(a5 + 4 * (v75 + (*n4_5)++)) = v51;
    v61 = *n4_5;
    if ( *n4_5 >= 17 )
      v61 = 0;
    n2_4 = (float *)n2;
    *n4_5 = v61;
    result = v78;
    if ( (float)(v57 - v52) > (float)(*(n2_4 - 7) + v60) )
    {
      result = v78 | 5;
      v78 |= 5u;
    }
    if ( (float)(*n2_4 - v60) > v59 )
    {
      result |= 2u;
      v78 = result;
    }
    n4_5 += 36;
    v37 += 16;
    v75 = v54 + 36;
    n4_4 = n4_5;
    n2 = (int)(n2_4 + 1);
  }
  while ( v54 + 36 < 252 );
  return result;
}

