// Function: sub_A792D0
// Address: 0xa792d0
// Size: 0x2f

int __cdecl sub_A792D0(int a1, int a2, int *a3)
{
  int v3; // edi
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa792e2*/
  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa792e4*/
  if ( ChrPointer ) /*0xa792ee*/
    sub_837B40(ChrPointer, v3); /*0xa792f2*/
  return 0; /*0xa792fc*/
}