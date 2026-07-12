// Function: sub_99A1C0
// Address: 0x99a1c0
int __userpurge sub_99A1C0@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>, float a3)
{
  int v4; // eax
  int v5; // edi
  int v6; // ecx
  int v7; // ecx
  float *v8; // eax
  double v9; // st7
  double v10; // st6
  double v11; // st5
  double v12; // st5
  double v13; // st6
  int v14; // eax
  _DWORD v16[4]; // [esp-C0h] [ebp-CCh] BYREF
  int v17; // [esp-B0h] [ebp-BCh]
  float v18; // [esp-ACh] [ebp-B8h]
  float v19; // [esp-A8h] [ebp-B4h]
  float v20; // [esp-A4h] [ebp-B0h]
  float v21; // [esp-A0h] [ebp-ACh]
  float v22; // [esp-9Ch] [ebp-A8h]
  float v23; // [esp-98h] [ebp-A4h]
  float v24; // [esp-94h] [ebp-A0h]
  float v25; // [esp-90h] [ebp-9Ch] BYREF
  float v26; // [esp-8Ch] [ebp-98h]
  float v27; // [esp-88h] [ebp-94h]
  int v28; // [esp-84h] [ebp-90h]
  float v29; // [esp-80h] [ebp-8Ch] BYREF
  float v30; // [esp-7Ch] [ebp-88h]
  float v31; // [esp-78h] [ebp-84h]
  int v32; // [esp-74h] [ebp-80h]
  float v33; // [esp-70h] [ebp-7Ch]
  float v34; // [esp-6Ch] [ebp-78h]
  float v35; // [esp-68h] [ebp-74h]
  int v36; // [esp-64h] [ebp-70h]
  float v37; // [esp-5Ch] [ebp-68h]
  float v38; // [esp-58h] [ebp-64h]
  float v39; // [esp-54h] [ebp-60h]
  float v40; // [esp-50h] [ebp-5Ch]
  float v41; // [esp-4Ch] [ebp-58h]
  float v42; // [esp-48h] [ebp-54h]
  int v43; // [esp-44h] [ebp-50h]
  float v44; // [esp-40h] [ebp-4Ch]
  float v45; // [esp-3Ch] [ebp-48h]
  float v46; // [esp-38h] [ebp-44h]
  int v47; // [esp-34h] [ebp-40h]
  float v48; // [esp-30h] [ebp-3Ch]
  float v49; // [esp-2Ch] [ebp-38h]
  float v50; // [esp-28h] [ebp-34h]
  int v51; // [esp-24h] [ebp-30h]
  float v52; // [esp-20h] [ebp-2Ch]
  float v53; // [esp-1Ch] [ebp-28h]
  float v54; // [esp-18h] [ebp-24h]
  int v55; // [esp-14h] [ebp-20h]
  int v56; // [esp+0h] [ebp-Ch]
  void *v57; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v56 = a2;
  v57 = retaddr;
  v4 = *a1;
  v37 = a3;
  v5 = *(_DWORD *)(LODWORD(a3) + 36);
  v17 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 204) + 24) + 80 * v5 + 64);
  v6 = *(_DWORD *)(a1[3] + 20);
  if ( v6 && ((*(int (__thiscall **)(int))(*(_DWORD *)v6 + 44))(v6) & 2) != 0 )
  {
    v7 = *a1;
    v40 = *(float *)(*a1 + 16);
    v41 = *(float *)(v7 + 20);
    v42 = *(float *)(v7 + 24);
    v43 = *(_DWORD *)(v7 + 28);
    v44 = *(float *)(v7 + 32);
    v45 = *(float *)(v7 + 36);
    v46 = *(float *)(v7 + 40);
    v47 = *(_DWORD *)(v7 + 44);
    v48 = *(float *)(v7 + 48);
    v49 = *(float *)(v7 + 52);
    v50 = *(float *)(v7 + 56);
    v51 = *(_DWORD *)(v7 + 60);
    v52 = *(float *)(v7 + 64);
    v53 = *(float *)(v7 + 68);
    v54 = *(float *)(v7 + 72);
    v55 = *(_DWORD *)(v7 + 76);
    v8 = (float *)LODWORD(v37);
    v37 = *(float *)(LODWORD(v37) + 16);
    v38 = *v8;
    v9 = v38;
    v29 = v37 - v38;
    v38 = v8[5];
    v39 = v8[1];
    v10 = v38;
    v11 = v39;
    v30 = v38 - v39;
    v39 = v8[6];
    v38 = v8[2];
    v31 = v39 - v38;
    v33 = v29 * 0.5;
    v34 = v30 * 0.5;
    v35 = v31 * 0.5;
    v33 = v33 + 0.0;
    v34 = v34 + 0.0;
    v35 = v35 + 0.0;
    v29 = v9 + v37;
    v30 = v10 + v11;
    v31 = v39 + v38;
    v25 = v29 * 0.5;
    v26 = v30 * 0.5;
    v27 = 0.5 * v31;
    v39 = fabs(v50);
    v21 = v39;
    v39 = fabs(v49);
    v24 = v39;
    v39 = fabs(v48);
    v19 = v39;
    v39 = fabs(v46);
    v20 = v39;
    v39 = fabs(v45);
    v23 = v39;
    v39 = fabs(v44);
    v22 = v39;
    v39 = fabs(v42);
    v18 = v39;
    v39 = fabs(v41);
    v37 = v39;
    v39 = fabs(v40);
    v38 = v39;
    v12 = v25;
    v13 = v26;
    v39 = v42 * v27 + v40 * v25 + v41 * v26;
    v25 = v39 + v52;
    v39 = v44 * v12 + v45 * v26 + v46 * v27;
    v26 = v39 + v53;
    v39 = v27 * v50 + v13 * v49 + v12 * v48;
    v27 = v39 + v54;
    v29 = v33 * v38 + v34 * v37 + v35 * v18;
    v30 = v34 * v23 + v33 * v22 + v35 * v20;
    v31 = v33 * v19 + v34 * v24 + v35 * v21;
    v33 = v25 - v29;
    v34 = v26 - v30;
    *(float *)v16 = v33;
    v35 = v27 - v31;
    *(float *)&v16[1] = v34;
    *(float *)&v16[2] = v35;
    v33 = v25 + v29;
    v16[3] = 0;
    v29 = v33;
    v36 = 0;
    v34 = v26 + v30;
    v30 = v34;
    v25 = 1.0;
    v26 = 0.0;
    v35 = v27 + v31;
    v31 = v35;
    v32 = 0;
    v14 = a1[3];
    v27 = 0.0;
    v28 = 0;
    (*(void (__thiscall **)(_DWORD, _DWORD *, float *, float *))(**(_DWORD **)(v14 + 20) + 48))(
      *(_DWORD *)(v14 + 20),
      v16,
      &v29,
      &v25);
  }
  return sub_99A5D0(v17, v5);
}
