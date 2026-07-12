// Function: sub_A79CC0
// Address: 0xa79cc0
// Size: 0x2f

int __cdecl sub_A79CC0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa79ccf*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa79cd4*/
  if ( ChrPointer ) /*0xa79cde*/
    sub_831380(ChrPointer, v4); /*0xa79ce2*/
  return 0; /*0xa79cec*/
}