// Function: sub_93D7D0
// Address: 0x93d7d0
float *__cdecl sub_93D7D0(float *a1, float *a2, float a3)
{
  *a1 = *a2 * a3;
  a1[1] = a2[1] * a3;
  a1[2] = a2[2] * a3;
  a1[3] = a3 * a2[3];
  return a1;
}
