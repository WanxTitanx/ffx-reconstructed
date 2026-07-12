// Function: sub_93D090
// Address: 0x93d090
int __cdecl sub_93D090(int a1, float *a2)
{
  float *v2; // eax
  float *v3; // ecx
  int n4; // edx
  double v5; // st7
  float v7; // [esp+8h] [ebp-44h] BYREF
  float v8[15]; // [esp+Ch] [ebp-40h] BYREF

  v2 = a2 + 8;
  v3 = v8;
  n4 = 4;
  do
  {
    v5 = *(v2 - 8);
    ++v2;
    *(v3 - 1) = v5;
    v3 += 4;
    *(v3 - 4) = *(v2 - 5);
    *(v3 - 3) = *(v2 - 1);
    *(v3 - 2) = v2[3];
    --n4;
  }
  while ( n4 );
  v8[2] = -(a2[7] * v8[0] + v7 * a2[3] + a2[11] * v8[1]);
  v8[6] = -(a2[7] * v8[4] + v8[3] * a2[3] + a2[11] * v8[5]);
  v8[10] = -(a2[7] * v8[8] + v8[7] * a2[3] + a2[11] * v8[9]);
  v8[13] = 0.0;
  v8[12] = 0.0;
  v8[11] = 0.0;
  v8[14] = 1.0;
  return sub_93CE10(a1, (int)&v7);
}
