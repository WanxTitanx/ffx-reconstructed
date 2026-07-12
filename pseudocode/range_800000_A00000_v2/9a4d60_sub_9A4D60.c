// Function: sub_9A4D60
// Address: 0x9a4d60
void __userpurge sub_9A4D60(int a1@<ecx>, int a2@<ebp>, float *a3, float *a4, float a5)
{
  int v5; // esi
  int v6; // eax
  double v7; // st7
  double v8; // st6
  double v9; // st5
  double v10; // st5
  float v11; // xmm0_4
  double v12; // st5
  double v13; // st5
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  double v17; // st3
  double v18; // st6
  float v19; // xmm0_4
  double v20; // st6
  double v21; // st4
  float v22; // xmm0_4
  double v23; // st5
  double v24; // st3
  double v25; // st2
  double v26; // st5
  float v27; // xmm0_4
  double v28; // st5
  double v29; // st5
  float v30; // xmm0_4
  float v31; // xmm0_4
  double v32; // st5
  float v33; // xmm0_4
  double v34; // st3
  double v35; // st2
  double v36; // st1
  float v37; // xmm0_4
  double v38; // st1
  float v39; // xmm0_4
  double v40; // st6
  int v41; // ecx
  int v42; // eax
  int v43; // edi
  int v44; // edx
  int v45; // ecx
  double v46; // st7
  float v47; // xmm0_4
  int v48; // eax
  float v49; // esi
  float v50; // ecx
  int v51; // xmm2_4
  int v52; // xmm1_4
  int v53; // xmm0_4
  int v54; // edx
  int v55; // eax
  float v56; // ecx
  float v57; // esi
  int v58; // ecx
  int v59; // edx
  int v60; // eax
  float v62; // [esp+14h] [ebp-1BCh] BYREF
  float v63; // [esp+18h] [ebp-1B8h]
  float v64; // [esp+1Ch] [ebp-1B4h]
  int v65; // [esp+20h] [ebp-1B0h]
  float v66; // [esp+24h] [ebp-1ACh] BYREF
  float v67; // [esp+28h] [ebp-1A8h]
  float v68; // [esp+2Ch] [ebp-1A4h]
  int v69; // [esp+30h] [ebp-1A0h]
  __int64 v70; // [esp+34h] [ebp-19Ch]
  double v71; // [esp+3Ch] [ebp-194h]
  float v72; // [esp+48h] [ebp-188h]
  float v73; // [esp+4Ch] [ebp-184h]
  bool v74; // [esp+53h] [ebp-17Dh]
  float v75; // [esp+54h] [ebp-17Ch]
  float v76; // [esp+58h] [ebp-178h]
  float v77; // [esp+5Ch] [ebp-174h]
  int v78; // [esp+60h] [ebp-170h]
  _QWORD src[36]; // [esp+64h] [ebp-16Ch] BYREF
  float v80; // [esp+184h] [ebp-4Ch]
  float v81; // [esp+188h] [ebp-48h]
  float v82; // [esp+18Ch] [ebp-44h]
  float v83; // [esp+194h] [ebp-3Ch]
  float v84; // [esp+198h] [ebp-38h]
  float v85; // [esp+19Ch] [ebp-34h]
  float v86; // [esp+1A4h] [ebp-2Ch]
  float v87; // [esp+1A8h] [ebp-28h]
  float v88; // [esp+1ACh] [ebp-24h]
  int v89; // [esp+1C4h] [ebp-Ch]
  void *v90; // [esp+1C8h] [ebp-8h]
  void *retaddr; // [esp+1D0h] [ebp+0h]

  v89 = a2;
  v90 = retaddr;
  v5 = a1;
  v71 = a5;
  if ( a5 <= sub_9A43D0((float *)*(_DWORD *)(a1 + 4)) )
  {
    v6 = *(_DWORD *)(v5 + 4);
    v7 = *a3;
    HIDWORD(v71) = 0;
    v74 = *(_DWORD *)(v6 + 1168) != *(_DWORD *)(v5 + 144);
    v75 = v7 * a5;
    v76 = a3[1] * a5;
    v77 = a3[2] * a5;
    v73 = *a4;
    v8 = v73;
    *(float *)&v70 = v73 + v75;
    v72 = a4[1];
    *((float *)&v70 + 1) = v72 + v76;
    v73 = a4[2];
    *(float *)&v71 = v73 + v77;
    v9 = *(float *)&v70;
    if ( v74 )
    {
      v10 = v9 - *(float *)(v5 + 128);
      v80 = *(float *)(v5 + 80);
      v11 = *(float *)(v5 + 112);
      v75 = v10;
      v82 = v11;
      v12 = *((float *)&v70 + 1) - *(float *)(v5 + 132);
      v83 = *(float *)(v5 + 84);
      v84 = *(float *)(v5 + 100);
      v76 = v12;
      v85 = *(float *)(v5 + 116);
      v13 = *(float *)&v71 - *(float *)(v5 + 136);
      v86 = *(float *)(v5 + 88);
      v14 = *(float *)(v5 + 104);
      v77 = v13;
      v87 = v14;
      v15 = *(float *)(v5 + 120);
      v81 = *(float *)(v5 + 96);
      v88 = v15;
      v16 = *(float *)(v5 + 16);
      v69 = 0;
      v17 = v80;
      v80 = v16;
      v66 = v82 * v77 + v17 * v75 + v81 * v76;
      v62 = v66;
      v67 = v76 * v84 + v83 * v75 + v77 * v85;
      v63 = v67;
      v68 = v75 * v86 + v76 * v87 + v77 * v88;
      v64 = v68;
      v18 = v8 - *(float *)(v5 + 64);
      v65 = 0;
      v75 = v18;
      v76 = v72 - *(float *)(v5 + 68);
      v77 = v73 - *(float *)(v5 + 72);
      v19 = *(float *)(v5 + 48);
      v81 = *(float *)(v5 + 32);
      v20 = v76;
      v82 = v19;
      v83 = *(float *)(v5 + 20);
      v21 = v75;
      v84 = *(float *)(v5 + 36);
      v85 = *(float *)(v5 + 52);
      v86 = *(float *)(v5 + 24);
      v87 = *(float *)(v5 + 40);
      v22 = *(float *)(v5 + 56);
      v23 = v77;
      v75 = v76 * v81 + v75 * v80 + v77 * v82;
      v24 = v76 * v84;
      v25 = v21 * v83;
    }
    else
    {
      v26 = v9 - *(float *)(v5 + 64);
      v80 = *(float *)(v5 + 16);
      v27 = *(float *)(v5 + 48);
      v75 = v26;
      v82 = v27;
      v28 = *((float *)&v70 + 1) - *(float *)(v5 + 68);
      v83 = *(float *)(v5 + 20);
      v84 = *(float *)(v5 + 36);
      v76 = v28;
      v85 = *(float *)(v5 + 52);
      v29 = *(float *)&v71 - *(float *)(v5 + 72);
      v86 = *(float *)(v5 + 24);
      v30 = *(float *)(v5 + 40);
      v77 = v29;
      v87 = v30;
      v31 = *(float *)(v5 + 56);
      v81 = *(float *)(v5 + 32);
      v88 = v31;
      v32 = v76;
      v33 = *(float *)(v5 + 80);
      v78 = 0;
      v34 = v75;
      v35 = v75 * v80;
      v80 = v33;
      v36 = v77 * v82;
      v82 = *(float *)(v5 + 112);
      v37 = *(float *)(v5 + 84);
      v75 = v76 * v81 + v35 + v36;
      v62 = v75;
      v38 = v34 * v83;
      v83 = v37;
      v39 = *(float *)(v5 + 100);
      v76 = v76 * v84 + v38 + v77 * v85;
      v63 = v76;
      v77 = v32 * v87 + v34 * v86 + v77 * v88;
      v64 = v77;
      v40 = v8 - *(float *)(v5 + 128);
      v65 = 0;
      v75 = v40;
      v76 = v72 - *(float *)(v5 + 132);
      v77 = v73 - *(float *)(v5 + 136);
      v81 = *(float *)(v5 + 96);
      v20 = v76;
      v84 = v39;
      v85 = *(float *)(v5 + 116);
      v21 = v75;
      v86 = *(float *)(v5 + 88);
      v87 = *(float *)(v5 + 104);
      v22 = *(float *)(v5 + 120);
      v23 = v77;
      v75 = v76 * v81 + v75 * v80 + v77 * v82;
      v24 = v21 * v83;
      v25 = v76 * v84;
    }
    v88 = v22;
    v66 = v75;
    v78 = 0;
    v76 = v24 + v25 + v23 * v85;
    v67 = v76;
    v77 = v20 * v87 + v21 * v86 + v23 * v22;
    v68 = v77;
    v69 = 0;
    sub_97BC00(&v62, &v66, a3, LODWORD(a5));
    src[6] = v70;
    v41 = *(_DWORD *)(v5 + 4);
    *(double *)&src[7] = v71;
    src[4] = *(_QWORD *)a4;
    src[5] = *((_QWORD *)a4 + 1);
    v42 = sub_9A4300(v41, (float *)src);
    v43 = *(_DWORD *)(v5 + 144);
    v44 = *(_DWORD *)(v5 + 148);
    v45 = v42;
    v46 = *(float *)(v43 + 236) * *(float *)(v44 + 236);
    HIDWORD(v71) = v42;
    v73 = v46;
    if ( v73 >= -10.0 )
      v47 = v73;
    else
      v47 = -10.0;
    if ( v47 > 10.0 )
      v47 = 10.0;
    *((float *)&src[10] + 1) = v47;
    *(float *)&src[11] = *(float *)(v43 + 240) * *(float *)(v44 + 240);
    if ( v74 )
    {
      HIDWORD(src[11]) = *(_DWORD *)(v5 + 156);
      LODWORD(src[12]) = *(_DWORD *)(v5 + 152);
      HIDWORD(src[12]) = *(_DWORD *)(v5 + 164);
      v48 = *(_DWORD *)(v5 + 160);
    }
    else
    {
      HIDWORD(src[11]) = *(_DWORD *)(v5 + 152);
      src[12] = *(_QWORD *)(v5 + 156);
      v48 = *(_DWORD *)(v5 + 164);
    }
    LODWORD(src[13]) = v48;
    if ( v45 < 0 )
    {
      v58 = sub_9A4180(*(int **)(v5 + 4), src);
    }
    else
    {
      v49 = *(float *)(v5 + 4);
      LODWORD(v50) = 288 * v45;
      v51 = *(_DWORD *)(LODWORD(v50) + LODWORD(v49) + 236);
      v52 = *(_DWORD *)(LODWORD(v50) + LODWORD(v49) + 268);
      v53 = *(_DWORD *)(LODWORD(v50) + LODWORD(v49) + 300);
      v54 = *(_DWORD *)(LODWORD(v50) + LODWORD(v49) + 160);
      v55 = *(_DWORD *)(LODWORD(v50) + LODWORD(v49) + 124);
      v72 = v49;
      v73 = v50;
      qmemcpy((void *)(LODWORD(v50) + LODWORD(v49) + 16), src, 0x120u);
      v56 = v73;
      v57 = v72;
      *(_DWORD *)(LODWORD(v73) + LODWORD(v72) + 124) = v55;
      *(_DWORD *)(LODWORD(v56) + LODWORD(v57) + 128) = v51;
      *(_DWORD *)(LODWORD(v56) + LODWORD(v57) + 136) = v52;
      *(_DWORD *)(LODWORD(v56) + LODWORD(v57) + 140) = v53;
      *(_DWORD *)(LODWORD(v56) + LODWORD(v57) + 236) = v51;
      *(_DWORD *)(LODWORD(v56) + LODWORD(v57) + 268) = v52;
      *(_DWORD *)(LODWORD(v56) + LODWORD(v57) + 300) = v53;
      *(_DWORD *)(LODWORD(v56) + LODWORD(v57) + 160) = v54;
      v5 = a1;
      v58 = HIDWORD(v71);
    }
    if ( unk_193F64C )
    {
      v59 = *(_DWORD *)(v5 + 144);
      if ( (*(_BYTE *)(v59 + 216) & 8) != 0 || (*(_BYTE *)(*(_DWORD *)(v5 + 148) + 216) & 8) != 0 )
      {
        if ( v74 )
        {
          v60 = *(_DWORD *)(v5 + 148);
        }
        else
        {
          v60 = *(_DWORD *)(v5 + 144);
          v59 = *(_DWORD *)(v5 + 148);
        }
        unk_193F64C(
          288 * v58 + *(_DWORD *)(v5 + 4) + 16,
          v60,
          HIDWORD(src[11]),
          HIDWORD(src[12]),
          v59,
          src[12],
          src[13]);
      }
    }
  }
}
