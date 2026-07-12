// Function: sub_9AFC00
// Address: 0x9afc00
int (__stdcall *__cdecl sub_9AFC00(int a1, float *a2, int a3, float *a4, _DWORD *a5, int a6, char a7))(int, int)
{
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st4
  double v11; // st7
  double v12; // st6
  double v13; // st3
  double v14; // st4
  double v15; // st7
  double v16; // st5
  double v17; // st3
  double v18; // st7
  double v19; // st3
  double v20; // st5
  double v21; // st4
  double v22; // st6
  double v23; // st2
  double v24; // st7
  int (__stdcall *sub_969B20_1)(int, int); // eax
  float v26; // [esp-A8h] [ebp-B4h]
  float v27; // [esp-A4h] [ebp-B0h]
  float v28; // [esp-A0h] [ebp-ACh]
  float v29; // [esp-9Ch] [ebp-A8h]
  float v30; // [esp-98h] [ebp-A4h]
  float v31; // [esp-98h] [ebp-A4h]
  float v32; // [esp-94h] [ebp-A0h]
  float v33; // [esp-94h] [ebp-A0h]
  float v34; // [esp-90h] [ebp-9Ch]
  float v35; // [esp-90h] [ebp-9Ch]
  float v36; // [esp-8Ch] [ebp-98h]
  float v37; // [esp-8Ch] [ebp-98h]
  float v38; // [esp-88h] [ebp-94h]
  float v39; // [esp-88h] [ebp-94h]
  float v40; // [esp-78h] [ebp-84h]
  float v41; // [esp-78h] [ebp-84h]
  float v42; // [esp-74h] [ebp-80h]
  float v43; // [esp-74h] [ebp-80h]
  float v44; // [esp-70h] [ebp-7Ch]
  float v45; // [esp-70h] [ebp-7Ch]
  float v46; // [esp-6Ch] [ebp-78h]
  float v47; // [esp-6Ch] [ebp-78h]
  float v48; // [esp-68h] [ebp-74h]
  float v49; // [esp-68h] [ebp-74h]
  float v50; // [esp-64h] [ebp-70h]
  float v51; // [esp-60h] [ebp-6Ch]
  float v52; // [esp-60h] [ebp-6Ch]
  float v53; // [esp-5Ch] [ebp-68h]
  float v54; // [esp-58h] [ebp-64h]
  float v55; // [esp-58h] [ebp-64h]
  float v56; // [esp-54h] [ebp-60h]
  float v57; // [esp-54h] [ebp-60h]
  float v58; // [esp-50h] [ebp-5Ch]
  float v59; // [esp-50h] [ebp-5Ch]
  float v60; // [esp-50h] [ebp-5Ch]
  float v61; // [esp-4Ch] [ebp-58h]
  float v62; // [esp-4Ch] [ebp-58h]
  float v63; // [esp-4Ch] [ebp-58h]
  float v64; // [esp-4Ch] [ebp-58h]
  float v65; // [esp-48h] [ebp-54h]
  float v66; // [esp-48h] [ebp-54h]
  float v67; // [esp-48h] [ebp-54h]
  float v68; // [esp-48h] [ebp-54h]
  float v69; // [esp-44h] [ebp-50h]
  float v70; // [esp-44h] [ebp-50h]
  float v71; // [esp-44h] [ebp-50h]

  a5[8] = 0;
  a5[4] = 0;
  *a5 = 0;
  a5[9] = 0;
  a5[5] = 0;
  a5[10] = 0;
  a5[6] = 0;
  a5[11] = 0;
  a5[7] = 0;
  v53 = a2[6];
  v7 = a4[6];
  *(_DWORD *)a6 = a1;
  v65 = v7;
  v8 = a2[2];
  *(_DWORD *)(a6 + 4) = a3;
  v56 = v8;
  v51 = a2[10];
  v61 = a4[10];
  v9 = a4[2];
  v58 = v9 * v56 + v65 * v53 + v61 * v51;
  v48 = a2[5];
  v54 = a2[1];
  v44 = a2[9];
  v42 = v54 * v9 + v48 * v65 + v44 * v61;
  v10 = v9 * *a2;
  v11 = a2[4];
  v12 = a2[8];
  v46 = v61 * v12 + v65 * v11 + v10;
  v66 = a4[5];
  v69 = a4[1];
  v62 = a4[9];
  v30 = v69 * v56 + v66 * v53 + v62 * v51;
  v32 = v69 * v54 + v66 * v48 + v62 * v44;
  v40 = v69 * *a2 + v66 * v11 + v62 * v12;
  v13 = a4[4];
  v14 = a4[8];
  v63 = *a4 * v56 + v13 * v53 + v14 * v51;
  v67 = *a4 * v54 + v13 * v48 + v14 * v44;
  v70 = v11 * v13 + *a4 * *a2 + v12 * v14;
  *(float *)(a6 + 16) = v70;
  *(float *)(a6 + 20) = v67;
  *(float *)(a6 + 24) = v63;
  *(_DWORD *)(a6 + 28) = 0;
  *(float *)(a6 + 32) = v40;
  *(float *)(a6 + 36) = v32;
  *(float *)(a6 + 40) = v30;
  *(_DWORD *)(a6 + 44) = 0;
  *(float *)(a6 + 48) = v46;
  *(float *)(a6 + 52) = v42;
  *(float *)(a6 + 56) = v58;
  *(_DWORD *)(a6 + 60) = 0;
  v34 = a4[12] - a2[12];
  v36 = a4[13] - a2[13];
  v38 = a4[14] - a2[14];
  v57 = a2[4];
  v68 = a2[8];
  v15 = v34;
  v16 = v36;
  v35 = v34 * *a2 + v36 * v57 + v38 * v68;
  v55 = a2[5];
  v50 = a2[1];
  v52 = a2[9];
  v37 = v15 * v50 + v36 * v55 + v38 * v52;
  v59 = a2[2];
  v17 = v15 * v59;
  v18 = a2[6];
  v19 = v16 * v18 + v17;
  v20 = a2[10];
  v39 = v38 * v20 + v19;
  v49 = a4[6];
  v45 = a4[2];
  v41 = a4[10];
  v29 = v45 * v59 + v49 * v18 + v41 * v20;
  v71 = a4[5];
  v64 = a4[1];
  v21 = a4[9];
  v28 = v64 * v59 + v71 * v18 + v21 * v20;
  v22 = a4[4];
  v23 = v18 * v22 + v59 * *a4;
  v24 = a4[8];
  v27 = v20 * v24 + v23;
  v26 = v45 * v50 + v49 * v55 + v41 * v52;
  v33 = v50 * v64 + v71 * v55 + v21 * v52;
  v31 = *a4 * v50 + v22 * v55 + v24 * v52;
  v47 = v45 * *a2 + v49 * v57 + v41 * v68;
  v43 = v21 * v68 + v71 * v57 + v64 * *a2;
  v60 = v24 * v68 + v22 * v57 + *a4 * *a2;
  *(float *)(a6 + 64) = v60;
  *(float *)(a6 + 68) = v43;
  *(float *)(a6 + 72) = v47;
  *(_DWORD *)(a6 + 76) = 0;
  *(float *)(a6 + 80) = v31;
  *(float *)(a6 + 84) = v33;
  *(float *)(a6 + 88) = v26;
  *(_DWORD *)(a6 + 92) = 0;
  *(float *)(a6 + 96) = v27;
  *(float *)(a6 + 100) = v28;
  *(float *)(a6 + 104) = v29;
  *(_DWORD *)(a6 + 108) = 0;
  *(float *)(a6 + 112) = v35;
  *(float *)(a6 + 116) = v37;
  *(float *)(a6 + 120) = v39;
  *(_DWORD *)(a6 + 124) = 0;
  sub_969B20_1 = sub_969B20;
  if ( a7 )
    sub_969B20_1 = sub_969990;
  *(_DWORD *)(a6 + 128) = sub_969B20_1;
  return sub_969B20_1;
}
