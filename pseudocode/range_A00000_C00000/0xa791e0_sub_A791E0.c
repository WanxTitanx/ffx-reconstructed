// Function: sub_A791E0
// Address: 0xa791e0
// Size: 0x2f

int __cdecl sub_A791E0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  __int16 v4; // ax

  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa791ef*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa791f4*/
  if ( ChrPointer ) /*0xa791fe*/
    sub_82B400(ChrPointer, v4); /*0xa79202*/
  return 0; /*0xa7920c*/
}