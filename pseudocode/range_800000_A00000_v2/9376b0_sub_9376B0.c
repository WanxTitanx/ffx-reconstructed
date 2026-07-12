// Function: sub_9376B0
// Address: 0x9376b0
int __cdecl sub_9376B0(int a1, int a2, float *a3)
{
  int result; // eax
  float v4; // [esp+8h] [ebp-10h]
  float v5; // [esp+Ch] [ebp-Ch]

  n964689920 = *(_QWORD *)a2;
  flt_C8F988 = *(float *)(a2 + 8);
  flt_C8F98C[0] = *(float *)(a2 + 12);
  flt_C8F970 = *a3;
  flt_C8F974 = a3[1];
  flt_C8F978 = a3[2];
  flt_C8F97C = a3[3];
  v4 = a3[1];
  v5 = a3[2];
  *(float *)&n964689920 = *(float *)&n964689920 - *a3;
  *((float *)&n964689920 + 1) = *((float *)&n964689920 + 1) - v4;
  flt_C8F988 = flt_C8F988 - v5;
  sub_42EF00();
  *(_QWORD *)a1 = n964689920;
  *(float *)(a1 + 8) = flt_C8F988;
  result = LODWORD(flt_C8F98C[0]);
  *(float *)(a1 + 12) = flt_C8F98C[0];
  return result;
}
