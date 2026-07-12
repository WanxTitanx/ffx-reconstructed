// Function: sub_A79310
// Address: 0xa79310
// Size: 0x2f

int __cdecl sub_A79310(int a1, int a2, int *a3)
{
  int v3; // edi
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa79322*/
  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa79324*/
  if ( ChrPointer ) /*0xa7932e*/
    sub_837B40(ChrPointer, v3); /*0xa79332*/
  return 0; /*0xa7933c*/
}