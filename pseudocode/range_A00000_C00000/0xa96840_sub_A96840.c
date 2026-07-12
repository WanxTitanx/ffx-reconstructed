// Function: sub_A96840
// Address: 0xa96840
// Size: 0x9a0
// Prototype: 

_DWORD *__usercall sub_A96840@<eax>(
        signed int count_12@<edx>,
        unsigned int *a2@<ecx>,
        float a3@<xmm1>,
        int a4@<xmm3>,
        float a5)
{
  unsigned int *v5; // edi
  void *v6; // esp
  float *j_2; // edx
  int *v8; // eax
  int n16_10; // ecx
  int n88; // ecx
  float *src_1; // edi
  float *v12; // esi
  int n56; // ebx
  float v14; // xmm0_4
  const void *j_1; // eax
  float *j_7; // esi
  int n8; // edi
  int i; // ecx
  float v19; // xmm1_4
  float v20; // xmm0_4
  int n2_1; // ebx
  __m128d v22; // xmm3
  int n2; // eax
  double n2_2; // xmm0_8
  __m128 v25; // xmm1
  __m128 *n16_5; // eax
  int n14; // ecx
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  float *dst; // edx
  float v31; // xmm1_4
  float *v32; // eax
  int n7; // ecx
  float v34; // xmm0_4
  int v35; // ecx
  int n56_1; // eax
  float v37; // xmm0_4
  char *v38; // edx
  int n7_1; // ebx
  char *v40; // edi
  float *v41; // ecx
  float *v42; // eax
  int n14_1; // esi
  float v44; // xmm1_4
  float v45; // xmm1_4
  float v46; // xmm1_4
  float *n56_6; // esi
  float *n56_7; // eax
  int v49; // edx
  int n56_2; // ecx
  float v51; // xmm1_4
  void *buf; // ebx
  int n16_8; // edi
  double v54; // xmm0_8
  int n16_12; // esi
  double v56; // xmm0_8
  double v57; // xmm0_8
  double n16_7; // st7
  int n16_2; // esi
  int n16; // eax
  int n8_1; // edi
  void *v62; // eax
  signed int count; // edx
  int v64; // ecx
  int count_4; // edi
  double v66; // xmm1_8
  int j_5; // eax
  double v68; // xmm0_8
  int count_3; // esi
  double v70; // xmm0_8
  signed int count_2; // edx
  double count_13; // xmm0_8
  int count_5; // esi
  float *j_4; // ecx
  float v75; // xmm1_4
  float *n56_8; // ecx
  float v77; // xmm1_4
  int count_8; // edi
  int n56_3; // eax
  double v80; // xmm0_8
  int count_7; // esi
  double v82; // xmm0_8
  int count_6; // edx
  double count_14; // xmm0_8
  int count_9; // eax
  float *n56_9; // esi
  float v87; // xmm1_4
  float v88; // xmm1_4
  int count_10; // esi
  int n56_4; // ecx
  _DWORD *v91; // edi
  double v92; // xmm0_8
  int count_11; // eax
  int v94; // edx
  int n16_3; // ecx
  float *v96; // eax
  float n16_4; // xmm0_4
  int n55; // ecx
  float *v99; // eax
  int v101; // [esp+8h] [ebp-7F54h] BYREF
  _DWORD j_6[7616]; // [esp+18h] [ebp-7F44h] BYREF
  _OWORD v103[112]; // [esp+7718h] [ebp-844h] BYREF
  _BYTE src[224]; // [esp+7E18h] [ebp-144h] BYREF
  double X_1; // [esp+7EF8h] [ebp-64h]
  double X; // [esp+7F00h] [ebp-5Ch]
  double v107; // [esp+7F08h] [ebp-54h]
  double v108; // [esp+7F10h] [ebp-4Ch]
  double n16_6; // [esp+7F18h] [ebp-44h]
  signed int count_1; // [esp+7F24h] [ebp-38h]
  _DWORD *v111; // [esp+7F28h] [ebp-34h]
  int n16_1; // [esp+7F2Ch] [ebp-30h]
  double n16_11; // [esp+7F30h] [ebp-2Ch]
  int v114; // [esp+7F38h] [ebp-24h]
  float *j_3; // [esp+7F3Ch] [ebp-20h]
  int n16_9; // [esp+7F40h] [ebp-1Ch]
  float v117; // [esp+7F44h] [ebp-18h]
  int j; // [esp+7F48h] [ebp-14h]
  unsigned int *v119; // [esp+7F4Ch] [ebp-10h]
  int n8_2; // [esp+7F50h] [ebp-Ch]
  float *n56_5; // [esp+7F54h] [ebp-8h]

  HIDWORD(n16_6) = a4;
  count_1 = count_12;
  v117 = a3;
  v5 = a2;
  v119 = a2;
  v6 = alloca(4 * count_12);
  HIDWORD(n16_11) = &v101;
  v111 = malloc_0(0x44u);
  memset(j_6, 0, sizeof(j_6));
  j = (int)&unk_B81668;
  j_2 = (float *)j_6;
  v8 = &dword_B8150C;
  n16_10 = 2 - (_DWORD)v5;
  n8_2 = 0;
  j_3 = (float *)j_6;
  v114 = (int)&dword_B8150C;
  n16_9 = 2 - (_DWORD)v5;
  do
  {
    n88 = (int)v5 + n16_10;
    src_1 = (float *)src;
    v12 = (float *)v8;
    n56 = 56;
    do
    {
      v14 = 999.0;
      if ( n88 - 2 >= 88 )
      {
        v14 = -30.0;
      }
      else if ( *(v12 - 1) < 999.0 )
      {
        v14 = *(v12 - 1);
      }
      if ( n88 - 1 >= 88 )
      {
        if ( v14 > -30.0 )
          v14 = -30.0;
      }
      else if ( v14 > *v12 )
      {
        v14 = *v12;
      }
      if ( n88 >= 88 )
      {
        if ( v14 > -30.0 )
          v14 = -30.0;
      }
      else if ( v14 > v12[1] )
      {
        v14 = v12[1];
      }
      if ( ++n88 >= 88 )
      {
        if ( v14 > -30.0 )
          v14 = -30.0;
      }
      else if ( v14 > v12[2] )
      {
        v14 = v12[2];
      }
      *src_1 = v14;
      ++v12;
      ++src_1;
      --n56;
    }
    while ( n56 );
    j_1 = (const void *)j;
    qmemcpy(j_2 + 112, (const void *)j, 0x540u);
    qmemcpy(j_2, j_1, 0xE0u);
    n56_5 = j_2 + 56;
    qmemcpy(j_2 + 56, j_1, 0xE0u);
    j_7 = j_3;
    n8 = 8;
    do
    {
      for ( i = 16; i > -40; --i )
      {
        v19 = (float)((float)(int)abs32(i) * a5) + *((float *)&n16_6 + 1);
        if ( v19 < 0.0 && *((float *)&n16_6 + 1) > 0.0 || v19 > 0.0 && *((float *)&n16_6 + 1) < 0.0 )
          v19 = 0.0;
        v20 = *j_7++ + v19;
        *(j_7 - 1) = v20;
      }
      j_3 = j_7;
      --n8;
    }
    while ( n8 );
    n2_1 = 0;
    v22 = _mm_cvtps_pd((__m128)*v119);
    v22.m128d_f64[0] = v22.m128d_f64[0] + 100.0;
    do
    {
      n2 = n2_1;
      if ( n2_1 < 2 )
        n2 = 2;
      n2_2 = (double)n2;
      v25.m128_u64[1] = *(_QWORD *)&v22.m128d_f64[1];
      n16_5 = (__m128 *)&j_6[56 * n2_1 + 56 * n8_2];
      n16_1 = (int)n16_5;
      n14 = 14;
      *(double *)v25.m128_u64 = v22.m128d_f64[0] - n2_2 * 10.0 - 30.0;
      v25.m128_f32[0] = *(double *)v25.m128_u64;
      v28 = _mm_shuffle_ps(v25, v25, 0);
      do
      {
        v29 = *n16_5++;
        n16_5[-1] = _mm_add_ps(v29, v28);
        --n14;
      }
      while ( n14 );
      dst = (float *)&v103[14 * n2_1];
      qmemcpy(dst, src, 0xE0u);
      v31 = 100.0 - (float)((float)n2_1 * 10.0) - 30.0;
      v32 = dst + 2;
      n7 = 7;
      do
      {
        v34 = v31 + *(v32 - 2);
        v32 += 8;
        *(v32 - 10) = v34;
        *(v32 - 9) = v31 + *(v32 - 9);
        *(v32 - 8) = v31 + *(v32 - 8);
        *(v32 - 7) = v31 + *(v32 - 7);
        *(v32 - 6) = v31 + *(v32 - 6);
        *(v32 - 5) = v31 + *(v32 - 5);
        *(v32 - 4) = v31 + *(v32 - 4);
        *(v32 - 3) = v31 + *(v32 - 3);
        --n7;
      }
      while ( n7 );
      v35 = n16_1 - (_DWORD)dst;
      n56_1 = 56;
      do
      {
        v37 = *(float *)((char *)dst + v35);
        if ( v37 > *dst )
          *dst = v37;
        ++dst;
        --n56_1;
      }
      while ( n56_1 );
      ++n2_1;
    }
    while ( n2_1 < 8 );
    v38 = (char *)v103;
    n7_1 = 7;
    do
    {
      v40 = v38 + 224;
      v41 = (float *)(v38 + 12);
      v42 = (float *)(v38 + 228);
      n14_1 = 14;
      do
      {
        v44 = *(v41 - 3);
        if ( *(v42 - 1) > v44 )
          *(v42 - 1) = v44;
        v45 = *(v42 - 56);
        if ( *v42 > v45 )
          *v42 = v45;
        v46 = *(v41 - 1);
        if ( v42[1] > v46 )
          v42[1] = v46;
        if ( v42[2] > *v41 )
          v42[2] = *v41;
        v42 += 4;
        v41 += 4;
        --n14_1;
      }
      while ( n14_1 );
      n56_6 = n56_5;
      n56_7 = n56_5;
      v49 = v40 - (char *)n56_5;
      n56_2 = 56;
      do
      {
        v51 = *(float *)((char *)n56_7 + v49);
        if ( *n56_7 > v51 )
          *n56_7 = v51;
        ++n56_7;
        --n56_2;
      }
      while ( n56_2 );
      v38 = v40;
      n56_5 = n56_6 + 56;
      --n7_1;
    }
    while ( n7_1 );
    j += 1344;
    n8_2 += 8;
    j_2 = j_3;
    n16_10 = n16_9;
    v8 = (int *)(v114 + 16);
    v5 = v119 + 1;
    v114 = (int)v8;
    ++v119;
  }
  while ( (int)v8 < (int)dword_B8161C );
  buf = (void *)HIDWORD(n16_11);
  n16_8 = 0;
  v119 = 0;
  for ( j = 8; j < 144; j += 8 )
  {
    v111[n16_8] = malloc_0(0x20u);
    v107 = (double)n16_8 * 0.5;
    v54 = (v107 + 5.965784072875977) * 0.6931470036506653;
    libm_sse2_exp_precise();
    X = v54 / v117;
    n16_11 = floor(X);
    n16_12 = (int)n16_11;
    v56 = (float)((float)((float)(int)n16_11 * v117) + 1.0);
    libm_sse2_log_precise();
    n16_6 = ceil((v56 * 1.442695021629333 - 5.965784072875977) * 2.0);
    v57 = (float)((float)(n16_12 + 1) * v117);
    libm_sse2_log_precise();
    X_1 = (v57 * 1.442695021629333 - 5.965784072875977) * 2.0;
    n16_7 = floor(X_1);
    n16_2 = (int)n16_6;
    n16_11 = n16_7;
    n16 = (int)n16_7;
    if ( (int)n16_6 > n16_8 )
      n16_2 = n16_8;
    if ( n16_2 < 0 )
      n16_2 = 0;
    if ( n16 >= 17 )
      n16 = 16;
    n8_1 = 0;
    HIDWORD(n16_6) = n16_2;
    n16_1 = n16;
    n8_2 = 0;
    do
    {
      v62 = malloc_0(0xE8u);
      count = count_1;
      *(_DWORD *)(v111[(_DWORD)v119] + 4 * n8_1) = v62;
      if ( count > 0 )
      {
        memset32(buf, 1148829696, count);
        n8_1 = n8_2;
      }
      n16_9 = n16_2;
      if ( SHIDWORD(n16_6) <= n16_1 )
      {
        v64 = n8_1 + 8 * HIDWORD(n16_6);
        v114 = 56 * v64;
        n56_5 = (float *)&j_6[56 * v64 + 55];
        do
        {
          count_4 = 0;
          v66 = (double)n16_2 * 0.5;
          j_5 = 0;
          j_3 = 0;
          v108 = v66;
          do
          {
            n16_11 = (double)j_5 * 0.125 + v66;
            v68 = (n16_11 - 2.0625 + 5.965784072875977) * 0.6931470036506653;
            libm_sse2_exp_precise();
            count_3 = (int)(v68 / v117);
            v70 = (n16_11 - 1.9375 + 5.965784072875977) * 0.6931470036506653;
            libm_sse2_exp_precise();
            count_2 = count_1;
            count_13 = v70 / v117 + 1.0;
            if ( count_3 < 0 )
              count_3 = 0;
            if ( count_3 > count_1 )
              count_3 = count_1;
            if ( count_3 < count_4 )
              count_4 = count_3;
            count_5 = (int)count_13;
            if ( (int)count_13 < 0 )
              count_5 = 0;
            if ( count_5 > count_1 )
              count_5 = count_1;
            if ( count_4 < count_5 )
            {
              j_4 = j_3;
              do
              {
                if ( count_4 >= count_2 )
                  break;
                v75 = *(float *)&j_6[(_DWORD)j_4 + v114];
                if ( *((float *)buf + count_4) > v75 )
                  *((float *)buf + count_4) = v75;
                ++count_4;
              }
              while ( count_4 < count_5 );
            }
            v66 = v108;
            j_5 = (int)j_3 + 1;
            j_3 = (float *)j_5;
          }
          while ( j_5 < 56 );
          n56_8 = n56_5;
          if ( count_4 < count_2 )
          {
            v77 = *n56_5;
            do
            {
              if ( *((float *)buf + count_4) > v77 )
                *((float *)buf + count_4) = v77;
              ++count_4;
            }
            while ( count_4 < count_2 );
          }
          v114 += 448;
          n16_2 = n16_9 + 1;
          n16_9 = n16_2;
          n56_5 = n56_8 + 448;
        }
        while ( n16_2 <= n16_1 );
      }
      if ( (int)v119 + 1 < 17 )
      {
        count_8 = 0;
        n56_3 = 0;
        n56_5 = 0;
        do
        {
          v108 = (double)n56_3 * 0.125 + v107;
          v80 = (v108 - 2.0625 + 5.965784072875977) * 0.6931470036506653;
          libm_sse2_exp_precise();
          count_7 = (int)(v80 / v117);
          v82 = (v108 - 1.9375 + 5.965784072875977) * 0.6931470036506653;
          libm_sse2_exp_precise();
          count_6 = count_1;
          count_14 = v82 / v117 + 1.0;
          if ( count_7 < 0 )
            count_7 = 0;
          if ( count_7 > count_1 )
            count_7 = count_1;
          count_9 = (int)count_14;
          if ( count_7 < count_8 )
            count_8 = count_7;
          if ( count_9 < 0 )
            count_9 = 0;
          if ( count_9 > count_1 )
            count_9 = count_1;
          HIDWORD(n16_11) = count_9;
          if ( count_8 < count_9 )
          {
            n56_9 = n56_5;
            do
            {
              if ( count_8 >= count_6 )
                break;
              v87 = *(float *)&j_6[(_DWORD)&n56_9[14 * n8_2 + 14 * j]];
              if ( *((float *)buf + count_8) > v87 )
                *((float *)buf + count_8) = v87;
              ++count_8;
            }
            while ( count_8 < SHIDWORD(n16_11) );
          }
          n56_3 = (int)n56_5 + 1;
          n56_5 = (float *)n56_3;
        }
        while ( n56_3 < 56 );
        if ( count_8 < count_6 )
        {
          v88 = *(float *)&j_6[56 * j + 55 + 56 * n8_2];
          do
          {
            if ( *((float *)buf + count_8) > v88 )
              *((float *)buf + count_8) = v88;
            ++count_8;
          }
          while ( count_8 < count_6 );
        }
      }
      count_10 = count_1;
      n56_4 = 0;
      HIDWORD(n16_11) = *(_DWORD *)(v111[(_DWORD)v119] + 4 * n8_2);
      n16_9 = 0;
      v91 = (_DWORD *)(HIDWORD(n16_11) + 8);
      do
      {
        v92 = ((double)n56_4 * 0.125 + v107 - 2.0 + 5.965784072875977) * 0.6931470036506653;
        libm_sse2_exp_precise();
        count_11 = (int)(v92 / v117);
        if ( count_11 >= 0 )
        {
          if ( count_11 < count_10 )
            *v91 = *((_DWORD *)buf + count_11);
          else
            *v91 = -998653952;
        }
        else
        {
          *v91 = -998653952;
        }
        n56_4 = n16_9 + 1;
        ++v91;
        n16_9 = n56_4;
      }
      while ( n56_4 < 56 );
      v94 = HIDWORD(n16_11);
      n16_3 = 0;
      v96 = (float *)(HIDWORD(n16_11) + 12);
      while ( *(v96 - 1) <= -200.0 )
      {
        if ( *v96 > -200.0 )
        {
          ++n16_3;
          break;
        }
        if ( v96[1] > -200.0 )
        {
          n16_3 += 2;
          break;
        }
        if ( v96[2] > -200.0 )
        {
          n16_3 += 3;
          break;
        }
        n16_3 += 4;
        v96 += 4;
        if ( n16_3 >= 16 )
          break;
      }
      n16_4 = (float)n16_3;
      n55 = 55;
      *(float *)HIDWORD(n16_11) = n16_4;
      v99 = (float *)(v94 + 224);
      while ( v99[1] <= -200.0 )
      {
        if ( *v99 > -200.0 )
        {
          --n55;
          break;
        }
        n55 -= 2;
        v99 -= 2;
        if ( n55 <= 17 )
          break;
      }
      n16_2 = HIDWORD(n16_6);
      n8_1 = n8_2 + 1;
      *(float *)(v94 + 4) = (float)n55;
      n8_2 = n8_1;
    }
    while ( n8_1 < 8 );
    n16_8 = (int)v119 + 1;
    v119 = (unsigned int *)((char *)v119 + 1);
  }
  return v111;
}

