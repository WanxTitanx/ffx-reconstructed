// Function: sub_A79C50
// Address: 0xa79c50
// Size: 0x68
// Prototype: 

int __cdecl sub_A79C50(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  int v4; // eax
  int ActorByIndex; // eax
  int v6; // eax
  int v8; // [esp+8h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v8 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
  {
    if ( v4 != -1 )
    {
      ActorByIndex = FFX_Field_GetActorByIndex(v4);
      v6 = FFX_TK_GetChrPointer(ActorByIndex);
      sub_8326B0(ChrPointer, v6, v8);
      return 0;
    }
    sub_8326B0(ChrPointer, 0, 0);
  }
  return 0;
}

