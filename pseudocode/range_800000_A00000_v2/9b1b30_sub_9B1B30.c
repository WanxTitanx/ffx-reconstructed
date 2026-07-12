// Function: sub_9B1B30
// Address: 0x9b1b30
double __usercall sub_9B1B30@<st0>(int a1@<ebp>, float *a2, float *a3, float *a4, float *a5, float *a6, float a7)
{
  double v7; // st7
  double v8; // st7
  double v9; // st6
  double v10; // st6
  double v11; // rt1
  double v12; // rtt
  float v13; // xmm1_4
  float v14; // edx
  int v15; // edi
  unsigned int i; // esi
  float v17; // ecx
  double v18; // st7
  double v19; // st5
  float v20; // ecx
  float v21; // ecx
  int v22; // edx
  float v23; // xmm0_4
  float v24; // edx
  int v25; // xmm0_4
  float *v26; // edi
  double v27; // st7
  float v28; // esi
  double v29; // st7
  double v30; // st7
  double v31; // st7
  float v33; // [esp-F4h] [ebp-100h]
  float *v34; // [esp-F0h] [ebp-FCh]
  float *v35; // [esp-E8h] [ebp-F4h]
  float *v36; // [esp-E4h] [ebp-F0h]
  float *v37; // [esp-DCh] [ebp-E8h]
  float v38; // [esp-D8h] [ebp-E4h]
  float *v39; // [esp-D4h] [ebp-E0h]
  float v40; // [esp-C0h] [ebp-CCh]
  float v41; // [esp-BCh] [ebp-C8h]
  float v42; // [esp-B8h] [ebp-C4h]
  _DWORD v43[4]; // [esp-B0h] [ebp-BCh]
  float v44; // [esp-A0h] [ebp-ACh]
  float v45; // [esp-9Ch] [ebp-A8h]
  float v46; // [esp-98h] [ebp-A4h]
  float *v47; // [esp-90h] [ebp-9Ch]
  float *v48; // [esp-8Ch] [ebp-98h]
  float *v49; // [esp-88h] [ebp-94h]
  float v50; // [esp-84h] [ebp-90h]
  float v51; // [esp-80h] [ebp-8Ch]
  float v52; // [esp-7Ch] [ebp-88h]
  float v53; // [esp-78h] [ebp-84h]
  float v54; // [esp-74h] [ebp-80h] BYREF
  float v55; // [esp-70h] [ebp-7Ch]
  float v56; // [esp-6Ch] [ebp-78h]
  float v57; // [esp-68h] [ebp-74h]
  float v58; // [esp-64h] [ebp-70h]
  float v59; // [esp-60h] [ebp-6Ch]
  float v60; // [esp-5Ch] [ebp-68h]
  float v61; // [esp-58h] [ebp-64h]
  float v62; // [esp-54h] [ebp-60h]
  float v63; // [esp-50h] [ebp-5Ch] BYREF
  float v64; // [esp-4Ch] [ebp-58h] BYREF
  float v65[2]; // [esp-48h] [ebp-54h]
  float v66[4]; // [esp-40h] [ebp-4Ch] BYREF
  float v67[4]; // [esp-30h] [ebp-3Ch] BYREF
  float v68; // [esp-20h] [ebp-2Ch]
  float v69; // [esp-1Ch] [ebp-28h] BYREF
  float v70; // [esp-18h] [ebp-24h]
  int v71; // [esp-14h] [ebp-20h]
  int v72; // [esp+0h] [ebp-Ch]
  void *v73; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v72 = a1;
  v73 = retaddr;
  v7 = *a2;
  v48 = a4;
  v52 = v7;
  v62 = *a5;
  v56 = a7;
  v8 = v62;
  v47 = a2;
  v50 = *(float *)&a3;
  v63 = v52 - v62;
  v49 = a5;
  v9 = a2[1];
  v57 = *(float *)&a6;
  v61 = v9;
  v43[0] = a2;
  v10 = a5[1];
  v43[1] = a3;
  v62 = v10;
  v43[2] = a4;
  v43[3] = a5;
  v65[1] = 0.0;
  v66[3] = 0.0;
  v67[3] = 0.0;
  v11 = v62;
  v64 = v61 - v62;
  v60 = a2[2];
  v62 = a5[2];
  v65[0] = v60 - v62;
  v51 = *a3;
  v66[0] = v51 - v8;
  v59 = a3[1];
  v66[1] = v59 - v11;
  v53 = a3[2];
  v66[2] = v53 - v62;
  v54 = *a4;
  v12 = v62;
  v67[0] = v54 - v8;
  v58 = a4[1];
  v67[1] = v58 - v11;
  v62 = a4[2];
  v67[2] = v62 - v12;
  v55 = sub_9B12D0(&v63, v66, v67);
  v68 = v52 - v51;
  v69 = v61 - v59;
  v70 = v60 - v53;
  v40 = v51 - v54;
  v41 = v59 - v58;
  v42 = v53 - v62;
  v44 = v41 * v70 - v42 * v69;
  v45 = v42 * v68 - v70 * v40;
  v46 = v69 * v40 - v41 * v68;
  v62 = v61 * v45 + v52 * v44 + v60 * v46;
  if ( v62 * v55 > 0.0 )
    return -1.0;
  v62 = fabs(v55);
  if ( v62 <= 0.0 )
    return -1.0;
  v13 = -1.0;
  v14 = COERCE_FLOAT(&v64);
  v58 = -1.0;
  v61 = -1.0;
  v69 = 0.0;
  v70 = 0.0;
  v71 = 0;
  v54 = 0.0;
  v15 = 1;
  v60 = COERCE_FLOAT(&v64);
  for ( i = 0; i < 3; ++i )
  {
    v17 = *(float *)&dword_B6FEA8[i];
    v62 = *(float *)LODWORD(v14);
    v53 = v17;
    v59 = v65[4 * LODWORD(v17)];
    v51 = *(float *)(LODWORD(v14) + 4);
    v52 = v65[4 * LODWORD(v17) - 1];
    v18 = v62;
    v19 = v59;
    v44 = v62 * v59 - v51 * v52;
    v62 = *(&v63 + 4 * LODWORD(v17));
    v59 = *(float *)(LODWORD(v14) - 4);
    v45 = v51 * v62 - v19 * v59;
    v46 = v52 * v59 - v18 * v62;
    v62 = v45 * v49[1] + v44 * *v49 + v49[2] * v46;
    v62 = v62 * v55;
    if ( v62 > 0.0 )
    {
      v62 = sub_9B1FF0(v43[i], v43[LODWORD(v17)], v49, &v69, &v54);
      v13 = v58;
      if ( v58 < 0.0 || v61 > (double)v62 )
      {
        v13 = v62;
        v20 = 0.0;
        if ( (LOBYTE(v54) & 1) != 0 )
          v20 = *(float *)&v15;
        v62 = v20;
        v21 = v53;
        v58 = v13;
        v61 = v13;
        if ( (LOBYTE(v54) & 2) != 0 )
          v22 = 1 << SLOBYTE(v53);
        else
          v22 = 0;
        v23 = v69;
        *(_DWORD *)LODWORD(v56) = LODWORD(v62) + v22 + 2 * (LOBYTE(v54) & 4);
        v24 = v57;
        *(float *)(i * 4 + LODWORD(v57)) = v23;
        *(float *)(LODWORD(v24) + 4 * LODWORD(v21)) = v70;
        v25 = v71;
        *(_DWORD *)(LODWORD(v24) + 4 * dword_B6FEA8[LODWORD(v21)]) = 0;
        *(_DWORD *)(LODWORD(v24) + 12) = v25;
      }
      v14 = v60;
    }
    *(float *)&v15 = COERCE_FLOAT(__ROL4__(v15, 1));
    LODWORD(v14) += 16;
    v60 = v14;
  }
  if ( v13 < 0.0 )
  {
    v26 = v49;
    v39 = v49;
    v38 = v50;
    v61 = 0.0;
    v37 = v48;
    *(_DWORD *)LODWORD(v56) = 15;
    v27 = sub_9B12D0(v37, LODWORD(v38), v39);
    v28 = v57;
    v36 = v48;
    v35 = v47;
    v56 = v27 / v55;
    *(float *)LODWORD(v57) = v56;
    v29 = sub_9B12D0(v35, v36, v26);
    v34 = v47;
    v33 = v50;
    v57 = v29 / v55;
    *(float *)(LODWORD(v28) + 4) = v57;
    v30 = sub_9B12D0(LODWORD(v33), v34, v26);
    v50 = v30 / v55;
    v31 = v50;
    *(float *)(LODWORD(v28) + 8) = v50;
    *(float *)(LODWORD(v28) + 12) = 1.0 - (v31 + v57 + v56);
  }
  return v61;
}
