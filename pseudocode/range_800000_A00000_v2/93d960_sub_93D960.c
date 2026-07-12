// Function: sub_93D960
// Address: 0x93d960
int __cdecl sub_93D960(
        float *a1,
        float a2,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10)
{
  double v10; // st6
  float v12[16]; // [esp+4h] [ebp-44h] BYREF

  sub_93D900((int)a1);
  *a1 = a2;
  a1[5] = a2;
  a1[10] = 0.0;
  a1[15] = 0.0;
  a1[14] = 1.0;
  a1[11] = 1.0;
  sub_93D900((int)v12);
  v12[0] = a3;
  v12[5] = a4;
  v10 = a10 - a9;
  v12[10] = (a8 - a7) * (a9 * a10) / v10;
  v12[12] = a5;
  v12[13] = a6;
  v12[14] = (a10 * a7 - a9 * a8) / v10;
  return sub_93D1B0((int)a1, v12, (int)a1);
}
