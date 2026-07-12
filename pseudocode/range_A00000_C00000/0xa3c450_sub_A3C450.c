// Function: sub_A3C450
// Address: 0xa3c450
// Size: 0x115
// Prototype: 

float *__cdecl sub_A3C450(int a1, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // ecx
  double v7; // st7
  int v8; // eax
  int v9; // esi
  double v10; // st7
  float *v11; // ebx
  double v12; // st7
  float *v13; // edi
  float *v14; // esi
  _DWORD *v16; // [esp-18h] [ebp-1Ch]
  float *v17; // [esp+0h] [ebp-4h]
  float *v18; // [esp+Ch] [ebp+8h]
  float v19; // [esp+10h] [ebp+Ch]
  float v20; // [esp+10h] [ebp+Ch]
  int v21; // [esp+10h] [ebp+Ch]
  float v22; // [esp+10h] [ebp+Ch]
  float v23; // [esp+10h] [ebp+Ch]
  float v24; // [esp+10h] [ebp+Ch]
  float v25; // [esp+10h] [ebp+Ch]
  float *v26; // [esp+18h] [ebp+14h]

  v19 = (float)(a2 - a1);
  v17 = (float *)dword_1A858B4;
  v5 = a1 + a2;
  v6 = a1 - a2;
  *((float *)dword_1A858B4 + 451) = 2.0 / v19;
  v18 = (float *)dword_1A858B4;
  v20 = (float)(a4 - a3);
  v7 = 2.0 / v20;
  v21 = v5;
  v8 = a3 + a4;
  v9 = a3 - a4;
  *((float *)dword_1A858B4 + 452) = v7;
  v26 = (float *)dword_1A858B4;
  v22 = (float)v21;
  v10 = v22;
  v23 = (float)v6;
  *((float *)dword_1A858B4 + 453) = v10 / v23;
  v11 = (float *)dword_1A858B4;
  v24 = (float)v8;
  v12 = v24;
  v25 = (float)v9;
  v13 = (float *)dword_1A858B4;
  v14 = (float *)(dword_1A858B4 + 455);
  v16 = dword_1A858B4 + 455;
  *((float *)dword_1A858B4 + 454) = v12 / v25;
  memset(v16, 0, 0x30u);
  *v14 = v17[451];
  v13[460] = v18[452];
  v13[463] = v26[453];
  v13[464] = v11[454];
  v13[465] = 1.0;
  v13[466] = 1.0;
  return v26;
}

