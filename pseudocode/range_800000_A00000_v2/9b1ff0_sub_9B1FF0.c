// Function: sub_9B1FF0
// Address: 0x9b1ff0
double __usercall sub_9B1FF0@<st0>(int a1@<ebp>, float *a2, float *a3, float *a4, float *a5, float a6)
{
  double v6; // st7
  double v7; // rt0
  double v8; // st5
  double v9; // st5
  double v10; // st5
  double v11; // st4
  double v12; // st3
  double v13; // st6
  double v14; // st0
  double v15; // st7
  double v16; // st5
  double v17; // st6
  float v18; // xmm1_4
  float *v19; // eax
  int v20; // edi
  unsigned int i; // esi
  float *v22; // ecx
  double v23; // st4
  float v24; // ecx
  int v25; // edx
  int v26; // eax
  float v27; // xmm0_4
  double v28; // st6
  double v29; // st5
  float *v30; // edx
  double v31; // rt1
  double v32; // st6
  double v33; // st5
  double v34; // st7
  double v35; // st4
  double v36; // st3
  float *v37; // eax
  float *v38; // esi
  double v39; // st7
  float *v41; // [esp-CCh] [ebp-D8h]
  float v42; // [esp-B8h] [ebp-C4h] BYREF
  float v43; // [esp-B4h] [ebp-C0h]
  float v44; // [esp-B0h] [ebp-BCh]
  float *v45; // [esp-ACh] [ebp-B8h]
  float *v46; // [esp-A8h] [ebp-B4h]
  float *v47; // [esp-A4h] [ebp-B0h]
  float v48; // [esp-A0h] [ebp-ACh]
  int v49; // [esp-9Ch] [ebp-A8h] BYREF
  float *v50; // [esp-98h] [ebp-A4h]
  float v51; // [esp-94h] [ebp-A0h]
  float v52; // [esp-90h] [ebp-9Ch]
  float v53; // [esp-8Ch] [ebp-98h]
  float v54; // [esp-88h] [ebp-94h]
  float v55; // [esp-74h] [ebp-80h]
  float v56; // [esp-70h] [ebp-7Ch]
  float v57; // [esp-6Ch] [ebp-78h]
  float v58; // [esp-68h] [ebp-74h]
  float v59; // [esp-64h] [ebp-70h]
  float v60; // [esp-60h] [ebp-6Ch]
  float v61; // [esp-5Ch] [ebp-68h]
  float v62; // [esp-58h] [ebp-64h]
  float *v63; // [esp-4Ch] [ebp-58h]
  float v64; // [esp-48h] [ebp-54h]
  float v65; // [esp-44h] [ebp-50h]
  float v66; // [esp-40h] [ebp-4Ch]
  float v67; // [esp-3Ch] [ebp-48h] BYREF
  float v68; // [esp-38h] [ebp-44h]
  int v69; // [esp-34h] [ebp-40h]
  float v70; // [esp-30h] [ebp-3Ch]
  float v71; // [esp-2Ch] [ebp-38h]
  float v72; // [esp-28h] [ebp-34h]
  int v73; // [esp-24h] [ebp-30h]
  float v74; // [esp-20h] [ebp-2Ch]
  float v75; // [esp-1Ch] [ebp-28h]
  float v76; // [esp-18h] [ebp-24h]
  int v77; // [esp-14h] [ebp-20h]
  int v78; // [esp+0h] [ebp-Ch]
  void *v79; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v78 = a1;
  v79 = retaddr;
  v65 = *a2;
  v64 = *a3;
  v6 = v65;
  v57 = *(float *)&a2;
  v58 = *(float *)&a3;
  v63 = a4;
  v50 = a5;
  v7 = v64;
  v59 = a6;
  v45 = a2;
  v66 = v65 - v64;
  v46 = a3;
  v8 = a2[1];
  v47 = a4;
  v65 = v8;
  v69 = 0;
  v9 = a3[1];
  v73 = 0;
  v64 = v9;
  v77 = 0;
  v10 = v65;
  v11 = v64;
  v67 = v65 - v64;
  v65 = a2[2];
  v64 = a3[2];
  v12 = v65;
  v68 = v65 - v64;
  v65 = *a4;
  v13 = v65;
  v70 = v7 - v65;
  v65 = a4[1];
  v71 = v11 - v65;
  v14 = a4[2];
  v72 = v64 - v14;
  v74 = v13 - v6;
  v75 = v65 - v10;
  v76 = v14 - v12;
  v60 = v72 * v67 - v71 * v68;
  v61 = v68 * v70 - v72 * v66;
  v62 = v66 * v71 - v70 * v67;
  v15 = v61;
  v16 = v60;
  v17 = v62;
  v51 = v60 * v60 + v61 * v61 + v62 * v62;
  if ( v51 <= 0.0 )
    return -1.0;
  v18 = -1.0;
  v19 = &v67;
  v48 = -1.0;
  v55 = -1.0;
  v42 = 0.0;
  v43 = 0.0;
  v49 = 0;
  v20 = 1;
  v65 = COERCE_FLOAT(&v67);
  for ( i = 0; i < 3; ++i )
  {
    v22 = (&v45)[i];
    v64 = *v19;
    v56 = v19[1];
    v23 = v64;
    v52 = v64 * v17 - v56 * v15;
    v64 = *(v19 - 1);
    v53 = v56 * v16 - v64 * v17;
    v54 = v64 * v15 - v23 * v16;
    v64 = v22[1] * v53 + v52 * *v22 + v22[2] * v54;
    if ( v64 > 0.0 )
    {
      v41 = (&v45)[dword_B6FE9C[i]];
      v64 = *(float *)&dword_B6FE9C[i];
      v56 = sub_9B2560(v22, v41, &v42, &v49);
      v18 = v48;
      if ( v48 >= 0.0 && v55 <= (double)v56 )
      {
        v15 = v61;
        v28 = v60;
        v29 = v62;
      }
      else
      {
        v18 = v56;
        v24 = v64;
        v25 = 0;
        if ( (v49 & 1) != 0 )
          v25 = v20;
        v48 = v56;
        v55 = v56;
        if ( (v49 & 2) != 0 )
          v26 = 1 << SLOBYTE(v64);
        else
          v26 = 0;
        v27 = v42;
        v15 = v61;
        v28 = v60;
        v29 = v62;
        *(_DWORD *)LODWORD(v59) = v25 + v26;
        v30 = v50;
        v50[i] = v27;
        v30[LODWORD(v24)] = v43;
        v30[dword_B6FE9C[LODWORD(v24)]] = 0.0;
      }
      v31 = v29;
      v16 = v28;
      v17 = v31;
    }
    v20 = __ROL4__(v20, 1);
    v19 = (float *)(LODWORD(v65) + 16);
    LODWORD(v65) += 16;
  }
  if ( v18 < 0.0 )
  {
    v65 = sqrt(v51);
    v32 = v60;
    v33 = v61;
    v34 = *(float *)LODWORD(v57) * v60 + v61 * *(float *)(LODWORD(v57) + 4);
    v35 = v62;
    v36 = v62 * *(float *)(LODWORD(v57) + 8);
    *(_DWORD *)LODWORD(v59) = 7;
    v57 = v34 + v36;
    v57 = v57 / v51;
    v60 = v32 * v57;
    v61 = v33 * v57;
    v62 = v35 * v57;
    v55 = v60 * v60 + v61 * v61 + v62 * v62;
    v52 = *(float *)LODWORD(v58) - v60;
    v53 = *(float *)(LODWORD(v58) + 4) - v61;
    v54 = *(float *)(LODWORD(v58) + 8) - v62;
    v44 = v54 * v71 - v53 * v72;
    *(float *)&v45 = v72 * v52 - v54 * v70;
    *(float *)&v46 = v70 * v53 - v52 * v71;
    v58 = v44 * v44 + *(float *)&v45 * *(float *)&v45 + *(float *)&v46 * *(float *)&v46;
    v58 = sqrt(v58);
    v37 = v63;
    v38 = v50;
    v59 = v58 / v65;
    *v50 = v59;
    v52 = *v37 - v60;
    v53 = v37[1] - v61;
    v54 = v37[2] - v62;
    v60 = v54 * v75 - v53 * v76;
    v61 = v76 * v52 - v54 * v74;
    v62 = v74 * v53 - v52 * v75;
    *(float *)&v63 = v60 * v60 + v61 * v61 + v62 * v62;
    *(float *)&v63 = sqrt(*(float *)&v63);
    *(float *)&v63 = *(float *)&v63 / v65;
    v39 = *(float *)&v63;
    v38[1] = *(float *)&v63;
    v38[2] = 1.0 - (v39 + v59);
  }
  return v55;
}
