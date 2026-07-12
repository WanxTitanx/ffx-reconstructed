// Function: sub_A785F0
// Address: 0xa785f0
// Size: 0x24
// Prototype: 

int __cdecl sub_A785F0(int a1, int *a2, int *a3)
{
  int v3; // eax
  int ActorByIndex; // eax
  int result; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  ActorByIndex = FFX_Field_GetActorByIndex(v3);
  result = FFX_TK_GetChrPointer(ActorByIndex);
  *a2 = result;
  return result;
}

