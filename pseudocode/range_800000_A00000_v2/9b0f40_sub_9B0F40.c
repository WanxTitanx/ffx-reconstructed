// Function: sub_9B0F40
// Address: 0x9b0f40
int __userpurge sub_9B0F40@<eax>(int a1@<ecx>, int a2@<ebp>, int a3@<esi>, int a4, float *a5)
{
  int v6; // ecx
  int (__thiscall *v7)(int, int *, float *, int); // eax
  float *v8; // eax
  double v9; // st7
  double v11; // st6
  double v12; // st7
  double v13; // st5
  double v14; // st4
  double v15; // st3
  int v17; // [esp-30h] [ebp-3Ch] BYREF
  float v18[5]; // [esp-20h] [ebp-2Ch] BYREF
  float v19; // [esp-Ch] [ebp-18h]
  float v20; // [esp-8h] [ebp-14h]
  float v21; // [esp-4h] [ebp-10h]
  int v22; // [esp+0h] [ebp-Ch]
  void *v23; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v22 = a2;
  v23 = retaddr;
  v21 = a5[1];
  v18[3] = 0.0;
  v6 = *(_DWORD *)(a1 + 4);
  v20 = *a5;
  v19 = a5[2];
  v7 = *(int (__thiscall **)(int, int *, float *, int))(a1 + 128);
  v18[0] = *(float *)(a1 + 24) * v19 + *(float *)(a1 + 20) * v21 + v20 * *(float *)(a1 + 16);
  v18[1] = *(float *)(a1 + 36) * v21 + v20 * *(float *)(a1 + 32) + *(float *)(a1 + 40) * v19;
  v18[2] = v19 * *(float *)(a1 + 56) + v21 * *(float *)(a1 + 52) + v20 * *(float *)(a1 + 48);
  v8 = (float *)v7(v6, &v17, v18, a3);
  v19 = v8[1];
  v20 = *v8;
  v9 = v8[2];
  v21 = v9;
  v11 = v19;
  v12 = v20;
  v13 = v21;
  v19 = *(float *)(a1 + 72) * v21 + *(float *)(a1 + 64) * v20 + *(float *)(a1 + 68) * v19;
  *(float *)a4 = v19 + *(float *)(a1 + 112);
  v14 = *(float *)(a1 + 84) * v11 + *(float *)(a1 + 80) * v12;
  v15 = *(float *)(a1 + 88);
  *(_DWORD *)(a4 + 12) = 0;
  v19 = v14 + v15 * v13;
  *(float *)(a4 + 4) = v19 + *(float *)(a1 + 116);
  v19 = v12 * *(float *)(a1 + 96) + v11 * *(float *)(a1 + 100) + v13 * *(float *)(a1 + 104);
  *(float *)(a4 + 8) = v19 + *(float *)(a1 + 120);
  return a4;
}
