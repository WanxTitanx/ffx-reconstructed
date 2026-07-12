// Function: sub_A413D0
// Address: 0xa413d0
// Size: 0x196
// Prototype: _DWORD __cdecl(float *, _DWORD, int, int n3)

float *__cdecl sub_A413D0(float *a1, _DWORD *a2, int a3, int n3)
{
  int v4; // edx
  int v5; // esi
  int v6; // ecx
  double v7; // st7
  float v9; // [esp+8h] [ebp-3Ch]
  float v10; // [esp+Ch] [ebp-38h]
  float v11; // [esp+10h] [ebp-34h]
  float v12; // [esp+28h] [ebp-1Ch]
  float v13; // [esp+2Ch] [ebp-18h]
  float v14; // [esp+30h] [ebp-14h]
  float v15; // [esp+38h] [ebp-Ch]
  float v16; // [esp+38h] [ebp-Ch]
  float v17; // [esp+38h] [ebp-Ch]
  float v18; // [esp+38h] [ebp-Ch]
  float v19; // [esp+38h] [ebp-Ch]
  float v20; // [esp+38h] [ebp-Ch]
  float v21; // [esp+3Ch] [ebp-8h]
  float v22; // [esp+40h] [ebp-4h]
  float v23; // [esp+50h] [ebp+Ch]
  float v24; // [esp+50h] [ebp+Ch]
  float v25; // [esp+50h] [ebp+Ch]
  float v26; // [esp+50h] [ebp+Ch]
  float v27; // [esp+50h] [ebp+Ch]
  float v28; // [esp+50h] [ebp+Ch]
  float v29; // [esp+54h] [ebp+10h]
  float v30; // [esp+54h] [ebp+10h]
  float n3a; // [esp+58h] [ebp+14h]
  float n3b; // [esp+58h] [ebp+14h]

  v4 = n3 * *a2;
  v5 = n3 * a2[1];
  v6 = n3 * a2[2];
  v12 = *(float *)(a3 + 4 * v4);
  v13 = *(float *)(a3 + 4 * v4 + 4);
  v14 = *(float *)(a3 + 4 * v4 + 8);
  v21 = *(float *)(a3 + 4 * v6) - v12;
  v22 = *(float *)(a3 + 4 * v6 + 4) - v13;
  n3a = *(float *)(a3 + 4 * v6 + 8) - v14;
  v15 = *(float *)(a3 + 4 * v5) - v12;
  v23 = *(float *)(a3 + 4 * v5 + 4) - v13;
  v29 = *(float *)(a3 + 4 * v5 + 8) - v14;
  v7 = v23;
  v24 = v23 * n3a - v29 * v22;
  n3b = v29 * v21 - n3a * v15;
  v30 = v22 * v15 - v7 * v21;
  v16 = v24 * v24;
  v17 = v16 + n3b * n3b;
  v18 = v17 + v30 * v30;
  v19 = sqrt(v18);
  v20 = 1.0 / v19;
  v9 = v24 * v20;
  v10 = n3b * v20;
  v11 = v20 * v30;
  v25 = v9 * v12;
  v26 = v25 + v10 * v13;
  v27 = v26 + v11 * v14;
  v28 = -v27;
  *a1 = v9;
  a1[1] = v10;
  a1[2] = v11;
  a1[3] = v28;
  return a1;
}

