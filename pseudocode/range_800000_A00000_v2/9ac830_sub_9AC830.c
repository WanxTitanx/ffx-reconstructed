// Function: sub_9AC830
// Address: 0x9ac830
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_9AC830@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int *a5,
        int a6,
        int a7,
        int a8)
{
  float *v9; // esi
  int v10; // xmm0_4
  float v11; // eax
  int v12; // xmm0_4
  float v13; // eax
  int v14; // xmm0_4
  float v15; // eax
  int v16; // xmm0_4
  int v17; // eax
  int v18; // xmm0_4
  float v19; // eax
  float *v20; // esi
  float v21; // eax
  double v22; // st7
  float v23; // eax
  float v27[7]; // [esp-C0h] [ebp-CCh] BYREF
  int v28; // [esp-A4h] [ebp-B0h]
  float v29; // [esp-A0h] [ebp-ACh] BYREF
  int v30; // [esp-8Ch] [ebp-98h] BYREF
  float v31; // [esp-88h] [ebp-94h]
  float v32; // [esp-84h] [ebp-90h] BYREF
  float v33; // [esp-80h] [ebp-8Ch] BYREF
  float v34; // [esp-7Ch] [ebp-88h]
  float v35; // [esp-78h] [ebp-84h]
  int v36; // [esp-74h] [ebp-80h]
  _DWORD v37[12]; // [esp-64h] [ebp-70h] BYREF
  int v38; // [esp-34h] [ebp-40h] BYREF
  _DWORD *v39; // [esp-30h] [ebp-3Ch]
  float *v40; // [esp-2Ch] [ebp-38h]
  float *v41; // [esp-28h] [ebp-34h]
  float *v42; // [esp-24h] [ebp-30h]
  int *v43; // [esp-20h] [ebp-2Ch]
  int n4; // [esp-1Ch] [ebp-28h]
  int v45; // [esp-18h] [ebp-24h]
  int v46; // [esp-14h] [ebp-20h]
  int v47; // [esp-10h] [ebp-1Ch]
  int v48; // [esp-Ch] [ebp-18h]
  int v49; // [esp+0h] [ebp-Ch]
  void *v50; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v49 = a2;
  v50 = retaddr;
  v9 = *(float **)(a1 + 8);
  v38 = *a5;
  v37[0] = a5[16];
  v39 = (_DWORD *)a5[1];
  v37[1] = a5[17];
  v40 = (float *)a5[2];
  v37[2] = a5[18];
  v42 = (float *)a5[4];
  v37[4] = a5[20];
  v43 = (int *)a5[5];
  v37[5] = a5[21];
  n4 = a5[6];
  v37[6] = a5[22];
  v10 = a5[8];
  v30 = a6;
  v11 = v9[8];
  v46 = v10;
  v12 = a5[24];
  v33 = v11;
  v13 = v9[9];
  v37[8] = v12;
  v14 = a5[9];
  v34 = v13;
  v15 = v9[10];
  v47 = v14;
  v16 = a5[25];
  v35 = v15;
  v17 = *((_DWORD *)v9 + 11);
  v37[9] = v16;
  v18 = a5[10];
  v36 = v17;
  v19 = *v9;
  v48 = v18;
  v32 = ((double (__thiscall *)(float *, int, int))*(_DWORD *)(LODWORD(v19) + 40))(v9, a3, a4);
  v31 = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)v9 + 40))(v9);
  v29 = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)v9 + 40))(v9);
  v33 = v33 + v29;
  v34 = v34 + v31;
  v35 = v35 + v32;
  v27[0] = v33 * 2.0;
  v20 = *(float **)(a1 + 4);
  v33 = v20[8];
  v21 = v20[9];
  v27[1] = v34 * 2.0;
  v34 = v21;
  v22 = 2.0 * v35;
  v35 = v20[10];
  v36 = *((_DWORD *)v20 + 11);
  v27[2] = v22;
  v23 = *v20;
  v27[3] = 0.0;
  v31 = ((double (__thiscall *)(float *))*(_DWORD *)(LODWORD(v23) + 40))(v20);
  v32 = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)v20 + 40))(v20);
  ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)v20 + 40))(v20);
  v47 = v30;
  v46 = 0;
  v45 = 0;
  n4 = 4;
  v43 = &v30;
  v42 = &v32;
  v41 = &v33;
  v40 = v27;
  v39 = v37;
  v38 = v28 + 112;
  return ((int (__cdecl *)(int, int *, float *))sub_9A9E80)(v28 + 48, &v38, &v29);
}
