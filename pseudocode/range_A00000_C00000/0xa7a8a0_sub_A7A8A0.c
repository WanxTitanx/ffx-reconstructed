// Function: sub_A7A8A0
// Address: 0xa7a8a0
// Size: 0x2e

int __cdecl sub_A7A8A0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi

  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa7a8ac*/
  if ( ChrPointer ) /*0xa7a8b3*/
    *(_BYTE *)(ChrPointer + 2160) = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a8c3*/
  return 0; /*0xa7a8cb*/
}