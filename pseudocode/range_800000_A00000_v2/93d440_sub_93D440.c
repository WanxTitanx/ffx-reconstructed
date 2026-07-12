// Function: sub_93D440
// Address: 0x93d440
float *__cdecl sub_93D440(float *a1, float *a2, float *a3)
{
  *a1 = a2[1] * a3[2] - a2[2] * a3[1];
  a1[1] = a2[2] * *a3 - *a2 * a3[2];
  a1[2] = a3[1] * *a2 - *a3 * a2[1];
  a1[3] = 0.0;
  return a1;
}
