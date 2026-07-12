// Function: sub_A78900
// Address: 0xa78900
// Size: 0x3f
// Prototype: 

int __cdecl sub_A78900(int a1, int a2, int *a3)
{
  int v3; // ebx
  int v4; // eax
  int ActorByIndex; // eax
  int result; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  ActorByIndex = FFX_Field_GetActorByIndex(v4);
  result = FFX_TK_GetChrPointer(ActorByIndex);
  if ( result )
    return sub_833C70(result, v3);
  return result;
}

