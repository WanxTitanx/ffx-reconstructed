// Function: sub_A7A8D0
// Address: 0xa7a8d0
// Size: 0x2e

int __cdecl sub_A7A8D0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi

  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa7a8dc*/
  if ( ChrPointer ) /*0xa7a8e3*/
    *(_BYTE *)(ChrPointer + 2161) = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a8f3*/
  return 0; /*0xa7a8fb*/
}