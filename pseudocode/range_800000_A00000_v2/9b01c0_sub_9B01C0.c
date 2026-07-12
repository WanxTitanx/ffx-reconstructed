// Function: sub_9B01C0
// Address: 0x9b01c0
char __usercall sub_9B01C0@<al>(int a1@<ebp>, int a2, float *a3, int a4, float *a5, float *a6, float *a7, char a8)
{
  void *v8; // esp
  float *v9; // edi
  int v10; // eax
  unsigned int v11; // esi
  int (__thiscall *v12)(_DWORD, int *, _DWORD); // edi
  int v13; // eax
  float v14; // ecx
  double v15; // st7
  float v16; // ecx
  int v17; // eax
  float *v18; // ecx
  double v19; // st7
  double v20; // st6
  double v21; // st6
  double v22; // st5
  double v23; // st4
  double v24; // st6
  double v25; // st4
  double v26; // st4
  double v27; // st2
  double v28; // st4
  float v29; // eax
  float v30; // xmm0_4
  double v31; // st7
  float v32; // xmm0_4
  float v33; // xmm0_4
  int v35; // [esp-2B00h] [ebp-2B0Ch] BYREF
  float v36; // [esp-2AE8h] [ebp-2AF4h]
  float *v37; // [esp-2AE4h] [ebp-2AF0h]
  float v38; // [esp-2AE0h] [ebp-2AECh]
  float v39; // [esp-2ADCh] [ebp-2AE8h]
  float v40; // [esp-2AD8h] [ebp-2AE4h]
  int v41; // [esp-2AD4h] [ebp-2AE0h]
  float v42; // [esp-2AD0h] [ebp-2ADCh] BYREF
  float v43; // [esp-2ACCh] [ebp-2AD8h]
  float v44; // [esp-2AC8h] [ebp-2AD4h]
  int v45; // [esp-2AC4h] [ebp-2AD0h]
  float v46; // [esp-2AC0h] [ebp-2ACCh]
  float v47; // [esp-2ABCh] [ebp-2AC8h]
  float v48; // [esp-2AB8h] [ebp-2AC4h]
  int v49; // [esp-2AB4h] [ebp-2AC0h]
  float *v50; // [esp-2AA4h] [ebp-2AB0h]
  _DWORD v51[9]; // [esp-2AA0h] [ebp-2AACh] BYREF
  unsigned int v52; // [esp-2A7Ch] [ebp-2A88h]
  float v53; // [esp-2A70h] [ebp-2A7Ch]
  float v54; // [esp-2A6Ch] [ebp-2A78h]
  float v55; // [esp-2A68h] [ebp-2A74h]
  float v56; // [esp-2A60h] [ebp-2A6Ch]
  int v57; // [esp-24Ch] [ebp-258h]
  int v58; // [esp-248h] [ebp-254h]
  int v59; // [esp-244h] [ebp-250h]
  int v60; // [esp-240h] [ebp-24Ch]
  _DWORD v61[100]; // [esp-230h] [ebp-23Ch] BYREF
  _DWORD v62[40]; // [esp-A0h] [ebp-ACh] BYREF
  _DWORD v63[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v63[0] = a1;
  v63[1] = retaddr;
  v8 = alloca(11016);
  v9 = a7;
  v50 = a3;
  v37 = a7;
  sub_9AFC00(a2, a3, a4, a5, a7, (int)v62, a8);
  sub_9AFB70(v61);
  v42 = -*a6;
  v43 = -a6[1];
  v44 = -a6[2];
  v45 = 0;
  v10 = sub_9AF2C0(v61, (int)v63, v62, &v42) - 1;
  if ( v10 )
  {
    if ( v10 == 1 )
      *(_DWORD *)a7 = 2;
    return 0;
  }
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v60 = 0;
  sub_9AFAB0(v51);
  v42 = -*a6;
  v43 = -a6[1];
  v44 = -a6[2];
  v45 = 0;
  if ( sub_9AEAD0((int)v51, (int)v63, (int)a7, (int)a6, (int)v61, &v42) == 9 )
  {
    *(_DWORD *)a7 = 3;
    return 0;
  }
  v11 = 0;
  v46 = 0.0;
  v47 = 0.0;
  v48 = 0.0;
  if ( v52 )
  {
    v12 = (int (__thiscall *)(_DWORD, int *, _DWORD))v62[32];
    do
    {
      v13 = v12(v62[0], &v35, v51[v11 + 1]);
      v14 = *(float *)v13;
      v36 = *(float *)&v51[v11 + 5];
      v38 = v14;
      v15 = v14;
      v39 = *(float *)(v13 + 4);
      v16 = *(float *)(v13 + 8);
      v17 = *(_DWORD *)(v13 + 12);
      v40 = v16;
      v42 = v15 * v36;
      ++v11;
      v41 = v17;
      v43 = v39 * v36;
      v44 = v36 * v16;
      v46 = v42 + v46;
      v47 = v43 + v47;
      v48 = v44 + v48;
    }
    while ( v11 < v52 );
    v9 = v37;
  }
  v18 = v50;
  v19 = v47;
  v20 = v47;
  *(_DWORD *)v9 = 1;
  v21 = v20 * v18[1];
  v49 = 0;
  v22 = v46;
  v23 = v21 + v46 * *v18 + v48 * v18[2];
  v24 = v48;
  *(float *)&v50 = v23;
  v46 = *(float *)&v50 + v18[12];
  *(float *)&v50 = v19 * v18[5] + v18[4] * v22 + v48 * v18[6];
  v47 = *(float *)&v50 + v18[13];
  *(float *)&v50 = v22 * v18[8] + v19 * v18[9] + v48 * v18[10];
  v25 = *(float *)&v50 + v18[14];
  v9[4] = v46;
  v9[5] = v47;
  v48 = v25;
  v26 = v53;
  v9[6] = v48;
  v27 = v56;
  *((_DWORD *)v9 + 7) = v49;
  v42 = v26 * v27;
  v43 = v54 * v27;
  v44 = v27 * v55;
  v38 = v22 - v42;
  v39 = v19 - v43;
  v40 = v24 - v44;
  *(float *)&v50 = v39 * v18[1] + v38 * *v18 + v40 * v18[2];
  v28 = *(float *)&v50 + v18[12];
  v49 = 0;
  v46 = v28;
  v29 = v46;
  v46 = -v53;
  v30 = -v54;
  *(float *)&v50 = v39 * v18[5] + v18[4] * v38 + v40 * v18[6];
  v47 = *(float *)&v50 + v18[13];
  *(float *)&v50 = v39 * v18[9] + v38 * v18[8] + v40 * v18[10];
  v31 = *(float *)&v50 + v18[14];
  v9[8] = v29;
  v9[9] = v47;
  v48 = v31;
  v9[10] = v48;
  *((_DWORD *)v9 + 11) = v49;
  v47 = v30;
  v32 = v55;
  v9[12] = v46;
  v9[13] = v47;
  v48 = -v32;
  v33 = v56;
  v9[14] = v48;
  v49 = 0;
  v9[15] = 0.0;
  v9[16] = -v33;
  return 1;
}
