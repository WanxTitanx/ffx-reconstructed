// Function: sub_9AF2C0
// Address: 0x9af2c0
int __userpurge sub_9AF2C0@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>, _DWORD *a3, _DWORD *a4)
{
  float v4; // esi
  int v5; // eax
  _DWORD *v6; // ecx
  int v7; // eax
  int v8; // eax
  float v9; // edi
  float v10; // xmm0_4
  int v11; // eax
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // edx
  float *v15; // edi
  double v16; // st7
  double v17; // st6
  double v18; // st5
  unsigned int i; // ecx
  float v20; // edi
  double v21; // st3
  double v22; // st4
  int v23; // ecx
  double v24; // st5
  int v25; // eax
  float *v26; // eax
  double v27; // st6
  int v28; // eax
  int v29; // eax
  int v30; // eax
  double v31; // st7
  unsigned int v32; // eax
  int v33; // edi
  float v34; // edx
  float v35; // ecx
  float v36; // esi
  unsigned int v37; // edx
  float v38; // ecx
  float v39; // xmm0_4
  int v40; // eax
  float *v41; // eax
  int n2; // eax
  int v43; // eax
  int v44; // edi
  int result; // eax
  int v46; // [esp-114h] [ebp-120h]
  float v47[4]; // [esp-100h] [ebp-10Ch] BYREF
  float v48; // [esp-F0h] [ebp-FCh]
  float v49; // [esp-ECh] [ebp-F8h]
  float v50; // [esp-E8h] [ebp-F4h]
  int v51; // [esp-D0h] [ebp-DCh]
  int v52; // [esp-CCh] [ebp-D8h]
  int v53; // [esp-C8h] [ebp-D4h]
  int v54; // [esp-C4h] [ebp-D0h]
  int v55; // [esp-BCh] [ebp-C8h]
  int v56; // [esp-B8h] [ebp-C4h]
  float v57; // [esp-B4h] [ebp-C0h]
  float v58; // [esp-B0h] [ebp-BCh]
  float v59; // [esp-ACh] [ebp-B8h]
  int v60; // [esp-A8h] [ebp-B4h]
  int v61; // [esp-A4h] [ebp-B0h]
  unsigned int v62; // [esp-A0h] [ebp-ACh] BYREF
  unsigned int v63; // [esp-9Ch] [ebp-A8h]
  float v64; // [esp-98h] [ebp-A4h]
  int v65; // [esp-94h] [ebp-A0h]
  float v66; // [esp-84h] [ebp-90h] BYREF
  float v67; // [esp-80h] [ebp-8Ch]
  float v68; // [esp-7Ch] [ebp-88h]
  float v69; // [esp-78h] [ebp-84h]
  float v70; // [esp-74h] [ebp-80h]
  float v71; // [esp-70h] [ebp-7Ch]
  int v72; // [esp-6Ch] [ebp-78h]
  float v73; // [esp-68h] [ebp-74h] BYREF
  float v74; // [esp-64h] [ebp-70h] BYREF
  int v75; // [esp-60h] [ebp-6Ch]
  int v76; // [esp-5Ch] [ebp-68h]
  int v77; // [esp-58h] [ebp-64h] BYREF
  _DWORD v78[16]; // [esp-54h] [ebp-60h]
  _BYTE v79[20]; // [esp-14h] [ebp-20h] BYREF
  int v80; // [esp+0h] [ebp-Ch]
  void *v81; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v80 = a2;
  v81 = retaddr;
  v4 = *(float *)&a1;
  a1[92] = a1 + 60;
  a1[93] = a1 + 68;
  a1[94] = a1 + 76;
  v67 = *(float *)&a1;
  v61 = 0;
  v66 = 0.0;
  v60 = 0;
  a1[95] = a1 + 84;
  a1[96] = 4;
  a1[97] = 0;
  a1[99] = 0;
  sub_9ADFC0(a1, a3);
  *(_DWORD *)(LODWORD(v4) + 160) = 0;
  *(_DWORD *)(LODWORD(v4) + 196) = 0;
  *(_DWORD *)(LODWORD(v4) + 144) = *a4;
  *(_DWORD *)(LODWORD(v4) + 148) = a4[1];
  *(_DWORD *)(LODWORD(v4) + 152) = a4[2];
  *(_DWORD *)(LODWORD(v4) + 156) = a4[3];
  v70 = *(float *)(LODWORD(v4) + 148);
  v65 = 0;
  v72 = *(int *)(LODWORD(v4) + 144);
  v69 = *(float *)(LODWORD(v4) + 152);
  v71 = *(float *)&v72 * *(float *)&v72 + v70 * v70 + v69 * v69;
  if ( v71 <= 0.0 )
  {
    *(float *)&v62 = 1.0;
    *(float *)&v63 = 0.0;
    v64 = 0.0;
  }
  else
  {
    v62 = v72 ^ 0x80000000;
    v63 = LODWORD(v70) ^ 0x80000000;
    v64 = -v69;
  }
  *(_DWORD *)(LODWORD(v4) + 4 * *(_DWORD *)(LODWORD(v4) + 196) + 180) = 0;
  --*(_DWORD *)(LODWORD(v4) + 384);
  *(_DWORD *)(LODWORD(v4) + 4 * *(_DWORD *)(LODWORD(v4) + 196) + 164) = *(_DWORD *)(LODWORD(v4)
                                                                                  + 4 * *(_DWORD *)(LODWORD(v4) + 384)
                                                                                  + 368);
  v5 = *(_DWORD *)(LODWORD(v4) + 196) + 1;
  v46 = *(_DWORD *)(LODWORD(v4) + 4 * v5 + 160);
  *(_DWORD *)(LODWORD(v4) + 196) = v5;
  sub_9B1530(&v62, v46);
  v6 = *(_DWORD **)(LODWORD(v4) + 164);
  *(_DWORD *)(LODWORD(v4) + 180) = 1065353216;
  *(_DWORD *)(LODWORD(v4) + 144) = v6[4];
  *(_DWORD *)(LODWORD(v4) + 148) = v6[5];
  *(_DWORD *)(LODWORD(v4) + 152) = v6[6];
  *(_DWORD *)(LODWORD(v4) + 156) = v6[7];
  v78[9] = *(_DWORD *)(LODWORD(v4) + 144);
  v78[10] = *(_DWORD *)(LODWORD(v4) + 148);
  v78[11] = *(_DWORD *)(LODWORD(v4) + 152);
  v78[12] = *(_DWORD *)(LODWORD(v4) + 156);
  v78[5] = *(_DWORD *)(LODWORD(v4) + 144);
  v78[6] = *(_DWORD *)(LODWORD(v4) + 148);
  v78[7] = *(_DWORD *)(LODWORD(v4) + 152);
  v78[8] = *(_DWORD *)(LODWORD(v4) + 156);
  v78[1] = *(_DWORD *)(LODWORD(v4) + 144);
  v78[2] = *(_DWORD *)(LODWORD(v4) + 148);
  v78[3] = *(_DWORD *)(LODWORD(v4) + 152);
  v78[4] = *(_DWORD *)(LODWORD(v4) + 156);
  v75 = *(_DWORD *)(LODWORD(v4) + 144);
  v76 = *(_DWORD *)(LODWORD(v4) + 148);
  v77 = *(_DWORD *)(LODWORD(v4) + 152);
  v7 = *(_DWORD *)(LODWORD(v4) + 156);
  v69 = v71;
  v78[0] = v7;
  while ( 1 )
  {
    v8 = *(_DWORD *)(LODWORD(v4) + 388);
    v74 = *(float *)(LODWORD(v4) + 148);
    v72 = *(int *)(LODWORD(v4) + 144);
    v56 = 1 - v8;
    v68 = *(float *)(LODWORD(v4) + 152);
    LODWORD(v9) = LODWORD(v4) + 4 * (9 * v8 + 41);
    v71 = v9;
    LODWORD(v70) = LODWORD(v4) + 4 * (1 - v8 + 8 * (1 - v8) + 41);
    v73 = *(float *)&v72 * *(float *)&v72 + v74 * v74 + v68 * v68;
    v73 = sqrt(v73);
    if ( v73 < 0.00009999999747378752 )
      break;
    v10 = *(float *)&v72;
    *(_DWORD *)(LODWORD(v9) + 4 * *(_DWORD *)(LODWORD(v9) + 32) + 16) = 0;
    --*(_DWORD *)(LODWORD(v4) + 384);
    *(_DWORD *)(LODWORD(v9) + 4 * *(_DWORD *)(LODWORD(v9) + 32)) = *(_DWORD *)(LODWORD(v4)
                                                                             + 4 * *(_DWORD *)(LODWORD(v4) + 384)
                                                                             + 368);
    v11 = *(_DWORD *)(LODWORD(v9) + 32);
    v47[0] = -v10;
    v12 = *(_DWORD *)(LODWORD(v9) + 4 * v11);
    v47[1] = -v74;
    v13 = v68;
    *(_DWORD *)(LODWORD(v9) + 32) = v11 + 1;
    v47[2] = -v13;
    v47[3] = 0.0;
    sub_9B1530(v47, v12);
    v14 = v9;
    v15 = (float *)&v77;
    v72 = *(_DWORD *)(LODWORD(v14) + 4 * *(_DWORD *)(LODWORD(v14) + 32) - 4) + 16;
    v55 = *(int *)v72;
    v16 = *(float *)&v55;
    v59 = *(float *)(v72 + 4);
    v17 = v59;
    v58 = *(float *)(v72 + 8);
    v18 = v58;
    for ( i = 0; i < 4; ++i )
    {
      v48 = v16 - *(v15 - 2);
      v49 = v17 - *(v15 - 1);
      v50 = v18 - *v15;
      v68 = v48 * v48 + v49 * v49 + v50 * v50;
      if ( v68 < 0.00009999999747378752 )
        goto LABEL_33;
      v15 += 4;
    }
    v20 = *(float *)&v72;
    v21 = *(float *)(LODWORD(v4) + 148);
    v22 = v16 * *(float *)(LODWORD(v4) + 144);
    v60 = ((_BYTE)v60 + 1) & 3;
    v23 = 2 * v60;
    v24 = v18 * *(float *)(LODWORD(v4) + 152);
    *(&v75 + 2 * v23) = *(_DWORD *)v72;
    *(&v76 + 2 * v23) = *(_DWORD *)(LODWORD(v20) + 4);
    v78[2 * v23 - 1] = *(_DWORD *)(LODWORD(v20) + 8);
    v25 = *(_DWORD *)(LODWORD(v20) + 12);
    v68 = v17 * v21 + v22 + v24;
    v78[2 * v23] = v25;
    v26 = &v73;
    v27 = v73;
    v73 = v68 / v73;
    if ( v73 <= (double)v66 )
      v26 = &v66;
    v66 = *v26;
    if ( v27 - v66 - 0.00009999999747378752 * v27 <= 0.0 )
    {
LABEL_33:
      v43 = 9 * *(_DWORD *)(LODWORD(v4) + 388);
      --*(_DWORD *)(LODWORD(v4) + 4 * v43 + 196);
      *(_DWORD *)(LODWORD(v4) + 4 * (*(_DWORD *)(LODWORD(v4) + 384))++ + 368) = *(_DWORD *)(LODWORD(v4)
                                                                                          + 4 * v43
                                                                                          + 4
                                                                                          * *(_DWORD *)(LODWORD(v4) + 4 * v43 + 196)
                                                                                          + 164);
      goto LABEL_35;
    }
    v28 = *(_DWORD *)(LODWORD(v14) + 32);
    v74 = 0.0;
    v29 = v28 - 2;
    if ( !v29 )
    {
      v31 = sub_9B2560(*(_DWORD *)LODWORD(v14) + 16, *(_DWORD *)(LODWORD(v14) + 4) + 16, v79, &v74);
      goto LABEL_18;
    }
    v30 = v29 - 1;
    if ( !v30 )
    {
      v31 = sub_9B1FF0(
              *(_DWORD *)LODWORD(v14) + 16,
              *(_DWORD *)(LODWORD(v14) + 4) + 16,
              *(_DWORD *)(LODWORD(v14) + 8) + 16,
              v79,
              &v74);
      goto LABEL_18;
    }
    if ( v30 == 1 )
    {
      v31 = sub_9B1B30(
              *(_DWORD *)LODWORD(v14) + 16,
              *(_DWORD *)(LODWORD(v14) + 4) + 16,
              *(_DWORD *)(LODWORD(v14) + 8) + 16,
              *(_DWORD *)(LODWORD(v14) + 12) + 16,
              v79,
              &v74);
LABEL_18:
      v14 = v71;
      v69 = v31;
    }
    if ( v69 < 0.0 )
      goto LABEL_33;
    v51 = 0;
    *(_DWORD *)(LODWORD(v70) + 32) = 0;
    *(_DWORD *)(LODWORD(v4) + 144) = v51;
    v52 = 0;
    *(_DWORD *)(LODWORD(v4) + 148) = 0;
    v53 = 0;
    *(_DWORD *)(LODWORD(v4) + 152) = 0;
    v54 = 0;
    *(_DWORD *)(LODWORD(v4) + 156) = 0;
    *(_DWORD *)(LODWORD(v4) + 388) = v56;
    *(float *)&v32 = 0.0;
    v73 = *(float *)(LODWORD(v14) + 32);
    *(float *)&v72 = 0.0;
    v33 = 1;
    if ( v73 != 0.0 )
    {
      LODWORD(v34) = LODWORD(v14) - (_DWORD)v79;
      v35 = v74;
      v71 = v34;
      do
      {
        if ( (v33 & LODWORD(v35)) != 0 )
        {
          v36 = v70;
          v37 = LODWORD(v34) + 4 * v32;
          *(_DWORD *)(LODWORD(v70) + 4 * *(_DWORD *)(LODWORD(v70) + 32)) = *(_DWORD *)&v79[v37];
          v38 = v36;
          v39 = *(float *)&v79[4 * v72];
          v40 = *(_DWORD *)(LODWORD(v36) + 32);
          v4 = v67;
          *(float *)(LODWORD(v38) + 4 * v40 + 16) = v39;
          ++*(_DWORD *)(LODWORD(v38) + 32);
          v41 = *(float **)&v79[v37];
          v57 = v39;
          v34 = v71;
          *(float *)&v62 = v41[4] * v39;
          *(float *)&v63 = v41[5] * v39;
          v64 = v39 * v41[6];
          *(float *)(LODWORD(v4) + 144) = *(float *)(LODWORD(v4) + 144) + *(float *)&v62;
          *(float *)(LODWORD(v4) + 148) = *(float *)&v63 + *(float *)(LODWORD(v4) + 148);
          *(float *)(LODWORD(v4) + 152) = v64 + *(float *)(LODWORD(v4) + 152);
        }
        else
        {
          *(_DWORD *)(LODWORD(v4) + 4 * (*(_DWORD *)(LODWORD(v4) + 384))++ + 368) = *(_DWORD *)&v79[4 * v32 + LODWORD(v34)];
        }
        v33 = __ROL4__(v33, 1);
        v35 = v74;
        v32 = v72 + 1;
        v72 = v32;
      }
      while ( v32 < LODWORD(v73) );
    }
    if ( LODWORD(v74) == 15 )
      *(_DWORD *)(LODWORD(v4) + 396) = 1;
    if ( (unsigned int)++v61 >= 0x80 )
      n2 = 2;
    else
      n2 = *(_DWORD *)(LODWORD(v4) + 396);
    *(_DWORD *)(LODWORD(v4) + 396) = n2;
    if ( n2 )
      goto LABEL_35;
  }
  *(_DWORD *)(LODWORD(v4) + 396) = 1;
LABEL_35:
  v44 = *(_DWORD *)(LODWORD(v4) + 396);
  *(_DWORD *)(LODWORD(v4) + 392) = LODWORD(v4) + 4 * (9 * *(_DWORD *)(LODWORD(v4) + 388) + 41);
  if ( v44 )
  {
    result = v44;
    if ( v44 == 1 )
      *(_DWORD *)(LODWORD(v4) + 160) = 0;
  }
  else
  {
    v67 = *(float *)(LODWORD(v4) + 144) * *(float *)(LODWORD(v4) + 144)
        + *(float *)(LODWORD(v4) + 148) * *(float *)(LODWORD(v4) + 148)
        + *(float *)(LODWORD(v4) + 152) * *(float *)(LODWORD(v4) + 152);
    v67 = sqrt(v67);
    *(float *)(LODWORD(v4) + 160) = v67;
    return 0;
  }
  return result;
}
