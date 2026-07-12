// Function: sub_A7A7E0
// Address: 0xa7a7e0
// Size: 0x2f

int __cdecl sub_A7A7E0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa7a7ef*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a7f4*/
  if ( ChrPointer ) /*0xa7a7fe*/
    sub_83D070(ChrPointer, v4); /*0xa7a802*/
  return 0; /*0xa7a80c*/
}