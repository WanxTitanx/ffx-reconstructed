// Function: sub_9AE090
// Address: 0x9ae090
char __usercall sub_9AE090@<al>(int a1@<ebp>, int a2, float a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // eax
  unsigned int i; // esi
  int v10; // eax
  float v11; // ecx
  int v12; // eax
  float *v13; // eax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float *v17; // ecx
  double v18; // st6
  double v19; // rt0
  double v20; // st5
  double v21; // st4
  double v22; // st5
  double v23; // st3
  double v24; // st2
  double v25; // st1
  double v26; // st2
  double v27; // st7
  double v29; // st7
  int v30; // [esp-2D4h] [ebp-2E0h]
  int v31; // [esp-2C0h] [ebp-2CCh] BYREF
  float v32[4]; // [esp-2B0h] [ebp-2BCh] BYREF
  float v33[4]; // [esp-2A0h] [ebp-2ACh] BYREF
  float v34; // [esp-290h] [ebp-29Ch]
  float v35; // [esp-28Ch] [ebp-298h]
  float v36; // [esp-288h] [ebp-294h]
  float v37; // [esp-280h] [ebp-28Ch]
  float v38; // [esp-27Ch] [ebp-288h]
  float v39; // [esp-278h] [ebp-284h]
  float v40; // [esp-270h] [ebp-27Ch]
  float v41; // [esp-26Ch] [ebp-278h]
  float v42; // [esp-268h] [ebp-274h]
  float v43; // [esp-260h] [ebp-26Ch]
  float v44; // [esp-25Ch] [ebp-268h]
  float v45; // [esp-258h] [ebp-264h]
  float v46; // [esp-250h] [ebp-25Ch]
  float v47; // [esp-24Ch] [ebp-258h]
  float v48; // [esp-248h] [ebp-254h]
  int v49; // [esp-244h] [ebp-250h]
  float v50; // [esp-238h] [ebp-244h]
  float v51; // [esp-234h] [ebp-240h]
  int v52; // [esp-230h] [ebp-23Ch] BYREF
  int v53; // [esp-A8h] [ebp-B4h]
  _DWORD v54[43]; // [esp-A0h] [ebp-ACh] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v54[40] = a1;
  v54[41] = retaddr;
  v51 = a3;
  sub_9AFC00(a2, LODWORD(a3), a4, a5, a7, v54, 0);
  sub_9AFB70(&v52);
  v7 = sub_9AF2C0(v54, a6);
  if ( v7 )
  {
    *(_DWORD *)a7 = (v7 != 1) + 1;
    return 0;
  }
  else
  {
    v43 = 0.0;
    v44 = 0.0;
    v45 = 0.0;
    v40 = 0.0;
    v41 = 0.0;
    v42 = 0.0;
    v8 = v53;
    for ( i = 0; i < *(_DWORD *)(v53 + 32); v42 = v36 + v42 )
    {
      v30 = *(_DWORD *)(v8 + 4 * i);
      v50 = *(float *)(v8 + 4 * i + 16);
      v10 = ((int (__thiscall *)(_DWORD, int *, int))v54[32])(v54[0], &v31, v30);
      v46 = *(float *)v10;
      v47 = *(float *)(v10 + 4);
      v11 = *(float *)(v10 + 8);
      v12 = *(_DWORD *)(v10 + 12);
      v37 = v46 * v50;
      v48 = v11;
      v49 = v12;
      v13 = *(float **)(v53 + 4 * i);
      v38 = v47 * v50;
      v14 = v13[2];
      v15 = v13[1];
      v16 = *v13;
      v39 = v50 * v11;
      v43 = v37 + v43;
      v33[0] = -v16;
      v33[1] = -v15;
      v33[2] = -v14;
      v33[3] = 0.0;
      v44 = v38 + v44;
      v45 = v39 + v45;
      sub_9B0F40(v32, v33);
      v8 = v53;
      ++i;
      v34 = v32[0] * v50;
      v35 = v32[1] * v50;
      v36 = v50 * v32[2];
      v40 = v34 + v40;
      v41 = v35 + v41;
    }
    v17 = (float *)LODWORD(v51);
    v49 = 0;
    v18 = v43;
    v51 = v17[2] * v45 + v17[1] * v44 + *v17 * v43;
    v46 = v51 + v17[12];
    v51 = v43 * v17[4] + v17[5] * v44 + v17[6] * v45;
    v47 = v51 + v17[13];
    v19 = v45;
    v51 = v44 * v17[9] + v43 * v17[8] + v17[10] * v45;
    v20 = v51 + v17[14];
    *(float *)(a7 + 16) = v46;
    *(float *)(a7 + 20) = v47;
    v48 = v20;
    *(float *)(a7 + 24) = v48;
    *(_DWORD *)(a7 + 28) = v49;
    v21 = v40;
    v22 = v41;
    v23 = v42;
    v51 = v17[2] * v42 + v17[1] * v41 + *v17 * v40;
    v46 = v51 + v17[12];
    v24 = v40 * v17[4] + v17[5] * v41;
    v25 = v17[6] * v42;
    v49 = 0;
    v51 = v24 + v25;
    v47 = v51 + v17[13];
    v51 = v40 * v17[8] + v17[9] * v41 + v17[10] * v42;
    v26 = v51 + v17[14];
    *(float *)(a7 + 32) = v46;
    *(float *)(a7 + 36) = v47;
    v48 = v26;
    *(float *)(a7 + 40) = v48;
    *(_DWORD *)(a7 + 44) = v49;
    v49 = 0;
    v46 = v18 - v21;
    *(float *)(a7 + 48) = v46;
    v47 = v44 - v22;
    *(float *)(a7 + 52) = v47;
    v48 = v19 - v23;
    *(float *)(a7 + 56) = v48;
    *(_DWORD *)(a7 + 60) = v49;
    v51 = *(float *)(a7 + 48) * *(float *)(a7 + 48)
        + *(float *)(a7 + 52) * *(float *)(a7 + 52)
        + *(float *)(a7 + 56) * *(float *)(a7 + 56);
    v50 = sqrt(v51);
    v27 = v50;
    *(float *)(a7 + 64) = v50;
    if ( v27 <= 0.00009999999747378752 )
      v50 = 1.0;
    v51 = 1.0 / v50;
    v29 = v51;
    *(float *)(a7 + 48) = *(float *)(a7 + 48) * v51;
    *(float *)(a7 + 52) = *(float *)(a7 + 52) * v29;
    *(float *)(a7 + 56) = v29 * *(float *)(a7 + 56);
    return 1;
  }
}
