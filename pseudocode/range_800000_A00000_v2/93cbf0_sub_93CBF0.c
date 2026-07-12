// Function: sub_93CBF0
// Address: 0x93cbf0
int __cdecl sub_93CBF0(int a1, float *a2, float *a3)
{
  float v4[4]; // [esp+0h] [ebp-10h] BYREF

  v4[0] = a2[1] * a3[1] + *a2 * *a3 + a2[2] * a3[2] + a2[3] * a3[3];
  v4[1] = a2[4] * *a3 + a2[5] * a3[1] + a2[6] * a3[2] + a2[7] * a3[3];
  v4[2] = a2[8] * *a3 + a2[9] * a3[1] + a2[10] * a3[2] + a2[11] * a3[3];
  v4[3] = a2[12] * *a3 + a2[13] * a3[1] + a2[14] * a3[2] + a2[15] * a3[3];
  return sub_93CE50(a1, v4);
}
