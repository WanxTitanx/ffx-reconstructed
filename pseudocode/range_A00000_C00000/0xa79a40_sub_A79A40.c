// Function: sub_A79A40
// Address: 0xa79a40
// Size: 0x32
// Prototype: 

int __cdecl sub_A79A40(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  char v4; // al

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    return sub_82B8A0(ChrPointer, v4);
  else
    return 0;
}

