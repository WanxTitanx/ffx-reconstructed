// Function: sub_A79640
// Address: 0xa79640
// Size: 0x2f
// Prototype: 

int __cdecl sub_A79640(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  char v4; // al

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_830B60(ChrPointer, v4);
  return 0;
}

