// Function: sub_A787A0
// Address: 0xa787a0
// Size: 0x2f

int __cdecl sub_A787A0(int a1, int a2, int *a3)
{
  int v3; // edi
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa787b2*/
  ChrPointer = FFX_TK_GetChrPointer(a1); /*0xa787b4*/
  if ( ChrPointer ) /*0xa787be*/
    sub_837B40(ChrPointer, v3); /*0xa787c2*/
  return 0; /*0xa787cc*/
}