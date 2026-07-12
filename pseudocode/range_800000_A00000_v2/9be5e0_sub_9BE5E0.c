// Function: sub_9BE5E0
// Address: 0x9be5e0
__int64 __userpurge sub_9BE5E0@<edx:eax>(char a1@<efl>, float *a2, float *a3, float *a4)
{
  __int64 result; // rax
  double v5; // st7
  double v6; // st5
  double v7; // st3
  double v8; // st7
  double v9; // st4
  double v10; // st6
  double v11; // st7
  double v12; // st6
  __m128 v13; // xmm0
  double v14; // st7
  float v15; // xmm0_4
  bool v16; // cf
  bool v17; // zf
  char v18; // sf
  char v19; // of
  char v20; // pf
  float v21; // [esp-40h] [ebp-4Ch]
  float v22; // [esp-40h] [ebp-4Ch]
  float v23; // [esp-40h] [ebp-4Ch]
  float v24; // [esp-40h] [ebp-4Ch]
  float v25; // [esp-40h] [ebp-4Ch]
  float v26; // [esp-3Ch] [ebp-48h]
  float v27; // [esp-3Ch] [ebp-48h]
  float v28; // [esp-3Ch] [ebp-48h]
  float v29; // [esp-3Ch] [ebp-48h]
  float v30; // [esp-3Ch] [ebp-48h]
  float v31; // [esp-38h] [ebp-44h]
  float v32; // [esp-38h] [ebp-44h]
  float v33; // [esp-38h] [ebp-44h]
  float v34; // [esp-38h] [ebp-44h]
  float v35; // [esp-38h] [ebp-44h]
  float v36; // [esp-30h] [ebp-3Ch]
  float v37; // [esp-30h] [ebp-3Ch]
  float v38; // [esp-30h] [ebp-3Ch]
  float v39; // [esp-30h] [ebp-3Ch]
  float v40; // [esp-2Ch] [ebp-38h]
  float v41; // [esp-2Ch] [ebp-38h]
  float v42; // [esp-2Ch] [ebp-38h]
  float v43; // [esp-2Ch] [ebp-38h]
  float v44; // [esp-28h] [ebp-34h]
  float v45; // [esp-28h] [ebp-34h]
  float v46; // [esp-28h] [ebp-34h]
  float v47; // [esp-28h] [ebp-34h]
  float v48; // [esp-18h] [ebp-24h]
  float v49; // [esp-18h] [ebp-24h]
  float v50; // [esp-18h] [ebp-24h]
  float v51; // [esp-18h] [ebp-24h]
  float v52; // [esp-14h] [ebp-20h]
  float v53; // [esp-14h] [ebp-20h]
  float v54; // [esp-10h] [ebp-1Ch]
  float v55; // [esp-Ch] [ebp-18h]
  float v56; // [esp-Ch] [ebp-18h]
  float v57; // [esp-8h] [ebp-14h]
  float v58; // [esp-8h] [ebp-14h]
  float v59; // [esp-8h] [ebp-14h]
  float v60; // [esp-4h] [ebp-10h]
  float v61; // [esp-4h] [ebp-10h]
  float v62; // [esp-4h] [ebp-10h]
  float v63; // [esp-4h] [ebp-10h]
  float v64; // [esp-4h] [ebp-10h]

  v57 = a4[24];
  v54 = a4[5];
  v60 = a4[4];
  HIDWORD(result) = a3;
  v55 = a4[35] - a4[36] * v57;
  v5 = v55;
  v56 = a4[1] * a2[149] + a2[148] * *a4 + a4[2] * a2[150];
  v6 = a4[6];
  v52 = v60 * a2[144] + v54 * a2[145] + v6 * a2[146];
  v53 = v56 + v52;
  v7 = v5;
  v8 = a4[29];
  v48 = v7 - v53 * v8;
  v9 = v48;
  v49 = a4[9] * a3[149] + a4[8] * a3[148] + a4[10] * a3[150];
  v10 = v49;
  v50 = v6 * a3[146] + v54 * a3[145] + a3[144] * v60;
  v51 = v10 - v50;
  v61 = v9 - v8 * v51;
  v11 = v57;
  v12 = v61;
  v62 = v57 + v61;
  v58 = a4[37];
  if ( v58 <= (double)v62 )
  {
    v59 = a4[38];
    if ( v62 <= (double)v59 )
    {
      v13 = (__m128)LODWORD(v62);
      v14 = v12;
    }
    else
    {
      v13 = (__m128)LODWORD(v59);
      v64 = v59 - v11;
      v14 = v64;
    }
  }
  else
  {
    v13 = (__m128)LODWORD(v58);
    v63 = v58 - v11;
    v14 = v63;
  }
  *((__m128 *)a4 + 6) = _mm_shuffle_ps(v13, v13, 0);
  if ( a2[88] != 0.0 )
  {
    v36 = a4[4] * a2[156];
    v21 = v36 * v14;
    v40 = a2[157] * a4[5];
    v26 = v40 * v14;
    v44 = a2[158] * a4[6];
    v31 = v44 * v14;
    a2[144] = v21 + a2[144];
    a2[145] = v26 + a2[145];
    a2[146] = v31 + a2[146];
    v22 = a2[152] * v14;
    v27 = a2[153] * v14;
    v32 = a2[154] * v14;
    v37 = a4[12] * v22;
    v41 = a4[13] * v27;
    v45 = a4[14] * v32;
    a2[148] = a2[148] + v37;
    a2[149] = a2[149] + v41;
    a2[150] = a2[150] + v45;
  }
  v15 = a3[88];
  v16 = v15 < 0.0;
  v20 = 0;
  v17 = v15 == 0.0;
  v18 = 0;
  v19 = 0;
  BYTE1(result) = a1;
  if ( v15 != 0.0 )
  {
    v23 = -a4[4];
    v38 = a3[156] * v23;
    v24 = v38 * v14;
    v28 = -a4[5];
    v42 = a3[157] * v28;
    v29 = v42 * v14;
    v33 = -a4[6];
    v46 = a3[158] * v33;
    v34 = v46 * v14;
    a3[144] = a3[144] + v24;
    a3[145] = a3[145] + v29;
    a3[146] = v34 + a3[146];
    v25 = a3[152] * v14;
    v30 = a3[153] * v14;
    v35 = v14 * a3[154];
    v39 = a4[16] * v25;
    v43 = a4[17] * v30;
    v47 = a4[18] * v35;
    a3[148] = v39 + a3[148];
    a3[149] = v43 + a3[149];
    a3[150] = v47 + a3[150];
  }
  return result;
}
