// Function: sub_A79B90
// Address: 0xa79b90
// Size: 0x2f
// Prototype: 

int __cdecl sub_A79B90(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  char v4; // al

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
  {
    v4 = FFX_FieldVM_PopOperand(a1, a3);
    sub_82B300(ChrPointer, v4);
  }
  return 0;
}

