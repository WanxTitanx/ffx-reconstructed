// Function: sub_A77C80
// Address: 0xa77c80
// Size: 0x2b

int __cdecl sub_A77C80(int a1, int a2, int *a3)
{
  int v3; // edi
  int v4; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa77c92*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa77c97*/
  sub_8301A0(v4, v3); /*0xa77c9e*/
  return 0; /*0xa77ca8*/
}