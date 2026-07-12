// Function: sub_A7A850
// Address: 0xa7a850
// Size: 0x2f

int __cdecl sub_A7A850(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa7a85f*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a864*/
  if ( ChrPointer ) /*0xa7a86e*/
    sub_824680(ChrPointer, v4); /*0xa7a872*/
  return 0; /*0xa7a87c*/
}