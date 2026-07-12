// Function: sub_9AEAD0
// Address: 0x9aead0
int __userpurge sub_9AEAD0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, int a5, float *a6)
{
  float **v6; // edi
  bool v8; // cc
  int v9; // ecx
  int v10; // edx
  int v11; // edx
  int v12; // eax
  float *v13; // ecx
  float *v14; // eax
  double v15; // st7
  double v16; // st7
  double v17; // st7
  float *v18; // eax
  double v19; // st7
  float *v20; // eax
  float *v21; // eax
  float *v22; // ecx
  float *v23; // xmm0_4
  float v24; // eax
  unsigned int n3_3; // eax
  float *v26; // eax
  float v27; // eax
  bool v28; // zf
  float v29; // edx
  float v30; // eax
  unsigned int n3_4; // ecx
  float *v32; // esi
  float v33; // edi
  float v34; // edx
  float *v35; // esi
  unsigned int n0x40; // edi
  int v37; // ecx
  unsigned int v38; // eax
  float v39; // edi
  char v40; // cl
  unsigned int n3; // eax
  _DWORD *v42; // edx
  char v43; // al
  float v44; // ecx
  float v45; // eax
  int v46; // ecx
  int v47; // ecx
  int v48; // eax
  float *dst_1; // edx
  float v50; // edi
  double v51; // st5
  float v52; // xmm0_4
  double v53; // st7
  double v54; // st6
  float v55; // eax
  double v56; // st7
  float *v57; // eax
  float v58; // esi
  float *v59; // esi
  float v60; // eax
  double v61; // st7
  double v62; // st6
  double v63; // st5
  float v65; // xmm0_4
  float *v66; // [esp-CCh] [ebp-D8h]
  float *v67; // [esp-CCh] [ebp-D8h]
  float *v68; // [esp-CCh] [ebp-D8h]
  float *v69; // [esp-C8h] [ebp-D4h]
  float *v70; // [esp-C8h] [ebp-D4h]
  float *v71; // [esp-C8h] [ebp-D4h]
  int v73; // [esp-C0h] [ebp-CCh]
  int v75; // [esp-BCh] [ebp-C8h]
  float dst[16]; // [esp-B0h] [ebp-BCh] BYREF
  unsigned int n3_2; // [esp-68h] [ebp-74h]
  float *v78; // [esp-64h] [ebp-70h]
  float v79; // [esp-60h] [ebp-6Ch] BYREF
  float v80; // [esp-5Ch] [ebp-68h]
  float v81; // [esp-58h] [ebp-64h]
  int v82; // [esp-54h] [ebp-60h]
  float v83; // [esp-50h] [ebp-5Ch] BYREF
  float v84; // [esp-4Ch] [ebp-58h]
  float v85; // [esp-48h] [ebp-54h]
  int v86; // [esp-44h] [ebp-50h]
  float v87; // [esp-40h] [ebp-4Ch] BYREF
  float v88; // [esp-3Ch] [ebp-48h]
  float v89; // [esp-38h] [ebp-44h]
  int v90; // [esp-34h] [ebp-40h]
  float *v91; // [esp-2Ch] [ebp-38h]
  float v92; // [esp-28h] [ebp-34h]
  float v93; // [esp-24h] [ebp-30h]
  float v94; // [esp-20h] [ebp-2Ch]
  float v95; // [esp-1Ch] [ebp-28h] BYREF
  float v96; // [esp-18h] [ebp-24h]
  unsigned int n3_1; // [esp-14h] [ebp-20h]
  float v98; // [esp-Ch] [ebp-18h]
  char v99; // [esp-5h] [ebp-11h]
  float v100; // [esp-4h] [ebp-10h]
  _DWORD v101[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v101[0] = a2;
  v101[1] = retaddr;
  v6 = *(float ***)(a5 + 392);
  v8 = (unsigned int)v6[8] <= 1;
  v91 = (float *)a1;
  if ( v8 || !sub_9AE580(a5, (int)v101) )
    goto LABEL_40;
  for ( ; *(_DWORD *)(a1 + 10324); *(_DWORD *)(a1 + 10332) = v9 )
  {
    v9 = *(_DWORD *)(a1 + 10324);
    v10 = *(_DWORD *)(v9 + 52);
    if ( v10 )
      *(_DWORD *)(v10 + 48) = *(_DWORD *)(v9 + 48);
    v11 = *(_DWORD *)(v9 + 48);
    if ( v11 )
      *(_DWORD *)(v11 + 52) = *(_DWORD *)(v9 + 52);
    if ( v9 == *(_DWORD *)(a1 + 10324) )
      *(_DWORD *)(a1 + 10324) = *(_DWORD *)(v9 + 52);
    --*(_DWORD *)(a1 + 10328);
    *(_DWORD *)(v9 + 48) = 0;
    *(_DWORD *)(v9 + 52) = *(_DWORD *)(a1 + 10332);
    v12 = *(_DWORD *)(a1 + 10332);
    if ( v12 )
      *(_DWORD *)(v12 + 48) = v9;
    ++*(_DWORD *)(a1 + 10336);
  }
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 10320) = 0;
  v13 = v6[3];
  v14 = v6[2];
  v86 = 0;
  v15 = v14[4];
  v82 = 0;
  v16 = v15 - v13[4];
  v90 = 0;
  v83 = v16;
  v84 = v14[5] - v13[5];
  v17 = v14[6];
  v18 = v6[1];
  v85 = v17 - v13[6];
  v79 = v18[4] - v13[4];
  v80 = v18[5] - v13[5];
  v19 = v18[6];
  v20 = *v6;
  v81 = v19 - v13[6];
  v87 = v20[4] - v13[4];
  v88 = v20[5] - v13[5];
  v89 = v20[6] - v13[6];
  if ( sub_9B12D0(&v87, &v79, &v83) < 0.0 )
  {
    v21 = v6[1];
    v22 = *v6;
    v23 = v6[4];
    v6[4] = v6[5];
    *v6 = v21;
    v6[1] = v22;
    v6[5] = v23;
  }
  v24 = COERCE_FLOAT(sub_9B1680(*v6, v6[1], v6[2], 1));
  v69 = v6[3];
  v66 = *v6;
  v98 = v24;
  n3_3 = sub_9B1680(v6[1], v66, v69, 1);
  v70 = v6[3];
  v67 = v6[1];
  n3_2 = n3_3;
  v26 = (float *)sub_9B1680(v6[2], v67, v70, 1);
  v71 = v6[3];
  v68 = v6[2];
  v78 = v26;
  v27 = COERCE_FLOAT(sub_9B1680(*v6, v68, v71, 1));
  v28 = *(_DWORD *)(a1 + 10328) == 4;
  v100 = v27;
  if ( v28 )
  {
    v29 = COERCE_FLOAT(sub_9B14C0(a1, a3, a4));
    v30 = v98;
    qmemcpy(dst, (const void *)LODWORD(v29), sizeof(dst));
    n3_4 = n3_2;
    v32 = v78;
    v33 = v100;
    *(_DWORD *)(LODWORD(v98) + 36) = n3_2;
    v93 = v29;
    v34 = 0.0;
    *(_BYTE *)(LODWORD(v30) + 56) = 0;
    *(_BYTE *)(n3_4 + 56) = 0;
    *(float *)(n3_4 + 36) = v30;
    *(_DWORD *)(LODWORD(v30) + 40) = v32;
    *(_BYTE *)(LODWORD(v30) + 57) = 0;
    *((_BYTE *)v32 + 56) = 1;
    v32[9] = v30;
    *(_BYTE *)(LODWORD(v30) + 58) = 0;
    *(float *)(LODWORD(v30) + 44) = v33;
    *(_BYTE *)(LODWORD(v33) + 56) = 2;
    *(float *)(LODWORD(v33) + 36) = v30;
    *(_BYTE *)(n3_4 + 57) = 2;
    *(float *)(n3_4 + 40) = v33;
    *(_BYTE *)(LODWORD(v33) + 58) = 1;
    *(_DWORD *)(LODWORD(v33) + 44) = n3_4;
    *(_DWORD *)(n3_4 + 44) = v32;
    *(_BYTE *)(n3_4 + 58) = 1;
    *(_WORD *)((char *)v32 + 57) = 258;
    *((_DWORD *)v32 + 10) = n3_4;
    v32[11] = v33;
    *(_DWORD *)(LODWORD(v33) + 40) = v32;
    v35 = v91;
    *(_BYTE *)(LODWORD(v33) + 57) = 2;
    v92 = 0.0;
    *v35 = 0.0;
    while ( 1 )
    {
      n0x40 = *((_DWORD *)v35 + 2580);
      if ( n0x40 >= 0x40 )
        break;
      v37 = 32 * n0x40 + 80;
      v38 = n0x40 + 1;
      v39 = v93;
      v78 = (float *)((char *)v35 + v37);
      v95 = 0.0;
      v96 = 0.0;
      n3_1 = 0;
      *((_DWORD *)v35 + 2580) = v38;
      v99 = 1;
      LODWORD(v98) = LODWORD(v34) + 1;
      *(_BYTE *)(LODWORD(v39) + 59) = LOBYTE(v34) + 1;
      sub_9B1530(LODWORD(v39), (char *)v35 + v37);
      v100 = v78[5] * *(float *)(LODWORD(v39) + 4)
           + v78[4] * *(float *)LODWORD(v39)
           + v78[6] * *(float *)(LODWORD(v39) + 8);
      v100 = v100 - *(float *)(LODWORD(v39) + 16);
      if ( v100 <= 0.00009999999747378752 )
      {
        *(_DWORD *)v35 = 7;
        goto LABEL_39;
      }
      v40 = v99;
      n3 = 0;
      v42 = (_DWORD *)(LODWORD(v39) + 36);
      n3_2 = 0;
      LODWORD(v93) = LODWORD(v39) + 36;
      do
      {
        if ( !v40 )
          goto LABEL_36;
        v43 = sub_9B1390(LODWORD(v98), v78, *v42, *(unsigned __int8 *)(n3 + LODWORD(v39) + 56), &v95);
        v40 = v43 & v99;
        n3 = n3_2 + 1;
        v42 = (_DWORD *)(LODWORD(v93) + 4);
        v99 = v40;
        n3_2 = n3;
        LODWORD(v93) += 4;
      }
      while ( n3 < 3 );
      if ( !v40 || n3_1 < 3 )
      {
LABEL_36:
        *(_DWORD *)v35 = 4;
        goto LABEL_39;
      }
      v44 = v96;
      v45 = v95;
      *(_BYTE *)(LODWORD(v95) + 57) = 2;
      *(float *)(LODWORD(v45) + 40) = v44;
      *(_BYTE *)(LODWORD(v44) + 58) = 1;
      *(float *)(LODWORD(v44) + 44) = v45;
      v46 = *(_DWORD *)(LODWORD(v39) + 52);
      if ( v46 )
        *(_DWORD *)(v46 + 48) = *(_DWORD *)(LODWORD(v39) + 48);
      v47 = *(_DWORD *)(LODWORD(v39) + 48);
      if ( v47 )
        *(_DWORD *)(v47 + 52) = *(_DWORD *)(LODWORD(v39) + 52);
      if ( LODWORD(v39) == *((_DWORD *)v35 + 2581) )
        v35[2581] = *(float *)(LODWORD(v39) + 52);
      --*((_DWORD *)v35 + 2582);
      *(_DWORD *)(LODWORD(v39) + 48) = 0;
      *(float *)(LODWORD(v39) + 52) = v35[2583];
      v48 = *((_DWORD *)v35 + 2583);
      if ( v48 )
        *(float *)(v48 + 48) = v39;
      ++*((_DWORD *)v35 + 2584);
      v35[2583] = v39;
      *(float *)&dst_1 = COERCE_FLOAT(sub_9B14C0(v35, v73, v75));
      v93 = *(float *)&dst_1;
      if ( dst_1[5] >= (double)dst[5] )
      {
        qmemcpy(dst, dst_1, sizeof(dst));
        v35 = v91;
      }
      v34 = v98;
      if ( ++LODWORD(v92) >= 0xFFu )
        goto LABEL_39;
    }
    *(_DWORD *)v35 = 6;
LABEL_39:
    v50 = dst[7];
    v51 = dst[4];
    v52 = dst[4];
    v53 = dst[0] * dst[4];
    v35[12] = dst[0];
    v35[13] = dst[1];
    v94 = v53;
    v54 = dst[1];
    v35[14] = dst[2];
    v35[15] = dst[3];
    v55 = dst[6];
    v95 = v54 * v51;
    v35[16] = v52;
    *((_DWORD *)v35 + 9) = 3;
    v56 = v51 * dst[2];
    v35[1] = v55;
    v57 = v91;
    v35[2] = v50;
    v96 = v56;
    v58 = dst[8];
    v57[3] = dst[8];
    v87 = *(float *)(LODWORD(v58) + 16) - v94;
    v88 = *(float *)(LODWORD(v58) + 20) - v95;
    v89 = *(float *)(LODWORD(v58) + 24) - v96;
    v79 = *(float *)(LODWORD(v50) + 16) - v94;
    v80 = *(float *)(LODWORD(v50) + 20) - v95;
    v81 = *(float *)(LODWORD(v50) + 24) - v96;
    v83 = v80 * v89 - v81 * v88;
    v84 = v81 * v87 - v89 * v79;
    v85 = v88 * v79 - v80 * v87;
    v100 = v83 * v83 + v84 * v84 + v85 * v85;
    v92 = sqrt(v100);
    v91[5] = v92;
    v83 = *(float *)(LODWORD(dst[6]) + 16) - v94;
    v84 = *(float *)(LODWORD(dst[6]) + 20) - v95;
    v85 = *(float *)(LODWORD(dst[6]) + 24) - v96;
    v79 = *(float *)(LODWORD(v58) + 16) - v94;
    v80 = *(float *)(LODWORD(v58) + 20) - v95;
    v81 = *(float *)(LODWORD(v58) + 24) - v96;
    v87 = v80 * v85 - v81 * v84;
    v88 = v81 * v83 - v85 * v79;
    v89 = v84 * v79 - v80 * v83;
    v100 = v87 * v87 + v88 * v88 + v89 * v89;
    v98 = sqrt(v100);
    v59 = v91;
    v60 = dst[6];
    v91[6] = v98;
    v83 = *(float *)(LODWORD(v50) + 16) - v94;
    v84 = *(float *)(LODWORD(v50) + 20) - v95;
    v85 = *(float *)(LODWORD(v50) + 24) - v96;
    v79 = *(float *)(LODWORD(v60) + 16) - v94;
    v80 = *(float *)(LODWORD(v60) + 20) - v95;
    v81 = *(float *)(LODWORD(v60) + 24) - v96;
    v87 = v80 * v85 - v81 * v84;
    v88 = v81 * v83 - v85 * v79;
    v89 = v84 * v79 - v80 * v83;
    v100 = v87 * v87 + v88 * v88 + v89 * v89;
    v100 = sqrt(v100);
    v61 = v98;
    v62 = v100;
    v100 = v98 + v92 + v100;
    v63 = v100;
    v59[5] = v92 / v100;
    v59[6] = v61 / v63;
    v59[7] = v62 / v63;
    return *(_DWORD *)v59;
  }
  else
  {
LABEL_40:
    *(_DWORD *)a1 = 8;
    v94 = -*a6;
    v95 = -a6[1];
    v65 = a6[2];
    *(float *)(a1 + 48) = v94;
    *(float *)(a1 + 52) = v95;
    v96 = -v65;
    *(float *)(a1 + 56) = -v65;
    n3_1 = 0;
    *(_DWORD *)(a1 + 60) = 0;
    v92 = *(float *)(a1 + 52);
    v98 = *(float *)(a1 + 48);
    v93 = *(float *)(a1 + 56);
    v100 = v98 * v98 + v92 * v92 + v93 * v93;
    v100 = sqrt(v100);
    n3_1 = 0;
    if ( v100 <= 0.0 )
    {
      v94 = 1.0;
      v95 = 0.0;
      v96 = 0.0;
    }
    else
    {
      v100 = 1.0 / v100;
      v94 = v100 * v98;
      v95 = v100 * v92;
      v96 = v100 * v93;
    }
    *(float *)(a1 + 48) = v94;
    *(float *)(a1 + 52) = v95;
    *(float *)(a1 + 56) = v96;
    *(_DWORD *)(a1 + 60) = n3_1;
    *(_DWORD *)(a1 + 64) = 0;
    *(_DWORD *)(a1 + 36) = 1;
    *(_DWORD *)(a1 + 4) = *v6;
    *(_DWORD *)(a1 + 20) = 1065353216;
    return *(_DWORD *)a1;
  }
}
