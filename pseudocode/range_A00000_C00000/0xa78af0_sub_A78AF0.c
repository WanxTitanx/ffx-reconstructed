// Function: sub_A78AF0
// Address: 0xa78af0
// Size: 0x3f
// Prototype: 

int __cdecl sub_A78AF0(int a1, int a2, int *a3)
{
  unsigned __int8 v3; // bl
  int v4; // eax
  int ActorByIndex; // eax
  int result; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  ActorByIndex = FFX_Field_GetActorByIndex(v4);
  result = FFX_TK_GetChrPointer(ActorByIndex);
  if ( result )
    return FFX_BtlMenu_ResetActorModelCommandState(result, v3);
  return result;
}

