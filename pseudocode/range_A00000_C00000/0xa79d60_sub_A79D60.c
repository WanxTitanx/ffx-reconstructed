// Function: sub_A79D60
// Address: 0xa79d60
// Size: 0x2e

int __cdecl sub_A79D60(int a1, int a2, int *a3)
{
  int v3; // eax
  int ActorByIndex; // eax
  int result; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa79d69*/
  ActorByIndex = FFX_Field_GetActorByIndex(v3); /*0xa79d6f*/
  result = FFX_TK_GetChrPointer(ActorByIndex); /*0xa79d75*/
  if ( result ) /*0xa79d7f*/
    return sub_83D840(result); /*0xa79d84*/
  return result; /*0xa79d81*/
}