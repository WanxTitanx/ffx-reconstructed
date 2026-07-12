// Function: sub_9A2DB0
// Address: 0x9a2db0
int __cdecl sub_9A2DB0(int a1, float *a2, float a3)
{
  double v3; // st6
  double v5; // st7
  float v6; // [esp-10h] [ebp-1Ch]
  float v7; // [esp-10h] [ebp-1Ch]
  float v8; // [esp-Ch] [ebp-18h]
  float v9; // [esp-Ch] [ebp-18h]
  float v10; // [esp-8h] [ebp-14h]
  float v11; // [esp-8h] [ebp-14h]

  v6 = *a2 - a3;
  v8 = a2[1] - a3;
  v3 = a2[2];
  *(float *)a1 = v6;
  *(float *)(a1 + 4) = v8;
  v10 = v3 - a3;
  *(float *)(a1 + 8) = v10;
  *(_DWORD *)(a1 + 12) = 0;
  v7 = *a2 + a3;
  v9 = a2[1] + a3;
  v5 = a3 + a2[2];
  *(float *)(a1 + 16) = v7;
  *(float *)(a1 + 20) = v9;
  v11 = v5;
  *(float *)(a1 + 24) = v11;
  *(_DWORD *)(a1 + 28) = 0;
  return a1;
}
