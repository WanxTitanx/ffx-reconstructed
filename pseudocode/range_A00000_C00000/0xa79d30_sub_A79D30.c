// Function: sub_A79D30
// Address: 0xa79d30
// Size: 0x2f

int __cdecl sub_A79D30(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa79d3c*/
  if ( ChrPointer ) /*0xa79d43*/
  {
    v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa79d4b*/
    sub_82B4A0(ChrPointer, v4); /*0xa79d52*/
  }
  return 0; /*0xa79d5c*/
}