// Function: sub_A3C1B0
// Address: 0xa3c1b0
// Size: 0xc2
// Prototype: 

float *__cdecl sub_A3C1B0(float *a1, int a2)
{
  int v2; // ecx
  int *v3; // ecx
  double v4; // st7
  double v6; // st5
  float v7; // [esp+4h] [ebp-Ch]
  float v8; // [esp+8h] [ebp-8h]
  float v9; // [esp+Ch] [ebp-4h]
  float v10; // [esp+Ch] [ebp-4h]
  float v11; // [esp+Ch] [ebp-4h]
  float v12; // [esp+1Ch] [ebp+Ch]
  float v13; // [esp+1Ch] [ebp+Ch]
  float v14; // [esp+1Ch] [ebp+Ch]
  float v15; // [esp+1Ch] [ebp+Ch]
  float v16; // [esp+1Ch] [ebp+Ch]
  float v17; // [esp+1Ch] [ebp+Ch]

  v2 = a2 - (_DWORD)dword_1A858B4 - 1080;
  v12 = (float)(int)dword_1A858B4[433];
  v9 = v12;
  v3 = &dword_1A858B4[4 * ((int)((unsigned __int64)(2454267027LL * v2) >> 32) >> 5)
                    + 396
                    + 4 * ((unsigned int)((unsigned __int64)(2454267027LL * v2) >> 32) >> 31)];
  v13 = (float)v3[1];
  v4 = v9;
  v8 = (v13 - 0.5) / v9;
  v14 = (float)(int)dword_1A858B4[432];
  v10 = v14;
  v15 = (float)v3[2];
  v6 = v10;
  v11 = (v15 + 0.5) / v10;
  v16 = (float)v3[3];
  v7 = (v16 + 0.5) / v4;
  v17 = (float)*v3;
  *a1 = (v17 - 0.5) / v6;
  a1[1] = v8;
  a1[2] = v11;
  a1[3] = v7;
  return a1;
}

