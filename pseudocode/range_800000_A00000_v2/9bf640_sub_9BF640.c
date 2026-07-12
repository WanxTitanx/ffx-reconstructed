// Function: sub_9BF640
// Address: 0x9bf640
__int32 __userpurge sub_9BF640@<eax>(int a1@<ecx>, char a2@<efl>, int a3, float *a4, float *a5, int a6, int a7)
{
  int v7; // eax
  int v9; // edx
  int v10; // ecx
  __m128 v11; // xmm0
  __int32 result; // eax
  double v13; // st7
  bool v14; // cf
  bool v15; // zf
  char v16; // sf
  char v17; // of
  char v18; // pf
  double v19; // st6
  int v20; // ecx
  __m128 v21; // xmm0
  double v22; // st7
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  int v26; // edx
  float v27; // [esp-160h] [ebp-16Ch]
  float v28; // [esp-15Ch] [ebp-168h]
  float v29; // [esp-158h] [ebp-164h]
  float v30; // [esp-150h] [ebp-15Ch]
  float v31; // [esp-14Ch] [ebp-158h]
  float v32; // [esp-148h] [ebp-154h]
  float v33; // [esp-140h] [ebp-14Ch]
  float v34; // [esp-13Ch] [ebp-148h]
  float v35; // [esp-138h] [ebp-144h]
  float v36; // [esp-130h] [ebp-13Ch]
  float v37; // [esp-12Ch] [ebp-138h]
  float v38; // [esp-128h] [ebp-134h]
  float v39; // [esp-120h] [ebp-12Ch]
  float v40; // [esp-11Ch] [ebp-128h]
  float v41; // [esp-118h] [ebp-124h]
  float v42; // [esp-110h] [ebp-11Ch]
  float v43; // [esp-10Ch] [ebp-118h]
  float v44; // [esp-108h] [ebp-114h]
  float v45; // [esp-100h] [ebp-10Ch]
  float v46; // [esp-FCh] [ebp-108h]
  float v47; // [esp-F8h] [ebp-104h]
  float v48; // [esp-F0h] [ebp-FCh]
  float v49; // [esp-ECh] [ebp-F8h]
  float v50; // [esp-E8h] [ebp-F4h]
  float v51; // [esp-E0h] [ebp-ECh]
  float v52; // [esp-DCh] [ebp-E8h]
  float v53; // [esp-D8h] [ebp-E4h]
  float v54; // [esp-D0h] [ebp-DCh]
  float v55; // [esp-CCh] [ebp-D8h]
  float v56; // [esp-C8h] [ebp-D4h]
  float v57; // [esp-C0h] [ebp-CCh]
  float v58; // [esp-BCh] [ebp-C8h]
  float v59; // [esp-B8h] [ebp-C4h]
  float v60; // [esp-B0h] [ebp-BCh]
  float v61; // [esp-ACh] [ebp-B8h]
  float v62; // [esp-A8h] [ebp-B4h]
  float v63; // [esp-A0h] [ebp-ACh]
  float v64; // [esp-9Ch] [ebp-A8h]
  float v65; // [esp-98h] [ebp-A4h]
  float v66; // [esp-90h] [ebp-9Ch]
  float v67; // [esp-8Ch] [ebp-98h]
  float v68; // [esp-88h] [ebp-94h]
  float v69; // [esp-80h] [ebp-8Ch]
  float v70; // [esp-7Ch] [ebp-88h]
  float v71; // [esp-78h] [ebp-84h]
  float v72; // [esp-70h] [ebp-7Ch]
  float v73; // [esp-6Ch] [ebp-78h]
  float v74; // [esp-68h] [ebp-74h]
  float v75; // [esp-60h] [ebp-6Ch]
  float v76; // [esp-5Ch] [ebp-68h]
  float v77; // [esp-58h] [ebp-64h]
  float v78; // [esp-50h] [ebp-5Ch]
  float v79; // [esp-4Ch] [ebp-58h]
  float v80; // [esp-48h] [ebp-54h]
  float v81; // [esp-40h] [ebp-4Ch]
  float v82; // [esp-3Ch] [ebp-48h]
  float v83; // [esp-38h] [ebp-44h]
  float v84; // [esp-30h] [ebp-3Ch]
  float v85; // [esp-2Ch] [ebp-38h]
  float v86; // [esp-28h] [ebp-34h]
  unsigned int v87; // [esp-8h] [ebp-14h]
  float v88; // [esp-8h] [ebp-14h]
  float v89; // [esp-8h] [ebp-14h]
  float v90; // [esp-8h] [ebp-14h]
  float v91; // [esp-8h] [ebp-14h]
  unsigned int v93; // [esp-4h] [ebp-10h]
  float v94; // [esp-4h] [ebp-10h]
  float v95; // [esp-4h] [ebp-10h]
  float v96; // [esp-4h] [ebp-10h]
  float v97; // [esp-4h] [ebp-10h]

  v7 = *(_DWORD *)(a3 + 124);
  v9 = *(_DWORD *)(a7 + 60);
  if ( (v9 & 8) != 0 )
  {
    v10 = *(_DWORD *)(a1 + 56) + 192 * v7;
    if ( (v9 & 4) != 0 )
    {
      *(float *)&v87 = *(float *)(a6 + 120) * *(float *)(a7 + 56);
      v11 = _mm_shuffle_ps((__m128)v87, (__m128)v87, 0);
      *(__m128 *)(v10 + 96) = v11;
      result = v11.m128_i32[3];
      if ( a4 )
      {
        v88 = a4[88];
        v13 = v88;
        v14 = v88 < 0.0;
        v18 = 0;
        v15 = v88 == 0.0;
        v16 = 0;
        v17 = 0;
        v42 = v88 * *(float *)(v10 + 16);
        v19 = *(float *)(v10 + 20) * v88;
        v89 = *(float *)(v10 + 96);
        BYTE1(result) = a2;
        if ( !v15 )
        {
          v27 = a4[92] * v42;
          v78 = v27 * v89;
          v43 = v19;
          v28 = a4[93] * v43;
          v79 = v28 * v89;
          v44 = v13 * *(float *)(v10 + 24);
          v29 = a4[94] * v44;
          v80 = v29 * v89;
          a4[144] = v78 + a4[144];
          a4[145] = v79 + a4[145];
          a4[146] = v80 + a4[146];
          v30 = a4[152] * v89;
          v31 = a4[153] * v89;
          v32 = v89 * a4[154];
          v72 = v30 * *(float *)(v10 + 48);
          v73 = *(float *)(v10 + 52) * v31;
          v74 = *(float *)(v10 + 56) * v32;
          a4[148] = v72 + a4[148];
          a4[149] = v73 + a4[149];
          a4[150] = v74 + a4[150];
        }
      }
      if ( a5 )
      {
        v90 = a5[88];
        v84 = -*(float *)(v10 + 64);
        v14 = v90 < 0.0;
        v18 = 0;
        v15 = v90 == 0.0;
        v16 = 0;
        v17 = 0;
        v48 = v90 * *(float *)(v10 + 16);
        v49 = *(float *)(v10 + 20) * v90;
        v85 = -*(float *)(v10 + 68);
        v86 = -*(float *)(v10 + 72);
        v50 = v90 * *(float *)(v10 + 24);
        BYTE1(result) = a2;
        v91 = -*(float *)(v10 + 96);
        if ( !v15 )
        {
          v66 = v48 * a5[92];
          v36 = v66 * v91;
          v67 = a5[93] * v49;
          v37 = v67 * v91;
          v68 = a5[94] * v50;
          v38 = v68 * v91;
          a5[144] = v36 + a5[144];
          a5[145] = v37 + a5[145];
          a5[146] = v38 + a5[146];
          v60 = a5[152] * v91;
          v61 = a5[153] * v91;
          v62 = v91 * a5[154];
          v54 = v60 * v84;
          v55 = v61 * v85;
          v56 = v62 * v86;
          a5[148] = v54 + a5[148];
          a5[149] = v55 + a5[149];
          a5[150] = v56 + a5[150];
        }
      }
    }
    else
    {
      *(_QWORD *)(v10 + 96) = 0;
      *(_DWORD *)(v10 + 104) = 0;
      result = 0;
      *(_DWORD *)(v10 + 108) = 0;
    }
    if ( (*(_BYTE *)(a7 + 60) & 0x10) != 0 )
    {
      v20 = *(_DWORD *)(a1 + 56) + 192 * (*(_DWORD *)(a3 + 124) + 1);
      if ( (*(_BYTE *)(a7 + 60) & 4) != 0 )
      {
        *(float *)&v93 = *(float *)(a6 + 124) * *(float *)(a7 + 56);
        v21 = _mm_shuffle_ps((__m128)v93, (__m128)v93, 0);
        *(__m128 *)(v20 + 96) = v21;
        result = v21.m128_i32[3];
        if ( a4 )
        {
          v94 = a4[88];
          v22 = v94;
          v14 = v94 < 0.0;
          v18 = 0;
          v15 = v94 == 0.0;
          v16 = 0;
          v17 = 0;
          v81 = v94 * *(float *)(v20 + 16);
          v95 = *(float *)(v20 + 96);
          BYTE1(result) = a2;
          if ( !v15 )
          {
            v75 = v81 * v95;
            v82 = *(float *)(v20 + 20) * v22;
            v76 = v82 * v95;
            v83 = v22 * *(float *)(v20 + 24);
            v77 = v83 * v95;
            a4[144] = v75 + a4[144];
            a4[145] = v76 + a4[145];
            a4[146] = v77 + a4[146];
            v69 = a4[152] * v95;
            v70 = a4[153] * v95;
            v71 = v95 * a4[154];
            v63 = v69 * *(float *)(v20 + 48);
            v64 = *(float *)(v20 + 52) * v70;
            v65 = *(float *)(v20 + 56) * v71;
            a4[148] = v63 + a4[148];
            a4[149] = v64 + a4[149];
            a4[150] = v65 + a4[150];
          }
        }
        if ( a5 )
        {
          v96 = a5[88];
          v39 = -*(float *)(v20 + 64);
          v14 = v96 < 0.0;
          v18 = 0;
          v15 = v96 == 0.0;
          v16 = 0;
          v17 = 0;
          v57 = v96 * *(float *)(v20 + 16);
          v40 = -*(float *)(v20 + 68);
          v58 = *(float *)(v20 + 20) * v96;
          v41 = -*(float *)(v20 + 72);
          BYTE1(result) = a2;
          v59 = v96 * *(float *)(v20 + 24);
          v97 = -*(float *)(v20 + 96);
          if ( !v15 )
          {
            v51 = v57 * v97;
            v52 = v58 * v97;
            v53 = v59 * v97;
            a5[144] = v51 + a5[144];
            a5[145] = v52 + a5[145];
            a5[146] = v53 + a5[146];
            v45 = a5[152] * v97;
            v46 = a5[153] * v97;
            v47 = v97 * a5[154];
            v33 = v45 * v39;
            v34 = v46 * v40;
            v35 = v47 * v41;
            a5[148] = v33 + a5[148];
            a5[149] = v34 + a5[149];
            a5[150] = v35 + a5[150];
          }
        }
      }
      else
      {
        *(_QWORD *)(v20 + 96) = 0;
        *(_DWORD *)(v20 + 104) = 0;
        *(_DWORD *)(v20 + 108) = 0;
        return 0;
      }
    }
  }
  else
  {
    v23 = *(_DWORD *)(a1 + 56);
    v24 = 192 * v7;
    *(_QWORD *)(v24 + v23 + 96) = 0;
    *(_DWORD *)(v24 + v23 + 104) = 0;
    result = 0;
    *(_DWORD *)(v24 + v23 + 108) = 0;
    if ( (*(_BYTE *)(a7 + 60) & 0x10) != 0 )
    {
      v25 = *(_DWORD *)(a1 + 56);
      v26 = 192 * *(_DWORD *)(a3 + 124);
      *(_QWORD *)(v26 + v25 + 288) = 0;
      *(_DWORD *)(v26 + v25 + 296) = 0;
      *(_DWORD *)(v26 + v25 + 300) = 0;
      return 0;
    }
  }
  return result;
}
