// Function: sub_A9D3E0
// Address: 0xa9d3e0
// Size: 0x260
// Prototype: 

float *__fastcall sub_A9D3E0(int *a1, int a2, int a3)
{
  int v3; // eax
  void *v4; // esp
  _BYTE *v5; // edi
  int v6; // edx
  int v7; // ecx
  float *v8; // eax
  float *v9; // esi
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float *v14; // edi
  _BYTE *v15; // esi
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float *v20; // esi
  unsigned int v21; // edx
  int v22; // esi
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  int v29; // edi
  float *result; // eax
  float *v31; // edx
  int i; // ecx
  float v33; // xmm1_4
  _BYTE v34[8]; // [esp+0h] [ebp-30h] BYREF
  int v35; // [esp+8h] [ebp-28h]
  int v36; // [esp+Ch] [ebp-24h]
  int i_1; // [esp+10h] [ebp-20h]
  int *v38; // [esp+14h] [ebp-1Ch]
  _BYTE *v39; // [esp+18h] [ebp-18h]
  int v40; // [esp+20h] [ebp-10h]
  int v41; // [esp+24h] [ebp-Ch]
  float *v42; // [esp+28h] [ebp-8h]
  int v43; // [esp+2Ch] [ebp-4h]

  v38 = a1;
  v3 = *a1;
  i_1 = *a1 >> 2;
  v40 = a2;
  v43 = v3 >> 1;
  v41 = v3 >> 3;
  v35 = 4 * v3;
  v4 = alloca(4 * v3);
  v36 = 4 * (v3 >> 1);
  v5 = &v34[v36];
  v39 = &v34[v36];
  v6 = a2 + 4 * (i_1 + (v3 >> 1));
  v7 = 0;
  v42 = (float *)(v6 + 4);
  v8 = (float *)(v36 + v38[2]);
  if ( v41 > 0 )
  {
    v9 = v42;
    do
    {
      v10 = *(float *)(v6 - 8) + *v9;
      v11 = v9[2] + *(float *)(v6 - 16);
      v12 = *(v8 - 1);
      v13 = *(v8 - 2);
      v6 -= 16;
      v8 -= 2;
      v7 += 2;
      v9 += 4;
      *(float *)&v5[4 * v7 - 8] = (float)(v12 * v11) + (float)(v13 * v10);
      *(float *)&v5[4 * v7 - 4] = (float)(*v8 * v11) - (float)(v8[1] * v10);
    }
    while ( v7 < v41 );
  }
  v42 = (float *)(v43 - v41);
  v14 = (float *)(v40 + 4);
  if ( v7 < v43 - v41 )
  {
    v15 = v39;
    do
    {
      v16 = *(float *)(v6 - 8) - *v14;
      v17 = *(float *)(v6 - 16) - v14[2];
      v18 = *(v8 - 1);
      v19 = *(v8 - 2);
      v6 -= 16;
      v8 -= 2;
      v7 += 2;
      v14 += 4;
      *(float *)&v15[4 * v7 - 8] = (float)(v18 * v17) + (float)(v19 * v16);
      *(float *)&v15[4 * v7 - 4] = (float)(*v8 * v17) - (float)(v8[1] * v16);
    }
    while ( v7 < (int)v42 );
  }
  v20 = (float *)v34;
  v35 += v40;
  v21 = (unsigned int)v39;
  if ( v7 < v43 )
  {
    v22 = v35;
    do
    {
      v23 = *(float *)(v22 - 8);
      v24 = *(float *)(v22 - 16);
      v25 = *(v8 - 1);
      v26 = *(v8 - 2);
      v22 -= 16;
      v8 -= 2;
      v27 = (float)-v23 - *v14;
      v28 = (float)-v24 - v14[2];
      v7 += 2;
      v14 += 4;
      *(float *)(v21 + 4 * v7 - 8) = (float)(v25 * v28) + (float)(v26 * v27);
      *(float *)(v21 + 4 * v7 - 4) = (float)(*v8 * v28) - (float)(v8[1] * v27);
    }
    while ( v7 < v43 );
    v20 = (float *)v34;
  }
  v29 = (int)v38;
  sub_A9C340((int)v38, v21, v43);
  sub_A9C190((int *)v29, (int)v34);
  result = (float *)(v36 + *(_DWORD *)(v29 + 8));
  v31 = (float *)(a3 + v36);
  for ( i = 0;
        i < i_1;
        *v31 = (float)((float)(*(result - 1) * *(v20 - 2)) - (float)(*(result - 2) * *(v20 - 1))) * *((float *)v38 + 4) )
  {
    --v31;
    ++i;
    v33 = (float)(result[1] * v20[1]) + (float)(*result * *v20);
    v20 += 2;
    result += 2;
    *(float *)(a3 + 4 * i - 4) = v33 * *(float *)(v29 + 16);
    v29 = (int)v38;
  }
  return result;
}

