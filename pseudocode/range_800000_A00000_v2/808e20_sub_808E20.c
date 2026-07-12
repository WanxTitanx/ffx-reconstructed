// Function: sub_808E20
// Address: 0x808e20
float *__cdecl sub_808E20(float *a1, float *a2, int a3, int a4, int a5, float a6)
{
  *a1 = *a2 * a6;
  a1[1] = a2[1] * a6;
  a1[2] = a6 * a2[2];
  return a1;
}
