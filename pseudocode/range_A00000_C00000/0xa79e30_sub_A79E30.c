// Function: sub_A79E30
// Address: 0xa79e30
// Size: 0x2f

int __cdecl sub_A79E30(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  char v4; // al

  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa79e3c*/
  if ( ChrPointer ) /*0xa79e43*/
  {
    v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa79e4b*/
    sub_8347F0(ChrPointer, v4); /*0xa79e52*/
  }
  return 0; /*0xa79e5c*/
}