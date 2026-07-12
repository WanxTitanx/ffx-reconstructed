// Function: sub_A79FC0
// Address: 0xa79fc0
// Size: 0x3b
// Prototype: 

int __cdecl sub_A79FC0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax
  int ActorByIndex; // eax
  int v6; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  ActorByIndex = FFX_Field_GetActorByIndex(v4);
  v6 = FFX_TK_GetChrPointer(ActorByIndex);
  if ( ChrPointer )
    sub_8350D0(ChrPointer, v6);
  return 0;
}

