// Function: sub_A79E00
// Address: 0xa79e00
// Size: 0x2e

int __cdecl sub_A79E00(int a1, int a2, int *a3)
{
  int v3; // eax
  int ActorByIndex; // eax
  int result; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa79e09*/
  ActorByIndex = FFX_Field_GetActorByIndex(v3); /*0xa79e0f*/
  result = FFX_TK_GetChrPointer(ActorByIndex); /*0xa79e15*/
  if ( result ) /*0xa79e1f*/
    return sub_83D900(result); /*0xa79e24*/
  return result; /*0xa79e21*/
}