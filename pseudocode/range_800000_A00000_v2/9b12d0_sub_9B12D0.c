// Function: sub_9B12D0
// Address: 0x9b12d0
double __cdecl sub_9B12D0(float *a1, float *a2, float *a3)
{
  float v4; // [esp+14h] [ebp-4h]

  v4 = a1[1];
  return (float)(a3[2] * (*a1 * a2[1])
               + *a2 * a1[2] * a3[1]
               + a2[2] * v4 * *a3
               - a3[1] * (a2[2] * *a1)
               - v4 * *a2 * a3[2]
               - a2[1] * a1[2] * *a3);
}
