// Function: sub_9BF0A0
// Address: 0x9bf0a0
__int64 __userpurge sub_9BF0A0@<edx:eax>(char a1@<efl>, float *a2, float *a3, float *a4)
{
  float v4; // xmm0_4
  bool v5; // cf
  bool v6; // zf
  char v7; // sf
  char v8; // of
  char v9; // pf
  __int64 result; // rax
  double v12; // st7
  double v13; // st5
  double v14; // st3
  double v15; // st7
  double v16; // st4
  double v17; // st6
  double v18; // st7
  double v19; // st6
  __m128 v20; // xmm0
  double v21; // st7
  float v22; // xmm0_4
  float v23; // [esp-40h] [ebp-4Ch]
  float v24; // [esp-40h] [ebp-4Ch]
  float v25; // [esp-40h] [ebp-4Ch]
  float v26; // [esp-40h] [ebp-4Ch]
  float v27; // [esp-40h] [ebp-4Ch]
  float v28; // [esp-3Ch] [ebp-48h]
  float v29; // [esp-3Ch] [ebp-48h]
  float v30; // [esp-3Ch] [ebp-48h]
  float v31; // [esp-3Ch] [ebp-48h]
  float v32; // [esp-3Ch] [ebp-48h]
  float v33; // [esp-38h] [ebp-44h]
  float v34; // [esp-38h] [ebp-44h]
  float v35; // [esp-38h] [ebp-44h]
  float v36; // [esp-38h] [ebp-44h]
  float v37; // [esp-38h] [ebp-44h]
  float v38; // [esp-30h] [ebp-3Ch]
  float v39; // [esp-30h] [ebp-3Ch]
  float v40; // [esp-30h] [ebp-3Ch]
  float v41; // [esp-30h] [ebp-3Ch]
  float v42; // [esp-2Ch] [ebp-38h]
  float v43; // [esp-2Ch] [ebp-38h]
  float v44; // [esp-2Ch] [ebp-38h]
  float v45; // [esp-2Ch] [ebp-38h]
  float v46; // [esp-28h] [ebp-34h]
  float v47; // [esp-28h] [ebp-34h]
  float v48; // [esp-28h] [ebp-34h]
  float v49; // [esp-28h] [ebp-34h]
  float v50; // [esp-18h] [ebp-24h]
  float v51; // [esp-18h] [ebp-24h]
  float v52; // [esp-18h] [ebp-24h]
  float v53; // [esp-18h] [ebp-24h]
  float v54; // [esp-14h] [ebp-20h]
  float v55; // [esp-14h] [ebp-20h]
  float v56; // [esp-Ch] [ebp-18h]
  float v57; // [esp-Ch] [ebp-18h]
  float v58; // [esp-8h] [ebp-14h]
  float v59; // [esp-8h] [ebp-14h]
  float v60; // [esp-4h] [ebp-10h]
  float v61; // [esp-4h] [ebp-10h]
  float v62; // [esp-4h] [ebp-10h]
  float v63; // [esp-4h] [ebp-10h]

  v4 = a4[39];
  v5 = v4 < 0.0;
  v9 = 0;
  v6 = v4 == 0.0;
  v7 = 0;
  v8 = 0;
  BYTE1(result) = a1;
  if ( v4 != 0.0 )
  {
    ++unk_193F664;
    v58 = a4[20];
    v60 = a4[5];
    HIDWORD(result) = a3;
    v56 = a4[39] - a4[36] * v58;
    v12 = v56;
    v57 = a4[1] * a2[165] + a2[164] * *a4 + a4[2] * a2[166];
    v13 = a4[6];
    v54 = v60 * a2[161] + a4[4] * a2[160] + v13 * a2[162];
    v55 = v57 + v54;
    v14 = v12;
    v15 = a4[29];
    v50 = v14 - v55 * v15;
    v16 = v50;
    v51 = a4[9] * *(float *)(HIDWORD(result) + 660)
        + a4[8] * *(float *)(HIDWORD(result) + 656)
        + a4[10] * *(float *)(HIDWORD(result) + 664);
    v17 = v51;
    v52 = v13 * *(float *)(HIDWORD(result) + 648)
        + a4[4] * *(float *)(HIDWORD(result) + 640)
        + v60 * *(float *)(HIDWORD(result) + 644);
    v53 = v17 - v52;
    v61 = v16 - v15 * v53;
    v18 = v58;
    v19 = v61;
    v62 = v58 + v61;
    v59 = a4[37];
    if ( v59 <= (double)v62 )
    {
      v20 = (__m128)LODWORD(v62);
      v21 = v19;
    }
    else
    {
      v20 = (__m128)LODWORD(v59);
      v63 = v59 - v18;
      v21 = v63;
    }
    *((__m128 *)a4 + 5) = _mm_shuffle_ps(v20, v20, 0);
    if ( a2[88] != 0.0 )
    {
      v38 = a2[156] * a4[4];
      v23 = v38 * v21;
      v42 = a2[157] * a4[5];
      v28 = v42 * v21;
      v46 = a2[158] * a4[6];
      v33 = v46 * v21;
      a2[160] = v23 + a2[160];
      a2[161] = a2[161] + v28;
      a2[162] = a2[162] + v33;
      v24 = a2[152] * v21;
      v29 = a2[153] * v21;
      v34 = a2[154] * v21;
      v39 = v24 * a4[12];
      v43 = a4[13] * v29;
      v47 = a4[14] * v34;
      a2[164] = a2[164] + v39;
      a2[165] = v43 + a2[165];
      a2[166] = a2[166] + v47;
    }
    v22 = a3[88];
    v5 = v22 < 0.0;
    v9 = 0;
    v6 = v22 == 0.0;
    v7 = 0;
    v8 = 0;
    BYTE1(result) = a1;
    if ( v22 != 0.0 )
    {
      v25 = -a4[4];
      v40 = v25 * a3[156];
      v26 = v40 * v21;
      v30 = -a4[5];
      v44 = a3[157] * v30;
      v31 = v44 * v21;
      v35 = -a4[6];
      v48 = a3[158] * v35;
      v36 = v48 * v21;
      a3[160] = v26 + a3[160];
      a3[161] = a3[161] + v31;
      a3[162] = v36 + a3[162];
      v27 = v21 * a3[152];
      v32 = a3[153] * v21;
      v37 = v21 * a3[154];
      v41 = v27 * a4[16];
      v45 = a4[17] * v32;
      v49 = a4[18] * v37;
      a3[164] = v41 + a3[164];
      a3[165] = a3[165] + v45;
      a3[166] = v49 + a3[166];
    }
  }
  return result;
}
