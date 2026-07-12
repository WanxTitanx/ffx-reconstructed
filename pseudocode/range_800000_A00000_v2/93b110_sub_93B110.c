// Function: sub_93B110
// Address: 0x93b110
int __cdecl sub_93B110(float *a1)
{
  int result; // eax
  float v2; // [esp+8h] [ebp-48h]
  float v3; // [esp+8h] [ebp-48h]
  float v4; // [esp+8h] [ebp-48h]
  int v5[16]; // [esp+Ch] [ebp-44h] BYREF

  sub_6EDAE0(v5);
  v2 = a1[38] * 0.01745329238474369;
  sub_6ED8C0((int)v5, (int)v5, v2);
  v3 = a1[39] * 0.01745329238474369;
  sub_6ED900((int)v5, (int)v5, v3);
  v4 = a1[40] * 0.01745329238474369;
  result = sub_6ED940((int)v5, (int)v5, v4);
  a1[30] = a1[61] * *(float *)&v5[8] + a1[26];
  a1[31] = a1[61] * *(float *)&v5[9] + a1[27];
  a1[32] = a1[61] * *(float *)&v5[10] + a1[28];
  a1[34] = -*(float *)&v5[4];
  a1[35] = -*(float *)&v5[5];
  a1[36] = -*(float *)&v5[6];
  return result;
}
