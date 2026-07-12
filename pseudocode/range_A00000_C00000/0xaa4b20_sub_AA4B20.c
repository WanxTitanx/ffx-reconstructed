// Function: sub_AA4B20
// Address: 0xaa4b20
// Size: 0x3e9
// Prototype: 

int __usercall sub_AA4B20@<eax>(
        int n4_2@<edx>,
        unsigned __int64 *a2@<ecx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>,
        int a6)
{
  int n4; // esi
  void *v7; // esp
  _DWORD *v8; // edi
  int n4_3; // edx
  bool v10; // cc
  unsigned __int64 *v11; // ecx
  __m128d *v12; // eax
  int v13; // ecx
  unsigned int v14; // edi
  double *v15; // eax
  double v16; // xmm0_8
  float *v17; // ecx
  double v18; // xmm0_8
  int v19; // edx
  double v20; // xmm6_8
  double n4_4; // xmm4_8
  double v22; // xmm3_8
  double v23; // xmm0_8
  double v24; // xmm1_8
  double v25; // xmm2_8
  int n4_6; // ecx
  double *v27; // edi
  unsigned int v28; // edx
  double v29; // xmm2_8
  double v30; // xmm1_8
  double v31; // xmm2_8
  double v32; // xmm0_8
  double v33; // xmm1_8
  double v34; // xmm2_8
  double v35; // xmm0_8
  double v36; // xmm1_8
  double v37; // xmm0_8
  double *v38; // eax
  double v39; // xmm4_8
  double v40; // xmm1_8
  double v41; // xmm0_8
  float *n4_8; // ecx
  int n4_1; // edx
  double *v44; // ecx
  unsigned int v45; // edi
  double v46; // xmm0_8
  double v47; // xmm0_8
  double v48; // xmm0_8
  double v49; // xmm0_8
  _DWORD *v50; // edi
  int v51; // eax
  double v52; // xmm0_8
  _DWORD v54[2]; // [esp-40h] [ebp-4Ch] BYREF
  double n4_5; // [esp-38h] [ebp-44h]
  double v56; // [esp-30h] [ebp-3Ch] BYREF
  double v57; // [esp-28h] [ebp-34h]
  double v58; // [esp-20h] [ebp-2Ch]
  double v59; // [esp-18h] [ebp-24h]
  float *n4_7; // [esp-Ch] [ebp-18h]
  unsigned __int64 *v61; // [esp-8h] [ebp-14h]
  _DWORD *v62; // [esp-4h] [ebp-10h]
  int v63; // [esp+0h] [ebp-Ch]
  void *v64; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v63 = a3;
  v64 = retaddr;
  v54[1] = a5;
  n4 = n4_2;
  v54[0] = a4;
  v61 = a2;
  v7 = alloca(8 * n4_2 + 8);
  v8 = v54;
  n4_3 = 0;
  v62 = v54;
  v10 = n4 <= 0;
  if ( n4 >= 0 )
  {
    v11 = v61;
    if ( (unsigned int)(n4 + 1) >= 2 && (v54 > (_DWORD *)v61 + n4 || &v54[2 * n4] < (_DWORD *)v61) )
    {
      n4_7 = (float *)(n4 - (n4 + 1) % 2);
      v12 = (__m128d *)v54;
      do
      {
        n4_3 += 2;
        *v12++ = _mm_cvtps_pd((__m128)*v11++);
      }
      while ( n4_3 <= (int)n4_7 );
      v11 = v61;
    }
    if ( n4_3 <= n4 )
    {
      if ( n4 - n4_3 + 1 >= 4 )
      {
        v13 = (int)v11 + 4 * n4_3 + 8;
        v14 = ((unsigned int)(n4 - n4_3 - 3) >> 2) + 1;
        v15 = &v56 + n4_3;
        n4_3 += 4 * v14;
        do
        {
          v16 = *(float *)(v13 - 8);
          v13 += 16;
          *(v15 - 2) = v16;
          v15 += 4;
          *(v15 - 5) = *(float *)(v13 - 20);
          *(v15 - 4) = *(float *)(v13 - 16);
          *(v15 - 3) = *(float *)(v13 - 12);
          --v14;
        }
        while ( v14 );
        v8 = v54;
      }
      if ( n4_3 <= n4 )
      {
        v17 = (float *)v61;
        do
        {
          v18 = v17[n4_3++];
          *(double *)&v54[2 * n4_3 - 2] = v18;
        }
        while ( n4_3 <= n4 );
      }
    }
    v10 = n4 <= 0;
  }
  if ( !v10 )
  {
    v19 = 8 * n4 - 16;
    v61 = (unsigned __int64 *)v19;
    n4_7 = (float *)(a6 + 4 * n4 - 4);
    do
    {
      v20 = (double)(n4 - 1);
      n4_4 = (double)n4;
      v22 = 0.0;
      v58 = 0.0;
      v56 = v20;
      n4_5 = (double)n4;
      do
      {
        v23 = *(double *)((char *)v8 + v19 + 16);
        v24 = 0.0;
        v59 = 0.0;
        v25 = 0.0;
        n4_6 = n4;
        if ( n4 >= 4 )
        {
          v27 = (double *)((char *)v8 + v19);
          v28 = ((unsigned int)(n4 - 4) >> 2) + 1;
          n4_6 = n4 - 4 * v28;
          do
          {
            v27 -= 4;
            v29 = v25 * v22 + v24;
            v30 = v24 * v22 + v23;
            v31 = v29 * v22 + v30;
            v32 = v23 * v22 + v27[5];
            v33 = v30 * v22 + v32;
            v34 = v31 * v22 + v33;
            v35 = v32 * v22 + v27[4];
            v36 = v33 * v22 + v35;
            v25 = v34 * v22 + v36;
            v37 = v35 * v22 + v27[3];
            v24 = v36 * v22 + v37;
            v23 = v37 * v22 + v27[2];
            --v28;
          }
          while ( v28 );
          v8 = v62;
          v59 = v24;
        }
        if ( n4_6 > 0 )
        {
          v38 = (double *)&v8[2 * n4_6 - 2];
          do
          {
            --n4_6;
            --v38;
            v25 = v25 * v22 + v24;
            v24 = v24 * v22 + v23;
            v23 = v23 * v22 + v38[1];
          }
          while ( n4_6 > 0 );
          v59 = v24;
        }
        v57 = n4_4 * v23;
        v39 = (v20 * v24 * v24 - n4_4 * v23 * v25) * v20;
        if ( v39 < 0.0 )
          return -1;
        if ( v24 <= 0.0 )
        {
          libm_sse2_sqrt_precise();
          v40 = v59 - v39;
          if ( v59 - v39 > -0.000001 )
            v40 = -0.000001;
        }
        else
        {
          libm_sse2_sqrt_precise();
          v40 = v39 + v59;
          if ( v39 + v59 < 0.000001 )
            v40 = 0.000001;
        }
        v41 = v57 / v40;
        v22 = v58 - v57 / v40;
        v58 = v22;
        if ( v57 / v40 < 0.0 )
          v41 = v41 * -1.0;
        v20 = v56;
        n4_4 = n4_5;
        v19 = (int)v61;
      }
      while ( fabs(v41 / v22) >= 9.999999999999999e-12 );
      n4_8 = n4_7;
      n4_1 = n4;
      *n4_7 = v22;
      if ( n4 >= 4 )
      {
        v44 = (double *)((char *)v61 + (_DWORD)v8);
        v45 = ((unsigned int)(n4 - 4) >> 2) + 1;
        n4_1 = n4 - 4 * v45;
        do
        {
          v46 = v44[2];
          v44 -= 4;
          v47 = v46 * v22 + v44[5];
          v44[5] = v47;
          v48 = v47 * v22 + v44[4];
          v44[4] = v48;
          v49 = v48 * v22 + v44[3];
          v44[3] = v49;
          v44[2] = v49 * v22 + v44[2];
          --v45;
        }
        while ( v45 );
        n4_8 = n4_7;
      }
      v50 = v62;
      if ( n4_1 > 0 )
      {
        v51 = (int)&v62[2 * n4_1 - 2];
        do
        {
          v52 = *(double *)(v51 + 8);
          --n4_1;
          v51 -= 8;
          *(double *)(v51 + 8) = v52 * v22 + *(double *)(v51 + 8);
        }
        while ( n4_1 > 0 );
      }
      v8 = v50 + 2;
      --n4;
      v19 = (int)(v61 - 1);
      v62 = v8;
      n4_7 = n4_8 - 1;
      --v61;
    }
    while ( n4 > 0 );
  }
  return 0;
}

