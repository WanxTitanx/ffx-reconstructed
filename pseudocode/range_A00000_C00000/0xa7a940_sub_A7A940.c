// Function: sub_A7A940
// Address: 0xa7a940
// Size: 0x3e

int __cdecl sub_A7A940(int a1, int a2, int *a3)
{
  int v3; // ebx
  int v4; // eax
  int ActorByIndex; // eax
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a952*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a957*/
  ActorByIndex = FFX_Field_GetActorByIndex(v4); /*0xa7a95d*/
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex); /*0xa7a963*/
  if ( ChrPointer ) /*0xa7a96d*/
    sub_837B40(ChrPointer, v3); /*0xa7a971*/
  return 0; /*0xa7a97b*/
}