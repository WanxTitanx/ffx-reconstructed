// Function: sub_A78BD0
// Address: 0xa78bd0
// Size: 0x42
// Prototype: 

int __cdecl sub_A78BD0(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  int v4; // eax
  int v6; // [esp+8h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v6 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_837D80(ChrPointer, v4, v6);
  return 0;
}

