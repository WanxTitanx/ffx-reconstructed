// Function: sub_A9BE10
// Address: 0xa9be10
// Size: 0x377
// Prototype: 

int __fastcall sub_A9BE10(int *a1, unsigned int a2, int a3)
{
  int v3; // eax
  int v4; // esi
  float *v5; // edi
  float *v6; // edx
  int v7; // eax
  float *v8; // ecx
  float v9; // xmm1_4
  float *v10; // ecx
  float *v11; // eax
  float *v12; // edx
  float v13; // xmm1_4
  float v14; // xmm0_4
  float *v15; // edx
  float *v16; // ecx
  int v17; // esi
  float *v18; // edi
  float v19; // xmm1_4
  float *v20; // edi
  float *v21; // edx
  float *v22; // ecx
  float *v23; // esi
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float *v28; // ecx
  int v29; // eax
  int result; // eax
  float *v31; // [esp+4h] [ebp-14h]
  int v33; // [esp+Ch] [ebp-Ch]
  int v34; // [esp+10h] [ebp-8h]

  v3 = *a1 >> 1;
  v4 = *a1 >> 2;
  v34 = v3;
  v5 = (float *)(a3 + 4 * (v4 + v3));
  v6 = (float *)(a2 + 4 * v3 - 28);
  v33 = 4 * v4;
  v7 = 4 * v4 + a1[2];
  v31 = v5;
  v8 = v5;
  do
  {
    v8 -= 4;
    v9 = (float)-(float)(v6[2] * *(float *)(v7 + 12)) - (float)(*v6 * *(float *)(v7 + 8));
    v6 -= 8;
    v7 += 16;
    *v8 = v9;
    v8[1] = (float)(v6[8] * *(float *)(v7 - 4)) - (float)(v6[10] * *(float *)(v7 - 8));
    v8[2] = (float)-(float)(*(float *)(v7 - 12) * v6[14]) - (float)(v6[12] * *(float *)(v7 - 16));
    v8[3] = (float)(*(float *)(v7 - 12) * v6[12]) - (float)(*(float *)(v7 - 16) * v6[14]);
  }
  while ( (unsigned int)v6 >= a2 );
  v10 = (float *)(v33 + a1[2]);
  v11 = (float *)(a2 + 4 * (v34 - 8));
  v12 = v5;
  do
  {
    v13 = v11[4] * *(v10 - 1);
    v14 = *(v10 - 2) * v11[6];
    v10 -= 4;
    v11 -= 8;
    v12 += 4;
    *(v12 - 4) = v13 + v14;
    *(v12 - 3) = (float)(v11[12] * v10[2]) - (float)(v10[3] * v11[14]);
    *(v12 - 2) = (float)(v11[10] * *v10) + (float)(v11[8] * v10[1]);
    *(v12 - 1) = (float)(v11[8] * *v10) - (float)(v10[1] * v11[10]);
  }
  while ( (unsigned int)v11 >= a2 );
  sub_A9C340(v34);
  sub_A9C190(a1, a3);
  v15 = (float *)(4 * v34 + a1[2]);
  v16 = v5;
  v17 = a3 + 12;
  v18 = v5 + 2;
  do
  {
    v18 -= 4;
    v19 = (float)(v15[1] * *(float *)(v17 - 12)) - (float)(*v15 * *(float *)(v17 - 8));
    v17 += 32;
    v15 += 8;
    v18[1] = v19;
    *v16 = -(float)((float)(*(float *)(v17 - 44) * *(v15 - 8)) + (float)(*(v15 - 7) * *(float *)(v17 - 40)));
    *v18 = (float)(*(float *)(v17 - 36) * *(v15 - 5)) - (float)(*(float *)(v17 - 32) * *(v15 - 6));
    v16[1] = -(float)((float)(*(float *)(v17 - 32) * *(v15 - 5)) + (float)(*(float *)(v17 - 36) * *(v15 - 6)));
    *(v18 - 1) = (float)(*(float *)(v17 - 28) * *(v15 - 3)) - (float)(*(float *)(v17 - 24) * *(v15 - 4));
    v16[2] = -(float)((float)(*(float *)(v17 - 24) * *(v15 - 3)) + (float)(*(float *)(v17 - 28) * *(v15 - 4)));
    *(v18 - 2) = (float)(*(float *)(v17 - 20) * *(v15 - 1)) - (float)(*(v15 - 2) * *(float *)(v17 - 16));
    v16[3] = -(float)((float)(*(v15 - 2) * *(float *)(v17 - 20)) + (float)(*(float *)(v17 - 16) * *(v15 - 1)));
    v16 += 4;
  }
  while ( v17 - 12 < (unsigned int)(v18 - 2) );
  v20 = v31;
  v21 = (float *)(a3 + 8 + v33);
  v22 = v31;
  v23 = &v31[2 - v34];
  do
  {
    v24 = *(v22 - 1);
    *(v23 - 3) = v24;
    v22 -= 4;
    v23 -= 4;
    *(v21 - 2) = -v24;
    v25 = v22[2];
    *v23 = v25;
    *(v21 - 1) = -v25;
    v26 = v22[1];
    *(v23 - 1) = v26;
    *v21 = -v26;
    v27 = *v22;
    *(v23 - 2) = *v22;
    v21[1] = -v27;
    v21 += 4;
  }
  while ( v21 - 2 < v22 );
  v28 = v31 + 2;
  do
  {
    v29 = *((_DWORD *)v28 + 1);
    v20 -= 4;
    v28 += 4;
    *(_DWORD *)v20 = v29;
    v20[1] = *(v28 - 4);
    v20[2] = *(v28 - 5);
    result = *((_DWORD *)v28 - 6);
    *((_DWORD *)v20 + 3) = result;
  }
  while ( (unsigned int)v20 > 4 * v34 + a3 );
  return result;
}

