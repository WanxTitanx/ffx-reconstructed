// Function: sub_A7A5A0
// Address: 0xa7a5a0
// Size: 0x2f
// Prototype: 

int __cdecl sub_A7A5A0(int a1, int a2, int *a3)
{
  int v3; // edi
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
    sub_837B40(ChrPointer, v3);
  return 0;
}

