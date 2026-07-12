// Function: sub_A79240
// Address: 0xa79240
// Size: 0x2f

int __cdecl sub_A79240(int a1, int *a2, int *a3)
{
  int result; // eax

  a2[3] = 0; /*0xa7924d*/
  a2[2] = FFX_FieldVM_PopOperand(a1, a3); /*0xa7925c*/
  result = FFX_FieldVM_PopOperand(a1, a3); /*0xa79262*/
  *a2 = result; /*0xa7926a*/
  return result; /*0xa7926c*/
}