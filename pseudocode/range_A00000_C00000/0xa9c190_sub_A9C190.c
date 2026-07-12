// Function: sub_A9C190
// Address: 0xa9c190
// Size: 0x1a8
// Prototype: int __fastcall(_DWORD, _DWORD)

float *__fastcall sub_A9C190(int *a1, int a2)
{
  _DWORD *v2; // edi
  int v3; // ebx
  float *v4; // esi
  int v5; // edx
  int v6; // eax
  float v7; // xmm0_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm4_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  float v14; // xmm1_4
  int v15; // ecx
  int v16; // eax
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm7_4
  float v22; // xmm2_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  float *result; // eax
  float v26; // [esp+Ch] [ebp-10h]
  float v27; // [esp+10h] [ebp-Ch]
  float *v28; // [esp+14h] [ebp-8h]
  float *v29; // [esp+18h] [ebp-4h]

  v2 = (_DWORD *)a1[3];
  v3 = a2 + 4 * (*a1 >> 1);
  v29 = (float *)(a1[2] + 4 * *a1);
  v28 = (float *)(a2 + 8);
  v4 = (float *)(v3 + 12);
  v5 = a2 - (_DWORD)v2;
  do
  {
    v6 = v2[1];
    v7 = *(float *)(v3 + 4 * v6 + 4);
    v8 = *(float *)(v3 + 4 * v6);
    v9 = *(float *)(v3 + 4 * *v2 + 4) - v7;
    v10 = v29[1];
    v26 = *(float *)(v3 + 4 * *v2);
    v11 = (float)(*v29 * (float)(v26 + v8)) + (float)(v10 * v9);
    v12 = (float)(v7 + *(float *)(v3 + 4 * *v2 + 4)) * 0.5;
    v13 = (float)(v10 * (float)(v26 + v8)) - (float)(*v29 * v9);
    v4 -= 4;
    v14 = (float)(v26 - v8) * 0.5;
    *(float *)((char *)v2 + v5) = v11 + v12;
    *(v4 - 1) = v12 - v11;
    v2 += 4;
    *(v28 - 1) = v13 + v14;
    *v4 = v13 - v14;
    v15 = *(v2 - 2);
    v16 = *(v2 - 1);
    v17 = *(float *)(v3 + 4 * v16);
    v18 = *(float *)(v3 + 4 * v15 + 4) - *(float *)(v3 + 4 * v16 + 4);
    v27 = *(float *)(v3 + 4 * v15);
    v19 = v29[2];
    v20 = v29[3];
    v21 = (float)(v20 * (float)(v27 + v17)) - (float)(v19 * v18);
    v22 = (float)(*(float *)(v3 + 4 * v16 + 4) + *(float *)(v3 + 4 * v15 + 4)) * 0.5;
    v23 = (float)(v20 * v18) + (float)(v19 * (float)(v27 + v17));
    v24 = (float)(v27 - v17) * 0.5;
    v29 += 4;
    *v28 = v23 + v22;
    *(v4 - 3) = v22 - v23;
    v28[1] = v21 + v24;
    *(v4 - 2) = v21 - v24;
    v28 += 4;
    result = v4 - 3;
  }
  while ( (_DWORD *)((char *)v2 + v5) < (_DWORD *)v4 - 3 );
  return result;
}

