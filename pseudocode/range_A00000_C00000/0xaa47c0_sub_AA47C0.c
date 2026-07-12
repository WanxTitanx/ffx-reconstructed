// Function: sub_AA47C0
// Address: 0xaa47c0
// Size: 0x35d
// Prototype: 

int __fastcall sub_AA47C0(int a1, int n2, float *a3)
{
  int n2_1; // esi
  void *v5; // esp
  int n2_4; // ecx
  float *v7; // eax
  float *v8; // edx
  float *v9; // edx
  __m128d *v10; // eax
  int v11; // edx
  unsigned int v12; // ebx
  double *v13; // eax
  double v14; // xmm0_8
  double v15; // xmm0_8
  int n40; // ecx
  int n2_5; // ebx
  double v18; // xmm6_8
  int v19; // ecx
  double v20; // xmm4_8
  double v21; // xmm5_8
  double v22; // xmm1_8
  unsigned int v23; // edx
  float *v24; // esi
  double v25; // xmm3_8
  double v26; // xmm2_8
  double v27; // xmm0_8
  double v28; // xmm3_8
  double v29; // xmm2_8
  double v30; // xmm3_8
  double v31; // xmm1_8
  int n2_2; // ecx
  float *v33; // edi
  float *v34; // eax
  unsigned __int64 *v35; // edx
  unsigned __int64 *v36; // eax
  unsigned int v37; // edi
  int v38; // eax
  double *v39; // edx
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  _BYTE v45[12]; // [esp+0h] [ebp-1Ch] BYREF
  int n2_3; // [esp+Ch] [ebp-10h]
  int n2_6; // [esp+10h] [ebp-Ch] BYREF
  int n40_1; // [esp+14h] [ebp-8h]

  n2_1 = n2;
  n2_3 = n2;
  n40_1 = 0;
  v5 = alloca(8 * n2);
  n2_4 = 0;
  if ( n2 > 0 )
  {
    if ( (unsigned int)n2 >= 2 )
    {
      v7 = &a3[n2 - 1];
      v8 = (float *)&v45[8 * n2 - 8];
      if ( v45 > (_BYTE *)v7 || v8 < a3 )
      {
        n2_6 = n2_1 - n2_1 % 2;
        v9 = a3;
        v10 = (__m128d *)v45;
        do
        {
          n2_4 += 2;
          *v10++ = _mm_cvtps_pd((__m128)*(unsigned __int64 *)v9);
          v9 += 2;
        }
        while ( n2_4 < n2_6 );
      }
    }
    if ( n2_4 < n2_1 )
    {
      if ( n2_1 - n2_4 >= 4 )
      {
        v11 = (int)&a3[n2_4 + 2];
        v12 = ((unsigned int)(n2_1 - n2_4 - 4) >> 2) + 1;
        v13 = (double *)(&n2_6 + 2 * n2_4);
        n2_4 += 4 * v12;
        do
        {
          v14 = *(float *)(v11 - 8);
          v11 += 16;
          *(v13 - 2) = v14;
          v13 += 4;
          *(v13 - 5) = *(float *)(v11 - 20);
          *(v13 - 4) = *(float *)(v11 - 16);
          *(v13 - 3) = *(float *)(v11 - 12);
          --v12;
        }
        while ( v12 );
      }
      for ( ; n2_4 < n2_1; *(double *)&v45[8 * n2_4 - 8] = v15 )
        v15 = a3[n2_4++];
    }
  }
  n40 = 0;
  do
  {
    n2_5 = 0;
    v18 = 0.0;
    if ( n2_1 > 0 )
    {
      v19 = n2_1 - 1;
      do
      {
        v20 = *(double *)&v45[8 * n2_5];
        v21 = 0.0;
        v22 = *(float *)(a1 + 4 * n2_1);
        if ( v19 >= 0 )
        {
          if ( v19 + 1 >= 4 )
          {
            v23 = (unsigned int)(v19 + 1) >> 2;
            v24 = (float *)(a1 - 8 + 4 * v19);
            v19 -= 4 * v23;
            do
            {
              v25 = v24[1];
              v26 = v24[2] + v22 * v20;
              v27 = *v24;
              v24 -= 4;
              v28 = v25 + v26 * v20;
              v29 = v20 * (v20 * (v20 * v21 + v22) + v26) + v28;
              v30 = v28 * v20 + v27;
              v21 = v20 * v29 + v30;
              v22 = v24[3] + v30 * v20;
              --v23;
            }
            while ( v23 );
            n2_1 = n2_3;
          }
          for ( ; v19 >= 0; v22 = v22 * v20 + *(float *)(a1 + 4 * v19 + 4) )
          {
            --v19;
            v21 = v21 * v20 + v22;
          }
        }
        v31 = v22 / v21;
        ++n2_5;
        v19 = n2_1 - 1;
        *(double *)&v45[8 * n2_5 - 8] = v20 - v31;
        v18 = v18 + v31 * v31;
      }
      while ( n2_5 < n2_1 );
      n40 = n40_1;
    }
    if ( n40 > 40 )
      return -1;
    n40_1 = ++n40;
  }
  while ( v18 > 9.999999999999999e-21 );
  n2_2 = 0;
  if ( n2_1 > 0 )
  {
    v33 = a3;
    if ( (unsigned int)n2_1 >= 2 && (a3 > (float *)&v45[8 * n2_1 - 8] || &a3[n2_1 - 1] < (float *)v45) )
    {
      v34 = a3;
      v35 = (unsigned __int64 *)v45;
      do
      {
        n2_2 += 2;
        v34 += 2;
        *((_QWORD *)v34 - 1) = *v35;
        v35 += 2;
      }
      while ( n2_2 < n2_1 - (n2_1 & 1) );
      v33 = a3;
    }
    if ( n2_2 < n2_1 )
    {
      if ( n2_1 - n2_2 >= 4 )
      {
        v36 = (unsigned __int64 *)(v33 + 2);
        v37 = ((unsigned int)(n2_1 - n2_2 - 4) >> 2) + 1;
        v38 = (int)v36 + 4 * n2_2;
        v39 = (double *)&v45[8 * n2_2 + 16];
        n2_2 += 4 * v37;
        do
        {
          v40 = *(v39 - 2);
          v39 += 4;
          *(float *)(v38 - 8) = v40;
          v41 = *(v39 - 5);
          v38 += 16;
          *(float *)(v38 - 20) = v41;
          v42 = *(v39 - 4);
          *(float *)(v38 - 16) = v42;
          *(float *)(v38 - 12) = *(v39 - 3);
          --v37;
        }
        while ( v37 );
      }
      for ( ; n2_2 < n2_1; a3[n2_2 - 1] = v43 )
        v43 = *(double *)&v45[8 * n2_2++];
    }
  }
  return 0;
}

