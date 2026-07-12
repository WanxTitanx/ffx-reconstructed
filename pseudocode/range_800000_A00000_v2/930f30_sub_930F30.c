// Function: sub_930F30
// Address: 0x930f30
int __cdecl sub_930F30(int a1, int a2, float a3, int a4, int a5, int a6)
{
  int result; // eax

  n964689920 = *(_QWORD *)a2;
  flt_C8F988 = *(float *)(a2 + 8);
  flt_C8F98C[0] = *(float *)(a2 + 12);
  *(float *)&n964689920 = *(float *)&n964689920 * a3;
  flt_C8F970 = a3;
  LODWORD(flt_C8F974) = a4;
  *((float *)&n964689920 + 1) = *((float *)&n964689920 + 1) * a3;
  LODWORD(flt_C8F978) = a5;
  LODWORD(flt_C8F97C) = a6;
  flt_C8F988 = a3 * flt_C8F988;
  *(_QWORD *)a1 = n964689920;
  *(float *)(a1 + 8) = flt_C8F988;
  result = LODWORD(flt_C8F98C[0]);
  *(float *)(a1 + 12) = flt_C8F98C[0];
  return result;
}
