// Function: sub_A789A0
// Address: 0xa789a0
// Size: 0x6d
// Prototype: 

int __cdecl sub_A789A0(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  int n7; // eax
  float v6; // [esp+18h] [ebp-Ch]
  float v7; // [esp+1Ch] [ebp-8h]
  float v8; // [esp+20h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v8 = FFX_TK_PopStackFloat(a1, a3);
  v7 = FFX_TK_PopStackFloat(a1, a3);
  v6 = FFX_TK_PopStackFloat(a1, a3);
  n7 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_82B5E0(ChrPointer, n7, v6, v7, v8);
  return 0;
}

