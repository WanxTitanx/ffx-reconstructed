// Function: sub_999840
// Address: 0x999840
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_999840@<eax>(int a1@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>, float a5, int a6, int a7)
{
  int v7; // edi
  int v8; // ecx
  float *v9; // esi
  float *v10; // eax
  double v11; // st7
  double v12; // st5
  double v13; // st6
  double v14; // st3
  double v15; // st7
  double v16; // st3
  double v17; // st5
  double v18; // st4
  double v19; // st6
  double v20; // st3
  double v21; // st6
  double v22; // st3
  double v23; // st7
  double v24; // st4
  double v25; // st5
  double v26; // st3
  double v27; // st4
  float *v28; // esi
  int v29; // ecx
  int result; // eax
  int v31; // [esp-104h] [ebp-110h]
  float v34; // [esp-ECh] [ebp-F8h]
  float v35; // [esp-E8h] [ebp-F4h]
  float v36; // [esp-E4h] [ebp-F0h]
  float v37; // [esp-E0h] [ebp-ECh]
  float v38; // [esp-DCh] [ebp-E8h]
  float v39; // [esp-D8h] [ebp-E4h]
  float v40; // [esp-D0h] [ebp-DCh]
  float v41; // [esp-CCh] [ebp-D8h]
  float v42; // [esp-C8h] [ebp-D4h]
  float v43; // [esp-C4h] [ebp-D0h]
  float v44; // [esp-C0h] [ebp-CCh]
  float v45; // [esp-BCh] [ebp-C8h]
  float v46; // [esp-B8h] [ebp-C4h]
  float v47; // [esp-B4h] [ebp-C0h]
  float v48; // [esp-B0h] [ebp-BCh]
  float v49; // [esp-ACh] [ebp-B8h]
  float v50; // [esp-A8h] [ebp-B4h]
  float v51; // [esp-A8h] [ebp-B4h]
  float v52; // [esp-A4h] [ebp-B0h]
  float v53; // [esp-A0h] [ebp-ACh]
  float v54; // [esp-9Ch] [ebp-A8h]
  float v55; // [esp-98h] [ebp-A4h]
  float v56; // [esp-98h] [ebp-A4h]
  float v57; // [esp-94h] [ebp-A0h]
  float v58; // [esp-94h] [ebp-A0h]
  float v59; // [esp-94h] [ebp-A0h]
  float v60; // [esp-94h] [ebp-A0h]
  float v61; // [esp-94h] [ebp-A0h]
  float v62; // [esp-94h] [ebp-A0h]
  _DWORD v63[16]; // [esp-90h] [ebp-9Ch] BYREF
  float v64[23]; // [esp-50h] [ebp-5Ch] BYREF
  float retaddr; // [esp+Ch] [ebp+0h]

  v64[20] = a2;
  v64[21] = retaddr;
  v7 = a1;
  v8 = *(_DWORD *)(a1 + 8);
  v9 = *(float **)(v7 + 4);
  *(_DWORD *)(v7 + 56) = a6;
  *(_DWORD *)(v7 + 48) = a7;
  *(float *)(v7 + 60) = a5;
  v10 = (float *)sub_982990((float *)(v8 + 16), (int)v64);
  v45 = v10[1];
  v53 = *v10;
  v43 = v10[2];
  v11 = v9[16];
  v12 = v9[17];
  v13 = v9[18];
  v57 = v11 * *v10 + v12 * v45 + v13 * v43;
  v37 = v57 + v10[12];
  v44 = v10[5];
  v41 = v10[4];
  v52 = v10[6];
  v58 = v41 * v11 + v44 * v12 + v52 * v13;
  v38 = v58 + v10[13];
  v59 = v10[8];
  v14 = v11 * v59;
  v15 = v10[9];
  v16 = v12 * v15 + v14;
  v17 = v10[10];
  v18 = v13 * v17 + v16;
  v19 = v59;
  v60 = v18;
  v39 = v60 + v10[14];
  v42 = v9[10];
  v48 = v9[6];
  v46 = v9[14];
  v35 = v48 * v19 + v42 * v15 + v46 * v17;
  v55 = v9[9];
  v54 = v9[5];
  v61 = v9[13];
  v34 = v54 * v19 + v55 * v15 + v61 * v17;
  v50 = v9[4];
  v20 = v19 * v50;
  v21 = v9[8];
  v22 = v15 * v21 + v20;
  v23 = v9[12];
  v24 = v17 * v23 + v22;
  v25 = v50;
  v36 = v24;
  v40 = v42 * v44 + v48 * v41 + v46 * v52;
  v26 = v55;
  v27 = v61;
  v56 = v44 * v55 + v41 * v54 + v61 * v52;
  v64[7] = 0.0;
  v64[11] = 0.0;
  v64[15] = 0.0;
  v62 = v50 * v41 + v21 * v44 + v23 * v52;
  v51 = v48 * v53 + v42 * v45 + v46 * v43;
  v64[6] = v51;
  v64[8] = v62;
  v64[9] = v56;
  v64[10] = v40;
  v64[12] = v36;
  v64[13] = v34;
  v64[14] = v35;
  v47 = v27 * v43 + v26 * v45 + v54 * v53;
  v49 = v25 * v53 + v45 * v21 + v43 * v23;
  v64[4] = v49;
  *(float *)v63 = v49;
  v64[5] = v47;
  *(float *)&v63[1] = v47;
  *(float *)&v63[2] = v51;
  v63[3] = 0;
  *(float *)&v63[4] = v62;
  *(float *)&v63[5] = v56;
  *(float *)&v63[6] = v40;
  v63[7] = 0;
  *(float *)&v63[8] = v36;
  *(float *)&v63[9] = v34;
  *(float *)&v63[10] = v35;
  v63[11] = 0;
  *(float *)&v63[12] = v37;
  *(float *)&v63[13] = v38;
  *(float *)&v63[14] = v39;
  v63[15] = 0;
  v28 = (float *)(v7 + 32);
  v29 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 204);
  v31 = v7 + 32;
  v7 += 16;
  result = (*(int (__thiscall **)(int, _DWORD *, int, int, int, int))(*(_DWORD *)v29 + 4))(v29, v63, v7, v31, a3, a4);
  *v28 = *v28 + a5;
  v28[1] = v28[1] + a5;
  v28[2] = a5 + v28[2];
  *(float *)v7 = *(float *)v7 - a5;
  *(float *)(v7 + 4) = *(float *)(v7 + 4) - a5;
  *(float *)(v7 + 8) = *(float *)(v7 + 8) - a5;
  return result;
}
