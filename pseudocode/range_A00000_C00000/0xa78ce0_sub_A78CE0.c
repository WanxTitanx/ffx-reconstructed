// Function: sub_A78CE0
// Address: 0xa78ce0
// Size: 0x48
// Prototype: 

int __cdecl sub_A78CE0(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  int v4; // eax
  int v6; // [esp+8h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v6 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    return sub_831410(ChrPointer, v4, v6);
  else
    return 0;
}

