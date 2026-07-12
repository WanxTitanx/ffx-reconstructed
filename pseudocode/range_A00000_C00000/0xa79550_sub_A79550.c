// Function: sub_A79550
// Address: 0xa79550
// Size: 0x2f
// Prototype: 

int __cdecl sub_A79550(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  char v4; // al

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_8375F0(ChrPointer, v4);
  return 0;
}

