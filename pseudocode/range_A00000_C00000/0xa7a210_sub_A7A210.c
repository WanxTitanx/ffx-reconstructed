// Function: sub_A7A210
// Address: 0xa7a210
// Size: 0x3e
// Prototype: 

int __cdecl sub_A7A210(int a1, int a2, int *a3)
{
  char v3; // bl
  int v4; // eax
  int ActorByIndex; // eax
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  ActorByIndex = FFX_Field_GetActorByIndex(v4);
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex);
  if ( ChrPointer )
    sub_8347F0(ChrPointer, v3);
  return 0;
}

