// Function: sub_A7A540
// Address: 0xa7a540
// Size: 0x2f
// Prototype: 

int __cdecl sub_A7A540(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
  {
    v4 = FFX_FieldVM_PopOperand(a1, a3);
    sub_82B9F0(ChrPointer, v4);
  }
  return 0;
}

