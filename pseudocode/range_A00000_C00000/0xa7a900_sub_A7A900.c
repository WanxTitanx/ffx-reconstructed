// Function: sub_A7A900
// Address: 0xa7a900
// Size: 0x3e

int __cdecl sub_A7A900(int a1, int a2, int *a3)
{
  int v3; // ebx
  int v4; // eax
  int ActorByIndex; // eax
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a912*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a917*/
  ActorByIndex = FFX_Field_GetActorByIndex(v4); /*0xa7a91d*/
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex); /*0xa7a923*/
  if ( ChrPointer ) /*0xa7a92d*/
    sub_837B40(ChrPointer, v3); /*0xa7a931*/
  return 0; /*0xa7a93b*/
}