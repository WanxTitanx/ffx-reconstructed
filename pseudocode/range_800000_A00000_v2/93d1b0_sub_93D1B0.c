// Function: sub_93D1B0
// Address: 0x93d1b0
int __cdecl sub_93D1B0(int a1, float *a2, int a3)
{
  int v3; // eax
  float *v4; // edx
  int n4; // edi
  double v6; // st7
  _BYTE v8[4]; // [esp+8h] [ebp-44h] BYREF
  char v9; // [esp+Ch] [ebp-40h] BYREF

  v3 = a3 + 8;
  v4 = (float *)&v9;
  n4 = 4;
  do
  {
    v6 = *(float *)(v3 - 4);
    v3 += 16;
    v4 += 4;
    *(v4 - 5) = v6 * a2[4] + *(float *)(v3 - 24) * *a2 + a2[8] * *(float *)(v3 - 16) + a2[12] * *(float *)(v3 - 12);
    *(v4 - 4) = a2[1] * *(float *)(v3 - 24)
              + *(float *)(v3 - 20) * a2[5]
              + a2[9] * *(float *)(v3 - 16)
              + *(float *)(v3 - 12) * a2[13];
    *(v4 - 3) = a2[6] * *(float *)(v3 - 20)
              + a2[2] * *(float *)(v3 - 24)
              + a2[10] * *(float *)(v3 - 16)
              + *(float *)(v3 - 12) * a2[14];
    *(v4 - 2) = a2[7] * *(float *)(v3 - 20)
              + a2[3] * *(float *)(v3 - 24)
              + a2[11] * *(float *)(v3 - 16)
              + *(float *)(v3 - 12) * a2[15];
    --n4;
  }
  while ( n4 );
  return sub_93CE10(a1, (int)v8);
}
