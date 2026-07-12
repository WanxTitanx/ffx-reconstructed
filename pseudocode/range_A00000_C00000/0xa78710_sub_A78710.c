// Function: sub_A78710
// Address: 0xa78710
// Size: 0x3e

int __cdecl sub_A78710(int a1, int a2, int *a3)
{
  char v3; // bl
  int v4; // eax
  int ActorByIndex; // eax
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa78722*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa78727*/
  ActorByIndex = FFX_Field_GetActorByIndex(v4); /*0xa7872d*/
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex); /*0xa78733*/
  if ( ChrPointer ) /*0xa7873d*/
    sub_8375F0(ChrPointer, v3); /*0xa78741*/
  return 0; /*0xa7874b*/
}