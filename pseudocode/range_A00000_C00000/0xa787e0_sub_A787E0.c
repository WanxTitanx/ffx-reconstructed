// Function: sub_A787E0
// Address: 0xa787e0
// Size: 0xb5
// Prototype: 

int __cdecl sub_A787E0(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  int v4; // eax
  int ActorByIndex; // eax
  int v6; // eax
  int v8; // [esp+18h] [ebp-10h]
  float v9; // [esp+1Ch] [ebp-Ch]
  float v10; // [esp+20h] [ebp-8h]
  float v11; // [esp+24h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v11 = FFX_TK_PopStackFloat(a1, a3);
  v10 = FFX_TK_PopStackFloat(a1, a3);
  v9 = FFX_TK_PopStackFloat(a1, a3);
  v8 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
  {
    if ( v4 != -1 )
    {
      ActorByIndex = FFX_Field_GetActorByIndex(v4);
      v6 = FFX_TK_GetChrPointer(ActorByIndex);
      sub_832760(ChrPointer, v6, v8, v9, v10, v11);
      return 0;
    }
    sub_832760(ChrPointer, 0, 0, v9, v10, v11);
  }
  return 0;
}

