// Function: sub_A30EB0
// Address: 0xa30eb0
// Size: 0xf9
// Prototype: 

float *__cdecl sub_A30EB0(float *a1, float *a2, float *a3, float *a4)
{
  float v5; // [esp+0h] [ebp-20h]
  float v6; // [esp+4h] [ebp-1Ch]
  float v7; // [esp+8h] [ebp-18h]
  float v8; // [esp+10h] [ebp-10h]
  float v9; // [esp+14h] [ebp-Ch]
  float v10; // [esp+18h] [ebp-8h]
  float v11; // [esp+2Ch] [ebp+Ch]
  float v12; // [esp+2Ch] [ebp+Ch]
  float v13; // [esp+2Ch] [ebp+Ch]
  float v14; // [esp+2Ch] [ebp+Ch]
  float v15; // [esp+2Ch] [ebp+Ch]
  float v16; // [esp+2Ch] [ebp+Ch]
  float v17; // [esp+2Ch] [ebp+Ch]
  float v18; // [esp+2Ch] [ebp+Ch]

  v8 = a2[1] * a3[2] - a2[2] * a3[1];
  v9 = a2[2] * *a3 - *a2 * a3[2];
  v10 = a3[1] * *a2 - *a3 * a2[1];
  v11 = v8 * v8;
  v12 = v11 + v9 * v9;
  v13 = v12 + v10 * v10;
  v14 = sqrt(v13);
  v15 = 1.0 / v14;
  v5 = v8 * v15;
  v6 = v9 * v15;
  v7 = v15 * v10;
  v16 = *a4 * v5;
  v17 = a4[1] * v6 + v16;
  v18 = a4[2] * v7 + v17;
  *a1 = v5;
  a1[1] = v6;
  a1[2] = v7;
  a1[3] = v18;
  return a1;
}

