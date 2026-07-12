// Function: sub_9B06B0
// Address: 0x9b06b0
double __usercall sub_9B06B0@<st0>(int a1@<ebp>, float *a2, int a3, int a4, float *a5, int a6)
{
  int v6; // eax
  int v7; // eax
  unsigned int i; // esi
  int v9; // eax
  float v10; // ecx
  int n1065353216_2; // eax
  float *v12; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float *v16; // ecx
  double v17; // st6
  double v18; // st7
  double v19; // st7
  double v20; // st6
  double v21; // st4
  double v22; // st7
  int v23; // ecx
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st6
  double v28; // st6
  double v29; // st6
  double v30; // st6
  double v31; // st7
  double v32; // st7
  double v33; // st7
  int v35; // [esp-2Ch] [ebp-384h]
  int v36; // [esp-14h] [ebp-36Ch] BYREF
  float v37; // [esp-4h] [ebp-35Ch]
  _DWORD v38[16]; // [esp+Ch] [ebp-34Ch] BYREF
  float v39; // [esp+4Ch] [ebp-30Ch]
  float v40[4]; // [esp+5Ch] [ebp-2FCh] BYREF
  float v41[4]; // [esp+6Ch] [ebp-2ECh] BYREF
  float v42; // [esp+7Ch] [ebp-2DCh] BYREF
  float v43; // [esp+80h] [ebp-2D8h]
  int n1065353216_1; // [esp+84h] [ebp-2D4h]
  int n1065353216; // [esp+88h] [ebp-2D0h]
  float v46; // [esp+8Ch] [ebp-2CCh]
  float v47; // [esp+90h] [ebp-2C8h]
  float v48; // [esp+94h] [ebp-2C4h]
  int v49; // [esp+98h] [ebp-2C0h]
  float v50; // [esp+A4h] [ebp-2B4h]
  int v51; // [esp+A8h] [ebp-2B0h]
  float v52; // [esp+ACh] [ebp-2ACh]
  float v53; // [esp+B0h] [ebp-2A8h]
  __int64 v54; // [esp+B4h] [ebp-2A4h]
  float v55; // [esp+BCh] [ebp-29Ch]
  float v56; // [esp+C0h] [ebp-298h]
  double v57; // [esp+C4h] [ebp-294h]
  _DWORD v58[36]; // [esp+CCh] [ebp-28Ch] BYREF
  float v59; // [esp+15Ch] [ebp-1FCh] BYREF
  int v60; // [esp+254h] [ebp-104h]
  _DWORD v61[36]; // [esp+25Ch] [ebp-FCh] BYREF
  float v62[23]; // [esp+2ECh] [ebp-6Ch] BYREF
  int v63; // [esp+348h] [ebp-10h]
  _DWORD v64[2]; // [esp+34Ch] [ebp-Ch] BYREF
  int v65; // [esp+354h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+358h] [ebp+0h]

  v64[0] = a1;
  v64[1] = retaddr;
  v63 = -1;
  LODWORD(v62[22]) = &loc_AD9B9B;
  v62[21] = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;
  LODWORD(v62[20]) = &v65;
  v51 = a4;
  HIDWORD(v57) = a5;
  sub_96A2F0(v38);
  v38[0] = &btSphereShape::`vftable';
  v38[1] = 8;
  v38[8] = a3;
  v38[12] = a3;
  v63 = 0;
  v42 = 0.0;
  v43 = 0.0;
  n1065353216_1 = 0;
  n1065353216 = 1065353216;
  sub_603C50(&v42);
  v62[12] = *a2;
  v62[13] = a2[1];
  v62[14] = a2[2];
  v62[15] = a2[3];
  sub_9AFC00(v51, a5, (int)v38, v62, (_DWORD *)a6, (int)v61, 0);
  sub_9AFB70(v58);
  v42 = 1.0;
  v43 = 1.0;
  n1065353216_1 = 1065353216;
  n1065353216 = 0;
  v6 = sub_9AF2C0(v58, (int)v64, v61, &v42);
  if ( v6 )
  {
    if ( v6 == 1 && sub_9B01C0((int)v64, v51, a5, (int)v38, v62, &v59, (float *)a6, 1) )
    {
      v56 = *(float *)(a6 + 24) - *(float *)(a6 + 40);
      v50 = *(float *)(a6 + 20) - *(float *)(a6 + 36);
      v41[0] = *(float *)(a6 + 16) - *(float *)(a6 + 32);
      *((float *)&v57 + 1) = v50 * v50 + v41[0] * v41[0] + v56 * v56;
      *((float *)&v57 + 1) = sqrt(*((float *)&v57 + 1));
      v51 = SHIDWORD(v57);
      if ( *((float *)&v57 + 1) >= 0.00000011920929 )
      {
        HIDWORD(v54) = 0;
        *((float *)&v57 + 1) = 1.0 / *((float *)&v57 + 1);
        v31 = *((float *)&v57 + 1);
        v55 = *((float *)&v57 + 1) * v56;
        *((float *)&v57 + 1) = *((float *)&v57 + 1) * v50;
        v52 = v31 * v41[0];
        v32 = *((float *)&v57 + 1);
        *(float *)(a6 + 48) = v52;
        v53 = v32;
        v33 = v55;
        *(float *)(a6 + 52) = v53;
        *(float *)&v54 = v33;
        *(_QWORD *)(a6 + 56) = v54;
      }
      v56 = -*(float *)&v51;
    }
    else
    {
      v56 = 3.4028235e38;
    }
  }
  else
  {
    v46 = 0.0;
    v47 = 0.0;
    v48 = 0.0;
    v52 = 0.0;
    v53 = 0.0;
    LODWORD(v54) = 0;
    v7 = v60;
    for ( i = 0; i < *(_DWORD *)(v60 + 32); *(float *)&v54 = *(float *)&v54 + v56 )
    {
      v35 = *(_DWORD *)(v7 + 4 * i);
      v50 = *(float *)(v7 + 4 * i + 16);
      v9 = ((int (__thiscall *)(_DWORD, int *, int))v61[32])(v61[0], &v36, v35);
      v42 = *(float *)v9;
      v43 = *(float *)(v9 + 4);
      v10 = *(float *)(v9 + 8);
      n1065353216_2 = *(_DWORD *)(v9 + 12);
      n1065353216_1 = LODWORD(v10);
      n1065353216 = n1065353216_2;
      v12 = *(float **)(v60 + 4 * i);
      v55 = v10 * v50;
      v13 = v12[2];
      v14 = v12[1];
      v15 = *v12;
      v56 = v43 * v50;
      v37 = v50 * v42;
      v40[0] = -v15;
      v40[1] = -v14;
      v40[2] = -v13;
      v40[3] = 0.0;
      v46 = v37 + v46;
      v47 = v47 + v56;
      v48 = v48 + v55;
      sub_9B0F40((int)v61, (int)v64, i, (int)v41, v40);
      v7 = v60;
      ++i;
      v56 = v41[2] * v50;
      v55 = v41[1] * v50;
      v39 = v50 * v41[0];
      v52 = v39 + v52;
      v53 = v53 + v55;
    }
    v16 = (float *)HIDWORD(v57);
    v49 = 0;
    v17 = v48;
    *((float *)&v57 + 1) = v46 * v16[8] + v47 * v16[9] + v48 * v16[10];
    v56 = *((float *)&v57 + 1) + v16[14];
    v48 = v56;
    *((float *)&v57 + 1) = v47 * v16[5] + v46 * v16[4] + v17 * v16[6];
    v55 = *((float *)&v57 + 1) + v16[13];
    *((float *)&v57 + 1) = v46 * *v16 + v47 * v16[1] + v17 * v16[2];
    v46 = *((float *)&v57 + 1) + v16[12];
    v18 = v55;
    *(float *)(a6 + 16) = v46;
    v47 = v18;
    v19 = v52;
    *(float *)(a6 + 20) = v47;
    *(float *)(a6 + 24) = v48;
    *(_DWORD *)(a6 + 28) = v49;
    v20 = *(float *)&v54;
    *((float *)&v57 + 1) = v19 * v16[8] + v53 * v16[9] + *(float *)&v54 * v16[10];
    v56 = *((float *)&v57 + 1) + v16[14];
    *((float *)&v57 + 1) = v53 * v16[5] + v19 * v16[4] + *(float *)&v54 * v16[6];
    v55 = *((float *)&v57 + 1) + v16[13];
    v21 = *v16;
    v54 = LODWORD(v56);
    *((float *)&v57 + 1) = v19 * v21 + v53 * v16[1] + v20 * v16[2];
    v22 = *((float *)&v57 + 1) + v16[12];
    v23 = v51;
    v52 = v22;
    v24 = v55;
    *(float *)(a6 + 32) = v52;
    v53 = v24;
    *(float *)(a6 + 36) = v53;
    *(_QWORD *)(a6 + 40) = v54;
    v50 = *(float *)(a6 + 40) - *(float *)(a6 + 24);
    v56 = *(float *)(a6 + 36) - *(float *)(a6 + 20);
    v41[0] = *(float *)(a6 + 32) - *(float *)(a6 + 16);
    v57 = sub_9695E0(v23);
    v25 = sub_9695E0(v38);
    *(float *)&v51 = v25 + v57;
    *((float *)&v57 + 1) = v41[0] * v41[0] + v56 * v56 + v50 * v50;
    *((float *)&v57 + 1) = sqrt(*((float *)&v57 + 1));
    HIDWORD(v54) = 0;
    v26 = *((float *)&v57 + 1);
    *((float *)&v57 + 1) = 1.0 / *((float *)&v57 + 1);
    v27 = *((float *)&v57 + 1);
    v55 = *((float *)&v57 + 1) * v50;
    *((float *)&v57 + 1) = *((float *)&v57 + 1) * v56;
    v52 = v27 * v41[0];
    v28 = *((float *)&v57 + 1);
    *(float *)(a6 + 48) = v52;
    v53 = v28;
    v29 = v55;
    *(float *)(a6 + 52) = v53;
    *(float *)&v54 = v29;
    *(_QWORD *)(a6 + 56) = v54;
    v30 = *(float *)&v51;
    v55 = *(float *)(a6 + 56) * *(float *)&v51;
    *((float *)&v57 + 1) = *(float *)(a6 + 52) * *(float *)&v51;
    v39 = *(float *)(a6 + 48) * *(float *)&v51;
    *(float *)(a6 + 16) = *(float *)(a6 + 16) + v39;
    *(float *)(a6 + 20) = *((float *)&v57 + 1) + *(float *)(a6 + 20);
    *(float *)(a6 + 24) = *(float *)(a6 + 24) + v55;
    *((float *)&v57 + 1) = v26 - v30;
    v56 = *((float *)&v57 + 1);
  }
  v63 = -1;
  v38[0] = &btConvexInternalShape::`vftable';
  sub_968890(v38);
  return v56;
}
