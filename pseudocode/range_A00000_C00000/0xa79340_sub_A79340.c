// Function: sub_A79340
// Address: 0xa79340
// Size: 0x28

int __cdecl sub_A79340(int a1, int *a2, int *a3)
{
  int result; // eax

  a2[3] = 0; /*0xa7934d*/
  a2[2] = 0; /*0xa79354*/
  result = FFX_FieldVM_PopOperand(a1, a3); /*0xa7935b*/
  *a2 = result; /*0xa79363*/
  return result; /*0xa79365*/
}