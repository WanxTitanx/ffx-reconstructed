// Function: sub_9C3630
// Address: 0x9c3630
int __stdcall sub_9C3630(int a1, float *a2, float *a3)
{
  double v4; // st7
  double v5; // st6
  float v6; // [esp-30h] [ebp-3Ch]
  float v7; // [esp-2Ch] [ebp-38h]
  float v8; // [esp-28h] [ebp-34h]
  float v9; // [esp-18h] [ebp-24h]
  float v10; // [esp-18h] [ebp-24h]
  float v11; // [esp-14h] [ebp-20h]
  float v12; // [esp-10h] [ebp-1Ch]
  float v13; // [esp-Ch] [ebp-18h]
  float v14; // [esp-4h] [ebp-10h]

  v14 = a2[1];
  v12 = a3[1];
  v13 = *a2;
  v9 = a2[2];
  v11 = a3[2];
  v4 = *a3;
  *(_DWORD *)(a1 + 12) = 0;
  v5 = v9;
  v10 = v11 * v9 + v4 * v13 + v12 * v14;
  v6 = v4 * v10;
  v7 = v12 * v10;
  v8 = v10 * v11;
  *(float *)a1 = v13 - v6;
  *(float *)(a1 + 4) = v14 - v7;
  *(float *)(a1 + 8) = v5 - v8;
  return a1;
}
