// Function: sub_A79EF0
// Address: 0xa79ef0
// Size: 0x42
// Prototype: 

int __cdecl sub_A79EF0(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  int v4; // eax
  int v6; // [esp+8h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v6 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_83D040(ChrPointer, v4, v6);
  return 0;
}

