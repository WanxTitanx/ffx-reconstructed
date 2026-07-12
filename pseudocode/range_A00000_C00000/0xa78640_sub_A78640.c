// Function: sub_A78640
// Address: 0xa78640
// Size: 0x30

bool __cdecl sub_A78640(int a1, int a2, int *a3)
{
  int v3; // eax
  int ActorByIndex; // eax
  int ChrPointer; // ecx
  bool result; // al

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa78649*/
  ActorByIndex = FFX_Field_GetActorByIndex(v3); /*0xa7864f*/
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex); /*0xa7865a*/
  result = 0; /*0xa7865f*/
  if ( ChrPointer ) /*0xa78663*/
    return *(_BYTE *)(ChrPointer + 1846) != 0; /*0xa7866b*/
  return result; /*0xa7866e*/
}