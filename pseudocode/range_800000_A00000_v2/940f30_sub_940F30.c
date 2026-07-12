// Function: sub_940F30
// Address: 0x940f30
int __cdecl sub_940F30(int a1, int a2, float *a3, float *a4, float *a5)
{
  int result; // eax
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st5
  float v11[4]; // [esp+0h] [ebp-50h] BYREF
  float v12; // [esp+10h] [ebp-40h]
  float v13; // [esp+14h] [ebp-3Ch]
  float v14; // [esp+18h] [ebp-38h]
  float v15; // [esp+20h] [ebp-30h]
  float v16; // [esp+24h] [ebp-2Ch]
  float v17; // [esp+28h] [ebp-28h]
  float v18; // [esp+2Ch] [ebp-24h] BYREF
  float v19; // [esp+30h] [ebp-20h]
  float v20; // [esp+34h] [ebp-1Ch]
  float v21[4]; // [esp+3Ch] [ebp-14h] BYREF

  v16 = (float)(a1 - 256);
  v16 = v16 * 1.25 * 0.0009765625;
  v15 = (float)(a2 - 208);
  v15 = v15 / 480.0 * 0.5;
  v11[0] = *a4 + *a5;
  v11[1] = a5[1] + a4[1];
  v11[2] = a5[2] + a4[2];
  v11[3] = 1.0;
  sub_942260(&v18, a3, a4);
  result = sub_942260(v21, a3, v11);
  v12 = v21[0] - v18;
  v13 = v21[1] - v19;
  v14 = v21[2] - v20;
  v17 = v20 * v14 + v18 * v12 + v19 * v13;
  v7 = v17;
  v17 = v14 + v12 * v16 + v13 * v15;
  v17 = v7 / v17;
  v8 = v17;
  v17 = v16 * v17;
  v16 = v17 - a3[12];
  v17 = v15 * v8;
  v15 = v17 - a3[13];
  v17 = v8;
  v17 = v17 - a3[14];
  v9 = v16;
  v10 = v17;
  v17 = a3[6] * v17 + a3[4] * v16 + a3[5] * v15;
  v16 = a3[9] * v15 + a3[8] * v16 + a3[10] * v10;
  *a4 = v9 * *a3 + v15 * a3[1] + v10 * a3[2];
  a4[1] = v17;
  a4[2] = v16;
  return result;
}
