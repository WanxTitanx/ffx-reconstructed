// Function: sub_802D40
// Address: 0x802d40
float *__cdecl sub_802D40(float *a1, float *a2)
{
  int v3; // edx
  double v5; // st6
  double v6; // st4
  float v7; // [esp+Ch] [ebp-14h]
  float v8; // [esp+10h] [ebp-10h]
  float v9; // [esp+14h] [ebp-Ch]
  float v10; // [esp+18h] [ebp-8h]
  float v11; // [esp+1Ch] [ebp-4h]
  float v12; // [esp+2Ch] [ebp+Ch]

  v3 = (int)a2[38];
  v7 = flt_C44BE0[(int)a2[36] & 0xFFF];
  v8 = flt_C44BE0[((unsigned __int16)(int)a2[36] + 1024) & 0xFFF];
  v10 = flt_C44BE0[(int)a2[37] & 0xFFF];
  v12 = flt_C44BE0[((unsigned __int16)(int)a2[37] + 1024) & 0xFFF];
  v9 = flt_C44BE0[v3 & 0xFFF];
  v11 = flt_C44BE0[((_WORD)v3 + 1024) & 0xFFF];
  *a1 = v11 * v12;
  v5 = v11 * v10;
  a1[1] = v9 * v8 + v7 * v5;
  a1[2] = v9 * v7 - v5 * v8;
  a1[4] = -v9 * v12;
  v6 = v9 * v10;
  a1[5] = v11 * v8 - v7 * v6;
  a1[6] = v6 * v8 + v11 * v7;
  a1[8] = v10;
  a1[9] = v7 * -v12;
  a1[10] = v12 * v8;
  a1[12] = a2[24];
  a1[13] = a2[25];
  a1[14] = a2[26];
  a1[11] = 0.0;
  a1[7] = 0.0;
  a1[3] = 0.0;
  a1[15] = 1.0;
  return a1;
}
