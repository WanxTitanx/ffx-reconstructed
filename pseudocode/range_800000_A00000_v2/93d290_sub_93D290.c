// Function: sub_93D290
// Address: 0x93d290
float *__cdecl sub_93D290(float *a1, float *a2, float *a3)
{
  *a1 = *a2 * *a3;
  a1[1] = a2[1] * a3[1];
  a1[2] = a2[2] * a3[2];
  a1[3] = a2[3] * a3[3];
  return a1;
}
