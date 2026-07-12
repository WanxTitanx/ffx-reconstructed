// Function: sub_A9E060
// Address: 0xa9e060
// Size: 0x484
// Prototype: _DWORD __cdecl(int, int n16)

int __userpurge sub_A9E060@<xmm0>(double *a1@<ecx>, unsigned int a2@<edx>, int a3, int n16)
{
  int n16_1; // edi
  void *v5; // esp
  void *v6; // esp
  int v7; // edx
  double *v8; // esi
  int v9; // edi
  int v10; // eax
  int n4_5; // ecx
  int n4; // eax
  double v13; // xmm3_8
  int v14; // ecx
  float *v15; // esi
  int v16; // eax
  float *n4_4; // edi
  unsigned int v18; // eax
  double v19; // xmm0_8
  double v20; // xmm3_8
  double v21; // xmm3_8
  double v22; // xmm1_8
  float *v23; // eax
  double v24; // xmm1_8
  double v25; // xmm0_8
  int n4_1; // edx
  double v27; // xmm4_8
  double v28; // xmm3_8
  double v29; // xmm4_8
  double *v30; // eax
  double v31; // xmm2_8
  int n4_2; // ecx
  double *v33; // edx
  unsigned int v34; // edi
  double *v35; // eax
  double v36; // xmm0_8
  double *v37; // eax
  double v38; // xmm0_8
  double v39; // xmm2_8
  int v40; // eax
  int v41; // ecx
  double *v42; // edx
  double v43; // xmm0_8
  double v44; // xmm1_8
  int n4_6; // edx
  int n16_2; // eax
  double v47; // xmm1_8
  unsigned int v48; // edx
  double *v49; // ecx
  double v50; // xmm0_8
  double v51; // xmm1_8
  double v52; // xmm0_8
  double v53; // xmm1_8
  double v54; // xmm0_8
  double v55; // xmm1_8
  double v56; // xmm0_8
  double v57; // xmm0_8
  int n16_3; // ecx
  unsigned int v59; // eax
  _QWORD *v60; // edx
  int v61; // eax
  unsigned int v62; // edi
  double *v63; // edx
  float v64; // xmm0_4
  float v65; // xmm0_4
  float v66; // xmm0_4
  unsigned int v67; // eax
  float v68; // xmm0_4
  int result; // xmm0_4
  _BYTE v70[8]; // [esp+0h] [ebp-2Ch] BYREF
  double v71; // [esp+8h] [ebp-24h]
  _DWORD v72[3]; // [esp+10h] [ebp-1Ch] BYREF
  double *v73; // [esp+1Ch] [ebp-10h]
  double *v74; // [esp+20h] [ebp-Ch]
  unsigned int v75; // [esp+24h] [ebp-8h]
  int n4_3; // [esp+28h] [ebp-4h]

  n16_1 = n16;
  v75 = a2;
  v73 = a1;
  v5 = alloca(8 * n16 + 8);
  v74 = (double *)v70;
  v6 = alloca(8 * n16);
  v7 = n16 + 1;
  if ( n16 != -1 )
  {
    v8 = v73;
    v9 = a3;
    v10 = a3 - v7;
    n4_5 = (int)v73 + 4 * v7 + 8;
    do
    {
      --v7;
      n4 = v10 + 1;
      n4_3 = n4_5 - 4;
      v72[0] = n4;
      v13 = 0.0;
      v14 = v7;
      if ( v7 < v9 )
      {
        if ( n4 >= 4 )
        {
          v72[1] = v8 + 1;
          v15 = (float *)(v8 + 1);
          v16 = v9;
          n4_4 = (float *)n4_3;
          v18 = ((unsigned int)(v16 - v7 - 4) >> 2) + 1;
          v14 = v7 + 4 * v18;
          do
          {
            v19 = *n4_4;
            v20 = v13 + *(v15 - 2) * *(n4_4 - 2) + *(v15 - 1) * *(n4_4 - 1);
            n4_4 += 4;
            v21 = v20 + *v15 * v19;
            v22 = v15[1];
            v15 += 4;
            v13 = v21 + v22 * *(n4_4 - 3);
            --v18;
          }
          while ( v18 );
          v9 = a3;
          v8 = v73;
        }
        if ( v14 < v9 )
        {
          v23 = (float *)v8 + v14 - v7;
          do
          {
            v24 = *((float *)v8 + v14);
            v25 = *v23;
            ++v14;
            ++v23;
            v13 = v24 * v25 + v13;
          }
          while ( v14 < v9 );
        }
      }
      n4_5 = n4_3;
      v74[v7] = v13;
      v10 = v72[0];
    }
    while ( v7 );
    n16_1 = n16;
  }
  n4_1 = 0;
  v27 = *v74;
  v28 = *v74 * 1.0000000001;
  n4_3 = 0;
  v71 = v28;
  v29 = v27 * 0.000000001 + 1.0e-10;
  if ( n16_1 > 0 )
  {
    v30 = v74 - 2;
    v73 = v74 - 2;
    while ( 1 )
    {
      v31 = -v30[3];
      if ( v29 > v28 )
        break;
      n4_2 = 0;
      if ( n4_1 >= 4 )
      {
        v33 = v73;
        v34 = ((unsigned int)(n4_3 - 4) >> 2) + 1;
        v35 = (double *)v72;
        n4_2 = 4 * v34;
        do
        {
          v36 = v33[2] * *(v35 - 2);
          v35 += 4;
          v33 -= 4;
          v31 = v31 - v36 - v33[5] * *(v35 - 5) - v33[4] * *(v35 - 4) - v33[3] * *(v35 - 3);
          --v34;
        }
        while ( v34 );
        n4_1 = n4_3;
      }
      if ( n4_2 < n4_1 )
      {
        v37 = &v74[n4_1 - n4_2];
        do
        {
          v38 = *(double *)&v70[8 * n4_2++] * *v37--;
          v31 = v31 - v38;
        }
        while ( n4_2 < n4_1 );
      }
      v39 = v31 / v28;
      *(double *)&v70[8 * n4_1] = v39;
      v40 = n4_1 / 2;
      v41 = 0;
      if ( n4_1 / 2 > 0 )
      {
        v42 = (double *)&v70[8 * n4_3 - 8];
        do
        {
          v43 = *v42;
          v44 = *(double *)&v70[8 * v41++];
          --v42;
          *(double *)&v70[8 * v41 - 8] = v43 * v39 + v44;
          v42[1] = v44 * v39 + v42[1];
        }
        while ( v41 < v40 );
      }
      n4_6 = n4_3;
      if ( (n4_3 & 1) != 0 )
        *(double *)&v70[8 * v41] = *(double *)&v70[8 * v41] * v39 + *(double *)&v70[8 * v41];
      n16_1 = n16;
      n4_1 = n4_6 + 1;
      v30 = v73 + 1;
      n4_3 = n4_1;
      ++v73;
      v28 = v28 * (1.0 - v39 * v39);
      v71 = v28;
      if ( n4_1 >= n16 )
        goto LABEL_31;
    }
    memset(&v70[8 * n4_1], 0, 8 * (n16_1 - n4_1));
    v28 = v71;
  }
LABEL_31:
  n16_2 = 0;
  v47 = 0.99;
  if ( n16_1 >= 4 )
  {
    v48 = ((unsigned int)(n16_1 - 4) >> 2) + 1;
    v49 = (double *)v72;
    n16_2 = 4 * v48;
    do
    {
      v50 = *(v49 - 2) * v47;
      v51 = v47 * 0.99;
      v49 += 4;
      *(v49 - 6) = v50;
      v52 = *(v49 - 5) * v51;
      v53 = v51 * 0.99;
      *(v49 - 5) = v52;
      v54 = *(v49 - 4) * v53;
      v55 = v53 * 0.99;
      *(v49 - 4) = v54;
      v56 = *(v49 - 3) * v55;
      v47 = v55 * 0.99;
      *(v49 - 3) = v56;
      --v48;
    }
    while ( v48 );
  }
  for ( ; n16_2 < n16_1; *(double *)&v70[8 * n16_2 - 8] = v57 )
  {
    v57 = *(double *)&v70[8 * n16_2++] * v47;
    v47 = v47 * 0.99;
  }
  n16_3 = 0;
  if ( n16_1 > 0 )
  {
    if ( (unsigned int)n16_1 >= 2
      && (v75 > (unsigned int)&v70[8 * n16_1 - 8] || v75 - 4 + 4 * n16_1 < (unsigned int)v70) )
    {
      v59 = v75;
      HIDWORD(v71) = n16_1 - (n16_1 & 1);
      v60 = v70;
      do
      {
        n16_3 += 2;
        v59 += 8;
        *(_QWORD *)(v59 - 8) = *v60;
        v60 += 2;
      }
      while ( n16_3 < SHIDWORD(v71) );
    }
    if ( n16_3 < n16_1 )
    {
      if ( n16_1 - n16_3 >= 4 )
      {
        v61 = v75 + 4 * n16_3 + 8;
        v62 = ((unsigned int)(n16_1 - n16_3 - 4) >> 2) + 1;
        v63 = (double *)&v70[8 * n16_3 + 16];
        n16_3 += 4 * v62;
        do
        {
          v64 = *(v63 - 2);
          v63 += 4;
          *(float *)(v61 - 8) = v64;
          v65 = *(v63 - 5);
          v61 += 16;
          *(float *)(v61 - 20) = v65;
          v66 = *(v63 - 4);
          *(float *)(v61 - 16) = v66;
          *(float *)(v61 - 12) = *(v63 - 3);
          --v62;
        }
        while ( v62 );
        n16_1 = n16;
      }
      if ( n16_3 < n16_1 )
      {
        v67 = v75;
        do
        {
          v68 = *(double *)&v70[8 * n16_3++];
          *(float *)(v67 + 4 * n16_3 - 4) = v68;
        }
        while ( n16_3 < n16_1 );
      }
    }
  }
  *(float *)&result = v28;
  return result;
}

