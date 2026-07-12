// Function: sub_984250
// Address: 0x984250
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_984250@<eax>(int a1@<ecx>, int a2@<ebp>, float *a3, int a4, int a5)
{
  double v6; // st7
  double v7; // st5
  double v8; // st6
  double v9; // st4
  double v10; // st5
  double v11; // st7
  double v12; // st6
  double v13; // st4
  double v14; // st5
  double v15; // st5
  double v16; // st5
  double v17; // st4
  double v18; // st3
  double v19; // st2
  int v20; // ecx
  _DWORD v22[4]; // [esp-C0h] [ebp-CCh] BYREF
  _DWORD v23[4]; // [esp-B0h] [ebp-BCh] BYREF
  _DWORD v24[4]; // [esp-A0h] [ebp-ACh] BYREF
  float v25; // [esp-90h] [ebp-9Ch]
  float v26; // [esp-8Ch] [ebp-98h]
  float v27; // [esp-88h] [ebp-94h]
  int v28; // [esp-84h] [ebp-90h]
  float v29; // [esp-7Ch] [ebp-88h]
  float v30; // [esp-78h] [ebp-84h]
  float v31; // [esp-74h] [ebp-80h]
  float v32; // [esp-70h] [ebp-7Ch]
  float v33; // [esp-6Ch] [ebp-78h]
  float v34; // [esp-68h] [ebp-74h]
  float v35; // [esp-64h] [ebp-70h]
  float v36; // [esp-60h] [ebp-6Ch] BYREF
  float v37; // [esp-5Ch] [ebp-68h]
  float v38; // [esp-58h] [ebp-64h]
  int v39; // [esp-54h] [ebp-60h]
  float v40; // [esp-50h] [ebp-5Ch] BYREF
  float v41; // [esp-4Ch] [ebp-58h]
  float v42; // [esp-48h] [ebp-54h]
  int v43; // [esp-44h] [ebp-50h]
  float v44; // [esp-40h] [ebp-4Ch] BYREF
  float v45; // [esp-3Ch] [ebp-48h]
  float v46; // [esp-38h] [ebp-44h]
  int v47; // [esp-34h] [ebp-40h]
  float v48; // [esp-2Ch] [ebp-38h]
  float v49; // [esp-28h] [ebp-34h]
  float v50; // [esp-24h] [ebp-30h]
  float v51; // [esp-20h] [ebp-2Ch]
  float v52; // [esp-1Ch] [ebp-28h]
  float v53; // [esp-18h] [ebp-24h]
  int v54; // [esp-14h] [ebp-20h]
  float v55; // [esp-Ch] [ebp-18h]
  float v56; // [esp-8h] [ebp-14h]
  float v57; // [esp-4h] [ebp-10h]
  int v58; // [esp+0h] [ebp-Ch]
  void *v59; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v58 = a2;
  v59 = retaddr;
  v28 = 0;
  v33 = *(float *)(a1 + 36);
  v49 = a3[1];
  v31 = *(float *)(a1 + 32);
  v56 = *a3;
  v35 = *(float *)(a1 + 40);
  v48 = a3[2];
  v30 = *(float *)(a1 + 80);
  v6 = v56;
  v7 = v49;
  v8 = v48;
  v56 = v56 * v31 + v49 * v33 + v48 * v35;
  v25 = v56 + v30;
  v9 = *(float *)(a1 + 52);
  *(float *)v24 = v25;
  v32 = v9;
  v29 = *(float *)(a1 + 48);
  v34 = *(float *)(a1 + 56);
  v48 = *(float *)(a1 + 84);
  v56 = v29 * v6 + v32 * v49 + v34 * v8;
  v26 = v56 + v48;
  v56 = *(float *)(a1 + 68);
  v49 = *(float *)(a1 + 64);
  v55 = *(float *)(a1 + 72);
  v50 = *(float *)(a1 + 88);
  v10 = v6 * v49 + v7 * v56;
  v11 = v55;
  v55 = v8 * v55 + v10;
  v12 = v50;
  v27 = v55 + v50;
  v55 = a3[5];
  *(float *)&v24[1] = v26;
  v50 = a3[4];
  *(float *)&v24[2] = v27;
  v57 = a3[6];
  v24[3] = 0;
  v54 = 0;
  v13 = v57;
  v57 = v50 * v31 + v55 * v33 + v57 * v35;
  v51 = v57 + v30;
  *(float *)v23 = v51;
  v57 = v50 * v29 + v55 * v32 + v13 * v34;
  v52 = v57 + v48;
  *(float *)&v23[1] = v52;
  v57 = v50 * v49 + v55 * v56 + v13 * v11;
  v53 = v57 + v12;
  v14 = a3[9];
  *(float *)&v23[2] = v53;
  v50 = v14;
  v15 = a3[8];
  v23[3] = 0;
  v57 = v15;
  v55 = a3[10];
  v16 = v57;
  v57 = v57 * v31 + v50 * v33 + v55 * v35;
  v44 = v57 + v30;
  *(float *)v22 = v44;
  v57 = v16 * v29 + v50 * v32 + v55 * v34;
  v45 = v57 + v48;
  *(float *)&v22[1] = v45;
  v57 = v11 * v55 + v16 * v49 + v50 * v56;
  v46 = v12 + v57;
  *(float *)&v22[2] = v46;
  v22[3] = 0;
  v47 = 0;
  v36 = v51 + v25;
  v37 = v52 + v26;
  v38 = v53 + v27;
  v17 = v44;
  v40 = v36 + v44;
  v18 = v45;
  v41 = v37 + v45;
  v19 = v46;
  v42 = v38 + v46;
  v44 = v40 * 0.3333333432674408;
  v45 = v41 * 0.3333333432674408;
  v46 = 0.3333333432674408 * v42;
  v40 = v17 - v25;
  v41 = v18 - v26;
  v42 = v19 - v27;
  v36 = v51 - v25;
  v37 = v52 - v26;
  v38 = v53 - v27;
  v51 = v37 * v42 - v38 * v41;
  v52 = v38 * v40 - v42 * v36;
  v53 = v41 * v36 - v37 * v40;
  v57 = v51 * v51 + v52 * v52 + v53 * v53;
  v57 = sqrt(v57);
  v40 = 1.0;
  v41 = 1.0;
  v42 = 0.0;
  v43 = 0;
  v57 = 1.0 / v57;
  v51 = v51 * v57;
  v52 = v52 * v57;
  v53 = v57 * v53;
  v36 = v51 + v44;
  v37 = v52 + v45;
  v20 = *(_DWORD *)(a1 + 8);
  v38 = v53 + v46;
  v39 = 0;
  (*(void (__thiscall **)(int, float *, float *, float *))(*(_DWORD *)v20 + 8))(v20, &v44, &v36, &v40);
  (*(void (__thiscall **)(_DWORD, _DWORD *, _DWORD *, int))(**(_DWORD **)(a1 + 8) + 8))(
    *(_DWORD *)(a1 + 8),
    v24,
    v23,
    a1 + 16);
  (*(void (__thiscall **)(_DWORD, _DWORD *, _DWORD *, int))(**(_DWORD **)(a1 + 8) + 8))(
    *(_DWORD *)(a1 + 8),
    v23,
    v22,
    a1 + 16);
  return (*(int (__thiscall **)(_DWORD, _DWORD *, _DWORD *, int))(**(_DWORD **)(a1 + 8) + 8))(
           *(_DWORD *)(a1 + 8),
           v22,
           v24,
           a1 + 16);
}
