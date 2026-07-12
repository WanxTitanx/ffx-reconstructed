// Function: sub_A39940
// Address: 0xa39940
// Size: 0xee
// Prototype: int __cdecl(int, int, int, float, int)

int __cdecl sub_A39940(float *a1, float *a2, float *a3, float a4, int a5)
{
  int v5; // eax
  int v6; // esi
  int v7; // edx
  int v8; // esi
  float v10; // [esp+10h] [ebp-8h]
  float v11; // [esp+14h] [ebp-4h]
  float v12; // [esp+28h] [ebp+10h]
  int v13; // [esp+30h] [ebp+18h]

  v11 = *a3;
  v10 = a3[1];
  v5 = a5 != 0 ? 1 : 4;
  v6 = a5 != 0 ? 4 : 1;
  *a1 = *a2 * v11;
  v7 = 3 * v6;
  v13 = v6;
  a1[v6] = a2[1] * v11;
  a1[2 * v6] = 0.0;
  v8 = v5 + v6;
  a1[v7] = v11 * a2[4] + a3[2];
  a1[v5] = a2[2] * v10;
  a1[v8] = a2[3] * v10;
  a1[2 * v13 + v5] = 0.0;
  v12 = v10 * a2[5] + a3[3];
  a1[2 * v13 + v13 + v5] = v12;
  a1[2 * v5] = 0.0;
  a1[2 * v5 + v13] = 0.0;
  a1[2 * v8] = 0.0;
  a1[2 * v5 + v7] = a4;
  a1[3 * v5] = 0.0;
  a1[2 * v5 + v5 + v13] = 0.0;
  a1[3 * v5 + 2 * v13] = 0.0;
  a1[3 * v8] = 1.0;
  return 3 * v8;
}

