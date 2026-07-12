// Function: sub_9C0C90
// Address: 0x9c0c90
float *__userpurge sub_9C0C90@<eax>(
        int a1@<ebp>,
        int a2,
        float *a3,
        int a4,
        int a5,
        int a6,
        float *a7,
        float *a8,
        int a9,
        float a10,
        float a11,
        float a12,
        unsigned int a13)
{
  int v13; // edi
  float v14; // ecx
  int v15; // eax
  void *v16; // eax
  float v17; // eax
  double v18; // st7
  double v19; // st7
  double v20; // st5
  double v21; // st4
  double v22; // st6
  double v23; // st2
  double v24; // st4
  double v25; // st3
  double v26; // st5
  double v27; // st7
  float *v28; // edx
  float v29; // xmm0_4
  double v30; // st7
  double v31; // st7
  double v32; // st5
  double v33; // st4
  double v34; // st6
  double v35; // st2
  double v36; // st6
  double v37; // st3
  double v38; // st7
  double v39; // st7
  float *v40; // edx
  double v41; // st7
  double v42; // st6
  float *v43; // eax
  float v44; // xmm0_4
  double v45; // st7
  double v46; // st7
  float *v47; // edx
  float *v48; // eax
  double v49; // st7
  double v50; // st6
  double v51; // st7
  double v52; // st5
  float *v53; // edx
  float *result; // eax
  double v55; // st7
  float v56; // xmm1_4
  _BYTE v57[16]; // [esp-160h] [ebp-16Ch] BYREF
  float v58[4]; // [esp-150h] [ebp-15Ch] BYREF
  _BYTE v59[16]; // [esp-140h] [ebp-14Ch] BYREF
  _DWORD v60[4]; // [esp-130h] [ebp-13Ch] BYREF
  _DWORD v61[4]; // [esp-120h] [ebp-12Ch] BYREF
  _DWORD v62[4]; // [esp-110h] [ebp-11Ch] BYREF
  _DWORD v63[4]; // [esp-100h] [ebp-10Ch] BYREF
  _BYTE v64[16]; // [esp-F0h] [ebp-FCh] BYREF
  _BYTE v65[16]; // [esp-E0h] [ebp-ECh] BYREF
  _BYTE v66[16]; // [esp-D0h] [ebp-DCh] BYREF
  _BYTE v67[16]; // [esp-C0h] [ebp-CCh] BYREF
  float v68[4]; // [esp-B0h] [ebp-BCh] BYREF
  float v69; // [esp-A0h] [ebp-ACh]
  float v70; // [esp-9Ch] [ebp-A8h]
  float v71; // [esp-98h] [ebp-A4h]
  float v72; // [esp-90h] [ebp-9Ch]
  float v73; // [esp-8Ch] [ebp-98h]
  float v74; // [esp-88h] [ebp-94h]
  float v75; // [esp-80h] [ebp-8Ch]
  float v76; // [esp-7Ch] [ebp-88h]
  float v77; // [esp-78h] [ebp-84h]
  float v78; // [esp-70h] [ebp-7Ch]
  float v79; // [esp-6Ch] [ebp-78h]
  float v80; // [esp-68h] [ebp-74h]
  float v81; // [esp-60h] [ebp-6Ch]
  float v82; // [esp-5Ch] [ebp-68h]
  float v83; // [esp-58h] [ebp-64h]
  float v84; // [esp-50h] [ebp-5Ch]
  float v85; // [esp-4Ch] [ebp-58h]
  float v86; // [esp-48h] [ebp-54h]
  int v87; // [esp-44h] [ebp-50h]
  float v88; // [esp-40h] [ebp-4Ch]
  float v89; // [esp-3Ch] [ebp-48h]
  float v90; // [esp-38h] [ebp-44h]
  int v91; // [esp-34h] [ebp-40h]
  __int128 v92; // [esp-30h] [ebp-3Ch]
  float v93; // [esp-14h] [ebp-20h]
  float v94; // [esp-10h] [ebp-1Ch]
  float v95; // [esp-Ch] [ebp-18h]
  float v96; // [esp-8h] [ebp-14h]
  float v97; // [esp-4h] [ebp-10h]
  _DWORD v98[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v98[0] = a1;
  v98[1] = retaddr;
  v13 = 0;
  if ( (*(_BYTE *)(a9 + 244) & 2) != 0 )
    v13 = a9;
  v14 = 0.0;
  if ( (*(_BYTE *)(LODWORD(a10) + 244) & 2) != 0 )
    v14 = a10;
  *(float *)(a2 + 16) = *a3;
  *(float *)(a2 + 20) = a3[1];
  *(float *)(a2 + 24) = a3[2];
  v15 = *((_DWORD *)a3 + 3);
  v93 = v14;
  *(_DWORD *)(a2 + 28) = v15;
  if ( v13 )
  {
    v16 = (void *)v13;
  }
  else
  {
    v16 = sub_9BDD30((int)v98);
    v14 = v93;
  }
  *(_DWORD *)(a2 + 128) = v16;
  if ( v14 == 0.0 )
  {
    v17 = COERCE_FLOAT(sub_9BDD30((int)v98));
    v14 = v93;
  }
  else
  {
    v17 = v14;
  }
  *(float *)(a2 + 132) = v17;
  v92 = xmmword_B700C0;
  v18 = *(float *)(a6 + 84);
  *(_DWORD *)(a2 + 96) = 0;
  *(float *)(a2 + 112) = v18;
  *(_QWORD *)(a2 + 100) = *(_QWORD *)((char *)&v92 + 4);
  *(_DWORD *)(a2 + 108) = HIDWORD(v92);
  v92 = xmmword_B700C0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 88) = *((_QWORD *)&v92 + 1);
  *(_DWORD *)(a2 + 136) = 0;
  v93 = *(float *)(a2 + 24);
  v91 = 0;
  v94 = a7[1];
  v96 = *(float *)(a2 + 20);
  v95 = a7[2];
  v19 = v94;
  v20 = v93;
  v21 = v95;
  v22 = v96;
  v88 = v94 * v93 - v95 * v96;
  v96 = *(float *)(a2 + 16);
  v95 = *a7;
  *(float *)a2 = v88;
  v23 = v21 * v96;
  v24 = v95;
  v25 = v23 - v20 * v95;
  v26 = v96;
  v89 = v25;
  *(float *)(a2 + 4) = v89;
  v90 = v22 * v24 - v19 * v26;
  *(float *)(a2 + 8) = v90;
  *(_DWORD *)(a2 + 12) = v91;
  if ( v13 )
  {
    v27 = *(float *)(v13 + 276);
    v58[3] = 0.0;
    v28 = v58;
    v72 = *(float *)(v13 + 280) * v90 + *(float *)(v13 + 272) * v88 + v27 * v89;
    v73 = *(float *)(v13 + 292) * v89 + v88 * *(float *)(v13 + 288) + *(float *)(v13 + 296) * v90;
    v74 = v88 * *(float *)(v13 + 304) + v89 * *(float *)(v13 + 308) + v90 * *(float *)(v13 + 312);
    v58[0] = v72 * *(float *)(v13 + 608);
    v58[1] = *(float *)(v13 + 612) * v73;
    v58[2] = *(float *)(v13 + 616) * v74;
  }
  else
  {
    memset(v66, 0, sizeof(v66));
    v28 = (float *)v66;
  }
  *(float *)(a2 + 48) = *v28;
  *(float *)(a2 + 52) = v28[1];
  *(float *)(a2 + 56) = v28[2];
  *(float *)(a2 + 60) = v28[3];
  v70 = -*(float *)(a2 + 20);
  v29 = -*(float *)(a2 + 16);
  v71 = -*(float *)(a2 + 24);
  v69 = v29;
  v30 = a8[1];
  v87 = 0;
  v96 = v30;
  v95 = a8[2];
  v31 = v71;
  v32 = v96;
  v33 = v70;
  v34 = v95;
  v84 = v71 * v96 - v70 * v95;
  v96 = *a8;
  *(float *)(a2 + 32) = v84;
  v35 = v34 * v69;
  v36 = v96;
  v37 = v35 - v31 * v96;
  v38 = v69;
  v85 = v37;
  *(float *)(a2 + 36) = v85;
  v86 = v36 * v33 - v38 * v32;
  *(float *)(a2 + 40) = v86;
  *(_DWORD *)(a2 + 44) = v87;
  if ( v14 == 0.0 )
  {
    memset(v64, 0, sizeof(v64));
    v40 = (float *)v64;
  }
  else
  {
    v39 = *(float *)(LODWORD(v14) + 276);
    v68[3] = 0.0;
    v40 = v68;
    v81 = *(float *)(LODWORD(v14) + 280) * v86 + v39 * v85 + v84 * *(float *)(LODWORD(v14) + 272);
    v82 = *(float *)(LODWORD(v14) + 292) * v85
        + v84 * *(float *)(LODWORD(v14) + 288)
        + *(float *)(LODWORD(v14) + 296) * v86;
    v83 = v86 * *(float *)(LODWORD(v14) + 312)
        + v85 * *(float *)(LODWORD(v14) + 308)
        + v84 * *(float *)(LODWORD(v14) + 304);
    v68[0] = v81 * *(float *)(LODWORD(v14) + 608);
    v68[1] = *(float *)(LODWORD(v14) + 612) * v82;
    v68[2] = *(float *)(LODWORD(v14) + 616) * v83;
  }
  *(float *)(a2 + 64) = *v40;
  *(float *)(a2 + 68) = v40[1];
  *(float *)(a2 + 72) = v40[2];
  *(float *)(a2 + 76) = v40[3];
  v94 = 0.0;
  v93 = 0.0;
  if ( v13 )
  {
    v95 = *(float *)(a2 + 52);
    v96 = a7[2];
    v97 = *(float *)(a2 + 56);
    v94 = a7[1];
    v41 = v96;
    v42 = v97;
    v78 = v96 * v95 - v94 * v97;
    v43 = a3;
    v97 = *a7;
    v96 = *(float *)(a2 + 48);
    v79 = v42 * v97 - v41 * v96;
    v80 = v96 * v94 - v97 * v95;
    v97 = v43[1] * v79 + v78 * *v43 + a3[2] * v80;
    v94 = v97 + *(float *)(v13 + 352);
  }
  else
  {
    v43 = a3;
  }
  if ( v14 != 0.0 )
  {
    v44 = *(float *)(a2 + 64);
    v76 = -*(float *)(a2 + 68);
    v45 = *(float *)(a2 + 72);
    v75 = -v44;
    v77 = -v45;
    v97 = a8[2];
    v96 = a8[1];
    v46 = v97;
    *(float *)&v92 = v97 * v76 - v96 * v77;
    v97 = *a8;
    *((float *)&v92 + 1) = v77 * v97 - v46 * (float)-v44;
    *((float *)&v92 + 2) = (float)-v44 * v96 - v97 * v76;
    v97 = v43[1] * *((float *)&v92 + 1) + *(float *)&v92 * *v43 + v43[2] * *((float *)&v92 + 2);
    v93 = v97 + *(float *)(LODWORD(v14) + 352);
  }
  v94 = a11 / (v93 + v94);
  *(float *)(a2 + 116) = v94;
  if ( v13 )
  {
    v60[0] = *(_DWORD *)(v13 + 320);
    v60[1] = *(_DWORD *)(v13 + 324);
    v60[2] = *(_DWORD *)(v13 + 328);
    v60[3] = *(_DWORD *)(v13 + 332);
    v62[0] = *(_DWORD *)(v13 + 336);
    v62[1] = *(_DWORD *)(v13 + 340);
    v62[2] = *(_DWORD *)(v13 + 344);
    v62[3] = *(_DWORD *)(v13 + 348);
    v47 = (float *)v60;
    v48 = (float *)v62;
  }
  else
  {
    memset(v67, 0, sizeof(v67));
    v47 = (float *)v67;
    memset(v65, 0, sizeof(v65));
    v48 = (float *)v65;
  }
  v49 = v48[1] * *(float *)(a2 + 4);
  v96 = *(float *)(a2 + 20);
  v50 = *(float *)a2 * *v48;
  v95 = *(float *)(a2 + 16);
  v93 = *(float *)(a2 + 24);
  v97 = v49 + v50 + v48[2] * *(float *)(a2 + 8);
  v51 = v97;
  v52 = v96;
  v97 = v47[2] * v93 + *v47 * v95 + v47[1] * v96;
  v96 = v51 + v97;
  if ( v14 == 0.0 )
  {
    memset(v59, 0, sizeof(v59));
    v53 = (float *)v59;
    memset(v57, 0, sizeof(v57));
    result = (float *)v57;
  }
  else
  {
    v63[0] = *(_DWORD *)(LODWORD(v14) + 320);
    v63[1] = *(_DWORD *)(LODWORD(v14) + 324);
    v63[2] = *(_DWORD *)(LODWORD(v14) + 328);
    v63[3] = *(_DWORD *)(LODWORD(v14) + 332);
    v61[0] = *(_DWORD *)(LODWORD(v14) + 336);
    v61[1] = *(_DWORD *)(LODWORD(v14) + 340);
    v61[2] = *(_DWORD *)(LODWORD(v14) + 344);
    v61[3] = *(_DWORD *)(LODWORD(v14) + 348);
    v53 = (float *)v63;
    result = (float *)v61;
  }
  v97 = *(float *)(a2 + 36) * result[1] + *result * *(float *)(a2 + 32) + *(float *)(a2 + 40) * result[2];
  v55 = v97;
  v97 = v93 * v53[2] + v95 * *v53 + v52 * v53[1];
  v97 = v55 - v97;
  v97 = v97 + v96;
  v97 = a12 - v97;
  v56 = _mm_shuffle_ps((__m128)LODWORD(v97), (__m128)LODWORD(v97), 0).m128_f32[0]
      * _mm_shuffle_ps((__m128)LODWORD(v94), (__m128)LODWORD(v94), 0).m128_f32[0];
  *(_QWORD *)(a2 + 144) = a13;
  *(float *)(a2 + 140) = v56;
  *(_DWORD *)(a2 + 152) = 1343554297;
  return result;
}
