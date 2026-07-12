// Function: sub_A78670
// Address: 0xa78670
// Size: 0x2e

int __cdecl sub_A78670(int a1, int a2, int *a3)
{
  int v3; // eax
  int ActorByIndex; // eax
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa78679*/
  ActorByIndex = FFX_Field_GetActorByIndex(v3); /*0xa7867f*/
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex); /*0xa78685*/
  if ( ChrPointer ) /*0xa7868f*/
    sub_82B100(ChrPointer); /*0xa78692*/
  return 0; /*0xa7869c*/
}