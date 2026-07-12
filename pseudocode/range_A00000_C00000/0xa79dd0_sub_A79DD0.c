// Function: sub_A79DD0
// Address: 0xa79dd0
// Size: 0x2e

int __cdecl sub_A79DD0(int a1, int a2, int *a3)
{
  int v3; // eax
  int ActorByIndex; // eax
  int result; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa79dd9*/
  ActorByIndex = FFX_Field_GetActorByIndex(v3); /*0xa79ddf*/
  result = FFX_TK_GetChrPointer(ActorByIndex); /*0xa79de5*/
  if ( result ) /*0xa79def*/
    return sub_8398E0(result); /*0xa79df4*/
  return result; /*0xa79df1*/
}