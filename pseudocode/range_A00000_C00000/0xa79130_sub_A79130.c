// Function: sub_A79130
// Address: 0xa79130
// Size: 0x2f
// Prototype: 

int __cdecl sub_A79130(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  char v4; // al

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_82B2C0(ChrPointer, v4);
  return 0;
}

