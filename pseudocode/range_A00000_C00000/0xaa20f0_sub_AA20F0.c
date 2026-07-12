// Function: sub_AA20F0
// Address: 0xaa20f0
// Size: 0x2b7
// Prototype: 

int __fastcall sub_AA20F0(int *a1, int a2, int *a3, int *a4, int a5)
{
  int v6; // edx
  int v7; // esi
  double v8; // xmm4_8
  double v9; // xmm6_8
  double v10; // xmm5_8
  double v11; // xmm7_8
  double v12; // xmm3_8
  _DWORD *v13; // edi
  int v14; // edx
  int v15; // esi
  double v16; // xmm2_8
  int v17; // ecx
  int v18; // ecx
  double v19; // xmm1_8
  int n1023_1; // esi
  double n1023_3; // st7
  int n1023; // ecx
  int n1023_2; // ecx
  int v24; // eax
  int v25; // eax
  double v27; // [esp+18h] [ebp-24h]
  double v28; // [esp+20h] [ebp-1Ch]
  int v29; // [esp+34h] [ebp-8h]

  v6 = *a1;
  v7 = a1[14 * a2 - 13];
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0.0;
  v12 = 0.0;
  v29 = v7;
  if ( a2 > 0 )
  {
    v13 = a1 + 8;
    do
    {
      v14 = *(v13 - 1);
      v15 = v13[5];
      v13 += 14;
      v16 = (float)((float)((float)(v15 + v14) * *(float *)(a5 + 1108)) / (float)(v14 + 1)) + 1.0;
      v8 = v8 + (double)(int)*(v13 - 20) * v16 + (double)(int)*(v13 - 14);
      v9 = v9 + (double)(int)*(v13 - 19) * v16 + (double)(int)*(v13 - 13);
      v10 = v10 + (double)(int)*(v13 - 18) * v16 + (double)(int)*(v13 - 12);
      v11 = v11 + (double)(int)*(v13 - 16) * v16 + (double)(int)*(v13 - 10);
      v12 = v12 + (double)v14 * v16 + (double)v15;
      --a2;
    }
    while ( a2 );
    v6 = *a1;
    v7 = v29;
  }
  v17 = *a3;
  if ( *a3 >= 0 )
  {
    v8 = v8 + (double)v6;
    v12 = v12 + 1.0;
    v9 = v9 + (double)v17;
    v10 = v10 + (double)(v6 * v6);
    v11 = v11 + (double)(v6 * v17);
  }
  v18 = *a4;
  if ( *a4 >= 0 )
  {
    v8 = v8 + (double)v7;
    v12 = v12 + 1.0;
    v9 = v9 + (double)v18;
    v10 = v10 + (double)(v7 * v7);
    v11 = v11 + (double)(v7 * v18);
  }
  v19 = v12 * v10 - v8 * v8;
  if ( v19 <= 0.0 )
  {
    *a4 = 0;
    *a3 = 0;
    return 1;
  }
  else
  {
    v27 = (v10 * v9 - v11 * v8) / v19;
    v28 = (v12 * v11 - v9 * v8) / v19;
    n1023_1 = (int)floor((double)v6 * v28 + v27 + 0.5);
    n1023_3 = floor((double)v29 * v28 + v27 + 0.5);
    n1023 = n1023_1;
    if ( n1023_1 > 1023 )
      n1023 = 1023;
    *a3 = n1023;
    n1023_2 = (int)n1023_3;
    v24 = *a3;
    if ( (int)n1023_3 > 1023 )
      n1023_2 = 1023;
    *a4 = n1023_2;
    if ( v24 < 0 )
      v24 = 0;
    *a3 = v24;
    v25 = *a4;
    if ( *a4 < 0 )
      v25 = 0;
    *a4 = v25;
    return 0;
  }
}

