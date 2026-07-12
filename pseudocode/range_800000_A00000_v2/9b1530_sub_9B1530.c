// Function: sub_9B1530
// Address: 0x9b1530
// bad sp value at call has been detected, the output may be wrong!
int *__userpurge sub_9B1530@<eax>(int *a1@<ecx>, int a2@<ebp>, float *a3, int a4)
{
  double v5; // st5
  double v6; // st6
  int v7; // ecx
  float v8; // xmm0_4
  int (__thiscall *v9)(int, _DWORD, _DWORD); // eax
  int v10; // eax
  float v11; // ecx
  float *v12; // eax
  double v13; // st7
  double v14; // st7
  int *result; // eax
  int v16; // [esp-50h] [ebp-5Ch] BYREF
  int v17; // [esp-40h] [ebp-4Ch] BYREF
  float v18; // [esp-30h] [ebp-3Ch]
  float v19; // [esp-2Ch] [ebp-38h]
  float v20; // [esp-28h] [ebp-34h]
  int v21; // [esp-24h] [ebp-30h]
  float v22; // [esp-20h] [ebp-2Ch] BYREF
  float v23; // [esp-1Ch] [ebp-28h]
  float v24; // [esp-18h] [ebp-24h]
  int *v25; // [esp-14h] [ebp-20h]
  float v26; // [esp-10h] [ebp-1Ch]
  float v27; // [esp-Ch] [ebp-18h]
  float v28; // [esp-8h] [ebp-14h]
  float v29; // [esp-4h] [ebp-10h]
  _DWORD v30[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v30[0] = a2;
  v30[1] = retaddr;
  v28 = a3[1];
  v29 = *a3;
  v27 = a3[2];
  v26 = v29 * v29 + v28 * v28 + v27 * v27;
  v26 = sqrt(v26);
  v25 = 0;
  v26 = 1.0 / v26;
  v5 = v26;
  v22 = v29 * v26;
  v6 = v28;
  *(float *)a4 = v22;
  v23 = v6 * v5;
  *(float *)(a4 + 4) = v23;
  v24 = v5 * v27;
  *(float *)(a4 + 8) = v24;
  *(_DWORD *)(a4 + 12) = v25;
  v7 = *a1;
  v22 = -*(float *)a4;
  v23 = -*(float *)(a4 + 4);
  v8 = -*(float *)(a4 + 8);
  v25 = &v17;
  v9 = (int (__thiscall *)(int, _DWORD, _DWORD))a1[32];
  v24 = v8;
  v10 = v9(v7, 0, LODWORD(v26));
  v18 = *(float *)v10;
  v19 = *(float *)(v10 + 4);
  v11 = *(float *)(v10 + 8);
  v21 = *(_DWORD *)(v10 + 12);
  v20 = v11;
  v12 = (float *)sub_9B0F40((int)a1, (int)v30, a4, (int)&v16, &v22);
  v13 = v18 - *v12;
  v25 = 0;
  v22 = v13;
  v23 = v19 - v12[1];
  v14 = v20 - v12[2];
  *(float *)(a4 + 16) = v22;
  *(float *)(a4 + 20) = v23;
  v24 = v14;
  *(float *)(a4 + 24) = v24;
  result = v25;
  *(_DWORD *)(a4 + 28) = v25;
  return result;
}
