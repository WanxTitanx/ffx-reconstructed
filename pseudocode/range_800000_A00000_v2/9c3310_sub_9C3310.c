// Function: sub_9C3310
// Address: 0x9c3310
int __stdcall sub_9C3310(int a1, float *a2, float *a3)
{
  double v4; // st7
  double v5; // st6
  float v6; // [esp-30h] [ebp-3Ch]
  float v7; // [esp-2Ch] [ebp-38h]
  float v8; // [esp-28h] [ebp-34h]
  float v9; // [esp-18h] [ebp-24h]
  float v10; // [esp-18h] [ebp-24h]
  float v11; // [esp-18h] [ebp-24h]
  float v12; // [esp-14h] [ebp-20h]
  float v13; // [esp-10h] [ebp-1Ch]
  float v14; // [esp-Ch] [ebp-18h]
  float v15; // [esp-4h] [ebp-10h]

  v15 = a2[1];
  v13 = a3[1];
  v14 = *a2;
  v9 = a2[2];
  v12 = a3[2];
  v4 = *a3;
  *(_DWORD *)(a1 + 12) = 0;
  v5 = v9;
  v10 = v12 * v9 + v4 * v14 + v13 * v15;
  v11 = v10 + v10;
  v6 = v4 * v11;
  v7 = v13 * v11;
  v8 = v11 * v12;
  *(float *)a1 = v14 - v6;
  *(float *)(a1 + 4) = v15 - v7;
  *(float *)(a1 + 8) = v5 - v8;
  return a1;
}
