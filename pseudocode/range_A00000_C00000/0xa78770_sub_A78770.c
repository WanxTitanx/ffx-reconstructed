// Function: sub_A78770
// Address: 0xa78770
// Size: 0x2f

int __cdecl sub_A78770(int a1, int a2, int *a3)
{
  int v3; // edi
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa78782*/
  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa78784*/
  if ( ChrPointer ) /*0xa7878e*/
    sub_837B40(ChrPointer, v3); /*0xa78792*/
  return 0; /*0xa7879c*/
}